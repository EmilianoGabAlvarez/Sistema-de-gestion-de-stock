#include"ClsItemVenta.h"

void ItemVenta::MostrarItemVenta(){

    std::cout<<"Codigo: "<<GetCodArticulo()<<'\t';
    std::cout<<"Cantidad: "<<GetCantidad() <<'\t';
    std::cout<<"Importe: $"<<GetImporte()<<'\t';

}

void ItemVenta::MostrarItemVentaNfactura()
{

    std::cout<<"Numero de factura: "<<GetnFactura()<<'\t';
    std::cout<<"Codigo: "<<GetCodArticulo()<<'\t';
    std::cout<<"Cantidad: "<<GetCantidad() <<'\t';
    std::cout<<"Importe: $"<<GetImporte()<<'\t';
}
