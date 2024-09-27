#include <bits/stdc++.h>
using namespace std; 

// Extracted: from GeeksForGeeks.
void compute_LPS_Array(string& pat, int M, vector<int>& lps){
  // Length of the previous longest prefix suffix
  int len = 0;

  // lps[0] is always 0
  lps[0] = 0;

  // loop calculates lps[i] for i = 1 to M-1
  int i = 1;
  while (i < M) {
    if (pat[i] == pat[len]) {
      len++;
      lps[i] = len;
      i++;
    }
    else {
      if (len != 0) {
        len = lps[len - 1];
      }
      else{
        lps[i] = 0;
        i++;
      }
    }
  } 

}

bool check_condition(string S){
  if(S.length() % 2 == 1){
    return false;
  }

  int i = 0, j = S.length() / 2;
  while( i < S.length() / 2 ){
    if(S[i] != S[j]){
      return false;
    }
    i++; j++;
  }
  return true;
}

int main(){
  string str;

  cin >> str;
  //cout << "str: " << str << '\n';

  int M = str.length();
  vector<int> lps(M);

  compute_LPS_Array(str, M, lps);
  //for(auto &elem : lps){
  //  cout << elem << ' ';
  //} cout << '\n';

  if( lps.back() <= M / 2 ){
    cout << "NO" << '\n';
    return 0;
  }
  cout << "YES" << '\n';

  string final_str;
  for(int i{M-lps.back()}; i < M; i++){
    final_str.push_back(str[i]);
  }
  cout << final_str << '\n';


  return 0;
}
