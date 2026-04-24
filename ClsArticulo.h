#ifndef CLSARTICULO_H_INCLUDED
#define CLSARTICULO_H_INCLUDED

class articulo
{
private:
    int _codigo;
    char _nombre[30];
    float _precio;
    int _capacidad;
    int _disponibilidad;
    int _stock;
    bool _estado;

public:
    void setCodigo(int codigo);
    void setNombre(const char *nombre);
    void setPrecio(float precio);
    void setCapacidad(int capacidad);
    void setStock(int cant);
    void setEstadoArt(bool estado);
    int setCantidadVenta(int cantidad);
    void setDisponibilidad(int num);
    int getCodigo();
    const char *getNombre();
    float getPrecio();
    int getDisponibilidad();
    int getCapacidad();
    int getStock();
    bool getEstadoArt();
    void cargar();
    void mostrar();
};

#endif // CLSARTICULO_H_INCLUDED
