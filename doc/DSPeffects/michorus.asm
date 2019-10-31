
;;; Simple Chorus
;;; Author:Daniel Bertrand
;;; Date: Oct 12, 2000

;;; This program is free software; you can redistribute it and/or modify  
;;; it under the terms of the GNU General Public License as published by  
;;; the Free Software Foundation; either version 2 of the License, or     
;;; (at your option) any later version.

;;; References:	
;;; http://www.harmony-central.com/Effects/Articles/Chorus

			
;;;  speed(formerly "delta")=2*pi*freq/48000
;;;  this give us our delta value for a specific freq (0.1-0.3Hz is good)
		

	include "emu_constants.asm"
	name "Chorus"
		
in	IO
in1     IO
outl	equ in
outr	equ in1

	
	
CHspeed	  control  1e-05 , 0 , 1e-4 	; Controls frequency (radians)
CHrelative control #.86, 0, #1
CHdelayL   control  &15e-3  ,&1e-3 , &90e-3; twice (2*) average delay (sec)
CHdelayR  control  &72e-3  ,&1e-3  ,&90e-3;
CHwidth	  control  #0.99   ,0.1	 ,#0.99 ; width control 

;; sine generator storage spaces:	
sinx  sta  0	
cosx  sta  #0.51
			
tmp  dyn 	
tmp1 dyn
tmp2 dyn
tmp3 dyn
chtmp dyn	
;;; Two Delay Lines:	
	
	
dly   delay  &90e-3		;10msec delay line
	
write	twrite dly,0		; tram writes
writeb  twrite dly,0
ready	tread dly,0		; tram reads
readyb  tread dly,0
reada   tread dly,0
readab  tread  dly,0
				
;;;The code:	
	
		
;;; two opcode sinewave generator (I love this chip!):
	macs  sinx,sinx,CHspeed,cosx
	macs1 cosx,cosx,CHspeed,sinx 

;;; 0.5Asint+0.5:	
	macs tmp,C_2^30,sinx,CHwidth
	
;;; calculate address:
        
        macs  chtmp,C_4,C_256,CHrelative 

	macs  ready.a,write.a,CHdelayL,tmp
        macs  readyb.a,writeb.a,CHdelayR,tmp
;second addresses for interpolation:
;(interesting how the emu engineers decided that $800 wasn't a needed value) 
	macints reada.a,ready.a,C_8,chtmp
        macints readab.a,readyb.a,C_8,chtmp
	
;;; Write to the delay line:
	
	macs  write,C_0,in,C_2^30
       	macs  writeb,C_0,in1,C_2^30
		
	
;;; output values:		
;;; 0x55 is 00100000 (?)

	macints tmp,C_0,reada.a,C_LSshift; get least significant part of address
	macints tmp1,C_0,readab.a,C_LSshift

	interp tmp2,ready,tmp,reada ;interpolate in-between the two delay line readings
	interp tmp3,readyb,tmp1,readab

	acc3  outl,tmp2,tmp2,tmp2
	acc3  outr,tmp3,tmp3,tmp3

	
	end





