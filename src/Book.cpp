#include "Book.hpp"

long Book::bestPrice() {
  long left = amount;
  long best_price = 0;

  for (auto &l : levels) {
    long volume = l.second.volume;
    long lot_price = l.first;
    if (left - volume == 0) {
      best_price += lot_price * volume;
      return best_price;
    } else if (left - volume > 0) {
      best_price += lot_price * volume;
      left -= volume;
    } else if (((int)left - (int)volume) < 0) {
      best_price += lot_price * left;
      return best_price;
    }
  }
  return -1;
}

void Book::add(Tick &t) {
  last_timestamp = t.timestamp;

  id_price[t.id] = t.price;
  auto it = levels.find(t.price);

  if (it != levels.end()) {
    it->second.volume += t.size;
    it->second.orders[t.id] = t.size;
  } else { // PriceLevel doesn't exist
    PriceLevel l;
    l.volume = t.size;
    l.orders[t.id] = t.size;
    levels[t.price] = l;
  }
}

bool Book::reduce(Tick &t) {
  last_timestamp = t.timestamp;

  long price;
  auto it_price = id_price.find(t.id);
  if (it_price == id_price.end())
    return false;
  else
    price = it_price->second;

  auto it_level = levels.find(price);

  if (it_level != levels.end()) {
    PriceLevel &level = it_level->second;

    auto it_order = level.orders.find(t.id);

    if (it_order != level.orders.end()) {
      long diff = it_order->second - t.size;
      if (diff > 0) {
        it_order->second -= t.size;
        level.volume -= t.size;
      } else if (diff <= 0) {
        // Never remove more from volume than the orignal order size
        level.volume -= it_order->second;
        level.orders.erase(it_order);
        id_price.erase(t.id);
      }
      if (level.orders.size() == 0 && level.volume == 0) {
        levels.erase(it_level);
      }

      return true;
    } else {
      std::cerr << "Warning: Couldn't find Order for ID!" << std::endl;
    }
  } else {
    std::cerr << "Warning: Can't find price for ID. Data structure "
                 "inconsistent. This "
                 "should not happen!"
              << std::endl;
  }
  return false;
}

opt_ts_price Book::update_log() {
  long new_best_price = bestPrice();
  if (best_price != new_best_price) {
    std::string ts_string = std::to_string(last_timestamp);
    std::string new_best_price_string;
    if (new_best_price == -1)
      new_best_price_string = "NA";
    else
      new_best_price_string = toDollarString(new_best_price);
    best_price = new_best_price;
    return std::make_pair(ts_string, new_best_price_string);
  } else {
    best_price = new_best_price;
    return boost::none;
  }
}
