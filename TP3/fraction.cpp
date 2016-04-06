#include "fraction.hpp"
#include <iostream>
#include "simplification.hpp"

//constructeur
fraction::fraction(int numerator, int denominator)
{
  this->numerator = numerator;
  if (denominator > 0)
    this->denominator = denominator;
  else
    {
      this->denominator = 1;
      std::cout << "Votre dénominateur ne peut être inférieur à 1 et à donc été mis à 1" << std::endl;
    }
}

//destructeur
fraction::~fraction()
{
  this->numerator = 0;
  this->denominator = 0;
}

//Getteur pour les deux valeurs des fractions
int	fraction::get_numerator()
{
  return (this->numerator);
}

int	fraction::get_denominator()
{
  return (this->denominator);
}

/*
  Les methodes suivante sont celles appelées lors d'un calcul entre une fraction et un int
  Elles créer une fraction sur 1 avec le int, multiplie les éléments pour les mettres sur un dénominateur commun si nécessaire(addition et soustraction) puis font le calcul.
  Elles appellent ensuite la fonction de simplification et retourne le résultat
*/

fraction	fraction::operator+(const int & n)
{
  fraction f(n,1);
  fraction tmp(this->numerator, this->denominator);

  f.numerator = f.numerator * this->denominator;
  f.denominator = f.denominator * this->denominator;
  tmp.numerator = tmp.numerator * f.denominator;
  tmp.denominator = tmp.denominator * f.denominator;
  tmp.numerator += f.numerator;
  tmp = simplification(tmp);
  return (tmp);
}

fraction	fraction::operator-(const int & n)
{
  fraction f(n,1);
  fraction tmp(this->numerator, this->denominator);

  f.numerator = f.numerator * this->denominator;
  f.denominator = f.denominator * this->denominator;
  tmp.numerator = tmp.numerator * f.denominator;
  tmp.denominator = tmp.denominator * f.denominator;
  tmp.numerator -= f.numerator;
  tmp = simplification(tmp);
  return (tmp);
}

fraction	fraction::operator*(const int & n)
{
  fraction f((this->numerator * n), this->denominator);
  f = simplification(f);
  return (f);
}

fraction	fraction::operator/(const int & n)
{
  fraction f (1,n);
  fraction tmp(this->numerator, this->denominator);
  tmp = simplification(tmp*f);
  return (tmp);
}

/*
  Les méthodes suivantes sont celles appelé lors d'un calcul entre deux fractions
  Elles créer deux fractions tampon, effectue une mise en commun des dénominateurs pour l'addition et la soustraction puis font le calcul.
  Elles appellent ensuite la fonction de simplification et retourne le resultat.
*/

fraction	fraction::operator+(const fraction & f)
{
  if (f.denominator != this->denominator)
    {
      fraction a(this->numerator * f.denominator,
		 this->denominator * f.denominator);
      fraction b(f.numerator * this->denominator,
		 f.denominator * this->denominator);
      fraction res(a.get_numerator() + b.get_numerator(), a.get_denominator());
      res = simplification(res);
      return (res);
    }
  else
    {
      fraction tmp(this->numerator + f.numerator, this->denominator);
      tmp = simplification(tmp);
      return (tmp);
    }
}

fraction	fraction::operator-(const fraction & f)
{
  if (f.denominator != this->denominator)
    {
      fraction a(this->numerator * f.denominator,
		 this->denominator * f.denominator);
      fraction b(f.numerator * this->denominator,
		 f.denominator * this->denominator);
      fraction res(a.get_numerator() - b.get_numerator(), a.get_denominator());
      res = simplification(res);
      return (res);
    }
  else
    {
      fraction tmp(this->numerator - f.numerator, this->denominator);
      tmp = simplification(tmp);
      return (tmp);
    }           
}

fraction	fraction::operator*(const fraction & f)
{
  fraction tmp(f.numerator * this->numerator,
	       f.denominator * this->denominator);
  tmp = simplification(tmp);
  return (tmp);
}

fraction	fraction::operator/(const fraction & f)
{
  fraction tmp(this->numerator, this->denominator);
  fraction tmp2 (f.numerator, f.denominator);
  tmp = simplification((tmp * (~tmp2)));
  return (tmp);
  //return (tmp * (~tmp2));
}

/*
  Les méthodes suivants sont celles appelé lors d'un calcul entre un int et une fraction.
  Elles transforme le int en une fraction puis font appel aux autres opérateurs pour une simplification du code.
  Enfin elles appellent la fonction de simplification et retournent le résultat. 
*/

fraction     operator+(int num, fraction  f)
{
  fraction tmp(f.get_numerator(), f.get_denominator());
  return (simplification(tmp + num));
  //  return(tmp + num);
}

fraction        operator-(int num, fraction f)
{
  fraction tmp(f.get_numerator(), f.get_denominator());
  fraction tmp2(num, 1);
  return (simplification(tmp2 - tmp));
  //  return (tmp2 - tmp);
}

fraction        operator*(int num, fraction f)
{
  fraction tmp(f.get_numerator(), f.get_denominator());
  return (simplification(tmp * num));
  //  return (tmp * num);
}

fraction        operator/(int num, fraction f)
{
  fraction tmp(f.get_numerator(), f.get_denominator());
  fraction tmp2(num, 1);
  return (simplification(tmp2 / tmp));
  //  return (tmp2 / tmp);
}

/*
  Les méthodes suivantes sont les opérateurs unitaire.
  Ils effectuent les opérations sur des fractions tampons qu'ils retournent sans simplification.
*/

fraction	fraction::operator+()
{
  fraction tmp(this->numerator * 1, this->denominator * 1);
  //  tmp = simplification(tmp);
  return (tmp);
}

fraction	fraction::operator-()
{
  fraction tmp(this->numerator * -1, this->denominator * -1);
  return (tmp);
}

fraction	fraction::operator~()
{
  fraction tmp(this->denominator, this->numerator);
  return (tmp);
}

// Surcharge de l'opéraeur << afin de gérer l'affichage
std::ostream	&operator<<(std::ostream &flux, fraction f)
{
  flux << f.get_numerator() << "/" << f.get_denominator();
  return (flux);
}
