#include "headers.hpp"
#include <memory>

#include <memory>

// Skip search utils; just used to construct Trie nodes structure.
class Trie {
public:
  struct TrieNode {
    TrieNode() : IsWord_(false), Children_(26) {}
    bool IsWord_;
    std::vector<std::unique_ptr<TrieNode>> Children_;
  };

  Trie() : Root_(std::make_unique<TrieNode>()) {}

  void insert(const std::string &Word) {
    auto Curr = Root_.get();
    for (auto C : Word) {
      if (!Curr->Children_[C - 'a']) {
        Curr->Children_[C - 'a'] = std::make_unique<TrieNode>();
      }
      Curr = Curr->Children_[C - 'a'].get();
    }
    Curr->IsWord_ = true;
  }

  const TrieNode *getRootTrieNode() const noexcept { return Root_.get(); }

private:
  std::unique_ptr<TrieNode> Root_;
};

class Solution {
  using BoardTy = std::vector<std::vector<char>>;
  using WordsTy = std::vector<std::string>;

public:
  WordsTy findWords(BoardTy &Board, const WordsTy &Words) {
    buildTrie_(Words);
    Board_ = Board; // Board is really small, just copy.
    for (int Row = 0; Row < Board_.size(); Row++) {
      for (int Col = 0; Col < Board_[0].size(); Col++) {
        std::string CurrChars;
        backtrack_(CurrChars, Row, Col, Trie_.getRootTrieNode());
      }
    }
    return std::move(Result_);
  }

private:
  Trie Trie_;
  BoardTy Board_;
  WordsTy Result_;

  void buildTrie_(const WordsTy &Words) {
    for (const auto &Word : Words) {
      Trie_.insert(Word);
    }
  }

  void backtrack_(std::string &CurrWord, const int Row, const int Col,
                  const Trie::TrieNode *PrefixTrieNode) {
    // Explored.
    if (Board_[Row][Col] == '#') {
      return;
    }

    auto NewChar = Board_[Row][Col];
    // It's impossible the prefix node itself is nullptr.
    assert(PrefixTrieNode);
    auto &ChildNode = PrefixTrieNode->Children_[NewChar - 'a'];
    if (!ChildNode) {
      // CurrWord + NewChar is not in Trie.
      return;
    }

    CurrWord.push_back(NewChar);
    Board_[Row][Col] = '#';
    if (ChildNode->IsWord_) {
      Result_.push_back(CurrWord);
      // Effectively delete the word in Trie to prevent duplication.
      ChildNode->IsWord_ = false;
    }

    for (auto [RowDir, ColDir] : Directions_) {
      auto NewRow = RowDir + Row;
      auto NewCol = ColDir + Col;
      if (!isValidRange_(NewRow, NewCol)) {
        continue;
      }
      backtrack_(CurrWord, NewRow, NewCol, ChildNode.get());
    }
    Board_[Row][Col] = NewChar;
    CurrWord.pop_back();
  }

  bool isValidRange_(int Row, int Col) const noexcept {
    return Row >= 0 && Row < Board_.size() && Col >= 0 &&
           Col < Board_[0].size();
  };

  const std::vector<std::pair<int, int>> Directions_{
      {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};
