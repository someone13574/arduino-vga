// X = r27:r26
// Y = r29:r28
// Z = r31:r30

// Memory layout
// Current line         0x100  to 0x10f  (6 tiles)
// Tile descriptors     0x110  to 0x38f (640 descriptors, 8 per line)
// Tile data            0x390 to 0x8f0 (86 tiles)

// Tile address
// 16-bit address

// Tile descriptor layout
// 8-bit tile index (1 byte)

// Tile layout
// 16x 8-bit color data (16 bytes)

void setup()
{
       
}

void loop()
{
  
  asm volatile (
    "cli \n"
    
    // Set pins to output
    "ldi r25, 0b00011000      \n"
    "out 0x04, r25            \n"
    "ldi r25, 0b11111111      \n"
    "out 0x0a, r25            \n"

    // Load tile descriptors
    "ldi XL, lo8(0x110)              \n"
    "ldi XH, hi8(0x110)              \n"
    "ldi YL, lo8(640)                \n"
    "ldi YH, hi8(640)                \n"
    "ldi r24, 0x00                   \n" // Set all tile descriptors to the first index
    "load_tile_descriptors:          \n"
      "st X+, r24                    \n"
      "sbiw Y, 1                     \n"
      "brne load_tile_descriptors    \n"

    // Load test line
    "ldi r25, lo8(0x390)\n"
    "ldi r24, hi8(0x390)\n"
    "sts 0x110, r25\n"
    "sts 0x111, r24\n"
    "sts 0x112, r25\n"
    "sts 0x113, r24\n"
    "sts 0x114, r25\n"
    "sts 0x115, r24\n"
    "sts 0x116, r25\n"
    "sts 0x117, r24\n"
    "sts 0x118, r25\n"
    "sts 0x119, r24\n"
    "sts 0x11a, r25\n"
    "sts 0x11b, r24\n"
    "sts 0x11c, r25\n"
    "sts 0x11d, r24\n"
    "sts 0x11e, r25\n"
    "sts 0x11f, r24\n"

    // Load test tile
    "ldi XL, lo8(0x390)       \n"
    "ldi XH, hi8(0x390)       \n"
    "ldi r25, 0b00000000      \n"
    "ldi r24, 0b00000001      \n"
    "ldi r23, 0b00000010      \n"
    "ldi r22, 0b00000011      \n"
    "st X+, r25               \n"
    "st X+, r24               \n"
    "st X+, r23               \n"
    "st X+, r22               \n"
    "ldi r25, 0b00000100      \n"
    "ldi r24, 0b00000101      \n"
    "ldi r23, 0b00000110      \n"
    "ldi r22, 0b00000111      \n"
    "st X+, r25               \n"
    "st X+, r24               \n"
    "st X+, r23               \n"
    "st X+, r22               \n"
    "ldi r25, 0b00000111      \n"
    "ldi r24, 0b00000110      \n"
    "ldi r23, 0b00000101      \n"
    "ldi r22, 0b00000100      \n"
    "st X+, r25               \n"
    "st X+, r24               \n"
    "st X+, r23               \n"
    "st X+, r22               \n"
    "ldi r25, 0b00000011      \n"
    "ldi r24, 0b00000010      \n"
    "ldi r23, 0b00000001      \n"
    "ldi r22, 0b00000000      \n"
    "st X+, r25               \n"
    "st X+, r24               \n"
    "st X+, r23               \n"
    "st X+, r22               \n"

    // Start loop
    "start_of_frame:                  \n"

      // Set tile descriptor start address
      "ldi ZL, lo8(0x110)             \n"
      "ldi ZH, hi8(0x110)             \n"
    
      // Visible area loop (vertical resolution of 80, 6 pixels per pixel)
      "ldi r16, 80                    \n"
      "visible_area_loop:             \n"
        "rjmp load_line               \n" // 2+501+2+3=508
        "load_line_ret:               \n"
        "rcall visible_line           \n" // 3+4+501=508
        "rcall visible_line           \n" // 3+4+501=508
        "rcall visible_line           \n" // 3+4+501=508
        "rcall visible_line           \n" // 3+4+501=508
        "rcall visible_line           \n" // 3+4+501=508
      
        "dec r16                      \n"
        "brne visible_area_loop       \n"
 
      // Front porch
      
      "ldi r16, 10                    \n"
      "front_porch_loop:              \n"
        "rjmp front_porch_line        \n" // 2+2+?+501=508
        "front_porch_line_ret:        \n"
        "dec r16                      \n"
        "brne front_porch_loop        \n"

        //"wdr \n"
     //"rjmp start_of_frame            \n"

     // Sync pulse
     "ldi r25, 0b00001000             \n"
     "out 0x05, r25                   \n"
     "ldi r16, 2                      \n"
     "sync_pulse_loop:                \n"
        "rjmp sync_pulse_line         \n"
        "sync_pulse_line_ret:         \n"
        "dec r16                      \n"
        "brne sync_pulse_loop         \n"
     "ldi r25, 0b00011000             \n"
     "out 0x05, r25                   \n"

     // Back porch
     "ldi r16, 33\n"
     "back_porch_loop:               \n"
       "rjmp back_porch_line         \n"
       "back_porch_line_ret:         \n"
       "dec r16                      \n"
       "brne back_porch_loop         \n"

     // Return to start
     //"sync_pulse_line_ret: \n front_porch_line_ret:\nback_porch_line_ret:\n"
     "wdr \n"
     "rjmp start_of_frame            \n"
        
    // Load line subroutine
    "load_line:                      \n"
      // Z = Tile descriptor address
      // Y = Tile data address
      // r24 = Tile data offset low
      // r23 = Tile data offset high

      // Set tile data offset
      "ldi r24, lo8(0x390)            \n" // 1
      "ldi r23, hi8(0x390)            \n" // 1

      // First tile
        // Get tile address
        "ld YL, Z+                    \n" // 2    Copy tile index
        "ldi YH, 0x00                 \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2
        "rol YH                       \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2 (now 4x)
        "rol YH                       \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2 (now 8x)
        "rol YH                       \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2 (now 16x)
        "rol YH                       \n" // 1

        "add YL, r24                  \n" // 1    Offset address by 0x390
        "adc YH, r23                  \n" // 1

        // Write tile address
        "sts 0x110, YL                 \n" // 2
        "sts 0x111, YH                 \n" // 2

      // 2 tile
        // Get tile address
        "ld YL, Z+                    \n" // 3    Copy tile index
        "ldi YH, 0x00                 \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2
        "rol YH                       \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2 (now 4x)
        "rol YH                       \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2 (now 8x)
        "rol YH                       \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2 (now 16x)
        "rol YH                       \n" // 1

        "add YL, r24                  \n" // 1    Offset address by 0x390
        "adc YH, r23                  \n" // 1

        // Write tile address
        "sts 0x112, YL                 \n" // 2
        "sts 0x113, YH                 \n" // 2

      // 3 tile
        // Get tile address
        "ld YL, Z+                    \n" // 3    Copy tile index
        "ldi YH, 0x00                 \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2
        "rol YH                       \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2 (now 4x)
        "rol YH                       \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2 (now 8x)
        "rol YH                       \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2 (now 16x)
        "rol YH                       \n" // 1

        "add YL, r24                  \n" // 1    Offset address by 0x390
        "adc YH, r23                  \n" // 1

        // Write tile address
        "sts 0x114, YL                 \n" // 2
        "sts 0x115, YH                 \n" // 2

      // 4 tile
        // Get tile address
        "ld YL, Z+                    \n" // 3    Copy tile index
        "ldi YH, 0x00                 \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2
        "rol YH                       \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2 (now 4x)
        "rol YH                       \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2 (now 8x)
        "rol YH                       \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2 (now 16x)
        "rol YH                       \n" // 1

        "add YL, r24                  \n" // 1    Offset address by 0x390
        "adc YH, r23                  \n" // 1

        // Write tile address
        "sts 0x116, YL                 \n" // 2
        "sts 0x117, YH                 \n" // 2

      // 5 tile
        // Get tile address
        "ld YL, Z+                    \n" // 3    Copy tile index
        "ldi YH, 0x00                 \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2
        "rol YH                       \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2 (now 4x)
        "rol YH                       \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2 (now 8x)
        "rol YH                       \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2 (now 16x)
        "rol YH                       \n" // 1

        "add YL, r24                  \n" // 1    Offset address by 0x390
        "adc YH, r23                  \n" // 1

        // Write tile address
        "sts 0x118, YL                 \n" // 2
        "sts 0x119, YH                 \n" // 2

      // 6 tile
        // Get tile address
        "ld YL, Z+                    \n" // 3    Copy tile index
        "ldi YH, 0x00                 \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2
        "rol YH                       \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2 (now 4x)
        "rol YH                       \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2 (now 8x)
        "rol YH                       \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2 (now 16x)
        "rol YH                       \n" // 1

        "add YL, r24                  \n" // 1    Offset address by 0x390
        "adc YH, r23                  \n" // 1

        // Write tile address
        "sts 0x11a, YL                 \n" // 2
        "sts 0x11b, YH                 \n" // 2

      // 7 tile
        // Get tile address
        "ld YL, Z+                    \n" // 3    Copy tile index
        "ldi YH, 0x00                 \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2
        "rol YH                       \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2 (now 4x)
        "rol YH                       \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2 (now 8x)
        "rol YH                       \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2 (now 16x)
        "rol YH                       \n" // 1

        "add YL, r24                  \n" // 1    Offset address by 0x390
        "adc YH, r23                  \n" // 1

        // Write tile address
        "sts 0x11c, YL                 \n" // 2
        "sts 0x11d, YH                 \n" // 2

      // 8 tile
        // Get tile address
        "ld YL, Z+                    \n" // 3    Copy tile index
        "ldi YH, 0x00                 \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2
        "rol YH                       \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2 (now 4x)
        "rol YH                       \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2 (now 8x)
        "rol YH                       \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2 (now 16x)
        "rol YH                       \n" // 1

        "add YL, r24                  \n" // 1    Offset address by 0x390
        "adc YH, r23                  \n" // 1

        // Write tile address
        "sts 0x11e, YL                 \n" // 2
        "sts 0x11f, YH                 \n" // 2

        // Front porch (burn 279)
        "ldi r25, 69                       \n" // 1
        "load_line_front_porch:             \n" // 4 / 1
          "dec r25                          \n" // 1
          "nop \n"  // 1
          "brne load_line_front_porch       \n" // 2 / 1
        "ldi r25, 0b00010000                \n" // 1

        // Sync pulse (61)
        "out 0x05, r25                      \n" // 1
        "ldi r25, 19                        \n" // 1
        "load_line_sync_pulse:              \n" // 3 / 1
           "dec r25                         \n" // 1
           "brne load_line_sync_pulse       \n" // 2 / 1
        "ldi r25, 0b00011000                \n" // 1

        // Back porch (30.5064548163 cycles) (-2 -2 -3 = -7) (23)
        "out 0x05, r25                      \n" // 1
        "ldi r25, 6                         \n" // 1
        "load_line_back_porch:              \n" // 3 / 1
          "dec r25                          \n" // 1
          "brne load_line_back_porch        \n" // 2 / 1

        "nop \n nop \n"                         // 2

        "rjmp load_line_ret                 \n" // 2

    // Visible line subroutine 501
    "visible_line:                    \n"
      // X = pixel read address
      // r25 = Pixel color
      
      // Visible area 407
        // Tile 1 (52)
        "lds XL, 0x110                 \n" // 2    Load tile address
        "lds XH, 0x111                 \n" // 2

        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1

        // Tile 2 (52)
        "lds XL, 0x112                 \n" // 2    Load tile address
        "lds XH, 0x113                 \n" // 2

        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1

        // Tile 3 (52)
        "lds XL, 0x114                 \n" // 2    Load tile address
        "lds XH, 0x115                 \n" // 2

        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1

        // Tile 4 (52)
        "lds XL, 0x116                 \n" // 2    Load tile address
        "lds XH, 0x117                 \n" // 2

        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1

        // Tile 5 (52)
        "lds XL, 0x118                 \n" // 2    Load tile address
        "lds XH, 0x119                 \n" // 2

        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1

        // Tile 6 (52)
        "lds XL, 0x11a                 \n" // 2    Load tile address
        "lds XH, 0x11b                 \n" // 2

        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1

        // Tile 7 (52)
        "lds XL, 0x11c                 \n" // 2    Load tile address
        "lds XH, 0x11d                 \n" // 2

        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1

        // Tile 8 (43)
        "lds XL, 0x11e                 \n" // 2    Load tile address
        "lds XH, 0x11f                 \n" // 2

        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 2
        "out 0x0b, r25                \n" // 1
        
        "nop \n nop \n"
        "ldi r25, 0b00000000          \n" // 1
        
        // Front porch (10)
        "out 0x0b, r25                \n" // 1    Clear RGB
        "nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n" // 8
        "ldi r25, 0b00010000          \n" // 1

        // Sync pulse (61)
        "out 0x05, r25                      \n" // 1
        "ldi r25, 19                        \n" // 1
        "visible_line_sync_pulse:           \n" // 3 / 1
           "dec r25                         \n" // 1
           "brne visible_line_sync_pulse    \n" // 2 / 1
        "ldi r25, 0b00011000                \n" // 1

        // Back porch (30.5064548163 cycles) (23)
        "out 0x05, r25                      \n" // 1
        "ldi r25, 6                         \n" // 1
        "visible_line_back_porch:           \n" // 3 / 1
          "dec r25                          \n" // 1
          "brne visible_line_back_porch     \n" // 2 / 1
        "nop \n nop \n" // 2

        "ret                                \n" // 4

    // Front porch line
    "front_porch_line:                      \n"
      // Front porch and visible area (417)
      "ldi r25, 138                         \n" // 1
      "front_porch_line_front_porch:        \n" // 3 / 1
        "dec r25                            \n" // 1
        "brne front_porch_line_front_porch  \n" // 2 / 1
      "ldi r25, 0b00010000                  \n" // 1

      // Sync pulse (61)
      "out 0x05, r25                          \n" // 1
      "ldi r25, 19                            \n" // 1
      "front_porch_line_sync_pulse:           \n" // 3 / 1
         "dec r25                             \n" // 1
         "brne front_porch_line_sync_pulse    \n" // 2 / 1
      "ldi r25, 0b00011000                    \n" // 1

      // Back porch (30.5064548163 cycles) (23)
      "out 0x05, r25                          \n" // 1
      "ldi r25, 6                             \n" // 1
      "front_porch_line_back_porch:           \n" // 3 / 1
        "dec r25                              \n" // 1
        "brne front_porch_line_back_porch     \n" // 2 / 1
      "nop \n nop \n                            " // 2

      "rjmp front_porch_line_ret              \n" // 2

    // Sync pulse line
    "sync_pulse_line:                       \n"
      // Front porch and visible area (417)
      "ldi r25, 138                         \n" // 1
      "sync_pulse_line_front_porch:         \n" // 3 / 1
        "dec r25                            \n" // 1
        "brne sync_pulse_line_front_porch   \n" // 2 / 1
      "ldi r25, 0b00000000                  \n" // 1

      // Sync pulse (61)
      "out 0x05, r25                          \n" // 1
      "ldi r25, 19                            \n" // 1
      "sync_pulse_line_sync_pulse:            \n" // 3 / 1
         "dec r25                             \n" // 1
         "brne sync_pulse_line_sync_pulse     \n" // 2 / 1
      "ldi r25, 0b00001000                    \n" // 1

      // Back porch (30.5064548163 cycles) (23)
      "out 0x05, r25                          \n" // 1
      "ldi r25, 6                             \n" // 1
      "sync_pulse_line_back_porch:            \n" // 4 / 1
        "dec r25                              \n" // 1
        "brne sync_pulse_line_back_porch      \n" // 2 / 1
      "nop \n nop \n                            " // 2

      "rjmp sync_pulse_line_ret               \n" // 2

    // Back porch line
    "back_porch_line:                       \n"
      // Front porch and visible area (417)
      "ldi r25, 138                         \n" // 1
      "back_porch_line_front_porch:         \n" // 3 / 1
        "dec r25                            \n" // 1
        "brne back_porch_line_front_porch   \n" // 2 / 1
      "ldi r25, 0b00010000                  \n" // 1

      // Sync pulse (61)
      "out 0x05, r25                          \n" // 1
      "ldi r25, 19                            \n" // 1
      "back_porch_line_sync_pulse:            \n" // 3 / 1
         "dec r25                             \n" // 1
         "brne back_porch_line_sync_pulse     \n" // 2 / 1
      "ldi r25, 0b00011000                    \n" // 1

      // Back porch (30.5064548163 cycles) (23)
      "out 0x05, r25                          \n" // 1
      "ldi r25, 6                             \n" // 1
      "back_porch_line_back_porch:            \n" // 4 / 1
        "dec r25                              \n" // 1
        "brne back_porch_line_back_porch      \n" // 2 / 1
      "nop \n nop \n                            " // 2

      "rjmp back_porch_line_ret               \n" // 2
      
  );
}
