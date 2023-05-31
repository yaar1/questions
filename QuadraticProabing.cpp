#include<iostream>
using namespace std;
void insert(int arr[],int n,int table[]){
    for(int i=0;i<n;i++){
        int val=arr[i];
        int hv=val%n;
        if(table[hv]==-1){
            table[hv]=val;
        }
        else{
            for(int j=0;j<n;j++){
                int t=(hv+j*j)%n;
                if(table[t]==-1){
                    table[t]=val;
                    break;
                }
            }
        }
    }
}
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }  
    int table[n];
    for(int i=0;i<n;i++){
        table[i]=-1;
    }
    insert(arr,n,table);
    print(table,n);
    return 0;
}