#include <bits/stdc++.h>
#define MAX_N 200010
using namespace std;
int incidence[MAX_N]{0}, visited[MAX_N]{0};
vector<vector<int>> adjList;
queue<int> q;

void bfs(int root){
  visited[root] = 1;
  q.push(root);

  int v;
  while( !q.empty() ){
    v = q.front(); 
    for(auto &elem : adjList[v] ){
      if(visited[elem] == 0){
        printf("%d %d\n", v, elem);
        visited[elem] = 1;
        q.push(elem);
      }
    }

    q.pop();
  }
}

int main(){
  int n, m;
  adjList.reserve(MAX_N);
  cin >> n >> m;

  int x, y;
  int start_node = -1, node_incidence = -1;
  for(int i = 0; i < m; i++){
    cin >> x >> y;

    adjList[x].push_back(y);
    adjList[y].push_back(x);
    incidence[x]++; incidence[y]++;
    if(incidence[x] > node_incidence){
      start_node = x;
      node_incidence = incidence[x];
    }
    if(incidence[y] > node_incidence){
      start_node = y;
      node_incidence = incidence[y];
    }
  }

  bfs(start_node);
  return 0;
}
