#include <bits/stdc++.h>

const int MAX_N = 2;
struct Matrix{
  long long mat[MAX_N][MAX_N];
};

Matrix matMul(Matrix a, Matrix b){
  Matrix ans;
  // Initialize matrix ans for supporting adding without trash
  for(int i{0}; i < MAX_N; ++i)
    for(int j{0}; j < MAX_N; ++j)
      ans.mat[i][j] = 0;

  // The multiplication indeed.
  for(int i{0}; i < MAX_N; ++i)
    for(int k{0}; k < MAX_N; ++k){
      if(a.mat[i][k] == 0) continue;
      for(int j{0}; j < MAX_N; ++j){
        ans.mat[i][j] += a.mat[i][k] * b.mat[k][j];
      }
    }

  return ans;
}

Matrix matPow(Matrix base, long long p){
  Matrix ans;
  for(int i{0}; i < MAX_N; ++i)
    for(int j{0}; j < MAX_N; ++j)
      ans.mat[i][j] = ( i == j );
  
  while( p ){
    if( p & 1 )
      ans = matMul(ans, base);
    base = matMul(base, base);
    p >>= 1;
  }

  return ans;
}

int main(){
  long long p, q, n, result;
  Matrix problemMatrix;
  while( scanf("%lld %lld", &p, &q) ){
    if( p == 0 && q == 0) break;
    scanf("%lld", &n);
    problemMatrix.mat[0][0] = p; problemMatrix.mat[0][1] = -q;
    problemMatrix.mat[1][0] = 1; problemMatrix.mat[1][1] = 0;

    problemMatrix = matPow(problemMatrix, n);
    result = problemMatrix.mat[1][0] * p + problemMatrix.mat[1][1] * 2; 
    
    printf("%lld\n", result);
  }

  return 0;
}
