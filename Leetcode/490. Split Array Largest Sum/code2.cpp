# Using Dynamic Programming
# TC: O(n^2)
# SC: O(n^2)

class Solution {
public:
    int dfs(vector<int>& nums, int m, int idx, vector<vector<int>>& dp){
        if(m==0 && idx==size(nums)){
            return 0;
        }
        if(m==0 || idx==size(nums)){
            return INT_MAX;
        }
        if(dp[m][idx]!=-1){
            return dp[m][idx];
        }
        int s=0,ans=INT_MAX;
        for(int i=idx;i<size(nums);i++){
            s+=nums[i];
            ans = min(ans, max(s, dfs(nums,m-1,i+1,dp)));
        }
        return dp[m][idx]=ans;
    }
    
    int splitArray(vector<int>& nums, int m) {
        vector<vector<int>> dp(m+1,vector<int>(size(nums)+1,-1));
        return dfs(nums,m,0,dp);
    }
};
