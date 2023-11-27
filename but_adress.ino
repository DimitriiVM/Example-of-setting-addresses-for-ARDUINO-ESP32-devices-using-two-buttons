//Задание адреса на основе двух кнопок
#define pinnumberone A0 //Кнопка 1
#define pinnumbertwo A1 //Кнопка 2
#define pinlednuberone A2//Световой индикатор режима

bool flag_pinnumberone = false;
bool flag_pinnumbertwo = false;
bool flag_led = false;
int countnumber = 0;
uint32_t timer = 0;
uint32_t timer2 = 0;
uint32_t timerled = 0;
uint32_t timercount = 0;
bool btstatusone = false;
bool btstatustwo = false;

void setup() {
  pinMode(pinnumberone, INPUT_PULLUP);
  pinMode(pinnumbertwo, INPUT_PULLUP);
  pinMode(pinlednuberone, OUTPUT);
  //Иницилизация кнопок
  Serial.begin(115200);
  Serial.println("Start OK!");

}

void loop() {
  //Serial.print("Сейчас задан адрес: ");
  //Serial.println(countnumber);

  btstatusone = !digitalRead(pinnumberone);
  btstatustwo = !digitalRead(pinnumbertwo);

  if(btstatusone && millis() - timer > 250){
    /*
    flag_pinnumberone = true;
    timer = millis();
    Serial.println("BT ONE ON");
    */
    if(!flag_pinnumberone){
      flag_pinnumberone = true;
      flag_led = true;
      countnumber = 0;
      Serial.println("ON");
    }
    else{
      flag_pinnumberone = false;
      flag_led = false;
      Serial.println("OFF");
    }
    timer = millis();
  }

  if(millis() - timerled > 100){
    digitalWrite(pinlednuberone, flag_led);
    timerled = millis();
  }
  //Указываем какой адрес выбран в режиме настройки

  if(millis() - timercount > 3000){
    if(!flag_pinnumberone){
    Serial.print("Адрес счетчика:");
    Serial.println(countnumber);
    }
    timercount = millis();
  }

  if(btstatustwo && millis() - timer2 > 250){
    if(flag_pinnumberone){
      countnumber++;
    }
    timer2 = millis();
  }
  //Если мы в режиме настройки светодиод загорается

  /*
  if(!btstatusone && flag_pinnumberone && millis() - timer > 100){
    flag_pinnumberone = false;
    timer = millis();
    Serial.println("BT ONE OFF");
  }
  */





}
