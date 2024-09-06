#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;


long long _sieve_size;
bitset<MAX+10> bs; // 10^7 is the rough limit for the sieve
vector<long long> p; // compact list of primes

void sieve(long long upperbound = MAX + 2){
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

int numDiv(long long N){
  int ans = 1; // 1 is always a divisor.
  for(int i = 0; (i < (int)p.size()) && (p[i]*p[i] <= N); ++i){
    int power = 0;
    while(N % p[i] == 0){
      N /= p[i];
      power++;
    }

    //cout << "power: " << power << '\n';
    ans *= (power+1);
  }
  if(N != 1)
    ans *= 2;

  return ans;
}

int main(){
  long long n, x;
  sieve();
  cin >> n;
  while(n--){
    cin >> x;
    if( bs[x] == 1 )
      printf("2\n");
    else
      printf("%d\n", numDiv(x));    
  }

  return 0;
}
