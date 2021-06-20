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
mov ax, 03h    	;PORT2 
out 112, ax    
in ax,112     	;PORT2'deki ax degeri bx'e kopyalandi
mov bx, ax    	
in al, 110    	;PORT1 degeri PORT2 cikisi 112 de cikti
out 112, al   
mov ax, bx    	;bx yine ax'e atandi
out 110, ax   	;PORT2 degeri PORT1 cikisi 110'da cikti
hlt


