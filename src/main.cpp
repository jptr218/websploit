#include "websploit.h"

int main(int argc, char* argv[]) {
	if (argc != 3) {
		cout << "Usage:" << endl << "websploit [url] [param]" << endl << "websploit info [exploit]";
		return 0;
	}
	
	vector<exploit> exploits = initExploits();

	if (string(argv[1]) == "info") {
		exploit i = vec_find(exploits, argv[2]);
		if (i.name == "ns") {
			cout << "The specified exploit could not be found. Are you sure that you've typed it right?" << endl;
			return 1;
		}
		cout << i.desc << endl;
		return 1;
	}

	string url = argv[1];
	string param = argv[2];

	cout << "Connecting to website...\r";
	if (!testConnect(url)) {
		cout << "The specified website doesn't exist. Are you sure that you've typed it correctly?" << endl;
		return 0;
	}

	cout << "Finding exploits...                 " << endl;
	bool foundExploit = false;
	for (exploit e : exploits) {
		cout << "Testing for " << e.name << "...";
		for (int i = 0; i < 50; i++) {
			cout << " ";
		}
		cout << "\r";
		if (testExploit(e, url, param)) {
			foundExploit = true;
			cout << "EXPLOIT FOUND: " << e.name << endl;
		}
	}

	if (!foundExploit) {
		cout << "Failed to find any exploits in the specified url. Maybe you should try and search manually?" << endl;
	}
	else {
		cout << "Websploit analysis excecuted successfully." << endl;
	}

	return 1;
}