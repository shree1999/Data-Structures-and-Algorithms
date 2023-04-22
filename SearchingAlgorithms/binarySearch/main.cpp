#include <iostream>
#include <vector>
#include <string>


using namespace std;
//===========BinarySearch for Static Array=============
int BinarySearch(int arr[], int begin, int n, int item){
    if(n == 0)
        return -1;
    else{
      int lastindex = n + begin -1;
      if(item == arr[begin])
        return begin;
      else if(item == arr[lastindex])
        return lastindex;
      else{
        int middle = (n/2 -1) + begin;
        if(item > arr[middle])
            BinarySearch(arr, middle+1 , n/2 , item);
        else if(item == arr[middle])
            return arr[middle];
        else
            BinarySearch(arr, begin , n/2  , item);
    }
   }
}

//===========BinarySearch for Dynamic Array -Vector-=========
int search(int arr[] , int n ,  int item){
    int index {0};
    return index = BinarySearch(arr, 0 , n , item);
}

//Binary search for Vector

int BinarySearch(vector <int> arr, int begin, int n, int item){
    if(n == 0)
        return -1;
    else{
      int lastindex = n + begin -1;
      if(item == arr[begin])
        return begin;
      else if(item == arr[lastindex])
        return lastindex;
      else{
        int middle = (n/2 -1) + begin;
        if(item > arr[middle])
            BinarySearch(arr, middle+1 , n/2 , item);
        else if(item == arr[middle])
            return arr[middle];
        else
            BinarySearch(arr, begin , n/2  , item);
    }
   }
}

int search(vector<int> arr ,  int item){
    int n = arr.size();
    int index {0};
    return index = BinarySearch(arr, 0 , n , item);
}
int main(){
  int arr[]{1,4,6,9,12,34};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << search(arr ,n, 34) << endl;
  cout<<"Hello World!"<<endl; 
    
	return 0;
}
