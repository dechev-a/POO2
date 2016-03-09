#include "classe.h"
#include "include.h"

//Methodes pour Compte_Normal
compte_normal::compte_normal()
{
}

compte_normal::compte_normal(std::vector<std::string> data)
{
  std::string tmp;

  number = std::stoi(data[0]);
  type_compte = (type)data[1][0];
  name = data[2];
  lastname = data[3];
  birthdate = data[4];
  solde = std::stof(data[6].c_str());

  if (data.size() > 7)
    {
      for (uint i = 7; i < data.size(); i = i + 2)
	if (i + 1 < data.size())
	  {
	    add_to_history(data[i + 1], data[i]);
	  }
    }
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
  if (data[5] != "")
    compte_parent = std::stoi(data[5]);
  daily_withdrawal = 0;
  monthly_withdrawal = 0;
}

void compte_enfant::get_money(float money)
{
  std::string tmp;
  std::cout << "Entrez la date du jour au format aaaa-m-j" << std::endl;
  std::cin >> tmp;
  //Verification que le mois du retrait est différent de celui du dernier retrait afin de remttre à zéro le compteur mensuel avant le début des tests 
  if (std::stoi(tmp.substr(tmp.find('-') + 1, 2)) != std::stoi(withdrawal_date.back().substr(withdrawal_date.back().find('-') +1, 2)))
    monthly_withdrawal = 0;
  if (tmp == withdrawal_date.back() &&
      ((daily_withdrawal + money) <= 10) &&
      (monthly_withdrawal <= (50 - money)))
    {
      add_to_history(std::to_string(money), tmp);
      solde = solde - money;
      daily_withdrawal += money;
      monthly_withdrawal += money;
    }
  else if ((monthly_withdrawal + money) <= 50 &&
	   (tmp != withdrawal_date.back()))
    {
      daily_withdrawal = 0;
      add_to_history(std::to_string(money), tmp);
      solde = solde - money;
      daily_withdrawal += money;
      monthly_withdrawal += daily_withdrawal;
    }
  else
    std::cout << "Solde incorrect: opération annulée" <<std::endl;
}

//Methodes pour Compte_Epargne
compte_epargne::compte_epargne(std::vector<std::string> data) : compte_normal(data)
{
}

void compte_epargne::get_money(float money)
{
  // Autorisation du banquier
  if(autorisation(money))
    compte_normal::get_money(money);
  else
    std::cout << "Votre banquier a refuser cette transaction" << std::endl;
}
