#pragma once

#include <memory>
#include <ostream>
#include <utility>
#include "expression.hpp"

namespace expr {

  class Operation : public Expression {
  public:

    Expression* lhs;
    Expression* rhs;

    Operation(Expression* lhs, Expression* rhs) : lhs{ lhs }, rhs{ rhs } {
    }

    bool equals(Expression const& rhs) const override;

    std::ostream& print(std::ostream& out) const override;

    double evaluate(Store& store) const override;

    virtual char const* name() const = 0;

    virtual double exec(double a, double b) const = 0;
  };



  class Plus : public Operation {
  public:
    using Operation::Operation;
    char const* name() const override { return "+"; }
    double exec(double a, double b) const override { return a + b; }
  };

  class Minus : public Operation {
  public:
    using Operation::Operation;
    char const* name() const override { return "-"; }
    double exec(double a, double b) const override { return a - b; }
  };

  class Times : public Operation {
  public:
    using Operation::Operation;
    char const* name() const override { return "*"; }
    double exec(double a, double b) const override { return a * b; }
  };

  class Divide : public Operation {
  public:
    using Operation::Operation;
    char const* name() const override { return "/"; }
    double exec(double a, double b) const override { return a / b; }
  };
}
