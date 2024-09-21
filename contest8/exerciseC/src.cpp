#include <bits/stdc++.h>
using namespace std;

struct Params{
  long long N, a, b;
};

int linearCongruence(int number, Params params){
  return ( params.a * number * number + params.b ) % params.N;
}

void hare_nd_turtle(long long &mu, long long &lambda, Params params){
  long long hare = 0, turtle = 0, i_hare = 0, i_turtle = 0;

/*   printf("First step:\n"); */
  do{
    hare = linearCongruence(linearCongruence(hare, params), params);
    turtle = linearCongruence(turtle, params);
    i_hare += 2;
    i_turtle += 1;
    /* printf("turtle: %lld\thare: %lld\n", turtle, hare);
    printf("i_turtle: %lld\ti_hare: %lld\n", i_turtle, i_hare); */
  } while( hare != turtle );
  
  hare = 0; i_hare = 0;
/*   printf("Second step:\n"); */
  while( hare != turtle ){
    turtle = linearCongruence(turtle, params); i_turtle++;
    hare = linearCongruence(hare, params); i_hare++;
    /* printf("turtle: %lld\thare: %lld\n", turtle, hare);
    printf("i_turtle: %lld\ti_hare: %lld\n", i_turtle, i_hare); */
  }
  mu = i_hare;
/*   printf("Compute mu\n"); */
  
  turtle = linearCongruence(hare, params);
  i_turtle = i_hare + 1;
  
/*   printf("Third step:\n"); */
  while(hare != turtle){
    turtle = linearCongruence(turtle, params);
    i_turtle++;
    /* printf("turtle: %lld\thare: %lld\n", turtle, hare);
    printf("i_turtle: %lld\ti_hare: %lld\n", i_turtle, i_hare); */
  }
  lambda = i_turtle - i_hare;
/*   printf("Compute lambda\n"); */
}

int main(){
  long long N, a, b, mu, lambda, num_dies = 0;
  Params params;
  while( scanf("%lld %lld %lld", &N, &a, &b) == 3 ){
    params.N = N; params.a = a; params.b = b;
    hare_nd_turtle(mu, lambda, params);
    num_dies = mu + lambda - 1;
    //printf("lamda: %lld\tmu: %lld\n", lambda, mu);
    printf("%lld\n", N - num_dies);
  }

  return 0;
}
