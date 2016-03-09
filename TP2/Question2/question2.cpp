enum typeCompte {
  Adulte,
  Enfant,
  Retraite
};
class Compte
{
private:
  int	number;
  std::string name;
  std::string lastname;
  std::string birthdate;
  float	solde;
  int numberParentAccount;
  typeCompte typeDuCompte;

public:
  void Retrait(float money);
  void Depot(float money);
  void Solde();
  Compte(std::string name, std::string birthdate);
};

void	Retrait(float money)
{
  switch (typeDuCompte)
    {
    case Adulte :
      {
	//Code pour le retrait, assez simple
	break;
      }
    case Enfant :
      {
	//Code pour le retrait également, contenant les restrictions qui s'impose
	break;
      }
    case Retraite :
      {
	//Encore le code du retrait, plus les spécification pour ce type de compte
	//(demande d'accord du banquier)
	break;
      }
    default :
      //message d'erreur
    }
}

/*
Ce squelette de classe paramétrisée donne une idée de ce à quoi aurait pu ressembler le projet s'il 
n'était basé sur une hierarchie de classe.
Au premiers abords, elle peut apparaître comme une solution plus simple, mais chaque fonction 
nécessaire à son fonctionnement contiendrait un switch sur le type de compte qui serait connu grâce 
à une enum, définie en haut de ce fichier. Chaque fonction serait donc diviser en trois sous-partie 
spécifiques à chaque type de compte, rendant le code redondant et plus difficile à maintenir.
En effet, dans le cas d'une hiérarchie de classe, s'il y a un besoin de modification impactant la 
pluspart des classes, il suffit de modifier la classe se trouvant le plus haut dans la hierarchie 
afin d'impacter le reste des classes. Alors que dand le cas d'une classe paramétrisée, il faut 
modifier toutes les sections de codes impactées par cette modification.
Le squelette de la methode Retrait ci-dessus donne une assez bonne image de ce à quoi ressemblerait 
toutes les fonctions d'une classe paramétrisée.
*/
