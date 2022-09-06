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
  AES aes(AESKeyLength::AES_128);
  string key = "123456789abcdef0";
  for (char c : key) {
    cout << stoi(c) << endl;
  }
  // const char* msg = strMsg.c_str();
  // unsigned char c = aes.EncryptECB(msg, strMsg.length(), key);
  // cout << c << endl;
  return 0;
}
