// *******************************************************************************************************************************
// START userdefined data
// *******************************************************************************************************************************
#include <Arduino.h>
// Turn logging on/off - turn read logfile on/off, turn delete logfile on/off ---> default is false for all 3, otherwise it can cause battery drainage.
const bool  logging = false;
const bool  readLogfile = false;
const bool  deleteLogfile = false;
String readString; // do not change this variable

// Select DHT type on the module - supported are DHT11, DHT12, DHT22 -- Even if you do not have one, you have to uncomment one, as compilation else will fail.
#define DHT_TYPE DHT11
// #define DHT_TYPE DHT12
//#define DHT_TYPE DHT22

// Set to true if you have a DHT sensor on the board, and false if not
bool dht_found = false;

// Select if 18B20 soil temp sensor available, if available -->> set to true
const bool USE_18B20_TEMP_SENSOR = false;

// It is a really good thing to calibrate each unit for soil, first note the number when unit is on the table, the soil number is for zero humidity. Then place the unit up to the electronics into a glass of water, the number now is the 100% humidity.
// By doing this you will get the same readout for each unit. Replace the value below for the dry condition, and the 100% humid condition, and you are done.

// Soil defaults - change them to your calibration data
int soil_min = 1506;
int soil_max = 3500;
bool calibrate_soil = true;

// Salt/Fertilizer recommandation break points. You can change these according to your own calibration measurements.
int fertil_needed = 200;
int fertil_low = 201;
int fertil_opt = 251;
int fertil_high = 351;

// Give the sensor a plant name, change to true, upload sketch and then revert to false
const bool update_plant_name = true;
String plant_name = "Lettuce";

//If using the Greenhouse automatic watering repo, then assign a waterValveNo to the plant. 
int plantValveNo = 1;

// define your SSID's, and remember to fill out variable ssidArrNo with the number of your SSID's
String ssidArr[] = {"WudiGYQ2"};
int ssidArrNo = 1;

const char* ssid = ""; // no need to fill in
const char* password = "0Kddffsgd!";
const char* ntpServer = "pool.ntp.org";

// Off-sets for time, and summertime. each hour is 3.600 seconds.
const long  gmtOffset_sec = 28800;

// Device configuration and name setting
const String device_name = "Tgrow_HIGrow"; // Can be changed, but not necessary, as it will give no added value.

#define uS_TO_S_FACTOR 1000000ULL //Conversion factor for micro seconds to seconds
#define TIME_TO_SLEEP  3600       //Time ESP32 will go to sleep (in seconds)

const char broker[] = "192.168.0.109";
int        port     = 1883;
const char mqttuser[] = "manymuch"; //add eventual mqtt username
const char mqttpass[] = "83344253"; //add eventual mqtt password

// *******************************************************************************************************************************
// END userdefined data
// *******************************************************************************************************************************
