class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> ngr(n);
        vector<int> ngl(n);
        stack<pair<int,int>> s;
        // Next Smaller Right
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && s.top().first >= heights[i])
                s.pop();
            if(s.empty())
                ngr[i] = n;
            else
                ngr[i] = s.top().second;
            
            s.push({heights[i],i});
        }
        
        //Empty the stack
        while(s.size()>0)
            s.pop();
        
        // Next Smaller Left
        for(int i=0;i<n;i++){
            while(!s.empty() && s.top().first >= heights[i])
                s.pop();
            if(s.empty())
                ngl[i] = -1;
            else
                ngl[i] = s.top().second;
            
            s.push({heights[i],i});
        }
        // Calculating the Width 
        vector<int> width(n);
        for(int i=0;i<n;i++)
            width[i] = ngr[i]-ngl[i]-1;
        
        // Finding the Maximum Area that is possible
        vector<int> area(n);
        int maxArea=0;
        for(int i=0;i<n;i++){
            area[i] = heights[i]*width[i];
            maxArea = max(maxArea,area[i]);
        }
        
        return maxArea;
    }
};
