#include "include.h"
// class compte_normal;
// class compte_enfant;
// class compte_epargne;

// enum compte {
//   A = 65,
//   E = 69,
//   R = 82
// };

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
      //Simple boucle d'analyse de ce qui est reçu dans le tableau
      int x = 0;
      for (std::string tmp : data_to_tab)
	{
	  std::cout << "data_to_tab[ "<< x << "] >> " << tmp << " << end" << std::endl;
	  x++;
	}
      std::cout << "\n\n\n" << std::endl;
      // CREER LA CLASSE ICI

      type_compte = (type)data_to_tab[1][0];
      compte_normal * test = factory(type_compte, data_to_tab);
      l_compte.push_back(test);
      // switch (type_compte)
      // 	{
      // 	case type::A:
      // 	  {
      // 	    l_compte_normal.push_back(*test);
      // 	    break;
      // 	  }
      // 	case type::E: {
      // 	  l_compte_enfant.push_back(dynamic_cast<compte_enfant>(test));
      // 	  break;
      // 	}
      // 	case type::R: {
      // 	  // l_compte_epargne.push_back(*test);
      // 	  break;
      // 	}
      // 	default:
      // 	  std::cout << "Error: impossible d'enregistrer le compte" << std::endl;
      // 	} 
      // l_compte_normal.push_back(*test);
      //if (test == compte_normal)
      //std::cout << "AZERTY" << std::endl;
      // switch(test)
      // 	{
      // 	case compte_normal:
      // 	  {
      // 	  // l_compte_normal.push_back()
      // 	  std::cout << "compte normal" << std::endl;
      // 	  break;
      // 	  }
      // 	case compte_normal::compte_enfant: {
      // 	  std::cout << "compte enfant" << std::endl;
      // 	  break;
      // 	}
      // 	case compte_normal::compte_epargne: {
      // 	  std::cout << "compte epargne" << std::endl;
      // 	  break;
      // 	}
      data_to_tab.clear();
    }
  }
