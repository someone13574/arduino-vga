// X = r27:r26
// Y = r29:r28
// Z = r31:r30

// Memory layout
// Current line         0x100  to 0x10f  (6 tiles)
// Tile descriptors     0x110  to 0x38f (640 descriptors, 8 per line)
// Tile data            0x390 to 0x8f0 (86 tiles)

// Pallet
// B = 0b11110100 (color) = 0b00000101 (grey) = blue
// W = 0b11111111 (color) = 0b00000111 (grey) = white
// G = 0b10110111 (color) = 0b00000110 (grey) = ground
// M = 0b01111101 (color) = 0b00000101 (grey) = Medium Green
// H = 0b10111110 (color) = 0b00000110 (grey) = Bright Green
// L = 0b01110100 (color) = 0b00000011 (grey) = Dark Green
// Y = yellow
// O = orange

// Tile map
// BBBB BBBB BBBB BBBB = 0
// BBBB BBBB BBBW WWBB = 1
// BBBB BBBB BBWB BBWB = 2
// BBBB BBBB BBBB WBBB = 3
// BBBB BBBB BBBW WBBB = 4
// BBBB BBBB BBWW WWWB = 5
// BBBB BBBB BBBB BWBB = 6
// BBBB BBBB BBBW BBBB = 7
// BBBB BBBB BBBB WWBB = 8
// BBBB BBBB BBBB BBWB = 9
// BBBB BBBB BBWB BWBB = 10
// BBWW WBBB BBBB BBBB = 11
// BWBB BWBB BBBB BBBB = 12
// BBBW BBBB BBBB BBBB = 13
// BBWW BBBB BBBB BBBB = 14
// BWWW WWBB BBBB BBBB = 15
// BBBB WBBB BBBB BBBB = 16
// BBWB BBBB BBBB BBBB = 17
// BBBW WBBB BBBB BBBB = 18
// BBBB BWBB BBBB BBBB = 19
// BWBB WBBB BBBB BBBB = 20
// BWBB BBBB BBBB BBBB = 21
// BWWW WBBB BBBB BBBB = 22
// BBWW WWBB BBBB BBBB = 23
// WBBB BWBB BBBB BBBB = 24
// BBBB BBYY YWBB BBBB = 25
// BBBB WWWY YWWB BBBB = 26
// BBBB WWWW YYOO BBBB = 27
// BBBB BWWY YYYB BBBB = 28
// BBBB BBBY YYBB BBBB = 29
// BBBB BWWW YWWB BBBB = 30
// BBBB BBWY YYOO BBBB = 31
// BBBB BWWB BBBB BBBB = 32
// BBBB BWWW YYBB BBBB = 33
// BBBB BWWW YYWB BBBB = 34
// BBBB BBWW YWWB BBBB = 35
// BBBB BBYY YYWB BBBB = 36
// BBBB BBYY YOOB BBBB = 37
// BBBB BBBB BBOB BBBB = 38
// BBBB BBBB WBBB BBBB = 39
// BBBB BBBW WBBB BBBB = 40
// BBBB BBWW WYBB BBBB = 41
// BBBB BBWW YYBB BBBB = 42
// BBBB BYYW YYYB BBBB = 43
// BBBB BBYY YWWB BBBB = 44
// BBBB BBYY OWBB BBBB = 45
// BBBB BBBY OBBB BBBB = 46
// BBBB BBYW WOOB BBBB = 47
// BBBB BYYY YYYB BBBB = 48
// BBBB BYWW YYYB BBBB = 49
// BBBB BWWW YYYB BBBB = 50
// BBBB WWWW BYBB BBBB = 51
// BBBB BBBB BBBB BBMH = 52
// BBBB BBBB BBBB MHMM = 53
// BBBB BBBB BBMH MMMM = 54
// BBBB BBBB MHMM MMLL = 55
// BBBB BBMH MMMM LLBB = 56
// BBBB MHMM MMLL BBBB = 57
// BBMH MMMM LLBB BBBB = 58
// MHMM MMLL BBBB BBBB = 59
// MMMM LLBB BBBB BBBB = 60
// MMLL BBBB BBBB BBBB = 61
// LLBB BBBB BBBB BBBB = 62
// BBBB BBBB BBBB BBBM = 63
// BBBB BBBB BBBB BMHM = 64
// BBBB BBBB BBBM HMML = 65
// BBBB BBBB BMHM MLLB = 66
// BBBB BBBM HMML LBBB = 67
// BBBB BMHM MLLB BBBB = 68
// BBBM HMML LBBB BBBB = 69
// BMHM MLLB BBBB BBBB = 70
// HMML LBBB BBBB BBBB = 71
// MLLB BBBB BBBB BBBB = 72
// LBBB BBBB BBBB BBBB = 73
// GGGG GGGG GGGG GGGG = 74

// Sky
// BBBB BBBB BBBB BBBB = 0

// Ground
// GGGG GGGG GGGG GGGG = 74

// Left 0
// BBBB BBBB BBBW WWBB = 1
// BBBB BBBB BBWB BBWB = 2
// BBBB BBBB BBWB BBWB = 2
// BBBB BBBB BBWB BBWB = 2
// BBBB BBBB BBWB BBWB = 2
// BBBB BBBB BBBW WWBB = 1

// Left 1
// BBBB BBBB BBBB WBBB = 3
// BBBB BBBB BBBW WBBB = 4
// BBBB BBBB BBBB WBBB = 3
// BBBB BBBB BBBB WBBB = 3
// BBBB BBBB BBBB WBBB = 3
// BBBB BBBB BBWW WWWB = 5

// Left 2
// BBBB BBBB BBBW WWBB = 1
// BBBB BBBB BBWB BBWB = 2
// BBBB BBBB BBBB BWBB = 6
// BBBB BBBB BBBB WBBB = 3
// BBBB BBBB BBBW BBBB = 7
// BBBB BBBB BBWW WWWB = 5

// Left 3
// BBBB BBBB BBBW WWBB = 1
// BBBB BBBB BBWB BBWB = 2
// BBBB BBBB BBBB WWBB = 8
// BBBB BBBB BBBB BBWB = 9
// BBBB BBBB BBWB BBWB = 2
// BBBB BBBB BBBW WWBB = 1

// Left 4
// BBBB BBBB BBWB BWBB = 10
// BBBB BBBB BBWB BWBB = 10
// BBBB BBBB BBWB BWBB = 10
// BBBB BBBB BBWW WWWB = 5
// BBBB BBBB BBBB BWBB = 6
// BBBB BBBB BBBB BWBB = 6

// Right 0
// BBWW WBBB BBBB BBBB = 11
// BWBB BWBB BBBB BBBB = 12
// BWBB BWBB BBBB BBBB = 12
// BWBB BWBB BBBB BBBB = 12
// BWBB BWBB BBBB BBBB = 12
// BBWW WBBB BBBB BBBB = 11

// Right 1
// BBBW BBBB BBBB BBBB = 13
// BBWW BBBB BBBB BBBB = 14
// BBBW BBBB BBBB BBBB = 13
// BBBW BBBB BBBB BBBB = 13
// BBBW BBBB BBBB BBBB = 13
// BWWW WWBB BBBB BBBB = 15

// Right 2
// BBWW WBBB BBBB BBBB = 11
// BWBB BWBB BBBB BBBB = 12
// BBBB WBBB BBBB BBBB = 16
// BBBW BBBB BBBB BBBB = 13
// BBWB BBBB BBBB BBBB = 17
// BWWW WWBB BBBB BBBB = 15

// Right 3
// BBWW WBBB BBBB BBBB = 11
// BWBB BWBB BBBB BBBB = 12
// BBBW WBBB BBBB BBBB = 18
// BBBB BWBB BBBB BBBB = 19
// BWBB BWBB BBBB BBBB = 12
// BBWW WBBB BBBB BBBB = 11

// Right 4
// BWBB WBBB BBBB BBBB = 20
// BWBB WBBB BBBB BBBB = 20
// BWBB WBBB BBBB BBBB = 20
// BWWW WWBB BBBB BBBB = 15
// BBBB WBBB BBBB BBBB = 16
// BBBB WBBB BBBB BBBB = 16

// Right 5
// BWWW WWBB BBBB BBBB = 15
// BWBB BBBB BBBB BBBB = 21
// BWWW WBBB BBBB BBBB = 22
// BBBB BWBB BBBB BBBB = 19
// BWBB BWBB BBBB BBBB = 12
// BBWW WBBB BBBB BBBB = 11

// Right 6
// BBWW WWBB BBBB BBBB = 23
// BWBB BBBB BBBB BBBB = 21
// BWWW WBBB BBBB BBBB = 22
// BWBB BWBB BBBB BBBB = 12
// BWBB BWBB BBBB BBBB = 12
// BBWW WBBB BBBB BBBB = 11

// Right 7
// BWWW WWBB BBBB BBBB = 15
// BBBB BWBB BBBB BBBB = 19
// BBBB WBBB BBBB BBBB = 16
// BBBB WBBB BBBB BBBB = 16
// BBBW BBBB BBBB BBBB = 13
// BBBW BBBB BBBB BBBB = 13

// Right 8
// BBWW WBBB BBBB BBBB = 11
// WBBB BWBB BBBB BBBB = 24
// BBWW WBBB BBBB BBBB = 11
// WBBB BWBB BBBB BBBB = 24
// WBBB BWBB BBBB BBBB = 24
// BBWW WBBB BBBB BBBB = 11

// Right 9
// BBWW WBBB BBBB BBBB = 11
// BWBB BWBB BBBB BBBB = 12
// BWBB BWBB BBBB BBBB = 12
// BBWW WWBB BBBB BBBB = 23
// BBBB BWBB BBBB BBBB = 19
// BBBB BWBB BBBB BBBB = 19

// Bird 0 (level)
// BBBB BBYY YWBB BBBB = 25
// BBBB WWWY YWWB BBBB = 26
// BBBB WWWW YYOO BBBB = 27
// BBBB BWWY YYYB BBBB = 28
// BBBB BBBY YYBB BBBB = 29

// Bird 1 (down 1)
// BBBB BWWY YYYB BBBB = 28
// BBBB WWWY YWWB BBBB = 26
// BBBB BWWW YWWB BBBB = 30
// BBBB BBWY YYOO BBBB = 31
// BBBB BBBY YYBB BBBB = 29

// Bird 2 (down 2)
// BBBB BWWB BBBB BBBB = 32
// BBBB BWWW YYBB BBBB = 33
// BBBB BWWW YYWB BBBB = 34
// BBBB BBWW YWWB BBBB = 35
// BBBB BBYY YYWB BBBB = 36
// BBBB BBYY YOOB BBBB = 37
// BBBB BBBB BBOB BBBB = 38

// Bird 3 (down 3)
// BBBB BBBB WBBB BBBB = 39
// BBBB BBBW WBBB BBBB = 40
// BBBB BBWW WYBB BBBB = 41
// BBBB BBWW YYBB BBBB = 42
// BBBB BYYW YYYB BBBB = 43
// BBBB BBYY YWWB BBBB = 44
// BBBB BBYY OWBB BBBB = 45
// BBBB BBBY OBBB BBBB = 46

// Bird 4 (up 1)
// BBBB BBBB BBOB BBBB = 38
// BBBB BBYW WOOB BBBB = 47
// BBBB BYYY YYYB BBBB = 48
// BBBB BYWW YYYB BBBB = 49
// BBBB BWWW YYYB BBBB = 50
// BBBB WWWW BYBB BBBB = 51
// BBBB BWBB BBBB BBBB = 19

// Pipe tops
// BBBB BBBB BBBB BBMH = 52
// BBBB BBBB BBBB MHMM = 53
// BBBB BBBB BBMH MMMM = 54
// BBBB BBBB MHMM MMLL = 55
// BBBB BBMH MMMM LLBB = 56
// BBBB MHMM MMLL BBBB = 57
// BBMH MMMM LLBB BBBB = 58
// MHMM MMLL BBBB BBBB = 59
// MMMM LLBB BBBB BBBB = 60
// MMLL BBBB BBBB BBBB = 61
// LLBB BBBB BBBB BBBB = 62

// Pipes
// BBBB BBBB BBBB BBBM = 63
// BBBB BBBB BBBB BMHM = 64
// BBBB BBBB BBBM HMML = 65
// BBBB BBBB BMHM MLLB = 66
// BBBB BBBM HMML LBBB = 67
// BBBB BMHM MLLB BBBB = 68
// BBBM HMML LBBB BBBB = 69
// BMHM MLLB BBBB BBBB = 70
// HMML LBBB BBBB BBBB = 71
// MLLB BBBB BBBB BBBB = 72
// LBBB BBBB BBBB BBBB = 73

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

  // Start loop
  asm("start_of_frame:                  ");

  // Set tile descriptor start address
  asm("ldi XL, lo8(0x110)             ");
  asm("ldi XH, hi8(0x110)             ");

  // Visible area loop (vertical resolution of 80, 6 pixels per pixel)
  asm("ldi r16, 80                    ");
  asm("visible_area_loop:             ");
  asm("rjmp load_line               "); // 2+501+2+3=508
  asm("load_line_ret:           nop    ");
  asm("rcall visible_line          \n nop "); // 3+4+501=508
  asm("rcall visible_line           ");       // 3+4+501=508
  asm("rcall visible_line          \n nop "); // 3+4+501=508
  asm("rcall visible_line           ");       // 3+4+501=508
  asm("rcall visible_line          \n nop "); // 3+4+501=508

  asm("dec r16                      ");
  asm("brne visible_area_loop       ");

  // Front porch
  asm("ldi r16, 10                    ");
  asm("front_porch_loop:              ");
  asm("rjmp front_porch_line        "); // 2+2+?+501=508
  asm("front_porch_line_ret:        ");
  asm("dec r16                      ");
  asm("brne front_porch_loop        ");

  // Sync pulse
  asm("ldi r25, 0b00001000             ");
  asm("out 0x05, r25                   ");
  asm("ldi r16, 2                      ");
  asm("rjmp sync_pulse_line");
  asm("sync_pulse_line_ret:");
  asm("rjmp sync_pulse_compute_line");
  asm("sync_pulse_compute_line_ret:");
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
  // X = Tile descriptor address
  // Y = Tile data address
  // r24 = Tile data offset low
  // r23 = Tile data offset high

  // Set tile data offset
  asm("ldi r24, lo8(0x390)            "); // 1
  asm("ldi r23, hi8(0x390)            "); // 1

  // First tile
  // Get tile address
  asm("ld YL, X+                    "); // 2    Copy tile index
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
  asm("ld YL, X+                    "); // 3    Copy tile index
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
  asm("ld YL, X+                    "); // 2    Copy tile index
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
  asm("ld YL, X+                    "); // 3    Copy tile index
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
  asm("ld YL, X+                    "); // 3    Copy tile index
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
  asm("ld YL, X+                    "); // 3    Copy tile index
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
  asm("ld YL, X+                    "); // 3    Copy tile index
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
  asm("ld YL, X+                    "); // 3    Copy tile index
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
  asm("lds YL, 0x110                 "); // 2    Load tile address
  asm("lds YH, 0x111                 "); // 2

  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1

  // Tile 2 (52)
  asm("lds YL, 0x112                 "); // 2    Load tile address
  asm("lds YH, 0x113                 "); // 2

  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1

  // Tile 3 (52)
  asm("lds YL, 0x114                 "); // 2    Load tile address
  asm("lds YH, 0x115                 "); // 2

  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1

  // Tile 4 (52)
  asm("lds YL, 0x116                 "); // 2    Load tile address
  asm("lds YH, 0x117                 "); // 2

  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1

  // Tile 5 (52)
  asm("lds YL, 0x118                 "); // 2    Load tile address
  asm("lds YH, 0x119                 "); // 2

  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1

  // Tile 6 (52)
  asm("lds YL, 0x11a                 "); // 2    Load tile address
  asm("lds YH, 0x11b                 "); // 2

  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1

  // Tile 7 (52)
  asm("lds YL, 0x11c                 "); // 2    Load tile address
  asm("lds YH, 0x11d                 "); // 2

  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1

  // Tile 8 (43)
  asm("lds YL, 0x11e                 "); // 2    Load tile address
  asm("lds YH, 0x11f                 "); // 2

  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
  asm("out 0x0b, r25                "); // 1
  asm("ld r25, Y+                   "); // 2
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
  asm("ldi r25, 7                             "); // 1
  asm("sync_pulse_line_back_porch:            "); // 4 / 1
  asm("dec r25                              ");   // 1
  asm("brne sync_pulse_line_back_porch      ");   // 2 / 1
  asm("nop \n nop                            ");  // 2

  asm("rjmp sync_pulse_line_ret               "); // 2

  // Sync pulse line compute
  asm("sync_pulse_compute_line:                       ");

  // Front porch and visible area (329)
  asm("ldi r25, 138                         ");         // 1
  asm("sync_pulse_compute_line_front_porch:         "); // 3 / 1
  asm("dec r25                            ");           // 1
  asm("brne sync_pulse_compute_line_front_porch   ");   // 2 / 1
  asm("ldi r25, 0b00000000                  ");         // 1

  // Sync pulse (61)
  asm("out 0x05, r25                          ");         // 1
  asm("ldi r25, 19                            ");         // 1
  asm("sync_pulse_compute_line_sync_pulse:            "); // 3 / 1
  asm("dec r25                             ");            // 1
  asm("brne sync_pulse_compute_line_sync_pulse     ");    // 2 / 1
  asm("ldi r25, 0b00001000                    ");         // 1

  // Back porch (30.5064548163 cycles) (23)
  asm("out 0x05, r25                          ");         // 1
  asm("ldi r25, 7                             ");         // 1
  asm("sync_pulse_line_compute_back_porch:            "); // 4 / 1
  asm("dec r25                              ");           // 1
  asm("brne sync_pulse_line_compute_back_porch      ");   // 2 / 1
  asm("nop \n nop                            ");          // 2

  asm("rjmp sync_pulse_compute_line_ret               "); // 2

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
  asm("ldi r21, lo8(0x390)            "); // 1
  asm("ldi r20, hi8(0x390)            "); // 1

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

  asm("add XL, r21                    "); // 1    Offset address by 0x390
  asm("adc XH, r20                    "); // 1

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
  // Set color pallet (cannot use r25, r22, r21, r20)
  asm("ldi r24, 0b00000101"); // B
  asm("ldi r23, 0b00000111"); // W

  // Tile 0 - BBBB BBBB BBBB BBBB
  asm("ldi r25, 0                     ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1     1 1
  asm("st X+, r24                     "); // 2     1 2
  asm("st X+, r24                     "); // 3     1 3
  asm("st X+, r24                     "); // 4     1 4
  asm("st X+, r24                     "); // 5     2 1
  asm("st X+, r24                     "); // 6     2 2
  asm("st X+, r24                     "); // 7     2 3
  asm("st X+, r24                     "); // 8     2 4
  asm("st X+, r24                     "); // 9     3 1
  asm("st X+, r24                     "); // 10    3 2
  asm("st X+, r24                     "); // 11    3 3
  asm("st X+, r24                     "); // 12    3 4
  asm("st X+, r24                     "); // 13    4 1
  asm("st X+, r24                     "); // 14    4 2
  asm("st X+, r24                     "); // 15    4 3
  asm("st X+, r24                     "); // 16    4 4

  // Tile 1 - BBBB BBBB BBBW WWBB = 1
  asm("ldi r25, 1                     ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r24                     "); // 6    2 2
  asm("st X+, r24                     "); // 7    2 3
  asm("st X+, r24                     "); // 8    2 4
  asm("st X+, r24                     "); // 9    3 1
  asm("st X+, r24                    ");  // 10   3 2
  asm("st X+, r24                    ");  // 11   3 3
  asm("st X+, r23                    ");  // 12   3 4
  asm("st X+, r23                    ");  // 13   4 1
  asm("st X+, r23                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 2 - BBBB BBBB BBWB BBWB = 2
  asm("ldi r25, 2                     ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r24                     "); // 6    2 2
  asm("st X+, r24                     "); // 7    2 3
  asm("st X+, r24                     "); // 8    2 4
  asm("st X+, r24                     "); // 9    3 1
  asm("st X+, r24                    ");  // 10   3 2
  asm("st X+, r23                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r23                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 3 - BBBB BBBB BBBB WBBB = 3
  asm("ldi r25, 3                     ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r24                     "); // 6    2 2
  asm("st X+, r24                     "); // 7    2 3
  asm("st X+, r24                     "); // 8    2 4
  asm("st X+, r24                     "); // 9    3 1
  asm("st X+, r24                    ");  // 10   3 2
  asm("st X+, r24                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r23                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 4 - BBBB BBBB BBBW WBBB = 4
  asm("ldi r25, 4                     ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r24                     "); // 6    2 2
  asm("st X+, r24                     "); // 7    2 3
  asm("st X+, r24                     "); // 8    2 4
  asm("st X+, r24                     "); // 9    3 1
  asm("st X+, r24                    ");  // 10   3 2
  asm("st X+, r24                    ");  // 11   3 3
  asm("st X+, r23                    ");  // 12   3 4
  asm("st X+, r23                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 5 - BBBB BBBB BBWW WWWB = 5
  asm("ldi r25, 5                     ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r24                     "); // 6    2 2
  asm("st X+, r24                     "); // 7    2 3
  asm("st X+, r24                     "); // 8    2 4
  asm("st X+, r24                     "); // 9    3 1
  asm("st X+, r24                    ");  // 10   3 2
  asm("st X+, r23                    ");  // 11   3 3
  asm("st X+, r23                    ");  // 12   3 4
  asm("st X+, r23                    ");  // 13   4 1
  asm("st X+, r23                    ");  // 14   4 2
  asm("st X+, r23                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 6 - BBBB BBBB BBBB BWBB = 6
  asm("ldi r25, 6                     ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r24                     "); // 6    2 2
  asm("st X+, r24                     "); // 7    2 3
  asm("st X+, r24                     "); // 8    2 4
  asm("st X+, r24                     "); // 9    3 1
  asm("st X+, r24                    ");  // 10   3 2
  asm("st X+, r24                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r23                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 7 - BBBB BBBB BBBW BBBB = 7
  asm("ldi r25, 7                     ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r24                     "); // 6    2 2
  asm("st X+, r24                     "); // 7    2 3
  asm("st X+, r24                     "); // 8    2 4
  asm("st X+, r24                     "); // 9    3 1
  asm("st X+, r24                    ");  // 10   3 2
  asm("st X+, r24                    ");  // 11   3 3
  asm("st X+, r23                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 8 - BBBB BBBB BBBB WWBB = 8
  asm("ldi r25, 8                     ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r24                     "); // 6    2 2
  asm("st X+, r24                     "); // 7    2 3
  asm("st X+, r24                     "); // 8    2 4
  asm("st X+, r24                     "); // 9    3 1
  asm("st X+, r24                    ");  // 10   3 2
  asm("st X+, r24                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r23                    ");  // 13   4 1
  asm("st X+, r23                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 9 - BBBB BBBB BBBB BBWB = 9
  asm("ldi r25, 9                     ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r24                     "); // 6    2 2
  asm("st X+, r24                     "); // 7    2 3
  asm("st X+, r24                     "); // 8    2 4
  asm("st X+, r24                     "); // 9    3 1
  asm("st X+, r24                    ");  // 10   3 2
  asm("st X+, r24                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r23                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 10 - BBBB BBBB BBWB BWBB = 10
  asm("ldi r25, 10                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r24                     "); // 6    2 2
  asm("st X+, r24                     "); // 7    2 3
  asm("st X+, r24                     "); // 8    2 4
  asm("st X+, r24                     "); // 9    3 1
  asm("st X+, r24                    ");  // 10   3 2
  asm("st X+, r23                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r23                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 11 - BBWW WBBB BBBB BBBB = 11
  asm("ldi r25, 11                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r23                     "); // 3    1 3
  asm("st X+, r23                     "); // 4    1 4
  asm("st X+, r23                     "); // 5    2 1
  asm("st X+, r24                     "); // 6    2 2
  asm("st X+, r24                     "); // 7    2 3
  asm("st X+, r24                     "); // 8    2 4
  asm("st X+, r24                     "); // 9    3 1
  asm("st X+, r24                    ");  // 10   3 2
  asm("st X+, r24                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 12 - BWBB BWBB BBBB BBBB = 12
  asm("ldi r25, 12                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r23                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r23                     "); // 6    2 2
  asm("st X+, r24                     "); // 7    2 3
  asm("st X+, r24                     "); // 8    2 4
  asm("st X+, r24                     "); // 9    3 1
  asm("st X+, r24                    ");  // 10   3 2
  asm("st X+, r24                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 13 - BBBW BBBB BBBB BBBB = 13
  asm("ldi r25, 13                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r23                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r24                     "); // 6    2 2
  asm("st X+, r24                     "); // 7    2 3
  asm("st X+, r24                     "); // 8    2 4
  asm("st X+, r24                     "); // 9    3 1
  asm("st X+, r24                    ");  // 10   3 2
  asm("st X+, r24                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 14 - BBWW BBBB BBBB BBBB = 14
  asm("ldi r25, 14                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r23                     "); // 3    1 3
  asm("st X+, r23                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r24                     "); // 6    2 2
  asm("st X+, r24                     "); // 7    2 3
  asm("st X+, r24                     "); // 8    2 4
  asm("st X+, r24                     "); // 9    3 1
  asm("st X+, r24                    ");  // 10   3 2
  asm("st X+, r24                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 15 - BWWW WWBB BBBB BBBB = 15
  asm("ldi r25, 15                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r23                     "); // 2    1 2
  asm("st X+, r23                     "); // 3    1 3
  asm("st X+, r23                     "); // 4    1 4
  asm("st X+, r23                     "); // 5    2 1
  asm("st X+, r23                     "); // 6    2 2
  asm("st X+, r24                     "); // 7    2 3
  asm("st X+, r24                     "); // 8    2 4
  asm("st X+, r24                     "); // 9    3 1
  asm("st X+, r24                    ");  // 10   3 2
  asm("st X+, r24                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 16 - BBBB WBBB BBBB BBBB = 16
  asm("ldi r25, 16                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r23                     "); // 5    2 1
  asm("st X+, r24                     "); // 6    2 2
  asm("st X+, r24                     "); // 7    2 3
  asm("st X+, r24                     "); // 8    2 4
  asm("st X+, r24                     "); // 9    3 1
  asm("st X+, r24                    ");  // 10   3 2
  asm("st X+, r24                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 17 - BBWB BBBB BBBB BBBB = 17
  asm("ldi r25, 17                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r23                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r24                     "); // 6    2 2
  asm("st X+, r24                     "); // 7    2 3
  asm("st X+, r24                     "); // 8    2 4
  asm("st X+, r24                     "); // 9    3 1
  asm("st X+, r24                    ");  // 10   3 2
  asm("st X+, r24                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 18 - BBBW WBBB BBBB BBBB = 18
  asm("ldi r25, 18                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r23                     "); // 4    1 4
  asm("st X+, r23                     "); // 5    2 1
  asm("st X+, r24                     "); // 6    2 2
  asm("st X+, r24                     "); // 7    2 3
  asm("st X+, r24                     "); // 8    2 4
  asm("st X+, r24                     "); // 9    3 1
  asm("st X+, r24                    ");  // 10   3 2
  asm("st X+, r24                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 19 - BBBB BWBB BBBB BBBB = 19
  asm("ldi r25, 19                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r23                     "); // 6    2 2
  asm("st X+, r24                     "); // 7    2 3
  asm("st X+, r24                     "); // 8    2 4
  asm("st X+, r24                     "); // 9    3 1
  asm("st X+, r24                    ");  // 10   3 2
  asm("st X+, r24                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 20 - BWBB WBBB BBBB BBBB = 20
  asm("ldi r25, 20                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r23                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r23                     "); // 5    2 1
  asm("st X+, r24                     "); // 6    2 2
  asm("st X+, r24                     "); // 7    2 3
  asm("st X+, r24                     "); // 8    2 4
  asm("st X+, r24                     "); // 9    3 1
  asm("st X+, r24                    ");  // 10   3 2
  asm("st X+, r24                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 21 - BWBB BBBB BBBB BBBB = 21
  asm("ldi r25, 21                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r23                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r24                     "); // 6    2 2
  asm("st X+, r24                     "); // 7    2 3
  asm("st X+, r24                     "); // 8    2 4
  asm("st X+, r24                     "); // 9    3 1
  asm("st X+, r24                    ");  // 10   3 2
  asm("st X+, r24                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 22 - BWWW WBBB BBBB BBBB = 22
  asm("ldi r25, 22                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r23                     "); // 2    1 2
  asm("st X+, r23                     "); // 3    1 3
  asm("st X+, r23                     "); // 4    1 4
  asm("st X+, r23                     "); // 5    2 1
  asm("st X+, r24                     "); // 6    2 2
  asm("st X+, r24                     "); // 7    2 3
  asm("st X+, r24                     "); // 8    2 4
  asm("st X+, r24                     "); // 9    3 1
  asm("st X+, r24                    ");  // 10   3 2
  asm("st X+, r24                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 23 - BBWW WWBB BBBB BBBB = 23
  asm("ldi r25, 23                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r23                     "); // 3    1 3
  asm("st X+, r23                     "); // 4    1 4
  asm("st X+, r23                     "); // 5    2 1
  asm("st X+, r23                     "); // 6    2 2
  asm("st X+, r24                     "); // 7    2 3
  asm("st X+, r24                     "); // 8    2 4
  asm("st X+, r24                     "); // 9    3 1
  asm("st X+, r24                    ");  // 10   3 2
  asm("st X+, r24                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 24 - WBBB BWBB BBBB BBBB = 24
  asm("ldi r25, 24                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r23                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r23                     "); // 6    2 2
  asm("st X+, r24                     "); // 7    2 3
  asm("st X+, r24                     "); // 8    2 4
  asm("st X+, r24                     "); // 9    3 1
  asm("st X+, r24                    ");  // 10   3 2
  asm("st X+, r24                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Set color pallet (cannot use r25, r22, r21, r20)
  asm("ldi r24, 0b00000101"); // B
  asm("ldi r23, 0b00000111"); // W
  asm("ldi r19, 0b00000111"); // Y
  asm("ldi r18, 0b00000111"); // O

  // Tile 25 - BBBB BBYY YWBB BBBB = 25
  asm("ldi r25, 25                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r24                     "); // 6    2 2
  asm("st X+, r19                     "); // 7    2 3
  asm("st X+, r19                     "); // 8    2 4
  asm("st X+, r19                     "); // 9    3 1
  asm("st X+, r23                    ");  // 10   3 2
  asm("st X+, r24                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 26 - BBBB WWWY YWWB BBBB = 26
  asm("ldi r25, 26                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r23                     "); // 5    2 1
  asm("st X+, r23                     "); // 6    2 2
  asm("st X+, r23                     "); // 7    2 3
  asm("st X+, r19                     "); // 8    2 4
  asm("st X+, r19                     "); // 9    3 1
  asm("st X+, r23                    ");  // 10   3 2
  asm("st X+, r23                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 27 - BBBB WWWW YYOO BBBB = 27
  asm("ldi r25, 27                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r23                     "); // 5    2 1
  asm("st X+, r23                     "); // 6    2 2
  asm("st X+, r23                     "); // 7    2 3
  asm("st X+, r23                     "); // 8    2 4
  asm("st X+, r19                     "); // 9    3 1
  asm("st X+, r19                    ");  // 10   3 2
  asm("st X+, r18                    ");  // 11   3 3
  asm("st X+, r18                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 28 - BBBB BWWY YYYB BBBB = 28
  asm("ldi r25, 28                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r23                     "); // 6    2 2
  asm("st X+, r23                     "); // 7    2 3
  asm("st X+, r19                     "); // 8    2 4
  asm("st X+, r19                     "); // 9    3 1
  asm("st X+, r19                    ");  // 10   3 2
  asm("st X+, r19                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 29 - BBBB BBBY YYBB BBBB = 29
  asm("ldi r25, 29                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r24                     "); // 6    2 2
  asm("st X+, r24                     "); // 7    2 3
  asm("st X+, r19                     "); // 8    2 4
  asm("st X+, r19                     "); // 9    3 1
  asm("st X+, r19                    ");  // 10   3 2
  asm("st X+, r24                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 30 - BBBB BWWW YWWB BBBB = 30
  asm("ldi r25, 30                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r23                     "); // 6    2 2
  asm("st X+, r23                     "); // 7    2 3
  asm("st X+, r23                     "); // 8    2 4
  asm("st X+, r19                     "); // 9    3 1
  asm("st X+, r23                    ");  // 10   3 2
  asm("st X+, r23                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 31 - BBBB BBWY YYOO BBBB = 31
  asm("ldi r25, 31                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r24                     "); // 6    2 2
  asm("st X+, r23                     "); // 7    2 3
  asm("st X+, r19                     "); // 8    2 4
  asm("st X+, r19                     "); // 9    3 1
  asm("st X+, r19                    ");  // 10   3 2
  asm("st X+, r18                    ");  // 11   3 3
  asm("st X+, r18                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 32 - BBBB BWWB BBBB BBBB = 32
  asm("ldi r25, 32                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r23                     "); // 6    2 2
  asm("st X+, r23                     "); // 7    2 3
  asm("st X+, r24                     "); // 8    2 4
  asm("st X+, r24                     "); // 9    3 1
  asm("st X+, r24                    ");  // 10   3 2
  asm("st X+, r24                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 33 - BBBB BWWW YYBB BBBB = 33
  asm("ldi r25, 33                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r23                     "); // 6    2 2
  asm("st X+, r23                     "); // 7    2 3
  asm("st X+, r23                     "); // 8    2 4
  asm("st X+, r19                     "); // 9    3 1
  asm("st X+, r19                    ");  // 10   3 2
  asm("st X+, r24                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 34 - BBBB BWWW YYWB BBBB = 34
  asm("ldi r25, 34                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r23                     "); // 6    2 2
  asm("st X+, r23                     "); // 7    2 3
  asm("st X+, r23                     "); // 8    2 4
  asm("st X+, r19                     "); // 9    3 1
  asm("st X+, r19                    ");  // 10   3 2
  asm("st X+, r23                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 35 - BBBB BBWW YWWB BBBB = 35
  asm("ldi r25, 35                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r24                     "); // 6    2 2
  asm("st X+, r23                     "); // 7    2 3
  asm("st X+, r23                     "); // 8    2 4
  asm("st X+, r19                     "); // 9    3 1
  asm("st X+, r23                    ");  // 10   3 2
  asm("st X+, r23                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 36 - BBBB BBYY YYWB BBBB = 36
  asm("ldi r25, 36                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r24                     "); // 6    2 2
  asm("st X+, r19                     "); // 7    2 3
  asm("st X+, r19                     "); // 8    2 4
  asm("st X+, r19                     "); // 9    3 1
  asm("st X+, r19                    ");  // 10   3 2
  asm("st X+, r23                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 37 - BBBB BBYY YOOB BBBB = 37
  asm("ldi r25, 37                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r24                     "); // 6    2 2
  asm("st X+, r19                     "); // 7    2 3
  asm("st X+, r19                     "); // 8    2 4
  asm("st X+, r19                     "); // 9    3 1
  asm("st X+, r18                    ");  // 10   3 2
  asm("st X+, r18                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 38 - BBBB BBBB BBOB BBBB = 38
  asm("ldi r25, 38                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r24                     "); // 6    2 2
  asm("st X+, r24                     "); // 7    2 3
  asm("st X+, r24                     "); // 8    2 4
  asm("st X+, r24                     "); // 9    3 1
  asm("st X+, r24                    ");  // 10   3 2
  asm("st X+, r18                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 39 - BBBB BBBB WBBB BBBB = 39
  asm("ldi r25, 39                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r24                     "); // 6    2 2
  asm("st X+, r24                     "); // 7    2 3
  asm("st X+, r24                     "); // 8    2 4
  asm("st X+, r23                     "); // 9    3 1
  asm("st X+, r24                    ");  // 10   3 2
  asm("st X+, r24                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 40 - BBBB BBBW WBBB BBBB = 40
  asm("ldi r25, 40                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r24                     "); // 6    2 2
  asm("st X+, r24                     "); // 7    2 3
  asm("st X+, r23                     "); // 8    2 4
  asm("st X+, r23                     "); // 9    3 1
  asm("st X+, r24                    ");  // 10   3 2
  asm("st X+, r24                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 41 - BBBB BBWW WYBB BBBB = 41
  asm("ldi r25, 41                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r24                     "); // 6    2 2
  asm("st X+, r23                     "); // 7    2 3
  asm("st X+, r23                     "); // 8    2 4
  asm("st X+, r23                     "); // 9    3 1
  asm("st X+, r19                    ");  // 10   3 2
  asm("st X+, r24                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 42 - BBBB BBWW YYBB BBBB = 42
  asm("ldi r25, 42                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r24                     "); // 6    2 2
  asm("st X+, r23                     "); // 7    2 3
  asm("st X+, r23                     "); // 8    2 4
  asm("st X+, r19                     "); // 9    3 1
  asm("st X+, r19                    ");  // 10   3 2
  asm("st X+, r24                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 43 - BBBB BYYW YYYB BBBB = 43
  asm("ldi r25, 43                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r19                     "); // 6    2 2
  asm("st X+, r19                     "); // 7    2 3
  asm("st X+, r23                     "); // 8    2 4
  asm("st X+, r19                     "); // 9    3 1
  asm("st X+, r19                    ");  // 10   3 2
  asm("st X+, r19                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 44 - BBBB BBYY YWWB BBBB = 44
  asm("ldi r25, 44                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r24                     "); // 6    2 2
  asm("st X+, r19                     "); // 7    2 3
  asm("st X+, r19                     "); // 8    2 4
  asm("st X+, r19                     "); // 9    3 1
  asm("st X+, r23                    ");  // 10   3 2
  asm("st X+, r23                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 45 - BBBB BBYY OWBB BBBB = 45
  asm("ldi r25, 45                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r24                     "); // 6    2 2
  asm("st X+, r19                     "); // 7    2 3
  asm("st X+, r19                     "); // 8    2 4
  asm("st X+, r18                     "); // 9    3 1
  asm("st X+, r23                    ");  // 10   3 2
  asm("st X+, r24                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 46 - BBBB BBBY OBBB BBBB = 46
  asm("ldi r25, 46                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r24                     "); // 6    2 2
  asm("st X+, r24                     "); // 7    2 3
  asm("st X+, r19                     "); // 8    2 4
  asm("st X+, r18                     "); // 9    3 1
  asm("st X+, r24                    ");  // 10   3 2
  asm("st X+, r24                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 47 - BBBB BBYW WOOB BBBB = 47
  asm("ldi r25, 47                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r24                     "); // 6    2 2
  asm("st X+, r19                     "); // 7    2 3
  asm("st X+, r23                     "); // 8    2 4
  asm("st X+, r23                     "); // 9    3 1
  asm("st X+, r18                    ");  // 10   3 2
  asm("st X+, r18                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 48 - BBBB BYYY YYYB BBBB = 48
  asm("ldi r25, 48                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r19                     "); // 6    2 2
  asm("st X+, r19                     "); // 7    2 3
  asm("st X+, r19                     "); // 8    2 4
  asm("st X+, r19                     "); // 9    3 1
  asm("st X+, r19                    ");  // 10   3 2
  asm("st X+, r19                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 49 - BBBB BYWW YYYB BBBB = 49
  asm("ldi r25, 49                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r19                     "); // 6    2 2
  asm("st X+, r23                     "); // 7    2 3
  asm("st X+, r23                     "); // 8    2 4
  asm("st X+, r19                     "); // 9    3 1
  asm("st X+, r19                    ");  // 10   3 2
  asm("st X+, r19                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 50 - BBBB BWWW YYYB BBBB = 50
  asm("ldi r25, 50                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r23                     "); // 6    2 2
  asm("st X+, r23                     "); // 7    2 3
  asm("st X+, r23                     "); // 8    2 4
  asm("st X+, r19                     "); // 9    3 1
  asm("st X+, r19                    ");  // 10   3 2
  asm("st X+, r19                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 51 - BBBB WWWW BYBB BBBB = 51
  asm("ldi r25, 51                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r23                     "); // 5    2 1
  asm("st X+, r23                     "); // 6    2 2
  asm("st X+, r23                     "); // 7    2 3
  asm("st X+, r23                     "); // 8    2 4
  asm("st X+, r24                     "); // 9    3 1
  asm("st X+, r19                    ");  // 10   3 2
  asm("st X+, r24                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Set color pallet (cannot use r25, r22, r21, r20)
  asm("ldi r24, 0b00000101"); // B
  asm("ldi r23, 0b00000101"); // M
  asm("ldi r19, 0b00000110"); // H
  asm("ldi r18, 0b00000011"); // L

  // Tile 52 - BBBB BBBB BBBB BBMH = 52
  asm("ldi r25, 52                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r24                     "); // 6    2 2
  asm("st X+, r24                     "); // 7    2 3
  asm("st X+, r24                     "); // 8    2 4
  asm("st X+, r24                     "); // 9    3 1
  asm("st X+, r24                    ");  // 10   3 2
  asm("st X+, r24                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r23                    ");  // 15   4 3
  asm("st X+, r19                    ");  // 16   4 4

  // Tile 53 - BBBB BBBB BBBB MHMM = 53
  asm("ldi r25, 53                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r24                     "); // 6    2 2
  asm("st X+, r24                     "); // 7    2 3
  asm("st X+, r24                     "); // 8    2 4
  asm("st X+, r24                     "); // 9    3 1
  asm("st X+, r24                    ");  // 10   3 2
  asm("st X+, r24                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r23                    ");  // 13   4 1
  asm("st X+, r19                    ");  // 14   4 2
  asm("st X+, r23                    ");  // 15   4 3
  asm("st X+, r23                    ");  // 16   4 4

  // Tile 54 - BBBB BBBB BBMH MMMM = 54
  asm("ldi r25, 54                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r24                     "); // 6    2 2
  asm("st X+, r24                     "); // 7    2 3
  asm("st X+, r24                     "); // 8    2 4
  asm("st X+, r24                     "); // 9    3 1
  asm("st X+, r24                    ");  // 10   3 2
  asm("st X+, r23                    ");  // 11   3 3
  asm("st X+, r19                    ");  // 12   3 4
  asm("st X+, r23                    ");  // 13   4 1
  asm("st X+, r23                    ");  // 14   4 2
  asm("st X+, r23                    ");  // 15   4 3
  asm("st X+, r23                    ");  // 16   4 4

  // Tile 55 - BBBB BBBB MHMM MMLL = 55
  asm("ldi r25, 55                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r24                     "); // 6    2 2
  asm("st X+, r24                     "); // 7    2 3
  asm("st X+, r24                     "); // 8    2 4
  asm("st X+, r23                     "); // 9    3 1
  asm("st X+, r19                    ");  // 10   3 2
  asm("st X+, r23                    ");  // 11   3 3
  asm("st X+, r23                    ");  // 12   3 4
  asm("st X+, r23                    ");  // 13   4 1
  asm("st X+, r23                    ");  // 14   4 2
  asm("st X+, r18                    ");  // 15   4 3
  asm("st X+, r18                    ");  // 16   4 4

  // Tile 56 - BBBB BBMH MMMM LLBB = 56
  asm("ldi r25, 56                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r24                     "); // 6    2 2
  asm("st X+, r23                     "); // 7    2 3
  asm("st X+, r19                     "); // 8    2 4
  asm("st X+, r23                     "); // 9    3 1
  asm("st X+, r23                    ");  // 10   3 2
  asm("st X+, r23                    ");  // 11   3 3
  asm("st X+, r23                    ");  // 12   3 4
  asm("st X+, r18                    ");  // 13   4 1
  asm("st X+, r18                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 57 - BBBB MHMM MMLL BBBB = 57
  asm("ldi r25, 57                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r23                     "); // 5    2 1
  asm("st X+, r19                     "); // 6    2 2
  asm("st X+, r23                     "); // 7    2 3
  asm("st X+, r23                     "); // 8    2 4
  asm("st X+, r23                     "); // 9    3 1
  asm("st X+, r23                    ");  // 10   3 2
  asm("st X+, r18                    ");  // 11   3 3
  asm("st X+, r18                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 58 - BBMH MMMM LLBB BBBB = 58
  asm("ldi r25, 58                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r23                     "); // 3    1 3
  asm("st X+, r19                     "); // 4    1 4
  asm("st X+, r23                     "); // 5    2 1
  asm("st X+, r23                     "); // 6    2 2
  asm("st X+, r23                     "); // 7    2 3
  asm("st X+, r23                     "); // 8    2 4
  asm("st X+, r18                     "); // 9    3 1
  asm("st X+, r18                    ");  // 10   3 2
  asm("st X+, r24                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 59 - MHMM MMLL BBBB BBBB = 59
  asm("ldi r25, 59                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r23                     "); // 1    1 1
  asm("st X+, r19                     "); // 2    1 2
  asm("st X+, r23                     "); // 3    1 3
  asm("st X+, r23                     "); // 4    1 4
  asm("st X+, r23                     "); // 5    2 1
  asm("st X+, r23                     "); // 6    2 2
  asm("st X+, r18                     "); // 7    2 3
  asm("st X+, r18                     "); // 8    2 4
  asm("st X+, r24                     "); // 9    3 1
  asm("st X+, r24                    ");  // 10   3 2
  asm("st X+, r24                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 60 - MMMM LLBB BBBB BBBB = 60
  asm("ldi r25, 60                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r23                     "); // 1    1 1
  asm("st X+, r23                     "); // 2    1 2
  asm("st X+, r23                     "); // 3    1 3
  asm("st X+, r23                     "); // 4    1 4
  asm("st X+, r18                     "); // 5    2 1
  asm("st X+, r18                     "); // 6    2 2
  asm("st X+, r24                     "); // 7    2 3
  asm("st X+, r24                     "); // 8    2 4
  asm("st X+, r24                     "); // 9    3 1
  asm("st X+, r24                    ");  // 10   3 2
  asm("st X+, r24                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 61 - MMLL BBBB BBBB BBBB = 61
  asm("ldi r25, 61                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r23                     "); // 1    1 1
  asm("st X+, r23                     "); // 2    1 2
  asm("st X+, r18                     "); // 3    1 3
  asm("st X+, r18                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r24                     "); // 6    2 2
  asm("st X+, r24                     "); // 7    2 3
  asm("st X+, r24                     "); // 8    2 4
  asm("st X+, r24                     "); // 9    3 1
  asm("st X+, r24                    ");  // 10   3 2
  asm("st X+, r24                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 62 - LLBB BBBB BBBB BBBB = 62
  asm("ldi r25, 62                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r18                     "); // 1    1 1
  asm("st X+, r18                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r24                     "); // 6    2 2
  asm("st X+, r24                     "); // 7    2 3
  asm("st X+, r24                     "); // 8    2 4
  asm("st X+, r24                     "); // 9    3 1
  asm("st X+, r24                    ");  // 10   3 2
  asm("st X+, r24                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 63 - BBBB BBBB BBBB BBBM = 63
  asm("ldi r25, 63                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r24                     "); // 6    2 2
  asm("st X+, r24                     "); // 7    2 3
  asm("st X+, r24                     "); // 8    2 4
  asm("st X+, r24                     "); // 9    3 1
  asm("st X+, r24                    ");  // 10   3 2
  asm("st X+, r24                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r23                    ");  // 16   4 4

  // Tile 64 - BBBB BBBB BBBB BMHM = 64
  asm("ldi r25, 64                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r24                     "); // 6    2 2
  asm("st X+, r24                     "); // 7    2 3
  asm("st X+, r24                     "); // 8    2 4
  asm("st X+, r24                     "); // 9    3 1
  asm("st X+, r24                    ");  // 10   3 2
  asm("st X+, r24                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r23                    ");  // 14   4 2
  asm("st X+, r19                    ");  // 15   4 3
  asm("st X+, r23                    ");  // 16   4 4

  // Tile 65 - BBBB BBBB BBBM HMML = 65
  asm("ldi r25, 65                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r24                     "); // 6    2 2
  asm("st X+, r24                     "); // 7    2 3
  asm("st X+, r24                     "); // 8    2 4
  asm("st X+, r24                     "); // 9    3 1
  asm("st X+, r24                    ");  // 10   3 2
  asm("st X+, r24                    ");  // 11   3 3
  asm("st X+, r23                    ");  // 12   3 4
  asm("st X+, r19                    ");  // 13   4 1
  asm("st X+, r23                    ");  // 14   4 2
  asm("st X+, r23                    ");  // 15   4 3
  asm("st X+, r18                    ");  // 16   4 4

  // Tile 66 - BBBB BBBB BMHM MLLB = 66
  asm("ldi r25, 66                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r24                     "); // 6    2 2
  asm("st X+, r24                     "); // 7    2 3
  asm("st X+, r24                     "); // 8    2 4
  asm("st X+, r24                     "); // 9    3 1
  asm("st X+, r23                    ");  // 10   3 2
  asm("st X+, r19                    ");  // 11   3 3
  asm("st X+, r23                    ");  // 12   3 4
  asm("st X+, r23                    ");  // 13   4 1
  asm("st X+, r18                    ");  // 14   4 2
  asm("st X+, r18                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 67 - BBBB BBBM HMML LBBB = 67
  asm("ldi r25, 67                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r24                     "); // 6    2 2
  asm("st X+, r24                     "); // 7    2 3
  asm("st X+, r23                     "); // 8    2 4
  asm("st X+, r19                     "); // 9    3 1
  asm("st X+, r23                    ");  // 10   3 2
  asm("st X+, r23                    ");  // 11   3 3
  asm("st X+, r18                    ");  // 12   3 4
  asm("st X+, r18                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 68 - BBBB BMHM MLLB BBBB = 68
  asm("ldi r25, 68                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r23                     "); // 6    2 2
  asm("st X+, r19                     "); // 7    2 3
  asm("st X+, r23                     "); // 8    2 4
  asm("st X+, r23                     "); // 9    3 1
  asm("st X+, r18                    ");  // 10   3 2
  asm("st X+, r18                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 69 - BBBM HMML LBBB BBBB = 69
  asm("ldi r25, 69                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r23                     "); // 4    1 4
  asm("st X+, r19                     "); // 5    2 1
  asm("st X+, r23                     "); // 6    2 2
  asm("st X+, r23                     "); // 7    2 3
  asm("st X+, r18                     "); // 8    2 4
  asm("st X+, r18                     "); // 9    3 1
  asm("st X+, r24                    ");  // 10   3 2
  asm("st X+, r24                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 70 - BMHM MLLB BBBB BBBB = 70
  asm("ldi r25, 70                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r24                     "); // 1    1 1
  asm("st X+, r23                     "); // 2    1 2
  asm("st X+, r19                     "); // 3    1 3
  asm("st X+, r23                     "); // 4    1 4
  asm("st X+, r23                     "); // 5    2 1
  asm("st X+, r18                     "); // 6    2 2
  asm("st X+, r18                     "); // 7    2 3
  asm("st X+, r24                     "); // 8    2 4
  asm("st X+, r24                     "); // 9    3 1
  asm("st X+, r24                    ");  // 10   3 2
  asm("st X+, r24                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 71 - HMML LBBB BBBB BBBB = 71
  asm("ldi r25, 71                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r19                     "); // 1    1 1
  asm("st X+, r23                     "); // 2    1 2
  asm("st X+, r23                     "); // 3    1 3
  asm("st X+, r18                     "); // 4    1 4
  asm("st X+, r18                     "); // 5    2 1
  asm("st X+, r24                     "); // 6    2 2
  asm("st X+, r24                     "); // 7    2 3
  asm("st X+, r24                     "); // 8    2 4
  asm("st X+, r24                     "); // 9    3 1
  asm("st X+, r24                    ");  // 10   3 2
  asm("st X+, r24                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 72 - MLLB BBBB BBBB BBBB = 72
  asm("ldi r25, 72                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r23                     "); // 1    1 1
  asm("st X+, r18                     "); // 2    1 2
  asm("st X+, r18                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r24                     "); // 6    2 2
  asm("st X+, r24                     "); // 7    2 3
  asm("st X+, r24                     "); // 8    2 4
  asm("st X+, r24                     "); // 9    3 1
  asm("st X+, r24                    ");  // 10   3 2
  asm("st X+, r24                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Tile 73 - LBBB BBBB BBBB BBBB = 73
  asm("ldi r25, 73                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r18                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r24                     "); // 6    2 2
  asm("st X+, r24                     "); // 7    2 3
  asm("st X+, r24                     "); // 8    2 4
  asm("st X+, r24                     "); // 9    3 1
  asm("st X+, r24                    ");  // 10   3 2
  asm("st X+, r24                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  // Set color pallet (cannot use r25, r22, r21, r20)
  asm("ldi r24, 0b00000110"); // G

  // Tile 73 - GGGG GGGG GGGG GGGG = 74
  asm("ldi r25, 74                    ");
  asm("rcall init_tile_load           ");
  asm("st X+, r14                     "); // 1    1 1
  asm("st X+, r24                     "); // 2    1 2
  asm("st X+, r24                     "); // 3    1 3
  asm("st X+, r24                     "); // 4    1 4
  asm("st X+, r24                     "); // 5    2 1
  asm("st X+, r24                     "); // 6    2 2
  asm("st X+, r24                     "); // 7    2 3
  asm("st X+, r24                     "); // 8    2 4
  asm("st X+, r24                     "); // 9    3 1
  asm("st X+, r24                    ");  // 10   3 2
  asm("st X+, r24                    ");  // 11   3 3
  asm("st X+, r24                    ");  // 12   3 4
  asm("st X+, r24                    ");  // 13   4 1
  asm("st X+, r24                    ");  // 14   4 2
  asm("st X+, r24                    ");  // 15   4 3
  asm("st X+, r24                    ");  // 16   4 4

  asm("ret");
}
