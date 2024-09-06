#include <bits/stdc++.h>
using namespace std;

long long _sieve_size;
bitset<33000010> bs; // 10^7 is the rough limit for the sieve
vector<long long> p; // compact list of primes

void sieve(long long upperbound = 33000002){
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

bool isPrime_withSieve(unsigned long long N){
  if( N < _sieve_size ) return bs[N];
  for(int i{0}; i < (int)p.size() && p[i]*p[i] <= N; i++){
    if(N % p[i] == 0) return false;
  }

  return true;
}

vector<long long> primeFactors(long long N){
  long long N_copy = N;
  vector<long long> factors;
  factors.clear();
  for(int i = 0; (i < (int)p.size()) && (p[i]*p[i] <= N); ++i){
    while(N % p[i] == 0){
      N /= p[i];
      factors.push_back(p[i]);
    }
  }
  if(N != 1) factors.push_back(N);
  return factors;
}

void primeFactorsMapBuild(map<long long, long long> &m, vector<long long> factors){
  m.clear();
  for(auto pf : factors){
    if( m.find(pf) == m.end() ){
      m[pf] = 1;
    }
    else{
      m[pf] += 1;
    }
  }
}

void printFactors(vector<long long> factors){
  map<long long, long long> m;
  primeFactorsMapBuild(m, factors);

  for(const auto& [key, value] : m){
    printf("%lld^%lld ", key, value);
  }

  printf("\n");
}

int main(){
  long long number;
  sieve();
  while( scanf("%lld", &number) ){
    if(number == 0) break;

    if( isPrime_withSieve(number) ){
      printf("%lld^1\n", number);
      continue;
    }
    vector<long long> factors = primeFactors(number);
    printFactors(factors);
  }

  return 0;
}
