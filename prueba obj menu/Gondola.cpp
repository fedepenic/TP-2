#include "Gondola.h"

Gondola::Gondola(){
    cout<<"Constructor Gondola"<<endl;
    tamanio_gondola = CANTIDAD_INICIAL_PRODUCTOS;
}

int Gondola::obtener_tamanio_gondola(){
    return tamanio_gondola;
}

void Gondola::preparar_gondola(int cantidad_productos){
    tamanio_gondola = cantidad_productos;
    productos_gondola = new Producto[tamanio_gondola];
}

Producto* Gondola::acomodar_producto(int posicion){
    return (&productos_gondola[posicion]);
}

void Gondola::mostrar_productos(){
    cout<<"Mostrando productos de gondola"<<endl<<endl;
    for(int i = 0; i < tamanio_gondola; i++){
        cout<<"Codigo: "<<(productos_gondola[i].obtener_codigo())<<endl;
        cout<<"Producto: "<<productos_gondola[i].obtener_nombre()<<endl;
        cout<<"Precio: "<<productos_gondola[i].obtener_precio()<<endl;
        if(!productos_gondola[i].obtener_oferta()){
            cout<<"Oferta: No esta en oferta :("<<endl<<endl;
        }else{
            cout<<"Oferta: Esta en oferta! :D"<<endl<<endl;
        }
    }
}

Gondola::~Gondola(){
    cout<<"Destructor Gondola"<<endl;
    delete[] productos_gondola;
}
