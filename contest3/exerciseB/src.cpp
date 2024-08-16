#include<bits/stdc++.h>

const long long MOD = 1e9 + 7;
const int MAX_N = 105;

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

void printMatrix(Matrix *matrix, int dim){
  for(int i{0}; i < dim; ++i){
    for(int j{0}; j < dim; ++j )
      printf("%lld ", matrix->mat[i][j]);
    printf("\n");
  }
}

int main(){
  long long nodes, edges, lenPath;
  Matrix edgeMatrix;
  scanf("%lld %lld %lld", &nodes, &edges, &lenPath);
  for(int i{0}; i < nodes; ++i){
    for(int j{0}; j < nodes; ++j){
      edgeMatrix.mat[i][j] = 0;
    }
  }

  int p, q;
  for(int i{0}; i < edges; i++){
    scanf("%d %d", &p, &q);
    --p; --q;
    edgeMatrix.mat[p][q] += 1;
  }

  edgeMatrix = matPow(edgeMatrix, lenPath, nodes);
  printf("%lld\n", edgeMatrix.mat[0][nodes-1]);
  // printMatrix(&edgeMatrix, nodes);

  return 0;
}
