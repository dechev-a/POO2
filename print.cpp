#include <string>
#include <iostream>
#include "struct.h"

void	print_all(etudiant liste[])
{
  int	i;

  i = 0;
  while (i < 30)
    {
      if (!liste[i].name.empty())
	{
	  print_one(i, liste);
	  //std::cout << i << " : " << liste[i].name << " " << liste[i].firstname << std::endl;
	}
      i++;
    }
}

void	print_one(int num_etudiant, etudiant liste[])
{
  if (!liste[num_etudiant].name.empty())
    {
      std::cout << "Nom: " << liste[num_etudiant].name << std::endl;
      std::cout << "Prénom: " << liste[num_etudiant].firstname << std::endl;
      std::cout << "Adresse: " << liste[num_etudiant].num_street << " ";
      std::cout << "rue " << liste[num_etudiant].name_street << std::endl;
      std::cout << "Ville: " << liste[num_etudiant].city << std::endl;
      std::cout << "Pays: " << liste[num_etudiant].country << std::endl;
      std::cout << "Date de naissance: " << liste[num_etudiant].birthdate << std::endl;
      std::cout << "Cours : " << std::endl;
      for (int i = 0; i < 5; i++)
	std::cout << liste[num_etudiant].cours[i] << std::endl;
    }
}
