#include "parsing.hpp"

inline Tick reduce(char **c) {
  int ts = std::atoi(c[0]);
  std::string id(c[2]);

  int size = std::atoi(c[3]);

  Tick t(ts, id, size);
  return t;
}

inline Tick add(char **c) {
  int ts = std::atoi(c[0]);
  std::string id(c[2]);

  int size = std::atoi(c[5]);

  TransactionType ta;
  if (strncmp(c[3], "B", 1) == 0)
    ta = TransactionType::BUY;
  else
    ta = TransactionType::SELL;

  char* price = c[4];

  char *cent_str;
  char *dollar_str = strtok(price, ".");
  if (dollar_str != NULL)
    cent_str = strtok(NULL, ".");

  int cent = std::atoi(cent_str);
  int dollar = std::atoi(dollar_str);

  Tick t(ts, id, ta, (dollar*100 + cent), size);
  return t;
}

Tick parseLine(std::string &line) {
  char *cstr = new char[line.length() + 1];

  std::strcpy(cstr, line.c_str());
  char count = 0; // Number of tokens
  char *tokens[6];
  for (char *t = strtok(cstr, " "); t != NULL; t = strtok(NULL, " ")) {
    tokens[count] = t;
    count++;
  }

  if (count == 6) {
    return add(tokens);
  }
  if (count == 4) {
    return reduce(tokens);
  }
  return Tick::errorTick();
}

std::list<Tick> parseLines(std::vector<std::string> &lines) {
  std::list<Tick> ret;
  for (auto &l : lines) {
    ret.push_back(parseLine(l));
  }
  return ret;
}
