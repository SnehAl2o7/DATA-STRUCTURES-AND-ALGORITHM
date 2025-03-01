#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string decodedString(string &s)
    {
        // code here
        stack<int> countStack;
        stack<string> resultStack;
        string currentResult = "";
        int k = 0;

        for (char ch : s)
        {
            if (isdigit(ch))
            {
                // If the character is a digit, form the number k
                k = k * 10 + (ch - '0');
            }
            else if (ch == '[')
            {
                // Push the current number and result to the stack
                countStack.push(k);
                resultStack.push(currentResult);
                // Reset the current number and result
                k = 0;
                currentResult = "";
            }
            else if (ch == ']')
            {
                // Pop the last result and count from the stack
                string lastResult = resultStack.top();
                resultStack.pop();
                int count = countStack.top();
                countStack.pop();
                // Repeat the current result k times and append to the last result
                for (int i = 0; i < count; ++i)
                {
                    lastResult += currentResult;
                }
                currentResult = lastResult;
            }
            else
            {
                // If the character is a letter, append it to the current result
                currentResult += ch;
            }
        }
        return currentResult;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~" << endl;
    }
    return 0;
}