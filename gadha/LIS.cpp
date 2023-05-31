#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>& arr,int n,int i,int prev,vector<vector<int>>& dp){
    if(i==n){
        return 0;
    }
    if(dp[i][prev+1]!=-1){
        return dp[i][prev+1];
    }
    int inc=0;
    if(prev==-1 || arr[i]>arr[prev]){
        inc=1+solve(arr,n,i+1,i,dp);
    }
    int exc=solve(arr,n,i+1,prev,dp);
    dp[i][prev+1]=max(inc,exc);
    return dp[i][prev+1];
}
int LIS(vector<int>& arr,int n)
{
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return solve(arr,n,0,-1,dp);
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=LIS(arr,n);
    cout<<ans<<endl;
    return 0;
}