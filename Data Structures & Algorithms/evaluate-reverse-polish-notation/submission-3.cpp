class Solution {
public:
    bool isDigit(string s) {
        if (s.size() > 1) return true;
        return isdigit(s[0]);
    }

    int evalRPN(vector<string>& tokens) {
        stack<long long> st;

        for (const string& s : tokens) {
            if (isDigit(s)) {
                st.push(stoll(s));
            } else {
                long long second = st.top();
                st.pop();
                long long first = st.top();
                st.pop();
                char op = s[0];
                switch(op) {
                    case '+':
                        st.push(first+second);
                        break;
                    case '-':
                        st.push(first-second);
                        break;
                    case '*':
                        st.push(first*second);
                        break;
                    case '/':
                        st.push(first/second);
                        break;
                    default:
                        // Invalid
                        break;
                }
            }
        }

        return (int)st.top();
    }
};
