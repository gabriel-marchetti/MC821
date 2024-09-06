#include <bits/stdc++.h>
using namespace std;

void increment(bitset<21> &bs){
  int i = 0;
  while(bs[i] == 1){
    bs[i] = 0;
    i++;
  }

  if( i <= 20 )
    bs[i] = 1;
}

int main(){
  long long n, k, tmp;
  cin >> n >> k;

  vector<long long> primes;
  for(int i{0}; i < k; ++i){
    cin >> tmp;
    primes.push_back(tmp);
  }


  long long aux, total = 0;
  bitset<21> bs;
  bs.reset();
  increment(bs);

  while( bs.count() <= k ){
    if(bs[k] == 1) break;

    //cout << bs << '\n';
    aux = 1;
    double aux_d = 1;
    for(int i{0}; i < k; i++){
      if(bs[i] == 1){
        aux *= primes[i];
        aux_d *= primes[i];
      } 
    }
      if(aux_d > 1e18){
      increment(bs);
      continue;
    }

    if(bs.count() & 1){
      //printf("caso1: %llu\n", aux);
      total += n / aux; 
    }
    else{
      //printf("caso2: %llu\n", aux);
      total -= n / aux;
    }
    
    increment(bs);
  }

  cout << total << '\n';


  return 0;
}
