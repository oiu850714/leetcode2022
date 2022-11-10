#include "headers.hpp"
#include <memory>

// Modified from 208.
class Trie {
public:
  struct TrieNode {
    TrieNode() : is_word(false), children(26) {}
    std::vector<std::unique_ptr<TrieNode>> children;
    bool is_word;
  };

  Trie() : Root_{std::make_unique<TrieNode>()} {}

  void insert(const std::string &Word) {
    auto Curr = Root_.get();
    for (auto C : Word) {
      if (!Curr->children[C - 'a']) {
        Curr->children[C - 'a'] = std::make_unique<TrieNode>();
      }
      Curr = Curr->children[C - 'a'].get();
    }
    Curr->is_word = true;
  }

  bool search(const std::string &Word) const {
    auto Curr = Root_.get();
    for (auto C : Word) {
      if (!Curr->children[C - 'a']) {
        return false;
      }
      Curr = Curr->children[C - 'a'].get();
    }
    return Curr->is_word;
  }

  bool startsWith(const std::string &Prefix) const {
    auto Curr = Root_.get();
    for (auto C : Prefix) {
      if (!Curr->children[C - 'a']) {
        return false;
      }
      Curr = Curr->children[C - 'a'].get();
    }
    return true;
  }

  const TrieNode *get() const { return Root_.get(); }

private:
  std::unique_ptr<TrieNode> Root_;
};

class Solution {

public:
  std::vector<std::string> findWords(std::vector<std::vector<char>> &Board,
                                     std::vector<std::string> &Words) {
    buildTrie_(Words);
    Board_ = &Board;
    std::string Explored;
    for (int i = 0; i < Board.size(); i++) {
      for (int j = 0; j < Board[i].size(); j++) {
        backtrack_(Explored, {i, j}, Trie_.get());
      }
    }
    return std::move(Result_);
  }

private:
  Trie Trie_;
  std::vector<std::string> Result_;
  std::vector<std::vector<char>> *Board_;
  const std::vector<std::pair<int, int>> Directions_{
      {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

  void buildTrie_(const std::vector<std::string> &Words) {
    for (const auto &Word : Words) {
      Trie_.insert(Word);
    }
  }

  void backtrack_(std::string &Explored, std::pair<int, int> LastStep,
                  const Trie::TrieNode *PrefixNode) {
    auto [CurRow, CurCol] = LastStep;
    auto NewChar = (*Board_)[CurRow][CurCol];

    if (NewChar == '#') {
      return;
    }
    // This is equivalent to check that Explored + NewChar is not a prefix in
    // the Trie.
    if (PrefixNode->children[NewChar - 'a'] == nullptr) {
      return;
    }

    // Mark explored;
    (*Board_)[CurRow][CurCol] = '#';
    Explored.push_back(NewChar);

    auto NewPrefixNode = PrefixNode->children[NewChar - 'a'].get();
    if (NewPrefixNode->is_word) {
      Result_.push_back(Explored);
      NewPrefixNode->is_word =
          false; // XXX: Really a hack for preventing duplication.
                 // The effect is the same as deleting a word in the Trie.
    }

    for (auto [RowDir, ColDir] : Directions_) {
      auto NewRow = CurRow + RowDir;
      auto NewCol = CurCol + ColDir;

      if (isValidRange_(NewRow, NewCol) && (*Board_)[NewRow][NewCol] != '#') {
        backtrack_(Explored, {NewRow, NewCol}, NewPrefixNode);
      }
    }

    // Restoring states.
    (*Board_)[CurRow][CurCol] = NewChar;
    Explored.pop_back();
  }

  bool isValidRange_(int Row, int Col) {
    return Row >= 0 && Row < Board_->size() && Col >= 0 &&
           Col < (*Board_)[0].size();
  };
};
