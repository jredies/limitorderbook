#include "Book.hpp"
#include "Tick.hpp"
#include "parsing.hpp"

#include <boost/lexical_cast.hpp>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <set>
#include <string>

#define DEBUG false

std::chrono::time_point<std::chrono::system_clock> start, stop;

void startStopWatch();
void stopStopWatch(std::string description);

void simulate(std::list<Tick> &ticks, int target_size);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Expected exactly one argument" << std::endl;
    std::cerr << "Syntax: ./pricer target-size" << std::endl;
    exit(1);
  }
  auto target_size = boost::lexical_cast<int>(argv[1]);

  std::ios::sync_with_stdio(false);

  std::vector<std::string> lines;
  std::string s;

  startStopWatch();
#define MAX_LINE 120
  char input_line[MAX_LINE];
  char *result;

  while ((result = fgets(input_line, MAX_LINE, stdin)) != NULL)
    lines.push_back(std::string(result));

  stopStopWatch("Read");

  startStopWatch();
  auto ticks = parseLines(lines);
  stopStopWatch("Parsing");

  startStopWatch();
  simulate(ticks, target_size);
  stopStopWatch("Simulation");

  return 0;
}

void simulate(std::list<Tick> &ticks, int target_size) {
  Book bid(target_size, std::greater<int>{});
  Book ask(target_size, std::less<int>{});

  for (auto &t : ticks) {
    if (t.isAddTick()) {
      if (t.transactiontype == TransactionType::BUY) {
        bid.add(t);
      }
      if (t.transactiontype == TransactionType::SELL) {
        ask.add(t);
      }
    } else if (t.isReduceTick()) {
      bool ask_reduced = ask.reduce(t);
      bool bid_reduced = bid.reduce(t);
      if (ask_reduced && bid_reduced) {
        std::cerr << "Warning: Should not be in both books!" << std::endl;
      } else if (!ask_reduced & !bid_reduced) {
        std::cerr << "Warning: Should be in one of the books!" << std::endl;
      }
    } else if (t.isErrorTick()) {
      std::cerr << "Warning: Invald line!" << std::endl;
    }

    if (auto ts_price = ask.update_log()) {
      if (!DEBUG) {
        std::cout << ts_price->first << " B " << ts_price->second << std::endl;
      }
    }

    if (auto ts_price = bid.update_log()) {
      if (!DEBUG) {
        std::cout << ts_price->first << " S " << ts_price->second << std::endl;
      }
    }
  }
}

inline void startStopWatch() {
  if (DEBUG)
    start = std::chrono::system_clock::now();
}

inline void stopStopWatch(std::string description) {
  if (DEBUG) {
    stop = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = stop - start;
    std::cout << description << " " << elapsed_seconds.count() << " s"
              << std::endl;
  }
}
