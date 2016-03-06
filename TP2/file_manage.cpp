#include "include.h"

void	read_file(std::list<compte_normal *> &l_compte)
{
  std::ifstream file ("save.csv");
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
      int j = 0;
      while ((pos = file_to_tab[i].find(",")) != std::string::npos)
	{
	  
	  string_parsing = file_to_tab[i].substr(0, pos);
	  // std::cout << "WHAT HAPPENEND: " << string_parsing << std::endl;
	  data_to_tab.push_back(string_parsing);
	  file_to_tab[i].erase(0, pos + 1);
	}
      data_to_tab.push_back(file_to_tab[i]);
      // for (auto item : data_to_tab)
      // 	{
      // 	  std::cout << "WHAT IS STOCKED" << item << std::endl;
      // 	}
      //    Simple boucle d'analyse de ce qui est reçu dans le tableau
      int x = 0;
      for (std::string tmp : data_to_tab)
      	{
      	  std::cout << "data_to_tab[ "<< x << "] >> " << tmp << " << end" << std::endl;
      	  x++;
      	}
      std::cout << "\n\n\n" << std::endl;
      // // CREER LA CLASSE ICI

      type_compte = (type)data_to_tab[1][0];
       compte_normal * test = factory(type_compte, data_to_tab);
       l_compte.push_back(test);
      data_to_tab.clear();
    }
  }
