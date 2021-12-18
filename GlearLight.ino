/*
Original code from http://jimspage.co.nz
Massive modifications made by Zakk Atkinson
http://ZakkBlog.com
*/


int CodeIn; //int to store incoming characters
String gearN,gearL,gearR; // incoming Gear string
int gearNi,gearLi,gearRi; //Gear string converted to Integer
int gearTot; // sum of gearNi, gearLi, and gearRi, added together 
int ngred=2;
int nggrn=3;
int ngblue=4;
int lgred=5;
int lggrn=6;
int lgblue=7;
int rgred=8;
int rggrn=9;
int rtgblue=10;

void setup()
{
Serial.begin(115200);
pinMode(ngred, OUTPUT); // gear nose red LED
pinMode(nggrn, OUTPUT); // gear nose green LED
pinMode(ngblue, OUTPUT); // gear nose blue LED

pinMode(lgred, OUTPUT); // gear left red LED
pinMode(lggrn, OUTPUT); // gear left green LED
pinMode(lgblue, OUTPUT); // gear left blue LED

pinMode(rgred, OUTPUT); // gear right red LED
pinMode(rggrn, OUTPUT); // gear right green LED
pinMode(rtgblue, OUTPUT); // gear right blue LED

//set gear pins LOW to start
digitalWrite(ngred, LOW);
digitalWrite(nggrn, LOW);
digitalWrite(ngblue, LOW);

digitalWrite(lgred, LOW);
digitalWrite(lggrn, LOW);
digitalWrite(lgblue, LOW);

digitalWrite(rgred, LOW);
digitalWrite(rggrn, LOW);
digitalWrite(rtgblue, LOW);
}

void loop()
{

{OTHER();}// Check for "Other" things to do.(Non extraction stuff)
 
 
if (Serial.available()) 
{
CodeIn = getChar();
if (CodeIn == '<') {LESSTHAN();}// The first identifier is "<"
}
}

char getChar()// Get a character from the serial buffer
{
while(Serial.available() == 0);// wait for data
return((char)Serial.read());// Thanks Doug

}

void LESSTHAN(){    // The first identifier was "<"
CodeIn = getChar(); // Get the second identifier
switch(CodeIn) {// Now lets find what to do with it

case 'A'://Found the second identifier "GearN"
gearN = "";
gearN += getChar(); //get the three digits that represent nose Gear location
gearN += getChar();
gearN += getChar();
gearNi = gearN.toInt(); // convert it to an integer (Thanks Phill)
if (gearNi > 99){ //if gear is fully down 

digitalWrite(ngred, LOW); //turn Nose red off
digitalWrite(nggrn, HIGH); // turn Nose green on
digitalWrite(ngblue, LOW); // turn Nose blue off
}

else if(gearNi == 0){
digitalWrite(ngred, LOW); //turn Nose red off
digitalWrite(nggrn, LOW); // turn Nose green off
digitalWrite(ngblue, HIGH); //turn Nose blue on
}

else{ //if any other case (see 'other' function for refinement) 

digitalWrite(ngred, HIGH); //turn Nose red on
digitalWrite(nggrn, LOW); // turn Nose green off
digitalWrite(ngblue, LOW); // turn Nose blue off
}
// See "OTHER" for more uses of gearni
break;
    
case 'B':
gearL = "";
gearL += getChar(); //get the three digits that represent left Gear location
gearL += getChar();
gearL += getChar();
gearLi = gearL.toInt(); // convert it to an integer (Thanks Phill)
if (gearLi > 99){//if gear is fully down 

digitalWrite(lgred, LOW); //turn left red off
digitalWrite(lggrn, HIGH); //turn left green on
digitalWrite(lgblue, LOW); //turn left blue off
}

else if(gearLi == 0){
digitalWrite(lgred, LOW); //turn Nose red off
digitalWrite(lggrn, LOW); // turn Nose green off
digitalWrite(lgblue, HIGH); //turn Nose blue on
}

else{//if any other case (see 'other' function for refinement)

digitalWrite(lgred, HIGH); //turn left red on
digitalWrite(lggrn, LOW); //turn left green off
digitalWrite(lgblue, LOW); //turn left blue off
}
// See "OTHER" for more uses of gearLi
break;
     
case 'C':
gearR = "";
gearR += getChar(); //get the three digits that represent right Gear location
gearR += getChar();
gearR += getChar();
gearRi = gearR.toInt(); // convert it to an integer (Thanks Phill)
if (gearRi > 99){//if gear is fully down 

digitalWrite(rgred, LOW); //turn right red off 
digitalWrite(rggrn, HIGH); //turn right green on
digitalWrite(rtgblue, LOW); //turn right blue off 
}

else if(gearRi == 0){
digitalWrite(rgred, LOW); //turn Nose red off
digitalWrite(rggrn, LOW); // turn Nose green off
digitalWrite(rtgblue, HIGH); //turn Nose blue on
}

else{//if any other case (see 'other' function for refinement)

digitalWrite(rgred, HIGH); //turn right red on 
digitalWrite(rggrn, LOW); //turn right green off
digitalWrite(rtgblue, LOW); //turn right blue off 
}
// See "OTHER" for more uses of gearRi
break;
}
}

void OTHER(){
/* In here you would put code that uses other data that
cant be put into an "extraction void" that references something else.
Also in here you would put code to do something that was not
relying on a current extraction trigger.
*/
//Sort out the gear "in transition" LED (redundancy to make sure it turns off when it's supposed to)
int gearTot = (gearNi + gearLi + gearRi);
if (gearTot == 300){
digitalWrite(ngred, LOW); //turn all three red gear LEDs off
digitalWrite(lgred, LOW);
digitalWrite(rgred, LOW);
} 
else if (gearTot == 1){
digitalWrite(ngred, LOW); //turn all three red gear LEDs off
digitalWrite(lgred, LOW);
digitalWrite(rgred, LOW);

}
}