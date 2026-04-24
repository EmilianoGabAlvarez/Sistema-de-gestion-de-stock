#include <iostream>
#include <cstring>
#include "GLOBALES.h"
#include "ClsArticulo.h"

void articulo::setCodigo(int codigo){
    _codigo = codigo;
}

void articulo::setNombre(const char *nombre){
    strcpy(_nombre,nombre);
}


void articulo::setPrecio(float precio){
    _precio = precio;
}

void articulo::setStock(int stock){
    _stock=stock;
}

void articulo::setEstadoArt(bool estado){
    _estado = estado;
}

void articulo::setDisponibilidad(int num){
    _disponibilidad=num;
}

int articulo::getCodigo(){
    return _codigo;
}

const char* articulo::getNombre(){
    return _nombre;
}

float articulo::getPrecio(){
    return _precio;
}


int articulo::getDisponibilidad(){
    return _disponibilidad;
}
int articulo::getCapacidad(){
    return _capacidad;
}

int articulo::getStock(){
    return _stock;
}
bool articulo::getEstadoArt(){
    return _estado;
}

void articulo::cargar()
{
    int cap,cant;
    float precio;
    std::cout << "Ingrese el nombre del articulo: " << '\t';
    cargarCadena(_nombre,29);
    std::cout << std::endl;
    std::cout << "Ingrese el precio del articulo: " << "$"<<'\t';
    std::cin >> precio;
    setPrecio(precio);
    std::cout << std::endl;
    std::cout << "Ingrese la capacidad de almacenamiento : " << '\t';
    std::cin >> cap;
    setCapacidad(cap);
    std::cout << std::endl;
    std::cout << "Ingrese la cantidad de bultos del articulo a guardar " << '\t';
    std::cin >> cant;
    std::cout << std::endl;
    while (cant>cap)
    {
        std::cout << "-- EL STOCK SUPERA LA CAPACIDAD DE ALMACENAMIENTO  --" <<std::endl;
        std::cout <<std::endl;
        std::cout << "Ingrese nuevamente la cantidad de bultos del articulo a guardar " << '\t';
        std::cin >> cant;
    }
    setStock(cant);
    int capacidad=getCapacidad()- getStock();
    setDisponibilidad(capacidad);
    setEstadoArt(true);
}

void articulo::mostrar(){
    std::cout << "CODIGO:  " << getCodigo() << '\t';
    std::cout << "NOMBRE: " << getNombre() << '\t';
    std::cout << "PRECIO: " << getPrecio() << '\t';
    std::cout << "CAPACIDAD: " << getCapacidad() << '\t';
    std::cout << "STOCK DISPONIBILE: " << getStock() << '\t';
    std::cout << "lugar DISPONIBILE: " << getDisponibilidad() << '\t';
    std::cout << std::endl;
}




void articulo::setCapacidad(int capacidad){
    _capacidad = capacidad;
}


