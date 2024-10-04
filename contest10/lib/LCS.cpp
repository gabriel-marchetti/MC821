#include <bits/stdc++.h>
#define MAX_SIZE 20
using namespace std;

struct Matrix{
  int table[MAX_SIZE][MAX_SIZE];
  int m, n;

  Matrix(int rows, int cols){
    if(rows > MAX_SIZE || cols > MAX_SIZE){
      cerr << "Matrix dimensions exceed static allocation size" << endl;
    }

    m = rows;
    n = cols;
  }

  void print_matrix(){
    for(int i{0}; i <= n; i++){
      for(int j{0}; j <= m; j++){
        printf("%3d", table[i][j]);
      }
      printf("\n");
    } 
  }
};


int main(){
  char P[MAX_SIZE] = "ACAATCC", Q[MAX_SIZE] = "AGCATGC";
  int n = (int) strlen(P), m = (int) strlen(Q);
  Matrix mat(n, m);
  memset(mat.table, 0, sizeof(mat.table));

  for(int i{1}; i <= n; i++){
    mat.table[i][0] = 0;
  }

  for(int i{1}; i <= n; i++){
    mat.table[0][i] = 0;
  }

  // DP-compute;
  for(int i{1}; i <= n; i++){
    for(int j{1}; j <= m; j++){
      mat.table[i][j] = mat.table[i-1][j-1] + ( P[i-1] == Q[j-1] ? 1 : 0 );
      mat.table[i][j] = max(mat.table[i][j], mat.table[i-1][j]);
      mat.table[i][j] = max(mat.table[i][j], mat.table[i][j-1]);
    }
  }

  vector<pair<int, int>> v_p;
  mat.print_matrix();

  reverse(v_p.begin(), v_p.end());
  for(auto &elem : v_p){
    printf("%3d %3d\n", elem.first, elem.second);
  }
  
  printf("MAX. Align Score: %d\n", mat.table[n][m]);
  

  return 0;
}

