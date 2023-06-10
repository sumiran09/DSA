 //we set the starting of the range to the largest weight in weights, say maxWeight
    //set the ending of the range to the sum of the elements of weights, say totalWeight
    //s = maxWeight and e = totalWeight

    /* If we are able to ship the packages with mid capacity within the required days, we know the answer is at most mid, 
    so we can look for a better answer by moving to the lower half - change r = mid */
    //otherwise we move to upper half 

//daysNeeded = 1: store the total number of days needed to ship all the weights with c capacity
//currentLoad = 0: keep track of how much weight has been placed in the ship on a day
//We keep on placing the weights until currentLoad > capacity 
//if exceeds capacity; we increase the days needed to ship the packages by one, i.e., daysNeeded = daysNeeded + 1
//Create a method feasible which takes weights, c, days as the parameters and returns true if we can ship all the packages with c capacity.
//Call feasible(weights, mid, days) to see if we can ship all the weights in days days while using mid as the ship's capacity.

class Solution {
public:
    bool feasible(vector<int>& weights,int c,int days){
        int daysneeded=1; int currentload=0;
        for(int weight : weights){
            currentload=currentload+weight;
            if(currentload>c){
                daysneeded++;
                currentload=weight; //for next day 
            }
        }
        return daysneeded<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int totalload=0;
        int maxload=0;
        for(int weight: weights){
            totalload=totalload+weight;
            maxload=max(maxload,weight);
        }
        int s=maxload; int e=totalload;
        while(s<e){
            int mid=s+(e-s)/2;
            if(feasible(weights,mid,days)){
                e=mid;
            }
            else{s=mid+1;}
        }
        return s;
    }
};
