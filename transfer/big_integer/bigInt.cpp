#include<bits/stdc++.h>

#define PLUS 1
#define MINUS -1

using namespace std;
class BigInt{
public:
  string digits;
  int signBit; 

  // Declaring the constructors:
  BigInt(long long n = 0);
  BigInt(string &);
  BigInt(const char *);
  BigInt(BigInt &);

  // Declaring functional functions;
  friend bool Null(const BigInt &);
  friend int Length(const BigInt &);

  int operator[](int index)const;
  friend bool operator==(const BigInt &, const BigInt &);
  

  // Read and Write
  friend ostream &operator<<(ostream &, const BigInt &);
  friend istream &operator>>(istream &, const BigInt &);
};
//=========================================================================//
//====================Defining The Constructors===========================//

BigInt::BigInt(string &s){
  digits = "";
  if(s[0] == '-') signBit = MINUS;
  else signBit = PLUS;

  int n = s.size();
  // Note that if we have a negative number, them
  // we do not include the '-' in reading.
  int finish = (signBit < 0) ? 1 : 0;
  for(int i{n-1}; i >= finish; --i){
    if( !isdigit(s[i]) )
      throw("Error: Invalid value from string");
    digits.push_back(s[i] - '0');
  }
}

BigInt::BigInt(long long n){
  if( n < 0 ) signBit = MINUS;
  else signBit = PLUS;

  digits.clear();
  // converting for absolute value;
  n = n * signBit;
  
  do{
    digits.push_back(n%10);
    n/=10;
  }while(n);
}

BigInt::BigInt(const char *s){
  digits = "";
  if( s[0] == '-' ) signBit = MINUS;
  else signBit = PLUS;

  int finish = (signBit < 0) ? 1 : 0;
  for(int i{(int)strlen(s)-1}; i >= finish; --i){
    if(!isdigit(s[i])){
      throw("Error: Could not handle this string for constructing.");
    }
    digits.push_back(s[i] - '0');
  }
}

BigInt::BigInt(BigInt &a){
  digits = a.digits;
  signBit = a.signBit;
}

//=========================================================================//
//=========================================================================//

bool Null(const BigInt &a){
  if(a.digits.size() == 1 && a.digits[0] == 0)
    return true;
  return false;
}

int Length(const BigInt &a){
  return a.digits.size();
}

int BigInt::operator[](const int index)const{
  if(digits.size() <= index || index < 0)
    throw("Error: cannot access invalid position");
  return digits[index];
}

bool operator==(const BigInt &a, const BigInt &b){
  return a.digits == b.digits && a.signBit == b.signBit;
}

//=========================================================================//
//======================Defining Read and Write============================//

istream &operator>>(istream &in, BigInt &a){
  string s;
  in >> s;
  int n = s.size();

  if(s[0] == '-') a.signBit = MINUS;
  else a.signBit = PLUS;
  a.digits.clear();

  while(!s.empty()){
    if(*(s.end()--) == '-')
      continue;
    if( !isdigit(*(s.end()--)) )
      throw("Problem at >> operator of BigInt.");
    a.digits.push_back(*(s.end()--));
    s.pop_back();
  }  

  return in;
}

ostream &operator<<(ostream &out, const BigInt &a){
  if(a.signBit < 0) cout << '-';
  
  int n = a.digits.size();
  for(int i={n-1}; i >= 0; --i){
    cout << (short)a.digits[i];
  }

  return cout;
}

//=========================================================================//
//=========================================================================//

/*
 * [x] Constructor BigInt::BigInt(string &s) seems to be working
 *     for negative and positive numbers;
 * [x] Constructor BigInt::BigInt(long long n) seems to be working
 *     for negative and positive numbers;
 * [x] Constructor BigInt::BigInt(const char *s) seems to be working
 *     for negative and positive numbers;
 * [x] Null and Size functions seems to be working.
 * [x] operator[] worked.
 * [x] operator== seems to be working.
 */
int main(){
  cout << "====================================================\n";


  string str("-12345");
  BigInt str_constructor(str);
  cout << "str_constructor: " << str_constructor << '\n';

  long long num = -12345;
  BigInt longlong_constructor(num);
  cout << "longlong_constructor: " << longlong_constructor << '\n';

  BigInt charStr_constructor("-12345");
  cout << "charStr_constructor: " << charStr_constructor << '\n' << '\n';

  BigInt testing_null("0");
  // Testing Length function:
  cout << "Size of charStr_constructor:" << Length(charStr_constructor) << '\n';
  cout << "Size of testing_null: " << Length(testing_null) << '\n' << '\n';
  // Testing Null function:
  cout << "Null of charStr_constructor: " << Null(charStr_constructor) << '\n';
  cout << "Null of testing_null: " << Null(testing_null) << '\n' << '\n';

  // Testing the operator[];
  cout << "longlong_constructor[0]: " << longlong_constructor[0] << '\n' << '\n'; // This should return 5;

  BigInt i1("5334");
  BigInt i2("5334");
  BigInt i3("-5334");
  BigInt i4("10");
  
  bool comparing;
  comparing = (i1 == i2);
  cout << "Compare i1 and i2: " << comparing << '\n';
  comparing = (i1 == i3);
  cout << "Compare i1 and i3: " << comparing << '\n';
  comparing = (i1 == i4);
  cout << "Compare i1 and i4: " << comparing << '\n';

  cout << "====================================================\n";

  return 0;
}
