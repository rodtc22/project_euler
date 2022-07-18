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

#define er(args...) { cout << "DBG: " << #args << " = {"; printe(args); cout << "}\n"; } 
/*SUMA DE NUMEROS GRANDES CON MEDIANTE STRING*/

void fillzeros(string &s, int n){
   if(s.size() < n){
      string y = s;
      s.assign(n-s.size(),'0');
      s.append(y);
   }
}

string sumar(string a, string& b){
   int len = max(a.size(), b.size());
   string ans = "";

   fillzeros(a,len); fillzeros(b,len);

   int ac = 0; // acarreo
   for(int i = len -1 ; i >= 0 ;i--){
      int x = a[i]-'0', y = b[i]-'0';

      int z = x + y + ac;
      ans.push_back((z%10)+'0');
      ac = z / 10;
   }
   if(ac) ans.push_back(ac + '0');
   reverse(ans.begin(),ans.end());

   return ans;
}

int main(){
   string sum = "0";
   string x;
   while(cin >> x){
      sum = sumar(sum,x);
      er(sum);
   }

   cout << sum.substr(0,10) << endl;
   return 0;
}
