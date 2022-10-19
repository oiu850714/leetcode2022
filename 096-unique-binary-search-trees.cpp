#include "headers.hpp"

class Solution {
public:
  int numTrees(int N) {
    std::vector<int> DPTable(N + 1);
    DPTable[0] = 1; // There is only one BST with no nodes.
    DPTable[1] = 1; // There is only one BST with one node.

    for (int NumNodesOfBST = 2; NumNodesOfBST <= N; NumNodesOfBST++) {
      for (int RootNode = 1; RootNode <= NumNodesOfBST; RootNode++) {
        auto NumLeftTreeNodes = RootNode - 1;
        auto NumRightTreeNodes = NumNodesOfBST - RootNode;
        DPTable[NumNodesOfBST] +=
            DPTable[NumLeftTreeNodes] * DPTable[NumRightTreeNodes];
      }
    }
    return DPTable[N];
  }
};