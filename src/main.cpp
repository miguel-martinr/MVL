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
* 20200507    Edgar Negrín      1      ...
*
**********************************************************************/
#include <iostream>
#include <cassert>

#include "stdlib.h"

#include "../include/user.hpp"
#include "../include/database.hpp"
#include "../include/coin.hpp"

using namespace std;

int menu1()
{
  int opt;
  system("clear");
  cout << "                         Plataforma Moneda Virtual Local (MVL)\n\n";
  cout << "\tMENÚ PRINCIPAL" << endl << endl;
  cout << "1.Iniciar sesión" << endl;
  cout << "2.Registrarte" << endl;
  cout << "3.Salir" << endl;

  cin >> opt;

  return opt;
}


int menu2()
{
  int opt;
  cout << endl << endl << "\tMENU" << endl << endl;
  cout << "1.Ver catalogo (No disponible)" << endl;
  cout << "2.Añadir servicio al catalogo (No disponible)" << endl;
  cout << "3.Borrar servicio del catalogo (No disponible)" << endl;
  cout << "4.Salir" << endl;

  cin >> opt;

  return opt;
}

user login(string username, string passwd)
{
  user userOne(username, passwd);
  return userOne;
}

int main()
{
  string dataFile = "cfg/test/test1.psw";
  user::dataBase_ = database(dataFile);
  user userOne;

  int opt1, opt2;
  string username, passwd;
  int log = -1; // Comprobacion del login
  bool foo = false; // Comprobacion del registro

  while(log != 0 && !foo){
    opt1 = menu1();

    switch(opt1){
      case 1:
        system("clear");
        cout << "\tIniciar Sesión" << endl;
        cout << "Introduce el nombre de usuario" << endl;
        cin >> username;
        cout << "Introduce la contraseña" << endl;
        cin >> passwd;

        userOne = login(username, passwd);
        log = userOne.login();
        if(log == 0){
          cout << endl << "Inicio de sesión completado satisfactoriamente." << endl;
        }else{
          cout << "No se pudo iniciar sesión" << endl;
        }
        break;

      case 2:
        cout << "\tRegistrarse" << endl;
        cout << "Introduce el nombre de usuario" << endl;
        cin >> username;
        cout << "Introduce la contraseña" << endl;
        cin >> passwd;

        foo = user::dataBase_.signIn(username,passwd, 0);
        if(foo){
          cout << "Registro completado satisfactoriamente." << endl;
        }else{
          cout << "No se pudo realizar el registro" << endl;
        }
        break;

      case 3:
        return 0;
        break;

      default:
        cout << "La opción introducida no está disponible." << endl;
        break;
    }
  }


  bool salir = false;

  while(!salir){
    system("clear");
    if (log == 0){
      cout << endl << endl << userOne.getName() << endl;
      cout << "Saldo actual: " << userOne.coins() << endl;
      opt2 = menu2();

      switch(opt2){
        case 1:
          cout << "La opción introducida no está disponible." << endl;
          break;

        case 2:
          cout << "La opción introducida no está disponible." << endl;
          break;

        case 3:
          cout << "La opción introducida no está disponible." << endl;
          break;

        case 4:
          salir = true;
          break;

        default:
          cout << "La opción introducida no está disponible." << endl;
          break;
      }
    } else if (foo) {
      cout << "Registrado correctamente. Reinicie el sistema :(" << endl;
      salir = true;
    }
  }
  return 0;
}
