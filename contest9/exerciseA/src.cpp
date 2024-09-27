#include <bits/stdc++.h>
using namespace std; 

vector<int> compute_LSP_array(string P){
  int len = 0, M = P.length();
  vector<int> lps(M);
  
  int i = 1;
  while(i < M){
    if(P[i] == P[len]){
      len++;
      lps[i] = len;
      i++;
    }
    else{
      if(len != 0){
        len = lps[len-1];
      }
      else{
        lps[i] = 0;
        i++;
      }
    }
  }

  return lps;
}

// Extracted from GeeksForGeeks.org
int get_min_char_to_add(string str){
  vector<int> lps;
  string rev_str = str;
  reverse(rev_str.begin(), rev_str.end());

  string concat = str + '$' + rev_str;
  lps = compute_LSP_array(concat);
  //cout << concat << '\n';
  //for(auto &elem : lps)
  //  printf("%d ", elem);
  //printf("\n");

  return (str.length() - lps.back());  
}

int main(){
  string line, line_reverse;
  while( getline(cin, line) ){
    //cout << line << '\n'; 
    line_reverse = line;
    reverse(line_reverse.begin(), line_reverse.end()); 
    int min_to_add = get_min_char_to_add(line_reverse);

    for(int i{min_to_add-1}; i >= 0; i--){
      line.push_back(line[i]);
    }

    cout << line << '\n';
  }

  return 0;
}
