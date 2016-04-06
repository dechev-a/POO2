#ifndef SIMPLIFICATION_HPP_
#define SIMPLIFICATION_HPP_

#include "fraction.hpp"
#include <vector>

fraction	simplification(fraction f);
std::vector<int>	diviseur(int n);
bool		search(int x, std::vector<int> tab);

#endif
