#include <bits/stdc++.h>

using namespace std;
int solution(int N, int K){
    int tmp = 1;
    for(int i{0}; i < N; i++){
        tmp = min(2*tmp, tmp + K);
    }

    return tmp;
}

int main(){
    int N, K;
    cin >> N >> K;

    cout << solution(N, K) << '\n';
    return 0;
}