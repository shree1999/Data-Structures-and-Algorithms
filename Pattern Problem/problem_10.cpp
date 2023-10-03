#include<iostream>
using namespace std;
int main()
{
    int n=0;
    cout<<"Enter the no of rows : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=n-i;j>0;j--)
        {
            cout<<"*"<<"\t";
        }
        cout<<"\n";
    }
    return 0;
}