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
    gondola_principal.asignar_tamanio_gondola(cantidad_productos);
    gondola_principal.preparar_gondola();
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
    dato obtener;
    cout<<"Acomodando productos en gondola..."<<endl;
    int i = 0;
    while(archivo_productos_dos>>(obtener.codigo)>>obtener.nombre>>obtener.precio>>obtener.oferta){
    gondola_principal.acomodar_producto(i)->asignar_codigo(obtener.codigo);
    gondola_principal.acomodar_producto(i)->asignar_nombre(obtener.nombre);
    gondola_principal.acomodar_producto(i)->asignar_precio(obtener.precio);
    gondola_principal.acomodar_producto(i)->asignar_oferta(obtener.oferta);
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
    cout<<"\n\n\t ---Menu de acciones en gondola---"<<endl;
    cout<<"\t      [Menu(*) - SubMenu(-)]"<<endl<<endl;
    cout<<" * Cargar nuevo producto        [a]"<<endl;
    cout<<" * Buscar producto por nombre   [b]"<<endl;
    cout<<"     - Modificar precio         -d-"<<endl;
    cout<<"     - Quitar un producto       -e-"<<endl;
    cout<<" * Buscar producto por codigo   [c]"<<endl;
    cout<<"     - Modificar precio         -d-"<<endl;
    cout<<"     - Quitar un producto       -e-"<<endl;
    cout<<" * Contar productos en oferta   [f]"<<endl;
    cout<<" * Cargar productos al chango   [g]"<<endl;
    cout<<" * Mostrar productos en gondola [h]"<<endl;
    cout<<"\n * Salir                        [x]"<<endl;
}

void Menu::ejecutar_opcion(){
    switch(opcion_usuario){
        case CARGAR_PRODUCTO:
            cargar_producto_gondola();
            break;
        case BUSCAR_PRODUCTO_NOMBRE:
            buscar_producto_nombre();
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
        case SALIR:
            cout<<"Saliendo de la tienda"<<endl;
            break;
        default:
            cout<<"Ingreso invalido"<<endl;
    }
}

void Menu::cargar_producto_gondola(){
    dato cargar[MAX_CARGAR_PRODUCTOS];
    cout<<"Ingrese cantidad de productos a cargar - maximo diez (10)"<<endl;
    gondola_principal.recibir_tamanio_cargar();
    int productos = gondola_principal.obtener_tamanio_cargar();
    pedir_datos_producto(productos, cargar);
    gondola_principal.actualizar_tamanio_previsto();
    gondola_principal.crear_espacio_gondola();
    gondola_principal.acomodar_productos_actuales();
    gondola_principal.acomodar_productos_nuevos(cargar);
    gondola_principal.actualizar_datos_gondola();
}

void Menu::pedir_datos_producto(int productos, dato cargar[]){
    for(int i = 0; i < productos; i++){
        cout<<"\t\tProducto a cargar numero: "<<i+1<<endl<<endl;
        cout<<"\t\t*** Codigo y Nombre de los productos son UNICOS***"<<endl;
        cout<<"Ingrese Codigo: ";
        cin>>cargar[i].codigo;
        cout<<"\nIngrese Nombre: ";
        cin>>cargar[i].nombre;
        cout<<"\nIngrese Precio: ";
        cin>>cargar[i].precio;
        cout<<"\nSin oferta[0] - En oferta[1]";
        cout<<"\nIngrese estado de Oferta: ";
        cin>>cargar[i].oferta;
    }
}

void Menu::buscar_producto_nombre(){
    int posicion = POSICION_NULA;
    string producto_buscado=BUSQUEDA_NULA;
    cout<<"Ingrese el nombre del producto a buscar: ";
    cin>>producto_buscado;
    gondola_principal.buscar_producto_nombre(producto_buscado, posicion);
    if(posicion==-1){
        cout<<"\t\t***Producto no encontrado***"<<endl;
    }else{
        cout<<" * Modificar precio             [d]"<<endl;
        cout<<" * Quitar un producto           [e]"<<endl;
        cout<<" * Volver al menu               [cualquier letra]"<<endl;
        recibir_opcion();
        if(opcion_usuario=='d'){
            gondola_principal.cambiar_producto_precio(posicion);
        }else if(opcion_usuario=='e'){
            gondola_principal.quitar_producto(posicion);
        }
    }
}
