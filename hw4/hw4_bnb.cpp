#include <iostream>
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
// bool compare(const pair<pair<float,float>,float>&i, const pair<pair<float,float>,float>&j) 
// { 
//     return i.second < j.second; 
// } 
bool sortbyfir(const pair<float,pair<float,float>> &a,
                   const pair<float,pair<float,float>> &b)
{
       return a.first>b.first;
}
auto bruteforce()
{

    vector<pair<float,pair<float,float>>>item;
    int n;
    float capacity;
    cin>>n>>capacity;
    for(auto i=0;i<n;i++)
    {
        // int price,capa;
        float cost;
        // pair<float,float>tmp;
        pair<float,pair<float,float>>tmpp;
        cin>>tmpp.second.first>>tmpp.second.second;
        cost=(tmpp.second.first/tmpp.second.second);
        tmpp.first=cost;
        item.push_back(tmpp);
    }
    cout<<"test"<<endl;
    for(auto j=0;j<n;j++)
    {
        cout<<fixed<<setprecision(3);
        cout<<"cost="<<item[j].first<<" price="<<item[j].second.first<<" weight="<<item[j].second.second<<endl;
    }
    sort(item.begin(),item.end(),sortbyfir);
    cout<<"after sorting:"<<endl;
    for(auto j=0;j<n;j++)
    {
        cout<<fixed<<setprecision(3);
        cout<<"cost="<<item[j].first<<" price="<<item[j].second.first<<" weight="<<item[j].second.second<<endl;
    }
    float ans=0;
    for(auto &k:item)
    {
        if(k.second.second<=capacity)
        {
            capacity-=k.second.second;
            ans+=k.second.first;
        }
        else break;
    }

    cout<<"ans="<<ans<<endl;
}
/*
P W
10 269
55 95
10 4
47 60
5 32
4 23
50 72 
8 80 
61 62 
85 65
87 46
*/
auto branchandbound(){
/*
please implement you code here, gg:)
*/
}
int main()
{

    auto start = high_resolution_clock::now();
    bruteforce();
    // branchandbound();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
    return 0;
}