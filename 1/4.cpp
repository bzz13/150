#include <iostream>
#include <string>
#include <sstream>

std::string translate_space_tohtml_code(const std::string& str)
{
	std::stringstream stream;
	for(int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
		{
			stream << "%20";
		}
		else
		{
			stream << str[i];
		}
	}
	return stream.str();
}

int main()
{
	std::cout << translate_space_tohtml_code("Mr John Smith") << std::endl;
	std::cout << translate_space_tohtml_code("MrJohnSmith") << std::endl;
	std::cout << translate_space_tohtml_code("    ") << std::endl;
	return 0;
}