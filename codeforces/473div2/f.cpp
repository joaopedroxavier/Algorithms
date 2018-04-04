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

vector<bitset<30>> base[N];
bitset<30> a[N];
int n, q;
ll pot[N];

void add (vector<bitset<30>> &bs, bitset<30> num) {
  int p = 0;
  bs.push_back(num);

  for(int i=0; i < 30; i++) {
    int k=-1;
    for(int j=p; j<(int)bs.size(); j++) if(bs[j][i]) {
      k = j;
    }
    if(~k) {
      swap(bs[p], bs[k]);
      for(int j=p+1; j<(int)bs.size(); j++) if(bs[j][i]) {
        bs[j] ^= bs[p];
      }
      p++;
    }
  }

  while(!bs.empty()) {
    int u = bs.back().to_ulong();
    if(u == 0) bs.pop_back();
    else break;
  }
}

bool query(vector<bitset<30>> bs, bitset<30> num) {
  for(int i=0; i<30; i++) if(num[i]){
    int k=-1;
    for(int j=0; j<(int)bs.size(); j++) if(bs[j][i]) {
      k = j;
    }
    if(~k) {
      num ^= bs[k];
    } else return false;
  }

  for(int i=0; i<30; i++) if(num[i]) return false;
  return true;
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  pot[0] = 1;
  for(int i=1; i<N; i++) pot[i] = (pot[i-1] * 2) % MOD;

  scanf("%d %d", &n, &q);
  for(int i=0; i<n; i++) {
    int u; scanf("%d", &u);
    a[i] = bitset<30>(u);

    if(i == 0) add(base[i], a[i]);
    else {
      base[i] = base[i-1];
      add(base[i], a[i]);
    }
  }

  for(int i=0; i<q; i++) {
    int l, x; scanf("%d %d", &l, &x);
    bitset<30> b(x); l--;

    if(query(base[l], b)) {
      printf("%lld\n", pot[l - base[l].size() + 1]);
    } else printf("0\n");
  }
  return 0;
}

