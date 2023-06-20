class Solution {
public:
      //O(n^2) solution: 
    int  ExpandFromCenter(string &s, int i, int j){
        while(i>=0 and j<s.length() and s[i]==s[j]){
            
            i--;
            j++;
        }
        return j-i+1-2;  //need to subtract 2 as it implies s[i]!=s[j] when the loop ends
    }
    string longestPalindrome(string s) {
        int n=s.size();
        int start=0;
        int end=0;
        int len=0;
        int max_len=1;
        for(int i=0;i<n;i++){
            int odd= ExpandFromCenter(s,i,i);
            int even= ExpandFromCenter(s,i,i+1);
            len=max(odd,even);
            if(end-start+1 < len){
                max_len=len;
                start= i-(len-1)/2;
                end= i+(len/2);
            }
        }
        return s.substr(start,max_len);
        //O(n^3) solution:
       /* int si=0;
        int max_len=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(check(s,i,j)){
                    if(j-i+1>max_len){
                        max_len = j-i+1;
                        si=i;
                    }
                }
            }
        }
        return s.substr(si,max_len);  */
    } 

};
