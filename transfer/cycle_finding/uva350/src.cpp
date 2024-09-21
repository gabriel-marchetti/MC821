#include <bits/stdc++.h>
using namespace std;

struct Params{
  int Z, I, M;
};

int linearCongruence(Params params, int L){
  return (params.Z * L + params.I) % params.M;
}

void hare_nd_turtle(Params params, int L, int &mu, int &lambda){
  mu = -1, lambda = -1;
  int hare = L, turtle = L, i_hare = 0, i_turtle = 0;
  do{
    hare = linearCongruence(params, hare);
    hare = linearCongruence(params, hare);
    i_hare += 2;
    turtle = linearCongruence(params, turtle);
    i_turtle += 1;
  } while( hare != turtle );

  hare = L; i_hare = 0;
  while( hare != turtle ){
    hare = linearCongruence(params, hare); i_hare++;
    turtle = linearCongruence(params, turtle); i_turtle++;
  }
  mu = i_turtle - i_hare;

  i_turtle = i_hare + 1;
  turtle = linearCongruence(params, hare);
  while( hare != turtle ){
    turtle = linearCongruence(params, turtle);
    i_turtle++;
  }
  lambda = i_turtle - i_hare; 
}

int main(){
  int Z, I, M, L, print_case = 1;
  Params params;

  int mu, lambda;
  while( scanf("%d %d %d %d", &Z, &I, &M, &L) ){
    if(Z == 0 && I == 0 && M == 0 && L == 0){
      break;
    }
    params.I = I; params.Z = Z; params.M = M;
    hare_nd_turtle(params, L, mu, lambda); 
    printf("Case %d: %d\n", print_case, lambda);

    print_case++;
  }

  return 0;
}
