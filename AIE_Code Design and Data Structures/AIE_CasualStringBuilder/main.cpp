#include <iostream>
#include <string>

std::string stringBuilder(std::string words)
{
    

    return words;
}

int main(int argc, char** argv)
{
    std::cout << stringBuilder("3[a]2[bc]") << std::endl;
    std::cout << stringBuilder("3[a2[c]]") << std::endl;
    std::cout << stringBuilder("2[abc]3[cd]ef") << std::endl;
    return 0;
}