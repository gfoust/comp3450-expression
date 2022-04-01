# CMakeList.txt : CMake project for Expression, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (expression 
  "main.cpp" 
  "include/expression.hpp" 
  "include/expr.hpp" 
  "include/literal.hpp" "literal.cpp" 
  "include/variable.hpp" "variable.cpp" "include/operation.hpp" "operation.cpp")
target_include_directories (expression PUBLIC "include")

# TODO: Add tests and install targets if needed.
