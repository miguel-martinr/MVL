#include "../include/user.hpp"

database user::dataBase_;

user::user(string user_name, string passwd) {
  assert(!user_name.empty() && !passwd.empty());
  user_name_ = user_name;
  passwd_ = passwd;
  logged_ = false;
}

//Autenticarse en el sistema
int user::login(void) {
  if (logged_)
    return 0;
  float money;
  int id = dataBase_.authenticate(user_name_, passwd_, money);
  if (id == 0)
    logged_ = true;
  return id;
}

//Añadir monedas a wallet
bool user::add(float value) {
  wallet_.increment(value);
  return update_db();
}

//Retirar monedas de wallet (el valor debe ser menor o igual a la cantidad de monedas)
bool user::subtract(float value) {
  if (coins() < value)
    return false; //No hay suficientes monedas
  wallet_.decrement(value);
  return update_db(); //Éxito
}

//Adeudar (se sustraen monedas incluso si no hay suficientes, quedando en negativo la cuenta)
bool user::debit(float value) {
  wallet_.decrement(value);
  return update_db();
}

//Actualiza base de datos
bool user::update_db(void) {
  int i = 0;
  while ((i < dataBase_.get_sheet().size()) &&
         (user_name_ != dataBase_.get_sheet()[i].name)) //ToDo: Incluirla como método de database
         i++;
  if (i < dataBase_.get_sheet().size()) {
    dataBase_.get_sheet()[i].money = coins();
    return true;
  }
  return false;
}
