#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
const int MAX_N = 2;

struct Matrix{
  long long mat[MAX_N][MAX_N];
};

long long mod(long long a, long long m){ return ((a % m) + m) % m; }

Matrix matMul(Matrix a, Matrix b){
  Matrix ans;
  for(int i{0}; i < MAX_N; ++i)
    for(int j{0}; j < MAX_N; ++j)
      ans.mat[i][j] = 0;

  for(int i{0}; i < MAX_N; ++i)
    for(int k{0}; k < MAX_N; ++k){
      if(a.mat[i][k] == 0) continue;
      for(int j{0}; j < MAX_N; ++j){
        ans.mat[i][j] += mod(a.mat[i][k], MOD) * mod(b.mat[k][j], MOD);
        ans.mat[i][j] = mod(ans.mat[i][j], MOD);
      }
    }

  return ans;
}

Matrix matPow(Matrix base, long long p){
  Matrix ans;
  for(int i{0}; i < MAX_N; ++i)
    for(int j{0}; j < MAX_N; ++j)
      ans.mat[i][j] = (i == j);

  while(p){
    if(p & 1)
      ans = matMul(ans, base);
    base = matMul(base, base);
    p >>= 1;
  }

  return ans;
}

int main(){
  long long n;

  cin >> n;
  Matrix problemMatrix;
  problemMatrix.mat[0][0] = 3; problemMatrix.mat[0][1] = 1;
  problemMatrix.mat[1][0] = 1; problemMatrix.mat[1][1] = 3;

  problemMatrix = matPow(problemMatrix, n);
  cout << problemMatrix.mat[0][0] << '\n';
  // This should be 4^n;
  // printf("teste: %lld\n", problemMatrix.mat[0][0] + problemMatrix.mat[1][0]);

  return 0;
}
