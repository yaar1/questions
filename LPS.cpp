#include<bits/stdc++.h>
using namespace std;
string reverse(string str){
    int i=0;
    int j=str.length()-1;
    while(i<j){
        char ch=str[i];
        str[i]=str[j];
        str[j]=ch;
        i++;
        j--;
    }
    return str;
}
int LCS(string a,string b,int i,int j,vector<vector<int>>& dp){
    if(i==a.length()){
        return 0;
    }
    if(j==b.length()){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans=0;
    if(a[i]==b[j]){
        ans=1+LCS(a,b,i+1,j+1,dp);
    }
    else{
        ans=max(LCS(a,b,i+1,j,dp),LCS(a,b,i,j+1,dp));
    }
    dp[i][j]=ans;
    return dp[i][j];
}
int LPS(string str){
    string rev=reverse(str);
    int n=str.length();
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return LCS(str,rev,0,0,dp);
}
int main()
{
    string str;
    cin>>str;
    int ans=LPS(str);
    cout<<ans<<endl;
    return 0;
}