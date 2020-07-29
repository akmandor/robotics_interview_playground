/*
##############################################
#          Coding Interview Questions
#      Created/Modified on: July 23, 2020
#           Author: Munir Jojo-Verge
##############################################
*/

/*
You are responsible for collecting signatures from all tenants of a certain
building. For each tenant, you know a period of time when he or she is at
home. You would like to collect all signatures by visiting the building as few
times as possible. The mathematical model for this problem is the following. You
are given a set of segments on a line and your goal is to mark as few points on
a line as possible so that each segment contains at least one marked point.
*/

#include <algorithm>
#include <iostream>
#include <vector>

struct time_slot {
  float start;
  float end;
  bool operator<(const time_slot& ts) const {
    return ((this->start < ts.start) ||
            (this->start == ts.start && this->end < ts.end));
  }
  bool operator=(const time_slot& ts) const {
    return ((this->start == ts.start) && (this->end == ts.end));
  }
};

std::vector<float> get_min_visits(std::vector<time_slot>& available_times) {
  std::vector<float> visits;

  unsigned i = 0, j = 0;
  unsigned n = available_times.size();
  while (i < n) {
    float visit_time =
        available_times[i].end;  // The latest i can visit this person is at the
                                 // end of their time slot

    j = i + 1;
    while ((j < n) && (available_times[j].start < visit_time)) {
      visit_time = std::min(available_times[j].end, visit_time);
      j++;
    }
    i = j;
    visits.push_back(visit_time);
  }

  return visits;
}

int main() {
  unsigned n;
  std::cout << "Enter the numner of time slots: ";
  std::cin >> n;

  std::vector<time_slot> available_times(n);
  for (unsigned i = 0; i < n; i++) {
    std::cout << "Enter the START of time slot " << i + 1 << ": ";
    std::cin >> available_times[i].start;

    std::cout << "Enter the END of time slot " << i + 1 << ": ";
    std::cin >> available_times[i].end;
  }

  std::vector<float> visits = get_min_visits(available_times);

  std::cout << "The numner of minimun visits is " << visits.size()
            << " at times: " << std::endl;
  for (unsigned i = 0; i < visits.size(); i++) {
    std::cout << visits[i] << ", ";
  }

  std::cout << std::endl;
}
