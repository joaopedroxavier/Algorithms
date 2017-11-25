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

string s;
int v[N][3];

int main(){
  cin >> s;

  int n = (int) s.size();
  if(s[0] == 'a') v[0][0] = 1;
  else v[0][1] = 1;
  for(int i=1; i<n; i++) {
    char c = s[i];
    if(c == 'a') {
      v[i][0] = v[i-1][0] + 1;
      v[i][2] = max(v[i-1][1], v[i-1][2]);
      v[i][2]++;
      v[i][1] = v[i-1][1];
    } else {
      v[i][0] = v[i-1][0];
      v[i][1] = max(v[i-1][0], v[i-1][1]);
      v[i][1]++;
      v[i][2] = v[i-1][2];
    }
    //printf("%d %d %d\n", v[i][0], v[i][1], v[i][2]);
  }

  printf("%d\n", max({v[n-1][0], v[n-1][1], v[n-1][2]}));
	return 0;
}

