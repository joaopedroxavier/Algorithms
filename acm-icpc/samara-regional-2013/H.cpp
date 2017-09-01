#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<
#define y1 asdasda

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const long double EPS = 1e-9;
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int x1[3], y1[3], x2[3], y2[3];
int s1[3], s2[3];

bool ans;

int dist(int px1, int py1, int px2, int py2){ return (px2-px1)*(px2-px1) + (py2-py1)*(py2-py1); }

bool check(int i, int j){
  return s1[i] * s2[j] == s2[i] * s1[j];
}

int main(){
	ios_base::sync_with_stdio(false);
  for(int i=0;i<3;i++) cin >> x1[i] >> y1[i];
  for(int i=0;i<3;i++) s1[i] = dist(x1[i], y1[i], x1[(i+1)%3], y1[(i+1)%3]);
  sort(s1, s1+3);

  for(int i=0;i<3;i++) cin >> x2[i] >> y2[i];
  for(int i=0;i<3;i++) s2[i] = dist(x2[i], y2[i], x2[(i+1)%3], y2[(i+1)%3]);
  sort(s2, s2+3);

  ans = true;
  for(int i=0;i<3;i++) for(int j=0;j<3;j++) ans = ans and check(i, j);

  cout << ((ans) ? "YES" : "NO") << endl;

	return 0;
}
