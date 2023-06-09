class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here 
       long long int s=1;
       long long int e=x;
       long long int ans;
       while(s<=e){
           long long int mid=s+(e-s)/2;
           long long int square=mid*mid;
           if(square==x)return mid;
           else if(square<x){
               ans=mid;
               s=mid+1;
           }
           else{
               e=mid-1;
           }
       }
       return ans;
        
        
    }
};
