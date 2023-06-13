class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int s=0;
        int e=arr.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            //to find missing positive integers 
            if(arr[mid]-mid-1<k){ // represents difference between the actual value of the element at index i and the expected value of the element at index i in a complete array of all positive integers.
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return s+k;
        //kth missing positive integer can be returned as arr[i]+k-(arr[i]-i-1)
    }
};
