#include <iostream>
#include "expr.hpp"
using namespace expr;

Store globalStore = {
  { "x", 10 },
  { "y", 20 },
  { "z", 30 }
};

void printIt(const char* name, const Expression& expr) {
  std::cout << '[' << name << "] " << expr << " ==> " << expr.evaluate(globalStore) << std::endl;
}

int main() {
  Literal n{ 3 };
  printIt("n", n);

  Variable v{ "x" };
  printIt("v", v);

  ExprRoot e = n;
  printIt("e", e);

  e = v;
  printIt("e", e);

  v = "y";
  printIt("v", v);
  printIt("e", e);

  e = Plus{ Times{ Literal{ 2 }, Variable{ "x" } }, Variable{ "y" } };
  printIt("e", e);

  if (is<Operation>(e)) {
    as<Operation>(e).rhs = e;
    printIt("e", e);
  }
}
