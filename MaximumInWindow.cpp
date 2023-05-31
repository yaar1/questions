#include<bits/stdc++.h>
using namespace std;
vector<int> solve(int arr[],int n,int k){
    deque<int> q;
    vector<int> ans;
    for(int i=0;i<k;i++){
        while(!q.empty() && arr[q.back()]<arr[i]){
            q.pop_back();
        }
        q.push_back(i);
    }
    ans.push_back(arr[q.front()]);
    for(int i=k;i<n;i++){
        if(q.front()==i-k){
            q.pop_front();
        }
        while(!q.empty() && arr[q.back()]<arr[i]){
            q.pop_back();
        }
        q.push_back(i);
        ans.push_back(arr[q.front()]);
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    vector<int> ans=solve(arr,n,k);
    for(auto i:ans){
        cout<<i<<  " ";
    }
    cout<<endl;
    return 0;
}