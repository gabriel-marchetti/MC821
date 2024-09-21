#include <bits/stdc++.h>
using namespace std;

int compute_next(int number){
  int aux = 0, rem = 0;
  while(number){
    rem = number % 10;  
    aux += rem * rem;
    number /= 10;
  }

  return aux;
}

bool converge(int number){
  int hare, turtle;
  hare = number; turtle = number;

  do{
    hare = compute_next(compute_next(hare));
    turtle = compute_next(turtle);
    if(hare == 1 || turtle == 1){
      return true;
    }
  } while( hare != turtle );

  return false;
}

int main(){
  int print_case = 1, test_cases, number;
  cin >> test_cases;
  while(test_cases--){
    cin >> number;
    if( converge(number) ){
      printf("Case #%d: %d is a Happy number.\n", print_case, number);
    }
    else{
      printf("Case #%d: %d is an Unhappy number.\n", print_case, number);
    }
    print_case++;
  }

  return 0;
}
