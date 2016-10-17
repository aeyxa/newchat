#include "common.h"

void error(std::string ErrorMessage)
{
  std::cout << ErrorMessage << std::endl; exit(1);
}

void check(int error_number)
{
  if(error_number != 0) error(strerror(errno));
}
