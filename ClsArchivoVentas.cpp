#include <iostream>
#include <cstring>
#include "ClsArchivoVentas.h"
#include "ClsArchivoArticulo.h"
#include "ClsArchivoCliente.h"
#include "ClsItemVenta.h"
#include "ClsArchivoItemVenta.h"


ArchivoVentas::ArchivoVentas(const char *n){
    strcpy(nombre, n);
}


int ArchivoVentas::contarRegistros()
{
    FILE *p;
    p=fopen("Ventas.dat", "rb");
    if(p==NULL) return -1;
    fseek(p, 0,2);
    int tam=ftell(p);
    fclose(p);
    return tam/sizeof(Ventas);
}

/// Funcion final Cargar ventas con ventas + item venta


float ArchivoVentas::sumaImporteTotal(int nFac)
{

    ItemVenta itVen;
    ArchivoItemVenta ArchIVen("ItemVenta.dat");
    FILE *pIVen;
    pIVen = fopen("ItemVenta.dat", "rb");
    if(pIVen == NULL)
    {
        std::cout << "-- NO SE PUDO MOSTRAR EL ARCHIVO --" << std::endl;
        return-1;
    }
    int suma=0;
    while(fread(&itVen, sizeof itVen, 1, pIVen) == 1)
    {
        if (itVen.GetnFactura()==nFac )
        {
            itVen.MostrarItemVenta();
            suma+=(itVen.GetImporte()*itVen.GetCantidad());
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
    return suma;

}




void ArchivoVentas::CargarVenta1()
{
    archivoCli archCli("Cliente.dat");

    ArchivoItemVenta archItemVen("ArchivoItemVenta.dat");

    int tam=0,id=0,cod,dniCliente;

    Ventas ven;
    FILE *pVen;
    pVen=fopen("ventas.dat","ab");
    if(pVen==NULL)
    {
        std::cout <<"No se pudo crear el archivo "<<std::endl;
        return;
    }
    fread(&ven,sizeof (Ventas),1,pVen);
    fseek(pVen,0,2);
    tam=ftell(pVen);
    id=tam/sizeof(Ventas)+1;
    ven.setNumeroFactura(id);


    std::cout << "-- NUEVA VENTA --" << std::endl;
    std::cout << std::endl;

    int nFac=ven.getNumeroFactura();
    std::cout << "-- Factura Nro: --" <<nFac<< std::endl;
    std::cout << std::endl;
    dniCliente=archCli.BuscayDevuelveDni();
    ven.setDni(dniCliente);
    std::cout << "-- Ingrese el codigo del producto a comprar  --" << std::endl;
    std::cin>> cod;
    std::cout << std::endl;
    while (cod !=0 )
    {
        archItemVen.setCantStock1(cod,nFac);  /// Esta funcion modifica el stock en "articulos.dat"

        std::cout << "-- Ingrese el codigo --" << std::endl;
        std::cin>> cod;
        std::cout << std::endl;
    }
    system("cls");
    int suma=0;
    suma=sumaImporteTotal( nFac); /// Funcion para  IMPORTE TOTAL
    ven.setImporte(suma);
    fwrite(&ven, sizeof ven, 1, pVen); /// Tendria que ir despues de cargar el IMPORTE TOTAL

    std::cout << " TOTAL DE LA VENTA:" <<" $ "<< ven.getImporte()<<std::endl;
    std::cout << std::endl;
    std::cout << "-- VENTA REALIZADA EXITOSAMENTE --" << std::endl;
    std::cout << std::endl;

    system("pause");
    fclose(pVen);
    system("cls");
}


Ventas ArchivoVentas::leerRegistro(int pos)
{
    Ventas reg;
    FILE *p;
    p=fopen("Ventas.dat", "rb");
    if(p==NULL) return reg;
    fseek(p, sizeof reg*pos,0);
    fread(&reg, sizeof reg,1, p);
    fclose(p);
    return reg;
}



bool ArchivoVentas::mostrarXarticulo()          ///    modificada
{
    archivoArt art("articulos.dat");
    Ventas ven;
    FILE *pp;
    pp=fopen("Ventas.dat", "rb");
    if(pp==NULL)
    {
        std::cout<< "No se pudo abrir el archivo "<<std::endl;
        return false;
    }
    ItemVenta res;
    FILE *p;
    p=fopen("ItemVenta.dat", "rb");
    if(p==NULL)
    {
        std::cout<< "No se pudo abrir el archivo "<<std::endl;
        return false;
    }
    int cod;
    std::cout << "Ingrese el codigo a buscar " << '\t';
    std::cin >> cod;
    system ("cls");
    int  pos = art.BuscarArchivoArt(cod);
    while(pos < 0)
    {
        std::cout << "CODIGO INCORRECTO - (Ingrese un codigo valido)" << std::endl;
        std::cout << std::endl;
        std::cout << "Ingrese el codigo a buscar " << '\t';
        std::cin >> cod;
        pos = art.BuscarArchivoArt(cod);
    }
    float Total=0;
    int cont=0;
    while (fread(&ven, sizeof ven,1, pp)==1 )
    {
        while (fread(&res, sizeof res,1, p)==1)
        {
            if (res.GetCodArticulo() ==cod)
            {
                std::cout<< "NUMERO DE FACTURA: "<<res.GetnFactura();
                std::cout << std::endl;
                std::cout << std::endl;
                ven.MostrarComoFactura();
                std::cout<< "Articulos: "<<std::endl;
                std::cout << std::endl;
                res.MostrarItemVenta();
                std::cout<<std::endl;
                std::cout<<std::endl;
                std::cout<< "Total de la venta : "<<" $ "<<ven.getImporte()<<std::endl;
                std::cout<<std::endl;
                std::cout <<"***********************************************"<< std::endl;
                std::cout << std::endl;
                std::cout << std::endl;
            }
        }
    }
    system("pause");
    system("cls");
    fclose(p);
    fclose(pp);
    return false;


}





bool ArchivoVentas::sobreEscribirReg(Ventas ven, int pos){
    FILE *pVen;
    pVen = fopen(nombre, "rb+");
    fseek(pVen, sizeof ven * pos, 0);
    bool aux = fwrite(&ven, sizeof ven, 1, pVen);
    fclose(pVen);
    return aux;
}





void ArchivoVentas::mostrarXcliente()
{
    archivoCli Cli("clientes.dat");
    ArchivoVentas ventas("ventas.dat");
    Cliente clientes;
    Ventas ven;
    FILE *pVen;
    pVen = fopen(nombre,"rb");

    int dni,pos;

    std::cout << "Ingrese el dni de el cliente a buscar: " << '\t';
    std::cin >> dni;
    system("cls");
    pos = Cli.BuscarClienteDni(dni);
    clientes = Cli.LeerArcCliente(pos);

    while(pos < 0)
    {
        std::cout << " --DNI INCORRECTO-- " << std::endl;
        std::cout << std::endl;
        std::cout << "Ingrese nuevamente un DNI: " << '\t';
        std::cin >> dni;
        pos = Cli.BuscarClienteDni(dni);
        clientes = Cli.LeerArcCliente(pos);
    }

    if(pVen == NULL)
    {
        std::cout << "-- NO SE PUDO MOSTRAR EL ARCHIVO --" << std::endl;
        return;
    }

    while(fread(&ven, sizeof ven, 1, pVen) == 1)
    {
        if(ven.GetDni() == dni)
        {
            ven.MostrarComoFacturaxCliente();
            std::cout << std::endl;
            std::cout << std::endl;
            system("pause");
        }
    }
    system("cls");
}

void ArchivoVentas::mostrarTodasLasVentas()
{
    archivoCli Cli("clientes.dat");
    ArchivoVentas ventas("ventas.dat");
    Cliente clientes;
    Ventas ven;
    FILE *pVen;
    pVen = fopen(nombre,"rb");

    int dni,pos;
    system("cls");



    if(pVen == NULL)
    {
        std::cout << "-- NO SE PUDO MOSTRAR EL ARCHIVO --" << std::endl;
        return;
    }
    std::cout << "-- LISTADO DE VENTAS --" << std::endl;
    std::cout << std::endl;
    while(fread(&ven, sizeof ven, 1, pVen) == 1)
    {
        ven.MostrarComoFacturaxCliente();
        std::cout << std::endl;
        std::cout << std::endl;
    }
    system("pause");
    system("cls");
}
