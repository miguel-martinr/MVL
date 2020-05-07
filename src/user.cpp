#include "../include/user.hpp"

database user::dataBase_;

user::user(string user_name, string passwd) {
  assert(!user_name.empty() && !passwd.empty());
  user_name_ = user_name;
  passwd_ = passwd;
  logged_ = false;
}


int user::login(void) {
  if (logged_)
    return true;
  int money;
  if (dataBase_.authenticate(user_name_, passwd_, money)) 
    logged_ = true;
    //
    //Actualizar monedero
    //


  return logged_;
}
