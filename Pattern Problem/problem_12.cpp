#include<iostream>
using namespace std;
int main()
{
    int n=0;
    cout<<"Enter the no of rows : ";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        /* Spaces */
        for(int j=n-i;j>0;j--)
            cout<<" "<<"\t";
        /* 1st TriAngle */

        for(int k=1;k<=i;k++)
            cout<<k<<"\t";

        /* 2nd Triangle */
        for(int l=i-1;l>0;l--)
            cout<<l<<"\t";
        cout<<endl;
    }
    return 0;
}