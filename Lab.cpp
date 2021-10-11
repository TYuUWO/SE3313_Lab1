#include <iostream>
#include <fstream>
#include <unistd.h>
#include <stdlib.h>
#include <vector>
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
	else if (ch_pid > 0) {
        	cout << "spawn child with pid - " << ch_pid << endl;
        	return ch_pid;
    	} else {
       		execve(program, arg_list, nullptr);
        	perror("execve");
        	exit(EXIT_FAILURE);
    	}
}

int main() {
	string program_name ("ChildThread");
	if (!exists(program_name)){
        	cout << "Program file 'child' does not exist in current directory!\n";
        	exit(EXIT_FAILURE);
    	}
	string userData;
	int i = 0;
	vector<int> children;
    	children.reserve(5); //start with a vector of size 5; size will increase when needed on its own
	while(userData != "Done"){ //If its finite it would terminate at 5
		cout << "Type something below. Type \"Done\" to exit."<< endl;
		cin >> userData;
		childern [i] = createChild();
		printf("Child with ForkID %d\n", childern[i]);
		createFile("FileNo" + i);
		i++;
		printf("There is %d array element(s)",i);
		}
	return EXIT_SUCCESS;
	}
