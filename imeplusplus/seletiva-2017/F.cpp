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

int v[N];
int n;
int lis[N];

int main(){
	ios_base::sync_with_stdio(false);
  cin >> n;
  for(int i=0;i<n;++i) cin >> v[i];
  lis[0] = v[0];
  int length=1;
  for(int i=1;i<n;++i){
    if(v[i] < lis[0]) lis[0] = v[i];
    else if(v[i] > lis[length-1]){
      lis[length] = v[i];
      length++;
    }
    else{
      lis[upper_bound(lis, lis+length, v[i]) - lis] = v[i];
    }
  }
  cout << length << endl;
	return 0;
}

