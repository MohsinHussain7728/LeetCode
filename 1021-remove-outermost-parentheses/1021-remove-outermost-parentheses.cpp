class Solution {
public:
    string removeOuterParentheses(string s) {
        string str="";
        int level=0;

        for(char ch : s){ //TC-->> O(n) //SC-->> O(1).
            if (ch == '('){
                //Check if it's inside primitive
                if(level > 0){
                    str += ch;
                }
                //Inc nesting level
                level++;
            }
            else if(ch == ')'){
                //dec nesting level
                level--;
                if(level > 0){
                    str += ch;
                }
            }
        }
        return str;
    }
};