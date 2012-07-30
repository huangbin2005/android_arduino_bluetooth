#define VR_IN 0
#define LED 9
#define BUTTON 7
#define GLED 13

int val = 0;
String old_val="0";
int state =0;
int svalue=0;

void setup(){
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
  pinMode(GLED,OUTPUT);
}

void loop(){

  if(Serial.available()){
    String comdata = "";
    while (Serial.available() > 0)  
    {
      comdata += char(Serial.read());
      delay(2);
    }

    if(comdata!=old_val){
      if(comdata=="v0"){
        digitalWrite(GLED,HIGH);
      }
      else if(comdata=="v1"){
        digitalWrite(GLED,LOW);
      }
      else{
        analogWrite(LED,comdata.toInt());
      }
      svalue=analogRead(VR_IN);
      for(int i =0;i<4;i++){
        svalue=svalue+analogRead(VR_IN);
      }
      svalue= svalue/5;
      Serial.println(svalue);
      Serial.println(comdata);
      old_val =comdata;
    }
  }
  delay(500);
}


