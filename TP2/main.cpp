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

void save_date(std::list<compte_normal *>list)
{
  std::ofstream savefile;
  savefile.open("save.csv");
  for (compte_normal * item : list)
    {
      savefile << item->number << "," <<
      	get_type(item->type_compte) << "," <<
      		item->name << "," <<
      	item->lastname << "," <<
      	item->birthdate << ",,"<<
      	item->solde << "," <<
      	//METTRE COMPTE PARENT SI EXISTE
      	item->creation_date;
      for (uint i = 0; i < item->withdrawal_date.size(); i++)
	 savefile << ',' << item->withdrawal_amount[i] << ',' << item->withdrawal_date[i]; 
      savefile << std::endl;
    }
   savefile.close();
}

template<typename T>
void displaylist(std::list<T> list)
{
  for (auto item : list)
    {
      std::cout << item->get_solde() << std::endl;
    }
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
  /*compte_normal test;
  compte_normal test3;
  compte_enfant test2(test);
  */

  std::list<compte_normal *> l_compte;
  /*  std::list<compte_enfant> l_compte_enfant;
  std::list<compte_epargne> l_compte_epargne;
  */
  /*  test3.number = 12034567;
  std::cout << test.get_solde() << std::endl;
  std::cout << test2.compte_parent.number << std::endl;
  */
    read_file(l_compte);
    displaylist(l_compte);
    save_date(l_compte);
}

