#include <bits/stdc++.h>
#define MAX_N 1010
using namespace std;

int n, m, num_rooms = 0;

void dfs(char mat[MAX_N][MAX_N], int i, int j){
  if(i < 0 || i >= n){
    return;
  }
  if(j < 0 || j >= m){
    return;
  }

  if(mat[i][j] != '.') return;

  mat[i][j] = '?'; 
  dfs(mat, i + 1, j);
  dfs(mat, i - 1, j);
  dfs(mat, i, j + 1);
  dfs(mat, i, j - 1);
}


int main(){
  char mat[MAX_N][MAX_N];
  cin >> n >> m;

  char tmp;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> tmp;
      mat[i][j] = tmp;
    }
  }

  for(int  i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(mat[i][j] == '.'){
        dfs(mat, i, j);
        num_rooms++;
      }
    }
  }

  cout << num_rooms << '\n';

  return 0;
}
