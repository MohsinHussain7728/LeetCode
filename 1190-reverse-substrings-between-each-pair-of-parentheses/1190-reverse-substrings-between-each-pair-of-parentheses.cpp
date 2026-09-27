class Solution {
public:
    string reverseParentheses(string s) {
        string ans;

        stack<char>st;
        queue<char>que;

        for(int i=0; i<s.size(); i++){
            if(s[i] != ')'){
                st.push(s[i]);
            }
            else{
                while(st.top() != '('){
                    que.push(st.top());
                    st.pop();
                }
                st.pop();
                while(!que.empty()){
                    st.push(que.front());
                    que.pop();
                }
            }
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};