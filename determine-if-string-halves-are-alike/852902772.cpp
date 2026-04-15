
/*
==========================================================
Problem: Determine if String Halves Are Alike
Difficulty: Easy
==========================================================

You are given a string s of even length. Split this string into two halves of equal lengths, and let a be the first half and b be the second half.

Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and lowercase letters.

Return true if a and b are alike. Otherwise, return false.

 
Example 1:


Input: s = "book"
Output: true
Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.


Example 2:


Input: s = "textbook"
Output: false
Explanation: a = "text" and b = "book". a has 1 vowel whereas b has 2. Therefore, they are not alike.
Notice that the vowel o is counted twice.


 
Constraints:


	2 <= s.length <= 1000
	s.length is even.
	s consists of uppercase and lowercase letters.

==========================================================
*/


class Solution {
public:
    bool halvesAreAlike(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        // cout<<s;
        int n=s.length();
        int t=n/2;
        string s1=s.substr(0,t);
        string s2=s.substr(t,n);
        // cout<<s1<<" "<<s2;
        unordered_map<char,int>mp1,mp2;
        for(int i=0;i<s1.length();i++){
            if(s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'i' || s1[i] == 'o' || s1[i] == 'u'){
                mp1[s1[i]]++;
            }
        }
        for(int i=0;i<s2.length();i++){
            if(s2[i] == 'a' || s2[i] == 'e' || s2[i] == 'i' || s2[i] == 'o' || s2[i] == 'u'){
                mp2[s2[i]]++;
            }
        }
        int sum1=0,sum2=0;
        for(auto i:mp1){
            sum1+=i.second;
        }
        for(auto i:mp2){
            sum2+=i.second;
        }
        cout<<sum1<<" "<<sum2;
        return (sum1==sum2);
    }
};