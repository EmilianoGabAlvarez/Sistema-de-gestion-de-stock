#ifndef CLSITEMVENTA_H_INCLUDED
#define CLSITEMVENTA_H_INCLUDED
#include <iostream>
#include <cstring>

class ItemVenta {
    private:
       int _nFactura;
       int _Dni;
       int _codArticulo;
       int _cantidad;
       float _importe;

    public:
    void SetnFactura(int num ){_nFactura=num;}
    void SetnDni(int dni ){_Dni=dni;}
    void SetCodArticulo(int cod){_codArticulo=cod;}
    void SetCantidad(int cant){_cantidad=cant;}
    void SetImporte (float imp){_importe=imp;}

    int GetnFactura(){return _nFactura;}
    int GetCodArticulo(){return _codArticulo;}
    int GetCantidad(){return _cantidad;}
    float GetImporte(){return _importe;}

    void MostrarItemVenta();
    void MostrarItemVentaNfactura();
};



#endif // CLSITEMVENTA_H_INCLUDED
