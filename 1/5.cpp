#include <iostream>
#include <string>
#include <sstream>

std::string compress(const std::string& str)
{
	std::stringstream stream;
	char current_char = str[0];
	int counter = 1;
	for(int i = 1; i < str.size(); i++)
	{
		if (str[i] == current_char)
		{
			counter++;
		}
		else
		{
			stream << current_char << counter;
			current_char = str[i];
			counter = 1;
		}
	}
	stream << current_char << counter;
	auto result = stream.str();
	return str.size() < result.size() ? str : result;
}

int main()
{
	std::cout << (compress("") == "") << std::endl;
	std::cout << (compress("abc") == "abc") << std::endl;
	std::cout << (compress("abb") == "abb") << std::endl;
	std::cout << (compress("abbb") == "a1b3") << std::endl;
	std::cout << (compress("aaabbbbcccdd") == "a3b4c3d2") << std::endl;
	return 0;
}