#define NOTE_C3 131
#define NOTE_D3 147
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_G3 195
#define NOTE_A3 220
#define NOTE_B3 247
#define NOTE_C4 262
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440

byte pins[7] = {13,12,11,10,9,8,7};
byte show[10][7]={
	{0,0,0,0,0,0,1},
	{1,0,0,1,1,1,1},
	{0,0,1,0,0,1,0},
	{0,0,0,0,1,1,0},
	{1,0,0,1,1,0,0},
	{0,1,0,0,1,0,0},
	{1,1,0,0,0,0,0},
	{0,0,0,1,1,1,1},
	{0,0,0,0,0,0,0},
	{0,0,0,1,1,0,0},
};

int melody[]={
	NOTE_C4, NOTE_C4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C4
};

int noteDurations[] = {
	4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 4, 4, 2
};
int melody2[]={
  NOTE_G4, NOTE_E4, NOTE_E4, NOTE_F4, NOTE_D4, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4,NOTE_G4, NOTE_G4, NOTE_G4
};
int noteDurations2[] = {
  4, 4, 2, 4, 4, 2, 4, 4, 4, 4, 4, 4, 2
};
int d;
int btn;
int btn2;
int thisNote = -1, noteDuration = 0;
long previousTime = 0, presentTime = 0, pauseBetweenNotes = 0;
unsigned long startTime, count;

void setup(){
	for(byte i = 0; i < 7; ++i){
		pinMode(pins[i], OUTPUT);
	}
    pinMode(4, INPUT_PULLUP);
    startTime = millis() / 2000;
    pinMode(3,INPUT_PULLUP);
}

void checkToPlay(){
	presentTime = millis();
	if(presentTime - previousTime >= pauseBetweenNotes){
		thisNote += 1;
		if(thisNote >= 14){
			thisNote = -1;
			pauseBetweenNotes = 1000;
			previousTime = millis();
		}
		else{
			noteDuration = 1000 / noteDurations[thisNote];
            tone(6, melody[thisNote], noteDuration);
			pauseBetweenNotes = noteDuration * 1.2;
			previousTime = millis();
		}
	}
}
void checkToPlay2(){
	presentTime = millis();
	if(presentTime - previousTime >= pauseBetweenNotes){
		thisNote += 1;
		if(thisNote >= 13){
			thisNote = -1;
			pauseBetweenNotes = 1000;
			previousTime = millis();
		}
		else{
			noteDuration = 1000 / noteDurations2[thisNote];
            tone(6, melody2[thisNote], noteDuration);
			pauseBetweenNotes = noteDuration* 1.2;
			previousTime = millis();
		}
	}
}

void loop(){
	btn = digitalRead(4);
    btn2 = digitalRead(3);
    count = millis() / 2000 - startTime;
    set_decimal(count);
    if(btn == 0){
      d = 9 - d;
    }
    for(byte j = 0; j < 7; j++){
		digitalWrite(pins[j], show[d][j]);
	}
  if(btn2==0){
    
    checkToPlay2();}
  else{
    
    checkToPlay();}
	delay(2);
	
}


void set_decimal(int count){
  d = count%10;
 }