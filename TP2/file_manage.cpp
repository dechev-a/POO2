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
  
  while (std::getline(file, string_compte, '\n'))
    {
       // std::cout << string_compte << std::endl;
      file_to_tab.push_back(string_compte);
    }

  for (std::string item : file_to_tab)
    {
      string_parsing = item.substr(item.find(","), 2);
      std::cout << string_parsing << std::endl;
    }
}
