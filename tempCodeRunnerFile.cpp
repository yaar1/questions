vector<int> ans;
    set<int> s;
    for(int i=0;i<k;i++){
        s.insert(arr[i]);
    }
    ans.push_back(*(s.end()));
    for(int i=k;i<n;i++){
        s.insert(arr[i]);
        s.erase(arr[i-k]);
        ans.push_back(*(--s.end()));
    }
    return ans;