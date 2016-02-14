#include <string>
#include <iostream>
#include "struct.h"

void		set_name(etudiant liste[], int num_etudiant, std::string name)
{
  liste[num_etudiant].name = name;
}

void		set_firstname(etudiant liste[], int num_etudiant, std::string firstname)
{
  liste[num_etudiant].firstname = firstname;
}

void		set_num_street(etudiant liste[], int num_etudiant, int num_street)
{
  liste[num_etudiant].num_street = num_street;
}

void		set_name_street(etudiant liste[], int num_etudiant, std::string name_street)
{
  liste[num_etudiant].name_street = name_street;
}

void		set_city(etudiant liste[], int num_etudiant, std::string city)
{
  liste[num_etudiant].city = city;
}

void		set_country(etudiant liste[], int num_etudiant, std::string country)
{
  liste[num_etudiant].country = country;
}

void		set_birthdate(etudiant liste[], int num_etudiant, std::string birthdate)
{
  liste[num_etudiant].birthdate = birthdate;
}

void		set_cours(etudiant liste[], int num_etudiant, std::string cours[])
{
  for (int i = 0; i <5; i++)
    liste[num_etudiant].cours[i] = cours[i];
}
