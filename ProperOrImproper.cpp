#include<bits/stdc++.h>
using namespace std;
bool solve(int arr[],int n,int m){
    unordered_map<int,int> map;
    for(int i=0;i<n;i++){
        int curr=arr[i];
        if(map.find(curr)!=map.end() && i-map[curr]<=m){
            return true;
        }
        map[curr]=i;
    }
    return false;
}
int main()
{
    int n,m;
    cin>>n>>m;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bool ans=solve(arr,n,m);
    if(ans){
        cout<<"Proper"<<endl;
    }
    else{
        cout<<"Improper"<<endl;
    }
    return 0;
}