#include "include.h"

int main()
{
  /*compte_normal test;
  compte_normal test3;
  compte_enfant test2(test);
  */

  std::list<compte_normal> l_compte_normal;
  std::list<compte_enfant> l_compte_enfant;
  std::list<compte_epargne> l_compte_epargne;
  
  /*  test3.number = 12034567;
  std::cout << test.get_solde() << std::endl;
  std::cout << test2.compte_parent.number << std::endl;
  */
    read_file(l_compte_normal, l_compte_enfant, l_compte_epargne);
}
