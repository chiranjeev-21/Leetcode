
/*
==========================================================
Problem: Divide Nodes Into the Maximum Number of Groups
Difficulty: Hard
==========================================================

You are given a positive integer n representing the number of nodes in an undirected graph. The nodes are labeled from 1 to n.

You are also given a 2D integer array edges, where edges[i] = [ai, bi] indicates that there is a bidirectional edge between nodes ai and bi. Notice that the given graph may be disconnected.

Divide the nodes of the graph into m groups (1-indexed) such that:


	Each node in the graph belongs to exactly one group.
	For every pair of nodes in the graph that are connected by an edge [ai, bi], if ai belongs to the group with index x, and bi belongs to the group with index y, then |y - x| = 1.


Return the maximum number of groups (i.e., maximum m) into which you can divide the nodes. Return -1 if it is impossible to group the nodes with the given conditions.

 
Example 1:


Input: n = 6, edges = [[1,2],[1,4],[1,5],[2,6],[2,3],[4,6]]
Output: 4
Explanation: As shown in the image we:
- Add node 5 to the first group.
- Add node 1 to the second group.
- Add nodes 2 and 4 to the third group.
- Add nodes 3 and 6 to the fourth group.
We can see that every edge is satisfied.
It can be shown that that if we create a fifth group and move any node from the third or fourth group to it, at least on of the edges will not be satisfied.


Example 2:


Input: n = 3, edges = [[1,2],[2,3],[3,1]]
Output: -1
Explanation: If we add node 1 to the first group, node 2 to the second group, and node 3 to the third group to satisfy the first two edges, we can see that the third edge will not be satisfied.
It can be shown that no grouping is possible.


 
Constraints:


	1 <= n <= 500
	1 <= edges.length <= 104
	edges[i].length == 2
	1 <= ai, bi <= n
	ai != bi
	There is at most one edge between any pair of vertices.

==========================================================
*/


class Solution {
public:

    bool Bipartite(vector<vector<int>>&graph,int src, int n, vector<int>& color){
        color[src]=0;
        queue<int>q;
        q.push(src);
        while(!q.empty()){
            int val = q.front();
            int colored = color[val];
            q.pop();
            for(auto i : graph[val]){
                if(color[i]==-1){
                    color[i]=colored^1;
                    q.push(i);
                }
                else if(color[i]==colored){
                    return false;
                }
            }
        }
        return true;
    }

    int bfs(vector<vector<int>>& graph, int n, int src){
        queue<int>q;
        vector<int>vis(n,0);
        q.push(src);
        vis[src]=1;
        int ans=0;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int val = q.front();
                q.pop();
                for(auto i : graph[val]){
                    if(!vis[i]){
                        q.push(i);
                        vis[i]=1;
                    } 
                }
            }
            ans++;
        }
        return ans;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        int ans=0;
        for(auto i : edges){
            adj[(i[0]-1)].push_back(i[1]-1);
            adj[(i[1]-1)].push_back(i[0]-1);
        }
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1 && !Bipartite(adj,i,n,color)){
                return -1;
            }
        }
        int final_ans=0;
        vector<bool> visited(n,false);

        for(int i=0;i<n;i++){
            if(!visited[i]){
                queue<int> q;
                vector<int> component;
                q.push(i);
                visited[i]=true;

                // Find all nodes in this component
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    component.push_back(node);
                    for(int neighbor:adj[node]){
                        if(!visited[neighbor]){
                            visited[neighbor]=true;
                            q.push(neighbor);
                        }
                    }
                }

                // Find the best BFS depth in this component
                int ans=0;
                for(int node:component){
                    ans=max(ans,bfs(adj,n,node));
                }
                final_ans+=ans;
            }
        }
        return final_ans;
    }
};