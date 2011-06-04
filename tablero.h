void gra(void){
/* request auto detection */
int gdriver = DETECT, gmode, errorcode;

/* initialize graphics and local variables */
initgraph(&gdriver, &gmode, "");

/* read result of initialization */
errorcode = graphresult();
/* an error occurred */
if (errorcode != grOk)
{
	printf("Graphics error: %s\n", grapherrormsg(errorcode));
	printf("Press any key to halt:");
	getch();
	exit(1);
}
}

//*******************************************************************

// Tablero de 7x7
void tablero(void){
	int x,y;
	x=156;
	y=20;

   /*Lineas Horizontales*/
   line(x,y,x+280,y);
   y+= 40;
   line(x,y,x+280,y);
   y+= 80;
   line(x,y,x+280,y);
   y+= 40;
   line(x,y,x+280,y);
   y+= 80;
   line(x,y,x+280,y);
   y+= 40;
   line(x,y,x+280,y);

   /*Volvemos a las coordenadas iniciales*/
   x= 156;
   y= 20;

   /*Lineas Verticales*/
   line(x,y,x,y+280);
   x+= 40;
   line(x,y,x,y+280);
   x+= 80;
   line(x,y,x,y+280);
   x+= 40;
   line(x,y,x,y+280);
   x+= 80;
   line(x,y,x,y+280);
   x+= 40;
   line(x,y,x,y+280);

   /*Volvemos a las coordenadas iniciales*/
   x= 156;
   y= 20;

   // pintar divisiones horizontales
   y+=80;
   line(x,y,x+40,y);
   x+=120;
   line(x,y,x+40,y);
   x+=120;
   line(x,y,x+40,y);
   y+=120;
   x=156;
   line(x,y,x+40,y);
   x+=120;
   line(x,y,x+40,y);
   x+=120;
   line(x,y,x+40,y);

   /*Volvemos a las coordenadas iniciales*/
   x= 156;
   y= 20;

   // pintar divisiones verticales
   x+=80;
   line(x,y,x,y+40);
   y+=120;
   line(x,y,x,y+40);
   y+=120;
   line(x,y,x,y+40);
   x+=120;
   y=20;
   line(x,y,x,y+40);
   y+=120;
   line(x,y,x,y+40);
   y+=120;
   line(x,y,x,y+40);

   /*Volvemos a las coordenadas iniciales*/
   x= 156;
   y= 20;

   // Dibujamos la salida 1
   setfillstyle(5,7);
   bar(x+1,y+1,x+39,y+39);

   // Dibujamos la salida 2
   x= 396;
   y= 20;
   setfillstyle(5,7);
   bar(x+1,y+1,x+39,y+39);

   // Dibujamos la salida 3
   x= 156;
   y= 260;
   setfillstyle(5,7);
   bar(x+1,y+1,x+39,y+39);

   // Dibujamos la salida 4
   x= 396;
   y= 260;
   setfillstyle(5,7);
   bar(x+1,y+1,x+39,y+39);

   /*Volvemos a las coordenadas iniciales*/
   x= 156;
   y= 20;

   // Dibujamos la meta
   x+=120;
   y+=120;
   setfillstyle(3,7);
   bar(x+1,y+1,x+39,y+39);
}
