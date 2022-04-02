#pragma once

#include "expression.hpp"
#include "exprroot.hpp"

namespace expr {

  /*========================================================
   * Base class for all operations.
   */
  class Operation : public Expression {
  public:

    ExprRoot lhs;

    ExprRoot rhs;

    Operation(ExprRoot lhs, ExprRoot rhs) : lhs{ std::move(lhs) }, rhs{ std::move(rhs) } {
    }

    // Overrides

    bool equals(const Expression& rhs) const override;

    std::ostream& print(std::ostream& out) const override;

    double evaluate(Store& store) const override;

    // New virtual methods

    virtual char const* name() const = 0;

    virtual double exec(double a, double b) const = 0;
  };


  /*========================================================
   * Derived class for each operator
   */

  class Plus : public Operation {
  public:
    using Operation::Operation;

    std::unique_ptr<Expression> make_copy() const override { 
      return std::make_unique<Plus>(*this); 
    }

    std::unique_ptr<Expression> make_move() override { 
      return std::make_unique<Plus>(std::move(*this)); 
    }

    char const* name() const override { 
      return "+"; 
    }

    double exec(double a, double b) const override { 
      return a + b; 
    }
  };


  class Minus : public Operation {
  public:
    using Operation::Operation;
    
    std::unique_ptr<Expression> make_copy() const override { 
      return std::make_unique<Minus>(*this); 
    }

    std::unique_ptr<Expression> make_move() override { 
      return std::make_unique<Minus>(std::move(*this)); 
    }

    char const* name() const override { 
      return "-"; 
    }

    double exec(double a, double b) const override { 
      return a - b; 
    }
  };


  class Times : public Operation {
  public:
    using Operation::Operation;
    
    std::unique_ptr<Expression> make_copy() const override { 
      return std::make_unique<Times>(*this); 
    }

    std::unique_ptr<Expression> make_move() override { 
      return std::make_unique<Times>(std::move(*this)); 
    }

    char const* name() const override { 
      return "*"; 
    }

    double exec(double a, double b) const override { 
      return a * b; 
    }
  };


  class Divide : public Operation {
  public:
    using Operation::Operation;

    std::unique_ptr<Expression> make_copy() const override {
      return std::make_unique<Divide>(*this);
    }

    std::unique_ptr<Expression> make_move() override { 
      return std::make_unique<Divide>(std::move(*this)); 
    }

    char const* name() const override { 
      return "/"; 
    }

    double exec(double a, double b) const override { 
      return a / b; 
    }
  };
}
