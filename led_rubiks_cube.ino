// This code was recovered from a project documentation and IS NOT COMPLETE. We sadly dont have the whole code anymore
int datapin=11; //Pin 11 des Arduino ist an den data input(DS) des Schieberegisters angeschlossen
int clockpin=12; //Pin 12 des Arduino ist an den clock Pin(SH_CP) des Schieberegisters angeschlossen
int latchpin=8; //Pin 8 des Arduino ist an den latch Pin(ST_CP) des Schieberegisters angeschlossen

byte ledB=B011; //Farbe Blau
byte ledG=B101; //Farbe Grün
byte ledR=B110; //Farbe Rot
byte ledV=B010; //Farbe Violet
byte ledY=B100;  //Farbe Gelb
byte ledT=B001;  //Farbe Türkis
byte ledW=000;  //Farbe Weiß
byte led0=111;   //Farbe Aus

//Erstellen einer Array mit allen 54 LEDs und deren standardmäßig sortierter Anordnung, diese wird dann bei den Knopfdrücken verändert z.B. leds[54] = leds[53]
byte leds[]={ledR,ledR,ledR,ledR,ledR,ledR,ledR,ledR,ledR,ledW,ledW,ledW,ledW,ledW,ledW,ledW,ledW,ledW,ledB,ledB,ledB,ledB,ledB,ledB,ledB,ledB,ledB,ledG,ledG,ledG,ledG,ledG,ledG,ledG,ledG,ledG,ledY,ledY,ledY,ledY,ledY,ledY,ledY,ledY,ledY,ledV,ledV,ledV,ledV,ledV,ledV,ledV,ledV,ledV};

//Temporäre Variablen für den Tausch der leds
byte t0=leds[45],t1=leds[46],t2=leds[47],t3=leds[48],t4=leds[49],t5=leds[50],t6=leds[51],t7=leds[52],t8=leds[53],b0=leds[36],b1=leds[37],b2=leds[38],b3=leds[39],b4=leds[40],b5=leds[41],b6=leds[42],b7=leds[43],b8=leds[44],d0=leds[27],d1=leds[28],d2=leds[29],d3=leds[30],d4=leds[31],d5=leds[32],d6=leds[33],d7=leds[34],d8=leds[35],l0=leds[18],l1=leds[19],l2=leds[20],l3=leds[21],l4=leds[22],l5=leds[23],l6=leds[24],l7=leds[25],l8=leds[26],f0=leds[9],f1=leds[10],f2=leds[11],f3=leds[12],f4=leds[13],f5=leds[14],f6=leds[15],f7=leds[16],f8=leds[17],r0=leds[0],r1=leds[1],r2=leds[2],r3=leds[3],r4=leds[4],r5=leds[5],r6=leds[6],r7=leds[7],r8=leds[8];

const int bpin[]={5,6,7,8,9,10,11,12,13,A0,A1,A2}; //Arry mit den verschiedenen möglichen Moves mit den Buttons

int wait=500; //variable für eine festgelegte Wartedauer(kann einfach für den gesamten Code verändert werden

void setup()
{

    pinMode(datapin, OUTPUT); //Pins auf Output stellen("Daten senden")
    pinMode(clockpin, OUTPUT); //Pins auf Output stellen("Daten senden") 
    pinMode(latchpin, OUTPUT); //Pins auf Output stellen("Daten senden")
 
    for (int i=0;i<12;i++) //Wird für alle 12 möglichen Moves widerholt
    {
        pinMode(bpin[i],INPUT); //bpin[i]/alle möglichen Pins für die Knöpfe auf INPUT, so können wir abfragen ob ein Signal kommt
        digitalWrite(bpin[i],HIGH); //bpin[i]/alle möglichen Pins für die Knöpfe werden auf HIGH gestellt
    }
 
    digitalWrite(latchpin, LOW); //Latch Pin auf LOW(aus), dass die Leds sich nicht ändern wärend neue Bits reingegeben werden
    for (int i=0; i<54;i++) //For Schleife(Der Vorgang wird für alle 54 LEDs/Schieberegister widerholt)
    { 
        shiftOut(datapin, clockpin, MSBFIRST, leds[i]);  //LEDs werde sortiert eingeschaltet(Cube geht an)
    }
    digitalWrite(latchpin, HIGH);  //Latch Pin auf HIGH(an), um die "änderungen anzuzeigen"
}

void loop()
{
    digitalWrite(latchpin,LOW);
    for(int i=0;i<54;i++) //Wird für alle 54 LEDs/Schieberegister widerholt
    { 
        shiftOut(datapin, clockpin, MSBFIRST, leds[i]); //ShiftOut Befehl wird durch loop jedes mal widerholt(somit werden Änderungen übernommen)
    }
    digitalWrite(latchpin, HIGH);

    for(int i=0;i<12;i++)
    {
        digitalWrite(bpin[i],HIGH); //Jeder mögliche Move wird nochmals auf HIGH gestellt
    }

    int b[12]; //12 Zusätzliche Variablen erstellen in denen der Status der Buttons gespeichert wird.
    for (int x=0;x<12;x++) //Schleife für jeden möglichen move
    {
        b[x]=digitalRead(bpin[x]); //Es wird der Wert in jeder Variable der Array ausgelesen
    }
    if(((b[0]==LOW))) //IF abfrage für einen move
    {
        //rotate left face CCW
        t0=leds[45],t1=leds[46],t2=leds[47],t3=leds[48],t4=leds[49],t5=leds[50],t6=leds[51],t7=leds[52],t8=leds[53],b0=leds[36],b1=leds[37],b2=leds[38],b3=leds[39],b4=leds[40],b5=leds[41],b6=leds[42],b7=leds[43],b8=leds[44],d0=leds[27],d1=leds[28],d2=leds[29],d3=leds[30],d4=leds[31],d5=leds[32],d6=leds[33],d7=leds[34],d8=leds[35],l0=leds[18],l1=leds[19],l2=leds[20],l3=leds[21],l4=leds[22],l5=leds[23],l6=leds[24],l7=leds[25],l8=leds[26],f0=leds[9],f1=leds[10],f2=leds[11],f3=leds[12],f4=leds[13],f5=leds[14],f6=leds[15],f7=leds[16],f8=leds[17],r0=leds[0],r1=leds[1],r2=leds[2],r3=leds[3],r4=leds[4],r5=leds[5],r6=leds[6],r7=leds[7],r8=leds[8];
        leds[51]=leds[15];
        leds[50]=leds[14];
        leds[45]=leds[9];
        leds[42]=t6;
        leds[41]=t5;
        leds[36]=t0;
        leds[33]=b6;
        leds[32]=b5;
        leds[27]=b0;
        leds[15]=d6;
        leds[14]=d5;
        leds[9]=d0;
        leds[26]=leds[24];
        leds[21]=leds[25];
        leds[20]=l8;
        leds[19]=l3;
        leds[18]=l2;
        leds[23]=l1;
        leds[24]=l0;
        leds[25]=l5;
        delay(wait);
    }
    // ... other Moves
}