#include<bits/stdc++.h>
using namespace std;

// Function for Brute Force Approach
// bool isValidString(string str) {
//     int count = 0;

//     for (char ch : str) {
//         if (ch == '(')
//             count++;
//         else
//             count--;

//         // closing brackets more than opening brackets
//         if (count < 0)
//             return false;
//     }

//     // if all opening brackets are matched
//     return count == 0;
// }

// // Brute Force Solution
// int longestValidParentheses(string s) {
//     int n = s.length();
//     int maxLength = 0;
//     int start;
//     int end;

//     // Generate all possible substrings
//     for (int start = 0; start < n; start++) {
//         for (int end = start; end < n; end++) {

//             string sub = s.substr(start, end - start + 1);

//             if (isValidString(sub)) {
//                 maxLength = max(maxLength, end - start + 1);
//             }
//         }
//     }

//     return maxLength;
// }


// Function for Optimal Approach (Using Stack)
int longestValidParentheses(string s) {
    stack<int> st;

    // Push a base index to handle valid substrings
    // starting from index 0
    st.push(-1);

    int maxLength = 0;

    for (int i = 0; i < s.length(); i++) {

        // If current character is an opening bracket,
        // push its index onto the stack.
        if (s[i] == '(') {
            st.push(i);
        }
        else {

            // Pop the previous opening bracket (or base index)
            st.pop();

            // If the stack becomes empty, push the current
            // index as the new base index.
            if (st.empty()) {
                st.push(i);
            }
            else {
                // Calculate the length of the current
                // valid parentheses substring.
                maxLength = max(maxLength, i - st.top());
            }
        }
    }

    return maxLength;
}

int main(){

    string s;
    cout<<"Enter string : ";
    cin>>s;

    cout<<endl;

    // Calling Function for Brute Force Approach

    // int ans = longestValidParentheses(s);
    // cout<<"Length of the longest valid (well-formed) parentheses substring : "<<ans<<endl;


    // Calling Function for Optimal Approach

    int ans = longestValidParentheses(s);
    cout<<"Length of the longest valid (well-formed) parentheses substring : "<<ans<<endl;

    


    return 0;
}