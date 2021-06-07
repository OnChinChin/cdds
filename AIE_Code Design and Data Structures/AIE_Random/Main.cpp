#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double number, answer;
    cout << "Enter a number: ";
    cin >> number;
    answer = sqrt(number);
    cout << "Square root is " << answer << endl;
    cin.get();
    return 0;
}