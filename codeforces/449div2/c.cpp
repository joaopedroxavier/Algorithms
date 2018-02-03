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

string text0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
string text1 = "What are you doing while sending \"";
string text2 = "\"? Are you busy? Will you send \"";
string text3 = "\"?";

ll sz[N];
int q;

char process(ll i, ll k) {
  if(i == 0) return text0[k];
  else if(k < (ll) text1.size()) return text1[k];
  else if(!sz[i]) return process(i-1, k-text1.size());
  else {
    ll t1 = text1.size();
    ll t2 = text2.size();
    if(k >= sz[i]) return '.';
    else if(k == sz[i]-1 or k == sz[i] - 2) return k == sz[i] - 1 ? text3[1] : text3[0];
    else if(k >= t1 + sz[i-1] + t2) return process(i-1, k - t1 - sz[i-1] - t2);
    else if(k >= t1 + sz[i-1]) return text2[k - t1 - sz[i-1]];
    else if(k >= t1) return process(i-1, k - t1);
    else return text1[k];
  }
}

int main(){
  scanf("%d", &q);

  sz[0] = (ll) text0.size();
  for(int i=1; i<N; i++) {
    sz[i] = 2*sz[i-1] + 68;
    if(sz[i] >= (ll)1e18) break;
  }

  for(int i=0; i<q; i++) {
    ll n, k;
    scanf("%lld %lld", &n, &k);
    if(sz[n] and k > sz[n]) printf(".");
    else printf("%c", process(n, k-1));
  }
  printf("\n");

	return 0;
}

