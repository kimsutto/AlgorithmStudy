
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char> st;
    st.push(s[0]);
    for (int i = 1; i < s.size(); i++) {
        if (!st.empty() && st.top() == s[i]) st.pop();
        else st.push(s[i]);
    }
    return st.empty() ? 1 : 0;
}
int main() {
    cout << solution("ddccss");
    return 0;
}