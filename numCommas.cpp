#include<bits/stdc++.h>
using namespace std;

int countDigits(int n){
    int d=0;
    while(n!=0){
        n = n/10;
        d++;
    }
    return d;
}

int main(){
    int n;
    cin>>n;

    int num_commas = 0;
    int num = countDigits(n);
    while(num!=3){ 
        num_commas += (num-1)/3;
        if(n<0) break;
        n--;
        num = countDigits(n);
    }

    cout<<num_commas<<endl;
    return 0;
}