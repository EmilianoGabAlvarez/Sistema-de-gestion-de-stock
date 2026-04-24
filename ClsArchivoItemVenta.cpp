#include<iostream>
#include<cstring>

#include"ClsArchivoArticulo.h"
#include"ClsArchivoCliente.h"
#include"ClsArchivoItemVenta.h"



void ArchivoItemVenta::setCantStock1(int cod, int nfac )  ///Esta funcion tiene que pasar a archivo Item ventas
{
    archivoArt art("articulos.dat");
    articulo articulos;

    ItemVenta ItVenta;
    ArchivoItemVenta ArchItem("ItemVenta.dat");

    archivoCli arC("clientes.dat");
    Cliente clientes;
    int pos,dni,cant;

    FILE *pIven;
    pIven=fopen("ItemVenta.dat","ab");
    if(pIven==NULL)
    {
        std::cout <<"No se pudo crear el archivo "<<std::endl;
        return;
    }
    pos = art.BuscarArchivoArt(cod);

    while(pos < 0)
    {
        std::cout << "No se encontro articulo con este codigo " << std::endl;
        std::cout<<std::endl;
        std::cout << "ingrese un codigo distinto " << std::endl;
        std::cin >> cod;
        std::cout << std::endl;

        pos = art.BuscarArchivoArt(cod);
    }
    articulos = art.LeerArcArticulo(pos);
    system("cls");
    std::cout << std::endl;
    articulos.mostrar();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Ingrese la cantidad : " << '\t';
    std::cin >> cant;
    std::cout << std::endl;

    while(cant > articulos.getStock())
    {
        std::cout << " --SUPERA EL STOCK DISPONIBLE-- " << std::endl;
        std::cout << std::endl;
        std::cout << "Ingrese nuevamente una cantidad menor al stock disponible" << std::endl;
        std::cin >> cant;
        std::cout << std::endl;
    }
    int s;
    s =articulos.getStock()-cant;
    art.ModificarStockArt(cod,s);
    pos = art.BuscarArchivoArt(cod);
    int Total = articulos.getPrecio()*cant;
    ItVenta.SetCantidad(cant);
    ItVenta.SetCodArticulo(cod);
    ItVenta.SetImporte(Total);
    ItVenta.SetnDni(dni);
    ItVenta.SetnFactura(nfac);
    ArchItem.escribirRegistro(ItVenta);
    fclose(pIven);

}

bool ArchivoItemVenta::escribirRegistro(ItemVenta obj){
    FILE *p;
    p=fopen("ItemVenta.dat", "ab");
    if(p==NULL) return false;
    bool escribio = fwrite(&obj, sizeof(obj), 1, p);
    fclose(p);
    return escribio;
}


ArchivoItemVenta::ArchivoItemVenta(const char *n){
    strcpy(Nombre, n);
}

ItemVenta ArchivoItemVenta::leerRegistro(int pos)
{
    ItemVenta reg;
    FILE *p;
    p=fopen("ItemVenta.dat", "rb");
    if(p==NULL) return reg;
    fseek(p, sizeof reg*pos,0);
    fread(&reg, sizeof reg,1, p);
    fclose(p);
    return reg;
}


int ArchivoItemVenta::contarRegistros()
{
    FILE *p;
    p=fopen("ItemVenta.dat", "rb");
    if(p==NULL) return -1;
    fseek(p, 0,2);
    int tam=ftell(p);
    fclose(p);
    return tam/sizeof(ItemVenta);
}


bool ArchivoItemVenta::escribirRegistro(){
    FILE *p;
    p=fopen(Nombre, "ab");
    if(p==NULL) return false;
    bool escribio = fwrite(this, sizeof(ArchivoItemVenta), 1, p);
    fclose(p);
    return escribio;

}



bool ArchivoItemVenta::ListarxFactura()              ///  FUNCION MUESTRA ITEM VENTA POR FACTURA
{
    Ventas ven;
    FILE *pp;
    pp=fopen("Ventas.dat", "rb");
    if(pp==NULL)
    {
        std::cout<< "No se pudo abrir el archivo "<<std::endl;
        return false;
    }
    int nFac;

    std::cout<< "Ingrese el numero de factura a buscar: "<<std::endl;
    std::cin>>nFac;
    system ("cls");
    int cont=0;
    while (fread(&ven, sizeof ven,1, pp)==1 && cont==0)
    {
        if (ven.getNumeroFactura() ==nFac)
        {
            ven.MostrarComoFactura();
            cont++;
            std::cout<<std::endl;
        }
    }
    ItemVenta res;
    FILE *p;
    p=fopen("ItemVenta.dat", "rb");
    if(p==NULL)
    {
        std::cout<< "No se pudo abrir el archivo "<<std::endl;
        return false;
    }
    float Tot=0;
    std::cout<< "Articulos: "<<std::endl;
    std::cout << std::endl;
    while (fread(&res, sizeof res,1, p)==1)
    {
        if (res.GetnFactura()==nFac)
        {
            res.MostrarItemVenta();
            Tot+=res.GetImporte();
            std::cout<<std::endl;
        }
    }
    std::cout<<std::endl;
    std::cout<< "Total de la venta : "<<" $ "<<Tot<<std::endl;
    std::cout<<std::endl;
    std::cout <<"***********************************************"<< std::endl;
    system("pause");
    fclose(p);
    fclose(pp);
    return false;
}

bool ArchivoItemVenta::listarTodasLasVentas()              ///  FUNCION MUESTRA ITEM VENTA POR FACTURA
{
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
    system ("cls");
    int cont=0,nFac;
    while (fread(&ven, sizeof ven,1, pp)==1 && cont==0)
    {
        ven.MostrarComoFactura();
        nFac=ven.getNumeroFactura();
        cont++;
        std::cout<<std::endl;
    }

    float Tot=0;
    std::cout<< "Articulos: "<<std::endl;
    std::cout << std::endl;
    while (fread(&res, sizeof res,1, p)==1)
    {
        if (res.GetnFactura()==nFac)
        {
            res.MostrarItemVenta();
            Tot+=res.GetImporte();
            std::cout<<std::endl;
        }
    }
    std::cout<<std::endl;
    std::cout<< "Total de la venta : "<<" $ "<<Tot<<std::endl;
    std::cout<<std::endl;
    std::cout <<"***********************************************"<< std::endl;
    system("pause");
    fclose(p);
    fclose(pp);
    return false;
}




