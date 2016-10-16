#include "Tick.hpp"

bool Tick::isAddTick() const { return type == TickType::ADD; }

bool Tick::isReduceTick() const { return type == TickType::REDUCE; }

bool Tick::isErrorTick() const { return type == TickType::ERROR; }

std::string toDollarString(const uint price) {
  std::stringstream ss;
  double d = boost::numeric_cast<double>(price) / 100.0;
  ss << std::fixed << std::setprecision(2) << d;
  return ss.str();
}

std::string reduce_toString(const Tick& t) {
  return std::to_string(t.timestamp) + " R " + t.id + " " +
         std::to_string(t.size);
}

std::string add_toString(const Tick& t) {
  auto ret = std::to_string(t.timestamp) + " A " + t.id + " ";
  if (t.transactiontype == TransactionType::BUY)
    ret += "B";
  else
    ret += "S";
  ret += " " + toDollarString(t.price);
  ret += " " + std::to_string(t.size);
  return ret;
}

std::string Tick::toString() const {
  if (isAddTick())
    return add_toString(*this);
  else
    return reduce_toString(*this);
}
