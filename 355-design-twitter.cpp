#include "headers.hpp"

class Twitter {
public:
  Twitter() {}

  void postTweet(int UserId, int TweetId) {
    OrderedIdToTweetId[OrderedId] = TweetId;
    UserFeedsOrderedId[UserId].insert(OrderedId);
    UserPosts[UserId].insert(OrderedId);
    for (auto Follower : UserFollowers[UserId]) {
      UserFeedsOrderedId[Follower].insert(OrderedId);
    }
    OrderedId++;
  }

  std::vector<int> getNewsFeed(int UserId) {
    std::vector<int> Ret;
    for (auto OrderedId : UserFeedsOrderedId[UserId]) {
      Ret.push_back(OrderedIdToTweetId[OrderedId]);
      if (Ret.size() == 10) {
        return Ret;
      }
    }
    return Ret;
  }

  void follow(int FollowerId, int FolloweeId) {
    UserFollowers[FolloweeId].insert(FollowerId);
    for (auto PostOrderedId : UserPosts[FolloweeId]) {
      UserFeedsOrderedId[FollowerId].insert(PostOrderedId);
    }
  }

  void unfollow(int FollowerId, int FolloweeId) {
    UserFollowers[FolloweeId].erase(FollowerId);
    for (auto PostOrderedId : UserPosts[FolloweeId]) {
      UserFeedsOrderedId[FollowerId].erase(PostOrderedId);
    }
  }

private:
  int OrderedId = 0;
  std::unordered_set<int> Users;
  std::unordered_map<int, int> OrderedIdToTweetId;
  std::unordered_map<int, std::set<int, std::greater<>>> UserPosts;
  std::unordered_map<int, std::unordered_set<int>> UserFollowers;
  std::unordered_map<int, std::set<int, std::greater<>>> UserFeedsOrderedId;
};
