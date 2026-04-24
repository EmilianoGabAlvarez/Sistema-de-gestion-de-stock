#ifndef CLSVENTAS_H_INCLUDED
#define CLSVENTAS_H_INCLUDED

#include "ClsFecha.h"
#include "ClsCliente.h"

class Ventas
{
private:
    int NumeroFactura;
    int Dni;
    float Importe;
    Fecha fechaVenta;
    bool Estado;

public:
    void setNumeroFactura(int nFac);
    void setDni(int num);
    void setCantStock1(int num, int nfac);
    void setEstadoVen(bool estado);
    void setImporte(float imp);

    int getNumeroFactura();
    int  GetDni();
    float getImporte();
    bool getEstadoVen();
    void MostrarComoFactura();
    void MostrarComoFacturaxCliente();
    Fecha mostrarFecha();

};

#endif // CLSVENTAS_H_INCLUDED
