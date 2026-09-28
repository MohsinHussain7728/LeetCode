class Solution {
public:
    int maxDepth(string s) {
        int level=0;
        int max_Level= 0;

        for(char c:s){ //TC-->> O(n).
            if(c == '('){
                level++;
                max_Level = max(max_Level, level);
            }

            else if(c == ')'){
                level--;
            }
        }
        return max_Level;
    }
};