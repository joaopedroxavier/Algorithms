//
// 내가 나인 게 싫은 날
// 영영 사라지고 싶은 날
// 문을 하나 만들자 너의 맘 속에다
// 그 문을 열고 들어가면
// 이 곳이 기다릴 거야
// 믿어도 괜찮아 널 위로해줄 magic shop
//
#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const ld EPS = 1e-9;
const ld PI = acos(-1);

const int N = 1e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

namespace fft {
  typedef float fl;

  struct num {
    fl x, y;
    num() { x = y = 0; }
    num(fl x, fl y) : x(x), y(y) {}
  };

  inline num operator+ (num a, num b) { return num(a.x + b.x, a.y + b.y); }
  inline num operator- (num a, num b) { return num(a.x - b.x, a.y - b.y); }
  inline num operator* (num a, num b) { return num(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }
  inline num conj(num a) { return num(a.x, -a.y); }

  int base = 1;
  vector<num> roots = {{0, 0}, {1, 0}};
  vector<int> rev = {0, 1};

  void ensure_base(int nbase) {
    if(nbase <= base) return;

    rev.resize(1 << nbase);
    for(int i=0; i < (1 << nbase); i++) {
      rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
    }
    roots.resize(1 << nbase);

    while(base < nbase) {
      fl angle = 2*PI / (1 << (base + 1));
      for(int i = 1 << (base - 1); i < (1 << base); i++) {
        roots[i << 1] = roots[i];
        fl angle_i = angle * (2 * i + 1 - (1 << base));
        roots[(i << 1) + 1] = num(cos(angle_i), sin(angle_i));
      }
      base++;
    }
  }

  void fft(vector<num> &a, int n = -1) {
    if(n == -1) {
      n = a.size();
    }
    assert((n & (n-1)) == 0);
    int zeros = __builtin_ctz(n);
    ensure_base(zeros);
    int shift = base - zeros;
    for(int i=0; i<n; i++) {
      if(i < (rev[i] >> shift)) {
        swap(a[i], a[rev[i] >> shift]);
      }
    }
    for(int k=1; k < n; k <<= 1) {
      for(int i=0; i<n; i+=2*k) {
        for(int j=0; j<k; j++) {
          num z = a[i+j+k] * roots[j+k];
          a[i+j+k] = a[i+j] - z;
          a[i+j] = a[i+j] + z;
        }
      }
    }
  }

  vector<num> fa, fb;
  vector<int> multiply(vector<int> &a, vector<int> &b) {
    int need = a.size() + b.size() - 1;
    int nbase = 0;

    while((1 << nbase) < need) nbase++;
    ensure_base(nbase);
    int sz = (1 << nbase);
    if(sz > (int) fa.size()) {
      fa.resize(sz);
    }
    for(int i=0; i<sz; i++) {
      int x = (i < (int) a.size() ? a[i] : 0);
      int y = (i < (int) b.size() ? b[i] : 0);
      fa[i] = num(x,y);
    }
    fft(fa, sz);
    num r(0, -0.25 / sz);
    for(int i=0; i <= (sz >> 1); i++) {
      int j = (sz - i) & (sz - 1);
      num z = (fa[j] * fa[j] - conj(fa[i] * fa[i])) * r;
      if(i != j) {
        fa[j] = (fa[i] * fa[i] - conj(fa[j] * fa[j])) * r;
      }
      fa[i] = z;
    }
    fft(fa, sz);
    vector<int> res(need);
    for(int i=0; i < need; i++) {
      res[i] = fa[i].x + 0.5;
    }
    return res;
  }
}

const int LIM = 27e5;
vector<int> sps, rps;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  string s; cin >> s;

  sps.resize(LIM+1);
  rps.resize(LIM+1);

  int sum = 0;
  for(int i=0; i < (int) s.size(); i++) {
    sum += s[i] - 'a' + 1;

    sps[sum] = 1;
    rps[LIM - sum] = 1;
  }

  rps[LIM] = 1;

  vector<int> res = fft::multiply(sps, rps);

  int ans = 0;
  for(int i = LIM+1; i < (int) res.size(); i++) if(res[i]) {
    ans++;
  }
  cout << ans << endl;


  return 0;
}

