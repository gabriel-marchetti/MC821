#include <bits/stdc++.h>
#define MAX 105
using namespace std;

struct Daughter{
  int neck, brace;
};

int main(){
  int tests{0}, num{0};
  Daughter daughters[MAX];
  vector<int> necklaces(MAX), bracelets(MAX);


  cin >> tests;
  while(tests--){
    cin >> num;
    int tmp;
    for(int i{0}; i < num; i++){
      cin >> tmp;
      necklaces[i] = tmp;
    } 
    for(int i{0}; i < num; i++){
      cin >> tmp;
      bracelets[i] = tmp;
    }

    sort(necklaces.begin(), necklaces.begin() + num);
    sort(bracelets.begin(), bracelets.begin() + num);
    
    for(int i{0}; i < num; i++){
      daughters[i].neck = necklaces[i];
      daughters[i].brace = bracelets[i];
    }

    for(int i{0}; i < num; i++){
      cout << daughters[i].neck << ' ';
    } cout << endl;

    
    for(int i{0}; i < num; i++){
      cout << daughters[i].brace << ' ';
    } cout << endl;
  }

  return 0;
}
