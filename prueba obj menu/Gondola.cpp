#include "Gondola.h"

Gondola::Gondola(){
    cout<<"Constructor Gondola"<<endl;
    tamanio_gondola = CANTIDAD_INICIAL_PRODUCTOS;
    tamanio_cargar = CANTIDAD_INICIAL_CARGAR_PRODUCTOS;
    tamanio_previsto = tamanio_gondola + tamanio_cargar;
}

int Gondola::obtener_tamanio_gondola(){
    return tamanio_gondola;
}

void Gondola::asignar_tamanio_gondola(int nuevo_tamanio_gondola){
    tamanio_gondola = nuevo_tamanio_gondola;
}

int Gondola::obtener_tamanio_cargar(){
    return tamanio_cargar;
}

void Gondola::asignar_tamanio_cargar(int nuevo_tamanio_cargar){
    tamanio_cargar = nuevo_tamanio_cargar;
}

int Gondola::obtener_tamanio_previsto(){
    return tamanio_previsto;
}

void Gondola::asignar_tamanio_previsto(int nuevo_tamanio_previsto){
    tamanio_previsto = nuevo_tamanio_previsto;
}

void Gondola::actualizar_tamanio_previsto(){
    tamanio_previsto = tamanio_gondola + tamanio_cargar;
}

void Gondola::recibir_tamanio_cargar(){
    cin>>tamanio_cargar;
}

void Gondola::preparar_gondola(){
    productos_gondola = new Producto[tamanio_gondola];
}

Producto* Gondola::acomodar_producto(int posicion){
    return (&productos_gondola[posicion]);
}

void Gondola::mostrar_productos(){
    cout<<"Mostrando productos de gondola ["<<tamanio_gondola<<"]"<<endl<<endl;
    for(int i = 0; i < tamanio_gondola; i++){
        cout<<"Codigo: "<<(productos_gondola[i].obtener_codigo())<<endl;
        cout<<"Producto: "<<productos_gondola[i].obtener_nombre()<<endl;
        cout<<"Precio: $ "<<productos_gondola[i].obtener_precio()<<endl;
        if(!productos_gondola[i].obtener_oferta()){
            cout<<"Oferta: No esta en oferta :("<<endl<<endl;
        }else{
            cout<<"Oferta: Esta en oferta! :D"<<endl<<endl;
        }
    }
}

void Gondola::mostrar_producto_particular(int posicion){
    cout<<"\t\t***Mostrando producto numero ["<<posicion+1<<"]***"<<endl<<endl;
    cout<<"Codigo: "<<(productos_gondola[posicion].obtener_codigo())<<endl;
    cout<<"Producto: "<<productos_gondola[posicion].obtener_nombre()<<endl;
    cout<<"Precio: $ "<<productos_gondola[posicion].obtener_precio()<<endl;
    if(!productos_gondola[posicion].obtener_oferta()){
        cout<<"Oferta: No esta en oferta :("<<endl<<endl;
    }else{
        cout<<"Oferta: Esta en oferta! :D"<<endl<<endl;
    }
}

void Gondola::crear_espacio_gondola(){
    cout<<"Creando espacio en la nueva gondola"<<endl;
    gondola_auxiliar = new Producto[tamanio_previsto];
}

void Gondola::acomodar_productos_actuales(){
    for(int i = 0; i<tamanio_gondola ; i++){
        gondola_auxiliar[i].asignar_codigo(productos_gondola[i].obtener_codigo());
        gondola_auxiliar[i].asignar_nombre(productos_gondola[i].obtener_nombre());
        gondola_auxiliar[i].asignar_precio(productos_gondola[i].obtener_precio());
        gondola_auxiliar[i].asignar_oferta(productos_gondola[i].obtener_oferta());
    }
}

void Gondola::acomodar_productos_nuevos(dato cargar[]){
    for(int i= tamanio_gondola; i<tamanio_previsto; i++){
        gondola_auxiliar[i].asignar_codigo(cargar[i-tamanio_gondola].codigo);
        gondola_auxiliar[i].asignar_nombre(cargar[i-tamanio_gondola].nombre);
        gondola_auxiliar[i].asignar_precio(cargar[i-tamanio_gondola].precio);
        gondola_auxiliar[i].asignar_oferta(cargar[i-tamanio_gondola].oferta);
    }
}

void Gondola::actualizar_datos_gondola(){
    tamanio_gondola = tamanio_previsto;
    tamanio_cargar = CANTIDAD_INICIAL_CARGAR_PRODUCTOS;
    cout<<"Limpiando gondola..."<<endl;
    delete[] productos_gondola;
    cout<<"Nuevos productos acomodados correctamente."<<endl;
    productos_gondola = gondola_auxiliar;
}

void Gondola::buscar_producto_nombre(string producto_buscado, int &posicion){
    cout<<"Buscando producto: "<<producto_buscado<<" ..."<<endl;
    bool encontrado = false;
    int contador = 0;
    while(!encontrado && (contador<tamanio_gondola)){
        if(productos_gondola[contador].obtener_nombre() == producto_buscado){
            encontrado = true;
            posicion=contador;
        }else{
            contador++;
        }
    }
}

void Gondola::cambiar_producto_precio(int posicion){
    float nuevo_precio =PRECIO_NULO;
    cout<<"Ingrese el nuevo precio para "<<productos_gondola[posicion].obtener_nombre()<<endl;
    cin>>nuevo_precio;
    productos_gondola[posicion].asignar_precio(nuevo_precio);
    cout<<"\t\t***Precio actualizado***"<<endl;
    mostrar_producto_particular(posicion);
}

void Gondola::quitar_producto(int posicion){
    cout<<"\t\t *** Producto: "<<productos_gondola[posicion].obtener_nombre()<<" removido ***"<<endl<<endl;
    for(int i =posicion; i<tamanio_gondola-1; i++){
        productos_gondola[i]=productos_gondola[i+1];
    }
    tamanio_gondola--;
}

Gondola::~Gondola(){
    cout<<"Destructor Gondola"<<endl;
    delete[] productos_gondola;
}
