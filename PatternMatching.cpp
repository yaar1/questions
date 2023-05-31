#include<bits/stdc++.h>
using namespace std;
char lowerCase(char ch){
    if(ch>='A' && ch<='Z'){
        ch=ch+32;
    }
    return ch;
}
int search(string str,string pat){
    int n=str.length();
    int m=pat.length();
    int i=0;
    while(i<n)
    {
        string word="";
        int temp=i;
        while(i<n && str[i]!=' '){
            word+=(char)lowerCase(str[i]);
            i++;
        }
        if(word==pat){
            return temp;
        }
        i++;
    }
    return -1;
}
vector<int> findIndex(vector<string>& arr,int n,string pat){
    vector<int> res;
    for(int i=0;i<n;i++){
        int ans=search(arr[i],pat);
        if(ans!=-1){
            res.push_back(ans);
        }
    }
    return res;
}
int main()
{
    int n;
    cin>>n;
    string pat;
    cin>>pat;
    cin.ignore();
    vector<string> arr(n);
    for(int i=0;i<n;i++){
        getline(cin,arr[i]);
    }
    vector<int> ans=findIndex(arr,n,pat);
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}