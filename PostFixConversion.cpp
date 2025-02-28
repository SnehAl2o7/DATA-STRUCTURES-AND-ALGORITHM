#include <bits/stdc++.h>
using namespace std;

int evaluate(vector<string> &tokens)
{
    stack<int> st;

    for (string &token : tokens)
    {
        if (isdigit(token[0]) || (token.size() > 1 && isdigit(token[1])))
        {
            // If the token is a number, push it onto the stack
            st.push(stoi(token));
        }
        else
        {
            // If the token is an operator, pop two numbers from the stack
            int num2 = st.top();
            st.pop();
            int num1 = st.top();
            st.pop();

            // Perform the operation and push the result back onto the stack
            if (token == "+")
            {
                st.push(num1 + num2);
            }
            else if (token == "-")
            {
                st.push(num1 - num2);
            }
            else if (token == "*")
            {
                st.push(num1 * num2);
            }
            else if (token == "/")
            {
                st.push(num1 / num2);
            }
        }
    }

    // The final result will be the only element left in the stack
    return st.top();
}

int main()
{
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    int result = evaluate(tokens);
    cout << "The result of the expression is: " << result << endl;
    return 0;
}
