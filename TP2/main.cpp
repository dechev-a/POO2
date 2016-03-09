#include "include.h"
#include "classe.h"

std::string get_type(type t)
{
  switch(t)
    {
    default:
    case A: return "A";
    case E: return "E";
    case R: return "R";
    }
}

void save_data(std::list<compte_normal *>list)
{
  std::ofstream savefile;
  savefile.open("banque.csv");
  
  for (compte_normal * item : list)
    {
      savefile << item->number << "," <<
      	get_type(item->type_compte) << "," <<
	item->name << "," <<
      	item->lastname << "," <<
	item->birthdate << ",";

      //Si ajout du compte parent si compte enfant
      if (item->type_compte == E)
	savefile<< dynamic_cast<compte_enfant*>(item)->compte_parent <<",";
      else
	savefile <<",";

      savefile << item->solde ;
      for (uint i = 0; i < item->withdrawal_date.size(); i++)
	savefile << ',' << item->withdrawal_date[i] << ',' << item->withdrawal_amount[i]; 
      savefile << std::endl;
    }
  savefile.close();
}


compte_normal * factory(type t, std::vector<std::string> data)
{
  switch(t)
    {
    default:
    case type::A : return new compte_normal(data);
    case type::E : return new compte_enfant(data);
    case type::R : return new compte_epargne(data);
    }
}


int main()
{
  std::list<compte_normal *> l_compte;

  read_file(l_compte);
  main_menu(l_compte);
  save_data(l_compte);
}

