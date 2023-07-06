#include "pch.h"
#include "../Baseball/baseball.cpp"
#include <string>

using namespace std;

class BaseballFixture : public testing::Test
{
public:
	Baseball game {"123"};
	void assertIllegalArgument(string guessNumber)
	{
		try
		{
			game.guess(guessNumber);
			FAIL();
		}
		catch (exception e)
		{
			//PASS
		}
	}
};

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCase) {
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
	assertIllegalArgument("121");
}

TEST_F(BaseballFixture, ReturnSolvedResultIfMatchedNumber) {
	GuessResult result = game.guess("123");

	EXPECT_TRUE(result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballFixture, ReturnUnSolvedResultCase2Strike) {
	GuessResult result = game.guess("125");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(2, result.strikes);
	EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballFixture, ReturnUnSolvedResultCase1Strike2Ball) {
	GuessResult result = game.guess("132");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(1, result.strikes);
	EXPECT_EQ(2, result.balls);
}

TEST_F(BaseballFixture, ReturnUnSolvedResultCase1Strike1Ball) {
	GuessResult result = game.guess("152");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(1, result.strikes);
	EXPECT_EQ(1, result.balls);
}

TEST_F(BaseballFixture, ReturnUnSolvedResultCase0Strike3Ball) {
	GuessResult result = game.guess("312");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(0, result.strikes);
	EXPECT_EQ(3, result.balls);
}

TEST_F(BaseballFixture, ReturnUnSolvedResultCase0Strike0Ball) {
	GuessResult result = game.guess("596");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(0, result.strikes);
	EXPECT_EQ(0, result.balls);
}
