#include <iostream>
#include <cmath>
#include "../src/AES.h"
#include "../src/utils.h"

using namespace std;
int main(int argc, char** argv)
{
  if (argc <= 1) {
    cout << "too few parameters" << endl;
  }
  else {
    cout << argv[1] << endl;
  }
  string strMsg = utils::readFile("./dev/files/test.txt");
  cout << strMsg << endl;
  AES aes(AESKeyLength::AES_256);
  string key = "123456789abcdef0123456789abcdef0";
  unsigned char *key = new char[]
  for (unsigned int i = 0; i < key.length(); i += 2) {
    cout << stoi(key.substr(i, 2), nullptr, 16) << endl;
  }
  // const char* msg = strMsg.c_str();
  // unsigned char c = aes.EncryptECB(msg, strMsg.length(), key);
  // cout << c << endl;
  return 0;
}
