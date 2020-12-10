/*
    BOJ 2875 (https://www.acmicpc.net/problem/2875)
*/

#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main(void) {
    cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, k;    // 여학생의 수, 남학생의 수, 인턴쉽 참여 인원 수
    cin >> n >> m >> k;

    while(k) {
        if(n % 2 != 0) {    // 남학생이 홀수면 짝수로 맞춤
            n--;
        } else {
            int mteam = n / 2;
            int wteam = m;

            // 더 인원이 많은 팀을 적은 팀으로 맞춤
            if(mteam < wteam) {
                m--;
            } else if(1 < k) {
                n -= 2;
                k--;
            } else {
                n--;
            }
        }
        k--;
    }

    cout << min(n / 2, m) << "\n";
}