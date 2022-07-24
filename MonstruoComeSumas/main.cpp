#include <iostream>
#include<sstream>
#include<ctime>
#include <conio.h>
#include <iomanip>
using namespace std;

// variable global
void bienvenida();
void jugador(string *nombre,int numero);

void juego(string *nombreJugador1, string *nombreJugador2);//la funcion principal
bool validarPosicion(string);
int dado();
void camino(string *nombreJugador, int *posicionActual);
//Crear matrices
//VARIABLE IMPORTANTE
string matrizPantalla[11][8];
string matrizPantallaCopia[11][8];
int matrizResultado[11][8];

void crearMatrizPantalla();
void obtenerNumeros();
int numeroAleatorio();
void imprimirMatriz();
void imprimirMatrizResultado();
string parseInt(int, int);
void crearCopia();
void limpiarMatriz();

int main()
{
    srand(time(NULL));
    bienvenida();

    //Jugador 1
    //es una variable local su ambito es el int main
    string nombreJugador1;
    //jugador(&nombreJugador1,1);

    //Jugador 2
    string nombreJugador2;
    //jugador(&nombreJugador2,2);

    juego(&nombreJugador1,&nombreJugador2);

    system("pause");
    return 0;
}

void bienvenida()
{
    cout<<setw(70)<<"Bienvenido a la aplicacion"<<endl;
    cout<<setw(60)<<"Monstruo come sumas"<<endl;
}

void jugador(string *nombre, int numero)
{
    cout<<"Digite el nombre del jugador #"<<numero<<": ";
    cin>>*nombre ;
}

void crearMatrizPantalla()
{
    matrizPantalla[0][0] = "INICIO";
    matrizPantalla[10][0]="FIN";

    //monstruos
    matrizPantalla[0][2]="MONSTRUO";
    matrizPantalla[0][6]="MONSTRUO";

    matrizPantalla[2][2]="MONSTRUO";
    matrizPantalla[2][6]="MONSTRUO";
    matrizPantalla[4][2]="MONSTRUO";
    matrizPantalla[4][6]="MONSTRUO";
    matrizPantalla[6][2]="MONSTRUO";
    matrizPantalla[6][6]="MONSTRUO";
    matrizPantalla[8][2]="MONSTRUO";
    matrizPantalla[8][6]="MONSTRUO";
    matrizPantalla[10][2]="MONSTRUO";
    matrizPantalla[10][6]="MONSTRUO";

    //paredes
    matrizPantalla[1][0]="======";
    matrizPantalla[1][1]="======";
    matrizPantalla[1][2]="======";
    matrizPantalla[1][3]="======";
    matrizPantalla[1][4]="======";
    matrizPantalla[1][5]="======";
    matrizPantalla[1][6]="======";
    matrizPantalla[3][1]="======";
    matrizPantalla[3][2]="======";
    matrizPantalla[3][3]="======";
    matrizPantalla[3][4]="======";
    matrizPantalla[3][5]="======";
    matrizPantalla[3][6]="======";
    matrizPantalla[3][7]="======";
    matrizPantalla[5][0]="======";
    matrizPantalla[5][1]="======";
    matrizPantalla[5][2]="======";
    matrizPantalla[5][3]="======";
    matrizPantalla[5][4]="======";
    matrizPantalla[5][5]="======";
    matrizPantalla[5][6]="======";
    matrizPantalla[7][1]="======";
    matrizPantalla[7][2]="======";
    matrizPantalla[7][3]="======";
    matrizPantalla[7][4]="======";
    matrizPantalla[7][5]="======";
    matrizPantalla[7][6]="======";
    matrizPantalla[7][7]="======";
    matrizPantalla[9][0]="======";
    matrizPantalla[9][1]="======";
    matrizPantalla[9][2]="======";
    matrizPantalla[9][3]="======";
    matrizPantalla[9][4]="======";
    matrizPantalla[9][5]="======";
    matrizPantalla[9][6]="======";

    obtenerNumeros();
    crearCopia();

}

void obtenerNumeros()
{

    int operador1, operador2;
    stringstream s;
    for(int i=0; i<11; i++)
    {
        for(int j=0; j<8; j++)
        {
            operador1 = numeroAleatorio();
            operador2 = numeroAleatorio();

            if(matrizPantalla[i][j] == "")
            {
                matrizPantalla[i][j] = parseInt(operador1,operador2);
                matrizResultado[i][j] = operador1 + operador2;
            }

        }
    }
}


void imprimirMatriz()
{
    system("cls");
    cout<<endl<<"Carton"<<endl;
    for(int i=0; i<11; i++)
    {
        for(int j=0; j<8; j++)
        {
            cout<<setw(10)<<matrizPantalla[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

void imprimirMatrizResultado()
{
    //system("cls");
    cout<<endl<<"Carton"<<endl;
    for(int i=0; i<11; i++)
    {
        for(int j=0; j<8; j++)
        {
            cout<<setw(5)<<matrizResultado[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

void crearCopia()
{
    for(int i=0; i<11; i++)
    {
        for(int j=0; j<8; j++)
        {
            matrizPantallaCopia[i][j] = matrizPantalla[i][j];
        }

    }

}
void limpiarMatriz()
{
    for(int i=0; i<11; i++)
    {
        for(int j=0; j<8; j++)
        {
            matrizPantalla[i][j] = matrizPantallaCopia[i][j] ;
        }

    }

}

int numeroAleatorio()
{
    return 1 + rand()%50;
}

//convertirmos de int a string
string parseInt(int a, int b)
{
    stringstream s;
    s<<a<<"+"<<b;
    return s.str();
}

void juego(string *nombreJugador1, string *nombreJugador2)
{
    //1 es continuar
    //2 es salir
    int opcion=1;

    crearMatrizPantalla();

    int posicionActual;
    int resultadoDado;




    do
    {
        imprimirMatriz();
        //pedir la posicion Jugador1
        cout<<"Jugador: "<<*nombreJugador1<<endl;
        cout<<"Lanzar Dado presionar ENTER"<<endl;
        system("pause");

        resultadoDado = 7;

        //cout<<endl<<endl<<endl;
        //imprimirMatrizResultado();
        posicionActual += resultadoDado;
        camino(nombreJugador1,&posicionActual);

        imprimirMatriz();

        cout<<"dado: "<<resultadoDado<<endl;
        cout<<"Posicion Actual: "<<posicionActual<<endl;



        cout<<"Presione 1 para Continuar jugando"<<endl;
        cout<<"Presione cualquier tecla para Salir"<<endl;
        cin>>opcion;

    }
    while(opcion==1);
}

bool validarPosicion(string valor)
{
    // (valor == "INICIO" || valor =="FIN" || valor "======");
    return true;
}

int dado()
{
    return 1 + rand()%6;
}

void camino(string *nombreJugador, int *posicionActual)
{
    limpiarMatriz();

    switch(*posicionActual)
    {
    case 1:
    {
        matrizPantalla[0][0] = matrizPantalla[0][0] +"("+ *nombreJugador+")";
    }
    break;
    case 2:
    {
        matrizPantalla[0][1] = matrizPantalla[0][1] +"("+ *nombreJugador+")";
    }
    break;
    case 3:
    {
        //MONSTRUO
        matrizPantalla[0][2] = matrizPantalla[0][2] +"("+ *nombreJugador+")";
    }
    break;
    case 4:
    {
        matrizPantalla[0][3] = matrizPantalla[0][3] +"("+ *nombreJugador+")";
    }
    break;
    case 5:
    {
        matrizPantalla[0][4] = matrizPantalla[0][4] +"("+ *nombreJugador+")";
    }
    break;
    case 6:
    {
        matrizPantalla[0][5] = matrizPantalla[0][5] +"("+ *nombreJugador+")";
    }
    break;
    case 7:
    {
        //MONSTRUO
        matrizPantalla[0][6] = "SE DEVUELVE";
        matrizPantalla[0][2] = matrizPantalla[0][2] +"("+ *nombreJugador+")";

        *posicionActual -= 4;
    }
    break;
    case 8:
    {
        matrizPantalla[0][7] = matrizPantalla[0][7] +"("+ *nombreJugador+")";
    }
    break;
    case 9:
    {
        matrizPantalla[1][7] = matrizPantalla[1][7] +"("+ *nombreJugador+")";
    }
    break;
    case 10:
    {
        matrizPantalla[2][7] = matrizPantalla[2][7] +"("+ *nombreJugador+")";
    }
    break;
    case 11:
    {
        //MONSTRUO
        matrizPantalla[2][6] = "SE DEVUELVE";
        matrizPantalla[0][6] =  matrizPantalla[0][6] +"("+ *nombreJugador+")";
        *posicionActual -= 4;
    }
    break;
    case 12:
    {
        matrizPantalla[2][5] = matrizPantalla[2][5] +"("+ *nombreJugador+")";
    }
    break;
    case 13:
    {
        matrizPantalla[2][4] = matrizPantalla[2][4] +"("+ *nombreJugador+")";
    }
    break;
    case 14:
    {
        matrizPantalla[2][3] = matrizPantalla[2][3] +"("+ *nombreJugador+")";
    }
    break;
    case 15:
    {
        //MONSTRUO
        matrizPantalla[2][2] = "SE DEVUELVE";
        matrizPantalla[2][6] =  matrizPantalla[2][6]+"("+ *nombreJugador+")";
        *posicionActual -= 4;
    }
    break;
    case 16:
    {
        matrizPantalla[2][1] = matrizPantalla[2][1] +"("+ *nombreJugador+")";
    }
    break;
    case 17:
    {
        matrizPantalla[2][0] = matrizPantalla[2][0] +"("+ *nombreJugador+")";
    }
    break;
    case 18:
    {
        matrizPantalla[3][0] = matrizPantalla[3][0] +"("+ *nombreJugador+")";
    }
    break;
    case 19:
    {
        matrizPantalla[4][0] = matrizPantalla[4][0] +"("+ *nombreJugador+")";
    }
    break;
    case 20:
    {
        matrizPantalla[4][1] = matrizPantalla[4][1] +"("+ *nombreJugador+")";
    }
    break;
    case 21:
    {
        //MONSTRUO
        matrizPantalla[4][2] = "SE DEVUELVE";
        matrizPantalla[2][2] = matrizPantalla[2][2] +"("+ *nombreJugador+")";
        *posicionActual -= 6;
    }
    break;
    case 22:
    {
        matrizPantalla[4][3] = matrizPantalla[4][3] +"("+ *nombreJugador+")";
    }
    break;
    case 23:
    {
        matrizPantalla[4][4] = matrizPantalla[4][4] +"("+ *nombreJugador+")";
    }
    break;
    case 24:
    {
        matrizPantalla[4][5] = matrizPantalla[4][5] +"("+ *nombreJugador+")";
    }
    break;
    case 25:
    {
        //MONSTRUO
        matrizPantalla[4][6] = "SE DEVUELVE";
        matrizPantalla[4][2] = matrizPantalla[4][2] +"("+ *nombreJugador+")";
        *posicionActual -= 4;
    }
    break;
    case 26:
    {
        matrizPantalla[4][7] = matrizPantalla[4][7] +"("+ *nombreJugador+")";
    }
    break;
    case 27:
    {
        matrizPantalla[5][7] = matrizPantalla[5][7] +"("+ *nombreJugador+")";
    }
    break;
    case 28:
    {
        matrizPantalla[6][7] = matrizPantalla[6][7] +"("+ *nombreJugador+")";
    }
    break;
    case 29:
    {
        //MONSTRUO
        matrizPantalla[6][6] = "SE DEVUELVE";
        matrizPantalla[4][6] = matrizPantalla[4][6] +"("+ *nombreJugador+")";
        *posicionActual -= 4;
    }
    break;
    case 30:
    {
        matrizPantalla[6][5] = matrizPantalla[6][5] +"("+ *nombreJugador+")";
    }
    break;
    case 31:
    {
        matrizPantalla[6][4] = matrizPantalla[6][4] +"("+ *nombreJugador+")";
    }
    break;
    case 32:
    {
        matrizPantalla[6][3] = matrizPantalla[6][3] +"("+ *nombreJugador+")";
    }
    break;
    case 33:
    {
        //MONSTRUO
        matrizPantalla[6][2] = "SE DEVUELVE";
        matrizPantalla[6][6] = matrizPantalla[6][6] +"("+ *nombreJugador+")";
        *posicionActual -= 4;
    }
    break;
    case 34:
    {
        matrizPantalla[6][1] = matrizPantalla[6][1] +"("+ *nombreJugador+")";
    }
    break;
    case 35:
    {
        matrizPantalla[6][0] = matrizPantalla[6][0] +"("+ *nombreJugador+")";
    }
    break;
    case 36:
    {
        matrizPantalla[7][0] = matrizPantalla[7][0] +"("+ *nombreJugador+")";
    }
    break;
    case 37:
    {
        matrizPantalla[8][0] = matrizPantalla[8][0] + "("+ *nombreJugador+")";
    }
    break;
    case 38:
    {
        matrizPantalla[8][1] = matrizPantalla[8][1] + "("+ *nombreJugador+")";
    }
    break;
    case 39:
    {
        //MONSTRUO
        matrizPantalla[8][2] = "SE DEVUELVE";
        matrizPantalla[6][2] =  matrizPantalla[6][2] + "("+ *nombreJugador+")";
        *posicionActual -= 6;
    }
    break;
    case 40:
    {
        matrizPantalla[8][3] = matrizPantalla[8][3] +"("+ *nombreJugador+")";
    }
    break;
    case 41:
    {
        matrizPantalla[8][4] = matrizPantalla[8][4] +"("+ *nombreJugador+")";
    }
    break;
    case 42:
    {
        matrizPantalla[8][5] = matrizPantalla[8][5] +"("+ *nombreJugador+")";
    }
    break;
    case 43:
    {
        //MONSTRUO
        matrizPantalla[8][6] = "SE DEVUELVE";
        matrizPantalla[8][2] =  matrizPantalla[8][2] +"("+ *nombreJugador+")";
        *posicionActual -= 4;
    }
    break;
    case 44:
    {
        matrizPantalla[8][7] = matrizPantalla[8][7] +"("+ *nombreJugador+")";
    }
    break;
    case 45:
    {
        matrizPantalla[9][7] = matrizPantalla[9][7] +"("+ *nombreJugador+")";
    }
    break;
    case 46:
    {
        matrizPantalla[10][7] = matrizPantalla[10][7] +"("+ *nombreJugador+")";
    }
    break;
    case 47:
    {
        //MONSTRUO
        matrizPantalla[10][6] = "SE DEVUELVE";
        matrizPantalla[8][6]=matrizPantalla[8][6]+"("+ *nombreJugador+")";
        *posicionActual -= 4;
    }
    break;
    case 48:
    {
        matrizPantalla[10][5] = matrizPantalla[10][5] +"("+ *nombreJugador+")";
    }
    break;
    case 49:
    {
        matrizPantalla[10][4] = matrizPantalla[10][4] +"("+ *nombreJugador+")";
    }
    break;
    case 50:
    {
        matrizPantalla[10][3] = matrizPantalla[10][3] +"("+ *nombreJugador+")";
    }
    break;
    case 51:
    {
        //MONSTRUO
        matrizPantalla[10][2] = "SE DEVUELVE";
        matrizPantalla[10][6]=  matrizPantalla[10][6]+"("+ *nombreJugador+")";
        *posicionActual -= 4;
    }
    break;
    case 52:
    {
        matrizPantalla[10][1] = matrizPantalla[10][1] +"("+ *nombreJugador+")";
    }
    break;
    case 53:
    {
        matrizPantalla[10][0] = matrizPantalla[10][0] +"("+ *nombreJugador+")";
    }
    break;
    }
}
