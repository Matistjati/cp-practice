#include "validate.h"

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define debug(...) //ignore
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long double ld;

#define repe(i, container) for (auto& i : container)

int main(int argc, char **argv) {
  init_io(argc, argv);

  int n, t;
  judge_in >> n >> t;
  vector<int> nums(n);
  rep(i,0,n) judge_in >> nums[i];

  auto check = [&](istream& sol, feedback_function feedback){
    string ans;
    if(!(sol >> ans)) feedback("Expected more output");
    for (char& c : ans) c = (char)toupper(c);
    if(ans != "NO" && ans != "YES")
      feedback("Answer \'%s\' is not {YES|NO}", ans.c_str());

    if(ans == "NO") {
      string trailing;
      if(sol >> trailing) feedback("Trailing output");
      return false;
    }
	string subset;
	if (!(sol >> subset)) feedback("Expected more output");
    if (subset.size() != n) feedback("Output was not of length n");
	int sum = 0;
	rep(i,0,n)
	{
		if (subset[i]!='0'&&subset[i]!='1') feedback("Output contains character other than {0|1}");
		if (subset[i]=='1') sum += nums[i];
	}

	if (sum!=t) feedback("Sum of subset is not T");

    string trailing;
    if(sol >> trailing) feedback("Trailing output");
    return true;
  };

  bool judge_found_sol = check(judge_ans, judge_error);
  bool contestant_found_sol = check(author_out, wrong_answer);

  if(!judge_found_sol && contestant_found_sol)
    judge_error("NO! Contestant found a solution, but judge says none exists");

  if(judge_found_sol && !contestant_found_sol)
    wrong_answer("Solution exists, but contestant did not find it");

  accept();
}
