#include <iostream>
#include <string>

bool is_substring(const std::string& str1, const std::string& str2)
{
	return str1.find(str2) != std::string::npos;
}

bool is_cyclic(const std::string& str1, const std::string& str2)
{
	if (str1.size() != str2.size())
	{
		return false;
	}
	if (str1.size() == 0)
	{
		return true;
	}
	return is_substring(str1 + str1, str2);
}

int main()
{
	std::cout << is_cyclic("", "") << std::endl;
	std::cout << !is_cyclic("a", "ab") << std::endl;
	std::cout << is_cyclic("a", "a") << std::endl;
	std::cout << is_cyclic("ab", "ab") << std::endl;
	std::cout << is_cyclic("abcdefg", "efgabcd") << std::endl;
	std::cout << !is_cyclic("abcdefg", "efgrbcd") << std::endl;
	return 0;
}