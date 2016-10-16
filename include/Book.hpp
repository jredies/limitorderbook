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
  bool operator()(const uint l, const uint r) const { return cmp(l, r); }
  std::function<bool(const uint, const uint)> cmp;
};

class PriceLevel {
  // id -> size
  std::unordered_map<std::string, uint> orders;
  uint volume;
  friend class Book;
public:
  PriceLevel() : volume(0), orders() {}
};

class Book {
  // price -> (id -> size)
  std::map<uint, PriceLevel, Compare> levels;

  // id -> price
  std::unordered_map<std::string, uint> id_price;

  const uint amount;
  uint last_timestamp;
  uint best_price;

public:
  template <typename T>
  Book(const uint amount, T comparator)
      : amount(amount), levels(Compare{comparator}), id_price(),
        last_timestamp(-1), best_price(-1) {}

  void add(Tick &t);

  bool reduce(Tick &t);

  uint bestPrice();

  opt_ts_price update_log();
};

#endif /* SRC_BOOK_H_ */
