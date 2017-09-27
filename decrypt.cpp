
#include<iostream>
#include<fstream>
#include<random>
#include<string.h>
#include<time.h>
#include<cstring>
#include<stdlib.h>

using namespace std;
class decrypt
{
	int k = 0;
public:
	decrypt(std::ifstream &input_file, std::ofstream &output_file, int _k);
	int getKey();
	void decryption(std::ifstream &input_file, std::ofstream &output_file);
	~decrypt();
};
decrypt::decrypt(std::ifstream &input_file, std::ofstream &output_file, int _k)
{
	//cout << "Decrypt constructor" << endl;
	k = _k;
	decrypt::decryption(input_file, output_file);
}
//getter method to get key. Not used here. But if this class in inherited, that subclass can call getKey()
int decrypt::getKey()
{
	return k;
}
decrypt::~decrypt()
{
	//cout << "Decrypt destructor" << endl;
	k = 0;
}
void decrypt::decryption(std::ifstream &input_file, std::ofstream &output_file)
{
	char c;
	input_file >> std::noskipws;
	while (!input_file.eof() && output_file.good()) {
		if(input_file.peek() == ifstream::traits_type::eof()) break;
		input_file >> c; output_file << char((c - k) % 255);
		//cout << char((c - k) % 255) << endl;
	}
}

int main(int argc, char* argv[])
{
	try 
	{
		char* input = argv[1];
		char* output = argv[2];
		std::ifstream inputfile;
		inputfile.open(input);
		std::ofstream outputfile;
		outputfile.open(output);
		int k = atoi(argv[3]);
		decrypt *e = new decrypt(inputfile, outputfile, k);
		//cout << e->getKey() << endl;
	}
	catch (std::ifstream::failure &e) {
		std::cout << "an error has occured in input file stream";
		return -1;
	}
	catch (...) {
		std::cout << "an error has occured in output file stream";
		return -1;
	}
	cout << "successfully Decrypted" << endl;
	return 0;
}