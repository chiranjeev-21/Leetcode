
/*
==========================================================
Problem: Decode String
Difficulty: Medium
==========================================================

Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 105.

 
Example 1:


Input: s = "3[a]2[bc]"
Output: "aaabcbc"


Example 2:


Input: s = "3[a2[c]]"
Output: "accaccacc"


Example 3:


Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"


 
Constraints:


	1 <= s.length <= 30
	s consists of lowercase English letters, digits, and square brackets '[]'.
	s is guaranteed to be a valid input.
	All the integers in s are in the range [1, 300].

==========================================================
*/


class Solution{
    public:
        string decodeString(string s){
            stack<char> st;
            for(int i = 0; i < s.size(); i++){
                if(s[i] != ']')
                    st.push(s[i]);
                else{
                    
                    string current_str = "";
                    while(st.top() != '['){
                        current_str = st.top() + current_str;
                        st.pop();
                    }
                    st.pop(); // for '['

                    string number = "";
                    while(st.empty() == false && isdigit(st.top())){
                        number = st.top() + number;
                        st.pop();
                    }

                    int k_times = stoi(number);
                    while(k_times > 0){
                        for(int i = 0; i < current_str.size(); i++)
                            st.push(current_str[i]);
                        k_times--;
                    }
                }
            }
            s = "";
            while(st.empty() == false){
                s = st.top() + s;
                st.pop();
            }
            return s;
        }
};