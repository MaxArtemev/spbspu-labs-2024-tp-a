#include <iostream>
#include <fstream>
#include <functional>
#include <algorithm>
#include <map>
#include <vector>
#include <iterator>
#include <numeric>
#include <limits>
#include "commands.hpp"
int main(int argc, char* argv[])
{
  using namespace artemev;
  if (argc != 2)
  {
    std::cerr << "Error! Incorrect input argc\n";
    return 1;
  }

  std::ifstream file(argv[1]);
  if (!file.is_open())
  {
    std::cerr << "Error! Files is empty\n";
    return 1; 
  }

  std::map< std::string, std::function< void(const std::string&, std::istream&, std::ostream&) > > commands;
  commands["READ"] = read;
  std::string command;
  std::string text = argv[1];
  while (std::cin >> command)
  {
    try
    {
      commands.at(command)(text, std::cin, std::cout);
      std::cout << "\n";
    }

    catch(const std::exception&)
    {
      std::cout << "<INVALID COMMAND>\n\n";
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits< std::streamsize >::max(), '\n');
  }
}