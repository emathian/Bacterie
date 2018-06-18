#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(){
  std::ofstream outfile ("new.csv",ios::app);
  // write to outfile

  char state ='0';
  int T = 1500;
  int Ainit = 50;
  outfile << state << ";" << T << ";" << Ainit << endl;



  return 0;
}
