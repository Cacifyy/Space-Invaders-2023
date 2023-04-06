        xdef    _get_video_base
        xdef    _set_video_base
        xref    super
        xref    exit_super

_get_video_base:
        
    move.l  a0,-(sp)
    clr.l   d0

    jsr     super

    lea     $FFFF8201,a0
    movep.w (a0),d0
    lsl.l   #8,d0

    jsr     exit_super

    move.l  (sp)+,a0
    rts

_set_video_base:
    link    a6,#0
    movem.l d0/a0,-(sp)

    jsr     super

    move.l  8(a6),d0
    lsr.l   #8,d0
    lea     $FFFF8201,a0
    movep.w d0,0(a0)

    jsr     exit_super

    movem.l (sp)+,d0/a0
    unlk    a6
    rts

old_ssp     ds.l    1
