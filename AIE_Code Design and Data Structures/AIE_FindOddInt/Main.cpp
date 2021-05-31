#include <iostream>
// TODO: Write the FindOdd function


int FindOdd(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int count = 0;

        for (int j = 0; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }

            if (count % 2 != 0)
            {
                return arr[i];
            }
        }
    }
    return -1;
}

//void FindOdd()
//{
//    int arr[100];
//    int size;
//    int odd = 0;
//    int even = 0;
//
//    
//
//    std::cout << "Enter size of array" << std::endl;
//    std::cin >> size;
//    std::cout << "\nEnter elements of array" << std::endl << std::endl;
//
//    for (int i = 0; i < size; i++)
//    {
//        std::cout << "Enter the element[" << i << "]: " << std::endl;
//        std::cin >> arr[i];
//    }
//
//    for (int i = 0; i < size; i++)
//    {
//        if (arr[i] % 2 == 0)
//        {
//            even++;
//        }
//        else
//        {
//            odd++;
//        }
//    }
//    
//    std::cout << "Total odd:" << odd;
//}

int main(int argc, char** argv)
{
    int arr[] = { 1,1,1,2,2,4,4 };
    int arr1[] = { 2,2,2,1,3,3,1 };
    int arr2[] = {2, 3, 4, 4, 1, 2, 1};

    int c = sizeof(arr) / sizeof(arr[0]);
    int a = sizeof(arr1) / sizeof(arr1[0]);
    int b = sizeof(arr2) / sizeof(arr2[0]);

    std::cout << FindOdd(arr, c) << std::endl;
    std::cout << FindOdd(arr1, a) << std::endl;
    std::cout << FindOdd(arr2, b) << std::endl;
    
    // TODO: write test code to verify your function works as expected
    return 0;
}