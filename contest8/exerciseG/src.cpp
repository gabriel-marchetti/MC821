#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int test_cases;
  double a1, t1, a2, t2, B, delta1, delta2, tm;
  scanf("%d", &test_cases);
  while(test_cases--){
    scanf("%lf%lf%lf%lf%lf", &B, &t1, &a1, &t2, &a2);
    if( (t1 + a1 / B) <= t2 ){
      delta1 = a1 / B;
      delta2 = a2 / B;
    }
    else{
      double aux1, aux2, tf1, tf2, tt1, tt2;
      aux1 = a1 - B*(t2-t1);

      tt1 = 2 * aux1 / B;
      tt2 = 2 * a2 / B;
      tm = min(tt1, tt2) + t2;
      
      if(tt1 <= tt2){
        delta1 = tm - t1;  
        aux2 = a2 - B / 2 * (tm - t2);
        tf2 = aux2 / B + tm;
        delta2 = tf2 - t2;
      }
      else{
        delta2 = tm - t2;
        aux1 = B * (t2 - t1) + B/2 * (tm - t2);
        aux1 = a1 - aux1;
        tf1 = tm + aux1/B;
        delta1 = tf1 - t1;
      }
    }

    printf("%.7f %.7f\n", delta1, delta2);
  }

  return 0;
}
