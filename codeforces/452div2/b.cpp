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

int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int daysleap[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int v[N], n;

int main(){
  scanf("%d", &n);
  for(int i=0; i<n; i++) scanf("%d", &v[i]);

  int cnt = 0;

  for(int i=0; i<n; i++) if(v[i] == 29) cnt++;

  if(cnt > 1) return printf("NO\n"), 0;

  for(int i=0; i<12; i++) {
    bool valid = true;
    for(int j=0; j<n; j++) {
      valid = valid and (days[(i+j)%12] == v[j] or daysleap[(i+j)%12] == v[j]);
    }
    if(valid) return printf("YES\n"), 0;
  }

  printf("NO\n"), 0;

	return 0;
}

