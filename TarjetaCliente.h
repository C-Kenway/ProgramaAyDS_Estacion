using namespace std;

#ifndef TarjetaClientee_TarjetaCliente_h
#define TarjetaClientee_TarjetaCliente_h

#include "Tarjeta.h"
#include "Reloj.h"

class TarjetaCliente:public Tarjeta
{
public:
    TarjetaCliente();
    TarjetaCliente(int idCli, int idTarjeta,string Matricula);
    int getidCli();
    string getMatricula();
    void setidCli(int idCli);
    void setMatricula(string Matricula);
    //Metodos abstractos
    int calculaPago(Reloj HE, Reloj HS, int Tarifa);
    int calculaHorasCobrar(Reloj HE, Reloj HS);
    void muestraDatos();
private:
    int idCli;
    string Matricula;
};

TarjetaCliente::TarjetaCliente():Tarjeta()
{
    idCli=0;
    idTarjeta=0;
    Matricula="S/T";
}

TarjetaCliente::TarjetaCliente(int idCli, int idTarjeta,string Matricula)
{
    this-> idCli=idCli;
    this->idTarjeta=idTarjeta;
    this->Matricula=Matricula;
}

int TarjetaCliente::getidCli()
{
    return idCli;
}

void TarjetaCliente::setidCli(int idCli)
{
    this->idCli=idCli;
}

string TarjetaCliente::getMatricula()
{
    return Matricula;
}

void TarjetaCliente::setMatricula(string Matricula)
{
    this->Matricula=Matricula;
}


int TarjetaCliente::calculaPago(Reloj HE, Reloj HS, int Tarifa)
{
    return calculaHorasCobrar(HE,HS)*Tarifa;
}

int TarjetaCliente::calculaHorasCobrar(Reloj HE, Reloj HS)
{
    Reloj HoraTotal=HS-HE;
    int Mins=HoraTotal.getMin();
    int Hora=HoraTotal.getHora();

    if(Hora==0 and Mins<15)
        return 0;
    else
    {
        if(Mins>=15)
            return (Hora+1);
        else
            return Hora;
    }
}

void TarjetaCliente::muestraDatos()
{
    cout << "CLIENTE " << endl;
    cout << "ID Tarjeta: " << idTarjeta << endl;
    cout << "ID Cliente: " << idCli << endl;
    cout << "Matricula: " << Matricula<< endl;
}

#endif