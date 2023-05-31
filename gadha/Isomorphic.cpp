#include<bits/stdc++.h>
using namespace std;
bool solve(string s1,string s2){
    unordered_map<char,char>map;
    if(s1.length()!=s2.length()){
        return false;
    }
    for(int i=0;i<s1.length();i++){
        if(map.find(s1[i])!=map.end()){
            if(map[s1[i]]!=s2[i]){
                return false;
            }
        }
        else{
            map[s1[i]]=s2[i];
        }
    }
    return true;
}
int main()
{
    string s1;
    string s2;
    cin>>s1;
    cin>>s2;
    bool ans=solve(s1,s2);
    if(ans){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    return 0;
}