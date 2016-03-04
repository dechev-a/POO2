#include "include.h"

enum type {
  A,
  E,
  R
};

class compte
{
public:
  int	number;
  std::string name;
  std::string birthdate;
  float solde;
  type type_compte;
  
  float get_solde(){return solde;};
  compte(){};
  virtual ~compte(){}
};

 class compte_normal : public compte
{
 public:
   void	set_money(float money){
    solde = solde + money;
  };
   virtual void	get_money(float money){
    if ((solde - money) > 0)
      solde = solde - money;
    else
      std::cout << "Solde incorrect: opération annulée" <<std::endl;
  };

 compte_normal()
      {
	number = 0;
	name = "toto";
	birthdate = "12/12/12";
	solde = 12.5;
	std::cout << "Création compte normal" << std::endl;
	type_compte = A;
      };
  virtual ~compte_normal(){};
};

class compte_enfant : public compte_normal
{
 public:
   compte_normal  compte_parent;
  
 public:
  void get_money(float money)
  {
    // TODO: Gestion des retrais par jours.
  }
  compte_enfant(const compte_normal &compte){
     std::cout << "Création enfant" << std::endl;
     this->compte_parent = compte;
     type_compte = E;
     };
   virtual ~compte_enfant(){};
};

class compte_epargne : public compte_normal
{
  void get_money(float money){
    // Autorisation du banquier
  };
  /* compte_epargne() */
  /*   { */
  /*     type_compte = R; */
  /*   }; */
  /* virtual ~compte_epargne(){}; */
};

//#endif
