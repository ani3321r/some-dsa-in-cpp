#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//dfs
class Solution1{
    private:
        void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls){
            vis[node] = 1;
            ls.push_back(node);
            for(auto it : adj[node]){
                if(!vis[it]){
                    dfs(it, adj, vis, ls);
                }
            }
        }
    public:
        vector<int> dfsOfGraph(int V, vector<int> adj[]){
            int vis[V] = {0};
            int start = 0;
            vector<int> ls;
            dfs(start, adj, vis, ls);
            return ls;
        }    
};

//bfs
class Solutions2{
    public:
        vector<int> bfsOfGraph(int V, vector<int> adj[]){
            int vis[V] = {0};
            vis[0] = 1;
            queue<int> q;
            q.push(0);
            vector<int> bfs;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                bfs.push_back(node);

                for(auto it: adj[node]){
                    if(!vis[it]){
                        vis[it] = 1;
                        q.push(it);
                    }
                }
            }
            return bfs;
        }
};