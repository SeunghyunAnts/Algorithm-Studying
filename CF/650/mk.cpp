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
		string s;
		int n, k, ans = 0;
		cin >> n >> k;
		vector< pair<int, int> > alpha(26);	// < 횟수, 숫자 >
		for(int i = 0; i < 26; i++) {
			alpha[i].first = 0;
			alpha[i].second = i;
		}
		cin >> s;
		for(int i = 0; i < s.size(); i++) {
			alpha[s[i] - 'a'].first++;
		}
		sort(alpha.begin(), alpha.end(), greater<>());

		int le = 0, ri = s.size();
		while(le <= ri) {
			// mid : 토막의 길이
			// mid 칸에, 가장 많은 원소 mid 종류를 "하나씩" 넣는다고 가정
			int mid = (le + ri) / 2;
			// 각각의 원소가 가지고 있는 개수 중 최솟값, 총 갯수
			int minalpha = 10000, cnt = 0;
			for(int i = 0; i < mid; i++) {
				cnt += alpha[i].first;
				minalpha = min(minalpha, alpha[i].first);
			}
			

		}
	}

	

	return 0;
}