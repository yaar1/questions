#include<iostream>
using namespace std;
int solve(int arr[],int n,int k,int i,int sum){
    if(i<0){
        if(sum==k){
            return 1;
        }
        return 0;
    }
    int pos=solve(arr,n,k,i-1,sum+arr[i]);
    int neg=solve(arr,n,k,i-1,sum-arr[i]);
    int exc=solve(arr,n,k,i-1,sum);
    return pos+neg+exc;
}
int Combinations(int arr[],int n,int k){
    return solve(arr,n,k,n-1,0);
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
    int ans=Combinations(arr,n,k);
    cout<<ans<<endl;
    return 0;
}