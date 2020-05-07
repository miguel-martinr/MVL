#include "../include/user.hpp"

user::user(string user_name, string passwd) {
  assert(!user_name.empty() && !passwd.empty());
  user_name_ = user_name;
  passwd_ = passwd;
  what();
}

int user::authenticate(void) {
  ifstream dataFile(dataBase_, ios::in);
  assert(dataFile.is_open() && "Error al conectar con base de datos...");
  string nameAux, pswAux;

  while ((nameAux != user_name_) && (!dataFile.eof())) {
    dataFile >> nameAux >> pswAux;
  }
  if (dataFile.eof())
    return 1; // Nombre de usuario no existe
  if (pswAux != passwd_)
    return 2; // Combinación incorrecta de usuario y contraseña

  return 0; // Autenticado
}

void user::what(void) {
  switch (authenticate()) {
    case 1:
      assert(false && "Error: Nombre de usuario no existe");
      break;
    case 2:
      assert(false && "Error: Combinación incorrecta de usuario y contraseña");
      break;
    default:
      break;
  }
}
