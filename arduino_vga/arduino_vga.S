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
    call init
    rjmp start_of_frame

init:
  ; Clear XYZ
  ldi XL, 0
  ldi XH, 0
  ldi YL, 0
  ldi YH, 0
  ldi ZL, 0
  ldi ZH, 0

  ; Set required pins as outputs
  ldi r16, 0b11111111 ; color pins
  ldi r17, 0b00000011 ; sync pins
  out 0x0a, r16
  out 0x04, r17
    
  ret

start_of_frame:
  ; Visible area lines
  ldi r16, 80
  visible_area_line_loop:
    call load_line
    call visible_line
    call visible_line
    call visible_line
    call visible_line
    dec r16
    brne visible_area_line_loop
  
  ; return to start of frame
  wdr
  jmp start_of_frame

load_line:
  ; X = Current descriptor address
  ; r24 = x-pos
  ; r25 = y-pos
  ; Y = Sprite data address
  ; r23 = color data
  
  ; Visible area and front porch available for use 416.9215488 cycles
  ldi XL, 0x61

  test_sprite_descriptors:
    ld r25, X
    cp r25, r16
    brbs 1, add_sprite
  
    adiw X, 4
    cpi XL, 0x95
    brbs 0, test_sprite_descriptors
    rjmp load_line_sync

  add_sprite:
    ldi r24, -X         ; 1
    adiw X, 2           ; 1
    ldi YL, X+          ; 1
    ldi YH, X+          ; 1

    ldi ZL, 0x95        ; 1
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

  load_line_sync:
    
visible_line:
