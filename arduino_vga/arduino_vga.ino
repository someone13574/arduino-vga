// X = r27:r26
// Y = r29:r28
// Z = r31:r30

// Memory layout
// Current line         0x100  to 0x10d  (6 tiles)
// Tile descriptors     0x10e  to 0x2ed (480 descriptors, 6 per line)
// Tile data            0x2ee to 0x8ee (96 tiles)

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
    "ldi r25, 0b11111100      \n"
    "out 0x0a, r25            \n"

    // Load tile descriptors
    "ldi XL, lo8(0x10e)              \n"
    "ldi XH, hi8(0x10e)              \n"
    "ldi YL, lo8(480)                \n"
    "ldi YH, hi8(480)                \n"
    "ldi r24, 0x00                   \n" // Set all tile descriptors to the first index
    "load_tile_descriptors:          \n"
      "st X+, r24                    \n"
      "sbiw Y, 1                     \n"
      "brne load_tile_descriptors    \n"

    // Load test line
    "ldi r25, lo8(0x2ee)\n"
    "ldi r24, hi8(0x2ee)\n"
    "sts 0x100, r25\n"
    "sts 0x101, r24\n"
    "sts 0x102, r25\n"
    "sts 0x103, r24\n"
    "sts 0x104, r25\n"
    "sts 0x105, r24\n"
    "sts 0x106, r25\n"
    "sts 0x107, r24\n"
    "sts 0x108, r25\n"
    "sts 0x109, r24\n"
    "sts 0x10a, r25\n"
    "sts 0x10b, r24\n"

    // Load test tile
    "ldi XL, lo8(0x2ee)       \n"
    "ldi XH, hi8(0x2ee)       \n"
    "ldi r25, 0b00000000      \n"
    "st X+, r25               \n"
    "st X+, r25               \n"
    "ldi r25, 0b00000100      \n"
    "st X+, r25               \n"
    "st X+, r25               \n"
    "ldi r25, 0b00001000      \n"
    "st X+, r25               \n"
    "st X+, r25               \n"
    "ldi r25, 0b00001100      \n"
    "st X+, r25               \n"
    "st X+, r25               \n"
    "ldi r25, 0b00010000      \n"
    "st X+, r25               \n"
    "st X+, r25               \n"
    "ldi r25, 0b00010100      \n"
    "st X+, r25               \n"
    "st X+, r25               \n"
    "ldi r25, 0b00011000      \n"
    "st X+, r25               \n"
    "st X+, r25               \n"
    "ldi r25, 0b00011100      \n"
    "st X+, r25               \n"
    "st X+, r25               \n"

    // Start loop
    "start_of_frame:                  \n"

      // Set tile descriptor start address
      "ldi ZL, lo8(0x10e)             \n"
      "ldi ZH, hi8(0x10e)             \n"
    
      // Visible area loop (vertical resolution of 80, 6 pixels per pixel)
      "ldi r16, 100                    \n"
      "visible_area_loop:             \n"
        //"rjmp load_line               \n"
        "load_line_ret:               \n"
        "rcall visible_line           \n"
        "rcall visible_line           \n"
        "rcall visible_line           \n"
        "rcall visible_line           \n"
        "rcall visible_line           \n"
      
        "dec r16                      \n"
        "brne visible_area_loop       \n"
 
      // Front porch
      
      "ldi r16, 1                    \n"
      "front_porch_loop:              \n"
        "rjmp front_porch_line        \n"
        "front_porch_line_ret:        \n"
        "dec r16                      \n"
        "brne front_porch_loop        \n"

        //"wdr \n"
     //"rjmp start_of_frame            \n"

     // Sync pulse
     "ldi r25, 0b00001000             \n"
     "out 0x05, r25                   \n"
     "ldi r16, 1                      \n"
     "sync_pulse_loop:                \n"
        "rjmp sync_pulse_line         \n"
        "sync_pulse_line_ret:         \n"
        "dec r16                      \n"
        "brne sync_pulse_loop         \n"
     "ldi r25, 0b00011000             \n"
     "out 0x05, r25                   \n"

     // Back porch
     "ldi r16, 1                    \n"
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
      "ldi r24, lo8(0x2ee)            \n"
      "ldi r23, hi8(0x2ee)            \n"

      // First tile
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

        "add YL, r24                  \n" // 1    Offset address by 0x2ee
        "adc YH, r23                  \n" // 1

        // Write tile address
        "sts 0x100, YL                 \n" // 2
        "sts 0x101, YH                 \n" // 2

      // Second tile
        // Get tile address
        "ld YL, Z+                    \n" // 3
        "ldi YH, 0x00                 \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2
        "rol YH                       \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2 (now 4x)
        "rol YH                       \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2 (now 8x)
        "rol YH                       \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2 (now 16x)
        "rol YH                       \n" // 1

        "add YL, r24                  \n" // 1    Offset address by 0x2ee
        "adc YH, r23                  \n" // 1

        // Write tile address
        "sts 0x102, YL                 \n" // 2
        "sts 0x103, YH                 \n" // 2

      // Third tile
        // Get tile address
        "ld YL, Z+                    \n" // 3
        "ldi YH, 0x00                 \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2
        "rol YH                       \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2 (now 4x)
        "rol YH                       \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2 (now 8x)
        "rol YH                       \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2 (now 16x)
        "rol YH                       \n" // 1

        "add YL, r24                  \n" // 1    Offset address by 0x2ee
        "adc YH, r23                  \n" // 1

        // Write tile address
        "sts 0x104, YL                 \n" // 2
        "sts 0x105, YH                 \n" // 2

      // Forth tile
        // Get tile address
        "ld YL, Z+                    \n" // 3
        "ldi YH, 0x00                 \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2
        "rol YH                       \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2 (now 4x)
        "rol YH                       \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2 (now 8x)
        "rol YH                       \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2 (now 16x)
        "rol YH                       \n" // 1

        "add YL, r24                  \n" // 1    Offset address by 0x2ee
        "adc YH, r23                  \n" // 1

        // Write tile address
        "sts 0x106, YL                 \n" // 2
        "sts 0x107, YH                 \n" // 2

      // Fifth tile
        // Get tile address
        "ld YL, Z+                    \n" // 3
        "ldi YH, 0x00                 \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2
        "rol YH                       \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2 (now 4x)
        "rol YH                       \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2 (now 8x)
        "rol YH                       \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2 (now 16x)
        "rol YH                       \n" // 1

        "add YL, r24                  \n" // 1    Offset address by 0x2ee
        "adc YH, r23                  \n" // 1

        // Write tile address
        "sts 0x108, YL                 \n" // 2
        "sts 0x109, YH                 \n" // 2

      // Sixth tile
        // Get tile address
        "ld YL, Z+                    \n" // 3
        "ldi YH, 0x00                 \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2
        "rol YH                       \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2 (now 4x)
        "rol YH                       \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2 (now 8x)
        "rol YH                       \n" // 1
        "lsl YL                       \n" // 1    Multiply by 2 (now 16x)
        "rol YH                       \n" // 1

        "add YL, r24                  \n" // 1    Offset address by 0x2ee
        "adc YH, r23                  \n" // 1

        // Write tile address
        "sts 0x10a, YL                 \n" // 2
        "sts 0x10b, YH                 \n" // 2

        // Front porch (burn 309)
        "ldi r25, 102                       \n" // 1
        "load_line_front_porch:             \n" // 3 / 1
          "dec r25                          \n" // 1
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
        "ldi r25, 7                         \n" // 1
        "load_line_back_porch:              \n" // 3 / 1
          "dec r25                          \n" // 1
          "brne load_line_back_porch        \n" // 2 / 1

        "nop \n nop \n"                         // 2

        "rjmp load_line_ret                 \n" // 2

    // Visible line subroutine
    "visible_line:                    \n"
      // X = pixel read address
      // r25 = Pixel color
      
      // Visible area
        // Tile 1 (68)
        //"lds XL, 0x100                 \n" // 2    Load tile address
        //"lds XH, 0x101                 \n" // 2
        "ldi XL, lo8(0x2ee)\n"
        "ldi XH, hi8(0x2ee)\n"
        "nop \n nop \n"

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

        "nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n"

        // Tile 2 (68)
        //"lds XL, 0x102                 \n" // 2    Load tile address
        //"lds XH, 0x103                 \n" // 2
        "ldi XL, lo8(0x2ee)\n"
        "ldi XH, hi8(0x2ee)\n"
        "nop \n nop \n"

        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1

        "nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n"

        // Tile 3 (68)
        //"lds XL, 0x104                 \n" // 2    Load tile address
        //"lds XH, 0x105                 \n" // 2
        "ldi XL, lo8(0x2ee)\n"
        "ldi XH, hi8(0x2ee)\n"
        "nop \n nop \n"

        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1

        "nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n"

        // Tile 4 (68)
        //"lds XL, 0x106                 \n" // 2    Load tile address
        //"lds XH, 0x107                 \n" // 2
        "ldi XL, lo8(0x2ee)\n"
        "ldi XH, hi8(0x2ee)\n"
        "nop \n nop \n"

        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1

        "nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n"

        // Tile 5 (68)
        //"lds XL, 0x108                 \n" // 2    Load tile address
        //"lds XH, 0x109                 \n" // 2
        "ldi XL, lo8(0x2ee)\n"
        "ldi XH, hi8(0x2ee)\n"
        "nop \n nop \n"

        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1

        "nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n"

        // Tile 6 (60)
        //"lds XL, 0x10a                 \n" // 2    Load tile address
        //"lds XH, 0x10b                 \n" // 2
        "ldi XL, lo8(0x2ee)\n"
        "ldi XH, hi8(0x2ee)\n"
        "nop \n nop \n"

        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1
        "ld r25, X+                   \n" // 3
        "out 0x0b, r25                \n" // 1

        "nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop \n"

        "nop                          \n" // 1
        "nop                          \n" // 1
        "nop                          \n" // 1
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

        // Back porch (30.5064548163 cycles) (-4 -3 = -7)
        "out 0x05, r25                      \n" // 1
        "ldi r25, 7                         \n" // 1
        "visible_line_back_porch:           \n" // 3 / 1
          "dec r25                          \n" // 1
          "brne visible_line_back_porch     \n" // 2 / 1

          "nop \n nop \n"

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

      // Back porch (30.5064548163 cycles) (-2 -2 -3 = -7)
      "out 0x05, r25                          \n" // 1
      "ldi r25, 7                             \n" // 1
      "front_porch_line_back_porch:           \n" // 4 / 1
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

      // Back porch (30.5064548163 cycles) (-2 -2 -3 = -7)
      "out 0x05, r25                          \n" // 1
      "ldi r25, 7                             \n" // 1
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

      // Back porch (30.5064548163 cycles) (-2 -2 -3 = -7)
      "out 0x05, r25                          \n" // 1
      "ldi r25, 7                             \n" // 1
      "back_porch_line_back_porch:            \n" // 4 / 1
        "dec r25                              \n" // 1
        "brne back_porch_line_back_porch      \n" // 2 / 1
      "nop \n nop \n                            " // 2

      "rjmp back_porch_line_ret               \n" // 2
      
  );
}
