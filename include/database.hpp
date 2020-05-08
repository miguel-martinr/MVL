/**********************************************************************
* Project           : plataforma MVL (Moneda Virtual Local)
*
* Class             : database (base de datos simple)
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

#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct line {
  line(void): name(), psw(), money() {}
  line (string name_, string psw_, float money_): name(name_), psw(psw_),
                                                money(money_) {}

  string name;
  string psw;
  float money;

};


class database {
 public:
   database(void): lines_(0), sheet_(), file_name_() {}
   database(string file_name);
   ~database(void);

   // Carga datos desde un fichero
   int load(string file_name);
   // Almacena los datos en un fichero
   int store(string file_name);

   // Autentica un usuario
   int authenticate(string name, string psw, float& money);

   // Registra una nueva entrada (usuario) en la base de datos
   bool signIn(string name, string psw, float money);

   vector<line>& get_sheet(void) { return sheet_; }


 private:
   int lines_; //ToDo: deshacerte de este atributo, usar sheet_.size()
   vector<line> sheet_;
   string file_name_;

};
