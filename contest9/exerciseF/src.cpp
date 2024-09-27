#include <bits/stdc++.h>
using namespace std;

int KMP_search(string P, string T);
void compute_LSP_array(string P, vector<int> &lps);

int KMP_search(string P, string T){
  int N = (int) T.size(), M = (int) P.size();
  vector<int> lps(M);

  compute_LSP_array(P, lps);

  int occur = 0;
  int i = 0, j = 0;
  while(i < N){
    if(P[j] == T[i]){
      i++;
      j++;
    }

    if(j == M){
      occur++;
      j = lps[j-1];
    }
    else if(i < N && P[j] != T[i]){
      if(j != 0){
        j = lps[j-1];
      }
      else{
        i = i + 1;
      }
    }
  }

  return occur;
}

void compute_LSP_array(string P, vector<int> &lps){
  int len_lps = 0, M = P.length();
  lps[0] = 0;
  
  int i = 1;
  while(i < M){
    if(P[i] == P[len_lps]){
      len_lps++;
      lps[i] = len_lps;
      i++;
    }
    else{
      if(len_lps != 0){
        len_lps = lps[len_lps-1];
      }
      else{
        lps[i] = 0;
        i++;
      }
    }
  }
}

int main(){
  string T, P;
  cin >> T >> P;
  //cout << T << '\n';
  //cout << P << '\n';
  cout << KMP_search(P, T) << '\n';

  return 0;
}
