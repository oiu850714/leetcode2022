#include "headers.hpp"

class Solution {
public:
  bool isPowerOfTwo(int N) {
    if (N <= 0) {
      return false;
    }

    // Refer to: https://youtu.be/ZRNO-ewsNcQ?t=273
    // Now N is positive.
    // By the vedio, (N & (~N + 1) (,or (N & -N),) preserves the least
    // significant 1 bit of N.
    // Note that N is a power of 2, IF AND ONLY IF, the least siginificant 1-bit
    // of N is the ONLY 1-bit of N.
    // So if we toggle that bit (by XOR N and that expression), the result will
    // be zero.
    return (N ^ (N & (~N + 1))) == 0;
  }
};