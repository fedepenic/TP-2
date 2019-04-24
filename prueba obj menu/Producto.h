#ifndef _PRODUCTO_H_
#define _PRODUCTO_H_

#include <iostream>
using namespace std;

const string NOMBRE_DEFECTO = "Nombre";
const int CODIGO_DEFECTO = 0;
const float PRECIO_DEFECTO = 0;
const bool OFERTA_DEFECTO = 0;

class Producto{
    private:
        string nombre;
        int codigo;
        float precio;
        bool oferta;
    public:
        //Constructor
        //Descripcion: Inicializa los atributos de la clase y muestra por consola que se ingreso al constructor.
        //Pre:-.
        //Post: Los atributos quedan inicializados.
        Producto();

        string obtener_nombre();
        void asignar_nombre(string nuevo_nombre);

        int obtener_codigo();
        void asignar_codigo(int nuevo_codigo);

        float obtener_precio();
        void asignar_precio(float nuevo_precio);

        bool obtener_oferta();
        void asignar_oferta(bool actualizar_oferta);
};


#endif /*_PRODUCTO_H_*/
