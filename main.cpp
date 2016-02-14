#include <string>
#include "struct.h"
#include <iostream>

int	main()
{
  etudiant liste[30];
  std::string test;
  
  liste[0].name = "toto";
  std::cout << "Hello" << std::endl << ">";
  std::cin >> test;
  std::cout << test << std::endl;
}
