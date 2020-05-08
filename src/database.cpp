#include "../include/database.hpp"

#include <cassert>
#include <iostream>

database::database(string file_name) {
  file_name_ = file_name;
  load (file_name_);
}

database::~database(void) {
  store(file_name_);
}


// Autentica un usuario
int database::authenticate(string name, string psw, float& money) {
  int i = 0;
  while ((sheet_[i].name != name) && (i < sheet_.size()))
    i++;

  if (i == sheet_.size())
    return 1; // Usuario no encontrado

  if (psw != sheet_[i].psw)
    return 2; //Contraseña incorrecta

  money = sheet_[i].money;

  return 0;
}

// Registra una nueva entrada (usuario) en la base de datos
bool database::signIn(string name, string psw, float money) {
  assert(!name.empty() && "Nombre de usuario no puede estar vacío!");
  assert(!psw.empty() && "Contraseña no puede estar vacía!");
  for (auto anUser : sheet_)
    if (anUser.name == name)
      return false; // Nombre de usuario no disponible
  line newUser(name, psw, money);
  std::cout << "Money" << newUser.money << std::endl;
  sheet_.push_back(newUser);
  return true;
}

// Carga datos desde un fichero
int database::load(string file_name) {
  ifstream file(file_name, ios::in);
  assert(file.is_open() && "Error al conectar con la base de datos");
  string name,psw;
  float money;
  file >> lines_;
  sheet_.resize(lines_);
  for (int i = 0; i < lines_; i++) {
    file >> name >> psw >> money;
    sheet_[i].name = name;
    sheet_[i].psw = psw;
    sheet_[i].money = money;
  }

  file.close();
  return 0;
}

// Almacena los datos en un fichero
int database::store(string file_name) {
  ofstream file(file_name);
  assert(file.is_open() && "Error al conectar con la base de datos");
  file << sheet_.size() << endl;
  for (int i = 0; i < sheet_.size(); i++) {
    file << sheet_[i].name << ' ' << sheet_[i].psw << ' ' << sheet_[i].money
         << endl;
  }

  file.close();
  return 0;
}
