//Code for searching an element inside an array

#include<iostream>
using namespace std;

int main()
{
        int arr[100], i, num, n, found=0, pos;
        // Taking user defined array size 
        
        cout<<"\n Enter Array Size : ";
        cin>>n;
        // Taking elements as input
        
        cout<<"\n Enter Array Elements : \n";
        for(i=0; i<n; i++)
        {
                cout<<" ";
                cin>>arr[i];
        }
        // Element that we want to search inside the array
        
        cout<<"\n Enter Element to be Searched : ";
        cin>>num;
        // for loop for traversing elements one by one (Linear Search)
        
        for(i=0; i<n; i++)
        {
                if(arr[i]==num)
                {
                        found=1;
                        pos=i+1;      // pos variable wiil track the index of the element
                        break;
                }
        }
        if(found==0)
        {
                cout<<"\n Element Not Found..!!";
        }
        else
        {
                cout<<"\n Element "<<num<<" Found At Position "<<pos;
        }
        return 0;
}

