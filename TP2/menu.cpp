#include "include.h"
#include "classe.h"

bool	autorisation(float money)
{
  std::string tmp;
  std::cout << "Vous êtes le banquier, authorisez vous cette transaction d'un montant de : " << money << "? (y/n)" << std::endl;
  std::cin >> tmp;
  if (tmp == "y")
    return (true);
  else
    return (false);
}
void	menu_retrait(compte_normal  &compte)
{
  std::string tmp;
  
  std::cout << "[RETRAIT] Entrez le montant désié" << std::endl << ">";
  tmp.clear();
  std::cin >> tmp;
  compte.get_money(std::stof(tmp));
}

void	menu_depot(compte_normal &compte)
{
  std::string tmp;
  std::cout << "[DEPOT] Entrez le montant déposé" << std::endl << ">";
  tmp.clear();
  std::cin >> tmp;
  compte.set_money(std::stof(tmp));
}

void	menu_solde(compte_normal &compte)
{
  std::cout << "[SOLDE] : " << compte.get_solde() << std::endl;
}

//Cette fonction sert à créer un compte "juste" avec le nom et la date de naissance, le reste dans champs étant remplie avec au mieux un espace
void	menu_create(std::list<compte_normal *> &l_compte)
{
  std::string tmp;
  std::vector<std::string> tab_new_compte;
  tab_new_compte.push_back(std::to_string(l_compte.size() + 1));
  tab_new_compte.push_back("A");
  std::cout << "[CREATION D'UN COMPTE]" << std::endl;
  std::cout << "Entrez le nom du client" << std::endl << ">";
  tmp.clear();
  std::cin >> tmp;
  tab_new_compte.push_back(tmp);
  tab_new_compte.push_back(" ");
  std::cout << "Entrez la date de naissance du client" << std::endl << ">";
  tmp.clear();
  std::cin >> tmp;
  tab_new_compte.push_back(tmp);
  if((2016 - std::stoi(tmp.substr(0,4)) < 10))
    {
      tmp.clear();
      std::cout << "Entrez le numéro du compte parent lié" << std::endl << ">";
      std::cin >> tmp;
      if (check_compte(std::stoi(tmp), l_compte))
	{
	  tab_new_compte.push_back(tmp);
	  tab_new_compte[1] = "E";
	}
    }
  else
    tab_new_compte.push_back(" ");
  tab_new_compte.push_back("75"); //Solde parfaitement arbitraire afin de ne pas créer un compte sans argent
  compte_normal * test = factory((type)tab_new_compte[1][0], tab_new_compte);
  l_compte.push_back(test);
}

void	print_info(compte_normal &compte)
{
  std::cout << "Numéro de compte : " << compte.number << std::endl 
	    << "Nom : " << compte.name << std::endl 
	    << "Prénom : " << compte.lastname << std::endl 
	    << "Date de naissance : " << compte.birthdate << std::endl;
  if (compte.type_compte == E)
    std::cout << "Compte parent lié : " << dynamic_cast<compte_enfant *>(&compte)->compte_parent << std::endl;
  std::cout << "Solde : " << compte.solde << std::endl 
	    << "Type de compte : " << get_type(compte.type_compte) << std::endl;
  for (uint i = 0; i < compte.withdrawal_date.size(); i++)
    {
      std::cout << "Date de retrait : " << compte.withdrawal_date[i]
		<< " Montant : " << compte.withdrawal_amount[i] << std::endl;
    }
}

void	menu_info(std::list<compte_normal *> &l_compte)
{
  std::string tmp;

  std::cout << "Entrez le numéro du compte dont vous voule voir les informations ou entrez -1 pour voir les informations de tous les comptes" << std::endl << ">";
  std::cin >> tmp;
  if (std::stoi(tmp) == -1)
    {
      for(auto item: l_compte)
	{
	  std::cout << std::endl;
	  print_info(*item);
	  std::cout << std::endl;
	}
    }
  else
    {
      for (auto item: l_compte)
	{
	  if (item->number == std::stoi(tmp))
	    {
	      print_info(*item);
	      return;
	    }
	}
    }
  std::cout << "Ce compte n'existe pas" << std::endl;
}


bool	check_compte(int num_compte, std::list<compte_normal *> &l_compte)
{
  for (compte_normal * item: l_compte)
    {
      if (item->number == num_compte)
	return (true);
    }
  return (false);
}
void	handler(int i, std::list<compte_normal *> &l_compte)
{
  std::string tmp;
  int	num_compte;
  
  std::cout << "Entrez votre numéro de compte" << std::endl << ">";
  std::cin >> tmp;
  num_compte = std::stoi(tmp);
  for (compte_normal * item: l_compte)
    {
      if(item->number == num_compte)
	{
	  switch (i)
	    {
	    case 0 :
	      menu_retrait(*item);
	      return;
	    case 1 :
	      menu_depot(*item);
	      return;
	    case 2 :
	      menu_solde(*item);
	      return; 
	    }    
	}
    }
  std::cout << "Ce compte n'existe pas, veuillez entrer un numéro de compte existant" << std::endl;
}

void	main_menu(std::list<compte_normal *> &l_compte)
{
  int	i;
  std::string	tmp;
  while (i != 5)
    {
      std::cout << "Quelle opération souhaitez vous effectuer?" << std::endl
		<< "0: Effectuer un retrait" << std::endl
		<< "1: Effectuer un dépôt" << std::endl
		<< "2: Afficher votre solde" << std::endl
		<< "3: Créer un compte" << std::endl
		<< "4: [Administration] Afficher les informations d'un ou de tous les comptes" << std::endl
		<< "5: Sortie" << std::endl
		<< ">";
      std::cin >> tmp;
      i = std::stoi(tmp);
      switch (i)
	{
	default:
	case 0 :
	  handler(i,l_compte);
	  break;
	case 1 :
	  handler(i,l_compte);
	  break;
	case 2 :
	  handler(i,l_compte);
	  break;
	case 3 :
	  menu_create(l_compte);
	  break;
	case 4 :
	  menu_info(l_compte);
	  break;
	case 5 :
	  return;
	}
    }
}
