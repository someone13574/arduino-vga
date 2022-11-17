const float arduino_clock_time_us = 0.0625;

const float horizontal_visible_area_time_us = 25.422045680238; // 25.6us
const float horizontal_front_porch_time_us = 0.63555114200596; //630ns
const float horizontal_sync_pulse_time_us = 3.8133068520357; //37.8 us
const float horizontal_back_porch_time_us = 1.9066534260179; //1.92us

const unsigned int vertical_visible_area_lines = 480;
const unsigned int vertical_front_porch_lines = 10;
const unsigned int vertical_sync_pulse_lines = 2;
const unsigned int vertical_back_porch_lines = 33;

inline __attribute__((always_inline)) void Visible_Horizontal_Line();
inline __attribute__((always_inline)) void Vertical_Blanking_Line();
inline __attribute__((always_inline)) void Vertical_Blanking_Line2();
inline __attribute__((always_inline)) void Vertical_Sync_Pulse();

void setup() {
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  asm("sof:"); // Start of frame

  asm("ldi r18, 0x18");
  asm("out 0x04, r18");

  // Visible area (243840 wanted 244052) (diff 212)
  asm("ldi ZL, lo8(480)"); // Load low bits of counter (1)
  asm("ldi ZH, hi8(480)"); // Load high bits of counter (1)

  asm("vva:");
  Visible_Horizontal_Line(); // 504
  asm("sbiw Z, 0x1"); // 2
  asm("brne vva"); // 2/1

  // Visible area burn
  asm("ldi r18, 42"); // 1

  asm("va_burn:");
  asm("nop\nnop"); // 2
  asm("dec r18"); //1
  asm("brne va_burn"); //2/1

  // Front porch (5084 wanted 5084)
  asm("ldi r19, 10"); // 1

  asm("vfp:");
  Vertical_Blanking_Line(); // 506
  asm("dec r19"); // 1
  asm("brne vfp"); // 2/1
  asm("nop\nnop"); // 2

  // Sync pulse 1017
  Vertical_Sync_Pulse(); // 506
  asm("jmp vsp"); // 2 + 506 = 508
  asm("nop\nnop\nnop"); // 3

  // Back porch (16779 wanted 16778) diff +1
  asm("ldi r19, 33"); // 1

  asm("vbp:");
  Vertical_Blanking_Line2(); // 506
  asm("dec r19"); // 1
  asm("brne vbp"); // 2/1

  asm("jmp sof"); // 2
}

void Visible_Horizontal_Line()
{
  // Visible area (407)
  asm("ldi r20, 0x87"); // (1)
  
  asm("hva:");
  asm("ldi r18, 0xfc"); // 1
  asm("out 0x0a, r18"); // 1
  asm("dec r20"); //(1)
  asm("brne hva"); //(2, 1)

  // Front porch (10)
  asm("ldi r18, 0x00"); //(1)
  asm("out 0x0a, r18"); // (1)
  asm("ldi r18, 0x18"); //(1)
  asm("out 0x04, r18"); // (1)
  asm("nop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\n"); // (6)

  // Sync pulse (61)
  asm("ldi r18, 0x10"); // 1
  asm("out 0x04, r18"); // 1
  asm("ldi r18, 0x13"); // 1

  asm("hsp:");
  asm("dec r18"); // 1
  asm("brne hsp"); // 2/1

  // Back porch (26)
  asm("ldi r18, 0x18"); // 1
  asm("out 0x04, r18"); // 1
  asm("ldi r18, 0x07"); // 1

  asm("hbp:");
  asm("dec r18"); // 1
  asm("brne hbp"); // 2/1
  asm("nop"); // 1
}

void Vertical_Blanking_Line()
{
  // Front porch and visible area (417)
  asm("ldi r18, 0x00"); // 1
  asm("out 0x0a, r18"); // 1
  asm("ldi r18, 0x18"); // 1
  asm("out 0x04, r18"); // 1
  asm("ldi r18, 102"); // 1

  asm("vbl_fp:");
  asm("nop"); // 1
  asm("dec r18"); // 1
  asm("brne vbl_fp"); // 2/1
  asm("nop\nnop\nnop"); //3

  // Sync pulse (61)
  asm("ldi r18, 0x10"); // 1  
  asm("out 0x04, r18"); // 1
  asm("ldi r18, 0x13"); // 1

  asm("vbl_hsp:");
  asm("dec r18"); // 1
  asm("brne vbl_hsp"); // 2/1

  // Back porch (28)
  asm("ldi r18, 0x18"); // 1
  asm("out 0x04, r18"); // 1
  asm("ldi r18, 0x07"); // 1

  asm("vbl_hbp:");
  asm("dec r18"); // 1
  asm("brne vbl_hbp"); // 2/1
  asm("nop\nnop\nnop"); // 3
}

void Vertical_Blanking_Line2()
{
  // Front porch and visible area (417)
  asm("ldi r18, 0x00"); // 1
  asm("out 0x0a, r18"); // 1
  asm("ldi r18, 0x18"); // 1
  asm("out 0x04, r18"); // 1
  asm("ldi r18, 102"); // 1

  asm("vbl2_fp:");
  asm("nop"); // 1
  asm("dec r18"); // 1
  asm("brne vbl2_fp"); // 2/1
  asm("nop\nnop\nnop"); //3

  // Sync pulse (61)
  asm("ldi r18, 0x10"); // 1  
  asm("out 0x04, r18"); // 1
  asm("ldi r18, 0x13"); // 1

  asm("vbl2_hsp:");
  asm("dec r18"); // 1
  asm("brne vbl2_hsp"); // 2/1

  // Back porch (28)
  asm("ldi r18, 0x18"); // 1
  asm("out 0x04, r18"); // 1
  asm("ldi r18, 0x07"); // 1

  asm("vbl2_hbp:");
  asm("dec r18"); // 1
  asm("brne vbl2_hbp"); // 2/1
  asm("nop\nnop\nnop"); // 3
}

void Vertical_Sync_Pulse()
{
  asm("vsp:");
  
  // Front porch and visible area (417)
  asm("ldi r18, 0x00"); // 1
  asm("out 0x0a, r18"); // 1
  asm("ldi r18, 0x08"); // 1
  asm("out 0x04, r18"); // 1
  asm("ldi r18, 102"); // 1

  asm("vsp_fp:");
  asm("nop"); // 1
  asm("dec r18"); // 1
  asm("brne vsp_fp"); // 2/1
  asm("nop\nnop\nnop"); //3

  // Sync pulse (61)
  asm("ldi r18, 0x00"); // 1  
  asm("out 0x04, r18"); // 1
  asm("ldi r18, 0x13"); // 1

  asm("vsp_hsp:");
  asm("dec r18"); // 1
  asm("brne vsp_hsp"); // 2/1

  // Back porch (28)
  asm("ldi r18, 0x08"); // 1
  asm("out 0x04, r18"); // 1
  asm("ldi r18, 0x07"); // 1

  asm("vsp_hbp:");
  asm("dec r18"); // 1
  asm("brne vsp_hbp"); // 2/1
  asm("nop\nnop\nnop"); // 3
}
