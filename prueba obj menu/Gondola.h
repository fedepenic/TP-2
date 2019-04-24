#ifndef _GONDOLA_H_
#define _GONDOLA_H_

#include "Producto.h"

#include <iostream>
using namespace std;


const int CANTIDAD_INICIAL_PRODUCTOS = 0;

class Gondola{
    private:
        int tamanio_gondola;
        Producto* productos_gondola;
    public:
        //Constructor
        //Descripcion: Inicializa los atributo "tamanio_gondola" y muestra por consola que se ingreso al constructor.
        //Pre:-.
        //Post: El atributo mencionado queda inicializado.
        Gondola();

    	//Descripci�n: Este m�todo se encargar� de devolver el tamanio_gondola de un objeto de clase Gondola.
        //Precondiciones: -.
        //Postcondiciones: Retorna el valor de tamanio_gondola de un objeto de clase Gondola.
        int obtener_tamanio_gondola();

        //Descripci�n: Este m�todo se encargar� de asignarle un nuevo valor al tama�o de la g�ndola, que representa la cantidad de productos presentes en ella.
        //Precondiciones: El tamanio_de_la_gondola pasado como par�metro debe ser un n�mero positivo y natural.
        //Postcondiciones: Al atributo tamanio_gondola de un objeto de clase Gondola se le asigna el valor de tamanio_de_la_gondola, variable pasada como
        //par�metro.
        void asignar_tamanio_gondola(int tamanio_gondola);

        /*
        *Descripcion: Crea el vector dinamico del atributo "productos_gondola".
        *Pre: "cantidad_productos" tiene que ser mayor a cero (0).
        *Post: Queda asignada la memoria dinamica para el vector del atributo "productos_gondola"
        */
        void preparar_gondola(int cantidad_productos);

        /*
        *Descripcion: Devuelve la direccion del vector dinamico "productos gondola" en la posicion requerida.
        *Pre: posicion >= 0.
        *Post: Retorna la direccion del vector "productos_gondola" en la posicion requerida.
        */
        Producto* acomodar_producto(int posicion);

        /*
        *Descripcion: Muestra por consola los productos actuales del vector dinamico "productos_gondola".
        *Pre: -.
        *Post: Muestra por consola los productos actuales del vector dinamico "productos_gondola".
        */
        void mostrar_productos();

        /*Descripci�n: Es el m�todo destructor de objetos de clase Gondola. Se encarga de liberar el espacio destinado para alocar el vector de Productos
        *              en memoria din�mica.
        *Precondiciones: -.
        *Postcondiciones: Libera el espacio utilizado para alocar el vector de productos en memoria din�mica.
        */
        ~Gondola();
};



#endif /*_GONDOLA_H_*/
