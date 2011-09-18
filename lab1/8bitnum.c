/*
 @author TEAM 0xDEADBEEF
 This is a simple program which is supposed to represent numbers
 in binary. 8 bit intergers are represented via 8 LEDs.
*/

/** Function declartions here */
void showNum( char );

/** Tell which pins do what. */
void setup() {               
 char i;

 // 38 -> 45 are the leds for bits
 for ( i=38; i<45+1; ++i ){
    pinMode(i, OUTPUT);
 }

}

void loop() {
 char var;

 for ( var=0; var<256; ++var ){
   showNum( var );
   delay(500);
 }

}

/** In charge of setting the correct pins to
 display the numbers. */
void showNum( char num ) {
 char mask = 1;
 char lp;

 /** 8 bits */
 for ( lp=0; lp<8; ++lp ){
    digitalWrite( 38 + lp, mask & num );
    num >>= 1;
 }
}
