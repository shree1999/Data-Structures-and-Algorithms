#include<iostream>
using namespace std;
int main()
{
    int n =0 ;
    cout<<"Enter the no of rows : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<i+1<<"\t";
        }
        cout<<endl;
    }
    return 0;
}