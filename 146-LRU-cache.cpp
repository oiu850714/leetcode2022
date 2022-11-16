#include "headers.hpp"

// XXX: Warning: without custom hash, the following implementation almost always
// TLE.
// But the implementation is still TLE sometimes...
// Refer to:
// https://stackoverflow.com/questions/38304877/why-stdhashint-seems-to-be-identity-function
// https://create.stephan-brumme.com/fnv-hash/
class LRUCache {
  struct CacheEntry {
    int Key;
    int Value;
  };

  // FNV1a
  struct MyHash {

    const static uint32_t Prime = 0x01000193; //   16777619
    const static uint32_t Seed = 0x811C9DC5;  // 2166136261
    /// hash a single byte
    inline uint32_t fnv1a(unsigned char oneByte, uint32_t hash = Seed) const {
      return (oneByte ^ hash) * Prime;
    }

    /// hash a 32 bit integer (four bytes)
    inline uint32_t fnv1a(uint32_t fourBytes, uint32_t hash = Seed) const {
      const unsigned char *ptr = (const unsigned char *)&fourBytes;
      hash = fnv1a(*ptr++, hash);
      hash = fnv1a(*ptr++, hash);
      hash = fnv1a(*ptr++, hash);
      return fnv1a(*ptr, hash);
    }

    std::size_t operator()(int i) const { return fnv1a((uint32_t)i); }
  };

public:
  LRUCache(int Capacity) : Capacity_(Capacity) {}

  int get(int Key) {
    if (auto It = KeyToListEntry.find(Key); It != KeyToListEntry.end()) {

      // Move the cache entry to the end.
      // Effectively make the entry newest.
      auto CacheEntryIt = It->second;
      CacheEntries.splice(CacheEntries.end(), CacheEntries, CacheEntryIt);

      return CacheEntryIt->Value;
    } else {
      return -1;
    }
  }

  void put(int Key, int Value) {
    if (auto It = KeyToListEntry.find(Key); It != KeyToListEntry.end()) {
      // Like get(), move the cache entry to the end.
      // Effectively make the entry newest.
      auto CacheEntryIt = It->second;
      CacheEntries.splice(CacheEntries.end(), CacheEntries, CacheEntryIt);

      // But also need to update the value.
      CacheEntryIt->Value = Value;
      return;
    } else {
      if (KeyToListEntry.size() == Capacity_) {
        auto [Key, Value] = *CacheEntries.begin();
        // Remove LRU entry.
        KeyToListEntry.erase(Key);
        CacheEntries.pop_front();
      }
      CacheEntries.push_back({Key, Value});
      // The list iterator is BIDIRECTIONAL.
      auto NewEntryIt = --CacheEntries.end();
      KeyToListEntry[Key] = NewEntryIt;
      return;
    }
  }

private:
  const int Capacity_;

  // Key, LRU Entry
  std::unordered_map<int, std::list<CacheEntry>::iterator, MyHash>
      KeyToListEntry;

  std::list<CacheEntry> CacheEntries;
};
