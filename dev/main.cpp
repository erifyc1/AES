#include <iostream>
#include <cmath>
#include <stdexcept>
#include "../src/AES.h"
#include "../src/utils.h"

using namespace std;
// string k = "123456789abcdef0123456789abcdef0";
int main(int argc, char** argv)
{
	if (argc != 4) {
		cout << "Usage:\n./bin/debug <encrypt/decrypt> <filename> <32-char key>" << endl;
		return 1;
	}
	string op = argv[1];
	if (op == "encrypt" || op == "decrypt") {
		bool encrypt = op == "encrypt";
		// extract filename
		string filename;
		for (unsigned int i = 0; argv[2][i] != '\0'; i++) {
			filename += argv[2][i];
		}
		// extract key
		vector<unsigned char> key;
		for (unsigned int i = 0; argv[3][i] != '\0'; i++) {
			key.push_back((unsigned char)argv[3][i]);
		}
		if (key.size() != 32) throw runtime_error("Invalid Key Length");

		if (encrypt) {
			// read file and insert padding
			string message = utils::readFile("./dev/files/" + filename);
			unsigned int remainder = message.length() % 16;
			if (remainder != 0) {
				for (unsigned int i = 0; i < 16 - remainder; i++) {
					message += '\0';
				}
			}

		   	// convert message to vector<unsigned char>
			vector<unsigned char> m;
			for (unsigned int i = 0; i < message.length(); i++) {
				m.push_back((unsigned char)message[i]);
			}

			// run encrypt
			AES aes(AESKeyLength::AES_256);
			vector<unsigned char> c = aes.EncryptECB(m, key);

			// convert to string and write to file
			string ciphertext; 
			for (unsigned char val : c) {
				ciphertext += val;
			}
			utils::writeFile("./dev/files/ciphertext.aes256", ciphertext);
			cout << "Successfully encrypted " << filename << endl;
		}
		else {
			// read file
			string ciphertext = utils::readFile("./dev/files/" + filename);

			// convert ciphertext to vector<unsigned char>
			vector<unsigned char> c;
			for (unsigned int i = 0; i < ciphertext.length(); i += 1) {
				c.push_back((unsigned char)ciphertext[i]);
			}

			// run decrypt
			AES aes(AESKeyLength::AES_256);
			vector<unsigned char> m = aes.DecryptECB(c, key);

			// convert to string and write to file
			string message;
			for (unsigned char val : m) {
				if (val != '\0') {
					message += val;
				}
			}
			utils::writeFile("./dev/files/decrypted_message.txt", message);
			cout << "Successfully decrypted " << filename << endl;
		}
	}
	else {
		cout << "Usage:\n./bin/debug <encrypt/decrypt> <key>" << endl;
	}
	return 0;
}
