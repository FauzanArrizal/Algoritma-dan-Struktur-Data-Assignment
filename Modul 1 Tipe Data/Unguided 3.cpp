#include <iostream>
#include <map>

int main() {
  // Deklarasi
  std::map<int, std::string> mapEG;

  // Insert
  mapEG[1] = "Spidol";
  mapEG[2] = "Pulpen";
  mapEG[3] = "Pensil";

  std::cout << "Value at key 1: " << mapEG[1] << std::endl;
  std::cout << "Value at key 2: " << mapEG[2] << std::endl;
  std::cout << "Value at key 3: " << mapEG[3] << std::endl;

  return 0;
}
