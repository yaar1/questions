#include<iostream>
using namespace std;
int solve(int arr[],int n,int x){
    for(int i=0;i<n;i++){
        if(arr[i]==x){
            x=x*2;
        }
    }
    return x;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int x;
    cin>>x;
    int ans=solve(arr,n,x);
    cout<<ans<<endl;
    return 0;
}