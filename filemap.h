#pragma once

#include <iostream>
#include <fstream>

#include <unordered_map>

class Filemap {
 public:
 Filemap(const std::string & filename) : path(filename) {
    refresh();
  }

  void refresh() {
    std::ifstream infile(path, std::ifstream::in);

    static const int buffer_size = 256;
    
    char buffer[buffer_size];	      
    
    while (!infile.eof()) {
      infile.getline(buffer, buffer_size);

      buffer[buffer_size - 1] = '\0';

      auto element = parseLine(std::string(buffer));

      if (element.first != "" && element.second != "") {
	map.insert(element);
      }
    }
  }

  void debug_display() const {
    std::cout << "Current map for " << path << std::endl;
  
    for (auto i : map) {
      std::cout << i.first << ": " << i.second << std::endl;
    }
  }
  
 private:
  static std::pair<std::string, std::string> parseLine(const std::string &
						       line) {
    std::pair<std::string, std::string> result("", "");

    std::string key, value;

    size_t eqPos = line.find('=');

    if (eqPos > 0 && eqPos != std::string::npos) {
      key = line.substr(0, eqPos);
      value = line.substr(eqPos + 1, line.length() - eqPos);

      result.first = key;
      result.second = value;
    }    
    
    return result;
  }
  
  Filemap() {}
  
  std::unordered_map<std::string, std::string> map;

  const std::string path;
};

static const std::string test_fm_contents = "hello world\n"
  "test2=goronberry\n" "test1=45\n" "test3=8.6\n";

int test_filemap() {
  const std::string tmpFilename = "test_filemap_TestFile.fm";

  std::ofstream tmpfile(tmpFilename, std::ios::out);

  tmpfile.write(test_fm_contents.data(), test_fm_contents.size());

  tmpfile.close();
  
  Filemap fmap(tmpFilename);

  fmap.debug_display();
}
