class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int i=0;
        for(int x: pushed){
            s.push(x);
            while(!s.empty() and s.top()==popped[i]){
                i++;
                s.pop();
            }
        }
        return i==popped.size();
    }
};
