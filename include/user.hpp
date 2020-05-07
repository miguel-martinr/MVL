/**********************************************************************
* Project           : plataforma MVL (Moneda Virtual Local)
*
* Class             : User (usuario)
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
#pragma once

#include <string>
#include <fstream>
#include <cassert>

using namespace std;

class user {

 public:
   user(string user_name, string passwd);
   ~user(void) {}

   static string dataBase_; //Nombre del fichero data base
   int authenticate(void);
   void what(void);


 private:
    string user_name_;
    string passwd_; //ToDo: método de seguridad para que esté encriptada
    //Monedero | puntero?
};
