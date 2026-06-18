// WhisperMagic v1 — ESP32 + SX1276 (915 MHz)
// TODO: All pin assignments must be verified against schematic before flashing

// SPI bus to SX1276
#define LORA_SCK    5     // TODO: confirm from schematic
#define LORA_MISO   19    // TODO: confirm from schematic
#define LORA_MOSI   27    // TODO: confirm from schematic
#define LORA_CS     18    // TODO: confirm from schematic (NSS)

// SX1276 control lines
#define LORA_RESET  14    // TODO: confirm from schematic
#define LORA_DIO0   26    // TX done / RX done interrupt
#define LORA_DIO1   33    // TODO: confirm from schematic
#define LORA_DIO2   32    // TODO: confirm from schematic

// SX1276 driver
#define USE_RF95

// Battery ADC
// TODO: calculate ADC_MULTIPLIER from voltage divider resistor values on schematic
// Formula: (R1 + R2) / R2  e.g. R1=100k, R2=100k → multiplier = 2.0
#define BATTERY_PIN     35    // TODO: confirm from schematic
#define ADC_CHANNEL     ADC_CHANNEL_7  // GPIO35 = ADC1_CH7 on ESP32
#define ADC_MULTIPLIER  2.0   // TODO: replace with actual divider ratio

// I2C bus (display / sensors — omit if board has neither)
#define I2C_SDA 21    // TODO: confirm from schematic
#define I2C_SCL 22    // TODO: confirm from schematic

// User button
#define BUTTON_PIN 0  // TODO: confirm from schematic
#define BUTTON_NEED_PULLUP

// Status LED — uncomment and set pin if board has one
// #define LED_POWER 25

// Power enable — uncomment if board has a VEXT / antenna boost enable pin
// #define VEXT_ENABLE 21  // active low
