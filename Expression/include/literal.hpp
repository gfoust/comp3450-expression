#pragma once

#include "expression.hpp"

namespace expr {
  
  /*========================================================
   * Derived class for numeric literals.
   */
  class Literal : public Expression {
  public:
    
    double value;

    Literal(double value = 0) : value{ value } {
    }

    Literal& operator =(double value) {
      this->value = value;
      return *this;
    }

    // Overrides

    std::unique_ptr<Expression> make_copy() const override {
      return std::make_unique<Literal>(*this);
    }

    std::unique_ptr<Expression> make_move() override {
      return std::make_unique<Literal>(std::move(*this));
    }

    bool equals(const Expression& rhs) const override;

    std::ostream& print(std::ostream& out) const override;

    double evaluate(Store& store) const override;
  };

}