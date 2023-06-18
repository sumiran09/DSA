class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> mpp;
        set<char> set;
        int n=s.size()-1;
        while(n>=0){
            if(mpp.count(s[n]) and mpp[s[n]] != t[n])return false;
            if(!mpp.count(s[n]) and set.count(t[n]))return false ;
            set.insert(t[n]);
            mpp[s[n]]=t[n];
            n--;
        }
        return true;
    }
};
