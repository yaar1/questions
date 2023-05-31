#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> sumOfMatrix(vector<vector<int>>& mat1,vector<vector<int>>& mat2,int n){
    vector<vector<int>> res(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int sum=0;
            for(int k=0;k<n;k++){
                sum+=mat1[i][k]*mat2[k][j];
            }
            res[i][j]=sum;
        }
    }
    return res;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> mat1(n,vector<int>(n));
    vector<vector<int>> mat2(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat1[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat2[i][j];
        }
    }
    vector<vector<int>> ans=sumOfMatrix(mat1,mat2,n);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<< " ";
        }
        cout<<endl;
    }
    return 0;
}