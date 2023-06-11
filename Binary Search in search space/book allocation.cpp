class Solution 
{
    bool isValid(int A[], int N,int M,int mid){
        int student=1 ;
        int sum=0;
        for(int i=0;i<N;i++){
            sum=sum+A[i];
            if(sum>mid){
                student++;
                sum=A[i];    //assign current book to next student and update sum
            }
            if(student>M){ //If count of students becomes greater than given no. of students, return False.
                return false;
            } //curSum += pages[i];
          // else, assign this book to current student and update
        }
        return true;
    }
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(N<M)return -1;
        int lsf=INT_MIN;
        int sum=0;
        for(int i=0;i<N;i++){
            lsf=max(lsf,A[i]);
            sum=sum+A[i];
        }
        int s=lsf;
        int e=sum;
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(isValid(A,N,M,mid)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};
