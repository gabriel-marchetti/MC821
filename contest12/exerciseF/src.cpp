#include <bits/stdc++.h>
using namespace std;

struct Point{
  long long x, y;
  Point(long long _x, long long _y) : x(_x), y(_y) {}
};

long long sqr(long long a){
  return a * a;
}

long long sqr_euclides_distance(Point p1, Point p2){
  return sqr(p1.x - p2.x) + sqr(p1.y - p2.y);
} 

int main(){
  int num_points;
  cin >> num_points;

  vector<Point> points;

  int x, y;
  for(int i{0}; i < num_points; i++){
    cin >> x >> y;
    points.push_back( Point(x,y) );
  }

  long long min_square_dist = LLONG_MAX;
  sort(points.begin(), points.end()); // Preference to sorting x-coordinate.
  


  return 0;
}
