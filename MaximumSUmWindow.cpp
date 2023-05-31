// #include<bits/stdc++.h>
// using namespace std;
// bool solve(int arr[],int n,int k,int window){
//     int sum=0;
//     for(int i=0;i<window;i++){
//         sum+=arr[i];
//     }
//     if(sum==k){
//         return true;
//     }
//     for(int i=k;i<n;i++){
//         sum+=arr[i];
//         sum-=arr[i-window];
//         if(sum==k){
//             return true;
//         }
//     }
//     return false;
// }
// int MaximumWindow(int arr[],int n,int k){
//     int maxWindow=0;
//     for(int window=1;window<n;window++){
//         bool ans=solve(arr,n,k,window);
//         if(ans){
//             maxWindow=window;
//         }
//     }
//     return maxWindow;
// }
// int maxSuminKWindow(int arr[],int n,int k){
//     //fixed size window code
//     int sum=0;
//     for(int i=0;i<k;i++){
//         sum+=arr[i];
//     }
//     int maxSum=sum;
//     for(int i=k;i<n;i++){
//         sum+=arr[i];
//         sum-=arr[i-k];
//         maxSum=max(sum,maxSum);
//     }
//     return maxSum;
// }
// int main()
// {
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int k;
//     cin>>k;
//     int ans=maxSuminKWindow(arr,n,k);
//     cout<<ans<<endl;
//     return 0;
// }


#include <iostream>
#include <unordered_map>
using namespace std;

int maxWindowSizeWithSumK(int arr[],int n,int k){
    unordered_map<int,int> map;
    int sum=0,maxLen=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==k){
            maxLen=i+1;
        }
        if(map.find(sum)==map.end()){
            map[sum]=i;
        }
        if(map.find(sum-k)!=map.end()){
            if(maxLen<i-map[sum-k]){
                maxLen=i-map[sum-k];
            }
        }
    }
    return maxLen;
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;

    int maxSize = maxWindowSizeWithSumK(arr, n, k);
    cout << "Maximum window size with sum equal to " << k << ": " << maxSize << endl;

    return 0;
}