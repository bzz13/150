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

bool is_permutation2(std::string str1, std::string str2)
{
	if (str1.size() != str2.size())
	{
		return false;
	}
	int symblos[256];
	for(int i = 0; i < 256; i++)
	{
		symblos[i] = 0;
	}
	for(int i = 0; i < str1.size(); i++)
	{
		symblos[str1[i]]++;
	}
	for(int i = 0; i < str2.size(); i++)
	{
		symblos[str2[i]]--;
	}
	for(int i = 0; i < 256; i++)
	{
		if (symblos[i] != 0)
			return false;
	}
	return true;
}

int main()
{
	std::cout << is_permutation("", "") << std::endl;
	std::cout << is_permutation("abcde", "") << std::endl;
	std::cout << is_permutation("abcde", "abcde") << std::endl;
	std::cout << is_permutation("aaaaa", "bb") << std::endl;
	std::cout << is_permutation("abcdea", "abeacd") << std::endl;
	std::cout << std::endl;
	std::cout << is_permutation2("", "") << std::endl;
	std::cout << is_permutation2("abcde", "") << std::endl;
	std::cout << is_permutation2("abcde", "abcde") << std::endl;
	std::cout << is_permutation2("aaaaa", "bb") << std::endl;
	std::cout << is_permutation2("abcdea", "abeacd") << std::endl;
	return 0;
}