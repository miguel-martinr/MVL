#include <iostream>

class coin{
  public:
    coin(void){}
    ~coin(void){}
    
    void increment(float s){ // Incrementa en lo que se le pase por parametro el numero de coins
      coins += s;
    }
    void decrement(float r){ // Decrementa en lo que se le pase por parametro el numero de coins
      coins -= r;
    }
    float coins(void){  // Devuelve la cantidad de moneda
      return coins;
    }
  pivate:
    float coins; // Cantidad de la moneda que posee
};
