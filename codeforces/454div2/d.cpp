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

int n, m;

bool ngb[1000][1000];

int main(){
  scanf("%d %d", &n, &m);

  vector<int> v(m);
  vector<vector<int>> room(n, v);

  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) room[i][j] = i*m + j+1;
  }

  if(n == 1 and m == 1) {
    printf("YES\n1\n");
  }
  else if((n <= 2 and m <= 3) or (m <= 2 and n <= 3)) {
    printf("NO\n");
  }
  else if(m >= 4) {
    printf("YES\n");
    vector<int> ord;
    for(int i=2; i<=m; i+=2) ord.pb(i);
    for(int i=1; i<=m; i+=2) ord.pb(i);

    vector<int> rord;
    if(m == 4) {
      rord = ord;
      reverse(rord.begin(), rord.end());
    }
    else {
      for(int i=1; i<=m; i+=2) rord.pb(i);
      for(int i=2; i<=m; i+=2) rord.pb(i);
    }

    for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
        printf("%d ", i&1 ? room[i][rord[j]-1] : room[i][ord[j]-1]);
        //printf("%d ", i&1 ? rord[j] : ord[j]);
      }
      printf("\n");
    }
  }
  else if(n >= 4) {
    printf("YES\n");
    vector<int> ord;
    for(int i=2; i<=n; i+=2) ord.pb(i);
    for(int i=1; i<=n; i+=2) ord.pb(i);

    vector<int> rord;
    if(n == 4) {
      rord = ord;
      reverse(rord.begin(), rord.end());
    }
    else {
      for(int i=1; i<=n; i+=2) rord.pb(i);
      for(int i=2; i<=n; i+=2) rord.pb(i);
    }

    for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
        printf("%d ", j&1 ? room[rord[i]-1][j] : room[ord[i]-1][j]);
      }
      printf("\n");
    }
  }
  else {
    printf("YES\n1 3 4\n5 7 6\n9 2 8\n");
  }


  return 0;
}

