#include <bits/stdc++.h>
using namespace std;

long long _sieve_size;
bitset<1000010> bs; // 10^7 is the rough limit for the sieve
vector<long long> p; // compact list of primes

void sieve(long long upperbound = 1000005){
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

// OBS: N >= 1
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

int main(){
  sieve();
  int testCases = 0;
  long long n = 0, i = 0;
  cin >> testCases;
  while(testCases--){
    cin >> n;
    for(i = n; i >= 1; --i){
      if(!isPrime_withSieve(i)) break;
    }

    if(i == 1){
      cout << "1\n";
      continue;
    }
    if( i % 2 == 1 ) i--;

    // There is a prime at range n;
    vector<long long> factors;
    factors = primeFactors(i);
    //for(auto factor : factors) 
    //  cout << factor << ' ';
    //cout << '\n';

    cout << i / factors[0] << '\n';
  }

  return 0;
}
