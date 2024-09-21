#include <bits/stdc++.h>
using namespace std;

struct ListNode{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* construct_linked_list(vector<int> &values, int pos){
  if(values.empty()) return nullptr;

  ListNode* head = new ListNode(values[0]);
  ListNode* current = head;

  for( size_t i = 1; i < values.size(); i++ ){
    current->next = new ListNode(values[i]);
    current = current->next;
  }

  ListNode* pos_ptr = head;
  if( 0 <= pos && pos <= (int)values.size() ){
    for(int i = 0; i < pos; i++){
      pos_ptr = pos_ptr->next;
    }  

    current->next = pos_ptr;
  }

  return head;
}

bool hasCycle(ListNode *head){
  ListNode *hare, *turtle;
  while(hare != nullptr && hare->next != nullptr){
    hare = (hare->next)->next;
    turtle = turtle->next;
    if( hare == turtle ){
      return true;
    }
  }

  return false;
}

int main(){
  vector<int> values = {3, 2, 0, -4};
  int pos = 1;
  ListNode *head = construct_linked_list(values, pos);
  printf("hasCycle: %d\n", hasCycle(head));

  return 0;
}
