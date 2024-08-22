/*
 * This code was extracted from geeksforgeeks.org!
 */
#include <bits/stdc++.h>

using namespace std;

class BigInt{
public:
  string digits;
  /*
  * Constructors.
  */
  BigInt(unsigned long long n = 0);
  BigInt(string &);
  BigInt(const char *);
  BigInt(BigInt &);

  /*
  * Helper Functions.
  */
  friend void divide_by_2(BigInt &a);
  friend bool Null(const BigInt &);
  friend int Length(const BigInt &);
  int operator[](const int)const;

  BigInt &operator=(const BigInt &);
  BigInt operator++(int tmp);
  BigInt &operator--();
  BigInt operator--(int tmp); 

  // Defining Adition:
  friend BigInt &operator+=(BigInt &, const BigInt &);
  friend BigInt operator+(const BigInt &, const BigInt &);

  // Defining Subtraction:
  friend BigInt operator-(const BigInt &, const BigInt &);
  friend BigInt &operator-=(BigInt &, const BigInt &);

  // Comparison:
  friend bool operator==(const BigInt &, const BigInt &);
  friend bool operator!=(const BigInt &, const BigInt &);
  friend bool operator>(const BigInt &, const BigInt &);
  friend bool operator>=(const BigInt &, const BigInt &);
  friend bool operator<(const BigInt &, const BigInt &);
  friend bool operator<=(const BigInt &, const BigInt &);

  // Multiplication:
  friend BigInt &operator*=(BigInt &, const BigInt &);
  friend BigInt operator*(const BigInt &, const BigInt &);

  // Division:
  friend BigInt &operator/=(BigInt &, const BigInt &);
  friend BigInt operator/(const BigInt &, const BigInt &);

  // Modulo:
  friend BigInt &operator%=(BigInt &, const BigInt &);
  friend BigInt operator%(const BigInt &, const BigInt &);

  // PowerFunction:
  friend BigInt &operator^=(BigInt &, const BigInt &);
  friend BigInt operator^(const BigInt &, const BigInt &);

  // SquareRoot:
  friend BigInt sqrt(BigInt &);

  // Read and Write.
  friend ostream &operator<<(ostream &, const BigInt &);
  friend istream &operator>>(istream &, BigInt &);
};

//============DEFINING THE CONSTRUCTOR============//

BigInt::BigInt(string &s){
  digits = "";
  int n = s.size();
  for(int i{n-1}; i >= 0; --i){
    if(!isdigit(s[i]))
      throw("ERROR");
    digits.push_back(s[i] - '0');
  }
}

BigInt::BigInt(unsigned long long number){
  do{
    digits.push_back(number % 10);
    number /= 10;
  } while(number);
}

BigInt::BigInt(const char *s){
  digits = "";
  for(int i = strlen(s)-1; i >= 0; --i){
    if( !isdigit(s[i]) )
      throw("ERROR");
    digits.push_back( s[i] - '0' );
  }
}

BigInt::BigInt(BigInt &a){
  digits = a.digits;
}
//==========================================//


bool Null(const BigInt &a){
  if(a.digits.size() == 1 && a.digits[0] == 0)
    return true;
  return false;
}
