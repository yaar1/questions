#include<bits/stdc++.h>
using namespace std;
bool solve(unordered_map<int,list<int>>& adj,int n,int source){
    queue<int> q;
    vector<bool> visited(n,false); 
    q.push(source);
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        for(auto i:adj[temp]){
            if(!visited[i]){
                q.push(i);
                visited[i]=true;
            }
        }
    }
    for(auto i:visited){
        if(i==false){
            return false;
        }
    }
    return true;
}
int main()
{
    int n,know;
    cin>>n>>know;
    unordered_map<int,list<int>> adj;
    for(int i=0;i<n;i++){
        int l,k;
        cin>>l>>k;
        for(int j=0;j<k;j++){
            int data;
            cin>>data;
            adj[l].push_back(data);
        }
    }
    bool ans=solve(adj,n,know);
    if(ans){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    return 0;
}