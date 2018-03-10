#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const ld EPS = 1e-9;
const ld PI = acos(-1);

const int N = 1e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int n, a[N];
int sum[2];

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &n);
  priority_queue<int> pq;
  int turn = 0;

  for(int i=0; i<n; i++) {
    int u;
    scanf("%d", &u);
    pq.push(u);
  }

  while(!pq.empty()) {
    int u = pq.top(); pq.pop();

    sum[turn&1] += u;
    turn++;
  }

  printf("%d %d\n", sum[0], sum[1]);
	return 0;
}

