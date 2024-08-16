#include<bits/stdc++.h>
const int MAX_N = 55;
const int MOD = 1000000007;

struct Matrix{
  long long mat[MAX_N][MAX_N];
};

long long mod(long long a, long long m){ return ((a % m) + m) % m; }

Matrix matMul(Matrix a, Matrix b, int dim){
  Matrix ans;
  for(int i{0}; i < dim; ++i){
    for(int j{0}; j < dim; ++j){
      ans.mat[i][j] = 0;
    }
  }

  for(int i{0}; i < dim; ++i)
    for(int k{0}; k < dim; ++k){
      if(a.mat[i][k] == 0) continue;
      for(int j{0}; j < dim; ++j){
        ans.mat[i][j] += mod(a.mat[i][k], MOD) * mod(b.mat[k][j], MOD);
        ans.mat[i][j] = mod(ans.mat[i][j], MOD);
      }
    }

  return ans;
}

Matrix matPow(Matrix base, int p, int dim){
  Matrix ans;
  for(int i{0}; i < dim; ++i)
    for(int j{0}; j < dim; ++j)
      ans.mat[i][j] = (i == j);

  while(p){
    if(p & 1)
      ans = matMul(ans, base, dim);
    base = matMul(base, base, dim);
    p >>= 1;
  }

  return ans;
}

void readMatrix(Matrix *matrix, int dim){
  for(int i{0}; i < dim; ++i)
    for(int j{0}; j < dim; ++j)
      scanf("%lld", &(matrix->mat[i][j]));
}

void printMatrix(Matrix *matrix, int dim){
  for(int i{0}; i < dim; ++i){
    for(int j{0}; j < dim; ++j)
      printf("%lld ", (matrix->mat[i][j]));
    printf("\n");
  }
}

int main(){
  int test_cases;
  scanf("%d", &test_cases);

  int dim, power;
  Matrix matrix;
  while(test_cases--){
    scanf("%d %d", &dim, &power);
    readMatrix(&matrix, dim);
    matrix = matPow(matrix, power, dim);
    printMatrix(&matrix, dim);
  }

  return 0;
}
