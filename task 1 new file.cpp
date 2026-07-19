#include<iostream>
using namespace std;
int main()
{
	  int arr[5]={10,20,30,40,50};
    int *ptr=&arr[2];
    cout<<"Value:"<< *ptr<<endl;
    cout<<"Adress:"<< ptr<<endl;

    return 0;
}
