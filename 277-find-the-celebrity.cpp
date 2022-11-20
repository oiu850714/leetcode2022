#include "headers.hpp"

bool knows(int a, int b);

// Refer to some discrete mathematics books.
// E.g. Discrete Mathematics and Its Applications (8th Edition), section 5-1,
// exercise 68.
class Solution {
public:
  // By assumption, 2 <= N <= 100.
  int findCelebrity(int N) { return findCelebrityRecursive(0, 1, N - 1); }

  // [First, Last] is close interval
  // The implementation directly reflects the structure of the proof by
  // induction.
  int findCelebrityRecursive(int Candidate, int First, int Last) {
    // Base case: #people <= 2.
    if (First == Last) {
      if (knows(Candidate, First) && !knows(First, Candidate)) {
        return First;
      } else if (!knows(Candidate, First) && knows(First, Candidate)) {
        return Candidate;
      } else {
        // Both know each other, or both do not know each other.
        return -1;
      }
    }

    // In the current problem, we need to:
    // 1. Call API once to remove one person.
    // 2. Find the celebrity of the remaining people.
    // 3. (This is important):
    //    3-1. Check whether the removed person in the current problem knows the
    //    celebrity of the remaining people.
    //    3-1. Check whether celebrity of the remaining people does NOT know the
    //    removed person in the current problem.
    auto SubProblemCandidate = -1;
    if (knows(Candidate, First)) {
      // Then Candidate is not the celebrity.
      SubProblemCandidate = findCelebrityRecursive(First, First + 1, Last);
      if (SubProblemCandidate == -1) {
        return -1;
      }
      return knows(Candidate, SubProblemCandidate) &&
                     !knows(SubProblemCandidate, Candidate)
                 ? SubProblemCandidate
                 : -1;
    } else {
      // Then First is not the celebrity.
      SubProblemCandidate = findCelebrityRecursive(Candidate, First + 1, Last);
      if (SubProblemCandidate == -1) {
        return -1;
      }
      return knows(First, SubProblemCandidate) &&
                     !knows(SubProblemCandidate, First)
                 ? SubProblemCandidate
                 : -1;
    }
  }
};
