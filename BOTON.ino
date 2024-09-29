//EJEMPLO DE USO DE BOTONES
#include "Nextion.h"

NexPage p0=NexPage(0,0,"page0");//Definir página 0
NexPicture lampPicture=NexPicture(0,1,"p0");//NO DE PAGINA, ID, NOMBRE EN NEXTION
NexButton lampButton=NexButton(0,2,"b0");

bool lampButtonStatus=true; //Definir variable para cambiar imagen

NexTouch *nex_listen_list[] = //Lista con los objetos con evento
{ 
  &lampButton, //OBJETOS QUE TIENEN UN EVENTO AL PRESIONARSE
  NULL
};

void lampButtonCallback(void *ptr) //FUNCION QUE SE VA A LLAMAR CUANDO SE PRESIONA EL BOTON
{
  dbSerialPrintln("Presionado"); //Mostrar en el monitor serial que se presionó 
  lampButtonStatus =!lampButtonStatus; //Invertir variable lampButtonStatus SI ES FALSE LO CAMBIA A TRUE
  //SI ES TRUE LO CAMBIA A FALSE
  if(lampButtonStatus== true)//si se enciende la lampara
  {
    lampButton.setText("Apagar"); //Cambia el texto del boton
    lampPicture.setPic(0);//cambia imagen al estado de encendido se cambia con el ID
  }
  else //si se apaga la lámpara
  {
    lampButton.setText("Encender"); //cambia texto a encender
    lampPicture.setPic(1); //cambia estado de la imagen
  }
}
void setup() {
  // put your setup code here, to run once:
  nexInit();
  lampButton.attachPop(lampButtonCallback,&lampButton) ;//con método attachpop relaciona la funcion
  //que se activara cuando se presione el botón
}

void loop() {
  // put your main code here, to run repeatedly:
  nexLoop(nex_listen_list);
}
