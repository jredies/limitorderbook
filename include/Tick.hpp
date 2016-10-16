#ifndef SRC_TICK_H_
#define SRC_TICK_H_

#include <boost/numeric/conversion/cast.hpp>
#include <iomanip>
#include <sstream>
#include <string>

enum class TransactionType { BUY, SELL };
enum class TickType { ADD, REDUCE, ERROR };
struct Tick {
  const uint timestamp;
  const std::string id;
  const TransactionType transactiontype;
  const uint price; // Price in USD Cents
  const uint size;
  const TickType type;

  // AddTick
  Tick(const uint timestamp, const std::string &id,
       const TransactionType transactiontype, const uint price, const uint size)
      : timestamp(timestamp), id(id), transactiontype(transactiontype),
        price(price), size(size), type(TickType::ADD) {}

  // ReduceTick
  Tick(const uint timestamp, const std::string &id, const uint size)
      : timestamp(timestamp), id(id), transactiontype(TransactionType::SELL),
        price(-1), size(size), type(TickType::REDUCE) {}

  Tick()
      : timestamp(0), id(""), transactiontype(TransactionType::SELL), price(0),
        size(0), type(TickType::ERROR) {}

  bool isAddTick() const;

  bool isReduceTick() const;

  bool isErrorTick() const;

  std::string toString() const;

  // ErrorTick - invalid Syntax
  static Tick errorTick() { return Tick(); }
};

std::string toDollarString(const uint price);

#endif /* SRC_TICK_H_ */
