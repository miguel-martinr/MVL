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

  //Login
  user userOne("miguel", "1234");
  bool foo = userOne.login();


 //SignIn
  bool sign = user::dataBase_.signIn("Raúl", "raulpsw", 13);


 //Movimientos de wallet
  user userTwo("Pepito", "pepitopsw");
  userTwo.login();
  cout << "Monedero de Pepito: " << userTwo.coins() << endl;
  userTwo.add(5);
  cout << "Añadimos 5 monedas: " << userTwo.coins() << endl;
  userTwo.subtract(3);
  cout << "Quitamos 3 monedas: " << userTwo.coins() << endl;
  userTwo.debit(10);
  cout << "Debitamos 10 monedas: " << userTwo.coins() << endl;

  cout << "stop" << endl;

  return 0;
}
