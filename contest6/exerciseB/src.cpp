#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

long long lcm(long long a, long long b)
{
    return (a / gcd(a, b)) * b;
}

int main(){
  int T;
  cin >> T;
  long long a, n, b, m, K;
  while(T--){
    cin >> a >> n >> b >> m;
    K = lcm(n, m);

  }

  return 0;
}
