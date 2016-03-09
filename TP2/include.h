#ifndef INCLUDE_H_
#define INCLUDE_H_

#include <string.h>
#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <sstream>
#include "classe.h"


/*class compte_normal;
class compte_enfant;
class compte_epargne;
*/

void read_file(std::list<compte_normal *> &);
compte_normal * factory(type, std::vector<std::string>);
void main_menu(std::list<compte_normal *> &);
bool verif_string(std::string );
void menu_retrait(compte_normal &);
void menu_depot(compte_normal &);
void menu_solde(compte_normal &);
void menu_solde(compte_normal &);
void menu_create(std::list<compte_normal *> &);
void menu_info(std::list<compte_normal *> &);
bool check_compte(int, std::list<compte_normal *> &);
void handler(int, std::list<compte_normal *> &);
void save_data(std::list<compte_normal *>);
std::string get_type(type);
bool autorisation(float money);
#endif
