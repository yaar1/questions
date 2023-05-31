#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>& arr,int n,int i,int k){
    if(i>=n){
        return;
    }
    int s=i;
    int e=i+k-1<n?i+k-1:n-1;
    while(s<e){
        int temp=arr[s];
        arr[s]=arr[e];
        arr[e]=temp;
        s++;
        e--;
    }
    solve(arr,n,i+k,k);
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    solve(arr,n,0,k);
    for(auto i:arr){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}