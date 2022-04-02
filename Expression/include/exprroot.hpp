#pragma once

#include <memory>
#include <concepts>
#include "expression.hpp"

namespace expr {

  class ExprRoot {
    std::unique_ptr<Expression> impl;

  public:

    ExprRoot() = default;

    ExprRoot(const Expression& src) : impl{ src.make_copy() } {
    }

    ExprRoot(Expression&& src) : impl{ src.make_move() } {
    }

    ExprRoot(const ExprRoot& src) : impl{ src.impl->make_copy() } {
    }

    ExprRoot& operator =(const ExprRoot& src) {
      impl = src.impl->make_copy();
      return *this;
    }

    ExprRoot(ExprRoot&&) noexcept = default;

    ExprRoot& operator =(ExprRoot&&) noexcept = default;

    operator Expression&() {
      return *impl;
    }

    operator const Expression&() const {
      return *impl;
    }

    friend bool operator ==(const ExprRoot& lhs, const ExprRoot& rhs) {
      return lhs.impl->equals(*rhs.impl);
    }

    friend bool operator ==(const ExprRoot& lhs, const Expression& rhs) {
      return lhs.impl->equals(rhs);
    }

    friend bool operator ==(const Expression& lhs, const ExprRoot& rhs) {
      return lhs.equals(*rhs.impl);
    }

    friend std::ostream& operator <<(std::ostream& out, const ExprRoot& rhs) {
      return rhs.impl->print(out);
    }

    double evaluate(Store& store) const {
      return impl->evaluate(store);
    }

    template <typename T> requires std::derived_from<T, Expression>
    friend bool is(const ExprRoot& expr) {
      return dynamic_cast<const T*>(expr.impl.get()) != nullptr;
    }

    template <typename T> requires std::derived_from<T, Expression>
    friend T& as(ExprRoot& expr) {
      return dynamic_cast<T&>(*expr.impl);
    }

    template <typename T> requires std::derived_from<T, Expression>
    friend const T& as(const ExprRoot& expr) {
      return dynamic_cast<const T&>(*expr.impl);
    }
  };

}