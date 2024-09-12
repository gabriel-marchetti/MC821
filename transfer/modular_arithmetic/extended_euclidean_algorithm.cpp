#include <bits/stdc++.h>

/////////////////////////////////////////////
// we need to find x and y such that       //
// a * x + b * y = gcd(a, b)               //
// This function returns the gcd, x and y. //
// //////////////////////////////////////////
int gcd(int a, int b, int &x, int &y){
  if( b == 0 ){
    x = 1;
    y = 0;
    return a;
  }

  int x1, y1;
  int d = gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}

int main(){
  int a, b, x, y, g;
  a = 0; b = 40;
  g = gcd(a, b, x, y);
  printf("%d * %d + %d * %d = %d\n", a, x, b, y, g);

  g = gcd(b, a, y, x);
  printf("%d * %d + %d * %d = %d\n", a, x, b, y, g);

  
  return 0;
}
