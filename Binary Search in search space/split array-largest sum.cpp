class Solution {
public:
//We initialize s as the maximum element in the array and e as the sum of all elements in the array.
//apply binary search to find the minimum possible value of the largest subarray sum.
    int splitArray(vector<int>& nums, int k) {
        int s=0;
        int e=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            s=max(s,nums[i]);
            e=e+nums[i];
        }
        int ans=0;
       // In each iteration of binary search,:
       /*calculate the mid value and,
       count the number of subarrays we can create such that the maximum sum of any subarray is less than or equal to the mid value */
        while(s<=e){
            int mid=(s+e)/2;
            int count=0;
            int tempsum=0;  //running sum 
            //To count the number of subarrays we can create for a given maximum sum mid
            for(int i=0;i<n;i++){
                if(tempsum+nums[i]<=mid)tempsum=tempsum+nums[i];
                else{
                    count++;
                    tempsum=nums[i];
                }
            }
            count++;
            //If the sum exceeds the maximum sum mid, we increment the count of subarrays and start a new subarray from the current element. We repeat this process until we have created k subarrays.
            if(count<=k){
                ans=mid;
                e=mid-1;
            }
            else{   //If the count is greater than k, then the mid value is too small, and we need to increase it, so we update low = mid + 1.
                s=mid+1;
            }
        }
        return ans;
    }
};
