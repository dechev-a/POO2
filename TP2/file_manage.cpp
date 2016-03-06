#include "include.h"
// class compte_normal;
// class compte_enfant;
// class compte_epargne;

// enum compte {
//   compte_normal,
//   compte_enfant,
//   compte_epargne
// };

void	read_file(std::list<compte_normal> &l_compte_normal,
		  std::list<compte_enfant> &l_compte_enfant,
		  std::list<compte_epargne> &l_compte_epargne)
{
  std::ifstream file ("banque.csv");
  std::string string_compte;
  std::string string_parsing;
  std::vector<std::string> file_to_tab;
  std::vector<std::string> data_to_tab;
  size_t	pos = 0;

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
      //Simple boucle d'analyse de ce qui est reçu dans le tableau
      int x = 0;
      for (std::string tmp : data_to_tab)
	{
	  std::cout << "data_to_tab[ "<< x << "] >> " << tmp << " << end" << std::endl;
	  x++;
	}
      std::cout << "\n\n\n" << std::endl;
      // CREER LA CLASSE ICI
      data_to_tab.clear();
    }
  }
