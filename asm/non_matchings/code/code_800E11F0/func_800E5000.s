glabel func_800E5000
/* B5C1A0 800E5000 27BDFF90 */  addiu $sp, $sp, -0x70
/* B5C1A4 800E5004 AFB20020 */  sw    $s2, 0x20($sp)
/* B5C1A8 800E5008 3C128017 */  lui   $s2, %hi(gAudioContext) # $s2, 0x8017
/* B5C1AC 800E500C 2652F180 */  addiu $s2, %lo(gAudioContext) # addiu $s2, $s2, -0xe80
/* B5C1B0 800E5010 8E4E289C */  lw    $t6, 0x289c($s2)
/* B5C1B4 800E5014 86432848 */  lh    $v1, 0x2848($s2)
/* B5C1B8 800E5018 AFBF0024 */  sw    $ra, 0x24($sp)
/* B5C1BC 800E501C 25CF0001 */  addiu $t7, $t6, 1
/* B5C1C0 800E5020 01E3001A */  div   $zero, $t7, $v1
/* B5C1C4 800E5024 01E03825 */  move  $a3, $t7
/* B5C1C8 800E5028 00002010 */  mfhi  $a0
/* B5C1CC 800E502C AFB1001C */  sw    $s1, 0x1c($sp)
/* B5C1D0 800E5030 AFB00018 */  sw    $s0, 0x18($sp)
/* B5C1D4 800E5034 AE4F289C */  sw    $t7, 0x289c($s2)
/* B5C1D8 800E5038 14600002 */  bnez  $v1, .L800E5044
/* B5C1DC 800E503C 00000000 */   nop
/* B5C1E0 800E5040 0007000D */  break 7
.L800E5044:
/* B5C1E4 800E5044 2401FFFF */  li    $at, -1
/* B5C1E8 800E5048 14610004 */  bne   $v1, $at, .L800E505C
/* B5C1EC 800E504C 3C018000 */   lui   $at, 0x8000
/* B5C1F0 800E5050 14E10002 */  bne   $a3, $at, .L800E505C
/* B5C1F4 800E5054 00000000 */   nop
/* B5C1F8 800E5058 0006000D */  break 6
.L800E505C:
/* B5C1FC 800E505C 00E02825 */  move  $a1, $a3
/* B5C200 800E5060 1080001D */  beqz  $a0, .L800E50D8
/* B5C204 800E5064 00003025 */   move  $a2, $zero
/* B5C208 800E5068 3C028017 */  lui   $v0, %hi(D_801755D0) # $v0, 0x8017
/* B5C20C 800E506C 8C4255D0 */  lw    $v0, %lo(D_801755D0)($v0)
/* B5C210 800E5070 50400013 */  beql  $v0, $zero, .L800E50C0
/* B5C214 800E5074 24990001 */   addiu $t9, $a0, 1
/* B5C218 800E5078 0040F809 */  jalr  $v0
/* B5C21C 800E507C 00000000 */  nop
/* B5C220 800E5080 3C038017 */  lui   $v1, %hi(gAudioContext+0x2848) # $v1, 0x8017
/* B5C224 800E5084 3C188017 */  lui   $t8, %hi(gAudioContext+0x289c) # $t8, 0x8017
/* B5C228 800E5088 8F181A1C */  lw    $t8, %lo(gAudioContext+0x289c)($t8)
/* B5C22C 800E508C 846319C8 */  lh    $v1, %lo(gAudioContext+0x2848)($v1)
/* B5C230 800E5090 0303001A */  div   $zero, $t8, $v1
/* B5C234 800E5094 00002010 */  mfhi  $a0
/* B5C238 800E5098 14600002 */  bnez  $v1, .L800E50A4
/* B5C23C 800E509C 00000000 */   nop
/* B5C240 800E50A0 0007000D */  break 7
.L800E50A4:
/* B5C244 800E50A4 2401FFFF */  li    $at, -1
/* B5C248 800E50A8 14610004 */  bne   $v1, $at, .L800E50BC
/* B5C24C 800E50AC 3C018000 */   lui   $at, 0x8000
/* B5C250 800E50B0 17010002 */  bne   $t8, $at, .L800E50BC
/* B5C254 800E50B4 00000000 */   nop
/* B5C258 800E50B8 0006000D */  break 6
.L800E50BC:
/* B5C25C 800E50BC 24990001 */  addiu $t9, $a0, 1
.L800E50C0:
/* B5C260 800E50C0 14790003 */  bne   $v1, $t9, .L800E50D0
/* B5C264 800E50C4 3C028013 */   lui   $v0, %hi(D_801304E4) # $v0, 0x8013
/* B5C268 800E50C8 10000128 */  b     .L800E556C
/* B5C26C 800E50CC 8C4204E4 */   lw    $v0, %lo(D_801304E4)($v0)
.L800E50D0:
/* B5C270 800E50D0 10000126 */  b     .L800E556C
/* B5C274 800E50D4 00001025 */   move  $v0, $zero
.L800E50D8:
/* B5C278 800E50D8 0C000C18 */  jal   osSendMesg
/* B5C27C 800E50DC 8E445BE8 */   lw    $a0, 0x5be8($s2)
/* B5C280 800E50E0 24030003 */  li    $v1, 3
/* B5C284 800E50E4 8E4B28A8 */  lw    $t3, 0x28a8($s2)
/* B5C288 800E50E8 8E4928A4 */  lw    $t1, 0x28a4($s2)
/* B5C28C 800E50EC 256C0001 */  addiu $t4, $t3, 1
/* B5C290 800E50F0 0183001A */  div   $zero, $t4, $v1
/* B5C294 800E50F4 00007010 */  mfhi  $t6
/* B5C298 800E50F8 25D80001 */  addiu $t8, $t6, 1
/* B5C29C 800E50FC 01806825 */  move  $t5, $t4
/* B5C2A0 800E5100 0303001A */  div   $zero, $t8, $v1
/* B5C2A4 800E5104 AE4C28A8 */  sw    $t4, 0x28a8($s2)
/* B5C2A8 800E5108 00008010 */  mfhi  $s0
/* B5C2AC 800E510C 392A0001 */  xori  $t2, $t1, 1
/* B5C2B0 800E5110 AE4A28A4 */  sw    $t2, 0x28a4($s2)
/* B5C2B4 800E5114 14600002 */  bnez  $v1, .L800E5120
/* B5C2B8 800E5118 00000000 */   nop
/* B5C2BC 800E511C 0007000D */  break 7
.L800E5120:
/* B5C2C0 800E5120 2401FFFF */  li    $at, -1
/* B5C2C4 800E5124 14610004 */  bne   $v1, $at, .L800E5138
/* B5C2C8 800E5128 3C018000 */   lui   $at, 0x8000
/* B5C2CC 800E512C 15A10002 */  bne   $t5, $at, .L800E5138
/* B5C2D0 800E5130 00000000 */   nop
/* B5C2D4 800E5134 0006000D */  break 6
.L800E5138:
/* B5C2D8 800E5138 AE4E28A8 */  sw    $t6, 0x28a8($s2)
/* B5C2DC 800E513C 01C07825 */  move  $t7, $t6
/* B5C2E0 800E5140 14600002 */  bnez  $v1, .L800E514C
/* B5C2E4 800E5144 00000000 */   nop
/* B5C2E8 800E5148 0007000D */  break 7
.L800E514C:
/* B5C2EC 800E514C 2401FFFF */  li    $at, -1
/* B5C2F0 800E5150 14610004 */  bne   $v1, $at, .L800E5164
/* B5C2F4 800E5154 3C018000 */   lui   $at, 0x8000
/* B5C2F8 800E5158 17010002 */  bne   $t8, $at, .L800E5164
/* B5C2FC 800E515C 00000000 */   nop
/* B5C300 800E5160 0006000D */  break 6
.L800E5164:
/* B5C304 800E5164 0C041700 */  jal   osAiGetLength
/* B5C308 800E5168 00000000 */   nop
/* B5C30C 800E516C 8E492984 */  lw    $t1, 0x2984($s2)
/* B5C310 800E5170 0002C882 */  srl   $t9, $v0, 2
/* B5C314 800E5174 AFB9006C */  sw    $t9, 0x6c($sp)
/* B5C318 800E5178 2D210010 */  sltiu $at, $t1, 0x10
/* B5C31C 800E517C 1020000B */  beqz  $at, .L800E51AC
/* B5C320 800E5180 00105040 */   sll   $t2, $s0, 1
/* B5C324 800E5184 024A3021 */  addu  $a2, $s2, $t2
/* B5C328 800E5188 84C22974 */  lh    $v0, 0x2974($a2)
/* B5C32C 800E518C 00105880 */  sll   $t3, $s0, 2
/* B5C330 800E5190 024B1821 */  addu  $v1, $s2, $t3
/* B5C334 800E5194 10400005 */  beqz  $v0, .L800E51AC
/* B5C338 800E5198 00022880 */   sll   $a1, $v0, 2
/* B5C33C 800E519C 8C642968 */  lw    $a0, 0x2968($v1)
/* B5C340 800E51A0 AFA30034 */  sw    $v1, 0x34($sp)
/* B5C344 800E51A4 0C039A30 */  jal   osAiSetNextBuffer
/* B5C348 800E51A8 AFA6003C */   sw    $a2, 0x3c($sp)
.L800E51AC:
/* B5C34C 800E51AC 3C028017 */  lui   $v0, %hi(D_801755D0) # $v0, 0x8017
/* B5C350 800E51B0 8C4255D0 */  lw    $v0, %lo(D_801755D0)($v0)
/* B5C354 800E51B4 50400004 */  beql  $v0, $zero, .L800E51C8
/* B5C358 800E51B8 8E4328A0 */   lw    $v1, 0x28a0($s2)
/* B5C35C 800E51BC 0040F809 */  jalr  $v0
/* B5C360 800E51C0 00000000 */  nop
/* B5C364 800E51C4 8E4328A0 */  lw    $v1, 0x28a0($s2)
.L800E51C8:
/* B5C368 800E51C8 3C118017 */  lui   $s1, %hi(gAudioContext+0x1ed0) # $s1, 0x8017
/* B5C36C 800E51CC 26311050 */  addiu $s1, %lo(gAudioContext+0x1ed0) # addiu $s1, $s1, 0x1050
/* B5C370 800E51D0 1860000E */  blez  $v1, .L800E520C
/* B5C374 800E51D4 00008025 */   move  $s0, $zero
/* B5C378 800E51D8 02202025 */  move  $a0, $s1
.L800E51DC:
/* B5C37C 800E51DC 00002825 */  move  $a1, $zero
/* B5C380 800E51E0 00003025 */  move  $a2, $zero
/* B5C384 800E51E4 0C000CA0 */  jal   osRecvMesg
/* B5C388 800E51E8 AFA3005C */   sw    $v1, 0x5c($sp)
/* B5C38C 800E51EC 14400002 */  bnez  $v0, .L800E51F8
/* B5C390 800E51F0 8FA3005C */   lw    $v1, 0x5c($sp)
/* B5C394 800E51F4 2463FFFF */  addiu $v1, $v1, -1
.L800E51F8:
/* B5C398 800E51F8 8E4C28A0 */  lw    $t4, 0x28a0($s2)
/* B5C39C 800E51FC 26100001 */  addiu $s0, $s0, 1
/* B5C3A0 800E5200 020C082A */  slt   $at, $s0, $t4
/* B5C3A4 800E5204 5420FFF5 */  bnezl $at, .L800E51DC
/* B5C3A8 800E5208 02202025 */   move  $a0, $s1
.L800E520C:
/* B5C3AC 800E520C 3C118017 */  lui   $s1, %hi(gAudioContext+0x1ed0) # $s1, 0x8017
/* B5C3B0 800E5210 1060000C */  beqz  $v1, .L800E5244
/* B5C3B4 800E5214 26311050 */   addiu $s1, %lo(gAudioContext+0x1ed0) # addiu $s1, $s1, 0x1050
/* B5C3B8 800E5218 1860000A */  blez  $v1, .L800E5244
/* B5C3BC 800E521C 00008025 */   move  $s0, $zero
/* B5C3C0 800E5220 02202025 */  move  $a0, $s1
.L800E5224:
/* B5C3C4 800E5224 00002825 */  move  $a1, $zero
/* B5C3C8 800E5228 24060001 */  li    $a2, 1
/* B5C3CC 800E522C 0C000CA0 */  jal   osRecvMesg
/* B5C3D0 800E5230 AFA3005C */   sw    $v1, 0x5c($sp)
/* B5C3D4 800E5234 8FA3005C */  lw    $v1, 0x5c($sp)
/* B5C3D8 800E5238 26100001 */  addiu $s0, $s0, 1
/* B5C3DC 800E523C 5603FFF9 */  bnel  $s0, $v1, .L800E5224
/* B5C3E0 800E5240 02202025 */   move  $a0, $s1
.L800E5244:
/* B5C3E4 800E5244 8E431ED8 */  lw    $v1, 0x1ed8($s2)
/* B5C3E8 800E5248 1060000C */  beqz  $v1, .L800E527C
/* B5C3EC 800E524C 00000000 */   nop
/* B5C3F0 800E5250 1860000A */  blez  $v1, .L800E527C
/* B5C3F4 800E5254 00008025 */   move  $s0, $zero
/* B5C3F8 800E5258 02202025 */  move  $a0, $s1
.L800E525C:
/* B5C3FC 800E525C 00002825 */  move  $a1, $zero
/* B5C400 800E5260 00003025 */  move  $a2, $zero
/* B5C404 800E5264 0C000CA0 */  jal   osRecvMesg
/* B5C408 800E5268 AFA30048 */   sw    $v1, 0x48($sp)
/* B5C40C 800E526C 8FA30048 */  lw    $v1, 0x48($sp)
/* B5C410 800E5270 26100001 */  addiu $s0, $s0, 1
/* B5C414 800E5274 5603FFF9 */  bnel  $s0, $v1, .L800E525C
/* B5C418 800E5278 02202025 */   move  $a0, $s1
.L800E527C:
/* B5C41C 800E527C 0C03847C */  jal   func_800E11F0
/* B5C420 800E5280 AE4028A0 */   sw    $zero, 0x28a0($s2)
/* B5C424 800E5284 0C038BFB */  jal   func_800E2FEC
/* B5C428 800E5288 92443518 */   lbu   $a0, 0x3518($s2)
/* B5C42C 800E528C 0C0393D6 */  jal   func_800E4F58
/* B5C430 800E5290 00000000 */   nop
/* B5C434 800E5294 924D3518 */  lbu   $t5, 0x3518($s2)
/* B5C438 800E5298 51A00011 */  beql  $t5, $zero, .L800E52E0
/* B5C43C 800E529C 8E4F2984 */   lw    $t7, 0x2984($s2)
/* B5C440 800E52A0 0C037E3D */  jal   Audio_ResetStep
/* B5C444 800E52A4 00000000 */   nop
/* B5C448 800E52A8 5440000D */  bnezl $v0, .L800E52E0
/* B5C44C 800E52AC 8E4F2984 */   lw    $t7, 0x2984($s2)
/* B5C450 800E52B0 924E3518 */  lbu   $t6, 0x3518($s2)
/* B5C454 800E52B4 00003025 */  move  $a2, $zero
/* B5C458 800E52B8 15C00004 */  bnez  $t6, .L800E52CC
/* B5C45C 800E52BC 00000000 */   nop
/* B5C460 800E52C0 8E445BE4 */  lw    $a0, 0x5be4($s2)
/* B5C464 800E52C4 0C000C18 */  jal   osSendMesg
/* B5C468 800E52C8 92453519 */   lbu   $a1, 0x3519($s2)
.L800E52CC:
/* B5C46C 800E52CC 3C018013 */  lui   $at, %hi(D_801304E4) # $at, 0x8013
/* B5C470 800E52D0 AC2004E4 */  sw    $zero, %lo(D_801304E4)($at)
/* B5C474 800E52D4 100000A5 */  b     .L800E556C
/* B5C478 800E52D8 00001025 */   move  $v0, $zero
/* B5C47C 800E52DC 8E4F2984 */  lw    $t7, 0x2984($s2)
.L800E52E0:
/* B5C480 800E52E0 2DE10011 */  sltiu $at, $t7, 0x11
/* B5C484 800E52E4 54200004 */  bnezl $at, .L800E52F8
/* B5C488 800E52E8 8E582984 */   lw    $t8, 0x2984($s2)
/* B5C48C 800E52EC 1000009F */  b     .L800E556C
/* B5C490 800E52F0 00001025 */   move  $v0, $zero
/* B5C494 800E52F4 8E582984 */  lw    $t8, 0x2984($s2)
.L800E52F8:
/* B5C498 800E52F8 27B1004C */  addiu $s1, $sp, 0x4c
/* B5C49C 800E52FC 02202825 */  move  $a1, $s1
/* B5C4A0 800E5300 13000004 */  beqz  $t8, .L800E5314
/* B5C4A4 800E5304 00003025 */   move  $a2, $zero
/* B5C4A8 800E5308 8E422984 */  lw    $v0, 0x2984($s2)
/* B5C4AC 800E530C 24590001 */  addiu $t9, $v0, 1
/* B5C4B0 800E5310 AE592984 */  sw    $t9, 0x2984($s2)
.L800E5314:
/* B5C4B4 800E5314 8E4328A4 */  lw    $v1, 0x28a4($s2)
/* B5C4B8 800E5318 8E5028A8 */  lw    $s0, 0x28a8($s2)
/* B5C4BC 800E531C 00034880 */  sll   $t1, $v1, 2
/* B5C4C0 800E5320 01234821 */  addu  $t1, $t1, $v1
/* B5C4C4 800E5324 00094900 */  sll   $t1, $t1, 4
/* B5C4C8 800E5328 02495021 */  addu  $t2, $s2, $t1
/* B5C4CC 800E532C 254B28C0 */  addiu $t3, $t2, 0x28c0
/* B5C4D0 800E5330 00036080 */  sll   $t4, $v1, 2
/* B5C4D4 800E5334 AE4B28B8 */  sw    $t3, 0x28b8($s2)
/* B5C4D8 800E5338 024C6821 */  addu  $t5, $s2, $t4
/* B5C4DC 800E533C 8DAE28AC */  lw    $t6, 0x28ac($t5)
/* B5C4E0 800E5340 8FAC006C */  lw    $t4, 0x6c($sp)
/* B5C4E4 800E5344 864B284E */  lh    $t3, 0x284e($s2)
/* B5C4E8 800E5348 00107880 */  sll   $t7, $s0, 2
/* B5C4EC 800E534C 024FC021 */  addu  $t8, $s2, $t7
/* B5C4F0 800E5350 AE4E28B4 */  sw    $t6, 0x28b4($s2)
/* B5C4F4 800E5354 016C6823 */  subu  $t5, $t3, $t4
/* B5C4F8 800E5358 AFB80034 */  sw    $t8, 0x34($sp)
/* B5C4FC 800E535C 25AE0080 */  addiu $t6, $t5, 0x80
/* B5C500 800E5360 8F092968 */  lw    $t1, 0x2968($t8)
/* B5C504 800E5364 31CFFFF0 */  andi  $t7, $t6, 0xfff0
/* B5C508 800E5368 00105040 */  sll   $t2, $s0, 1
/* B5C50C 800E536C 024A4021 */  addu  $t0, $s2, $t2
/* B5C510 800E5370 25F80010 */  addiu $t8, $t7, 0x10
/* B5C514 800E5374 A5182974 */  sh    $t8, 0x2974($t0)
/* B5C518 800E5378 86442852 */  lh    $a0, 0x2852($s2)
/* B5C51C 800E537C 85022974 */  lh    $v0, 0x2974($t0)
/* B5C520 800E5380 AFA90058 */  sw    $t1, 0x58($sp)
/* B5C524 800E5384 0044082A */  slt   $at, $v0, $a0
/* B5C528 800E5388 50200004 */  beql  $at, $zero, .L800E539C
/* B5C52C 800E538C 86432850 */   lh    $v1, 0x2850($s2)
/* B5C530 800E5390 A5042974 */  sh    $a0, 0x2974($t0)
/* B5C534 800E5394 85022974 */  lh    $v0, 0x2974($t0)
/* B5C538 800E5398 86432850 */  lh    $v1, 0x2850($s2)
.L800E539C:
/* B5C53C 800E539C 0062082A */  slt   $at, $v1, $v0
/* B5C540 800E53A0 50200003 */  beql  $at, $zero, .L800E53B0
/* B5C544 800E53A4 92593518 */   lbu   $t9, 0x3518($s2)
/* B5C548 800E53A8 A5032974 */  sh    $v1, 0x2974($t0)
/* B5C54C 800E53AC 92593518 */  lbu   $t9, 0x3518($s2)
.L800E53B0:
/* B5C550 800E53B0 00008025 */  move  $s0, $zero
/* B5C554 800E53B4 AFA8003C */  sw    $t0, 0x3c($sp)
/* B5C558 800E53B8 57200019 */  bnezl $t9, .L800E5420
/* B5C55C 800E53BC 8FA8003C */   lw    $t0, 0x3c($sp)
/* B5C560 800E53C0 8E445BEC */  lw    $a0, 0x5bec($s2)
/* B5C564 800E53C4 0C000CA0 */  jal   osRecvMesg
/* B5C568 800E53C8 AFA8003C */   sw    $t0, 0x3c($sp)
/* B5C56C 800E53CC 2401FFFF */  li    $at, -1
/* B5C570 800E53D0 1041000B */  beq   $v0, $at, .L800E5400
/* B5C574 800E53D4 00000000 */   nop
.L800E53D8:
/* B5C578 800E53D8 0C03975B */  jal   func_800E5D6C
/* B5C57C 800E53DC 8FA4004C */   lw    $a0, 0x4c($sp)
/* B5C580 800E53E0 8E445BEC */  lw    $a0, 0x5bec($s2)
/* B5C584 800E53E4 02202825 */  move  $a1, $s1
/* B5C588 800E53E8 00003025 */  move  $a2, $zero
/* B5C58C 800E53EC 0C000CA0 */  jal   osRecvMesg
/* B5C590 800E53F0 26100001 */   addiu $s0, $s0, 1
/* B5C594 800E53F4 2401FFFF */  li    $at, -1
/* B5C598 800E53F8 1441FFF7 */  bne   $v0, $at, .L800E53D8
/* B5C59C 800E53FC 00000000 */   nop
.L800E5400:
/* B5C5A0 800E5400 56000007 */  bnezl $s0, .L800E5420
/* B5C5A4 800E5404 8FA8003C */   lw    $t0, 0x3c($sp)
/* B5C5A8 800E5408 92495BDA */  lbu   $t1, 0x5bda($s2)
/* B5C5AC 800E540C 51200004 */  beql  $t1, $zero, .L800E5420
/* B5C5B0 800E5410 8FA8003C */   lw    $t0, 0x3c($sp)
/* B5C5B4 800E5414 0C0396E0 */  jal   func_800E5B80
/* B5C5B8 800E5418 00000000 */   nop
/* B5C5BC 800E541C 8FA8003C */  lw    $t0, 0x3c($sp)
.L800E5420:
/* B5C5C0 800E5420 8E4428B4 */  lw    $a0, 0x28b4($s2)
/* B5C5C4 800E5424 27A50068 */  addiu $a1, $sp, 0x68
/* B5C5C8 800E5428 8FA60058 */  lw    $a2, 0x58($sp)
/* B5C5CC 800E542C 0C036C31 */  jal   func_800DB0C4
/* B5C5D0 800E5430 85072974 */   lh    $a3, 0x2974($t0)
/* B5C5D4 800E5434 0C001BA8 */  jal   osGetCount
/* B5C5D8 800E5438 AE4228B4 */   sw    $v0, 0x28b4($s2)
/* B5C5DC 800E543C 8E47289C */  lw    $a3, 0x289c($s2)
/* B5C5E0 800E5440 8E4A297C */  lw    $t2, 0x297c($s2)
/* B5C5E4 800E5444 8FAD0034 */  lw    $t5, 0x34($sp)
/* B5C5E8 800E5448 30EF00FF */  andi  $t7, $a3, 0xff
/* B5C5EC 800E544C 01475821 */  addu  $t3, $t2, $a3
/* B5C5F0 800E5450 004B0019 */  multu $v0, $t3
/* B5C5F4 800E5454 000FC040 */  sll   $t8, $t7, 1
/* B5C5F8 800E5458 3C0F800E */  lui   $t7, %hi(func_800E4FE0) # $t7, 0x800e
/* B5C5FC 800E545C 25EF4FE0 */  addiu $t7, %lo(func_800E4FE0) # addiu $t7, $t7, 0x4fe0
/* B5C600 800E5460 3C018013 */  lui   $at, %hi(gWaveSamples+0x20) # $at, 0x8013
/* B5C604 800E5464 3C068015 */  lui   $a2, %hi(D_80155C70) # $a2, 0x8015
/* B5C608 800E5468 3C0A8015 */  lui   $t2, %hi(D_80155F50) # $t2, 0x8015
/* B5C60C 800E546C 24C65C70 */  addiu $a2, %lo(D_80155C70) # addiu $a2, $a2, 0x5c70
/* B5C610 800E5470 254A5F50 */  addiu $t2, %lo(D_80155F50) # addiu $t2, $t2, 0x5f50
/* B5C614 800E5474 3C048011 */  lui   $a0, %hi(D_801120C0) # $a0, 0x8011
/* B5C618 800E5478 00006012 */  mflo  $t4
/* B5C61C 800E547C AE4C297C */  sw    $t4, 0x297c($s2)
/* B5C620 800E5480 8DAE2968 */  lw    $t6, 0x2968($t5)
/* B5C624 800E5484 248420C0 */  addiu $a0, %lo(D_801120C0) # addiu $a0, $a0, 0x20c0
/* B5C628 800E5488 24051000 */  li    $a1, 4096
/* B5C62C 800E548C 01D8C821 */  addu  $t9, $t6, $t8
/* B5C630 800E5490 87290000 */  lh    $t1, ($t9)
/* B5C634 800E5494 012C5821 */  addu  $t3, $t1, $t4
/* B5C638 800E5498 316DFFF0 */  andi  $t5, $t3, 0xfff0
/* B5C63C 800E549C AE4B297C */  sw    $t3, 0x297c($s2)
/* B5C640 800E54A0 01AF7021 */  addu  $t6, $t5, $t7
/* B5C644 800E54A4 AC2EF0B0 */  sw    $t6, %lo(gWaveSamples+0x20)($at)
/* B5C648 800E54A8 8E5828B8 */  lw    $t8, 0x28b8($s2)
/* B5C64C 800E54AC 8E5028A4 */  lw    $s0, 0x28a4($s2)
/* B5C650 800E54B0 01465823 */  subu  $t3, $t2, $a2
/* B5C654 800E54B4 AF000040 */  sw    $zero, 0x40($t8)
/* B5C658 800E54B8 8E5928B8 */  lw    $t9, 0x28b8($s2)
/* B5C65C 800E54BC 000B60C3 */  sra   $t4, $t3, 3
/* B5C660 800E54C0 000C68C0 */  sll   $t5, $t4, 3
/* B5C664 800E54C4 AF200044 */  sw    $zero, 0x44($t9)
/* B5C668 800E54C8 8E4328B8 */  lw    $v1, 0x28b8($s2)
/* B5C66C 800E54CC 24090002 */  li    $t1, 2
/* B5C670 800E54D0 25AFFFFF */  addiu $t7, $t5, -1
/* B5C674 800E54D4 00107080 */  sll   $t6, $s0, 2
/* B5C678 800E54D8 024EC021 */  addu  $t8, $s2, $t6
/* B5C67C 800E54DC AC690000 */  sw    $t1, ($v1)
/* B5C680 800E54E0 AC600004 */  sw    $zero, 4($v1)
/* B5C684 800E54E4 AC640008 */  sw    $a0, 8($v1)
/* B5C688 800E54E8 AC65000C */  sw    $a1, 0xc($v1)
/* B5C68C 800E54EC AC6F001C */  sw    $t7, 0x1c($v1)
/* B5C690 800E54F0 AC640010 */  sw    $a0, 0x10($v1)
/* B5C694 800E54F4 AC660018 */  sw    $a2, 0x18($v1)
/* B5C698 800E54F8 AC650014 */  sw    $a1, 0x14($v1)
/* B5C69C 800E54FC AC600020 */  sw    $zero, 0x20($v1)
/* B5C6A0 800E5500 AC600024 */  sw    $zero, 0x24($v1)
/* B5C6A4 800E5504 AC600028 */  sw    $zero, 0x28($v1)
/* B5C6A8 800E5508 AC60002C */  sw    $zero, 0x2c($v1)
/* B5C6AC 800E550C 8F1928AC */  lw    $t9, 0x28ac($t8)
/* B5C6B0 800E5510 3C0B8013 */  lui   $t3, %hi(D_801304E0) # $t3, 0x8013
/* B5C6B4 800E5514 AC790030 */  sw    $t9, 0x30($v1)
/* B5C6B8 800E5518 8FA90068 */  lw    $t1, 0x68($sp)
/* B5C6BC 800E551C AC600038 */  sw    $zero, 0x38($v1)
/* B5C6C0 800E5520 AC60003C */  sw    $zero, 0x3c($v1)
/* B5C6C4 800E5524 000950C0 */  sll   $t2, $t1, 3
/* B5C6C8 800E5528 AC6A0034 */  sw    $t2, 0x34($v1)
/* B5C6CC 800E552C 8FAC0068 */  lw    $t4, 0x68($sp)
/* B5C6D0 800E5530 8D6B04E0 */  lw    $t3, %lo(D_801304E0)($t3)
/* B5C6D4 800E5534 016C082A */  slt   $at, $t3, $t4
/* B5C6D8 800E5538 10200002 */  beqz  $at, .L800E5544
/* B5C6DC 800E553C 3C018013 */   lui   $at, %hi(D_801304E0) # $at, 0x8013
/* B5C6E0 800E5540 AC2C04E0 */  sw    $t4, %lo(D_801304E0)($at)
.L800E5544:
/* B5C6E4 800E5544 864D2848 */  lh    $t5, 0x2848($s2)
/* B5C6E8 800E5548 24010001 */  li    $at, 1
/* B5C6EC 800E554C 55A10004 */  bnel  $t5, $at, .L800E5560
/* B5C6F0 800E5550 8E4F28B8 */   lw    $t7, 0x28b8($s2)
/* B5C6F4 800E5554 10000005 */  b     .L800E556C
/* B5C6F8 800E5558 8E4228B8 */   lw    $v0, 0x28b8($s2)
/* B5C6FC 800E555C 8E4F28B8 */  lw    $t7, 0x28b8($s2)
.L800E5560:
/* B5C700 800E5560 3C018013 */  lui   $at, %hi(D_801304E4) # $at, 0x8013
/* B5C704 800E5564 00001025 */  move  $v0, $zero
/* B5C708 800E5568 AC2F04E4 */  sw    $t7, %lo(D_801304E4)($at)
.L800E556C:
/* B5C70C 800E556C 8FBF0024 */  lw    $ra, 0x24($sp)
/* B5C710 800E5570 8FB00018 */  lw    $s0, 0x18($sp)
/* B5C714 800E5574 8FB1001C */  lw    $s1, 0x1c($sp)
/* B5C718 800E5578 8FB20020 */  lw    $s2, 0x20($sp)
/* B5C71C 800E557C 03E00008 */  jr    $ra
/* B5C720 800E5580 27BD0070 */   addiu $sp, $sp, 0x70

