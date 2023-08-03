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
typedef long double ld;


int main(int argc, char **argv) {
    init_io(argc, argv);

    int n, m;
    judge_in >> n >> m;

    vector<pii> spacesorig;
    rep(i,0,m) {
        int a, b;
        judge_in >> a >> b;
        spacesorig.emplace_back(a,b);
    }

    auto check = [&](istream& sol, feedback_function feedback){
        int k;
        if(!(sol >> k))
        {
            author_message("Did not output number of moves");
            feedback("Expected more output");
        }

        vector<pii> spaces = spacesorig;

        pii ret_on_error = pii(k, false); // We can't give WA if they fail here, as they still potentially have 20% score
        rep(i,0,k) {
            int a,b;
            if(!(sol >> a >> b))
            {
                author_message("Outputted too few moves");
                return ret_on_error;
            }
            for (auto x : {a,b}) if(x < 1 || x > m)
            {
                author_message("Out of bounds");
                return ret_on_error;
            }
            if (a==b)
            {
                author_message("You can't move car to same parking spot");
                return ret_on_error;
            }
            a--;
            b--;
            if (spaces[b].second!=0)
            {
                author_message("Moving to full parking spot");
                return ret_on_error;
            }
            if (spaces[a].first==0)
            {
                author_message("Trying to move car from empty parking spot");
                return ret_on_error;
            }
            int col = -1;
            if (spaces[a].second!=0)
            {
                col = spaces[a].second;
                spaces[a].second = 0;
            }
            else
            {
                col = spaces[a].first;
                spaces[a].first = 0;
            }

            
            if (spaces[b].first!=0)
            {
                if (spaces[b].first!=col)
                {
                    
                    author_message("Trying to move car to spot with different color");
                    return ret_on_error;
                }
                spaces[b].second = col;
            }
            else spaces[b].first = col;
        }

        
        bool works = 1;
        for (int i = 0; i < m; i++)
        {
            works &= spaces[i].first==spaces[i].second;
        }

        string trailing;
        if(sol >> trailing)
        {
            author_message("Outputted more than K lines of moves");
            return ret_on_error; //feedback("Trailing output");
        }
        return pii(k,works);
    };

    pii judge = check(judge_ans, judge_error);
    pii author = check(author_out, wrong_answer);


    if (get<0>(author) < get<0>(judge) || get<0>(author)>=0 && get<0>(judge)==-1)
    {
        if (get<1>(author)) judge_error("Contestant found better solution");
        else
        {
            author_message("Did not identify the correct amount of moves");
            wrong_answer("Did not identify the correct amount of moves");
        }
    }
    if (get<0>(author) > get<0>(judge)) 
    {
        author_message("Did not identify the correct amount of moves");
        wrong_answer("Did not identify the correct amount of moves");
    }
    
    // Same number of moves
    bool correctdecision = get<1>(judge)==get<1>(author);
    if (!correctdecision)
    {
        author_message("Correct number of moves, but moves are incorrect");
        accept_with_score(0.2);
    }

    accept_with_score(1.0);
}
