# MVL
Plataforma de moneda virtual (Simulador simple)


Para usuarios:

uso:

  make
  bin/main
























Para desarroladores:


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

  códigos de retorno:
   0.Login correcto
   1.Usuario no encontrado
   2.contraseña incorrecta


Para registrar nuevo usuario:
  database previamente inicializado.
  if (user::dataBase_.signIn(string username,string password))
    Registrado correctamente
    else
    No registrado




Notas:
  *No se aceptan nombres de usuario o contraseñas vacías
  *Hay que verificar que los movimientos de wallet retornen true, de otro modo
   no se garantiza que se haya realizado el movimiento.
