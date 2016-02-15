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

// Dans main.cpp
// Initialisation du tableau
void		ini(etudiant liste[]);

// Dans modif.cpp
// Constructeur/Destructeur
int		add_etudiant(std::string new_name, etudiant liste[]);
int		suppr_etudiant(int num_etudiant, etudiant liste[]);
// Ajout/suppression d'un seul cours, permettant des boucles
void		add_sigle(etudiant liste[], int num_etudiant);
void		suppr_sigle(etudiant liste[], int num_etudiant);

// Dans print.cpp
// Affichage globale
void		print_all(etudiant liste[]);
// Affichage unique
void		print_one(int num_etudiant, etudiant liste[]);

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
void		set_name(etudiant liste[], int num_etudiant);
void		set_firstname(etudiant liste[], int num_etudiant);
void		set_num_street(etudiant liste[], int num_etudiant);
void		set_name_street(etudiant liste[], int num_etudiant);
void		set_city(etudiant liste[], int num_etudiant);
void		set_country(etudiant liste[], int num_etudiant);
void		set_birthdate(etudiant liste[], int num_etudiant);
void		set_cours(etudiant liste[], int num_etudiant, std::string cours[]);

// Dans handler.cpp
void		handle_modif(etudiant liste[]);

// Dans check.pp
bool		check_birthdate(std::string str);
bool		check_sigle(std::string sigle);
#endif //STRUCT_H_//
