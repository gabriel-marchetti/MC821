#include<bits/stdc++.h>
using namespace std;

int main(){
  double N, K, prob{0}, aux_prob{0};
  cin >> N >> K;
  for(int i{1}; i <= K-1; i++){
    aux_prob += pow(0.5, ceil(log2(K-i)) );
  }
 
  prob = (N-K+1.0)/N + (K-1.0)/N * aux_prob;
  printf("%.10lf\n", prob);

  return 0;
}
