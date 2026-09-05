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

    int target;
    cin>>target;

    sort(nums.begin(),nums.end());
    vector<vector<int>> res;
    if(n==4){
        long sum = (long)nums[0] + (long)nums[1] + (long)nums[2] + (long)nums[3];
        if(sum==target){
            res.push_back(nums);
        }
        //print res
        return 0;
    }
    for(int i=0;i<n-3;i++){
        if(i>0 && nums[i] == nums[i-1]){
            continue;
        }
        for(int  j=i+1;j<n-2;j++){
            if(j>i+1 && nums[j] == nums[j-1]){
                continue;
            }
            vector<int> ans;
            int k = j+1;
            int l = n-1;
            
            while(k<l){
            int secondSum = target - nums[i] - nums[j];
            int sum = nums[k] + nums[l];
            if(k>j+1 && nums[k] == nums[k-1]){
                k++;
            }
            else if(l<n-1 && nums[l] == nums[l+1]){
                l--;
            }
            else if(sum == secondSum){
                ans.push_back(nums[i]);
                ans.push_back(nums[j]);
                ans.push_back(nums[k]);
                ans.push_back(nums[l]);
                res.push_back(ans);
                k++;
                l--;
            }
            else if(sum < secondSum){
                k++;
            }
            else{
                l--;
            }
            ans.clear();
        }
      }    
    }

    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[0].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}