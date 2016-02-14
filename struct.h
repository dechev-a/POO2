#ifndef STRUCT_H_
#define STRUCT_H_

#include <string>
struct etudiant {
  std::string	name;
  std::string	firstname;
  int	num_street;
  std::string	name_street;
  std::string	city;
  std::string	country;
  std::string	birthdate;
  std::string	cours[5];
};
// Dans modif.cpp
// Constructeur/Destructeur
int		add_etudiant(std::string new_name, etudiant liste[]);
int		suppr_etudiant(int num_etudiant, etudiant liste[]);
// Ajout/suppression d'un seul cours, permettant des boucles
int		add_sigle(std::string sigle, int num_etudiant,etudiant liste[]);
int		suppr_sigle(std::string, int num_etudiant, int num_cours, etudiant liste[]);

// Dans print.cpp
// Affichage globale
int		print_all(etudiant liste[]);
// Affichage unique
int		print_one(int num_etudiant, etudiant liste[]);

// Dans getter.cpp
// Getters
std::string	get_name(etudiant liste[], int num_etudiant);
std::string	get_firstname(etudiant liste[], int num_etudiant);
int		get_num_street(etudiant liste[], int num_etudiant);
std::string	get_name_street(etudiant liste[], int num_etudiant);
std::string	get_city(etudiant liste[], int num_etudiant);
std::string	get_country(etudiant liste[], int num_etudiant);
std::string	get_birthdate(etudiant liste[], int num_etudiant);
std::string*	get_cours(etudiant liste[], int num_etudiant);

// Dans setter.cpp
// Setters
void		set_name(etudiant liste[], int num_etudiant, std::string name);
void		set_firstname(etudiant liste[], int num_etudiant, std::string firstname);
void		set_num_street(etudiant liste[], int num_etudiant, int num_street);
void		set_name_street(etudiant liste[], int num_etudiant, std::string name_street);
void		set_city(etudiant liste[], int num_etudiant, std::string city);
void		set_country(etudiant liste[], int num_etudiant, std::string country);
void		set_birthdate(etudiant liste[], int num_etudiant, std::string birthdate);
void		set_cours(etudiant liste[], int num_etudiant, std::string cours[]);

#endif //STRUCT_H_//
