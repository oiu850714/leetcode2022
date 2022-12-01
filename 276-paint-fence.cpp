#include "headers.hpp"

class Solution {
public:
  // I wrote the code without noticing there is actually a recurrence relation.
  // And the time is O(NK), space O(K), pitty.
  int numWays(int N, int K) {
    // Store the total #ways of paint.
    int Total = K;
    // Store the #ways of paint with the last post using kth color different
    // from the 2nd-to-last post.
    std::vector<int> DiffPost(K, 1);
    // Store the #ways of paint with the last post using kth color same as
    // the 2nd-to-last post.
    std::vector<int> SamePost(K, 0);

    for (int i = 1; i < N; i++) {
      std::vector<int> NextDiffPost(K);
      std::vector<int> NextSamePost(K);
      for (int j = 0; j < K; j++) {
        NextDiffPost[j] = Total - DiffPost[j] - SamePost[j];
        NextSamePost[j] = DiffPost[j];
      }
      DiffPost.swap(NextDiffPost);
      SamePost.swap(NextSamePost);
      Total = std::accumulate(DiffPost.begin(), DiffPost.end(), 0) +
              std::accumulate(SamePost.begin(), SamePost.end(), 0);
    }

    return Total;
  }
};
