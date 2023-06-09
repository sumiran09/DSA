class Solution {
public:
    int findDivisionSum(vector<int>& nums, int& divisor){
        int sum=0;
        for(int num: nums){
            sum=sum+ceil((num*1.0)/divisor);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int ans=-1;
        int s=1;
        int e=*max_element(nums.begin(), nums.end());
        while(s<=e){
            int mid=s+(e-s)/2;
            int sum=findDivisionSum(nums,mid);
            if(sum<=threshold){
                ans=mid;
                e=mid-1; //left half
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};
