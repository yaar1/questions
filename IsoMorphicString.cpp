#include<bits/stdc++.h>
using namespace std;
bool isIsoMorphic(string str,string pat){
    int n=str.length();
    int m=pat.length();
    if(n!=m){
        return false;
    }
    unordered_map<char,char> map;
    for(int i=0;i<n;i++){
        if(map.find(str[i])!=map.end()){
            if(map[str[i]]!=pat[i]){
                return false;
            }
        }
        else{
            map[str[i]]=pat[i];
        }
    }
    return true;
}
int main()
{
    string str,pat;
    cin>>str>>pat;
    bool ans=isIsoMorphic(str,pat);
    if(ans){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    return 0;
}