#define PH_PIN A0
#define TDS_PIN A1
#define TURBIDITY_PIN A2

#define PUMP_RELAY 7
#define VALVE1_RELAY 8
#define VALVE2_RELAY 9

#define VREF 5.0
#define SCOUNT 30  

// ==== Calibration Factors ====
float tdsFactor = 1.256;
float pHCalibrationFactor = -5.7;
float pHIntercept = 17.825;

// ==== Buffers ====
int tdsBuffer[SCOUNT];
int bufferIndex = 0;

// ==== Timing ====
unsigned long startTime;
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
float turbVoltage = analogRead(TURBIDITY_PIN) * (5.0 / 1024.0);
  float turbidityValue = -1120.4 * sq(turbVoltage) + 5742.3 * turbVoltage - 4352.9;
}
