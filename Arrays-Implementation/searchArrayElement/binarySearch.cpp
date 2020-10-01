                                                           // Code for binary search of element inside an array

#include <iostream>
using namespace std;

int main()
{
	int count, i, num, first, last, middle;
                                                               // Taking no. of elements from user
  
	cout<<"How many elements would you like to enter?:"; 
        cin>>count;
        int arr[count];

	for (i=0; i<count; i++)
	{
		cout<<"Enter numbers in accending order "<<(i+1)<<": ";     // Insert elements in ascending order only
                cin>>arr[i];
	}
	cout<<"Enter the number that you want to search:";             // Input element that you want to search inside the array
        cin>>num;
	first = 0;
	last = count-1;
	middle = (first+last)/2;
	while (first <= last)                                           // Binary search algorithm (Divide and conquer technique)
	{
	   if(arr[middle] < num)
	   {
		first = middle + 1;

	   }
	   else if(arr[middle] == num)
	   {
		cout<<num<<" Found in the array at the location "<<middle+1<<"\n"; 
                break; 
           } 
           else { 
                last = middle - 1; 
           } 
           middle = (first + last)/2; 
        } 
        if(first > last)
	{
	   cout<<num<<" Element is not found in the array";
	}
	return 0;
}
