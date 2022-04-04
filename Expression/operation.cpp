#include "operation.hpp"

namespace expr {

  bool Operation::equals(const Expression& other) const {
    return typeid(*this).operator ==(typeid(other)) &&
      lhs == static_cast<const Operation&>(other).lhs &&
      rhs == static_cast<const Operation&>(other).rhs;
  }

  std::ostream& Operation::print(std::ostream& out) const {
    return out << '(' << *lhs << ' ' << name() << ' ' << *rhs << ')';
  }

  double Operation::evaluate(Store& store) const {
    return exec(lhs->evaluate(store), rhs->evaluate(store));
  }

}