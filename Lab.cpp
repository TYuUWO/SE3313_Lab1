#include <iostream>
#include <fstream>
#include <unistd.h>
#include <stdlib.h>
#include <chrono>
#include <thread>

using namespace std;
int createFile(string fileName) { //This should just create the file
	std::ofstream MyFile("file" + std::to_string(getpid()) + ".txt");
	MyFile << fileName << endl;
	
	return 0;
}

int writeToFile(string userData) {
	sleep(1);
	//Can you put code that writes to a file here 
	return 0;
}

pid_t createChild(){
	pid_t childPid = fork();
	if(childPid < 0){
		perror("Fork Failed");
		exit(EXIT_FAILURE);
	}
	else{
		printf("Child with pid %d\n",(int)getpid());
		return childPid;
	}
}

int main() {
	string userData;
	int i = 0;
	int childern [5] = {};
	while(userData != "Done"){ //If its finite it would terminate at 5
		i++;
		cout << "Type something below. Type \"Done\" to exit."<< endl;
		cin >> userData;
		childern [i -1] = createChild();
		printf("Child with ForkID %d\n",childern [i-1]);
		cout << i;
		createFile("FileNo" + i);
		}
	return EXIT_SUCCESS;
	}
