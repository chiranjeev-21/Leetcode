
/*
==========================================================
Problem: Count Unreachable Pairs of Nodes in an Undirected Graph
Difficulty: Medium
==========================================================

You are given an integer n. There is an undirected graph with n nodes, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

Return the number of pairs of different nodes that are unreachable from each other.

 
Example 1:


Input: n = 3, edges = [[0,1],[0,2],[1,2]]
Output: 0
Explanation: There are no pairs of nodes that are unreachable from each other. Therefore, we return 0.


Example 2:


Input: n = 7, edges = [[0,2],[0,5],[2,4],[1,6],[5,4]]
Output: 14
Explanation: There are 14 pairs of nodes that are unreachable from each other:
[[0,1],[0,3],[0,6],[1,2],[1,3],[1,4],[1,5],[2,3],[2,6],[3,4],[3,5],[3,6],[4,6],[5,6]].
Therefore, we return 14.


 
Constraints:


	1 <= n <= 105
	0 <= edges.length <= 2 * 105
	edges[i].length == 2
	0 <= ai, bi < n
	ai != bi
	There are no repeated edges.

==========================================================
*/


class Solution {
public:
    void dfs(vector<int>adj[],int src,vector<bool>&vis,int &counter){
        if(vis[src]) return;
        vis[src]=true;
        counter++;
        for(auto ele:adj[src]){
            if(!vis[ele]){
                dfs(adj,ele,vis,counter);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(auto ele:edges){
            adj[ele[0]].push_back(ele[1]);
            adj[ele[1]].push_back(ele[0]);
        }
        long long res = 0;
        vector<bool>vis(n,false);
        vector<int>temp;
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                int counter = 0;
                dfs(adj,i,vis,counter);
               temp.push_back(counter);
            }
        }
        int total = 0;
        for(int i = 0;i<temp.size();i++){
            res+=(long)((long)temp[i]*(long)(n-total-temp[i]));
            total+=temp[i];
        }
        return res;
    }
};
