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

char clw[] = {'^', '>', 'v', '<'};
char ccw[] = {'^', '<', 'v', '>'};

char moveclw(int c, int n){
  return clw[(c + (n%4))%4];
}
char moveccw(int c, int n){
  return ccw[(c + (n%4))%4];
}

bool isclw = false, isccw = false;

int main(){
	ios_base::sync_with_stdio(false);
  char fst, lst;
  int n;
  cin >> fst >> lst;
  cin >> n;
  if(fst == '^'){
    if(moveclw(0,n) == lst) isclw = true;
    if(moveccw(0,n) == lst) isccw = true;
  }
  if(fst == '>'){
    if(moveclw(1,n) == lst) isclw = true;
    if(moveccw(3,n) == lst) isccw = true;
  }
  if(fst == 'v'){
    if(moveclw(2,n) == lst) isclw = true;
    if(moveccw(2,n) == lst) isccw = true;
  }
  if(fst == '<'){
    if(moveclw(3,n) == lst) isclw = true;
    if(moveccw(1,n) == lst) isccw = true;
  }

  if(isccw and isclw) cout << "undefined" << endl;
  else cout << ((isclw) ? "cw" : "ccw") << endl;

	return 0;
}

