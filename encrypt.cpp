
#include<iostream>
#include<fstream>
#include<random>
#include<string.h>
#include<time.h>
#include<cstring>
#include<stdlib.h>

using namespace std;
class encrypt
{
	int k=0;
	int generateKey();

public:
	encrypt(std::ifstream &input_file, std::ofstream &output_file);
	int getKey();
	void encryption(std::ifstream &input_file, std::ofstream &output_file);
	~encrypt();
};
encrypt::encrypt(std::ifstream &input_file, std::ofstream &output_file)
{
	//cout << " Encrypt constructor " << endl;
	k = generateKey();
    encrypt::encryption( input_file,  output_file);
}
int encrypt::getKey()
{
	return k;
}
encrypt::~encrypt()
{
	//cout << "Encrypt destructor" << endl;
	k = 0;
}
int encrypt::generateKey()
{
	//cout << "generating Key" << endl;
	srand(time(NULL));
	int generated_key = rand() % 64 + 1;
	cout << " Generated_key  is  " << generated_key << endl;
	if (generated_key != 32)
		return generated_key;
	return generateKey();
}	
void encrypt::encryption(std::ifstream &input_file, std::ofstream &output_file)
{
	char c;
	//cout << "encryption called" << endl;
	input_file >> std::noskipws;
	while (!input_file.eof() && output_file.good()) { 
		if (input_file.peek() == ifstream::traits_type::eof()) break;
	input_file >> c; output_file << char((c+k)%255);
	}
}

int main(int argc, char *argv[])
{
	try 
	{
		char* input = argv[1];
		char* output = argv[2];
		std::ifstream inputfile;
		inputfile.open(input);
		std::ofstream outputfile;
		outputfile.open(output);
		encrypt *e = new encrypt( inputfile,  outputfile);
		//cout<<e->getKey()<<endl;


	}
	catch (std::ifstream::failure &e) {
		std::cout << "an error has occured in input stream";
		return -1;
	}
	catch (...) {
		std::cout << "an error has occured in output stream";
		return -1;
	}
	cout << "successfully Encrypted" << endl;
	return 0;
}