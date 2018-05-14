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

const int N = 5e3+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

map<int, int> factorize(int n) {
  map<int, int> ans;
  for(int i=2; i*i <= n; i++) {
    while(n % i == 0) {
      n /= i;
      ans[i]++;
    }
  }
  if(n > 1) ans[n]++;
  return ans;
}

void reduce(int &n) {
  if(abs(n) <= 1) return;

  int sgn = n / abs(n);
  map<int, int> factors = factorize(abs(n));

  int m = 1;
  for(auto it : factors) if(it.second & 1) m *= it.first;
  n = m * sgn;
}

int n, a[N], ans[N], pos[N], am[N];
vector<int> comp;
int zeropos = -1;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &n);
  for(int i=1; i<=n; i++) {
    scanf("%d", &a[i]);
    reduce(a[i]);
    comp.push_back(a[i]);
  }

  sort(comp.begin(), comp.end());
  auto it = unique(comp.begin(), comp.end());
  comp.resize(it - comp.begin());

  for(int i=1; i<=n; i++) {
    pos[i] = lower_bound(comp.begin(), comp.end(), a[i]) - comp.begin();
    if(a[i] == 0) zeropos = pos[i];
  }

  for(int i=1; i<=n; i++) {
    memset(am, 0, sizeof am);
    int sz = 0;
    bool fuck = false;

    for(int j=1; j<=i; j++) {
      if(am[pos[j]] == 0) sz++;
      am[pos[j]]++;

      fuck = false;
      if(~zeropos) {
        if(am[zeropos] > 0 and am[zeropos] != i) fuck = true;
      }
    }

    ans[sz - fuck]++;

    for(int j=i+1; j<=n; j++) {
      if(am[pos[j]] == 0) sz++;
      am[pos[j]]++;
      am[pos[j-i]]--;
      if(am[pos[j-i]] == 0) sz--;

      fuck = false;
      if(~zeropos) {
        if(am[zeropos] > 0 and am[zeropos] != i) fuck = true;
      }
      ans[sz - fuck]++;
    }
  }

  for(int i=1; i<=n; i++) printf("%d ", ans[i]);
  printf("\n");

	return 0;
}

