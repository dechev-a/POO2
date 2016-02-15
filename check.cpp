#include <iostream>
#include <string>
#include "struct.h"

bool            check_birthdate(std::string str)
{
  bool result = true;
  int   day = 0;
  int   month = 0;
  int   year = 0;

  if (str.length() != 10 || str.find("/") == 0)
    return false;

  day = std::stoi(str.substr(0, str.find("/")));
  month = std::stoi(str.substr(1,str.find("/")));
  year = std::stoi(str.substr((str.find_last_of("/")) + 1));
  std::cout << day << std::endl <<  month << std::endl << year << std::endl;
  if ((day < 1 || day > 31) ||
      (month < 1 || month > 12) ||
      (year < 1900 || year > 2100))
    result = false;
  return result;
}

bool		check_sigle(std::string sigle)
{
  std::string sigle_verif[12];

  sigle_verif[0] = "INF10107";
  sigle_verif[1] = "INF11107";
  sigle_verif[2] = "INF1407";
  sigle_verif[3] = "INF16107";
  sigle_verif[4] = "MAT13203";
  sigle_verif[5] = "INF11207";
  sigle_verif[6] = "INF15107";
  sigle_verif[7] = "INF23107";
  sigle_verif[8] = "INF26207";
  sigle_verif[9] = "MAT14107";
  sigle_verif[10] = "GEN12303";
  sigle_verif[11] = "MUS12097";

  for (int i = 0; i < 12; i++)
    {
      if (sigle_verif[i] == sigle)
	return (true);
    }
  return (false);
}
