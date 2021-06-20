; this sample shows how to access virtual ports (0 to 0FFFFh).
; these ports are emulated in this file: c:\emu8086.io

; this new technology allows to make external add-on devices
; for emu8086, such as led displays, thermostat, stepper-motor, etc...

; "devices" folder contains sample device that works with this sample.
; (with visual basic source code).

#start=simple.exe#

#make_bin#

name "simple"          


mov al, 00h	;PORT1 

out 110, al

mov ax, 03h	;PORT2

out 112, ax

in al, 110 	;PORT1'den verinin okunmasi

x1:   		;Gelen degerin birer birer sayilip PORT2 de gosterilmesi
out 112, al

inc al

jmp x1 

hlt


