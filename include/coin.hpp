/**********************************************************************
* Project           : plataforma MVL (Moneda Virtual Local)
*
* Class             : coin (monedero)
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

#include <iostream>

class coin{
  public:
    coin(void): coins(0) {}
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
