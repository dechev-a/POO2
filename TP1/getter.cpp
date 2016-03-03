#include <string>
#include <iostream>
#include "struct.h"

std::string	get_name(etudiant liste[], int num_etudiant)
{
  if (!liste[num_etudiant].name.empty())
    return (liste[num_etudiant].name);
  else
    {
      std::cout << "Aucun étudiant n'est enregistré à ce numéro." << std::endl;
      return (0);
    }
}

std::string	get_firstname(etudiant liste[], int num_etudiant)
{
  if (!liste[num_etudiant].name.empty())
    return (liste[num_etudiant].firstname);
  else
    {
      std::cout << "Aucun étudiant n'est enregistré à ce numéro." << std::endl;
      return (0);
    }
}

int	get_num_street(etudiant liste[], int num_etudiant)
{
  if (!liste[num_etudiant].name.empty())
    return (liste[num_etudiant].num_street);
  else
    {
      std::cout << "Aucun étudiant n'est enregistré à ce numéro." << std::endl;
      return (0);
    }
}

std::string	get_name_street(etudiant liste[], int num_etudiant)
{
  if (!liste[num_etudiant].name.empty())
    return (liste[num_etudiant].name_street);
  else
    {
      std::cout << "Aucun étudiant n'est enregistré à ce numéro." << std::endl;
      return (0);
    }
}

std::string	get_city(etudiant liste[], int num_etudiant)
{
  if (!liste[num_etudiant].name.empty())
    return (liste[num_etudiant].city);
  else
    {
      std::cout << "Aucun étudiant n'est enregistré à ce numéro." << std::endl;
      return (0);
    }
}

std::string	get_country(etudiant liste[], int num_etudiant)
{
  if (!liste[num_etudiant].name.empty())
    return (liste[num_etudiant].country);
  else
    {
      std::cout << "Aucun étudiant n'est enregistré à ce numéro." << std::endl;
      return (0);
    }
}

std::string	get_birthdate(etudiant liste[], int num_etudiant)
{
  if (!liste[num_etudiant].name.empty())
    return (liste[num_etudiant].birthdate);
  else
    {
      std::cout << "Aucun étudiant n'est enregistré à ce numéro." << std::endl;
      return (0);
    }
}

std::string*	get_cours(etudiant liste[], int num_etudiant)
{
  if (!liste[num_etudiant].name.empty())
    return (liste[num_etudiant].cours);
  else
    {
      std::cout << "Aucun étudiant n'est enregistré à ce numéro." << std::endl;
      return (0);
    }
}
