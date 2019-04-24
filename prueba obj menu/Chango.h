#ifndef _CHANGO_H_
#define _CHANGO_H_

class Chango{
    private:
        int tamanio_chango;
        Producto productos_de_chango;
    public:
        Chango();
        ~Chango();
        int obtener_tamanio_chango();
        void asignar_tamanio_chango(int tamanio_del_chango);
};


#endif /*_CHANGO_H_*/

