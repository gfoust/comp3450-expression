#include "variable.hpp"

namespace expr {

  bool Variable::equals(const Expression& rhs) const {
    return typeid(Variable) == typeid(rhs) &&
      name == static_cast<Variable const&>(rhs).name;
  }

  std::ostream& Variable::print(std::ostream& out) const {
    return out << name;
  }

  double Variable::evaluate(Store& store) const {
    return store[name];
  }

}