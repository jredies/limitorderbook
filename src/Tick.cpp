#include "Tick.hpp"

bool Tick::isAddTick() const { return price >= 0; }

bool Tick::isReduceTick() const { return price == -1; }

bool Tick::isErrorTick() const { return price == -2; }

std::string toDollarString(const long price) {
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
