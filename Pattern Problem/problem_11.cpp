#include<iostream>
using namespace std;
int main()
{
    int n=0;
    cout<<"Enter the no of rows : ";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        /* space */
        for(int j=i-1;j>0;j--)
            cout<<" "<<"\t";
        
        for(int k= n-i+1;k>0;k--)
            cout<<"*\t";
        cout<<endl;
    }
    return 0;
}