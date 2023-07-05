#include <string>
#include <stdexcept>

using namespace std;

struct GuessResult
{
	bool solved;
	int strikes;
	int balls;
};

class Baseball
{
public:
	explicit Baseball(const std::string ans) : question(ans) {}
	bool isDupliacatedNumber(std::string& guessNumber)
	{
		return guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2];
	}

	void assertIllegalArgument(std::string& guessNumber)
	{
		if (guessNumber.length() != 3)
			throw length_error("Must be three letters.");

		for (auto ch : guessNumber)
		{
			if (ch >= '0' && ch <= '9')
				continue;
			throw invalid_argument("Must be number");
		}

		if (isDupliacatedNumber(guessNumber))
		{
			throw invalid_argument("Must not have the same number");
		}
	}

	GuessResult guess(std::string guessNumber)
	{
		assertIllegalArgument(guessNumber);
		if (guessNumber == question) {
			return { true ,3, 0 };
		}
		return { false, 3, 0 };
	}
private:
	string question;
};
