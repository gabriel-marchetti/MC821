#include <bits/stdc++.h>
using namespace std;

struct Fract{
  int numerator, denominator;
};

int mdc(int a, int b){
  if(b == 0)
    return a;
  return mdc(b, a % b);
}

int mmc(int a, int b){
  return a * (b / mdc(a,b));
}

void printFract(Fract a){
  printf("%d/%d\n", a.numerator, a.denominator);
}

int main(){
  string cylinder;

  while( cin >> cylinder ){
    // Case A: case where you ROTATE the cylinder
    // Case B: case where you SHOOT.
    Fract caseA, caseB;
    caseA.numerator = 0; caseA.denominator = cylinder.length();
    caseB.numerator = 0; caseB.denominator = 0;

    printf("%lu\n", cylinder.length());
    // Does not check final Character of String.
    for(int i{0}; i < cylinder.length() - 1; i++){
      if(cylinder[i] == '0'){
        caseA.numerator++;
        
        if(cylinder[i+1] == '0'){
          caseB.numerator++;
          caseB.denominator++;
        }
        else{
          caseB.denominator++;
        }
      }
    }
    // Checking final Character
    int cyl_length = cylinder.length();
    if(cylinder[cyl_length-1] == '0' && cylinder[0] == '0')
      caseB.numerator++;
    if(cylinder[cyl_length-1] == '0')
      caseB.denominator++;
    
    int MDC = mdc(caseA.denominator, caseB.denominator);
    int multiplyA, multiplyB;
    multiplyA = MDC / caseA.denominator;
    multiplyB = MDC / caseB.denominator;
    caseA.numerator *= multiplyA; caseA.denominator = MDC;
    caseB.numerator *= multiplyB; caseB.denominator = MDC;
  
    if(caseA.numerator == caseB.numerator){
      printf("EQUAL\n");
    }
    else if(caseA.numerator > caseB.numerator){
      printf("ROTATE\n");
    }
    else{
      printf("SHOOT\n");
    }
    
  }

  return 0;
}
