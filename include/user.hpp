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

#include "database.hpp"

#include <string>
#include <fstream>
#include <cassert>

using namespace std;

class user {

 public:
   user(void): user_name_(), passwd_(), logged_(false) {}
   user(string user_name, string passwd);
   ~user(void) {}

   static database dataBase_; //Base de datos común
   int login(void);

   string getName(void) { return user_name_; }

 private:
    string user_name_;
    string passwd_; //ToDo: método de seguridad para que esté encriptada
    //Monedero | puntero?
    bool logged_;
};
