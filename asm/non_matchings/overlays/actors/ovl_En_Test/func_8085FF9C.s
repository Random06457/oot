glabel func_8085FF9C
/* 0094C 8085FF9C 27BDFFE8 */  addiu   $sp, $sp, 0xFFE8           ## $sp = FFFFFFE8
/* 00950 8085FFA0 AFBF0014 */  sw      $ra, 0x0014($sp)           
/* 00954 8085FFA4 00803025 */  or      $a2, $a0, $zero            ## $a2 = 00000000
/* 00958 8085FFA8 AFA5001C */  sw      $a1, 0x001C($sp)           
/* 0095C 8085FFAC AFA60018 */  sw      $a2, 0x0018($sp)           
/* 00960 8085FFB0 0C02927F */  jal     SkelAnime_FrameUpdateMatrix
              
/* 00964 8085FFB4 24840188 */  addiu   $a0, $a0, 0x0188           ## $a0 = 00000188
/* 00968 8085FFB8 8FA60018 */  lw      $a2, 0x0018($sp)           
/* 0096C 8085FFBC 3C014316 */  lui     $at, 0x4316                ## $at = 43160000
/* 00970 8085FFC0 44813000 */  mtc1    $at, $f6                   ## $f6 = 150.00
/* 00974 8085FFC4 3C014348 */  lui     $at, 0x4348                ## $at = 43480000
/* 00978 8085FFC8 44818000 */  mtc1    $at, $f16                  ## $f16 = 200.00
/* 0097C 8085FFCC C4CA0090 */  lwc1    $f10, 0x0090($a2)          ## 00000090
/* 00980 8085FFD0 C4C4000C */  lwc1    $f4, 0x000C($a2)           ## 0000000C
/* 00984 8085FFD4 3C0143E1 */  lui     $at, 0x43E1                ## $at = 43E10000
/* 00988 8085FFD8 4610503C */  c.lt.s  $f10, $f16                 
/* 0098C 8085FFDC 46062200 */  add.s   $f8, $f4, $f6              
/* 00990 8085FFE0 4500001D */  bc1f    .L80860058                 
/* 00994 8085FFE4 E4C80028 */  swc1    $f8, 0x0028($a2)           ## 00000028
/* 00998 8085FFE8 C4C00094 */  lwc1    $f0, 0x0094($a2)           ## 00000094
/* 0099C 8085FFEC 44809000 */  mtc1    $zero, $f18                ## $f18 = 0.00
/* 009A0 8085FFF0 44812000 */  mtc1    $at, $f4                   ## $f4 = 450.00
/* 009A4 8085FFF4 3C058086 */  lui     $a1, %hi(func_80860318)    ## $a1 = 80860000
/* 009A8 8085FFF8 4600903E */  c.le.s  $f18, $f0                  
/* 009AC 8085FFFC 24A50318 */  addiu   $a1, $a1, %lo(func_80860318) ## $a1 = 80860318
/* 009B0 80860000 00C02025 */  or      $a0, $a2, $zero            ## $a0 = 00000000
/* 009B4 80860004 45020004 */  bc1fl   .L80860018                 
/* 009B8 80860008 46000087 */  neg.s   $f2, $f0                   
/* 009BC 8086000C 10000002 */  beq     $zero, $zero, .L80860018   
/* 009C0 80860010 46000086 */  mov.s   $f2, $f0                   
/* 009C4 80860014 46000087 */  neg.s   $f2, $f0                   
.L80860018:
/* 009C8 80860018 4604103C */  c.lt.s  $f2, $f4                   
/* 009CC 8086001C 00000000 */  nop
/* 009D0 80860020 4502000E */  bc1fl   .L8086005C                 
/* 009D4 80860024 8FBF0014 */  lw      $ra, 0x0014($sp)           
/* 009D8 80860028 0C217D94 */  jal     EnTest_SetupAction              
/* 009DC 8086002C AFA60018 */  sw      $a2, 0x0018($sp)           
/* 009E0 80860030 8FA40018 */  lw      $a0, 0x0018($sp)           
/* 009E4 80860034 3C053C75 */  lui     $a1, 0x3C75                ## $a1 = 3C750000
/* 009E8 80860038 34A5C28F */  ori     $a1, $a1, 0xC28F           ## $a1 = 3C75C28F
/* 009EC 8086003C 8C8E0004 */  lw      $t6, 0x0004($a0)           ## 00000004
/* 009F0 80860040 8482008A */  lh      $v0, 0x008A($a0)           ## 0000008A
/* 009F4 80860044 35CF0001 */  ori     $t7, $t6, 0x0001           ## $t7 = 00000001
/* 009F8 80860048 AC8F0004 */  sw      $t7, 0x0004($a0)           ## 00000004
/* 009FC 8086004C A4820032 */  sh      $v0, 0x0032($a0)           ## 00000032
/* 00A00 80860050 0C00B58B */  jal     Actor_SetScale
              
/* 00A04 80860054 A48200B6 */  sh      $v0, 0x00B6($a0)           ## 000000B6
.L80860058:
/* 00A08 80860058 8FBF0014 */  lw      $ra, 0x0014($sp)           
.L8086005C:
/* 00A0C 8086005C 27BD0018 */  addiu   $sp, $sp, 0x0018           ## $sp = 00000000
/* 00A10 80860060 03E00008 */  jr      $ra                        
/* 00A14 80860064 00000000 */  nop
