#ifndef CLSARCHIVOITEMVENTA_H_INCLUDED
#define CLSARCHIVOITEMVENTA_H_INCLUDED
#include"ClsItemVenta.h"
#include"ClsArchivoVentas.h"

class ArchivoItemVenta{
private:
    char Nombre[30];

public:
    ArchivoItemVenta(const char *n);
        bool escribirRegistro();
        bool escribirRegistro(ItemVenta obj);
        int contarRegistros();
        ItemVenta leerRegistro(int pos);
        bool ListarxFactura();
        bool listarTodasLasVentas();
        void setCantStock1(int cod, int nfac );

};

#endif // CLSARCHIVOITEMVENTA_H_INCLUDED
