#include <bits/stdc++.h>
using namespace std;

int main(){
  int num_cards, power_of_two, diff;
  while( scanf("%d", &num_cards) ){
    if(num_cards == 0){
      break;
    }
    if(num_cards == 1){
      printf("1\n");
      continue;
    }

    power_of_two = 1;
    while(power_of_two < num_cards){
      power_of_two *= 2;
    }
    power_of_two /= 2;
    diff = num_cards - power_of_two;

    printf("%d\n", 2 * diff);
  }

  return 0;
}
