#include <bits/stdc++.h>
long long MOD;

int mod(long long a, long long m){ return ((a % m) + m) % m; } // ensures mod will be positive.

const int MAX_N = 2;
struct Matrix{
  long long mat[MAX_N][MAX_N]; 
  int row=MAX_N, col=MAX_N;
};

Matrix matMul(Matrix a, Matrix b){
  Matrix ans;
  for( int i{0}; i < ans.row; ++i ){
    for( int j{0}; j < ans.col; ++j ){
      ans.mat[i][j] = 0;
    }
  }

  int dim = MAX_N;
  for(int i{0}; i < dim; ++i ){
    for(int k{0}; k < dim; ++k ){
      if( a.mat[i][k] == 0 ) continue;
      for(int j{0}; j < dim; ++j ){
        ans.mat[i][j] += mod(a.mat[i][k], MOD) * mod(b.mat[k][j], MOD);
        ans.mat[i][j] = mod(ans.mat[i][j], MOD);
      }
    }
  }

  return ans;
}

Matrix matPow( Matrix base, int p ){
  Matrix ans;
  for(int i{0}; i < ans.row; ++i )
    for(int j{0}; j < ans.col; ++j )
      ans.mat[i][j] = ( i == j ); // Identity Matrix
  
  while( p ){
    if( p & 1 )
      ans = matMul(ans, base);
    base = matMul(base, base);
    p >>= 1;
  }

  return ans;
}

long long pow(int a, int p){
  if( p == 0 ) return 1;
  int ans = pow(a, p/2);
  ans = ans * ans;
  if( p & 1 )
    ans = ans*a;

  return ans;
}

int main(){
  long long a, b;
  Matrix fibMatrix;
  while( scanf("%lld %lld", &a, &b) != EOF ){
    fibMatrix.mat[0][0] = 1; fibMatrix.mat[0][1] = 1; fibMatrix.mat[1][0] = 1; fibMatrix.mat[1][1] = 0;
    MOD = pow(2, b);
    fibMatrix = matPow(fibMatrix, a - 1);
    printf("%lld\n", fibMatrix.mat[0][0]); 
  }

  return 0;
}
