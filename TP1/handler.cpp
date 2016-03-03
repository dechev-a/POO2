#include <iostream>
#include <string>
#include "struct.h"

void		handle_modif(etudiant liste[])
{
  void (*function_pointer[9])(etudiant*, int);
  function_pointer[0] = set_name;
  function_pointer[1] = set_firstname;
  function_pointer[2] = set_num_street;
  function_pointer[3] = set_name_street;
  function_pointer[4] = set_city;
  function_pointer[5] = set_country;
  function_pointer[6] = set_birthdate;
  function_pointer[7] = add_sigle;
  function_pointer[8] = suppr_sigle;

  int	modif;
  int	num_etudiant;
  std::string tmp;
  std::string tmp2;

  modif = 0;
  num_etudiant = 0;
  while (modif != -1)
    {
      std::cout << "Tapez:" << std::endl;
      std::cout << "0: Modifier le nom d'un étudiant" << std::endl;
      std::cout << "1: Modifier le prénom d'un étudiant" << std::endl;
      std::cout << "2: Modifier le numéro de rue d'un étudiant" << std::endl;
      std::cout << "3: Modifier le nom de rue d'un étudiant" << std::endl;
      std::cout << "4: Modifier la ville d'un étudiant" << std::endl;
      std::cout << "5: Modifier le pays d'un étudiant" << std::endl;
      std::cout << "6: Modifier la date de naissance d'un étudiant" << std::endl;
      std::cout << "7: Ajouter un cours àl'étudiant" << std::endl;
      std::cout << "8: Supprimer un cours de l'étudiant" << std::endl;
      std::cout << "-1: Sortir de la section modification" << std::endl;
      std::cout << ">";
      std::cin >> tmp;
      modif = std::stoi(tmp);
      if (modif > -1 && modif < 9)
	{
	  std::cout << "Entrez le numéros de l'étudiant sur lequel vous souhaitz effectuer la modification:" << std::endl;
	  std::cin >> tmp;
	  num_etudiant = std::stoi(tmp);
	  (*function_pointer[modif])(liste, num_etudiant);
	  tmp.clear();
	}
    }
}
