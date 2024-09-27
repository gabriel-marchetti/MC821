#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    bool isWord;
    TrieNode* child[26];

    TrieNode() : isWord(false) {
        memset(child, 0, sizeof(child));      
    }
};

int count_distinct_substrings(const string& str) {
    TrieNode* head = new TrieNode();
    int count = 0;

    for (int i = 0; i < str.length(); i++) {
        TrieNode *temp = head;

        for (int j = i; j < str.length(); j++) {
            int index = str[j] - 'a';
            if (!temp->child[index]) {
                temp->child[index] = new TrieNode();
                count++;
            }
            temp = temp->child[index];
        }
    }

    return count;
}

int main() {
    string str;
    ios_base::sync_with_stdio(0);  
    cin.tie(0);                    
    cin >> str;
    cout << count_distinct_substrings(str) << '\n';
    return 0;
}

