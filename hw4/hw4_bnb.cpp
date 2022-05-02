#include <iostream>
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
auto time()
{
    
    auto start = high_resolution_clock::now();
    // Get ending timepoint
    auto stop = high_resolution_clock::now();
 
    // Get duration. Substart timepoints to
    // get duration. To cast it to proper unit
    // use duration cast method
    auto duration = duration_cast<microseconds>(stop - start);
 
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
}
int main()
{
    auto start = high_resolution_clock::now();
    cout<<"hello world"<<endl;
    string s;
    s="fuck";
    cout<<s<<endl;
    // time();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
    return 0;
}