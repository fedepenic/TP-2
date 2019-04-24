#include "Producto.h"

Producto::Producto(){
    cout<<"Constructor Producto"<<endl;
    nombre = NOMBRE_DEFECTO;
    codigo = CODIGO_DEFECTO;
    precio = PRECIO_DEFECTO;
    oferta = OFERTA_DEFECTO;
}


void Producto::asignar_codigo(int nuevo_codigo){
    codigo = nuevo_codigo;
}

int Producto::obtener_codigo(){
    return codigo;
}

void Producto::asignar_nombre(string nuevo_nombre){
    nombre = nuevo_nombre;
}

string Producto::obtener_nombre(){
    return nombre;
}

void Producto::asignar_precio(float nuevo_precio ){
    precio = nuevo_precio;
}

float Producto::obtener_precio(){
    return precio;
}

void Producto::asignar_oferta(bool actualizar_oferta){
    oferta = actualizar_oferta;
}

bool Producto::obtener_oferta(){
    return oferta;
}
