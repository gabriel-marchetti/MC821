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

  // Memory related operators.
  int operator[](int index)const;
  BigInt &operator=(const BigInt &);

  // Comparison operators.
  friend bool operator==(const BigInt &, const BigInt &);
  friend bool operator!=(const BigInt &, const BigInt &);
  friend bool operator<(const BigInt &, const BigInt &);
  friend bool operator>(const BigInt &, const BigInt &);
  friend bool operator<=(const BigInt &, const BigInt &);
  friend bool operator>=(const BigInt &, const BigInt &);

  // Arithmetic Operators
  BigInt &operator++();
  BigInt operator++(int temp);
  BigInt &operator--();
  BigInt operator--(int temp);

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

// Operators definition.

// Memory related operators definition.
int BigInt::operator[](const int index)const{
  if(digits.size() <= index || index < 0)
    throw("Error: cannot access invalid position");
  return digits[index];
}

BigInt &BigInt::operator=(const BigInt &a){
  digits = a.digits;
  signBit = a.signBit;
  return *this;
}

// Comparison operators definition.
bool operator==(const BigInt &a, const BigInt &b){
  return a.digits == b.digits && a.signBit == b.signBit;
}

bool operator!=(const BigInt &a, const BigInt &b){
  return !(a==b);
}

bool operator<(const BigInt &a, const BigInt &b){
  if( a.signBit != b.signBit )
    return a.signBit < b.signBit;
  int size_a = a.digits.size(); int size_b = b.digits.size();

  if(size_a != size_b)
    return size_a < size_b;

  // Since both have same size;
  int n = size_a; 
  // Setting index for [] in string
  n--;
  while(n >= 0){
    if( a.digits[n] != b.digits[n] ){
      return a.digits[n] < b.digits[n];
    }
    n--;
  }

  // They're equal
  return false;
}

bool operator>(const BigInt &a, const BigInt &b){
  return b < a;
}

bool operator<=(const BigInt &a, const BigInt &b){
  return !(a > b);
}

bool operator>=(const BigInt &a, const BigInt &b){
  return !(a < b);
}

// Defining the Arithmetic Operators.



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
 * [x] operator!= implemented. Since operator== is working, i will 
 *     not test this one.
 *
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
  BigInt i5("5335");
  cout << "i1: " << i1 << '\n';
  cout << "i2: " << i2 << '\n';
  cout << "i3: " << i3 << '\n';
  cout << "i4: " << i4 << '\n';
  cout << "i5: " << i5 << '\n';
  
  bool comparing;
  comparing = (i1 == i2);
  cout << "Compare i1 and i2: " << comparing << '\n';
  comparing = (i1 == i3);
  cout << "Compare i1 and i3: " << comparing << '\n';
  comparing = (i1 == i4);
  cout << "Compare i1 and i4: " << comparing << '\n' << '\n';

  // This should output --> false, false, false, true.
  comparing = (i1 < i2);
  cout << "i1 < i2: " << comparing << '\n';
  comparing = (i1 < i3);
  cout << "i1 < i3: " << comparing << '\n';
  comparing = (i1 < i4);
  cout << "i1 < i4: " << comparing << '\n';
  comparing = (i1 < i5);
  cout << "i1 < i5: " << comparing << '\n' << '\n';

  cout << "====================================================\n";

  return 0;
}
