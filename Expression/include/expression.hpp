#pragma once

#include <ostream>
#include <map>
#include <string>

namespace expr {

  using Store = std::map<std::string, double>;

  class Expression {
  public:
    virtual ~Expression() { 
    };

    virtual bool equals(const Expression& rhs) const = 0;

    virtual std::ostream& print(std::ostream& out) const = 0;

    virtual double evaluate(Store& store) const = 0;
  };

  inline std::ostream& operator <<(std::ostream& out, const Expression& expr) {
    return expr.print(out);
  }

  inline bool operator ==(const Expression& lhs, const Expression& rhs) {
    return lhs.equals(rhs);
  }

}