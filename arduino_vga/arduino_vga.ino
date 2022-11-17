const float arduino_clock_time_us = 0.0625;
const float pixel_clock_time_us = 0.1588877856;

const unsigned int horizontal_visible_area_pixels = 160;
const unsigned int horizontal_front_porch_pixels = 4;
const unsigned int horizontal_sync_pulse_pixels = 24;
const unsigned int horizontal_back_porch_pixels = 12;
const unsigned int horizontal_total = horizontal_visible_area_pixels + horizontal_front_porch_pixels + horizontal_sync_pulse_pixels + horizontal_back_porch_pixels;

const unsigned int vertical_visible_area_lines = 480;
const unsigned int vertical_front_porch_lines = 10;
const unsigned int vertical_sync_pulse_lines = 2;
const unsigned int vertical_back_porch_lines = 33;

const unsigned int line_index = 0;

inline __attribute__((always_inline)) void Horizontal_Sync_And_Blank();
inline __attribute__((always_inline)) void Constant_Horizontal_Line();

void setup()
{
  // Set digital pins 2-7 as outputs
  DDRD &= 0b11111100;

  // Set digital pins 8-12 as outputs
  DDRB &= 0b00011111;
}

void loop()
{
  while (true)
  {
    line_index = 0;

    // Vertical visible area
    while (line_index < vertical_visible_area_lines)
    {
      PORTD |= 0b11111100;
      PORTB |= 0b00000111;
      Constant_Horizontal_Line();

      line_index++;
    }

    // Vertical Front porch
    PORTD &= 0b00000011;
    PORTB &= 0b11111000;
    while (line_index < vertical_visible_area_lines + vertical_front_porch_lines)
    {
      Constant_Horizontal_Line();

      line_index++;
    }

    // Vertical Sync Pulse
    PORTB &= 0b11101111;
    while (line_index < vertical_visible_area_lines + vertical_front_porch_lines + vertical_sync_pulse_lines)
    {
      Constant_Horizontal_Line();

      line_index++;
    }
    PORTB |= 0b00010000;

    // Vertical Back Porch
    while (line_index < vertical_visible_area_lines + vertical_front_porch_lines + vertical_sync_pulse_lines + vertical_back_porch_lines)
    {
      Constant_Horizontal_Line();

      line_index++;
    }
  }
}

void Horizontal_Sync_And_Blank()
{
  // Front porch
  PORTD &= 0b00000011;
  PORTB &= 0b11111000;
  __builtin_avr_delay_cycles(horizontal_front_porch_pixels * pixel_clock_time_us / arduino_clock_time_us);

  // Sync pulse
  PORTB &= 0b11110111;
  __builtin_avr_delay_cycles(horizontal_sync_pulse_pixels * pixel_clock_time_us / arduino_clock_time_us);
  PORTB |= 0b00001000;

  // Back porch
  __builtin_avr_delay_cycles(horizontal_back_porch_pixels * pixel_clock_time_us / arduino_clock_time_us);
}

void Constant_Horizontal_Line()
{
  // Visible area and front porch
  __builtin_avr_delay_cycles((horizontal_visible_area_pixels + horizontal_front_porch_pixels) * pixel_clock_time_us / arduino_clock_time_us);

  // Sync pulse
  PORTB &= 0b11110111;
  __builtin_avr_delay_cycles(horizontal_sync_pulse_pixels * pixel_clock_time_us / arduino_clock_time_us);
  PORTB |= 0b00001000;

  // Back porch
  __builtin_avr_delay_cycles(horizontal_back_porch_pixels * pixel_clock_time_us / arduino_clock_time_us);
}
