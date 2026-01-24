#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
    struct Segment {
        int count = 0;
        double length = 0;
    };

    vector<Segment> tree;
    vector<int> coords;

    void update(int node, int start, int end, int l, int r, int val) {
        if (l <= start && end <= r) {
            tree[node].count += val;
        } else {
            int mid = (start + end) / 2;
            if (l <= mid) update(2 * node, start, mid, l, r, val);
            if (r > mid) update(2 * node + 1, mid + 1, end, l, r, val);
        }
        
        if (tree[node].count > 0) {
            tree[node].length = coords[end + 1] - coords[start];
        } else if (start != end) {
            tree[node].length = tree[2 * node].length + tree[2 * node + 1].length;
        } else {
            tree[node].length = 0;
        }
    }

public:
    double separateSquares(vector<vector<int>>& squares) {
        struct Event {
            int y, x1, x2, type;
            bool operator<(const Event& other) const { return y < other.y; }
        };

        vector<Event> events;
        vector<int> x_coords;
        for (auto& s : squares) {
            int x = s[0], y = s[1], l = s[2];
            events.push_back({y, x, x + l, 1});
            events.push_back({y + l, x, x + l, -1});
            x_coords.push_back(x);
            x_coords.push_back(x + l);
        }

        sort(events.begin(), events.end());
        sort(x_coords.begin(), x_coords.end());
        x_coords.erase(unique(x_coords.begin(), x_coords.end()), x_coords.end());
        coords = x_coords;

        int m = coords.size();
        tree.assign(4 * m, {0, 0});

        auto get_idx = [&](int val) {
            return lower_bound(coords.begin(), coords.end(), val) - coords.begin();
        };

        // First pass: Calculate Total Union Area
        double totalArea = 0;
        for (int i = 0; i < events.size() - 1; ++i) {
            update(1, 0, m - 2, get_idx(events[i].x1), get_idx(events[i].x2) - 1, events[i].type);
            totalArea += (double)tree[1].length * (events[i+1].y - events[i].y);
        }

        // Second pass: Find the y-level where area is totalArea / 2
        tree.assign(4 * m, {0, 0});
        double currentArea = 0;
        double target = totalArea / 2.0;

        for (int i = 0; i < events.size() - 1; ++i) {
            update(1, 0, m - 2, get_idx(events[i].x1), get_idx(events[i].x2) - 1, events[i].type);
            double nextDeltaArea = (double)tree[1].length * (events[i+1].y - events[i].y);
            
            if (currentArea + nextDeltaArea >= target - 1e-9) {
                return events[i].y + (target - currentArea) / tree[1].length;
            }
            currentArea += nextDeltaArea;
        }

        return events.back().y;
    }
};