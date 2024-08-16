#include<bits/stdc++.h>

int main(){
  int test_cases;
  scanf("%d", &test_cases);

  long long a, b, n;
  while(test_cases--){
    scanf("%lld %lld %lld", &a, &b, &n);
    if( n % 3 == 0 ) printf("%lld\n", a);
    else if( n % 3 == 1 ) printf("%lld\n", b);
    else printf("%lld\n", (a ^ b));
  }

  return 0;
}
