#include <bits/stdc++.h>
using namespace std;
long long MOD;

const int MAX_N = 2;
struct Matrix{
  long long mat[MAX_N][MAX_N]; 
};

Matrix matMul(Matrix a, Matrix b){
  Matrix ans;
  for( int i{0}; i < MAX_N; ++i ){
    for( int j{0}; j < MAX_N; ++j ){
      ans.mat[i][j] = 0;
    }
  }

  for(int i{0}; i < MAX_N; ++i ){
    for(int k{0}; k < MAX_N; ++k ){
      if( a.mat[i][k] == 0 ) continue;
      for(int j{0}; j < MAX_N; ++j ){
        ans.mat[i][j] += (a.mat[i][k] % MOD) * (b.mat[k][j] % MOD);
        ans.mat[i][j] = (ans.mat[i][j] % MOD);
      }
    }
  }
  return ans;
}

Matrix matPow( Matrix base, int p ){
  Matrix ans;
  for(int i{0}; i < MAX_N; ++i )
    for(int j{0}; j < MAX_N; ++j )
      ans.mat[i][j] = ( i == j ); // Identity Matrix
  
  while( p ){
    if( p & 1 )
      ans = matMul(ans, base);
    base = matMul(base, base);
    p >>= 1;
  }

  return ans;
}


int main(){
  int a, b;
  Matrix fibMatrix;
  while( scanf("%d %d", &a, &b) == 2 ){
    fibMatrix.mat[0][0] = 1; fibMatrix.mat[0][1] = 1; fibMatrix.mat[1][0] = 1; fibMatrix.mat[1][1] = 0;
    MOD = 1 << b;
    fibMatrix = matPow(fibMatrix, a);
    printf("%lld\n", fibMatrix.mat[0][1]); 
  }

  return 0;
}
