#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const long double EPS = 1e-9;
const int N=5e6+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int k1, k2, k3;
map<int, int> cnt;

int main(){
  scanf("%d %d %d", &k1, &k2, &k3);
  cnt[k1]++, cnt[k2]++, cnt[k3]++;

  printf("%s\n", cnt[1] >= 1 or cnt[2] >= 2 or cnt[3] >= 3 or (cnt[4] >= 2 and cnt[2] >= 1) ? "YES" : "NO");

	return 0;
}

