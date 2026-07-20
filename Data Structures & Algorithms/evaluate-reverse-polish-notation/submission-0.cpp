class Solution {
public:
    int operate(int num1, int num2, string op)
    {
        if(op == "+")
            return num1 + num2;
        else if(op == "-")
            return num1 - num2;
        else if(op == "*")
            return num1 * num2;
        else
            return num1 / num2;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string token : tokens )
        {
            if(token == "+" || token == "-" || token == "*" || token == "/" )
            {
                int second = st.top();
                st.pop();
                int first = st.top();
                st.pop();

                int result = operate(first, second, token);
                st.push(result);
            }
            else
                st.push(stoi(token));
        }
        return st.top();
    }
};
