//
// 내가 나인 게 싫은 날
// 영영 사라지고 싶은 날
// 문을 하나 만들자 너의 맘 속에다
// 그 문을 열고 들어가면
// 이 곳이 기다릴 거야
// 믿어도 괜찮아 널 위로해줄 magic shop
//
#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const ld EPS = 1e-9;
const ld PI = acos(-1);

const int N = 1e6+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

string a, b;
ll cost;
ll n, pa, pb;

void doswap(int i, int j) {
  cost += min(2, abs(i-j));
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);
  
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> a >> b;

  vector<int> ao, bo;
  for(int i=0; i<n; i++) {
    if(a[i] == '1') ao.push_back(i);
    if(b[i] == '1') bo.push_back(i);

    if(!bo.empty() and !ao.empty()) {
      if(abs(ao.back() - bo.back()) <= 1) {
        doswap(ao.back(), bo.back());
        ao.pop_back(); bo.pop_back();
      }
    }
  }

  cout << cost + ao.size() + bo.size() << endl;

	return 0;
}

