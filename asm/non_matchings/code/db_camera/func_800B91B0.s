glabel func_800B91B0
/* B30350 800B91B0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* B30354 800B91B4 AFB00020 */  sw    $s0, 0x20($sp)
/* B30358 800B91B8 3C108016 */  lui   $s0, %hi(D_8016110C) # $s0, 0x8016
/* B3035C 800B91BC 2610110C */  addiu $s0, %lo(D_8016110C) # addiu $s0, $s0, 0x110c
/* B30360 800B91C0 86030000 */  lh    $v1, ($s0)
/* B30364 800B91C4 AFB20028 */  sw    $s2, 0x28($sp)
/* B30368 800B91C8 3C128016 */  lui   $s2, %hi(D_80161150)
/* B3036C 800B91CC 26521150 */  addiu $s2, %lo(D_80161150) # addiu $s2, $s2, 0x1150
/* B30370 800B91D0 00037100 */  sll   $t6, $v1, 4
/* B30374 800B91D4 024E1021 */  addu  $v0, $s2, $t6
/* B30378 800B91D8 904F0000 */  lbu   $t7, ($v0)
/* B3037C 800B91DC 2406003F */  li    $a2, 63
/* B30380 800B91E0 AFBF002C */  sw    $ra, 0x2c($sp)
/* B30384 800B91E4 AFB10024 */  sw    $s1, 0x24($sp)
/* B30388 800B91E8 AFA40030 */  sw    $a0, 0x30($sp)
/* B3038C 800B91EC 14CF0016 */  bne   $a2, $t7, .L800B9248
/* B30390 800B91F0 AFA50034 */   sw    $a1, 0x34($sp)
/* B30394 800B91F4 24780001 */  addiu $t8, $v1, 1
.L800B91F8:
/* B30398 800B91F8 A6180000 */  sh    $t8, ($s0)
/* B3039C 800B91FC 86030000 */  lh    $v1, ($s0)
/* B303A0 800B9200 3C118016 */  lui   $s1, %hi(D_80161110)
/* B303A4 800B9204 26311110 */  addiu $s1, %lo(D_80161110) # addiu $s1, $s1, 0x1110
/* B303A8 800B9208 2861000F */  slti  $at, $v1, 0xf
/* B303AC 800B920C 14200009 */  bnez  $at, .L800B9234
/* B303B0 800B9210 00001025 */   move  $v0, $zero
/* B303B4 800B9214 44802000 */  mtc1  $zero, $f4
/* B303B8 800B9218 44803000 */  mtc1  $zero, $f6
/* B303BC 800B921C A6200008 */  sh    $zero, 8($s1)
/* B303C0 800B9220 A620000A */  sh    $zero, 0xa($s1)
/* B303C4 800B9224 A6000000 */  sh    $zero, ($s0)
/* B303C8 800B9228 E6240000 */  swc1  $f4, ($s1)
/* B303CC 800B922C 100000D1 */  b     .L800B9574
/* B303D0 800B9230 E6260004 */   swc1  $f6, 4($s1)
.L800B9234:
/* B303D4 800B9234 0003C900 */  sll   $t9, $v1, 4
/* B303D8 800B9238 02591021 */  addu  $v0, $s2, $t9
/* B303DC 800B923C 90490000 */  lbu   $t1, ($v0)
/* B303E0 800B9240 50C9FFED */  beql  $a2, $t1, .L800B91F8
/* B303E4 800B9244 24780001 */   addiu $t8, $v1, 1
.L800B9248:
/* B303E8 800B9248 3C118016 */  lui   $s1, %hi(D_80161110) # $s1, 0x8016
/* B303EC 800B924C 3C0A8016 */  lui   $t2, %hi(D_80161118) # $t2, 0x8016
/* B303F0 800B9250 26311110 */  addiu $s1, %lo(D_80161110) # addiu $s1, $s1, 0x1110
/* B303F4 800B9254 254A1118 */  addiu $t2, %lo(D_80161118) # addiu $t2, $t2, 0x1118
/* B303F8 800B9258 3C048016 */  lui   $a0, %hi(D_80161120) # $a0, 0x8016
/* B303FC 800B925C 3C058016 */  lui   $a1, %hi(D_80161138) # $a1, 0x8016
/* B30400 800B9260 3C068016 */  lui   $a2, %hi(D_8016113C) # $a2, 0x8016
/* B30404 800B9264 24C6113C */  addiu $a2, %lo(D_8016113C) # addiu $a2, $a2, 0x113c
/* B30408 800B9268 24A51138 */  addiu $a1, %lo(D_80161138) # addiu $a1, $a1, 0x1138
/* B3040C 800B926C 24841120 */  addiu $a0, %lo(D_80161120) # addiu $a0, $a0, 0x1120
/* B30410 800B9270 AFAA0010 */  sw    $t2, 0x10($sp)
/* B30414 800B9274 AFB10014 */  sw    $s1, 0x14($sp)
/* B30418 800B9278 0C02ECAD */  jal   func_800BB2B4
/* B3041C 800B927C 8C470004 */   lw    $a3, 4($v0)
/* B30420 800B9280 144000AC */  bnez  $v0, .L800B9534
/* B30424 800B9284 3C048016 */   lui   $a0, %hi(D_8016112C) # $a0, 0x8016
/* B30428 800B9288 860B0000 */  lh    $t3, ($s0)
/* B3042C 800B928C 3C0E8016 */  lui   $t6, %hi(D_80161118) # $t6, 0x8016
/* B30430 800B9290 25CE1118 */  addiu $t6, %lo(D_80161118) # addiu $t6, $t6, 0x1118
/* B30434 800B9294 000B6100 */  sll   $t4, $t3, 4
/* B30438 800B9298 024C6821 */  addu  $t5, $s2, $t4
/* B3043C 800B929C 8DA70008 */  lw    $a3, 8($t5)
/* B30440 800B92A0 3C058016 */  lui   $a1, %hi(D_80161138) # $a1, 0x8016
/* B30444 800B92A4 3C068016 */  lui   $a2, %hi(D_8016113C) # $a2, 0x8016
/* B30448 800B92A8 24C6113C */  addiu $a2, %lo(D_8016113C) # addiu $a2, $a2, 0x113c
/* B3044C 800B92AC 24A51138 */  addiu $a1, %lo(D_80161138) # addiu $a1, $a1, 0x1138
/* B30450 800B92B0 AFB10014 */  sw    $s1, 0x14($sp)
/* B30454 800B92B4 AFAE0010 */  sw    $t6, 0x10($sp)
/* B30458 800B92B8 0C02ECAD */  jal   func_800BB2B4
/* B3045C 800B92BC 2484112C */   addiu $a0, %lo(D_8016112C) # addiu $a0, $a0, 0x112c
/* B30460 800B92C0 1440009C */  bnez  $v0, .L800B9534
/* B30464 800B92C4 2407000A */   li    $a3, 10
/* B30468 800B92C8 86220008 */  lh    $v0, 8($s1)
/* B3046C 800B92CC 860A0000 */  lh    $t2, ($s0)
/* B30470 800B92D0 C6280004 */  lwc1  $f8, 4($s1)
/* B30474 800B92D4 24420001 */  addiu $v0, $v0, 1
/* B30478 800B92D8 0047001A */  div   $zero, $v0, $a3
/* B3047C 800B92DC 000A5900 */  sll   $t3, $t2, 4
/* B30480 800B92E0 024B6021 */  addu  $t4, $s2, $t3
/* B30484 800B92E4 8583000E */  lh    $v1, 0xe($t4)
/* B30488 800B92E8 00007812 */  mflo  $t7
/* B3048C 800B92EC 0000C810 */  mfhi  $t9
/* B30490 800B92F0 2463FFFB */  addiu $v1, $v1, -5
/* B30494 800B92F4 4600428D */  trunc.w.s $f10, $f8
/* B30498 800B92F8 0067001A */  div   $zero, $v1, $a3
/* B3049C 800B92FC 44045000 */  mfc1  $a0, $f10
/* B304A0 800B9300 3C088013 */  lui   $t0, %hi(D_8012D13C) # $t0, 0x8013
/* B304A4 800B9304 25F80030 */  addiu $t8, $t7, 0x30
/* B304A8 800B9308 2508D13C */  addiu $t0, %lo(D_8012D13C) # addiu $t0, $t0, -0x2ec4
/* B304AC 800B930C 14E00002 */  bnez  $a3, .L800B9318
/* B304B0 800B9310 00000000 */   nop   
/* B304B4 800B9314 0007000D */  break 7
.L800B9318:
/* B304B8 800B9318 2401FFFF */  li    $at, -1
/* B304BC 800B931C 14E10004 */  bne   $a3, $at, .L800B9330
/* B304C0 800B9320 3C018000 */   lui   $at, 0x8000
/* B304C4 800B9324 14410002 */  bne   $v0, $at, .L800B9330
/* B304C8 800B9328 00000000 */   nop   
/* B304CC 800B932C 0006000D */  break 6
.L800B9330:
/* B304D0 800B9330 A1180007 */  sb    $t8, 7($t0)
/* B304D4 800B9334 00006812 */  mflo  $t5
/* B304D8 800B9338 00007810 */  mfhi  $t7
/* B304DC 800B933C 27290030 */  addiu $t1, $t9, 0x30
/* B304E0 800B9340 25AE0030 */  addiu $t6, $t5, 0x30
/* B304E4 800B9344 25F80030 */  addiu $t8, $t7, 0x30
/* B304E8 800B9348 3C058013 */  lui   $a1, %hi(D_8012D114+0xA) # $a1, 0x8013
/* B304EC 800B934C 00042400 */  sll   $a0, $a0, 0x10
/* B304F0 800B9350 A1090008 */  sb    $t1, 8($t0)
/* B304F4 800B9354 14E00002 */  bnez  $a3, .L800B9360
/* B304F8 800B9358 00000000 */   nop   
/* B304FC 800B935C 0007000D */  break 7
.L800B9360:
/* B30500 800B9360 2401FFFF */  li    $at, -1
/* B30504 800B9364 14E10004 */  bne   $a3, $at, .L800B9378
/* B30508 800B9368 3C018000 */   lui   $at, 0x8000
/* B3050C 800B936C 14610002 */  bne   $v1, $at, .L800B9378
/* B30510 800B9370 00000000 */   nop   
/* B30514 800B9374 0006000D */  break 6
.L800B9378:
/* B30518 800B9378 A10E000A */  sb    $t6, 0xa($t0)
/* B3051C 800B937C A118000B */  sb    $t8, 0xb($t0)
/* B30520 800B9380 00042403 */  sra   $a0, $a0, 0x10
/* B30524 800B9384 24A5D11E */  addiu $a1, %lo(D_8012D114+0xA) # addiu $a1, $a1, -0x2ee2
/* B30528 800B9388 0C02CF7E */  jal   func_800B3DF8
/* B3052C 800B938C 24060004 */   li    $a2, 4
/* B30530 800B9390 3C078013 */  lui   $a3, %hi(D_8012D114) # $a3, 0x8013
/* B30534 800B9394 24E7D114 */  addiu $a3, %lo(D_8012D114) # addiu $a3, $a3, -0x2eec
/* B30538 800B9398 2404000F */  li    $a0, 15
/* B3053C 800B939C 24050016 */  li    $a1, 22
/* B30540 800B93A0 0C018DDB */  jal   func_8006376C
/* B30544 800B93A4 24060003 */   li    $a2, 3
/* B30548 800B93A8 3C058013 */  lui   $a1, %hi(D_8012D128+0xA) # $a1, 0x8013
/* B3054C 800B93AC 24A5D132 */  addiu $a1, %lo(D_8012D128+0xA) # addiu $a1, $a1, -0x2ece
/* B30550 800B93B0 8624000C */  lh    $a0, 0xc($s1)
/* B30554 800B93B4 0C02CF7E */  jal   func_800B3DF8
/* B30558 800B93B8 24060004 */   li    $a2, 4
/* B3055C 800B93BC 3C078013 */  lui   $a3, %hi(D_8012D128) # $a3, 0x8013
/* B30560 800B93C0 24E7D128 */  addiu $a3, %lo(D_8012D128) # addiu $a3, $a3, -0x2ed8
/* B30564 800B93C4 2404000F */  li    $a0, 15
/* B30568 800B93C8 24050017 */  li    $a1, 23
/* B3056C 800B93CC 0C018DDB */  jal   func_8006376C
/* B30570 800B93D0 24060003 */   li    $a2, 3
/* B30574 800B93D4 3C078013 */  lui   $a3, %hi(D_8012D13C)
/* B30578 800B93D8 24E7D13C */  addiu $a3, %lo(D_8012D13C) # addiu $a3, $a3, -0x2ec4
/* B3057C 800B93DC 2404000F */  li    $a0, 15
/* B30580 800B93E0 24050018 */  li    $a1, 24
/* B30584 800B93E4 0C018DDB */  jal   func_8006376C
/* B30588 800B93E8 24060003 */   li    $a2, 3
/* B3058C 800B93EC 3C078013 */  lui   $a3, %hi(D_8012CEF0)
/* B30590 800B93F0 8CE7CEF0 */  lw    $a3, %lo(D_8012CEF0)($a3)
/* B30594 800B93F4 24040010 */  li    $a0, 16
/* B30598 800B93F8 2405001A */  li    $a1, 26
/* B3059C 800B93FC 0C018DDB */  jal   func_8006376C
/* B305A0 800B9400 24060001 */   li    $a2, 1
/* B305A4 800B9404 86030000 */  lh    $v1, ($s0)
/* B305A8 800B9408 3C013F80 */  li    $at, 0x3F800000 # 0.000000
/* B305AC 800B940C 44819000 */  mtc1  $at, $f18
/* B305B0 800B9410 C6300004 */  lwc1  $f16, 4($s1)
/* B305B4 800B9414 00035900 */  sll   $t3, $v1, 4
/* B305B8 800B9418 8629000C */  lh    $t1, 0xc($s1)
/* B305BC 800B941C 024B1021 */  addu  $v0, $s2, $t3
/* B305C0 800B9420 46128100 */  add.s $f4, $f16, $f18
/* B305C4 800B9424 8444000C */  lh    $a0, 0xc($v0)
/* B305C8 800B9428 252A0001 */  addiu $t2, $t1, 1
/* B305CC 800B942C A62A000C */  sh    $t2, 0xc($s1)
/* B305D0 800B9430 18800012 */  blez  $a0, .L800B947C
/* B305D4 800B9434 E6240004 */   swc1  $f4, 4($s1)
/* B305D8 800B9438 44843000 */  mtc1  $a0, $f6
/* B305DC 800B943C C62A0004 */  lwc1  $f10, 4($s1)
/* B305E0 800B9440 246C0001 */  addiu $t4, $v1, 1
/* B305E4 800B9444 46803220 */  cvt.s.w $f8, $f6
/* B305E8 800B9448 460A403C */  c.lt.s $f8, $f10
/* B305EC 800B944C 00000000 */  nop   
/* B305F0 800B9450 4502000B */  bc1fl .L800B9480
/* B305F4 800B9454 844D0002 */   lh    $t5, 2($v0)
/* B305F8 800B9458 A60C0000 */  sh    $t4, ($s0)
/* B305FC 800B945C 44808000 */  mtc1  $zero, $f16
/* B30600 800B9460 44809000 */  mtc1  $zero, $f18
/* B30604 800B9464 86020000 */  lh    $v0, ($s0)
/* B30608 800B9468 A6200008 */  sh    $zero, 8($s1)
/* B3060C 800B946C E6300000 */  swc1  $f16, ($s1)
/* B30610 800B9470 E6320004 */  swc1  $f18, 4($s1)
/* B30614 800B9474 1000003F */  b     .L800B9574
/* B30618 800B9478 34428000 */   ori   $v0, $v0, 0x8000
.L800B947C:
/* B3061C 800B947C 844D0002 */  lh    $t5, 2($v0)
.L800B9480:
/* B30620 800B9480 24010001 */  li    $at, 1
/* B30624 800B9484 51A1000E */  beql  $t5, $at, .L800B94C0
/* B30628 800B9488 8FB00030 */   lw    $s0, 0x30($sp)
/* B3062C 800B948C 8FA50034 */  lw    $a1, 0x34($sp)
/* B30630 800B9490 3C048016 */  lui   $a0, %hi(D_80161120) # $a0, 0x8016
/* B30634 800B9494 24841120 */  addiu $a0, %lo(D_80161120) # addiu $a0, $a0, 0x1120
/* B30638 800B9498 0C02CFCE */  jal   func_800B3F38
/* B3063C 800B949C 24A50010 */   addiu $a1, $a1, 0x10
/* B30640 800B94A0 8FA50034 */  lw    $a1, 0x34($sp)
/* B30644 800B94A4 3C048016 */  lui   $a0, %hi(D_8016112C) # $a0, 0x8016
/* B30648 800B94A8 2484112C */  addiu $a0, %lo(D_8016112C) # addiu $a0, $a0, 0x112c
/* B3064C 800B94AC 0C02CFCE */  jal   func_800B3F38
/* B30650 800B94B0 24A50004 */   addiu $a1, $a1, 4
/* B30654 800B94B4 10000010 */  b     .L800B94F8
/* B30658 800B94B8 8FA20034 */   lw    $v0, 0x34($sp)
/* B3065C 800B94BC 8FB00030 */  lw    $s0, 0x30($sp)
.L800B94C0:
/* B30660 800B94C0 8FA60034 */  lw    $a2, 0x34($sp)
/* B30664 800B94C4 3C058016 */  lui   $a1, %hi(D_8016112C) # $a1, 0x8016
/* B30668 800B94C8 26100094 */  addiu $s0, $s0, 0x94
/* B3066C 800B94CC 02002025 */  move  $a0, $s0
/* B30670 800B94D0 24A5112C */  addiu $a1, %lo(D_8016112C) # addiu $a1, $a1, 0x112c
/* B30674 800B94D4 0C02CFFD */  jal   func_800B3FF4
/* B30678 800B94D8 24C60004 */   addiu $a2, $a2, 4
/* B3067C 800B94DC 8FA60034 */  lw    $a2, 0x34($sp)
/* B30680 800B94E0 3C058016 */  lui   $a1, %hi(D_80161120)
/* B30684 800B94E4 24A51120 */  addiu $a1, %lo(D_80161120) # addiu $a1, $a1, 0x1120
/* B30688 800B94E8 02002025 */  move  $a0, $s0
/* B3068C 800B94EC 0C02CFFD */  jal   func_800B3FF4
/* B30690 800B94F0 24C60010 */   addiu $a2, $a2, 0x10
/* B30694 800B94F4 8FA20034 */  lw    $v0, 0x34($sp)
.L800B94F8:
/* B30698 800B94F8 C624002C */  lwc1  $f4, 0x2c($s1)
/* B3069C 800B94FC 3C013FB4 */  li    $at, 0x3FB40000 # 0.000000
/* B306A0 800B9500 44818000 */  mtc1  $at, $f16
/* B306A4 800B9504 E4440048 */  swc1  $f4, 0x48($v0)
/* B306A8 800B9508 C6260028 */  lwc1  $f6, 0x28($s1)
/* B306AC 800B950C 3C038016 */  lui   $v1, %hi(D_8016110C)
/* B306B0 800B9510 4600320D */  trunc.w.s $f8, $f6
/* B306B4 800B9514 440F4000 */  mfc1  $t7, $f8
/* B306B8 800B9518 00000000 */  nop   
/* B306BC 800B951C A44F004C */  sh    $t7, 0x4c($v0)
/* B306C0 800B9520 C62A0028 */  lwc1  $f10, 0x28($s1)
/* B306C4 800B9524 46105482 */  mul.s $f18, $f10, $f16
/* B306C8 800B9528 E4520050 */  swc1  $f18, 0x50($v0)
/* B306CC 800B952C 10000010 */  b     .L800B9570
/* B306D0 800B9530 8463110C */   lh    $v1, %lo(D_8016110C)($v1)
.L800B9534:
/* B306D4 800B9534 86180000 */  lh    $t8, ($s0)
/* B306D8 800B9538 44802000 */  mtc1  $zero, $f4
/* B306DC 800B953C 44803000 */  mtc1  $zero, $f6
/* B306E0 800B9540 27190001 */  addiu $t9, $t8, 1
/* B306E4 800B9544 A6190000 */  sh    $t9, ($s0)
/* B306E8 800B9548 86030000 */  lh    $v1, ($s0)
/* B306EC 800B954C 2401000F */  li    $at, 15
/* B306F0 800B9550 A6200008 */  sh    $zero, 8($s1)
/* B306F4 800B9554 E6240000 */  swc1  $f4, ($s1)
/* B306F8 800B9558 14610005 */  bne   $v1, $at, .L800B9570
/* B306FC 800B955C E6260004 */   swc1  $f6, 4($s1)
/* B30700 800B9560 A6000000 */  sh    $zero, ($s0)
/* B30704 800B9564 A620000A */  sh    $zero, 0xa($s1)
/* B30708 800B9568 10000002 */  b     .L800B9574
/* B3070C 800B956C 2402FFFF */   li    $v0, -1
.L800B9570:
/* B30710 800B9570 34628000 */  ori   $v0, $v1, 0x8000
.L800B9574:
/* B30714 800B9574 8FBF002C */  lw    $ra, 0x2c($sp)
/* B30718 800B9578 8FB00020 */  lw    $s0, 0x20($sp)
/* B3071C 800B957C 8FB10024 */  lw    $s1, 0x24($sp)
/* B30720 800B9580 8FB20028 */  lw    $s2, 0x28($sp)
/* B30724 800B9584 03E00008 */  jr    $ra
/* B30728 800B9588 27BD0030 */   addiu $sp, $sp, 0x30

