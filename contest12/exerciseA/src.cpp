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

int main(){
  int N;
  point p1, p2, p3, p4;
  line l1, l2;
  int x, y;
  cin >> N;

  cout << "INTERSECTING LINES OUTPUT" << endl;
  cout << fixed;
  cout << setprecision(2);
  while(N--){
    cin >> x >> y;
    p1.x = x;
    p1.y = y;
    cin >> x >> y;
    p2.x = x;
    p2.y = y;
    cin >> x >> y;
    p3.x = x;
    p3.y = y;
    cin >> x >> y;
    p4.x = x;
    p4.y = y;
    l1 = points_to_line(p1, p2);
    l2 = points_to_line(p3, p4);

    if( are_same(l1, l2) ){
      cout << "LINE" << endl;
    }
    else if(are_parallel(l1, l2) && fabs(l1.c - l2.c) > EPS){
      cout << "NONE" << endl;
    }
    else{
      point intersection;
      compute_intersection(l1, l2, intersection);
      cout << "POINT " << intersection.x << ' ' << intersection.y << endl;
    }
    
  }
  cout << "END OF OUTPUT" << endl;

  return 0;
}

