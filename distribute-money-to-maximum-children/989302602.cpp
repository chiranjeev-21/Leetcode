
/*
==========================================================
Problem: Distribute Money to Maximum Children
Difficulty: Easy
==========================================================

You are given an integer money denoting the amount of money (in dollars) that you have and another integer children denoting the number of children that you must distribute the money to.

You have to distribute the money according to the following rules:


	All money must be distributed.
	Everyone must receive at least 1 dollar.
	Nobody receives 4 dollars.


Return the maximum number of children who may receive exactly 8 dollars if you distribute the money according to the aforementioned rules. If there is no way to distribute the money, return -1.

 
Example 1:


Input: money = 20, children = 3
Output: 1
Explanation: 
The maximum number of children with 8 dollars will be 1. One of the ways to distribute the money is:
- 8 dollars to the first child.
- 9 dollars to the second child. 
- 3 dollars to the third child.
It can be proven that no distribution exists such that number of children getting 8 dollars is greater than 1.


Example 2:


Input: money = 16, children = 2
Output: 2
Explanation: Each child can be given 8 dollars.


 
Constraints:


	1 <= money <= 200
	2 <= children <= 30

==========================================================
*/


class Solution {
public:
    int distMoney(int money, int children) {
        if(money<children){
            return -1;
        }
        vector<int>vec(children,0);
        for(int i=0;i<children;i++){
            vec[i]+=1;
        }
        money-=children;
        for(int i=0;i<children;i++){
            if(money-7>=0){
                vec[i]+=7;
                money-=7;
            }
            else if(money<7 && money!=3){
                vec[i]+=money;
                money=0;
                break;
            }
            else if(money==3){
                if(i==children-1){
                    vec[i-1]+=1;
                    vec[i]+=2;
                    money=0;
                }
                else{
                    if(i+1<children && i-1>=0){
                        if(vec[i-1]==8 && vec[i+1]==8){
                            vec[i-1]+=1;
                            vec[i]+=2;
                            money=0;
                        }
                        else if(vec[i-1]==8){
                            vec[i+1]+=1;
                            vec[i]+=2;
                            money=0;
                        }
                        else if(vec[i+1]==8){
                            vec[i-1]+=1;
                            vec[i]+=2;
                            money=0;
                        }
                    }
                }
            }
        }
        if(money>0){
            for(int i=0;i<children;i++){
                if(i==children-1){
                    vec[i]+=money;
                    money=0;
                }
                if(vec[i]!=8 && vec[i]+money!=4){
                    vec[i]+=money;
                    money=0;
                    break;
                }
            }
        }
        cout<<money<<" ";
        int cnt=0;
        for(int i=0;i<vec.size();i++){
            cout<<vec[i]<<" ";
            if(vec[i]==8)
                cnt++;
        }
        return cnt;
    }
};