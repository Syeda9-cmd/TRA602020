#include<iostream>
using namespace std;
int main()
{
int a;
int b;
int *ptrA;
int *ptrB;
ptrA=&a;
ptrB=&b;
cout<<"enter a value of a:";
cin>>a;
cout<<"enter a value of b:";
cin>>b;
cout<<"assigning value of a :"<<*ptrA<<endl;
cout<<"assigning value of b:"<<*ptrB<<endl;
cout<<"adress stored in ptrA:"<<ptrA<<endl;
cout<<"adress stored in ptrB:"<<ptrB<<endl;
    return 0;
}
