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

}

int main(){


  return 0;
}
