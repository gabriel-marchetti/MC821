#include <bits/stdc++.h>

using namespace std;
bool test_second_condition(string str, int l, int i){
    for( int k{1}; k <= l; k++ ){
        if( str[k] == str[k+i] ){
            return false;
        }
    }
    return true;
}

int main(){
    int len_str;
    string str;

    cin >> len_str >> str;
    // Just using the notation of 1-index of the exercise, it is more simples
    string str_aux ("a");
    str = str_aux + str;

    for( int i{1}; i < len_str; ++i ){
        int l = len_str - i;
        while( !test_second_condition(str, l, i) )
            l--;
        cout << l << '\n';        
    }

    return 0;
}