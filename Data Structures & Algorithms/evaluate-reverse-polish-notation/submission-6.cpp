class Solution {
public:
    bool isDigit(string s) {
        for (int i = 0; i < s.length(); i++) {
            if (i == 0 && s[0] == '-' && s.length() > 1) continue;
            if (!isdigit(s[i])) return false;
        }
        return true;
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
