#include "headers.hpp"
#include <memory>

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

  // For 212.
  const TrieNode *getPrefixNode(const std::string &Prefix) const {
    auto Curr = Root_.get();
    for (auto C : Prefix) {
      if (!Curr->children[C - 'a']) {
        return nullptr;
      }
      Curr = Curr->children[C - 'a'].get();
    }
    return Curr;
  }

private:
  std::unique_ptr<TrieNode> Root_;
};
