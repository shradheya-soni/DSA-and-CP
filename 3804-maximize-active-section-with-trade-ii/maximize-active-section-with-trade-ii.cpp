#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct node {
    int val;
    node() {
        val = 0;
    }
    node(int v) {
        val = v;
    }
};

vector<node> seg;
vector<int> arr;

node merge(node left, node right) {
    return node(max(left.val, right.val));
}

void build_tree(int i, int j, vector<int>& a, int ind) {
    if (i == j) {
        seg[ind].val = a[i];
        return;
    }
    int mid = (i + j) / 2;
    int left = 2 * ind + 1;
    int right = 2 * ind + 2;
    build_tree(i, mid, a, left);
    build_tree(mid + 1, j, a, right);
    seg[ind] = merge(seg[left], seg[right]);
}

node query_tree(int i, int j, int l, int r, int ind) {
    if (r < i || j < l) return node(0);
    if (l <= i && j <= r) return seg[ind];
    int mid = (i + j) / 2;
    node left = query_tree(i, mid, l, r, ind * 2 + 1);
    node right = query_tree(mid + 1, j, l, r, ind * 2 + 2);
    return merge(left, right);
}

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        

        int total_ones = 0;
        for (char c : s) {
            if (c == '1') total_ones++;
        }

        vector<int> start;
        vector<int> finish;
        vector<int> len;
        
        int i = 0;
        while (i < n) {
            if (s[i] == '0') {
                int st = i;
                while (i < n && s[i] == '0') {
                    i++;
                }
                start.push_back(st);
                finish.push_back(i - 1);
                len.push_back(i - st);
            } else {
                i++;
            }
        }

        int m = start.size();
        vector<int> ans;

        // If there are fewer than 2 blocks of zeros in the whole string,
        // we can never merge two blocks. Just return the total '1's.
        if (m < 2) {
            for(int k = 0; k < queries.size(); k++) {
                ans.push_back(total_ones);
            }
            return ans;
        }

        // 3. Build Segment Tree for the sum of lengths of adjacent '0' blocks
        int N = m - 1; // Number of adjacent pairs
        arr.assign(N, 0);
        for (int k = 0; k < N; k++) {
            arr[k] = len[k] + len[k+1];
        }
        
        seg.assign(4 * N, node());
        build_tree(0, N - 1, arr, 0);

        // 4. Process each query
        for(auto& q : queries) {
            int l = q[0];
            int r = q[1];
            
            int maxPairSum = 0;

            // Find the blocks that intersect with the query range [l, r]
            int low = lower_bound(finish.begin(), finish.end(), l) - finish.begin();
            int high = upper_bound(start.begin(), start.end(), r) - start.begin() - 1;

            if (low <= high) {
                // Calculate lengths of the boundary blocks, restricted to [l, r]
                int firstLen = min(finish[low], r) - max(start[low], l) + 1;
                int lastLen = min(finish[high], r) - max(start[high], l) + 1;

                if (low == high) {
                    // Only one block of '0's intersects the query. No pairs to merge.
                    maxPairSum = 0; 
                } 
                else if (high - low == 1) {
                    // Exactly two blocks intersect the query. They are adjacent.
                    maxPairSum = firstLen + lastLen;
                } 
                else {
                    // More than two blocks intersect. 
                    int pair1 = firstLen + len[low + 1];
                    int pair2 = len[high - 1] + lastLen;
                    
                    int rmqMax = 0;
                    if (low + 1 <= high - 2) {
                        rmqMax = query_tree(0, N - 1, low + 1, high - 2, 0).val;
                    }
                    
                    maxPairSum = max({pair1, pair2, rmqMax});
                }
            }
            
            // Add the gain from the trade to the TOTAL '1's in the string
            ans.push_back(total_ones + maxPairSum);
        }

        return ans;
    }
};