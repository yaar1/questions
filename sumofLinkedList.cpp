// #include<iostream>
// using namespace std;
// class Node{
//     public:
//     int data;
//     Node* next;
//     Node(int val){
//         this->data=val;
//         this->next=NULL;
//     }
// };
// class LinkedList{
//     public:
//     Node* head=NULL;
//     Node* tail=NULL;
//     void insertAtTail(int val){
//         Node* newNode=new Node(val);
//         if(head==NULL && tail==NULL){
//             head=newNode;
//             tail=newNode;
//             return;
//         }
//         tail->next=newNode;
//         tail=newNode;
//     }
//     void reverse(){
//         Node* curr=head;
//         Node* prev=NULL;
//         while(curr!=NULL){
//             Node* next=curr->next;
//             curr->next=prev;
//             prev=curr;
//             curr=next;
//         }
//         tail=head;
//         head=prev;
//     }
//     void print(){
//         Node* temp=head;
//         while(temp!=NULL){
//             cout<<temp->data<<" ";
//             temp=temp->next;
//         }
//         cout<<endl;
//     }
// };
// void print(Node* head){
//     Node* temp=head;
//     while(temp!=NULL){
//         cout<<temp->data<<" ";
//         temp=temp->next;
//     }
//     cout<<endl;
// }
// void reverse(Node* &head){
//     Node* curr=head;
//     Node* prev=NULL;
//     while(curr!=NULL){
//         Node* next=curr->next;
//         curr->next=prev;
//         prev=curr;
//         curr=next;
//     }
//     head=prev;
// }
// void insertAtTail(Node*& head,Node* &tail,int val){
//     Node* newNode=new Node(val);
//     if(head==NULL && tail==NULL){
//         head=newNode;
//         tail=newNode;
//         return;
//     }
//     tail->next=newNode;
//     tail=newNode;
// }
// Node* solve(Node* curr1,Node* curr2)
// {
//     Node* head=NULL;
//     Node* tail=NULL;
//     int carry=0;
//     while(curr1!=NULL || curr2!=NULL || carry!=0){
//         int temp1=0,temp2=0;
//         if(curr1!=NULL){
//             temp1=curr1->data;
//         }
//         if(curr2!=NULL){
//             temp2=curr2->data;
//         }
//         int sum=temp1+temp2+carry;
//         int data=sum%10;
//         carry=sum/10;
//         insertAtTail(head,tail,data);
//         if(curr1!=NULL){
//             curr1=curr1->next;
//         }
//         if(curr2!=NULL){
//             curr2=curr2->next;
//         }
//     }
//     return head;
// }
// Node* sum(Node* head1,Node* head2){
//     reverse(head1);
//     reverse(head2);
//     Node* ans=solve(head1,head2);
//     reverse(ans);
//     return ans;
// }
// int main()
// {
//     int n,m;
//     cin>>n>>m;
//     LinkedList l1;
//     LinkedList l2;
//     for(int i=0;i<n;i++){
//         int data;
//         cin>>data;
//         l1.insertAtTail(data);
//     }
//     for(int i=0;i<m;i++){
//         int data;
//         cin>>data;
//         l2.insertAtTail(data);
//     }
//     Node* head=sum(l1.head,l2.head);
//     print(head);
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
vector<int> solve(int arr1[],int n,int arr2[],int m){
    vector<int> res;
    int i=n-1;
    int j=m-1;
    int carry=0;
    while(i>=0 || j>=0 || carry!=0){
        int t1=0,t2=0;
        if(i>=0){
            t1=arr1[i];
        }
        if(j>=0){
            t2=arr2[j];
        }
        int sum=t1+t2+carry;
        int data=sum%10;
        carry=sum/10;
        res.push_back(data);
        if(i>=0){
            i--;
        }
        if(j>=0){
            j--;
        }
    }
    reverse(res.begin(),res.end());
    return res;
}
int main()
{
    int n,m;
    cin>>n>>m;
    int arr1[n];
    int arr2[m];
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }
    vector<int> ans=solve(arr1,n,arr2,m);
    for(auto i:ans){
        cout<<i<<" ";
    }cout<<endl;
    return 0;
}