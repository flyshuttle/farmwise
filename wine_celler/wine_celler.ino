#include <dht11.h>

dht11 myDHT_2;

int temp;
int humi;
int signal; //继电器开关指示：断开0，闭合1


int dht_2_gettemperature() {

  int chk = myDHT_2.read(2);

  int value = myDHT_2.temperature;

  return value;

}



int dht_2_gethumidity() {

  int chk = myDHT_2.read(2);

  int value = myDHT_2.humidity;

  return value;

}

void setup()

{

  Serial.begin(9600);
  temp = 0;
  humi=0;
  signal=0;
  pinMode(7, OUTPUT);	//设置管脚7为输出管脚
  digitalWrite(7,LOW);	//设置管脚7状态为低

}



void loop()

{
  temp=dht_2_gettemperature();
  humi=dht_2_gethumidity();



  if (temp <= 30) {//如果温度低于30度
    if (signal== 0){
       digitalWrite(7,HIGH);  //设置数字管脚7状态为HIGH，闭合继电器
       signal=1;

    }       

  } else if (temp >= 40) {//如果温度高于40度
       if (signal== 1){
          digitalWrite(7,LOW);  //设置数字管脚7状态为LOW，断开继电器
          signal=0;
       }       
    }
      Serial.println(temp);
      Serial.println(humi);
      Serial.println(signal);
      Serial.println(digitalRead(7));

    delay(1000);
  }
  


