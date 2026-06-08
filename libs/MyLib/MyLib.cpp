#include "MyLib.h"

int MyLib::getNumber() {
  return this->m_number;
}

void MyLib::setNumber(int in_number) {
  this->m_number = in_number;
}
