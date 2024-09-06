#include <bits/stdc++.h> 
using namespace std;

void solve(long long a, long long b, long long &x, long long &y){
  //printf("%lld %lld\n", a, b);
  if(b == 0){
    x = 1;
    y = 0;
    return;
  }

  long long x1, y1;
  solve(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
}

long long gcd(long long a, long long b){
  if( b == 0 )
    return a;
  else
    return gcd(b, a % b);
}

int main(){
  long long a, b, c, x, y;
  scanf("%lld %lld %lld", &a, &b, &c);

  long long gcd_ab = gcd(abs(a), abs(b));
  //printf("gcd_ab: %lld\n", gcd_ab);
  if( abs(c) % gcd_ab == 0 ){
    solve(abs(a), abs(b), x, y);
    //printf("x: %lld\t y: %lld\n", x, y);
    x *= (abs(c) / gcd_ab);
    y *= (abs(c) / gcd_ab);
    if( a < 0 ) x *= -1;
    if( b < 0 ) y *= -1;
    if( c > 0 ){
      x *= -1;
      y *= -1;
    }

    printf("%lld %lld\n", x, y);
  }
  else{
    printf("-1\n");
  }
  
}
