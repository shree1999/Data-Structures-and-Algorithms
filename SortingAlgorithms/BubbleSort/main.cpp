/* This program is based on Bubble sort Sorting algorithm where size and elements of array are  entered by user
time complexity O(n^2)
space Complexity O(1)
*/
#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int i,j,n,temp,arr[5];
    cout<<"size of an array:";
    cin>>n;
    cout<<"enter the elements of the array";
    for(i=0;i<n;i++)
        cin>>arr[i];
        cout<<" ";
    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<" sorting an array using bubble sort:";
    for(i=0;i<n;i++)
    {
    for(j=0;j<n-i-1;j++)
      {

        if(arr[j]>arr[j+1])
          {

           temp=arr[j];
           arr[j]=arr[j+1];
           arr[j+1]=temp;

          }
      }
    }
    cout<<" sorted array:";
    for(j=0;j<n;j++)
    cout<<arr[j]<<" ";
    return 0;
}
