#include <string>
#include "struct.h"
#include <iostream>

void	init(etudiant liste[])
{
  for (int i = 0; i < 30; i++)
    {
      liste[i].name.clear();
      liste[i].firstname.clear();
      liste[i].num_street = 0;
      liste[i].name_street.clear();
      liste[i].city.clear();
      liste[i].country.clear();
      liste[i].birthdate.clear();
      for (int x = 0; x < 5; x++)
	liste[i].cours[x].clear();
    }
}

int	main()
{
  etudiant liste[30];
  std::string tmp;
  int	i;
  void (*handle_function[2])(etudiant*);

  init(liste);
  handle_function[0] = handle_modif;
  handle_function[1] = print_all;
  liste[0].name = "toto";
  std::cout << "1: Modifier les données d'un étudiant" << std::endl
	    << "2: Consulter la liste des étudiants" << std::endl
	    << "0: Quitter le programme" << std::endl;
  while(tmp != "0")
    {
      std::cout << ">";
      std::cin >> tmp;
      i = std::stoi(tmp);
      if (i == 1 || i == 2)
	{
	  i = i - 1;
	  (*handle_function[i])(liste);
	}
    }
  //std::cout << test << std::endl;
}
