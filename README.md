# MVL
Plataforma de moneda virtual (Simulador simple)

Formato del data base:


nº de líneas
username password monedero
username password monedero
username password monedero
.
.
.


Inicialización de la base de datos:
  string datafile = "ruta del fichero de datos"
  user::dataBase_ = database(string datafile);


Para hacer un login:
  database previamente inicializado.
  user userVar(string username, string password);

  if (userVar.login())
    Se ha loggeado correctamente
    else
    No se ha loggeado correctamente


Para registrar nuevo usuario:
  database previamente inicializado.
  if (user::dataBase_.signIn(string username,string password))
    Registrado correctamente
    else
    No registrado




Notas:
  *No se aceptan nombres de usuario o contraseñas vacías
