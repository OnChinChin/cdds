#include <iostream>

#include<vector>
// TODO: Write your function here


bool isMiniSudoku(std::vector<std::vector<int>>grid)
{
    //check column

    int numbers[9] = 
    {
        0,0,0,
        0,0,0,
        0,0,0 
    };

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int val = grid[i][j];
            if (val <= 0 || val > 9)
            {
                return false;
            }
            numbers[val - 1]++;
        }
       
    }

    bool valid = true;
    for (auto& i : numbers)
    {
        if (i != 1)
        {
            valid = false;
        }
    }

    return true;
}






int main()
{
    std::cout << std::boolalpha;
    std::cout << isMiniSudoku({ {1, 3, 2}, {9, 7, 8}, {4, 5, 6} }) << "Expected true" << std::endl;
    std::cout << isMiniSudoku({ {8, 9, 2}, {5, 6, 1}, {3, 7, 4} }) << "Expected true" << std::endl;
    std::cout << isMiniSudoku({ {1, 1, 3}, {6, 5, 4}, {8, 7, 9} }) << "Expected false" << std::endl; // The 1 is repeated twice 
    std::cout << isMiniSudoku({ {0, 1, 2}, {6, 4, 5}, {9, 8, 7} }) << "Expected false" << std::endl; // The 0 is included (outside range)
    return 0;
}
