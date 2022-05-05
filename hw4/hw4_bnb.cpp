#include <iostream>
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
int n;
struct Node
{
    int lv,profit,bound;
    float weight;
};
bool sortbyfir(const pair<float,pair<float,float>> &a,
                   const pair<float,pair<float,float>> &b)
{
       return a.first>b.first;
}
int bound(Node u, int n,float capacity,vector<pair<float,pair<float,float>>>&item)
{
    if(u.weight>=capacity)return 0;
    int probound=u.profit;
    int j=u.lv+1;
    int total=u.weight;
    while((j<n)&&(total+item[j].second.second<=capacity))
    {
        total+=item[j].second.second;
        probound+=item[j].second.first;
        j++;
    }
    if(j<n)
    {
        probound+=(capacity-total)*item[j].first;
    }
    return probound;
}
auto branchandbound()
{
    vector<pair<float,pair<float,float>>>item;//item cost value, weight 
    float capacity;
    cin>>n>>capacity;
    
    for(auto i=0;i<n;i++)
    {
     
        float cost;
        pair<float,pair<float,float>>tmpp;
        cin>>tmpp.second.first>>tmpp.second.second;
        cost=(tmpp.second.first/tmpp.second.second);
        tmpp.first=cost;
        item.push_back(tmpp);
    }
    auto start = high_resolution_clock::now();
    // cout<<"test"<<endl;
    // for(auto j=0;j<n;j++)
    // {
    //     cout<<fixed<<setprecision(3);
    //     cout<<"cost="<<item[j].first<<" price="<<item[j].second.first<<" weight="<<item[j].second.second<<endl;
    // }
    sort(item.begin(),item.end(),sortbyfir);
    // cout<<"after sorting:"<<endl;
    // for(auto j=0;j<n;j++)
    // {
    //     cout<<fixed<<setprecision(3);
    //     cout<<"cost="<<item[j].first<<" price="<<item[j].second.first<<" weight="<<item[j].second.second<<endl;
    // }
    queue<Node>Q;
    Node u,v;
    u.lv=-1;
    u.profit=u.weight=0;
    Q.push(u);
    int ans=0;
    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();
        if(u.lv==-1)v.lv=0;
        if(u.lv==n-1)continue;
        v.lv=u.lv+1;
        v.weight=u.weight+item[v.lv].second.second;
        v.profit=u.profit+item[v.lv].second.first;

        if(v.weight<=capacity&&v.profit>ans)ans=v.profit;
        v.bound=bound(v,n,capacity,item);
        if (v.bound>ans)Q.push(v);

        v.weight=u.weight;
        v.profit=u.profit;
        v.bound=bound(v,n,capacity,item);
        if(v.bound>ans)
        Q.push(v);
    }

    cout<<"ans="<<ans<<endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << float(duration.count()) /1000000<< " seconds" << endl;
    ofstream out;
    out.open("./result.txt",ios::app);
    out<<n<<" "<<float(duration.count()) /1000000<<endl;
    return 0;
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
auto bruteforce(){
/*
 you code here, gg:)
*/

/* time function
auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << float(duration.count()) /1000000<< " seconds" << endl;
    ofstream out;
    out.open("./result2.txt",ios::app);
    out<<n<<" "<<float(duration.count()) /1000000<<endl;
    return 0;
*/
}
int main()
{  
    //bruteforce();
    branchandbound();   
    return 0;
}