#include<bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>>& arr,int n,int m,int i,int j,vector<vector<int>>& dp){
    if(i==0 && j==0){
        return arr[0][0];
    }
    if(i<0 || j<0){
        return INT_MAX;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int top=solve(arr,n,m,i-1,j,dp);
    int left=solve(arr,n,m,i,j-1,dp);
    dp[i][j]=arr[i][j]+min(top,left);
    return dp[i][j];
}
int MinCost(vector<vector<int>>& arr,int n,int m){
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    return solve(arr,n,m,n-1,m-1,dp);
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int ans=MinCost(arr,n,m);
    cout<<ans<<endl;
    return 0;
}