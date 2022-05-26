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
int partition(vector<int> &v, int start, int end){
	
	int pivot = end;
	int j = start;
	for(int i=start;i<end;++i){
		if(v[i]<v[pivot]){
			swap(v[i],v[j]);
			++j;
		}
	}
	swap(v[j],v[pivot]);
	return j;
	
}
void QQsort(vector<int> &arr,int start,int end)
{
    if (start<end)
    {
        int p=partition(arr,start,end);
        QQsort(arr,start,p-1);
		QQsort(arr,p+1,end);
    }
}
void quicksort()
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
    int size=arr.size()-1;
    int begin=0;
    QQsort(arr,begin,size);
    cout<<arr[k-1]<<endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    cout << "Time taken by function: "
         << float(duration.count()) /1000000<< " seconds" << endl;
    ofstream out;
    out.open("./qsort_result.txt",ios::app);
    out<<n<<" "<<float(duration.count()) /1000000<<endl;
    return ;
 
}
int main()
{
    quicksort();
    return 0;
}