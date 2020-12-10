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

	while(tc--) {
		int n0, n1, n2;
		cin >> n0 >> n1 >> n2;
		
		// 111100001010 모양으로 출력

		// n2가 0일 경우, 앞에서 n1을 한번 처리하지 못함.
		// 마찬가지로 n0이 0일경우 앞에서 n1을 한번 처리하지 못함.
		if(n2 == 0) {
			for(int i = 0; i < n0 + 1; i++) cout << "0";
			for(int i = 0; i < n1 / 2; i++) cout << "10";
			if(n1 % 2 == 1) cout << "1";
		} else if(n0 == 0) {
			for(int i = 0; i < n2 + 1; i++) cout << "1";
			for(int i = 0; i < n1 / 2; i++) cout << "01";
			if(n1 % 2 == 1) cout << "0";
		} else {
			// 나머지 경우 출력
			for(int i = 0; i < n2 + 1; i++) cout << "1";
			for(int i = 0; i < n0 + 1; i++) cout << "0";
			// n2와 n0 사이에서 n1 경우가 한 개 발생함.
			// n1을 처리하는 시작부분은 무조건 1
			n1--;
			for(int i = 0; i < n1 / 2; i++) cout << "10";
			if(n1 % 2 == 1) cout << "1";
		}
		cout << "\n";
	}

	return 0;
}