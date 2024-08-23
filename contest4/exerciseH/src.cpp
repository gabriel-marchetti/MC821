#include <bits/stdc++.h>
using namespace std;

void printString(string::iterator head, string::iterator tail){
  if( head == tail )
    return;
  while(head != tail){
    cout << *head;
    head++;
  }
  cout << '\n';
}

unsigned long long num_distinct_substrings(string &S){
  unsigned long long num = 0;
  vector<bool> appeared(26, false);
  string::iterator head, tail;
  head = S.begin();
  tail = S.begin();
  while(head != S.end()){
    int pos = S[*tail] - 'a';
    if(appeared[pos] == false){
      appeared[pos] = true;
      tail++;
      num++;
    }
    else{
      pos = S[*head] - 'a';
      appeared[pos] = false;

      head++;
      num++;
    }
    printString(head, tail);
  }

  return num;
}


int main(){
  string S;
  cin >> S;
  cout << num_distinct_substrings(S) << '\n';

  return 0;
}
