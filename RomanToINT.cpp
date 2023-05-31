#include<iostream>
using namespace std;
int valueOf(char ch){
    switch (ch)
    {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return -1;
    }
}
int romanToInt(string str){
    int sum=0;
    int n=str.length();
    for(int i=0;i<n;i++){
        if(i==n-1){
            sum+=valueOf(str[i]);
        }
        else{
            int curr=valueOf(str[i]);
            int next=valueOf(str[i+1]);
            if(curr<next){
                sum-=curr;
            }
            else{
                sum+=curr;
            }
        }
    }
    return sum;
}

string intToRoman(int n){
    int normal[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
    string roman[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    string res;
    for(int i=0;i<13;i++){
        while(n>=normal[i]){
            res+=roman[i];
            n-=normal[i];
        }
    }
    return res;
}
int main()
{
    string str;
    cin>>str;
    int n=romanToInt(str);
    cout<<n<<endl;
    return 0;
}

