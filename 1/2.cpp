#include <iostream>

void reverse(char* str)
{
    int length = 0;
    while(str[length] != '\0')
    {
        length++;
    }
    length--;
    for (int i = 0; i <= length/2; ++i)
    {
        auto tmp = str[i];
        str[i] = str[length-i];
        str[length-i] = tmp;
    }
}

int main()
{
    char str[] = "string";
    std::cout << str << " -> ";
    reverse(str);
    std::cout << str << std::endl;
    return 0;
}