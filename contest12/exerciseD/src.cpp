#include <bits/stdc++.h>
using namespace std;

#define MAX_NODES 200010

vector<int> graph[MAX_NODES];
long long dp[MAX_NODES], answers[MAX_NODES];

void first_dfs(int node, int parent, long long depth){
  answers[1] += depth;
  dp[node] = 1;
  for(int neigh : graph[node]){
    if( neigh != parent ){
      first_dfs(neigh, node, depth + 1);
      dp[node] += dp[neigh];
    }
  }
}

void second_dfs(int node, int parent, int num_nodes){
  for(int neigh : graph[node]){
    if( neigh != parent ){
      answers[neigh] = answers[node] + num_nodes - 2 * dp[neigh];
      second_dfs(neigh, node, num_nodes);
    }
  }
}

int main(){
  int num_nodes;
  cin >> num_nodes;
  for(int i{1}; i < num_nodes; i++){
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  first_dfs(1, 0, 0);
  second_dfs(1, 0, num_nodes);
  for(int i{1}; i <= num_nodes; i++){
    cout << answers[i] << ' ';
  }
  cout << endl;

  return 0;
}
