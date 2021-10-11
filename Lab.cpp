#include <iostream>
#include <fstream>
#include <unistd.h>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include <vector>
#include <signal.h>
#include <algorithm>

using namespace std;
namespace{
	volatile sig_atomic_t shutdownSig = 1;
}
int createFile(string fileName) { //This should just create the file
	std::ofstream MyFile("file" + std::to_string(getpid()) + ".txt");
	MyFile << fileName << endl;
	
	return 0;
}

void Exit(int signalNumber){
	shutdownSig = 0;
}

pid_t createChild(string userData){
	pid_t childPid = fork();
	string testDone = userData;
	std::transform(testDone.begin(), testDone.end(), testDone.begin(), ::tolower);
	if (testDone == "done"){
		exit(EXIT_SUCCESS);
	}
	if(childPid < 0){
		perror("Fork Failed");
		exit(EXIT_FAILURE);
	}
	else if(childPid > 0){
		printf("Child with pid %d\n",(int)getpid());
		return childPid;
	}
	else{
		cout << "printed from child process " << getpid() << endl;
		createFile("FileNo" + getpid());
		string fileName = ("file" + to_string(getpid())+".txt");
		ofstream childFile;
		childFile.open(fileName);
		while (shutdownSig){
			signal(SIGTERM, Exit);
			cout<< "writing: " + userData <<endl;
			sleep(1);
			childFile << userData + "\n";
		}
		childFile.close();
        	exit(EXIT_SUCCESS);
	}
}

int main() {
	string userData;
	int i = 0;
	vector<int> children;
	children.reserve(5);
	string testDone = userData;
	while(userData != "done"){ //If its finite it would terminate at 5
	std::transform(testDone.begin(), testDone.end(), testDone.begin(), ::tolower);
		i++;
		cout << "Type something below. Type \"Done\" to exit."<< endl;
		cin >> userData;
		cout << "this is the parent thread \n";
		children.push_back(createChild(userData));
		printf("Child with ForkID %d\n",children [i-1]);
		cout << i << endl;
		//createFile("FileNo" + i);
		}
	for (int j=0; j<children.size(); j++){
		kill(children[j], SIGTERM);
	}
	return EXIT_SUCCESS;
	}
