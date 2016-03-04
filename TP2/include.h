#ifndef INCLUDE_H_
#define INCLUDE_H_

#include <string.h>
#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <sstream>
#include "classe.h"


/*class compte_normal;
class compte_enfant;
class compte_epargne;
*/
void read_file(std::list<compte_normal> &,
	       std::list<compte_enfant> &,
	       std::list<compte_epargne> &);

#endif
