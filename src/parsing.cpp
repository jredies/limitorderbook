#include "parsing.hpp"

inline long convertToCents(std::string dollar) {
    std::vector<std::string> parts;
    parts.reserve(2);
    boost::split(parts, dollar, boost::is_any_of("."), boost::token_compress_on);
    long left;
    if (!parse(parts[0].begin(), parts[0].end(), long_, left))
      return -1;
    long right;
    if (!parse(parts[1].begin(), parts[1].end(), long_, right))
      return -1;
    return left * 100 + right;
}

Tick parseLine(std::string &line) {
  std::vector<std::string> words;
  words.reserve(4);
  boost::split(words, line, boost::is_any_of(" "), boost::token_compress_on);

  long timestamp;
  if (!parse(words[0].begin(), words[0].end(), long_, timestamp))
    return Tick::errorTick();

  auto type = words[1];
  auto id = words[2];

  if (type.compare("A") == 0 && words.size() == 6) { // ADD
    TransactionType transactiontype = words[3].compare("B") == 0 ? TransactionType::BUY : TransactionType::SELL;

    long price = convertToCents(words[4]);
    if (price == -1)
      return Tick::errorTick();

    long size;
    if (!parse(words[5].begin(), words[5].end(), long_, size))
      return Tick::errorTick();
    return Tick(timestamp, id, transactiontype, price, size);
  } else if (type.compare("R") == 0 && words.size() == 4) { // REDUCE
    long size;
    if (!parse(words[3].begin(), words[3].end(), long_, size))
      return Tick::errorTick();
    return Tick(timestamp, id, size);
  }
  return Tick::errorTick();
}


std::list<Tick> parseLines(std::list<std::string> &lines) {
  std::list<Tick> ret;
  for (auto &l : lines) {
    ret.push_back(parseLine(l));
  }
  return ret;
}
