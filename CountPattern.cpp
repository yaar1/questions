#include<iostream>
using namespace std;
int solve(string str,string pat){
    string window="";
    for(int i=0;i<pat.length();i++){
        window+=str[i];
    }
    int count=0;
    if(window==pat){
        count++;
    }
    for(int i=pat.length();i<str.length();i++){
        window+=str[i];
        window.erase(0,1);
        if(window==pat){
            count++;
        }
    }
    return count;
}
int main()
{
    string str,pat;
    cin>>str>>pat;
    int ans=solve(str,pat);
    cout<<ans<<endl;
    return 0;
}