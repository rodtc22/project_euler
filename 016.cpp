#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <climits>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
using namespace std;

template <typename A,typename B> ostream& operator <<(ostream& os, pair<A,B>& p) { return os << "(" << p.first << ", " << p.second << ")";}
template <typename T> ostream& operator <<(ostream& os, vector<T>& v) {    os << "[" ;    for(int i = 0 ;i < v.size(); i++){      if(i) os <<", ";      os <<v[i];    }    os << "]";return os;}
template <typename T> istream& operator >>(istream& is, vector<T>& v){ for(auto &x : v) is >> x; return is;}
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

typedef long long ll;
typedef pair<int,int> pii;
const int inf = 2e9;
const int mod = 1e9+7;
const int N = 2e6;

void printe(){}
template <typename H, typename ...T>
void printe(H x, T... y){
   cout << ", " << x;
   printe(y...);
}

#define er(args...) { cout << "DBG: " << #args << " {"; printe(args); cout << "}\n"; } 

string bytwo(string &s){
   int n = s.size();
   string ans = "";
   int res = 0;
   for(int i = n-1 ;i >= 0 ;i--){
      int dig = s[i] - '0';
      dig <<= 1;
      dig += res;
      ans.push_back((dig%10)+'0');
      res = dig / 10;
   }
   if(res != 0) ans.push_back(res + '0');
   reverse(ans.begin(),ans.end());
   return ans;
}

int main(){
   string nro = "1";
   for(int i = 1 ; i <= 1000 ;i++){
      nro = bytwo(nro);
   }
   int acu = 0;
   for(char c : nro) acu += (c-'0');
      cout << acu << endl;
   return 0;
}