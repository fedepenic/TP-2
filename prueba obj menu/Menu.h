#ifndef _MENU_H_
#define _MENU_H_

#include "Gondola.h"
#include "acciones.h"

#include <fstream>

#include <iostream>
using namespace std;

const char CARGAR_PRODUCTO = 'a';
const char BUSCAR_PRODUCTO_NOMBRE = 'b';
const char BUSCAR_PRODUCTO_BARRA = 'c';
const char MODIFICAR_PRECIO = 'd';
const char QUITAR_PRODUCTO = 'e';
const char CANTIDAD_OFERTA = 'f';
const char CARGAR_CHANGO = 'g';
const char MOSTRAR_PRODUCTOS_GONDOLA = 'h';
const char SALIR = 'x';

const char MENU_ACTIVO = 's';

const string BUSQUEDA_NULA = "NINGUNO";

const int MAX_CARGAR_PRODUCTOS = 10;



class Menu{
    private:
        char opcion_usuario;
        Gondola gondola_principal;
        //Chango chango_principal;
    public:
        /*Constructor
        *Descripcion: Inicializa el atributo "opcion_usuario". Muestra por consola que se ingreso al constructor.
        *Pre:-.
        *Post: El atributo mencionado queda inicializado. Muestra por consola el ingreso al constructor de esta clase.
        */
        Menu();


        /*
        *Descripcion: Inicia la compra usando los metodos y clases necesarios para realizar la misma.
        *Pre: El archivo "productos.txt" debe existir.
        *Post: Se muestra un menu mediante consola dando a elegir distintas opciones al usuario, el programa realizara las opciones del menu.
        */
        void iniciar_compra();

        private:
        /*
        *Descripcion: Lee dos veces el archivo "productos.txt" contando la cantidad de productos como sus caracteristicas.
        *Pre: El archivo "productos.txt" debe existir.
        *Post: En el atributo "gondola_principal" queda inicializado el vector de clase Producto con la cantidad y caracteristicas de los productos del archivo "productos.txt".
        */
        void leer_lista_compras();

        /*
        *Descripcion: Lee el archivo "productos.txt" contando la cantidad de productos.
        *Pre: El archivo "productos.txt" debe existir.
        *Post: devuelve en el parametro "cantidad_productos" la cantidad exacta de productos encontrados en el archivo mencionado.
        */
        void leer_cantidad(int &cantidad_productos, ifstream &archivo_productos);

        /*
        *Descripcion: Lee el archivo "productos.txt" guardando sus caracteristicas en el vector de clase Productos del atributoi "gondola_principal" mediante el struct "obtener".
        *Pre: El archivo "productos.txt" debe existir. El vector perteneciente al atributo "gondola_principal" debe estar correctamente inicializado.
        *Post: Guarda las caracteristicas en el vector de clase Productos del atributo "gondola_principal".
        */
        void leer_caracteristicas(ifstream &archivo_productos);

        /*
        *Descripcion: Muestra por consola los productos actuales del vector dinamico del atributo "gondola_principal".
        *Pre: -.
        *Post: Muestra por consola los productos actuales del vector dinamico del atributo "gondola_principal".
        */
        void mostrar_productos_gondola();

        //Descripción: Este método se encargará de asignarle un nuevo caracter al atributo opcion_usuario perteneciente a un objeto de clase Menú.
		//Precondiciones: La opcion pasada como parámetro debe encontrarse dentro del dominio de dicho atributo.
		//Postcondiciones: El atributo opcion_usuario de clase Menu es asignado con el caracter pasado como parámetro opcion.
		void asignar_opcion(char opcion);

        //Descripción: Este método se encargará de devolver un caracter que indica la opcion de menú elegida por el usuario.
		//Precondiciones: -.
		//Postcondiciones: Retorna un caracter que representa al atributo opcion_usuario correspondiente a un objeto de clase Menu.
		char obtener_opcion();

        /*
        *Descripcion: Recibe la opcion del usuario guardandolo en el atributo "opcion_usuario".
        *Pre: -.
        *Post: Queda recibida la opcion del usuario en el atributo "opcion_usuario".
        */
        void recibir_opcion();

		//Descripción: De acuerdo con la opción que ha elegido el usuario, realiza una tarea particular.
		//Precondiciones: La opción elegida por el usuario se encuentra dentro del dominio de dicho atributo.
		//Postcondiciones: Ejecuta la opción acorde con lo que haya elegido el usuario.
		void ejecutar_opcion();

		//Descripción: Este método se encarga de mostrarle el menú de opciones del supermercado al usuario a través de una interfaz gráfica rudimentaria.
		//Precondiciones: -.
		//Postcondiciones: Se imprime por pantalla el menú de opciones para la visualización del usuario.
		void mostrar_menu();

		/*Descripcion: Realizara los metodos necesarios para poder actualizar el vector dinamico de clase Prodcuto del atributo "gondola_principal".
		 *Pre: Maximo 10 productos a ingresar..
		 *Post: Queda actualizado el vector dinamico mencionado.
		*/
		void cargar_producto_gondola();

        /*Descripcion: Pedira los datos de la cantidad deseada de productos a ingresar.
		 *Pre: Codigo y Nombre de los productos no pueden repetirse.
		 *Post: Los datos de los productos a ingresar quedan almacenados en el struct "cargar".
		*/
		void pedir_datos_producto(int nuevo_tamanio_cargar, dato cargar[]);

		/*Descripcion: Busca el nombre del producto ingresado en el vector dinamico de clase Producto del atributo "gondola_principal".
		 *Pre: -.
		 *Post: Verifica la existencia del producto a buscar, procede a mostrar el submenu.
		*/
		void buscar_producto_nombre();


		//void ejecutar_opcion_a();
		//void ejecutar_opcion_b();
		void ejecutar_opcion_c();
		//void ejecutar_opcion_d();
		//void ejecutar_opcion_e();
		void ejecutar_opcion_f();
		void ejecutar_opcion_g();
		//void ejecutar_opcion_h();
};


#endif /*_MENU_H_*/
