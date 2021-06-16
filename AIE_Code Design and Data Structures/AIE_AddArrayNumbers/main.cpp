#include<iostream>
#include<utility>
#include<vector>


std::pair<int,int> arrayNumbers(std::vector<int> arr, int result)
{
	for (int i = 0; arr.size(); i++)
	{
		for (int j = i + 1; arr.size(); i++)
		{
			if (arr[i] + arr[j] == result)
			{
				return std::make_pair(arr[i], arr[j]);
			}
		}
	}
	return std::make_pair(0,0);
}

int main(int argc, char** argv)
{
	std::pair<int, int> arr = arrayNumbers({ 1, 4, 8, 9, 12 }, 13);
	std::cout << arr.first << " " << arr.second << std::endl;
	std::pair<int, int> arr1 = arrayNumbers({ 1, 2, 3, 7, 8, 9 }, 10); // output [8, 2] or [1, 9] or [7, 3] any of these are acceptable
	std::cout << arr1.first << " " << arr1.second << std::endl;
	std::pair<int, int> arr2 = arrayNumbers({1 , 7, 12, 13, 14, 15, 16, 17 }, 20); // output: [5, 15] or [7, 13]
	std::cout << arr2.first << " " << arr2.second << std::endl;

	return 0;
}