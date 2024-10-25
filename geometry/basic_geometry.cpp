#include <bits/stdc++.h>
using namespace std;

// Change this based on the problem.
#define ftype float
#define eps 10e-5

struct Point2d{
  ftype x, y;
  Point2d(){}
  Point2d(ftype x, ftype y) : x(x), y(y) {}

  bool operator==(const Point2d &t) const{
    return abs(x - t.x) <= eps && abs(y - t.y) <= eps; 
  }
  
  Point2d& operator+=(const Point2d &t){
    x += t.x;
    y += t.y;
    return *this;
  }

  Point2d& operator-=(const Point2d &t){
    x -= t.x;
    y -= t.y;
    return *this;
  }


  Point2d& operator*=(ftype t){
    x *= t;
    y *= t;
    return *this;
  }

  Point2d& operator/=(ftype t){
    x /= t;
    y /= t;
    return *this;
  }

  Point2d operator+(const Point2d &t) const {
    return Point2d(*this) += t;
  }

  Point2d operator-(const Point2d &t) const {
    return Point2d(*this) -= t;
  }
  
  Point2d operator*(ftype t) const {
    return Point2d(*this) *= t;
  }

  Point2d operator/(ftype t) const {
    return Point2d(*this) /= t;
  }
};


/* Function declarations. */

ftype dot_point2d(Point2d a, Point2d b);
ftype norm(Point2d a);
Point2d proj(Point2d a, Point2d b);

/* Function definitions. */

ftype dot_point2d(Point2d a, Point2d b){
  return a.x * b.x + a.y * b.y;
}

ftype norm(Point2d a){
  return (ftype) sqrt(dot_point2d(a, a));
}

/*
 * Projection of a into b.
 * Inputs:
 *          a: vector that need to be projected.
 *          b: projection line.
 * Outputs: 
 *          Point2d that is in line b, but is projection
 *          of a.
 */
Point2d proj(Point2d a, Point2d b){
  ftype b_norm = norm(b), a_norm = norm(a);
  if( b_norm == 0 || a_norm == 0 ){
    // B is a point or A is a point.
    return Point2d(0, 0);
  }
  ftype scalar = dot_point2d(a, b) / b_norm;
  return (b / b_norm) * scalar;
}

/* Testing functions */

void test_proj(){
  cout << "Testando a função proj" << endl;
  // Test 1: Projeção em vetores sem características especiais.
  Point2d a(3, 4); 
  Point2d b(1, 0);
  Point2d result = proj(a, b);
  Point2d expected(3, 0);
  assert(expected == result);
  cout << "Teste 1 passou" << endl;

  // Test 2: Projeção de um vetor sobre si mesmo.
  a = Point2d(3, 7);
  result = proj(a, a);
  expected = Point2d(3, 7);
  assert(result == expected);
  cout << "Teste 2 passou" << endl;

  // Test 3: Projeção vetores perpendiculares.
  a = Point2d(1, -1);
  b = Point2d(-1, 1);
  result = proj(a, b);

  cout << result.x << ' ' << result.y << endl;
  expected = Point2d(0, 0);
  assert(result == expected);
  cout << "Teste 3 passou" << endl;
   
  // Test 4: Projeção de um vetor, sobre um ponto.
  a = Point2d(-3, 7);
  b = Point2d(0, 0);
  expected = Point2d(0, 0);
  result = proj(a, b);
  assert(expected == result);
  result = proj(b, a);
  assert(expected == result);
  cout << "Teste 4 passou" << endl;
  
}

int main(){
  test_proj(); 
}
