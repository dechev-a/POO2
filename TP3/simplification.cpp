#include "simplification.hpp"

std::vector<int>	diviseur(int n)
{
  std::vector<int> divide;
  for(int i = 1;i <= n;i++)
    {
      if ((n % i) == 0)
	divide.push_back(i);
    }
  return (divide);
}

bool		search(int x, std::vector<int> tab)
{
  for (int i = tab.size() - 1; i >= 0; i--)
    {
      if (tab[i] == x)
	return (true);
    }
  return (false);
}

fraction	simplification(fraction f)
{
  std::vector<int>	divide_numerator = diviseur(f.get_numerator());
  std::vector<int>	divide_denominator = diviseur(f.get_denominator());
  int x;

  x = divide_denominator.back();
  while (divide_denominator.empty() != true)
    {
      if (search(x, divide_numerator) == true)
	{
	  fraction tmp(f.get_numerator() / x, f.get_denominator() / x);
	  return (tmp);
	}
      else
	{
	  divide_denominator.pop_back();
	  x = divide_denominator.back();
	}
    }
  return (f);
}
