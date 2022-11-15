const float arduino_clock_time_us = 0.0625;

const float horizontal_visible_area_time_us = 25.422045680238; // 25.6us
const float horizontal_front_porch_time_us = 0.63555114200596; //630ns
const float horizontal_sync_pulse_time_us = 3.8133068520357; //37.8 us
const float horizontal_back_porch_time_us = 1.9066534260179; //1.92us

const unsigned int vertical_visible_area_lines = 480;
const unsigned int vertical_front_porch_lines = 10;
const unsigned int vertical_sync_pulse_lines = 2;
const unsigned int vertical_back_porch_lines = 33;

inline __attribute__((always_inline)) void Constant_Horizontal_Line();

void setup() {
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  while (true)
  {
    for (unsigned int i = 0; i < vertical_visible_area_lines; i++)
    {
      PORTD |= 0b11111100;
      PORTB |= 0b00000111;
      Constant_Horizontal_Line();
    }

    for (unsigned int i = 0; i < vertical_front_porch_lines; i++)
    {
      PORTD &= 0b00000011;
      PORTB &= 0b11111000;
      Constant_Horizontal_Line();
    }

    PORTB &= 0b11101111;
    for (unsigned int i = 0; i < vertical_sync_pulse_lines; i++)
    {
      PORTD &= 0b00000011;
      PORTB &= 0b11111000;
      Constant_Horizontal_Line();
    }
    PORTB |= 0b00010000;

    for (unsigned int i = 0; i < vertical_back_porch_lines; i++)
    {
      PORTD &= 0b11111111;
      PORTB &= 0b11111111;
      Constant_Horizontal_Line();
    }
  }
}

void Constant_Horizontal_Line()
{
  // Visible area
  __builtin_avr_delay_cycles(horizontal_visible_area_time_us / arduino_clock_time_us - 6);

  // Vertical Front porch
  PORTD &= 0b00000011;
  PORTB &= 0b11111000;
  __builtin_avr_delay_cycles(horizontal_front_porch_time_us / arduino_clock_time_us - 5);

  // Sync pulse
  PORTB &= 0b11110111;
  __builtin_avr_delay_cycles(horizontal_sync_pulse_time_us / arduino_clock_time_us - 2);
  PORTB |= 0b00001000;

  __builtin_avr_delay_cycles(horizontal_back_porch_time_us / arduino_clock_time_us - 9);
}
