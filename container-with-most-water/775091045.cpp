
/*
==========================================================
Problem: Container With Most Water
Difficulty: Medium
==========================================================

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

 
Example 1:


Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.


Example 2:


Input: height = [1,1]
Output: 1


 
Constraints:


	n == height.length
	2 <= n <= 105
	0 <= height[i] <= 104

==========================================================
*/


class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size(),largest=0;
        int start=0;
        int end=n-1;
        int area = 0;
            while(start<end){
                int minn=min(height[start],height[end]);
                area = max(area,minn*(end-start));
                if(height[start]>height[end]){
                    end--;
                }
                else{
                    start++;

                }
            }
        return area;
    //     vector<pair<int, int> > vp;
    //     for (int i = 0; i < n; ++i) {
    //         vp.push_back(make_pair(height[i], i));
    //     }
    //     sort(vp.begin(), vp.end());
    // //     for (int i = 0; i < vp.size(); i++) {
    // //     cout << vp[i].first << "\t"
    // //          << vp[i].second << endl;
    // // }
    //     for(int i=n-1;i>=0;i--){
    //         int one = height[i].first;
    //         int two = height[i-1].first;
    //         int t=min(one,two);
    //         largest=max(largest,t*(height[i].second-height[i-1].second));
    //     }
    //     return largest;
    }
};