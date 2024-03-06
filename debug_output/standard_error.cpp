#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>
#include <stdlib.h>

int main() {
  unsigned int min = 100000;
  unsigned int max = 500000;

  std::vector<std::string> lyrics;
  lyrics.push_back("Never gonna give you up\n");
  lyrics.push_back("Never gonna let you down\n");
  lyrics.push_back("Never gonna run around and desert you\n");
  lyrics.push_back("Never gonna make you cry\n");
  lyrics.push_back("Never gonna say goodbye\n");
  lyrics.push_back("Never gonna tell a lie and hurt you\n");

  while (true){
    for (int i = 0; i < lyrics.size(); ++i) {
      for(int j = 0; j < lyrics[i].size(); ++j) {
	unsigned randNum = rand()%(max-min + 1) + min;
	usleep(randNum);
	std::cerr << lyrics[i][j];
      }
    }
  }  

  return 0;

}
