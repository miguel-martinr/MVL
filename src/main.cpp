#include <iostream>
#include <cassert>

#include "../include/user.hpp"
#include "../include/database.hpp"
#include "../include/coin.hpp"

using namespace std;

int menu1()
{
  int opt;
  cout << "\tMENU PRINCIPAL" << endl << endl;
  cout << "1.Iniciar secion" << endl;
  cout << "2.Registrarte" << endl;
  
  cin >> opt;
  
  return opt;
}


int menu2()
{
  int opt;
  cout << "\tMENU" << endl << endl;
  cout << "1.Ver catalogo (No disponible)" << endl;
  cout << "2.Añadir servicio al catalogo (No disponible)" << endl;
  cout << "3.Borrar servicio del catalogo (No disponible)" << endl;
  
  cin >> opt;
  
  return opt;
}

int main()
{
  string dataFile = "cfg/test/test1.psw";
  user::dataBase_ = database(dataFile);
  user userOne();

  int opt1, opt2;
  string username, passwd;
  bool log = false; // Comprobacion del login
  bool foo = false; // Comprobacion del registro

  opt1 = menu1();
  
  switch(opt1){
    case 1:
      cout << "\tIniciar Secion" << endl;
      cout << "Introduce el nombre de usuario" << endl;
      cin >> username;
      cout << "Introduce la contraseña" << endl;
      cin >> passwd;
   
      userOne = login(username, passwd);
      log = userOne.login();
      if(log){
        cout << "Inicio de secion completado satisfactoriamente." << endl;
      }else{
        cout << "No se pudo iniciar secion" << endl;
        opt1 = menu1();
      }
      
      break;
    case 2:
      cout << "\tRegistrarse" << endl;
      cout << "Introduce el nombre de usuario" << endl;
      cin >> username;
      cout << "Introduce la contraseña" << endl;
      cin >> passwd;
      
      foo = user::dataBase_.signIn(username,passwd, 7.59);
      if(foo){
        cout << "Registro completado satisfactoriamente." << endl;
      }else{
        cout << "No se pudo realizar el registro" << endl;
      }
      
      opt1 = menu1();
      break;
    default:
      cout << "La opcion introducida no esta disponible." << endl;
      opt1 = menu1();
      break;
  }
  
  opt2 = menu2();

  if (log){
    cout << userOne.getName() << endl;
    cout << "Saldo actual: " << userOne.coins() << endl;
    switch(opt2){
      case 1:
        cout << "La opcion introducida no esta disponible." << endl;
        break;
      case 2:
        cout << "La opcion introducida no esta disponible." << endl;
        break;
      case 3:
        cout << "La opcion introducida no esta disponible." << endl;
        break;

      default:
        cout << "La opcion introducida no esta disponible." << endl;
        opt2 = menu2();
        break;
    }
  }
}
