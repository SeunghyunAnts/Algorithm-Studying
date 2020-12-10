#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))
// int pair 간단히
#define pii pair<int, int>
#define mp(X, Y) make_pair(X, Y)

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

	while(tc--) {
		map<int, int> checker;
		int n, qsize = 0;
		cin >> n;

		while(n--) {
			char order;
			int data;
			cin >> order >> data;

			if(order == 'I') {
				map<int, int>::iterator it = checker.find(data);
				if(it != checker.end()) {
					(*it).second++;
				} else {
					checker.insert(mp(data, 1));
				}
				qsize++;
			} else {
				if(qsize == 0) continue;
				else if(data == -1) {
					map<int, int>::iterator it = checker.begin();
					if(it->second == 1) {
						checker.erase(it->first);
					} else {
						(*it).second--;
					}
				} else {
					map<int, int>::reverse_iterator it = checker.rbegin();
					if(it->second == 1) {
						checker.erase(it->first);
					} else {
						(*it).second--;
					}
				}
				qsize--;
			}
		}

		if(qsize) {
			cout << checker.rbegin()->first << " " << checker.begin()->first << "\n";
		} else {
			cout << "EMPTY\n";
		}
	}

	return 0;
}