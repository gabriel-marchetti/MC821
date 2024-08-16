#include<bits/stdc++.h>

const long long MOD = 1e9 + 7;
const int MAX_N = 201;

struct Matrix{
  long long mat[MAX_N][MAX_N];
};

long long mod(long long a, long long m){ return ((a % m) + m) % m;}

Matrix matMul(Matrix a, Matrix b, int dim){
  Matrix ans;
  for(int i{0}; i < dim; ++i){
    for(int j{0}; j < dim; ++j){
      ans.mat[i][j] = 0;
    }
  }

  for(int i{0}; i < dim; ++i){
    for(int k{0}; k < dim; ++k){
      if(a.mat[i][k] == 0) continue;
      for(int j{0}; j < dim; ++j){
        ans.mat[i][j] += mod(a.mat[i][k], MOD) * mod(b.mat[k][j], MOD);
        ans.mat[i][j] = mod(ans.mat[i][j], MOD);
      }
    }
  }
  
  return ans;
}

Matrix matPow(Matrix base, long long p, int dim){
  Matrix ans;
  for(int i{0}; i < dim; ++i){
    for(int j{0}; j < dim; ++j){
      ans.mat[i][j] = (i == j);
    }
  }

  while(p){
    if(p&1)
      ans = matMul(ans, base, dim);
    base = matMul(base, base, dim);
    p >>= 1;
  }

  return ans;
}

int main(){
  int nodes, edges, queries;
  scanf("%d %d %d", &nodes, &edges, &queries);
  Matrix edgeMatrix;
  Matrix auxMatrix;
  for(int i{0}; i < nodes; ++i)
    for(int j{0}; j < nodes; ++j)
      edgeMatrix.mat[i][j] = 0;

  int a, b;
  for(int i{0}; i < edges; i++){
    scanf("%d %d", &a, &b);
    a--; b--;
    edgeMatrix.mat[a][b]++;
  }

  int start, end;
  long long pathSize;
  for(int iq{0}; iq < queries; ++iq){
    scanf("%d %d %lld", &start, &end, &pathSize);
    start--; end--;
    auxMatrix = matPow(edgeMatrix, pathSize, nodes);
    printf("%lld\n", auxMatrix.mat[start][end]);
  }


  return 0;
}
