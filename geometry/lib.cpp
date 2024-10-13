#include <bits/stdc++.h>
using namespace std;

/* Here we will make both point2d and point3d with long long datatype
 * But you might need to change in the context you are using it.
 * */

/* HERE WE ARE DEFINING POINT2D */

struct point2d{
  long long x, y;
  point2d() {}
  point2d(long long x, long long y): x(x), y(y) {}
  point2d& operator+=(const point2d &t){
    x += t.x;
    y += t.y;
    return *this;
  }

  point2d& operator -=(const point2d &t){
    x -= t.x;
    y -= t.y;
    return *this;
  }

  point2d& operator *=(const point2d &t){
    x *= t.x;
    y *= t.y;
    return *this;
  }
  
  point2d& operator /=(const point2d &t){
    x /= t.x;
    y /= t.y;
    return *this;
  }

  point2d operator+(const point2d &t) const{
    return point2d(*this) += t;
  }
  
  point2d operator-(const point2d &t) const{
    return point2d(*this) -= t;
  }

  point2d operator*(const point2d &t) const{
    return point2d(*this) *= t;
  }

  point2d operator/(const point2d &t) const{
    return point2d(*this) /= t;
  }
};

/* HERE WE ARE DEFINING POINT3D */

struct point3d{
  long long x, y, z;
  point3d() {}
  point3d(long long x, long long y, long long z): x(x), y(y), z(z) {}
  point3d& operator+=(const point3d &t){
    x += t.x;
    y += t.y;
    z += t.z;
    return *this;
  }

  point3d& operator -=(const point3d &t){
    x -= t.x;
    y -= t.y;
    z -= t.z;
    return *this;
  }

  point3d& operator *=(const point3d &t){
    x *= t.x;
    y *= t.y;
    z *= t.z;
    return *this;
  }
  
  point3d& operator /=(const point3d &t){
    x /= t.x;
    y /= t.y;
    z /= t.z;
    return *this;
  }

  point3d operator+(const point3d &t) const{
    return point3d(*this) += t;
  }
  
  point3d operator-(const point3d &t) const{
    return point3d(*this) -= t;
  }

  point3d operator*(const point3d &t) const{
    return point3d(*this) *= t;
  }

  point3d operator/(const point3d &t) const{
    return point3d(*this) /= t;
  }
};

// Defining the dot-product for 2-dimensional vectors
long long dot2d(point2d a, point2d b){
  return a.x * b.x + a.y * b.y;
}

// Defining the dot-product for 3-dimensional vectors
long long dot3d(point3d a, point3d b){
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

// Defining some basic operations for 2-dimensional vectors
long long square_norm2d(point2d a){
  return dot2d(a, a);
}

long long abs2d(point2d a){
  return sqrt(square_norm2d(a));
}

// projection of a into b
long long projection2d(point2d a, point2d b){

}

int main(){

  return 0;
}
