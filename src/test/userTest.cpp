#include "../../include/user.hpp"
#include "../../include/database.hpp"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int main(void) {

//database myDB("cfg/test/test1.psw");
//  myDB.get_sheet()[2].name = "Modificado";

  string dataFile = "cfg/test/test1.psw";
  user::dataBase_ = database(dataFile);

  user userOne("miguel", "123");
  bool foo = userOne.login();
  bool sign = user::dataBase_.signIn("Pepito", "pepitopsw", 5);
  cout << "stop" << endl;

  return 0;
}
