#include <iostream>
#include "expr.hpp"
using namespace expr;

Store globalStore = {
  { "x", 10 },
  { "y", 20 },
  { "z", 30 }
};

void printIt(Expression& expr) {
  std::cout << expr << " ==> " << expr.evaluate(globalStore) << std::endl;
}

int main() {
  Literal n = 3;
  printIt(n);

  Variable v = "x";
  printIt(v);

  Plus p = { new Variable{ "y" }, new Literal{ 7 } };
  printIt(p);

  Minus m = { new Times{ new Literal{ 2 }, new Variable{ "x" } }, new Variable{ "z" } };
  printIt(m);
}