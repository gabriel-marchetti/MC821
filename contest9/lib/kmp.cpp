#include <bits/stdc++.h>
using namespace std;

// Functions signatures.
void compute_LSP_array(char *P, int M, int *lps);
void KMP_search(char *P, char *T);

void KMP_search(char *P, char *T){
  int M = strlen(P); int N = strlen(T);
  int lps[M];

  compute_LSP_array(P, M, lps);
  int i{0}, j{0};
  while(i < N){
    if(P[i] == P[j]){
      i++; j++;
    }

    if(j == M){
      printf("Found pattern at index %d\n", i - j);
      j = lps[j-1];
    }
    else if(i < N && P[j] != T[j]){
      if(j != 0){
        j = lps[j-1];
      }
      else{
        i++;
      }
    }
  }
}

void compute_LSP_array(char *P, int M, int *lps){
  int len = 0;
  lps[0] = 0;

  int i = 1;
  while(i < M){
    if(P[i] == P[len]){
      len++;
      lps[i] = len;
      i++;
    }
    else{
      if(len == 0){
        lps[i] = 0;
        i++;
      }
      else{
        len = lps[len - 1];
      }
    }
  }
}

void compute_LSP_array(string P, vector<int> &lps){
  lps.clear();
  int len_lps = 0, M = (int) P.size();
  lps.push_back(0);
  
  int i = 1;
  while(i < M){
    if(P[i] == P[len_lps]){
      len_lps++;
      lps.push_back(len_lps);
      i++;
    }
    else{
      if(len_lps == 0){
        lps.push_back(0);
        i++;
      }
      else{
        len_lps = lps[len_lps - 1];
      }
    }
  }
}

void KMP_search(string P, string T){
  int N = (int) T.size(), M = (int) P.size();
  vector<int> lps;

  compute_LSP_array(P, lps);

  int i = 0, j = 0;
  while(i < N){
    if(P[j] == T[i]){
      i++;
      j++;
    }

    if(j == M){
      printf("Pattern Found at Index: %d\n", i - j);
      j = lps[j-1];
    }
    else if(i < N && P[j] != T[i]){
      if(j == 0){
        i++;
      }
      else{
        j = lps[j-1];
      }
    }
  }
}

void print_array(int array[], int size){
  for(int i{0}; i < size; i++){
    printf("%d ", array[i]);
  }
  printf("\n");
}

int main(){
  char P_test[] = "AAACAAAAA";
  int P_test_len = strlen(P_test), lps[P_test_len];
  
  compute_LSP_array(P_test, strlen(P_test), lps);  
  print_array(lps, P_test_len);

  string P_test_str = "AAACAAAAA";
  vector<int> lps_test_str;
  compute_LSP_array(P_test_str, lps_test_str);

  for(auto &elem : lps_test_str){
    printf("%d ", elem);
  } printf("\n");
  
  P_test_str.clear(); 
  lps_test_str.clear();

  string T_test_str = "AAAABAAABAA";
  P_test_str = "AAAB";
  KMP_search(P_test_str, T_test_str);
  

  return 0;
}
