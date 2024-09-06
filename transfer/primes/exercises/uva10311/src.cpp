#include <bits/stdc++.h>
#define MAX (10000010)
using namespace std;


long long _sieve_size;
bitset<MAX> bs;
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
  sieve(MAX);
  while( scanf("%lld", &n) != EOF ){
    long long b;
    // This will find the maximum a - b since it starts at the lowest
    // prime, then b = n - (*it) will be maximum.

    //printf("%d\n", (int)primes.size());
    long long ans = 0;
    bool flag = false;
    for(auto it = primes.begin(); it != primes.end(); ++it){
      b = n - (*it);
      if(primes.count(b)){
        flag = true;
        break;
      }  
    }

    if(flag)
      printf("%lld is the sum of %lld and %lld.\n", n, n - b, b);
    else
      printf("%lld is not the sum of two primes!\n", n);
  }

  return 0;
}
