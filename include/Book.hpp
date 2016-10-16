#ifndef SRC_BOOK_H_
#define SRC_BOOK_H_

#include "Tick.hpp"

#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <utility>

#include <boost/numeric/conversion/cast.hpp>
#include <boost/optional.hpp>

// optional <timestamp, price>
typedef boost::optional<std::pair<std::string, std::string>> opt_ts_price;

struct Compare {
  bool operator()(const long l, const long r) const { return cmp(l, r); }
  std::function<bool(const long, const long)> cmp;
};

class PriceLevel {
  // id -> size
  std::unordered_map<std::string, long> orders;
  long volume;
  friend class Book;
public:
  PriceLevel() : volume(0), orders() {}
};

class Book {
  // price -> (id -> size)
  std::map<long, PriceLevel, Compare> levels;

  // id -> price
  std::unordered_map<std::string, long> id_price;

  const long amount;
  long last_timestamp;
  long best_price;

public:
  template <typename T>
  Book(const long amount, T comparator)
      : amount(amount), levels(Compare{comparator}), id_price(),
        last_timestamp(-1), best_price(-1) {}

  void add(Tick &t);

  bool reduce(Tick &t);

  long bestPrice();

  opt_ts_price update_log();
};

#endif /* SRC_BOOK_H_ */
