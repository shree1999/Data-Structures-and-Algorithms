//Given two arrays: a1[0..n-1] of size n and a2[0..m-1] of size m. Task is to check whether a2[] is a subset of a1[] or not.
//Both the arrays can be sorted or unsorted. It may be assumed that elements in both array are distinct.
 

string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int,int> a1map;
    int i,c=0;
    for(i=0;i<n;i++)
   a1map[a1[i]]++;
    for(i=0;i<m;i++)
    {
        if(!a1map[a2[i]])
        {
            return "No";
        }
        c++;
    }
    if(c==m)
    return "Yes";
    
    return "No";
    
}
