#include "headers.hpp"

class Solution {
  struct Job {
    int StartTime;
    int EndTime;
    int Profit;

    bool operator<(const Job &Other) const {
      return StartTime < Other.StartTime;
    }
  };

  auto toJobs_(const std::vector<int> &StartTime,
               const std::vector<int> &EndTime,
               const std::vector<int> &Profit) {
    std::vector<Job> Jobs(Profit.size());
    for (int CurrJob = 0; CurrJob < Jobs.size(); ++CurrJob) {
      Jobs[CurrJob] = {StartTime[CurrJob], EndTime[CurrJob], Profit[CurrJob]};
    }
    std::sort(Jobs.begin(), Jobs.end());
    return Jobs;
  }

public:
  int jobScheduling(const std::vector<int> &StartTime,
                    const std::vector<int> &EndTime,
                    const std::vector<int> &Profit) {
    auto Jobs = toJobs_(StartTime, EndTime, Profit);
    std::vector<int> DPTable(Jobs.size());

    // Base case
    DPTable.back() = Jobs.back().Profit;
    for (int CurrJob = Jobs.size() - 2; CurrJob >= 0; CurrJob--) {
      auto Subproblem1 = DPTable[CurrJob + 1];
      auto PostValidJob = getValidPostJob_(CurrJob, Jobs);
      auto Subproblem2 = Jobs[CurrJob].Profit +
                         (PostValidJob != -1 ? DPTable[PostValidJob] : 0);
      DPTable[CurrJob] = std::max(Subproblem1, Subproblem2);
    }
    return DPTable.front();
  }

  int getValidPostJob_(int CurrJob, const std::vector<Job> &Jobs) {
    // Find the neareast nonoverlapping job of the current job.
    auto L = std::lower_bound(
        Jobs.begin() + CurrJob, Jobs.end(), Jobs[CurrJob].EndTime,
        [](const Job &J, const auto Time) { return J.StartTime < Time; });
    if (L == Jobs.end()) {
      return -1;
    }
    return L - Jobs.begin();
  }
};
