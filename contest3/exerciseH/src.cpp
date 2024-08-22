#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
const int MAX=205;

struct Matrix{
  long long mat[MAX][MAX]; 
};

Matrix matMul(Matrix a, Matrix b, int dim){
  Matrix ans;
  for(int i{0}; i < dim; ++i){
    for(int j{0}; j < dim; ++j){
      ans.mat[i][j] = 0;
    }
  } 

  for(int i{0}; i < dim; ++i){
    for(int k{0}; k < dim; ++k){
      if( a.mat[i][k] == 0 ) continue;
      for(int j{0}; j < dim; ++j){
        ans.mat[i][j] += ((a.mat[i][k] % MOD) * (b.mat[k][j] % MOD)) % MOD;
      }
    }
  }

  return ans;
}

Matrix matPow(Matrix m, long long pow, int dim){
  Matrix ans;
  for(int i{0}; i < dim; ++i)
    for(int j{0}; j < dim; ++j)
      m.mat[i][j] = (i == j);

  while(pow){
    if(pow & 1)
      ans = matMul(ans, m, dim);
    m = matMul(m, m, dim);
    pow >>= 1;
  }

  return ans;
}

int main(){
  int vertex, edges, queries;
  scanf("%d %d %d", &vertex, &edges, &queries);
  
  return 0;
}
