#include <bits/stdc++.h>
using namespace std;

void primeFactorsMapBuild(map<long long, long long> &m, vector<long long> factors);

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

long long _sieve_size;
bitset<1000010> bs; // 10^7 is the rough limit for the sieve
vector<long long> p; // compact list of primes

void sieve(long long upperbound = 1000002){
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

vector<long long> primeFactors(long long N){
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

long long eulerPhi(long long N){
  vector<long long> factors = primeFactors(N);
  map<long long, long long> factors_map;
  primeFactorsMapBuild(factors_map, factors);

  long long ans = N;
  for(auto &[key, value] : factors_map){
    ans /= key;
    ans *= (key - 1); 
  }

  return ans;
}

int main(){
  sieve();
  int testCases = 0;
  long long n = 0;
  cin >> testCases;
  while(testCases--){
    cin >> n;
    printf("%lld\n", eulerPhi(n));
  }

  return 0;
}
