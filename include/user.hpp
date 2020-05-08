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
#include "coin.hpp"

#include <string>
#include <fstream>
#include <cassert>

using namespace std;

class user {

 public:
   user(void): user_name_(), passwd_(), logged_(false), wallet_() {}
   user(string user_name, string passwd);
   ~user(void) {}

   static database dataBase_; //Base de datos común (SOLO PARA DEMO)
   int login(void);

   string getName(void) { return user_name_; }
   float coins(void) { return wallet_.get_coins(); } //Devuelve cantidad en monedero
   //void updateWallet(float value) { wallet_.update(value); }

   //Movimientos de wallet
   bool add(float value);
   bool subtract(float value);
   bool debit(float value);

   //Database
   bool update_db(void); //Actualiza base de datos


 private:
    string user_name_;
    string passwd_; //ToDo: método de seguridad para que esté encriptada
    bool logged_;
    coin wallet_; //Monedero
};
