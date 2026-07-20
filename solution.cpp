#include<bits/stdc++.h>
using namespace std;

// Brute Force Approach
bool isValidString(string str) {
    int count = 0;

    for (char ch : str) {
        if (ch == '(')
            count++;
        else
            count--;

        // closing brackets more than opening brackets
        if (count < 0)
            return false;
    }

    // if all opening brackets are matched
    return count == 0;
}

// Brute Force Solution
int longestValidParentheses(string s) {
    int n = s.length();
    int maxLength = 0;
    int start;
    int end;

    // Generate all possible substrings
    for (int start = 0; start < n; start++) {
        for (int end = start; end < n; end++) {

            string sub = s.substr(start, end - start + 1);

            if (isValidString(sub)) {
                maxLength = max(maxLength, end - start + 1);
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

    int ans = longestValidParentheses(s);
    cout<<"Length of the longest valid (well-formed) parentheses substring : "<<ans<<endl;

    


    return 0;
}