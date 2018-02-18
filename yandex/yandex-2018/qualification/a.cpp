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

set<int> s;
int n, res[10], ticket[N][6];

int main(){
  for(int i=0; i<10; i++) {
    scanf("%d", &res[i]);
    s.insert(res[i]);
  }

  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    int cnt = 0;
    for(int i=0; i<6; i++) {
      int v;
      scanf("%d", &v);
      cnt += s.count(v);
    }
    printf("%s\n", cnt >= 3 ? "Lucky" : "Unlucky");
  }

	return 0;
}

