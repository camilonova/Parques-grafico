//#include <graphics.h>
#include <stdlib.h>					
#include <stdio.h>
#include <string.h>
#include <iostream.h>
#include <conio.h>
#include "tablero.h"

void pintarTablero(void);	 					  	// Funcion que dibuja el tablero en pantalla
void dibujarFichas(void);     					// Funcion que pinta las fichas
void jugar(void);										// Funcion que genera el dialogo de juego
void cambiarTurno(void);         				// Cambia el turno de juego
void hacerMovimiento(int);			   	      // Hace el movimiento dependiendo las casillas a mover

int posicionTablero[49][2] =  {{176,40} ,{216,40} ,{256,40} ,{296,40} ,{336,40} ,{376,40} ,{416,40},
									    {176,80} ,{0,0}    ,{0,0}    ,{296,80} ,{0,0}    ,{0,0}    ,{416,80},
                               {176,120},{0,0}    ,{0,0}    ,{296,120},{0,0}    ,{0,0}    ,{416,120},
                               {176,160},{216,160},{256,160},{296,160},{336,160},{376,160},{416,160},
                               {176,200},{0,0}    ,{256,}   ,{296,200},{0,0}    ,{0,0}    ,{416,200},
                               {176,240},{0,0}    ,{256,}   ,{296,240},{0,0}    ,{0,0}    ,{416,240},
                               {176,280},{216,280},{256,280},{296,280},{336,280},{376,280},{416,280}};

char *posicionFichas[7][7] = {{"1","0","0","0","0","0","4"},
                              {"0","0","0","0","0","0","0"},
                              {"0","0","0","0","0","0","0"},
                              {"0","0","0","0","0","0","0"},
                              {"0","0","0","0","0","0","0"},
                              {"0","0","0","0","0","0","0"},
                              {"2","0","0","0","0","0","3"}};

// Representa el jugador actual
int jugadorActual = 1;

// LLevamos un registro de las casillas de cada jugador
int casillasJugador1 = 0;
int casillasJugador2 = 0;
int casillasJugador3 = 0;
int casillasJugador4 = 0;

// Funcion principal del programa
void main() {
	bool jugar = true;
   int casillasAMover;
   char eleccion;

  	pintarTablero();			// Dibujamos el tablero de juego

   // Ejecutamos el ciclo mientras jugar sea true
   do{
      gotoxy(12,25);
      cout<< "Bienvenido al parques.\n" << endl;
      cout<< "\t1.\t Jugar." << endl;
      cout<< "\t2.\t Salir." << endl;
      cin>> eleccion;

      setfillstyle(0,0);
      bar(0,350,getmaxx(),getmaxy());
      gotoxy(12,25);

      switch(eleccion){
      	case '1':
         	cout<< "El jugador actual es el numero: " << jugadorActual << endl;
            cout<< "\tDigite el numero de casillas que desea mover: ";
            cin>> casillasAMover;
            if (casillasAMover >0 &&  casillasAMover<7)
            hacerMovimiento(casillasAMover);
            else {cout<<"\tDigite numero valido";cin.get();cin.get();}
            if(strcmp(posicionFichas[3][3], "0") != 0){
            	setfillstyle(0,0);
					bar(0,350,getmaxx(),getmaxy());
					gotoxy(12,25);
            	cout<<"El jugador "<<posicionFichas[3][3] << " gana la partida" << endl;
               jugar = false;
               cin.get();
               cin.get();
            }
            break;
         case '2':
         	cout<< "Gracias por jugar.";
         	jugar = false;
            cin.get();
            cin.get();
            break;
         default:
         	cout<< "Digite una opcion valida";
            cin.get();
            cin.get();
            break;
      }

      setfillstyle(0,0);
      bar(0,350,getmaxx(),getmaxy());
      gotoxy(12,25);

   } while(jugar);

	closegraph();				// Termina el driver de graficos - Salir
}

void pintarTablero()   {
 	gra();						//Funcion para cargar los graficos desde la libreria
	tablero();              //Funcion para pintar el tablero desde la libreria
   dibujarFichas();			//Funcion para pintar las fichas
}

void dibujarFichas() {
	int k = 0;
	for(int i=0; i < 7; i++)
   	for(int j=0; j < 7; j++) {
      	if(strcmp(posicionFichas[i][j], "0") != 0){
         	outtextxy(posicionTablero[k][0], posicionTablero[k][1], posicionFichas[i][j]);
         }
         k++;
      }
}

// Solo debe ser llamada al terminar el juego del jugador actual
void cambiarTurno(){
	if(jugadorActual == 4)
   	jugadorActual = 1;
   else
   	jugadorActual++;
}

void hacerMovimiento(int casillas) {
	int posX, posY;

   if(jugadorActual == 1){
   	casillasJugador1 += casillas;
     	for(int i=0; i < 7; i++){
      	for(int j=0; j < 7; j++){
	      	// Borramos la posicion anterior de la ficha
           	if(strcmp(posicionFichas[i][j], "1") == 0){
              	posicionFichas[i][j] = "0";
               posX = i;
               posY = j;
            }
          }
      }

      for(int i=0; i < casillas; i++){
       	if(posX < 3 && posY == 3 )
				posX++;
       	if(posY == 0)
         	posX++;
         if(posX == 6)
				posY++;
         if(posY == 6)
         	posX--;
         if(posX == 0 && posY > 3)
				posY--;
         if(i == casillas-1)
         	posicionFichas[posX][posY] = "1";
      }

      pintarTablero();
    }
    if(jugadorActual == 2){
    	casillasJugador2 += casillas;
     	for(int i=0; i < 7; i++){
      	for(int j=0; j < 7; j++){
	      	// Borramos la posicion anterior de la ficha
           	if(strcmp(posicionFichas[i][j], "2") == 0){
              	posicionFichas[i][j] = "0";
               posX = i;
               posY = j;
            }
          }
      }

      for(int i=0; i < casillas; i++){
         if(posX == 3 && posY < 3)
         	posY++;
         if(posX == 6)
				posY++;
         if(posY == 6)
         	posX--;
         if(posX == 0)
				posY--;
      	if(posY == 0 && posX < 3)
         	posX++;
         if(i == casillas-1)
         	posicionFichas[posX][posY] = "2";
      }

      pintarTablero();
    }
    if(jugadorActual == 3){
    	casillasJugador3 += casillas;
     	for(int i=0; i < 7; i++){
      	for(int j=0; j < 7; j++){
	      	// Borramos la posicion anterior de la ficha
           	if(strcmp(posicionFichas[i][j], "3") == 0){
              	posicionFichas[i][j] = "0";
               posX = i;
               posY = j;
            }
          }
      }

      for(int i=0; i < casillas; i++){
			if(posY == 3 && posX > 3)
         	posX--;
         if(posY == 6)
         	posX--;
         if(posX == 0)
				posY--;
      	if(posY == 0)
         	posX++;
         if(posX == 6 && posY < 3)
				posY++;
         if(i == casillas-1)
         	posicionFichas[posX][posY] = "3";
      }

      pintarTablero();
    }
    if(jugadorActual == 4){
    	casillasJugador4 += casillas;
     	for(int i=0; i < 7; i++){
      	for(int j=0; j < 7; j++){
	      	// Borramos la posicion anterior de la ficha
           	if(strcmp(posicionFichas[i][j], "4") == 0){
              	posicionFichas[i][j] = "0";
               posX = i;
               posY = j;
            }
          }
      }

      for(int i=0; i < casillas; i++){
      	if (posX == 3 && posY>3)
         	posY--;
         if(posX == 0)
				posY--;
      	if(posY == 0)
         	posX++;
         if(posX == 6)
				posY++;
         if(posY == 6 && posX>3)
         	posX--;
         if(i == casillas-1)
         	posicionFichas[posX][posY] = "4";
      }

      pintarTablero();
    }
    cambiarTurno();
}
