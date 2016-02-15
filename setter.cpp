#include <string>
#include <iostream>
#include "struct.h"

void		set_name(etudiant liste[], int num_etudiant)
{
  std::string name;

  std::cout << "Entrez le nom de l'étudiant:" << std::endl;
  std::cin >> name;
  liste[num_etudiant].name = name;
}

void		set_firstname(etudiant liste[], int num_etudiant)
{
  std::string firstname;

  std::cout << "Entrez le prénom de l'étudiant:" << std::endl;
  std::cin >> firstname;
  liste[num_etudiant].firstname = firstname;
}

void		set_num_street(etudiant liste[], int num_etudiant)
{
  std::string num_street;

  std::cout << "Entrez le numéro de rue de l'étudiant:" << std::endl;
  std::cin >> num_street;
  liste[num_etudiant].num_street = std::stoi(num_street);
}

void		set_name_street(etudiant liste[], int num_etudiant)
{
  std::string name_street;

  std::cout << "Entrez le nom de rue de l'étudiant:" << std::endl;
  std::cin >> name_street;
  liste[num_etudiant].name_street = name_street;
}

void		set_city(etudiant liste[], int num_etudiant)
{
  std::string city;

  std::cout << "Entrez la ville de l'étudiant:" << std::endl;
  std::cin >> city;
  liste[num_etudiant].city = city;
}

void		set_country(etudiant liste[], int num_etudiant)
{
  std::string country;

  std::cout << "Entrez le pays de l'étudiant:" << std::endl;
  std::cin >> country;
  liste[num_etudiant].country = country;
}

void		set_birthdate(etudiant liste[], int num_etudiant)
{
  std::string birthdate;

  std::cout << "Entrez la date de naissance de l'étudiant:" << std::endl;
  std::cin >> birthdate;
  if (check_birthdate(birthdate) == true)
    liste[num_etudiant].birthdate = birthdate;
  else
    {
      std::cout << "La date rentrée n'est pas au format jj/mm/aaaa, veuillez recommencer" << std::endl << std::endl;
      set_birthdate(liste, num_etudiant);
    }
}

void		set_cours(etudiant liste[], int num_etudiant, std::string cours[])
{
  for (int i = 0; i <5; i++)
    liste[num_etudiant].cours[i] = cours[i];
}
