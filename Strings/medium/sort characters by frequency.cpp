class Solution {
public:
    string frequencySort(string s) {
       string ans;
       unordered_map<char,int> mpp;
       int n=s.size();
       for(int i=0;i<n;i++){
           mpp[s[i]]++;  //to keep track of frequency of each char in string s
       }
       vector<pair<int,char>> v;
       for(auto x: mpp){
           v.push_back({x.second,x.first});
       }
       sort(v.rbegin(),v.rend());  //sorting the freq+char vector in reverse 
       for(auto x: v){
           for(int i=0;i<x.first;i++){
               ans.push_back(x.second);
           }
       }
       return ans;
    }
};
