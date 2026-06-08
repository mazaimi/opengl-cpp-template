#include <iostream>
#include "MyLib.h"

int main() {
  std::cout << "Hello World" << std::endl;

  MyLib lib_instance;
  lib_instance.setNumber(2);

  std::cout << "MyLib number: " << lib_instance.getNumber() << std::endl;

  return 0;
}
