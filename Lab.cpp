#include <iostream>
#include <string>
#include <filesystem>
//#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(){
	string userData;
	while (userData != "Done"){
		cout<<"Type something below. Type \"Done\" to exit." << endl;
		cin>> userData;
		
		/*
		//this code goes at the bottom right above terminateChildren()
		std::transform(userData.begin(), userData.end(), userData.begin(), ::tolower);
		std::size_t found = outputLine.find("found");
		if (found != string::npos){
			break;
	}
		*/
		//write a line to terminate child threads here
	}
	return 0;
}

//comment to test github pull
