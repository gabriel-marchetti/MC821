#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-9

#define LEFT 1
#define RIGHT -1

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

struct segment{
  point left, right;
  line l;
  int direction_flows;
};

int where_it_falls(point source, vector<segment> segments){
  line vertical_line = points_to_line( point(source.x, 0), source );

  for(int i{0}; i < (int)segments.size(); i++){
    
  }
}

int main(){
  int N;
  int num_segments, num_sources;
  vector<segment> segments;
  vector<point> sources;
  while(N--){
    segments.clear(); sources.clear(); 
    cin >> num_segments;

    int x1, y1, x2, y2;
    for(int i{0}; i < num_segments; i++){
      cin >> x1 >> y1 >> x2 >> y2;
      segment seg;
      if( x1 < x2 ){
        seg.left = point(x1, y1);
        seg.right = point(x2, y2);
      }
      else{
        seg.left = point(x2, y2);
        seg.right = point(x1, y1);
      }
      seg.l = points_to_line(seg.left, seg.right);
      if( y1 < y2 ){
        seg.direction_flows = LEFT;
      }
      else{
        seg.direction_flows = RIGHT;
      }
      
      segments.push_back(seg);
    }

    cin >> num_sources;
    for(int i{0}; i < num_sources; i++){
      cin >> x1 >> y1;
      sources.push_back(point(x1, y1));
    }

    while( !sources.empty() ){
      
    }
  }

  return 0;
}
