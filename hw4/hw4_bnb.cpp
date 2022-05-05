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
auto showarray(vector<pair<float,pair<float,float>>>&item)
{
    for(auto j=0;j<n;j++)
    {
        cout<<fixed<<setprecision(3);
        cout<<"cost="<<item[j].first<<" price="<<item[j].second.first<<" weight="<<item[j].second.second<<endl;
    } 
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
    //showarray(item);
    sort(item.begin(),item.end(),sortbyfir);
    // cout<<"after sorting:"<<endl;
    //showarray(item);
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
auto bruteforce()
{
    int n, M;
    int P[50];
    int W[50];
    int C[50] = {0};
    scanf("%d %d", &n, &M);
    for(int i = 1; i <= n; i++)
        scanf("%d %d", &P[i], &W[i]);
    auto start = high_resolution_clock::now();

    int temp_p, temp_w, ptr, ans = 0;
    for(int i = 1; i <= pow(2, n); i++){
        ptr = n;
        temp_p = 0;
        temp_w = 0;
        while((C[ptr] != 0) && ptr > 0){
            C[ptr] = 0;
            ptr--;
        }
        C[ptr] = 1;
        for(int j = 1; j <= n; j++)
            if(C[j] == 1){
                temp_p += P[j];
                temp_w += W[j];
            }
        
        /*for(int j = 1; j <= n; j++)
            printf("%d", C[j]);
        printf(": ");
        printf("%d %d\n", temp_p, temp_w);*/
        
        if((temp_p > ans) && (temp_w <= M))
            ans = temp_p;
    }
    printf("%d\n", ans);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
            << float(duration.count()) /1000000<< " seconds" << endl;
    ofstream out;
    out.open("./result2.txt",ios::app);
    out<<n<<" "<<float(duration.count()) /1000000<<endl;
    return 0;

}
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

int main()
{  
    // bruteforce();
    branchandbound();   
    return 0;
}