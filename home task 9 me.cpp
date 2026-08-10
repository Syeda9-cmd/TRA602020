#include<iostream>
using namespace std;
void inputArray(int *arr, int size)
{
    cout << "Enter "<< size <<" values:\n";
    for(int i = 0; i < size; i++)
    {
        cin >> *(arr + i);
    }
}
void doubArray(int *arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        *(arr + i) = *(arr + i) * 2;
    }
}
int main()
{
    int arr[3];
    inputArray(arr, 3);
    cout << "Original Array: ";
    for(int i = 0; i < 3; i++)
    {
        cout << *(arr + i) << " ";
    }
    doubArray(arr, 3);
    cout << "\nDoubled Array(new): ";
    for(int i = 0; i < 3; i++)
    {
        cout << *(arr + i) << " ";
    }
    return 0;
}
