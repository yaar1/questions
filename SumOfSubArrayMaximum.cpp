#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int sum_of_max_subarrays(const std::vector<int>& arr) {
    int n = arr.size();
    int sum=0;
    for(int i=0;i<n;i++){
        int maxi=INT_MIN;
        for(int j=i;j<n;j++){
            maxi=max(maxi,arr[j]);
            sum+=maxi;
        }
    }
    return sum;
}
int main()
{
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int result = sum_of_max_subarrays(arr);
    std::cout << result << std::endl;

    return 0;
}