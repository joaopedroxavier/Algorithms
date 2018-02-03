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
const int N=2e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

ii v[N];
int n;
ii tv1 = {-1, -1}, tv2 = {-1, -1};

int main(){
  scanf("%d", &n);

  for(int i=0; i<n; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    v[i].first = l, v[i].second = r;
  }

  sort(v, v+n);

  for(int i=0; i<n; i++) {
    if(tv1 == mp(-1, -1) or tv1.second < v[i].first) {
      tv1 = v[i];
    }
    else if(tv2 == mp(-1, -1) or tv2.second < v[i].first) {
      tv2 = v[i];
    }
    else {
      printf("NO\n");
      return 0;
    }
  }

  printf("YES\n");

	return 0;
}

