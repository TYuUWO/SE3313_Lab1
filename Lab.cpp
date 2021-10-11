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

pid_t createChild(){
	pid_t childPid = fork(const char* program, char** arg_list);
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
	string program_name ("ChildThread.cpp");
	string fileName;
	string userData;
	char *arg_list[] = {program_name.data(), fileName, userData, nullptr};
	if (!exists(program_name)){
        	cout << "Program file 'child' does not exist in current directory!\n";
        	exit(EXIT_FAILURE);
    	}
	int i = 0;
	vector<int> children;
    	children.reserve(5); //start with a vector of size 5; size will increase when needed on its own
	while(userData != "Done"){ //If its finite it would terminate at 5
		cout << "Type something below. Type \"Done\" to exit."<< endl;
		cin >> userData;
		childern.push_back(createChild(program_name.c_str, arg_list));
		printf("Child with ForkID %d\n", childern[i]);
		createFile("FileNo" + i);
		i++;
		printf("There is %d array element(s)",i);
		}
	for (int i = 0; i < children.size(); ++i) {
        	kill(children[i], SIGTERM); //kill all child threads
   	}
	return EXIT_SUCCESS;
	}
