#ifndef CLSCOBRANZA_H
#define CLSCOBRANZA_H


class clsCobranza
{
    private:
        float Deuda;
        int nCliente;

    public:
        clsCobranza();
        void setDeuda(float cob);
        void setnCliente(int numero);
        float getDeuda();
        int getnCliente();
        void Pagar(float pago);

};

#endif // CLSCOBRANZA_H
