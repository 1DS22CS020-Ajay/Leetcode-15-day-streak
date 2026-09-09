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
    int d = countDigits(n);
    cout<<d<<endl;
    return 0;
}