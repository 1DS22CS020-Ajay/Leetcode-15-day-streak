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

    int k;
    cin>>k;

    vector<int>nums1;
        //sorted array for tracking minimum
        for(int i=0;i<n;i++){
            nums1.push_back(nums[i]);
        }

        sort(nums1.begin(),nums1.end());
        int m=0;

        vector<int>PrefMax;
        
        PrefMax.push_back(nums[0]);
        int mx = nums[0];
        for(int i=1;i<n;i++){
            if(mx <= nums[i]){
                mx = nums[i];
            }
            PrefMax.push_back(mx);
        }


        vector<int>SuffMin(n);
        SuffMin[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            SuffMin[i] = min(nums[i],SuffMin[i+1]);
        }

        for(int i=0;i<n;i++){
            cout<<PrefMax[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++){
            cout<<SuffMin[i]<<" ";
        }

        
}