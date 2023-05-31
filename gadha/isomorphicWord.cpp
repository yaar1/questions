#include<bits/stdc++.h>
using namespace std;
bool solve(string s1,string s2){
    unordered_map<string,char>map;
    int i=0;
    int j=0;
    while(i<s1.length()){
        string word="";
        word+=s1[i];
        i++;
        while(s1[i]>='a' && s1[i]<='z'){
            word+=s1[i];
            i++;
        }
        if(map.find(word)!=map.end()){
            if(map[word]!=s2[j]){
                return false;
            }
            j++;
        }
        else{
            map[word]=s2[j];
            j++;
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