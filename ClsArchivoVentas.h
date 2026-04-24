#ifndef CLSARCHIVOVENTAS_H_INCLUDED
#define CLSARCHIVOVENTAS_H_INCLUDED
#include "ClsVentas.h"

class ArchivoVentas
{
private :
    char nombre[30];
public:
    ArchivoVentas(const char *n);
    void CargarVenta1();
    void Cargar();
    void Mostrar();
    Ventas leerRegistro(int pos);
    int contarRegistros();
    bool mostrarXarticulo();
    void mostrarXcliente();
    void mostrarTodasLasVentas();
    bool sobreEscribirReg(Ventas ven,int pos);

    int BuscayDevuelveCodigo();
    float sumaImporteTotal(int nFac);
    void MostrarComoFacturaxCliente();

};



#endif // CLSARCHIVOVENTAS_H_INCLUDED
