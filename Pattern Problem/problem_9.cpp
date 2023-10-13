#include<iostream>
using namespace std;
int main()
{
    int n=0;
    cout<<"Enter the no of rows : ";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=n-i;j;j--)
        {
            cout<<" "<<"\t";
        }
        for(int k=1;k<=i;k++)
        {
            cout<<"*"<<"\t";
        }
        cout<<endl;
    }
    return 0;
}