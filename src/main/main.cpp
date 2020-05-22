/**********************************************************************
* Project           : plataforma MVL (Moneda Virtual Local)
*
* Main              : Prototipo rudimentario para simular el funcionamiento
                      de la paltaforma de moneda virtual local.
*
* Author            : Edgar Negrín González
* e-mail            :
* github            :
*
* Date created      : 20200507
*
* References  :
*
*
*
* Revision History  :
*
* Date        Author              Ref    Revision
* 20200507    Edgar Negrín         1      ...
* 20200522    Miguel Martín        2      Factorización main
**********************************************************************/
#include "../../include/user.hpp"
#include "../../include/database.hpp"
#include "../../include/coin.hpp"
#include "../../include/termcolor.hpp"

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <string>

int ask_menu_inical(void);
bool handle_inicial(int option, user& myUser, bool& quit);
int handle_user(int option, bool& quit);
string err_inicio_sesion(int code);
int ask_menu_user(void);



int main(void) {

  string dataFile = "cfg/test/test1.psw";
  user::dataBase_ = database(dataFile); // Carga base de datos (provisional)
  int option;
  user myUser;
  bool handled = false, quit = false;

  while (!quit) {
    while (!handled && !quit) {
      option = ask_menu_inical();
      handled = handle_inicial(option,myUser,quit);
    }

    cout << endl << endl;

    bool go_back = false;
    while (!go_back && !quit) {
      cout << termcolor::cyan << "\n\nUsuario:  " << termcolor::reset << myUser.getName() << endl;
      cout << termcolor::cyan << "Monedero: " << termcolor::reset << myUser.coins() << endl;
      cout << termcolor::green << "  ONLINE  " << termcolor::reset << endl;
      option = ask_menu_user();
      handle_user(option, go_back);
    }
    handled = false;
}


  return 0;
}















int ask_menu_inical(void) {
  int opt;
  cout << "\n\n                         "
       << termcolor::on_blue  <<"Plataforma Moneda Virtual Local (MVL)"
       << termcolor::reset << endl << endl;
  cout << '\t' << termcolor::reverse << "MENÚ PRINCIPAL" << termcolor::reset
       << endl << endl;
  cout << "1.Iniciar sesión" << endl;
  cout << "2.Registrarte" << endl;
  cout << "3.Salir" << endl;

  cin >> opt;

  return opt;
}

bool handle_inicial(int option, user& myUser, bool& quit) {
  string username, psw;
  int err;
  bool signedUp;
  switch (option) {
    case 1: // Iniciar sesión
      cout << '\t' << termcolor::reverse << "Iniciar Sesión"
           << termcolor::reset << endl;
      cout << "Introduce el nombre de usuario > ";
      cin >> username;
      cout << "Introduce la contraseña > ";
      cin >> psw;
      myUser = user(username,psw);
      err = myUser.login();
      cout << termcolor::on_red  << err_inicio_sesion(err)
           << termcolor::reset << endl;
      break;
    case 2:
      cout << "\tRegistrarse" << endl;
      cout << "Introduce el nombre de usuario > ";
      cin >> username;
      cout << "Introduce la contraseña > ";
      cin >> psw;

      signedUp = user::dataBase_.signIn(username,psw, 0);
      if(signedUp){
        cout << termcolor::on_green << "Registro completado satisfactoriamente."
             << termcolor::reset << endl;
      }else{
        cout << termcolor::on_red << "No se pudo realizar el registro"
             << termcolor::reset << endl;
      }
      break;
      case 3:
        quit = true;
      break;
    default:
      cout << termcolor::on_red << err_inicio_sesion(-1)
           << termcolor::reset << endl;

  }
  if (err != 0)
    return false;
  return true;
}


int handle_user(int option, bool& quit) {
  switch (option) {
    case 4:
      quit = true;
      break;
    default:
      cout << termcolor::on_red << err_inicio_sesion(-1) << termcolor::reset;
  }
  return 0;
}


string err_inicio_sesion(int code) {
  switch (code) {
    case 0:
      return "Inicio de sesión completado satisfactoriamente.";
    case 1:
      return "Nombre de usuario incorrecto.";
    case 2:
      return "Contraseña incorrecta.";
    default:
      return "Opción no esperada :'(";
  }
}


int ask_menu_user(void) {
  int opt;
  cout << endl << endl << "\tMENU" << endl << endl;
  cout << "1.Ver catalogo (No disponible)" << endl;
  cout << "2.Añadir servicio al catalogo (No disponible)" << endl;
  cout << "3.Borrar servicio del catalogo (No disponible)" << endl;
  cout << "4.Cerrar sesión" << endl;

  cin >> opt;

  return opt;
}
