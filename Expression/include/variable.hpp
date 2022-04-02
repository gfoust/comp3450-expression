#pragma once

#include "expression.hpp"

namespace expr {

  /*========================================================
   * Derived class for variables.
   */
  class Variable : public Expression {
  public:

    std::string name;

    Variable(std::string name = "") : name{ std::move(name) } {
    }

    Variable& operator =(std::string name) {
      this->name = std::move(name);
      return *this;
    }

    // Overrides

    std::unique_ptr<Expression> make_copy() const override {
      return std::make_unique<Variable>(*this);
    }

    std::unique_ptr<Expression> make_move() override {
      return std::make_unique<Variable>(std::move(*this));
    }

    bool equals(const Expression& rhs) const override;

    std::ostream& print(std::ostream& out) const override;

    double evaluate(Store& store) const override;
  };
}
