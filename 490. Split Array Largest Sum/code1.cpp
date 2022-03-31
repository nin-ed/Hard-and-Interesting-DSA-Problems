# Using Binary Search
# TC: O(nlogn)
# SC: O(1)

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int l=0, r=0;
        for(int e: nums){
            l = max(l,e);
            r += e;
        }
        
        while(l<=r){
            int mid = (l+r)/2, s=0, ans=1;
            for(int e: nums){
                if(s+e > mid){
                    s = 0;
                    ans++;
                }
                s += e;
            }
            if(ans <= m){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
};
