/**********************************************************************
* Project           : plataforma MVL (Moneda Virtual Local)
*
* Main
*
* Author            : Miguel Alejandro Martín Reyes (miguel-martinr)
* e-mail            : alu0101209777@ull.edu.es
* github            : https://github.com/miguel-martinr
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
* 20200507    miguel-martinr      1      ...
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
  cout << "\tMENU PRINCIPAL" << endl << endl;
  cout << "1.Iniciar secion" << endl;
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
  bool log = false; // Comprobacion del login
  bool foo = false; // Comprobacion del registro

  while(!log){
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
        if(log){
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

        foo = user::dataBase_.signIn(username,passwd, 7.59);
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
      if(log){
        cout << "Inicio de sesión completado satisfactoriamente." << endl;
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

      foo = user::dataBase_.signIn(username,passwd, 7.59);
      if(foo){
        cout << "Registro completado satisfactoriamente." << endl;
      }else{
        cout << "No se pudo realizar el registro" << endl;
      }
      break;

    default:
      cout << "La opcion introducida no está disponible." << endl;
      break;
  }

  bool salir = false;

  while(!salir){
    system("clear");
    if (log){
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
    }
  }
  return 0;
}
