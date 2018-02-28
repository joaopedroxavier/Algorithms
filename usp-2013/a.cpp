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

bool gallai(vector<int> v) {
  vector<ll> sum;
  sum.resize(v.size());

  sort(v.begin(), v.end(), greater<int>());

  sum[0] = v[0];
  for(int i=1; i < (int)v.size(); i++) sum[i] = sum[i-1] + v[i];

  if(sum.back() % 2) return false;

  for(int k=1; k < (int)v.size(); k++) {
    int p = lower_bound(v.begin(), v.end(), k, greater<int>()) - v.begin();
    if(p < k) p = k;
    if(sum[k-1] > 1ll*k*(p-1) + sum.back() - sum[p-1]) return false;
  }

  return true;
}

int n, t;

int main(){
  scanf("%d", &t);
  for(int i=0; i<t; i++) {
    scanf("%d", &n);

    vector<int> v(n);
    for(int j=0; j<n; j++) scanf("%d", &v[j]);

    printf("%s\n", gallai(v) ? "Y" : "N");
  }

	return 0;
}

