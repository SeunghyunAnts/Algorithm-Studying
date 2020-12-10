#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int n, m, cnt = 0, mididx = -1;
string s;
vector<string> v;		// 문자열을 저장하는 벡터
vector<bool> isused;	// 이미 사용된 문자열인지 확인
queue<int> fans;		// 앞에서부터 출력할 문자열
stack<int> bans;		// 중간 이후부터 출력할 문자열


int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	for(int i = 0; i < n; i++) {
		cin >> s;
		v.push_back(s);
		isused.push_back(false);
	}

	while(true) {
		bool havePair = false;
		for(int i = 0; i < n; i++) {		// 처음에 위치할 문자열
			for(int j = 0; j < n; j++) {	// 끝에 위치할 문자열
				if(i == j || isused[i] || isused[j] || havePair) continue;
				else {
					bool ispd = true;	// i와 j가 펠린드롬이면 true
					for(int idx = 0; idx < m; idx++) {
						int iidx = idx;
						int jidx = m - idx - 1;
						if(v[i][iidx] != v[j][jidx]) {
							ispd = false;
							break;
						}
					}

					if(ispd) {
						havePair = true;
						isused[i] = true;
						isused[j] = true;
						fans.push(i);
						bans.push(j);
						cnt += 2;
					} else {
						continue;
					}
				}
			}
		}

		if(!havePair) break;
	}

	for(int i = 0; i < n; i++) {
		if(!isused[i]) {
			bool ispd = true;
			for(int j = 0; j < m; j++) {
				// 자기자신이 펠린드롬인지 확인
				if(v[i][j] != v[i][m - j - 1]) {
					ispd = false;
					break;
				}
			}
			if(ispd) {
				mididx = i;
				cnt++;
				break;
			}
		}
	}
	
	// 출력
	cout << cnt * m << "\n";

	while(!fans.empty()) {
		cout << v[fans.front()];
		fans.pop();
	}
	if(mididx > -1) {
		cout << v[mididx];
	}
	while(!bans.empty()) {
		cout << v[bans.top()];
		bans.pop();
	}

	return 0;
}