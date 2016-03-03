#include "include.h"
#include "classe.h"

int main()
{
  compte_normal test;
  compte_normal test3;
  compte_enfant test2(test);

  test3.number = 12034567;
  std::cout << test.get_solde() << std::endl;
  std::cout << test2.compte_parent.number << std::endl;
}
