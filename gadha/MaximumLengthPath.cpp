#include<bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>>& arr,int n,int m,int i,int j,vector<vector<int>>& dp){
    if(i<0 || j<0 || i>=n || j>=m){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int top=INT_MIN,bottom=INT_MIN,left=INT_MIN,right=INT_MIN;
    if(i>0 && arr[i][j]+1==arr[i-1][j]){
        //top
        top=1+solve(arr,n,m,i-1,j,dp);
    }
    if(i<n-1 && arr[i][j]+1==arr[i+1][j]){
        //bottom
        bottom=1+solve(arr,n,m,i+1,j,dp);
    }
    if(j<m-1 && arr[i][j]+1==arr[i][j+1]){
        //right
        right=1+solve(arr,n,m,i,j+1,dp);
    }
    if(j>0 && arr[i][j]+1==arr[i][j-1]){
        //left
        left=1+solve(arr,n,m,i,j-1,dp);
    }
    dp[i][j]=max(top,max(bottom,max(left,max(right,1))));
    return dp[i][j];
}
int FindMaxLength(vector<vector<int>>& arr,int n,int m){
    int maxi=1;
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int ans=solve(arr,n,m,i,j,dp);
            maxi=max(maxi,ans);
        }
    }
    return maxi;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> mat(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    int ans=FindMaxLength(mat,n,m);
    cout<<ans<<endl;
    return 0;
}