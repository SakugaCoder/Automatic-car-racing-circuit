#define CAR1_PIN_START 2
#define CAR1_PIN_END 4
#define CAR2_PIN_START 3
#define CAR2_PIN_END 5

bool car1_started = false;
bool car2_started = false;

unsigned long last_time = 0;
unsigned long time_start_car1 = 0;
unsigned long time_start_car2 = 0;

double seconds_car1 = 0.0;
double seconds_car2 = 0.0;

void setup() {
  Serial.begin(9600);
  pinMode(CAR1_PIN_START,INPUT_PULLUP);
  pinMode(CAR2_PIN_START,INPUT_PULLUP);
  pinMode(CAR1_PIN_END,INPUT_PULLUP);
  pinMode(CAR2_PIN_END,INPUT_PULLUP);
}

void loop() {

  //Auto #1
  
  //Si el auto #1 presionó el boton de la salida
  if( !digitalRead(CAR1_PIN_START) && !car1_started ){
    time_start_car1 = millis();
    car1_started = true;
    Serial.println("El auto #1 ha salido de la pista");
  }

  //Si el auto #1 presionó el boton de la meta
  if ( !digitalRead(CAR1_PIN_END) && car1_started ){
    seconds_car1 = (float(millis()) - float(time_start_car1)) / 1000;
    car1_started = false;
    time_start_car1 = 0;
    Serial.print("El auto #1 ha llegado a la meta en: ");
    Serial.print(seconds_car1);
    Serial.println(" segundos");
  }


  //Auto #2

  //Si el auto #2 presiono el boton de la salida
  if( !digitalRead(CAR2_PIN_START) && !car2_started ){
    time_start_car2 = millis();
    car2_started = true;
    Serial.println("El auto #2 ha salido de la pista");
  }

  //Si el aito #2 presiono el boton de la meta
  if ( !digitalRead(CAR2_PIN_END) && car2_started ){
    seconds_car2 = (float(millis()) - float(time_start_car2)) / 1000;
    car2_started = false;
    time_start_car2 = 0;
    Serial.print("El auto #2 ha llegado a la meta en: ");
    Serial.print(seconds_car2);
    Serial.println(" segundos");
  }
}
