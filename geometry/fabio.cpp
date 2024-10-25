#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-9
#define PI acos(-1.0)

double DEG_to_RAD(double d){
  return d * PI / 180.0;
}

struct point{
  double x, y;
  point() { x = y = 0.0; }
  point(double _x, double _y) : x(_x), y(_y) {}
  bool operator <(point other) const{
    if( fabs(x - other.x) > EPS ){
      return x < other.x;
    }
    else if( fabs(y - other.y) > EPS ){
      return y < other.y;
    }
    return 0;     // They are equal.
  }

  bool operator ==(point other) const{
    return ( fabs(x - other.x) < EPS ) && ( fabs(y - other.y) <EPS );
  }
};

struct line{
  double a, b, c; // represent a line with a*x + b*y + c = 0
  bool isVertical(){
    if( fabs(b) > EPS ){
      return false;
    }
    return true;
  }

  bool isHorizontal(){
    if( fabs(a) > EPS ){
      return false;
    }
    return true;
  }

  bool intersectOrigin(){
    if( fabs(c) > EPS ){
      return false;
    }
    return true;
  }
};

double dist_point_to_point(point p1, point p2){
  return hypot(p1.x - p2.x, p1.y - p2.y);
}

point rotate_by(point p, double theta){
  // theta is DEG
  double rad = DEG_to_RAD(theta);
  return point(
    cos(rad) * p.x - sin(rad) * p.y,
    sin(rad) * p.x + cos(rad) * p.y 
  );
}

line points_to_line(point p1, point p2){
  line l;
  if( fabs(p1.x - p2.x) < EPS ){
    // Case when x1 == x2, then l should be vertical
    l.a = 1.0; l.b = 0.0; l.c = -p1.x;
  }
  else{
    l.a = (double) (p1.y - p2.y) / (p1.x - p2.x);
    l.b = 1.0;
    l.c = (double) (l.a * p1.x) - p1.y;
  }

  return l;
}

/*
 *: Here we are considering that parallel lines are normalized, i.e.,
 *: | (l1.a, l1.b) | == 1
 *: | (l2.a, l2.b) | == 1
 */
bool are_parallel(line l1, line l2){
  return ( (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS) );
}

bool are_same(line l1, line l2){
  return are_parallel(l1, l2) && ( fabs(l1.c - l2.c) < EPS );
}

int main(){

  return 0;
}
