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

//obtener numero de divisores p1^a1 * p2^a2 *... -> nrodivisores = (a1+1) * (a2+2) * ...

bitset<N> is;
vector<int> prime;
void sieve(){
   is.set();
   is[0] = is[1] = 0;
   for(int i = 2 ;i < N ;i++){
      if(is[i] == 0) continue;
      prime.push_back(i);
      for(int j = i+i ;j < N ;j+=i) is[j] = 0;
   }
}

int main(){
   sieve();
   int nro_divisors = 0;
   int triangle = 0;
   for(int i = 1 ; nro_divisors < 500 ;i++){
      triangle += i;

      //get nrodivisors
      
      nro_divisors = 1;
      int cp = triangle;
      for(int p : prime){
         if(cp == 1) break;

         int cont = 0;
         while(cp > 1 && cp%p == 0){
            cont++;
            cp = cp / p;
         }
         
         nro_divisors *= (cont + 1);
      }

      if(nro_divisors >= 500){
         er(i,triangle,nro_divisors);
      }
   }
   return 0;
}