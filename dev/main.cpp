#include <iostream>
#include <cmath>
#include "../src/AES.h"
#include "../src/utils.h"

using namespace std;
int main(int argc, char** argv)
{
  if (argc != 2) {
    cout << "Usage:\n./bin/debug <encrypt/decrypt> <key>" << endl;
  }
  else if (argv[1][0] == 'e' && argv[1][1] == 'n' && argv[1][2] == 'c' && argv[1][3] == 'r' && argv[1][4] == 'y' && argv[1][5] == 'p' && argv[1][6] == 't') {
  string strMsg = utils::readFile("./dev/files/" + argv[2]);
  unsigned int remainder = strMsg.length() % 16;
  if (remainder != 0) {
    for (unsigned int i = 0; i < 16 - remainder; i++) {
      strMsg += '\0';
    }
  }
  AES aes(AESKeyLength::AES_256);

  string k = "123456789abcdef0123456789abcdef0";
  vector<unsigned char> key;
  for (unsigned int i = 0; i < k.length(); i++) {
    key.push_back((unsigned char)k[i]);
  }
  vector<unsigned char> msg;
  for (unsigned int i = 0; i < strMsg.length(); i++) {
    msg.push_back((unsigned char)strMsg[i]);
  }
  vector<unsigned char> c = aes.EncryptECB(msg, key);
  for (unsigned char q : c) {
    cout << q;
  }
  cout << endl;
    cout << argv[2] << endl;
  }
  else if (argv[1][0] == 'd' && argv[1][1] == 'e' && argv[1][2] == 'c' && argv[1][3] == 'r' && argv[1][4] == 'y' && argv[1][5] == 'p' && argv[1][6] == 't') {

  }
  else {
    cout << "Usage:\n./bin/debug <encrypt/decrypt> <key>" << endl;
  }
  return 0;
}
