#include "validate.h"

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define debug(...) //ignore
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef long double ld;

// A point in 2D plane
struct Point
{
    ll x, y;
};

// A line segment with left as Point
// with smaller x value and right with
// larger x value.
struct Segment
{
    Point left, right;
};


// An event for sweep line algorithm
// An event has a point, the position
// of point (whether left or right) and
// index of point in the original input
// array of segments.
struct Event {
    ll x, y;
    bool isLeft;
    ll index;
    Event(ll x, ll y, bool l, int i) : x(x), y(y), isLeft(l), index(i) {}

    // This is for maintaining the order in set.
    bool operator<(const Event& e) const {
        if (y == e.y)return x < e.x;
        return y < e.y;
    }
};


// Given three collinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;

    return false;
}

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are collinear
// 1 --> Clockwise
// 2 --> Counterclockwise
ll orientation(Point p, Point q, Point r)
{
    // See https://www.geeksforgeeks.org/orientation-3-ordered-points/
    // for details of below formula.
    ll val = (q.y - p.y) * (r.x - q.x) -
        (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // collinear

    return (val > 0) ? 1 : 2; // clock or counterclock wise
}

bool doIntersect(Segment s1, Segment s2)
{
    Point p1 = s1.left, q1 = s1.right, p2 = s2.left, q2 = s2.right;

    // Find the four orientations needed for general and
    // special cases
    ll o1 = orientation(p1, q1, p2);
    ll o2 = orientation(p1, q1, q2);
    ll o3 = orientation(p2, q2, p1);
    ll o4 = orientation(p2, q2, q1);

    

    // Special Cases
    // p1, q1 and p2 are collinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1) && orientation(p1, p2, q1) == 0) return false;

    // p1, q1 and q2 are collinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1) && orientation(p1, q2, q1) == 0) return false;

    // p2, q2 and p1 are collinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2) && orientation(p2, p1, q2) == 0) return false;

    // p2, q2 and q1 are collinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2) && orientation(p2, q1, q2) == 0) return false;

    // General case
    if (o1 != o2 && o3 != o4)
        return true;

    return false; // Doesn't fall in any of the above cases
}

// Find predecessor of iterator in s.
multiset<Event>::iterator pred(multiset<Event>& s, multiset<Event>::iterator it) {
    return it == s.begin() ? s.end() : --it;
}

// Find successor of iterator in s.
multiset<Event>::iterator succ(multiset<Event>& s, multiset<Event>::iterator it) {
    return ++it;
}

// Returns true if any two lines intersect.
ll isIntersect(vector<Segment> arr)
{
    ll n = arr.size();

    // Pushing all points to a vector of events
    vector<Event> e;
    for (int i = 0; i < n; ++i) {
        e.push_back(Event(arr[i].left.x, arr[i].left.y, true, i));
        e.push_back(Event(arr[i].right.x, arr[i].right.y, false, i));
    }

    // Sorting all events according to x coordinate.
    stable_sort(e.begin(), e.end(), [](const Event& e1, const Event& e2) {return e1.x < e2.x; });


    // For storing active segments.
    multiset<Event> s;
    // Traversing through sorted points
    for (int i = 0; i < 2 * n; i++)
    {

        Event curr = e[i];
        int index = curr.index;

        // If current point is left of its segment
        if (curr.isLeft)
        {
            // Get above and below points
            auto next = s.lower_bound(curr);
            auto prev = pred(s, next);
            // Check if current point intersects with
            // any of its adjacent
            if (next != s.end() && doIntersect(arr[next->index], arr[index])) {
                return 1;
            }
            if (prev != s.end() && doIntersect(arr[prev->index], arr[index])) {
                return 1;
            }
            // if same line segment is there then decrease answer as it got increased twice

            // Insert current point (or event)
            s.insert(curr);
        }
        else
        {
            // Find the iterator
            auto it = s.find(Event(arr[index].left.x, arr[index].left.y, true, index));

            s.erase(it);
        }
    }

    return 0;
}

int main(int argc, char **argv) {
    init_io(argc, argv);

    int n;
    judge_in >> n;

    vector<pii> edges;
    vector<pii> points;
    rep(i,0,n-1) {
        int a, b;
        judge_in >> a >> b;
        a--; b--;
        edges.emplace_back(a,b);
    }
    rep(i,0,n)
    {
        int a,b;
        judge_in >> a >> b;
        points.emplace_back(a,b);
    }

    auto check = [&](istream& sol, feedback_function feedback){

        vi seen(n);
        vi perm(n);
        rep(i,0, n) {
            int a;
            if (!(sol >> a))
            {
                author_message("Not enough output");
                return false;
            }
            if (a < 1 || a > n)
            {
                author_message("Point out of range");
                return false;
            }

            a--;
            if (seen[a])
            {
                author_message("Outputted same point twice");
                return false;
            }
            seen[a] = 1;

            perm[a] = i;
        }

        vector<Segment> segments;
        rep(i,0,n-1)
        {
            int a,b;
            tie(a,b)=edges[i];
            Point p1;
            p1.x = points[perm[a]].first;
            p1.y = points[perm[a]].second;
            Point p2;
            p2.x = points[perm[b]].first;
            p2.y = points[perm[b]].second;
            if (p1.x > p2.x) swap(p1, p2);
            Segment s;
            s.left = p1;
            s.right = p2;
            segments.emplace_back(s);
        }
        
        if (isIntersect(segments))
        {
            author_message("Intersected");
            return false;
        }
        
        string trailing;
        if(sol >> trailing)
        {
            author_message("Outputted more than n point indices");
            return false;
        }
        return true;
    };

    bool judge = check(judge_ans, judge_error);
    bool author = check(author_out, wrong_answer);


    if (!judge)
    {
        wrong_answer("Judge failed to find solution");
    }

    if (!author) 
    {
        wrong_answer("Incorrect solution");
    }
    
    accept();
}
