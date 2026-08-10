#include<iostream>
using namespace std;
int maxNum(int* ptr, int size)
{
    int max = *ptr;
    for(int i = 1; i < size; i++)
    {
        if(*(ptr + i) > max)
            max = *(ptr + i);
    }
    return max;
}
int main()
{
    int arr[] = {34, 7, 89, 12, 56, 43};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum: " << maxNum(arr, size) << endl;
    return 0;
}
