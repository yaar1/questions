#include<bits/stdc++.h>
using namespace std;
int solve(string str,string pat){
    int n=str.length();
    int w=pat.length();
    if(n<w){
        return 0;
    }
    unordered_map<char,int> whash;
    unordered_map<char,int> mhash;
    for(int i=0;i<w;i++){
        mhash[str[i]]++;
        whash[pat[i]]++;
    }
    int count=0;
    if(mhash==whash){
        count++;
    }
    for(int i=w;i<n;i++){
        mhash[str[i]]++;
        mhash[str[i-w]]--;
        if(mhash[str[i-w]]==0){
            mhash.erase(str[i-w]);
        }
        if(mhash==whash){
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