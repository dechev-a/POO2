#include "classe.h"

//Methodes pour Compte_Normal
compte_normal::compte_normal()
{
}

compte_normal::compte_normal(std::vector<std::string> data)
{
  std::string tmp;

  number = std::stoi(data[0]);
  //type_compte = data[1];
  name = data[2];
  lastname = data[3];
  birthdate = data[4];
  solde = std::stof(data[6]);
  creation_date = data[7];
  if (data.size() > 8)
    {
      for (uint i = 8; i < data.size(); i = i + 2)
	add_to_history(data[i], data[i + 1]);
    }
  /*  number = 0;
  name = "toto";
  birthdate = "12/12/12";
  solde = 12.5;
  std::cout << "Création compte normal" << std::endl;
  type_compte = A;  */
}

void	compte_normal::set_money(float money)
{
  solde = solde + money;
}

void	compte_normal::get_money(float money){

  std::string tmp;
  tmp.clear();
  std::cout << "entrez la date du jour sous le format aaaa-m-j" << std::endl;
  std::cin >> tmp;
  if ((solde - money) > 0)
    {
      add_to_history(std::to_string(money), tmp);
      solde = solde - money;
    }
  else
    std::cout << "Solde incorrect: opération annulée" <<std::endl;
}

void	compte_normal::add_to_history(std::string amount, std::string date)
{
  withdrawal_amount.push_back(std::stof(amount));
  withdrawal_date.push_back(date);
}
compte_normal::~compte_normal()
{
}
//Methodes pour Compte_Enfant

compte_enfant::compte_enfant(std::vector<std::string> data) : compte_normal(data)
{
  compte_parent = std::stoi(data[5]);
  //temporaire, necessité de refaire setter via l'historique
  daily_withdrawal = 0;
  monthly_withdrawal = 0;
}

void compte_enfant::get_money(float money)
{
  std::string tmp;
  std::cout << "Entrez la date du jour au format aaaa-m-j" << std::endl;
  std::cin >> tmp;
  if (tmp == withdrawal_date.back() && (daily_withdrawal + money) <= 10 && monthly_withdrawal <= 50)
    {
      add_to_history(std::to_string(money), tmp);
      solde = solde - money;
    }
  else if ((monthly_withdrawal + money) <= 50)//Ajouter vérification mois avec une fonction extérieur retournant un bool
    {
      daily_withdrawal = 0;
      add_to_history(std::to_string(money), tmp);
      solde = solde - money;
    }
  else
    std::cout << "Solde incorrect: opération annulée" <<std::endl;
  // TODO: Gestion des retrais par jours.
}

//Methodes pour Compte_Epargne
compte_epargne::compte_epargne(std::vector<std::string> data) : compte_normal(data)
{
}

void compte_epargne::get_money(float money){
  // Autorisation du banquier
}
