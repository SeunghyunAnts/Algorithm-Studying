#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))

// 기본설정
typedef long long ll;
using namespace std;
int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;

	// 소수 확인
	bool isPrime[10000];
	memset(isPrime, 1, sizeof(isPrime));
	for(int i = 2; i < 10000; i++) {
		if(isPrime[i] == 1) {
			for(int j = 2; i * j < 10000; j++) {
				isPrime[i * j] = 0;
			}
		}
	}

	while(tc--) {
		string n, m;
		cin >> n >> m;
		if(n == m) {
			cout << "0\n";
			continue;
		}
		int check[10000];
		memset(check, -1, sizeof(check));
		check[stoi(n)] = 0;
		queue<string> q;
		q.push(n);
		while(!q.empty()) {
			string cur_s = q.front();
			int cur_i = stoi(cur_s);
			q.pop();
			if(cur_s == m) continue;

			for(int i = 0; i < 4; i++) {
				for(int j = 0; j < 10; j++) {
					// 필요없는경우 예외처리
					if((i == 0 && j == 0) || (cur_s[i] == (j + '0'))) continue;
					string next_s = cur_s; next_s[i] = (char)(j + '0');
					int next_i = stoi(next_s);
					if(isPrime[next_i] && (check[next_i] == -1)) {
						// 이전에 방문한적없는 소수
						check[next_i] = check[cur_i] + 1;
						q.push(next_s);
					}
				}
			}
		}
		if(check[stoi(m)] == -1) cout << "Impossible\n";
		else cout << check[stoi(m)] <<"\n";
	}

	return 0;
}