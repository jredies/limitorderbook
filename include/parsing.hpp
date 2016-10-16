#ifndef SRC_PARSING_H_
#define SRC_PARSING_H_

#pragma system_header

#include "Tick.hpp"
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
#include <iostream>
#include <list>
#include <memory>
#include <string>
#include <vector>
#include <future>
#include <thread>

#include <algorithm>
#include <cstdlib>

std::list<Tick> parseLines(std::vector<std::string> &lines);

std::string to_dollar_string(const uint price);

// Gets rid of annyoing warning.
// Know issue reported at svn.boost.org/trac/boost/ticket/11886

#ifdef __GNUC__
#pragma GCC system_header
#endif
#include <boost/spirit/include/qi.hpp>

using boost::spirit::qi::double_;
using boost::spirit::qi::uint_;
using boost::spirit::qi::parse;

#endif /* SRC_PARSING_H_ */
