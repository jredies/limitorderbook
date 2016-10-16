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
