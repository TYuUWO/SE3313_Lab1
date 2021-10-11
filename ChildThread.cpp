#include <iostream>
#include <fstream>
#include <unistd.h>
#include <stdlib.h>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;

int writeToFile(string userData, string fileName) {
	sleep(1);
  cout<<"writing to file..."<<endl;
	//Can you put code that writes to a file here 
	return 0;
}
int main(string userData, string fileName){
  while(true){
    writeToFile(userData, fileName)
  }
}
