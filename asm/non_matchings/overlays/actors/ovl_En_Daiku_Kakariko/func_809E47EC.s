glabel func_809E47EC
/* 004CC 809E47EC 27BDFFD8 */  addiu   $sp, $sp, 0xFFD8           ## $sp = FFFFFFD8
/* 004D0 809E47F0 AFBF001C */  sw      $ra, 0x001C($sp)           
/* 004D4 809E47F4 AFB00018 */  sw      $s0, 0x0018($sp)           
/* 004D8 809E47F8 8C8E01E0 */  lw      $t6, 0x01E0($a0)           ## 000001E0
/* 004DC 809E47FC 24010002 */  addiu   $at, $zero, 0x0002         ## $at = 00000002
/* 004E0 809E4800 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 004E4 809E4804 55C10006 */  bnel    $t6, $at, .L809E4820       
/* 004E8 809E4808 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 004EC 809E480C 0C2791D3 */  jal     func_809E474C              
/* 004F0 809E4810 00000000 */  nop
/* 004F4 809E4814 1000005F */  beq     $zero, $zero, .L809E4994   
/* 004F8 809E4818 AE0201E0 */  sw      $v0, 0x01E0($s0)           ## 000001E0
/* 004FC 809E481C 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
.L809E4820:
/* 00500 809E4820 0C00BC65 */  jal     func_8002F194              
/* 00504 809E4824 AFA5002C */  sw      $a1, 0x002C($sp)           
/* 00508 809E4828 10400004 */  beq     $v0, $zero, .L809E483C     
/* 0050C 809E482C 8FA4002C */  lw      $a0, 0x002C($sp)           
/* 00510 809E4830 240F0002 */  addiu   $t7, $zero, 0x0002         ## $t7 = 00000002
/* 00514 809E4834 10000057 */  beq     $zero, $zero, .L809E4994   
/* 00518 809E4838 AE0F01E0 */  sw      $t7, 0x01E0($s0)           ## 000001E0
.L809E483C:
/* 0051C 809E483C 02002825 */  or      $a1, $s0, $zero            ## $a1 = 00000000
/* 00520 809E4840 27A60026 */  addiu   $a2, $sp, 0x0026           ## $a2 = FFFFFFFE
/* 00524 809E4844 0C00BCDD */  jal     func_8002F374              
/* 00528 809E4848 27A70024 */  addiu   $a3, $sp, 0x0024           ## $a3 = FFFFFFFC
/* 0052C 809E484C 87A20026 */  lh      $v0, 0x0026($sp)           
/* 00530 809E4850 04400050 */  bltz    $v0, .L809E4994            
/* 00534 809E4854 28410141 */  slti    $at, $v0, 0x0141           
/* 00538 809E4858 1020004E */  beq     $at, $zero, .L809E4994     
/* 0053C 809E485C 87A20024 */  lh      $v0, 0x0024($sp)           
/* 00540 809E4860 0440004C */  bltz    $v0, .L809E4994            
/* 00544 809E4864 284100F1 */  slti    $at, $v0, 0x00F1           
/* 00548 809E4868 5020004B */  beql    $at, $zero, .L809E4998     
/* 0054C 809E486C 8FBF001C */  lw      $ra, 0x001C($sp)           
/* 00550 809E4870 8E1801E0 */  lw      $t8, 0x01E0($s0)           ## 000001E0
/* 00554 809E4874 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 00558 809E4878 8FA5002C */  lw      $a1, 0x002C($sp)           
/* 0055C 809E487C 57000046 */  bnel    $t8, $zero, .L809E4998     
/* 00560 809E4880 8FBF001C */  lw      $ra, 0x001C($sp)           
/* 00564 809E4884 0C00BCB3 */  jal     func_8002F2CC              
/* 00568 809E4888 3C0642C8 */  lui     $a2, 0x42C8                ## $a2 = 42C80000
/* 0056C 809E488C 24010001 */  addiu   $at, $zero, 0x0001         ## $at = 00000001
/* 00570 809E4890 54410041 */  bnel    $v0, $at, .L809E4998       
/* 00574 809E4894 8FBF001C */  lw      $ra, 0x001C($sp)           
/* 00578 809E4898 8619001C */  lh      $t9, 0x001C($s0)           ## 0000001C
/* 0057C 809E489C 3C05809E */  lui     $a1, %hi(D_809E5570)       ## $a1 = 809E0000
/* 00580 809E48A0 8FA4002C */  lw      $a0, 0x002C($sp)           
/* 00584 809E48A4 33280003 */  andi    $t0, $t9, 0x0003           ## $t0 = 00000000
/* 00588 809E48A8 00084880 */  sll     $t1, $t0,  2               
/* 0058C 809E48AC 00A92821 */  addu    $a1, $a1, $t1              
/* 00590 809E48B0 0C01B0D8 */  jal     Text_GetFaceReaction              
/* 00594 809E48B4 8CA55570 */  lw      $a1, %lo(D_809E5570)($a1)  
/* 00598 809E48B8 304AFFFF */  andi    $t2, $v0, 0xFFFF           ## $t2 = 00000000
/* 0059C 809E48BC 15400035 */  bne     $t2, $zero, .L809E4994     
/* 005A0 809E48C0 A602010E */  sh      $v0, 0x010E($s0)           ## 0000010E
/* 005A4 809E48C4 8602001C */  lh      $v0, 0x001C($s0)           ## 0000001C
/* 005A8 809E48C8 24010001 */  addiu   $at, $zero, 0x0001         ## $at = 00000001
/* 005AC 809E48CC 30420003 */  andi    $v0, $v0, 0x0003           ## $v0 = 00000000
/* 005B0 809E48D0 5040000A */  beql    $v0, $zero, .L809E48FC     
/* 005B4 809E48D4 960B0200 */  lhu     $t3, 0x0200($s0)           ## 00000200
/* 005B8 809E48D8 10410011 */  beq     $v0, $at, .L809E4920       
/* 005BC 809E48DC 24010002 */  addiu   $at, $zero, 0x0002         ## $at = 00000002
/* 005C0 809E48E0 10410019 */  beq     $v0, $at, .L809E4948       
/* 005C4 809E48E4 24010003 */  addiu   $at, $zero, 0x0003         ## $at = 00000003
/* 005C8 809E48E8 50410022 */  beql    $v0, $at, .L809E4974       
/* 005CC 809E48EC 960D0200 */  lhu     $t5, 0x0200($s0)           ## 00000200
/* 005D0 809E48F0 10000029 */  beq     $zero, $zero, .L809E4998   
/* 005D4 809E48F4 8FBF001C */  lw      $ra, 0x001C($sp)           
/* 005D8 809E48F8 960B0200 */  lhu     $t3, 0x0200($s0)           ## 00000200
.L809E48FC:
/* 005DC 809E48FC 240D5076 */  addiu   $t5, $zero, 0x5076         ## $t5 = 00005076
/* 005E0 809E4900 240E5075 */  addiu   $t6, $zero, 0x5075         ## $t6 = 00005075
/* 005E4 809E4904 316C0008 */  andi    $t4, $t3, 0x0008           ## $t4 = 00000000
/* 005E8 809E4908 11800003 */  beq     $t4, $zero, .L809E4918     
/* 005EC 809E490C 00000000 */  nop
/* 005F0 809E4910 10000020 */  beq     $zero, $zero, .L809E4994   
/* 005F4 809E4914 A60D010E */  sh      $t5, 0x010E($s0)           ## 0000010E
.L809E4918:
/* 005F8 809E4918 1000001E */  beq     $zero, $zero, .L809E4994   
/* 005FC 809E491C A60E010E */  sh      $t6, 0x010E($s0)           ## 0000010E
.L809E4920:
/* 00600 809E4920 960F0200 */  lhu     $t7, 0x0200($s0)           ## 00000200
/* 00604 809E4924 2419502A */  addiu   $t9, $zero, 0x502A         ## $t9 = 0000502A
/* 00608 809E4928 24085074 */  addiu   $t0, $zero, 0x5074         ## $t0 = 00005074
/* 0060C 809E492C 31F80001 */  andi    $t8, $t7, 0x0001           ## $t8 = 00000000
/* 00610 809E4930 13000003 */  beq     $t8, $zero, .L809E4940     
/* 00614 809E4934 00000000 */  nop
/* 00618 809E4938 10000016 */  beq     $zero, $zero, .L809E4994   
/* 0061C 809E493C A619010E */  sh      $t9, 0x010E($s0)           ## 0000010E
.L809E4940:
/* 00620 809E4940 10000014 */  beq     $zero, $zero, .L809E4994   
/* 00624 809E4944 A608010E */  sh      $t0, 0x010E($s0)           ## 0000010E
.L809E4948:
/* 00628 809E4948 96090200 */  lhu     $t1, 0x0200($s0)           ## 00000200
/* 0062C 809E494C 240B506A */  addiu   $t3, $zero, 0x506A         ## $t3 = 0000506A
/* 00630 809E4950 240C506B */  addiu   $t4, $zero, 0x506B         ## $t4 = 0000506B
/* 00634 809E4954 312A0001 */  andi    $t2, $t1, 0x0001           ## $t2 = 00000000
/* 00638 809E4958 11400003 */  beq     $t2, $zero, .L809E4968     
/* 0063C 809E495C 00000000 */  nop
/* 00640 809E4960 1000000C */  beq     $zero, $zero, .L809E4994   
/* 00644 809E4964 A60B010E */  sh      $t3, 0x010E($s0)           ## 0000010E
.L809E4968:
/* 00648 809E4968 1000000A */  beq     $zero, $zero, .L809E4994   
/* 0064C 809E496C A60C010E */  sh      $t4, 0x010E($s0)           ## 0000010E
/* 00650 809E4970 960D0200 */  lhu     $t5, 0x0200($s0)           ## 00000200
.L809E4974:
/* 00654 809E4974 240F5077 */  addiu   $t7, $zero, 0x5077         ## $t7 = 00005077
/* 00658 809E4978 24185078 */  addiu   $t8, $zero, 0x5078         ## $t8 = 00005078
/* 0065C 809E497C 31AE0001 */  andi    $t6, $t5, 0x0001           ## $t6 = 00000000
/* 00660 809E4980 51C00004 */  beql    $t6, $zero, .L809E4994     
/* 00664 809E4984 A618010E */  sh      $t8, 0x010E($s0)           ## 0000010E
/* 00668 809E4988 10000002 */  beq     $zero, $zero, .L809E4994   
/* 0066C 809E498C A60F010E */  sh      $t7, 0x010E($s0)           ## 0000010E
/* 00670 809E4990 A618010E */  sh      $t8, 0x010E($s0)           ## 0000010E
.L809E4994:
/* 00674 809E4994 8FBF001C */  lw      $ra, 0x001C($sp)           
.L809E4998:
/* 00678 809E4998 8FB00018 */  lw      $s0, 0x0018($sp)           
/* 0067C 809E499C 27BD0028 */  addiu   $sp, $sp, 0x0028           ## $sp = 00000000
/* 00680 809E49A0 03E00008 */  jr      $ra                        
/* 00684 809E49A4 00000000 */  nop
