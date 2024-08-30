#include <bits/stdc++.h>
using namespace std;

int DP[13];
int TOTAL_CASES[13];

void compute_DP(){
  DP[0] = 0;
  DP[1] = 0;
  DP[2] = 1;
  for(int i{3}; i <= 12; i++)
    DP[i] = (i-1)*(DP[i-1] + DP[i-2]);
}

void compute_TOTAL(){
  TOTAL_CASES[0] = 1;
  for(int i{1}; i <= 12; i++)
    TOTAL_CASES[i] = i * TOTAL_CASES[i-1];
}

int main(){
  int test_cases;
  cin >> test_cases;
  compute_DP();
  compute_TOTAL();
  int num_hats;
  while(test_cases--){
    cin >> num_hats;
    printf("%d/%d\n", DP[num_hats], TOTAL_CASES[num_hats]);
  }

  return 0;
}
