#include <iostream>

class coin{
  public:
    coin(void){}
    coin(float coins_): coins(coins_) {}
    ~coin(void){}

    void increment(float s) { // Incrementa en lo que se le pase por parametro el numero de coins
      coins += s;
    }

    void decrement(float r) { // Decrementa en lo que se le pase por parametro el numero de coins
      coins -= r;
    }

    float get_coins(void) {  // Devuelve la cantidad de moneda
      return coins;
    }

    void update(float value) { //Actualiza cantidad en el monedero
      coins = value;
    }

  private:
    float coins; // Cantidad de la moneda que posee
};
