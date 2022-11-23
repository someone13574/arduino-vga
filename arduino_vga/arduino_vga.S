; 0x60 to 0xE6 = Line data (134 pixels)
; 0xE7 to 0x5e7 = Sprite Descriptors (320, 4 per line)
; 0x5e8 to 0x85F = Sprite Data (78 sprite lines of 8 pixels)

; Sprite descriptor
; 8-bit x-pos
; 8-bit y-pos
; 16-bit data-address

; Sprite data
; 8x color-data

; Color data
; 3-bit red-channel
; 3-bit green-channel
; 2-bit blue-channel

; r26-27 X
; r28-29 Y
; r30-31 Z
; r16 = line index

.global main
main:
    rcall init
    rjmp start_of_frame

init:
  ; Init line data
  ldi r25, 0b11111111;
  ;ldi XL, lo8(0x60)
  ;ldi XH, hi8(0x60)
  ;init_line_data:
  ;  st X+, r25
  ;  cpi XL, 0xe7
  ;  brbc 1, init_line_data

  ldi r24, 134
  init_line_data:
    ldi XL, lo8(0x60)
    ldi XH, 0
    add XL, r24
    st X, r25
    dec r24
    brne init_line_data

  ; Clear XYZ registers
  ldi XL, 0
  ldi XH, 0
  ldi YL, 0
  ldi YH, 0
  ldi ZL, 0
  ldi ZH, 0

  ; Set required pins as outputs
  ldi r16, 0b11111100 ; color pins
  ldi r17, 0b00000111 ; sync pins
  out 0x0a, r16
  out 0x04, r17
    
  ret

start_of_frame:
  ; Visible area lines
  ldi r16, 80
  visible_area_line_loop:
    rcall visible_line
    rcall visible_line
    rcall visible_line
    rcall visible_line
    rcall visible_line
    rcall visible_line
    dec r16
    brne visible_area_line_loop

  ; Front porch
  ldi r16, 10
  front_porch_line_loop:
    rcall vertical_blanking_line
    dec r16
    brne front_porch_line_loop

  ; Sync pulse
  rcall vertical_sync_line
  rcall vertical_sync_line
  ldi r25, 0b00000101
  out 0x05, r25

  ; Back porch
  ldi r16, 33
  back_porch_line_loop:
    rcall vertical_blanking_line
    dec r16
    brne back_porch_line_loop
  
  ; return to start of frame
  wdr
  jmp start_of_frame

load_line:
  ; X = Current descriptor address
  ; r24 = x-pos
  ; r25 = y-pos
  ; Y = Sprite data address
  ; r23 = color data
  ; r22 = burn cycles
  ; r21 = compare
  
  ; Visible area and front porch available for use 416.9215488 cycles
  ldi r22, 4

  ldi XL, lo8(0x5e4)
  ldi XH, hi8(0x5e4)

  test_sprite_descriptors:
    ld r25, X       ; Read y
    cp r25, r16     ; Test if y is equal to current line
    brbs 1, add_sprite  ; Jump if y is equal to current line
  
    sbiw X, 4
    mov r21, XL
    and r21, XH
    cpi r21, 0xe4     ; set r21 == k
    brbc 1, test_sprite_descriptors
    rjmp load_line_burn

  add_sprite: // 54 continue, 55 exit
    ld r24, -X         ; 1     read x
    adiw X, 2           ; 1    offset to data address
    ld YL, X+          ; 1     read data address
    ld YH, X+          ; 1

    ldi ZL, 0x60        ; 1    
    add ZL, r24         ; 1

    ld r23, Y+          ; 3
    st Z+, r23          ; 2
    ld r23, Y+          ; 3
    st Z+, r23          ; 2
    ld r23, Y+          ; 3
    st Z+, r23          ; 2
    ld r23, Y+          ; 3
    st Z+, r23          ; 2
    ld r23, Y+          ; 3
    st Z+, r23          ; 2
    ld r23, Y+          ; 3
    st Z+, r23          ; 2
    ld r23, Y+          ; 3
    st Z+, r23          ; 2
    ld r23, Y+          ; 3
    st Z+, r23          ; 2

    dec r22             ; 1
    sbiw X, 7           ; 2

    mov r21, XL         ; 1
    and r21, XH         ; 1
    cpi r21, 0xe4        ; 1
    brbc 0, test_sprite_descriptors        ; 2 / 1
    rjmp load_line_burn                    ; 2

  load_line_burn:
    dec r22
    brne load_line_burn

  ldi r25, 0b00000100

  ; Sync pulse 61.0129096326 cycles        (61)
  out 0x05, r25                  ; 1
  ldi r25, 18                    ; 1
  ldi r24, 0b00000101            ; resolve state 1
  load_line_sync_pulse:
    dec r25                      ; 1
    brne load_line_sync_pulse    ; 2 / 1
  nop                            ; 1
  nop                            ; 1
  out 0x05, r24                     ; 1

  ; Back porch    30.5064548163 cycles 
  ldi r25, 7                       ; 1
  load_line_back_porch:
    dec r25                        ; 1
    brne load_line_back_porch      ; 2 / 1
  nop

  ret
    
visible_line:
  ; Visible area (407)
  lds r25, 0x60 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x61 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x62 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x63 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x64 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x65 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x66 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x67 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x68 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x69 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x6a ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x6b ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x6c ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x6d ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x6e ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x6f ; 2
  out 0x0b, r25 ; 1

  lds r25, 0x70 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x71 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x72 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x73 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x74 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x75 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x76 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x77 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x78 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x79 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x7a ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x7b ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x7c ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x7d ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x7e ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x7f ; 2
  out 0x0b, r25 ; 1

  lds r25, 0x80 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x81 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x82 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x83 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x84 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x85 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x86 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x87 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x88 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x89 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x8a ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x8b ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x8c ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x8d ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x8e ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x8f ; 2
  out 0x0b, r25 ; 1

  lds r25, 0x90 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x91 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x92 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x93 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x94 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x95 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x96 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x97 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x98 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x99 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x9a ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x9b ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x9c ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x9d ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x9e ; 2
  out 0x0b, r25 ; 1
  lds r25, 0x9f ; 2
  out 0x0b, r25 ; 1

  lds r25, 0xa0 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xa1 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xa2 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xa3 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xa4 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xa5 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xa6 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xa7 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xa8 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xa9 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xaa ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xab ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xac ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xad ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xae ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xaf ; 2
  out 0x0b, r25 ; 1

  lds r25, 0xb0 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xb1 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xb2 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xb3 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xb4 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xb5 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xb6 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xb7 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xb8 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xb9 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xba ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xbb ; 2
  out 0x0b, r25 ; 1  
  lds r25, 0xbc ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xbd ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xbe ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xbf ; 2
  out 0x0b, r25 ; 1

  lds r25, 0xc0 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xc1 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xc2 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xc3 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xc4 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xc5 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xc6 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xc7 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xc8 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xc9 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xca ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xcb ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xcc ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xcd ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xce ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xcf ; 2
  out 0x0b, r25 ; 1

  lds r25, 0xd0 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xd1 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xd2 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xd3 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xd4 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xd5 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xd6 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xd7 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xd8 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xd9 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xda ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xdb ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xdc ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xdd ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xde ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xdf ; 2
  out 0x0b, r25 ; 1

  lds r25, 0xe0 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xe1 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xe2 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xe3 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xe4 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xe5 ; 2
  out 0x0b, r25 ; 1
  lds r25, 0xe6 ; 2
  out 0x0b, r25 ; 1

  nop
  nop
  nop
  nop
  ldi r25, 0b00000000

  ; Front porch 10.1688182721 (10)
  out 0x0b, r25
  ldi r25, 2
  visible_line_front_porch:
    dec r25
    brne visible_line_front_porch
  ldi r25, 0b00000100
  
  ; Sync pulse 61.0129096326 cycles        (61)
  out 0x05, r25                     ; 1
  ldi r25, 18                       ; 1
  ldi r24, 0b00000101               ; resolve state 1
  visible_line_sync_pulse:
    dec r25                         ; 1
    brne visible_line_sync_pulse    ; 2 / 1
  nop                               ; 1
  nop                               ; 1
  out 0x05, r24                     ; 1

  ; Back porch    30.5064548163 cycles  (31)
  ldi r25, 7                           ; 1
  visible_line_back_porch:
    dec r25                            ; 1
    brne visible_line_back_porch       ; 2 / 1
  nop                                  ; 1

  ret

vertical_blanking_line:
  ; Visible area and front porch       416.921549156 cycles
  ldi r25, 138
  vertical_blanking_line_visible_area_and_front_porch:
    dec r25
    brne vertical_blanking_line_visible_area_and_front_porch
  ldi r25, 0b00000100
  nop

  ; Sync pulse 61.0129096326 cycles        (61)
  out 0x05, r25                     ; 1
  ldi r25, 18                       ; 1
  ldi r24, 0b00000101               ; resolve state 1
  vertical_blanking_line_sync_pulse:
    dec r25                         ; 1
    brne vertical_blanking_line_sync_pulse    ; 2 / 1
  nop                               ; 1
  nop                               ; 1
  out 0x05, r24                     ; 1

  ; Back porch    30.5064548163 cycles  (31)
  ldi r25, 7                           ; 1
  vertical_blanking_line_back_porch:
    dec r25                            ; 1
    brne vertical_blanking_line_back_porch       ; 2 / 1
  nop                                  ; 1

  ret

vertical_sync_line:
  ; Visible area and front porch
  ldi r25, 0b00000001
  out 0x05, r25
  ldi r25, 137
  vertical_sync_line_visible_area_and_front_porch:
    dec r25
    brne vertical_sync_line_visible_area_and_front_porch
  ldi r25, 0b00000000
  nop
  nop

  ; Sync pulse 61.0129096326 cycles        (61)
  out 0x05, r25                     ; 1
  ldi r25, 18                       ; 1
  ldi r24, 0b00000001               ; resolve state 1
  vertical_sync_line_sync_pulse:
    dec r25                         ; 1
    brne vertical_sync_line_sync_pulse    ; 2 / 1
  nop                               ; 1
  nop                               ; 1
  out 0x05, r24                     ; 1

  ; Back porch    30.5064548163 cycles  (31)
  ldi r25, 7                           ; 1
  vertical_sync_line_back_porch:
    dec r25                            ; 1
    brne vertical_sync_line_back_porch       ; 2 / 1
  nop                                  ; 1

  ret
