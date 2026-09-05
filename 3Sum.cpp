#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int> nums;
    int ele;
    for(int i=0;i<n;i++){
        cin>>ele;
        nums.push_back(ele);
    }

    sort(nums.begin(),nums.end());

    vector<vector<int>> res;
    int zeroCons = 0;
    for(int i=0;i<n-2;i++){
        if(i>0 && nums[i]==nums[i-1]){
            continue;
        }
        vector<int>ans;
        int j = i+1;
        int k = n-1;
        while(j<k){
            int target = 0 - nums[i];
            int sum = nums[j]+nums[k];
            if(j>i+1 && nums[j] == nums[j-1]){
                j++;
            }
            else if(k<n-1 && nums[k] == nums[k+1]){
                k--;
            }
            else if(target==sum){
               if(nums[i]==0 && nums[j]==0){
                 zeroCons = 1;
               }
               ans.push_back(nums[i]);
               ans.push_back(nums[j]);
               ans.push_back(nums[k]);
               res.push_back(ans);
               j++;
               k--;
            }
            else if(sum<target){
                j++;
            }
            else{
                k--;
            }
            ans.clear();
        }
    }

    int b = 0;
    int zeroCount = 0;
    while(nums[b++]==0 && b<n && !zeroCons){
        if(zeroCount==3){
           res.push_back({0,0,0});
           break;
        }
        zeroCount++;
    }
    

    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[0].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}