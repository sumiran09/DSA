class Solution {
public:
    bool canPlaceCows(vector<int>stalls,int k,int mid){
        // place the 1st cow in the 1st stall i.e. stalls[0]
        int numOfCowsPlaced=1;
        int prevCowPos=stalls[0];
        for(int i=1;i<stalls.size();i++){ // can I place the next cow in the ith stall
            if(stalls[i]-prevCowPos>=mid){
                // you can place the next cow in the ith stall
                numOfCowsPlaced++;
                prevCowPos=stalls[i];
            }
            if(numOfCowsPlaced==k)return true;
            // you've mananged to place k cows in n stalls at a min.dist. of >= mid
        }
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        int m=stalls.size();
        sort(stalls.begin(),stalls.end()); 
        int s=0;
        int e=stalls[m-1]-stalls[0]; // for the tightest upper-bound, place the two cows at the extreme positions
        int ans=0;
        while(s<=e){
            int mid=(s+e)>>1;
            if(canPlaceCows(stalls,k,mid)){
                ans=mid;
                s=mid+1; // since we want to find the largest minimum distance b/w
			// the cows, continue your search towards the right of 'm' 
			// i.e. search space reduces from [s, e] to [m+1, e].
            }
            else{
                e=mid-1; // you cannot place 'c' cows in 'n' stalls at a minimum distance
			// of 'm' therefore continue your search towards the left of 'm'
			// i.e. search space reduces from [s, e] to [s, m-1].
            }
        }
        return ans;
    }
};
