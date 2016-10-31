#include <algorithm>
#include <iostream>
#include <string>

bool is_permutation(std::string str1, std::string str2)
{
	if (str1.size() != str2.size())
	{
		return false;
	}
	std::sort(str1.begin(), str1.end());
	std::sort(str2.begin(), str2.end());
	return str1 == str2;
}

int main()
{
	std::cout << is_permutation("", "") << std::endl;
	std::cout << is_permutation("abcde", "") << std::endl;
	std::cout << is_permutation("abcde", "abcde") << std::endl;
	std::cout << is_permutation("aaaaa", "bb") << std::endl;
	std::cout << is_permutation("abcdea", "abeacd") << std::endl;
	return 0;
}