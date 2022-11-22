// X = r27:r26
// Y = r29:r28
// Z = r31:r30

inline void Visible_Line() __attribute__((always_inline));
inline void Front_Porch_Line() __attribute__((always_inline));
inline void Sync_Pulse_Line() __attribute__((always_inline));
inline void Back_Porch_Line() __attribute__((always_inline));

void setup()
{
}

void loop()
{ 
  // Load test pattern
  asm("ldi XL, lo8(0x80)");
  asm("ldi XH, hi8(0x80)");
  
  asm("ldi ZL, lo8(60)");
  asm("ldi ZH, hi8(60)");
  asm("load_line:");
  asm("ldi r25, 66");
  asm("load_pixel:");

  asm("mov r24, r25");
  asm("eor r24, ZL");
  asm("andi r24, 0b00011100");
  asm("st X+, 0b00011100");
  
  asm("dec r25");
  asm("brne load_pixel");
  
  asm("sbiw Z, 1");
  asm("brne load_line");
  
  // Set pins 2-12 to outputs
  asm("ldi r18, 0b11111100");
  asm("out 0x04, r18"); // Set DDRB

  asm("ldi r18, 0b00011111");
  asm("out 0x0a, r18"); // Set DDRD

  // Disable interrupts
  asm("cli");

  // Test output start state
  asm("ldi r20, 0");
  
  asm("start_of_frame:");

  asm("ldi XL, lo8(0x80)");
  asm("ldi XH, hi8(0x80)");

  // Visible area (244051.6385 cycle budget) 243843       244051.695652
  asm("ldi ZL, lo8(480)"); // 1
  asm("ldi ZH, hi8(480)"); // 1

  asm("visible_area:");
  Visible_Line();           // 504    504.434782609
  asm("sbiw Z, 1");         // 2
  asm("brne visible_area"); // 2/1
  
  // Front porch (5084.4091 cycle budget) 5052      5086.34782609
  asm("ldi r22, 10"); // 1

  asm("front_porch:");
  Front_Porch_Line();      // 505.434782609
  asm("dec r22");          // 1
  asm("brne front_porch"); // 2/1

  // Sync pulse (1016.8818 cycle budget) 1014
  asm("ldi r21, 0b00001000"); // 1
  asm("out 0x05, r21");       // 1
  asm("ldi r22, 2");          // 1

  asm("sync_pulse:");
  Sync_Pulse_Line();      // 505
  asm("dec r22");         // 1
  asm("brne sync_pulse"); // 2/1

  asm("ldi r21, 0b00011000"); // 1
  asm("out 0x05, r21");       // 1

  // Back porch (16778.5501 cycle budget) // 16669
  asm("ldi r22, 33"); // 1

  asm("back_porch:");
  Back_Porch_Line();      // 505
  asm("dec r22");         // 1
  asm("brne back_porch"); // 2/1

  asm("jmp start_of_frame"); // 2
}

void Visible_Line() // 504    .434663542 every 2.3        504.434782609
{
  // Visible area (406.7527 cycle budget, no restrictions) 407
  asm("ldi r25, 66"); // 1
  //asm("ldi r24, 0b00011100");
  //asm("ldi r23, 0b00011100");
  //asm("out 0x0b, r24");

  asm("visible_line_visible_area:");

  asm("ld r24, X+");
  asm("out 0x0b, r24");

  
  //asm("eor r24, r23"); //1
  //asm("out 0x0b, r24"); //1
  asm("dec r25");                        // 1
  asm("brne visible_line_visible_area"); // 2/1

  asm("ldi r25, 0b00000000"); // 1
  asm("ldi r24, 0b00011000"); // 1
  asm("out 0x05, r24");       // 1     PORTB
  asm("out 0x0b, r25");       // 1     PORTD
  asm("ldi r25, 2");          // 1 (set for front porch counter)
  asm("nop \n nop \n nop");          // 2

  // Front porch (10.1688 cycle budget, enter restriction) 10
  asm("visible_line_front_porch:");
  asm("dec r25");                       // 1
  asm("brne visible_line_front_porch"); // 2/1

  asm("ldi r25, 19");         // 1 (set for sync pulse counter)
  asm("ldi r24, 0b00010000"); // 1 (sync pulse set state)
  asm("ldi r23, 0b00011000"); // 1 (sync pulse resolve state)

  // Sync pulse (61.0129 cycle budget, enter restriction) 61
  asm("out 0x05, r24"); // 1

  asm("visible_line_sync_pulse:");
  asm("dec r25");                      // 1
  asm("brne visible_line_sync_pulse"); // 2/1

  asm("nop");           // 1
  asm("out 0x05, r23"); // 1

  // Back porch (30.5065 cycle budget, enter restriction) 26
  /**asm("ldi r25, 8"); // 1

  asm("visible_line_back_porch:");
  asm("dec r25");                      // 1
  asm("brne visible_line_back_porch"); // 2/1
  **/

  asm("cpi r20, 11"); //1
  asm("brcs add_cycle"); // 2/1

  asm("add_cycle:");

  asm("cpi r20, 24"); //1
  asm("brcs reset_20"); // 2/1
  asm("jmp skip_reset"); // 2

  asm("reset_20:");
  asm("ldi r20, 0"); // 1

  asm("skip_reset:");
  asm("inc r20"); // 1
  asm("nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop");
  
}

void Front_Porch_Line() // 505      505.434782609
{
  // Front porch (416.9215 cycle budget) 417
  asm("ldi r25, 137"); // 1

  asm("front_porch_line_front_porch:");
  asm("dec r25");                           // 1
  asm("brne front_porch_line_front_porch"); // 2/1

  asm("ldi r25, 19");         // 1 (set for sync pulse counter)
  asm("ldi r24, 0b00010000"); // 1 (sync pulse set state)
  asm("ldi r23, 0b00011000"); // 1 (sync pulse resolve state)
  asm("nop");                 // 1

  // Sync pulse (61.0129 cycle budget, enter restriction) 61
  asm("out 0x05, r24"); // 1

  asm("front_porch_line_sync_pulse:");
  asm("dec r25");                          // 1
  asm("brne front_porch_line_sync_pulse"); // 2/1

  asm("nop");           // 1
  asm("out 0x05, r23"); // 1

  // Back porch (30.5065 cycle budget, enter restriction) 27
  asm("cpi r20, 11"); //1
  asm("brcs fp_add_cycle"); // 2/1

  asm("fp_add_cycle:");

  asm("cpi r20, 24"); //1
  asm("brcs fp_reset_20"); // 2/1
  asm("jmp fp_skip_reset"); // 2

  asm("fp_reset_20:");
  asm("ldi r20, 0"); // 1

  asm("fp_skip_reset:");
  asm("inc r20"); // 1
  asm("nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop");
}

void Sync_Pulse_Line() // 505     505.434782609
{
  // Front porch (416.9215 cycle budget) 417
  asm("ldi r25, 137"); // 1

  asm("sync_pulse_line_front_porch:");
  asm("dec r25");                          // 1
  asm("brne sync_pulse_line_front_porch"); // 2/1

  asm("ldi r25, 19");         // 1 (set for sync pulse counter)
  asm("ldi r24, 0b00000000"); // 1 (sync pulse set state)
  asm("ldi r23, 0b00001000"); // 1 (sync pulse resolve state)
  asm("nop");                 // 1

  // Sync pulse (61.0129 cycle budget, enter restriction) 61
  asm("out 0x05, r24"); // 1

  asm("sync_pulse_line_sync_pulse:");
  asm("dec r25");                         // 1
  asm("brne sync_pulse_line_sync_pulse"); // 2/1

  asm("nop");           // 1
  asm("out 0x05, r23"); // 1

  // Back porch (30.5065 cycle budget, enter restriction) 27
  asm("cpi r20, 11"); //1
  asm("brcs sp_add_cycle"); // 2/1

  asm("sp_add_cycle:");

  asm("cpi r20, 24"); //1
  asm("brcs sp_reset_20"); // 2/1
  asm("jmp sp_skip_reset"); // 2

  asm("sp_reset_20:");
  asm("ldi r20, 0"); // 1

  asm("sp_skip_reset:");
  asm("inc r20"); // 1
  asm("nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop");
}

void Back_Porch_Line() // 505      505.434782609
{
  // Front porch (416.9215 cycle budget) 417
  asm("ldi r25, 137"); // 1

  asm("back_porch_line_front_porch:");
  asm("dec r25");                          // 1
  asm("brne back_porch_line_front_porch"); // 2/1

  asm("ldi r25, 19");         // 1 (set for sync pulse counter)
  asm("ldi r24, 0b00010000"); // 1 (sync pulse set state)
  asm("ldi r23, 0b00011000"); // 1 (sync pulse resolve state)
  asm("nop");                 // 1

  // Sync pulse (61.0129 cycle budget, enter restriction) 61
  asm("out 0x05, r24"); // 1

  asm("back_porch_line_sync_pulse:");
  asm("dec r25");                         // 1
  asm("brne back_porch_line_sync_pulse"); // 2/1

  asm("nop");           // 1
  asm("out 0x05, r23"); // 1

  // Back porch (30.5065 cycle budget, enter restriction) 27/28
  asm("cpi r20, 11"); //1
  asm("brcs bp_add_cycle"); // 2/1

  asm("bp_add_cycle:");

  asm("cpi r20, 23"); //1
  asm("brcs bp_reset_20"); // 2/1
  asm("jmp bp_skip_reset"); // 2

  asm("bp_reset_20:");
  asm("ldi r20, 0"); // 1

  asm("bp_skip_reset:");
  asm("inc r20"); // 1
  asm("nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop"); // 20
}
