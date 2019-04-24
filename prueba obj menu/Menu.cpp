#include "acciones.h"
#include "Menu.h"

Menu::Menu(){
    cout<<"Constructor Menu"<<endl;
    opcion_usuario = MENU_ACTIVO;
}

void Menu::iniciar_compra(){
    leer_lista_compras();
    while(opcion_usuario != SALIR){
    mostrar_menu();
    recibir_opcion();
    ejecutar_opcion();
    }
}

void Menu::leer_lista_compras(){
    int cantidad_productos = CANTIDAD_INICIAL_PRODUCTOS;
    ifstream archivo_productos("productos.txt");
    leer_cantidad(cantidad_productos, archivo_productos);
    cout<<"cantidad: "<<cantidad_productos<<endl;
    archivo_productos.close();
    ifstream archivo_productos_dos("productos.txt");
    gondola_principal.preparar_gondola(cantidad_productos);
    leer_caracteristicas(archivo_productos_dos);
    archivo_productos_dos.close();
}

void Menu::leer_cantidad(int &cantidad_productos, ifstream &archivo_productos){
    char c;
    while( archivo_productos.get(c)){
        if( c == '\n'){
            cantidad_productos++;
        }
    }
}

void Menu::leer_caracteristicas(ifstream &archivo_productos_dos){
    datos obtener;
    bool actualizar_oferta = false;
    cout<<"Acomodando productos en gondola..."<<endl;
    int i = 0;
    while(archivo_productos_dos>>(obtener.codigo)>>obtener.nombre>>obtener.precio>>obtener.oferta){
    if(!obtener.oferta){
        actualizar_oferta = false;
    }else{
        actualizar_oferta = true;
    }
    gondola_principal.acomodar_producto(i)->asignar_codigo(obtener.codigo);
    gondola_principal.acomodar_producto(i)->asignar_nombre(obtener.nombre);
    gondola_principal.acomodar_producto(i)->asignar_precio(obtener.precio);
    gondola_principal.acomodar_producto(i)->asignar_oferta(actualizar_oferta);
    i++;
    }
    cout<<"Productos cargados correctamente."<<endl;
}

void Menu::mostrar_productos_gondola(){
    gondola_principal.mostrar_productos();
}

void Menu::asignar_opcion(char opcion){
    opcion_usuario = opcion;
}

char Menu::obtener_opcion(){
    return opcion_usuario;
}

void Menu::recibir_opcion(){
    cin>>opcion_usuario;
}

void Menu::mostrar_menu(){
    opcion_usuario = MENU_ACTIVO;
    cout<<"--- Menu de acciones en gondola ---"<<endl<<endl;
    cout<<" * Cargar nuevo producto        [a]"<<endl;
    cout<<" * Buscar producto por nombre   [b]"<<endl;
    cout<<" * Buscar producto por codigo   [c]"<<endl;
    cout<<" * Modificar precio             [d]"<<endl;
    cout<<" * Quitar un producto           [e]"<<endl;
    cout<<" * Contar productos en oferta   [f]"<<endl;
    cout<<" * Cargar productos al chango   [g]"<<endl;
    cout<<" * Mostrar productos en gondola [h]"<<endl;
    cout<<"\n * Salir                        [x]"<<endl;
}

void Menu::ejecutar_opcion(){
    switch(opcion_usuario){
        case CARGAR_PRODUCTO:
            //ejecutar_opcion_a();
            break;
        case BUSCAR_PRODUCTO_NOMBRE:
            //ejecutar_opcion_b();
            break;
        case BUSCAR_PRODUCTO_BARRA:
            //ejecutar_opcion_c();
            break;
        case MODIFICAR_PRECIO:
            //ejecutar_opcion_d();
            break;
        case QUITAR_PRODUCTO:
            //ejecutar_opcion_e();
            break;
        case CANTIDAD_OFERTA:
            //ejecutar_opcion_f();
            break;
        case CARGAR_CHANGO:
            //ejecutar_opcion_g();
            break;
        case MOSTRAR_PRODUCTOS_GONDOLA:
            mostrar_productos_gondola();
            break;
        default:
            cout<<"Saliendo de la tienda"<<endl;
    }
}
