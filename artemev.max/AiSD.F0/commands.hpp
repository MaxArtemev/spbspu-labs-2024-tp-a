#ifndef COMMANDS_HPP
#define COMMANDS_HPP
#include <fstream>
#include <iostream>
namespace artemev
{
  void read(const std::string& filename, std::istream& input, std::ostream& output);
}

#endif