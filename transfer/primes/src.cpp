#include <bits/stdc++.h>
using namespace std;

bool isPrime(unsigned long long N){
  if( N == 1 || N == 0 )
    return false;
  if( N % 2 == 0 && N != 2 )
    return false;
  if( N == 2 )
    return true;

  for(int i{3}; i <= sqrt(N); i += 2){
    if( N % i == 0 ) return false;
  }

  return true;
}

long long _sieve_size;
bitset<10000010> bs; // 10^7 is the rough limit for the sieve
vector<long long> p; // compact list of primes

void sieve(long long upperbound){
  _sieve_size = upperbound + 1;
  bs.set();
  bs[0] = bs[1] = 0;
  for(long long i{2}; i < _sieve_size; ++i){
    if(bs[i]){
      for(long long j = i * i; j < _sieve_size; j += i) bs[j] = 0;
      p.push_back(i);
    }
  }
}

// note: Only works if N <= (last prime in p)^2
bool isPrime_withSieve(unsigned long long N){
  if( N < _sieve_size ) return bs[N];
  for(int i{0}; i < (int)p.size() && p[i]*p[i] <= N; i++){
    if(N % p[i] == 0) return false;
  }

  return true;
}

int main(){
  for(int i{1}; i < 15; i++){
    printf("isPrime(%d): %d\n", i, isPrime(i));
  }

  printf("---------------------------------------\n");
  printf("isPrime(104729): %d\n", isPrime(104729));
  printf("isPrime(1e9+7): %d\n", isPrime(1e9+7));
  printf("isPrime(2^31 - 1): %d\n", isPrime((1LL << 31) - 1));
  printf("isPrime(1299709): %d\n", isPrime(1299709));
  printf("---------------------------------------\n");

  sieve(10000000);
  printf("isPrime_withSieve(2^31-1): %d\n", isPrime_withSieve((1LL<<31)-1));
  printf("isPrime_withSieve(136117223861LL): %d\n", isPrime_withSieve(136117223861LL));


  return 0;
}
