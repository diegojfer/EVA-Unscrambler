#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char ** argv){
	if (argc < 2){
		cout << "encoded data not found!" << endl;
		return 0;
	}

	string data = string(argv[1]);
	string content = "";
	uint32_t key = 50;
	
	for (int i = 0; i < data.length(); i += 2){
		uint32_t c = stoul(data.substr(i, 2), NULL, 16) ^ key;
		content += (char)c;
		
		key = key + c & 0xFF;
	}
	content = string(content.rbegin(), content.rend());
	
	cout << content << endl;
	
	return 0;
}
