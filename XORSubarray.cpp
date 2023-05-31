#include<iostream>
using namespace std;
int calculateXOR(int arr[], int n)
{
    int xorSum=0;
    for(int i=0;i<n;i++){
        int temp=0;
        for(int j=i;j<n;j++){
            temp^=arr[j];
            xorSum^=temp;
        }
    }
    return xorSum;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=calculateXOR(arr,n);
    cout<<ans<<endl;
    return 0;
}