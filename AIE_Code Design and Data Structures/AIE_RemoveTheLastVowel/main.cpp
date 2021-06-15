#include<iostream>
#include<string>
#include<vector>
#include<sstream>

std::string removeVowel(std::string str)
{
    std::vector<char> vowels = { 'a','e' ,'i' ,'o' ,'u','A','E','I','O','U' };

    std::istringstream iss(str);
    std::vector<std::string> result;
    for (std::string s; iss >> s;)
    {
        result.push_back(s);
    }
    int n = result.size();
    for (int i = 0; i < n; i++)
    {
        std::cout << result[i] << std::endl;
    }
   

    for (int i = str.length() -1; i >= 0; i--)
    {
        if (std::find(vowels.begin(), vowels.end(), str[i]) != vowels.end())
        {
            str = str.replace(i, 1, "");
            i -= 2;
        }
    }
    return str;
}

int main(int argc, char** argv)
{

    std::string str = "Those who dare to fail miserably can achieve greatly";
    std::string str1 = "Love is a serious mental disease.";
    std::string str2 = "Get busy living or get busy dying.";
        

    std::cout << removeVowel(str) << std::endl;
 

    
    // TODO: write tests to verify your output
    //split or explode
}