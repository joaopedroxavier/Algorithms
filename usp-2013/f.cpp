#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;

const long double EPS = 1e-9;
const long double PI = acos(-1);
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int t;

bool zero(ld l) { return l < EPS and l > -EPS; }

int main(){
  scanf("%d", &t);

  while(t--) {
    int n;
    ld w, s; vector<ld> h;
    scanf("%d %Lf %Lf", &n, &w, &s);

    int pos;
    for(int i=0; i<n; i++) {
      ld ht;
      scanf("%Lf", &ht);
      h.pb(ht);
      if(zero(ht)) pos = i;
    }

    ld start = 0, x = s;
    int it = pos-1;
    while(it >= 0) {
      x += w; start = max(start, atan2(h[it], x));
      x += s; it--;
    }

    ld fin = 0; x = s;
    it = pos+1;
    while(it < n) {
      x += w; fin = max(fin, atan2(h[it], x));
      x += s; it++;
    }

    fin = PI - fin;

    printf("%.12Lf\n", (fin - start)*960/PI);
  }

	return 0;
}

