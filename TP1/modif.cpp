#include <string>
#include <iostream>
#include "struct.h"

int	add_etudiant(etudiant liste[], etudiant new_etudiant)
{
  int	i;

  i = 0;
  while (i < 30 && !liste[i].name.empty())
    {
      i++;
    }
  if (i < 30)
    {
      liste[i].name = new_etudiant.name;
      liste[i].firstname = new_etudiant.firstname;
      liste[i].num_street = new_etudiant.num_street;
      liste[i].name_street = new_etudiant.name_street;
      liste[i].city = new_etudiant.city;
      liste[i].country = new_etudiant.country;
      liste[i].birthdate = new_etudiant.birthdate;
      for (int x =0; x < 5; x++)
	liste[i].cours[x] = new_etudiant.cours[x];
      std::cout << "i vaut : " << i << std::endl;
      return (1);
    }
  else
    return (-1);
}

int	suppr_etudiant(int num_etudiant, etudiant liste[])
{
  if (!liste[num_etudiant].name.empty())
    {
      liste[num_etudiant].name.clear();
      liste[num_etudiant].firstname.clear();
      liste[num_etudiant].num_street = 0;
      liste[num_etudiant].name_street.clear();
      liste[num_etudiant].city.clear();
      liste[num_etudiant].country.clear();
      liste[num_etudiant].birthdate.clear();
      for (int i = 0; i < 5; i++)
	liste[num_etudiant].cours[i].clear();
      return (1);
    }
  else
    return (-1);
}

void	add_sigle(etudiant liste[] ,int num_etudiant)
{
  std::string sigle;
  int	i;

  i = 0;
  std::cout << "Entrez le sigle du cours à ajouter:" << std::endl;
  std::cin >> sigle;
  if (check_sigle(sigle))
    {
      while (i < 5 && !liste[num_etudiant].cours[i].empty())
	i++;
      if (i < 5)
	{
	  liste[num_etudiant].cours[i] = sigle;
	  std::cout << "i vaut : " << i << std::endl;
	}
      else
	{
	  std::cout << "L'étudiant est déjà inscrit à 5 cours, vous devez en supprimer un avant de l'inscrire à un nouveau cours" << std::endl;
	}
    }
  else
    std::cout << "Ce sigle ne fait pas parti des sigles autorisés" << std::endl;

}

void	suppr_sigle(etudiant liste[], int num_etudiant)
{
  std::string sigle;
  
  std::cout << "Entrez le sigle du cours à supprimer:" << std::endl;
  std::cin >> sigle;
  for (int i =0; i < 5; i++)
    {
      if (liste[num_etudiant].cours[i] == sigle)
	liste[num_etudiant].cours[i].empty();
    }
}
