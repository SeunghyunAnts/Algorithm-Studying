#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))

// 기본설정
typedef long long ll;
using namespace std;
int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};

// 전역변수

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;

	while(tc--) {
		int a, b;
		queue< pair<int, string> > q;
		int check[10000] = {false};

		// 초기화
		cin >> a >> b;
		q.push(make_pair(a, "")); check[a] = true;
		
		while(!q.empty()) {
			int i = q.front().first, next;
			string ans = q.front().second;
			q.pop();
			
			// 명령어 D
			next = (i * 2) % 10000;
			if(!check[next]) {
				if(next == b) { cout << ans + "D"; break; }
				q.push(make_pair(next, ans + "D"));
				check[next] = true;
			}
			// 명령어 S
			next = ((i == 0) ? 9999 : i - 1);
			if(!check[next]) {
				if(next == b) { cout << ans + "S"; break; }
				q.push(make_pair(next, ans + "S"));
				check[next] = true;
			}
			// 명령어 L
			next = (i / 1000) + (i % 1000) * 10;
			if(!check[next]) {
				if(next == b) { cout << ans + "L"; break; }
				q.push(make_pair(next, ans + "L"));
				check[next] = true;
			}
			// 명령어 R
			next = (i % 10) * 1000 + (i / 10);
			if(!check[next]) {
				if(next == b) { cout << ans + "R"; break; }
				q.push(make_pair(next, ans + "R"));
				check[next] = true;
			}
		}
		cout << "\n";
	}

	return 0;
}