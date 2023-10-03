/*
    1   2   3   4   5   5   4   3   2   1
    1   2   3   4   *   *   4   3   2   1
    1   2   3   *   *   *   *   3   2   1
    1   2   *   *   *   *   *   *   2   1
    1   *   *   *   *   *   *   *   *   1
*/

#include<iostream>
using namespace std;
int main()
{
    int n=0;
    cout<<"Enter the no of rows : ";
    cin>>n;
    for(int row=1;row<=n;row++)
    {
        /* 1st Triangle */
        for(int i=1;i<=n-row+1;i++)
            cout<<i<<"\t";

        /* 1st Space Angle */
        for(int j=row-1;j>0;j--)
            cout<<"*"<<"\t";

        /* 2nd Space angle */
        for(int l=row-1;l>=1;l--)
            cout<<"*"<<"\t";

        /* 2nd Triangle */
        for(int k=n-row+1;k>=1;k--)
            cout<<k<<"\t";
        
        cout<<endl;
    }
    return 0;
}