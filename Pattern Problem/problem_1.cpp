/*
    1   2   3   4
    1   2   3   4
    1   2   3   4
    1   2   3   4
*/



#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the Rows : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<j+1<<"\t";
        }
        cout<<"\n";
    }

    return 0;
}