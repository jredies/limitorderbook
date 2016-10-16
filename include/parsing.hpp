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

#include <algorithm>
#include <cstdlib>

std::list<Tick> parseLines(std::list<std::string> &lines);

std::string to_dollar_string(const long price);

// Gets rid of annyoing warning.
// Know issue reported at svn.boost.org/trac/boost/ticket/11886

#ifdef __GNUC__
#pragma GCC system_header
#endif
#include <boost/spirit/include/qi.hpp>

using boost::spirit::qi::double_;
using boost::spirit::qi::long_;
using boost::spirit::qi::parse;

#endif /* SRC_PARSING_H_ */
