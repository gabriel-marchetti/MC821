#include<bits/stdc++.h>
const int MAX_N=2;
const int MOD = 1000000007;

struct Matrix{
  long long mat[MAX_N][MAX_N];
};

Matrix IDENTITY;

void initializeId(){
  for(int i{0}; i < MAX_N; i++)
    for(int j{0}; j < MAX_N; j++)
      IDENTITY.mat[i][j] = (i == j);
}

Matrix matMul(Matrix a, Matrix b){
  Matrix ans;
  for(int i{0}; i < MAX_N; ++i)
    for(int j{0}; j < MAX_N; ++j)
      ans.mat[i][j] = 0;

  for(int i{0}; i < MAX_N; ++i)
    for(int k{0}; k < MAX_N; ++k){
      if( a.mat[i][k] == 0 ) continue;
      for(int j{0}; j < MAX_N; ++j){
        ans.mat[i][j] += (a.mat[i][k] % MOD) * (b.mat[k][j] % MOD);
        ans.mat[i][j] %= MOD;
      }
    }

  return ans;
}

Matrix matPow(Matrix base, long long p){
  if( p == 0 ) return IDENTITY;
  if( p == 1 ) return base;
  Matrix tmp = matPow(base, p / 2);
  tmp = matMul(tmp, tmp);
  if( p % 2 ) 
    tmp = matMul(base, tmp);
  return tmp;
}


int main(){
  initializeId();
  long long n;
  scanf("%lld", &n);
  Matrix fibMatrix;
  fibMatrix.mat[0][0] = 1; fibMatrix.mat[0][1] = 1;
  fibMatrix.mat[1][0] = 1; fibMatrix.mat[1][1] = 0;
  fibMatrix = matPow(fibMatrix, n);
  printf("%lld\n", fibMatrix.mat[0][1]);

  return 0;
}
