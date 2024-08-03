#include <bits/stdc++.h>

using namespace std;
/* From wikipedia */
int gcd(int a, int b){
    int tmp;
    while( b != 0 ){
        tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

int main(){
    int N;
    cin >> N;
    vector<int> diff_vect;
    for(int i{0}; i < N; i++){
        int tmp;
        cin >> tmp;
        diff_vect.push_back(tmp);
    }
    // for( auto elem : diff_vect ){
    //     cout << elem << " ";
    // }
    // cout << '\n';

    vector<int>::iterator it;
    for( it = diff_vect.begin(); it < diff_vect.end(); it++){
        *it = *(it+1) - *it;
    }

    // for( auto elem : diff_vect ){
    //     cout << elem << " ";
    // }
    // cout << '\n';
    int gcd_diff;
    for( it = diff_vect.begin(); it < diff_vect.end() - 1; it++ ){
        gcd_diff = gcd(gcd_diff, *it);
    }
    int num_trees{0};
    for( it = diff_vect.begin(); it < diff_vect.end() - 1; it++ ){
        num_trees += *it / gcd_diff - 1;
    }
    cout << num_trees << '\n';
 

    return 0;
}