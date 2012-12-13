#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

struct cc{string s; long long c;};

bool operator< (const cc& a, const cc& b){return a.c<b.c;}

class AlternateColors {
public:
  string getColor(long long r, long long g, long long b, long long k) {
		vector<cc> vc,vcs;
		cc ccr,ccg,ccb;
		ccr.s="RED";ccr.c=r;
		ccg.s="GREEN";ccg.c=g;
		ccb.s="BLUE";ccb.c=b;
		vc.push_back(ccr);
		vc.push_back(ccg);
		vc.push_back(ccb);
		vcs=vc;
		stable_sort(vcs.begin(),vcs.end());
		long long re;
		if(k<=vcs[0].c*3){
			re=k%3-1;
			if(re<0) re+=3;
			return vc[re].s;
		}
		else if(k<=(vcs[0].c+vcs[1].c*2)){
			re=k-vcs[0].c*3;
			re=re%2-1;
			if(re<0) re+=2;
			vector<int> rem;
			for(int i=0;i<3;i++){
				if(vcs[0].s!=vc[i].s){
					rem.push_back(i);
				}
			}
			return vc[rem[re]].s;
		}
		else return vcs[2].s;
	}
};
