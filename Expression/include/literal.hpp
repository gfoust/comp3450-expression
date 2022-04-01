#pragma once

#include "expression.hpp"

namespace expr {
  
  class Literal : public Expression {
  public:
    
    double value;

    Literal(double value = 0) : value{ value } {
    }

    Literal& operator =(double value) {
      this->value = value;
      return *this;
    }

    bool equals(const Expression& rhs) const override;

    std::ostream& print(std::ostream& out) const override;

    double evaluate(Store& store) const override;

  };

}