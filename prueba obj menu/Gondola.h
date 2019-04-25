#ifndef _GONDOLA_H_
#define _GONDOLA_H_

#include "Producto.h"
#include "acciones.h"

#include <iostream>
using namespace std;


const int CANTIDAD_INICIAL_PRODUCTOS = 0;
const int CANTIDAD_INICIAL_CARGAR_PRODUCTOS = 0;
const float PRECIO_NULO = -1;
const int POSICION_NULA = -1;



class Gondola{
    private:
        int tamanio_gondola;
        int tamanio_cargar; // se usa para actualizar "tamanio_gondola" en el metodo de Menu "cargar_producto_gondola"
        int tamanio_previsto; // suma de tamanio_gondola y tamanio_cargar (requiere metodo actualizar_tamanio_previsto para su uso)

        Producto* productos_gondola;
        Producto* gondola_auxiliar; // vector dinamico aux para la redimencion
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
        //Precondiciones: El nuevo_tamanio_gondola pasado como par�metro debe ser un n�mero positivo y natural.
        //Postcondiciones: Al atributo tamanio_gondola de un objeto de clase Gondola se le asigna el valor de nuevo_tamanio_gondola, variable pasada como
        //par�metro.
        void asignar_tamanio_gondola(int nuevo_tamanio_gondola);

        //Descripci�n: Este m�todo se encargar� de devolver el tamanio_cargar de un objeto de clase Gondola.
        //Precondiciones: -.
        //Postcondiciones: Retorna el valor de tamanio_cargar de un objeto de clase Gondola.
        int obtener_tamanio_cargar();

        //Descripci�n: Este m�todo se encargar� de asignarle un nuevo valor al tama�o de la g�ndola, que representa la cantidad de productos presentes en ella.
        //Precondiciones: El nuevo_tamanio_cargar pasado como par�metro debe ser un n�mero positivo y natural.
        //Postcondiciones: Al atributo tamanio_cargar de un objeto de clase Gondola se le asigna el valor de tamanio_de_la_gondola, variable pasada como
        //par�metro.
        void asignar_tamanio_cargar(int nuevo_tamanio_cargar);

        void recibir_tamanio_cargar();

        //Descripci�n: Este m�todo se encargar� de devolver el atributo tamanio_previsto.
        //Precondiciones:-.
        //Postcondiciones: Retorna el valor del atributo tamanio_previsto.
        int obtener_tamanio_previsto();

        //Descripci�n: Este m�todo se encargar� de asignarle un nuevo valor al tamanio_previsto.
        //Precondiciones:.
        //Postcondiciones: Al atributo tamanio_previsto de un objeto de clase Gondola se le asigna el valor de nuevo_tamanio_previsto, variable pasada como
        //par�metro.
        void asignar_tamanio_previsto(int nuevo_tamanio_previsto);

        /*Descripcion: Actualizara el atributo "tamanio_previsto" a la suma de los valores actuales de "tamanio_gondola" y "tamanio_cargar".
         *Pre: "tamanio_gondola" y "tamanio_cargar" son >= 0.
         *Post: Actualizara el atributo "tamanio_previsto".
        */
        void actualizar_tamanio_previsto();

        /*
        *Descripcion: Crea el vector dinamico del atributo "productos_gondola".
        *Pre: "tamanio_gondola" tiene que ser mayor a cero (0).
        *Post: Queda asignada la memoria dinamica para el vector del atributo "productos_gondola"
        */
        void preparar_gondola();

         /*
        *Descripcion: Devuelve la direccion del vector dinamico "productos gondola" en la posicion requerida.
        *Pre: posicion >= 0.
        *Post: Retorna la direccion del vector "productos_gondola" en la posicion requerida.
        */
        Producto* acomodar_producto(int posicion);

        /*
        *Descripcion: Actualiza el vector dinamico del atributo "gondola_principal" junto a "tamanio_gondola".
        *Pre:-.
        *Post: El vector dinamico mencionado queda actualizado con los productos anteriores y nuevos, "tamanio_gondola" actualizado a la nueva cantidad de productos.
        */
        void actualizar_productos_gondola();

        /*
        *Descripcion: Crea un vector dinamico auxiliar con el valor del atributo "tamanio_previsto".
        *Pre: "tamanio_previsto" tiene que ser mayor a cero (0).
        *Post: Queda asignada la memoria dinamica para el vector dinamico auxiliar.
        */
        void crear_espacio_gondola();

        /*
        *Descripcion: Acomoda los productos actuales al vector dinamico auxiliar.
        *Pre:-.
        *Post: El vector dinamico auxiliar posee los productos actuales.
        */
        void acomodar_productos_actuales();

        /*
        *Descripcion: Acomoda los nuevos productos al vector dinamico auxiliar.
        *Pre:-.
        *Post: El vector dinamico auxiliar queda actualizado con todos los productos.
        */
        void acomodar_productos_nuevos(dato cargar[]);

        /*
        *Descripcion: Actualiza el tama�o y la direccion del vector dinamico "productos_gondola", previamente libera la memoria utilizada en el mismo.
        *Pre: Vector dinamico "gondola_auxiliar" creado correctamente.
        *Post: El vector dinamico "productos_gondola" queda actualizado.
        */
        void actualizar_datos_gondola();

        /*
        *Descripcion: Busca el nombre pedido (producto_buscado) en el vector dinamico "productos_gondola".
        *Pre:-.
        *Post: REVISAR---SE PUEDE AGREGAR LAS OPCIONES CAMBIAR PRECIO Y QUITAR PARA EVITAR MANEJAR LA POSICION BUSCADA.
        */
        void buscar_producto_nombre(string producto_buscado, int &posicion);

        /*
        *Descripcion: Cambia el precio del producto en la "posicion" del vector dinamico "productos_gondola".
        *Pre: El nuevo precio tiene que ser de tipo float.
        *Post: Queda actualizado el precio del producto en la "posicion" del vector dinamico mencionado.
        */
        void cambiar_producto_precio(int posicion);

        /*Descripcion: REQUIERE REORDENAR Y LUEGO AL TAMANIO_GONDOLA RESTARLE 1 ---
         *Pre:
         *Post:
        */
        void quitar_producto(int posicion);


        /*
        *Descripcion: Muestra por consola los productos actuales del vector dinamico "productos_gondola".
        *Pre: -.
        *Post: Muestra por consola los productos actuales del vector dinamico "productos_gondola".
        */
        void mostrar_productos();

        /*
        *Descripcion: Muestra por consola el producto requerido del vector dinamico "productos_gondola".
        *Pre: "posicion">=0 y < "tamanio_gondola".
        *Post: Muestra por consola el producto requerido.
        */
        void mostrar_producto_particular(int posicion);

        /*Descripci�n: Es el m�todo destructor de objetos de clase Gondola. Se encarga de liberar el espacio destinado para alocar el vector de Productos
        *              en memoria din�mica.
        *Precondiciones: -.
        *Postcondiciones: Libera el espacio utilizado para alocar el vector de productos en memoria din�mica.
        */
        ~Gondola();
};



#endif /*_GONDOLA_H_*/
