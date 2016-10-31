#include <algorithm>
#include <iostream>
#include <string>

bool hasUniqueChars(std::string str)
{
	if (str.size() == 0)
	{
		return true;
	}
	std::sort(str.begin(), str.end());
	for (int i = 0; i < str.size() - 1; ++i)
	{
		if (str[i] == str[i+1])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	std::cout << hasUniqueChars("") << std::endl;
	std::cout << hasUniqueChars("abcde") << std::endl;
	std::cout << hasUniqueChars("aaaaa") << std::endl;
	std::cout << hasUniqueChars("abcdea") << std::endl;
	std::cout << hasUniqueChars("abcdee") << std::endl;
	return 0;
}