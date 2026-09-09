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
        long long n;
        cin>>n;

        if(n<=999){
            cout<<0<<endl;
            return 0;
        }

        long long num_commas = 0;
        long long n1=n;
        int num = countDigits(n);
        
        int sec_digits = num-1;
        long long second = 0;
        int i = 0;
        while(i<sec_digits){
         second += 9*pow(10,i);
         i++;
        }

        while(num != 3){
            num_commas += ((num-1)/3)*(n1-second);
            n1 = second;
            second = (second - second%10)/10;
            num--;
        }

        cout<<num_commas<<endl;
        return 0;
}