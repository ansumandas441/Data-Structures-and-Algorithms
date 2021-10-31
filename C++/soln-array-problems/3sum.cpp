/**
 @author Farheen Bano

 Date 11-08-2021

 References-
 https://www.interviewbit.com/problems/3-sum-zero/
 https://leetcode.com/problems/3sum/
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {   
        int n=nums.size();
        vector<vector<int>> triplets;

        if(n<3)
            return triplets;
        sort(nums.begin(),nums.end());
        
        for (int i=0; i<n-2; i++){
            if(i>0 && nums[i]==nums[i-1])
                continue;
            
            int left=i+1;
            int right=n-1;            
            while(left<right){
                int sum=nums[i]+nums[left]+nums[right];
                if(sum==0){
                    triplets.push_back({nums[i],nums[left],nums[right]});  
                    
                    left++;
                    while(left<n && nums[left]==nums[left-1])
                        left++;
                }
                else if(sum<0)
                    left++;
                else
                    right--;
            }
        }  
        return triplets;
    }
};