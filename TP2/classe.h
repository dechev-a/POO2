#ifndef CLASSE_H_
#define CLASSE_H_

#include <string.h>
#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <sstream> 
//#include "include.h"

enum type {
  A = 65,
  E = 69,
  R = 82
};

class compte_normal
{
 protected:
  int	number;
  std::string name;
  std::string lastname;
  std::string birthdate;
  float solde;
  type type_compte;
  std::string creation_date;
  std::vector<std::string> withdrawal_date;
  std::vector<float> withdrawal_amount;
  
 public:
  float get_solde(){return solde;};
  void	set_money(float money);
  virtual void	get_money(float money);
  void	add_to_history(std::string amount, std::string date);
  compte_normal();
  compte_normal(std::vector<std::string> data);
  virtual ~compte_normal();
};

class compte_enfant : public compte_normal
{
 public:
  int  compte_parent;
  float daily_withdrawal;
  float monthly_withdrawal;
  
  void get_money(float money);
  compte_enfant(std::vector<std::string> data);
};

class compte_epargne : public compte_normal
{
 public:
  compte_epargne(std::vector<std::string> data);
  void get_money(float money);
};

#endif
