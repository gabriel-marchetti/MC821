#include<bits/stdc++.h>

const long long MOD = 1e9 + 7;
const int MAX_N = 51;

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

int convertToSize(char p){
  if( 97 <= (int) p && (int) p <= 122 ) return (int) p - 97 + 1;
  return ( (int) p - 65 + 27 ); 
}

long long computeAllCombinations(Matrix *matrix, int dim){
  long long sum = 0;
  for(int i{0}; i < dim; ++i){
    for(int j{0}; j < dim; ++j){
      sum += matrix->mat[i][j];
    }
  }

  return sum;
}

void printMatrix(Matrix *matrix, int dim){
  for(int i{0}; i < dim; i++){
    for(int j{0}; j < dim; j++){
      printf("%lld ", matrix->mat[i][j]);
    }
    printf("\n");
  }
}

using namespace std;
int main(){
  long long chainSize, nucleotides, restrictions;
  scanf("%lld %lld %lld", &chainSize, &nucleotides, &restrictions);
  Matrix possibleChains;
  for(int i{0}; i < nucleotides; ++i){
    for(int j{0}; j < nucleotides; ++j){
      possibleChains.mat[i][j] = 1;
    }
  } 

  char str[2];
  int ip, iq;
  for(int i{0}; i < restrictions; ++i){
    scanf("%s", str);
    //printf("%c %c\n", str[0], str[1]);
    ip = convertToSize(str[0]);
    iq = convertToSize(str[1]);
    ip--; iq--;
    // cout << ip << ' ' << iq << '\n';
    possibleChains.mat[ip][iq] = 0;
 }
  // printMatrix(&possibleChains, nucleotides);
  long long totalCombinations = 0;
  if( chainSize == 1 ){
    totalCombinations = nucleotides;
  }
  else{
    possibleChains = matPow(possibleChains, chainSize - 1, nucleotides);
    totalCombinations = computeAllCombinations(&possibleChains, nucleotides);
  }

  printf("%lld\n", totalCombinations);

  return 0;
}
