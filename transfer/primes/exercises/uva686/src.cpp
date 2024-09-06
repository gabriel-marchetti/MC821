#include <bits/stdc++.h>
using namespace std;

long long _sieve_size;
bitset<1000010> bs;
set<long long> primes;

void sieve(long long upperbound){
  _sieve_size = upperbound + 1;
  bs.set();
  bs[0] = bs[1] = 0;
  for(long long i{2}; i < _sieve_size; ++i){
    if(bs[i]){
      for(long long j = i * i; j < _sieve_size; j += i) bs[j] = 0;
      primes.insert(i);
    }
  }
}

int main(){
  long long n;
  sieve(100000);
  while( scanf("%lld", &n) ){
    if(n == 0) break;
    long long b;
    // This will find the maximum a - b since it starts at the lowest
    // prime, then b = n - (*it) will be maximum.

    //printf("%d\n", (int)primes.size());
    long long ans = 0, max_found_prime = -1;
    for(auto it = primes.begin(); it != primes.end(); ++it){
      b = n - (*it);
      if(primes.count(b)){
        if(n - b > b) break;
        //printf("%lld = %lld + %lld\n", n, n - b, b);
        ans++;
      }  
    }

    printf("%lld\n", ans);
  }

  return 0;
}