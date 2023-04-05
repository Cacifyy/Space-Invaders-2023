; The GEMDOS call $20 (Page 161 of the Devpac manual) can be used to change
; the processor from user mode to supervisor mode, and then back again. 
; When switching modes, the first parameter is either the value of a new 
; system stack pointer, or 0 if you want to use the same stack after the
; switch.  When switching to supervisor mode, the old system stack 
; pointer is returned in D0

        xdef    _get_video_base 

_get_video_base:
	nop

	move.l		a0,-(sp)

	move.l		$462,d0		; read the vb clock
	
	clr.l		-(sp)		; set up GEMDOS call to enter supervisor
	move.w		#$20,-(sp)	;   mode and to use the user stack
	trap		#1		;   until toggling back to user mode
	addq.l		#6,sp		; clean up stack
	move.l		d0,old_ssp	; save old system stack pointer

	lea			$FFFF8201,a0
	movep.w		(a0),d0
	lsl.l		#8,d0

_super:

	move.l		old_ssp(pc),-(sp)	; return to user mode, restoring
	move.w		#$20,-(sp)		;   system stack pointer
	trap		#1
	addq.l		#6,sp

	move.w	#0,-(sp)	; return to caller
	move.w	#$4C,-(sp)
	trap	#1
	rts



old_ssp:	ds.l	1		; SSP save area

	end	start
