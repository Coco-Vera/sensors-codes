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
unsigned long startTime;void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
tdsBuffer[bufferIndex++] = analogRead(TDS_PIN);

  if (bufferIndex >= SCOUNT) bufferIndex = 0;



  long sum = 0;

  for (int i = 0; i < SCOUNT; i++) {

    sum += tdsBuffer[i];

  }

  float averageVoltage = sum * VREF / 1024.0 / SCOUNT;

  float tdsValue = (133.42 * pow(averageVoltage, 3)

                    - 255.86 * pow(averageVoltage, 2)

                    + 857.39 * averageVoltage) * 1.256; tdsBuffer[bufferIndex++] = analogRead(TDS_PIN);
  if (bufferIndex >= SCOUNT) bufferIndex = 0;

  long sum = 0;
  for (int i = 0; i < SCOUNT; i++) {
    sum += tdsBuffer[i];
  }
  float averageVoltage = sum * VREF / 1024.0 / SCOUNT;
  float tdsValue = (133.42 * pow(averageVoltage, 3)
                    - 255.86 * pow(averageVoltage, 2)
                    + 857.39 * averageVoltage) * 1.256;
}
