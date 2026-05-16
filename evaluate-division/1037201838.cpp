
/*
==========================================================
Problem: Evaluate Division
Difficulty: Medium
==========================================================

You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

Note: The variables that do not occur in the list of equations are undefined, so the answer cannot be determined for them.

 
Example 1:


Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
Explanation: 
Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? 
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
note: x is undefined => -1.0

Example 2:


Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
Output: [3.75000,0.40000,5.00000,0.20000]


Example 3:


Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
Output: [0.50000,2.00000,-1.00000,-1.00000]


 
Constraints:


	1 <= equations.length <= 20
	equations[i].length == 2
	1 <= Ai.length, Bi.length <= 5
	values.length == equations.length
	0.0 < values[i] <= 20.0
	1 <= queries.length <= 20
	queries[i].length == 2
	1 <= Cj.length, Dj.length <= 5
	Ai, Bi, Cj, Dj consist of lower case English letters and digits.

==========================================================
*/


class Solution {
public:

    double dfsMultiply(map<string, vector<pair<string, double>>>& adj, string& src, string& dest, unordered_set<string>& visited, double currentWeight){
    visited.insert(src);
    if (src == dest)
        return currentWeight;
    for (auto neighbor : adj.at(src)) {
        string nextNode = neighbor.first;
        double weight = neighbor.second;
        // cout<<nextNode<<" "<<weight<<"\n";
        if (visited.find(nextNode) == visited.end()) {
            double result = dfsMultiply(adj, nextNode, dest, visited,currentWeight * weight);
            if (result != -1)
                return result;
        }
    }
    return -1;
}

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        set<string>st;
        int n=equations.size();
        for(int i=0;i<n;i++){
            st.insert(equations[i][0]);
            st.insert(equations[i][1]);
        }
        map<string, vector<pair<string, double>>> adj;
        for(int i=0;i<n;i++){
            adj[equations[i][0]].push_back(make_pair(equations[i][1], values[i]));
            adj[equations[i][1]].push_back(make_pair(equations[i][0], (1/values[i])));
        }
        // for (auto vertex : adj) {
        //     cout << "Adjacency list of vertex " << vertex.first << ": ";
        //     for (auto edge : vertex.second) {
        //         cout << "(" << edge.first << ", " << edge.second << ") ";
        //     }
        //     cout << endl;
        // }
        vector<double>ans;
        for(int i=0;i<queries.size();i++){
            if(st.find(queries[i][0])==st.end() || st.find(queries[i][1])==st.end()){
                ans.push_back(-1);
            }
            else{
                unordered_set<string> visited;
                string source = queries[i][0];
                string destination = queries[i][1];
                double W=1;
                double temp = dfsMultiply(adj, source, destination, visited, W);
                if (temp != -1){
                    ans.push_back(temp);
                }
                else{
                    ans.push_back(-1);
                }
            }
        }
        return ans;
    }
};