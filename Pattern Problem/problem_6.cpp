#include<iostream>
using namespace std;
int main()
{
    int n=0;
    cout<<"Enter the no of rows : ";
    cin>>n;
    int k = 'A';
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<(char)k<<"\t";
        }
        k++;
        cout<<endl;
    }
    return 0;
}