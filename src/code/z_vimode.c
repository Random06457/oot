#include "global.h"


#define LOG_MODE_FIELD(exp, line) LOG_ADDRESS(#exp, exp, "../z_vimode.c", line)

// ViMode_LogViMode
void func_800AC030(OSViMode* osvimodep) {
    LOG_MODE_FIELD(osvimodep, 87);
    LOG_MODE_FIELD(osvimodep->comRegs.ctrl, 88);
    LOG_MODE_FIELD(osvimodep->comRegs.width, 89);
    LOG_MODE_FIELD(osvimodep->comRegs.burst, 90);
    LOG_MODE_FIELD(osvimodep->comRegs.vSync, 91);
    LOG_MODE_FIELD(osvimodep->comRegs.hSync, 92);
    LOG_MODE_FIELD(osvimodep->comRegs.leap, 93);
    LOG_MODE_FIELD(osvimodep->comRegs.hStart, 94);
    LOG_MODE_FIELD(osvimodep->comRegs.xScale, 95);
    LOG_MODE_FIELD(osvimodep->fldRegs[0].vStart, 96);
    LOG_MODE_FIELD(osvimodep->fldRegs[0].vBurst, 97);
    LOG_MODE_FIELD(osvimodep->fldRegs[0].origin, 98);
    LOG_MODE_FIELD(osvimodep->fldRegs[0].yScale, 99);
    LOG_MODE_FIELD(osvimodep->fldRegs[0].vIntr, 100);
    LOG_MODE_FIELD(osvimodep->fldRegs[1].vStart, 101);
    LOG_MODE_FIELD(osvimodep->fldRegs[1].vBurst, 102);
    LOG_MODE_FIELD(osvimodep->fldRegs[1].origin, 103);
    LOG_MODE_FIELD(osvimodep->fldRegs[1].yScale, 104);
    LOG_MODE_FIELD(osvimodep->fldRegs[1].vIntr, 105);
}

// ViMode_UpdateMode
//#pragma GLOBAL_ASM("asm/non_matchings/code/z_vimode/func_800AC2F4.s")

void func_800AC2F4(ViModeContext *this, s32 type, s32 tvType, s32 unk_70, s32 unk_74, s32 unk_78, s32 unk_7C, s32 width, s32 height, s32 unk_5C, s32 unk_58, s32 unk_64, s32 unk_60) {
    s32 yScaleLo;
    s32 cond1;
    s32 cond2;
    s32 cond4;
    s32 cond5;
    s32 cond0;
    s32 phi_v0_6;
    s32 phi_v1;
    s32 cond3;
    s32 phi_v0_8;
    s32 phi_v1_2;
    s32 phi_a2;
    s32 cond6;
    s32 phi_v0_12;
    s32 phi_v1_3;
    s32 yScale0Hi;
    s32 yScale1Hi;

    cond0 = !unk_70 && !unk_78;
    cond1 = !unk_70 && unk_78;
    cond2 = unk_70 && unk_78;
    cond3 = unk_70 && !unk_78;
    cond4 = unk_70 && !unk_74 && unk_78 && unk_7C;
    cond5 = unk_70 && unk_74 && unk_78 && !unk_7C;
    cond6 = !unk_70 && unk_74 && unk_78 && !unk_7C;
    
    unk_64 &= ~1;
    unk_60 &= ~1;
    
    yScaleLo = (((height << 11) / ((unk_60 - unk_64) + 0x1E0)) / (unk_70 ? 1 : 2)) * (cond0 ? 2 : 1);

    yScale0Hi = !unk_78 ? (cond3 ? 0x1000000 : 0x2000000) : 0;
    yScale1Hi = !unk_78 ? (cond3 ? 0x3000000 : 0x2000000) : 0;

    this->viMode.type = type;

    this->viMode.comRegs.ctrl =
        (!unk_7C ? OS_VI_UNK1 | OS_VI_UNK2 : OS_VI_UNK2) |
        (OS_VI_UNK1000 | OS_VI_UNK2000 | OS_VI_GAMMA_DITHER | OS_VI_GAMMA) |
        (!cond2 ? OS_VI_UNK40 : 0) |
        (!unk_74 ? OS_VI_DIVOT : 0);

    
    if (cond4) {
        this->viMode.comRegs.ctrl |= OS_VI_UNK100;
    } else if ((cond5 | cond6)) {
        this->viMode.comRegs.ctrl |= OS_VI_UNK100 | OS_VI_UNK200;
    } else if (unk_74) {
        this->viMode.comRegs.ctrl |= OS_VI_UNK200;
    }
    else {
        this->viMode.comRegs.ctrl |= 0;
    }
    
    this->viMode.comRegs.width = (cond1 ? 2 : 1) * width;

    if (tvType == 1) {
        this->viMode.comRegs.burst = 0x3E52239;
        this->viMode.comRegs.vSync = 0x20C;
        this->viMode.comRegs.hSync = 0xC15;
        this->viMode.comRegs.leap = 0xC150C15;
        this->viMode.comRegs.hStart = 0x6C02EC;
        this->viMode.fldRegs[0].vStart = 0x2501FF;
        this->viMode.fldRegs[0].vBurst = 0xE0204;
    } else if (tvType == 0) {
        this->viMode.comRegs.burst = 0x404233A;
        this->viMode.comRegs.vSync = 0x270;
        this->viMode.comRegs.hSync = 0x150C69;
        this->viMode.comRegs.leap = 0xC6F0C6E;
        this->viMode.comRegs.hStart = 0x800300;
        this->viMode.fldRegs[0].vStart = 0x5F0239;
        this->viMode.fldRegs[0].vBurst = 0x9026B;
    } else if (tvType == 2) {
        this->viMode.comRegs.burst = 0x4651E39;
        this->viMode.comRegs.vSync = 0x20C;
        this->viMode.comRegs.hSync = 0xC10;
        this->viMode.comRegs.leap = 0xC1C0C1C;
        this->viMode.comRegs.hStart = 0x6C02EC;
        this->viMode.fldRegs[0].vStart = 0x2501FF;
        this->viMode.fldRegs[0].vBurst = 0xE0204;
    }

    this->viMode.comRegs.hStart += ((unk_5C << 0x10) + (s16) unk_58);


    this->viMode.fldRegs[0].vStart += (unk_64 << 0x10) + (s16) unk_60;
    this->viMode.fldRegs[1].vStart = this->viMode.fldRegs[0].vStart;

    this->viMode.fldRegs[1].vBurst = this->viMode.fldRegs[0].vBurst;

    if (cond2) {
        this->viMode.comRegs.vSync++;
        if (tvType == 2) {
            this->viMode.comRegs.hSync += 0x40001;
        }
        if (tvType == 2) {
            this->viMode.comRegs.leap += 0xFFFCFFFE;
        }
    } else {
        this->viMode.fldRegs[0].vStart += 0xFFFDFFFE;
        if (tvType == 2) {
            this->viMode.fldRegs[0].vBurst += 0xFFFCFFFE;
        }
        if (tvType == 0) {
            this->viMode.fldRegs[1].vBurst += 0x2FFFE;
        }
    }

    this->viMode.comRegs.xScale = (width << 10) / ((unk_58 - unk_5C) + 0x280);
    this->viMode.comRegs.vCurrent = 0;

    this->viMode.fldRegs[0].origin = (unk_7C ? 1 : 2) * width * 2;
    this->viMode.fldRegs[1].origin = (unk_70 ? 1 : 2) * width * 2 * (unk_7C ? 1 : 2);
    
    this->viMode.fldRegs[0].yScale = yScaleLo | yScale0Hi;
    this->viMode.fldRegs[1].yScale = yScaleLo | yScale1Hi;
    
    this->viMode.fldRegs[0].vIntr = 2;
    this->viMode.fldRegs[1].vIntr = 2;
}

// ViMode_LogCurrMode
void func_800AC89C(ViModeContext* this) {
    
    SREG(48) = this->unk_68;
    SREG(49) = this->width;
    SREG(50) = this->height;
    SREG(51) = this->unk_64;
    SREG(52) = this->unk_60;
    SREG(53) = this->unk_5C;
    SREG(54) = this->unk_58;

    if (SREG(58) == 1) {
        SREG(58) = 0;
        
        switch (SREG(59)) {
            case 1:
                osSyncPrintf("osViModePalLan1\n");
                func_800AC030(&osViModePalLan1);
                break;
            case 2:
                osSyncPrintf("osViModeFpalLan1\n");
                func_800AC030(&osViModeFpalLan1);
                break;
            default:
                osSyncPrintf("Custom\n");
                func_800AC030(&this->viMode);
                break;
        }
    }
}

// ViMode_UpdateFieldsFromRegs
void func_800AC9A4(ViModeContext* this) {
    // width?
    if ((SREG(49) & ~3) == 1) {
        SREG(49) += 4;
    }

    this->unk_68 = SREG(48); // use gViMode?
    this->width = SREG(49) & ~0x3;
    this->height = SREG(50);
    this->unk_64 = SREG(51);
    this->unk_60 = SREG(52);
    this->unk_5C = SREG(53);
    this->unk_58 = SREG(54);
}

// ViMode_Init
void func_800ACA28(ViModeContext* this) {
    this->unk_68 = 0;
    this->width = SCREEN_WIDTH; // 54
    this->height = SCREEN_HEIGHT; // 50
    this->unk_5C = 0;
    this->unk_58 = 0;
    this->unk_64 = 0;
    this->unk_60 = 0;
    this->viFeatures = OS_VI_DITHER_FILTER_ON | OS_VI_GAMMA_OFF;
    this->tvType = osTvType;
    this->unk_7C = true;
    this->unk_78 = true;
    this->unk_74 = false;
    this->unk_70 = true;
    func_800AC89C(this);
}

// ViMode_Destroy
void func_800ACA90(ViModeContext* this) {

}

// ViMode_UpdateComRegsCtrl
void func_800ACA98(ViModeContext* this, s32 flag) {

    s32 mode = this->viMode.comRegs.ctrl;

    if (flag & OS_VI_GAMMA_ON) {
        mode |= OS_VI_GAMMA;
    }
    if (flag & OS_VI_GAMMA_OFF) {
        mode &= ~OS_VI_GAMMA;
    }

    if (flag & OS_VI_GAMMA_DITHER_ON) {
        mode |= OS_VI_GAMMA_DITHER;
    }
    if (flag & OS_VI_GAMMA_DITHER_OFF) {
        mode &= ~OS_VI_GAMMA_DITHER;
    }

    if (flag & OS_VI_DIVOT_ON) {
        mode |= OS_VI_DIVOT;
    }
    if (flag & OS_VI_DIVOT_OFF) {
        mode &= ~OS_VI_DIVOT;
    }

    this->viMode.comRegs.ctrl = mode;
}

// ViMode_Update
void func_800ACAF8(ViModeContext* this, Input* input) {

    func_800AC9A4(this);

    if (this->unk_68 == 1 || this->unk_68 == 2 || this->unk_68 == 3) {
        gScreenWidth = this->width;
        gScreenHeight = this->height;

        if (CHECK_BTN_ALL(input->cur.button, BTN_START | BTN_CRIGHT | BTN_CUP)) {
            func_800ACA28(this);
        }
        if (CHECK_BTN_ALL(input->cur.button, BTN_CUP)) {
            if (CHECK_BTN_ALL(input->cur.button, BTN_DUP)) {
                this->unk_64--;
            }
            if (CHECK_BTN_ALL(input->cur.button, BTN_DDOWN)) {
                this->unk_64++;
            }
            if (CHECK_BTN_ALL(input->cur.button, BTN_DLEFT)) {
                this->unk_5C--;
            }
            if (CHECK_BTN_ALL(input->cur.button, BTN_DRIGHT)) {
                this->unk_5C++;
            }
        }
        if (CHECK_BTN_ALL(input->cur.button, BTN_CRIGHT)) {
            if (CHECK_BTN_ALL(input->cur.button, BTN_DUP)) {
                this->unk_60--;
            }
            if (CHECK_BTN_ALL(input->cur.button, BTN_DDOWN)) {
                this->unk_60++;
            }
            if (CHECK_BTN_ALL(input->cur.button, BTN_DLEFT)) {
                this->unk_58--;
            }
            if (CHECK_BTN_ALL(input->cur.button, BTN_DRIGHT)) {
                this->unk_58++;
            }
        }
        if (CHECK_BTN_ALL(input->cur.button, BTN_CDOWN)) {
            if (CHECK_BTN_ALL(input->press.button, BTN_DUP)) {
                this->unk_70 = !this->unk_70;
            }
            if (CHECK_BTN_ALL(input->press.button, BTN_DDOWN)) {
                this->unk_74 = !this->unk_74;
            }
            if (CHECK_BTN_ALL(input->press.button, BTN_DLEFT)) {
                this->unk_78 = !this->unk_78;
            }
            if (CHECK_BTN_ALL(input->press.button, BTN_DRIGHT)) {
                this->unk_7C = !this->unk_7C;
            }
        }

        if (this->unk_68 >= 2) {
            if (this->unk_5C < -16) {
                this->unk_5C = -16;
            }
            if (this->unk_64 < -50) {
                this->unk_64 = -50;
            }
            if (this->unk_58 > 16) {
                this->unk_58 = 16;
            }
            if (this->unk_60 > 50) {
                this->unk_60 = 50;
            }
        }
        else {
            if (this->unk_5C < 0) {
                this->unk_5C = 0;
            }
            if (this->unk_64 < 0) {
                this->unk_64 = 0;
            }
            if (this->unk_58 > 0) {
                this->unk_58 = 0;
            }
            if (this->unk_60 > 0) {
                this->unk_60 = 0;
            }
        }

        func_800AC2F4(this, 0x1C, osTvType, this->unk_70, this->unk_74, this->unk_78, this->unk_7C, this->width, this->height, this->unk_5C, this->unk_58, this->unk_64, this->unk_60);
        func_800ACA98(this, this->viFeatures);
        if (this->unk_68 == 3) {
            func_800AC030(&osViModeNtscLan1);
            func_800AC030(&this->viMode);
            this->unk_68 = 2;
        }
    }

    func_800AC89C(this);
}
