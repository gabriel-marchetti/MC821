#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b){
  if(b == 0) return a;
  return gcd(b, a % b);
}

long long lcm(long long a, long long b, long long k){
  return (a % k) * (b % k) / gcd(a, b);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  long long k, tmp;
  cin >> n >> k;
  
  long long current_lcm = 1;
  for(int i = 0; i < n; i++){
    cin >> tmp;
    current_lcm = lcm(current_lcm, tmp, k) % k;
  }

  if(current_lcm == 0){
    cout << "Yes\n";
  }
  else{
    cout << "No\n";
  }

  return 0;
}
