#include<iostream>
using namespace std;
void arrReverse(int* ptr, int size)
{
    int* start = ptr;
    int* end = ptr + size - 1;
    while(start < end)
    {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = 5;
    arrReverse(arr, size);
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    return 0;
}
