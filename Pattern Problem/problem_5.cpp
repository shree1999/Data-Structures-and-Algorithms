#include<iostream>
using namespace std;
int main()
{
    int n=0;
    cout<<"Enter the no of rows : ";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int k = i;
        for(int j=1;j<=i;j++)
        {
            cout<<k++<<"\t";
        }
        cout<<endl;
    }
    return 0;
}