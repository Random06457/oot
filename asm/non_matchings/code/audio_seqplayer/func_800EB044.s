glabel func_800EB044
/* B621E4 800EB044 AFA50004 */  sw    $a1, 4($sp)
/* B621E8 800EB048 30A500FF */  andi  $a1, $a1, 0xff
/* B621EC 800EB04C 44852000 */  mtc1  $a1, $f4
/* B621F0 800EB050 3C0142FE */  li    $at, 0x42FE0000 # 0.000000
/* B621F4 800EB054 44814000 */  mtc1  $at, $f8
/* B621F8 800EB058 468021A0 */  cvt.s.w $f6, $f4
/* B621FC 800EB05C 46083283 */  div.s $f10, $f6, $f8
/* B62200 800EB060 03E00008 */  jr    $ra
/* B62204 800EB064 E48A002C */   swc1  $f10, 0x2c($a0)

