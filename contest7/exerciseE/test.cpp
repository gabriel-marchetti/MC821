#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
  if(b == 0){
    return a;
  }

  return gcd(b, a % b);
}

int main(){
  int max_n;
  cin >> max_n;

  int max_a = -1, max_b = -1, max_gcd = -1; 
  for(int i = 1; i <= max_n; i++){
    for(int j = 1; j <= max_n; j++){
      if( i == j ) continue;
      if( gcd(i, j) > gcd(max_a, max_b) ){
        max_gcd = gcd(i, j);
        max_a = i;
        max_b = j;
      }
    }
  }

  printf("gcd(%d, %d) = %d\n", max_a, max_b, max_gcd);

  return 0;
}
