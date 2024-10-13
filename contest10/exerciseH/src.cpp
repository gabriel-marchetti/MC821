#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

int main(){
  int tests, len_palindrome, n;
  int mat[MAX][MAX];
  cin >> tests;
  cin.ignore();

  string str, rev_str;
  while(tests--){
    getline(cin, str);

    if(str.empty()){
      cout << 0 << endl;
      continue;
    }

    rev_str = str;
    reverse(rev_str.begin(), rev_str.end());
    memset(mat, 0, sizeof(mat));
    
    n = str.length();
    for(int i{1}; i <= n; i++){
      for(int j{1}; j <= n; j++){
        mat[i][j] = mat[i-1][j-1] + (str[i-1] == rev_str[j-1] ? 1 : 0);
        mat[i][j] = max(mat[i][j], mat[i-1][j]);
        mat[i][j] = max(mat[i][j], mat[i][j-1]);
      }
    }

    cout << mat[n][n] << endl;
  }

  return 0;
}
