#include <string>
#include <iostream>
#include "struct.h"

int	print_all(etudiant liste[])
{
  int	i;

  i = 0;
  while (i < 30)
    {
      if (!liste[i].name.empty())
	{
	  std::cout << i << " : " << liste[i].name << " " << liste[i].firstname << std::endl;
	}
      i++;
    }
  return (1);
}

int	print_one(int num_etudiant, etudiant liste[])
{
  if (!liste[num_etudiant].name.empty())
    {
      std::cout << liste[num_etudiant].name << std::endl;
      std::cout << liste[num_etudiant].firstname << std::endl;
      std::cout << liste[num_etudiant].num_street << std::endl;
      std::cout << liste[num_etudiant].name_street << std::endl;
      std::cout << liste[num_etudiant].city << std::endl;
      std::cout << liste[num_etudiant].country << std::endl;
      std::cout << liste[num_etudiant].birthdate << std::endl;
      std::cout << "Cours : " << std::endl;
      for (int i = 0; i < 5; i++)
	std::cout << liste[num_etudiant].cours[i] << std::endl;
      return (1);
    }
}
