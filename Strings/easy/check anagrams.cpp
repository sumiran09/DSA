class Solution {
public:
    bool isAnagram(string s, string t) {
        // using hashmap to store freq
        if(s.length()!=t.length())return false;
        vector<int>hm(26,0);
        for(int i=0;i<s.length();i++){
            hm[s[i]-'a']++;
            hm[t[i]-'a']--;
        }
        for(int i=0;i<hm.size();i++){
            if(hm[i]!=0)return false; // to check if all freq are zero 
        }
        return true; 
        
        //using sorting 
  /*    sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s==t)return true;
        return false;     */
    }
};
