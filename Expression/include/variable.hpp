#pragma once
#include <ostream>
#include <string>
#include <utility>
#include "expression.hpp"

namespace expr {

  class Variable : public Expression {
  public:

    std::string name;

    Variable(std::string name = "") : name{ std::move(name) } {
    }

    Variable& operator =(std::string name) {
      this->name = std::move(name);
      return *this;
    }

    bool equals(const Expression& rhs) const override;

    std::ostream& print(std::ostream& out) const override;

    double evaluate(Store& store) const override;
  };
}
