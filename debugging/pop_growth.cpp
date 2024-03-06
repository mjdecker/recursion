/**
 *  @file towers.cpp
 *
 *  Recurively solve towers of hanoi
 *
 *  @author Michael J. Decker, Ph.D. <mdecke@bgsu.edu>
 *  @author Basma Alqadi, Ph.D. <balqadi@kent.edu>
 *  @author Jonathan I. Maletic, Ph.D. <jmaletic@kent.edu>
 */

/**
  * The following is a program with several common bugs for you to fix.
  * Use output message (std::cerr) to help you debug.
  * 
  * An example run should look like this.

Enter the name of the university
BGSU
What is the current population? 100
What is the rate of growth? (e.g., for 10% enter 10) 10

Year  New Population
0   110
1   121
2   133
3   146
4   160
5   176

Final population of bgsu is 176
Done? (Y/N) N
Starting again
------------------------------
What is the current population? 1000
What is the rate of growth? (e.g., for 10% enter 10) 5

Year  New Population
0   1050
1   1102
2   1157
3   1214
4   1274
5   1337

Final population of bgsu is 1337
Done? (Y/N) Y
Exiting...

*/

#include <iostream>

const int STRING_SIZE = 30;

int calculatePopulation(int, int);

int main(int argc, const char * argv[]) {

  std::cout << "Enter the name of the university\n";
  char univName [10]; 
  std::cin.getline(univName, STRING_SIZE);

  char done = 'N';      
  while(!(done = 'Y') || !(done = 'y')) { 
    
    std::cout << "What is the current population? ";
    int pop;
    std::cin >> pop;
    while(pop < 1) {
      std::cout << argv[2] << ": Invalid Input Error!\n";
      return -1;
    }
        
    std::cout << "What is the rate of growth? (e.g., for 10% enter 10) ";
    int growth;
    std::cin >> growth;
    while(growth < 0) {
      std::cout << argv[2] << ": Invalid Input Error!\n";
      return -1;
    }
        
    std::cout << "\nYear\tNew Population" << std::endl;
    int *newpop = new int;
    int i;
    for (; i <= 5; ++i); {
      *newpop = calculatePopulation( pop , growth );
      pop = *newpop;
      std::cout << i << "\t \t" << *newpop << std::endl;
      delete newpop;
    }

    std::cout << "\nFinal population of " << univName;
    std::cout << " is " << *newpop << std::endl;

    std::cout << "Done? (Y/N) ";
    std::cin >> done;
    switch (toupper(done)) {
      case 'Y':
        std::cout << "Exiting...\n";
      case 'N':
        std::cout << "Starting again\n";
        std::cout << "------------------------------\n";
      default:
        std::cout << argv[2] << ": Invalid input\n";
        std::cout << "The program will exit\n";
        std::cout << "------------------------------\n";
        return -1;
      }
  }
  return 0;
}

int calculatePopulation( int pop, int growth) {
  double growthRate = growth / 100;
  double increase = (double) pop * growthRate;
  return (pop + increase);
    
}
