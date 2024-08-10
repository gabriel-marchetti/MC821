#include <bits/stdc++.h>

using namespace std; 

int main(){
    int testcases{0};
    cin >> testcases;
    int n, m;
    set<int> numbers;
    while(testcases--){
        cin >> n >> m;
        int tmp;
        /* READ NUMBERS APPEARENCE FIRST SQUARE */
        for(int i{0}; i < n; i++){
            for(int j{0}; j < m; j++){
                cin >> tmp;
                numbers.insert(tmp);
            }
        }

        set<int>::iterator found;
        for(int i{0}; i < n; i++){
            for(int j{0}; j < m; j++){
                cin >> tmp;
                found = numbers.find(tmp);
                if( found == numbers.end() ){
                    printf("NO\n");
                    break;
                }
            }
            if(found == numbers.end() ) break;
        }
        if(found != numbers.end()) printf("YES\n");
        numbers.clear();
    }

    return 0;
}