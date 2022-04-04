#pragma once

#include <ostream>
#include <map>
#include <string>

namespace expr {

  /*========================================================
   * Variable store.
   * Map variable names to their value
   */
  using Store = std::map<std::string, double>;


  /*========================================================
   * Base class for all Expressions.
   */
  class Expression {
  public:

    // Virtual methods

    virtual ~Expression() { 
    };

    virtual bool equals(const Expression& rhs) const = 0;

    virtual std::ostream& print(std::ostream& out) const = 0;

    virtual double evaluate(Store& store) const = 0;
  };

  /*========================================================
   * Operators for all Expressions
   */

  inline std::ostream& operator <<(std::ostream& out, const Expression& expr) {
    return expr.print(out);
  }

  inline bool operator ==(const Expression& lhs, const Expression& rhs) {
    return lhs.equals(rhs);
  }

}