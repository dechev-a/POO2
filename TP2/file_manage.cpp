#include "include.h"

void	read_file(std::list<compte_normal *> &l_compte)
{
  std::ifstream file ("banque.csv");
  std::string string_compte;
  std::string string_parsing;
  std::vector<std::string> file_to_tab;
  std::vector<std::string> data_to_tab;
  size_t	pos = 0;
  type type_compte;
  
  while (std::getline(file, string_compte, '\n'))
      file_to_tab.push_back(string_compte);
  for (uint i = 0; i < file_to_tab.size(); i++)
    {
      while ((pos = file_to_tab[i].find(",")) != std::string::npos)
	{
	  
	  string_parsing = file_to_tab[i].substr(0, pos);
	  data_to_tab.push_back(string_parsing);
	  file_to_tab[i].erase(0, pos + 1);
	}
      data_to_tab.push_back(file_to_tab[i]);

      type_compte = (type)data_to_tab[1][0];
       compte_normal * test = factory(type_compte, data_to_tab);
       l_compte.push_back(test);
      data_to_tab.clear();
    }
  }
