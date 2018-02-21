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
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int k, n, s[N], cnt[N];

int main(){
  scanf("%d %d", &k, &n);

  for(int i=1; i<=n; i++) scanf("%d", &s[i]), cnt[s[i]]++;
  for(int i=1; i<=k; i++) {
    cnt[i]--;

    bool found = true;
    for(int j=1; j<=k; j++) found = found and (cnt[j] == cnt[1]);
    if(found) return printf("-%d\n", i), 0;

    cnt[i]++;
  }

  for(int i=1; i<=k; i++) {
    cnt[i]++;

    bool found = true;
    for(int j=1; j<=k; j++) found = found and (cnt[j] == cnt[1]);
    if(found) return printf("+%d\n", i), 0;

    cnt[i]--;
  }

  if(n % k != 0) return printf("*\n");
  vector<int> diff;
  for(int i=1; i<=k; i++) if(cnt[i] != n/k) diff.push_back(i);

  if(diff.size() != 2) return printf("*\n");
  sort(diff.begin(), diff.end(), [](int i, int j){ return cnt[i] > cnt[j]; });

  printf("-%d +%d\n", diff[0], diff[1]);

	return 0;
}

