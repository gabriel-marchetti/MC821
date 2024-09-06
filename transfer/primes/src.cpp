#include <bits/stdc++.h>
using namespace std;

void primeFactorsMapBuild(map<long long, long long> &m, vector<long long> factors);


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

// numPF(N): Count the number of prime factors that the N has.
// Limitation: If there is a prime factor of N such that
//             p[i] * p[i] > N, then the algorithm does not work.
int numPF(long long N){
  int ans = 0;
  for(int i = 0; (i < (int)p.size()) && (p[i]*p[i] <= N); ++i){
    while(N % p[i] == 0){
      N /= p[i];
      ++ans;
    }

  }
  return ans + (N != 1);
}

// numDiv(N): Count the number of divisors that N has.
// Same limitation as above;
int numDiv(long long N){
  int ans = 1; // 1 is always a divisor.
  for(int i = 0; (i < (int)p.size()) && (p[i]*p[i] <= N); ++i){
    int power = 0;
    while(N % p[i] == 0){
      N /= p[i];
      power++;
    }

    ans *= power;
  }

  return ans;
}

long long fastPow(long long base, long long power){
  if( power == 0 )
    return 1;
  else if( power == 1 )
    return base;
  else if( power % 2 == 1 ){
    return base * fastPow(base, power-1);
  }
  long long tmp = fastPow(base, power/2);
  return tmp * tmp;
}

// sumDiv(N): Compute the sum of all divisors of N.
long long sumDiv(map<long long, long long> m){
  long long ans = 1, aux;
  for(auto &[key, value] : m){
    //printf("key: %lld\t value: %lld\n", key, value);
    aux = fastPow(key, value + 1) - 1;
    //printf("%lld/%lld\n", aux, (key-1));
    ans *= aux/(key - 1);
  }
  return ans;
}

long long sumDiv(long long N){
  vector<long long> factors = primeFactors(N);
  map<long long, long long> factors_map;
  primeFactorsMapBuild(factors_map, factors);
  return sumDiv(factors_map);
}

// EulerPhi totient functions: Counts the number os Coprimes o N.
// Such that for i in [1, N-1] gcd(N, i) = 1
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

// Count the number o Different prime factors of N.
long long numDiffPF(long long N){
  vector<long long> factors = primeFactors(N);
  map<long long, long long> factors_map;
  primeFactorsMapBuild(factors_map, factors);
  
  return factors_map.size();
}

// Compute the sum of all Prime Factors 
long long sumPF(long long N){
  vector<long long> factors = primeFactors(N);
  map<long long, long long> factors_map;
  primeFactorsMapBuild(factors_map, factors);

  long long ans = 0;
  for(auto &[key, value] : factors_map){
    ans += key;
  }

  return ans;
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

void printFactors(map<long long, long long> m){
  if( m.empty() ){
    printf("> No factors\n");
    return;
  }

  for(const auto& [key, value] : m){
    if(value == 1){
      printf("> %lld\n", key);
      
    }
    else{
      printf("> %lld^%lld\n", key, value);
    }
  }
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

  printf("---------------------------------------\n");

  vector<long long> factors;
  map<long long, long long> factors_map;

  printf("Factors of 2^31 - 1:\n");
  factors = primeFactors((1LL<<31)-1);
  primeFactorsMapBuild(factors_map, factors);
  printFactors(factors_map);

  printf("Factors of 136117223861:\n");
  factors = primeFactors(136117223861LL);
  primeFactorsMapBuild(factors_map, factors);
  printFactors(factors_map);

  printf("Factors of 5000000035:\n");
  factors = primeFactors(5000000035LL);
  primeFactorsMapBuild(factors_map, factors);
  printFactors(factors_map);
  
  printf("Factors of 142391208960:\n");
  factors = primeFactors(142391208960LL);
  primeFactorsMapBuild(factors_map, factors);
  printFactors(factors_map);

  printf("Factors of 100000380000361:\n");
  factors = primeFactors(100000380000361LL);
  primeFactorsMapBuild(factors_map, factors);
  printFactors(factors_map);

  // Testing function for sum of divisors of N.
  printf("---------------------------------------\n");
  printf("SUM OF DIVISORS\n");
  factors = primeFactors(60LL);
  primeFactorsMapBuild(factors_map, factors);
  printFactors(factors_map);
  printf("Sum of divisors of 60: %lld\n", sumDiv(factors_map));

  // Testing EulerPhiTotient Function.
  printf("---------------------------------------\n");
  printf("EulerPhiTotient(36): %lld\n", eulerPhi(36LL));

  // Testing function for numDiffPF(N)
  printf("---------------------------------------\n");
  for(int i = 0; i <= 15; ++i)
    printf("numDiffPF(%d): %lld\n", i, numDiffPF(i));

  // Testing sumPF(N) function. 
  printf("---------------------------------------\n");
  for(int i = 0; i <= 15; ++i)
    printf("sumPF(%d): %lld\n", i, sumPF(i));

  // Testing numPF(N), numDiffPF(N), sumPF(N), numDiv(N), sumDiv(N), eulerPhi(N)
  // for N prime.
  for(auto &prime : p){
    if(prime >= 20) break;
    printf("---------------------------------------\n");
    printf("numPF(%lld): %d\n", prime, numPF(prime));
    printf("numDiffPF(%lld): %lld\n", prime, numDiffPF(prime));
    printf("sumPF(%lld): %lld\n", prime, sumPF(prime));
    printf("numDiv(%lld): %d\n", prime, numDiv(prime));
    printf("sumDiv(%lld): %lld\n", prime, sumDiv(prime));
    printf("eulerPhi(%lld): %lld\n", prime, eulerPhi(prime));
  }


  return 0;
}
