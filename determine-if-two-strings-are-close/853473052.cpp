
/*
==========================================================
Problem: Determine if Two Strings Are Close
Difficulty: Medium
==========================================================

Two strings are considered close if you can attain one from the other using the following operations:


	Operation 1: Swap any two existing characters.

	
		For example, abcde -> aecdb
	
	
	Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
	
		For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
	
	


You can use the operations on either string as many times as necessary.

Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.

 
Example 1:


Input: word1 = "abc", word2 = "bca"
Output: true
Explanation: You can attain word2 from word1 in 2 operations.
Apply Operation 1: "abc" -> "acb"
Apply Operation 1: "acb" -> "bca"


Example 2:


Input: word1 = "a", word2 = "aa"
Output: false
Explanation: It is impossible to attain word2 from word1, or vice versa, in any number of operations.


Example 3:


Input: word1 = "cabbba", word2 = "abbccc"
Output: true
Explanation: You can attain word2 from word1 in 3 operations.
Apply Operation 1: "cabbba" -> "caabbb"
Apply Operation 2: "caabbb" -> "baaccc"
Apply Operation 2: "baaccc" -> "abbccc"


 
Constraints:


	1 <= word1.length, word2.length <= 105
	word1 and word2 contain only lowercase English letters.

==========================================================
*/


class Solution 
{
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;
        int sz = word1.size();

        vector<int> cnt1(26), cnt2(26);
        for(int i = 0;i < sz;i++){
            cnt1[word1[i] - 'a']++;
            cnt2[word2[i] - 'a']++;
        }
    
        unordered_map<int, int> mp1, mp2;
        for(int i = 0; i < 26; i++){
            if(cnt1[i] and !cnt2[i] or !cnt1[i] and cnt2[i]) return false;
            if(cnt1[i]) mp1[cnt1[i]]++;
            if(cnt2[i]) mp2[cnt2[i]]++;
        }

        for(int i = 0;i < 26; i++){
            int freq1 = cnt1[i], freq2 = cnt2[i];
            if(mp1[freq1] != mp2[freq1]) return false;
            if(mp1[freq2] != mp2[freq2]) return false;
        }
        return true;
    }
};