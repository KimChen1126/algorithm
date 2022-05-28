#include <iostream>
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
/*
7 3
12
3
5
7
4
19
26
*/
int findmedian(vector<int>&,int,int);
void mysort(vector<int>&arr,int left,int right)
{
    int i,j,v;
    for(i = left+1; i <= right; i++) {
            v = arr[i];
            j = i;
            while(j-1 >= left && arr[j-1] > v)
            {
                arr[j] = arr[j-1];
                j--;
            }
            arr[j] = v;
    }
}
int pruneandsearch(vector<int>&arr,int left,int right, int target)
{      
    if(right-left+1 <= 5) {
        int i, j, v;
        mysort(arr,left,right);
        return left+target;
    }   
    int pivot = findmedian(arr, left,right);
    swap(arr[left], arr[pivot]);
    int i, j;
    int t = arr[left];
    for(i = left, j = left+1; j <= right; j++) {
        if(arr[j] <= t)
        {           
            i++;
            swap(arr[i], arr[j]);
            
        }    
    }
    swap(arr[left], arr[i]);
    // partition end.
    int position = i;
    if(position-left == target)    
        return position;
    if(position-left < target)
        return pruneandsearch(arr, position+1, right, target-(position-left+1));
    else
        return pruneandsearch(arr, left, position, target);
}
int findmedian(vector<int>&arr, int l, int r) {
    int med = (r-l+4)/5;
    int i, subleft, subright;
    int medIdx;
    for(i = 0; i < med; i++) {
        subleft = l + i*5;
        subright = subleft + 4;
        if(subright > r)    
            subright = r;
        medIdx = pruneandsearch(arr, subleft, subright, (subright-subleft)/2);
        swap(arr[l+i], arr[medIdx]);
    }
    
    return pruneandsearch(arr, l, l+med, med/2);
}
int main()
{
    vector<int>arr;
    int n,k,tmp;
    cin>>n>>k;
    // cout<<n<<k;
    for(auto i=0;i<n;i++)
    {   
        cin>>tmp;
        arr.push_back(tmp);
    }
    auto start = high_resolution_clock::now();
    int idx=pruneandsearch(arr,0,n-1,k-1);
    cout<<arr[idx]<<endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << float(duration.count()) /1000000<< " seconds" << endl;
    ofstream out;
    out.open("./result.txt",ios::app);
    out<<n<<" "<<float(duration.count()) /1000000<<endl;
    return 0;
}