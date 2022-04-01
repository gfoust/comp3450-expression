#include "literal.hpp"

namespace expr {

  bool Literal::equals(const Expression& rhs) const {
    return typeid(Literal) == typeid(rhs) &&
      value == static_cast<const Literal&>(rhs).value;
  }

  std::ostream& Literal::print(std::ostream& out) const {
    return out << value;
  }

  double Literal::evaluate(Store& store) const {
    return value;
  }


}