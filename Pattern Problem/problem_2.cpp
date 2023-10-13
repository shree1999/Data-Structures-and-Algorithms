#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter Rows number : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=n-1;j>=0;j--)
        {
            cout<<j+1<<"\t";
        }
        cout<<"\n";
    }

    return 0;
}