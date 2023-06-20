class Solution {
public:
    int beautySum(string s) {
        int n= s.size();
        int ans=0;
        int mini= 500;
        int maxi=0;
        for(int i=0;i<n;i++){
            map<char,int>mpp;
            for(int j=i;j<n;j++){
                mpp[s[j]]++;
                for(auto it: mpp){
                    mini=min(mini,it.second);
                    maxi=max(maxi,it.second);
                }
                ans=ans+(maxi-mini);
                mini=500;
                maxi=0;
            }
            mpp.clear();
        }
        return ans;
    }
};
