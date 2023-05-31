#include<bits/stdc++.h>
using namespace std;
vector<int> solve(int arr[],int n,int window){
    vector<int> ans;
    for(int i=0;i<=n-window;i++){
        int negativeNumber=-1;
        for(int j=i;j<i+window;j++)
        {
            if(arr[j]<0){
                negativeNumber=j;
                break;
            }
        }
        if(negativeNumber!=-1){
            ans.push_back(arr[negativeNumber]);
        }
        else{
            ans.push_back(0);
        }
    }
    return ans;
}
vector<int> solveO(int arr[],int n,int window){
    deque<int> q;
    for(int i=0;i<window;i++){
        if(arr[i]<0){
            q.push_back(i);
        }
    }
    vector<int> ans;
    if(!q.empty()){
        ans.push_back(arr[q.front()]);
    }
    else{
        ans.push_back(0);
    }
    for(int i=window;i<n;i++){
        if(arr[i]<0){
            q.push_back(i);
        }
        if(q.front()==i-window){
            q.pop_front();
        }
        if(!q.empty()){
            ans.push_back(arr[q.front()]);
        }
        else{
            ans.push_back(0);
        }
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int window;
    cin>>window;
    vector<int> ans=solveO(arr,n,window);
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}