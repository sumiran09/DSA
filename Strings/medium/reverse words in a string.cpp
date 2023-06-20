// reverse every word in the string and don't include any spaces 
class Solution {
public:
    string reverseWords(string s) {
        // Reverse the entire string
        reverse(s.begin(), s.end());

        int start = 0; // Start index of the current word
        int end = 0;   // End index of the current word
        int i = 0;     // Current index
        int n = s.size(); // Size of the string

        while (i < n) {
            // Skip leading spaces
            while (i < n && s[i] == ' ')
                i++;

            // Find the end of the current word
            while (i < n && s[i] != ' ')
                s[end++] = s[i++];

            if (start < end) {
                // Reverse the current word
                reverse(s.begin() + start, s.begin() + end);

                // Add a space after the reversed word
                s[end++] = ' ';

                // Update the start index for the next word
                start = end;
            }
            i++;
        }

        // Remove extra space at the end if present
        if (end > 0)
            s.resize(end - 1);

        return s;
    }
};
