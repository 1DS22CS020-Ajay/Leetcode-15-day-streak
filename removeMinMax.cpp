#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int>nums;
    vector<int>nums1;
    int ele;
    for(int i=0;i<n;i++){
       cin>>ele;
       nums.push_back(ele);
       nums1.push_back(ele);
    }

    sort(nums1.begin(),nums1.end());

    int mn = nums1[0];
    int mx = nums1[n-1];

    int mn_index = 0;
    int mx_index = 0;
    for(int i=0;i<n;i++){
        if(nums[i]==mn){
            mn_index = i;
        }
        else if(nums[i]==mx){
            mx_index = i;
        }
    }
    int min_removals;
    int mn_dist = mn_index -0+1;
    int mx_dist = n-1-mx_index+1;
    if(mn_index > mx_index){
        min_removals = min(mn_index-0+1,n-1-mx_index+1);
        mn_dist = n-1-mn_index+1;
        mx_dist = mx_index-0+1;
    }
    else if(mx_index > mn_index){
        min_removals = min(mx_index-0+1,n-1-mn_index+1);

    }

    if(mn_dist >= n-1-mn_index+1 && mn_index > mx_index){
        mn_dist = n-1-mn_index+1;
    }
    if(mx_dist >= mx_index-0+1 && mx_index < mn_index){
        mx_dist = mx_index-0+1;
    }
    min_removals = min(min_removals,mn_dist + mx_dist);
    
    cout<<min_removals<<endl;
    return 0;
    
}