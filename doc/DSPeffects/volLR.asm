	name  "volLR"
	

	include "emu_constants.asm"

AvolLR   control  #1,0,#1
CaptureSynth control 4,1,10	

inl	IO
inr     IO
inl1    IO
inr1    IO

outl	equ	inl
outr    equ     inr
outl1   equ     inl1
outr1   equ     inr1

	macs	outl,inl.o,inl,AvolLR
        macs    outr,inr.o,inr,AvolLR
        

	macints	outl1,outl,outl,CaptureSynth
        macints outr1,outr,outl,CaptureSynth
        

	end
	
	
