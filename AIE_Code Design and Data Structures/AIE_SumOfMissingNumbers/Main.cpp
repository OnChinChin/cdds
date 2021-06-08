#include <iostream>
#include<vector>
// TODO: Write the sumMissingNumbers method here
void SumMissingNumbers(int arr[], int n) 
{
    int min = sizeof(arr[0]);
    
    // to find max
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > min)
        {
            min = arr[i];
        }
    }

}

int main(int argc, char** argv)
{
    int arr[] = { 1, 2, 3, 5, 6, 7, 8, 10, 12 };

    int n = 2 + sizeof(arr) / sizeof(arr[0]);
    
    SumMissingNumbers(arr, n);

   

   

    return 0;
    // TODO: write tests to verify your output
}