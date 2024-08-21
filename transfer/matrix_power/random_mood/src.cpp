#include <bits/stdc++.h>

double probHappy(double prob, long long n){
  if( n == 0 ) return 1;
  if( n == 1 ) return 1 - prob; 
  double tmp = probHappy(prob, n / 2);
  if( n & 1 )
      return 2 * prob * ( 1 - tmp ) * tmp + (1 - prob) * tmp * tmp + (1 - prob) * (1 - tmp) * (1 - tmp);
  return tmp * tmp + (1 - tmp) * (1 - tmp);
}

int main(){
  long long n;
  double p;
  scanf("%lld %lf", &n, &p);
  printf("%.7lf\n", probHappy(p, n));

  return 0;
}
