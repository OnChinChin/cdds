#include <iostream>
#include <cstring>
// TODO:
// Create a function that returns the number of characters shared between two words.
int SharedLetters(std::string word1, std::string word2)
{
    int count = 0;

    for (int i = 0; i < word1.length(); i++)
    {
        for (int j = 0; j < word2.length(); j++)
        {
            if (word1[i] == word2[j])
            {
                count++;
            }
            
        }
    }
    return count;
}

int main()
{
    std::cout << SharedLetters("apple", "meaty") << std::endl; // 2
    std::cout << SharedLetters("fan", "forsook") << std::endl; // 1
    std::cout << SharedLetters("fanf", "forsookf") << std::endl; // 2
    std::cout << SharedLetters("fan", "forsookf") << std::endl; // 1
    std::cout << SharedLetters("spout", "shout") << std::endl; // 4
}
