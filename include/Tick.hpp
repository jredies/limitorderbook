#ifndef SRC_TICK_H_
#define SRC_TICK_H_

#include <string>
#include <sstream>
#include <iomanip>
#include <boost/numeric/conversion/cast.hpp>

enum class TransactionType {BUY, SELL};

struct Tick {
  const long timestamp;
  const bool add;
  const std::string id;
  const TransactionType transactiontype;
  const long price; // Price in USD Cents
  const long size;

  // AddTick
  Tick(const long timestamp, const std::string &id, const TransactionType transactiontype,
       const long price, const long size)
      : timestamp(timestamp), add(true), id(id), transactiontype(transactiontype), price(price),
        size(size) {}

  // ReduceTick
  Tick(const long timestamp, const std::string &id, const long size)
      : timestamp(timestamp), add(false), id(id), transactiontype(TransactionType::SELL), price(-1),
        size(size) {}

  bool isAddTick() const;

  bool isReduceTick() const;

  bool isErrorTick() const;

  std::string toString() const;

  // ErrorTick - invalid Syntax
  static Tick errorTick() { return Tick(0, " ", TransactionType::SELL, -2, 0); }
};

std::string toDollarString(const long price);

#endif /* SRC_TICK_H_ */
