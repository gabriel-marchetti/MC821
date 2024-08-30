#include <bits/stdc++.h>
using namespace std;

unsigned long long memo[24][150];

const int num_lines = 24;
const int num_cols = 150;
unsigned long long POSITIVE_CASES, TOTAL_CASES;

void compute_DP_table(){
  for(int i{1}; i <= 6; i++)
    memo[0][i] = 1;

  unsigned long long partial_case;
  for(int i{1}; i < num_lines; i++){
    for(int j{0}; j < num_cols; j++){
      partial_case = 0;
      for(int k{1}; k <= 6; k++){
        if(j - k < 0) continue;
        partial_case += memo[i-1][j-k];
      }
      memo[i][j] = partial_case;
    }
  }
}

unsigned long long gcd(unsigned long long a, unsigned long long b){
  if(b == 0)
    return a;
  return gcd(b, a % b);
}

unsigned long long compute_positive_cases(int num_dices, unsigned long long sum){
  if(sum > 6 * num_dices) return 0;
  if(sum <= 0) return 0;
  if(num_dices == 0) return 0;
  unsigned long long sum_cases{0};
  for(unsigned long long i{sum}; i < num_cols; i++){
    sum_cases += memo[num_dices-1][i];
  }
  return sum_cases;
}

unsigned long long compute_total_cases(int num_dices){
  if(num_dices == 0) return 0;
  unsigned long long total_cases = 1;
  for(int i{0}; i < num_dices; i++){
    total_cases *= 6;
  }

  return total_cases;
}

int main(){
  int num_dices;
  unsigned long long gcd_factor, sum;
  memset(memo, 0, sizeof(memo));
  compute_DP_table();
  while(scanf("%d %llu", &num_dices, &sum) == 2){
    if(num_dices == 0 && sum == 0) break;
    POSITIVE_CASES = compute_positive_cases(num_dices, sum);
    TOTAL_CASES = compute_total_cases(num_dices);
    gcd_factor = gcd(POSITIVE_CASES, TOTAL_CASES);

    POSITIVE_CASES = POSITIVE_CASES / gcd_factor;
    TOTAL_CASES = TOTAL_CASES / gcd_factor;

    if(POSITIVE_CASES == 0){
      printf("0\n");
    }
    else if(TOTAL_CASES == 1){
      printf("%llu\n", POSITIVE_CASES);
    }
    else{
      printf("%llu/%llu\n", POSITIVE_CASES, TOTAL_CASES);
    }
  }

  return 0;
}
