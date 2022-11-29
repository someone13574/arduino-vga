// X = r27:r26
// Y = r29:r28
// Z = r31:r30

// Memory layout
// Current line         0x100  to 0x10f  (6 tiles)
// Tile descriptors     0x110  to 0x38f (640 descriptors, 8 per line)
// Tile data            0x390 to 0x8f0 (86 tiles)

// Pallet
// r24 = A = White
// r23 = B = Black
// r22 = C = Grey

// Tile map
// 0 = BBBB BBBB BBBB BBBB
// 1 = BBBB AAAA BBBB BBBB
// 2 = BBBA BBBB ABBB BBBB
// 3 = BBAB BBBB BABB BBBB
// 4 = BBBB AAAB BBBB BBBB
// 5 = BBBA AAAB BBBB BBBB
// 6 = BBBB BAAB BBBB BBBB
// 7 = BBAA AAAA AABB BBBB
// 8 = BBBA AAAA ABBB BBBB
// 9 = BBBB BBBB BABB BBBB
// 10 = BBBB BBBA ABBB BBBB
// 11 = BBBA ABBB BBBB BBBB
// 12 = BBBB BBAA ABBB BBBB
// 13 = BBBB BABB ABBB BBBB
// 14 = BBBB ABBB ABBB BBBB
// 15 = BBBB BBBB ABBB BBBB
// 16 = BBAB BBBB BBBB BBBB
// 17 = BBAA AAAA ABBB BBBB
// 18 = BBBB BBBA BBBB BBBB
// 19 = BBBB BBAB BBBB BBBB
// 20 = BBBA AAAA AABB BBBB
// 21 = BBBB GBBB BBBB BBBB
// 22 = BBBB GBBB BBBB BAAB
// 23 = BBBB GGGG GGGG GGGG
// 24 = GGGG GGGG GGGG GGGG
// 25 = BBBB BBBB BBBB BGGB
// 26 = GGGG GGGG BBBB BBBB
// 27 = BBBB BBBB BBBB BBAA

// Number 0
// BBBB AAAA BBBB BBBB = 1
// BBBA BBBB ABBB BBBB = 2
// BBAB BBBB BABB BBBB = 3
// BBAB BBBB BABB BBBB = 3
// BBAB BBBB BABB BBBB = 3
// BBAB BBBB BABB BBBB = 3
// BBBA BBBB ABBB BBBB = 2
// BBBB AAAA BBBB BBBB = 1

// Number 1
// BBBB AAAB BBBB BBBB = 4
// BBBA AAAB BBBB BBBB = 5
// BBBB BAAB BBBB BBBB = 6
// BBBB BAAB BBBB BBBB = 6
// BBBB BAAB BBBB BBBB = 6
// BBBB BAAB BBBB BBBB = 6
// BBBB BAAB BBBB BBBB = 6
// BBAA AAAA AABB BBBB = 7

// Number 2
// BBBA AAAA ABBB BBBB = 8
// BBAB BBBB BABB BBBB = 3
// BBBB BBBB BABB BBBB = 9
// BBBB BBBA ABBB BBBB = 10
// BBBB BAAB BBBB BBBB = 6
// BBBA ABBB BBBB BBBB = 11
// BBAB BBBB BABB BBBB = 3
// BBAA AAAA AABB BBBB = 7

// Number 3
// BBBA AAAA ABBB BBBB = 8
// BBAB BBBB BABB BBBB = 3
// BBAB BBBB BABB BBBB = 3
// BBBB BBBA ABBB BBBB = 10
// BBBB BBBB BABB BBBB = 9
// BBAB BBBB BABB BBBB = 3
// BBAB BBBB BABB BBBB = 3
// BBBA AAAA ABBB BBBB = 8

// Number 4
// BBBB BBAA ABBB BBBB = 12
// BBBB BABB ABBB BBBB = 13
// BBBB ABBB ABBB BBBB = 14
// BBBA BBBB ABBB BBBB = 2
// BBAA AAAA AABB BBBB = 7
// BBBB BBBB ABBB BBBB = 15
// BBBB BBBB ABBB BBBB = 15

// Number 5
// BBAA AAAA AABB BBBB = 7
// BBAB BBBB BBBB BBBB = 16
// BBAB BBBB BBBB BBBB = 16
// BBAA AAAA AABB BBBB = 7
// BBBB BBBB BABB BBBB = 9
// BBAB BBBB BABB BBBB = 3
// BBAB BBBB BABB BBBB = 3
// BBBA AAAA ABBB BBBB = 8

// Number 6
// BBBA AAAA ABBB BBBB = 8
// BBAB BBBB BABB BBBB = 3
// BBAB BBBB BBBB BBBB = 16
// BBAA AAAA ABBB BBBB = 17
// BBAB BBBB BABB BBBB = 3
// BBAB BBBB BABB BBBB = 3
// BBAB BBBB BABB BBBB = 3
// BBBA AAAA ABBB BBBB = 8

// Number 7
// BBAA AAAA AABB BBBB = 7
// BBAB BBBB BABB BBBB = 3
// BBBB BBBB ABBB BBBB = 15
// BBBB BBBB ABBB BBBB = 15
// BBBB BBBA BBBB BBBB = 18
// BBBB BBBA BBBB BBBB = 18
// BBBB BBAB BBBB BBBB = 19

// Number 8
// BBBA AAAA ABBB BBBB = 8
// BBAB BBBB BABB BBBB = 3
// BBAB BBBB BABB BBBB = 3
// BBBA AAAA ABBB BBBB = 8
// BBAB BBBB BABB BBBB = 3
// BBAB BBBB BABB BBBB = 3
// BBAB BBBB BABB BBBB = 3
// BBBA AAAA ABBB BBBB = 8

// Number 9
// BBBA AAAA ABBB BBBB = 8
// BBAB BBBB BABB BBBB = 3
// BBAB BBBB BABB BBBB = 3
// BBBA AAAA AABB BBBB = 20
// BBBB BBBB BABB BBBB = 9
// BBBB BBBB BABB BBBB = 9
// BBBB BBBB BABB BBBB = 9
// BBBB BBBB BABB BBBB = 9

// Left wall no paddle
// BBBB GBBB BBBB BBBB = 21

// Left wall with paddle
// BBBB GBBB BBBB BAAB = 22

// Top/bottom wall left start
// BBBB GGGG GGGG GGGG = 23

// Top/bottom wall
// GGGG GGGG GGGG GGGG = 24

// Middle divider dot
// BBBB BBBB BBBB BGGB = 25

// Top/bottom wall right end
// GGGG GGGG BBBB BBBB = 26

// Right paddle
// BBBB BBBB BBBB BBAA = 27

void setup()
{
}

void loop()
{
  asm("cli");

  // Set pins to output
  asm("ldi r25, 0b00011000              ");
  asm("out 0x04, r25                    ");
  asm("ldi r25, 0b11111111              ");
  asm("out 0x0a, r25                    ");

  // Load tile data
  asm("rcall load_tiles                ");

  // Load descriptors
  //r25 = x, r24 = y, r23 = index)

  // Clear descriptors
  asm("ldi r25, 0");
  asm("ldi XL, lo8(0x110)");
  asm("ldi XH, hi8(0x110)");
  asm("ldi YL, lo8(640)");
  asm("ldi YH, hi8(640)");
  asm("clear_descriptors_loop:");
    asm("st X, r25");
    asm("sbiw, Y, 1");
    asm("brne clear_descriptors_loop");
  
  // Load scores
  asm("ldi r25, 3");
  asm("ldi r24, 4");
  asm("ldi r23, 1");
  asm("rcall write_descriptor"); // Line 1, left
  asm("ldi r24, 5");
  asm("ldi r23, 2");
  asm("rcall write_descriptor"); // Line 2, left
  asm("ldi r24, 6");
  asm("ldi r23, 3");
  asm("rcall write_descriptor"); // Line 3, left
  asm("ldi r24, 7");
  asm("rcall write_descriptor"); // Line 4, left
  asm("ldi r24, 8");
  asm("rcall write_descriptor"); // Line 5, left
  asm("ldi r24, 9");
  asm("rcall write_descriptor"); // Line 6, left
  asm("ldi r24, 10");
  asm("ldi r23, 2");
  asm("rcall write_descriptor"); // Line 7, left
  asm("ldi r24, 11");
  asm("ldi r23, 1");
  asm("rcall write_descriptor"); // Line 8, left

  asm("ldi r25, 4");
  asm("ldi r24, 4");
  asm("ldi r23, 1");
  asm("rcall write_descriptor"); // Line 1, right
  asm("ldi r24, 5");
  asm("ldi r23, 2");
  asm("rcall write_descriptor"); // Line 2, right
  asm("ldi r24, 6");
  asm("ldi r23, 3");
  asm("rcall write_descriptor"); // Line 3, right
  asm("ldi r24, 7");
  asm("rcall write_descriptor"); // Line 4, right
  asm("ldi r24, 8");
  asm("rcall write_descriptor"); // Line 5, right
  asm("ldi r24, 9");
  asm("rcall write_descriptor"); // Line 6, right
  asm("ldi r24, 10");
  asm("ldi r23, 2");
  asm("rcall write_descriptor"); // Line 7, right
  asm("ldi r24, 11");
  asm("ldi r23, 1");
  asm("rcall write_descriptor"); // Line 8, right

  // Start loop
  asm("start_of_frame:                  ");

  // Set tile descriptor start address
  asm("ldi ZL, lo8(0x110)             ");
  asm("ldi ZH, hi8(0x110)             ");

  // Visible area loop (vertical resolution of 80, 6 pixels per pixel)
  asm("ldi r16, 80                    ");
  asm("visible_area_loop:             ");
  asm("rjmp load_line               "); // 2+501+2+3=508
  asm("load_line_ret:               ");
  asm("rcall visible_line           "); // 3+4+501=508
  asm("rcall visible_line           "); // 3+4+501=508
  asm("rcall visible_line           "); // 3+4+501=508
  asm("rcall visible_line           "); // 3+4+501=508
  asm("rcall visible_line           "); // 3+4+501=508

  asm("dec r16                      ");
  asm("brne visible_area_loop       ");

  // Front porch
  asm("ldi r16, 10                    ");
  asm("front_porch_loop:              ");
  asm("rjmp front_porch_line        "); // 2+2+?+501=508
  asm("front_porch_line_ret:        ");
  asm("dec r16                      ");
  asm("brne front_porch_loop        ");

  //"wdr ");
  // asm("rjmp start_of_frame            ");

  // Sync pulse
  asm("ldi r25, 0b00001000             ");
  asm("out 0x05, r25                   ");
  asm("ldi r16, 2                      ");
  asm("sync_pulse_loop:                ");
  asm("rjmp sync_pulse_line         ");
  asm("sync_pulse_line_ret:         ");
  asm("dec r16                      ");
  asm("brne sync_pulse_loop         ");
  asm("ldi r25, 0b00011000             ");
  asm("out 0x05, r25                   ");

  // Back porch
  asm("ldi r16, 33");
  asm("back_porch_loop:               ");
  asm("rjmp back_porch_line         ");
  asm("back_porch_line_ret:         ");
  asm("dec r16                      ");
  asm("brne back_porch_loop         ");

  // Return to start
  asm("wdr                            ");
  asm("rjmp start_of_frame            ");

  // Load line subroutine
  asm("load_line:                      ");
  // Z = Tile descriptor address
  // Y = Tile data address
  // r24 = Tile data offset low
  // r23 = Tile data offset high

  // Set tile data offset
  asm("ldi r24, lo8(0x390)            "); // 1
  asm("ldi r23, hi8(0x390)            "); // 1

  // First tile
  // Get tile address
  asm("ld YL, Z+                    "); // 2    Copy tile index
  asm("ldi YH, 0x00                 "); // 1
  asm("lsl YL                       "); // 1    Multiply by 2
  asm("rol YH                       "); // 1
  asm("lsl YL                       "); // 1    Multiply by 2 (now 4x)
  asm("rol YH                       "); // 1
  asm("lsl YL                       "); // 1    Multiply by 2 (now 8x)
  asm("rol YH                       "); // 1
  asm("lsl YL                       "); // 1    Multiply by 2 (now 16x)
  asm("rol YH                       "); // 1

  asm("add YL, r24                  "); // 1    Offset address by 0x390
  asm("adc YH, r23                  "); // 1

  // Write tile address
  asm("sts 0x110, YL                 "); // 2
  asm("sts 0x111, YH                 "); // 2

  // 2 tile
  // Get tile address
  asm("ld YL, Z+                    "); // 3    Copy tile index
  asm("ldi YH, 0x00                 "); // 1
  asm("lsl YL                       "); // 1    Multiply by 2
  asm("rol YH                       "); // 1
  asm("lsl YL                       "); // 1    Multiply by 2 (now 4x)
  asm("rol YH                       "); // 1
  asm("lsl YL                       "); // 1    Multiply by 2 (now 8x)
  asm("rol YH                       "); // 1
  asm("lsl YL                       "); // 1    Multiply by 2 (now 16x)
  asm("rol YH                       "); // 1

  asm("add YL, r24                  "); // 1    Offset address by 0x390
  asm("adc YH, r23                  "); // 1

  // Write tile address
  asm("sts 0x112, YL                 "); // 2
  asm("sts 0x113, YH                 "); // 2

  // 3 tile
  // Get tile address
  asm("ld YL, Z+                    "); // 3    Copy tile index
  asm("ldi YH, 0x00                 "); // 1
  asm("lsl YL                       "); // 1    Multiply by 2
  asm("rol YH                       "); // 1
  asm("lsl YL                       "); // 1    Multiply by 2 (now 4x)
  asm("rol YH                       "); // 1
  asm("lsl YL                       "); // 1    Multiply by 2 (now 8x)
  asm("rol YH                       "); // 1
  asm("lsl YL                       "); // 1    Multiply by 2 (now 16x)
  asm("rol YH                       "); // 1

  asm("add YL, r24                  "); // 1    Offset address by 0x390
  asm("adc YH, r23                  "); // 1

  // Write tile address
  asm("sts 0x114, YL                 "); // 2
  asm("sts 0x115, YH                 "); // 2

  // 4 tile
  // Get tile address
  asm("ld YL, Z+                    "); // 3    Copy tile index
  asm("ldi YH, 0x00                 "); // 1
  asm("lsl YL                       "); // 1    Multiply by 2
  asm("rol YH                       "); // 1
  asm("lsl YL                       "); // 1    Multiply by 2 (now 4x)
  asm("rol YH                       "); // 1
  asm("lsl YL                       "); // 1    Multiply by 2 (now 8x)
  asm("rol YH                       "); // 1
  asm("lsl YL                       "); // 1    Multiply by 2 (now 16x)
  asm("rol YH                       "); // 1

  asm("add YL, r24                  "); // 1    Offset address by 0x390
  asm("adc YH, r23                  "); // 1

  // Write tile address
  asm("sts 0x116, YL                 "); // 2
  asm("sts 0x117, YH                 "); // 2

  // 5 tile
  // Get tile address
  asm("ld YL, Z+                    "); // 3    Copy tile index
  asm("ldi YH, 0x00                 "); // 1
  asm("lsl YL                       "); // 1    Multiply by 2
  asm("rol YH                       "); // 1
  asm("lsl YL                       "); // 1    Multiply by 2 (now 4x)
  asm("rol YH                       "); // 1
  asm("lsl YL                       "); // 1    Multiply by 2 (now 8x)
  asm("rol YH                       "); // 1
  asm("lsl YL                       "); // 1    Multiply by 2 (now 16x)
  asm("rol YH                       "); // 1

  asm("add YL, r24                  "); // 1    Offset address by 0x390
  asm("adc YH, r23                  "); // 1

  // Write tile address
  asm("sts 0x118, YL                 "); // 2
  asm("sts 0x119, YH                 "); // 2

  // 6 tile
  // Get tile address
  asm("ld YL, Z+                    "); // 3    Copy tile index
  asm("ldi YH, 0x00                 "); // 1
  asm("lsl YL                       "); // 1    Multiply by 2
  asm("rol YH                       "); // 1
  asm("lsl YL                       "); // 1    Multiply by 2 (now 4x)
  asm("rol YH                       "); // 1
  asm("lsl YL                       "); // 1    Multiply by 2 (now 8x)
  asm("rol YH                       "); // 1
  asm("lsl YL                       "); // 1    Multiply by 2 (now 16x)
  asm("rol YH                       "); // 1

  asm("add YL, r24                  "); // 1    Offset address by 0x390
  asm("adc YH, r23                  "); // 1

  // Write tile address
  asm("sts 0x11a, YL                 "); // 2
  asm("sts 0x11b, YH                 "); // 2

  // 7 tile
  // Get tile address
  asm("ld YL, Z+                    "); // 3    Copy tile index
  asm("ldi YH, 0x00                 "); // 1
  asm("lsl YL                       "); // 1    Multiply by 2
  asm("rol YH                       "); // 1
  asm("lsl YL                       "); // 1    Multiply by 2 (now 4x)
  asm("rol YH                       "); // 1
  asm("lsl YL                       "); // 1    Multiply by 2 (now 8x)
  asm("rol YH                       "); // 1
  asm("lsl YL                       "); // 1    Multiply by 2 (now 16x)
  asm("rol YH                       "); // 1

  asm("add YL, r24                  "); // 1    Offset address by 0x390
  asm("adc YH, r23                  "); // 1

  // Write tile address
  asm("sts 0x11c, YL                 "); // 2
  asm("sts 0x11d, YH                 "); // 2

  // 8 tile
  // Get tile address
  asm("ld YL, Z+                    "); // 3    Copy tile index
  asm("ldi YH, 0x00                 "); // 1
  asm("lsl YL                       "); // 1    Multiply by 2
  asm("rol YH                       "); // 1
  asm("lsl YL                       "); // 1    Multiply by 2 (now 4x)
  asm("rol YH                       "); // 1
  asm("lsl YL                       "); // 1    Multiply by 2 (now 8x)
  asm("rol YH                       "); // 1
  asm("lsl YL                       "); // 1    Multiply by 2 (now 16x)
  asm("rol YH                       "); // 1

  asm("add YL, r24                  "); // 1    Offset address by 0x390
  asm("adc YH, r23                  "); // 1

  // Write tile address
  asm("sts 0x11e, YL                 "); // 2
  asm("sts 0x11f, YH                 "); // 2

  // Front porch (burn 279)
  asm("ldi r25, 69                       ");  // 1
  asm("load_line_front_porch:             "); // 4 / 1
  asm("dec r25                          ");   // 1
  asm("nop ");                                // 1
  asm("brne load_line_front_porch       ");   // 2 / 1
  asm("ldi r25, 0b00010000                "); // 1

  // Sync pulse (61)
  asm("out 0x05, r25                      "); // 1
  asm("ldi r25, 19                        "); // 1
  asm("load_line_sync_pulse:              "); // 3 / 1
  asm("dec r25                         ");    // 1
  asm("brne load_line_sync_pulse       ");    // 2 / 1
  asm("ldi r25, 0b00011000                "); // 1

  // Back porch (30.5064548163 cycles) (-2 -2 -3 = -7) (23)
  asm("out 0x05, r25                      "); // 1
  asm("ldi r25, 6                         "); // 1
  asm("load_line_back_porch:              "); // 3 / 1
  asm("dec r25                          ");   // 1
  asm("brne load_line_back_porch        ");   // 2 / 1

  asm("nop \n nop "); // 2

  asm("rjmp load_line_ret                 "); // 2

  // Visible line subroutine 501
  asm("visible_line:                    ");
  // X = pixel read address
  // r25 = Pixel color

  // Visible area 407
  // Tile 1 (52)
  asm("lds XL, 0x110                 "); // 2    Load tile address
  asm("lds XH, 0x111                 "); // 2

  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1

  // Tile 2 (52)
  asm("lds XL, 0x112                 "); // 2    Load tile address
  asm("lds XH, 0x113                 "); // 2

  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1

  // Tile 3 (52)
  asm("lds XL, 0x114                 "); // 2    Load tile address
  asm("lds XH, 0x115                 "); // 2

  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1

  // Tile 4 (52)
  asm("lds XL, 0x116                 "); // 2    Load tile address
  asm("lds XH, 0x117                 "); // 2

  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1

  // Tile 5 (52)
  asm("lds XL, 0x118                 "); // 2    Load tile address
  asm("lds XH, 0x119                 "); // 2

  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1

  // Tile 6 (52)
  asm("lds XL, 0x11a                 "); // 2    Load tile address
  asm("lds XH, 0x11b                 "); // 2

  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1

  // Tile 7 (52)
  asm("lds XL, 0x11c                 "); // 2    Load tile address
  asm("lds XH, 0x11d                 "); // 2

  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1

  // Tile 8 (43)
  asm("lds XL, 0x11e                 "); // 2    Load tile address
  asm("lds XH, 0x11f                 "); // 2

  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, X+                   "); // 2
  asm("out 0x0b, r25                "); // 1

  asm("nop \n nop ");
  asm("ldi r25, 0b00000000          "); // 1

  // Front porch (10)
  asm("out 0x0b, r25                ");                         // 1    Clear RGB
  asm("nop \n nop \n nop \n nop \n nop \n nop \n nop \n nop "); // 8
  asm("ldi r25, 0b00010000          ");                         // 1

  // Sync pulse (61)
  asm("out 0x05, r25                      "); // 1
  asm("ldi r25, 19                        "); // 1
  asm("visible_line_sync_pulse:           "); // 3 / 1
  asm("dec r25                         ");    // 1
  asm("brne visible_line_sync_pulse    ");    // 2 / 1
  asm("ldi r25, 0b00011000                "); // 1

  // Back porch (30.5064548163 cycles) (23)
  asm("out 0x05, r25                      "); // 1
  asm("ldi r25, 6                         "); // 1
  asm("visible_line_back_porch:           "); // 3 / 1
  asm("dec r25                          ");   // 1
  asm("brne visible_line_back_porch     ");   // 2 / 1
  asm("nop \n nop ");                         // 2

  asm("ret                                "); // 4

  // Front porch line
  asm("front_porch_line:                      ");
  // Front porch and visible area (417)
  asm("ldi r25, 138                         "); // 1
  asm("front_porch_line_front_porch:        "); // 3 / 1
  asm("dec r25                            ");   // 1
  asm("brne front_porch_line_front_porch  ");   // 2 / 1
  asm("ldi r25, 0b00010000                  "); // 1

  // Sync pulse (61)
  asm("out 0x05, r25                          "); // 1
  asm("ldi r25, 19                            "); // 1
  asm("front_porch_line_sync_pulse:           "); // 3 / 1
  asm("dec r25                             ");    // 1
  asm("brne front_porch_line_sync_pulse    ");    // 2 / 1
  asm("ldi r25, 0b00011000                    "); // 1

  // Back porch (30.5064548163 cycles) (23)
  asm("out 0x05, r25                          "); // 1
  asm("ldi r25, 6                             "); // 1
  asm("front_porch_line_back_porch:           "); // 3 / 1
  asm("dec r25                              ");   // 1
  asm("brne front_porch_line_back_porch     ");   // 2 / 1
  asm("nop \n nop                            ");  // 2

  asm("rjmp front_porch_line_ret              "); // 2

  // Sync pulse line
  asm("sync_pulse_line:                       ");
  // Front porch and visible area (417)
  asm("ldi r25, 138                         "); // 1
  asm("sync_pulse_line_front_porch:         "); // 3 / 1
  asm("dec r25                            ");   // 1
  asm("brne sync_pulse_line_front_porch   ");   // 2 / 1
  asm("ldi r25, 0b00000000                  "); // 1

  // Sync pulse (61)
  asm("out 0x05, r25                          "); // 1
  asm("ldi r25, 19                            "); // 1
  asm("sync_pulse_line_sync_pulse:            "); // 3 / 1
  asm("dec r25                             ");    // 1
  asm("brne sync_pulse_line_sync_pulse     ");    // 2 / 1
  asm("ldi r25, 0b00001000                    "); // 1

  // Back porch (30.5064548163 cycles) (23)
  asm("out 0x05, r25                          "); // 1
  asm("ldi r25, 6                             "); // 1
  asm("sync_pulse_line_back_porch:            "); // 4 / 1
  asm("dec r25                              ");   // 1
  asm("brne sync_pulse_line_back_porch      ");   // 2 / 1
  asm("nop \n nop                            ");  // 2

  asm("rjmp sync_pulse_line_ret               "); // 2

  // Back porch line
  asm("back_porch_line:                       ");
  // Front porch and visible area (417)
  asm("ldi r25, 138                         "); // 1
  asm("back_porch_line_front_porch:         "); // 3 / 1
  asm("dec r25                            ");   // 1
  asm("brne back_porch_line_front_porch   ");   // 2 / 1
  asm("ldi r25, 0b00010000                  "); // 1

  // Sync pulse (61)
  asm("out 0x05, r25                          "); // 1
  asm("ldi r25, 19                            "); // 1
  asm("back_porch_line_sync_pulse:            "); // 3 / 1
  asm("dec r25                             ");    // 1
  asm("brne back_porch_line_sync_pulse     ");    // 2 / 1
  asm("ldi r25, 0b00011000                    "); // 1

  // Back porch (30.5064548163 cycles) (23)
  asm("out 0x05, r25                          "); // 1
  asm("ldi r25, 6                             "); // 1
  asm("back_porch_line_back_porch:            "); // 4 / 1
  asm("dec r25                              ");   // 1
  asm("brne back_porch_line_back_porch      ");   // 2 / 1
  asm("nop \n nop                             "); // 2

  asm("rjmp back_porch_line_ret               "); // 2

  // Init load of tile (21 with rcall) (r25 = tile index)
  asm("init_tile_load:                  ");
  asm("ldi r24, lo8(0x390)            "); // 1
  asm("ldi r23, hi8(0x390)            "); // 1

  asm("mov XL, r25                    "); // 1    Copy tile index
  asm("ldi XH, 0x00                   "); // 1

  asm("lsl XL                         "); // 1    Multiply by 2
  asm("rol XH                         "); // 1
  asm("lsl XL                         "); // 1    Multiply by 2 (now 4x)
  asm("rol XH                         "); // 1
  asm("lsl XL                         "); // 1    Multiply by 2 (now 8x)
  asm("rol XH                         "); // 1
  asm("lsl XL                         "); // 1    Multiply by 2 (now 16x)
  asm("rol XH                         "); // 1

  asm("add XL, r24                    "); // 1    Offset address by 0x390
  asm("adc XH, r23                    "); // 1

  asm("ret                            "); // 4

  // Write descriptor (24 with rcall) (r25 = x, r24 = y, r23 = index)
  asm("write_descriptor:                ");
  asm("ldi r22, lo8(0x110)            "); // 1
  asm("ldi r21, hi8(0x110)            "); // 1
  asm("ldi r20, 0x00                  "); // 1

  asm("mov XL, r24                    "); // 1    Load y-coord to X
  asm("ldi XH, 0x00                   "); // 1

  asm("lsl XL                         "); // 1    Multiply by 2
  asm("rol XH                         "); // 1
  asm("lsl XL                         "); // 1    Multiply by 2 (now 4x)
  asm("rol XH                         "); // 1
  asm("lsl XL                         "); // 1    Multiply by 2 (now 8x)
  asm("rol XH                         "); // 1

  asm("add XL, r25                    "); // 1    Add x-coord to address
  asm("adc XH, r20                    "); // 1

  asm("add XL, r22                    "); // 1    Offset address by 0x110
  asm("add XH, r21                    "); // 1

  asm("st X, r23                      "); // 2    Write index to address

  asm("ret                            "); // 4

  // Load tiles
  asm("load_tiles:");
  // Set color pallet
  asm("ldi r24, 0b00000111            "); // White
  asm("ldi r23, 0b00000000            "); // Black
  asm("ldi r22, 0b00000100            "); // 50% grey

  // Tile 0 - BBBB BBBB BBBB BBBB
  asm("ldi r25, 0                     ");
  asm("rcall init_tile_load           ");
  asm("st X+, r23                     "); // 1
  asm("st X+, r23                     "); // 2
  asm("st X+, r23                     "); // 3
  asm("st X+, r23                     "); // 4
  asm("st X+, r23                     "); // 5
  asm("st X+, r23                     "); // 6
  asm("st X+, r23                     "); // 7
  asm("st X+, r23                     "); // 8
  asm("st X+, r23                     "); // 9
  asm("st X+, r23                     "); // 10
  asm("st X+, r23                     "); // 11
  asm("st X+, r23                     "); // 12
  asm("st X+, r23                     "); // 13
  asm("st X+, r23                     "); // 14
  asm("st X+, r23                     "); // 15
  asm("st X+, r23                     "); // 16

  // Tile 1 - BBBB AAAA BBBB BBBB
  asm("ldi r25, 1                     ");
  asm("rcall init_tile_load           ");
  asm("st X+, r23                     "); // 1
  asm("st X+, r23                     "); // 2
  asm("st X+, r23                     "); // 3
  asm("st X+, r23                     "); // 4
  asm("st X+, r24                     "); // 5
  asm("st X+, r24                     "); // 6
  asm("st X+, r24                     "); // 7
  asm("st X+, r24                     "); // 8
  asm("st X+, r23                     "); // 9
  asm("st X+, r23                     "); // 10
  asm("st X+, r23                     "); // 11
  asm("st X+, r23                     "); // 12
  asm("st X+, r23                     "); // 13
  asm("st X+, r23                     "); // 14
  asm("st X+, r23                     "); // 15
  asm("st X+, r23                     "); // 16

  // Tile 2 - BBBA BBBB ABBB BBBB
  asm("ldi r25, 2                     ");
  asm("rcall init_tile_load           ");
  asm("st X+, r23                     "); // 1
  asm("st X+, r23                     "); // 2
  asm("st X+, r23                     "); // 3
  asm("st X+, r24                     "); // 4
  asm("st X+, r23                     "); // 5
  asm("st X+, r23                     "); // 6
  asm("st X+, r23                     "); // 7
  asm("st X+, r23                     "); // 8
  asm("st X+, r24                     "); // 9
  asm("st X+, r23                     "); // 10
  asm("st X+, r23                     "); // 11
  asm("st X+, r23                     "); // 12
  asm("st X+, r23                     "); // 13
  asm("st X+, r23                     "); // 14
  asm("st X+, r23                     "); // 15
  asm("st X+, r23                     "); // 16

  // Tile 3 - BBAB BBBB BABB BBBB
  asm("ldi r25, 3                     ");
  asm("rcall init_tile_load           ");
  asm("st X+, r23                     "); // 1
  asm("st X+, r23                     "); // 2
  asm("st X+, r24                     "); // 3
  asm("st X+, r23                     "); // 4
  asm("st X+, r23                     "); // 5
  asm("st X+, r23                     "); // 6
  asm("st X+, r23                     "); // 7
  asm("st X+, r23                     "); // 8
  asm("st X+, r23                     "); // 9
  asm("st X+, r24                     "); // 10
  asm("st X+, r23                     "); // 11
  asm("st X+, r23                     "); // 12
  asm("st X+, r23                     "); // 13
  asm("st X+, r23                     "); // 14
  asm("st X+, r23                     "); // 15
  asm("st X+, r23                     "); // 16

  // Tile 4 - BBBB AAAB BBBB BBBB
  asm("ldi r25, 4                     ");
  asm("rcall init_tile_load           ");
  asm("st X+, r23                     "); // 1
  asm("st X+, r23                     "); // 2
  asm("st X+, r23                     "); // 3
  asm("st X+, r23                     "); // 4
  asm("st X+, r24                     "); // 5
  asm("st X+, r24                     "); // 6
  asm("st X+, r24                     "); // 7
  asm("st X+, r23                     "); // 8
  asm("st X+, r23                     "); // 9
  asm("st X+, r23                     "); // 10
  asm("st X+, r23                     "); // 11
  asm("st X+, r23                     "); // 12
  asm("st X+, r23                     "); // 13
  asm("st X+, r23                     "); // 14
  asm("st X+, r23                     "); // 15
  asm("st X+, r23                     "); // 16

  // Tile 5 - BBBA AAAB BBBB BBBB
  asm("ldi r25, 5                     ");
  asm("rcall init_tile_load           ");
  asm("st X+, r23                     "); // 1
  asm("st X+, r23                     "); // 2
  asm("st X+, r23                     "); // 3
  asm("st X+, r24                     "); // 4
  asm("st X+, r24                     "); // 5
  asm("st X+, r24                     "); // 6
  asm("st X+, r24                     "); // 7
  asm("st X+, r23                     "); // 8
  asm("st X+, r23                     "); // 9
  asm("st X+, r23                     "); // 10
  asm("st X+, r23                     "); // 11
  asm("st X+, r23                     "); // 12
  asm("st X+, r23                     "); // 13
  asm("st X+, r23                     "); // 14
  asm("st X+, r23                     "); // 15
  asm("st X+, r23                     "); // 16

  // Tile 6 - BBBB BAAB BBBB BBBB
  asm("ldi r25, 6                     ");
  asm("rcall init_tile_load           ");
  asm("st X+, r23                     "); // 1
  asm("st X+, r23                     "); // 2
  asm("st X+, r23                     "); // 3
  asm("st X+, r23                     "); // 4
  asm("st X+, r23                     "); // 5
  asm("st X+, r24                     "); // 6
  asm("st X+, r24                     "); // 7
  asm("st X+, r23                     "); // 8
  asm("st X+, r23                     "); // 9
  asm("st X+, r23                     "); // 10
  asm("st X+, r23                     "); // 11
  asm("st X+, r23                     "); // 12
  asm("st X+, r23                     "); // 13
  asm("st X+, r23                     "); // 14
  asm("st X+, r23                     "); // 15
  asm("st X+, r23                     "); // 16

  // Tile 7 - BBAA AAAA AABB BBBB
  asm("ldi r25, 7                     ");
  asm("rcall init_tile_load           ");
  asm("st X+, r23                     "); // 1
  asm("st X+, r23                     "); // 2
  asm("st X+, r24                     "); // 3
  asm("st X+, r24                     "); // 4
  asm("st X+, r24                     "); // 5
  asm("st X+, r24                     "); // 6
  asm("st X+, r24                     "); // 7
  asm("st X+, r24                     "); // 8
  asm("st X+, r24                     "); // 9
  asm("st X+, r24                     "); // 10
  asm("st X+, r23                     "); // 11
  asm("st X+, r23                     "); // 12
  asm("st X+, r23                     "); // 13
  asm("st X+, r23                     "); // 14
  asm("st X+, r23                     "); // 15
  asm("st X+, r23                     "); // 16

  // Tile 8 - BBBA AAAA ABBB BBBB
  asm("ldi r25, 8                     ");
  asm("rcall init_tile_load           ");
  asm("st X+, r23                     "); // 1
  asm("st X+, r23                     "); // 2
  asm("st X+, r23                     "); // 3
  asm("st X+, r24                     "); // 4
  asm("st X+, r24                     "); // 5
  asm("st X+, r24                     "); // 6
  asm("st X+, r24                     "); // 7
  asm("st X+, r24                     "); // 8
  asm("st X+, r24                     "); // 9
  asm("st X+, r23                     "); // 10
  asm("st X+, r23                     "); // 11
  asm("st X+, r23                     "); // 12
  asm("st X+, r23                     "); // 13
  asm("st X+, r23                     "); // 14
  asm("st X+, r23                     "); // 15
  asm("st X+, r23                     "); // 16

  // Tile 9 - BBBB BBBB BABB BBBB
  asm("ldi r25, 9                     ");
  asm("rcall init_tile_load           ");
  asm("st X+, r23                     "); // 1
  asm("st X+, r23                     "); // 2
  asm("st X+, r23                     "); // 3
  asm("st X+, r23                     "); // 4
  asm("st X+, r23                     "); // 5
  asm("st X+, r23                     "); // 6
  asm("st X+, r23                     "); // 7
  asm("st X+, r23                     "); // 8
  asm("st X+, r23                     "); // 9
  asm("st X+, r24                     "); // 10
  asm("st X+, r23                     "); // 11
  asm("st X+, r23                     "); // 12
  asm("st X+, r23                     "); // 13
  asm("st X+, r23                     "); // 14
  asm("st X+, r23                     "); // 15
  asm("st X+, r23                     "); // 16

  // Tile 10 - BBBB BBBA ABBB BBBB
  asm("ldi r25, 10                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r23                     "); // 1
  asm("st X+, r23                     "); // 2
  asm("st X+, r23                     "); // 3
  asm("st X+, r23                     "); // 4
  asm("st X+, r23                     "); // 5
  asm("st X+, r23                     "); // 6
  asm("st X+, r23                     "); // 7
  asm("st X+, r24                     "); // 8
  asm("st X+, r24                     "); // 9
  asm("st X+, r23                     "); // 10
  asm("st X+, r23                     "); // 11
  asm("st X+, r23                     "); // 12
  asm("st X+, r23                     "); // 13
  asm("st X+, r23                     "); // 14
  asm("st X+, r23                     "); // 15
  asm("st X+, r23                     "); // 16

  // Tile 11 - BBBA ABBB BBBB BBBB
  asm("ldi r25, 11                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r23                     "); // 1
  asm("st X+, r23                     "); // 2
  asm("st X+, r23                     "); // 3
  asm("st X+, r24                     "); // 4
  asm("st X+, r24                     "); // 5
  asm("st X+, r23                     "); // 6
  asm("st X+, r23                     "); // 7
  asm("st X+, r23                     "); // 8
  asm("st X+, r23                     "); // 9
  asm("st X+, r23                     "); // 10
  asm("st X+, r23                     "); // 11
  asm("st X+, r23                     "); // 12
  asm("st X+, r23                     "); // 13
  asm("st X+, r23                     "); // 14
  asm("st X+, r23                     "); // 15
  asm("st X+, r23                     "); // 16

  // Tile 12 - BBBB BBAA ABBB BBBB
  asm("ldi r25, 12                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r23                     "); // 1
  asm("st X+, r23                     "); // 2
  asm("st X+, r23                     "); // 3
  asm("st X+, r23                     "); // 4
  asm("st X+, r23                     "); // 5
  asm("st X+, r23                     "); // 6
  asm("st X+, r24                     "); // 7
  asm("st X+, r24                     "); // 8
  asm("st X+, r24                     "); // 9
  asm("st X+, r23                     "); // 10
  asm("st X+, r23                     "); // 11
  asm("st X+, r23                     "); // 12
  asm("st X+, r23                     "); // 13
  asm("st X+, r23                     "); // 14
  asm("st X+, r23                     "); // 15
  asm("st X+, r23                     "); // 16

  // Tile 13 - BBBB BABB ABBB BBBB
  asm("ldi r25, 13                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r23                     "); // 1
  asm("st X+, r23                     "); // 2
  asm("st X+, r23                     "); // 3
  asm("st X+, r23                     "); // 4
  asm("st X+, r23                     "); // 5
  asm("st X+, r24                     "); // 6
  asm("st X+, r23                     "); // 7
  asm("st X+, r23                     "); // 8
  asm("st X+, r24                     "); // 9
  asm("st X+, r23                     "); // 10
  asm("st X+, r23                     "); // 11
  asm("st X+, r23                     "); // 12
  asm("st X+, r23                     "); // 13
  asm("st X+, r23                     "); // 14
  asm("st X+, r23                     "); // 15
  asm("st X+, r23                     "); // 16

  // Tile 14 - BBBB ABBB ABBB BBBB
  asm("ldi r25, 14                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r23                     "); // 1
  asm("st X+, r23                     "); // 2
  asm("st X+, r23                     "); // 3
  asm("st X+, r23                     "); // 4
  asm("st X+, r24                     "); // 5
  asm("st X+, r23                     "); // 6
  asm("st X+, r23                     "); // 7
  asm("st X+, r23                     "); // 8
  asm("st X+, r24                     "); // 9
  asm("st X+, r23                     "); // 10
  asm("st X+, r23                     "); // 11
  asm("st X+, r23                     "); // 12
  asm("st X+, r23                     "); // 13
  asm("st X+, r23                     "); // 14
  asm("st X+, r23                     "); // 15
  asm("st X+, r23                     "); // 16

  // Tile 15 - BBBB BBBB ABBB BBBB
  asm("ldi r25, 15                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r23                     "); // 1
  asm("st X+, r23                     "); // 2
  asm("st X+, r23                     "); // 3
  asm("st X+, r23                     "); // 4
  asm("st X+, r23                     "); // 5
  asm("st X+, r23                     "); // 6
  asm("st X+, r23                     "); // 7
  asm("st X+, r23                     "); // 8
  asm("st X+, r24                     "); // 9
  asm("st X+, r23                     "); // 10
  asm("st X+, r23                     "); // 11
  asm("st X+, r23                     "); // 12
  asm("st X+, r23                     "); // 13
  asm("st X+, r23                     "); // 14
  asm("st X+, r23                     "); // 15
  asm("st X+, r23                     "); // 16

  // Tile 16 - BBAB BBBB BBBB BBBB
  asm("ldi r25, 16                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r23                     "); // 1
  asm("st X+, r23                     "); // 2
  asm("st X+, r24                     "); // 3
  asm("st X+, r23                     "); // 4
  asm("st X+, r23                     "); // 5
  asm("st X+, r23                     "); // 6
  asm("st X+, r23                     "); // 7
  asm("st X+, r23                     "); // 8
  asm("st X+, r23                     "); // 9
  asm("st X+, r23                     "); // 10
  asm("st X+, r23                     "); // 11
  asm("st X+, r23                     "); // 12
  asm("st X+, r23                     "); // 13
  asm("st X+, r23                     "); // 14
  asm("st X+, r23                     "); // 15
  asm("st X+, r23                     "); // 16

  // Tile 17 - BBAA AAAA ABBB BBBB
  asm("ldi r25, 17                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r23                     "); // 1
  asm("st X+, r23                     "); // 2
  asm("st X+, r24                     "); // 3
  asm("st X+, r24                     "); // 4
  asm("st X+, r24                     "); // 5
  asm("st X+, r24                     "); // 6
  asm("st X+, r24                     "); // 7
  asm("st X+, r24                     "); // 8
  asm("st X+, r24                     "); // 9
  asm("st X+, r23                     "); // 10
  asm("st X+, r23                     "); // 11
  asm("st X+, r23                     "); // 12
  asm("st X+, r23                     "); // 13
  asm("st X+, r23                     "); // 14
  asm("st X+, r23                     "); // 15
  asm("st X+, r23                     "); // 16

  // Tile 18 - BBBB BBBA BBBB BBBB
  asm("ldi r25, 18                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r23                     "); // 1
  asm("st X+, r23                     "); // 2
  asm("st X+, r23                     "); // 3
  asm("st X+, r23                     "); // 4
  asm("st X+, r23                     "); // 5
  asm("st X+, r23                     "); // 6
  asm("st X+, r23                     "); // 7
  asm("st X+, r24                     "); // 8
  asm("st X+, r23                     "); // 9
  asm("st X+, r23                     "); // 10
  asm("st X+, r23                     "); // 11
  asm("st X+, r23                     "); // 12
  asm("st X+, r23                     "); // 13
  asm("st X+, r23                     "); // 14
  asm("st X+, r23                     "); // 15
  asm("st X+, r23                     "); // 16

  // Tile 19 - BBBB BBAB BBBB BBBB
  asm("ldi r25, 19                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r23                     "); // 1
  asm("st X+, r23                     "); // 2
  asm("st X+, r23                     "); // 3
  asm("st X+, r23                     "); // 4
  asm("st X+, r23                     "); // 5
  asm("st X+, r23                     "); // 6
  asm("st X+, r24                     "); // 7
  asm("st X+, r23                     "); // 8
  asm("st X+, r23                     "); // 9
  asm("st X+, r23                     "); // 10
  asm("st X+, r23                     "); // 11
  asm("st X+, r23                     "); // 12
  asm("st X+, r23                     "); // 13
  asm("st X+, r23                     "); // 14
  asm("st X+, r23                     "); // 15
  asm("st X+, r23                     "); // 16

  // Tile 20 - BBBA AAAA AABB BBBB
  asm("ldi r25, 20                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r23                     "); // 1
  asm("st X+, r23                     "); // 2
  asm("st X+, r23                     "); // 3
  asm("st X+, r24                     "); // 4
  asm("st X+, r24                     "); // 5
  asm("st X+, r24                     "); // 6
  asm("st X+, r24                     "); // 7
  asm("st X+, r24                     "); // 8
  asm("st X+, r24                     "); // 9
  asm("st X+, r24                     "); // 10
  asm("st X+, r23                     "); // 11
  asm("st X+, r23                     "); // 12
  asm("st X+, r23                     "); // 13
  asm("st X+, r23                     "); // 14
  asm("st X+, r23                     "); // 15
  asm("st X+, r23                     "); // 16

  // Tile 21 - BBBB GBBB BBBB BBBB
  asm("ldi r25, 21                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r23                     "); // 1
  asm("st X+, r23                     "); // 2
  asm("st X+, r23                     "); // 3
  asm("st X+, r23                     "); // 4
  asm("st X+, r22                     "); // 5
  asm("st X+, r23                     "); // 6
  asm("st X+, r23                     "); // 7
  asm("st X+, r23                     "); // 8
  asm("st X+, r23                     "); // 9
  asm("st X+, r23                     "); // 10
  asm("st X+, r23                     "); // 11
  asm("st X+, r23                     "); // 12
  asm("st X+, r23                     "); // 13
  asm("st X+, r23                     "); // 14
  asm("st X+, r23                     "); // 15
  asm("st X+, r23                     "); // 16

  // Tile 22 - BBBB GBBB BBBB BAAB
  asm("ldi r25, 22                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r23                     "); // 1
  asm("st X+, r23                     "); // 2
  asm("st X+, r23                     "); // 3
  asm("st X+, r23                     "); // 4
  asm("st X+, r22                     "); // 5
  asm("st X+, r23                     "); // 6
  asm("st X+, r23                     "); // 7
  asm("st X+, r23                     "); // 8
  asm("st X+, r23                     "); // 9
  asm("st X+, r23                     "); // 10
  asm("st X+, r23                     "); // 11
  asm("st X+, r23                     "); // 12
  asm("st X+, r23                     "); // 13
  asm("st X+, r24                     "); // 14
  asm("st X+, r24                     "); // 15
  asm("st X+, r23                     "); // 16

  // Tile 23 - BBBB GGGG GGGG GGGG
  asm("ldi r25, 23                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r23                     "); // 1
  asm("st X+, r23                     "); // 2
  asm("st X+, r23                     "); // 3
  asm("st X+, r23                     "); // 4
  asm("st X+, r22                     "); // 5
  asm("st X+, r22                     "); // 6
  asm("st X+, r22                     "); // 7
  asm("st X+, r22                     "); // 8
  asm("st X+, r22                     "); // 9
  asm("st X+, r22                     "); // 10
  asm("st X+, r22                     "); // 11
  asm("st X+, r22                     "); // 12
  asm("st X+, r22                     "); // 13
  asm("st X+, r22                     "); // 14
  asm("st X+, r22                     "); // 15
  asm("st X+, r22                     "); // 16

  // Tile 24 - GGGG GGGG GGGG GGGG
  asm("ldi r25, 24                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r22                     "); // 1
  asm("st X+, r22                     "); // 2
  asm("st X+, r22                     "); // 3
  asm("st X+, r22                     "); // 4
  asm("st X+, r22                     "); // 5
  asm("st X+, r22                     "); // 6
  asm("st X+, r22                     "); // 7
  asm("st X+, r22                     "); // 8
  asm("st X+, r22                     "); // 9
  asm("st X+, r22                     "); // 10
  asm("st X+, r22                     "); // 11
  asm("st X+, r22                     "); // 12
  asm("st X+, r22                     "); // 13
  asm("st X+, r22                     "); // 14
  asm("st X+, r22                     "); // 15
  asm("st X+, r22                     "); // 16

  // Tile 25 - BBBB BBBB BBBB BGGB
  asm("ldi r25, 25                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r23                     "); // 1
  asm("st X+, r23                     "); // 2
  asm("st X+, r23                     "); // 3
  asm("st X+, r23                     "); // 4
  asm("st X+, r23                     "); // 5
  asm("st X+, r23                     "); // 6
  asm("st X+, r23                     "); // 7
  asm("st X+, r23                     "); // 8
  asm("st X+, r23                     "); // 9
  asm("st X+, r23                     "); // 10
  asm("st X+, r23                     "); // 11
  asm("st X+, r23                     "); // 12
  asm("st X+, r23                     "); // 13
  asm("st X+, r22                     "); // 14
  asm("st X+, r22                     "); // 15
  asm("st X+, r23                     "); // 16

  // Tile 26 - GGGG GGGG BBBB BBBB
  asm("ldi r25, 26                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r22                     "); // 1
  asm("st X+, r22                     "); // 2
  asm("st X+, r22                     "); // 3
  asm("st X+, r22                     "); // 4
  asm("st X+, r22                     "); // 5
  asm("st X+, r22                     "); // 6
  asm("st X+, r22                     "); // 7
  asm("st X+, r22                     "); // 8
  asm("st X+, r23                     "); // 9
  asm("st X+, r23                     "); // 10
  asm("st X+, r23                     "); // 11
  asm("st X+, r23                     "); // 12
  asm("st X+, r23                     "); // 13
  asm("st X+, r23                     "); // 14
  asm("st X+, r23                     "); // 15
  asm("st X+, r23                     "); // 16

  // Tile 27 - BBBB BBBB BBBB BBAA
  asm("ldi r25, 27                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r23                     "); // 1
  asm("st X+, r23                     "); // 2
  asm("st X+, r23                     "); // 3
  asm("st X+, r23                     "); // 4
  asm("st X+, r23                     "); // 5
  asm("st X+, r23                     "); // 6
  asm("st X+, r23                     "); // 7
  asm("st X+, r23                     "); // 8
  asm("st X+, r23                     "); // 9
  asm("st X+, r23                     "); // 10
  asm("st X+, r23                     "); // 11
  asm("st X+, r23                     "); // 12
  asm("st X+, r23                     "); // 13
  asm("st X+, r23                     "); // 14
  asm("st X+, r24                     "); // 15
  asm("st X+, r24                     "); // 16
}
