#include<bits/stdc++.h>
using namespace std;
int solve(int n,int sum,vector<int>&dp){
    if(sum==n){
        return 0;
    }
    if(sum>n){
        return INT_MAX;
    }
    if(dp[sum]!=-1){
        return dp[sum];
    }
    //add
    int add=solve(n,sum+1,dp);
    //mutiply
    int mult=INT_MAX;
    if(sum!=0){
        mult=solve(n,sum*2,dp);
    }
    // cout<<n<<" "<<sum<<endl;
    dp[sum]=1+min(add,mult);
    return dp[sum];
}
int MinOperation(int n){
    vector<int> dp(n+1,-1);
    return solve(n,0,dp);
}
int main()
{
    int n;
    cin>>n;
    int ans=MinOperation(n);
    cout<<ans<<endl;
    return 0;
}