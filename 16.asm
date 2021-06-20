; this sample shows how to access virtual ports (0 to 0FFFFh).
; these ports are emulated in this file: c:\emu8086.io

; this new technology allows to make external add-on devices
; for emu8086, such as led displays, thermostat, stepper-motor, etc...

; "devices" folder contains sample device that works with this sample.
; (with visual basic source code).

#start=simple.exe#

#make_bin#

name "simple"          

mov al, 00h 	;PORT1    
out 88h, al    	;Kontrol kaydedisi tamamen giris 00H 		     
mov ax, 00h    	;PORT2
out 86h, ax  	;Mode kaydedici tamamen giris 00H               
in ax, 112     	;ax degerini okuyup bx'e kopyaladik
mov bx, ax     
in al, 110     	;PORT de okunan al degerini PORT2 cikisi 112'de yazdirildi
out 112, al    	
mov ax, bx     	;bx'e kopyalanan degeri ax'e verip PORT1 cikisi 110'a yazdirildi               
out 110, ax    
hlt


