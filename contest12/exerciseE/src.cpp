#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-9

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

line points_to_line(point p1, point p2){
  line l;
  if( fabs(p1.x - p2.x) < EPS ){
    // Case when x1 == x2, then l should be vertical
    l.a = 1.0; l.b = 0.0; l.c = -p1.x;
  }
  else{
    l.a = -(double) (p1.y - p2.y) / (p1.x - p2.x);
    l.b = 1.0;
    l.c = -(double) (l.a * p1.x) - p1.y;
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

bool compute_intersection(line l1, line l2, point &p){
  if( are_parallel(l1, l2) ){
    return false;
  }
  p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);

  if( fabs(l1.b) > EPS ){
    p.y = -(l1.a * p.x + l1.c);
  }
  else{
    p.y = -(l2.a * p.x + l2.c);
  }
  return true;
}

struct vec{
  double x, y;
  vec(double _x, double _y) : x(_x), y(_y){}
};

vec points_to_vec(point p1, point p2){
  return vec(p1.x - p2.x, p1.y - p2.y);
}

double dot(vec a, vec b){
  return a.x * b.x + a.y * b.y;
}

int main(){
  int N;
  point p1, p2, p3;
  line l;
  int x, y;
  cin >> N;
  while(N--){
    cin >> x >> y;
    p1.x = x; p1.y = y;
    cin >> x >> y;
    p2.x = x; p2.y = y;
    cin >> x >> y;
    p3.x = x; p3.y = y;

    // Checking through dot-product.
    vec v1 = points_to_vec(p1, p2),
        v2 = points_to_vec(p1, p3);

    double cross_product = v1.x * v2.y - v1.y * v2.x;
    if( fabs(cross_product) < EPS ){
      cout << "TOUCH" << endl;  
    }
    else if( cross_product > 0 ){
      cout << "LEFT" << endl;
    }
    else{
      cout << "RIGHT" << endl;
    }
  }

  return 0;
}

