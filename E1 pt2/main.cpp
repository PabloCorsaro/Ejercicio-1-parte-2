#include <iostream>
#include <fstream>

using namespace std;

string unPartido();
string unaLista();
string unCandidato();
string cantidaddeVotos();
string escribirPartido(string);
string escribirCandidatos(string);
string escribirLista(string);
string escribirVotos(string);
string escribirVotosenBlanco();
string escribirVotosImpugnados();
string escribirSenadores();
string escribirDiputados();
void crearArchivo();
void escribirArchivo(ofstream&);
string escribirTabulador();
string escribirEspacio();
string escribirCargo(string);
string escribirSeparacion();

int main()
{
    crearArchivo();

    return 0;
}

void crearArchivo()
{
    ofstream archivo;
    escribirArchivo(archivo);
}

string unPartido()
{
    string respuesta;
    cout << "Que partido: " << endl;
    getline(cin,respuesta);
    return respuesta;
}

string unaLista()
{
    string respuesta;
    cout << "Lista: " << endl;
    getline(cin,respuesta);
    return respuesta;
}

string unCandidato()
{
    string respuesta;
    cout << "Candidato: " << endl;
    getline(cin,respuesta);
    return respuesta;
}

string cantidaddeVotos()
{
    string respuesta;
    cout << "Cantidad de votos: " << endl;
    getline(cin,respuesta);
    return respuesta;
}

//Escribir

void escribirArchivo(ofstream &archivo)
{
    for(int h = 0 ; h < 5 ; h++)
    {
        string nombreArchivo;
        cout << "Numero de mesa: " << endl;
        getline(cin,nombreArchivo);

        archivo.open(nombreArchivo.c_str(),ios::out);

        for(int i = 0 ; i < 2 ; i++)
        {
            if(i == 0)
            {
            archivo << escribirCargo(escribirSenadores());
            archivo << escribirEspacio();
            }
            else
            {
            archivo << escribirEspacio() << escribirSeparacion() << escribirEspacio();
            archivo << escribirCargo(escribirDiputados());
            archivo << escribirEspacio();
            }
            for(int j = 0; j < 10 ; j++)
            {
                archivo << escribirPartido(unPartido());
                archivo << escribirEspacio();

                for(int k = 0; k < 3; k++)
                {
                    archivo << escribirCandidatos(unCandidato());
                    archivo << escribirTabulador();
                    archivo << escribirLista(unaLista());
                    archivo << escribirTabulador();
                    archivo << escribirVotos(cantidaddeVotos());
                    archivo << escribirEspacio();
                }
            }
            archivo << "Votos en Blanco:\t " << escribirTabulador() << escribirVotosenBlanco() << escribirEspacio();
            archivo << "Votos Impugnados:\t " << escribirTabulador() << escribirVotosImpugnados() << escribirEspacio();
        }

    archivo.close();

    }
}

string escribirSeparacion()
{
    return "---------------------------------------------------------------------------------------------------";
}
string escribirTabulador()
{
    return "\t";
}

string escribirEspacio()
{
    return "\n";
}

string escribirPartido(string partido)
{
    return partido;
}

string escribirCandidatos(string candidato)
{
    return candidato;
}

string escribirLista(string lista)
{
    return lista;
}

string escribirVotos(string votos)
{
    return votos;
}

string escribirVotosenBlanco()
{
    string respuesta;
    cout << "Votos en Blanco: " << endl;
    getline(cin,respuesta);
    return respuesta;
}

string escribirVotosImpugnados()
{
    string respuesta;
    cout << "Votos Impugnados: " << endl;
    getline(cin,respuesta);
    return respuesta;
}

string escribirSenadores()
{
    return "Senadores";
}

string escribirDiputados()
{
    return "Diputados";
}

string escribirCargo(string cargo)
{
    return cargo;
}
