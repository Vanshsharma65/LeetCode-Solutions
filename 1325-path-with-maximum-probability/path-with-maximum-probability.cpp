#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});
        }
        vector<double> max_prob(n, 0.0);
        max_prob[start_node] = 1.0;
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});
        while (!pq.empty()) {
            auto [curr_prob, u] = pq.top();
            pq.pop();
            if (u == end_node) {
                return curr_prob;
            }
            if (curr_prob < max_prob[u]) continue;
            for (const auto& neighbor : adj[u]) {
                int v = neighbor.first;
                double edge_prob = neighbor.second;
                if (curr_prob * edge_prob > max_prob[v]) {
                    max_prob[v] = curr_prob * edge_prob;
                    pq.push({max_prob[v], v});
                }
            }
        }
        return max_prob[end_node]; 
    }
};