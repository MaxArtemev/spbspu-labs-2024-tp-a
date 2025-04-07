#include "commands.hpp"
#include <vector>
#include <iomanip>
void artemev::read(const std::string& filename, std::istream& input, std::ostream& output)
{
  output << std::fixed << std::setprecision(1);
  std::string command;
  input >> command;
  
  if (command == "-f")
  {
    std::ifstream file(filename, std::ifstream::binary);

    std::vector< int > freq(0x100, 0);  
    while (!file.eof())
    {
      char ch;
      file.read(&ch, 1);
      freq[static_cast< unsigned char >(ch)]++;
    }
    for(size_t i = 0; i < freq.size(); ++i)
    {
      if (freq[i] == 0)
      {
        continue;
      }
      else
      {
        output << "[" << i << "] = " << freq[i] << "\t" << "\n";
      }
    }
    file.close();
  }

  else if (command == "-t")
  {
    std::ifstream fileT(filename);

    char s[256];
    while (!fileT.eof())
    {
      fileT.getline(s, 256);
      output << s; 
    }
    output << "\n";
    fileT.close();
  }

  else
  {
    throw std::logic_error("<INVALID COMMAND>\n\n");
  }
}