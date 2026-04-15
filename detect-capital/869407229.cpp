
/*
==========================================================
Problem: Detect Capital
Difficulty: Easy
==========================================================

We define the usage of capitals in a word to be right when one of the following cases holds:


	All letters in this word are capitals, like "USA".
	All letters in this word are not capitals, like "leetcode".
	Only the first letter in this word is capital, like "Google".


Given a string word, return true if the usage of capitals in it is right.

 
Example 1:
Input: word = "USA"
Output: true
Example 2:
Input: word = "FlaG"
Output: false

 
Constraints:


	1 <= word.length <= 100
	word consists of lowercase and uppercase English letters.

==========================================================
*/


class Solution {
public:
    bool detectCapitalUse(string word) {
        int capitals=0;
        int first_capital=0;
        for(int i=0;i<word.length();i++){
            if(word[i]<='Z' && i==0){
                first_capital++;
                capitals++;
            }
            else if(word[i]<='Z'){
                capitals++;
            }
        }
        cout<<capitals;
        if(capitals == word.length()){
            return true;
        }
        else if(first_capital==1 && capitals==1){
            return true;
        }
        else if(first_capital==0 && capitals==0){
            return true;
        }
        else{
            return false;
        }
        return 0;
    }
};