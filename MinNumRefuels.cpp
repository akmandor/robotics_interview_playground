/*
##############################################
#          Coding Interview Questions
#      Created/Modified on: Jun 9, 2020
#           Author: Munir Jojo-Verge
##############################################
*/
/*
 As the input, we have a car which can travel at most L kilometers, where L is a
 parameter if it's filled up to full tank. We have a source and destination, A
 and B, and we have n gas station at distances from x1 to xn in kilometers, from
 A along the path from A to B. And we need to output the minimum number of
 refills to get from A to B, not counting the initial refill at A.
*/
#include <iostream>
#include <vector>

size_t min_refuels(const std::vector<size_t>& stations, size_t n, size_t L) {
  size_t last_station{0};
  size_t curr_station{0};
  size_t num_refuels{0};
  while (curr_station < n - 1) {
    last_station = curr_station;
    while ((curr_station < n - 1) &&
           (stations[curr_station + 1] - stations[last_station] <= L)) {
      curr_station++;
    }

    if (curr_station == last_station) {
      return 0;
    }

    if (curr_station < n - 1) {
      num_refuels++;
    }
  }
  return num_refuels;
}

int main() {
  size_t L;
  //   std::cout << "What's the total range your can travel with a full tank in
  //   Km "
  //                "(integers only)?: ";
  //   std::cin >> L;
  //   std::cout << std::endl;

  size_t num_stations;
  num_stations = 5;
  //   std::cout << "Enter the num of gas stations: ";
  //   std::cin >> num_stations;
  //   std::cout << std::endl;

  std::vector<size_t> stations(num_stations, 0);
  //   size_t distance;
  //   std::cout << "Enter the distance of each gas station from the origin (Km)
  //   "
  //                "(integers only): "
  //             << std::endl;
  //   for (size_t i = 0; i < num_stations; i++) {
  //     std::cout << "Distance from origin to gas station " << i + 1 << ": "
  //               << std::endl;
  //     std::cin >> stations[i];
  //   }

  L = 400;

  stations[0] = 0;
  stations[1] = 250;
  stations[2] = 400;
  stations[3] = 600;
  stations[4] = 850;
  size_t min = min_refuels(stations, num_stations, L);
  std::cout << "Min number of refuels is: " << min << std::endl;

  return 0;
}