glabel func_800EE9D0
/* B65B70 800EE9D0 AFA50004 */  sw    $a1, 4($sp)
/* B65B74 800EE9D4 30A500FF */  andi  $a1, $a1, 0xff
/* B65B78 800EE9D8 24020001 */  li    $v0, 1
/* B65B7C 800EE9DC 00A03025 */  move  $a2, $a1
/* B65B80 800EE9E0 18A00016 */  blez  $a1, .L800EEA3C
/* B65B84 800EE9E4 00001825 */   move  $v1, $zero
/* B65B88 800EE9E8 3C0E8017 */  lui   $t6, %hi(D_8016B9B8) # $t6, 0x8017
/* B65B8C 800EE9EC 25CEB9B8 */  addiu $t6, %lo(D_8016B9B8) # addiu $t6, $t6, -0x4648
/* B65B90 800EE9F0 00CE3821 */  addu  $a3, $a2, $t6
/* B65B94 800EE9F4 00004025 */  move  $t0, $zero
/* B65B98 800EE9F8 240A0030 */  li    $t2, 48
/* B65B9C 800EE9FC 24090031 */  li    $t1, 49
.L800EEA00:
/* B65BA0 800EEA00 00827824 */  and   $t7, $a0, $v0
/* B65BA4 800EEA04 11E00005 */  beqz  $t7, .L800EEA1C
/* B65BA8 800EEA08 00021040 */   sll   $v0, $v0, 1
/* B65BAC 800EEA0C 0008C023 */  negu  $t8, $t0
/* B65BB0 800EEA10 00F8C821 */  addu  $t9, $a3, $t8
/* B65BB4 800EEA14 10000004 */  b     .L800EEA28
/* B65BB8 800EEA18 A329FFFF */   sb    $t1, -1($t9)
.L800EEA1C:
/* B65BBC 800EEA1C 00085823 */  negu  $t3, $t0
/* B65BC0 800EEA20 00EB6021 */  addu  $t4, $a3, $t3
/* B65BC4 800EEA24 A18AFFFF */  sb    $t2, -1($t4)
.L800EEA28:
/* B65BC8 800EEA28 24630001 */  addiu $v1, $v1, 1
/* B65BCC 800EEA2C 306300FF */  andi  $v1, $v1, 0xff
/* B65BD0 800EEA30 0066082A */  slt   $at, $v1, $a2
/* B65BD4 800EEA34 1420FFF2 */  bnez  $at, .L800EEA00
/* B65BD8 800EEA38 00604025 */   move  $t0, $v1
.L800EEA3C:
/* B65BDC 800EEA3C 3C038017 */  lui   $v1, %hi(D_8016B9B8)
/* B65BE0 800EEA40 2462B9B8 */  addiu $v0, $v1, %lo(D_8016B9B8)
/* B65BE4 800EEA44 00456821 */  addu  $t5, $v0, $a1
/* B65BE8 800EEA48 03E00008 */  jr    $ra
/* B65BEC 800EEA4C A1A00000 */   sb    $zero, ($t5)

