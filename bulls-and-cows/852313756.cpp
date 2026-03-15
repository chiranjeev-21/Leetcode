
/*
==========================================================
Problem: Bulls and Cows
Difficulty: Medium
==========================================================

You are playing the Bulls and Cows game with your friend.

You write down a secret number and ask your friend to guess what the number is. When your friend makes a guess, you provide a hint with the following info:


	The number of "bulls", which are digits in the guess that are in the correct position.
	The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position. Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls.


Given the secret number secret and your friend's guess guess, return the hint for your friend's guess.

The hint should be formatted as "xAyB", where x is the number of bulls and y is the number of cows. Note that both secret and guess may contain duplicate digits.

 
Example 1:


Input: secret = "1807", guess = "7810"
Output: "1A3B"
Explanation: Bulls are connected with a '|' and cows are underlined:
"1807"
  |
"7810"

Example 2:


Input: secret = "1123", guess = "0111"
Output: "1A1B"
Explanation: Bulls are connected with a '|' and cows are underlined:
"1123"        "1123"
  |      or     |
"0111"        "0111"
Note that only one of the two unmatched 1s is counted as a cow since the non-bull digits can only be rearranged to allow one 1 to be a bull.


 
Constraints:


	1 <= secret.length, guess.length <= 1000
	secret.length == guess.length
	secret and guess consist of digits only.

==========================================================
*/


class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<int,int>mp;
        int cnt=0;
        string str;
        vector<int>guess_vec,secret_vec;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]){
                cnt++;
                continue;
            }
            secret_vec.push_back(secret[i]-'0');
            guess_vec.push_back(guess[i]-'0');
            mp[secret[i]-'0']++;
        }
        cout<<cnt;
        // for(int i=0;i<secret_vec.size();i++){
        //     cout<<secret_vec[i]<<" ";
        // }
        // for(int i=0;i<guess_vec.size();i++){
        //     cout<<guess_vec[i]<<" ";
        // }
        // for(auto i:mp){
        //     cout<<i.first<<" "<<i.second<<"\n";
        // }
        int res=0;
        for(int i=0;i<guess_vec.size();i++){
            if(mp.find(guess_vec[i])!=mp.end()){
                if(mp[guess_vec[i]]>0){
                    mp[guess_vec[i]]--;
                    res++;
                }
            }
        }
        cout<<res;
        str+=to_string(cnt)+'A'+to_string(res)+'B';
        return str;
    }
};