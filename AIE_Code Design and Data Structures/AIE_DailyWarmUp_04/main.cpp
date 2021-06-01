#include <iostream>
// TODO: Write your function here

bool isValidHexCode(std::string hex)
{

    /*int uppercount = 0;
    int lowercount = 0;
    int digitcount = 0;

    if (hex.size() == 7 && hex[0] == '#')
    {
        for (char c : hex)
        {
            if ((c >= 'a' && c <= 'f') && (c >= 'A' && c <= 'F'))
            {

                return false;
            }
            
        }
        if (uppercount + digitcount == 6 || lowercount + digitcount == 6)
        {

        }
    }*/

    if (hex.size() != 7 && hex[0] == '#')
    {
        return false;
    }
    for (int i = 0; i < hex.length(); i++)
    {
        if ((hex[i] >= 'a' && hex[i] <= 'f') && (hex[i] >= 'A' && hex[i] <= 'F'))
        {
            return false;
        }
        
    }
}

int main()
{
    std::cout << std::boolalpha << isValidHexCode("#CD5C5C") << ": expected true" << std::endl;
    std::cout << std::boolalpha << isValidHexCode("#EAECEE") << ": expected true" << std::endl;
    std::cout << std::boolalpha << isValidHexCode("#eaecee") << ": expected true" << std::endl;
    std::cout << std::boolalpha << isValidHexCode("#CD5C58C") << ": expected false" << std::endl;
    std::cout << std::boolalpha << isValidHexCode("#CD5C5Z") << ": expected false" << std::endl;
    std::cout << std::boolalpha << isValidHexCode("#CD5C&C") << ": expected false" << std::endl;
    std::cout << std::boolalpha << isValidHexCode("#Cd5C&C") << ": expected false" << std::endl;
    std::cout << std::boolalpha << isValidHexCode("CD5C5C") << ": expected false" << std::endl;
}

