#include <bits/stdc++.h>
using namespace std;

int main(){
  int n{0}, number{0}, mods[5]{0}, num_groups{0};
  cin >> n;
  for(int i{0}; i < n; i++){
    cin >> number;
    mods[number%5]++;
  }
  num_groups += mods[0];
  int aux_group = 0;
  if(mods[4] && mods[1]){
    aux_group = min(mods[1], mods[4]);
    num_groups += aux_group;
    mods[4] -= aux_group;
    mods[1] -= aux_group;
  }
  if(mods[3] && mods[2]){
    aux_group = min(mods[2], mods[3]);
    num_groups += aux_group;
    mods[2] -= aux_group;
    mods[3] -= aux_group;
  }

  // 1 e 2
  // 1 e 3
  // 2 e 4
  // 3 e 4
  if(mods[1] && mods[2]){
    aux_group = min(mods[2]/2, mods[1]);
    num_groups += aux_group;
    mods[1] -= 2 * aux_group;
    mods[2] -= aux_group;
  }
  else if(mods[1] && mods[3]){
    aux_group = min(mods[1]/2, mods[3]);
    num_groups += aux_group;
    mods[1] -= 2 * aux_group;
    mods[3] -= aux_group; 
  }
  else if(mods[2] && mods[4]){
    aux_group = min(mods[4]/2, mods[2]);
    num_groups += aux_group;
    mods[4] -= 2 * aux_group;
    mods[2] -= aux_group;
  }
  else if(mods[3] && mods[4]){
    aux_group = min(mods[3]/2, mods[4]);
    num_groups += aux_group;
    mods[3] -= 2 * aux_group;
    mods[4] -= aux_group;
  }

  if(mods[1]){
    aux_group = mods[1] / 5;
    num_groups += aux_group;
  }
  else if(mods[2]){
    aux_group = mods[2] / 5;
    num_groups += aux_group;
  }
  else if(mods[3]){
    aux_group = mods[3] / 5;
    num_groups += aux_group;
  }
  else if(mods[4]){
    aux_group = mods[4] / 5;
    num_groups += aux_group;
  }
 
  printf("%d\n", num_groups);
 
  return 0;
}
