//#include <Keypad.h>
//#include <Arduino.h>

char caractere;
char total[3] = {};
char teclas[4][4] = {

   	{'1','2','3','A'},  
		{'4','5','6','B'}, 
		{'7','8','9','C'}, 
		{'*','0','#','D'} 

};

int n = 0;

byte PinosLinha [4] = {12,11,10,9};
byte PinosColuna [4] = {8,7,6,5};

Keypad teclado (makeKeymap(teclas),PinosLinha,PinosColuna,4,4);

void setup() {

Serial.begin(9600);

}

void loop() {
  
  caractere = teclado.getKey();
    
  if(caractere) {
    if(caractere != 'B') {
    if(caractere != 'A') {
      Serial.print("Caractere: ");
      Serial.println(caractere);

      total[n] = caractere;
      n++; }
    else {
      total[n-1] = ' ';
      n--; }

    Serial.print("total: ");
    Serial.println(total); }
  else {
    Serial.print("FIM");

    n = 0;
    
    total[0] = ' ';
    total[1] = ' ';
    total[2] = ' '; 
    }
  }
}