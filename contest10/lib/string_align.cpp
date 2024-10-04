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

void get_pairs(
  pair<int, int> p, 
  Matrix mat, 
  vector<pair<int, int>> &pairs,
  char *P,
  char *Q
){
  int i = p.first, j = p.second;
  if(i < 0 || j < 0){
    return;
  }
  if(i > mat.n || j > mat.m){
    return;
  }

  if(i == 0 && j == 0){
    pairs.push_back({0, 0});
    return;
  }
  if(i == 0 && j != 0){
    pairs.push_back({0, j});
    return;
  }
  if(i != 0 && j == 0){
    pairs.push_back({i, 0});
    return;
  }

  if( mat.table[i][j] == mat.table[i-1][j-1] + (P[i-1] == Q[j-1] ? 2 : -1) ){
    pairs.push_back({i, j});
    get_pairs({i-1, j-1}, mat, pairs, P, Q);
    return;
  }  
  if( mat.table[i][j] == mat.table[i][j-1] - 1 ){
    pairs.push_back({i, j});
    get_pairs({i, j-1}, mat, pairs, P, Q);
    return;
  }
  if( mat.table[i][j] == mat.table[i-1][j] - 1 ){
    pairs.push_back({i, j});
    get_pairs({i-1, j}, mat, pairs, P, Q);
    return;
  }
}

void convert_pairs_to_string(
  vector<pair<int, int>> p, 
  char *P, 
  char *Q,
  string &sub_P,
  string &sub_Q
){
  sub_P.clear(); sub_Q.clear();
  int ip{0}, iq{0};

  for(int i{0}; i < (int) p.size() - 1; i++){
    if(p[i].first + 1 == (p[i+1].first)){
      sub_P.push_back(P[ip]);
      ip++;
    }
    else{
      sub_P.push_back('-');
    }
    if(p[i].second + 1 == (p[i+1].second)){
      sub_Q.push_back(Q[iq]);
      iq++;
    }
    else{
      sub_Q.push_back('-');
    }
  }
}

int main(){
  char P[MAX_SIZE] = "ACAATCC", Q[MAX_SIZE] = "AGCATGC";
  int n = (int) strlen(P), m = (int) strlen(Q);
  Matrix mat(n, m);
  memset(mat.table, 0, sizeof(mat.table));

  for(int i{1}; i <= n; i++){
    mat.table[i][0] = i * (-1);
  }

  for(int i{1}; i <= n; i++){
    mat.table[0][i] = i * (-1);
  }

  // DP-compute;
  for(int i{1}; i <= n; i++){
    for(int j{1}; j <= m; j++){
      mat.table[i][j] = mat.table[i-1][j-1] + ( P[i-1] == Q[j-1] ? 2 : -1 );
      mat.table[i][j] = max(mat.table[i][j], mat.table[i-1][j] - 1);
      mat.table[i][j] = max(mat.table[i][j], mat.table[i][j-1] - 1);
    }
  }

  vector<pair<int, int>> v_p;
  mat.print_matrix();
  get_pairs({n, m}, mat, v_p, P, Q);

  reverse(v_p.begin(), v_p.end());
  /* for(auto &elem : v_p){
    printf("%3d %3d\n", elem.first, elem.second);
  } */
  
  printf("MAX. Align Score: %d\n", mat.table[n][m]);

  string sub_P, sub_Q;
  convert_pairs_to_string(v_p, P, Q, sub_P, sub_Q);
  cout << sub_P << endl;
  cout << sub_Q << endl;

  return 0;
}
