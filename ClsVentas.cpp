#include <iostream>
#include <cstring>
#include "ClsVentas.h"
#include "ClsCliente.h"
#include "ClsArchivoArticulo.h"
#include "ClsArchivoCliente.h"
#include "ClsItemVenta.h"
#include "ClsArchivoItemVenta.h"

void Ventas::setNumeroFactura(int nFac){
    NumeroFactura=nFac;
    setEstadoVen(true);
    }

void Ventas::setImporte(float imp){
 Importe=imp;
}


void Ventas::setEstadoVen(bool estado){
    Estado = estado;
}

Fecha Ventas::mostrarFecha(){
    fechaVenta.Mostrar();
}


void Ventas::setDni(int num){
Dni=num;
}

int Ventas:: GetDni(){
return Dni;
}

int Ventas::getNumeroFactura(){
    return NumeroFactura;
}

float Ventas::getImporte(){
    return Importe;
}


bool Ventas::getEstadoVen(){
    return Estado;
}


void Ventas::MostrarComoFactura(){
    std::cout <<"***********************************************"<< std::endl;
    //std::cout << "NUMERO DE FACTURA  :"<<getNumeroFactura()<< std::endl;
    std::cout << std::endl;
    std::cout << "DNI CLIENTE: "<< GetDni() << std::endl;
    std::cout << std::endl;
    fechaVenta.Mostrar();
    std::cout << std::endl;
    std::cout << std::endl;
    ///  std::cout <<"*********************************"<< std::endl;

}

void Ventas::MostrarComoFacturaxCliente(){
    std::cout <<"***********************************************"<< std::endl;
    std::cout << "NUMERO DE FACTURA  :"<<getNumeroFactura()<< std::endl;
    std::cout << std::endl;
    std::cout << "DNI CLIENTE: "<< GetDni() << std::endl;
    std::cout << std::endl;
    fechaVenta.Mostrar();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "IMPORTE TOTAL: "<<"$ "<< getImporte() << std::endl;
    ///  std::cout <<"*********************************"<< std::endl;

}

