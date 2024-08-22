#include <bits/stdc++.h>
using namespace std;

#define PLUS 1
#define MINUS -1

struct BigNum{
  string digits;
  int signBit;
  int lastDigit;
};

void longlong_to_bignum(long long num, BigNum *bigNum){
  if(num >= 0) bigNum->signBit = PLUS;
  else bigNum->signBit = MINUS;

  // Garantir que estamos recebendo uma string vazia.
  bigNum->lastDigit = 0;
  bigNum->digits.clear();
  long long tmp = (num >= 0) ? num : -num;

  do{
    bigNum->digits.push_back((char)num%10);
    num/=10;
    bigNum->lastDigit++;
  }while(num);
  // Vou fazer esse decremento para esse ser o índice
  // do último elemento.
  bigNum->lastDigit--;
}

int compare_bigNum(BigNum *a, BigNum *b){
  // Return:
  // 0 ------ se a e b são iguais
  // 1 ------ se a maior que b
  // -1 ----- se b maior que a
  if((a->signBit == MINUS) && (b->signBit == PLUS))
    return -1;
  if((a->signBit == PLUS) && (b->signBit == MINUS))
    return 1;
  
  // + + / + - / - + / - - //
  if(a->lastDigit > b->lastDigit) return a->signBit;
  if(b->lastDigit > a->lastDigit) return b->signBit;

  for(int i{a->lastDigit}; i >= 0; --i){
    if(a->digits[i] != b->digits[i])
      return ( a->digits[i] > b->digits[i] ) ? 1 : -1;
  }

  return 0;
}

void digit_shift(BigNum *n, int d){
  if( n->digits.empty() ) return;
  if( (n->lastDigit == 0) && (n->digits[0] == 0) ) return;

  n->digits.reserve();
  for(int i{0}; i < d; ++i){
    n->digits.push_back(0);
    n->lastDigit++;
  }
  n->digits.reserve();
}

void zero_justify(BigNum *n){
  while( (n->lastDigit > 0) && (n->digits[n->lastDigit] == 0) )
    n->lastDigit--;
  if((n->lastDigit == 0) && (n->digits[0] == 0))
    n->signBit = PLUS;
}

void subtract_bignum(BigNum *a, BigNum *b, BigNum *c);
void add_bignum(BigNum *a, BigNum *b, BigNum *c){
  int carry;
  c->signBit = PLUS;
  c->digits.clear();
  c->lastDigit = -1;
  
  if( a->signBit == b->signBit ) c->signBit = a->signBit;
  else{
    if(a->signBit == MINUS){
      a->signBit = PLUS;
      subtract_bignum(b, a, c);
      a->signBit = MINUS;
    }    
    else{
      b->signBit = PLUS;
      subtract_bignum(a, b, c);
      b->signBit = MINUS;
    }
    return;
  }
  int size = max(a->digits.size(), b->digits.size()); 
  c->digits.resize(size);
  c->lastDigit = size - 1;
  carry = 0;
  for(int i{0}; i <= c->lastDigit; ++i){
    c->digits[i] = (char) (carry+a->digits[i]+b->digits[i]) % 10;
    carry = (carry + a->digits[i] + b->digits[i]) / 10;
  }
  zero_justify(c);
}

void subtract_bignum(BigNum *a, BigNum *b, BigNum *c){
  int borrow;
  int v;
  c->digits.clear();
  c->lastDigit = c->digits.size() - 1;
  c->signBit = PLUS;

  if((a->signBit == MINUS) || (b->signBit == MINUS)){
    b->signBit = MINUS * b->signBit;
    add_bignum(a, b, c);
    b->signBit = MINUS * b->signBit;
    return;
  }

  if(compare_bigNum(a, b) == -1){
    subtract_bignum(b, a, c);
    c->signBit = MINUS;
    return;
  }
  
  c->lastDigit = max(a->lastDigit, b->lastDigit);
  borrow = 0;
  for(int i{0}; i <= c->lastDigit; ++i){
    v = (a->digits[i] - borrow - b->digits[i]);
    if(a->digits[i] > 0) borrow = 0;
    if(v < 0){
      v += 10;
      borrow = 1;
    }
    c->digits[i] = (char) v;
  }
  zero_justify(c);
}

int main(){
  long long n1 = 10;
  long long n2 = 20;

}
