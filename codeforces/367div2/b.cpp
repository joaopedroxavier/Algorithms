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

int x[N];
int n, q;
map<int, int> m, m1;

int main(){
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    scanf("%d", &x[i]);
    m[x[i]]++; m1[x[i]]++;
  }

  int last = 0; 
  for(auto it=m.begin(); it!=m.end(); it++) {
    it->second += last; last = it->second;
  }

  scanf("%d", &q);

  for(int i=0; i<q; i++) {
    int p;
    scanf("%d", &p);
    auto it = m.lower_bound(p);
    if(it == m.end()) printf("%d\n", n);
    else if(it->first != p) printf("%d\n", it->second - m1[it->first]);
    else printf("%d\n", it->second);
  }

	return 0;
}

