#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int>nums;
    int ele;
    for(int i=0;i<n;i++){
        cin>>ele;
        nums.push_back(ele);
    }

    int target;
    cin>>target;

    sort(nums.begin(),nums.end());
    vector<int>ans;
    for(int i=0;i<n-2;i++){
        if(i>0 && nums[i]==nums[i-1]){
            continue;
        }
        int j = i+1;
        int k = n-1;
        while(j<k){
            int sum = nums[i]+nums[j]+nums[k];
            ans.push_back(sum);
            if(j>i+1 && nums[j] == nums[j-1]){
                j++;
            }
            else if(k<n-1 && nums[k] == nums[k+1]){
                k--;
            }
            else if(sum<=target){
                j++;
            }
            else{
                k--;
            }   
        }
    }

    int min_diff = INT_MAX;
    int final_ans = 0;
    for(auto sum:ans){
        int diff = abs(sum - target);
        if(diff<min_diff){
            min_diff = diff;
            final_ans = sum;
        }
    }
    cout<<final_ans<<endl;
    return 0;
}