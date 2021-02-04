#pragma _permuter latedefine start
#pragma _permuter define LOG(exp,value,format,file,line) do { LogUtils_LogThreadId(file, line); osSyncPrintf(exp " = " format "\n", value); } while (0)
void LOG();
#pragma _permuter latedefine end
typedef unsigned long size_t;
typedef signed char s8;
typedef unsigned char u8;
typedef signed short int s16;
typedef unsigned short int u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long int s64;
typedef unsigned long long int u64;
typedef volatile u8 vu8;
typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef volatile u64 vu64;
typedef volatile s8 vs8;
typedef volatile s16 vs16;
typedef volatile s32 vs32;
typedef volatile s64 vs64;
typedef float f32;
typedef double f64;
typedef long int Mtx_t[4][4];
typedef union {
    Mtx_t m;
    long long int forc_structure_alignment;
} Mtx;
typedef float MtxF_t[4][4];
typedef union {
    MtxF_t mf;
    struct {
        float xx, xy, xz, xw,
              yx, yy, yz, yw,
              zx, zy, zz, zw,
              wx, wy, wz, ww;
    };
} MtxF;
typedef union {
    struct {
        u32 hi;
        u32 lo;
    } word;
    f64 d;
} du;
typedef union {
    u32 i;
    f32 f;
} fu;
extern f32 __libm_qnan_f;
typedef u32 OSIntMask;
typedef s32 OSPri;
typedef s32 OSId;
typedef union {
    struct {
                   f32 f_odd;
                   f32 f_even;
    } f;
} __OSfp;
typedef struct {
                u64 at, v0, v1, a0, a1, a2, a3;
                u64 t0, t1, t2, t3, t4, t5, t6, t7;
                u64 s0, s1, s2, s3, s4, s5, s6, s7;
                u64 t8, t9, gp, sp, s8, ra;
                u64 lo, hi;
                u32 sr, pc, cause, badvaddr, rcp;
                u32 fpcsr;
                __OSfp fp0, fp2, fp4, fp6, fp8, fp10, fp12, fp14;
                __OSfp fp16, fp18, fp20, fp22, fp24, fp26, fp28, fp30;
} __OSThreadContext;
typedef struct {
               u32 flag;
               u32 count;
               u64 time;
} __OSThreadprofile;
typedef struct OSThread {
             struct OSThread* next;
             OSPri priority;
             struct OSThread** queue;
             struct OSThread* tlnext;
             u16 state;
             u16 flags;
             OSId id;
             s32 fp;
             __OSThreadprofile* thprof;
             __OSThreadContext context;
} OSThread;
typedef void* OSMesg;
typedef u32 OSEvent;
typedef struct OSMesgQueue {
               OSThread* mtqueue;
               OSThread* fullqueue;
               s32 validCount;
               s32 first;
               s32 msgCount;
               OSMesg* msg;
} OSMesgQueue;
typedef u64 OSTime;
typedef struct OSTimer {
               struct OSTimer* next;
               struct OSTimer* prev;
               OSTime interval;
               OSTime value;
               OSMesgQueue* mq;
               OSMesg msg;
} OSTimer;
typedef struct {
               u32 type;
               u32 flags;
               u64* ucode_boot;
               u32 ucode_boot_size;
               u64* ucode;
               u32 ucode_size;
               u64* ucode_data;
               u32 ucode_data_size;
               u64* dram_stack;
               u32 dram_stack_size;
               u64* output_buff;
               u64* output_buff_size;
               u64* data_ptr;
               u32 data_size;
               u64* yield_data_ptr;
               u32 yield_data_size;
} OSTask_t;
typedef union
{
    OSTask_t t;
    long long int force_structure_alignment;
} OSTask;
typedef u32 OSYieldResult;
typedef struct {
               u32 ctrl;
               u32 width;
               u32 burst;
               u32 vSync;
               u32 hSync;
               u32 leap;
               u32 hStart;
               u32 xScale;
               u32 vCurrent;
} OSViCommonRegs;
typedef struct {
               u32 origin;
               u32 yScale;
               u32 vStart;
               u32 vBurst;
               u32 vIntr;
} OSViFieldRegs;
typedef struct {
               u8 type;
               OSViCommonRegs comRegs;
               OSViFieldRegs fldRegs[2];
} OSViMode;
typedef struct {
              f32 factor;
              u16 offset;
              u32 scale;
} __OSViScale;
typedef struct {
               u16 state;
               u16 retraceCount;
               void* buffer;
               OSViMode* modep;
               u32 features;
               OSMesgQueue* mq;
               OSMesg* msg;
               __OSViScale x;
               __OSViScale y;
} OSViContext;
typedef struct {
               u32 errStatus;
               void* dramAddr;
               void* C2Addr;
               u32 sectorSize;
               u32 C1ErrNum;
               u32 C1ErrSector[4];
} __OSBlockInfo;
typedef struct {
               u32 cmdType;
               u16 transferMode;
               u16 blockNum;
               s32 sectorNum;
               u32 devAddr;
               u32 bmCtlShadow;
               u32 seqCtlShadow;
               __OSBlockInfo block[2];
} __OSTranxInfo;
typedef struct OSPiHandle {
               struct OSPiHandle* next;
               u8 type;
               u8 latency;
               u8 pageSize;
               u8 relDuration;
               u8 pulse;
               u8 domain;
               u32 baseAddress;
               u32 speed;
               __OSTranxInfo transferInfo;
} OSPiHandle;
typedef struct {
               u8 type;
               u32 address;
} OSPiInfo;
typedef struct {
               u16 type;
               u8 pri;
               u8 status;
               OSMesgQueue* retQueue;
} OSIoMesgHdr;
typedef struct {
               OSIoMesgHdr hdr;
               void* dramAddr;
               u32 devAddr;
               size_t size;
               OSPiHandle* piHandle;
} OSIoMesg;
typedef struct {
               u32 ram[15];
               u32 status;
} OSPifRam;
typedef struct {
               u16 type;
               u8 status;
               u8 errno;
} OSContStatus;
typedef struct {
               u16 button;
               s8 stick_x;
               s8 stick_y;
               u8 errno;
} OSContPad;
typedef struct {
               void* address;
               u8 databuffer[32];
               u8 addressCrc;
               u8 dataCrc;
               u8 errno;
} OSContRamIo;
typedef struct {
               u8 align;
               u8 txsize;
               u8 rxsize;
               u8 poll;
               u8 typeh;
               u8 typel;
               u8 status;
               u8 align1;
} __OSContRequestHeader;
typedef struct {
               u8 txsize;
               u8 rxsize;
               u8 poll;
               u8 typeh;
               u8 typel;
               u8 status;
} __OSContRequestHeaderAligned;
typedef struct {
               u8 unk_00;
               u8 txsize;
               u8 rxsize;
               u8 poll;
               u8 hi;
               u8 lo;
               u8 data[32];
               u8 datacrc;
} __OSContRamHeader;
typedef struct {
               u8 align;
               u8 txsize;
               u8 rxsize;
               u8 poll;
               u16 button;
               s8 joyX;
               s8 joyY;
} __OSContReadHeader;
typedef char* va_list;
typedef struct {
              union {
                  s64 ll;
                  f64 ld;
    } v;
              char* s;
              s32 n0;
               s32 nz0;
               s32 n1;
               s32 nz1;
               s32 n2;
               s32 nz2;
               s32 prec;
               s32 width;
               u32 nchar;
               u32 flags;
               u8 qual;
} _Pft;
typedef struct {
 short ob[3];
 unsigned short flag;
 short tc[2];
 unsigned char cn[4];
} Vtx_t;
typedef struct {
 short ob[3];
 unsigned short flag;
 short tc[2];
 signed char n[3];
 unsigned char a;
} Vtx_tn;
typedef union {
    Vtx_t v;
    Vtx_tn n;
    long long int force_structure_alignment;
} Vtx;
typedef struct {
  void *SourceImagePointer;
  void *TlutPointer;
  short Stride;
  short SubImageWidth;
  short SubImageHeight;
  char SourceImageType;
  char SourceImageBitSize;
  short SourceImageOffsetS;
  short SourceImageOffsetT;
  char dummy[4];
} uSprite_t;
typedef union {
  uSprite_t s;
  long long int force_structure_allignment[3];
} uSprite;
typedef struct {
 unsigned char flag;
 unsigned char v[3];
} Tri;
typedef struct {
 short vscale[4];
 short vtrans[4];
} Vp_t;
typedef union {
    Vp_t vp;
    long long int force_structure_alignment;
} Vp;
typedef struct {
  unsigned char col[3];
  char pad1;
  unsigned char colc[3];
  char pad2;
  signed char dir[3];
  char pad3;
} Light_t;
typedef struct {
  unsigned char col[3];
  char pad1;
  unsigned char colc[3];
  char pad2;
} Ambient_t;
typedef struct {
  int x1,y1,x2,y2;
} Hilite_t;
typedef union {
    Light_t l;
    long long int force_structure_alignment[2];
} Light;
typedef union {
    Ambient_t l;
    long long int force_structure_alignment[1];
} Ambient;
typedef struct {
    Ambient a;
    Light l[7];
} Lightsn;
typedef struct {
    Ambient a;
    Light l[1];
} Lights0;
typedef struct {
    Ambient a;
    Light l[1];
} Lights1;
typedef struct {
    Ambient a;
    Light l[2];
} Lights2;
typedef struct {
    Ambient a;
    Light l[3];
} Lights3;
typedef struct {
    Ambient a;
    Light l[4];
} Lights4;
typedef struct {
    Ambient a;
    Light l[5];
} Lights5;
typedef struct {
    Ambient a;
    Light l[6];
} Lights6;
typedef struct {
    Ambient a;
    Light l[7];
} Lights7;
typedef struct {
    Light l[2];
} LookAt;
typedef union {
    Hilite_t h;
    long int force_structure_alignment[4];
} Hilite;
typedef struct {
 int cmd:8;
 unsigned int par:8;
 unsigned int len:16;
 unsigned int addr;
} Gdma;
typedef struct {
  int cmd:8;
  int pad:24;
  Tri tri;
} Gtri;
typedef struct {
  int cmd:8;
  int pad1:24;
  int pad2:24;
  unsigned char param:8;
} Gpopmtx;
typedef struct {
  int cmd:8;
  int pad0:8;
  int mw_index:8;
  int number:8;
  int pad1:8;
  int base:24;
} Gsegment;
typedef struct {
  int cmd:8;
  int pad0:8;
  int sft:8;
  int len:8;
  unsigned int data:32;
} GsetothermodeL;
typedef struct {
  int cmd:8;
  int pad0:8;
  int sft:8;
  int len:8;
  unsigned int data:32;
} GsetothermodeH;
typedef struct {
  unsigned char cmd;
  unsigned char lodscale;
  unsigned char tile;
  unsigned char on;
  unsigned short s;
  unsigned short t;
} Gtexture;
typedef struct {
  int cmd:8;
  int pad:24;
  Tri line;
} Gline3D;
typedef struct {
  int cmd:8;
  int pad1:24;
  short int pad2;
  short int scale;
} Gperspnorm;
typedef struct {
                int cmd:8;
                unsigned int fmt:3;
                unsigned int siz:2;
                unsigned int pad:7;
                unsigned int wd:12;
                unsigned int dram;
} Gsetimg;
typedef struct {
  int cmd:8;
  unsigned int muxs0:24;
  unsigned int muxs1:32;
} Gsetcombine;
typedef struct {
  int cmd:8;
  unsigned char pad;
  unsigned char prim_min_level;
  unsigned char prim_level;
  unsigned long color;
} Gsetcolor;
typedef struct {
  int cmd:8;
  int x0:10;
  int x0frac:2;
  int y0:10;
  int y0frac:2;
  unsigned int pad:8;
  int x1:10;
  int x1frac:2;
  int y1:10;
  int y1frac:2;
} Gfillrect;
typedef struct {
  int cmd:8;
  unsigned int fmt:3;
  unsigned int siz:2;
  unsigned int pad0:1;
  unsigned int line:9;
  unsigned int tmem:9;
  unsigned int pad1:5;
  unsigned int tile:3;
  unsigned int palette:4;
  unsigned int ct:1;
  unsigned int mt:1;
  unsigned int maskt:4;
  unsigned int shiftt:4;
  unsigned int cs:1;
  unsigned int ms:1;
  unsigned int masks:4;
  unsigned int shifts:4;
} Gsettile;
typedef struct {
  int cmd:8;
  unsigned int sl:12;
  unsigned int tl:12;
  int pad:5;
  unsigned int tile:3;
  unsigned int sh:12;
  unsigned int th:12;
} Gloadtile;
typedef Gloadtile Gloadblock;
typedef Gloadtile Gsettilesize;
typedef Gloadtile Gloadtlut;
typedef struct {
  unsigned int cmd:8;
  unsigned int xl:12;
  unsigned int yl:12;
  unsigned int pad1:5;
  unsigned int tile:3;
  unsigned int xh:12;
  unsigned int yh:12;
  unsigned int s:16;
  unsigned int t:16;
  unsigned int dsdx:16;
  unsigned int dtdy:16;
} Gtexrect;
typedef struct {
    unsigned long w0;
    unsigned long w1;
    unsigned long w2;
    unsigned long w3;
} TexRect;
typedef struct {
 unsigned int w0;
 unsigned int w1;
} Gwords;
typedef union {
 Gwords words;
 Gdma dma;
 Gtri tri;
 Gline3D line;
 Gpopmtx popmtx;
 Gsegment segment;
 GsetothermodeH setothermodeH;
 GsetothermodeL setothermodeL;
 Gtexture texture;
 Gperspnorm perspnorm;
 Gsetimg setimg;
 Gsetcombine setcombine;
 Gsetcolor setcolor;
 Gfillrect fillrect;
 Gsettile settile;
 Gloadtile loadtile;
 Gsettilesize settilesize;
 Gloadtlut loadtlut;
        long long int force_structure_alignment;
} Gfx;
typedef struct
{
    unsigned int cmd : 8;
    unsigned int flags : 8;
    unsigned int gain : 16;
    unsigned int addr;
} Aadpcm;
typedef struct
{
    unsigned int cmd : 8;
    unsigned int flags : 8;
    unsigned int gain : 16;
    unsigned int addr;
} Apolef;
typedef struct
{
    unsigned int cmd : 8;
    unsigned int flags : 8;
    unsigned int pad1 : 16;
    unsigned int addr;
} Aenvelope;
typedef struct
{
    unsigned int cmd : 8;
    unsigned int pad1 : 8;
    unsigned int dmem : 16;
    unsigned int pad2 : 16;
    unsigned int count : 16;
} Aclearbuff;
typedef struct
{
    unsigned int cmd : 8;
    unsigned int pad1 : 8;
    unsigned int pad2 : 16;
    unsigned int inL : 16;
    unsigned int inR : 16;
} Ainterleave;
typedef struct
{
    unsigned int cmd : 8;
    unsigned int pad1 : 24;
    unsigned int addr;
} Aloadbuff;
typedef struct
{
    unsigned int cmd : 8;
    unsigned int flags : 8;
    unsigned int pad1 : 16;
    unsigned int addr;
} Aenvmixer;
typedef struct
{
    unsigned int cmd : 8;
    unsigned int flags : 8;
    unsigned int gain : 16;
    unsigned int dmemi : 16;
    unsigned int dmemo : 16;
} Amixer;
typedef struct
{
    unsigned int cmd : 8;
    unsigned int flags : 8;
    unsigned int dmem2 : 16;
    unsigned int addr;
} Apan;
typedef struct
{
    unsigned int cmd : 8;
    unsigned int flags : 8;
    unsigned int pitch : 16;
    unsigned int addr;
} Aresample;
typedef struct
{
    unsigned int cmd : 8;
    unsigned int flags : 8;
    unsigned int pad1 : 16;
    unsigned int addr;
} Areverb;
typedef struct
{
    unsigned int cmd : 8;
    unsigned int pad1 : 24;
    unsigned int addr;
} Asavebuff;
typedef struct
{
    unsigned int cmd : 8;
    unsigned int pad1 : 24;
    unsigned int pad2 : 2;
    unsigned int number : 4;
    unsigned int base : 24;
} Asegment;
typedef struct
{
    unsigned int cmd : 8;
    unsigned int flags : 8;
    unsigned int dmemin : 16;
    unsigned int dmemout : 16;
    unsigned int count : 16;
} Asetbuff;
typedef struct
{
    unsigned int cmd : 8;
    unsigned int flags : 8;
    unsigned int vol : 16;
    unsigned int voltgt : 16;
    unsigned int volrate : 16;
} Asetvol;
typedef struct
{
    unsigned int cmd : 8;
    unsigned int pad1 : 8;
    unsigned int dmemin : 16;
    unsigned int dmemout : 16;
    unsigned int count : 16;
} Admemmove;
typedef struct
{
    unsigned int cmd : 8;
    unsigned int pad1 : 8;
    unsigned int count : 16;
    unsigned int addr;
} Aloadadpcm;
typedef struct
{
    unsigned int cmd : 8;
    unsigned int pad1 : 8;
    unsigned int pad2 : 16;
    unsigned int addr;
} Asetloop;
typedef struct
{
    unsigned int w0;
    unsigned int w1;
} Awords;
typedef union {
    Awords words;
    Aadpcm adpcm;
    Apolef polef;
    Aclearbuff clearbuff;
    Aenvelope envelope;
    Ainterleave interleave;
    Aloadbuff loadbuff;
    Aenvmixer envmixer;
    Aresample resample;
    Areverb reverb;
    Asavebuff savebuff;
    Asegment segment;
    Asetbuff setbuff;
    Asetvol setvol;
    Admemmove dmemmove;
    Aloadadpcm loadadpcm;
    Amixer mixer;
    Asetloop setloop;
    long long int force_union_align;
} Acmd;
typedef short ADPCM_STATE[16];
typedef short POLEF_STATE[4];
typedef short RESAMPLE_STATE[16];
typedef short ENVMIX_STATE[40];
typedef struct {
               s32 status;
               OSMesgQueue* queue;
               s32 channel;
               u8 id[32];
               u8 label[32];
               s32 version;
               s32 dir_size;
               s32 inode_table;
               s32 minode_table;
               s32 dir_table;
               s32 inodeStartPage;
               u8 banks;
               u8 activebank;
} OSPfs;
typedef struct {
               u32 file_size;
               u32 game_code;
               u16 company_code;
               char ext_name[4];
               char game_name[16];
} OSPfsState;
typedef union {
    struct {
                   u8 bank;
                   u8 page;
    } inode_t;
               u16 ipage;
} __OSInodeUnit;
typedef struct {
               __OSInodeUnit inodePage[128];
} __OSInode;
typedef struct {
               u32 game_code;
               u16 company_code;
               __OSInodeUnit start_page;
               u8 status;
               s8 reserved;
               u16 data_sum;
               u8 ext_name[4];
               u8 game_name[16];
} __OSDir;
typedef struct {
               u32 repaired;
               u32 random;
               u64 serialMid;
               u64 serialLow;
               u16 deviceid;
               u8 banks;
               u8 version;
               u16 checksum;
               u16 invertedChecksum;
} __OSPackId;
typedef struct {
                __OSInode inode;
                u8 bank;
                u8 map[(8 * 32)];
} __OSInodeCache;
typedef struct {
  u16 imageX;
  u16 imageW;
  s16 frameX;
  u16 frameW;
  u16 imageY;
  u16 imageH;
  s16 frameY;
  u16 frameH;
  u64 *imagePtr;
  u16 imageLoad;
  u8 imageFmt;
  u8 imageSiz;
  u16 imagePal;
  u16 imageFlip;
  u16 tmemW;
  u16 tmemH;
  u16 tmemLoadSH;
  u16 tmemLoadTH;
  u16 tmemSizeW;
  u16 tmemSize;
} uObjBg_t;
typedef struct {
  u16 imageX;
  u16 imageW;
  s16 frameX;
  u16 frameW;
  u16 imageY;
  u16 imageH;
  s16 frameY;
  u16 frameH;
  u64 *imagePtr;
  u16 imageLoad;
  u8 imageFmt;
  u8 imageSiz;
  u16 imagePal;
  u16 imageFlip;
  u16 scaleW;
  u16 scaleH;
  s32 imageYorig;
  u8 padding[4];
} uObjScaleBg_t;
typedef union {
  uObjBg_t b;
  uObjScaleBg_t s;
  long long int force_structure_alignment;
} uObjBg;
typedef struct {
  s16 objX;
  u16 scaleW;
  u16 imageW;
  u16 paddingX;
  s16 objY;
  u16 scaleH;
  u16 imageH;
  u16 paddingY;
  u16 imageStride;
  u16 imageAdrs;
  u8 imageFmt;
  u8 imageSiz;
  u8 imagePal;
  u8 imageFlags;
} uObjSprite_t;
typedef union {
  uObjSprite_t s;
  long long int force_structure_alignment;
} uObjSprite;
typedef struct {
  s32 A, B, C, D;
  s16 X, Y;
  u16 BaseScaleX;
  u16 BaseScaleY;
} uObjMtx_t;
typedef union {
  uObjMtx_t m;
  long long int force_structure_alignment;
} uObjMtx;
typedef struct {
  s16 X, Y;
  u16 BaseScaleX;
  u16 BaseScaleY;
} uObjSubMtx_t;
typedef union {
  uObjSubMtx_t m;
  long long int force_structure_alignment;
} uObjSubMtx;
typedef struct {
  u32 type;
  u64 *image;
  u16 tmem;
  u16 tsize;
  u16 tline;
  u16 sid;
  u32 flag;
  u32 mask;
} uObjTxtrBlock_t;
typedef struct {
  u32 type;
  u64 *image;
  u16 tmem;
  u16 twidth;
  u16 theight;
  u16 sid;
  u32 flag;
  u32 mask;
} uObjTxtrTile_t;
typedef struct {
  u32 type;
  u64 *image;
  u16 phead;
  u16 pnum;
  u16 zero;
  u16 sid;
  u32 flag;
  u32 mask;
} uObjTxtrTLUT_t;
typedef union {
  uObjTxtrBlock_t block;
  uObjTxtrTile_t tile;
  uObjTxtrTLUT_t tlut;
  long long int force_structure_alignment;
} uObjTxtr;
typedef struct {
  uObjTxtr txtr;
  uObjSprite sprite;
} uObjTxSprite;
extern u64 gspS2DEX_fifoTextStart[], gspS2DEX_fifoTextEnd[];
extern u64 gspS2DEX_fifoDataStart[], gspS2DEX_fifoDataEnd[];
extern u64 gspS2DEX_fifo_dTextStart[], gspS2DEX_fifo_dTextEnd[];
extern u64 gspS2DEX_fifo_dDataStart[], gspS2DEX_fifo_dDataEnd[];
extern u64 gspS2DEX2_fifoTextStart[], gspS2DEX2_fifoTextEnd[];
extern u64 gspS2DEX2_fifoDataStart[], gspS2DEX2_fifoDataEnd[];
extern u64 gspS2DEX2_xbusTextStart[], gspS2DEX2_xbusTextEnd[];
extern u64 gspS2DEX2_xbusDataStart[], gspS2DEX2_xbusDataEnd[];
extern void guS2DInitBg(uObjBg *);
  extern void guS2D2EmuSetScissor(u32, u32, u32, u32, u8);
  extern void guS2D2EmuBgRect1Cyc(Gfx **, uObjBg *);
typedef struct {
    f32 x, y;
} Vec2f;
typedef struct {
    f32 x, y, z;
} Vec3f;
typedef struct {
    u16 x, y, z;
} Vec3us;
typedef struct {
    s16 x, y, z;
} Vec3s;
typedef struct {
    s32 x, y, z;
} Vec3i;
typedef struct {
    Vec3s center;
    s16 radius;
} Sphere16;
typedef struct {
    Vec3f center;
    f32 radius;
} Spheref;
typedef struct {
    Vec3f normal;
    f32 originDist;
} Plane;
typedef struct {
    Vec3f vtx[3];
    Plane plane;
} TriNorm;
typedef struct {
                 s16 radius;
                 s16 height;
                 s16 yShift;
                 Vec3s pos;
} Cylinder16;
typedef struct {
               f32 radius;
               f32 height;
               f32 yShift;
               Vec3f pos;
} Cylinderf;
typedef struct {
                 Vec3f point;
                 Vec3f dir;
} InfiniteLine;
typedef struct {
                 Vec3f a;
                 Vec3f b;
} Linef;
typedef struct {
               f32 r;
               s16 pitch;
               s16 yaw;
} VecSph;
typedef struct {
               u8 buttonItems[4];
               u8 cButtonSlots[3];
               u16 equipment;
} ItemEquips;
typedef struct {
               u8 items[24];
               s8 ammo[16];
               u16 equipment;
               u32 upgrades;
               u32 questItems;
               u8 dungeonItems[20];
               s8 dungeonKeys[19];
               s8 defenseHearts;
               s16 gsTokens;
} Inventory;
typedef struct {
               u32 chest;
               u32 swch;
               u32 clear;
               u32 collect;
               u32 unk;
               u32 rooms;
               u32 floors;
} SavedSceneFlags;
typedef struct {
               s16 scene;
               Vec3s pos;
               s16 angle;
} HorseData;
typedef struct {
               Vec3f pos;
               s16 yaw;
               s16 playerParams;
               s16 entranceIndex;
               u8 roomIndex;
               s8 data;
               u32 tempSwchFlags;
               u32 tempCollectFlags;
} RespawnData;
typedef struct {
               Vec3i pos;
               s32 yaw;
               s32 playerParams;
               s32 entranceIndex;
               s32 roomIndex;
               s32 set;
               s32 tempSwchFlags;
               s32 tempCollectFlags;
} FaroresWindData;
typedef struct {
                 s32 entranceIndex;
                 s32 linkAge;
                 s32 cutsceneIndex;
                 u16 dayTime;
                 s32 nightFlag;
                 s32 numDays;
                 s32 unk_18;
                 char newf[6];
                 s16 deaths;
                 char playerName[8];
                 s16 n64ddFlag;
                 s16 healthCapacity;
                 s16 health;
                 s8 magicLevel;
                 s8 magic;
                 s16 rupees;
                 u16 swordHealth;
                 u16 naviTimer;
                 u8 magicAcquired;
                 char unk_3B[0x01];
                 u8 doubleMagic;
                 u8 doubleDefense;
                 u8 bgsFlag;
                 u8 ocarinaGameReward;
                 ItemEquips childEquips;
                 ItemEquips adultEquips;
                 u32 unk_54;
                 char unk_58[0x0E];
                 s16 savedSceneNum;
                 ItemEquips equips;
                 Inventory inventory;
                 SavedSceneFlags sceneFlags[124];
                 FaroresWindData fw;
                 char unk_E8C[0x10];
                 s32 gsFlags[6];
                 char unk_EB4[0x4];
                 s32 highScores[7];
                 u16 eventChkInf[14];
                 u16 itemGetInf[4];
                 u16 infTable[30];
                 char unk_F34[0x04];
                 u32 worldMapAreaData;
                 char unk_F3C[0x4];
                 u8 scarecrowCustomSongSet;
                 u8 scarecrowCustomSong[0x360];
                 char unk_12A1[0x24];
                 u8 scarecrowSpawnSongSet;
                 u8 scarecrowSpawnSong[0x80];
                 char unk_1346[0x02];
                 HorseData horseData;
                 u16 checksum;
                 s32 fileNum;
                 char unk_1358[0x0004];
                 s32 gameMode;
                 s32 sceneSetupIndex;
                 s32 respawnFlag;
                 RespawnData respawn[3];
                 f32 entranceSpeed;
                 u16 entranceSound;
                 char unk_13C2[0x0001];
                 u8 unk_13C3;
                 s16 dogParams;
                 u8 textTriggerFlags;
                 u8 showTitleCard;
                 s16 nayrusLoveTimer;
                 char unk_13CA[0x0002];
                 s16 rupeeAccumulator;
                 s16 timer1State;
                 s16 timer1Value;
                 s16 timer2State;
                 s16 timer2Value;
                 s16 timerX[2];
                 s16 timerY[2];
                 char unk_13DE[0x0002];
                 u8 seqIndex;
                 u8 nightSeqIndex;
                 u8 buttonStatus[5];
                 u8 unk_13E7;
                 u16 unk_13E8;
                 u16 unk_13EA;
                 u16 unk_13EC;
                 u16 unk_13EE;
                 s16 unk_13F0;
                 s16 unk_13F2;
                 s16 unk_13F4;
                 s16 unk_13F6;
                 s16 unk_13F8;
                 u16 eventInf[4];
                 u16 mapIndex;
                 u16 minigameState;
                 u16 minigameScore;
                 char unk_1408[0x0001];
                 u8 language;
                 u8 audioSetting;
                 char unk_140B[0x0001];
                 u8 zTargetSetting;
                 u16 unk_140E;
                 u8 unk_1410;
                 char unk_1411[0x0001];
                 u16 nextCutsceneIndex;
                 u8 cutsceneTrigger;
                 u8 chamberCutsceneNum;
                 u16 nextDayTime;
                 u8 fadeDuration;
                 u8 unk_1419;
                 u16 environmentTime;
                 u8 dogIsLost;
                 u8 nextTransition;
                 char unk_141E[0x0002];
                 s16 worldMapArea;
                 s16 unk_1422;
                 s16 healthAccumulator;
} SaveContext;
typedef enum {
               RESPAWN_MODE_DOWN,
               RESPAWN_MODE_RETURN,
               RESPAWN_MODE_TOP
} RespawnMode;
typedef enum {
               BTN_ENABLED,
               BTN_DISABLED = 0xFF
} ButtonStatus;
typedef enum {
               HS_HBA,
               HS_POE_POINTS,
               HS_FISHING,
               HS_HORSE_RACE,
               HS_MARATHON,
               HS_UNK_05,
               HS_DAMPE_RACE
} HighScores;
typedef struct {
    u8 r, g, b;
} Color_RGB8;
typedef struct {
    u8 r, g, b, a;
} Color_RGBA8;
typedef union {
    struct {
        u8 r, g, b, a;
    };
    u32 rgba;
} Color_RGBA8_u32;
typedef struct {
    f32 r, g, b, a;
} Color_RGBAf;
typedef struct {
              s16 x;
              s16 y;
              s16 z;
              u8 color[3];
              u8 drawGlow;
              s16 radius;
} LightPoint;
typedef struct {
              s8 x;
              s8 y;
              s8 z;
              u8 color[3];
} LightDirectional;
typedef union {
    LightPoint point;
    LightDirectional dir;
} LightParams;
typedef struct {
              u8 type;
              LightParams params;
} LightInfo;
typedef struct Lights {
               u8 numLights;
               Lightsn l;
} Lights;
typedef struct LightNode {
              LightInfo* info;
              struct LightNode* prev;
              struct LightNode* next;
} LightNode;
typedef struct {
              LightNode* listHead;
              Color_RGB8 ambient;
              u8 unk_07;
              u8 unk_08;
              u8 unk_09;
              s16 unk_0A;
              s16 unk_0C;
} LightContext;
typedef enum {
               LIGHT_POINT_NOGLOW,
               LIGHT_DIRECTIONAL,
               LIGHT_POINT_GLOW
} LightType;
typedef void (*LightsBindFunc)(Lights* lights, LightParams* params, Vec3f* vec);
struct GlobalContext;
struct Actor;
struct DynaPolyActor;
typedef struct {
    Vec3f scale;
    Vec3s rot;
    Vec3f pos;
} ScaleRotPos;
typedef struct {
               u16 type;
    union {
        u16 vtxData[3];
        struct {
                       u16 flags_vIA;
                       u16 flags_vIB;
                       u16 vIC;
        };
    };
               Vec3s normal;
               s16 dist;
} CollisionPoly;
typedef struct {
               u16 cameraSType;
               s16 numCameras;
               Vec3s* camPosData;
} CamData;
typedef struct {
               s16 xMin;
               s16 ySurface;
               s16 zMin;
               s16 xLength;
               s16 zLength;
               u32 properties;
} WaterBox;
typedef struct {
    u32 data[2];
} SurfaceType;
typedef struct {
               Vec3s minBounds;
               Vec3s maxBounds;
               u16 nbVertices;
               Vec3s* vtxList;
               u16 nbPolygons;
               CollisionPoly* polyList;
               SurfaceType* surfaceTypeList;
               CamData* cameraDataList;
               u16 nbWaterBoxes;
               WaterBox* waterBoxes;
} CollisionHeader;
typedef struct {
    s16 polyId;
    u16 next;
} SSNode;
typedef struct {
    u16 head;
} SSList;
typedef struct {
               u16 max;
               u16 count;
               SSNode* tbl;
               u8* polyCheckTbl;
} SSNodeList;
typedef struct {
    SSNode* tbl;
    s32 count;
    s32 max;
} DynaSSNodeList;
typedef struct {
    SSList floor;
    SSList wall;
    SSList ceiling;
} StaticLookup;
typedef struct {
    u16 polyStartIndex;
    SSList ceiling;
    SSList wall;
    SSList floor;
} DynaLookup;
typedef struct {
               struct Actor* actor;
               CollisionHeader* colHeader;
               DynaLookup dynaLookup;
               u16 vtxStartIndex;
               ScaleRotPos prevTransform;
               ScaleRotPos curTransform;
               Sphere16 boundingSphere;
               f32 minY;
               f32 maxY;
} BgActor;
typedef struct {
                 u8 bitFlag;
                 BgActor bgActors[50];
                 u16 bgActorFlags[50];
                 CollisionPoly* polyList;
                 Vec3s* vtxList;
                 DynaSSNodeList polyNodes;
                 s32 polyNodesMax;
                 s32 polyListMax;
                 s32 vtxListMax;
} DynaCollisionContext;
typedef struct CollisionContext {
               CollisionHeader* colHeader;
               Vec3f minBounds;
               Vec3f maxBounds;
               Vec3i subdivAmount;
               Vec3f subdivLength;
               Vec3f subdivLengthInv;
               StaticLookup* lookupTbl;
               SSNodeList polyNodes;
               DynaCollisionContext dyna;
                 u32 memSize;
} CollisionContext;
typedef struct {
               struct GlobalContext* globalCtx;
               struct CollisionContext* colCtx;
               u16 xpFlags;
               CollisionPoly** resultPoly;
               f32 yIntersect;
               Vec3f* pos;
               s32* bgId;
               struct Actor* actor;
               u32 unk_20;
               f32 chkDist;
               DynaCollisionContext* dyna;
               SSList* ssList;
} DynaRaycast;
typedef struct {
               struct CollisionContext* colCtx;
               u16 xpFlags;
               DynaCollisionContext* dyna;
               SSList* ssList;
               Vec3f* posA;
               Vec3f* posB;
               Vec3f* posResult;
               CollisionPoly** resultPoly;
               s32 chkOneFace;
               f32* distSq;
               f32 chkDist;
} DynaLineTest;
typedef struct {
               u32 vromAddr;
               void* dramAddr;
               u32 size;
               char* filename;
               s32 line;
               s32 unk_14;
               OSMesgQueue* notifyQueue;
               OSMesg notifyMsg;
} DmaRequest;
typedef struct {
               u32 vromStart;
               u32 vromEnd;
               u32 romStart;
               u32 romEnd;
} DmaEntry;
extern u32 link_animetion_segment;
struct GlobalContext;
struct Actor;
struct SkelAnime;
typedef enum {
            ANIMMODE_LOOP,
            ANIMMODE_LOOP_INTERP,
            ANIMMODE_ONCE,
            ANIMMODE_ONCE_INTERP,
            ANIMMODE_LOOP_PARTIAL,
            ANIMMODE_LOOP_PARTIAL_INTERP
} AnimationModes;
typedef enum {
             ANIMTAPER_DECEL = -1,
             ANIMTAPER_NONE,
             ANIMTAPER_ACCEL
} AnimationTapers;
typedef struct {
               Vec3s jointPos;
               u8 child;
               u8 sibling;
               Gfx* dList;
} StandardLimb;
typedef struct {
               Vec3s jointPos;
               u8 child;
               u8 sibling;
               Gfx* dLists[2];
} LodLimb;
typedef struct {
               Vec3s jointPos;
               u8 child;
               u8 sibling;
               s32 unk_8;
               void* segment;
} SkinLimb;
typedef struct {
               void** segment;
               u8 limbCount;
} SkeletonHeader;
typedef struct {
               SkeletonHeader sh;
               u8 dListCount;
} FlexSkeletonHeader;
typedef struct {
               u16 x;
               u16 y;
               u16 z;
} JointIndex;
typedef struct {
               s16 frameCount;
} AnimationHeaderCommon;
typedef struct {
               AnimationHeaderCommon common;
               u32 segment;
} LinkAnimationHeader;
typedef struct {
               AnimationHeaderCommon common;
               s16* frameData;
               JointIndex* jointIndices;
               u16 staticIndexMax;
} AnimationHeader;
typedef struct {
               s16 xMax;
               s16 x;
               s16 yMax;
               s16 y;
               s16 zMax;
               s16 z;
} JointKey;
typedef struct {
               s16 frameCount;
               s16 limbCount;
               s16* frameData;
               JointKey* jointKey;
} AnimationHeader2;
typedef s32 (*OverrideLimbDrawOpa)(struct GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot,
                                   void*);
typedef void (*PostLimbDrawOpa)(struct GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void*);
typedef s32 (*OverrideLimbDraw)(struct GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot,
                                void*, Gfx** gfx);
typedef void (*PostLimbDraw)(struct GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void*, Gfx** gfx);
typedef enum {
    ANIMENTRY_LOADFRAME,
    ANIMENTRY_COPYALL,
    ANIMENTRY_INTERP,
    ANIMENTRY_COPYTRUE,
    ANIMENTRY_COPYFALSE,
    ANIMENTRY_MOVEACTOR
} AnimationType;
typedef struct {
                DmaRequest req;
                OSMesgQueue msgQueue;
                OSMesg msg;
} AnimEntryLoadFrame;
typedef struct {
                u8 queueFlag;
                u8 vecCount;
                Vec3s* dst;
                Vec3s* src;
} AnimEntryCopyAll;
typedef struct {
                u8 queueFlag;
                u8 vecCount;
                Vec3s* base;
                Vec3s* mod;
                f32 weight;
} AnimEntryInterp;
typedef struct {
                u8 queueFlag;
                u8 vecCount;
                Vec3s* dst;
                Vec3s* src;
                u8* copyFlag;
} AnimEntryCopyTrue;
typedef struct {
                u8 queueFlag;
                u8 vecCount;
                Vec3s* dst;
                Vec3s* src;
                u8* copyFlag;
} AnimEntryCopyFalse;
typedef struct {
                struct Actor* actor;
                struct SkelAnime* skelAnime;
                f32 unk_08;
} AnimEntryMoveActor;
typedef union {
    AnimEntryLoadFrame load;
    AnimEntryCopyAll copy;
    AnimEntryInterp interp;
    AnimEntryCopyTrue copy1;
    AnimEntryCopyFalse copy0;
    AnimEntryMoveActor move;
} AnimationEntryData;
typedef struct {
               u8 type;
               AnimationEntryData data;
} AnimationEntry;
typedef struct AnimationContext {
    s16 animationCount;
    AnimationEntry entries[50];
} AnimationContext;
typedef void (*AnimationEntryCallback)(struct GlobalContext* globalCtx, AnimationEntryData* data);
typedef struct {
                 u16 unk_00;
                 s16 unk_02;
                 s16 unk_04;
                 s16 unk_06;
                 f32 unk_08;
} TransformData;
typedef struct {
                 u8* refIndex;
                 TransformData* transformData;
                 s16* copyValues;
                 s16 unk_0C;
                 s16 unk_10;
} TransformUpdateIndex;
typedef struct {
                 u8 firstChildIdx;
                 u8 nextLimbIdx;
                 Gfx* dList[2];
} SkelCurveLimb;
typedef struct {
                 SkelCurveLimb** limbs;
                 u8 limbCount;
} SkelCurveLimbList;
typedef struct {
                 Vec3s scale;
                 Vec3s rot;
                 Vec3s pos;
} LimbTransform;
typedef struct {
                 u8 limbCount;
                 SkelCurveLimb** limbList;
                 TransformUpdateIndex* transUpdIdx;
                 f32 unk_0C;
                 f32 animFinalFrame;
                 f32 animSpeed;
                 f32 animCurFrame;
                 LimbTransform* transforms;
} SkelAnimeCurve;
typedef s32 (*OverrideCurveLimbDraw)(struct GlobalContext* globalCtx, SkelAnimeCurve* skelCurve, s32 limbIndex, void*);
typedef void (*PostCurveLimbDraw)(struct GlobalContext* globalCtx, SkelAnimeCurve* skelCurve, s32 limbIndex, void*);
typedef s32 (*AnimUpdateFunc)();
typedef struct SkelAnime {
               u8 limbCount;
               u8 mode;
               u8 dListCount;
               s8 taper;
               void** skeleton;
               void* animation;
               f32 startFrame;
               f32 endFrame;
               f32 animLength;
               f32 curFrame;
               f32 playSpeed;
               Vec3s* jointTable;
               Vec3s* morphTable;
               f32 morphWeight;
               f32 morphRate;
               s32 (*update)();
               s8 initFlags;
               u8 moveFlags;
               s16 prevRot;
               Vec3s prevTransl;
               Vec3s baseTransl;
} SkelAnime;
typedef struct {
                u16 unk_0;
                char unk_2[0x4];
                s8 unk_6;
                s8 unk_7;
                s8 unk_8;
                char unk_9[0x1];
} Struct_800A57C0;
typedef struct {
                u8 unk_0;
                s16 x;
                s16 y;
                s16 z;
                u8 unk_8;
} Struct_800A598C_2;
typedef struct {
                char unk_0[0x2];
                u16 unk_2;
                u32 unk_4;
                Gfx* unk_8;
} Struct_800A5E28;
typedef struct {
                u16 unk_0;
                u16 unk_2;
                u16 unk_4;
                s32 unk_8;
                s32 unk_C;
} Struct_800A598C;
typedef struct {
                u8 unk_0;
                Vtx* buf[2];
} SkinAvb;
typedef struct {
                SkeletonHeader* skeletonHeader;
                MtxF mtx;
                s32 avbCount;
                SkinAvb* avbTbl;
                SkelAnime skelAnime;
} PSkinAwb;
typedef void (*SkinCallback)(struct Actor*, struct GlobalContext*, PSkinAwb*);
typedef s32 (*SkinCallback2)(struct Actor*, struct GlobalContext*, s32, PSkinAwb*);
struct Actor;
typedef struct {
               struct Actor* actor;
               struct Actor* at;
               struct Actor* ac;
               struct Actor* oc;
               u8 atFlags;
               u8 acFlags;
               u8 ocFlags1;
               u8 ocFlags2;
               u8 colType;
               u8 shape;
} Collider;
typedef struct {
               u8 colType;
               u8 atFlags;
               u8 acFlags;
               u8 ocFlags1;
               u8 ocFlags2;
               u8 shape;
} ColliderInit;
typedef struct {
               u8 colType;
               u8 atFlags;
               u8 acFlags;
               u8 ocFlags1;
               u8 shape;
} ColliderInitType1;
typedef struct {
               struct Actor* actor;
               u8 atFlags;
               u8 acFlags;
               u8 ocFlags1;
               u8 shape;
} ColliderInitToActor;
typedef struct {
               u32 dmgFlags;
               u8 effect;
               u8 damage;
} ColliderTouch;
typedef struct {
               u32 dmgFlags;
               u8 effect;
               u8 defense;
               Vec3s hitPos;
} ColliderBump;
typedef struct {
               u32 dmgFlags;
               u8 effect;
               u8 defense;
} ColliderBumpInit;
typedef struct ColliderInfo {
               ColliderTouch toucher;
               ColliderBump bumper;
               u8 elemType;
               u8 toucherFlags;
               u8 bumperFlags;
               u8 ocElemFlags;
               Collider* atHit;
               Collider* acHit;
               struct ColliderInfo* atHitInfo;
               struct ColliderInfo* acHitInfo;
} ColliderInfo;
typedef struct {
               u8 elemType;
               ColliderTouch toucher;
               ColliderBumpInit bumper;
               u8 toucherFlags;
               u8 bumperFlags;
               u8 ocElemFlags;
} ColliderInfoInit;
typedef struct {
               Sphere16 modelSphere;
               Sphere16 worldSphere;
               f32 scale;
               u8 limb;
} ColliderJntSphElementDim;
typedef struct {
               u8 limb;
               Sphere16 modelSphere;
               s16 scale;
} ColliderJntSphElementDimInit;
typedef struct {
               ColliderInfo info;
               ColliderJntSphElementDim dim;
} ColliderJntSphElement;
typedef struct {
               ColliderInfoInit info;
               ColliderJntSphElementDimInit dim;
} ColliderJntSphElementInit;
typedef struct {
               Collider base;
               s32 count;
               ColliderJntSphElement* elements;
} ColliderJntSph;
typedef struct {
               ColliderInit base;
               s32 count;
               ColliderJntSphElementInit* elements;
} ColliderJntSphInit;
typedef struct {
               ColliderInitType1 base;
               s32 count;
               ColliderJntSphElementInit* elements;
} ColliderJntSphInitType1;
typedef struct {
               ColliderInitToActor base;
               s32 count;
               ColliderJntSphElementInit* elements;
} ColliderJntSphInitToActor;
typedef struct {
               Collider base;
               ColliderInfo info;
               Cylinder16 dim;
} ColliderCylinder;
typedef struct {
               ColliderInit base;
               ColliderInfoInit info;
               Cylinder16 dim;
} ColliderCylinderInit;
typedef struct {
               ColliderInitType1 base;
               ColliderInfoInit info;
               Cylinder16 dim;
} ColliderCylinderInitType1;
typedef struct {
               ColliderInitToActor base;
               ColliderInfoInit info;
               Cylinder16 dim;
} ColliderCylinderInitToActor;
typedef struct {
               Vec3f vtx[3];
} ColliderTrisElementDimInit;
typedef struct {
               ColliderInfo info;
               TriNorm dim;
} ColliderTrisElement;
typedef struct {
               ColliderInfoInit info;
               ColliderTrisElementDimInit dim;
} ColliderTrisElementInit;
typedef struct {
               Collider base;
               s32 count;
               ColliderTrisElement* elements;
} ColliderTris;
typedef struct {
               ColliderInit base;
               s32 count;
               ColliderTrisElementInit* elements;
} ColliderTrisInit;
typedef struct {
               ColliderInitType1 base;
               s32 count;
               ColliderTrisElementInit* elements;
} ColliderTrisInitType1;
typedef struct {
               Vec3f quad[4];
               Vec3s dcMid;
               Vec3s baMid;
               f32 acDist;
} ColliderQuadDim;
typedef struct {
               Vec3f quad[4];
} ColliderQuadDimInit;
typedef struct {
               ColliderInfo info;
               ColliderQuadDim dim;
} ColliderQuadElement;
typedef struct {
               Collider base;
               ColliderInfo info;
               ColliderQuadDim dim;
} ColliderQuad;
typedef struct {
               ColliderInit base;
               ColliderInfoInit info;
               ColliderQuadDimInit dim;
} ColliderQuadInit;
typedef struct {
               ColliderInitType1 base;
               ColliderInfoInit info;
               ColliderQuadDimInit dim;
} ColliderQuadInitType1;
typedef struct {
               Linef line;
               u16 ocFlags;
} OcLine;
typedef enum {
             COLTYPE_HIT0,
             COLTYPE_HIT1,
             COLTYPE_HIT2,
             COLTYPE_HIT3,
             COLTYPE_HIT4,
             COLTYPE_HIT5,
             COLTYPE_HIT6,
             COLTYPE_HIT7,
             COLTYPE_HIT8,
             COLTYPE_METAL,
             COLTYPE_NONE,
             COLTYPE_WOOD,
             COLTYPE_HARD,
             COLTYPE_TREE
} ColliderType;
typedef enum {
            COLSHAPE_JNTSPH,
            COLSHAPE_CYLINDER,
            COLSHAPE_TRIS,
            COLSHAPE_QUAD,
            COLSHAPE_INVALID
} ColliderShape;
typedef enum {
            ELEMTYPE_UNK0,
            ELEMTYPE_UNK1,
            ELEMTYPE_UNK2,
            ELEMTYPE_UNK3,
            ELEMTYPE_UNK4,
            ELEMTYPE_UNK5,
            ELEMTYPE_UNK6,
            ELEMTYPE_UNK7
} ElementType;
struct Actor;
struct GlobalContext;
struct Lights;
typedef void (*ActorFunc)(struct Actor*, struct GlobalContext*);
typedef void (*ActorShadowFunc)(struct Actor*, struct Lights*, struct GlobalContext*);
typedef u16 (*callback1_800343CC)(struct GlobalContext*, struct Actor*);
typedef s16 (*callback2_800343CC)(struct GlobalContext*, struct Actor*);
typedef struct {
    Vec3f pos;
    Vec3s rot;
} PosRot;
typedef struct {
               s16 id;
               u8 category;
               u32 flags;
               s16 objectId;
               u32 instanceSize;
               ActorFunc init;
               ActorFunc destroy;
               ActorFunc update;
               ActorFunc draw;
} ActorInit;
typedef enum {
            ALLOCTYPE_NORMAL,
            ALLOCTYPE_ABSOLUTE,
            ALLOCTYPE_PERMANENT
} AllocType;
typedef struct {
               u32 vromStart;
               u32 vromEnd;
               void* vramStart;
               void* vramEnd;
               void* loadedRamAddr;
               ActorInit* initInfo;
               char* name;
               u16 allocType;
               s8 nbLoaded;
} ActorOverlay;
typedef struct {
    u8 table[32];
} DamageTable;
typedef struct {
               u8 health;
               s16 cylRadius;
               s16 cylHeight;
               u8 mass;
} CollisionCheckInfoInit;
typedef struct {
               u8 health;
               s16 cylRadius;
               s16 cylHeight;
               s16 cylYShift;
               u8 mass;
} CollisionCheckInfoInit2;
typedef struct {
               DamageTable* damageTable;
               Vec3f displacement;
               s16 cylRadius;
               s16 cylHeight;
               s16 cylYShift;
               u8 mass;
               u8 health;
               u8 damage;
               u8 damageEffect;
               u8 atHitEffect;
               u8 acHitEffect;
} CollisionCheckInfo;
typedef struct {
               Vec3s rot;
               s16 face;
               f32 yOffset;
               ActorShadowFunc shadowDraw;
               f32 shadowScale;
               u8 shadowAlpha;
               u8 feetFloorFlags;
               Vec3f feetPos[2];
} ActorShape;
typedef struct Actor {
                s16 id;
                u8 category;
                s8 room;
                u32 flags;
                PosRot home;
                s16 params;
                s8 objBankIndex;
                s8 targetMode;
                u16 sfx;
                PosRot world;
                PosRot focus;
                f32 targetArrowOffset;
                Vec3f scale;
                Vec3f velocity;
                f32 speedXZ;
                f32 gravity;
                f32 minVelocityY;
                CollisionPoly* wallPoly;
                CollisionPoly* floorPoly;
                u8 wallBgId;
                u8 floorBgId;
                s16 wallYaw;
                f32 floorHeight;
                f32 yDistToWater;
                u16 bgCheckFlags;
                s16 yawTowardsPlayer;
                f32 xyzDistToPlayerSq;
                f32 xzDistToPlayer;
                f32 yDistToPlayer;
                CollisionCheckInfo colChkInfo;
                ActorShape shape;
                Vec3f projectedPos;
                f32 projectedW;
                f32 uncullZoneForward;
                f32 uncullZoneScale;
                f32 uncullZoneDownward;
                Vec3f prevPos;
                u8 isTargeted;
                u8 targetPriority;
                u16 textId;
                u16 freezeTimer;
                u16 colorFilterParams;
                u8 colorFilterTimer;
                u8 isDrawn;
                u8 dropFlag;
                u8 naviEnemyId;
                struct Actor* parent;
                struct Actor* child;
                struct Actor* prev;
                struct Actor* next;
                ActorFunc init;
                ActorFunc destroy;
                ActorFunc update;
                ActorFunc draw;
                ActorOverlay* overlayEntry;
                char dbgPad[0x10];
} Actor;
typedef enum {
            FOOT_LEFT,
            FOOT_RIGHT
} ActorFootIndex;
typedef struct DynaPolyActor {
                struct Actor actor;
                s32 bgId;
                f32 unk_150;
                f32 unk_154;
                s16 unk_158;
                u16 unk_15A;
                u32 unk_15C;
                u8 unk_160;
                s16 unk_162;
} DynaPolyActor;
typedef struct {
               MtxF* unk_00;
               s16* unk_04;
               s16 unk_08;
               char unk_0A[0x02];
               Gfx** unk_0C;
               s32 unk_10;
               s32 unk_14;
} struct_80032E24;
typedef enum {
               ITEM00_RUPEE_GREEN,
               ITEM00_RUPEE_BLUE,
               ITEM00_RUPEE_RED,
               ITEM00_HEART,
               ITEM00_BOMBS_A,
               ITEM00_ARROWS_SINGLE,
               ITEM00_HEART_PIECE,
               ITEM00_HEART_CONTAINER,
               ITEM00_ARROWS_SMALL,
               ITEM00_ARROWS_MEDIUM,
               ITEM00_ARROWS_LARGE,
               ITEM00_BOMBS_B,
               ITEM00_NUTS,
               ITEM00_STICK,
               ITEM00_MAGIC_LARGE,
               ITEM00_MAGIC_SMALL,
               ITEM00_SEEDS,
               ITEM00_SMALL_KEY,
               ITEM00_FLEXIBLE,
               ITEM00_RUPEE_ORANGE,
               ITEM00_RUPEE_PURPLE,
               ITEM00_SHIELD_DEKU,
               ITEM00_SHIELD_HYLIAN,
               ITEM00_TUNIC_ZORA,
               ITEM00_TUNIC_GORON,
               ITEM00_BOMBS_SPECIAL
} Item00Type;
struct EnItem00;
typedef void (*EnItem00ActionFunc)(struct EnItem00*, struct GlobalContext*);
typedef struct EnItem00 {
                Actor actor;
                EnItem00ActionFunc actionFunc;
                s16 collectibleFlag;
                s16 unk_152;
                s16 unk_154;
                s16 unk_156;
                s16 unk_158;
                s16 unk_15A;
                f32 unk_15C;
                ColliderCylinder collider;
} EnItem00;
typedef enum {
               A_OBJ_BLOCK_SMALL,
               A_OBJ_BLOCK_LARGE,
               A_OBJ_BLOCK_HUGE,
               A_OBJ_BLOCK_SMALL_ROT,
               A_OBJ_BLOCK_LARGE_ROT,
               A_OBJ_CUBE_SMALL,
               A_OBJ_UNKNOWN_6,
               A_OBJ_GRASS_CLUMP,
               A_OBJ_TREE_STUMP,
               A_OBJ_SIGNPOST_OBLONG,
               A_OBJ_SIGNPOST_ARROW,
               A_OBJ_KNOB
} AObjType;
struct EnAObj;
typedef void (*EnAObjActionFunc)(struct EnAObj*, struct GlobalContext*);
typedef struct EnAObj {
                DynaPolyActor dyna;
                EnAObjActionFunc actionFunc;
                s32 unk_168;
                s16 textId;
                s16 unk_16E;
                s16 unk_170;
                s16 unk_172;
                s16 unk_174;
                f32 unk_178;
                ColliderCylinder collider;
} EnAObj;
typedef enum {
               ACTORCAT_SWITCH,
               ACTORCAT_BG,
               ACTORCAT_PLAYER,
               ACTORCAT_EXPLOSIVE,
               ACTORCAT_NPC,
               ACTORCAT_ENEMY,
               ACTORCAT_PROP,
               ACTORCAT_ITEMACTION,
               ACTORCAT_MISC,
               ACTORCAT_BOSS,
               ACTORCAT_DOOR,
               ACTORCAT_CHEST
} ActorCategory;
typedef enum {
                 ACTOR_PLAYER,
                 ACTOR_UNSET_1,
                 ACTOR_EN_TEST,
                 ACTOR_UNSET_3,
                 ACTOR_EN_GIRLA,
                 ACTOR_UNSET_5,
                 ACTOR_UNSET_6,
                 ACTOR_EN_PART,
                 ACTOR_EN_LIGHT,
                 ACTOR_EN_DOOR,
                 ACTOR_EN_BOX,
                 ACTOR_BG_DY_YOSEIZO,
                 ACTOR_BG_HIDAN_FIREWALL,
                 ACTOR_EN_POH,
                 ACTOR_EN_OKUTA,
                 ACTOR_BG_YDAN_SP,
                 ACTOR_EN_BOM,
                 ACTOR_EN_WALLMAS,
                 ACTOR_EN_DODONGO,
                 ACTOR_EN_FIREFLY,
                 ACTOR_EN_HORSE,
                 ACTOR_EN_ITEM00,
                 ACTOR_EN_ARROW,
                 ACTOR_UNSET_17,
                 ACTOR_EN_ELF,
                 ACTOR_EN_NIW,
                 ACTOR_UNSET_1A,
                 ACTOR_EN_TITE,
                 ACTOR_EN_REEBA,
                 ACTOR_EN_PEEHAT,
                 ACTOR_EN_BUTTE,
                 ACTOR_UNSET_1F,
                 ACTOR_EN_INSECT,
                 ACTOR_EN_FISH,
                 ACTOR_UNSET_22,
                 ACTOR_EN_HOLL,
                 ACTOR_EN_SCENE_CHANGE,
                 ACTOR_EN_ZF,
                 ACTOR_EN_HATA,
                 ACTOR_BOSS_DODONGO,
                 ACTOR_BOSS_GOMA,
                 ACTOR_EN_ZL1,
                 ACTOR_EN_VIEWER,
                 ACTOR_EN_GOMA,
                 ACTOR_BG_PUSHBOX,
                 ACTOR_EN_BUBBLE,
                 ACTOR_DOOR_SHUTTER,
                 ACTOR_EN_DODOJR,
                 ACTOR_EN_BDFIRE,
                 ACTOR_UNSET_31,
                 ACTOR_EN_BOOM,
                 ACTOR_EN_TORCH2,
                 ACTOR_EN_BILI,
                 ACTOR_EN_TP,
                 ACTOR_UNSET_36,
                 ACTOR_EN_ST,
                 ACTOR_EN_BW,
                 ACTOR_EN_A_OBJ,
                 ACTOR_EN_EIYER,
                 ACTOR_EN_RIVER_SOUND,
                 ACTOR_EN_HORSE_NORMAL,
                 ACTOR_EN_OSSAN,
                 ACTOR_BG_TREEMOUTH,
                 ACTOR_BG_DODOAGO,
                 ACTOR_BG_HIDAN_DALM,
                 ACTOR_BG_HIDAN_HROCK,
                 ACTOR_EN_HORSE_GANON,
                 ACTOR_BG_HIDAN_ROCK,
                 ACTOR_BG_HIDAN_RSEKIZOU,
                 ACTOR_BG_HIDAN_SEKIZOU,
                 ACTOR_BG_HIDAN_SIMA,
                 ACTOR_BG_HIDAN_SYOKU,
                 ACTOR_EN_XC,
                 ACTOR_BG_HIDAN_CURTAIN,
                 ACTOR_BG_SPOT00_HANEBASI,
                 ACTOR_EN_MB,
                 ACTOR_EN_BOMBF,
                 ACTOR_EN_ZL2,
                 ACTOR_BG_HIDAN_FSLIFT,
                 ACTOR_EN_OE2,
                 ACTOR_BG_YDAN_HASI,
                 ACTOR_BG_YDAN_MARUTA,
                 ACTOR_BOSS_GANONDROF,
                 ACTOR_UNSET_53,
                 ACTOR_EN_AM,
                 ACTOR_EN_DEKUBABA,
                 ACTOR_EN_M_FIRE1,
                 ACTOR_EN_M_THUNDER,
                 ACTOR_BG_DDAN_JD,
                 ACTOR_BG_BREAKWALL,
                 ACTOR_EN_JJ,
                 ACTOR_EN_HORSE_ZELDA,
                 ACTOR_BG_DDAN_KD,
                 ACTOR_DOOR_WARP1,
                 ACTOR_OBJ_SYOKUDAI,
                 ACTOR_ITEM_B_HEART,
                 ACTOR_EN_DEKUNUTS,
                 ACTOR_BG_MENKURI_KAITEN,
                 ACTOR_BG_MENKURI_EYE,
                 ACTOR_EN_VALI,
                 ACTOR_BG_MIZU_MOVEBG,
                 ACTOR_BG_MIZU_WATER,
                 ACTOR_ARMS_HOOK,
                 ACTOR_EN_FHG,
                 ACTOR_BG_MORI_HINERI,
                 ACTOR_EN_BB,
                 ACTOR_BG_TOKI_HIKARI,
                 ACTOR_EN_YUKABYUN,
                 ACTOR_BG_TOKI_SWD,
                 ACTOR_EN_FHG_FIRE,
                 ACTOR_BG_MJIN,
                 ACTOR_BG_HIDAN_KOUSI,
                 ACTOR_DOOR_TOKI,
                 ACTOR_BG_HIDAN_HAMSTEP,
                 ACTOR_EN_BIRD,
                 ACTOR_UNSET_73,
                 ACTOR_UNSET_74,
                 ACTOR_UNSET_75,
                 ACTOR_UNSET_76,
                 ACTOR_EN_WOOD02,
                 ACTOR_UNSET_78,
                 ACTOR_UNSET_79,
                 ACTOR_UNSET_7A,
                 ACTOR_UNSET_7B,
                 ACTOR_EN_LIGHTBOX,
                 ACTOR_EN_PU_BOX,
                 ACTOR_UNSET_7E,
                 ACTOR_UNSET_7F,
                 ACTOR_EN_TRAP,
                 ACTOR_EN_AROW_TRAP,
                 ACTOR_EN_VASE,
                 ACTOR_UNSET_83,
                 ACTOR_EN_TA,
                 ACTOR_EN_TK,
                 ACTOR_BG_MORI_BIGST,
                 ACTOR_BG_MORI_ELEVATOR,
                 ACTOR_BG_MORI_KAITENKABE,
                 ACTOR_BG_MORI_RAKKATENJO,
                 ACTOR_EN_VM,
                 ACTOR_DEMO_EFFECT,
                 ACTOR_DEMO_KANKYO,
                 ACTOR_BG_HIDAN_FWBIG,
                 ACTOR_EN_FLOORMAS,
                 ACTOR_EN_HEISHI1,
                 ACTOR_EN_RD,
                 ACTOR_EN_PO_SISTERS,
                 ACTOR_BG_HEAVY_BLOCK,
                 ACTOR_BG_PO_EVENT,
                 ACTOR_OBJ_MURE,
                 ACTOR_EN_SW,
                 ACTOR_BOSS_FD,
                 ACTOR_OBJECT_KANKYO,
                 ACTOR_EN_DU,
                 ACTOR_EN_FD,
                 ACTOR_EN_HORSE_LINK_CHILD,
                 ACTOR_DOOR_ANA,
                 ACTOR_BG_SPOT02_OBJECTS,
                 ACTOR_BG_HAKA,
                 ACTOR_MAGIC_WIND,
                 ACTOR_MAGIC_FIRE,
                 ACTOR_UNSET_A0,
                 ACTOR_EN_RU1,
                 ACTOR_BOSS_FD2,
                 ACTOR_EN_FD_FIRE,
                 ACTOR_EN_DH,
                 ACTOR_EN_DHA,
                 ACTOR_EN_RL,
                 ACTOR_EN_ENCOUNT1,
                 ACTOR_DEMO_DU,
                 ACTOR_DEMO_IM,
                 ACTOR_DEMO_TRE_LGT,
                 ACTOR_EN_FW,
                 ACTOR_BG_VB_SIMA,
                 ACTOR_EN_VB_BALL,
                 ACTOR_BG_HAKA_MEGANE,
                 ACTOR_BG_HAKA_MEGANEBG,
                 ACTOR_BG_HAKA_SHIP,
                 ACTOR_BG_HAKA_SGAMI,
                 ACTOR_UNSET_B2,
                 ACTOR_EN_HEISHI2,
                 ACTOR_EN_ENCOUNT2,
                 ACTOR_EN_FIRE_ROCK,
                 ACTOR_EN_BROB,
                 ACTOR_MIR_RAY,
                 ACTOR_BG_SPOT09_OBJ,
                 ACTOR_BG_SPOT18_OBJ,
                 ACTOR_BOSS_VA,
                 ACTOR_BG_HAKA_TUBO,
                 ACTOR_BG_HAKA_TRAP,
                 ACTOR_BG_HAKA_HUTA,
                 ACTOR_BG_HAKA_ZOU,
                 ACTOR_BG_SPOT17_FUNEN,
                 ACTOR_EN_SYATEKI_ITM,
                 ACTOR_EN_SYATEKI_MAN,
                 ACTOR_EN_TANA,
                 ACTOR_EN_NB,
                 ACTOR_BOSS_MO,
                 ACTOR_EN_SB,
                 ACTOR_EN_BIGOKUTA,
                 ACTOR_EN_KAREBABA,
                 ACTOR_BG_BDAN_OBJECTS,
                 ACTOR_DEMO_SA,
                 ACTOR_DEMO_GO,
                 ACTOR_EN_IN,
                 ACTOR_EN_TR,
                 ACTOR_BG_SPOT16_BOMBSTONE,
                 ACTOR_UNSET_CE,
                 ACTOR_BG_HIDAN_KOWARERUKABE,
                 ACTOR_BG_BOMBWALL,
                 ACTOR_BG_SPOT08_ICEBLOCK,
                 ACTOR_EN_RU2,
                 ACTOR_OBJ_DEKUJR,
                 ACTOR_BG_MIZU_UZU,
                 ACTOR_BG_SPOT06_OBJECTS,
                 ACTOR_BG_ICE_OBJECTS,
                 ACTOR_BG_HAKA_WATER,
                 ACTOR_UNSET_D8,
                 ACTOR_EN_MA2,
                 ACTOR_EN_BOM_CHU,
                 ACTOR_EN_HORSE_GAME_CHECK,
                 ACTOR_BOSS_TW,
                 ACTOR_EN_RR,
                 ACTOR_EN_BA,
                 ACTOR_EN_BX,
                 ACTOR_EN_ANUBICE,
                 ACTOR_EN_ANUBICE_FIRE,
                 ACTOR_BG_MORI_HASHIGO,
                 ACTOR_BG_MORI_HASHIRA4,
                 ACTOR_BG_MORI_IDOMIZU,
                 ACTOR_BG_SPOT16_DOUGHNUT,
                 ACTOR_BG_BDAN_SWITCH,
                 ACTOR_EN_MA1,
                 ACTOR_BOSS_GANON,
                 ACTOR_BOSS_SST,
                 ACTOR_UNSET_EA,
                 ACTOR_UNSET_EB,
                 ACTOR_EN_NY,
                 ACTOR_EN_FR,
                 ACTOR_ITEM_SHIELD,
                 ACTOR_BG_ICE_SHELTER,
                 ACTOR_EN_ICE_HONO,
                 ACTOR_ITEM_OCARINA,
                 ACTOR_UNSET_F2,
                 ACTOR_UNSET_F3,
                 ACTOR_MAGIC_DARK,
                 ACTOR_DEMO_6K,
                 ACTOR_EN_ANUBICE_TAG,
                 ACTOR_BG_HAKA_GATE,
                 ACTOR_BG_SPOT15_SAKU,
                 ACTOR_BG_JYA_GOROIWA,
                 ACTOR_BG_JYA_ZURERUKABE,
                 ACTOR_UNSET_FB,
                 ACTOR_BG_JYA_COBRA,
                 ACTOR_BG_JYA_KANAAMI,
                 ACTOR_FISHING,
                 ACTOR_OBJ_OSHIHIKI,
                 ACTOR_BG_GATE_SHUTTER,
                 ACTOR_EFF_DUST,
                 ACTOR_BG_SPOT01_FUSYA,
                 ACTOR_BG_SPOT01_IDOHASHIRA,
                 ACTOR_BG_SPOT01_IDOMIZU,
                 ACTOR_BG_PO_SYOKUDAI,
                 ACTOR_BG_GANON_OTYUKA,
                 ACTOR_BG_SPOT15_RRBOX,
                 ACTOR_BG_UMAJUMP,
                 ACTOR_UNSET_109,
                 ACTOR_ARROW_FIRE,
                 ACTOR_ARROW_ICE,
                 ACTOR_ARROW_LIGHT,
                 ACTOR_UNSET_10D,
                 ACTOR_UNSET_10E,
                 ACTOR_ITEM_ETCETERA,
                 ACTOR_OBJ_KIBAKO,
                 ACTOR_OBJ_TSUBO,
                 ACTOR_EN_WONDER_ITEM,
                 ACTOR_EN_IK,
                 ACTOR_DEMO_IK,
                 ACTOR_EN_SKJ,
                 ACTOR_EN_SKJNEEDLE,
                 ACTOR_EN_G_SWITCH,
                 ACTOR_DEMO_EXT,
                 ACTOR_DEMO_SHD,
                 ACTOR_EN_DNS,
                 ACTOR_ELF_MSG,
                 ACTOR_EN_HONOTRAP,
                 ACTOR_EN_TUBO_TRAP,
                 ACTOR_OBJ_ICE_POLY,
                 ACTOR_BG_SPOT03_TAKI,
                 ACTOR_BG_SPOT07_TAKI,
                 ACTOR_EN_FZ,
                 ACTOR_EN_PO_RELAY,
                 ACTOR_BG_RELAY_OBJECTS,
                 ACTOR_EN_DIVING_GAME,
                 ACTOR_EN_KUSA,
                 ACTOR_OBJ_BEAN,
                 ACTOR_OBJ_BOMBIWA,
                 ACTOR_UNSET_128,
                 ACTOR_UNSET_129,
                 ACTOR_OBJ_SWITCH,
                 ACTOR_OBJ_ELEVATOR,
                 ACTOR_OBJ_LIFT,
                 ACTOR_OBJ_HSBLOCK,
                 ACTOR_EN_OKARINA_TAG,
                 ACTOR_EN_YABUSAME_MARK,
                 ACTOR_EN_GOROIWA,
                 ACTOR_EN_EX_RUPPY,
                 ACTOR_EN_TORYO,
                 ACTOR_EN_DAIKU,
                 ACTOR_UNSET_134,
                 ACTOR_EN_NWC,
                 ACTOR_EN_BLKOBJ,
                 ACTOR_ITEM_INBOX,
                 ACTOR_EN_GE1,
                 ACTOR_OBJ_BLOCKSTOP,
                 ACTOR_EN_SDA,
                 ACTOR_EN_CLEAR_TAG,
                 ACTOR_EN_NIW_LADY,
                 ACTOR_EN_GM,
                 ACTOR_EN_MS,
                 ACTOR_EN_HS,
                 ACTOR_BG_INGATE,
                 ACTOR_EN_KANBAN,
                 ACTOR_EN_HEISHI3,
                 ACTOR_EN_SYATEKI_NIW,
                 ACTOR_EN_ATTACK_NIW,
                 ACTOR_BG_SPOT01_IDOSOKO,
                 ACTOR_EN_SA,
                 ACTOR_EN_WONDER_TALK,
                 ACTOR_BG_GJYO_BRIDGE,
                 ACTOR_EN_DS,
                 ACTOR_EN_MK,
                 ACTOR_EN_BOM_BOWL_MAN,
                 ACTOR_EN_BOM_BOWL_PIT,
                 ACTOR_EN_OWL,
                 ACTOR_EN_ISHI,
                 ACTOR_OBJ_HANA,
                 ACTOR_OBJ_LIGHTSWITCH,
                 ACTOR_OBJ_MURE2,
                 ACTOR_EN_GO,
                 ACTOR_EN_FU,
                 ACTOR_UNSET_154,
                 ACTOR_EN_CHANGER,
                 ACTOR_BG_JYA_MEGAMI,
                 ACTOR_BG_JYA_LIFT,
                 ACTOR_BG_JYA_BIGMIRROR,
                 ACTOR_BG_JYA_BOMBCHUIWA,
                 ACTOR_BG_JYA_AMISHUTTER,
                 ACTOR_BG_JYA_BOMBIWA,
                 ACTOR_BG_SPOT18_BASKET,
                 ACTOR_UNSET_15D,
                 ACTOR_EN_GANON_ORGAN,
                 ACTOR_EN_SIOFUKI,
                 ACTOR_EN_STREAM,
                 ACTOR_UNSET_161,
                 ACTOR_EN_MM,
                 ACTOR_EN_KO,
                 ACTOR_EN_KZ,
                 ACTOR_EN_WEATHER_TAG,
                 ACTOR_BG_SST_FLOOR,
                 ACTOR_EN_ANI,
                 ACTOR_EN_EX_ITEM,
                 ACTOR_BG_JYA_IRONOBJ,
                 ACTOR_EN_JS,
                 ACTOR_EN_JSJUTAN,
                 ACTOR_EN_CS,
                 ACTOR_EN_MD,
                 ACTOR_EN_HY,
                 ACTOR_EN_GANON_MANT,
                 ACTOR_EN_OKARINA_EFFECT,
                 ACTOR_EN_MAG,
                 ACTOR_DOOR_GERUDO,
                 ACTOR_ELF_MSG2,
                 ACTOR_DEMO_GT,
                 ACTOR_EN_PO_FIELD,
                 ACTOR_EFC_ERUPC,
                 ACTOR_BG_ZG,
                 ACTOR_EN_HEISHI4,
                 ACTOR_EN_ZL3,
                 ACTOR_BOSS_GANON2,
                 ACTOR_EN_KAKASI,
                 ACTOR_EN_TAKARA_MAN,
                 ACTOR_OBJ_MAKEOSHIHIKI,
                 ACTOR_OCEFF_SPOT,
                 ACTOR_END_TITLE,
                 ACTOR_UNSET_180,
                 ACTOR_EN_TORCH,
                 ACTOR_DEMO_EC,
                 ACTOR_SHOT_SUN,
                 ACTOR_EN_DY_EXTRA,
                 ACTOR_EN_WONDER_TALK2,
                 ACTOR_EN_GE2,
                 ACTOR_OBJ_ROOMTIMER,
                 ACTOR_EN_SSH,
                 ACTOR_EN_STH,
                 ACTOR_OCEFF_WIPE,
                 ACTOR_OCEFF_STORM,
                 ACTOR_EN_WEIYER,
                 ACTOR_BG_SPOT05_SOKO,
                 ACTOR_BG_JYA_1FLIFT,
                 ACTOR_BG_JYA_HAHENIRON,
                 ACTOR_BG_SPOT12_GATE,
                 ACTOR_BG_SPOT12_SAKU,
                 ACTOR_EN_HINTNUTS,
                 ACTOR_EN_NUTSBALL,
                 ACTOR_BG_SPOT00_BREAK,
                 ACTOR_EN_SHOPNUTS,
                 ACTOR_EN_IT,
                 ACTOR_EN_GELDB,
                 ACTOR_OCEFF_WIPE2,
                 ACTOR_OCEFF_WIPE3,
                 ACTOR_EN_NIW_GIRL,
                 ACTOR_EN_DOG,
                 ACTOR_EN_SI,
                 ACTOR_BG_SPOT01_OBJECTS2,
                 ACTOR_OBJ_COMB,
                 ACTOR_BG_SPOT11_BAKUDANKABE,
                 ACTOR_OBJ_KIBAKO2,
                 ACTOR_EN_DNT_DEMO,
                 ACTOR_EN_DNT_JIJI,
                 ACTOR_EN_DNT_NOMAL,
                 ACTOR_EN_GUEST,
                 ACTOR_BG_BOM_GUARD,
                 ACTOR_EN_HS2,
                 ACTOR_DEMO_KEKKAI,
                 ACTOR_BG_SPOT08_BAKUDANKABE,
                 ACTOR_BG_SPOT17_BAKUDANKABE,
                 ACTOR_UNSET_1AA,
                 ACTOR_OBJ_MURE3,
                 ACTOR_EN_TG,
                 ACTOR_EN_MU,
                 ACTOR_EN_GO2,
                 ACTOR_EN_WF,
                 ACTOR_EN_SKB,
                 ACTOR_DEMO_GJ,
                 ACTOR_DEMO_GEFF,
                 ACTOR_BG_GND_FIREMEIRO,
                 ACTOR_BG_GND_DARKMEIRO,
                 ACTOR_BG_GND_SOULMEIRO,
                 ACTOR_BG_GND_NISEKABE,
                 ACTOR_BG_GND_ICEBLOCK,
                 ACTOR_EN_GB,
                 ACTOR_EN_GS,
                 ACTOR_BG_MIZU_BWALL,
                 ACTOR_BG_MIZU_SHUTTER,
                 ACTOR_EN_DAIKU_KAKARIKO,
                 ACTOR_BG_BOWL_WALL,
                 ACTOR_EN_WALL_TUBO,
                 ACTOR_EN_PO_DESERT,
                 ACTOR_EN_CROW,
                 ACTOR_DOOR_KILLER,
                 ACTOR_BG_SPOT11_OASIS,
                 ACTOR_BG_SPOT18_FUTA,
                 ACTOR_BG_SPOT18_SHUTTER,
                 ACTOR_EN_MA3,
                 ACTOR_EN_COW,
                 ACTOR_BG_ICE_TURARA,
                 ACTOR_BG_ICE_SHUTTER,
                 ACTOR_EN_KAKASI2,
                 ACTOR_EN_KAKASI3,
                 ACTOR_OCEFF_WIPE4,
                 ACTOR_EN_EG,
                 ACTOR_BG_MENKURI_NISEKABE,
                 ACTOR_EN_ZO,
                 ACTOR_OBJ_MAKEKINSUTA,
                 ACTOR_EN_GE3,
                 ACTOR_OBJ_TIMEBLOCK,
                 ACTOR_OBJ_HAMISHI,
                 ACTOR_EN_ZL4,
                 ACTOR_EN_MM2,
                 ACTOR_BG_JYA_BLOCK,
                 ACTOR_OBJ_WARP2BLOCK,
                 ACTOR_ID_MAX
} ActorID;
struct Player;
typedef enum {
               PLAYER_SHIELD_NONE,
               PLAYER_SHIELD_DEKU,
               PLAYER_SHIELD_HYLIAN,
               PLAYER_SHIELD_MIRROR,
               PLAYER_SHIELD_MAX
} PlayerShield;
typedef enum {
               PLAYER_TUNIC_KOKIRI,
               PLAYER_TUNIC_GORON,
               PLAYER_TUNIC_ZORA,
               PLAYER_TUNIC_MAX
} PlayerTunic;
typedef enum {
               PLAYER_BOOTS_NORMAL,
               PLAYER_BOOTS_IRON,
               PLAYER_BOOTS_HOVER,
               PLAYER_BOOTS_INDOOR,
               PLAYER_BOOTS_IRON_UNDERWATER,
               PLAYER_BOOTS_NORMAL_CHILD,
               PLAYER_BOOTS_MAX
} PlayerBoots;
typedef enum {
               PLAYER_STR_NONE,
               PLAYER_STR_BRACELET,
               PLAYER_STR_SILVER_G,
               PLAYER_STR_GOLD_G,
               PLAYER_STR_MAX
} PlayerStrength;
typedef enum {
               PLAYER_MASK_NONE,
               PLAYER_MASK_KEATON,
               PLAYER_MASK_SKULL,
               PLAYER_MASK_SPOOKY,
               PLAYER_MASK_BUNNY,
               PLAYER_MASK_GORON,
               PLAYER_MASK_ZORA,
               PLAYER_MASK_GERUDO,
               PLAYER_MASK_TRUTH,
               PLAYER_MASK_MAX
} PlayerMask;
typedef enum {
               PLAYER_AP_NONE,
               PLAYER_AP_LAST_USED,
               PLAYER_AP_FISHING_POLE,
               PLAYER_AP_SWORD_MASTER,
               PLAYER_AP_SWORD_KOKIRI,
               PLAYER_AP_SWORD_BGS,
               PLAYER_AP_STICK,
               PLAYER_AP_HAMMER,
               PLAYER_AP_BOW,
               PLAYER_AP_BOW_FIRE,
               PLAYER_AP_BOW_ICE,
               PLAYER_AP_BOW_LIGHT,
               PLAYER_AP_BOW_0C,
               PLAYER_AP_BOW_0D,
               PLAYER_AP_BOW_0E,
               PLAYER_AP_SLINGSHOT,
               PLAYER_AP_HOOKSHOT,
               PLAYER_AP_LONGSHOT,
               PLAYER_AP_BOMB,
               PLAYER_AP_BOMBCHU,
               PLAYER_AP_BOOMERANG,
               PLAYER_AP_MAGIC_SPELL_15,
               PLAYER_AP_MAGIC_SPELL_16,
               PLAYER_AP_MAGIC_SPELL_17,
               PLAYER_AP_FARORES_WIND,
               PLAYER_AP_NAYRUS_LOVE,
               PLAYER_AP_DINS_FIRE,
               PLAYER_AP_NUT,
               PLAYER_AP_OCARINA_FAIRY,
               PLAYER_AP_OCARINA_TIME,
               PLAYER_AP_BOTTLE,
               PLAYER_AP_BOTTLE_FISH,
               PLAYER_AP_BOTTLE_FIRE,
               PLAYER_AP_BOTTLE_BUG,
               PLAYER_AP_BOTTLE_POE,
               PLAYER_AP_BOTTLE_BIG_POE,
               PLAYER_AP_BOTTLE_LETTER,
               PLAYER_AP_BOTTLE_POTION_RED,
               PLAYER_AP_BOTTLE_POTION_BLUE,
               PLAYER_AP_BOTTLE_POTION_GREEN,
               PLAYER_AP_BOTTLE_MILK,
               PLAYER_AP_BOTTLE_MILK_HALF,
               PLAYER_AP_BOTTLE_FAIRY,
               PLAYER_AP_LETTER_ZELDA,
               PLAYER_AP_WEIRD_EGG,
               PLAYER_AP_CHICKEN,
               PLAYER_AP_BEAN,
               PLAYER_AP_POCKET_EGG,
               PLAYER_AP_POCKET_CUCCO,
               PLAYER_AP_COJIRO,
               PLAYER_AP_ODD_MUSHROOM,
               PLAYER_AP_ODD_POTION,
               PLAYER_AP_SAW,
               PLAYER_AP_SWORD_BROKEN,
               PLAYER_AP_PRESCRIPTION,
               PLAYER_AP_FROG,
               PLAYER_AP_EYEDROPS,
               PLAYER_AP_CLAIM_CHECK,
               PLAYER_AP_MASK_KEATON,
               PLAYER_AP_MASK_SKULL,
               PLAYER_AP_MASK_SPOOKY,
               PLAYER_AP_MASK_BUNNY,
               PLAYER_AP_MASK_GORON,
               PLAYER_AP_MASK_ZORA,
               PLAYER_AP_MASK_GERUDO,
               PLAYER_AP_MASK_TRUTH,
               PLAYER_AP_LENS,
               PLAYER_AP_MAX
} PlayerActionParam;
typedef enum {
               PLAYER_LIMB_NONE,
               PLAYER_LIMB_ROOT,
               PLAYER_LIMB_WAIST,
               PLAYER_LIMB_LOWER,
               PLAYER_LIMB_R_THIGH,
               PLAYER_LIMB_R_SHIN,
               PLAYER_LIMB_R_FOOT,
               PLAYER_LIMB_L_THIGH,
               PLAYER_LIMB_L_SHIN,
               PLAYER_LIMB_L_FOOT,
               PLAYER_LIMB_UPPER,
               PLAYER_LIMB_HEAD,
               PLAYER_LIMB_HAT,
               PLAYER_LIMB_COLLAR,
               PLAYER_LIMB_L_SHOULDER,
               PLAYER_LIMB_L_FOREARM,
               PLAYER_LIMB_L_HAND,
               PLAYER_LIMB_R_SHOULDER,
               PLAYER_LIMB_R_FOREARM,
               PLAYER_LIMB_R_HAND,
               PLAYER_LIMB_SHEATH,
               PLAYER_LIMB_TORSO,
               PLAYER_LIMB_MAX
} PlayerLimb;
typedef struct {
               f32 unk_00;
               f32 unk_04;
               f32 unk_08;
               f32 unk_0C;
               f32 unk_10;
               f32 unk_14;
               f32 unk_18;
               f32 unk_1C;
               f32 unk_20;
               f32 unk_24;
               f32 unk_28;
               f32 unk_2C;
               f32 unk_30;
               f32 unk_34;
               f32 unk_38;
               f32 unk_3C;
               f32 unk_40;
               Vec3s unk_44;
               Vec3s unk_4A[4];
               Vec3s unk_62[4];
               Vec3s unk_7A[2];
               Vec3s unk_86[2];
               u16 unk_92;
               u16 unk_94;
               LinkAnimationHeader* unk_98;
               LinkAnimationHeader* unk_9C;
               LinkAnimationHeader* unk_A0;
               LinkAnimationHeader* unk_A4;
               LinkAnimationHeader* unk_A8;
               LinkAnimationHeader* unk_AC[4];
               LinkAnimationHeader* unk_BC[2];
               LinkAnimationHeader* unk_C4[2];
               LinkAnimationHeader* unk_CC[2];
} PlayerAgeProperties;
typedef struct {
               s32 active;
               Vec3f tip;
               Vec3f base;
} WeaponInfo;
typedef void (*PlayerFunc674)(struct Player*, struct GlobalContext*);
typedef s32 (*PlayerFunc82C)(struct Player*, struct GlobalContext*);
typedef void (*PlayerFuncA74)(struct GlobalContext*, struct Player*);
typedef struct Player {
                 Actor actor;
                 s8 currentTunic;
                 s8 currentSword;
                 s8 currentShield;
                 s8 currentBoots;
                 s8 heldItemButton;
                 s8 heldItemActionParam;
                 u8 heldItemId;
                 s8 prevBoots;
                 s8 itemActionParam;
                 char unk_155[0x003];
                 u8 modelGroup;
                 u8 nextModelGroup;
                 s8 unk_15A;
                 u8 modelAnimType;
                 u8 leftHandType;
                 u8 rightHandType;
                 u8 sheathType;
                 u8 currentMask;
                 Gfx** rightHandDLists;
                 Gfx** leftHandDLists;
                 Gfx** sheathDLists;
                 Gfx** waistDLists;
                 u8 giObjectLoading;
                 DmaRequest giObjectDmaRequest;
                 OSMesgQueue giObjectLoadQueue;
                 OSMesg giObjectLoadMsg;
                 void* giObjectSegment;
                 SkelAnime skelAnime;
                 Vec3s jointTable[PLAYER_LIMB_MAX + 2];
                 Vec3s morphTable[PLAYER_LIMB_MAX + 2];
                 Vec3s blendTable[PLAYER_LIMB_MAX + 2];
                 s16 unk_3A8[2];
                 Actor* heldActor;
                 Vec3f leftHandPos;
                 Vec3s unk_3BC;
                 Actor* unk_3C4;
                 Vec3f unk_3C8;
                 char unk_3D4[0x058];
                 s8 doorType;
                 s8 doorDirection;
                 s16 doorTimer;
                 Actor* doorActor;
                 s8 getItemId;
                 u16 getItemDirection;
                 Actor* interactRangeActor;
                 s8 unk_43C;
                 char unk_43D[0x003];
                 Actor* rideActor;
                 u8 csMode;
                 u8 prevCsMode;
                 u8 unk_446;
                 u8 unk_447;
                 Actor* unk_448;
                 char unk_44C[0x004];
                 Vec3f unk_450;
                 Vec3f unk_45C;
                 char unk_468[0x002];
                 s16 unk_46A;
                 s16 unk_46C;
                 char unk_46E[0x02A];
                 ColliderCylinder cylinder;
                 ColliderQuad swordQuads[2];
                 ColliderQuad shieldQuad;
                 Actor* unk_664;
                 char unk_668[0x004];
                 s32 unk_66C;
                 s32 swordEffectIndex;
                 PlayerFunc674 func_674;
                 PlayerAgeProperties* ageProperties;
                 u32 stateFlags1;
                 u32 stateFlags2;
                 Actor* unk_684;
                 Actor* boomerangActor;
                 Actor* naviActor;
                 s16 naviTextId;
                 u8 stateFlags3;
                 s8 exchangeItemId;
                 Actor* targetActor;
                 f32 targetActorDistance;
                 char unk_69C[0x004];
                 f32 unk_6A0;
                 f32 unk_6A4;
                 Actor* unk_6A8;
                 s8 unk_6AC;
                 u8 unk_6AD;
                 u16 unk_6AE;
                 s16 unk_6B0;
                 char unk_6B4[0x004];
                 s16 unk_6B6;
                 s16 unk_6B8;
                 s16 unk_6BA;
                 s16 unk_6BC;
                 s16 unk_6BE;
                 s16 unk_6C0;
                 s16 unk_6C2;
                 f32 unk_6C4;
                 SkelAnime skelAnime2;
                 Vec3s jointTable2[PLAYER_LIMB_MAX + 2];
                 Vec3s morphTable2[PLAYER_LIMB_MAX + 2];
                 PlayerFunc82C func_82C;
                 f32 unk_830;
                 s16 unk_834;
                 s8 unk_836;
                 u8 unk_837;
                 f32 linearVelocity;
                 s16 currentYaw;
                 s16 targetYaw;
                 u16 unk_840;
                 s8 swordAnimation;
                 s8 swordState;
                 s8 unk_844;
                 u8 unk_845;
                 u8 unk_846;
                 s8 unk_847[4];
                 s8 unk_84B[4];
                 s8 unk_84F;
                 s16 unk_850;
                 f32 unk_854;
                 f32 unk_858;
                 f32 unk_85C;
                 s16 unk_860;
                 s8 unk_862;
                 f32 unk_864;
                 f32 unk_868;
                 f32 unk_86C;
                 f32 unk_870;
                 f32 unk_874;
                 f32 unk_878;
                 s16 unk_87C;
                 s16 unk_87E;
                 f32 unk_880;
                 f32 wallHeight;
                 f32 wallDistance;
                 u8 unk_88C;
                 u8 unk_88D;
                 u8 unk_88E;
                 u8 unk_88F;
                 u8 unk_890;
                 u8 shockTimer;
                 u8 unk_892;
                 u8 unk_893;
                 s16 fallStartHeight;
                 s16 fallDistance;
                 s16 unk_898;
                 s16 unk_89A;
                 s16 unk_89C;
                 u16 unk_89E;
                 u8 unk_8A0;
                 u8 unk_8A1;
                 s16 unk_8A2;
                 f32 unk_8A4;
                 f32 unk_8A8;
                 f32 windSpeed;
                 s16 windDirection;
                 WeaponInfo swordInfo[3];
                 Vec3f bodyPartsPos[18];
                 MtxF mf_9E0;
                 MtxF shieldMf;
                 u8 isBurning;
                 u8 flameTimers[18];
                 u8 unk_A73;
                 PlayerFuncA74 func_A74;
                 s8 invincibilityTimer;
                 u8 unk_A79;
                 u8 unk_A7A;
                 u8 unk_A7B;
                 f32 unk_A7C;
                 s16 unk_A80;
                 u16 unk_A82;
                 s16 unk_A84;
                 s8 unk_A86;
                 u8 unk_A87;
                 Vec3f unk_A88;
} Player;
struct Note;
struct NotePool;
struct SequenceChannel;
struct SequenceChannelLayer;
typedef struct AudioListItem {
               struct AudioListItem* prev;
               struct AudioListItem* next;
               union {
                   void* value;
                   s32 count;
               } u;
               struct NotePool* pool;
} AudioListItem;
typedef struct NotePool {
               AudioListItem disabled;
               AudioListItem decaying;
               AudioListItem releasing;
               AudioListItem active;
} NotePool;
typedef struct {
               u8 mode;
               u16 cur;
               u16 speed;
               f32 extent;
} Portamento;
typedef struct {
              s16 delay;
              s16 arg;
} AdsrEnvelope;
typedef struct {
               u32 start;
               u32 end;
               u32 count;
               char unk_0C[0x4];
               s16 state[16];
} AdpcmLoop;
typedef struct {
               s32 order;
               s32 npredictors;
               s16 book[1];
} AdpcmBook;
typedef struct {
               u8 bits4 : 4;
               u8 bits2 : 2;
               u8 unk_bits2 : 2;
               u32 bits24 : 24;
               u8* sampleAddr;
               AdpcmLoop* loop;
               AdpcmBook* book;
} AudioBankSample;
typedef struct {
               AudioBankSample* sample;
               f32 tuning;
} AudioBankSound;
typedef struct {
               s16 numSamplesAfterDownsampling;
               s16 chunkLen;
               s16* toDownsampleLeft;
               s16* toDownsampleRight;
               s32 startPos;
               s16 lengthA;
               s16 lengthB;
               u8 pad[8];
} ReverbRingBufferItem;
typedef struct {
                u8 unk_00;
                u8 useReverb;
                u8 unk_02;
                u8 unk_03;
                u8 downsampleRate;
                u8 unk_05;
                u16 windowSize;
                u16 unk_08;
                u16 unk_0A;
                u16 unk_0C;
                u16 unk_0E;
                u16 unk_10;
                u16 unk_12;
                u16 unk_14;
                u16 unk_16;
                u8 unk_18;
                s32 unk_1C;
                s32 unk_20;
                s32 unk_24;
                s16* unk_28;
                s16* unk_2C;
                void* unk_30;
                void* unk_34;
                void* unk_38;
                void* unk_3C;
                ReverbRingBufferItem items[2][5];
                ReverbRingBufferItem items2[2][5];
                s16* unk_270;
                s16* unk_274;
                void* unk_278;
                void* unk_27C;
                AudioBankSound sound;
                AudioBankSample sample;
                AdpcmLoop loop;
} SynthesisReverb;
typedef struct {
               u8 loaded;
               u8 normalRangeLo;
               u8 normalRangeHi;
               u8 releaseRate;
               AdsrEnvelope* envelope;
               AudioBankSound lowNotesSound;
               AudioBankSound normalNotesSound;
               AudioBankSound highNotesSound;
} Instrument;
typedef struct {
               u8 releaseRate;
               u8 pan;
               u8 loaded;
               AudioBankSound sound;
               AdsrEnvelope *envelope;
} Drum;
typedef struct {
               u8 numInstruments;
               u8 numDrums;
               u8 unk_02;
               u8 unk_03;
               u16 numSfx;
               Instrument** instruments;
               Drum** drums;
               AudioBankSound* soundEffects;
} CtlEntry;
typedef struct {
               u8* pc;
               u8* stack[4];
               u8 remLoopIters[4];
               u8 depth;
               s8 value;
} M64ScriptState;
typedef struct {
                u8 enabled : 1;
                u8 finished : 1;
                u8 muted : 1;
                u8 seqDmaInProgress : 1;
                u8 bankDmaInProgress : 1;
                u8 recalculateVolume : 1;
                u8 unk_0b2 : 1;
                u8 unk_0b1 : 1;
                u8 state;
                u8 noteAllocPolicy;
                u8 muteBehavior;
                u8 seqId;
                u8 defaultBank;
                u8 loadingBankId;
                s8 seqVariationEu[1];
                u16 tempo;
                u16 tempoAcc;
                u16 unk_0C;
                s16 transposition;
                u16 delay;
                u16 fadeTimer;
                u16 fadeTimerUnkEu;
                char pad_16[0x2];
                u8* seqData;
                f32 fadeVolume;
                f32 fadeVelocity;
                f32 volume;
                f32 muteVolumeScale;
                f32 fadeVolumeScale;
                f32 appliedFadeVolume;
                f32 unk_34;
                struct SequenceChannel* channels[16];
                M64ScriptState scriptState;
                u8* shortNoteVelocityTable;
                u8* shortNoteDurationTable;
                NotePool notePool;
                s32 unk_DC;
                u32 unk_E0;
                u8 pad_E4[0x10];
                OSMesg seqDmaMesg;
                OSIoMesg seqDmaIoMesg;
                OSMesgQueue bankDmaMesgQueue;
                OSMesg bankDmaMesg;
                OSIoMesg bankDmaIoMesg;
                u8* bankDmaCurrMemAddr;
                u32 bankDmaCurrDevAddr;
                s32 bankDmaRemaining;
                u8 pad_150[8];
                s8 unk_158[8];
} SequencePlayer;
typedef struct {
              u8 releaseRate;
              u8 sustain;
              AdsrEnvelope* envelope;
} AdsrSettings;
typedef struct {
               union {
        struct A {
                       u8 unk_0b80 : 1;
                       u8 hang : 1;
                       u8 decay : 1;
                       u8 release : 1;
                       u8 state : 4;
        } s;
                   u8 asByte;
    } action;
               u8 envIndex;
               s16 delay;
               f32 sustain;
               f32 velocity;
               f32 fadeOutVel;
               f32 current;
               f32 target;
               char pad_18[4];
               AdsrEnvelope *envelope;
} AdsrState;
typedef struct {
               u8 bit0 : 1;
               u8 bit1 : 1;
               u8 bit2 : 2;
               u8 strongRight : 1;
               u8 strongLeft : 1;
               u8 stereoHeadsetEffects : 1;
               u8 usesHeadsetPanEffects : 1;
} ReverbBitsData;
typedef union {
               ReverbBitsData s;
               u8 asByte;
} ReverbBits;
typedef struct {
               u8 reverb;
               u8 unk_1;
               u8 pan;
               ReverbBits reverbBits;
               u8 unk_4;
               u16 unk_6;
               f32 freqScale;
               f32 velocity;
               s16* unk_10;
               s16 unk_14[8];
} NoteAttributes;
typedef struct SequenceChannel {
               u8 enabled : 1;
               u8 finished : 1;
               u8 stopScript : 1;
               u8 stopSomething2 : 1;
               u8 hasInstrument : 1;
               u8 stereoHeadsetEffects : 1;
               u8 largeNotes : 1;
               u8 unused : 1;
    union {
        struct {
                       u8 freqScale : 1;
                       u8 volume : 1;
                       u8 pan : 1;
        } s;
                   u8 asByte;
    } changes;
               u8 noteAllocPolicy;
               u8 muteBehavior;
               u8 reverb;
               u8 notePriority;
               u8 someOtherPriority;
               u8 bankId;
               u8 reverbIndex;
               u8 bookOffset;
               u8 newPan;
               u8 panChannelWeight;
               u8 unk_0C;
               u8 velocityRandomVariance;
               u8 durationRandomVariance;
               u8 unk_0F;
               u16 vibratoRateStart;
               u16 vibratoExtentStart;
               u16 vibratoRateTarget;
               u16 vibratoExtentTarget;
               u16 vibratoRateChangeDelay;
               u16 vibratoExtentChangeDelay;
               u16 vibratoDelay;
               u16 delay;
               u16 unk_20;
               u16 pad_22;
               s16 instOrWave;
               s16 transposition;
               f32 volumeScale;
               f32 volume;
               s32 pan;
               f32 appliedVolume;
               f32 freqScale;
               u8 (*dynTable)[][2];
               struct Note* noteUnused;
               struct SequenceChannelLayer* layerUnused;
               Instrument* instrument;
               SequencePlayer* seqPlayer;
               struct SequenceChannelLayer* layers[4];
               M64ScriptState scriptState;
               AdsrSettings adsr;
               NotePool notePool;
               s8 soundScriptIO[8];
               s16* unk_CC;
               ReverbBits reverbBits;
} SequenceChannel;
typedef struct SequenceChannelLayer {
               u8 enabled : 1;
               u8 finished : 1;
               u8 stopSomething : 1;
               u8 continuousNotes : 1;
               u8 bit3 : 1;
               u8 ignoreDrumPan : 1;
               u8 bit1 : 1;
               u8 notePropertiesNeedInit : 1;
               ReverbBits reverbBits;
               u8 instOrWave;
               u8 noteDuration;
               u8 semitone;
               u8 portamentoTargetNote;
               u8 pan;
               u8 notePan;
               s16 delay;
               s16 duration;
               s16 delay2;
               u16 portamentoTime;
               s16 transposition;
               s16 shortNoteDefaultPlayPercentage;
               s16 playPercentage;
               AdsrSettings adsr;
               Portamento portamento;
               struct Note* note;
               f32 freqScale;
               f32 unk_34;
               f32 velocitySquare2;
               f32 velocitySquare;
               f32 noteVelocity;
               f32 noteFreqScale;
               Instrument* instrument;
               AudioBankSound* sound;
               SequenceChannel* seqChannel;
               M64ScriptState scriptState;
               AudioListItem listItem;
} SequenceChannelLayer;
typedef struct {
             s16 adpcmdecState[0x10];
             s16 finalResampleState[0x10];
             s16 mixEnvelopeState[0x28];
             s16 panResampleState[0x10];
             s16 panSamplesBuffer[0x20];
             s16 dummyResampleState[0x10];
} NoteSynthesisBuffers;
typedef struct {
               u8 restart;
               u8 sampleDmaIndex;
               u8 prevHeadsetPanRight;
               u8 prevHeadsetPanLeft;
               u16 samplePosFrac;
               s32 samplePosInt;
               NoteSynthesisBuffers* synthesisBuffers;
               s16 curVolLeft;
               s16 curVolRight;
} NoteSynthesisState;
typedef struct {
               struct SequenceChannel* seqChannel;
               u32 time;
               s16* curve;
               f32 extent;
               f32 rate;
               u8 active;
               u16 rateChangeTimer;
               u16 extentChangeTimer;
               u16 delay;
} VibratoState;
typedef struct {
               u8 priority;
               u8 waveId;
               u8 sampleCountIndex;
               u8 bankId;
               u8 unk_04;
               u8 stereoHeadsetEffects;
               s16 adsrVolScale;
               f32 portamentoFreqScale;
               f32 vibratoFreqScale;
               SequenceChannelLayer* prevParentLayer;
               SequenceChannelLayer* parentLayer;
               SequenceChannelLayer* wantedParentLayer;
               NoteAttributes attributes;
               AdsrState adsr;
} NotePlaybackState;
typedef struct {
    union {
        struct {
                       vu8 enabled : 1;
                       u8 needsInit : 1;
                       u8 finished : 1;
                       u8 envMixerNeedsInit : 1;
                       u8 stereoStrongRight : 1;
                       u8 stereoStrongLeft : 1;
                       u8 stereoHeadsetEffects : 1;
                       u8 usesHeadsetPanEffects : 1;
        } s;
                   u8 asByte;
    } bitField0;
    union {
        struct {
                       u8 reverbIndex : 3;
                       u8 bookOffset : 2;
                       u8 bit2 : 1;
                       u8 isSyntheticWave : 1;
                       u8 hasTwoAdpcmParts : 1;
        } s;
                   u8 asByte;
    } bitField1;
               u8 unk_2;
               u8 headsetPanRight;
               u8 headsetPanLeft;
               u8 reverbVol;
               u8 unk_06;
               u8 unk_07;
               u16 targetVolLeft;
               u16 targetVolRight;
               u16 resamplingRateFixedPoint;
               s16 unk_10;
               union {
                 s16* samples;
                 AudioBankSound* audioBankSound;
             } sound;
               s16* unk_14;
               char pad_18[0x8];
} NoteSubEu;
typedef struct Note {
               AudioListItem listItem;
               NoteSynthesisState synthesisState;
               char pad_24[0xC];
               NotePlaybackState playbackState;
               Portamento portamento;
               VibratoState vibratoState;
               char pad_B8[0x4];
               u32 unk_BC;
               NoteSubEu noteSubEu;
} Note;
typedef struct {
               u8 downsampleRate;
               u16 windowSize;
               u16 unk_4;
               u16 unk_6;
               u16 unk_8;
               u16 unk_A;
               u16 unk_C;
               u16 unk_E;
               s8 unk_10;
               u16 unk_12;
               s16 unk_14;
               s16 unk_16;
} ReverbSettings;
typedef struct {
               u32 frequency;
               u8 unk_04;
               u8 maxSimultaneousNotes;
               u8 numSequencePlayers;
               u8 pad_07[2];
               u8 numReverbs;
               u8 pad_0A[2];
               ReverbSettings* reverbSettings;
               u16 unk_10;
               u16 unk_12;
               u16 unk_14;
               u32 persistentSeqMem;
               u32 persistentBankMem;
               u32 persistentUnusedMem;
               u32 temporarySeqMem;
               u32 temporaryBankMem;
               u32 temporaryUnusedMem;
               s32 unk_30;
               s32 unk_34;
} AudioSessionSettings;
typedef struct {
               s16 presetUnk4;
               u16 frequency;
               u16 aiFrequency;
               s16 samplesPerFrameTarget;
               s16 maxAiBufferLength;
               s16 minAiBufferLength;
               s16 updatesPerFrame;
               s16 samplesPerUpdate;
               s16 samplesPerUpdateMax;
               s16 samplesPerUpdateMin;
               s16 numSequencePlayers;
               f32 resampleRate;
               f32 updatesPerFrameInv;
               f32 unkUpdatesPerFrameScaled;
               f32 unk_24;
} AudioBufferParameters;
typedef struct {
              u8* start;
              u8* cur;
              s32 size;
              s32 unused;
} SoundAllocPool;
typedef struct {
              u8 *ptr;
              u32 size;
              s16 poolIndex;
              s16 id;
} SeqOrBankEntry;
typedef struct {
               s8 unk_00;
               s8 unk_01;
               s8 unk_02;
               char pad[0x5];
               u8* unk_08;
               void* unk_0C;
               u32 size;
} UnkHeapEntry;
typedef struct {
                SoundAllocPool pool;
                UnkHeapEntry entries[32];
                s32 size;
} UnkPool;
typedef struct
{
              u32 numEntries;
              SoundAllocPool pool;
              SeqOrBankEntry entries[16];
} PersistentPool;
typedef struct
{
              u32 nextSide;
              SoundAllocPool pool;
              SeqOrBankEntry entries[2];
} TemporaryPool;
typedef struct
{
               PersistentPool persistent;
               TemporaryPool temporary;
               u8 pad[0x10];
} SoundMultiPool;
typedef struct {
    u32 wantPersistent;
    u32 wantTemporary;
} AudioPoolSplit2;
typedef struct {
    u32 wantSeq;
    u32 wantBank;
    u32 wantUnused;
} AudioPoolSplit3;
typedef struct {
    u32 wantSeq;
    u32 wantBank;
    u32 wantUnused;
    u32 wantCustom;
} AudioPoolSplit4;
typedef struct {
    u8* unk_0;
    u8* unk_4;
    u32 unk_8;
    s8 unk_C;
} Struct_800E0E0C_2;
typedef struct {
    char pad[0xC];
    Struct_800E0E0C_2 unk_C[1];
} ManyStruct_800E0E0C_2;
typedef struct {
               s32 unk_00;
               AudioBankSample* sample;
               u8* unk_08;
               s32 pad;
               s32 unk_10;
} AudioStruct0D68;
typedef struct {
                 char unk_0000;
                 s8 gNumSynthesisReverbs;
                 u16 unk_2;
                 u16 unk_4;
                 char unk_0006[0x0e];
                 NoteSubEu* gNoteSubsEu;
                 SynthesisReverb gSynthesisReverbs[4];
                 char unk_0B38[0x230];
                 AudioStruct0D68 unk_0D68[128];
                 char unk_1768[4];
                 s32 unk_176C;
                 char unk_1770[0xEB0];
                 s32 gSampleDmaNumListItems;
                 char unk_2624[0x210];
                 s16* unk_2834;
                 ManyStruct_800E0E0C_2* unk_2838;
                 char unk_283C[0x8];
                 CtlEntry* gCtlEntries;
                 AudioBufferParameters gAudioBufferParameters;
                 f32 unk_2870;
                 s32 unk_2874;
                 s32 unk_2878;
                 char unk_287C[0x14];
                 s32 gMaxAudioCmds;
                 s32 gMaxSimultaneousNotes;
                 s16 gTempoInternalToExternal;
                 s8 gSoundMode;
                 char unk_289B[0xD];
                 s32 unk_28A8;
                 u64* gAudioCmdBuffers[2];
                 char unk_28B4[0xAC];
                 f32 unk_2960;
                 s32 gRefreshRate;
                 s16* unk_2968[3];
                 s16 unk_2974[3];
                 u32 gAudioRandom;
                 s32 gAudioErrorFlags;
                 char unk_2984[0xC];
                 SoundAllocPool gAudioSessionPool;
                 SoundAllocPool gUnkPool;
                 SoundAllocPool gAudioInitPool;
                 SoundAllocPool gNotesAndBuffersPool;
                 char unk_29D0[0x20];
                 SoundAllocPool gSeqAndBankPool;
                 SoundAllocPool gPersistentCommonPool;
                 SoundAllocPool gTemporaryCommonPool;
                 SoundMultiPool gSeqLoadedPool;
                 SoundMultiPool gBankLoadedPool;
                 SoundMultiPool gUnusedLoadedPool;
                 SoundAllocPool unk_2D50;
                 SeqOrBankEntry unk_2D60[32];
                 UnkPool unk_2EE0;
                 UnkPool unk_3174;
                 AudioPoolSplit4 sSessionPoolSplit;
                 AudioPoolSplit2 sSeqAndBankPoolSplit;
                 AudioPoolSplit3 sPersistentCommonPoolSplit;
                 AudioPoolSplit3 sTemporaryCommonPoolSplit;
                 u8 gUnusedLoadStatus[0x30];
                 u8 gBankLoadStatus[0x30];
                 u8 gSeqLoadStatus[0x80];
                 volatile u8 gAudioResetStatus;
                 u8 gAudioResetPresetIdToLoad;
                 s32 gAudioResetFadeOutFramesLeft;
                 f32* unk_3520;
                 u8* gAudioHeap;
                 u32 gAudioHeapSize;
                 Note* gNotes;
                 SequencePlayer gSequencePlayers[4];
                 SequenceChannelLayer gSequenceLayers[64];
                 SequenceChannel gSequenceChannelNone;
                 s32 gNoteSubEuOffset;
                 AudioListItem gLayerFreeList;
} AudioContext;
typedef struct {
               u8 reverb;
               u8 unk_1;
               u8 pan;
               ReverbBits reverbBits;
               f32 frequency;
               f32 velocity;
               char unk_0C[0x4];
               s16* unk_10;
               u8 unk_14;
               u16 unk_16;
} Reverb;
typedef struct {
               f32* posX;
               f32* posY;
               f32* posZ;
               u8 unk_C;
               f32* unk_10;
               f32* unk_14;
               f32* unk_18;
               f32 unk_1C;
               u32 unk_20;
               u8 unk_24;
               u16 unk_26;
               u16 unk_28;
               u8 unk_2A;
               u8 unk_2B;
               u8 prev;
               u8 next;
               u8 unk_2E;
               u8 unk_2F;
} SoundBankEntry;
typedef enum {
                 OBJECT_UNSET_0,
                 OBJECT_GAMEPLAY_KEEP,
                 OBJECT_GAMEPLAY_FIELD_KEEP,
                 OBJECT_GAMEPLAY_DANGEON_KEEP,
                 OBJECT_UNSET_4,
                 OBJECT_UNSET_5,
                 OBJECT_HUMAN,
                 OBJECT_OKUTA,
                 OBJECT_CROW,
                 OBJECT_POH,
                 OBJECT_DY_OBJ,
                 OBJECT_WALLMASTER,
                 OBJECT_DODONGO,
                 OBJECT_FIREFLY,
                 OBJECT_BOX,
                 OBJECT_FIRE,
                 OBJECT_UNSET_10,
                 OBJECT_UNSET_11,
                 OBJECT_BUBBLE,
                 OBJECT_NIW,
                 OBJECT_LINK_BOY,
                 OBJECT_LINK_CHILD,
                 OBJECT_TITE,
                 OBJECT_REEBA,
                 OBJECT_PEEHAT,
                 OBJECT_KINGDODONGO,
                 OBJECT_HORSE,
                 OBJECT_ZF,
                 OBJECT_GOMA,
                 OBJECT_ZL1,
                 OBJECT_GOL,
                 OBJECT_DODOJR,
                 OBJECT_TORCH2,
                 OBJECT_BL,
                 OBJECT_TP,
                 OBJECT_OA1,
                 OBJECT_ST,
                 OBJECT_BW,
                 OBJECT_EI,
                 OBJECT_HORSE_NORMAL,
                 OBJECT_OB1,
                 OBJECT_O_ANIME,
                 OBJECT_SPOT04_OBJECTS,
                 OBJECT_DDAN_OBJECTS,
                 OBJECT_HIDAN_OBJECTS,
                 OBJECT_HORSE_GANON,
                 OBJECT_OA2,
                 OBJECT_SPOT00_OBJECTS,
                 OBJECT_MB,
                 OBJECT_BOMBF,
                 OBJECT_SK2,
                 OBJECT_OE1,
                 OBJECT_OE_ANIME,
                 OBJECT_OE2,
                 OBJECT_YDAN_OBJECTS,
                 OBJECT_GND,
                 OBJECT_AM,
                 OBJECT_DEKUBABA,
                 OBJECT_UNSET_3A,
                 OBJECT_OA3,
                 OBJECT_OA4,
                 OBJECT_OA5,
                 OBJECT_OA6,
                 OBJECT_OA7,
                 OBJECT_JJ,
                 OBJECT_OA8,
                 OBJECT_OA9,
                 OBJECT_OB2,
                 OBJECT_OB3,
                 OBJECT_OB4,
                 OBJECT_HORSE_ZELDA,
                 OBJECT_OPENING_DEMO1,
                 OBJECT_WARP1,
                 OBJECT_B_HEART,
                 OBJECT_DEKUNUTS,
                 OBJECT_OE3,
                 OBJECT_OE4,
                 OBJECT_MENKURI_OBJECTS,
                 OBJECT_OE5,
                 OBJECT_OE6,
                 OBJECT_OE7,
                 OBJECT_OE8,
                 OBJECT_OE9,
                 OBJECT_OE10,
                 OBJECT_OE11,
                 OBJECT_OE12,
                 OBJECT_VALI,
                 OBJECT_OA10,
                 OBJECT_OA11,
                 OBJECT_MIZU_OBJECTS,
                 OBJECT_FHG,
                 OBJECT_OSSAN,
                 OBJECT_MORI_HINERI1,
                 OBJECT_BB,
                 OBJECT_TOKI_OBJECTS,
                 OBJECT_YUKABYUN,
                 OBJECT_ZL2,
                 OBJECT_MJIN,
                 OBJECT_MJIN_FLASH,
                 OBJECT_MJIN_DARK,
                 OBJECT_MJIN_FLAME,
                 OBJECT_MJIN_ICE,
                 OBJECT_MJIN_SOUL,
                 OBJECT_MJIN_WIND,
                 OBJECT_MJIN_OKA,
                 OBJECT_HAKA_OBJECTS,
                 OBJECT_SPOT06_OBJECTS,
                 OBJECT_ICE_OBJECTS,
                 OBJECT_RELAY_OBJECTS,
                 OBJECT_PO_FIELD,
                 OBJECT_PO_COMPOSER,
                 OBJECT_MORI_HINERI1A,
                 OBJECT_MORI_HINERI2,
                 OBJECT_MORI_HINERI2A,
                 OBJECT_MORI_OBJECTS,
                 OBJECT_MORI_TEX,
                 OBJECT_SPOT08_OBJ,
                 OBJECT_WARP2,
                 OBJECT_HATA,
                 OBJECT_BIRD,
                 OBJECT_UNSET_78,
                 OBJECT_UNSET_79,
                 OBJECT_UNSET_7A,
                 OBJECT_UNSET_7B,
                 OBJECT_WOOD02,
                 OBJECT_UNSET_7D,
                 OBJECT_UNSET_7E,
                 OBJECT_UNSET_7F,
                 OBJECT_UNSET_80,
                 OBJECT_LIGHTBOX,
                 OBJECT_PU_BOX,
                 OBJECT_UNSET_83,
                 OBJECT_UNSET_84,
                 OBJECT_TRAP,
                 OBJECT_VASE,
                 OBJECT_IM,
                 OBJECT_TA,
                 OBJECT_TK,
                 OBJECT_XC,
                 OBJECT_VM,
                 OBJECT_BV,
                 OBJECT_HAKACH_OBJECTS,
                 OBJECT_EFC_CRYSTAL_LIGHT,
                 OBJECT_EFC_FIRE_BALL,
                 OBJECT_EFC_FLASH,
                 OBJECT_EFC_LGT_SHOWER,
                 OBJECT_EFC_STAR_FIELD,
                 OBJECT_GOD_LGT,
                 OBJECT_LIGHT_RING,
                 OBJECT_TRIFORCE_SPOT,
                 OBJECT_BDAN_OBJECTS,
                 OBJECT_SD,
                 OBJECT_RD,
                 OBJECT_PO_SISTERS,
                 OBJECT_HEAVY_OBJECT,
                 OBJECT_GNDD,
                 OBJECT_FD,
                 OBJECT_DU,
                 OBJECT_FW,
                 OBJECT_MEDAL,
                 OBJECT_HORSE_LINK_CHILD,
                 OBJECT_SPOT02_OBJECTS,
                 OBJECT_HAKA,
                 OBJECT_RU1,
                 OBJECT_SYOKUDAI,
                 OBJECT_FD2,
                 OBJECT_DH,
                 OBJECT_RL,
                 OBJECT_EFC_TW,
                 OBJECT_DEMO_TRE_LGT,
                 OBJECT_GI_KEY,
                 OBJECT_MIR_RAY,
                 OBJECT_BROB,
                 OBJECT_GI_JEWEL,
                 OBJECT_SPOT09_OBJ,
                 OBJECT_SPOT18_OBJ,
                 OBJECT_BDOOR,
                 OBJECT_SPOT17_OBJ,
                 OBJECT_SHOP_DUNGEN,
                 OBJECT_NB,
                 OBJECT_MO,
                 OBJECT_SB,
                 OBJECT_GI_MELODY,
                 OBJECT_GI_HEART,
                 OBJECT_GI_COMPASS,
                 OBJECT_GI_BOSSKEY,
                 OBJECT_GI_MEDAL,
                 OBJECT_GI_NUTS,
                 OBJECT_SA,
                 OBJECT_GI_HEARTS,
                 OBJECT_GI_ARROWCASE,
                 OBJECT_GI_BOMBPOUCH,
                 OBJECT_IN,
                 OBJECT_TR,
                 OBJECT_SPOT16_OBJ,
                 OBJECT_OE1S,
                 OBJECT_OE4S,
                 OBJECT_OS_ANIME,
                 OBJECT_GI_BOTTLE,
                 OBJECT_GI_STICK,
                 OBJECT_GI_MAP,
                 OBJECT_OF1D_MAP,
                 OBJECT_RU2,
                 OBJECT_GI_SHIELD_1,
                 OBJECT_DEKUJR,
                 OBJECT_GI_MAGICPOT,
                 OBJECT_GI_BOMB_1,
                 OBJECT_OF1S,
                 OBJECT_MA2,
                 OBJECT_GI_PURSE,
                 OBJECT_HNI,
                 OBJECT_TW,
                 OBJECT_RR,
                 OBJECT_BXA,
                 OBJECT_ANUBICE,
                 OBJECT_GI_GERUDO,
                 OBJECT_GI_ARROW,
                 OBJECT_GI_BOMB_2,
                 OBJECT_GI_EGG,
                 OBJECT_GI_SCALE,
                 OBJECT_GI_SHIELD_2,
                 OBJECT_GI_HOOKSHOT,
                 OBJECT_GI_OCARINA,
                 OBJECT_GI_MILK,
                 OBJECT_MA1,
                 OBJECT_GANON,
                 OBJECT_SST,
                 OBJECT_NY_UNUSED,
                 OBJECT_UNSET_E4,
                 OBJECT_NY,
                 OBJECT_FR,
                 OBJECT_GI_PACHINKO,
                 OBJECT_GI_BOOMERANG,
                 OBJECT_GI_BOW,
                 OBJECT_GI_GLASSES,
                 OBJECT_GI_LIQUID,
                 OBJECT_ANI,
                 OBJECT_DEMO_6K,
                 OBJECT_GI_SHIELD_3,
                 OBJECT_GI_LETTER,
                 OBJECT_SPOT15_OBJ,
                 OBJECT_JYA_OBJ,
                 OBJECT_GI_CLOTHES,
                 OBJECT_GI_BEAN,
                 OBJECT_GI_FISH,
                 OBJECT_GI_SAW,
                 OBJECT_GI_HAMMER,
                 OBJECT_GI_GRASS,
                 OBJECT_GI_LONGSWORD,
                 OBJECT_SPOT01_OBJECTS,
                 OBJECT_MD_UNUSED,
                 OBJECT_MD,
                 OBJECT_KM1,
                 OBJECT_KW1,
                 OBJECT_ZO,
                 OBJECT_KZ,
                 OBJECT_UMAJUMP,
                 OBJECT_MASTERKOKIRI,
                 OBJECT_MASTERKOKIRIHEAD,
                 OBJECT_MASTERGOLON,
                 OBJECT_MASTERZOORA,
                 OBJECT_AOB,
                 OBJECT_IK,
                 OBJECT_AHG,
                 OBJECT_CNE,
                 OBJECT_GI_NIWATORI,
                 OBJECT_SKJ,
                 OBJECT_GI_BOTTLE_LETTER,
                 OBJECT_BJI,
                 OBJECT_BBA,
                 OBJECT_GI_OCARINA_0,
                 OBJECT_DS,
                 OBJECT_ANE,
                 OBJECT_BOJ,
                 OBJECT_SPOT03_OBJECT,
                 OBJECT_SPOT07_OBJECT,
                 OBJECT_FZ,
                 OBJECT_BOB,
                 OBJECT_GE1,
                 OBJECT_YABUSAME_POINT,
                 OBJECT_GI_BOOTS_2,
                 OBJECT_GI_SEED,
                 OBJECT_GND_MAGIC,
                 OBJECT_D_ELEVATOR,
                 OBJECT_D_HSBLOCK,
                 OBJECT_D_LIFT,
                 OBJECT_MAMENOKI,
                 OBJECT_GOROIWA,
                 OBJECT_UNSET_120,
                 OBJECT_TORYO,
                 OBJECT_DAIKU,
                 OBJECT_UNSET_123,
                 OBJECT_NWC,
                 OBJECT_BLKOBJ,
                 OBJECT_GM,
                 OBJECT_MS,
                 OBJECT_HS,
                 OBJECT_INGATE,
                 OBJECT_LIGHTSWITCH,
                 OBJECT_KUSA,
                 OBJECT_TSUBO,
                 OBJECT_GI_GLOVES,
                 OBJECT_GI_COIN,
                 OBJECT_KANBAN,
                 OBJECT_GJYO_OBJECTS,
                 OBJECT_OWL,
                 OBJECT_MK,
                 OBJECT_FU,
                 OBJECT_GI_KI_TAN_MASK,
                 OBJECT_GI_REDEAD_MASK,
                 OBJECT_GI_SKJ_MASK,
                 OBJECT_GI_RABIT_MASK,
                 OBJECT_GI_TRUTH_MASK,
                 OBJECT_GANON_OBJECTS,
                 OBJECT_SIOFUKI,
                 OBJECT_STREAM,
                 OBJECT_MM,
                 OBJECT_FA,
                 OBJECT_OS,
                 OBJECT_GI_EYE_LOTION,
                 OBJECT_GI_POWDER,
                 OBJECT_GI_MUSHROOM,
                 OBJECT_GI_TICKETSTONE,
                 OBJECT_GI_BROKENSWORD,
                 OBJECT_JS,
                 OBJECT_CS,
                 OBJECT_GI_PRESCRIPTION,
                 OBJECT_GI_BRACELET,
                 OBJECT_GI_SOLDOUT,
                 OBJECT_GI_FROG,
                 OBJECT_MAG,
                 OBJECT_DOOR_GERUDO,
                 OBJECT_GT,
                 OBJECT_EFC_ERUPC,
                 OBJECT_ZL2_ANIME1,
                 OBJECT_ZL2_ANIME2,
                 OBJECT_GI_GOLONMASK,
                 OBJECT_GI_ZORAMASK,
                 OBJECT_GI_GERUDOMASK,
                 OBJECT_GANON2,
                 OBJECT_KA,
                 OBJECT_TS,
                 OBJECT_ZG,
                 OBJECT_GI_HOVERBOOTS,
                 OBJECT_GI_M_ARROW,
                 OBJECT_DS2,
                 OBJECT_EC,
                 OBJECT_FISH,
                 OBJECT_GI_SUTARU,
                 OBJECT_GI_GODDESS,
                 OBJECT_SSH,
                 OBJECT_BIGOKUTA,
                 OBJECT_BG,
                 OBJECT_SPOT05_OBJECTS,
                 OBJECT_SPOT12_OBJ,
                 OBJECT_BOMBIWA,
                 OBJECT_HINTNUTS,
                 OBJECT_RS,
                 OBJECT_SPOT00_BREAK,
                 OBJECT_GLA,
                 OBJECT_SHOPNUTS,
                 OBJECT_GELDB,
                 OBJECT_GR,
                 OBJECT_DOG,
                 OBJECT_JYA_IRON,
                 OBJECT_JYA_DOOR,
                 OBJECT_UNSET_16E,
                 OBJECT_SPOT11_OBJ,
                 OBJECT_KIBAKO2,
                 OBJECT_DNS,
                 OBJECT_DNK,
                 OBJECT_GI_FIRE,
                 OBJECT_GI_INSECT,
                 OBJECT_GI_BUTTERFLY,
                 OBJECT_GI_GHOST,
                 OBJECT_GI_SOUL,
                 OBJECT_BOWL,
                 OBJECT_DEMO_KEKKAI,
                 OBJECT_EFC_DOUGHNUT,
                 OBJECT_GI_DEKUPOUCH,
                 OBJECT_GANON_ANIME1,
                 OBJECT_GANON_ANIME2,
                 OBJECT_GANON_ANIME3,
                 OBJECT_GI_RUPY,
                 OBJECT_SPOT01_MATOYA,
                 OBJECT_SPOT01_MATOYAB,
                 OBJECT_MU,
                 OBJECT_WF,
                 OBJECT_SKB,
                 OBJECT_GJ,
                 OBJECT_GEFF,
                 OBJECT_HAKA_DOOR,
                 OBJECT_GS,
                 OBJECT_PS,
                 OBJECT_BWALL,
                 OBJECT_COW,
                 OBJECT_COB,
                 OBJECT_GI_SWORD_1,
                 OBJECT_DOOR_KILLER,
                 OBJECT_OUKE_HAKA,
                 OBJECT_TIMEBLOCK,
                 OBJECT_ZL4,
                 OBJECT_ID_MAX
} ObjectID;
typedef struct {
               u16 entrance;
               u8 ageRestriction;
               u8 flag;
               u32 segAddr;
} EntranceCutscene;
typedef struct {
               s8 continueFlag;
               s8 cameraRoll;
               u16 nextPointFrame;
               f32 viewAngle;
               Vec3s pos;
} CutsceneCameraPoint;
typedef struct {
               u16 base;
               u16 startFrame;
               u16 endFrame;
} CsCmdBase;
typedef struct {
               u8 unk_00;
               u8 setting;
               u16 startFrame;
               u16 endFrame;
} CsCmdEnvLighting;
typedef struct {
               u8 unk_00;
               u8 sequence;
               u16 startFrame;
               u16 endFrame;
} CsCmdMusicChange;
typedef struct {
               u16 type;
               u16 startFrame;
               u16 endFrame;
} CsCmdMusicFade;
typedef struct {
               u16 unk_00;
               u16 startFrame;
               u16 endFrame;
               u8 unk_06;
               u8 unk_07;
               u8 unk_08;
} CsCmdUnknown9;
typedef struct {
               u16 unk_00;
               u16 startFrame;
               u16 endFrame;
               u8 hour;
               u8 minute;
} CsCmdDayTime;
typedef struct {
               u16 base;
               u16 startFrame;
               u16 endFrame;
               u16 type;
               u16 textId1;
               u16 textId2;
} CsCmdTextbox;
typedef struct {
               u16 action;
               u16 startFrame;
               u16 endFrame;
    union {
                   Vec3s rot;
                   Vec3us urot;
    };
               Vec3i startPos;
               Vec3i endPos;
               Vec3i normal;
} CsCmdActorAction;
typedef enum {
    CS_STATE_IDLE,
    CS_STATE_SKIPPABLE_INIT,
    CS_STATE_SKIPPABLE_EXEC,
    CS_STATE_UNSKIPPABLE_INIT,
    CS_STATE_UNSKIPPABLE_EXEC
} CutsceneState;
typedef enum {
    CS_CMD_00 = 0x0000,
    CS_CMD_CAMERA_POS = 0x0001,
    CS_CMD_CAMERA_FOCUS = 0x0002,
    CS_CMD_MISC = 0x0003,
    CS_CMD_SET_LIGHTING = 0x0004,
    CS_CMD_CAMERA_POS_PLAYER = 0x0005,
    CS_CMD_CAMERA_FOCUS_PLAYER = 0x0006,
    CS_CMD_07 = 0x0007,
    CS_CMD_08 = 0x0008,
    CS_CMD_09 = 0x0009,
    CS_CMD_TEXTBOX = 0x0013,
    CS_CMD_SET_PLAYER_ACTION = 0x000A,
    CS_CMD_SET_ACTOR_ACTION_1 = 0x000F,
    CS_CMD_SET_ACTOR_ACTION_2 = 0x000E,
    CS_CMD_SET_ACTOR_ACTION_3 = 0x0019,
    CS_CMD_SET_ACTOR_ACTION_4 = 0x001D,
    CS_CMD_SET_ACTOR_ACTION_5 = 0x001E,
    CS_CMD_SET_ACTOR_ACTION_6 = 0x002C,
    CS_CMD_SET_ACTOR_ACTION_7 = 0x001F,
    CS_CMD_SET_ACTOR_ACTION_8 = 0x0031,
    CS_CMD_SET_ACTOR_ACTION_9 = 0x003E,
    CS_CMD_SET_ACTOR_ACTION_10 = 0x008F,
    CS_CMD_SCENE_TRANS_FX = 0x002D,
    CS_CMD_NOP = 0x000B,
    CS_CMD_PLAYBGM = 0x0056,
    CS_CMD_STOPBGM = 0x0057,
    CS_CMD_FADEBGM = 0x007C,
    CS_CMD_SETTIME = 0x008C,
    CS_CMD_TERMINATOR = 0x03E8,
    CS_CMD_END = 0xFFFF
} CutsceneCmd;
typedef union CutsceneData {
    s32 i;
    f32 f;
    s16 s[2];
    s8 b[4];
} CutsceneData;
typedef enum {
               OCARINA_ACTION_UNK_0,
               OCARINA_ACTION_FREE_PLAY_OCARINA,
               OCARINA_ACTION_MINUET,
               OCARINA_ACTION_BOLERO,
               OCARINA_ACTION_SERENADE,
               OCARINA_ACTION_REQUIEM,
               OCARINA_ACTION_NOCTURNE,
               OCARINA_ACTION_PRELUDE,
               OCARINA_ACTION_SARIAS_SONG,
               OCARINA_ACTION_EPONAS_SONG,
               OCARINA_ACTION_ZELDAS_LULLABY,
               OCARINA_ACTION_SUNS_SONG,
               OCARINA_ACTION_SONG_OF_TIME,
               OCARINA_ACTION_SONG_OF_STORMS,
               OCARINA_ACTION_OCARINA_ACTION_UNK_E,
               OCARINA_ACTION_MINUET_PLAYBACK,
               OCARINA_ACTION_BOLERO_PLAYBACK,
               OCARINA_ACTION_SERENADE_PLAYBACK,
               OCARINA_ACTION_REQUIEM_PLAYBACK,
               OCARINA_ACTION_NOCTURNE_PLAYBACK,
               OCARINA_ACTION_PRELUDE_PLAYBACK,
               OCARINA_ACTION_SARIAS_SONG_PLAYBACK,
               OCARINA_ACTION_EPONAS_SONG_PLAYBACK,
               OCARINA_ACTION_ZELDAS_LULLABY_PLAYBACK,
               OCARINA_ACTION_SUNS_SONG_PLAYBACK,
               OCARINA_ACTION_SONG_OF_TIME_PLAYBACK,
               OCARINA_ACTION_SONG_OF_STORMS_PLAYBACK
} OcarinaSongActionIDs;
typedef enum {
               INVALID_DESTINATION_0,
               CUTSCENE_MAP_GANON_HORSE,
               CUTSCENE_MAP_THREE_GODESSES_POST_DEKU_TREE,
               GERUDO_VALLEY_DIN,
               DEATH_MOUNTAIN_TRAIL_NAYRU,
               KOKIRI_FOREST_FARORE,
               CUTSCENE_MAP_TRIFORCE_CREATION,
               KOKIRI_FOREST_RECEIVE_KOKIRI_EMERALD,
               TEMPLE_OF_TIME_AFTER_USE_MS,
               GERUDO_VALLEY_DIN_2,
               LINKS_HOUSE_INTRO,
               KOKIRI_FOREST_INTRO,
               DEATH_MOUNTAIN_TRAIL_AFTER_GORON_RUBY,
               ZORAS_FOUNTAIN_AFTER_ZORAS_SAPPHIRE,
               KOKIRI_FOREST_AFTER_KOKIRI_EMERALD,
               TEMPLE_OF_TIME_KOKIRI_EMERALD,
               TEMPLE_OF_TIME_GORON_RUBY,
               TEMPLE_OF_TIME_ZORAS_SAPPHIRE,
               TEMPLE_OF_TIME_AFTER_USE_MS_FIRST,
               DEATH_MOUNTAIN_TRAIL_AFTER_INTRO,
               INVALID_DESTINATION_14,
               LAKE_HYLIA_WATER_RISES,
               DESERT_COLOSSUS_REQUIEM,
               CUTSCENE_MAP_CURSE_YOU,
               JABU_JABU_INTRO,
               CHAMBER_OF_SAGES_LIGHT_MEDALLION,
               TEMPLE_OF_TIME_KOKIRI_EMERALD_2,
               TEMPLE_OF_TIME_GORON_RUBY_2,
               TEMPLE_OF_TIME_ZORAS_SAPPHIRE_2,
               CHAMBER_OF_SAGES_FOREST_MEDALLION,
               CHAMBER_OF_SAGES_FIRE_MEDALLION,
               CHAMBER_OF_SAGES_WATER_MEDALLION,
               HYRULE_FIELD_FLASHBACK,
               HYRULE_FIELD_AFTER_LAKE_HYLIA_OWL,
               CUTSCENE_MAP_GANON_AFTER_USE_MS,
               HYRULE_FIELD_INTRO_ZELDA_ESCAPE,
               INVALID_DESTINATION_24,
               INVALID_DESTINATION_25,
               CUTSCENE_MAP_SHEIKAH_LEGEND,
               TEMPLE_OF_TIME_ZELDA_REVEAL,
               TEMPLE_OF_TIME_GET_LIGHT_ARROWS,
               LAKE_HYLIA_AFTER_BLUE_WARP,
               KAKARIKO_VILLAGE_DRAIN_WELL,
               WINDMILL_AFTER_DRAIN_WELL,
               TEMPLE_OF_TIME_AFTER_DOOR_OF_TIME_OPENS,
               INVALID_DESTINATION_2D,
               TEMPLE_OF_TIME_AFTER_USE_MS_FIRST_2,
               KAKARIKO_VILLAGE_NOCTURNE_PART_2,
               DESERT_COLOSSUS_AFTER_REQUIEM,
               TEMPLE_OF_TIME_AFTER_LIGHT_ARROWS,
               KAKARIKO_VILLAGE_AFTER_NOCTURNE,
               HYRULE_FIELD_IMPA_ESCORT_CS,
               TEMPLE_OF_TIME_SONG_OF_TIME,
               HYRULE_FIELD_AFTER_SONG_OF_TIME,
               GERUDO_VALLEY_CREDITS,
               GERUDO_FORTRESS_CREDITS,
               KAKARIKO_VILLAGE_CREDITS,
               DEATH_MOUNTAIN_TRAIL_CREDITS_1,
               GORON_CITY_CREDITS,
               LAKE_HYLIA_CREDITS,
               ZORAS_FOUNTAIN_CREDITS,
               ZORAS_DOMAIN_CREDITS,
               KOKIRI_FOREST_CREDITS_1,
               KOKIRI_FOREST_CREDITS_2,
               HYRULE_FIELD_CREDITS,
               LON_LON_RANCH_CREDITS_1,
               KAKARIKO_VILLAGE_AFTER_TRAIL_OWL,
               HTRULE_FIELD_UNUSED_ENTRANCE,
               CUTSCENE_MAP_FIRE,
               KOKIRI_FOREST_POST_FOREST_MEDALLION,
               DEATH_MOUNTAIN_TRAIL_CREDITS_2,
               TEMPLE_OF_TIME_CREDITS,
               ZELDAS_COURTYARD_CREDITS,
               LON_LON_RANCH_CREDITS_1_2,
               LON_LON_RANCH_CREDITS_2,
               LON_LON_RANCH_CREDITS_3,
               LON_LON_RANCH_CREDITS_4,
               LON_LON_RANCH_CREDITS_5,
               LON_LON_RANCH_CREDITS_6,
               LON_LON_RANCH_NO_CS_1,
               LON_LON_RANCH_NO_CS_2,
               LON_LON_RANCH_NO_CS_3,
               LON_LON_RANCH_NO_CS_4,
               LON_LON_RANCH_NO_CS_5,
               LON_LON_RANCH_NO_CS_6,
               LON_LON_RANCH_NO_CS_7,
               LON_LON_RANCH_NO_CS_8,
               LON_LON_RANCH_NO_CS_9,
               LON_LON_RANCH_NO_CS_10,
               LON_LON_RANCH_NO_CS_11,
               LON_LON_RANCH_NO_CS_12,
               LON_LON_RANCH_NO_CS_13,
               LON_LON_RANCH_NO_CS_14,
               LON_LON_RANCH_NO_CS_15,
               LON_LON_RANCH_NO_CS_EPONAS_SONG,
               CONDITIONAL_DESTINATION,
               DESERT_COLOSSUS_SPIRIT_BLUE_WARP,
               GRAVEYARD_AFTER_SHADOW_BLUE_WARP,
               DEATH_MOUNTAIN_CRATER_AFTER_FIRE_BLUE_WARP,
               SACRED_FOREST_MEADOW_AFTER_FOREST_BLUE_WARP,
               KOKIRI_FOREST_AFTER_FOREST_BLUE_WARP,
               DESERT_COLOSSUS_AFTER_SILVER_GAUNTLETS,
               TEMPLE_OF_TIME_FRONT_OF_PEDESTAL,
               HYRULE_FIELD_TITLE_SCREEN,
               SPIRIT_TEMPLE_BOSS_TITLE_SCREEN,
               GRAVEYARD_SUNS_SONG,
               ROYAL_FAMILYS_TOMB_SUNS_SONG,
               GANONS_CASTLE_AFTER_FOREST_TRIAL,
               GANONS_CASTLE_AFTER_WATER_TRIAL,
               GANONS_CASTLE_AFTER_SHADOW_TRIAL,
               GANONS_CASTLE_AFTER_FIRE_TRIAL,
               GANONS_CASTLE_AFTER_LIGHT_TRIAL,
               GANONS_CASTLE_AFTER_SPIRIT_TRIAL,
               GANONS_CASTLE_DISPEL_BARRIER_IF_CONDITIONS,
               HYRULE_FIELD_INTRO,
               HYRULE_FIELD_AFTER_IMPA_ESCORT,
               DESERT_COLOSSUS_SPIRIT_BLUE_WARP_2,
               HYRULE_FIELD_SKY,
               GANON_BATTLE_TOWER_COLLAPSE,
               ZELDAS_COURTYARD_RECEIVE_LETTER
} CutsceneTerminatorDestination;
typedef enum {
               CAM_SET_NONE,
               CAM_SET_NORMAL0,
               CAM_SET_NORMAL1,
               CAM_SET_DUNGEON0,
               CAM_SET_DUNGEON1,
               CAM_SET_NORMAL3,
               CAM_SET_HORSE0,
               CAM_SET_BOSS_GOMA,
               CAM_SET_BOSS_DODO,
               CAM_SET_BOSS_BARI,
               CAM_SET_BOSS_FGANON,
               CAM_SET_BOSS_BAL,
               CAM_SET_BOSS_SHADES,
               CAM_SET_BOSS_MOFA,
               CAM_SET_TWIN0,
               CAM_SET_TWIN1,
               CAM_SET_BOSS_GANON1,
               CAM_SET_BOSS_GANON2,
               CAM_SET_TOWER0,
               CAM_SET_TOWER1,
               CAM_SET_FIXED0,
               CAM_SET_FIXED1,
               CAM_SET_CIRCLE0,
               CAM_SET_CIRCLE2,
               CAM_SET_CIRCLE3,
               CAM_SET_PREREND0,
               CAM_SET_PREREND1,
               CAM_SET_PREREND3,
               CAM_SET_DOOR0,
               CAM_SET_DOORC,
               CAM_SET_RAIL3,
               CAM_SET_START0,
               CAM_SET_START1,
               CAM_SET_FREE0,
               CAM_SET_FREE2,
               CAM_SET_CIRCLE4,
               CAM_SET_CIRCLE5,
               CAM_SET_DEMO0,
               CAM_SET_DEMO1,
               CAM_SET_MORI1,
               CAM_SET_ITEM0,
               CAM_SET_ITEM1,
               CAM_SET_DEMO3,
               CAM_SET_DEMO4,
               CAM_SET_UFOBEAN,
               CAM_SET_LIFTBEAN,
               CAM_SET_SCENE0,
               CAM_SET_SCENE1,
               CAM_SET_HIDAN1,
               CAM_SET_HIDAN2,
               CAM_SET_MORI2,
               CAM_SET_MORI3,
               CAM_SET_TAKO,
               CAM_SET_SPOT05A,
               CAM_SET_SPOT05B,
               CAM_SET_HIDAN3,
               CAM_SET_ITEM2,
               CAM_SET_CIRCLE6,
               CAM_SET_NORMAL2,
               CAM_SET_FISHING,
               CAM_SET_DEMOC,
               CAM_SET_UO_FIBER,
               CAM_SET_DUNGEON2,
               CAM_SET_TEPPEN,
               CAM_SET_CIRCLE7,
               CAM_SET_NORMAL4,
               CAM_SET_MAX
} CameraSettingType;
typedef enum {
               CAM_MODE_NORMAL,
               CAM_MODE_TARGET,
               CAM_MODE_FOLLOWTARGET,
               CAM_MODE_TALK,
               CAM_MODE_BATTLE,
               CAM_MODE_CLIMB,
               CAM_MODE_FIRSTPERSON,
               CAM_MODE_BOWARROW,
               CAM_MODE_BOWARROWZ,
               CAM_MODE_FOOKSHOT,
               CAM_MODE_BOOMERANG,
               CAM_MODE_SLINGSHOT,
               CAM_MODE_CLIMBZ,
               CAM_MODE_JUMP,
               CAM_MODE_HANG,
               CAM_MODE_HANGZ,
               CAM_MODE_FREEFALL,
               CAM_MODE_CHARGE,
               CAM_MODE_STILL,
               CAM_MODE_PUSHPULL,
               CAM_MODE_BOOMFOLLLOW,
               CAM_MODE_MAX
} CameraModeType;
typedef enum {
               CAM_FUNC_NONE,
               CAM_FUNC_NORM0,
               CAM_FUNC_NORM1,
               CAM_FUNC_NORM2,
               CAM_FUNC_NORM3,
               CAM_FUNC_NORM4,
               CAM_FUNC_PARA0,
               CAM_FUNC_PARA1,
               CAM_FUNC_PARA2,
               CAM_FUNC_PARA3,
               CAM_FUNC_PARA4,
               CAM_FUNC_KEEP0,
               CAM_FUNC_KEEP1,
               CAM_FUNC_KEEP2,
               CAM_FUNC_KEEP3,
               CAM_FUNC_KEEP4,
               CAM_FUNC_SUBJ0,
               CAM_FUNC_SUBJ1,
               CAM_FUNC_SUBJ2,
               CAM_FUNC_SUBJ3,
               CAM_FUNC_SUBJ4,
               CAM_FUNC_JUMP0,
               CAM_FUNC_JUMP1,
               CAM_FUNC_JUMP2,
               CAM_FUNC_JUMP3,
               CAM_FUNC_JUMP4,
               CAM_FUNC_BATT0,
               CAM_FUNC_BATT1,
               CAM_FUNC_BATT2,
               CAM_FUNC_BATT3,
               CAM_FUNC_BATT4,
               CAM_FUNC_FIXD0,
               CAM_FUNC_FIXD1,
               CAM_FUNC_FIXD2,
               CAM_FUNC_FIXD3,
               CAM_FUNC_FIXD4,
               CAM_FUNC_DATA0,
               CAM_FUNC_DATA1,
               CAM_FUNC_DATA2,
               CAM_FUNC_DATA3,
               CAM_FUNC_DATA4,
               CAM_FUNC_UNIQ0,
               CAM_FUNC_UNIQ1,
               CAM_FUNC_UNIQ2,
               CAM_FUNC_UNIQ3,
               CAM_FUNC_UNIQ4,
               CAM_FUNC_UNIQ5,
               CAM_FUNC_UNIQ6,
               CAM_FUNC_UNIQ7,
               CAM_FUNC_UNIQ8,
               CAM_FUNC_UNIQ9,
               CAM_FUNC_DEMO0,
               CAM_FUNC_DEMO1,
               CAM_FUNC_DEMO2,
               CAM_FUNC_DEMO3,
               CAM_FUNC_DEMO4,
               CAM_FUNC_DEMO5,
               CAM_FUNC_DEMO6,
               CAM_FUNC_DEMO7,
               CAM_FUNC_DEMO8,
               CAM_FUNC_DEMO9,
               CAM_FUNC_SPEC0,
               CAM_FUNC_SPEC1,
               CAM_FUNC_SPEC2,
               CAM_FUNC_SPEC3,
               CAM_FUNC_SPEC4,
               CAM_FUNC_SPEC5,
               CAM_FUNC_SPEC6,
               CAM_FUNC_SPEC7,
               CAM_FUNC_SPEC8,
               CAM_FUNC_SPEC9,
               CAM_FUNC_MAX
} CameraFuncType;
typedef struct {
                 Vec3f collisionClosePoint;
                 CollisionPoly* atEyePoly;
                 f32 swingUpdateRate;
                 s16 unk_14;
                 s16 unk_16;
                 s16 unk_18;
                 s16 swingUpdateRateTimer;
} SwingAnimation;
typedef struct {
                 SwingAnimation swing;
                 f32 yOffset;
                 f32 unk_20;
                 s16 slopePitchAdj;
                 s16 swingYawTarget;
                 s16 unk_28;
                 s16 startSwingTimer;
} Normal1Anim;
typedef struct {
                 f32 yOffset;
                 f32 distMin;
                 f32 distMax;
                 f32 unk_0C;
                 f32 unk_10;
                 f32 unk_14;
                 f32 fovTarget;
                 f32 atLERPScaleMax;
                 s16 pitchTarget;
                 s16 interfaceFlags;
                 Normal1Anim anim;
} Normal1;
typedef struct {
                 Vec3f unk_00;
                 Vec3f unk_0C;
                 f32 unk_18;
                 f32 unk_1C;
                 s16 unk_20;
                 s16 unk_22;
                 f32 unk_24;
                 s16 unk_28;
} Normal2Anim;
typedef struct {
                 f32 unk_00;
                 f32 unk_04;
                 f32 unk_08;
                 f32 unk_0C;
                 f32 unk_10;
                 f32 unk_14;
                 f32 unk_18;
                 s16 unk_1C;
                 s16 interfaceFlags;
                 Normal2Anim anim;
} Normal2;
typedef struct {
                 SwingAnimation swing;
                 f32 unk_1C;
                 f32 unk_20;
                 s16 curPitch;
                 s16 yawUpdAmt;
                 s16 yawTimer;
                 s16 distTimer;
} Normal3Anim;
typedef struct {
                 f32 yOffset;
                 f32 distMin;
                 f32 distMax;
                 f32 yawUpdateSpeed;
                 f32 unk_10;
                 f32 fovTarget;
                 f32 maxAtLERPScale;
                 s16 pitchTarget;
                 s16 interfaceFlags;
                 Normal3Anim anim;
} Normal3;
typedef struct {
                 Vec3f unk_00;
                 f32 yTarget;
                 s16 unk_10;
                 s16 yawTarget;
                 s16 pitchTarget;
                 s16 unk_16;
                 s16 animTimer;
} Parallel1Anim;
typedef struct {
                 f32 unk_00;
                 f32 distTarget;
                 f32 unk_08;
                 f32 unk_0C;
                 f32 fovTarget;
                 f32 unk_14;
                 f32 unk_18;
                 f32 unk_1C;
                 s16 pitchTarget;
                 s16 yawTarget;
                 s16 interfaceFlags;
                 Parallel1Anim anim;
} Parallel1;
typedef struct {
                 SwingAnimation swing;
                 f32 unk_1C;
                 VecSph unk_20;
} Jump1Anim;
typedef struct {
                 f32 atYOffset;
                 f32 distMin;
                 f32 distMax;
                 f32 yawUpateRateTarget;
                 f32 maxYawUpdate;
                 f32 unk_14;
                 f32 atLERPScaleMax;
                 s16 interfaceFlags;
                 Jump1Anim anim;
} Jump1;
typedef struct {
                 f32 floorY;
                 s16 yawTarget;
                 s16 initYawDiff;
                 s16 yawAdj;
                 s16 onFloor;
                 s16 animTimer;
} Jump2Anim;
typedef struct {
                 f32 atYOffset;
                 f32 minDist;
                 f32 maxDist;
                 f32 minMaxDistFactor;
                 f32 yawUpdRateTarget;
                 f32 xzUpdRateTarget;
                 f32 fovTarget;
                 f32 atLERPStepScale;
                 s16 interfaceFlags;
                 Jump2Anim anim;
} Jump2;
typedef struct {
                 SwingAnimation swing;
                 f32 unk_1C;
                 s16 animTimer;
                 s16 mode;
} Jump3Anim;
typedef struct {
                 f32 yOffset;
                 f32 distMin;
                 f32 distMax;
                 f32 swingUpdateRate;
                 f32 unk_10;
                 f32 unk_14;
                 f32 fovTarget;
                 f32 unk_1C;
                 s16 pitchTarget;
                 s16 interfaceFlags;
                 Jump3Anim anim;
} Jump3;
typedef struct {
                 f32 initialEyeToAtDist;
                 f32 roll;
                 f32 yPosOffset;
                 Actor* target;
                 f32 unk_10;
                 s16 unk_14;
                 s16 initialEyeToAtYaw;
                 s16 initialEyeToAtPitch;
                 s16 animTimer;
                 s16 chargeTimer;
} Battle1Anim;
typedef struct {
                 f32 yOffset;
                 f32 distance;
                 f32 swingYawInitial;
                 f32 swingYawFinal;
                 f32 swingPitchInitial;
                 f32 swingPitchFinal;
                 f32 swingPitchAdj;
                 f32 fov;
                 f32 atLERPScaleOnGround;
                 f32 yOffsetOffGround;
                 f32 atLERPScaleOffGround;
                 s16 flags;
                 Battle1Anim anim;
} Battle1;
typedef struct {
                 s16 animTimer;
} Battle4Anim;
typedef struct {
                 f32 yOffset;
                 f32 rTarget;
                 s16 pitchTarget;
                 f32 lerpUpdateRate;
                 f32 fovTarget;
                 f32 atLERPTarget;
                 s16 interfaceFlags;
                 s16 unk_1A;
                 Battle4Anim anim;
} Battle4;
typedef struct {
                 f32 unk_00;
                 f32 unk_04;
                 f32 unk_08;
                 Actor* unk_0C;
                 s16 unk_10;
                 s16 unk_12;
                 s16 unk_14;
                 s16 unk_16;
} Keep1Anim;
typedef struct {
                 f32 unk_00;
                 f32 unk_04;
                 f32 unk_08;
                 f32 unk_0C;
                 f32 unk_10;
                 f32 unk_14;
                 f32 unk_18;
                 f32 unk_1C;
                 f32 unk_20;
                 f32 unk_24;
                 f32 unk_28;
                 f32 unk_2C;
                 s16 interfaceFlags;
                 Keep1Anim anim;
} KeepOn1;
typedef struct {
                 Vec3f eyeToAtTarget;
                 Actor* target;
                 Vec3f atTarget;
                 s16 animTimer;
} Keep3Anim;
typedef struct {
                 f32 yOffset;
                 f32 minDist;
                 f32 maxDist;
                 f32 swingYawInital;
                 f32 swingYawFinal;
                 f32 swingPitchInitial;
                 f32 swingPitchFinal;
                 f32 swingPitchAdj;
                 f32 fovTarget;
                 f32 atLERPScaleMax;
                 s16 initTimer;
                 s16 flags;
                 Keep3Anim anim;
} KeepOn3;
typedef struct {
                 f32 unk_00;
                 f32 unk_04;
                 f32 unk_08;
                 s16 unk_0C;
                 s16 unk_0E;
                 s16 unk_10;
                 s16 unk_12;
                 s16 unk_14;
} KeepOn4_Unk20;
typedef struct {
                 f32 unk_00;
                 f32 unk_04;
                 f32 unk_08;
                 f32 unk_0C;
                 f32 unk_10;
                 f32 unk_14;
                 f32 unk_18;
                 s16 unk_1C;
                 s16 unk_1E;
                 KeepOn4_Unk20 unk_20;
} KeepOn4;
typedef struct {
                 f32 fovTarget;
                 s16 animTimer;
} KeepOn0Anim;
typedef struct {
                 f32 fovScale;
                 f32 yawScale;
                 s16 timerInit;
                 s16 interfaceFlags;
                 KeepOn0Anim anim;
} KeepOn0;
typedef struct {
                 PosRot eyePosRotTarget;
                 s16 fov;
} Fixed1Anim;
typedef struct {
                 f32 unk_00;
                 f32 lerpStep;
                 f32 fov;
                 s16 interfaceFlags;
                 Fixed1Anim anim;
} Fixed1;
typedef struct {
                 Vec3f eye;
                 s16 fov;
} Fixed2InitParams;
typedef struct {
                 f32 yOffset;
                 f32 eyeStepScale;
                 f32 posStepScale;
                 f32 fov;
                 s16 interfaceFlags;
                 Fixed2InitParams initParams;
} Fixed2;
typedef struct {
                 Vec3s rot;
                 s16 fov;
                 s16 updDirTimer;
                 s16 jfifId;
} Fixed3Anim;
typedef struct {
                s16 interfaceFlags;
                 Fixed3Anim anim;
} Fixed3;
typedef struct {
                 Vec3f eyeTarget;
                 f32 followSpeed;
} Fixed4Anim;
typedef struct {
                 f32 yOffset;
                 f32 speedToEyePos;
                 f32 followSpeed;
                 f32 fov;
                 s16 interfaceFlags;
                 Fixed4Anim anim;
} Fixed4;
typedef struct {
                 f32 r;
                 s16 yaw;
                 s16 pitch;
                 s16 animTimer;
} Subj3Anim;
typedef struct {
                 f32 eyeNextYOffset;
                 f32 eyeDist;
                 f32 eyeNextDist;
                 f32 unk_0C;
                 Vec3f atOffset;
                 f32 fovTarget;
                 s16 interfaceFlags;
                 Subj3Anim anim;
} Subj3;
typedef struct {
                 Linef unk_00;
                 f32 unk_18;
                 f32 unk_1C;
                 f32 unk_20;
                 f32 unk_24;
                 f32 unk_28;
                 s16 unk_2C;
                 s16 unk_2E;
                 s16 unk_30;
                 s16 unk_32;
} Subj4Anim;
typedef struct {
                 s16 interfaceFlags;
                 Subj4Anim anim;
} Subj4;
typedef struct {
                 PosRot eyePosRot;
                 char unk_14[0x8];
                 s16 fov;
                 s16 jfifId;
} Data4InitParams;
typedef struct {
                 f32 yOffset;
                 f32 fov;
                 s16 interfaceFlags;
                 Data4InitParams initParams;
} Data4;
typedef struct {
                 f32 unk_00;
                 s16 yawTarget;
                 s16 yawTargetAdj;
                 s16 timer;
} Unique1Anim;
typedef struct {
                 f32 yOffset;
                 f32 distMin;
                 f32 distMax;
                 char unk_0C[4];
                 f32 fovTarget;
                 f32 atLERPScaleMax;
                 s16 pitchTarget;
                 s16 interfaceFlags;
                 Unique1Anim anim;
} Unique1;
typedef struct {
                 f32 unk_00;
                 s16 unk_04;
} Unique2Unk10;
typedef struct {
                 f32 yOffset;
                 f32 distTarget;
                 f32 fovTarget;
                 s16 interfaceFlags;
                 Unique2Unk10 unk_10;
} Unique2;
typedef struct {
                 f32 initialFov;
                 f32 initialDist;
} Unique3Anim;
typedef struct {
                 f32 yOffset;
                 f32 fov;
                 s16 interfaceFlags;
} Unique3Params;
typedef struct {
                 struct Actor* doorActor;
                 s16 camDataIdx;
                 s16 timer1;
                 s16 timer2;
                 s16 timer3;
} DoorParams;
typedef struct {
                 DoorParams doorParams;
                 Unique3Params params;
                 Unique3Anim anim;
} Unique3;
typedef struct {
                 Vec3f initalPos;
                 s16 animTimer;
                 Linef sceneCamPosPlayerLine;
} Unique0Anim;
typedef struct {
                 s16 interfaceFlags;
                 Unique0Anim anim;
} Unique0Params;
typedef struct {
                 DoorParams doorParams;
                 Unique0Params uniq0;
} Unique0;
typedef struct {
                 s16 interfaceFlags;
} Unique6;
typedef union {
                 Vec3s unk_00;
} Unique7Unk8;
typedef struct {
                 f32 fov;
                 s16 interfaceFlags;
                 s16 align;
                 Unique7Unk8 unk_08;
} Unique7;
typedef struct {
                 u8 actionFlags;
                 u8 unk_01;
                 s16 initFlags;
                 s16 timerInit;
                 s16 rollTargetInit;
                 f32 fovTargetInit;
                 f32 lerpStepScale;
                 Vec3f atTargetInit;
                 Vec3f eyeTargetInit;
} OnePointDemoFull;
typedef struct {
                 OnePointDemoFull* curKeyFrame;
                 Vec3f atTarget;
                 Vec3f eyeTarget;
                 Vec3f playerPos;
                 f32 fovTarget;
                 VecSph atEyeOffsetTarget;
                 s16 rollTarget;
                 s16 curKeyFrameIdx;
                 s16 unk_38;
                 s16 isNewKeyFrame;
                 s16 keyFrameTimer;
} Unique9Anim;
typedef struct {
                 s16 interfaceFlags;
                 Unique9Anim anim;
} Unique9;
typedef struct {
                 s32 keyFrameCnt;
                 OnePointDemoFull* keyFrames;
                 Unique9 uniq9;
} Unique9OnePointDemo;
typedef struct {
                 f32 curFrame;
                 s16 keyframe;
} Demo1Anim;
typedef struct {
                 s16 interfaceFlags;
                 Demo1Anim anim;
} Demo1;
typedef struct {
                 Vec3f initialAt;
                 f32 unk_0C;
                 s16 animFrame;
                 s16 yawDir;
} Demo3Anim;
typedef struct {
                 f32 fov;
                 f32 unk_04;
                 s16 interfaceFlags;
                 Demo3Anim anim;
} Demo3;
typedef struct {
                 s16 animTimer;
                 Vec3f atTarget;
} Demo6Anim;
typedef struct {
                 s16 interfaceFlags;
                 s16 unk_02;
                 Demo6Anim anim;
} Demo6;
typedef struct {
                 f32 curFrame;
                 s16 keyframe;
                 s16 doLERPAt;
                 s16 finishAction;
                 s16 animTimer;
} Demo9Anim;
typedef struct {
                 s16 interfaceFlags;
                 Demo9Anim anim;
} Demo9;
typedef struct {
                 CutsceneCameraPoint* atPoints;
                 CutsceneCameraPoint* eyePoints;
                 s16 actionParameters;
                 s16 initTimer;
} OnePointDemoCamera;
typedef struct {
                 OnePointDemoCamera onePointDemo;
                 Demo9 demo9;
} Demo9OnePointDemo;
typedef struct {
                 f32 lerpAtScale;
                 s16 interfaceFlags;
} Special0;
typedef struct {
                 s16 initalTimer;
} Special4;
typedef struct {
                 s16 animTimer;
} Special5Anim;
typedef struct {
                 f32 yOffset;
                 f32 eyeDist;
                 f32 minDistForRot;
                 f32 fovTarget;
                 f32 atMaxLERPScale;
                 s16 timerInit;
                 s16 pitch;
                 s16 interfaceFlags;
                 s16 unk_1A;
                 Special5Anim anim;
} Special5;
typedef struct {
                 s16 idx;
} Special7;
typedef struct {
                 f32 initalPlayerY;
                 s16 animTimer;
} Special6Anim;
typedef struct {
                 s16 interfaceFlags;
                 Special6Anim anim;
} Special6;
typedef struct {
                 s16 targetYaw;
} Special9Anim;
typedef struct {
                 f32 yOffset;
                 f32 unk_04;
                 s16 interfaceFlags;
                 s16 unk_0A;
                 Special9Anim anim;
} Special9Params;
typedef struct {
                 DoorParams doorParams;
                 Special9Params params;
} Special9;
typedef struct {
                 Vec3f pos;
                 Vec3f norm;
                 CollisionPoly* poly;
                 VecSph sphNorm;
                 u32 bgId;
} CamColChk;
typedef struct {
    char paramData[0x50];
                 Vec3f at;
                 Vec3f eye;
                 Vec3f up;
                 Vec3f eyeNext;
                 Vec3f skyboxOffset;
                 struct GlobalContext* globalCtx;
                 struct Player* player;
                 PosRot playerPosRot;
                 struct Actor* target;
                 PosRot targetPosRot;
                 f32 rUpdateRateInv;
                 f32 pitchUpdateRateInv;
                 f32 yawUpdateRateInv;
                 f32 xzOffsetUpdateRate;
                 f32 yOffsetUpdateRate;
                 f32 fovUpdateRate;
                 f32 xzSpeed;
                 f32 dist;
                 f32 speedRatio;
                 Vec3f posOffset;
                 Vec3f playerPosDelta;
                 f32 fov;
                 f32 atLERPStepScale;
                 f32 playerGroundY;
                 Vec3f floorNorm;
                 f32 waterYPos;
                 s32 waterPrevCamIdx;
                 s32 waterPrevCamSetting;
                 s32 waterQuakeId;
                 void* data0;
                 void* data1;
                 s16 data2;
                 s16 data3;
                 s16 uid;
                 char unk_132[0x02];
                 Vec3s inputDir;
                 Vec3s camDir;
                 s16 status;
                 s16 setting;
                 s16 mode;
                 s16 bgCheckId;
                 s16 camDataIdx;
                 s16 unk_14A;
                 s16 unk_14C;
                 s16 childCamIdx;
                 s16 unk_150;
                 s16 unk_152;
                 s16 prevSetting;
                 s16 nextCamDataIdx;
                 s16 nextBGCheckId;
                 s16 roll;
                 s16 paramFlags;
                 s16 animState;
                 s16 timer;
                 s16 parentCamIdx;
                 s16 thisIdx;
                 s16 prevCamDataIdx;
                 s16 unk_168;
                 s16 unk_16A;
} Camera;
typedef struct {
                 s32 unk_00;
                 Vec3f at;
                 Vec3f eye;
                 Vec3f up;
                 Vec3f unk_28;
                 s32 unk_34;
                 s32 unk_38;
                 s32 unk_3C;
                 s32 unk_40;
                 s32 unk_44;
                 f32 fov;
                 s16 unk_4C;
                 f32 unk_50;
                 Vec3f unk_54;
                 Vec3f unk_60;
                 f32 unk_6C;
                 f32 unk_70;
                 f32 unk_74;
                 s16 unk_78;
                 s16 unk_7A;
                 s16 unk_7C;
                 s16 unk_7E;
                 s16 unk_80;
                 s16 unk_82;
                 s16 unk_84;
                 s16 unk_86;
                 s32 unk_88;
                 char unk_8C[0x1034];
                 Vec3s unk_10C0;
                 Vec3s unk_10C6;
} DBCamera;
typedef struct {
               u32 vromStart;
               u32 vromEnd;
} RomFile;
typedef struct {
               RomFile sceneFile;
               RomFile titleFile;
               u8 unk_10;
               u8 config;
               u8 unk_12;
               u8 unk_13;
} Scene;
typedef struct {
               u8 code;
               u8 data1;
               u32 data2;
} SCmdBase;
typedef struct {
               u8 code;
               u8 data1;
               u32 segment;
} SCmdSpawnList;
typedef struct {
               u8 code;
               u8 num;
               u32 segment;
} SCmdActorList;
typedef struct {
               u8 code;
               u8 data1;
               u32 segment;
} SCmdCsCameraList;
typedef struct {
               u8 code;
               u8 data1;
               u32 segment;
} SCmdColHeader;
typedef struct {
               u8 code;
               u8 num;
               u32 segment;
} SCmdRoomList;
typedef struct {
               u8 code;
               u8 data1;
               char pad[2];
               s8 unk_04;
               s8 unk_05;
               s8 unk_06;
               u8 unk_07;
} SCmdWindSettings;
typedef struct {
               u8 code;
               u8 data1;
               u32 segment;
} SCmdEntranceList;
typedef struct {
               u8 code;
               u8 cUpElfMsgNum;
               u32 keepObjectId;
} SCmdSpecialFiles;
typedef struct {
               u8 code;
               u8 gpFlag1;
               u32 gpFlag2;
} SCmdRoomBehavior;
typedef struct {
               u8 code;
               u8 data1;
               u32 segment;
} SCmdMesh;
typedef struct {
               u8 code;
               u8 num;
               u32 segment;
} SCmdObjectList;
typedef struct {
               u8 code;
               u8 num;
               u32 segment;
} SCmdLightList;
typedef struct {
               u8 code;
               u8 data1;
               u32 segment;
} SCmdPathList;
typedef struct {
               u8 code;
               u8 num;
               u32 segment;
} SCmdTransiActorList;
typedef struct {
               u8 code;
               u8 num;
               u32 segment;
} SCmdLightSettingList;
typedef struct {
               u8 code;
               u8 data1;
               char pad[2];
               u8 hour;
               u8 min;
               u8 unk_06;
} SCmdTimeSettings;
typedef struct {
               u8 code;
               u8 data1;
               char pad[2];
               u8 skyboxId;
               u8 unk_05;
               u8 unk_06;
} SCmdSkyboxSettings;
typedef struct {
               u8 code;
               u8 data1;
               char pad[2];
               u8 unk_04;
               u8 unk_05;
} SCmdSkyboxDisables;
typedef struct {
               u8 code;
               u8 data1;
               u32 data2;
} SCmdEndMarker;
typedef struct {
               u8 code;
               u8 data1;
               u32 segment;
} SCmdExitList;
typedef struct {
               u8 code;
               u8 bgmId;
               char pad[4];
               u8 nightSeqIndex;
               u8 seqIndex;
} SCmdSoundSettings;
typedef struct {
               u8 code;
               u8 data1;
               char pad[5];
               u8 echo;
} SCmdEchoSettings;
typedef struct {
               u8 code;
               u8 data1;
               u32 segment;
} SCmdCutsceneData;
typedef struct {
               u8 code;
               u8 data1;
               u32 segment;
} SCmdAltHeaders;
typedef struct {
               u8 code;
               u8 cameraMovement;
               u32 area;
} SCmdMiscSettings;
typedef struct {
    u8 headerType;
} MeshHeaderBase;
typedef struct {
    MeshHeaderBase base;
    u8 numEntries;
    u32 dListStart;
    u32 dListEnd;
} MeshHeader0;
typedef struct {
    u32 opaqueDList;
    u32 translucentDList;
} MeshEntry0;
typedef struct {
    MeshHeaderBase base;
    u8 format;
    u32 entryRecord;
} MeshHeader1Base;
typedef struct {
    MeshHeader1Base base;
    u32 imagePtr;
    u32 unknown;
    u32 unknown2;
    u16 bgWidth;
    u16 bgHeight;
    u8 imageFormat;
    u8 imageSize;
    u16 imagePal;
    u16 imageFlip;
} MeshHeader1Single;
typedef struct {
    MeshHeader1Base base;
    u8 bgCnt;
    u32 bgRecordPtr;
} MeshHeader1Multi;
typedef struct {
    u16 unknown;
    s8 bgID;
    u32 imagePtr;
    u32 unknown2;
    u32 unknown3;
    u16 bgWidth;
    u16 bgHeight;
    u8 imageFmt;
    u8 imageSize;
    u16 imagePal;
    u16 imageFlip;
} BackgroundRecord;
typedef struct {
    s16 playerXMax, playerZMax;
    s16 playerXMin, playerZMin;
    u32 opaqueDList;
    u32 translucentDList;
} MeshEntry2;
typedef struct {
    MeshHeaderBase base;
    u8 numEntries;
    u32 dListStart;
    u32 dListEnd;
} MeshHeader2;
typedef struct {
    u8 ambientClrR, ambientClrG, ambientClrB;
    u8 diffuseClrA_R, diffuseClrA_G, diffuseClrA_B;
    u8 diffuseDirA_X, diffuseDirA_Y, diffuseDirA_Z;
    u8 diffuseClrB_R, diffuseClrB_G, diffuseClrB_B;
    u8 diffuseDirB_X, diffuseDirB_Y, diffuseDirB_Z;
    u8 fogClrR, fogClrG, fogClrB;
    u16 unk;
    u16 drawDistance;
} LightSettings;
typedef struct {
               u8 count;
               Vec3s* points;
} Path;
typedef union {
    SCmdBase base;
    SCmdSpawnList spawnList;
    SCmdActorList actorList;
    SCmdCsCameraList csCameraList;
    SCmdRoomList roomList;
    SCmdEntranceList entranceList;
    SCmdObjectList objectList;
    SCmdLightList lightList;
    SCmdPathList pathList;
    SCmdTransiActorList transiActorList;
    SCmdLightSettingList lightSettingList;
    SCmdExitList exitList;
    SCmdColHeader colHeader;
    SCmdMesh mesh;
    SCmdSpecialFiles specialFiles;
    SCmdCutsceneData cutsceneData;
    SCmdRoomBehavior roomBehavior;
    SCmdWindSettings windSettings;
    SCmdTimeSettings timeSettings;
    SCmdSkyboxSettings skyboxSettings;
    SCmdSkyboxDisables skyboxDisables;
    SCmdEndMarker endMarker;
    SCmdSoundSettings soundSettings;
    SCmdEchoSettings echoSettings;
    SCmdMiscSettings miscSettings;
    SCmdAltHeaders altHeaders;
} SceneCmd;
typedef enum {
               SCENE_YDAN,
               SCENE_DDAN,
               SCENE_BDAN,
               SCENE_BMORI1,
               SCENE_HIDAN,
               SCENE_MIZUSIN,
               SCENE_JYASINZOU,
               SCENE_HAKADAN,
               SCENE_HAKADANCH,
               SCENE_ICE_DOUKUTO,
               SCENE_GANON,
               SCENE_MEN,
               SCENE_GERUDOWAY,
               SCENE_GANONTIKA,
               SCENE_GANON_SONOGO,
               SCENE_GANONTIKA_SONOGO,
               SCENE_TAKARAYA,
               SCENE_YDAN_BOSS,
               SCENE_DDAN_BOSS,
               SCENE_BDAN_BOSS,
               SCENE_MORIBOSSROOM,
               SCENE_FIRE_BS,
               SCENE_MIZUSIN_BS,
               SCENE_JYASINBOSS,
               SCENE_HAKADAN_BS,
               SCENE_GANON_BOSS,
               SCENE_GANON_FINAL,
               SCENE_ENTRA,
               SCENE_ENTRA_N,
               SCENE_ENRUI,
               SCENE_MARKET_ALLEY,
               SCENE_MARKET_ALLEY_N,
               SCENE_MARKET_DAY,
               SCENE_MARKET_NIGHT,
               SCENE_MARKET_RUINS,
               SCENE_SHRINE,
               SCENE_SHRINE_N,
               SCENE_SHRINE_R,
               SCENE_KOKIRI_HOME,
               SCENE_KOKIRI_HOME3,
               SCENE_KOKIRI_HOME4,
               SCENE_KOKIRI_HOME5,
               SCENE_KAKARIKO,
               SCENE_KAKARIKO3,
               SCENE_SHOP1,
               SCENE_KOKIRI_SHOP,
               SCENE_GOLON,
               SCENE_ZOORA,
               SCENE_DRAG,
               SCENE_ALLEY_SHOP,
               SCENE_NIGHT_SHOP,
               SCENE_FACE_SHOP,
               SCENE_LINK_HOME,
               SCENE_IMPA,
               SCENE_MALON_STABLE,
               SCENE_LABO,
               SCENE_HYLIA_LABO,
               SCENE_TENT,
               SCENE_HUT,
               SCENE_DAIYOUSEI_IZUMI,
               SCENE_YOUSEI_IZUMI_TATE,
               SCENE_YOUSEI_IZUMI_YOKO,
               SCENE_KAKUSIANA,
               SCENE_HAKAANA,
               SCENE_HAKAANA2,
               SCENE_HAKAANA_OUKE,
               SCENE_SYATEKIJYOU,
               SCENE_TOKINOMA,
               SCENE_KENJYANOMA,
               SCENE_HAIRAL_NIWA,
               SCENE_HAIRAL_NIWA_N,
               SCENE_HIRAL_DEMO,
               SCENE_HAKASITARELAY,
               SCENE_TURIBORI,
               SCENE_NAKANIWA,
               SCENE_BOWLING,
               SCENE_SOUKO,
               SCENE_MIHARIGOYA,
               SCENE_MAHOUYA,
               SCENE_GANON_DEMO,
               SCENE_KINSUTA,
               SCENE_SPOT00,
               SCENE_SPOT01,
               SCENE_SPOT02,
               SCENE_SPOT03,
               SCENE_SPOT04,
               SCENE_SPOT05,
               SCENE_SPOT06,
               SCENE_SPOT07,
               SCENE_SPOT08,
               SCENE_SPOT09,
               SCENE_SPOT10,
               SCENE_SPOT11,
               SCENE_SPOT12,
               SCENE_SPOT13,
               SCENE_SPOT15,
               SCENE_SPOT16,
               SCENE_SPOT17,
               SCENE_SPOT18,
               SCENE_SPOT20,
               SCENE_GANON_TOU,
               SCENE_TEST01,
               SCENE_BESITU,
               SCENE_DEPTH_TEST,
               SCENE_SYOTES,
               SCENE_SYOTES2,
               SCENE_SUTARU,
               SCENE_HAIRAL_NIWA2,
               SCENE_SASATEST,
               SCENE_TESTROOM,
               SCENE_ID_MAX
} SceneID;
struct GraphicsContext;
struct GlobalContext;
typedef struct {
               u8 active;
               u8 unk_01;
               u8 unk_02;
} EffectStatus;
typedef struct {
               Vec3f velocity;
               Vec3f position;
               Vec3s unkVelocity;
               Vec3s unkPosition;
} EffectSparkElement;
typedef struct {
                Vec3s position;
                s32 numElements;
                EffectSparkElement elements[32];
                f32 speed;
                f32 gravity;
                u32 uDiv;
                u32 vDiv;
                Color_RGBA8 colorStart[4];
                Color_RGBA8 colorEnd[4];
                s32 timer;
                s32 duration;
} EffectSparkInit;
typedef struct {
                Vec3s position;
                s32 numElements;
                EffectSparkElement elements[32];
                f32 speed;
                f32 gravity;
                u32 uDiv;
                u32 vDiv;
                Color_RGBA8 colorStart[4];
                Color_RGBA8 colorEnd[4];
                s32 timer;
                s32 duration;
} EffectSpark;
typedef struct {
               s32 state;
               s32 timer;
               Vec3s p1;
               Vec3s p2;
               u16 flags;
} EffectBlureElement;
typedef struct {
                char unk_00[0x184];
                u8 p1StartColor[4];
                u8 p2StartColor[4];
                u8 p1EndColor[4];
                u8 p2EndColor[4];
                s32 elemDuration;
                s32 unkFlag;
                s32 calcMode;
} EffectBlureInit1;
typedef struct {
               s32 calcMode;
               u16 flags;
               s16 addAngleChange;
               u8 p1StartColor[4];
               u8 p2StartColor[4];
               u8 p1EndColor[4];
               u8 p2EndColor[4];
               u8 elemDuration;
               u8 unkFlag;
               u8 drawMode;
               u8 mode4Param;
               Color_RGBA8 altPrimColor;
               Color_RGBA8 altEnvColor;
} EffectBlureInit2;
typedef struct {
                EffectBlureElement elements[16];
                s32 calcMode;
                f32 mode4Param;
                u16 flags;
                s16 addAngleChange;
                s16 addAngle;
                Color_RGBA8 p1StartColor;
                Color_RGBA8 p2StartColor;
                Color_RGBA8 p1EndColor;
                Color_RGBA8 p2EndColor;
                u8 numElements;
                u8 elemDuration;
                u8 unkFlag;
                u8 drawMode;
                Color_RGBA8 altPrimColor;
                Color_RGBA8 altEnvColor;
} EffectBlure;
typedef struct {
               f32 initialSpeed;
               f32 endXChange;
               f32 endX;
               f32 startXChange;
               f32 startX;
               s16 yaw;
               s16 pitch;
} EffectShieldParticleElement;
typedef struct {
               u8 numElements;
               Vec3s position;
               Color_RGBA8 primColorStart;
               Color_RGBA8 envColorStart;
               Color_RGBA8 primColorMid;
               Color_RGBA8 envColorMid;
               Color_RGBA8 primColorEnd;
               Color_RGBA8 envColorEnd;
               f32 deceleration;
               f32 maxInitialSpeed;
               f32 lengthCutoff;
               u8 duration;
               LightPoint lightPoint;
               s32 lightDecay;
} EffectShieldParticleInit;
typedef struct {
                EffectShieldParticleElement elements[16];
                u8 numElements;
                Vec3s position;
                Color_RGBA8 primColorStart;
                Color_RGBA8 envColorStart;
                Color_RGBA8 primColorMid;
                Color_RGBA8 envColorMid;
                Color_RGBA8 primColorEnd;
                Color_RGBA8 envColorEnd;
                f32 deceleration;
                char unk_1A4[0x04];
                f32 maxInitialSpeed;
                f32 lengthCutoff;
                u8 duration;
                u8 timer;
                LightInfo lightInfo;
                LightNode* lightNode;
                s32 lightDecay;
} EffectShieldParticle;
typedef struct {
                 struct GlobalContext* globalCtx;
    struct {
        EffectStatus status;
        EffectSpark effect;
    } sparks[3];
    struct {
        EffectStatus status;
        EffectBlure effect;
    } blures[25];
    struct {
        EffectStatus status;
        EffectShieldParticle effect;
    } shieldParticles[3];
} EffectContext;
typedef struct {
               u32 size;
               void (*init)(void* effect, void* initParams);
               void (*destroy)(void* effect);
               s32 (*update)(void* effect);
               void (*draw)(void* effect, struct GraphicsContext* gfxCtx);
} EffectInfo;
typedef enum {
               EFFECT_SPARK,
               EFFECT_BLURE1,
               EFFECT_BLURE2,
               EFFECT_SHIELD_PARTICLE
} EffectType;
struct EffectSs;
typedef u32 (*EffectSsInitFunc)(struct GlobalContext* globalCtx, u32 index, struct EffectSs* effectSs, void* initParams);
typedef void (*EffectSsUpdateFunc)(struct GlobalContext* globalCtx, u32 index, struct EffectSs* effectSs);
typedef void (*EffectSsDrawFunc)(struct GlobalContext* globalCtx, u32 index, struct EffectSs* effectSs);
typedef struct {
               u32 type;
               EffectSsInitFunc init;
} EffectSsInit;
typedef struct {
               u32 vromStart;
               u32 vromEnd;
               void* vramStart;
               void* vramEnd;
               void* loadedRamAddr;
               EffectSsInit* initInfo;
               u8 unk_18;
} EffectSsOverlay;
typedef struct EffectSs {
               Vec3f pos;
               Vec3f velocity;
               Vec3f accel;
               EffectSsUpdateFunc update;
               EffectSsDrawFunc draw;
               Vec3f vec;
               void* gfx;
               Actor* actor;
               s16 regs[13];
               u16 flags;
               s16 life;
               u8 priority;
               u8 type;
} EffectSs;
typedef struct {
               EffectSs* table;
               s32 searchStartIndex;
               s32 tableSize;
} EffectSsInfo;
typedef enum {
               EFFECT_SS_DUST,
               EFFECT_SS_KIRAKIRA,
               EFFECT_SS_BOMB,
               EFFECT_SS_BOMB2,
               EFFECT_SS_BLAST,
               EFFECT_SS_G_SPK,
               EFFECT_SS_D_FIRE,
               EFFECT_SS_BUBBLE,
               EFFECT_SS_UNSET,
               EFFECT_SS_G_RIPPLE,
               EFFECT_SS_G_SPLASH,
               EFFECT_SS_G_MAGMA,
               EFFECT_SS_G_FIRE,
               EFFECT_SS_LIGHTNING,
               EFFECT_SS_DT_BUBBLE,
               EFFECT_SS_HAHEN,
               EFFECT_SS_STICK,
               EFFECT_SS_SIBUKI,
               EFFECT_SS_SIBUKI2,
               EFFECT_SS_G_MAGMA2,
               EFFECT_SS_STONE1,
               EFFECT_SS_HITMARK,
               EFFECT_SS_FHG_FLASH,
               EFFECT_SS_K_FIRE,
               EFFECT_SS_SOLDER_SRCH_BALL,
               EFFECT_SS_KAKERA,
               EFFECT_SS_ICE_PIECE,
               EFFECT_SS_EN_ICE,
               EFFECT_SS_FIRE_TAIL,
               EFFECT_SS_EN_FIRE,
               EFFECT_SS_EXTRA,
               EFFECT_SS_FCIRCLE,
               EFFECT_SS_DEAD_DB,
               EFFECT_SS_DEAD_DD,
               EFFECT_SS_DEAD_DS,
               EFFECT_SS_DEAD_SOUND,
               EFFECT_SS_ICE_SMOKE,
               EFFECT_SS_TYPE_MAX
} EffectSsType;
typedef enum {
               EQUIP_SWORD,
               EQUIP_SHIELD,
               EQUIP_TUNIC,
               EQUIP_BOOTS
} EquipmentType;
typedef enum {
               UPG_QUIVER,
               UPG_BOMB_BAG,
               UPG_STRENGTH,
               UPG_SCALE,
               UPG_WALLET,
               UPG_BULLET_BAG,
               UPG_STICKS,
               UPG_NUTS
} UpgradeType;
typedef enum {
               QUEST_MEDALLION_FOREST,
               QUEST_MEDALLION_FIRE,
               QUEST_MEDALLION_WATER,
               QUEST_MEDALLION_SPIRIT,
               QUEST_MEDALLION_SHADOW,
               QUEST_MEDALLION_LIGHT,
               QUEST_SONG_MINUET,
               QUEST_SONG_BOLERO,
               QUEST_SONG_SERENADE,
               QUEST_SONG_REQUIEM,
               QUEST_SONG_NOCTURNE,
               QUEST_SONG_PRELUDE,
               QUEST_SONG_LULLABY,
               QUEST_SONG_EPONA,
               QUEST_SONG_SARIA,
               QUEST_SONG_SUN,
               QUEST_SONG_TIME,
               QUEST_SONG_STORMS,
               QUEST_KOKIRI_EMERALD,
               QUEST_GORON_RUBY,
               QUEST_ZORA_SAPPHIRE,
               QUEST_STONE_OF_AGONY,
               QUEST_GERUDO_CARD,
               QUEST_SKULL_TOKEN,
               QUEST_HEART_PIECE
} QuestItem;
typedef enum {
               DUNGEON_KEY_BOSS,
               DUNGEON_COMPASS,
               DUNGEON_MAP
} DungeonItem;
typedef enum {
               SLOT_STICK,
               SLOT_NUT,
               SLOT_BOMB,
               SLOT_BOW,
               SLOT_ARROW_FIRE,
               SLOT_DINS_FIRE,
               SLOT_SLINGSHOT,
               SLOT_OCARINA,
               SLOT_BOMBCHU,
               SLOT_HOOKSHOT,
               SLOT_ARROW_ICE,
               SLOT_FARORES_WIND,
               SLOT_BOOMERANG,
               SLOT_LENS,
               SLOT_BEAN,
               SLOT_HAMMER,
               SLOT_ARROW_LIGHT,
               SLOT_NAYRUS_LOVE,
               SLOT_BOTTLE_1,
               SLOT_BOTTLE_2,
               SLOT_BOTTLE_3,
               SLOT_BOTTLE_4,
               SLOT_TRADE_ADULT,
               SLOT_TRADE_CHILD,
               SLOT_NONE = 0xFF
} InventorySlot;
typedef enum {
               ITEM_STICK,
               ITEM_NUT,
               ITEM_BOMB,
               ITEM_BOW,
               ITEM_ARROW_FIRE,
               ITEM_DINS_FIRE,
               ITEM_SLINGSHOT,
               ITEM_OCARINA_FAIRY,
               ITEM_OCARINA_TIME,
               ITEM_BOMBCHU,
               ITEM_HOOKSHOT,
               ITEM_LONGSHOT,
               ITEM_ARROW_ICE,
               ITEM_FARORES_WIND,
               ITEM_BOOMERANG,
               ITEM_LENS,
               ITEM_BEAN,
               ITEM_HAMMER,
               ITEM_ARROW_LIGHT,
               ITEM_NAYRUS_LOVE,
               ITEM_BOTTLE,
               ITEM_POTION_RED,
               ITEM_POTION_GREEN,
               ITEM_POTION_BLUE,
               ITEM_FAIRY,
               ITEM_FISH,
               ITEM_MILK_BOTTLE,
               ITEM_LETTER_RUTO,
               ITEM_BLUE_FIRE,
               ITEM_BUG,
               ITEM_BIG_POE,
               ITEM_MILK_HALF,
               ITEM_POE,
               ITEM_WEIRD_EGG,
               ITEM_CHICKEN,
               ITEM_LETTER_ZELDA,
               ITEM_MASK_KEATON,
               ITEM_MASK_SKULL,
               ITEM_MASK_SPOOKY,
               ITEM_MASK_BUNNY,
               ITEM_MASK_GORON,
               ITEM_MASK_ZORA,
               ITEM_MASK_GERUDO,
               ITEM_MASK_TRUTH,
               ITEM_SOLD_OUT,
               ITEM_POCKET_EGG,
               ITEM_POCKET_CUCCO,
               ITEM_COJIRO,
               ITEM_ODD_MUSHROOM,
               ITEM_ODD_POTION,
               ITEM_SAW,
               ITEM_SWORD_BROKEN,
               ITEM_PRESCRIPTION,
               ITEM_FROG,
               ITEM_EYEDROPS,
               ITEM_CLAIM_CHECK,
               ITEM_BOW_ARROW_FIRE,
               ITEM_BOW_ARROW_ICE,
               ITEM_BOW_ARROW_LIGHT,
               ITEM_SWORD_KOKIRI,
               ITEM_SWORD_MASTER,
               ITEM_SWORD_BGS,
               ITEM_SHIELD_DEKU,
               ITEM_SHIELD_HYLIAN,
               ITEM_SHIELD_MIRROR,
               ITEM_TUNIC_KOKIRI,
               ITEM_TUNIC_GORON,
               ITEM_TUNIC_ZORA,
               ITEM_BOOTS_KOKIRI,
               ITEM_BOOTS_IRON,
               ITEM_BOOTS_HOVER,
               ITEM_BULLET_BAG_30,
               ITEM_BULLET_BAG_40,
               ITEM_BULLET_BAG_50,
               ITEM_QUIVER_30,
               ITEM_QUIVER_40,
               ITEM_QUIVER_50,
               ITEM_BOMB_BAG_20,
               ITEM_BOMB_BAG_30,
               ITEM_BOMB_BAG_40,
               ITEM_BRACELET,
               ITEM_GAUNTLETS_SILVER,
               ITEM_GAUNTLETS_GOLD,
               ITEM_SCALE_SILVER,
               ITEM_SCALE_GOLDEN,
               ITEM_SWORD_KNIFE,
               ITEM_WALLET_ADULT,
               ITEM_WALLET_GIANT,
               ITEM_SEEDS,
               ITEM_FISHING_POLE,
               ITEM_SONG_MINUET,
               ITEM_SONG_BOLERO,
               ITEM_SONG_SERENADE,
               ITEM_SONG_REQUIEM,
               ITEM_SONG_NOCTURNE,
               ITEM_SONG_PRELUDE,
               ITEM_SONG_LULLABY,
               ITEM_SONG_EPONA,
               ITEM_SONG_SARIA,
               ITEM_SONG_SUN,
               ITEM_SONG_TIME,
               ITEM_SONG_STORMS,
               ITEM_MEDALLION_FOREST,
               ITEM_MEDALLION_FIRE,
               ITEM_MEDALLION_WATER,
               ITEM_MEDALLION_SPIRIT,
               ITEM_MEDALLION_SHADOW,
               ITEM_MEDALLION_LIGHT,
               ITEM_KOKIRI_EMERALD,
               ITEM_GORON_RUBY,
               ITEM_ZORA_SAPPHIRE,
               ITEM_STONE_OF_AGONY,
               ITEM_GERUDO_CARD,
               ITEM_SKULL_TOKEN,
               ITEM_HEART_CONTAINER,
               ITEM_HEART_PIECE,
               ITEM_KEY_BOSS,
               ITEM_COMPASS,
               ITEM_DUNGEON_MAP,
               ITEM_KEY_SMALL,
               ITEM_MAGIC_SMALL,
               ITEM_MAGIC_LARGE,
               ITEM_HEART_PIECE_2,
               ITEM_INVALID_1,
               ITEM_INVALID_2,
               ITEM_INVALID_3,
               ITEM_INVALID_4,
               ITEM_INVALID_5,
               ITEM_INVALID_6,
               ITEM_INVALID_7,
               ITEM_MILK,
               ITEM_HEART,
               ITEM_RUPEE_GREEN,
               ITEM_RUPEE_BLUE,
               ITEM_RUPEE_RED,
               ITEM_RUPEE_PURPLE,
               ITEM_RUPEE_GOLD,
               ITEM_INVALID_8,
               ITEM_STICKS_5,
               ITEM_STICKS_10,
               ITEM_NUTS_5,
               ITEM_NUTS_10,
               ITEM_BOMBS_5,
               ITEM_BOMBS_10,
               ITEM_BOMBS_20,
               ITEM_BOMBS_30,
               ITEM_ARROWS_SMALL,
               ITEM_ARROWS_MEDIUM,
               ITEM_ARROWS_LARGE,
               ITEM_SEEDS_30,
               ITEM_BOMBCHUS_5,
               ITEM_BOMBCHUS_20,
               ITEM_STICK_UPGRADE_20,
               ITEM_STICK_UPGRADE_30,
               ITEM_NUT_UPGRADE_30,
               ITEM_NUT_UPGRADE_40,
               ITEM_LAST_USED = 0xFC,
               ITEM_NONE_FE = 0xFE,
               ITEM_NONE = 0xFF
} ItemID;
typedef enum {
               GI_NONE,
               GI_BOMBS_5,
               GI_NUTS_5,
               GI_BOMBCHUS_10,
               GI_BOW,
               GI_SLINGSHOT,
               GI_BOOMERANG,
               GI_STICKS_1,
               GI_HOOKSHOT,
               GI_LONGSHOT,
               GI_LENS,
               GI_LETTER_ZELDA,
               GI_OCARINA_OOT,
               GI_HAMMER,
               GI_COJIRO,
               GI_BOTTLE,
               GI_POTION_RED,
               GI_POTION_GREEN,
               GI_POTION_BLUE,
               GI_FAIRY,
               GI_MILK_BOTTLE,
               GI_LETTER_RUTO,
               GI_BEAN,
               GI_MASK_SKULL,
               GI_MASK_SPOOKY,
               GI_CHICKEN,
               GI_MASK_KEATON,
               GI_MASK_BUNNY,
               GI_MASK_TRUTH,
               GI_POCKET_EGG,
               GI_POCKET_CUCCO,
               GI_ODD_MUSHROOM,
               GI_ODD_POTION,
               GI_SAW,
               GI_SWORD_BROKEN,
               GI_PRESCRIPTION,
               GI_FROG,
               GI_EYEDROPS,
               GI_CLAIM_CHECK,
               GI_SWORD_KOKIRI,
               GI_SWORD_KNIFE,
               GI_SHIELD_DEKU,
               GI_SHIELD_HYLIAN,
               GI_SHIELD_MIRROR,
               GI_TUNIC_GORON,
               GI_TUNIC_ZORA,
               GI_BOOTS_IRON,
               GI_BOOTS_HOVER,
               GI_QUIVER_40,
               GI_QUIVER_50,
               GI_BOMB_BAG_20,
               GI_BOMB_BAG_30,
               GI_BOMB_BAG_40,
               GI_GAUNTLETS_SILVER,
               GI_GAUNTLETS_GOLD,
               GI_SCALE_SILVER,
               GI_SCALE_GOLD,
               GI_STONE_OF_AGONY,
               GI_GERUDO_CARD,
               GI_OCARINA_FAIRY,
               GI_SEEDS_5,
               GI_HEART_CONTAINER,
               GI_HEART_PIECE,
               GI_KEY_BOSS,
               GI_COMPASS,
               GI_MAP,
               GI_KEY_SMALL,
               GI_MAGIC_SMALL,
               GI_MAGIC_LARGE,
               GI_WALLET_ADULT,
               GI_WALLET_GIANT,
               GI_WEIRD_EGG,
               GI_HEART,
               GI_ARROWS_SMALL,
               GI_ARROWS_MEDIUM,
               GI_ARROWS_LARGE,
               GI_RUPEE_GREEN,
               GI_RUPEE_BLUE,
               GI_RUPEE_RED,
               GI_HEART_CONTAINER_2,
               GI_MILK,
               GI_MASK_GORON,
               GI_MASK_ZORA,
               GI_MASK_GERUDO,
               GI_BRACELET,
               GI_RUPEE_PURPLE,
               GI_RUPEE_GOLD,
               GI_SWORD_BGS,
               GI_ARROW_FIRE,
               GI_ARROW_ICE,
               GI_ARROW_LIGHT,
               GI_SKULL_TOKEN,
               GI_DINS_FIRE,
               GI_FARORES_WIND,
               GI_NAYRUS_LOVE,
               GI_BULLET_BAG_30,
               GI_BULLET_BAG_40,
               GI_STICKS_5,
               GI_STICKS_10,
               GI_NUTS_5_2,
               GI_NUTS_10,
               GI_BOMBS_1,
               GI_BOMBS_10,
               GI_BOMBS_20,
               GI_BOMBS_30,
               GI_SEEDS_30,
               GI_BOMBCHUS_5,
               GI_BOMBCHUS_20,
               GI_FISH,
               GI_BUGS,
               GI_BLUE_FIRE,
               GI_POE,
               GI_BIG_POE,
               GI_DOOR_KEY,
               GI_RUPEE_GREEN_LOSE,
               GI_RUPEE_BLUE_LOSE,
               GI_RUPEE_RED_LOSE,
               GI_RUPEE_PURPLE_LOSE,
               GI_HEART_PIECE_WIN,
               GI_STICK_UPGRADE_20,
               GI_STICK_UPGRADE_30,
               GI_NUT_UPGRADE_30,
               GI_NUT_UPGRADE_40,
               GI_BULLET_BAG_50,
               GI_ICE_TRAP,
               GI_TEXT_0,
               GI_MAX
} GetItemID;
typedef enum {
               EXCH_ITEM_NONE,
               EXCH_ITEM_LETTER_ZELDA,
               EXCH_ITEM_WEIRD_EGG,
               EXCH_ITEM_CHICKEN,
               EXCH_ITEM_BEAN,
               EXCH_ITEM_POCKET_EGG,
               EXCH_ITEM_POCKET_CUCCO,
               EXCH_ITEM_COJIRO,
               EXCH_ITEM_ODD_MUSHROOM,
               EXCH_ITEM_ODD_POTION,
               EXCH_ITEM_SAW,
               EXCH_ITEM_SWORD_BROKEN,
               EXCH_ITEM_PRESCRIPTION,
               EXCH_ITEM_FROG,
               EXCH_ITEM_EYEDROPS,
               EXCH_ITEM_CLAIM_CHECK,
               EXCH_ITEM_MASK_SKULL,
               EXCH_ITEM_MASK_SPOOKY,
               EXCH_ITEM_MASK_KEATON,
               EXCH_ITEM_MASK_BUNNY,
               EXCH_ITEM_MASK_TRUTH,
               EXCH_ITEM_MASK_GORON,
               EXCH_ITEM_MASK_ZORA,
               EXCH_ITEM_MASK_GERUDO,
               EXCH_ITEM_FISH,
               EXCH_ITEM_BLUE_FIRE,
               EXCH_ITEM_BUG,
               EXCH_ITEM_POE,
               EXCH_ITEM_BIG_POE,
               EXCH_ITEM_LETTER_RUTO,
               EXCH_ITEM_MAX
} ExchangeItemID;
typedef struct {
    f32 unk_0;
    f32 unk_4;
} TransitionUnkData;
typedef struct {
               s32 row;
               s32 col;
               s32 frame;
               TransitionUnkData* unk_0C;
               Vtx* vtxFrame1;
               Vtx* vtxFrame2;
               Mtx projection;
               Mtx modelView;
               Mtx unk_98;
               Gfx* gfx;
               u16* zBuffer;
} TransitionUnk;
typedef struct {
                Color_RGBA8_u32 color;
                Color_RGBA8_u32 envColor;
                u8 direction;
                u8 frame;
                u8 isDone;
                u16 texX;
                u16 texY;
                u16 normal;
                Mtx projection;
                Mtx lookAt;
                Mtx modelView[2][3];
} TransitionWipe;
typedef struct {
                u8 fadeType;
                u8 isDone;
                u8 fadeDirection;
                Color_RGBA8_u32 fadeColor;
                u16 fadeTimer;
} TransitionFade;
typedef struct {
                Color_RGBA8_u32 color;
                Color_RGBA8_u32 envColor;
                s32 texX;
                s32 texY;
                s32 step;
                u8 unk_14;
                u8 typeColor;
                u8 speed;
                u8 effect;
                u8 isDone;
                u8 frame;
                u16 normal;
                Mtx projection;
                Mtx lookAt;
                char* texture;
                Mtx modelView[2][3];
} TransitionCircle;
typedef struct {
                Color_RGBA8_u32 color;
                f32 transPos;
                f32 step;
                s32 state;
                s32 fadeDirection;
                Mtx projection;
                s32 frame;
                Mtx modelView[2][3];
} TransitionTriforce;
typedef struct {
    u32 cont: 1;
    u32 type: 4;
    u32 offset: 11;
    s32 value: 16;
} InitChainEntry;
typedef enum {
              ICHAINTYPE_U8,
              ICHAINTYPE_S8,
              ICHAINTYPE_U16,
              ICHAINTYPE_S16,
              ICHAINTYPE_U32,
              ICHAINTYPE_S32,
              ICHAINTYPE_F32,
              ICHAINTYPE_F32_DIV1000,
              ICHAINTYPE_VEC3F,
              ICHAINTYPE_VEC3F_DIV1000,
              ICHAINTYPE_VEC3S
} InitChainType;
typedef struct lldiv_t {
    s64 quot;
    s64 rem;
} lldiv_t;
typedef struct ldiv_t {
    s32 quot;
    s32 rem;
} ldiv_t;
typedef struct {
               s32 regPage;
               s32 regGroup;
               s32 regCur;
               s32 dpadLast;
               s32 repeat;
               s16 data[29 * 6 * 16];
} GameInfo;
typedef struct {
                  u16 headMagic;
                  Gfx polyOpaBuffer[0x17E0];
                  Gfx polyXluBuffer[0x800];
                  Gfx overlayBuffer[0x400];
                  Gfx workBuffer[0x80];
                  Gfx unusedBuffer[0x20];
                  u16 tailMagic;
} GfxPool;
typedef struct {
                 u32 size;
                 void* bufp;
                 void* head;
                 void* tail;
} TwoHeadArena;
typedef struct {
                 u32 size;
                 Gfx* bufp;
                 Gfx* p;
                 Gfx* d;
} TwoHeadGfxArena;
typedef struct {
               u16* fb1;
               u16* swapBuffer;
               OSViMode* viMode;
               u32 features;
               u8 unk_10;
               s8 updateRate;
               s8 updateRate2;
               u8 unk_13;
               f32 xScale;
               f32 yScale;
} CfbInfo;
typedef struct OSScTask {
               struct OSScTask* next;
               u32 state;
               u32 flags;
               CfbInfo* framebuffer;
               OSTask list;
               OSMesgQueue* msgQ;
               OSMesg msg;
} OSScTask;
typedef struct GraphicsContext {
                 Gfx* polyOpaBuffer;
                 Gfx* polyXluBuffer;
                 char unk_008[0x08];
                 Gfx* overlayBuffer;
                 u32 unk_014;
                 char unk_018[0x20];
                 OSMesg msgBuff[0x08];
                 OSMesgQueue* schedMsgQ;
                 OSMesgQueue queue;
                 char unk_074[0x04];
                 OSScTask task;
                 char unk_0D0[0xE0];
                 Gfx* workBuffer;
                 TwoHeadGfxArena work;
                 char unk_01C4[0xC0];
                 OSViMode* viMode;
                 char unk_0288[0x20];
                 TwoHeadGfxArena overlay;
                 TwoHeadGfxArena polyOpa;
                 TwoHeadGfxArena polyXlu;
                 u32 gfxPoolIdx;
                 u16* curFrameBuffer;
                 char unk_2E0[0x04];
                 u32 viFeatures;
                 s32 fbIdx;
                 void (*callback)(struct GraphicsContext*, u32);
                 u32 callbackParam;
                 f32 xScale;
                 f32 yScale;
                 char unk_2FC[0x04];
} GraphicsContext;
typedef struct {
               OSContPad cur;
               OSContPad prev;
               OSContPad press;
               OSContPad rel;
} Input;
typedef struct {
                s32 topY;
                s32 bottomY;
                s32 leftX;
                s32 rightX;
} Viewport;
typedef struct {
                 s32 magic;
                 GraphicsContext* gfxCtx;
                 Viewport viewport;
                 f32 fovy;
                 f32 zNear;
                 f32 zFar;
                 f32 scale;
                 Vec3f eye;
                 Vec3f lookAt;
                 Vec3f up;
                 Vp vp;
                 Mtx projection;
                 Mtx viewing;
                 Mtx* projectionPtr;
                 Mtx* viewingPtr;
                 Vec3f unk_E8;
                 Vec3f unk_F4;
                 f32 unk_100;
                 Vec3f unk_104;
                 Vec3f unk_110;
                 u16 normal;
                 s32 flags;
                 s32 unk_124;
} View;
typedef struct {
               u8 seqIndex;
               u8 nightSeqIndex;
               char unk_02[0x2];
} SoundContext;
typedef struct {
               u32 toggle;
               s32 counter;
} SubGlobalContext7B8;
typedef struct {
               Vec3f pos;
               f32 unk_0C;
               Color_RGB8 color;
} TargetContextEntry;
typedef struct {
               Vec3f naviRefPos;
               Vec3f targetCenterPos;
               Color_RGBAf naviInner;
               Color_RGBAf naviOuter;
               Actor* arrowPointedActor;
               Actor* targetedActor;
               f32 unk_40;
               f32 unk_44;
               s16 unk_48;
               u8 activeCategory;
               u8 unk_4B;
               s8 unk_4C;
               char unk_4D[0x03];
               TargetContextEntry arr_50[3];
               Actor* unk_8C;
               Actor* unk_90;
               Actor* unk_94;
} TargetContext;
typedef struct {
               u8* texture;
               s16 unk_4;
               s16 unk_6;
               u8 unk_8;
               u8 unk_9;
               u8 delayA;
               u8 delayB;
               s16 unk_C;
               s16 unk_E;
} TitleCardContext;
typedef struct {
               s32 length;
               Actor* head;
} ActorListEntry;
typedef struct {
                 u8 unk_00;
                 char unk_01[0x01];
                 u8 unk_02;
                 u8 unk_03;
                 char unk_04[0x04];
                 u8 total;
                 char unk_09[0x03];
                 ActorListEntry actorLists[12];
                 TargetContext targetCtx;
    struct {
                     u32 swch;
                     u32 tempSwch;
                     u32 unk0;
                     u32 unk1;
                     u32 chest;
                     u32 clear;
                     u32 tempClear;
                     u32 collect;
                     u32 tempCollect;
    } flags;
                 TitleCardContext titleCtx;
                 char unk_138[0x04];
                 void* absoluteSpace;
} ActorContext;
typedef struct {
               char unk_00[0x4];
               void* segment;
               u8 state;
               f32 unk_0C;
               u16 frames;
               u16 unk_12;
               s32 unk_14;
               u16 unk_18;
               u8 unk_1A;
               u8 unk_1B;
               CutsceneCameraPoint* cameraFocus;
               CutsceneCameraPoint* cameraPosition;
               CsCmdActorAction* linkAction;
               CsCmdActorAction* npcActions[10];
} CutsceneContext;
typedef struct {
               u16 countdown;
               Vec3f originPos;
               Vec3f relativePos;
} SoundSource;
typedef struct {
                char unk_00[0x128];
                void* staticSegments[3];
                Gfx* dpList;
                Gfx* unk_138;
                void* roomVtx;
                s16 unk_140;
                Vec3f rot;
} SkyboxContext;
typedef enum {
    MESSAGE_ICON_TRIANGLE,
    MESSAGE_ICON_SQUARE,
    MESSAGE_ICON_ARROW
} MessageBoxIcon;
typedef struct {
                 u32 msgOffset;
                 u32 msgLength;
                 char unk_8[0x3C00];
                 u8 iconBuf[128];
                 u8 fontBuf[128 * 320];
                 char msgBuf[1064];
                 char unk_E0B0[0xD8];
} Font;
typedef struct {
                 View view;
                 Font font;
                 void* textboxSegment;
                 char unk_E2B4[0x44];
                 u16 unk_E2F8;
                 u16 unk_E2FA;
                 char unk_E2FC[0x04];
                 s32 unk_E300;
                 u8 msgMode;
                 char unk_E305[0xD1];
                 u16 unk_E3D6;
                 char unk_E3D8[0x0A];
                 u16 unk_E3E2;
                 u8 unk_E3E4;
                 u8 choiceIndex;
                 char unk_E3E6[0x01];
                 u8 unk_E3E7;
                 char unk_E3E8[0x04];
                 u16 unk_E3EC;
                 u16 unk_E3EE;
                 u16 unk_E3F0;
                 u16 unk_E3F2;
                 u16 unk_E3F4;
                 char unk_E3F6[0x16];
                 u16 unk_E40C;
                 s16 unk_E40E;
                 u8 unk_E410;
                 char unk_E411[0x07];
} MessageContext;
typedef struct {
                 View view;
                 Vtx* vtx_128;
                 Vtx* vtx_12C;
                 void* parameterSegment;
                 void* do_actionSegment;
                 void* icon_itemSegment;
                 void* mapSegment;
                 u8 unk_140[32];
                 DmaRequest dmaRequest_160;
                 DmaRequest dmaRequest_180;
                 char unk_1A0[0x20];
                 OSMesgQueue loadQueue;
                 OSMesg loadMsg;
                 Viewport viewport;
                 s16 unk_1EC;
                 u16 unk_1EE;
                 u16 unk_1F0;
                 f32 unk_1F4;
                 s16 naviCalling;
                 s16 unk_1FA;
                 s16 unk_1FC;
                 s16 unk_1FE;
                 s16 unk_200;
                 s16 beatingHeartPrim[3];
                 s16 beatingHeartEnv[3];
                 s16 heartsPrimR[2];
                 s16 heartsPrimG[2];
                 s16 heartsPrimB[2];
                 s16 heartsEnvR[2];
                 s16 heartsEnvG[2];
                 s16 heartsEnvB[2];
                 s16 unk_226;
                 s16 unk_228;
                 s16 unk_22A;
                 s16 unk_22C;
                 s16 unk_22E;
                 s16 unk_230;
                 s16 counterDigits[4];
                 u8 unk_23A;
                 u16 unk_23C;
                 u16 hbaAmmo;
                 u16 unk_240;
                 u16 unk_242;
                 u16 unk_244;
                 u16 aAlpha;
                 u16 bAlpha;
                 u16 cLeftAlpha;
                 u16 cDownAlpha;
                 u16 cRightAlpha;
                 u16 healthAlpha;
                 u16 magicAlpha;
                 u16 minimapAlpha;
                 s16 startAlpha;
                 s16 unk_258;
                 s16 unk_25A;
                 s16 mapRoomNum;
                 s16 mapPaletteNum;
                 u8 unk_260;
                 u8 unk_261;
    struct {
                     u8 hGauge;
                     u8 bButton;
                     u8 aButton;
                     u8 bottles;
                     u8 tradeItems;
                     u8 hookshot;
                     u8 ocarina;
                     u8 warpSongs;
                     u8 sunsSong;
                     u8 farores;
                     u8 dinsNayrus;
                     u8 all;
    } restrictions;
} InterfaceContext;
typedef struct {
                 View view;
                 void* unk_128;
                 void* unk_12C;
                 void* unk_130;
                 void* unk_134;
                 void* unk_138;
                 void* unk_13C;
                 char unk_140[0x028];
                 Vtx* vtx_168;
                 char unk_16C[0x068];
                 u16 state;
                 u16 flag;
                 Vec3f eye;
                 u16 unk_1E4;
                 u16 mode;
                 u16 kscpPos;
                 u16 unk_1EA;
                 u16 unk_1EC;
                 char unk_1EE[0x2];
                 f32 unk_1F0;
                 f32 unk_1F4;
                 f32 unk_1F8;
                 f32 unk_1FC;
                 f32 unk_200;
                 f32 unk_204;
                 s16 unk_208;
                 char unk_20A[0xA];
                 s16 inputX;
                 s16 inputY;
                 s16 unk_218;
                 s16 unk_21A;
                 s16 unk_21C;
                 s16 unk_21E;
                 s16 unk_220;
                 s16 unk_222;
                 s16 unk_224;
                 s16 unk_226;
                 s16 unk_228;
                 s16 unk_22A;
                 s16 unk_22C;
                 s16 unk_22E;
                 s16 unk_230;
                 s16 unk_232;
                 s16 unk_234;
                 s16 unk_236;
                 s16 unk_238;
                 s16 unk_23A;
                 s16 unk_23C;
                 u16 unk_23E;
                 s16 unk_240;
                 u16 unk_242;
                 s16 unk_244;
                 s16 unk_246;
                 s16 unk_248;
                 s16 unk_24A;
                 s16 unk_24C;
                 s16 unk_24E;
                 s16 unk_250;
                 s16 unk_252;
                 s16 unk_254;
                 s16 unk_256;
                 s16 unk_258;
                 s16 unk_25A;
                 s16 unk_25C;
                 s16 unk_25E;
                 s16 unk_260;
                 s16 unk_262;
                 s16 unk_264;
                 s16 unk_266;
                 char unk_268[0x58];
} PauseContext;
typedef struct {
               char unk_00[0x02];
               u16 unk_02;
               Vec3f unk_04;
               char unk_10[0x03];
               u8 unk_13;
               char unk_14[0x01];
               u8 skyDisabled;
               u8 sunMoonDisabled;
               u8 gloomySky;
               u8 unk_18;
               u8 unk_19;
               u16 unk_1A;
               char unk_1C[0x02];
               u8 unk_1E;
               u8 unk_1F;
               u8 unk_20;
               u8 unk_21;
               u16 unk_22;
               u16 unk_24;
               char unk_26[0x04];
               s8 unk_2A;
               s8 unk_2B;
               s8 unk_2C;
               char unk_2D[0x5E];
               s16 unk_8C[3][3];
               s16 unk_9E;
               s16 unk_A0;
               char unk_A2[0x06];
               s16 unk_A8;
               s16 unk_AA;
               s16 unk_AC;
               f32 unk_B0;
               u8 nbLightSettings;
               void* lightSettingsList;
               char unk_BC[0x03];
               u8 unk_BF;
               char unk_C0[0x0F];
               u8 unk_CF[3];
               s16 unk_D2;
               char unk_D4[0x02];
               s16 unk_D6;
               f32 unk_D8;
               u8 unk_DC;
               u8 gloomySkyEvent;
               u8 unk_DE;
               u8 lightning;
               u8 unk_E0;
               u8 unk_E1;
               u8 unk_E2[4];
               u8 unk_E6;
               u8 unk_E7;
               u8 unk_E8;
               char unk_E9[0x05];
               u8 unk_EE[4];
               u8 unk_F2[4];
               char unk_F6[0x06];
} EnvironmentContext;
typedef struct {
               s16 id;
               void* segment;
               DmaRequest dmaRequest;
               OSMesgQueue loadQueue;
               OSMesg loadMsg;
} ObjectStatus;
typedef struct {
                 void* spaceStart;
                 void* spaceEnd;
                 u8 num;
                 u8 unk_09;
                 u8 mainKeepIndex;
                 u8 subKeepIndex;
                 ObjectStatus status[19];
} ObjectContext;
typedef struct {
               Gfx* opa;
               Gfx* xlu;
} PolygonDlist;
typedef struct {
               u8 type;
               u8 num;
               void* start;
               void* end;
} Polygon;
typedef struct {
               u8 type;
               u8 num;
               void* start;
               void* end;
} PolygonType0;
typedef struct {
               u16 unk_00;
               u8 id;
               u32 source;
               u32 unk_0C;
               u32 tlut;
               u16 width;
               u16 height;
               u8 fmt;
               u8 siz;
               u16 mode0;
               u16 tlutCount;
} BgImage;
typedef struct {
               u8 type;
               u8 format;
               void* dlist;
    union {
        struct {
                       u32 source;
                       u32 unk_0C;
                       u32 tlut;
                       u16 width;
                       u16 height;
                       u8 fmt;
                       u8 siz;
                       u16 mode0;
                       u16 tlutCount;
        } single;
        struct {
                       u8 count;
                       BgImage* list;
        } multi;
    };
} PolygonType1;
typedef struct {
               Vec3s pos;
               s16 unk_06;
               Gfx* opa;
               Gfx* xlu;
} PolygonDlist2;
typedef struct {
               u8 type;
               u8 num;
               void* start;
               void* end;
} PolygonType2;
typedef union {
    Polygon polygon;
    PolygonType0 polygon0;
    PolygonType1 polygon1;
    PolygonType2 polygon2;
} Mesh;
typedef struct {
               s8 num;
               u8 unk_01;
               u8 unk_02;
               u8 unk_03;
               s8 echo;
               u8 showInvisActors;
               Mesh* mesh;
               void* segment;
               char unk_10[0x4];
} Room;
typedef struct {
               Room curRoom;
               Room prevRoom;
               void* bufPtrs[2];
               u8 unk_30;
               s8 status;
               void* unk_34;
               DmaRequest dmaRequest;
               OSMesgQueue loadQueue;
               OSMesg loadMsg;
} RoomContext;
typedef struct {
                s16 colATCount;
                u16 sacFlags;
                Collider* colAT[50];
                s32 colACCount;
                Collider* colAC[60];
                s32 colOCCount;
                Collider* colOC[50];
                s32 colLineCount;
                OcLine* colLine[3];
} CollisionCheckContext;
typedef struct ListAlloc {
               struct ListAlloc* prev;
               struct ListAlloc* next;
} ListAlloc;
typedef struct {
               s32 width;
               s32 height;
               s32 widthSave;
               s32 heightSave;
               u16* fbuf;
               u16* fbufSave;
               u8* cvgSave;
               u16* zbuf;
               u16* zbufSave;
               s32 ulxSave;
               s32 ulySave;
               s32 lrxSave;
               s32 lrySave;
               s32 ulx;
               s32 uly;
               s32 lrx;
               s32 lry;
               ListAlloc alloc;
               u32 unk_4C;
} PreRenderContext;
typedef struct {
    union {
        TransitionFade fade;
        TransitionCircle circle;
        TransitionTriforce triforce;
        TransitionWipe wipe;
        char data[0x228];
    };
                s32 transitionType;
                void* (*init)(void* transition);
                void (*destroy)(void* transition);
                void (*update)(void* transition, s32 updateRate);
                void (*draw)(void* transition, Gfx** gfxP);
                void (*start)(void* transition);
                void (*setType)(void* transition, s32 type);
                void (*setColor)(void* transition, u32 color);
                void (*setEnvColor)(void* transition, u32 color);
                s32 (*isDone)(void* transition);
} TransitionContext;
typedef struct {
               s16 id;
               Vec3s pos;
               Vec3s rot;
               s16 params;
} ActorEntry;
typedef struct {
    struct {
        s8 room;
        s8 effects;
    } sides[2];
               s16 id;
               Vec3s pos;
               s16 rotY;
               s16 params;
} TransitionActorEntry;
typedef struct {
               u8 spawn;
               u8 room;
} EntranceEntry;
typedef struct {
               u8* readBuff;
} SramContext;
typedef struct GameAllocEntry {
               struct GameAllocEntry* next;
               struct GameAllocEntry* prev;
               u32 size;
               u32 unk_0C;
} GameAllocEntry;
typedef struct {
               GameAllocEntry base;
               GameAllocEntry* head;
} GameAlloc;
struct GameState;
typedef void (*GameStateFunc)(struct GameState* gameState);
typedef struct GameState {
               GraphicsContext* gfxCtx;
               GameStateFunc main;
               GameStateFunc destroy;
               GameStateFunc init;
               u32 size;
               Input input[4];
               TwoHeadArena tha;
               GameAlloc alloc;
               u32 running;
               u32 frames;
               u32 unk_A0;
} GameState;
typedef struct {
                 GameState state;
                 void* staticSegment;
                 View view;
                 SramContext sramCtx;
                 u16 unk_1D4;
                 s16 coverAlpha;
                 s16 addAlpha;
                 u16 visibleDuration;
                 s16 ult;
                 s16 uls;
                 char unk_1E0[0x01];
                 u8 exit;
                 char unk_1E2[0x06];
} TitleContext;
struct SelectContext;
typedef struct {
               char* name;
               void (*loadFunc)(struct SelectContext*, s32);
               s32 entranceIndex;
} SceneSelectEntry;
typedef struct SelectContext {
                 GameState state;
                 View view;
                 s32 count;
                 SceneSelectEntry* scenes;
                 s32 currentScene;
                 s32 unk_1DC;
                 s32 unk_1E0[7];
                 s32 unk_1FC;
                 s32 unk_200;
                 s32 unk_204;
                 s32 opt;
                 s32 unk_20C;
                 s32 unk_210;
                 s32 unk_214;
                 s32 unk_218;
                 s32 unk_21C;
                 s32 unk_220;
                 s32 unk_224;
                 s32 unk_228;
                 s32 unk_22C;
                 s32 unk_230;
                 s32 unk_234;
                 void* staticSegment;
                 s32 unk_23C;
} SelectContext;
typedef struct {
                 GameState state;
                 void* staticSegment;
                 View view;
} SampleContext;
typedef struct {
               u8 byte0;
               u8 byte1;
               u8 byte2;
               u8 byte3;
} ElfMessage;
typedef struct GlobalContext {
                  GameState state;
                  s16 sceneNum;
                  u8 sceneConfig;
                  char unk_A7[0x9];
                  void* sceneSegment;
                  View view;
                  Camera mainCamera;
                  Camera subCameras[3];
                  Camera* cameraPtrs[4];
                  s16 activeCamera;
                  s16 nextCamera;
                  SoundContext soundCtx;
                  LightContext lightCtx;
                  SubGlobalContext7B8 sub_7B8;
                  CollisionContext colCtx;
                  ActorContext actorCtx;
                  CutsceneContext csCtx;
                  SoundSource soundSources[16];
                  SramContext sramCtx;
                  SkyboxContext skyboxCtx;
                  char unk_20C8[0x10];
                  MessageContext msgCtx;
                  InterfaceContext interfaceCtx;
                  PauseContext pauseCtx;
                  u16 unk_10A20;
                  EnvironmentContext envCtx;
                  AnimationContext animationCtx;
                  ObjectContext objectCtx;
                  RoomContext roomCtx;
                  s16 unk_11D30[2];
                  u8 nbTransitionActors;
                  TransitionActorEntry* transitionActorList;
                  void (*playerInit)(Player* player, struct GlobalContext* globalCtx, FlexSkeletonHeader* skelHeader);
                  void (*playerUpdate)(Player* player, struct GlobalContext* globalCtx, Input* input);
                  s32 (*isPlayerDroppingFish)(struct GlobalContext* globalCtx);
                  s32 (*startPlayerFishing)(struct GlobalContext* globalCtx);
                  s32 (*grabPlayer)(struct GlobalContext* globalCtx, Player* player);
                  s32 (*startPlayerCutscene)(struct GlobalContext* globalCtx, Actor* actor, s32 mode);
                  void (*func_11D54)(Player* player, struct GlobalContext* globalCtx);
                  s32 (*damagePlayer)(struct GlobalContext* globalCtx, s32 damage);
                  void (*talkWithPlayer)(struct GlobalContext* globalCtx, Actor* actor);
                  MtxF mf_11D60;
                  MtxF mf_11DA0;
                  Mtx* unk_11DE0;
                  u32 gameplayFrames;
                  u8 linkAgeOnLoad;
                  u8 unk_11DE9;
                  u8 curSpawn;
                  u8 nbSetupActors;
                  u8 nbRooms;
                  RomFile* roomList;
                  ActorEntry* linkActorEntry;
                  ActorEntry* setupActorList;
                  void* unk_11DFC;
                  EntranceEntry* setupEntranceList;
                  s16* setupExitList;
                  Path* setupPathList;
                  ElfMessage* cUpElfMsgs;
                  char unk_11E10[0x4];
                  u8 skyboxId;
                  s8 sceneLoadFlag;
                  s16 unk_11E16;
                  s16 unk_11E18;
                  s16 nextEntranceIndex;
                  char unk_11E1C[0x40];
                  s8 shootingGalleryStatus;
                  s8 bombchuBowlingStatus;
                  u8 fadeTransition;
                  CollisionCheckContext colChkCtx;
                  u16 envFlags[20];
                  PreRenderContext preRenderCtx;
                  char unk_12174[0x53];
                  s8 unk_121C7;
                  TransitionContext transitionCtx;
                  char unk_12418[0x3];
                  u8 transitionMode;
                  TransitionFade transitionFade;
                  char unk_12428[0x3];
                  u8 unk_1242B;
                  Scene* loadedScene;
                  char unk_12430[0xE8];
} GlobalContext;
typedef struct {
                 GameState state;
                 View view;
} OpeningContext;
typedef struct {
                  GameState state;
                  Vtx* allocVtx1;
                  void* staticSegment;
                  void* parameterSegment;
                  char unk_B0[0x8];
                  View view;
                  SramContext sramCtx;
                  char unk_1E4[0x4];
                  SkyboxContext skyboxCtx;
                  char unk_338[0x10];
                  MessageContext msgCtx;
                  char kanfont[0xE188];
                  EnvironmentContext envCtx;
                  char unk_1C9E4[0x4];
                  Vtx* allocVtx2;
                  Vtx* allocVtx3;
                  Vtx* allocVtx4;
                  u8 n64ddFlag;
                  u16 deaths[3];
                  u8 fileNames[3][8];
                  u16 healthCapacities[3];
                  u32 questItems[3];
                  s16 n64ddFlags[3];
                  s8 heartStatus[3];
                  u16 nowLife[3];
                  s16 btnIdx;
                  u16 yesNoButtonIdx;
                  s16 menuIdx;
                  s16 fileSelectStateIdx;
                  s16 unkActionIndex;
                  u16 nextFileSelectStateIdx;
                  s16 openFileStateIdx;
                  s16 selectedFileIdx;
                  char unk_1CA48[0x2];
                  u16 fileNamesY[3];
                  u16 actionTimer;
                  u16 buttonsY[6];
                  s16 copyDestFileIdx;
                  u16 fileWarningTexIdx;
                  u16 warningFileIdx;
                  u16 titleTexIdx;
                  u16 nextTitleTexIdx;
                  s16 windowR;
                  s16 windowG;
                  s16 windowB;
                  u16 selectFileTitleA;
                  u16 openFileTitleA;
                  u16 windowA;
                  u16 fileButtonsA[3];
                  u16 fileNameBoxesA[3];
                  u16 fileNamesA[3];
                  u16 metalJointsA[3];
                  u16 fileInfoA;
                  u16 targetFileInfoBoxA;
                  u16 unkFileInfoBoxA;
                  u16 copyButtonA;
                  u16 eraseButtonA;
                  u16 yesBiuttonA;
                  u16 quitButtonA;
                  u16 optionButtonA;
                  u16 newFileNameBoxA;
                  u16 decideCancelTextA;
                  u16 fileEmptyTextA;
                  u16 highlightColorR;
                  u16 highlightColorG;
                  u16 highlightColorB;
                  u16 highlightColorA;
                  u16 highlightColorAIncrease;
                  char unk_1CAAC[0x6];
                  u16 stickXTimer;
                  u16 stickYTimer;
                  u16 idxXOff;
                  u16 idxYOff;
                  s16 stickX;
                  s16 stickY;
                  u16 newFileNameBoxX;
                  u16 windowX;
                  f32 windowRotX;
                  u16 kbdButtonIdx;
                  u16 unk_1CACA;
                  u16 kbdCharBoxA;
                  s16 kbdCharIdx;
                  s16 kbdCharX;
                  s16 kbdCharY;
                  s16 newFileNameCharCount;
                  u16 unk_1CAD6[3];
} FileChooseContext;
typedef enum {
    DPM_UNK = 0,
    DPM_PLAYER = 1,
    DPM_ENEMY = 2,
    DPM_UNK3 = 3
} DynaPolyMoveFlag;
typedef struct {
               AnimationHeader* animation;
               f32 playbackSpeed;
               f32 startFrame;
               f32 frameCount;
               u8 mode;
               f32 transitionRate;
} struct_80034EC0_Entry;
typedef struct {
               AnimationHeader* animation;
               f32 frameCount;
               u8 mode;
               f32 transitionRate;
} struct_D_80AA1678;
typedef struct {
               s16 unk_00;
               s16 unk_02;
               s16 unk_04;
               s16 unk_06;
               Vec3s unk_08;
               Vec3s unk_0E;
               f32 unk_14;
               Vec3f unk_18;
               s16 unk_24;
} struct_80034A14_arg1;
typedef struct {
               s8 scene;
               s8 spawn;
               u16 field;
} EntranceInfo;
typedef struct {
               void* loadedRamAddr;
               u32 vromStart;
               u32 vromEnd;
               void* vramStart;
               void* vramEnd;
               void* unk_14;
               void* init;
               void* destroy;
               void* unk_20;
               void* unk_24;
               s32 unk_28;
               u32 instanceSize;
} GameStateOverlay;
typedef struct PreNMIContext {
               GameState state;
               u32 timer;
               s32 unk_A8;
} PreNMIContext;
typedef enum {
             F_8F = 1,
             F_7F,
             F_6F,
             F_5F,
             F_4F,
             F_3F,
             F_2F,
             F_1F,
             F_B1,
             F_B2,
             F_B3,
             F_B4,
             F_B5,
             F_B6,
             F_B7,
             F_B8
} FloorID;
typedef struct {
               s16 (*floorTexIndexOffset)[8];
               s16* bossFloor;
               s16 (*roomPalette)[32];
               s16* maxPaletteCount;
               s16 (*paletteRoom)[8][14];
               s16 (*roomCompassOffsetX)[44];
               s16 (*roomCompassOffsetY)[44];
               u8* dgnMinimapCount;
               u16* dgnMinimapTexIndexOffset;
               u16* owMinimapTexSize;
               u16* owMinimapTexOffset;
               s16* owMinimapPosX;
               s16* owMinimapPosY;
               s16 (*owCompassInfo)[4];
               s16* dgnMinimapTexIndexBase;
               s16 (*dgnCompassInfo)[4];
               s16* owMinimapWidth;
               s16* owMinimapHeight;
               s16* owEntranceIconPosX;
               s16* owEntranceIconPosY;
               u16* owEntranceFlag;
               f32 (*floorCoordY)[8];
               u16* switchEntryCount;
               u8 (*switchFromRoom)[51];
               u8 (*switchFromFloor)[51];
               u8 (*switchToRoom)[51];
               u8 (*floorID)[8];
               s16* skullFloorIconY;
} MapData;
typedef struct {
               s8 chestFlag;
               u8 x, y;
} MapMarkPoint;
typedef struct {
               s8 markType;
               u8 count;
               MapMarkPoint points[12];
} MapMarkData;
typedef MapMarkData MapMarksData[3];
typedef struct DebugDispObject {
               Vec3f pos;
               Vec3s rot;
               Vec3f scale;
               Color_RGBA8 color;
               s16 type;
               struct DebugDispObject* next;
} DebugDispObject;
typedef enum {
    MTXMODE_NEW,
    MTXMODE_APPLY
} MatrixMode;
typedef struct FaultClient {
               struct FaultClient* next;
               u32 callback;
               u32 param1;
               u32 param2;
} FaultClient;
typedef struct FaultAddrConvClient {
               struct FaultAddrConvClient* next;
               u32 callback;
               u32 param;
} FaultAddrConvClient;
typedef struct {
               u32 (*callback)(u32, u32);
               u32 param0;
               u32 param1;
               u32 ret;
               OSMesgQueue* queue;
               OSMesg msg;
} FaultClientContext;
typedef struct FaultThreadStruct {
                OSThread thread;
                u8 unk_1B0[0x600];
                OSMesgQueue queue;
                OSMesg msg;
                u8 exitDebugger;
                u8 msgId;
                u8 faultHandlerEnabled;
                u8 faultActive;
                OSThread* faultedThread;
                void(*padCallback)(Input*);
                FaultClient* clients;
                FaultAddrConvClient* addrConvClients;
                u8 unk_7E0[4];
                Input padInput;
                u16 colors[36];
                void* fb;
                u32 currClientThreadSp;
                u8 unk_84C[4];
} FaultThreadStruct;
typedef struct {
               u16* fb;
               u16 w;
               u16 h;
               u16 yStart;
               u16 yEnd;
               u16 xStart;
               u16 xEnd;
               u16 foreColor;
               u16 backColor;
               u16 cursorX;
               u16 cursorY;
               u32* fontData;
               u8 charW;
               u8 charH;
               s8 charWPad;
               s8 charHPad;
               u16 printColors[10];
               u8 escCode;
               u8 osSyncPrintfEnabled;
               void(*inputCallback)();
} FaultDrawer;
typedef struct GfxPrint {
               struct GfxPrint*(*callback)(struct GfxPrint*, const char*, size_t);
               Gfx* dlist;
               u16 posX;
               u16 posY;
               u16 baseX;
               u8 baseY;
               u8 flag;
               Color_RGBA8_u32 color;
               char unk_14[0x1C];
} GfxPrint;
typedef enum {
    GFXPRINT_FLAG1 = 1,
    GFXPRINT_USE_RGBA16 = 2,
    GFXPRINT_FLAG4 = 4,
    GFXPRINT_UPDATE_MODE = 8,
    GFXPRINT_FLAG64 = 0x40,
    GFXPRINT_OPEN = 0x80
} GfxPrintFlag;
typedef struct StackEntry {
               struct StackEntry* next;
               struct StackEntry* prev;
               u32 head;
               u32 tail;
               u32 initValue;
               s32 minSpace;
               const char* name;
} StackEntry;
typedef enum {
    STACK_STATUS_OK = 0,
    STACK_STATUS_WARNING = 1,
    STACK_STATUS_OVERFLOW = 2
} StackStatus;
typedef struct {
               u32 magic;
               u32 get;
               u8 unk_08[0x14-0x08];
               u32 put;
               u8 unk_18[0x20-0x18];
               u8 data[0x10000-0x20];
} ISVDbg;
typedef struct {
               char name[0x18];
               u32 mediaFormat;
               union {
        struct {
            u16 cartId;
            u8 countryCode;
            u8 version;
        };
        u32 regionInfo;
    };
} LocaleCartInfo;
typedef struct {
               char magic[4];
               u32 decSize;
               u32 compInfoOffset;
               u32 uncompDataOffset;
               u32 data[1];
} Yaz0Header;
typedef struct {
               s16 type;
               char misc[0x1E];
} OSScMsg;
typedef struct IrqMgrClient {
               struct IrqMgrClient* prev;
               OSMesgQueue* queue;
} IrqMgrClient;
typedef struct {
                OSScMsg retraceMsg;
                OSScMsg prenmiMsg;
                OSScMsg nmiMsg;
                OSMesgQueue queue;
                OSMesg msgBuf[8];
                OSThread thread;
                IrqMgrClient* clients;
                u8 resetStatus;
                OSTime resetTime;
                OSTimer timer;
                OSTime retraceTime;
} IrqMgr;
typedef struct {
                 OSContStatus padStatus[4];
                 OSMesg serialMsgBuf[1];
                 OSMesg lockMsgBuf[1];
                 OSMesg interruptMsgBuf[4];
                 OSMesgQueue serialMsgQ;
                 OSMesgQueue lockMsgQ;
                 OSMesgQueue interruptMsgQ;
                 IrqMgrClient irqClient;
                 IrqMgr* irqMgr;
                 OSThread thread;
                 Input inputs[4];
                 OSContPad pads[4];
                 vu8 validCtrlrsMask;
                 u8 ncontrollers;
                 u8 ctrlrIsConnected[4];
                 u8 pakType[4];
                 vu8 rumbleEnable[4];
                 u8 rumbleCounter[4];
                 OSPfs pfs[4];
                 vu8 rumbleOffFrames;
                 vu8 rumbleOnFrames;
                 u8 preNMIShutdown;
                 void (*retraceCallback)(void* padmgr, u32 unk464);
                 u32 retraceCallbackValue;
} PadMgr;
typedef struct {
                 u16* curBuffer;
                 u16* nextBuffer;
} FrameBufferSwap;
typedef struct {
                 OSMesgQueue interruptQ;
                 OSMesg intBuf[8];
                 OSMesgQueue cmdQ;
                 OSMesg cmdMsgBuf[8];
                 OSThread thread;
                 OSScTask* audioListHead;
                 OSScTask* gfxListHead;
                 OSScTask* audioListTail;
                 OSScTask* gfxListTail;
                 OSScTask* curRSPTask;
                 OSScTask* curRDPTask;
                 s32 retraceCnt;
                 s32 doAudio;
                 CfbInfo* curBuf;
                 CfbInfo* pendingSwapBuf1;
                 CfbInfo* pendingSwapBuf2;
                 s32 unk_24C;
                 IrqMgrClient irqClient;
} SchedContext;
typedef struct {
    struct {
                 s32 unk_0[0x10];
    } unk_0;
                 OSMesgQueue* unk_40;
} Sub_AudioMgr_18;
typedef struct {
                 IrqMgr* irqMgr;
                 SchedContext* sched;
                 OSMesg unk_8;
                 char unk_C[0x04];
                 s32 unk_10;
                 s32 unk_14;
                 Sub_AudioMgr_18 unk_18;
                 void* unk_5C;
                 char unk_60[0x10];
                 Sub_AudioMgr_18* unk_70;
                 OSMesgQueue unk_74;
                 OSMesg unk_8C;
                 OSMesgQueue unk_90;
                 OSMesg unk_A8;
                 OSMesgQueue unk_AC;
                 OSMesg unk_C4;
                 OSMesgQueue unk_C8;
                 OSMesg unk_E0;
                 char unk_E4[0x04];
                 OSThread unk_E8;
} AudioMgr;
struct ArenaNode;
typedef struct Arena {
               struct ArenaNode* head;
               void* start;
               OSMesgQueue lock;
               u8 unk_20;
               u8 isInit;
               u8 flag;
} Arena;
typedef struct ArenaNode {
               s16 magic;
               s16 isFree;
               u32 size;
               struct ArenaNode* next;
               struct ArenaNode* prev;
               const char* filename;
               s32 line;
               OSId threadId;
               Arena* arena;
               OSTime time;
               u8 unk_28[0x30-0x28];
} ArenaNode;
typedef struct OverlayRelocationSection {
               u32 textSize;
               u32 dataSize;
               u32 rodataSize;
               u32 bssSize;
               u32 nRelocations;
               u32 relocations[1];
} OverlayRelocationSection;
typedef struct {
               void* loadedRamAddr;
               u32 vromStart;
               u32 vromEnd;
               u8* vramStart;
               u8* vramEnd;
               u32 off;
               const char* name;
} KaleidoManagerOvl;
typedef struct {
               u32 resetting;
               u32 resetCount;
               OSTime duration;
               OSTime resetTime;
} PreNmiBuff;
typedef struct {
               s16 unk_00;
               s16 unk_02;
               s16 unk_04;
} SubQuakeRequest14;
typedef struct {
               s16 randIdx;
               s16 countdownMax;
               Camera* cam;
               u32 callbackIdx;
               s16 y;
               s16 x;
               s16 zoom;
               s16 rotZ;
               SubQuakeRequest14 unk_14;
               s16 speed;
               s16 unk_1C;
               s16 countdown;
               s16 camPtrIdx;
} QuakeRequest;
typedef struct {
               Vec3f vec1;
               Vec3f vec2;
               s16 rotZ;
               s16 unk_1A;
               s16 zoom;
} ShakeInfo;
typedef struct {
               Vec3f atOffset;
               Vec3f eyeOffset;
               s16 rotZ;
               s16 unk_1A;
               s16 zoom;
               f32 unk_20;
} QuakeCamCalc;
typedef struct {
               u32 type;
               void* ptr;
} UCodeInfo;
typedef struct {
               u32 segments[(16)];
               u32 dlStack[18];
               s32 dlDepth;
               u32 dlCnt;
               u32 vtxCnt;
               u32 spvtxCnt;
               u32 tri1Cnt;
               u32 tri2Cnt;
               u32 quadCnt;
               u32 lineCnt;
               u32 loaducodeCnt;
               u32 pipeSyncRequired;
               u32 tileSyncRequired;
               u32 loadSyncRequired;
               u32 syncErr;
               s32 enableLog;
               s32 ucodeType;
               s32 ucodeInfoCount;
               UCodeInfo* ucodeInfo;
               u32 modeH;
               u32 modeL;
               u32 geometryMode;
} UCodeDisas;
typedef struct {
               u16 table[8*8];
} JpegQuantizationTable;
typedef struct {
               u8 codeOffs[16];
               u16 codesA[16];
               u16 codesB[16];
               u8* symbols;
} JpegHuffmanTable;
typedef struct {
                u8 codeOffs[16];
                u16 dcCodes[120];
                u16 acCodes[256];
} JpegHuffmanTableOld;
typedef struct {
               u32 address;
               u32 mbCount;
               u32 mode;
               u32 qTableYPtr;
               u32 qTableUPtr;
               u32 qTableVPtr;
               char unk_18[0x8];
} JpegTaskData;
typedef struct {
                JpegTaskData taskData;
                char yieldData[0x200];
                JpegQuantizationTable qTableY;
                JpegQuantizationTable qTableU;
                JpegQuantizationTable qTableV;
                u8 codesLengths[0x110];
                u16 codes[0x108];
                u16 unk_6C0[4][0x180];
} JpegWork;
typedef struct {
               void* imageData;
               u8 mode;
               u8 unk_05;
               JpegHuffmanTable* hTablePtrs[4];
               u8 unk_18;
} JpegDecoder;
typedef struct {
               u8 dqtCount;
               u8* dqtPtr[3];
               u8 dhtCount;
               u8* dhtPtr[4];
               void* imageData;
               u32 mode;
               char unk_2C[4];
               OSScTask scTask;
               char unk_88[0x10];
               OSMesgQueue mq;
               OSMesg msg;
               JpegWork* workBuf;
} JpegContext;
typedef struct {
               u32 byteIdx;
               u8 bitIdx;
               u8 dontSkip;
               u32 curWord;
               s16 unk_0C;
               s16 unk_0E;
               s16 unk_10;
} JpegDecoderState;
typedef struct {
               u32 type;
               u32 setScissor;
               Color_RGBA8_u32 color;
               Color_RGBA8_u32 envColor;
} struct_801664F0;
typedef struct {
               u32 unk_00;
               u32 setScissor;
               Color_RGBA8_u32 primColor;
               Color_RGBA8_u32 envColor;
               u16* tlut;
               Gfx* monoDl;
} VisMono;
typedef struct {
               u32 useRgba;
               u32 setScissor;
               Color_RGBA8_u32 primColor;
               Color_RGBA8_u32 envColor;
} struct_80166500;
typedef struct {
                u8 rumbleEnable[4];
                u8 unk_04[0x40];
                u8 unk_44[0x40];
                u8 unk_84[0x40];
                u8 unk_C4[0x40];
                u8 unk_104;
                u8 unk_105;
                u16 unk_106;
                u16 unk_108;
                u8 unk_10A;
                u8 unk_10B;
                u8 unk_10C;
                u8 unk_10D;
} UnkRumbleStruct;
typedef struct {
               char unk_00[0x18];
               s32 unk_18;
               s32 y;
} SpeedMeter;
typedef struct {
               s32 maxval;
               s32 val;
               u16 backColor;
               u16 foreColor;
               s32 ulx;
               s32 lrx;
               s32 uly;
               s32 lry;
} SpeedMeterAllocEntry;
typedef struct {
               OSTime* time;
               u8 x;
               u8 y;
               u16 color;
} SpeedMeterTimeEntry;
typedef struct {
               u16 intPart[4][4];
               u16 fracPart[4][4];
} MatrixInternal;
typedef struct {
               u32 value;
               const char* name;
} F3dzexConst;
typedef struct {
               u32 value;
               const char* setName;
               const char* unsetName;
} F3dzexFlag;
typedef struct {
               const char* name;
               u32 value;
               u32 mask;
} F3dzexRenderMode;
typedef struct {
               const char* name;
               u32 value;
} F3dzexSetModeMacroValue;
typedef struct {
               const char* name;
               u32 shift;
               u32 len;
               F3dzexSetModeMacroValue values[4];
} F3dzexSetModeMacro;
typedef struct {
               u16* value;
               const char* name;
} FlagSetEntry;
typedef struct {
               OSViMode viMode;
               s32 height;
               s32 width;
               s32 unk_58;
               s32 unk_5C;
               s32 unk_60;
               s32 unk_64;
               s32 unk_68;
               s32 tvType;
               s32 unk_70;
               s32 unk_74;
               s32 unk_78;
               s32 unk_7C;
               u32 viFeatures;
               char unk_84[4];
} ViModeContext;
f32 fabsf(f32 f);
#pragma intrinsic(fabsf)
f32 sqrtf(f32 f);
#pragma intrinsic(sqrtf)
f64 sqrt(f64 d);
#pragma intrinsic(sqrt)
void cleararena(void);
void bootproc(void);
void Main_ThreadEntry(void* arg0);
void Idle_ThreadEntry(void* a0);
void ViConfig_UpdateVi(u32 arg0);
void ViConfig_UpdateBlack();
s32 DmaMgr_CompareName(const char* name1, const char* name2);
s32 DmaMgr_DMARomToRam(u32 rom, u32 ram, u32 size);
s32 DmaMgr_DmaCallback0(OSPiHandle* pihandle, OSIoMesg* mb, s32 direction);
void DmaMgr_DmaCallback1(u32 ram, u32 rom, u32 size);
void DmaMgr_Error(DmaRequest* req, const char* file, const char* errorName, const char* errorDesc);
const char* DmaMgr_GetFileNameImpl(u32 vrom);
const char* DmaMgr_GetFileName(u32 vrom);
void DmaMgr_ProcessMsg(DmaRequest* req);
void DmaMgr_ThreadEntry(void* arg0);
s32 DmaMgr_SendRequestImpl(DmaRequest* req, u32 ram, u32 vrom, u32 size, u32 unk, OSMesgQueue* queue, OSMesg msg);
s32 DmaMgr_SendRequest0(u32 ram, u32 vrom, u32 size);
void DmaMgr_Init();
s32 DmaMgr_SendRequest2(DmaRequest* req, u32 ram, u32 vrom, u32 size, u32 unk5, OSMesgQueue* queue, OSMesg msg,
                        const char* file, s32 line);
s32 DmaMgr_SendRequest1(void* ram0, u32 vrom, u32 size, const char* file, s32 line);
void* Yaz0_FirstDMA();
void* Yaz0_NextDMA(void* curSrcPos);
void Yaz0_DecompressImpl(Yaz0Header* hdr, u8* dst);
void Yaz0_Decompress(u32 romStart, void* dst, u32 size);
void Locale_Init();
void Locale_ResetRegion();
u32 func_80001F48();
u32 func_80001F8C();
u32 Locale_IsRegionNative();
void __assert(const char* exp, const char* file, s32 line);
void isPrintfInit();
void osSyncPrintfUnused(const char* fmt, ...);
void osSyncPrintf(const char* fmt, ...);
void rmonPrintf(const char* fmt, ...);
u32 is_proutSyncPrintf(void* arg0, const char* str, s32 count);
void func_80002384(const char* exp, const char* file, u32 line);
OSPiHandle* osDriveRomInit();
void Mio0_Decompress(Yaz0Header* hdr, u8* dst);
void StackCheck_Init(StackEntry* entry, void* stackTop, void* stackBottom, u32 initValue, s32 minSpace,
                     const char* name);
void StackCheck_Cleanup(StackEntry* entry);
StackStatus StackCheck_GetState(StackEntry* entry);
u32 StackCheck_CheckAll();
u32 StackCheck_Check(StackEntry* entry);
f32 LogUtils_CheckFloatRange(const char* exp, s32 arg1, const char* var1Name, f32 var1, const char* var2Name, f32 var2,
                             const char* var3Name, f32 var3);
s32 LogUtils_CheckIntRange(const char* exp, s32 arg1, const char* var1Name, s32 var1, const char* var2Name, s32 var2,
                           const char* var3Name, s32 var3);
void LogUtils_LogHexDump(void* ptr, s32 size0);
void LogUtils_LogPointer(s32 value, u32 max, void* ptr, const char* name, const char* file, s32 line);
void LogUtils_CheckBoundary(const char* name, s32 value, s32 unk, const char* file, s32 line);
void LogUtils_CheckNullPointer(const char* exp, void* ptr, const char* file, s32 line);
void LogUtils_CheckValidPointer(const char* exp, void* ptr0, const char* file, s32 line);
void LogUtils_LogThreadId(const char* name, s32 line);
void LogUtils_HungupThread(const char* name, s32 line);
void LogUtils_ResetHungup();
char* proutSprintf(char* dst, const char* fmt, size_t size);
s32 vsprintf(char* dst, const char* fmt, va_list args);
s32 sprintf(char* dst, const char* fmt, ...);
void __osPiCreateAccessQueue(void);
void __osPiGetAccess(void);
void __osPiRelAccess(void);
s32 osSendMesg(OSMesgQueue* mq, OSMesg mesg, s32 flag);
void osStopThread(OSThread* thread);
void osViExtendVStart(u32 arg0);
s32 osRecvMesg(OSMesgQueue* mq, OSMesg* msg, s32 flag);
void __createSpeedParam(void);
void __osInitialize_common(void);
void __osInitialize_autodetect();
void __osExceptionPreamble();
void __osEnqueueAndYield(OSThread**);
void __osEnqueueThread(OSThread**, OSThread*);
OSThread* __osPopThread(OSThread**);
void __osDispatchThread();
void __osCleanupThread(void);
void __osDequeueThread(OSThread** queue, OSThread* thread);
void osDestroyThread(OSThread* thread);
void bzero(void* __s, u32 __n);
void osCreateThread(OSThread* thread, OSId id, void (*entry)(void*), void* arg, void* sp, OSPri pri);
void __osSetSR(u32);
u32 __osGetSR();
void osWritebackDCache(void* vaddr, s32 nbytes);
void* osViGetNextFramebuffer();
void osCreatePiManager(OSPri pri, OSMesgQueue* cmdQ, OSMesg* cmdBuf, s32 cmdMsgCnt);
void __osDevMgrMain(void* arg);
s32 __osPiRawStartDma(s32 dir, u32 cartAddr, void* dramAddr, size_t size);
u32 osVirtualToPhysical(void* vaddr);
void osViBlack(u8 active);
s32 __osSiRawReadIo(void* a0, u32* a1);
OSId osGetThreadId(OSThread* thread);
OSIntMask osSetIntMask(OSIntMask);
void osViSetMode(OSViMode* mode);
u32 __osProbeTLB(void*);
u32 osGetMemSize(void);
void osSetEventMesg(OSEvent e, OSMesgQueue* mq, OSMesg msg);
s32 _Printf(char* (*pfn)(char*, const char*, size_t), char* arg, const char* fmt, va_list ap);
void osUnmapTLBAll(void);
s32 osEPiStartDma(OSPiHandle* handle, OSIoMesg* mb, s32 direction);
const u8* strchr(const u8* str, s32 ch);
size_t strlen(const u8* str);
void* memcpy(void* dst, const void* src, size_t size);
void osInvalICache(void* vaddr, s32 nbytes);
void osCreateMesgQueue(OSMesgQueue* mq, OSMesg* msg, s32 count);
void osInvalDCache(void* vaddr, s32 nbytes);
s32 __osSiDeviceBusy();
s32 osJamMesg(OSMesgQueue* mq, OSMesg mesg, s32 flag);
void osSetThreadPri(OSThread* thread, OSPri pri);
OSPri osGetThreadPri(OSThread* thread);
s32 __osEPiRawReadIo(OSPiHandle* handle, u32 devAddr, u32* data);
void osViSwapBuffer(void* vaddr);
s32 __osEPiRawStartDma(OSPiHandle* handle, s32 direction, u32 cartAddr, void* dramAddr, size_t size);
u32 bcmp(void* __sl, void* __s2, u32 __n);
OSTime osGetTime(void);
void __osTimerServicesInit();
void __osTimerInterrupt();
void __osSetTimerIntr(OSTime tim);
OSTime __osInsertTimer(OSTimer* a0);
u32 osGetCount(void);
void __osSetGlobalIntMask(u32 mask);
void __osSetCompare(u32);
void* bcopy(void* __src, void* __dest, u32 __n);
void __osResetGlobalIntMask(u32 mask);
s32 __osDisableInt(void);
void __osRestoreInt(s32);
void __osViInit();
void __osViSwapContext();
OSMesgQueue* osPiGetCmdQueue();
s32 osEPiReadIo(OSPiHandle* handle, u32 devAddr, u32* data);
void osViSetSpecialFeatures(u32 func);
OSPiHandle* osCartRomInit();
void __osSetFpcCsr(u32);
u32 __osGetFpcCsr();
s32 osEPiWriteIo(OSPiHandle* handle, u32 devAddr, u32 data);
void osMapTLBRdb(void);
void osYieldThread();
u32 __osGetCause();
s32 __osEPiRawWriteIo(OSPiHandle* handle, u32 devAddr, u32 data);
void _Litob(_Pft* args, u8 type);
ldiv_t ldiv(s32 num, s32 denom);
lldiv_t lldiv(s64 num, s64 denom);
void _Ldtob(_Pft* args, u8 type);
s32 __osSiRawWriteIo(void* a0, u32 a1);
void osCreateViManager(OSPri pri);
void viMgrMain(void* vargs);
OSViContext* __osViGetCurrentContext();
void osStartThread(OSThread* thread);
void osViSetYScale(f32 scale);
void osViSetXScale(f32 value);
void __osSetHWIntrRoutine(s32 idx, OSMesgQueue* queue, OSMesg msg);
void __osGetHWIntrRoutine(s32 idx, OSMesgQueue** outQueue, OSMesg* outMsg);
void __osSetWatchLo(u32);
EnItem00* Item_DropCollectible(GlobalContext* globalCtx, Vec3f* spawnPos, s16 params);
EnItem00* Item_DropCollectible2(GlobalContext* globalCtx, Vec3f* spawnPos, s16 params);
void Item_DropCollectibleRandom(GlobalContext* globalCtx, Actor* fromActor, Vec3f* spawnPos, s16 params);
void EffectBlure_AddVertex(EffectBlure* this, Vec3f* p1, Vec3f* p2);
void EffectBlure_AddSpace(EffectBlure* this);
void EffectBlure_Init1(void* thisx, void* initParamsx);
void EffectBlure_Init2(void* thisx, void* initParamsx);
void EffectBlure_Destroy(void* thisx);
s32 EffectBlure_Update(void* thisx);
void EffectBlure_Draw(void* thisx, GraphicsContext* gfxCtx);
void EffectShieldParticle_Init(void* thisx, void* initParamsx);
void EffectShieldParticle_Destroy(void* thisx);
s32 EffectShieldParticle_Update(void* thisx);
void EffectShieldParticle_Draw(void* thisx, GraphicsContext* gfxCtx);
void EffectSpark_Init(void* thisx, void* initParamsx);
void EffectSpark_Destroy(void* thisx);
s32 EffectSpark_Update(void* thisx);
void EffectSpark_Draw(void* thisx, GraphicsContext* gfxCtx);
void func_80026230(GlobalContext* globalCtx, Color_RGBA8* color, s16 arg2, s16 arg3);
void func_80026400(GlobalContext* globalCtx, Color_RGBA8* color, s16 arg2, s16 arg3);
void func_80026608(GlobalContext* globalCtx);
void func_80026690(GlobalContext* globalCtx, Color_RGBA8* color, s16 arg2, s16 arg3);
void func_80026860(GlobalContext* globalCtx, Color_RGBA8* color, s16 arg2, s16 arg3);
void func_80026A6C(GlobalContext* globalCtx);
GlobalContext* Effect_GetGlobalCtx(void);
void* Effect_GetByIndex(s32 index);
void Effect_InitContext(GlobalContext* globalCtx);
void Effect_Add(GlobalContext* globalCtx, s32* pIndex, s32 type, u8 arg3, u8 arg4, void* initParams);
void Effect_DrawAll(GraphicsContext* gfxCtx);
void Effect_UpdateAll(GlobalContext* globalCtx);
void Effect_Delete(GlobalContext* globalCtx, s32 index);
void Effect_DeleteAll(GlobalContext* globalCtx);
void EffectSs_InitInfo(GlobalContext* globalCtx, s32 tableSize);
void EffectSs_ClearAll(GlobalContext* globalCtx);
void EffectSs_Delete(EffectSs* effectSs);
void EffectSs_Reset(EffectSs* effectSs);
void EffectSs_Insert(GlobalContext* globalCtx, EffectSs* effectSs);
void EffectSs_Spawn(GlobalContext* globalCtx, s32 type, s32 priority, void* initParams);
void EffectSs_UpdateAll(GlobalContext* globalCtx);
void EffectSs_DrawAll(GlobalContext* globalCtx);
s16 func_80027DD4(s16 arg0, s16 arg1, s32 arg2);
s16 func_80027E34(s16 arg0, s16 arg1, f32 arg2);
u8 func_80027E84(u8 arg0, u8 arg1, f32 arg2);
void EffectSs_DrawGEffect(GlobalContext* globalCtx, EffectSs* this, void* texture);
void EffectSsDust_Spawn(GlobalContext* globalCtx, u16 drawFlags, Vec3f* pos, Vec3f* velocity, Vec3f* accel,
                        Color_RGBA8* primColor, Color_RGBA8* envColor, s16 scale, s16 scaleStep, s16 life,
                        u8 updateMode);
void func_8002829C(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, Color_RGBA8* primColor,
                   Color_RGBA8* envColor, s16 scale, s16 scaleStep);
void func_80028304(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, Color_RGBA8* primColor,
                   Color_RGBA8* envColor, s16 scale, s16 scaleStep);
void func_8002836C(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, Color_RGBA8* primColor,
                   Color_RGBA8* envColor, s16 scale, s16 scaleStep, s16 life);
void func_800283D4(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, Color_RGBA8* primColor,
                   Color_RGBA8* envColor, s16 scale, s16 scaleStep, s16 life);
void func_8002843C(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, Color_RGBA8* primColor,
                   Color_RGBA8* envColor, s16 scale, s16 scaleStep, s16 life);
void func_800284A4(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, Color_RGBA8* primColor,
                   Color_RGBA8* envColor, s16 scale, s16 scaleStep);
void func_80028510(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, Color_RGBA8* primColor,
                   Color_RGBA8* envColor, s16 scale, s16 scaleStep);
void func_8002857C(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel);
void func_800285EC(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel);
void func_8002865C(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, s16 scale, s16 scaleStep);
void func_800286CC(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, s16 scale, s16 scaleStep);
void func_8002873C(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, s16 scale, s16 scaleStep,
                   s16 life);
void func_800287AC(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, s16 scale, s16 scaleStep,
                   s16 life);
void func_8002881C(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, Color_RGBA8* primColor,
                   Color_RGBA8* envColor);
void func_80028858(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, Color_RGBA8* primColor,
                   Color_RGBA8* envColor);
void func_80028990(GlobalContext* globalCtx, f32 randScale, Vec3f* srcPos);
void func_80028A54(GlobalContext* globalCtx, f32 randScale, Vec3f* srcPos);
void EffectSsKiraKira_SpawnSmallYellow(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel);
void EffectSsKiraKira_SpawnSmall(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel,
                                 Color_RGBA8* primColor, Color_RGBA8* envColor);
void EffectSsKiraKira_SpawnDispersed(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel,
                                     Color_RGBA8* primColor, Color_RGBA8* envColor, s16 scale, s32 life);
void EffectSsKiraKira_SpawnFocused(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel,
                                   Color_RGBA8* primColor, Color_RGBA8* envColor, s16 scale, s32 life);
void EffectSsBomb_Spawn(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel);
void EffectSsBomb2_SpawnFade(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel);
void EffectSsBomb2_SpawnLayered(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, s16 scale,
                                s16 scaleStep);
void EffectSsBlast_Spawn(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, Color_RGBA8* primColor,
                         Color_RGBA8* envColor, s16 scale, s16 scaleStep, s16 sclaeStepDecay, s16 life);
void EffectSsBlast_SpawnWhiteCustomScale(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, s16 scale,
                                         s16 scaleStep, s16 life);
void EffectSsBlast_SpawnShockwave(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel,
                                  Color_RGBA8* primColor, Color_RGBA8* envColor, s16 life);
void EffectSsBlast_SpawnWhiteShockwave(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel);
void EffectSsGSpk_SpawnAccel(GlobalContext* globalCtx, Actor* actor, Vec3f* pos, Vec3f* velocity, Vec3f* accel,
                             Color_RGBA8* primColor, Color_RGBA8* envColor, s16 scale, s16 scaleStep);
void EffectSsGSpk_SpawnNoAccel(GlobalContext* globalCtx, Actor* actor, Vec3f* pos, Vec3f* velocity, Vec3f* accel,
                               Color_RGBA8* primColor, Color_RGBA8* envColor, s16 scale, s16 scaleStep);
void EffectSsGSpk_SpawnFuse(GlobalContext* globalCtx, Actor* actor, Vec3f* pos, Vec3f* velocity, Vec3f* accel);
void EffectSsGSpk_SpawnRandColor(GlobalContext* globalCtx, Actor* actor, Vec3f* pos, Vec3f* velocity, Vec3f* accel,
                                 s16 scale, s16 scaleStep);
void EffectSsGSpk_SpawnSmall(GlobalContext* globalCtx, Actor* actor, Vec3f* pos, Vec3f* velocity, Vec3f* accel,
                             Color_RGBA8* primColor, Color_RGBA8* envColor);
void EffectSsDFire_Spawn(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, s16 scale, s16 scaleStep,
                         s16 alpha, s16 fadeDelay, s32 life);
void EffectSsDFire_SpawnFixedScale(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, s16 alpha,
                                   s16 fadeDelay);
void EffectSsBubble_Spawn(GlobalContext* globalCtx, Vec3f* pos, f32 yPosOffset, f32 yPosRandScale, f32 xzPosRandScale,
                          f32 scale);
void EffectSsGRipple_Spawn(GlobalContext* globalCtx, Vec3f* pos, s16 radius, s16 radiusMax, s16 life);
void EffectSsGSplash_Spawn(GlobalContext* globalCtx, Vec3f* pos, Color_RGBA8* primColor, Color_RGBA8* envColor,
                           s16 type, s16 scale);
void EffectSsGMagma_Spawn(GlobalContext* globalCtx, Vec3f* pos);
void EffectSsGFire_Spawn(GlobalContext* globalCtx, Vec3f* pos);
void EffectSsLightning_Spawn(GlobalContext* globalCtx, Vec3f* pos, Color_RGBA8* primColor, Color_RGBA8* envColor,
                             s16 scale, s16 yaw, s16 life, s16 numBolts);
void EffectSsDtBubble_SpawnColorProfile(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, s16 scale,
                                        s16 life, s16 colorProfile, s16 randXZ);
void EffectSsDtBubble_SpawnCustomColor(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel,
                                       Color_RGBA8* primColor, Color_RGBA8* envColor, s16 scale, s16 life, s16 randXZ);
void EffectSsHahen_Spawn(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, s16 unused, s16 scale,
                         s16 objId, s16 life, Gfx* dList);
void EffectSsHahen_SpawnBurst(GlobalContext* globalCtx, Vec3f* pos, f32 burstScale, s16 unused, s16 scale,
                              s16 randScaleRange, s16 count, s16 objId, s16 life, Gfx* dList);
void EffectSsStick_Spawn(GlobalContext* globalCtx, Vec3f* pos, s16 yaw);
void EffectSsSibuki_Spawn(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, s16 moveDelay,
                          s16 direction, s16 scale);
void EffectSsSibuki_SpawnBurst(GlobalContext* globalCtx, Vec3f* pos);
void EffectSsSibuki2_Spawn(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, s16 scale);
void EffectSsGMagma2_Spawn(GlobalContext* globalCtx, Vec3f* pos, Color_RGBA8* primColor, Color_RGBA8* envColor,
                           s16 updateRate, s16 drawMode, s16 scale);
void EffectSsStone1_Spawn(GlobalContext* globalCtx, Vec3f* pos, s32 arg2);
void EffectSsHitMark_Spawn(GlobalContext* globalCtx, s32 type, s16 scale, Vec3f* pos);
void EffectSsHitMark_SpawnFixedScale(GlobalContext* globalCtx, s32 type, Vec3f* pos);
void EffectSsHitMark_SpawnCustomScale(GlobalContext* globalCtx, s32 type, s16 scale, Vec3f* pos);
void EffectSsFhgFlash_SpawnLightBall(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, s16 scale,
                                     u8 param);
void EffectSsFhgFlash_SpawnShock(GlobalContext* globalCtx, Actor* actor, Vec3f* pos, s16 scale, u8 param);
void EffectSsKFire_Spawn(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, s16 scaleMax, u8 type);
void EffectSsSolderSrchBall_Spawn(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, s16 unused,
                                  s16* linkDetected);
void EffectSsKakera_Spawn(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* arg3, s16 gravity, s16 arg5,
                          s16 arg6, s16 arg7, s16 arg8, s16 scale, s16 arg10, s16 arg11, s32 life, s16 colorIdx,
                          s16 objId, Gfx* dList);
void EffectSsIcePiece_Spawn(GlobalContext* globalCtx, Vec3f* pos, f32 scale, Vec3f* velocity, Vec3f* accel, s32 life);
void EffectSsIcePiece_SpawnBurst(GlobalContext* globalCtx, Vec3f* refPos, f32 scale);
void EffectSsEnIce_SpawnFlyingVec3f(GlobalContext* globalCtx, Actor* actor, Vec3f* pos, s16 primR, s16 primG, s16 primB,
                                    s16 primA, s16 envR, s16 envG, s16 envB, f32 scale);
void EffectSsEnIce_SpawnFlyingVec3s(GlobalContext* globalCtx, Actor* actor, Vec3s* pos, s16 primR, s16 primG, s16 primB,
                                    s16 primA, s16 envR, s16 envG, s16 envB, f32 scale);
void EffectSsEnIce_Spawn(GlobalContext* arg0, Vec3f* pos, f32 scale, Vec3f* velocity, Vec3f* accel,
                         Color_RGBA8* primColor, Color_RGBA8* envColor, s32 life);
void EffectSsFireTail_Spawn(GlobalContext* globalCtx, Actor* actor, Vec3f* pos, f32 scale, Vec3f* arg4, s16 arg5,
                            Color_RGBA8* primColor, Color_RGBA8* envColor, s16 type, s16 bodyPart, s32 life);
void EffectSsFireTail_SpawnFlame(GlobalContext* globalCtx, Actor* actor, Vec3f* pos, f32 arg3, s16 bodyPart,
                                 f32 colorIntensity);
void EffectSsFireTail_SpawnFlameOnPlayer(GlobalContext* globalCtx, f32 scale, s16 bodyPart, f32 colorIntensity);
void EffectSsEnFire_SpawnVec3f(GlobalContext* globalCtx, Actor* actor, Vec3f* pos, s16 scale, s16 unk_12, s16 flags,
                               s16 bodyPart);
void EffectSsEnFire_SpawnVec3s(GlobalContext* globalCtx, Actor* actor, Vec3s* vec, s16 scale, s16 arg4, s16 flags,
                               s16 bodyPart);
void EffectSsExtra_Spawn(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, s16 scale, s16 scoreIdx);
void EffectSsFCircle_Spawn(GlobalContext* globalCtx, Actor* actor, Vec3f* pos, s16 radius, s16 height);
void EffectSsDeadDb_Spawn(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, s16 scale, s16 scaleStep,
                          s16 primR, s16 primG, s16 primB, s16 primA, s16 envR, s16 envG, s16 envB, s16 unused,
                          s32 arg14, s16 playSound);
void EffectSsDeadDd_Spawn(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, s16 scale, s16 scaleStep,
                          s16 primR, s16 primG, s16 primB, s16 alpha, s16 envR, s16 envG, s16 envB, s16 alphaStep,
                          s32 life);
void EffectSsDeadDd_SpawnRandYellow(GlobalContext* globalCtx, Vec3f* pos, s16 scale, s16 scaleStep, f32 randPosScale,
                                    s32 randIter, s32 life);
void EffectSsDeadDs_Spawn(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, s16 scale, s16 scaleStep,
                          s16 alpha, s32 life);
void EffectSsDeadDs_SpawnStationary(GlobalContext* globalCtx, Vec3f* pos, s16 scale, s16 scaleStep, s16 alpha,
                                    s32 life);
void EffectSsDeadSound_Spawn(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, u16 sfxId,
                             s16 lowerPriority, s16 repeatMode, s32 life);
void EffectSsDeadSound_SpawnStationary(GlobalContext* globalCtx, Vec3f* pos, u16 sfxId, s16 lowerPriority,
                                       s16 repeatMode, s32 life);
void EffectSsIceSmoke_Spawn(GlobalContext* globalCtx, Vec3f* pos, Vec3f* velocity, Vec3f* accel, s16 scale);
void FlagSet_Update(GlobalContext* globalCtx);
void Overlay_LoadGameState(GameStateOverlay* overlayEntry);
void Overlay_FreeGameState(GameStateOverlay* overlayEntry);
void ActorShape_Init(ActorShape* shape, f32 yOffset, ActorShadowFunc shadowDraw, f32 shadowScale);
void ActorShadow_DrawCircle(Actor* actor, Lights* lights, GlobalContext* globalCtx);
void ActorShadow_DrawWhiteCircle(Actor* actor, Lights* lights, GlobalContext* globalCtx);
void ActorShadow_DrawHorse(Actor* actor, Lights* lights, GlobalContext* globalCtx);
void ActorShadow_DrawFeet(Actor* actor, Lights* lights, GlobalContext* globalCtx);
void Actor_SetFeetPos(Actor* actor, s32 limbIndex, s32 leftFootIndex, Vec3f* leftFootPos, s32 rightFootIndex,
                      Vec3f* rightFootPos);
void func_8002C124(TargetContext* targetCtx, GlobalContext* globalCtx);
s32 Flags_GetSwitch(GlobalContext* globalCtx, s32 flag);
void Flags_SetSwitch(GlobalContext* globalCtx, s32 flag);
void Flags_UnsetSwitch(GlobalContext* globalCtx, s32 flag);
s32 Flags_GetUnknown(GlobalContext* globalCtx, s32 flag);
void Flags_SetUnknown(GlobalContext* globalCtx, s32 flag);
void Flags_UnsetUnknown(GlobalContext* globalCtx, s32 flag);
s32 Flags_GetTreasure(GlobalContext* globalCtx, s32 flag);
void Flags_SetTreasure(GlobalContext* globalCtx, s32 flag);
s32 Flags_GetClear(GlobalContext* globalCtx, s32 flag);
void Flags_SetClear(GlobalContext* globalCtx, s32 flag);
void Flags_UnsetClear(GlobalContext* globalCtx, s32 flag);
s32 Flags_GetTempClear(GlobalContext* globalCtx, s32 flag);
void Flags_SetTempClear(GlobalContext* globalCtx, s32 flag);
void Flags_UnsetTempClear(GlobalContext* globalCtx, s32 flag);
s32 Flags_GetCollectible(GlobalContext* globalCtx, s32 flag);
void Flags_SetCollectible(GlobalContext* globalCtx, s32 flag);
void TitleCard_InitBossName(GlobalContext* globalCtx, TitleCardContext* titleCtx, void* texture, s16 arg3, s16 arg4,
                            u8 arg5, u8 arg6);
void TitleCard_InitPlaceName(GlobalContext* globalCtx, TitleCardContext* titleCtx, void* texture, s32 arg3, s32 arg4,
                             s32 arg5, s32 arg6, s32 arg7);
s32 func_8002D53C(GlobalContext* globalCtx, TitleCardContext* titleCtx);
void Actor_Kill(Actor* actor);
void Actor_SetFocus(Actor* actor, f32 offset);
void Actor_SetScale(Actor* actor, f32 scale);
void Actor_SetObjectDependency(GlobalContext* globalCtx, Actor* actor);
void func_8002D7EC(Actor* actor);
void func_8002D868(Actor* actor);
void Actor_MoveForward(Actor* actor);
void func_8002D908(Actor* actor);
void func_8002D97C(Actor* actor);
void func_8002D9A4(Actor* actor, f32 arg1);
s16 Actor_WorldYawTowardActor(Actor* actorA, Actor* actorB);
s16 Actor_WorldYawTowardPoint(Actor* actor, Vec3f* refPoint);
f32 Actor_WorldDistXYZToActor(Actor* actorA, Actor* actorB);
f32 Actor_WorldDistXYZToPoint(Actor* actor, Vec3f* refPoint);
s16 Actor_WorldPitchTowardActor(Actor* actorA, Actor* actorB);
s16 Actor_WorldPitchTowardPoint(Actor* actor, Vec3f* refPoint);
f32 Actor_WorldDistXZToActor(Actor* actorA, Actor* actorB);
f32 Actor_WorldDistXZToPoint(Actor* actor, Vec3f* refPoint);
void func_8002DBD0(Actor* actor, Vec3f* result, Vec3f* arg2);
f32 Actor_HeightDiff(Actor* actorA, Actor* actorB);
f32 Player_GetHeight(Player* player);
f32 func_8002DCE4(Player* player);
s32 func_8002DD6C(Player* player);
s32 func_8002DD78(Player* player);
s32 func_8002DDE4(GlobalContext* globalCtx);
s32 func_8002DDF4(GlobalContext* globalCtx);
void func_8002DE04(GlobalContext* globalCtx, Actor* actorA, Actor* actorB);
void func_8002DE74(GlobalContext* globalCtx, Player* player);
void func_8002DECC(GlobalContext* globalCtx, Player* player, Actor* horse);
s32 func_8002DEEC(Player* player);
void func_8002DF18(GlobalContext* globalCtx, Player* player);
s32 func_8002DF38(GlobalContext* globalCtx, Actor* actor, u8 csMode);
s32 func_8002DF54(GlobalContext* globalCtx, Actor* actor, u8 arg2);
void func_8002DF90(DynaPolyActor* dynaActor);
void func_8002DFA4(DynaPolyActor* dynaActor, f32 arg1, s16 arg2);
s32 func_8002DFC8(Actor* actor, s16 arg1, GlobalContext* globalCtx);
s32 func_8002E084(Actor* actor, s16 arg1);
s32 func_8002E12C(Actor* actor, f32 arg1, s16 arg2);
s32 func_8002E1A8(Actor* actorA, Actor* actorB, f32 arg2, s16 arg3);
void Actor_UpdateBgCheckInfo(GlobalContext* globalCtx, Actor* actor, f32 arg2, f32 arg3, f32 arg4, s32 arg5);
Hilite* func_8002EABC(Vec3f* object, Vec3f* eye, Vec3f* lightDir, GraphicsContext* gfxCtx);
Hilite* func_8002EB44(Vec3f* object, Vec3f* eye, Vec3f* lightDir, GraphicsContext* gfxCtx);
void func_8002EBCC(Actor* actor, GlobalContext* globalCtx, s32 flag);
void func_8002ED80(Actor* actor, GlobalContext* globalCtx, s32 flag);
PosRot* Actor_GetFocus(PosRot* arg0, Actor* actor);
PosRot* Actor_GetWorld(PosRot* arg0, Actor* actor);
PosRot* Actor_GetWorldPosShapeRot(PosRot* arg0, Actor* actor);
s32 func_8002F0C8(Actor* actor, Player* player, s32 arg2);
u32 func_8002F194(Actor* actor, GlobalContext* globalCtx);
s32 func_8002F1C4(Actor* actor, GlobalContext* globalCtx, f32 arg2, f32 arg3, u32 arg4);
s32 func_8002F298(Actor* actor, GlobalContext* globalCtx, f32 arg2, u32 arg3);
s32 func_8002F2CC(Actor* actor, GlobalContext* globalCtx, f32 arg2);
s32 func_8002F2F4(Actor* actor, GlobalContext* globalCtx);
u32 func_8002F334(Actor* actor, GlobalContext* globalCtx);
s8 func_8002F368(GlobalContext* globalCtx);
void func_8002F374(GlobalContext* globalCtx, Actor* actor, s16* arg2, s16* arg3);
u32 Actor_HasParent(Actor* actor, GlobalContext* globalCtx);
s32 func_8002F434(Actor* actor, GlobalContext* globalCtx, s32 getItemId, f32 xzRange, f32 yRange);
void func_8002F554(Actor* actor, GlobalContext* globalCtx, s32 getItemId);
void func_8002F580(Actor* actor, GlobalContext* globalCtx);
u32 Actor_HasNoParent(Actor* actor, GlobalContext* globalCtx);
void func_8002F5C4(Actor* actorA, Actor* actorB, GlobalContext* globalCtx);
void func_8002F5F0(Actor* actor, GlobalContext* globalCtx);
u32 Actor_HasChild(GlobalContext* globalCtx, Actor* actor);
u32 func_8002F63C(GlobalContext* globalCtx, Actor* horse, s32 arg2);
u32 Actor_HasNoChild(GlobalContext* globalCtx, Actor* actor);
void func_8002F698(GlobalContext* globalCtx, Actor* actor, f32 arg2, s16 arg3, f32 arg4, u32 arg5, u32 arg6);
void func_8002F6D4(GlobalContext* globalCtx, Actor* actor, f32 arg2, s16 arg3, f32 arg4, u32 arg5);
void func_8002F71C(GlobalContext* globalCtx, Actor* actor, f32 arg2, s16 arg3, f32 arg4);
void func_8002F758(GlobalContext* globalCtx, Actor* actor, f32 arg2, s16 arg3, f32 arg4, u32 arg5);
void func_8002F7A0(GlobalContext* globalCtx, Actor* actor, f32 arg2, s16 arg3, f32 arg4);
void func_8002F7DC(Actor* actor, u16 sfxId);
void Audio_PlayActorSound2(Actor* actor, u16 sfxId);
void func_8002F850(GlobalContext* globalCtx, Actor* actor);
void func_8002F8F0(Actor* actor, u16 sfxId);
void func_8002F91C(Actor* actor, u16 sfxId);
void func_8002F948(Actor* actor, u16 sfxId);
void func_8002F974(Actor* actor, u16 sfxId);
void func_8002F994(Actor* actor, s32 arg1);
s32 func_8002F9EC(GlobalContext* globalCtx, Actor* actor, CollisionPoly* poly, s32 bgId, Vec3f* pos);
void func_800304B0(GlobalContext* globalCtx);
void func_800304DC(GlobalContext* globalCtx, ActorContext* actorCtx, ActorEntry* actorEntry);
void Actor_UpdateAll(GlobalContext* globalCtx, ActorContext* actorCtx);
s32 func_800314D4(GlobalContext* globalCtx, Actor* actorB, Vec3f* arg2, f32 arg3);
void func_80031B14(GlobalContext* globalCtx, ActorContext* actorCtx);
void func_80031C3C(ActorContext* actorCtx, GlobalContext* globalCtx);
Actor* Actor_Spawn(ActorContext* actorCtx, GlobalContext* globalCtx, s16 actorId, f32 posX, f32 posY, f32 posZ,
                   s16 rotX, s16 rotY, s16 rotZ, s16 params);
Actor* Actor_SpawnAsChild(ActorContext* actorCtx, Actor* parent, GlobalContext* globalCtx, s16 actorId, f32 posX,
                          f32 posY, f32 posZ, s16 rotX, s16 rotY, s16 rotZ, s16 params);
void Actor_SpawnTransitionActors(GlobalContext* globalCtx, ActorContext* actorCtx);
Actor* Actor_SpawnEntry(ActorContext* actorCtx, ActorEntry* actorEntry, GlobalContext* globalCtx);
Actor* Actor_Delete(ActorContext* actorCtx, Actor* actor, GlobalContext* globalCtx);
Actor* func_80032AF0(GlobalContext* globalCtx, ActorContext* actorCtx, Actor** actorPtr, Player* player);
Actor* Actor_Find(ActorContext* actorCtx, s32 actorId, s32 actorCategory);
void func_80032C7C(GlobalContext* globalCtx, Actor* actor);
s16 func_80032CB4(s16* arg0, s16 arg1, s16 arg2, s16 arg3);
void func_80032E24(struct_80032E24* arg0, s32 arg1, GlobalContext* globalCtx);
void func_80032F54(struct_80032E24* arg0, s32 arg1, s32 arg2, s32 arg3, u32 arg4, Gfx** dList, s16 arg6);
s32 func_8003305C(Actor* actor, struct_80032E24* arg1, GlobalContext* globalCtx, s16 params);
void func_80033260(GlobalContext* globalCtx, Actor* actor, Vec3f* arg2, f32 arg3, s32 arg4, f32 arg5, s16 arg6,
                   s16 arg7, u8 arg8);
void func_80033480(GlobalContext* globalCtx, Vec3f* arg1, f32 arg2, s32 arg3, s16 arg4, s16 arg5, u8 arg6);
Actor* Actor_GetCollidedExplosive(GlobalContext* globalCtx, Collider* collider);
Actor* func_80033684(GlobalContext* globalCtx, Actor* explosiveActor);
Actor* func_80033780(GlobalContext* globalCtx, Actor* refActor, f32 arg2);
void Actor_ChangeCategory(GlobalContext* globalCtx, ActorContext* actorCtx, Actor* actor, u8 actorCategory);
void Actor_SetTextWithPrefix(GlobalContext* globalCtx, Actor* actor, s16 textIdLower);
s16 func_800339B8(Actor* actor, GlobalContext* globalCtx, f32 arg2, s16 arg3);
s32 func_80033A84(GlobalContext* globalCtx, Actor* actor);
s32 func_80033AB8(GlobalContext* globalCtx, Actor* actor);
f32 func_80033AEC(Vec3f* arg0, Vec3f* arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);
void func_80033C30(Vec3f* arg0, Vec3f* arg1, u8 alpha, GlobalContext* globalCtx);
void func_80033DB8(GlobalContext* globalCtx, s16 arg1, s16 arg2);
void func_80033E1C(GlobalContext* globalCtx, s16 arg1, s16 arg2, s16 arg3);
void func_80033E88(Actor* actor, GlobalContext* globalCtx, s16 arg2, s16 arg3);
f32 Rand_ZeroFloat(f32 f);
f32 Rand_CenteredFloat(f32 f);
void Actor_DrawDoorLock(GlobalContext* globalCtx, s32 arg1, s32 arg2);
void func_8003424C(GlobalContext* globalCtx, Vec3f* arg1);
void func_8003426C(Actor* actor, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
Hilite* func_800342EC(Vec3f* object, GlobalContext* globalCtx);
Hilite* func_8003435C(Vec3f* object, GlobalContext* globalCtx);
s32 func_800343CC(GlobalContext* globalCtx, Actor* actor, s16* arg2, f32 arg3, u16 (*unkFunc1)(GlobalContext*, Actor*),
                  s16 (*unkFunc2)(GlobalContext*, Actor*));
s16 func_800347E8(s16 arg0);
void func_80034A14(Actor* actor, struct_80034A14_arg1* arg1, s16 arg2, s16 arg3);
void func_80034BA0(GlobalContext* globalCtx, SkelAnime* skelAnime, OverrideLimbDraw overrideLimbDraw,
                   PostLimbDraw postLimbDraw, Actor* actor, s16 alpha);
void func_80034CC4(GlobalContext* globalCtx, SkelAnime* skelAnime, OverrideLimbDraw overrideLimbDraw,
                   PostLimbDraw postLimbDraw, Actor* actor, s16 alpha);
s16 func_80034DD4(Actor* actor, GlobalContext* globalCtx, s16 arg2, f32 arg3);
void func_80034EC0(SkelAnime* skelAnime, struct_80034EC0_Entry* animations, s32 index);
void func_80034F54(GlobalContext* globalCtx, s16* arg1, s16* arg2, s32 arg3);
void Actor_Noop(Actor* actor, GlobalContext* globalCtx);
void Gfx_DrawDListOpa(GlobalContext* globalCtx, Gfx* dlist);
void Gfx_DrawDListXlu(GlobalContext* globalCtx, Gfx* dlist);
Actor* Actor_FindNearby(GlobalContext* globalCtx, Actor* refActor, s16 actorId, u8 actorCategory, f32 range);
s32 func_800354B4(GlobalContext* globalCtx, Actor* actor, f32 range, s16 arg3, s16 arg4, s16 arg5);
void func_8003555C(GlobalContext* globalCtx, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3);
void func_800355B8(GlobalContext* globalCtx, Vec3f* arg1);
u8 func_800355E4(GlobalContext* globalCtx, Collider* collider);
u8 Actor_ApplyDamage(Actor* actor);
void func_80035650(Actor* actor, ColliderInfo* colBody, s32 freezeFlag);
void func_8003573C(Actor* actor, ColliderJntSph* colBody, s32 freezeFlag);
void func_80035844(Vec3f* arg0, Vec3f* arg1, s16* arg2, s32 arg3);
Actor* func_800358DC(Actor* actor, Vec3f* spawnPos, Vec3s* spawnRot, f32* arg3, s32 timer, s16* unused,
                      GlobalContext* globalCtx, s16 params, s32 arg8);
void func_800359B8(Actor* actor, s16 arg1, Vec3s* arg2);
s32 Flags_GetEventChkInf(s32 flag);
void Flags_SetEventChkInf(s32 flag);
s32 Flags_GetInfTable(s32 flag);
void Flags_SetInfTable(s32 flag);
u16 func_80037C30(GlobalContext* globalCtx, s16 arg1);
s32 func_80037D98(GlobalContext* globalCtx, Actor* actor, s16 arg2, s32* arg3);
s32 func_80038290(GlobalContext* globalCtx, Actor* actor, Vec3s* arg2, Vec3s* arg3, Vec3f arg4);
void ActorOverlayTable_LogPrint(void);
void ActorOverlayTable_Init(void);
void ActorOverlayTable_Cleanup(void);
u16 DynaSSNodeList_GetNextNodeIdx(DynaSSNodeList*);
void func_80038A28(CollisionPoly* poly, f32 tx, f32 ty, f32 tz, MtxF* dest);
f32 CollisionPoly_GetPointDistanceFromPlane(CollisionPoly* poly, Vec3f* point);
void CollisionPoly_GetVerticesByBgId(CollisionPoly* poly, s32 bgId, CollisionContext* colCtx, Vec3f* dest);
s32 BgCheck_CheckStaticCeiling(StaticLookup* lookup, u16 xpFlags, CollisionContext* colCtx, f32* outY, Vec3f* pos,
                               f32 checkHeight, CollisionPoly** outPoly);
s32 func_8003A5B8(SSList* headNodeId, CollisionContext* colCtx, u16 xpFlags1, u16 xpFlags2, Vec3f* posA, Vec3f* posB,
                  Vec3f* outPos, CollisionPoly** outPoly, f32* outDistSq, f32 chkDist, s32 bccFlags);
void BgCheck_GetStaticLookupIndicesFromPos(CollisionContext* colCtx, Vec3f* pos, Vec3i* arg2);
void BgCheck_Allocate(CollisionContext* colCtx, GlobalContext* globalCtx, CollisionHeader* colHeader);
s32 BgCheck_PosInStaticBoundingBox(CollisionContext* colCtx, Vec3f* pos);
f32 BgCheck_EntityRaycastFloor1(CollisionContext* colCtx, CollisionPoly** outPoly, Vec3f* pos);
f32 BgCheck_EntityRaycastFloor2(GlobalContext* globalCtx, CollisionContext* colCtx, CollisionPoly** outPoly,
                                Vec3f* pos);
f32 BgCheck_EntityRaycastFloor3(CollisionContext* colCtx, CollisionPoly** outPoly, s32* bgId, Vec3f* pos);
f32 BgCheck_EntityRaycastFloor4(CollisionContext* colCtx, CollisionPoly** outPoly, s32* bgId, Actor* actor,
                                Vec3f* arg4);
f32 BgCheck_EntityRaycastFloor5(GlobalContext* globalCtx, CollisionContext* colCtx, CollisionPoly** outPoly, s32* bgId,
                                Actor* actor, Vec3f* pos);
f32 BgCheck_EntityRaycastFloor6(CollisionContext* colCtx, CollisionPoly** outPoly, s32* bgId, Actor* actor, Vec3f* pos,
                                f32 chkDist);
f32 BgCheck_EntityRaycastFloor7(CollisionContext* colCtx, CollisionPoly** outPoly, s32* bgId, Actor* actor, Vec3f* pos);
f32 BgCheck_AnyRaycastFloor1(CollisionContext* colCtx, CollisionPoly* outPoly, Vec3f* pos);
f32 BgCheck_AnyRaycastFloor2(CollisionContext* colCtx, CollisionPoly* outPoly, s32* bgId, Vec3f* pos);
f32 BgCheck_CameraRaycastFloor2(CollisionContext* colCtx, CollisionPoly** outPoly, s32* bgId, Vec3f* pos);
f32 BgCheck_EntityRaycastFloor8(CollisionContext* colCtx, CollisionPoly** outPoly, s32* bgId, Actor* actor, Vec3f* pos);
f32 BgCheck_EntityRaycastFloor9(CollisionContext* colCtx, CollisionPoly** outPoly, s32* bgId, Vec3f* pos);
s32 BgCheck_SphVsWallImpl(CollisionContext* colCtx, u16 xpFlags, Vec3f* posResult, Vec3f* posNext, Vec3f* posPrev,
                          f32 radius, CollisionPoly** outPoly, s32* outBgId, Actor* actor, f32 checkHeight, u8 argA);
s32 BgCheck_EntitySphVsWall1(CollisionContext* colCtx, Vec3f* posResult, Vec3f* posNext, Vec3f* posPrev, f32 radius,
                             CollisionPoly** outPoly, f32 checkHeight);
s32 BgCheck_EntitySphVsWall2(CollisionContext* colCtx, Vec3f* posResult, Vec3f* posNext, Vec3f* posPrev, f32 radius,
                             CollisionPoly** outPoly, s32* outBgId, f32 checkHeight);
s32 BgCheck_EntitySphVsWall3(CollisionContext* colCtx, Vec3f* posResult, Vec3f* posNext, Vec3f* posPrev, f32 radius,
                             CollisionPoly** outPoly, s32* outBgId, Actor* actor, f32 checkHeight);
s32 BgCheck_EntitySphVsWall4(CollisionContext* colCtx, Vec3f* posResult, Vec3f* posNext, Vec3f* posPrev, f32 radius,
                             CollisionPoly** outPoly, s32* outBgId, Actor* actor, f32 checkHeight);
s32 BgCheck_AnyCheckCeiling(CollisionContext* colCtx, f32* outY, Vec3f* pos, f32 checkHeight);
s32 BgCheck_EntityCheckCeiling(CollisionContext* colCtx, f32* arg1, Vec3f* arg2, f32 arg3, CollisionPoly** outPoly,
                               s32* outBgId, Actor* actor);
s32 BgCheck_LineTestImpl(CollisionContext* colCtx, u16 xpFlags1, u16 xpFlags2, Vec3f* posA, Vec3f* posB,
                         Vec3f* posResult, CollisionPoly** outPoly, s32* bgId, Actor* actor, f32 chkDist, u32 bccFlags);
s32 BgCheck_CameraLineTest1(CollisionContext* colCtx, Vec3f* posA, Vec3f* posB, Vec3f* posResult,
                            CollisionPoly** outPoly, s32 chkWall, s32 chkFloor, s32 chkCeil, s32 chkOneFace, s32* bgId);
s32 BgCheck_CameraLineTest2(CollisionContext* colCtx, Vec3f* posA, Vec3f* posB, Vec3f* posResult,
                            CollisionPoly** outPoly, s32 chkWall, s32 chkFloor, s32 chkCeil, s32 chkOneFace, s32* bgId);
s32 BgCheck_EntityLineTest1(CollisionContext* colCtx, Vec3f* posA, Vec3f* posB, Vec3f* posResult,
                            CollisionPoly** outPoly, s32 chkWall, s32 chkFloor, s32 chkCeil, s32 chkOneFace, s32* bgId);
s32 BgCheck_EntityLineTest2(CollisionContext* colCtx, Vec3f* posA, Vec3f* posB, Vec3f* posResult,
                            CollisionPoly** outPoly, s32 chkWall, s32 chkFloor, s32 chkCeil, s32 chkOneFace, s32* bgId,
                            Actor* actor);
s32 BgCheck_EntityLineTest3(CollisionContext* colCtx, Vec3f* posA, Vec3f* posB, Vec3f* posResult,
                            CollisionPoly** outPoly, s32 chkWall, s32 chkFloor, s32 chkCeil, s32 chkOneFace, s32* bgId,
                            Actor* actor, f32 chkDist);
s32 BgCheck_ProjectileLineTest(CollisionContext* colCtx, Vec3f* posA, Vec3f* posB, Vec3f* posResult,
                               CollisionPoly** outPoly, s32 chkWall, s32 chkFloor, s32 chkCeil, s32 chkOneFace,
                               s32* bgId);
s32 BgCheck_AnyLineTest1(CollisionContext* colCtx, Vec3f* posA, Vec3f* posB, Vec3f* posResult, CollisionPoly** outPoly,
                         s32 chkOneFace);
s32 BgCheck_AnyLineTest2(CollisionContext* colCtx, Vec3f* posA, Vec3f* posB, Vec3f* posResult, CollisionPoly** outPoly,
                         s32 chkWall, s32 chkFloor, s32 chkCeil, s32 chkOneFace);
s32 BgCheck_AnyLineTest3(CollisionContext* colCtx, Vec3f* posA, Vec3f* posB, Vec3f* posResult, CollisionPoly** outPoly,
                         s32 chkWall, s32 chkFloor, s32 chkCeil, s32 chkOneFace, s32* bgId);
s32 BgCheck_SphVsFirstPoly(CollisionContext* colCtx, Vec3f* center, f32 radius);
void SSNodeList_Initialize(SSNodeList*);
void SSNodeList_Alloc(GlobalContext* globalCtx, SSNodeList* this, s32 tblMax, s32 numPolys);
u16 SSNodeList_GetNextNodeIdx(SSNodeList* this);
s32 DynaPoly_IsBgIdBgActor(s32 bgId);
void DynaPoly_Init(GlobalContext* globalCtx, DynaCollisionContext* dyna);
void DynaPoly_Alloc(GlobalContext* globalCtx, DynaCollisionContext* dyna);
void func_8003EBF8(GlobalContext* globalCtx, DynaCollisionContext* dyna, s32 bgId);
void func_8003EC50(GlobalContext* globalCtx, DynaCollisionContext* dyna, s32 bgId);
void func_8003ECA8(GlobalContext* globalCtx, DynaCollisionContext* dyna, s32 bgId);
s32 DynaPoly_SetBgActor(GlobalContext* globalCtx, DynaCollisionContext* dyna, Actor* actor, CollisionHeader* colHeader);
Actor* DynaPoly_GetActor(CollisionContext* colCtx, s32 bgId);
void DynaPoly_DeleteBgActor(GlobalContext* globalCtx, DynaCollisionContext* dyna, s32 bgId);
void func_8003F8EC(GlobalContext* globalCtx, DynaCollisionContext* dyna, Actor* actor);
void DynaPoly_Setup(GlobalContext* globalCtx, DynaCollisionContext* dyna);
void DynaPoly_UpdateBgActorTransforms(GlobalContext* globalCtx, DynaCollisionContext* dyna);
f32 BgCheck_RaycastFloorDyna(DynaRaycast* dynaRaycast);
s32 BgCheck_SphVsDynaWall(CollisionContext* colCtx, u16 xpFlags, f32* outX, f32* outZ, Vec3f* pos, f32 radius,
                          CollisionPoly** outPoly, s32* outBgId, Actor* actor);
s32 BgCheck_CheckDynaCeiling(CollisionContext* colCtx, u16 xpFlags, f32* outY, Vec3f* pos, f32 chkDist,
                             CollisionPoly** outPoly, s32* outBgId, Actor* actor);
s32 func_80041240(CollisionContext* colCtx, u16 xpFlags, Vec3f* posA, Vec3f* posB, Vec3f* posResult,
                  CollisionPoly** outPoly, f32* distSq, s32* outBgId, Actor* actor, f32 chkDist, s32 bccFlags);
s32 BgCheck_SphVsFirstDynaPoly(CollisionContext* colCtx, u16 xpFlags, CollisionPoly** outPoly, s32* outBgId,
                               Vec3f* center, f32 radius, Actor* actor, u16 bciFlags);
void CollisionHeader_GetVirtual(void* colHeader, CollisionHeader** dest);
void BgCheck_ResetPolyCheckTbl(SSNodeList* nodeList, s32 numPolys);
u32 SurfaceType_GetCamDataIndex(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
u16 func_80041A4C(CollisionContext* colCtx, u32 camId, s32 bgId);
u16 SurfaceType_GetCameraSType(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
u16 SurfaceType_GetNumCameras(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
Vec3s* func_80041C10(CollisionContext* colCtx, s32 camId, s32 bgId);
Vec3s* SurfaceType_GetCamPosData(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
u32 SurfaceType_GetSceneExitIndex(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
u32 func_80041D4C(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
u32 func_80041D70(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
s32 func_80041DB8(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
s32 func_80041DE4(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
s32 func_80041E18(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
s32 func_80041E4C(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
u32 func_80041EA4(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
u32 func_80041EC8(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
u32 SurfaceType_IsHorseBlocked(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
u32 func_80041F10(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
u16 SurfaceType_GetSfx(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
u32 SurfaceType_GetSlope(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
u32 SurfaceType_GetLightSettingIndex(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
u32 SurfaceType_GetEcho(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
u32 SurfaceType_IsHookshotSurface(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
s32 SurfaceType_IsIgnoredByEntities(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
s32 SurfaceType_IsIgnoredByProjectiles(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
s32 SurfaceType_IsConveyor(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
u32 SurfaceType_GetConveyorSpeed(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
u32 SurfaceType_GetConveyorDirection(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
u32 SurfaceType_IsWallDamage(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
s32 WaterBox_GetSurface1(GlobalContext* globalCtx, CollisionContext* colCtx, f32 x, f32 z, f32* ySurface,
                         WaterBox** outWaterBox);
s32 WaterBox_GetSurface2(GlobalContext* globalCtx, CollisionContext* colCtx, Vec3f* pos, f32 surfaceChkDist,
                         WaterBox** outWaterBox);
s32 WaterBox_GetSurfaceImpl(GlobalContext* globalCtx, CollisionContext* colCtx, f32 x, f32 z, f32* ySurface,
                            WaterBox** outWaterBox);
u32 WaterBox_GetCamDataIndex(CollisionContext* colCtx, WaterBox* waterBox);
u16 WaterBox_GetCameraSType(CollisionContext* colCtx, WaterBox* waterBox);
u32 WaterBox_GetLightSettingIndex(CollisionContext* colCtx, WaterBox* waterBox);
s32 func_80042708(CollisionPoly* polyA, CollisionPoly* polyB, Vec3f* point, Vec3f* closestPoint);
s32 func_800427B4(CollisionPoly* polyA, CollisionPoly* polyB, Vec3f* pointA, Vec3f* pointB, Vec3f* closestPoint);
void BgCheck_DrawDynaCollision(GlobalContext*, CollisionContext*);
void BgCheck_DrawStaticCollision(GlobalContext*, CollisionContext*);
void func_80043334(CollisionContext* colCtx, Actor* actor, s32 bgId);
s32 func_800433A4(CollisionContext* colCtx, s32 bgId, Actor* actor);
void DynaPolyActor_Init(DynaPolyActor* dynaActor, DynaPolyMoveFlag flags);
void func_800434A0(DynaPolyActor* dynaActor);
void func_800434A8(DynaPolyActor* dynaActor);
void func_800434C8(CollisionContext* colCtx, s32 floorBgId);
void func_80043508(CollisionContext* colCtx, s32 floorBgId);
void func_80043538(DynaPolyActor* dynaActor);
s32 func_80043548(DynaPolyActor* dynaActor);
s32 func_8004356C(DynaPolyActor* dynaActor);
s32 func_80043590(DynaPolyActor* dynaActor);
s32 func_800435B4(DynaPolyActor* dynaActor);
s32 func_800435D8(GlobalContext* globalCtx, DynaPolyActor* dyna, s16 arg2, s16 arg3, s16 arg4);
void Camera_Init(Camera* camera, View* view, CollisionContext* colCtx, GlobalContext* globalCtx);
void Camera_InitPlayerSettings(Camera* camera, Player* player);
s16 Camera_ChangeStatus(Camera* camera, s16 status);
Vec3s* Camera_Update(Vec3s* outDir, Camera* camera);
void Camera_Finish(Camera* camera);
s32 Camera_ChangeMode(Camera* camera, s16 mode);
s32 Camera_CheckValidMode(Camera* camera, s16 mode);
s32 Camera_ChangeSetting(Camera* camera, s16 setting);
s32 Camera_ChangeDataIdx(Camera* camera, s32 camDataIdx);
s16 Camera_GetInputDirYaw(Camera* camera);
Vec3s* Camera_GetCamDir(Vec3s* dir, Camera* camera);
s16 Camera_GetCamDirPitch(Camera* camera);
s16 Camera_GetCamDirYaw(Camera* camera);
s32 Camera_AddQuake(Camera* camera, s32 arg1, s16 y, s32 countdown);
s32 Camera_SetParam(Camera* camera, s32 param, void* value);
s32 func_8005AC48(Camera* camera, s16 arg1);
s16 func_8005ACFC(Camera* camera, s16 arg1);
s16 func_8005AD1C(Camera* camera, s16 arg1);
s32 Camera_ResetAnim(Camera* camera);
s32 Camera_SetCSParams(Camera* camera, CutsceneCameraPoint* atPoints, CutsceneCameraPoint* eyePoints, Player* player,
                       s16 relativeToPlayer);
s32 Camera_ChangeDoorCam(Camera* camera, Actor* doorActor, s16 camDataIdx, f32 arg3, s16 timer1, s16 timer2,
                         s16 timer3);
s32 Camera_Copy(Camera* dstCamera, Camera* srcCamera);
Vec3f* Camera_GetSkyboxOffset(Vec3f* dst, Camera* camera);
void Camera_SetCameraData(Camera* camera, s16 setDataFlags, void* data0, void* data1, s16 data2, s16 data3,
                          s32 arg6);
s32 func_8005B198(void);
s16 func_8005B1A4(Camera* camera);
DamageTable* DamageTable_Get(s32 index);
void DamageTable_Clear(DamageTable* table);
void Collider_DrawRedPoly(GraphicsContext* gfxCtx, Vec3f* vA, Vec3f* vB, Vec3f* vC);
void Collider_DrawPoly(GraphicsContext* gfxCtx, Vec3f* vA, Vec3f* vB, Vec3f* vC, u8 r, u8 g, u8 b);
s32 Collider_InitJntSph(GlobalContext* globalCtx, ColliderJntSph* collider);
s32 Collider_FreeJntSph(GlobalContext* globalCtx, ColliderJntSph* collider);
s32 Collider_DestroyJntSph(GlobalContext* globalCtx, ColliderJntSph* collider);
s32 Collider_SetJntSphToActor(GlobalContext* globalCtx, ColliderJntSph* dest, ColliderJntSphInitToActor* src);
s32 Collider_SetJntSphAllocType1(GlobalContext* globalCtx, ColliderJntSph* dest, Actor* actor,
                                 ColliderJntSphInitType1* src);
s32 Collider_SetJntSphAlloc(GlobalContext* globalCtx, ColliderJntSph* dest, Actor* actor, ColliderJntSphInit* src);
s32 Collider_SetJntSph(GlobalContext* globalCtx, ColliderJntSph* dest, Actor* actor, ColliderJntSphInit* src,
                       ColliderJntSphElement* elements);
s32 Collider_ResetJntSphAT(GlobalContext* globalCtx, Collider* collider);
s32 Collider_ResetJntSphAC(GlobalContext* globalCtx, Collider* collider);
s32 Collider_ResetJntSphOC(GlobalContext* globalCtx, Collider* collider);
s32 Collider_InitCylinder(GlobalContext* globalCtx, ColliderCylinder* collider);
s32 Collider_DestroyCylinder(GlobalContext* globalCtx, ColliderCylinder* collider);
s32 Collider_SetCylinderToActor(GlobalContext* globalCtx, ColliderCylinder* collider, ColliderCylinderInitToActor* src);
s32 Collider_SetCylinderType1(GlobalContext* globalCtx, ColliderCylinder* collider, Actor* actor,
                              ColliderCylinderInitType1* src);
s32 Collider_SetCylinder(GlobalContext* globalCtx, ColliderCylinder* collider, Actor* actor, ColliderCylinderInit* src);
s32 Collider_ResetCylinderAT(GlobalContext* globalCtx, Collider* collider);
s32 Collider_ResetCylinderAC(GlobalContext* globalCtx, Collider* collider);
s32 Collider_ResetCylinderOC(GlobalContext* globalCtx, Collider* collider);
s32 Collider_InitTris(GlobalContext* globalCtx, ColliderTris* tris);
s32 Collider_FreeTris(GlobalContext* globalCtx, ColliderTris* tris);
s32 Collider_DestroyTris(GlobalContext* globalCtx, ColliderTris* tris);
s32 Collider_SetTrisAllocType1(GlobalContext* globalCtx, ColliderTris* dest, Actor* actor, ColliderTrisInitType1* src);
s32 Collider_SetTrisAlloc(GlobalContext* globalCtx, ColliderTris* dest, Actor* actor, ColliderTrisInit* src);
s32 Collider_SetTris(GlobalContext* globalCtx, ColliderTris* dest, Actor* actor, ColliderTrisInit* src,
                     ColliderTrisElement* elements);
s32 Collider_ResetTrisAT(GlobalContext* globalCtx, Collider* collider);
s32 Collider_ResetTrisAC(GlobalContext* globalCtx, Collider* collider);
s32 Collider_ResetTrisOC(GlobalContext* globalCtx, Collider* collider);
s32 Collider_InitQuad(GlobalContext* globalCtx, ColliderQuad* collider);
s32 Collider_DestroyQuad(GlobalContext* globalCtx, ColliderQuad* collider);
s32 Collider_SetQuadType1(GlobalContext* globalCtx, ColliderQuad* collider, Actor* actor, ColliderQuadInitType1* src);
s32 Collider_SetQuad(GlobalContext* globalCtx, ColliderQuad* collider, Actor* actor, ColliderQuadInit* src);
s32 Collider_ResetQuadAT(GlobalContext* globalCtx, Collider* collider);
s32 Collider_ResetQuadAC(GlobalContext* globalCtx, Collider* collider);
s32 Collider_ResetQuadOC(GlobalContext* globalCtx, Collider* collider);
s32 Collider_InitLine(GlobalContext* globalCtx, OcLine* line);
s32 Collider_DestroyLine(GlobalContext* globalCtx, OcLine* line);
s32 Collider_SetLinePoints(GlobalContext* globalCtx, OcLine* ocLine, Vec3f* a, Vec3f* b);
s32 Collider_SetLine(GlobalContext* globalCtx, OcLine* dest, OcLine* src);
s32 Collider_ResetLineOC(GlobalContext* globalCtx, OcLine* line);
void CollisionCheck_InitContext(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx);
void CollisionCheck_DestroyContext(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx);
void CollisionCheck_ClearContext(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx);
void CollisionCheck_EnableSAC(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx);
void CollisionCheck_DisableSAC(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx);
void Collider_Draw(GlobalContext* globalCtx, Collider* collider);
void CollisionCheck_DrawCollision(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx);
s32 CollisionCheck_SetAT(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* collider);
s32 CollisionCheck_SetAT_SAC(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* collider, s32 index);
s32 CollisionCheck_SetAC(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* collider);
s32 CollisionCheck_SetAC_SAC(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* collider, s32 index);
s32 CollisionCheck_SetOC(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* collider);
s32 CollisionCheck_SetOC_SAC(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* collider, s32 index);
s32 CollisionCheck_SetOCLine(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, OcLine* collider);
void CollisionCheck_BlueBlood(GlobalContext* globalCtx, Collider* collider, Vec3f* v);
void CollisionCheck_AT(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx);
void CollisionCheck_OC(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx);
void CollisionCheck_InitInfo(CollisionCheckInfo* info);
void CollisionCheck_ResetDamage(CollisionCheckInfo* info);
void CollisionCheck_SetInfoNoDamageTable(CollisionCheckInfo* info, CollisionCheckInfoInit* init);
void CollisionCheck_SetInfo(CollisionCheckInfo* info, DamageTable* damageTable, CollisionCheckInfoInit* init);
void CollisionCheck_SetInfo2(CollisionCheckInfo* info, DamageTable* damageTable, CollisionCheckInfoInit2* init);
void CollisionCheck_SetInfoGetDamageTable(CollisionCheckInfo* info, s32 index, CollisionCheckInfoInit2* init);
void CollisionCheck_Damage(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx);
s32 CollisionCheck_LineOCCheckAll(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Vec3f* a, Vec3f* b);
s32 CollisionCheck_LineOCCheck(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Vec3f* a, Vec3f* b,
                               Actor** exclusions, s32 numExclusions);
void Collider_UpdateCylinder(Actor* actor, ColliderCylinder* collider);
void Collider_SetCylinderPosition(ColliderCylinder* collider, Vec3s* pos);
void Collider_SetQuadVertices(ColliderQuad* collider, Vec3f* a, Vec3f* b, Vec3f* c, Vec3f* d);
void Collider_SetTrisVertices(ColliderTris* collider, s32 index, Vec3f* a, Vec3f* b, Vec3f* c);
void Collider_SetTrisDim(GlobalContext* globalCtx, ColliderTris* collider, s32 index, ColliderTrisElementDimInit* init);
void Collider_UpdateSpheres(s32 limb, ColliderJntSph* collider);
void CollisionCheck_SpawnRedBlood(GlobalContext* globalCtx, Vec3f* v);
void CollisionCheck_SpawnWaterDroplets(GlobalContext* globalCtx, Vec3f* v);
void CollisionCheck_SpawnShieldParticles(GlobalContext* globalCtx, Vec3f* v);
void CollisionCheck_SpawnShieldParticlesMetal(GlobalContext* globalCtx, Vec3f* v);
void CollisionCheck_SpawnShieldParticlesMetalSound(GlobalContext* globalCtx, Vec3f* v, Vec3f* actorPos);
void CollisionCheck_SpawnShieldParticlesMetal2(GlobalContext* globalCtx, Vec3f* v);
void CollisionCheck_SpawnShieldParticlesWood(GlobalContext* globalCtx, Vec3f* b, Vec3f* actorPos);
s32 CollisionCheck_CylSideVsLineSeg(f32 radius, f32 height, f32 offset, Vec3f* actorPos, Vec3f* itemPos,
                                    Vec3f* itemProjPos, Vec3f* out1, Vec3f* out2);
u8 CollisionCheck_GetSwordDamage(s32 dmgFlags);
void SaveContext_Init(void);
void func_8006375C(s32 arg0, s32 arg1, const char* text);
void func_8006376C(u8 x, u8 y, u8 colorId, const char* text);
void func_8006390C(Input* input);
void func_80063D7C(GraphicsContext* gfxCtx);
void DebugDisplay_Init(void);
DebugDispObject* DebugDisplay_AddObject(f32 posX, f32 posY, f32 posZ, s16 rotX, s16 rotY, s16 rotZ, f32 scaleX,
                                        f32 scaleY, f32 scaleZ, u8 red, u8 green, u8 blue, u8 alpha, s16 type,
                                        GraphicsContext* gfxCtx);
void DebugDisplay_DrawObjects(GlobalContext* globalCtx);
void func_8006450C(GlobalContext* globalCtx, CutsceneContext* csCtx);
void func_80064534(GlobalContext* globalCtx, CutsceneContext* csCtx);
void func_80064558(GlobalContext* globalCtx, CutsceneContext* csCtx);
void func_800645A0(GlobalContext* globalCtx, CutsceneContext* csCtx);
void Cutscene_HandleEntranceTriggers(GlobalContext* globalCtx);
void Cutscene_HandleConditionalTriggers(GlobalContext* globalCtx);
void Cutscene_SetSegment(GlobalContext* globalCtx, u32 segment);
void* MemCopy(void* dest, void* src, s32 size);
void func_800694A0(GlobalContext* globalCtx, s16 drawId);
void func_8006BA00(GlobalContext* globalCtx);
void func_8006BA30(GlobalContext* globalCtx);
void Audio_PlaySoundAtPosition(GlobalContext* globalCtx, Vec3f* pos, s32 duration, u16 sfxId);
u16 ElfMessage_GetSariaText(GlobalContext* globalCtx);
u16 ElfMessage_GetCUpText(GlobalContext* globalCtx);
u16 Text_GetFaceReaction(GlobalContext* globalCtx, u32 reactionSet);
void Flags_UnsetAllEnv(GlobalContext* globalCtx);
void Flags_SetEnv(GlobalContext* globalCtx, s16 flag);
void Flags_UnsetEnv(GlobalContext* globalCtx, s16 flag);
s32 Flags_GetEnv(GlobalContext* globalCtx, s16 flag);
f32 func_8006C5A8(f32 target, TransformData* transData, s32 refIdx);
void SkelCurve_Clear(SkelAnimeCurve* skelCurve);
s32 SkelCurve_Init(GlobalContext* globalCtx, SkelAnimeCurve* skelCurve, SkelCurveLimbList* limbListSeg,
                   TransformUpdateIndex* transUpdIdx);
void SkelCurve_Destroy(GlobalContext* globalCtx, SkelAnimeCurve* skelCurve);
void SkelCurve_SetAnim(SkelAnimeCurve* skelCurve, TransformUpdateIndex* transUpdIdx, f32 arg2, f32 animFinalFrame,
                       f32 animCurFrame, f32 animSpeed);
s32 SkelCurve_Update(GlobalContext* globalCtx, SkelAnimeCurve* skelCurve);
void SkelCurve_Draw(Actor* actor, GlobalContext* globalCtx, SkelAnimeCurve* skelCurve,
                    OverrideCurveLimbDraw overrideLimbDraw, PostCurveLimbDraw postLimbDraw, s32 lod, void* data);
s32 func_8006CFC0(s32 scene);
void func_8006D074(GlobalContext* globalCtx);
void func_8006D0AC(GlobalContext* globalCtx);
void func_8006D0EC(GlobalContext* globalCtx, Player* player);
void func_8006D684(GlobalContext* globalCtx, Player* player);
void func_8006DC68(GlobalContext* globalCtx, Player* player);
void func_8006DD9C(Actor* actor, Vec3f* arg1, s16 arg2);
u32 Jpeg_SendTask(JpegContext* ctx);
void Jpeg_CopyToZbuffer(u16* src, u16* zbuffer, s32 x, s32 y);
u16 Jpeg_GetU16(u8* ptr);
void Jpeg_ParseMarkers(u8* ptr, JpegContext* ctx);
s32 Jpeg_Decode(void* data, u16* zbuffer, JpegWork* workBuff, u32 workSize);
void KaleidoSetup_Update(GlobalContext* globalCtx);
void KaleidoSetup_Init(GlobalContext* globalCtx);
void KaleidoSetup_Destroy(GlobalContext* globalCtx);
void func_8006EE50(Font* font, s16 arg1, s16 arg2);
void Font_LoadChar(u32 offset, u8 character, u16 codePointIndex);
void Font_LoadMessageBoxEndIcon(Font* font, u16 icon);
void Font_LoadOrderedFont(Font* font);
s32 func_8006F0A0(s32 arg0);
u8 func_8006F140(GlobalContext*, EnvironmentContext*, s32);
f32 func_8006F93C(u16, u16, u16);
f32 func_8006F9BC(u16 endFrame, u16 startFrame, u16 frames, u16, u16);
void func_80070600(GlobalContext* globalCtx, s32 waterboxProperties);
void func_800706A0(GlobalContext* globalCtx);
void func_80073988(GlobalContext*, EnvironmentContext*, View*, GraphicsContext*, Vec3f, s32);
f32 func_800746DC();
void func_80074CE8(GlobalContext* globalCtx, s32 arg1);
void func_800753C4(GlobalContext* globalCtx, u8 arg1);
void func_8007672C(GraphicsContext*, u8, u8, u8, u8, s32);
void func_800773A8(GlobalContext* globalCtx, f32 arg1, f32 arg2, f32 arg3, f32 arg4);
s32 func_800775CC();
void func_800775D8();
s32 func_800775E4();
void func_800775F0(u16);
void func_80077624(GlobalContext* globalCtx);
void func_80077684(GlobalContext* globalCtx);
void func_800776E4(GlobalContext* globalCtx);
void Lib_MemSet(u8* dest, size_t size, u8 val);
f32 Math_CosS(s16 angle);
f32 Math_SinS(s16 angle);
s32 Math_ScaledStepToS(s16* pValue, s16 target, s16 step);
s32 Math_StepToS(s16* pValue, s16 target, s16 step);
s32 Math_StepToF(f32* pValue, f32 target, f32 step);
s32 Math_StepUntilAngleS(s16* pValue, s16 limit, s16 step);
s32 Math_StepUntilS(s16* pValue, s16 limit, s16 step);
s32 Math_StepToAngleS(s16* pValue, s16 target, s16 step);
s32 Math_StepUntilF(f32* pValue, f32 limit, f32 step);
s32 Math_AsymStepToF(f32* pValue, f32 target, f32 incrStep, f32 decrStep);
void func_80077D10(f32* arg0, s16* arg1, Input* input);
s16 Rand_S16Offset(s16 base, s16 range);
void Math_Vec3f_Copy(Vec3f* dest, Vec3f* src);
void Math_Vec3s_ToVec3f(Vec3f* dest, Vec3s* src);
void Math_Vec3f_Sum(Vec3f* a, Vec3f* b, Vec3f* dest);
void Math_Vec3f_Diff(Vec3f* a, Vec3f* b, Vec3f* dest);
void Math_Vec3s_DiffToVec3f(Vec3f* dest, Vec3s* a, Vec3s* b);
void Math_Vec3f_Scale(Vec3f* vec, f32 scaleF);
f32 Math_Vec3f_DistXYZ(Vec3f* a, Vec3f* b);
f32 Math_Vec3f_DistXYZAndStoreDiff(Vec3f* a, Vec3f* b, Vec3f* dest);
f32 Math_Vec3f_DistXZ(Vec3f* a, Vec3f* b);
s16 Math_Vec3f_Yaw(Vec3f* a, Vec3f* b);
s16 Math_Vec3f_Pitch(Vec3f* a, Vec3f* b);
void Actor_ProcessInitChain(Actor* actor, InitChainEntry* initChain);
f32 Math_SmoothStepToF(f32* pValue, f32 target, f32 fraction, f32 step, f32 minStep);
void Math_ApproachF(f32* pValue, f32 target, f32 fraction, f32 step);
void Math_ApproachZeroF(f32* pValue, f32 fraction, f32 step);
f32 Math_SmoothStepToDegF(f32* pValue, f32 target, f32 fraction, f32 step, f32 minStep);
s16 Math_SmoothStepToS(s16* pValue, s16 target, s16 scale, s16 step, s16 minStep);
void Math_ApproachS(s16* pValue, s16 target, s16 scale, s16 step);
void Color_RGBA8_Copy(Color_RGBA8* dst, Color_RGBA8* src);
void func_80078884(u16 sfxId);
void func_800788CC(u16 sfxId);
void func_80078914(Vec3f* arg0, u16 sfxId);
void HealthMeter_Init(GlobalContext* globalCtx);
void HealthMeter_Update(GlobalContext* globalCtx);
void HealthMeter_Draw(GlobalContext* globalCtx);
void HealthMeter_HandleCriticalAlarm(GlobalContext* globalCtx);
u32 HealthMeter_IsCritical(void);
void Lights_PointSetInfo(LightInfo* info, s16 x, s16 y, s16 z, u8 r, u8 g, u8 b, s16 radius, s32 type);
void Lights_PointNoGlowSetInfo(LightInfo* info, s16 x, s16 y, s16 z, u8 r, u8 g, u8 b, s16 radius);
void Lights_PointGlowSetInfo(LightInfo* info, s16 x, s16 y, s16 z, u8 r, u8 g, u8 b, s16 radius);
void Lights_PointSetColorAndRadius(LightInfo* info, u8 r, u8 g, u8 b, s16 radius);
void Lights_DirectionalSetInfo(LightInfo* info, s8 x, s8 y, s8 z, u8 r, u8 g, u8 b);
void Lights_Reset(Lights* lights, u8 ambentR, u8 ambentG, u8 ambentB);
void Lights_Draw(Lights* lights, GraphicsContext* gfxCtx);
void Lights_BindAll(Lights* lights, LightNode* listHead, Vec3f* vec);
void LightContext_Init(GlobalContext* globalCtx, LightContext* lightCtx);
void LightContext_SetAmbientColor(LightContext* lightCtx, u8 r, u8 g, u8 b);
void func_8007A698(LightContext* lightCtx, u8 arg1, u8 arg2, u8 arg3, s16 numLights, s16 arg5);
Lights* LightContext_NewLights(LightContext* lightCtx, GraphicsContext* gfxCtx);
void LightContext_InitList(GlobalContext* globalCtx, LightContext* lightCtx);
void LightContext_DestroyList(GlobalContext* globalCtx, LightContext* lightCtx);
LightNode* LightContext_InsertLight(GlobalContext* globalCtx, LightContext* lightCtx, LightInfo* info);
void LightContext_RemoveLight(GlobalContext* globalCtx, LightContext* lightCtx, LightNode* node);
Lights* Lights_NewAndDraw(GraphicsContext* gfxCtx, u8 ambientR, u8 ambientG, u8 ambientB, u8 numLights, u8 r, u8 g,
                          u8 b, s8 x, s8 y, s8 z);
Lights* Lights_New(GraphicsContext* gfxCtx, u8 ambientR, u8 ambientG, u8 ambientB);
void Lights_GlowCheck(GlobalContext* globalCtx);
void Lights_DrawGlow(GlobalContext* globalCtx);
void ZeldaArena_CheckPointer(void* ptr, u32 size, const char* name, const char* action);
void* ZeldaArena_Malloc(u32 size);
void* ZeldaArena_MallocDebug(u32 size, const char* file, s32 line);
void* ZeldaArena_MallocR(u32 size);
void* ZeldaArena_MallocRDebug(u32 size, const char* file, s32 line);
void* ZeldaArena_Realloc(void* ptr, u32 newSize);
void* ZeldaArena_ReallocDebug(void* ptr, u32 newSize, const char* file, s32 line);
void ZeldaArena_Free(void* ptr);
void ZeldaArena_FreeDebug(void* ptr, const char* file, s32 line);
void* ZeldaArena_Calloc(u32 num, u32 size);
void ZeldaArena_Display();
void ZeldaArena_GetSizes(u32* outMaxFree, u32* outFree, u32* outAlloc);
void ZeldaArena_Check();
void ZeldaArena_Init(void* start, u32 size);
void ZeldaArena_Cleanup();
u8 ZeldaArena_IsInitalized();
void MapMark_Init(GlobalContext* globalCtx);
void MapMark_ClearPointers(GlobalContext* globalCtx);
void MapMark_DrawConditionally(GlobalContext* globalCtx);
void PreNmiBuff_Init(PreNmiBuff* this);
void PreNmiBuff_SetReset(PreNmiBuff* this);
u32 PreNmiBuff_IsResetting(PreNmiBuff* this);
void MsgEvent_SendNullTask();
f32 OLib_Vec3fDist(Vec3f* a, Vec3f* b);
f32 OLib_Vec3fDistXZ(Vec3f* a, Vec3f* b);
f32 OLib_ClampMinDist(f32 val, f32 min);
f32 OLib_ClampMaxDist(f32 val, f32 max);
Vec3f* OLib_Vec3fDistNormalize(Vec3f* dest, Vec3f* a, Vec3f* b);
Vec3f* OLib_VecSphGeoToVec3f(Vec3f* dest, VecSph* sph);
VecSph* OLib_Vec3fToVecSph(VecSph* dest, Vec3f* vec);
VecSph* OLib_Vec3fToVecSphGeo(VecSph* arg0, Vec3f* arg1);
VecSph* OLib_Vec3fDiffToVecSphGeo(VecSph* arg0, Vec3f* a, Vec3f* b);
Vec3f* OLib_Vec3fDiffRad(Vec3f* dest, Vec3f* a, Vec3f* b);
s16 func_800800F8(GlobalContext* globalCtx, s16 csID, s16 timer, Actor* actor, s16 camIdx);
void func_800803F0(GlobalContext* globalCtx, s16 camId);
s16 func_80080480(GlobalContext* globalCtx, Actor* actor);
void func_800806BC(GlobalContext* globalCtx, Actor* actor, u16 sfxId);
s32 func_80080728(GlobalContext* globalCtx, u8 actorCategory);
void func_80080788(s32, s32);
void Map_SavePlayerInitialInfo(GlobalContext* globalCtx);
void Map_SetFloorPalettesData(GlobalContext* globalCtx, s16 floor);
void Map_InitData(GlobalContext* globalCtx, s16 room);
void Map_InitRoomData(GlobalContext* globalCtx, s16 room);
void Map_Destroy(GlobalContext* globalCtx);
void Map_Init(GlobalContext* globalCtx);
void Minimap_Draw(GlobalContext* globalCtx);
void Map_Update(GlobalContext* globalCtx);
void Interface_ChangeAlpha(u16 alphaType);
void Interface_SetSceneRestrictions(GlobalContext* globalCtx);
void Inventory_SwapAgeEquipment(void);
void Interface_InitHorsebackArchery(GlobalContext* globalCtx);
void func_800849EC(GlobalContext* globalCtx);
void Interface_LoadItemIcon1(GlobalContext* globalCtx, u16 button);
void Interface_LoadItemIcon2(GlobalContext* globalCtx, u16 button);
void func_80084BF4(GlobalContext* globalCtx, u16 flag);
u8 Item_Give(GlobalContext* globalCtx, u8 item);
u8 Item_CheckObtainability(u8 item);
void Inventory_DeleteItem(u16 item, u16 invSlot);
s32 Inventory_ReplaceItem(GlobalContext* globalCtx, u16 oldItem, u16 newItem);
s32 Inventory_HasEmptyBottle(void);
s32 Inventory_HasSpecificBottle(u8 bottleItem);
void Inventory_UpdateBottleItem(GlobalContext* globalCtx, u8 item, u8 cButton);
s32 Inventory_ConsumeFairy(GlobalContext* globalCtx);
void Interface_SetDoAction(GlobalContext* globalCtx, u16 action);
void Interface_SetNaviCall(GlobalContext* globalCtx, u16 naviCallState);
void Interface_LoadActionLabelB(GlobalContext* globalCtx, u16 action);
s32 Health_ChangeBy(GlobalContext* globalCtx, s16 healthChange);
void Rupees_ChangeBy(s16 rupeeChange);
void Inventory_ChangeAmmo(s16 item, s16 ammoChange);
void Magic_Fill(GlobalContext* globalCtx);
void func_800876C8(GlobalContext* globalCtx);
s32 func_80087708(GlobalContext* globalCtx, s16 arg1, s16 arg2);
void func_80088AA0(s16 seconds);
void func_80088AF0(GlobalContext* globalCtx);
void func_80088B34(s16 arg0);
void Interface_Draw(GlobalContext* globalCtx);
void Interface_Update(GlobalContext* globalCtx);
Path* Path_GetByIndex(GlobalContext* globalCtx, s16 index, s16 max);
f32 Path_OrientAndGetDistSq(Actor* actor, Path* path, s16 waypoint, s16* yaw);
void Path_CopyLastPoint(Path* path, Vec3f* dest);
void Player_SetBootData(GlobalContext* globalCtx, Player* player);
s32 Player_InBlockingCsMode(GlobalContext* globalCtx, Player* player);
s32 Player_InCsMode(GlobalContext* globalCtx);
s32 func_8008E9C4(Player* player);
s32 Player_IsChildWithHylianShield(Player* player);
s32 Player_ActionToModelGroup(Player* player, s32 actionParam);
void Player_SetModelsForHoldingShield(Player* player);
void Player_SetModels(Player* player, s32 modelGroup);
void Player_SetModelGroup(Player* player, s32 modelGroup);
void func_8008EC70(Player* player);
void Player_SetEquipmentData(GlobalContext* globalCtx, Player* player);
void Player_UpdateBottleHeld(GlobalContext* globalCtx, Player* player, s32 item, s32 actionParam);
void func_8008EDF0(Player* player);
void func_8008EE08(Player* player);
void func_8008EEAC(GlobalContext* globalCtx, Actor* actor);
s32 func_8008EF44(GlobalContext* globalCtx, s32 ammo);
s32 Player_IsBurningStickInRange(GlobalContext* globalCtx, Vec3f* pos, f32 radius, f32 arg3);
s32 Player_GetStrength(void);
u8 Player_GetMask(GlobalContext* globalCtx);
Player* Player_UnsetMask(GlobalContext* globalCtx);
s32 Player_HasMirrorShieldEquipped(GlobalContext* globalCtx);
s32 Player_HasMirrorShieldSetToDraw(GlobalContext* globalCtx);
s32 Player_ActionToMagicSpell(Player* player, s32 actionParam);
s32 Player_HoldsHookshot(Player* player);
s32 func_8008F128(Player* player);
s32 Player_ActionToSword(s32 actionParam);
s32 Player_GetSwordHeld(Player* player);
s32 Player_HoldsTwoHandedWeapon(Player* player);
s32 Player_HoldsBrokenKnife(Player* player);
s32 Player_ActionToBottle(Player* player, s32 actionParam);
s32 Player_GetBottleHeld(Player* player);
s32 Player_ActionToExplosive(Player* player, s32 actionParam);
s32 Player_GetExplosiveHeld(Player* player);
s32 func_8008F2BC(Player* player, s32 actionParam);
s32 func_8008F2F8(GlobalContext* globalCtx);
void func_8008F470(GlobalContext* globalCtx, void** skeleton, Vec3s* jointTable, s32 dListCount, s32 lod, s32 tunic,
                   s32 boots, s32 face, OverrideLimbDrawOpa overrideLimbDraw, PostLimbDrawOpa postLimbDraw, void* this);
s32 func_8008FCC8(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* data);
s32 func_80090014(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* data);
s32 func_800902F0(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* data);
s32 func_80090440(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* data);
u8 func_80090480(GlobalContext* globalCtx, ColliderQuad* collider, WeaponInfo* weaponDim, Vec3f* newTip,
                 Vec3f* newBase);
void Player_DrawGetItem(GlobalContext* globalCtx, Player* player);
void func_80090D20(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* data);
u32 func_80091738(GlobalContext* globalCtx, u8* segment, SkelAnime* skelAnime);
void func_8009214C(GlobalContext* globalCtx, u8* segment, SkelAnime* arg2, Vec3f* pos, Vec3s* rot, f32 scale, s32 sword,
                   s32 tunic, s32 shield, s32 boots);
void PreNMI_Init(GameState* thisx);
Vec3f* Quake_AddVec(Vec3f* dst, Vec3f* arg1, VecSph* arg2);
void Quake_UpdateShakeInfo(QuakeRequest* req, ShakeInfo* shake, f32 y, f32 x);
s16 Quake_Callback1(QuakeRequest* req, ShakeInfo* shake);
s16 Quake_Callback2(QuakeRequest* req, ShakeInfo* shake);
s16 Quake_Callback3(QuakeRequest* req, ShakeInfo* shake);
s16 Quake_Callback4(QuakeRequest* req, ShakeInfo* shake);
s16 Quake_Callback5(QuakeRequest* req, ShakeInfo* shake);
s16 Quake_Callback6(QuakeRequest* req, ShakeInfo* shake);
s16 Quake_GetFreeIndex();
QuakeRequest* Quake_AddImpl(Camera* cam, u32 callbackIdx);
void Quake_Remove(QuakeRequest* req);
QuakeRequest* Quake_GetRequest(s16 idx);
QuakeRequest* Quake_SetValue(s16 idx, s16 valueType, s16 value);
u32 Quake_SetSpeed(s16 idx, s16 value);
u32 Quake_SetCountdown(s16 idx, s16 value);
s16 Quake_GetCountdown(s16 idx);
u32 Quake_SetQuakeValues(s16 idx, s16 y, s16 x, s16 zoom, s16 rotZ);
u32 Quake_SetUnkValues(s16 idx, s16 arg1, SubQuakeRequest14 arg2);
void Quake_Init();
s16 Quake_Add(Camera* cam, u32 callbackIdx);
u32 Quake_RemoveFromIdx(s16 idx);
s16 Quake_Calc(Camera* camera, QuakeCamCalc* camData);
Gfx* Gfx_SetFog(Gfx* gfx, s32 r, s32 g, s32 b, s32 a, s32 n, s32 f);
Gfx* Gfx_SetFogWithSync(Gfx* gfx, s32 r, s32 g, s32 b, s32 a, s32 n, s32 f);
Gfx* Gfx_SetFog2(Gfx* gfx, s32 r, s32 g, s32 b, s32 a, s32 n, s32 f);
Gfx* Gfx_CallSetupDL(Gfx* gfx, u32 i);
Gfx* func_800937C0(Gfx* gfx);
Gfx* func_80093808(Gfx* gfx);
void func_800938B4(GraphicsContext* gfxCtx);
void func_8009398C(GraphicsContext* gfxCtx);
void func_80093AD0(GraphicsContext* gfxCtx);
void func_80093BA8(GraphicsContext* gfxCtx);
void func_80093C14(GraphicsContext* gfxCtx);
void func_80093C80(GlobalContext* globalCtx);
void func_80093D18(GraphicsContext* gfxCtx);
void func_80093D84(GraphicsContext* gfxCtx);
Gfx* func_80093F34(Gfx* gfx);
Gfx* func_80093F58(Gfx* gfx);
void func_80094044(GraphicsContext* gfxCtx);
void func_800940B0(GraphicsContext* gfxCtx);
void func_80094140(GraphicsContext* gfxCtx);
Gfx* func_8009411C(Gfx* gfx);
void func_800942F0(GraphicsContext* gfxCtx);
void func_8009435C(GraphicsContext* gfxCtx);
void func_800943C8(GraphicsContext* gfxCtx);
Gfx* func_800944A0(Gfx* gfx);
void func_800944C4(GraphicsContext* gfxCtx);
void func_80094520(GraphicsContext* gfxCtx);
void func_8009457C(Gfx** gfxp);
void func_800945A0(GraphicsContext* gfxCtx);
void func_8009460C(GraphicsContext* gfxCtx);
void func_80094678(GraphicsContext* gfxCtx);
Gfx* func_800946E4(Gfx* gfx);
Gfx* func_800947AC(Gfx* gfx);
void func_80094A14(GraphicsContext* gfxCtx);
void func_80094B58(GraphicsContext* gfxCtx);
void func_80094BC4(GraphicsContext* gfxCtx);
void func_80094C50(GraphicsContext* gfxCtx);
void func_80094D28(Gfx** gfxp);
Gfx* Gfx_BranchTexScroll(Gfx** gfxp, u32 x, u32 y, s32 width, s32 height);
Gfx* func_80094E78(GraphicsContext* gfxCtx, u32 x, u32 y);
Gfx* Gfx_TexScroll(GraphicsContext* gfxCtx, u32 x, u32 y, s32 width, s32 height);
Gfx* Gfx_TwoTexScroll(GraphicsContext* gfxCtx, s32 tile1, u32 x1, u32 y1, s32 width1, s32 height1, s32 tile2, u32 x2,
                      u32 y2, s32 width2, s32 height2);
Gfx* Gfx_TwoTexScrollEnvColor(GraphicsContext* gfxCtx, s32 tile1, u32 x1, u32 y1, s32 width1, s32 height1, s32 tile2,
                              u32 x2, u32 y2, s32 width2, s32 height2, s32 r, s32 g, s32 b, s32 a);
Gfx* Gfx_EnvColor(GraphicsContext* gfxCtx, s32 r, s32 g, s32 b, s32 a);
void func_80095248(GraphicsContext* gfxCtx, u8 r, u8 g, u8 b);
void func_80095974(GraphicsContext* gfxCtx);
void func_80095AA0(GlobalContext* globalCtx, Room* room, Input* arg2, s32 arg3);
void func_80096FD4(GlobalContext* globalCtx, Room* room);
u32 func_80096FE8(GlobalContext* globalCtx, RoomContext* roomCtx);
s32 func_8009728C(GlobalContext* globalCtx, RoomContext* roomCtx, s32 roomNum);
s32 func_800973FC(GlobalContext* globalCtx, RoomContext* roomCtx);
void Room_Draw(GlobalContext* globalCtx, Room* room, u32 flags);
void func_80097534(GlobalContext* globalCtx, RoomContext* roomCtx);
void Sample_Destroy(GameState* thisx);
void Sample_Init(GameState* thisx);
void Inventory_ChangeEquipment(s16 equipment, u16 value);
u8 Inventory_DeleteEquipment(GlobalContext* globalCtx, s16 equipment);
void Inventory_ChangeUpgrade(s16 upgrade, s16 value);
void Object_InitBank(GlobalContext* globalCtx, ObjectContext* objectCtx);
void Object_UpdateBank(ObjectContext* objectCtx);
s32 Object_GetIndex(ObjectContext* objectCtx, s16 objectId);
s32 Object_IsLoaded(ObjectContext* objectCtx, s32 bankIndex);
void func_800981B8(ObjectContext* objectCtx);
s32 Scene_ExecuteCommands(GlobalContext* globalCtx, SceneCmd* sceneCmd);
void func_80098CBC(GlobalContext* globalCtx, u8* nbTransitionActors);
void func_800994A0(GlobalContext* globalCtx);
void Scene_Draw(GlobalContext* globalCtx);
void SkelAnime_DrawLod(GlobalContext* globalCtx, void** skeleton, Vec3s* jointTable,
                       OverrideLimbDrawOpa overrideLimbDraw, PostLimbDrawOpa postLimbDraw, void* arg, s32 dListIndex);
void SkelAnime_DrawFlexLod(GlobalContext* globalCtx, void** skeleton, Vec3s* jointTable, s32 dListCount,
                           OverrideLimbDrawOpa overrideLimbDraw, PostLimbDrawOpa postLimbDraw, void* arg,
                           s32 dListIndex);
void SkelAnime_DrawOpa(GlobalContext* globalCtx, void** skeleton, Vec3s* jointTable,
                       OverrideLimbDrawOpa overrideLimbDraw, PostLimbDrawOpa postLimbDraw, void* arg);
void SkelAnime_DrawFlexOpa(GlobalContext* globalCtx, void** skeleton, Vec3s* jointTable, s32 dListCount,
                           OverrideLimbDrawOpa overrideLimbDraw, PostLimbDrawOpa postLimbDraw, void* arg);
s16 Animation_GetLength(void* animation);
s16 Animation_GetLastFrame(void* animation);
s16 Animation_GetLimbCount2(AnimationHeader2* animation);
s16 Animation_GetLength2(AnimationHeader2* animation);
s16 Animation_GetLastFrame2(AnimationHeader2* animation);
Gfx* SkelAnime_Draw(GlobalContext* globalCtx, void** skeleton, Vec3s* jointTable, OverrideLimbDraw overrideLimbDraw,
                    PostLimbDraw postLimbDraw, void* arg, Gfx* gfx);
Gfx* SkelAnime_DrawFlex(GlobalContext* globalCtx, void** skeleton, Vec3s* jointTable, s32 dListCount,
                        OverrideLimbDraw overrideLimbDraw, PostLimbDraw postLimbDraw, void* arg, Gfx* gfx);
void SkelAnime_InterpFrameTable(s32 limbCount, Vec3s* dst, Vec3s* start, Vec3s* target, f32 weight);
void AnimationContext_Reset(AnimationContext* animationCtx);
void AnimationContext_SetNextQueue(GlobalContext* globalCtx);
void AnimationContext_DisableQueue(GlobalContext* globalCtx);
void AnimationContext_SetLoadFrame(GlobalContext* globalCtx, LinkAnimationHeader* animation, s32 frame, s32 limbCount,
                                   Vec3s* frameTable);
void AnimationContext_SetCopyAll(GlobalContext* globalCtx, s32 vecCount, Vec3s* dst, Vec3s* src);
void AnimationContext_SetInterp(GlobalContext* globalCtx, s32 vecCount, Vec3s* base, Vec3s* mod, f32 weight);
void AnimationContext_SetCopyTrue(GlobalContext* globalCtx, s32 vecCount, Vec3s* dst, Vec3s* src, u8* copyFlag);
void AnimationContext_SetCopyFalse(GlobalContext* globalCtx, s32 vecCount, Vec3s* dst, Vec3s* src, u8* copyFlag);
void AnimationContext_SetMoveActor(GlobalContext* globalCtx, Actor* actor, SkelAnime* skelAnime, f32 arg3);
void AnimationContext_Update(GlobalContext* globalCtx, AnimationContext* animationCtx);
void SkelAnime_InitLink(GlobalContext* globalCtx, SkelAnime* skelAnime, FlexSkeletonHeader* skeletonHeaderSeg,
                        LinkAnimationHeader* animation, s32 initFlags, Vec3s* jointTable, Vec3s* morphTable,
                        s32 limbCount);
void LinkAnimation_SetUpdateFunction(SkelAnime* skelAnime);
s32 LinkAnimation_Update(GlobalContext* globalCtx, SkelAnime* skelAnime);
void LinkAnimation_AnimateFrame(GlobalContext* globalCtx, SkelAnime* skelAnime);
void Animation_SetMorph(GlobalContext* globalCtx, SkelAnime* skelAnime, f32 morphFrames);
void LinkAnimation_Change(GlobalContext* globalCtx, SkelAnime* skelAnime, LinkAnimationHeader* animation, f32 playSpeed,
                          f32 startFrame, f32 endFrame, u8 mode, f32 morphFrames);
void LinkAnimation_PlayOnce(GlobalContext* globalCtx, SkelAnime* skelAnime, LinkAnimationHeader* animation);
void LinkAnimation_PlayOnceSetSpeed(GlobalContext* globalCtx, SkelAnime* skelAnime, LinkAnimationHeader* animation,
                                    f32 playSpeed);
void LinkAnimation_PlayLoop(GlobalContext* globalCtx, SkelAnime* skelAnime, LinkAnimationHeader* animation);
void LinkAnimation_PlayLoopSetSpeed(GlobalContext* globalCtx, SkelAnime* skelAnime, LinkAnimationHeader* animation,
                                    f32 playSpeed);
void LinkAnimation_CopyJointToMorph(GlobalContext* globalCtx, SkelAnime* skelAnime);
void LinkAnimation_CopyMorphToJoint(GlobalContext* globalCtx, SkelAnime* skelAnime);
void LinkAnimation_LoadToMorph(GlobalContext* globalCtx, SkelAnime* skelAnime, LinkAnimationHeader* animation,
                               f32 frame);
void LinkAnimation_LoadToJoint(GlobalContext* globalCtx, SkelAnime* skelAnime, LinkAnimationHeader* animation,
                               f32 frame);
void LinkAnimation_InterpJointMorph(GlobalContext* globalCtx, SkelAnime* skelAnime, f32 frame);
void LinkAnimation_BlendToJoint(GlobalContext* globalCtx, SkelAnime* skelAnime, LinkAnimationHeader* animation1,
                                f32 frame1, LinkAnimationHeader* animation2, f32 frame2, f32 weight, Vec3s* blendTable);
void LinkAnimation_BlendToMorph(GlobalContext* globalCtx, SkelAnime* skelAnime, LinkAnimationHeader* animation1,
                                f32 frame1, LinkAnimationHeader* animation2, f32 frame2, f32 weight, Vec3s* blendTable);
void LinkAnimation_EndLoop(SkelAnime* skelAnime);
s32 LinkAnimation_OnFrame(SkelAnime* skelAnime, f32 frame);
s32 SkelAnime_Init(GlobalContext* globalCtx, SkelAnime* skelAnime, SkeletonHeader* skeletonHeaderSeg,
                   AnimationHeader* animation, Vec3s* jointTable, Vec3s* morphTable, s32 limbCount);
s32 SkelAnime_InitFlex(GlobalContext* globalCtx, SkelAnime* skelAnime, FlexSkeletonHeader* skeletonHeaderSeg,
                       AnimationHeader* animation, Vec3s* jointTable, Vec3s* morphTable, s32 limbCount);
s32 SkelAnime_InitSkin(GlobalContext* globalCtx, SkelAnime* skelAnime, SkeletonHeader* skeletonHeaderSeg,
                       AnimationHeader* animation);
s32 SkelAnime_Update(SkelAnime* skelAnime);
void Animation_ChangeImpl(SkelAnime* skelAnime, AnimationHeader* animation, f32 playSpeed, f32 startFrame, f32 endFrame,
                          u8 mode, f32 morphFrames, s8 taper);
void Animation_Change(SkelAnime* skelAnime, AnimationHeader* animation, f32 playSpeed, f32 startFrame, f32 endFrame,
                      u8 mode, f32 morphFrames);
void Animation_PlayOnce(SkelAnime* skelAnime, AnimationHeader* animation);
void Animation_MorphToPlayOnce(SkelAnime* skelAnime, AnimationHeader* animation, f32 morphFrames);
void Animation_PlayOnceSetSpeed(SkelAnime* skelAnime, AnimationHeader* animation, f32 playSpeed);
void Animation_PlayLoop(SkelAnime* skelAnime, AnimationHeader* animation);
void Animation_MorphToLoop(SkelAnime* skelAnime, AnimationHeader* animation, f32 morphFrames);
void Animation_PlayLoopSetSpeed(SkelAnime* skelAnime, AnimationHeader* animation, f32 playSpeed);
void Animation_EndLoop(SkelAnime* skelAnime);
void Animation_Reverse(SkelAnime* skelAnime);
void SkelAnime_CopyFrameTableTrue(SkelAnime* skelAnime, Vec3s* dst, Vec3s* src, u8* copyFlag);
void SkelAnime_CopyFrameTableFalse(SkelAnime* skelAnime, Vec3s* dst, Vec3s* src, u8* copyFlag);
void SkelAnime_UpdateTranslation(SkelAnime* skelAnime, Vec3f* pos, s16 angle);
s32 Animation_OnFrame(SkelAnime* skelAnime, f32 frame);
void SkelAnime_Free(SkelAnime* skelAnime, GlobalContext* globalCtx);
void SkelAnime_CopyFrameTable(SkelAnime* skelAnime, Vec3s* dst, Vec3s* src);
void func_800A57C0(MtxF* mtx, Struct_800A57C0* arg1, Struct_800A598C* arg2, Vtx* arg3, Vec3f* arg4);
void func_800A598C(GraphicsContext* gfxCtx, PSkinAwb* skin, s32 limbIndex, s32 arg3);
void func_800A5E28(GraphicsContext* gfxCtx, PSkinAwb* skin, s32 limbIndex, s32 arg3, s32 arg4);
void func_800A5F60(GraphicsContext* gfxCtx, PSkinAwb* skin, s32 limbIndex, Gfx* arg3, s32 arg4);
void func_800A60D8(Actor* actor, GlobalContext* globalCtx, PSkinAwb* skin, SkinCallback callback, SkinCallback2 arg4,
                   s32 arg5, s32 arg6, s32 arg7);
void func_800A6330(Actor* actor, GlobalContext* globalCtx, PSkinAwb* skin, SkinCallback callback, s32 arg4);
void func_800A6360(Actor* this, GlobalContext* globalCtx, PSkinAwb* skin, SkinCallback callback, SkinCallback2 arg4,
                   s32 arg5);
void func_800A63CC(Actor* actor, GlobalContext* globalCtx, PSkinAwb* skin, SkinCallback callback, SkinCallback2 arg4,
                   s32 arg5, s32 arg6, s32 arg7);
void func_800A6408(PSkinAwb* skin, s32 joint, Vec3f* arg2, Vec3f* arg3);
void func_800A6460(GlobalContext* globalCtx, PSkinAwb* skin, s32 arg2);
void func_800A663C(GlobalContext* globalCtx, PSkinAwb* skin, SkeletonHeader* skeletonHeader,
                   AnimationHeader* animationHeader);
void func_800A6888(GlobalContext* globalCtx, PSkinAwb* skin);
s32 func_800A698C(PSkinAwb* skin, SkinLimb** limbs, Mtx* arg2, u8 arg3, u8 arg4);
s32 func_800A6AC4(PSkinAwb* skin, MtxF* arg1, Actor* actor, s32 arg3);
void SkinMatrix_Vec3fMtxFMultXYZW(MtxF* mf, Vec3f* src, Vec3f* xyzDest, f32* wDest);
void SkinMatrix_Vec3fMtxFMultXYZ(MtxF* mf, Vec3f* src, Vec3f* dest);
void SkinMatrix_MtxFMtxFMult(MtxF* mfB, MtxF* mfA, MtxF* dest);
void SkinMatrix_GetClear(MtxF** mf);
void SkinMatrix_MtxFCopy(MtxF* src, MtxF* dest);
s32 SkinMatrix_Invert(MtxF* src, MtxF* dest);
void SkinMatrix_SetScale(MtxF* mf, f32 x, f32 y, f32 z);
void SkinMatrix_SetRotateRPY(MtxF* mf, s16 roll, s16 pitch, s16 yaw);
void SkinMatrix_SetTranslate(MtxF* mf, f32 x, f32 y, f32 z);
void SkinMatrix_SetScaleRotateYRPTranslate(MtxF* mf, f32 scaleX, f32 scaleY, f32 scaleZ, s16 yaw, s16 roll, s16 pitch,
                                           f32 dx, f32 dy, f32 dz);
void SkinMatrix_SetRotateRPYTranslate(MtxF* mf, s16 roll, s16 pitch, s16 yaw, f32 dx, f32 dy, f32 dz);
Mtx* SkinMatrix_MtxFToNewMtx(GraphicsContext* gfxCtx, MtxF* src);
void func_800A7EC0(MtxF* mf, s16 a, f32 x, f32 y, f32 z);
void Sram_InitNewSave(void);
void Sram_InitDebugSave(void);
void Sram_OpenSave(SramContext* sramCtx);
void Sram_WriteSave(s32 unused);
void Sram_VerifyAndLoadAllSaves(FileChooseContext* fileChoose, SramContext* sramCtx);
void Sram_InitSave(FileChooseContext* fileChoose, SramContext* sramCtx);
void Sram_EraseSave(FileChooseContext* fileChoose, SramContext* sramCtx);
void Sram_CopySave(FileChooseContext* fileChoose, SramContext* sramCtx);
void Sram_Write16Bytes(SramContext* sramCtx);
void Sram_InitSram(GameState* gameState, SramContext* sramCtx);
void Sram_Alloc(GameState* gameState, SramContext* sramCtx);
void Sram_Init(GlobalContext* globalCtx, SramContext* sramCtx);
void SsSram_Init(u32 addr, u8 handleType, u8 handleDomain, u8 handleLatency, u8 handlePageSize, u8 handleRelDuration,
                 u8 handlePulse, u32 handleSpeed);
void SsSram_Dma(void* dramAddr, size_t size, s32 direction);
void SsSram_ReadWrite(u32 addr, void* dramAddr, size_t size, s32 direction);
void func_800A9F30(PadMgr*, s32);
void func_800A9F6C(f32, u8, u8, u8);
void func_800AA000(f32, u8, u8, u8);
void func_800AA0B4();
u32 func_800AA148();
void func_800AA15C();
void func_800AA16C();
void func_800AA178(u32);
View* View_New(GraphicsContext* gfxCtx);
void View_Free(View* view);
void View_Init(View*, GraphicsContext*);
void func_800AA358(View* view, Vec3f* eye, Vec3f* lookAt, Vec3f* up);
void func_800AA3F0(View* view, Vec3f* eye, Vec3f* lookAt, Vec3f* up);
void View_SetScale(View* view, f32 scale);
void View_GetScale(View* view, f32* scale);
void func_800AA460(View* view, f32 fovy, f32 near, f32 far);
void func_800AA48C(View* view, f32* fovy, f32* near, f32* far);
void func_800AA4A8(View* view, f32 fovy, f32 near, f32 far);
void func_800AA4E0(View* view, f32* fovy, f32* near, f32* far);
void View_SetViewport(View* view, Viewport* viewport);
void View_GetViewport(View* view, Viewport* viewport);
void func_800AA76C(View* view, f32 arg1, f32 arg2, f32 arg3);
void func_800AA78C(View* view, f32 arg1, f32 arg2, f32 arg3);
s32 func_800AA7AC(View* view, f32 arg1);
void func_800AA7B8(View* view);
void func_800AA814(View* view);
void func_800AA840(View* view, Vec3f vec1, Vec3f vec2, f32 arg3);
s32 func_800AA890(View* view, Mtx* mtx);
void func_800AAA50(View* view, s32 arg1);
s32 func_800AAA9C(View* view);
s32 func_800AB0A8(View* view);
s32 func_800AB2C4(View* view);
s32 func_800AB560(View* view);
s32 func_800AB944(View* view);
s32 func_800AB9EC(View* view, s32 arg1, Gfx** p);
s32 func_800ABE74(f32 eyeX, f32 eyeY, f32 eyeZ);
void func_800ACE70(struct_801664F0* this);
void func_800ACE90(struct_801664F0* this);
void func_800ACE98(struct_801664F0* this, Gfx** gfxp);
void VisMono_Init(VisMono* this);
void VisMono_Destroy(VisMono* this);
void VisMono_UpdateTexture(VisMono* this, u16* tex);
Gfx* VisMono_DrawTexture(VisMono* this, Gfx* gfx);
void VisMono_Draw(VisMono* this, Gfx** gfxp);
void VisMono_DrawOld(VisMono* this);
void func_800AD920(struct_80166500* this);
void func_800AD950(struct_80166500* this);
void func_800AD958(struct_80166500* this, Gfx** gfxp);
Mtx* SkyboxDraw_UpdateMatrix(SkyboxContext* skyboxCtx, f32 x, f32 y, f32 z);
void SkyboxDraw_Draw(SkyboxContext* skyboxCtx, GraphicsContext* gfxCtx, s16 skyboxId, s16 alpha, f32 x, f32 y, f32 z);
void SkyboxDraw_Update(SkyboxContext* skyboxCtx);
void PlayerCall_InitFuncPtrs();
void TransitionUnk_InitGraphics(TransitionUnk* this);
void TransitionUnk_InitData(TransitionUnk* this);
void TransitionUnk_Destroy(TransitionUnk* this);
TransitionUnk* TransitionUnk_Init(TransitionUnk* this, s32 row, s32 col);
void TransitionUnk_SetData(TransitionUnk* this);
void TransitionUnk_Draw(TransitionUnk* this, Gfx**);
void func_800B23E8(TransitionUnk* this);
void TransitionTriforce_Start(TransitionTriforce* this);
TransitionTriforce* TransitionTriforce_Init(TransitionTriforce* this);
void TransitionTriforce_Destroy(TransitionTriforce* this);
void TransitionTriforce_Update(TransitionTriforce* this, s32 updateRate);
void TransitionTriforce_SetColor(TransitionTriforce* this, u32 color);
void TransitionTriforce_SetType(TransitionTriforce* this, s32 type);
void TransitionTriforce_Draw(TransitionTriforce* this, Gfx** gfxP);
s32 TransitionTriforce_IsDone(TransitionTriforce* this);
void TransitionWipe_Start(TransitionWipe* this);
TransitionWipe* TransitionWipe_Init(TransitionWipe* this);
void TransitionWipe_Destroy(TransitionWipe* this);
void TransitionWipe_Update(TransitionWipe* this, s32 updateRate);
void TransitionWipe_Draw(TransitionWipe* this, Gfx** gfxP);
s32 TransitionWipe_IsDone(TransitionWipe* this);
void TransitionWipe_SetType(TransitionWipe* this, s32 type);
void TransitionWipe_SetColor(TransitionWipe* this, u32 color);
void TransitionCircle_Start(TransitionCircle* this);
TransitionCircle* TransitionCircle_Init(TransitionCircle* this);
void TransitionCircle_Destroy(TransitionCircle* this);
void TransitionCircle_Update(TransitionCircle* this, s32 updateRate);
void TransitionCircle_Draw(TransitionCircle* this, Gfx** gfxP);
s32 TransitionCircle_IsDone(TransitionCircle* this);
void TransitionCircle_SetType(TransitionCircle* this, s32 type);
void TransitionCircle_SetColor(TransitionCircle* this, u32 color);
void TransitionCircle_SetEnvColor(TransitionCircle* this, u32 color);
void TransitionFade_Start(TransitionFade* this);
TransitionFade* TransitionFade_Init(TransitionFade* this);
void TransitionFade_Destroy(TransitionFade* this);
void TransitionFade_Update(TransitionFade* this, s32 updateRate);
void TransitionFade_Draw(TransitionFade* this, Gfx** gfxP);
s32 TransitionFade_IsDone(TransitionFade* this);
void TransitionFade_SetColor(TransitionFade* this, u32 color);
void TransitionFade_SetType(TransitionFade* this, s32 type);
void ShrinkWindow_SetVal(s32 value);
u32 ShrinkWindow_GetVal(void);
void ShrinkWindow_SetCurrentVal(s32 nowVal);
u32 ShrinkWindow_GetCurrentVal(void);
void ShrinkWindow_Init(void);
void ShrinkWindow_Destroy(void);
void ShrinkWindow_Update(s32 updateRate);
void DbgCamera_Init(DBCamera* dbCamera, Camera* camera);
void DbgCamera_Enable(DBCamera* dbCamera, Camera* camera);
void DbgCamera_Update(DBCamera* dbCamera, Camera* camera);
void DbgCamera_FirstInit(Camera* camera, DBCamera* dbCamera);
s32 func_800BB2B4(Vec3f* pos, f32* roll, f32* fov, CutsceneCameraPoint* point, s16* keyframe, f32* curFrame);
s32 Mempak_Init(s32 controllerNb);
s32 Mempak_GetFreeBytes(s32 controllerNb);
s32 Mempak_FindFile(s32 controllerNb, char start, char end);
s32 Mempak_Write(s32 controllerNb, char idx, void* buffer, s32 offset, s32 size);
s32 Mempak_Read(s32 controllerNb, char idx, void* buffer, s32 offset, s32 size);
s32 Mempak_Alloc(s32 controllerNb, char* idx, s32 size);
s32 Mempak_DeleteFile(s32 controllerNb, char idx);
s32 Mempak_GetFileSize(s32 controllerNb, char idx);
void KaleidoManager_LoadOvl(KaleidoManagerOvl* ovl);
void KaleidoManager_ClearOvl(KaleidoManagerOvl* ovl);
void KaleidoManager_Init(GlobalContext* globalCtx);
void KaleidoManager_Destroy();
void* KaleidoManager_GetRamAddr(void* vram);
void KaleidoScopeCall_LoadPlayer();
void KaleidoScopeCall_Init(GlobalContext* globalCtx);
void KaleidoScopeCall_Destroy(GlobalContext* globalCtx);
void KaleidoScopeCall_Update(GlobalContext* globalCtx);
void KaleidoScopeCall_Draw(GlobalContext* globalCtx);
void func_800BC490(GlobalContext* globalCtx, s16 point);
s32 func_800BC56C(GlobalContext* globalCtx, s16 arg1);
void func_800BC590(GlobalContext* globalCtx);
void func_800BC5E0(GlobalContext* globalCtx, s32 arg1);
Gfx* func_800BC8A0(GlobalContext* globalCtx, Gfx* gfx);
void Gameplay_Destroy(GameState* thisx);
void Gameplay_Init(GameState* thisx);
void Gameplay_Main(GameState* thisx);
s32 Gameplay_InCsMode(GlobalContext* globalCtx);
f32 func_800BFCB8(GlobalContext* globalCtx, MtxF* mf, Vec3f* vec);
void* Gameplay_LoadFile(GlobalContext* globalCtx, RomFile* file);
void Gameplay_SpawnScene(GlobalContext* globalCtx, s32 sceneNum, s32 spawn);
void func_800C016C(GlobalContext* globalCtx, Vec3f* src, Vec3f* dest);
s16 Gameplay_CreateSubCamera(GlobalContext* globalCtx);
s16 Gameplay_GetActiveCamId(GlobalContext* globalCtx);
s16 Gameplay_ChangeCameraStatus(GlobalContext* globalCtx, s16 camId, s16 status);
void Gameplay_ClearCamera(GlobalContext* globalCtx, s16 camId);
void Gameplay_ClearAllSubCameras(GlobalContext* globalCtx);
Camera* Gameplay_GetCamera(GlobalContext* globalCtx, s16 camId);
s32 Gameplay_CameraSetAtEye(GlobalContext* globalCtx, s16 camId, Vec3f* arg2, Vec3f* arg3);
s32 Gameplay_CameraSetAtEyeUp(GlobalContext* globalCtx, s16 camId, Vec3f* at, Vec3f* eye, Vec3f* up);
s32 Gameplay_CameraSetFov(GlobalContext* globalCtx, s16 camId, f32 fov);
s32 Gameplay_SetCameraRoll(GlobalContext* globalCtx, s16 camId, s16 roll);
void Gameplay_CopyCamera(GlobalContext* globalCtx, s16 camId1, s16 camId2);
s32 func_800C0808(GlobalContext* globalCtx, s16 camId, Player* player, s16 arg3);
s32 Gameplay_CameraChangeSetting(GlobalContext* globalCtx, s16 camId, s16 arg2);
void func_800C08AC(GlobalContext* globalCtx, s16 camId, s16 arg2);
void Gameplay_SaveSceneFlags(GlobalContext* globalCtx);
void Gameplay_SetupRespawnPoint(GlobalContext* globalCtx, s32 respawnMode, s32 playerParams);
void Gameplay_TriggerVoidOut(GlobalContext* globalCtx);
void Gameplay_TriggerRespawn(GlobalContext* globalCtx);
s32 func_800C0CB8(GlobalContext* globalCtx);
s32 func_800C0D28(GlobalContext* globalCtx);
s32 func_800C0D34(GlobalContext* globalCtx, Actor* actor, s16* yaw);
void PreRender_SetValuesSave(PreRenderContext* this, u32 width, u32 height, void* fbuf, void* zbuf, void* cvg);
void PreRender_Init(PreRenderContext* this);
void PreRender_SetValues(PreRenderContext* this, u32 width, u32 height, void* fbuf, void* zbuf);
void PreRender_Destroy(PreRenderContext* this);
void func_800C0F28(PreRenderContext* this, Gfx** gfxp, void* buf, void* bufSave);
void func_800C1258(PreRenderContext* this, Gfx** gfxp);
void func_800C170C(PreRenderContext* this, Gfx** gfxp, void* fbuf, void* fbufSave, u32 r, u32 g, u32 b, u32 a);
void func_800C1AE8(PreRenderContext* this, Gfx** gfxp, void* fbuf, void* fbufSave);
void func_800C1B24(PreRenderContext* this, Gfx** gfxp, void* fbuf, void* cvgSave);
void func_800C1E9C(PreRenderContext* this, Gfx** gfxp);
void func_800C1F20(PreRenderContext* this, Gfx** gfxp);
void func_800C1FA4(PreRenderContext* this, Gfx** gfxp);
void func_800C20B4(PreRenderContext* this, Gfx** gfxp);
void func_800C2118(PreRenderContext* this, Gfx** gfxp);
void func_800C213C(PreRenderContext* this, Gfx** gfxp);
void func_800C24BC(PreRenderContext* this, Gfx** gfxp);
void func_800C24E0(PreRenderContext* this, Gfx** gfxp);
void func_800C2500(PreRenderContext* this, s32 x, s32 y);
void func_800C2FE4(PreRenderContext* this);
void PreRender_Calc(PreRenderContext* this);
void THGA_Ct(TwoHeadGfxArena* thga, Gfx* start, u32 size);
void THGA_Dt(TwoHeadGfxArena* thga);
u32 THGA_IsCrash(TwoHeadGfxArena* thga);
void THGA_Init(TwoHeadGfxArena* thga);
s32 THGA_GetSize(TwoHeadGfxArena* thga);
Gfx* THGA_GetHead(TwoHeadGfxArena* thga);
void THGA_SetHead(TwoHeadGfxArena* thga, Gfx* start);
Gfx* THGA_GetTail(TwoHeadGfxArena* thga);
Gfx* THGA_AllocStartArray8(TwoHeadGfxArena* thga, u32 count);
Gfx* THGA_AllocStart8(TwoHeadGfxArena* thga);
Gfx* THGA_AllocStart8Wrapper(TwoHeadGfxArena* thga);
Gfx* THGA_AllocEnd(TwoHeadGfxArena* thga, u32 size);
Gfx* THGA_AllocEndArray64(TwoHeadGfxArena* thga, u32 count);
Gfx* THGA_AllocEnd64(TwoHeadGfxArena* thga);
Gfx* THGA_AllocEndArray16(TwoHeadGfxArena* thga, u32 count);
Gfx* THGA_AllocEnd16(TwoHeadGfxArena* thga);
void* THA_GetHead(TwoHeadArena* tha);
void THA_SetHead(TwoHeadArena* tha, void* start);
void* THA_GetTail(TwoHeadArena* tha);
void* THA_AllocStart(TwoHeadArena* tha, u32 size);
void* THA_AllocStart1(TwoHeadArena* tha);
void* THA_AllocEnd(TwoHeadArena* tha, u32 size);
void* THA_AllocEndAlign16(TwoHeadArena* tha, u32 size);
void* THA_AllocEndAlign(TwoHeadArena* tha, u32 size, u32 mask);
s32 THA_GetSize(TwoHeadArena* tha);
u32 THA_IsCrash(TwoHeadArena* tha);
void THA_Init(TwoHeadArena* tha);
void THA_Ct(TwoHeadArena* tha, void* ptr, u32 size);
void THA_Dt(TwoHeadArena* tha);
void func_800C3C20(void);
void func_800C3C80(AudioMgr* audioMgr);
void AudioMgr_HandleRetrace(AudioMgr* audioMgr);
void AudioMgr_HandlePRENMI(AudioMgr* audioMgr);
void AudioMgr_ThreadEntry(void* arg0);
void AudioMgr_Unlock(AudioMgr* audioMgr);
void AudioMgr_Init(AudioMgr* audioMgr, void* stack, OSPri pri, OSId id, SchedContext* sched, IrqMgr* irqMgr);
void TitleSetup_InitImpl(GameState* gameState);
void TitleSetup_Destroy(GameState* gameState);
void TitleSetup_Init(GameState* gameState);
void GameState_FaultPrint(void);
void GameState_SetFBFilter(Gfx** gfx);
void GameState_DrawInputDisplay(u16 input, Gfx** gfx);
void GameState_Draw(GameState* gameState, GraphicsContext* gfxCtx);
void GameState_SetFrameBuffer(GraphicsContext* gfxCtx);
void GameState_ReqPadData(GameState* gameState);
void GameState_Update(GameState* gameState);
void GameState_InitArena(GameState* gameState, size_t size);
void GameState_Realloc(GameState* gameState, size_t size);
void GameState_Init(GameState* gameState, GameStateFunc init, GraphicsContext* gfxCtx);
void GameState_Destroy(GameState* gameState);
GameStateFunc GameState_GetInit(GameState* gameState);
u32 GameState_IsRunning(GameState* gameState);
void* GameState_Alloc(GameState* gameState, size_t size, char* file, s32 line);
void func_800C55D0(GameAlloc* this);
void* GameAlloc_MallocDebug(GameAlloc* this, u32 size, const char* file, s32 line);
void* GameAlloc_Malloc(GameAlloc* this, u32 size);
void GameAlloc_Free(GameAlloc* this, void* data);
void GameAlloc_Cleanup(GameAlloc* this);
void GameAlloc_Init(GameAlloc* this);
void Graph_FaultClient();
void Graph_DisassembleUCode(void* arg0);
void Graph_UCodeFaultClient(void* arg0);
void* Graph_InitTHGA(GraphicsContext* gfxCtx);
GameStateOverlay* Graph_GetNextGameState(GameState* gameState);
void Graph_Init(GraphicsContext* gfxCtx);
void Graph_Destroy(GraphicsContext* gfxCtx);
void Graph_TaskSet00(GraphicsContext* gfxCtx);
void Graph_Update(GraphicsContext* gfxCtx, GameState* gameState);
void Graph_ThreadEntry(void*);
void* Graph_Alloc(GraphicsContext* gfxCtx, size_t size);
void* Graph_Alloc2(GraphicsContext* gfxCtx, size_t size);
void Graph_OpenDisps(Gfx** dispRefs, GraphicsContext* gfxCtx, const char* file, s32 line);
void Graph_CloseDisps(Gfx** dispRefs, GraphicsContext* gfxCtx, const char* file, s32 line);
Gfx* Graph_GfxPlusOne(Gfx* gfx);
Gfx* Graph_BranchDlist(Gfx* gfx, Gfx* dst);
void* Graph_DlistAlloc(Gfx** gfx, u32 size);
ListAlloc* ListAlloc_Init(ListAlloc* this);
void* ListAlloc_Alloc(ListAlloc* this, u32 size);
void ListAlloc_Free(ListAlloc* this, void* data);
void ListAlloc_FreeAll(ListAlloc* this);
void Main_LogSystemHeap();
void Main(void*);
OSMesgQueue* PadMgr_LockSerialMesgQueue(PadMgr* padmgr);
void PadMgr_UnlockSerialMesgQueue(PadMgr* padmgr, OSMesgQueue* ctrlrqueue);
void PadMgr_LockPadData(PadMgr* padmgr);
void PadMgr_UnlockPadData(PadMgr* padmgr);
void PadMgr_RumbleControl(PadMgr* padmgr);
void PadMgr_RumbleStop(PadMgr* padmgr);
void PadMgr_RumbleReset(PadMgr* padmgr);
void PadMgr_RumbleSet(PadMgr* padmgr, u8* ctrlrRumbles);
void PadMgr_ProcessInputs(PadMgr* padmgr);
void PadMgr_HandleRetraceMsg(PadMgr* padmgr);
void PadMgr_HandlePreNMI(PadMgr* padmgr);
void PadMgr_Init(PadMgr* padmgr, OSMesgQueue* siIntMsgQ, IrqMgr* irqMgr, OSId id, OSPri priority, void* stack);
void Sched_SwapFrameBuffer(CfbInfo* cfbInfo);
void func_800C84E4(SchedContext* sc, CfbInfo* cfbInfo);
void Sched_HandleReset(SchedContext* sc);
void Sched_HandleStart(SchedContext* sc);
void Sched_QueueTask(SchedContext* sc, OSScTask* task);
void Sched_Yield(SchedContext* sc);
OSScTask* func_800C89D4(SchedContext* sc, OSScTask* task);
s32 Sched_Schedule(SchedContext* sc, OSScTask** sp, OSScTask** dp, s32 state);
void func_800C8BC4(SchedContext* sc, OSScTask* task);
u32 Sched_IsComplete(SchedContext* sc, OSScTask* task);
void Sched_RunTask(SchedContext* sc, OSScTask* spTask, OSScTask* dpTask);
void Sched_HandleEntry(SchedContext* sc);
void Sched_HandleRetrace(SchedContext* sc);
void Sched_HandleRSPDone(SchedContext* sc);
void Sched_HandleRDPDone(SchedContext* sc);
void Sched_SendEntryMsg(OSMesgQueue* mq);
void Sched_ThreadEntry(void* arg);
void Sched_Init(SchedContext* sc, void* stack, OSPri priority, s32 arg3, s32 arg4, IrqMgr* irqMgr);
void SpeedMeter_InitImpl(SpeedMeter* this, u32 arg1, u32 y);
void SpeedMeter_Init(SpeedMeter* this);
void SpeedMeter_Destroy(SpeedMeter* this);
void SpeedMeter_DrawTimeEntries(SpeedMeter* this, GraphicsContext* gfxCtx);
void SpeedMeter_InitAllocEntry(SpeedMeterAllocEntry* entry, u32 maxval, u32 val, u16 backColor, u16 foreColor, u32 ulx,
                               u32 lrx, u32 uly, u32 lry);
void SpeedMeter_DrawAllocEntry(SpeedMeterAllocEntry* this, GraphicsContext* gfxCtx);
void SpeedMeter_DrawAllocEntries(SpeedMeter* meter, GraphicsContext* gfxCtx, GameState* state);
void SysCfb_Init(s32 n64dd);
u32 SysCfb_GetFbPtr(s32 idx);
u32 SysCfb_GetFbEnd();
f32 Math_FactorialF(f32 n);
f32 Math_Factorial(s32 n);
f32 Math_PowF(f32 base, s32 exp);
f32 Math_SinF(f32 angle);
f32 Math_CosF(f32 angle);
s32 Math3D_PlaneVsLineSegClosestPoint(f32 planeAA, f32 planeAB, f32 planeAC, f32 planeADist, f32 planeBA, f32 planeBB,
                                      f32 planeBC, f32 planeBDist, Vec3f* linePointA, Vec3f* linePointB,
                                      Vec3f* closestPoint);
void Math3D_LineClosestToPoint(Linef* line, Vec3f* pos, Vec3f* closestPoint);
s32 Math3D_PlaneVsPlaneVsLineClosestPoint(f32 planeAA, f32 planeAB, f32 planeAC, f32 planeADist, f32 planeBA,
                                          f32 planeBB, f32 planeBC, f32 planeBDist, Vec3f* point, Vec3f* closestPoint);
void Math3D_LineSplitRatio(Vec3f* v0, Vec3f* v1, f32 ratio, Vec3f* ret);
f32 Math3D_Cos(Vec3f* a, Vec3f* b);
s32 Math3D_CosOut(Vec3f* a, Vec3f* b, f32* dst);
void Math3D_Vec3fReflect(Vec3f* vec, Vec3f* normal, Vec3f* reflVec);
s32 Math3D_PointInSquare2D(f32 upperLeftX, f32 lowerRightX, f32 upperLeftY, f32 lowerRightY, f32 x, f32 y);
f32 Math3D_Dist1DSq(f32 a, f32 b);
f32 Math3D_Dist2DSq(f32 x0, f32 y0, f32 x1, f32 y1);
f32 Math3D_Vec3fMagnitudeSq(Vec3f* vec);
f32 Math3D_Vec3fMagnitude(Vec3f* vec);
f32 Math3D_Vec3fDistSq(Vec3f* a, Vec3f* b);
void Math3D_Vec3f_Cross(Vec3f* a, Vec3f* b, Vec3f* ret);
void Math3D_SurfaceNorm(Vec3f* va, Vec3f* vb, Vec3f* vc, Vec3f* normal);
f32 Math3D_Vec3f_DistXYZ(Vec3f* a, Vec3f* b);
s32 Math3D_PointRelativeToCubeFaces(Vec3f* point, Vec3f* min, Vec3f* max);
s32 Math3D_PointRelativeToCubeEdges(Vec3f* point, Vec3f* min, Vec3f* max);
s32 Math3D_PointRelativeToCubeVertices(Vec3f* point, Vec3f* min, Vec3f* max);
s32 Math3D_LineVsCube(Vec3f* min, Vec3f* max, Vec3f* a, Vec3f* b);
void Math3D_RotateXZPlane(Vec3f* pointOnPlane, s16 angle, f32* a, f32* c, f32* d);
void Math3D_DefPlane(Vec3f* va, Vec3f* vb, Vec3f* vc, f32* nx, f32* ny, f32* nz, f32* originDist);
f32 Math3D_UDistPlaneToPos(f32 nx, f32 ny, f32 nz, f32 originDist, Vec3f* p);
f32 Math3D_DistPlaneToPos(f32 nx, f32 ny, f32 nz, f32 originDist, Vec3f* p);
s32 Math3D_TriChkPointParaYSlopedY(Vec3f* v0, Vec3f* v1, Vec3f* v2, f32 z, f32 x);
s32 Math3D_TriChkPointParaYIntersectDist(Vec3f* v0, Vec3f* v1, Vec3f* v2, f32 nx, f32 ny, f32 nz, f32 originDist, f32 z,
                                         f32 x, f32* yIntersect, f32 chkDist);
s32 Math3D_TriChkPointParaYIntersectInsideTri(Vec3f* v0, Vec3f* v1, Vec3f* v2, f32 nx, f32 ny, f32 nz, f32 originDist,
                                              f32 z, f32 x, f32* yIntersect, f32 chkDist);
s32 Math3D_TriChkLineSegParaYIntersect(Vec3f* v0, Vec3f* v1, Vec3f* v2, f32 nx, f32 ny, f32 nz, f32 originDist, f32 z,
                                       f32 x, f32* yIntersect, f32 y0, f32 y1);
s32 Math3D_TriChkPointParaYDist(Vec3f* v0, Vec3f* v1, Vec3f* v2, Plane* plane, f32 z, f32 x, f32 chkDist);
s32 Math3D_TriChkPointParaXIntersect(Vec3f* v0, Vec3f* v1, Vec3f* v2, f32 nx, f32 ny, f32 nz, f32 originDist, f32 y,
                                     f32 z, f32* xIntersect);
s32 Math3D_TriChkLineSegParaXIntersect(Vec3f* v0, Vec3f* v1, Vec3f* v2, f32 nx, f32 ny, f32 nz, f32 originDist, f32 y,
                                       f32 z, f32* xIntersect, f32 x0, f32 x1);
s32 Math3D_TriChkPointParaXDist(Vec3f* v0, Vec3f* v1, Vec3f* v2, Plane* plane, f32 y, f32 z, f32 chkDist);
s32 Math3D_TriChkPointParaZIntersect(Vec3f* v0, Vec3f* v1, Vec3f* v2, f32 nx, f32 ny, f32 nz, f32 originDist, f32 x,
                                     f32 y, f32* zIntersect);
s32 Math3D_TriChkLineSegParaZIntersect(Vec3f* v0, Vec3f* v1, Vec3f* v2, f32 nx, f32 ny, f32 nz, f32 originDist, f32 x,
                                       f32 y, f32* zIntersect, f32 z0, f32 z1);
s32 Math3D_TriChkLineSegParaZDist(Vec3f* v0, Vec3f* v1, Vec3f* v2, Plane* plane, f32 x, f32 y, f32 chkDist);
s32 Math3D_LineSegVsPlane(f32 nx, f32 ny, f32 nz, f32 originDist, Vec3f* linePointA, Vec3f* linePointB,
                          Vec3f* intersect, s32 fromFront);
void Math3D_TriNorm(TriNorm* tri, Vec3f* va, Vec3f* vb, Vec3f* vc);
s32 Math3D_PointDistToLine2D(f32 x0, f32 y0, f32 x1, f32 y1, f32 x2, f32 y2, f32* lineLenSq);
s32 Math3D_LineVsSph(Sphere16* sphere, Linef* line);
s32 Math3D_TriVsSphIntersect(Sphere16* sphere, TriNorm* tri, Vec3f* intersectPoint);
s32 Math3D_CylVsLineSeg(Cylinder16* cyl, Vec3f* linePointA, Vec3f* linePointB, Vec3f* intersectA, Vec3f* intersectB);
s32 Math3D_CylVsTri(Cylinder16* cyl, TriNorm* tri);
s32 Math3D_CylTriVsIntersect(Cylinder16* cyl, TriNorm* tri, Vec3f* intersect);
s32 Math3D_SphVsSph(Sphere16* sphereA, Sphere16* sphereB);
s32 Math3D_SphVsSphOverlap(Sphere16* sphereA, Sphere16* sphereB, f32* overlapSize);
s32 Math3D_SphVsSphOverlapCenter(Sphere16* sphereA, Sphere16* sphereB, f32* overlapSize, f32* centerDist);
s32 Math3D_SphVsCylOverlapDist(Sphere16* sph, Cylinder16* cyl, f32* overlapSize);
s32 Math3D_SphVsCylOverlapCenterDist(Sphere16* sph, Cylinder16* cyl, f32* overlapSize, f32* centerDist);
s32 Math3D_CylOutsideCyl(Cylinder16* ca, Cylinder16* cb, f32* deadSpace);
s32 Math3D_CylOutsideCylDist(Cylinder16* ca, Cylinder16* cb, f32* deadSpace, f32* xzDist);
s32 Math3D_TriVsTriIntersect(TriNorm* ta, TriNorm* tb, Vec3f* intersect);
s32 Math3D_XZInSphere(Sphere16* sphere, f32 x, f32 z);
s32 Math3D_XYInSphere(Sphere16* sphere, f32 x, f32 y);
s32 Math3D_YZInSphere(Sphere16* sphere, f32 y, f32 z);
void Math3D_DrawSphere(GlobalContext* globalCtx, Sphere16* sph);
void Math3D_DrawCylinder(GlobalContext* globalCtx, Cylinder16* cyl);
s16 Math_Atan2S(f32 x, f32 y);
f32 Math_Atan2F(f32 x, f32 y);
void Matrix_Init(GameState* gameState);
void Matrix_Push(void);
void Matrix_Pull(void);
void Matrix_Get(MtxF* dest);
void Matrix_Put(MtxF* src);
void Matrix_Mult(MtxF* mf, u8 mode);
void Matrix_Translate(f32 x, f32 y, f32 z, u8 mode);
void Matrix_Scale(f32 x, f32 y, f32 z, u8 mode);
void Matrix_RotateX(f32 x, u8 mode);
void Matrix_RotateY(f32 y, u8 mode);
void Matrix_RotateZ(f32 z, u8 mode);
void Matrix_RotateRPY(s16 x, s16 y, s16 z, u8 mode);
void Matrix_JointPosition(Vec3f* position, Vec3s* rotation);
void func_800D1694(f32 x, f32 y, f32 z, Vec3s* vec);
Mtx* Matrix_MtxFToMtx(MtxF* src, Mtx* dest);
Mtx* Matrix_ToMtx(Mtx* dest, char* file, s32 line);
Mtx* Matrix_NewMtx(GraphicsContext* gfxCtx, char* file, s32 line);
Mtx* Matrix_MtxFToNewMtx(MtxF* src, GraphicsContext* gfxCtx);
void Matrix_MultVec3f(Vec3f* src, Vec3f* dest);
void Matrix_MtxFCopy(MtxF* dest, MtxF* src);
void Matrix_MtxToMtxF(Mtx* src, MtxF* dest);
void Matrix_MultVec3fExt(Vec3f* src, Vec3f* dest, MtxF* mf);
void Matrix_Reverse(MtxF* mf);
void func_800D1FD4(MtxF* mf);
void func_800D20CC(MtxF* mf, Vec3s* vec, s32 flag);
void func_800D2264(MtxF* mf, Vec3s* vec, s32 flag);
void func_800D23FC(f32 f, Vec3f* vec, u8 mode);
MtxF* Matrix_CheckFloats(MtxF* mf, char* file, s32 line);
void func_800D2CEC(Mtx* mtx, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6);
u32 SysUcode_GetUCodeBoot();
u32 SysUcode_GetUCodeBootSize();
u32 SysUcode_GetUCode();
u32 SysUcode_GetUCodeData();
void func_800D2E30(UnkRumbleStruct* arg0);
void func_800D3140(UnkRumbleStruct* arg0);
void func_800D3178(UnkRumbleStruct* arg0);
void IrqMgr_AddClient(IrqMgr* this, IrqMgrClient* c, OSMesgQueue* msgQ);
void IrqMgr_RemoveClient(IrqMgr* this, IrqMgrClient* c);
void IrqMgr_SendMesgForClient(IrqMgr* this, OSMesg msg);
void IrqMgr_JamMesgForClient(IrqMgr* this, OSMesg msg);
void IrqMgr_HandlePreNMI(IrqMgr* this);
void IrqMgr_CheckStack();
void IrqMgr_HandlePRENMI450(IrqMgr* this);
void IrqMgr_HandlePRENMI480(IrqMgr* this);
void IrqMgr_HandlePRENMI500(IrqMgr* this);
void IrqMgr_HandleRetrace(IrqMgr* this);
void IrqMgr_ThreadEntry(void* arg0);
void IrqMgr_Init(IrqMgr* this, void* stack, OSPri pri, u8 retraceCount);
void DebugArena_CheckPointer(void* ptr, u32 size, const char* name, const char* action);
void* DebugArena_Malloc(u32 size);
void* DebugArena_MallocDebug(u32 size, const char* file, s32 line);
void* DebugArena_MallocR(u32 size);
void* DebugArena_MallocRDebug(u32 size, const char* file, s32 line);
void* DebugArena_Realloc(void* ptr, u32 newSize);
void* DebugArena_ReallocDebug(void* ptr, u32 newSize, const char* file, s32 line);
void DebugArena_Free(void* ptr);
void DebugArena_FreeDebug(void* ptr, const char* file, s32 line);
void* DebugArena_Calloc(u32 num, u32 size);
void DebugArena_Display();
void DebugArena_GetSizes(u32* outMaxFree, u32* outFree, u32* outAlloc);
void DebugArena_Check();
void DebugArena_Init(void* start, u32 size);
void DebugArena_Cleanup();
u8 DebugArena_IsInitalized();
void Fault_SleepImpl(u32);
void Fault_ClientProcessThread(FaultClientContext*);
void Fault_ProcessClientContext(FaultClientContext*);
u32 Fault_ProcessClient(u32, u32, u32);
void Fault_AddClient(FaultClient*, void*, void*, void*);
void Fault_RemoveClient(FaultClient*);
void Fault_AddAddrConvClient(FaultAddrConvClient*, void*, void*);
void Fault_RemoveAddrConvClient(FaultAddrConvClient*);
u32 Fault_ConvertAddress(FaultAddrConvClient*);
void Fault_Sleep(u32);
void Fault_PadCallback(Input*);
void Fault_UpdatePadImpl();
u32 Fault_WaitForInputImpl();
void Fault_WaitForInput();
void Fault_DrawRec(s32, s32, s32, s32, u16);
void Fault_FillScreenBlack();
void Fault_FillScreenRed();
void Fault_DrawCornerRec(u16);
void Fault_PrintFReg(s32, f32*);
void Fault_LogFReg(s32, f32*);
void Fault_PrintFPCR(u32);
void Fault_LogFPCR(u32);
void Fault_PrintThreadContext(OSThread*);
void Fault_LogThreadContext(OSThread*);
OSThread* Fault_FindFaultedThread();
void Fault_Wait5Seconds();
void Fault_WaitForButtonCombo();
void Fault_DrawMemDumpPage(const char*, u32*, u32);
void Fault_DrawMemDump(u32, u32, u32, u32);
void Fault_WalkStack(u32* spPtr, u32* pcPtr, u32* raPtr);
void Fault_DrawStackTrace(OSThread* thread, s32 x, s32 y, s32 height);
void Fault_LogStackTrace(OSThread* thread, s32 height);
void Fault_ResumeThread(OSThread*);
void Fault_CommitFB();
void Fault_ProcessClients();
void Fault_UpdatePad();
void Fault_ThreadEntry(void*);
void Fault_SetFB(void*, u16, u16);
void Fault_Init(void);
void Fault_HangupFaultClient(const char*, const char*);
void Fault_AddHungupAndCrashImpl(const char*, const char*);
void Fault_AddHungupAndCrash(const char*, u32);
void FaultDrawer_SetOsSyncPrintfEnabled(u32);
void FaultDrawer_DrawRecImpl(s32, s32, s32, s32, u16);
void FaultDrawer_DrawChar(char);
s32 FaultDrawer_ColorToPrintColor(u16);
void FaultDrawer_UpdatePrintColor();
void FaultDrawer_SetForeColor(u16);
void FaultDrawer_SetBackColor(u16);
void FaultDrawer_SetFontColor(u16);
void FaultDrawer_SetCharPad(s8, s8);
void FaultDrawer_SetCursor(s32, s32);
void FaultDrawer_FillScreen();
u32 FaultDrawer_FormatStringFunc(u32, const char*, s32);
void FaultDrawer_VPrintf(const char*, char*);
void FaultDrawer_Printf(const char*, ...);
void FaultDrawer_DrawText(s32, s32, const char*, ...);
void FaultDrawer_SetDrawerFB(void*, u16, u16);
void FaultDrawer_SetInputCallback(void (*)());
void FaultDrawer_SetDefault();
f32 func_800DDE20(f32 arg0);
void func_800DDE3C(void);
void Audio_ResetLoadStatus(void);
void Audio_DiscardBank(s32 bankId);
void Audio_DiscardSequence(s32 seqId);
void func_800DE238(void* mem, u32 size);
void* func_800DE258(SoundAllocPool* pool, u32 size);
void* func_800DE2B0(SoundAllocPool* pool, u32 size);
void* Audio_AllocDmaMemory(SoundAllocPool* pool, u32 size);
void* Audio_AllocDmaMemoryZeroed(SoundAllocPool* pool, u32 size);
void* Audio_AllocZeroed(SoundAllocPool* pool, u32 size);
void* Audio_Alloc(SoundAllocPool* pool, u32 size);
void Audio_SoundAllocPoolInit(SoundAllocPool* pool, void* memAddr, u32 size);
void Audio_PersistentPoolClear(PersistentPool* persistent);
void Audio_TemporaryPoolClear(TemporaryPool* temporary);
void func_800DE4B0(s32 poolIdx);
void Audio_InitMainPools(s32 sizeForAudioInitPool);
void Audio_SessionPoolsInit(AudioPoolSplit4* split);
void Audio_SeqAndBankPoolInit(AudioPoolSplit2* split);
void Audio_PersistentPoolsInit(AudioPoolSplit3* split);
void Audio_TemporaryPoolsInit(AudioPoolSplit3* split);
void* Audio_AllocBankOrSeq(s32 poolIdx, s32 size, s32 arg2, s32 id);
void* func_800DF074(s32 poolIdx, s32 arg1, s32 id);
void* func_800DF0CC(s32 poolIdx, s32 arg1, s32 id);
void func_800DF5DC(s16* arg0, s32 arg1);
void func_800DF630(s16* arg0, s32 arg1);
void func_800DF688(s16* arg0, s32 arg1, s32 arg2);
void func_800DF7C4(void);
void func_800DF888(void);
s32 Audio_ResetStep(void);
void func_800DFBF8(void);
void* func_800E04E8(s32 poolIdx, s32 id);
void* func_800E05C4(u32 size, s32 arg1, void* arg2, s8 arg3, s32 arg4);
void func_800E0634(u32 arg0, u32 arg1);
UnkHeapEntry* func_800E06CC(u32 size);
void func_800E0964(UnkHeapEntry* entry, s32 bankId);
void func_800E0AD8(UnkHeapEntry* entry);
void func_800E0BB4(UnkHeapEntry* entry, AudioBankSample* sample);
UnkHeapEntry* func_800E0BF8(u32 size);
void func_800E0CBC(void);
void func_800E0E6C(s32 id);
void func_800E0E90(s32 id);
void func_800E0EB4(s32 arg0, s32 id);
void func_800E1148(void);
void func_800E1618(s32 arg0);
s32 Audio_IsBankLoadComplete(s32 bankId);
s32 Audio_IsSeqLoadComplete(s32 seqId);
void Audio_SetBankLoadStatus(s32 bankId, u8 status);
void Audio_SetSeqLoadStatus(s32 seqId, u8 status);
void func_800E301C(void* callback);
void func_800E3400(void);
void func_800E3A14(void);
void func_800E4D94(void);
void func_800E4FB0(void);
void func_800E5B20(u32, s8);
s32 Audio_NextRandom(void);
void func_800E6880(void* mem, s32 size);
s32 osAiSetNextBuffer(void*, u32);
void Audio_NoteSetVelPanReverb(Note* note, NoteSubEu* sub, Reverb* reverb);
void Audio_NoteSetResamplingRate(NoteSubEu* noteSubEu, f32 resamplingRateInput);
void Audio_NoteInit(Note* note);
void Audio_NoteDisable(Note* note);
void Audio_ProcessNotes(void);
AudioBankSound* Audio_InstrumentGetAudioBankSound(Instrument* instrument, s32 semitone);
Instrument* Audio_GetInstrumentInner(s32 bankId, s32 instId);
Drum* Audio_GetDrum(s32 bankId, s32 drumId);
AudioBankSound* Audio_GetSfx(s32 bankId, s32 sfxId);
s32 func_800E7744(s32 instrument, s32 bankId, s32 instId, void* arg3);
void Audio_SeqChanLayerDecayRelease(SequenceChannelLayer* seqLayer, s32 target);
void Audio_SeqChanLayerNoteDecay(SequenceChannelLayer* seqLayer);
void Audio_SeqChanLayerNoteRelease(SequenceChannelLayer* seqLayer);
s32 Audio_BuildSyntheticWave(Note* note, SequenceChannelLayer* seqLayer, s32 waveId);
void Audio_InitSyntheticWave(Note* note, SequenceChannelLayer* seqLayer);
void Audio_InitNoteList(AudioListItem* list);
void Audio_InitNoteLists(NotePool* pool);
void Audio_InitNoteFreeList(void);
void Audio_NotePoolClear(NotePool* pool);
void Audio_NotePoolFill(NotePool* pool, s32 count);
void Audio_AudioListPushFront(AudioListItem* list, AudioListItem* item);
void Audio_AudioListRemove(AudioListItem* item);
Note* Audio_PopNodeWithValueLessEqual(AudioListItem* list, s32 limit);
void Audio_NoteInitForLayer(Note* note, SequenceChannelLayer* seqLayer);
void func_800E82C0(Note* note, SequenceChannelLayer* seqLayer);
void Audio_NoteReleaseAndTakeOwnership(Note* note, SequenceChannelLayer* seqLayer);
Note* Audio_AllocNoteFromDisabled(NotePool* pool, SequenceChannelLayer* seqLayer);
Note* Audio_AllocNoteFromDecaying(NotePool* pool, SequenceChannelLayer* seqLayer);
Note* Audio_AllocNoteFromActive(NotePool* pool, SequenceChannelLayer* seqLayer);
Note* Audio_AllocNote(SequenceChannelLayer* seqLayer);
void Audio_NoteInitAll(void);
void Audio_SequenceChannelProcessSound(SequenceChannel* seqChannel, s32 recalculateVolume, s32 b);
void Audio_SequencePlayerProcessSound(SequencePlayer* seqPlayer);
f32 Audio_GetPortamentoFreqScale(Portamento* p);
s16 Audio_GetVibratoPitchChange(VibratoState* vib);
f32 Audio_GetVibratoFreqScale(VibratoState* vib);
void Audio_NoteVibratoUpdate(Note* note);
void Audio_NoteVibratoInit(Note* note);
void Audio_NotePortamentoInit(Note* note);
void Audio_AdsrInit(AdsrState* adsr, AdsrEnvelope* envelope, s16* volOut);
f32 Audio_AdsrUpdate(AdsrState* adsr);
void Audio_SequenceChannelDisable(SequenceChannel* seqChannel);
void Audio_SequencePlayerDisableAsFinished(SequencePlayer* seqPlayer);
void Audio_SequencePlayerDisable(SequencePlayer* seqPlayer);
void Audio_AudioListPushBack(AudioListItem* list, AudioListItem* item);
void* Audio_AudioListPopBack(AudioListItem* list);
void Audio_ProcessSequences(s32 arg0);
void Audio_ProcessSequence(SequencePlayer* seqPlayer);
void Audio_ResetSequencePlayer(SequencePlayer* seqPlayer);
void func_800EC734(s32 seqPlayerIdx);
void Audio_InitSequencePlayers(void);
void func_800ED858(u8);
void func_800EE824(CutsceneContext* csCtx);
void func_800F2D6C(u8*, u16 sfxId);
void func_800F3A08(u8, u8, u8);
void func_800F3F3C(u8);
void func_800F4010(Vec3f*, u16 sfxId, f32);
void func_800F41E0(Vec3f*, u16 sfxId, u8);
void func_800F4138(Vec3f*, u16 sfxId, f32);
void func_800F4190(Vec3f*, u16 sfxId);
void func_800F4254(Vec3f* pos, u8 arg1);
void func_800F436C(Vec3f*, s16 arg1, f32 arg2);
void func_800F4414(Vec3f*, u16, f32);
void func_800F44EC(s32 arg0, s32 arg1);
void func_800F4524(Vec3f*, u16 sfxId, u8);
void func_800F46E0(Vec3f* pos, f32 arg0);
void func_800F47BC(void);
void func_800F47FC(void);
void func_800F483C(s32 arg0, s32 arg1);
void func_800F4BF4(Vec3f*, u16 sfxId, s8);
void func_800F4C58(Vec3f*, u16 sfxId, u8);
void func_800F5718(void);
void func_800F574C(f32 arg0, s32 arg2);
void func_800F5918(void);
void func_800F595C(u16);
void func_800F59E8(u16);
void func_800F5ACC(u32 bgmID);
void func_800F5B58(void);
void func_800F5C64(u16);
void func_800F5E90(u8);
void func_800F6114(f32);
void func_800F6268(f32, s32);
void func_800F6584(s32);
void func_800F6584(s32);
void func_800F66DC(s8);
void func_800F6700(s8 outputMode);
void func_800F67A0(u8);
void func_800F6828(u8);
void func_800F68BC(s8);
void func_800F6964(u16);
void func_800F6AB0(u8);
void func_800F6C14();
void func_800F6D58(u8 arg0, u8 arg1, u8 arg2);
void func_800F70F8();
void func_800F711C();
void func_800F7260(u16);
void func_800F72B8(u8);
void func_800F731C(u8);
void Audio_PlaySoundGeneral(u16 sfxId, Vec3f* a1, u8 a2, f32* a3, f32* a4, f32* a5);
void func_800F7680(void);
void func_800F7B54(u8, u8);
void func_800F7CEC(u8);
void func_800F8480(u8);
void func_800F87A0(u8);
void func_800F8884(u8, Vec3f*);
void func_800F89A0(u8, Vec3f*);
void func_800F89E8(Vec3f*);
void func_800F8A44(Vec3f* pos, u16 sfxId);
void func_800F8BA0(u8, u16);
void func_800F8D04(u32 sfxId);
void func_800F8E3C(void);
void func_800F8EA0(u8, u8, u16);
void func_800F8F34(u8);
void func_800F8F88(void);
u8 func_800F8FF4(u32 sfxId);
void func_800F905C(void);
void func_800F9474(u8, u16);
void func_800F94FC(u32);
void Audio_SetBGM(u32 bgmId);
void func_800FA034(void);
u16 func_800FA0B4(u8 a0);
s32 func_800FA11C(u32, s32);
void func_800FA174(u8);
void func_800FA18C(u8, u8);
void func_800FA240(u8, u8, u8, u8);
void func_800FA3DC(void);
u8 func_800FAD34(void);
void func_800FADF8(void);
void func_800FAEB4(void);
void GfxPrint_InitDlist(GfxPrint*);
void GfxPrint_SetColor(GfxPrint*, u32, u32, u32, u32);
void GfxPrint_SetPosPx(GfxPrint*, s32, s32);
void GfxPrint_SetPos(GfxPrint*, s32, s32);
void GfxPrint_SetBasePosPx(GfxPrint*, s32, s32);
void GfxPrint_PrintCharImpl(GfxPrint*, u8);
void GfxPrint_PrintChar(GfxPrint*, u8);
void GfxPrint_PrintStringWithSize(GfxPrint*, const void*, size_t, size_t);
GfxPrint* GfxPrint_Callback(GfxPrint*, const char*, size_t);
void GfxPrint_Init(GfxPrint*);
void GfxPrint_Destroy(GfxPrint*);
void GfxPrint_Open(GfxPrint*, Gfx*);
Gfx* GfxPrint_Close(GfxPrint*);
void GfxPrint_VPrintf(GfxPrint*, const char*, va_list);
void GfxPrint_Printf(GfxPrint*, const char*, ...);
void func_800FBCE0();
void func_800FBFD8(void);
void* Overlay_AllocateAndLoad(u32 vRomStart, u32 vRomEnd, void* vRamStart, void* vRamEnd);
void MtxConv_F2L(MatrixInternal* m1, MtxF* m2);
void MtxConv_L2F(MtxF* m1, MatrixInternal* m2);
void Overlay_Relocate(void* allocatedVRamAddress, OverlayRelocationSection* overlayInfo, void* vRamAddress);
s32 Overlay_Load(u32 vRomStart, u32 vRomEnd, void* vRamStart, void* vRamEnd, void* allocatedVRamAddress);
void SystemHeap_Init(void* start, u32 size);
void PadUtils_Init(Input* input);
void func_800FCB70();
void PadUtils_ResetPressRel(Input* input);
u32 PadUtils_CheckCurExact(Input* input, u16 value);
u32 PadUtils_CheckCur(Input* input, u16 key);
u32 PadUtils_CheckPressed(Input* input, u16 key);
u32 PadUtils_CheckReleased(Input* input, u16 key);
u16 PadUtils_GetCurButton(Input* input);
u16 PadUtils_GetPressButton(Input* input);
s8 PadUtils_GetCurX(Input* input);
s8 PadUtils_GetCurY(Input* input);
void PadUtils_SetRelXY(Input* input, s32 x, s32 y);
s8 PadUtils_GetRelXImpl(Input* input);
s8 PadUtils_GetRelYImpl(Input* input);
s8 PadUtils_GetRelX(Input* input);
s8 PadUtils_GetRelY(Input* input);
void PadUtils_UpdateRelXY(Input* input);
s32 PadSetup_Init(OSMesgQueue* mq, u8* outMask, OSContStatus* status);
f32 Math_FTanF(f32 x);
f32 Math_FFloorF(f32 x);
f32 Math_FCeilF(f32 x);
f32 Math_FRoundF(f32 x);
f32 Math_FNearbyIntF(f32 x);
f32 Math_FTruncF(f32 x);
f32 Math_FAtanF(f32 x);
f32 Math_FAtan2F(f32 y, f32 x);
f32 Math_FAsinF(f32 x);
f32 Math_FAcosF(f32 x);
f32 ceilf(f32 x);
f32 truncf(f32 x);
f32 roundf(f32 x);
f32 nearbyintf(f32 x);
void SystemArena_CheckPointer(void* ptr, u32 size, const char* name, const char* action);
void* SystemArena_Malloc(u32 size);
void* SystemArena_MallocDebug(u32 size, const char* file, s32 line);
void* SystemArena_MallocR(u32 size);
void* SystemArena_MallocRDebug(u32 size, const char* file, s32 line);
void* SystemArena_Realloc(void* ptr, u32 newSize);
void* SystemArena_ReallocDebug(void* ptr, u32 newSize, const char* file, s32 line);
void SystemArena_Free(void* ptr);
void SystemArena_FreeDebug(void* ptr, const char* file, s32 line);
void* SystemArena_Calloc(u32 num, u32 size);
void SystemArena_Display();
void SystemArena_GetSizes(u32* outMaxFree, u32* outFree, u32* outAlloc);
void SystemArena_Check();
void SystemArena_Init(void* start, u32 size);
void SystemArena_Cleanup();
u8 SystemArena_IsInitalized();
u32 Rand_Next(void);
void Rand_Seed(u32 seed);
f32 Rand_ZeroOne(void);
f32 Rand_Centered(void);
void Rand_Seed_Variable(u32* rndNum, u32 seed);
u32 Rand_Next_Variable(u32* rndNum);
f32 Rand_ZeroOne_Variable(u32* rndNum);
f32 Rand_Centered_Variable(u32* rndNum);
u32 ArenaImpl_GetFillAllocBlock(Arena* arena);
u32 ArenaImpl_GetFillFreeBlock(Arena* arena);
u32 ArenaImpl_GetCheckFreeBlock(Arena* arena);
void ArenaImpl_SetFillAllocBlock(Arena* arena);
void ArenaImpl_SetFillFreeBlock(Arena* arena);
void ArenaImpl_SetCheckFreeBlock(Arena* arena);
void ArenaImpl_UnsetFillAllocBlock(Arena* arena);
void ArenaImpl_UnsetFillFreeBlock(Arena* arena);
void ArenaImpl_UnsetCheckFreeBlock(Arena* arena);
void ArenaImpl_SetDebugInfo(ArenaNode* node, const char* file, s32 line, Arena* arena);
void ArenaImpl_LockInit(Arena* arena);
void ArenaImpl_Lock(Arena* arena);
void ArenaImpl_Unlock(Arena* arena);
ArenaNode* ArenaImpl_GetNextBlock(ArenaNode* node);
ArenaNode* ArenaImpl_GetPrevBlock(ArenaNode* node);
ArenaNode* ArenaImpl_GetLastBlock(Arena* arena);
void __osMallocInit(Arena* arena, void* start, u32 size);
void __osMallocAddBlock(Arena* arena, void* start, s32 size);
void ArenaImpl_RemoveAllBlocks(Arena* arena);
void __osMallocCleanup(Arena* arena);
u8 __osMallocIsInitalized(Arena* arena);
void __osMalloc_FreeBlockTest(Arena* arena, ArenaNode* node);
void* __osMalloc_NoLockDebug(Arena* arena, u32 size, const char* file, s32 line);
void* __osMallocDebug(Arena* arena, u32 size, const char* file, s32 line);
void* __osMallocRDebug(Arena* arena, u32 size, const char* file, s32 line);
void* __osMalloc_NoLock(Arena* arena, u32 size);
void* __osMalloc(Arena* arena, u32 size);
void* __osMallocR(Arena* arena, u32 size);
void __osFree_NoLock(Arena* arena, void* ptr);
void __osFree(Arena* arena, void* ptr);
void __osFree_NoLockDebug(Arena* arena, void* ptr, const char* file, s32 line);
void __osFreeDebug(Arena* arena, void* ptr, const char* file, s32 line);
void* __osRealloc(Arena* arena, void* ptr, u32 newSize);
void* __osReallocDebug(Arena* arena, void* ptr, u32 newSize, const char* file, s32 line);
void ArenaImpl_GetSizes(Arena* arena, u32* outMaxFree, u32* outFree, u32* outAlloc);
void __osDisplayArena(Arena* arena);
void ArenaImpl_FaultClient(Arena* arena);
u32 __osCheckArena(Arena* arena);
u8 func_800FF334(Arena* arena);
void PrintUtils_VPrintf(char** arg0, const char* fmt, va_list args);
void PrintUtils_Printf(void* arg0, const char* fmt, ...);
void Sleep_Cycles(OSTime cycles);
void Sleep_Nsec(u32 nsec);
void Sleep_Usec(u32 usec);
void Sleep_Msec(u32 ms);
void Sleep_Sec(u32 sec);
void JpegUtils_ProcessQuantizationTable(u8* dqt, JpegQuantizationTable* qt, u8 count);
s32 JpegUtils_ParseHuffmanCodesLengths(u8* ptr, u8* codesLengths);
s32 JpegUtils_GetHuffmanCodes(u8* codesLengths, u16* codes);
s32 JpegUtils_SetHuffmanTable(u8* data, JpegHuffmanTable* ht, u16* codes);
u32 JpegUtils_ProcessHuffmanTableImpl(u8* data, JpegHuffmanTable* ht, u8* codesLengths, u16* codes, u8 isAc);
u32 JpegUtils_ProcessHuffmanTable(u8* dht, JpegHuffmanTable* ht, u8* codesLengths, u16* codes, u8 count);
void JpegUtils_SetHuffmanTableOld(u8* data, JpegHuffmanTableOld* ht, u8* codesLengths, u16* codes, s16 count, u8 isAc);
u32 JpegUtils_ProcessHuffmanTableImplOld(u8* dht, JpegHuffmanTableOld* ht, u8* codesLengths, u16* codes);
s32 JpegDecoder_Decode(JpegDecoder* decoder, u16* mcuBuff, s32 count, u8 isFollowing, JpegDecoderState* state);
s32 JpegDecoder_ProcessMcu(JpegHuffmanTable* hTable0, JpegHuffmanTable* hTable1, s16* mcu, s16* unk);
s32 JpegDecoder_ParseNextSymbol(JpegHuffmanTable* hTable, s16* outCoeff, u8* outZeroCount);
u16 JpegDecoder_ReadBits(u8 len);
s32 osPfsFreeBlocks(OSPfs* pfs, s32* leftoverBytes);
void guScale(Mtx* m, f32 x, f32 y, f32 z);
f32 sinf(f32);
s16 sins(u16);
OSTask* _VirtualToPhysicalTask(OSTask* intp);
void osSpTaskLoad(OSTask* task);
void osSpTaskStartGo(OSTask* task);
s32 osSetRumble(OSPfs* pfs, u32 vibrate);
void osSetUpMempakWrite(s32 channel, OSPifRam* buf);
s32 osProbeRumblePak(OSMesgQueue* ctrlrqueue, OSPfs* pfs, u32 channel);
void __osSiCreateAccessQueue();
void __osSiGetAccess();
void __osSiRelAccess();
s32 osContInit(OSMesgQueue* mq, u8* ctl_present_bitfield, OSContStatus* status);
void __osContGetInitData(u8* ctl_present_bitfield, OSContStatus* status);
void __osPackRequestData(u8 poll);
s32 osContStartReadData(OSMesgQueue* mq);
void osContGetReadData(OSContPad* pad);
void __osPackReadData();
void guPerspectiveF(f32 mf[4][4], u16* perspNorm, f32 fovy, f32 aspect, f32 near, f32 far, f32 scale);
void guPerspective(Mtx* m, u16* perspNorm, f32 fovy, f32 aspect, f32 near, f32 far, f32 scale);
s32 __osSpRawStartDma(s32 direction, void* devAddr, void* dramAddr, u32 size);
s32 __osSiRawStartDma(s32 dir, void* addr);
void osSpTaskYield(void);
s32 __osPfsGetNextPage(OSPfs* pfs, u8* bank, __OSInode* inode, __OSInodeUnit* page);
s32 osPfsReadWriteFile(OSPfs* pfs, s32 fileNo, u8 flag, s32 offset, s32 size, u8* data);
s32 __osPfsGetStatus(OSMesgQueue* queue, s32 channel);
void __osPfsRequestOneChannel(s32 channel, u8 poll);
void __osPfsGetOneChannelData(s32 channel, OSContStatus* contData);
void guMtxIdentF(f32 mf[4][4]);
void guLookAtF(f32 mf[4][4], f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt, f32 xUp, f32 yUp, f32 zUp);
void guLookAt(Mtx*, f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt, f32 xUp, f32 yUp, f32 zUp);
s32 osPfsAllocateFile(OSPfs* pfs, u16 companyCode, u32 gameCode, u8* gameName, u8* extName, s32 length, s32* fileNo);
s32 __osPfsDeclearPage(OSPfs* pfs, __OSInode* inode, s32 fileSizeInPages, s32* startPage, u8 bank, s32* decleared,
                       s32* finalPage);
s32 osStopTimer(OSTimer* timer);
u16 __osSumcalc(u8* ptr, s32 length);
s32 __osIdCheckSum(u16* ptr, u16* csum, u16* icsum);
s32 __osRepairPackId(OSPfs* pfs, __OSPackId* badid, __OSPackId* newid);
s32 __osCheckPackId(OSPfs* pfs, __OSPackId* temp);
s32 __osGetId(OSPfs* pfs);
s32 __osCheckId(OSPfs* pfs);
s32 __osPfsRWInode(OSPfs* pfs, __OSInode* inode, u8 flag, u8 bank);
void guMtxL2F(MtxF* m1, Mtx* m2);
s32 osPfsFindFile(OSPfs* pfs, u16 companyCode, u32 gameCode, u8* gameName, u8* extName, s32* fileNo);
s32 osAfterPreNMI(void);
s32 osContStartQuery(OSMesgQueue* mq);
void osContGetQuery(OSContStatus* data);
void guLookAtHiliteF(f32 mf[4][4], LookAt* l, Hilite* h, f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt,
                     f32 xUp, f32 yUp, f32 zUp, f32 xl1, f32 yl1, f32 zl1, f32 xl2, f32 yl2, f32 zl2, s32 hiliteWidth,
                     s32 hiliteHeight);
void guLookAtHilite(Mtx* m, LookAt* l, Hilite* h, f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt, f32 xUp,
                    f32 yUp, f32 zUp, f32 xl1, f32 yl1, f32 zl1, f32 xl2, f32 yl2, f32 zl2, s32 hiliteWidth,
                    s32 hiliteHeight);
u32 __osSpDeviceBusy();
void guMtxIdent(f32 m[4][4]);
void guPositionF(f32 mf[4][4], f32 rot, f32 pitch, f32 yaw, f32 scale, f32 x, f32 y, f32 z);
void guPosition(Mtx*, f32, f32, f32, f32, f32, f32, f32);
OSYieldResult osSpTaskYielded(OSTask* task);
void guRotateF(f32 m[4][4], f32 a, f32 x, f32 y, f32 z);
void guRotate(Mtx*, f32 angle, f32 x, f32 y, f32 z);
s32 osAiSetFrequency(u32 frequency);
OSThread* __osGetActiveQueue();
void guNormalize(f32* x, f32* y, f32* z);
u32 osDpGetStatus(void);
void osDpSetStatus(u32 status);
s32 osPfsDeleteFile(OSPfs* pfs, u16 companyCode, u32 gameCode, u8* gameName, u8* extName);
s32 __osPfsReleasePages(OSPfs* pfs, __OSInode* inode, u8 initialPage, u8 bank, __OSInodeUnit* finalPage);
void guOrthoF(f32[4][4], f32, f32, f32, f32, f32, f32, f32);
void guOrtho(Mtx*, f32, f32, f32, f32, f32, f32, f32);
f32 cosf(f32);
s16 coss(u16);
void osViSetEvent(OSMesgQueue* mq, OSMesg m, u32 retraceCount);
s32 osPfsIsPlug(OSMesgQueue* mq, u8* pattern);
void __osPfsRequestData(u8 poll);
void __osPfsGetInitData(u8* pattern, OSContStatus* contData);
void guS2DInitBg(uObjBg* bg);
s32 __osPfsSelectBank(OSPfs* pfs, u8 bank);
s32 osContSetCh(u8 ch);
s32 osPfsFileState(OSPfs* pfs, s32 fileNo, OSPfsState* state);
s32 osPfsInitPak(OSMesgQueue* mq, OSPfs* pfs, s32 channel);
s32 __osPfsCheckRamArea(OSPfs* pfs);
s32 osPfsChecker(OSPfs* pfs);
s32 func_80105788(OSPfs* pfs, __OSInodeCache* cache);
s32 func_80105A60(OSPfs* pfs, __OSInodeUnit fpage, __OSInodeCache* cache);
u32 osAiGetLength(void);
void guTranslate(Mtx* m, f32 x, f32 y, f32 z);
s32 __osContRamWrite(OSMesgQueue* mq, s32 channel, u16 address, u8* buffer, s32 force);
s32 __osContRamRead(OSMesgQueue* ctrlrqueue, s32 channel, u16 addr, u8* data);
u8 __osContAddressCrc(u16 addr);
u8 __osContDataCrc(u8* data);
s32 osSetTimer(OSTimer* timer, OSTime countdown, OSTime interval, OSMesgQueue* mq, OSMesg msg);
u32 __osSpGetStatus();
void __osSpSetStatus(u32 status);
void osWritebackDCacheAll(void);
OSThread* __osGetCurrFaultedThread();
void guMtxF2L(MtxF* m1, Mtx* m2);
u32* osViGetCurrentFramebuffer(void);
s32 __osSpSetPc(void* pc);
f32 absf(f32);
void* func_80106860(void* ptr, s32 val, size_t size);
void* func_801068B0(void* dst, void* src, size_t size);
u8 func_80106BC8(GlobalContext* globalCtx);
void func_80106CCC(GlobalContext*);
void func_8010B680(GlobalContext*, u16 textID, Actor* actor);
void func_8010B720(GlobalContext* globalCtx, u16 textId);
void func_8010BD58(GlobalContext* globalCtx, u16 arg1);
void func_8010BD88(GlobalContext* globalCtx, u16 arg1);
u8 func_8010BDBC(MessageContext* msgCtx);
void func_8011040C(void);
void func_80110990(GlobalContext* globalCtx);
void func_801109B0(GlobalContext* globalCtx);
void func_80110F68(GlobalContext* globalCtx);
void func_80112098(GlobalContext* globalCtx);
void Title_Init(GameState* thisx);
void Title_Destroy(GameState* thisx);
void Select_Init(GameState* thisx);
void Select_Destroy(GameState* thisx);
void Opening_Init(GameState* thisx);
void Opening_Destroy(GameState* thisx);
void func_80811A20(GameState* thisx);
void func_80811A18(GameState* thisx);
void func_80823994(PauseContext*, f32, f32, f32);
void func_800949A8(GraphicsContext*);
void func_8082409C(GlobalContext*, GraphicsContext*);
void func_80820434(GlobalContext*, GraphicsContext*);
void func_80821C10(GlobalContext*);
void func_80825C14(GlobalContext*);
void func_808161AC(GlobalContext*);
extern u8 _bootSegmentStart[]; extern u8 _bootSegmentEnd[];
extern u8 _bootSegmentRomStart[]; extern u8 _bootSegmentRomEnd[];
extern u8 _dmadataSegmentStart[]; extern u8 _dmadataSegmentEnd[];
extern u8 _dmadataSegmentRomStart[]; extern u8 _dmadataSegmentRomEnd[];
extern u8 _AudiobankSegmentRomStart[]; extern u8 _AudiobankSegmentRomEnd[];
extern u8 _AudioseqSegmentRomStart[]; extern u8 _AudioseqSegmentRomEnd[];
extern u8 _AudiotableSegmentRomStart[]; extern u8 _AudiotableSegmentRomEnd[];
extern u8 _link_animetionSegmentRomStart[]; extern u8 _link_animetionSegmentRomEnd[];
extern u8 _icon_item_staticSegmentRomStart[]; extern u8 _icon_item_staticSegmentRomEnd[];
extern u8 _icon_item_24_staticSegmentRomStart[]; extern u8 _icon_item_24_staticSegmentRomEnd[];
extern u8 _icon_item_field_staticSegmentRomStart[]; extern u8 _icon_item_field_staticSegmentRomEnd[];
extern u8 _icon_item_dungeon_staticSegmentRomStart[]; extern u8 _icon_item_dungeon_staticSegmentRomEnd[];
extern u8 _icon_item_gameover_staticSegmentRomStart[]; extern u8 _icon_item_gameover_staticSegmentRomEnd[];
extern u8 _icon_item_nes_staticSegmentRomStart[]; extern u8 _icon_item_nes_staticSegmentRomEnd[];
extern u8 _icon_item_ger_staticSegmentRomStart[]; extern u8 _icon_item_ger_staticSegmentRomEnd[];
extern u8 _icon_item_fra_staticSegmentRomStart[]; extern u8 _icon_item_fra_staticSegmentRomEnd[];
extern u8 _item_name_staticSegmentRomStart[]; extern u8 _item_name_staticSegmentRomEnd[];
extern u8 _map_name_staticSegmentRomStart[]; extern u8 _map_name_staticSegmentRomEnd[];
extern u8 _do_action_staticSegmentRomStart[]; extern u8 _do_action_staticSegmentRomEnd[];
extern u8 _message_staticSegmentRomStart[]; extern u8 _message_staticSegmentRomEnd[];
extern u8 _message_texture_staticSegmentRomStart[]; extern u8 _message_texture_staticSegmentRomEnd[];
extern u8 _nes_font_staticSegmentRomStart[]; extern u8 _nes_font_staticSegmentRomEnd[];
extern u8 _nes_message_data_staticSegmentRomStart[]; extern u8 _nes_message_data_staticSegmentRomEnd[];
extern u8 _ger_message_data_staticSegmentRomStart[]; extern u8 _ger_message_data_staticSegmentRomEnd[];
extern u8 _fra_message_data_staticSegmentRomStart[]; extern u8 _fra_message_data_staticSegmentRomEnd[];
extern u8 _staff_message_data_staticSegmentRomStart[]; extern u8 _staff_message_data_staticSegmentRomEnd[];
extern u8 _map_grand_staticSegmentRomStart[]; extern u8 _map_grand_staticSegmentRomEnd[];
extern u8 _map_i_staticSegmentRomStart[]; extern u8 _map_i_staticSegmentRomEnd[];
extern u8 _map_48x85_staticSegmentRomStart[]; extern u8 _map_48x85_staticSegmentRomEnd[];
extern u8 _codeSegmentStart[]; extern u8 _codeSegmentEnd[];
extern u8 _codeSegmentRomStart[]; extern u8 _codeSegmentRomEnd[];
extern u8 _codeSegmentBssStart[]; extern u8 _codeSegmentBssEnd[];
extern u8 _ovl_titleSegmentStart[]; extern u8 _ovl_titleSegmentEnd[]; extern u8 _ovl_titleSegmentRomStart[]; extern u8 _ovl_titleSegmentRomEnd[];
extern u8 _ovl_selectSegmentStart[]; extern u8 _ovl_selectSegmentEnd[]; extern u8 _ovl_selectSegmentRomStart[]; extern u8 _ovl_selectSegmentRomEnd[];
extern u8 _ovl_openingSegmentStart[]; extern u8 _ovl_openingSegmentEnd[]; extern u8 _ovl_openingSegmentRomStart[]; extern u8 _ovl_openingSegmentRomEnd[];
extern u8 _ovl_file_chooseSegmentStart[]; extern u8 _ovl_file_chooseSegmentEnd[]; extern u8 _ovl_file_chooseSegmentRomStart[]; extern u8 _ovl_file_chooseSegmentRomEnd[];
extern u8 _ovl_kaleido_scopeSegmentStart[]; extern u8 _ovl_kaleido_scopeSegmentEnd[]; extern u8 _ovl_kaleido_scopeSegmentRomStart[]; extern u8 _ovl_kaleido_scopeSegmentRomEnd[];
extern u8 _ovl_player_actorSegmentStart[]; extern u8 _ovl_player_actorSegmentEnd[]; extern u8 _ovl_player_actorSegmentRomStart[]; extern u8 _ovl_player_actorSegmentRomEnd[];
extern u8 _ovl_map_mark_dataSegmentStart[]; extern u8 _ovl_map_mark_dataSegmentEnd[]; extern u8 _ovl_map_mark_dataSegmentRomStart[]; extern u8 _ovl_map_mark_dataSegmentRomEnd[];
extern u8 _ovl_Effect_Ss_DustSegmentStart[]; extern u8 _ovl_Effect_Ss_DustSegmentEnd[]; extern u8 _ovl_Effect_Ss_DustSegmentRomStart[]; extern u8 _ovl_Effect_Ss_DustSegmentRomEnd[];
extern u8 _ovl_Effect_Ss_KiraKiraSegmentStart[]; extern u8 _ovl_Effect_Ss_KiraKiraSegmentEnd[]; extern u8 _ovl_Effect_Ss_KiraKiraSegmentRomStart[]; extern u8 _ovl_Effect_Ss_KiraKiraSegmentRomEnd[];
extern u8 _ovl_Effect_Ss_BombSegmentStart[]; extern u8 _ovl_Effect_Ss_BombSegmentEnd[]; extern u8 _ovl_Effect_Ss_BombSegmentRomStart[]; extern u8 _ovl_Effect_Ss_BombSegmentRomEnd[];
extern u8 _ovl_Effect_Ss_Bomb2SegmentStart[]; extern u8 _ovl_Effect_Ss_Bomb2SegmentEnd[]; extern u8 _ovl_Effect_Ss_Bomb2SegmentRomStart[]; extern u8 _ovl_Effect_Ss_Bomb2SegmentRomEnd[];
extern u8 _ovl_Effect_Ss_BlastSegmentStart[]; extern u8 _ovl_Effect_Ss_BlastSegmentEnd[]; extern u8 _ovl_Effect_Ss_BlastSegmentRomStart[]; extern u8 _ovl_Effect_Ss_BlastSegmentRomEnd[];
extern u8 _ovl_Effect_Ss_G_SpkSegmentStart[]; extern u8 _ovl_Effect_Ss_G_SpkSegmentEnd[]; extern u8 _ovl_Effect_Ss_G_SpkSegmentRomStart[]; extern u8 _ovl_Effect_Ss_G_SpkSegmentRomEnd[];
extern u8 _ovl_Effect_Ss_D_FireSegmentStart[]; extern u8 _ovl_Effect_Ss_D_FireSegmentEnd[]; extern u8 _ovl_Effect_Ss_D_FireSegmentRomStart[]; extern u8 _ovl_Effect_Ss_D_FireSegmentRomEnd[];
extern u8 _ovl_Effect_Ss_BubbleSegmentStart[]; extern u8 _ovl_Effect_Ss_BubbleSegmentEnd[]; extern u8 _ovl_Effect_Ss_BubbleSegmentRomStart[]; extern u8 _ovl_Effect_Ss_BubbleSegmentRomEnd[];
extern u8 _ovl_Effect_Ss_G_RippleSegmentStart[]; extern u8 _ovl_Effect_Ss_G_RippleSegmentEnd[]; extern u8 _ovl_Effect_Ss_G_RippleSegmentRomStart[]; extern u8 _ovl_Effect_Ss_G_RippleSegmentRomEnd[];
extern u8 _ovl_Effect_Ss_G_SplashSegmentStart[]; extern u8 _ovl_Effect_Ss_G_SplashSegmentEnd[]; extern u8 _ovl_Effect_Ss_G_SplashSegmentRomStart[]; extern u8 _ovl_Effect_Ss_G_SplashSegmentRomEnd[];
extern u8 _ovl_Effect_Ss_G_MagmaSegmentStart[]; extern u8 _ovl_Effect_Ss_G_MagmaSegmentEnd[]; extern u8 _ovl_Effect_Ss_G_MagmaSegmentRomStart[]; extern u8 _ovl_Effect_Ss_G_MagmaSegmentRomEnd[];
extern u8 _ovl_Effect_Ss_G_FireSegmentStart[]; extern u8 _ovl_Effect_Ss_G_FireSegmentEnd[]; extern u8 _ovl_Effect_Ss_G_FireSegmentRomStart[]; extern u8 _ovl_Effect_Ss_G_FireSegmentRomEnd[];
extern u8 _ovl_Effect_Ss_LightningSegmentStart[]; extern u8 _ovl_Effect_Ss_LightningSegmentEnd[]; extern u8 _ovl_Effect_Ss_LightningSegmentRomStart[]; extern u8 _ovl_Effect_Ss_LightningSegmentRomEnd[];
extern u8 _ovl_Effect_Ss_Dt_BubbleSegmentStart[]; extern u8 _ovl_Effect_Ss_Dt_BubbleSegmentEnd[]; extern u8 _ovl_Effect_Ss_Dt_BubbleSegmentRomStart[]; extern u8 _ovl_Effect_Ss_Dt_BubbleSegmentRomEnd[];
extern u8 _ovl_Effect_Ss_HahenSegmentStart[]; extern u8 _ovl_Effect_Ss_HahenSegmentEnd[]; extern u8 _ovl_Effect_Ss_HahenSegmentRomStart[]; extern u8 _ovl_Effect_Ss_HahenSegmentRomEnd[];
extern u8 _ovl_Effect_Ss_StickSegmentStart[]; extern u8 _ovl_Effect_Ss_StickSegmentEnd[]; extern u8 _ovl_Effect_Ss_StickSegmentRomStart[]; extern u8 _ovl_Effect_Ss_StickSegmentRomEnd[];
extern u8 _ovl_Effect_Ss_SibukiSegmentStart[]; extern u8 _ovl_Effect_Ss_SibukiSegmentEnd[]; extern u8 _ovl_Effect_Ss_SibukiSegmentRomStart[]; extern u8 _ovl_Effect_Ss_SibukiSegmentRomEnd[];
extern u8 _ovl_Effect_Ss_Sibuki2SegmentStart[]; extern u8 _ovl_Effect_Ss_Sibuki2SegmentEnd[]; extern u8 _ovl_Effect_Ss_Sibuki2SegmentRomStart[]; extern u8 _ovl_Effect_Ss_Sibuki2SegmentRomEnd[];
extern u8 _ovl_Effect_Ss_G_Magma2SegmentStart[]; extern u8 _ovl_Effect_Ss_G_Magma2SegmentEnd[]; extern u8 _ovl_Effect_Ss_G_Magma2SegmentRomStart[]; extern u8 _ovl_Effect_Ss_G_Magma2SegmentRomEnd[];
extern u8 _ovl_Effect_Ss_Stone1SegmentStart[]; extern u8 _ovl_Effect_Ss_Stone1SegmentEnd[]; extern u8 _ovl_Effect_Ss_Stone1SegmentRomStart[]; extern u8 _ovl_Effect_Ss_Stone1SegmentRomEnd[];
extern u8 _ovl_Effect_Ss_HitMarkSegmentStart[]; extern u8 _ovl_Effect_Ss_HitMarkSegmentEnd[]; extern u8 _ovl_Effect_Ss_HitMarkSegmentRomStart[]; extern u8 _ovl_Effect_Ss_HitMarkSegmentRomEnd[];
extern u8 _ovl_Effect_Ss_Fhg_FlashSegmentStart[]; extern u8 _ovl_Effect_Ss_Fhg_FlashSegmentEnd[]; extern u8 _ovl_Effect_Ss_Fhg_FlashSegmentRomStart[]; extern u8 _ovl_Effect_Ss_Fhg_FlashSegmentRomEnd[];
extern u8 _ovl_Effect_Ss_K_FireSegmentStart[]; extern u8 _ovl_Effect_Ss_K_FireSegmentEnd[]; extern u8 _ovl_Effect_Ss_K_FireSegmentRomStart[]; extern u8 _ovl_Effect_Ss_K_FireSegmentRomEnd[];
extern u8 _ovl_Effect_Ss_Solder_Srch_BallSegmentStart[]; extern u8 _ovl_Effect_Ss_Solder_Srch_BallSegmentEnd[]; extern u8 _ovl_Effect_Ss_Solder_Srch_BallSegmentRomStart[]; extern u8 _ovl_Effect_Ss_Solder_Srch_BallSegmentRomEnd[];
extern u8 _ovl_Effect_Ss_KakeraSegmentStart[]; extern u8 _ovl_Effect_Ss_KakeraSegmentEnd[]; extern u8 _ovl_Effect_Ss_KakeraSegmentRomStart[]; extern u8 _ovl_Effect_Ss_KakeraSegmentRomEnd[];
extern u8 _ovl_Effect_Ss_Ice_PieceSegmentStart[]; extern u8 _ovl_Effect_Ss_Ice_PieceSegmentEnd[]; extern u8 _ovl_Effect_Ss_Ice_PieceSegmentRomStart[]; extern u8 _ovl_Effect_Ss_Ice_PieceSegmentRomEnd[];
extern u8 _ovl_Effect_Ss_En_IceSegmentStart[]; extern u8 _ovl_Effect_Ss_En_IceSegmentEnd[]; extern u8 _ovl_Effect_Ss_En_IceSegmentRomStart[]; extern u8 _ovl_Effect_Ss_En_IceSegmentRomEnd[];
extern u8 _ovl_Effect_Ss_Fire_TailSegmentStart[]; extern u8 _ovl_Effect_Ss_Fire_TailSegmentEnd[]; extern u8 _ovl_Effect_Ss_Fire_TailSegmentRomStart[]; extern u8 _ovl_Effect_Ss_Fire_TailSegmentRomEnd[];
extern u8 _ovl_Effect_Ss_En_FireSegmentStart[]; extern u8 _ovl_Effect_Ss_En_FireSegmentEnd[]; extern u8 _ovl_Effect_Ss_En_FireSegmentRomStart[]; extern u8 _ovl_Effect_Ss_En_FireSegmentRomEnd[];
extern u8 _ovl_Effect_Ss_ExtraSegmentStart[]; extern u8 _ovl_Effect_Ss_ExtraSegmentEnd[]; extern u8 _ovl_Effect_Ss_ExtraSegmentRomStart[]; extern u8 _ovl_Effect_Ss_ExtraSegmentRomEnd[];
extern u8 _ovl_Effect_Ss_FcircleSegmentStart[]; extern u8 _ovl_Effect_Ss_FcircleSegmentEnd[]; extern u8 _ovl_Effect_Ss_FcircleSegmentRomStart[]; extern u8 _ovl_Effect_Ss_FcircleSegmentRomEnd[];
extern u8 _ovl_Effect_Ss_Dead_DbSegmentStart[]; extern u8 _ovl_Effect_Ss_Dead_DbSegmentEnd[]; extern u8 _ovl_Effect_Ss_Dead_DbSegmentRomStart[]; extern u8 _ovl_Effect_Ss_Dead_DbSegmentRomEnd[];
extern u8 _ovl_Effect_Ss_Dead_DdSegmentStart[]; extern u8 _ovl_Effect_Ss_Dead_DdSegmentEnd[]; extern u8 _ovl_Effect_Ss_Dead_DdSegmentRomStart[]; extern u8 _ovl_Effect_Ss_Dead_DdSegmentRomEnd[];
extern u8 _ovl_Effect_Ss_Dead_DsSegmentStart[]; extern u8 _ovl_Effect_Ss_Dead_DsSegmentEnd[]; extern u8 _ovl_Effect_Ss_Dead_DsSegmentRomStart[]; extern u8 _ovl_Effect_Ss_Dead_DsSegmentRomEnd[];
extern u8 _ovl_Effect_Ss_Dead_SoundSegmentStart[]; extern u8 _ovl_Effect_Ss_Dead_SoundSegmentEnd[]; extern u8 _ovl_Effect_Ss_Dead_SoundSegmentRomStart[]; extern u8 _ovl_Effect_Ss_Dead_SoundSegmentRomEnd[];
extern u8 _ovl_Effect_Ss_Ice_SmokeSegmentStart[]; extern u8 _ovl_Effect_Ss_Ice_SmokeSegmentEnd[]; extern u8 _ovl_Effect_Ss_Ice_SmokeSegmentRomStart[]; extern u8 _ovl_Effect_Ss_Ice_SmokeSegmentRomEnd[];
extern u8 _ovl_En_TestSegmentStart[]; extern u8 _ovl_En_TestSegmentEnd[]; extern u8 _ovl_En_TestSegmentRomStart[]; extern u8 _ovl_En_TestSegmentRomEnd[];
extern u8 _ovl_En_GirlASegmentStart[]; extern u8 _ovl_En_GirlASegmentEnd[]; extern u8 _ovl_En_GirlASegmentRomStart[]; extern u8 _ovl_En_GirlASegmentRomEnd[];
extern u8 _ovl_En_PartSegmentStart[]; extern u8 _ovl_En_PartSegmentEnd[]; extern u8 _ovl_En_PartSegmentRomStart[]; extern u8 _ovl_En_PartSegmentRomEnd[];
extern u8 _ovl_En_LightSegmentStart[]; extern u8 _ovl_En_LightSegmentEnd[]; extern u8 _ovl_En_LightSegmentRomStart[]; extern u8 _ovl_En_LightSegmentRomEnd[];
extern u8 _ovl_En_DoorSegmentStart[]; extern u8 _ovl_En_DoorSegmentEnd[]; extern u8 _ovl_En_DoorSegmentRomStart[]; extern u8 _ovl_En_DoorSegmentRomEnd[];
extern u8 _ovl_En_BoxSegmentStart[]; extern u8 _ovl_En_BoxSegmentEnd[]; extern u8 _ovl_En_BoxSegmentRomStart[]; extern u8 _ovl_En_BoxSegmentRomEnd[];
extern u8 _ovl_Bg_Dy_YoseizoSegmentStart[]; extern u8 _ovl_Bg_Dy_YoseizoSegmentEnd[]; extern u8 _ovl_Bg_Dy_YoseizoSegmentRomStart[]; extern u8 _ovl_Bg_Dy_YoseizoSegmentRomEnd[];
extern u8 _ovl_Bg_Hidan_FirewallSegmentStart[]; extern u8 _ovl_Bg_Hidan_FirewallSegmentEnd[]; extern u8 _ovl_Bg_Hidan_FirewallSegmentRomStart[]; extern u8 _ovl_Bg_Hidan_FirewallSegmentRomEnd[];
extern u8 _ovl_En_PohSegmentStart[]; extern u8 _ovl_En_PohSegmentEnd[]; extern u8 _ovl_En_PohSegmentRomStart[]; extern u8 _ovl_En_PohSegmentRomEnd[];
extern u8 _ovl_En_OkutaSegmentStart[]; extern u8 _ovl_En_OkutaSegmentEnd[]; extern u8 _ovl_En_OkutaSegmentRomStart[]; extern u8 _ovl_En_OkutaSegmentRomEnd[];
extern u8 _ovl_Bg_Ydan_SpSegmentStart[]; extern u8 _ovl_Bg_Ydan_SpSegmentEnd[]; extern u8 _ovl_Bg_Ydan_SpSegmentRomStart[]; extern u8 _ovl_Bg_Ydan_SpSegmentRomEnd[];
extern u8 _ovl_En_BomSegmentStart[]; extern u8 _ovl_En_BomSegmentEnd[]; extern u8 _ovl_En_BomSegmentRomStart[]; extern u8 _ovl_En_BomSegmentRomEnd[];
extern u8 _ovl_En_WallmasSegmentStart[]; extern u8 _ovl_En_WallmasSegmentEnd[]; extern u8 _ovl_En_WallmasSegmentRomStart[]; extern u8 _ovl_En_WallmasSegmentRomEnd[];
extern u8 _ovl_En_DodongoSegmentStart[]; extern u8 _ovl_En_DodongoSegmentEnd[]; extern u8 _ovl_En_DodongoSegmentRomStart[]; extern u8 _ovl_En_DodongoSegmentRomEnd[];
extern u8 _ovl_En_FireflySegmentStart[]; extern u8 _ovl_En_FireflySegmentEnd[]; extern u8 _ovl_En_FireflySegmentRomStart[]; extern u8 _ovl_En_FireflySegmentRomEnd[];
extern u8 _ovl_En_HorseSegmentStart[]; extern u8 _ovl_En_HorseSegmentEnd[]; extern u8 _ovl_En_HorseSegmentRomStart[]; extern u8 _ovl_En_HorseSegmentRomEnd[];
extern u8 _ovl_En_Item00SegmentStart[]; extern u8 _ovl_En_Item00SegmentEnd[]; extern u8 _ovl_En_Item00SegmentRomStart[]; extern u8 _ovl_En_Item00SegmentRomEnd[];
extern u8 _ovl_En_ArrowSegmentStart[]; extern u8 _ovl_En_ArrowSegmentEnd[]; extern u8 _ovl_En_ArrowSegmentRomStart[]; extern u8 _ovl_En_ArrowSegmentRomEnd[];
extern u8 _ovl_En_ElfSegmentStart[]; extern u8 _ovl_En_ElfSegmentEnd[]; extern u8 _ovl_En_ElfSegmentRomStart[]; extern u8 _ovl_En_ElfSegmentRomEnd[];
extern u8 _ovl_En_NiwSegmentStart[]; extern u8 _ovl_En_NiwSegmentEnd[]; extern u8 _ovl_En_NiwSegmentRomStart[]; extern u8 _ovl_En_NiwSegmentRomEnd[];
extern u8 _ovl_En_TiteSegmentStart[]; extern u8 _ovl_En_TiteSegmentEnd[]; extern u8 _ovl_En_TiteSegmentRomStart[]; extern u8 _ovl_En_TiteSegmentRomEnd[];
extern u8 _ovl_En_ReebaSegmentStart[]; extern u8 _ovl_En_ReebaSegmentEnd[]; extern u8 _ovl_En_ReebaSegmentRomStart[]; extern u8 _ovl_En_ReebaSegmentRomEnd[];
extern u8 _ovl_En_PeehatSegmentStart[]; extern u8 _ovl_En_PeehatSegmentEnd[]; extern u8 _ovl_En_PeehatSegmentRomStart[]; extern u8 _ovl_En_PeehatSegmentRomEnd[];
extern u8 _ovl_En_ButteSegmentStart[]; extern u8 _ovl_En_ButteSegmentEnd[]; extern u8 _ovl_En_ButteSegmentRomStart[]; extern u8 _ovl_En_ButteSegmentRomEnd[];
extern u8 _ovl_En_InsectSegmentStart[]; extern u8 _ovl_En_InsectSegmentEnd[]; extern u8 _ovl_En_InsectSegmentRomStart[]; extern u8 _ovl_En_InsectSegmentRomEnd[];
extern u8 _ovl_En_FishSegmentStart[]; extern u8 _ovl_En_FishSegmentEnd[]; extern u8 _ovl_En_FishSegmentRomStart[]; extern u8 _ovl_En_FishSegmentRomEnd[];
extern u8 _ovl_En_HollSegmentStart[]; extern u8 _ovl_En_HollSegmentEnd[]; extern u8 _ovl_En_HollSegmentRomStart[]; extern u8 _ovl_En_HollSegmentRomEnd[];
extern u8 _ovl_En_Scene_ChangeSegmentStart[]; extern u8 _ovl_En_Scene_ChangeSegmentEnd[]; extern u8 _ovl_En_Scene_ChangeSegmentRomStart[]; extern u8 _ovl_En_Scene_ChangeSegmentRomEnd[];
extern u8 _ovl_En_ZfSegmentStart[]; extern u8 _ovl_En_ZfSegmentEnd[]; extern u8 _ovl_En_ZfSegmentRomStart[]; extern u8 _ovl_En_ZfSegmentRomEnd[];
extern u8 _ovl_En_HataSegmentStart[]; extern u8 _ovl_En_HataSegmentEnd[]; extern u8 _ovl_En_HataSegmentRomStart[]; extern u8 _ovl_En_HataSegmentRomEnd[];
extern u8 _ovl_Boss_DodongoSegmentStart[]; extern u8 _ovl_Boss_DodongoSegmentEnd[]; extern u8 _ovl_Boss_DodongoSegmentRomStart[]; extern u8 _ovl_Boss_DodongoSegmentRomEnd[];
extern u8 _ovl_Boss_GomaSegmentStart[]; extern u8 _ovl_Boss_GomaSegmentEnd[]; extern u8 _ovl_Boss_GomaSegmentRomStart[]; extern u8 _ovl_Boss_GomaSegmentRomEnd[];
extern u8 _ovl_En_Zl1SegmentStart[]; extern u8 _ovl_En_Zl1SegmentEnd[]; extern u8 _ovl_En_Zl1SegmentRomStart[]; extern u8 _ovl_En_Zl1SegmentRomEnd[];
extern u8 _ovl_En_ViewerSegmentStart[]; extern u8 _ovl_En_ViewerSegmentEnd[]; extern u8 _ovl_En_ViewerSegmentRomStart[]; extern u8 _ovl_En_ViewerSegmentRomEnd[];
extern u8 _ovl_En_GomaSegmentStart[]; extern u8 _ovl_En_GomaSegmentEnd[]; extern u8 _ovl_En_GomaSegmentRomStart[]; extern u8 _ovl_En_GomaSegmentRomEnd[];
extern u8 _ovl_Bg_PushboxSegmentStart[]; extern u8 _ovl_Bg_PushboxSegmentEnd[]; extern u8 _ovl_Bg_PushboxSegmentRomStart[]; extern u8 _ovl_Bg_PushboxSegmentRomEnd[];
extern u8 _ovl_En_BubbleSegmentStart[]; extern u8 _ovl_En_BubbleSegmentEnd[]; extern u8 _ovl_En_BubbleSegmentRomStart[]; extern u8 _ovl_En_BubbleSegmentRomEnd[];
extern u8 _ovl_Door_ShutterSegmentStart[]; extern u8 _ovl_Door_ShutterSegmentEnd[]; extern u8 _ovl_Door_ShutterSegmentRomStart[]; extern u8 _ovl_Door_ShutterSegmentRomEnd[];
extern u8 _ovl_En_DodojrSegmentStart[]; extern u8 _ovl_En_DodojrSegmentEnd[]; extern u8 _ovl_En_DodojrSegmentRomStart[]; extern u8 _ovl_En_DodojrSegmentRomEnd[];
extern u8 _ovl_En_BdfireSegmentStart[]; extern u8 _ovl_En_BdfireSegmentEnd[]; extern u8 _ovl_En_BdfireSegmentRomStart[]; extern u8 _ovl_En_BdfireSegmentRomEnd[];
extern u8 _ovl_En_BoomSegmentStart[]; extern u8 _ovl_En_BoomSegmentEnd[]; extern u8 _ovl_En_BoomSegmentRomStart[]; extern u8 _ovl_En_BoomSegmentRomEnd[];
extern u8 _ovl_En_Torch2SegmentStart[]; extern u8 _ovl_En_Torch2SegmentEnd[]; extern u8 _ovl_En_Torch2SegmentRomStart[]; extern u8 _ovl_En_Torch2SegmentRomEnd[];
extern u8 _ovl_En_BiliSegmentStart[]; extern u8 _ovl_En_BiliSegmentEnd[]; extern u8 _ovl_En_BiliSegmentRomStart[]; extern u8 _ovl_En_BiliSegmentRomEnd[];
extern u8 _ovl_En_TpSegmentStart[]; extern u8 _ovl_En_TpSegmentEnd[]; extern u8 _ovl_En_TpSegmentRomStart[]; extern u8 _ovl_En_TpSegmentRomEnd[];
extern u8 _ovl_En_StSegmentStart[]; extern u8 _ovl_En_StSegmentEnd[]; extern u8 _ovl_En_StSegmentRomStart[]; extern u8 _ovl_En_StSegmentRomEnd[];
extern u8 _ovl_En_BwSegmentStart[]; extern u8 _ovl_En_BwSegmentEnd[]; extern u8 _ovl_En_BwSegmentRomStart[]; extern u8 _ovl_En_BwSegmentRomEnd[];
extern u8 _ovl_En_A_ObjSegmentStart[]; extern u8 _ovl_En_A_ObjSegmentEnd[]; extern u8 _ovl_En_A_ObjSegmentRomStart[]; extern u8 _ovl_En_A_ObjSegmentRomEnd[];
extern u8 _ovl_En_EiyerSegmentStart[]; extern u8 _ovl_En_EiyerSegmentEnd[]; extern u8 _ovl_En_EiyerSegmentRomStart[]; extern u8 _ovl_En_EiyerSegmentRomEnd[];
extern u8 _ovl_En_River_SoundSegmentStart[]; extern u8 _ovl_En_River_SoundSegmentEnd[]; extern u8 _ovl_En_River_SoundSegmentRomStart[]; extern u8 _ovl_En_River_SoundSegmentRomEnd[];
extern u8 _ovl_En_Horse_NormalSegmentStart[]; extern u8 _ovl_En_Horse_NormalSegmentEnd[]; extern u8 _ovl_En_Horse_NormalSegmentRomStart[]; extern u8 _ovl_En_Horse_NormalSegmentRomEnd[];
extern u8 _ovl_En_OssanSegmentStart[]; extern u8 _ovl_En_OssanSegmentEnd[]; extern u8 _ovl_En_OssanSegmentRomStart[]; extern u8 _ovl_En_OssanSegmentRomEnd[];
extern u8 _ovl_Bg_TreemouthSegmentStart[]; extern u8 _ovl_Bg_TreemouthSegmentEnd[]; extern u8 _ovl_Bg_TreemouthSegmentRomStart[]; extern u8 _ovl_Bg_TreemouthSegmentRomEnd[];
extern u8 _ovl_Bg_DodoagoSegmentStart[]; extern u8 _ovl_Bg_DodoagoSegmentEnd[]; extern u8 _ovl_Bg_DodoagoSegmentRomStart[]; extern u8 _ovl_Bg_DodoagoSegmentRomEnd[];
extern u8 _ovl_Bg_Hidan_DalmSegmentStart[]; extern u8 _ovl_Bg_Hidan_DalmSegmentEnd[]; extern u8 _ovl_Bg_Hidan_DalmSegmentRomStart[]; extern u8 _ovl_Bg_Hidan_DalmSegmentRomEnd[];
extern u8 _ovl_Bg_Hidan_HrockSegmentStart[]; extern u8 _ovl_Bg_Hidan_HrockSegmentEnd[]; extern u8 _ovl_Bg_Hidan_HrockSegmentRomStart[]; extern u8 _ovl_Bg_Hidan_HrockSegmentRomEnd[];
extern u8 _ovl_En_Horse_GanonSegmentStart[]; extern u8 _ovl_En_Horse_GanonSegmentEnd[]; extern u8 _ovl_En_Horse_GanonSegmentRomStart[]; extern u8 _ovl_En_Horse_GanonSegmentRomEnd[];
extern u8 _ovl_Bg_Hidan_RockSegmentStart[]; extern u8 _ovl_Bg_Hidan_RockSegmentEnd[]; extern u8 _ovl_Bg_Hidan_RockSegmentRomStart[]; extern u8 _ovl_Bg_Hidan_RockSegmentRomEnd[];
extern u8 _ovl_Bg_Hidan_RsekizouSegmentStart[]; extern u8 _ovl_Bg_Hidan_RsekizouSegmentEnd[]; extern u8 _ovl_Bg_Hidan_RsekizouSegmentRomStart[]; extern u8 _ovl_Bg_Hidan_RsekizouSegmentRomEnd[];
extern u8 _ovl_Bg_Hidan_SekizouSegmentStart[]; extern u8 _ovl_Bg_Hidan_SekizouSegmentEnd[]; extern u8 _ovl_Bg_Hidan_SekizouSegmentRomStart[]; extern u8 _ovl_Bg_Hidan_SekizouSegmentRomEnd[];
extern u8 _ovl_Bg_Hidan_SimaSegmentStart[]; extern u8 _ovl_Bg_Hidan_SimaSegmentEnd[]; extern u8 _ovl_Bg_Hidan_SimaSegmentRomStart[]; extern u8 _ovl_Bg_Hidan_SimaSegmentRomEnd[];
extern u8 _ovl_Bg_Hidan_SyokuSegmentStart[]; extern u8 _ovl_Bg_Hidan_SyokuSegmentEnd[]; extern u8 _ovl_Bg_Hidan_SyokuSegmentRomStart[]; extern u8 _ovl_Bg_Hidan_SyokuSegmentRomEnd[];
extern u8 _ovl_En_XcSegmentStart[]; extern u8 _ovl_En_XcSegmentEnd[]; extern u8 _ovl_En_XcSegmentRomStart[]; extern u8 _ovl_En_XcSegmentRomEnd[];
extern u8 _ovl_Bg_Hidan_CurtainSegmentStart[]; extern u8 _ovl_Bg_Hidan_CurtainSegmentEnd[]; extern u8 _ovl_Bg_Hidan_CurtainSegmentRomStart[]; extern u8 _ovl_Bg_Hidan_CurtainSegmentRomEnd[];
extern u8 _ovl_Bg_Spot00_HanebasiSegmentStart[]; extern u8 _ovl_Bg_Spot00_HanebasiSegmentEnd[]; extern u8 _ovl_Bg_Spot00_HanebasiSegmentRomStart[]; extern u8 _ovl_Bg_Spot00_HanebasiSegmentRomEnd[];
extern u8 _ovl_En_MbSegmentStart[]; extern u8 _ovl_En_MbSegmentEnd[]; extern u8 _ovl_En_MbSegmentRomStart[]; extern u8 _ovl_En_MbSegmentRomEnd[];
extern u8 _ovl_En_BombfSegmentStart[]; extern u8 _ovl_En_BombfSegmentEnd[]; extern u8 _ovl_En_BombfSegmentRomStart[]; extern u8 _ovl_En_BombfSegmentRomEnd[];
extern u8 _ovl_En_Zl2SegmentStart[]; extern u8 _ovl_En_Zl2SegmentEnd[]; extern u8 _ovl_En_Zl2SegmentRomStart[]; extern u8 _ovl_En_Zl2SegmentRomEnd[];
extern u8 _ovl_Bg_Hidan_FsliftSegmentStart[]; extern u8 _ovl_Bg_Hidan_FsliftSegmentEnd[]; extern u8 _ovl_Bg_Hidan_FsliftSegmentRomStart[]; extern u8 _ovl_Bg_Hidan_FsliftSegmentRomEnd[];
extern u8 _ovl_En_OE2SegmentStart[]; extern u8 _ovl_En_OE2SegmentEnd[]; extern u8 _ovl_En_OE2SegmentRomStart[]; extern u8 _ovl_En_OE2SegmentRomEnd[];
extern u8 _ovl_Bg_Ydan_HasiSegmentStart[]; extern u8 _ovl_Bg_Ydan_HasiSegmentEnd[]; extern u8 _ovl_Bg_Ydan_HasiSegmentRomStart[]; extern u8 _ovl_Bg_Ydan_HasiSegmentRomEnd[];
extern u8 _ovl_Bg_Ydan_MarutaSegmentStart[]; extern u8 _ovl_Bg_Ydan_MarutaSegmentEnd[]; extern u8 _ovl_Bg_Ydan_MarutaSegmentRomStart[]; extern u8 _ovl_Bg_Ydan_MarutaSegmentRomEnd[];
extern u8 _ovl_Boss_GanondrofSegmentStart[]; extern u8 _ovl_Boss_GanondrofSegmentEnd[]; extern u8 _ovl_Boss_GanondrofSegmentRomStart[]; extern u8 _ovl_Boss_GanondrofSegmentRomEnd[];
extern u8 _ovl_En_AmSegmentStart[]; extern u8 _ovl_En_AmSegmentEnd[]; extern u8 _ovl_En_AmSegmentRomStart[]; extern u8 _ovl_En_AmSegmentRomEnd[];
extern u8 _ovl_En_DekubabaSegmentStart[]; extern u8 _ovl_En_DekubabaSegmentEnd[]; extern u8 _ovl_En_DekubabaSegmentRomStart[]; extern u8 _ovl_En_DekubabaSegmentRomEnd[];
extern u8 _ovl_En_M_Fire1SegmentStart[]; extern u8 _ovl_En_M_Fire1SegmentEnd[]; extern u8 _ovl_En_M_Fire1SegmentRomStart[]; extern u8 _ovl_En_M_Fire1SegmentRomEnd[];
extern u8 _ovl_En_M_ThunderSegmentStart[]; extern u8 _ovl_En_M_ThunderSegmentEnd[]; extern u8 _ovl_En_M_ThunderSegmentRomStart[]; extern u8 _ovl_En_M_ThunderSegmentRomEnd[];
extern u8 _ovl_Bg_Ddan_JdSegmentStart[]; extern u8 _ovl_Bg_Ddan_JdSegmentEnd[]; extern u8 _ovl_Bg_Ddan_JdSegmentRomStart[]; extern u8 _ovl_Bg_Ddan_JdSegmentRomEnd[];
extern u8 _ovl_Bg_BreakwallSegmentStart[]; extern u8 _ovl_Bg_BreakwallSegmentEnd[]; extern u8 _ovl_Bg_BreakwallSegmentRomStart[]; extern u8 _ovl_Bg_BreakwallSegmentRomEnd[];
extern u8 _ovl_En_JjSegmentStart[]; extern u8 _ovl_En_JjSegmentEnd[]; extern u8 _ovl_En_JjSegmentRomStart[]; extern u8 _ovl_En_JjSegmentRomEnd[];
extern u8 _ovl_En_Horse_ZeldaSegmentStart[]; extern u8 _ovl_En_Horse_ZeldaSegmentEnd[]; extern u8 _ovl_En_Horse_ZeldaSegmentRomStart[]; extern u8 _ovl_En_Horse_ZeldaSegmentRomEnd[];
extern u8 _ovl_Bg_Ddan_KdSegmentStart[]; extern u8 _ovl_Bg_Ddan_KdSegmentEnd[]; extern u8 _ovl_Bg_Ddan_KdSegmentRomStart[]; extern u8 _ovl_Bg_Ddan_KdSegmentRomEnd[];
extern u8 _ovl_Door_Warp1SegmentStart[]; extern u8 _ovl_Door_Warp1SegmentEnd[]; extern u8 _ovl_Door_Warp1SegmentRomStart[]; extern u8 _ovl_Door_Warp1SegmentRomEnd[];
extern u8 _ovl_Obj_SyokudaiSegmentStart[]; extern u8 _ovl_Obj_SyokudaiSegmentEnd[]; extern u8 _ovl_Obj_SyokudaiSegmentRomStart[]; extern u8 _ovl_Obj_SyokudaiSegmentRomEnd[];
extern u8 _ovl_Item_B_HeartSegmentStart[]; extern u8 _ovl_Item_B_HeartSegmentEnd[]; extern u8 _ovl_Item_B_HeartSegmentRomStart[]; extern u8 _ovl_Item_B_HeartSegmentRomEnd[];
extern u8 _ovl_En_DekunutsSegmentStart[]; extern u8 _ovl_En_DekunutsSegmentEnd[]; extern u8 _ovl_En_DekunutsSegmentRomStart[]; extern u8 _ovl_En_DekunutsSegmentRomEnd[];
extern u8 _ovl_Bg_Menkuri_KaitenSegmentStart[]; extern u8 _ovl_Bg_Menkuri_KaitenSegmentEnd[]; extern u8 _ovl_Bg_Menkuri_KaitenSegmentRomStart[]; extern u8 _ovl_Bg_Menkuri_KaitenSegmentRomEnd[];
extern u8 _ovl_Bg_Menkuri_EyeSegmentStart[]; extern u8 _ovl_Bg_Menkuri_EyeSegmentEnd[]; extern u8 _ovl_Bg_Menkuri_EyeSegmentRomStart[]; extern u8 _ovl_Bg_Menkuri_EyeSegmentRomEnd[];
extern u8 _ovl_En_ValiSegmentStart[]; extern u8 _ovl_En_ValiSegmentEnd[]; extern u8 _ovl_En_ValiSegmentRomStart[]; extern u8 _ovl_En_ValiSegmentRomEnd[];
extern u8 _ovl_Bg_Mizu_MovebgSegmentStart[]; extern u8 _ovl_Bg_Mizu_MovebgSegmentEnd[]; extern u8 _ovl_Bg_Mizu_MovebgSegmentRomStart[]; extern u8 _ovl_Bg_Mizu_MovebgSegmentRomEnd[];
extern u8 _ovl_Bg_Mizu_WaterSegmentStart[]; extern u8 _ovl_Bg_Mizu_WaterSegmentEnd[]; extern u8 _ovl_Bg_Mizu_WaterSegmentRomStart[]; extern u8 _ovl_Bg_Mizu_WaterSegmentRomEnd[];
extern u8 _ovl_Arms_HookSegmentStart[]; extern u8 _ovl_Arms_HookSegmentEnd[]; extern u8 _ovl_Arms_HookSegmentRomStart[]; extern u8 _ovl_Arms_HookSegmentRomEnd[];
extern u8 _ovl_En_fHGSegmentStart[]; extern u8 _ovl_En_fHGSegmentEnd[]; extern u8 _ovl_En_fHGSegmentRomStart[]; extern u8 _ovl_En_fHGSegmentRomEnd[];
extern u8 _ovl_Bg_Mori_HineriSegmentStart[]; extern u8 _ovl_Bg_Mori_HineriSegmentEnd[]; extern u8 _ovl_Bg_Mori_HineriSegmentRomStart[]; extern u8 _ovl_Bg_Mori_HineriSegmentRomEnd[];
extern u8 _ovl_En_BbSegmentStart[]; extern u8 _ovl_En_BbSegmentEnd[]; extern u8 _ovl_En_BbSegmentRomStart[]; extern u8 _ovl_En_BbSegmentRomEnd[];
extern u8 _ovl_Bg_Toki_HikariSegmentStart[]; extern u8 _ovl_Bg_Toki_HikariSegmentEnd[]; extern u8 _ovl_Bg_Toki_HikariSegmentRomStart[]; extern u8 _ovl_Bg_Toki_HikariSegmentRomEnd[];
extern u8 _ovl_En_YukabyunSegmentStart[]; extern u8 _ovl_En_YukabyunSegmentEnd[]; extern u8 _ovl_En_YukabyunSegmentRomStart[]; extern u8 _ovl_En_YukabyunSegmentRomEnd[];
extern u8 _ovl_Bg_Toki_SwdSegmentStart[]; extern u8 _ovl_Bg_Toki_SwdSegmentEnd[]; extern u8 _ovl_Bg_Toki_SwdSegmentRomStart[]; extern u8 _ovl_Bg_Toki_SwdSegmentRomEnd[];
extern u8 _ovl_En_Fhg_FireSegmentStart[]; extern u8 _ovl_En_Fhg_FireSegmentEnd[]; extern u8 _ovl_En_Fhg_FireSegmentRomStart[]; extern u8 _ovl_En_Fhg_FireSegmentRomEnd[];
extern u8 _ovl_Bg_MjinSegmentStart[]; extern u8 _ovl_Bg_MjinSegmentEnd[]; extern u8 _ovl_Bg_MjinSegmentRomStart[]; extern u8 _ovl_Bg_MjinSegmentRomEnd[];
extern u8 _ovl_Bg_Hidan_KousiSegmentStart[]; extern u8 _ovl_Bg_Hidan_KousiSegmentEnd[]; extern u8 _ovl_Bg_Hidan_KousiSegmentRomStart[]; extern u8 _ovl_Bg_Hidan_KousiSegmentRomEnd[];
extern u8 _ovl_Door_TokiSegmentStart[]; extern u8 _ovl_Door_TokiSegmentEnd[]; extern u8 _ovl_Door_TokiSegmentRomStart[]; extern u8 _ovl_Door_TokiSegmentRomEnd[];
extern u8 _ovl_Bg_Hidan_HamstepSegmentStart[]; extern u8 _ovl_Bg_Hidan_HamstepSegmentEnd[]; extern u8 _ovl_Bg_Hidan_HamstepSegmentRomStart[]; extern u8 _ovl_Bg_Hidan_HamstepSegmentRomEnd[];
extern u8 _ovl_En_BirdSegmentStart[]; extern u8 _ovl_En_BirdSegmentEnd[]; extern u8 _ovl_En_BirdSegmentRomStart[]; extern u8 _ovl_En_BirdSegmentRomEnd[];
extern u8 _ovl_En_Wood02SegmentStart[]; extern u8 _ovl_En_Wood02SegmentEnd[]; extern u8 _ovl_En_Wood02SegmentRomStart[]; extern u8 _ovl_En_Wood02SegmentRomEnd[];
extern u8 _ovl_En_LightboxSegmentStart[]; extern u8 _ovl_En_LightboxSegmentEnd[]; extern u8 _ovl_En_LightboxSegmentRomStart[]; extern u8 _ovl_En_LightboxSegmentRomEnd[];
extern u8 _ovl_En_Pu_boxSegmentStart[]; extern u8 _ovl_En_Pu_boxSegmentEnd[]; extern u8 _ovl_En_Pu_boxSegmentRomStart[]; extern u8 _ovl_En_Pu_boxSegmentRomEnd[];
extern u8 _ovl_En_TrapSegmentStart[]; extern u8 _ovl_En_TrapSegmentEnd[]; extern u8 _ovl_En_TrapSegmentRomStart[]; extern u8 _ovl_En_TrapSegmentRomEnd[];
extern u8 _ovl_En_Arow_TrapSegmentStart[]; extern u8 _ovl_En_Arow_TrapSegmentEnd[]; extern u8 _ovl_En_Arow_TrapSegmentRomStart[]; extern u8 _ovl_En_Arow_TrapSegmentRomEnd[];
extern u8 _ovl_En_VaseSegmentStart[]; extern u8 _ovl_En_VaseSegmentEnd[]; extern u8 _ovl_En_VaseSegmentRomStart[]; extern u8 _ovl_En_VaseSegmentRomEnd[];
extern u8 _ovl_En_TaSegmentStart[]; extern u8 _ovl_En_TaSegmentEnd[]; extern u8 _ovl_En_TaSegmentRomStart[]; extern u8 _ovl_En_TaSegmentRomEnd[];
extern u8 _ovl_En_TkSegmentStart[]; extern u8 _ovl_En_TkSegmentEnd[]; extern u8 _ovl_En_TkSegmentRomStart[]; extern u8 _ovl_En_TkSegmentRomEnd[];
extern u8 _ovl_Bg_Mori_BigstSegmentStart[]; extern u8 _ovl_Bg_Mori_BigstSegmentEnd[]; extern u8 _ovl_Bg_Mori_BigstSegmentRomStart[]; extern u8 _ovl_Bg_Mori_BigstSegmentRomEnd[];
extern u8 _ovl_Bg_Mori_ElevatorSegmentStart[]; extern u8 _ovl_Bg_Mori_ElevatorSegmentEnd[]; extern u8 _ovl_Bg_Mori_ElevatorSegmentRomStart[]; extern u8 _ovl_Bg_Mori_ElevatorSegmentRomEnd[];
extern u8 _ovl_Bg_Mori_KaitenkabeSegmentStart[]; extern u8 _ovl_Bg_Mori_KaitenkabeSegmentEnd[]; extern u8 _ovl_Bg_Mori_KaitenkabeSegmentRomStart[]; extern u8 _ovl_Bg_Mori_KaitenkabeSegmentRomEnd[];
extern u8 _ovl_Bg_Mori_RakkatenjoSegmentStart[]; extern u8 _ovl_Bg_Mori_RakkatenjoSegmentEnd[]; extern u8 _ovl_Bg_Mori_RakkatenjoSegmentRomStart[]; extern u8 _ovl_Bg_Mori_RakkatenjoSegmentRomEnd[];
extern u8 _ovl_En_VmSegmentStart[]; extern u8 _ovl_En_VmSegmentEnd[]; extern u8 _ovl_En_VmSegmentRomStart[]; extern u8 _ovl_En_VmSegmentRomEnd[];
extern u8 _ovl_Demo_EffectSegmentStart[]; extern u8 _ovl_Demo_EffectSegmentEnd[]; extern u8 _ovl_Demo_EffectSegmentRomStart[]; extern u8 _ovl_Demo_EffectSegmentRomEnd[];
extern u8 _ovl_Demo_KankyoSegmentStart[]; extern u8 _ovl_Demo_KankyoSegmentEnd[]; extern u8 _ovl_Demo_KankyoSegmentRomStart[]; extern u8 _ovl_Demo_KankyoSegmentRomEnd[];
extern u8 _ovl_Bg_Hidan_FwbigSegmentStart[]; extern u8 _ovl_Bg_Hidan_FwbigSegmentEnd[]; extern u8 _ovl_Bg_Hidan_FwbigSegmentRomStart[]; extern u8 _ovl_Bg_Hidan_FwbigSegmentRomEnd[];
extern u8 _ovl_En_FloormasSegmentStart[]; extern u8 _ovl_En_FloormasSegmentEnd[]; extern u8 _ovl_En_FloormasSegmentRomStart[]; extern u8 _ovl_En_FloormasSegmentRomEnd[];
extern u8 _ovl_En_Heishi1SegmentStart[]; extern u8 _ovl_En_Heishi1SegmentEnd[]; extern u8 _ovl_En_Heishi1SegmentRomStart[]; extern u8 _ovl_En_Heishi1SegmentRomEnd[];
extern u8 _ovl_En_RdSegmentStart[]; extern u8 _ovl_En_RdSegmentEnd[]; extern u8 _ovl_En_RdSegmentRomStart[]; extern u8 _ovl_En_RdSegmentRomEnd[];
extern u8 _ovl_En_Po_SistersSegmentStart[]; extern u8 _ovl_En_Po_SistersSegmentEnd[]; extern u8 _ovl_En_Po_SistersSegmentRomStart[]; extern u8 _ovl_En_Po_SistersSegmentRomEnd[];
extern u8 _ovl_Bg_Heavy_BlockSegmentStart[]; extern u8 _ovl_Bg_Heavy_BlockSegmentEnd[]; extern u8 _ovl_Bg_Heavy_BlockSegmentRomStart[]; extern u8 _ovl_Bg_Heavy_BlockSegmentRomEnd[];
extern u8 _ovl_Bg_Po_EventSegmentStart[]; extern u8 _ovl_Bg_Po_EventSegmentEnd[]; extern u8 _ovl_Bg_Po_EventSegmentRomStart[]; extern u8 _ovl_Bg_Po_EventSegmentRomEnd[];
extern u8 _ovl_Obj_MureSegmentStart[]; extern u8 _ovl_Obj_MureSegmentEnd[]; extern u8 _ovl_Obj_MureSegmentRomStart[]; extern u8 _ovl_Obj_MureSegmentRomEnd[];
extern u8 _ovl_En_SwSegmentStart[]; extern u8 _ovl_En_SwSegmentEnd[]; extern u8 _ovl_En_SwSegmentRomStart[]; extern u8 _ovl_En_SwSegmentRomEnd[];
extern u8 _ovl_Boss_FdSegmentStart[]; extern u8 _ovl_Boss_FdSegmentEnd[]; extern u8 _ovl_Boss_FdSegmentRomStart[]; extern u8 _ovl_Boss_FdSegmentRomEnd[];
extern u8 _ovl_Object_KankyoSegmentStart[]; extern u8 _ovl_Object_KankyoSegmentEnd[]; extern u8 _ovl_Object_KankyoSegmentRomStart[]; extern u8 _ovl_Object_KankyoSegmentRomEnd[];
extern u8 _ovl_En_DuSegmentStart[]; extern u8 _ovl_En_DuSegmentEnd[]; extern u8 _ovl_En_DuSegmentRomStart[]; extern u8 _ovl_En_DuSegmentRomEnd[];
extern u8 _ovl_En_FdSegmentStart[]; extern u8 _ovl_En_FdSegmentEnd[]; extern u8 _ovl_En_FdSegmentRomStart[]; extern u8 _ovl_En_FdSegmentRomEnd[];
extern u8 _ovl_En_Horse_Link_ChildSegmentStart[]; extern u8 _ovl_En_Horse_Link_ChildSegmentEnd[]; extern u8 _ovl_En_Horse_Link_ChildSegmentRomStart[]; extern u8 _ovl_En_Horse_Link_ChildSegmentRomEnd[];
extern u8 _ovl_Door_AnaSegmentStart[]; extern u8 _ovl_Door_AnaSegmentEnd[]; extern u8 _ovl_Door_AnaSegmentRomStart[]; extern u8 _ovl_Door_AnaSegmentRomEnd[];
extern u8 _ovl_Bg_Spot02_ObjectsSegmentStart[]; extern u8 _ovl_Bg_Spot02_ObjectsSegmentEnd[]; extern u8 _ovl_Bg_Spot02_ObjectsSegmentRomStart[]; extern u8 _ovl_Bg_Spot02_ObjectsSegmentRomEnd[];
extern u8 _ovl_Bg_HakaSegmentStart[]; extern u8 _ovl_Bg_HakaSegmentEnd[]; extern u8 _ovl_Bg_HakaSegmentRomStart[]; extern u8 _ovl_Bg_HakaSegmentRomEnd[];
extern u8 _ovl_Magic_WindSegmentStart[]; extern u8 _ovl_Magic_WindSegmentEnd[]; extern u8 _ovl_Magic_WindSegmentRomStart[]; extern u8 _ovl_Magic_WindSegmentRomEnd[];
extern u8 _ovl_Magic_FireSegmentStart[]; extern u8 _ovl_Magic_FireSegmentEnd[]; extern u8 _ovl_Magic_FireSegmentRomStart[]; extern u8 _ovl_Magic_FireSegmentRomEnd[];
extern u8 _ovl_En_Ru1SegmentStart[]; extern u8 _ovl_En_Ru1SegmentEnd[]; extern u8 _ovl_En_Ru1SegmentRomStart[]; extern u8 _ovl_En_Ru1SegmentRomEnd[];
extern u8 _ovl_Boss_Fd2SegmentStart[]; extern u8 _ovl_Boss_Fd2SegmentEnd[]; extern u8 _ovl_Boss_Fd2SegmentRomStart[]; extern u8 _ovl_Boss_Fd2SegmentRomEnd[];
extern u8 _ovl_En_Fd_FireSegmentStart[]; extern u8 _ovl_En_Fd_FireSegmentEnd[]; extern u8 _ovl_En_Fd_FireSegmentRomStart[]; extern u8 _ovl_En_Fd_FireSegmentRomEnd[];
extern u8 _ovl_En_DhSegmentStart[]; extern u8 _ovl_En_DhSegmentEnd[]; extern u8 _ovl_En_DhSegmentRomStart[]; extern u8 _ovl_En_DhSegmentRomEnd[];
extern u8 _ovl_En_DhaSegmentStart[]; extern u8 _ovl_En_DhaSegmentEnd[]; extern u8 _ovl_En_DhaSegmentRomStart[]; extern u8 _ovl_En_DhaSegmentRomEnd[];
extern u8 _ovl_En_RlSegmentStart[]; extern u8 _ovl_En_RlSegmentEnd[]; extern u8 _ovl_En_RlSegmentRomStart[]; extern u8 _ovl_En_RlSegmentRomEnd[];
extern u8 _ovl_En_Encount1SegmentStart[]; extern u8 _ovl_En_Encount1SegmentEnd[]; extern u8 _ovl_En_Encount1SegmentRomStart[]; extern u8 _ovl_En_Encount1SegmentRomEnd[];
extern u8 _ovl_Demo_DuSegmentStart[]; extern u8 _ovl_Demo_DuSegmentEnd[]; extern u8 _ovl_Demo_DuSegmentRomStart[]; extern u8 _ovl_Demo_DuSegmentRomEnd[];
extern u8 _ovl_Demo_ImSegmentStart[]; extern u8 _ovl_Demo_ImSegmentEnd[]; extern u8 _ovl_Demo_ImSegmentRomStart[]; extern u8 _ovl_Demo_ImSegmentRomEnd[];
extern u8 _ovl_Demo_Tre_LgtSegmentStart[]; extern u8 _ovl_Demo_Tre_LgtSegmentEnd[]; extern u8 _ovl_Demo_Tre_LgtSegmentRomStart[]; extern u8 _ovl_Demo_Tre_LgtSegmentRomEnd[];
extern u8 _ovl_En_FwSegmentStart[]; extern u8 _ovl_En_FwSegmentEnd[]; extern u8 _ovl_En_FwSegmentRomStart[]; extern u8 _ovl_En_FwSegmentRomEnd[];
extern u8 _ovl_Bg_Vb_SimaSegmentStart[]; extern u8 _ovl_Bg_Vb_SimaSegmentEnd[]; extern u8 _ovl_Bg_Vb_SimaSegmentRomStart[]; extern u8 _ovl_Bg_Vb_SimaSegmentRomEnd[];
extern u8 _ovl_En_Vb_BallSegmentStart[]; extern u8 _ovl_En_Vb_BallSegmentEnd[]; extern u8 _ovl_En_Vb_BallSegmentRomStart[]; extern u8 _ovl_En_Vb_BallSegmentRomEnd[];
extern u8 _ovl_Bg_Haka_MeganeSegmentStart[]; extern u8 _ovl_Bg_Haka_MeganeSegmentEnd[]; extern u8 _ovl_Bg_Haka_MeganeSegmentRomStart[]; extern u8 _ovl_Bg_Haka_MeganeSegmentRomEnd[];
extern u8 _ovl_Bg_Haka_MeganeBGSegmentStart[]; extern u8 _ovl_Bg_Haka_MeganeBGSegmentEnd[]; extern u8 _ovl_Bg_Haka_MeganeBGSegmentRomStart[]; extern u8 _ovl_Bg_Haka_MeganeBGSegmentRomEnd[];
extern u8 _ovl_Bg_Haka_ShipSegmentStart[]; extern u8 _ovl_Bg_Haka_ShipSegmentEnd[]; extern u8 _ovl_Bg_Haka_ShipSegmentRomStart[]; extern u8 _ovl_Bg_Haka_ShipSegmentRomEnd[];
extern u8 _ovl_Bg_Haka_SgamiSegmentStart[]; extern u8 _ovl_Bg_Haka_SgamiSegmentEnd[]; extern u8 _ovl_Bg_Haka_SgamiSegmentRomStart[]; extern u8 _ovl_Bg_Haka_SgamiSegmentRomEnd[];
extern u8 _ovl_En_Heishi2SegmentStart[]; extern u8 _ovl_En_Heishi2SegmentEnd[]; extern u8 _ovl_En_Heishi2SegmentRomStart[]; extern u8 _ovl_En_Heishi2SegmentRomEnd[];
extern u8 _ovl_En_Encount2SegmentStart[]; extern u8 _ovl_En_Encount2SegmentEnd[]; extern u8 _ovl_En_Encount2SegmentRomStart[]; extern u8 _ovl_En_Encount2SegmentRomEnd[];
extern u8 _ovl_En_Fire_RockSegmentStart[]; extern u8 _ovl_En_Fire_RockSegmentEnd[]; extern u8 _ovl_En_Fire_RockSegmentRomStart[]; extern u8 _ovl_En_Fire_RockSegmentRomEnd[];
extern u8 _ovl_En_BrobSegmentStart[]; extern u8 _ovl_En_BrobSegmentEnd[]; extern u8 _ovl_En_BrobSegmentRomStart[]; extern u8 _ovl_En_BrobSegmentRomEnd[];
extern u8 _ovl_Mir_RaySegmentStart[]; extern u8 _ovl_Mir_RaySegmentEnd[]; extern u8 _ovl_Mir_RaySegmentRomStart[]; extern u8 _ovl_Mir_RaySegmentRomEnd[];
extern u8 _ovl_Bg_Spot09_ObjSegmentStart[]; extern u8 _ovl_Bg_Spot09_ObjSegmentEnd[]; extern u8 _ovl_Bg_Spot09_ObjSegmentRomStart[]; extern u8 _ovl_Bg_Spot09_ObjSegmentRomEnd[];
extern u8 _ovl_Bg_Spot18_ObjSegmentStart[]; extern u8 _ovl_Bg_Spot18_ObjSegmentEnd[]; extern u8 _ovl_Bg_Spot18_ObjSegmentRomStart[]; extern u8 _ovl_Bg_Spot18_ObjSegmentRomEnd[];
extern u8 _ovl_Boss_VaSegmentStart[]; extern u8 _ovl_Boss_VaSegmentEnd[]; extern u8 _ovl_Boss_VaSegmentRomStart[]; extern u8 _ovl_Boss_VaSegmentRomEnd[];
extern u8 _ovl_Bg_Haka_TuboSegmentStart[]; extern u8 _ovl_Bg_Haka_TuboSegmentEnd[]; extern u8 _ovl_Bg_Haka_TuboSegmentRomStart[]; extern u8 _ovl_Bg_Haka_TuboSegmentRomEnd[];
extern u8 _ovl_Bg_Haka_TrapSegmentStart[]; extern u8 _ovl_Bg_Haka_TrapSegmentEnd[]; extern u8 _ovl_Bg_Haka_TrapSegmentRomStart[]; extern u8 _ovl_Bg_Haka_TrapSegmentRomEnd[];
extern u8 _ovl_Bg_Haka_HutaSegmentStart[]; extern u8 _ovl_Bg_Haka_HutaSegmentEnd[]; extern u8 _ovl_Bg_Haka_HutaSegmentRomStart[]; extern u8 _ovl_Bg_Haka_HutaSegmentRomEnd[];
extern u8 _ovl_Bg_Haka_ZouSegmentStart[]; extern u8 _ovl_Bg_Haka_ZouSegmentEnd[]; extern u8 _ovl_Bg_Haka_ZouSegmentRomStart[]; extern u8 _ovl_Bg_Haka_ZouSegmentRomEnd[];
extern u8 _ovl_Bg_Spot17_FunenSegmentStart[]; extern u8 _ovl_Bg_Spot17_FunenSegmentEnd[]; extern u8 _ovl_Bg_Spot17_FunenSegmentRomStart[]; extern u8 _ovl_Bg_Spot17_FunenSegmentRomEnd[];
extern u8 _ovl_En_Syateki_ItmSegmentStart[]; extern u8 _ovl_En_Syateki_ItmSegmentEnd[]; extern u8 _ovl_En_Syateki_ItmSegmentRomStart[]; extern u8 _ovl_En_Syateki_ItmSegmentRomEnd[];
extern u8 _ovl_En_Syateki_ManSegmentStart[]; extern u8 _ovl_En_Syateki_ManSegmentEnd[]; extern u8 _ovl_En_Syateki_ManSegmentRomStart[]; extern u8 _ovl_En_Syateki_ManSegmentRomEnd[];
extern u8 _ovl_En_TanaSegmentStart[]; extern u8 _ovl_En_TanaSegmentEnd[]; extern u8 _ovl_En_TanaSegmentRomStart[]; extern u8 _ovl_En_TanaSegmentRomEnd[];
extern u8 _ovl_En_NbSegmentStart[]; extern u8 _ovl_En_NbSegmentEnd[]; extern u8 _ovl_En_NbSegmentRomStart[]; extern u8 _ovl_En_NbSegmentRomEnd[];
extern u8 _ovl_Boss_MoSegmentStart[]; extern u8 _ovl_Boss_MoSegmentEnd[]; extern u8 _ovl_Boss_MoSegmentRomStart[]; extern u8 _ovl_Boss_MoSegmentRomEnd[];
extern u8 _ovl_En_SbSegmentStart[]; extern u8 _ovl_En_SbSegmentEnd[]; extern u8 _ovl_En_SbSegmentRomStart[]; extern u8 _ovl_En_SbSegmentRomEnd[];
extern u8 _ovl_En_BigokutaSegmentStart[]; extern u8 _ovl_En_BigokutaSegmentEnd[]; extern u8 _ovl_En_BigokutaSegmentRomStart[]; extern u8 _ovl_En_BigokutaSegmentRomEnd[];
extern u8 _ovl_En_KarebabaSegmentStart[]; extern u8 _ovl_En_KarebabaSegmentEnd[]; extern u8 _ovl_En_KarebabaSegmentRomStart[]; extern u8 _ovl_En_KarebabaSegmentRomEnd[];
extern u8 _ovl_Bg_Bdan_ObjectsSegmentStart[]; extern u8 _ovl_Bg_Bdan_ObjectsSegmentEnd[]; extern u8 _ovl_Bg_Bdan_ObjectsSegmentRomStart[]; extern u8 _ovl_Bg_Bdan_ObjectsSegmentRomEnd[];
extern u8 _ovl_Demo_SaSegmentStart[]; extern u8 _ovl_Demo_SaSegmentEnd[]; extern u8 _ovl_Demo_SaSegmentRomStart[]; extern u8 _ovl_Demo_SaSegmentRomEnd[];
extern u8 _ovl_Demo_GoSegmentStart[]; extern u8 _ovl_Demo_GoSegmentEnd[]; extern u8 _ovl_Demo_GoSegmentRomStart[]; extern u8 _ovl_Demo_GoSegmentRomEnd[];
extern u8 _ovl_En_InSegmentStart[]; extern u8 _ovl_En_InSegmentEnd[]; extern u8 _ovl_En_InSegmentRomStart[]; extern u8 _ovl_En_InSegmentRomEnd[];
extern u8 _ovl_En_TrSegmentStart[]; extern u8 _ovl_En_TrSegmentEnd[]; extern u8 _ovl_En_TrSegmentRomStart[]; extern u8 _ovl_En_TrSegmentRomEnd[];
extern u8 _ovl_Bg_Spot16_BombstoneSegmentStart[]; extern u8 _ovl_Bg_Spot16_BombstoneSegmentEnd[]; extern u8 _ovl_Bg_Spot16_BombstoneSegmentRomStart[]; extern u8 _ovl_Bg_Spot16_BombstoneSegmentRomEnd[];
extern u8 _ovl_Bg_Hidan_KowarerukabeSegmentStart[]; extern u8 _ovl_Bg_Hidan_KowarerukabeSegmentEnd[]; extern u8 _ovl_Bg_Hidan_KowarerukabeSegmentRomStart[]; extern u8 _ovl_Bg_Hidan_KowarerukabeSegmentRomEnd[];
extern u8 _ovl_Bg_BombwallSegmentStart[]; extern u8 _ovl_Bg_BombwallSegmentEnd[]; extern u8 _ovl_Bg_BombwallSegmentRomStart[]; extern u8 _ovl_Bg_BombwallSegmentRomEnd[];
extern u8 _ovl_Bg_Spot08_IceblockSegmentStart[]; extern u8 _ovl_Bg_Spot08_IceblockSegmentEnd[]; extern u8 _ovl_Bg_Spot08_IceblockSegmentRomStart[]; extern u8 _ovl_Bg_Spot08_IceblockSegmentRomEnd[];
extern u8 _ovl_En_Ru2SegmentStart[]; extern u8 _ovl_En_Ru2SegmentEnd[]; extern u8 _ovl_En_Ru2SegmentRomStart[]; extern u8 _ovl_En_Ru2SegmentRomEnd[];
extern u8 _ovl_Obj_DekujrSegmentStart[]; extern u8 _ovl_Obj_DekujrSegmentEnd[]; extern u8 _ovl_Obj_DekujrSegmentRomStart[]; extern u8 _ovl_Obj_DekujrSegmentRomEnd[];
extern u8 _ovl_Bg_Mizu_UzuSegmentStart[]; extern u8 _ovl_Bg_Mizu_UzuSegmentEnd[]; extern u8 _ovl_Bg_Mizu_UzuSegmentRomStart[]; extern u8 _ovl_Bg_Mizu_UzuSegmentRomEnd[];
extern u8 _ovl_Bg_Spot06_ObjectsSegmentStart[]; extern u8 _ovl_Bg_Spot06_ObjectsSegmentEnd[]; extern u8 _ovl_Bg_Spot06_ObjectsSegmentRomStart[]; extern u8 _ovl_Bg_Spot06_ObjectsSegmentRomEnd[];
extern u8 _ovl_Bg_Ice_ObjectsSegmentStart[]; extern u8 _ovl_Bg_Ice_ObjectsSegmentEnd[]; extern u8 _ovl_Bg_Ice_ObjectsSegmentRomStart[]; extern u8 _ovl_Bg_Ice_ObjectsSegmentRomEnd[];
extern u8 _ovl_Bg_Haka_WaterSegmentStart[]; extern u8 _ovl_Bg_Haka_WaterSegmentEnd[]; extern u8 _ovl_Bg_Haka_WaterSegmentRomStart[]; extern u8 _ovl_Bg_Haka_WaterSegmentRomEnd[];
extern u8 _ovl_En_Ma2SegmentStart[]; extern u8 _ovl_En_Ma2SegmentEnd[]; extern u8 _ovl_En_Ma2SegmentRomStart[]; extern u8 _ovl_En_Ma2SegmentRomEnd[];
extern u8 _ovl_En_Bom_ChuSegmentStart[]; extern u8 _ovl_En_Bom_ChuSegmentEnd[]; extern u8 _ovl_En_Bom_ChuSegmentRomStart[]; extern u8 _ovl_En_Bom_ChuSegmentRomEnd[];
extern u8 _ovl_En_Horse_Game_CheckSegmentStart[]; extern u8 _ovl_En_Horse_Game_CheckSegmentEnd[]; extern u8 _ovl_En_Horse_Game_CheckSegmentRomStart[]; extern u8 _ovl_En_Horse_Game_CheckSegmentRomEnd[];
extern u8 _ovl_Boss_TwSegmentStart[]; extern u8 _ovl_Boss_TwSegmentEnd[]; extern u8 _ovl_Boss_TwSegmentRomStart[]; extern u8 _ovl_Boss_TwSegmentRomEnd[];
extern u8 _ovl_En_RrSegmentStart[]; extern u8 _ovl_En_RrSegmentEnd[]; extern u8 _ovl_En_RrSegmentRomStart[]; extern u8 _ovl_En_RrSegmentRomEnd[];
extern u8 _ovl_En_BaSegmentStart[]; extern u8 _ovl_En_BaSegmentEnd[]; extern u8 _ovl_En_BaSegmentRomStart[]; extern u8 _ovl_En_BaSegmentRomEnd[];
extern u8 _ovl_En_BxSegmentStart[]; extern u8 _ovl_En_BxSegmentEnd[]; extern u8 _ovl_En_BxSegmentRomStart[]; extern u8 _ovl_En_BxSegmentRomEnd[];
extern u8 _ovl_En_AnubiceSegmentStart[]; extern u8 _ovl_En_AnubiceSegmentEnd[]; extern u8 _ovl_En_AnubiceSegmentRomStart[]; extern u8 _ovl_En_AnubiceSegmentRomEnd[];
extern u8 _ovl_En_Anubice_FireSegmentStart[]; extern u8 _ovl_En_Anubice_FireSegmentEnd[]; extern u8 _ovl_En_Anubice_FireSegmentRomStart[]; extern u8 _ovl_En_Anubice_FireSegmentRomEnd[];
extern u8 _ovl_Bg_Mori_HashigoSegmentStart[]; extern u8 _ovl_Bg_Mori_HashigoSegmentEnd[]; extern u8 _ovl_Bg_Mori_HashigoSegmentRomStart[]; extern u8 _ovl_Bg_Mori_HashigoSegmentRomEnd[];
extern u8 _ovl_Bg_Mori_Hashira4SegmentStart[]; extern u8 _ovl_Bg_Mori_Hashira4SegmentEnd[]; extern u8 _ovl_Bg_Mori_Hashira4SegmentRomStart[]; extern u8 _ovl_Bg_Mori_Hashira4SegmentRomEnd[];
extern u8 _ovl_Bg_Mori_IdomizuSegmentStart[]; extern u8 _ovl_Bg_Mori_IdomizuSegmentEnd[]; extern u8 _ovl_Bg_Mori_IdomizuSegmentRomStart[]; extern u8 _ovl_Bg_Mori_IdomizuSegmentRomEnd[];
extern u8 _ovl_Bg_Spot16_DoughnutSegmentStart[]; extern u8 _ovl_Bg_Spot16_DoughnutSegmentEnd[]; extern u8 _ovl_Bg_Spot16_DoughnutSegmentRomStart[]; extern u8 _ovl_Bg_Spot16_DoughnutSegmentRomEnd[];
extern u8 _ovl_Bg_Bdan_SwitchSegmentStart[]; extern u8 _ovl_Bg_Bdan_SwitchSegmentEnd[]; extern u8 _ovl_Bg_Bdan_SwitchSegmentRomStart[]; extern u8 _ovl_Bg_Bdan_SwitchSegmentRomEnd[];
extern u8 _ovl_En_Ma1SegmentStart[]; extern u8 _ovl_En_Ma1SegmentEnd[]; extern u8 _ovl_En_Ma1SegmentRomStart[]; extern u8 _ovl_En_Ma1SegmentRomEnd[];
extern u8 _ovl_Boss_GanonSegmentStart[]; extern u8 _ovl_Boss_GanonSegmentEnd[]; extern u8 _ovl_Boss_GanonSegmentRomStart[]; extern u8 _ovl_Boss_GanonSegmentRomEnd[];
extern u8 _ovl_Boss_SstSegmentStart[]; extern u8 _ovl_Boss_SstSegmentEnd[]; extern u8 _ovl_Boss_SstSegmentRomStart[]; extern u8 _ovl_Boss_SstSegmentRomEnd[];
extern u8 _ovl_En_NySegmentStart[]; extern u8 _ovl_En_NySegmentEnd[]; extern u8 _ovl_En_NySegmentRomStart[]; extern u8 _ovl_En_NySegmentRomEnd[];
extern u8 _ovl_En_FrSegmentStart[]; extern u8 _ovl_En_FrSegmentEnd[]; extern u8 _ovl_En_FrSegmentRomStart[]; extern u8 _ovl_En_FrSegmentRomEnd[];
extern u8 _ovl_Item_ShieldSegmentStart[]; extern u8 _ovl_Item_ShieldSegmentEnd[]; extern u8 _ovl_Item_ShieldSegmentRomStart[]; extern u8 _ovl_Item_ShieldSegmentRomEnd[];
extern u8 _ovl_Bg_Ice_ShelterSegmentStart[]; extern u8 _ovl_Bg_Ice_ShelterSegmentEnd[]; extern u8 _ovl_Bg_Ice_ShelterSegmentRomStart[]; extern u8 _ovl_Bg_Ice_ShelterSegmentRomEnd[];
extern u8 _ovl_En_Ice_HonoSegmentStart[]; extern u8 _ovl_En_Ice_HonoSegmentEnd[]; extern u8 _ovl_En_Ice_HonoSegmentRomStart[]; extern u8 _ovl_En_Ice_HonoSegmentRomEnd[];
extern u8 _ovl_Item_OcarinaSegmentStart[]; extern u8 _ovl_Item_OcarinaSegmentEnd[]; extern u8 _ovl_Item_OcarinaSegmentRomStart[]; extern u8 _ovl_Item_OcarinaSegmentRomEnd[];
extern u8 _ovl_Magic_DarkSegmentStart[]; extern u8 _ovl_Magic_DarkSegmentEnd[]; extern u8 _ovl_Magic_DarkSegmentRomStart[]; extern u8 _ovl_Magic_DarkSegmentRomEnd[];
extern u8 _ovl_Demo_6KSegmentStart[]; extern u8 _ovl_Demo_6KSegmentEnd[]; extern u8 _ovl_Demo_6KSegmentRomStart[]; extern u8 _ovl_Demo_6KSegmentRomEnd[];
extern u8 _ovl_En_Anubice_TagSegmentStart[]; extern u8 _ovl_En_Anubice_TagSegmentEnd[]; extern u8 _ovl_En_Anubice_TagSegmentRomStart[]; extern u8 _ovl_En_Anubice_TagSegmentRomEnd[];
extern u8 _ovl_Bg_Haka_GateSegmentStart[]; extern u8 _ovl_Bg_Haka_GateSegmentEnd[]; extern u8 _ovl_Bg_Haka_GateSegmentRomStart[]; extern u8 _ovl_Bg_Haka_GateSegmentRomEnd[];
extern u8 _ovl_Bg_Spot15_SakuSegmentStart[]; extern u8 _ovl_Bg_Spot15_SakuSegmentEnd[]; extern u8 _ovl_Bg_Spot15_SakuSegmentRomStart[]; extern u8 _ovl_Bg_Spot15_SakuSegmentRomEnd[];
extern u8 _ovl_Bg_Jya_GoroiwaSegmentStart[]; extern u8 _ovl_Bg_Jya_GoroiwaSegmentEnd[]; extern u8 _ovl_Bg_Jya_GoroiwaSegmentRomStart[]; extern u8 _ovl_Bg_Jya_GoroiwaSegmentRomEnd[];
extern u8 _ovl_Bg_Jya_ZurerukabeSegmentStart[]; extern u8 _ovl_Bg_Jya_ZurerukabeSegmentEnd[]; extern u8 _ovl_Bg_Jya_ZurerukabeSegmentRomStart[]; extern u8 _ovl_Bg_Jya_ZurerukabeSegmentRomEnd[];
extern u8 _ovl_Bg_Jya_CobraSegmentStart[]; extern u8 _ovl_Bg_Jya_CobraSegmentEnd[]; extern u8 _ovl_Bg_Jya_CobraSegmentRomStart[]; extern u8 _ovl_Bg_Jya_CobraSegmentRomEnd[];
extern u8 _ovl_Bg_Jya_KanaamiSegmentStart[]; extern u8 _ovl_Bg_Jya_KanaamiSegmentEnd[]; extern u8 _ovl_Bg_Jya_KanaamiSegmentRomStart[]; extern u8 _ovl_Bg_Jya_KanaamiSegmentRomEnd[];
extern u8 _ovl_FishingSegmentStart[]; extern u8 _ovl_FishingSegmentEnd[]; extern u8 _ovl_FishingSegmentRomStart[]; extern u8 _ovl_FishingSegmentRomEnd[];
extern u8 _ovl_Obj_OshihikiSegmentStart[]; extern u8 _ovl_Obj_OshihikiSegmentEnd[]; extern u8 _ovl_Obj_OshihikiSegmentRomStart[]; extern u8 _ovl_Obj_OshihikiSegmentRomEnd[];
extern u8 _ovl_Bg_Gate_ShutterSegmentStart[]; extern u8 _ovl_Bg_Gate_ShutterSegmentEnd[]; extern u8 _ovl_Bg_Gate_ShutterSegmentRomStart[]; extern u8 _ovl_Bg_Gate_ShutterSegmentRomEnd[];
extern u8 _ovl_Eff_DustSegmentStart[]; extern u8 _ovl_Eff_DustSegmentEnd[]; extern u8 _ovl_Eff_DustSegmentRomStart[]; extern u8 _ovl_Eff_DustSegmentRomEnd[];
extern u8 _ovl_Bg_Spot01_FusyaSegmentStart[]; extern u8 _ovl_Bg_Spot01_FusyaSegmentEnd[]; extern u8 _ovl_Bg_Spot01_FusyaSegmentRomStart[]; extern u8 _ovl_Bg_Spot01_FusyaSegmentRomEnd[];
extern u8 _ovl_Bg_Spot01_IdohashiraSegmentStart[]; extern u8 _ovl_Bg_Spot01_IdohashiraSegmentEnd[]; extern u8 _ovl_Bg_Spot01_IdohashiraSegmentRomStart[]; extern u8 _ovl_Bg_Spot01_IdohashiraSegmentRomEnd[];
extern u8 _ovl_Bg_Spot01_IdomizuSegmentStart[]; extern u8 _ovl_Bg_Spot01_IdomizuSegmentEnd[]; extern u8 _ovl_Bg_Spot01_IdomizuSegmentRomStart[]; extern u8 _ovl_Bg_Spot01_IdomizuSegmentRomEnd[];
extern u8 _ovl_Bg_Po_SyokudaiSegmentStart[]; extern u8 _ovl_Bg_Po_SyokudaiSegmentEnd[]; extern u8 _ovl_Bg_Po_SyokudaiSegmentRomStart[]; extern u8 _ovl_Bg_Po_SyokudaiSegmentRomEnd[];
extern u8 _ovl_Bg_Ganon_OtyukaSegmentStart[]; extern u8 _ovl_Bg_Ganon_OtyukaSegmentEnd[]; extern u8 _ovl_Bg_Ganon_OtyukaSegmentRomStart[]; extern u8 _ovl_Bg_Ganon_OtyukaSegmentRomEnd[];
extern u8 _ovl_Bg_Spot15_RrboxSegmentStart[]; extern u8 _ovl_Bg_Spot15_RrboxSegmentEnd[]; extern u8 _ovl_Bg_Spot15_RrboxSegmentRomStart[]; extern u8 _ovl_Bg_Spot15_RrboxSegmentRomEnd[];
extern u8 _ovl_Bg_UmajumpSegmentStart[]; extern u8 _ovl_Bg_UmajumpSegmentEnd[]; extern u8 _ovl_Bg_UmajumpSegmentRomStart[]; extern u8 _ovl_Bg_UmajumpSegmentRomEnd[];
extern u8 _ovl_Arrow_FireSegmentStart[]; extern u8 _ovl_Arrow_FireSegmentEnd[]; extern u8 _ovl_Arrow_FireSegmentRomStart[]; extern u8 _ovl_Arrow_FireSegmentRomEnd[];
extern u8 _ovl_Arrow_IceSegmentStart[]; extern u8 _ovl_Arrow_IceSegmentEnd[]; extern u8 _ovl_Arrow_IceSegmentRomStart[]; extern u8 _ovl_Arrow_IceSegmentRomEnd[];
extern u8 _ovl_Arrow_LightSegmentStart[]; extern u8 _ovl_Arrow_LightSegmentEnd[]; extern u8 _ovl_Arrow_LightSegmentRomStart[]; extern u8 _ovl_Arrow_LightSegmentRomEnd[];
extern u8 _ovl_Item_EtceteraSegmentStart[]; extern u8 _ovl_Item_EtceteraSegmentEnd[]; extern u8 _ovl_Item_EtceteraSegmentRomStart[]; extern u8 _ovl_Item_EtceteraSegmentRomEnd[];
extern u8 _ovl_Obj_KibakoSegmentStart[]; extern u8 _ovl_Obj_KibakoSegmentEnd[]; extern u8 _ovl_Obj_KibakoSegmentRomStart[]; extern u8 _ovl_Obj_KibakoSegmentRomEnd[];
extern u8 _ovl_Obj_TsuboSegmentStart[]; extern u8 _ovl_Obj_TsuboSegmentEnd[]; extern u8 _ovl_Obj_TsuboSegmentRomStart[]; extern u8 _ovl_Obj_TsuboSegmentRomEnd[];
extern u8 _ovl_En_Wonder_ItemSegmentStart[]; extern u8 _ovl_En_Wonder_ItemSegmentEnd[]; extern u8 _ovl_En_Wonder_ItemSegmentRomStart[]; extern u8 _ovl_En_Wonder_ItemSegmentRomEnd[];
extern u8 _ovl_En_IkSegmentStart[]; extern u8 _ovl_En_IkSegmentEnd[]; extern u8 _ovl_En_IkSegmentRomStart[]; extern u8 _ovl_En_IkSegmentRomEnd[];
extern u8 _ovl_Demo_IkSegmentStart[]; extern u8 _ovl_Demo_IkSegmentEnd[]; extern u8 _ovl_Demo_IkSegmentRomStart[]; extern u8 _ovl_Demo_IkSegmentRomEnd[];
extern u8 _ovl_En_SkjSegmentStart[]; extern u8 _ovl_En_SkjSegmentEnd[]; extern u8 _ovl_En_SkjSegmentRomStart[]; extern u8 _ovl_En_SkjSegmentRomEnd[];
extern u8 _ovl_En_SkjneedleSegmentStart[]; extern u8 _ovl_En_SkjneedleSegmentEnd[]; extern u8 _ovl_En_SkjneedleSegmentRomStart[]; extern u8 _ovl_En_SkjneedleSegmentRomEnd[];
extern u8 _ovl_En_G_SwitchSegmentStart[]; extern u8 _ovl_En_G_SwitchSegmentEnd[]; extern u8 _ovl_En_G_SwitchSegmentRomStart[]; extern u8 _ovl_En_G_SwitchSegmentRomEnd[];
extern u8 _ovl_Demo_ExtSegmentStart[]; extern u8 _ovl_Demo_ExtSegmentEnd[]; extern u8 _ovl_Demo_ExtSegmentRomStart[]; extern u8 _ovl_Demo_ExtSegmentRomEnd[];
extern u8 _ovl_Demo_ShdSegmentStart[]; extern u8 _ovl_Demo_ShdSegmentEnd[]; extern u8 _ovl_Demo_ShdSegmentRomStart[]; extern u8 _ovl_Demo_ShdSegmentRomEnd[];
extern u8 _ovl_En_DnsSegmentStart[]; extern u8 _ovl_En_DnsSegmentEnd[]; extern u8 _ovl_En_DnsSegmentRomStart[]; extern u8 _ovl_En_DnsSegmentRomEnd[];
extern u8 _ovl_Elf_MsgSegmentStart[]; extern u8 _ovl_Elf_MsgSegmentEnd[]; extern u8 _ovl_Elf_MsgSegmentRomStart[]; extern u8 _ovl_Elf_MsgSegmentRomEnd[];
extern u8 _ovl_En_HonotrapSegmentStart[]; extern u8 _ovl_En_HonotrapSegmentEnd[]; extern u8 _ovl_En_HonotrapSegmentRomStart[]; extern u8 _ovl_En_HonotrapSegmentRomEnd[];
extern u8 _ovl_En_Tubo_TrapSegmentStart[]; extern u8 _ovl_En_Tubo_TrapSegmentEnd[]; extern u8 _ovl_En_Tubo_TrapSegmentRomStart[]; extern u8 _ovl_En_Tubo_TrapSegmentRomEnd[];
extern u8 _ovl_Obj_Ice_PolySegmentStart[]; extern u8 _ovl_Obj_Ice_PolySegmentEnd[]; extern u8 _ovl_Obj_Ice_PolySegmentRomStart[]; extern u8 _ovl_Obj_Ice_PolySegmentRomEnd[];
extern u8 _ovl_Bg_Spot03_TakiSegmentStart[]; extern u8 _ovl_Bg_Spot03_TakiSegmentEnd[]; extern u8 _ovl_Bg_Spot03_TakiSegmentRomStart[]; extern u8 _ovl_Bg_Spot03_TakiSegmentRomEnd[];
extern u8 _ovl_Bg_Spot07_TakiSegmentStart[]; extern u8 _ovl_Bg_Spot07_TakiSegmentEnd[]; extern u8 _ovl_Bg_Spot07_TakiSegmentRomStart[]; extern u8 _ovl_Bg_Spot07_TakiSegmentRomEnd[];
extern u8 _ovl_En_FzSegmentStart[]; extern u8 _ovl_En_FzSegmentEnd[]; extern u8 _ovl_En_FzSegmentRomStart[]; extern u8 _ovl_En_FzSegmentRomEnd[];
extern u8 _ovl_En_Po_RelaySegmentStart[]; extern u8 _ovl_En_Po_RelaySegmentEnd[]; extern u8 _ovl_En_Po_RelaySegmentRomStart[]; extern u8 _ovl_En_Po_RelaySegmentRomEnd[];
extern u8 _ovl_Bg_Relay_ObjectsSegmentStart[]; extern u8 _ovl_Bg_Relay_ObjectsSegmentEnd[]; extern u8 _ovl_Bg_Relay_ObjectsSegmentRomStart[]; extern u8 _ovl_Bg_Relay_ObjectsSegmentRomEnd[];
extern u8 _ovl_En_Diving_GameSegmentStart[]; extern u8 _ovl_En_Diving_GameSegmentEnd[]; extern u8 _ovl_En_Diving_GameSegmentRomStart[]; extern u8 _ovl_En_Diving_GameSegmentRomEnd[];
extern u8 _ovl_En_KusaSegmentStart[]; extern u8 _ovl_En_KusaSegmentEnd[]; extern u8 _ovl_En_KusaSegmentRomStart[]; extern u8 _ovl_En_KusaSegmentRomEnd[];
extern u8 _ovl_Obj_BeanSegmentStart[]; extern u8 _ovl_Obj_BeanSegmentEnd[]; extern u8 _ovl_Obj_BeanSegmentRomStart[]; extern u8 _ovl_Obj_BeanSegmentRomEnd[];
extern u8 _ovl_Obj_BombiwaSegmentStart[]; extern u8 _ovl_Obj_BombiwaSegmentEnd[]; extern u8 _ovl_Obj_BombiwaSegmentRomStart[]; extern u8 _ovl_Obj_BombiwaSegmentRomEnd[];
extern u8 _ovl_Obj_SwitchSegmentStart[]; extern u8 _ovl_Obj_SwitchSegmentEnd[]; extern u8 _ovl_Obj_SwitchSegmentRomStart[]; extern u8 _ovl_Obj_SwitchSegmentRomEnd[];
extern u8 _ovl_Obj_ElevatorSegmentStart[]; extern u8 _ovl_Obj_ElevatorSegmentEnd[]; extern u8 _ovl_Obj_ElevatorSegmentRomStart[]; extern u8 _ovl_Obj_ElevatorSegmentRomEnd[];
extern u8 _ovl_Obj_LiftSegmentStart[]; extern u8 _ovl_Obj_LiftSegmentEnd[]; extern u8 _ovl_Obj_LiftSegmentRomStart[]; extern u8 _ovl_Obj_LiftSegmentRomEnd[];
extern u8 _ovl_Obj_HsblockSegmentStart[]; extern u8 _ovl_Obj_HsblockSegmentEnd[]; extern u8 _ovl_Obj_HsblockSegmentRomStart[]; extern u8 _ovl_Obj_HsblockSegmentRomEnd[];
extern u8 _ovl_En_Okarina_TagSegmentStart[]; extern u8 _ovl_En_Okarina_TagSegmentEnd[]; extern u8 _ovl_En_Okarina_TagSegmentRomStart[]; extern u8 _ovl_En_Okarina_TagSegmentRomEnd[];
extern u8 _ovl_En_Yabusame_MarkSegmentStart[]; extern u8 _ovl_En_Yabusame_MarkSegmentEnd[]; extern u8 _ovl_En_Yabusame_MarkSegmentRomStart[]; extern u8 _ovl_En_Yabusame_MarkSegmentRomEnd[];
extern u8 _ovl_En_GoroiwaSegmentStart[]; extern u8 _ovl_En_GoroiwaSegmentEnd[]; extern u8 _ovl_En_GoroiwaSegmentRomStart[]; extern u8 _ovl_En_GoroiwaSegmentRomEnd[];
extern u8 _ovl_En_Ex_RuppySegmentStart[]; extern u8 _ovl_En_Ex_RuppySegmentEnd[]; extern u8 _ovl_En_Ex_RuppySegmentRomStart[]; extern u8 _ovl_En_Ex_RuppySegmentRomEnd[];
extern u8 _ovl_En_ToryoSegmentStart[]; extern u8 _ovl_En_ToryoSegmentEnd[]; extern u8 _ovl_En_ToryoSegmentRomStart[]; extern u8 _ovl_En_ToryoSegmentRomEnd[];
extern u8 _ovl_En_DaikuSegmentStart[]; extern u8 _ovl_En_DaikuSegmentEnd[]; extern u8 _ovl_En_DaikuSegmentRomStart[]; extern u8 _ovl_En_DaikuSegmentRomEnd[];
extern u8 _ovl_En_NwcSegmentStart[]; extern u8 _ovl_En_NwcSegmentEnd[]; extern u8 _ovl_En_NwcSegmentRomStart[]; extern u8 _ovl_En_NwcSegmentRomEnd[];
extern u8 _ovl_En_BlkobjSegmentStart[]; extern u8 _ovl_En_BlkobjSegmentEnd[]; extern u8 _ovl_En_BlkobjSegmentRomStart[]; extern u8 _ovl_En_BlkobjSegmentRomEnd[];
extern u8 _ovl_Item_InboxSegmentStart[]; extern u8 _ovl_Item_InboxSegmentEnd[]; extern u8 _ovl_Item_InboxSegmentRomStart[]; extern u8 _ovl_Item_InboxSegmentRomEnd[];
extern u8 _ovl_En_Ge1SegmentStart[]; extern u8 _ovl_En_Ge1SegmentEnd[]; extern u8 _ovl_En_Ge1SegmentRomStart[]; extern u8 _ovl_En_Ge1SegmentRomEnd[];
extern u8 _ovl_Obj_BlockstopSegmentStart[]; extern u8 _ovl_Obj_BlockstopSegmentEnd[]; extern u8 _ovl_Obj_BlockstopSegmentRomStart[]; extern u8 _ovl_Obj_BlockstopSegmentRomEnd[];
extern u8 _ovl_En_SdaSegmentStart[]; extern u8 _ovl_En_SdaSegmentEnd[]; extern u8 _ovl_En_SdaSegmentRomStart[]; extern u8 _ovl_En_SdaSegmentRomEnd[];
extern u8 _ovl_En_Clear_TagSegmentStart[]; extern u8 _ovl_En_Clear_TagSegmentEnd[]; extern u8 _ovl_En_Clear_TagSegmentRomStart[]; extern u8 _ovl_En_Clear_TagSegmentRomEnd[];
extern u8 _ovl_En_Niw_LadySegmentStart[]; extern u8 _ovl_En_Niw_LadySegmentEnd[]; extern u8 _ovl_En_Niw_LadySegmentRomStart[]; extern u8 _ovl_En_Niw_LadySegmentRomEnd[];
extern u8 _ovl_En_GmSegmentStart[]; extern u8 _ovl_En_GmSegmentEnd[]; extern u8 _ovl_En_GmSegmentRomStart[]; extern u8 _ovl_En_GmSegmentRomEnd[];
extern u8 _ovl_En_MsSegmentStart[]; extern u8 _ovl_En_MsSegmentEnd[]; extern u8 _ovl_En_MsSegmentRomStart[]; extern u8 _ovl_En_MsSegmentRomEnd[];
extern u8 _ovl_En_HsSegmentStart[]; extern u8 _ovl_En_HsSegmentEnd[]; extern u8 _ovl_En_HsSegmentRomStart[]; extern u8 _ovl_En_HsSegmentRomEnd[];
extern u8 _ovl_Bg_IngateSegmentStart[]; extern u8 _ovl_Bg_IngateSegmentEnd[]; extern u8 _ovl_Bg_IngateSegmentRomStart[]; extern u8 _ovl_Bg_IngateSegmentRomEnd[];
extern u8 _ovl_En_KanbanSegmentStart[]; extern u8 _ovl_En_KanbanSegmentEnd[]; extern u8 _ovl_En_KanbanSegmentRomStart[]; extern u8 _ovl_En_KanbanSegmentRomEnd[];
extern u8 _ovl_En_Heishi3SegmentStart[]; extern u8 _ovl_En_Heishi3SegmentEnd[]; extern u8 _ovl_En_Heishi3SegmentRomStart[]; extern u8 _ovl_En_Heishi3SegmentRomEnd[];
extern u8 _ovl_En_Syateki_NiwSegmentStart[]; extern u8 _ovl_En_Syateki_NiwSegmentEnd[]; extern u8 _ovl_En_Syateki_NiwSegmentRomStart[]; extern u8 _ovl_En_Syateki_NiwSegmentRomEnd[];
extern u8 _ovl_En_Attack_NiwSegmentStart[]; extern u8 _ovl_En_Attack_NiwSegmentEnd[]; extern u8 _ovl_En_Attack_NiwSegmentRomStart[]; extern u8 _ovl_En_Attack_NiwSegmentRomEnd[];
extern u8 _ovl_Bg_Spot01_IdosokoSegmentStart[]; extern u8 _ovl_Bg_Spot01_IdosokoSegmentEnd[]; extern u8 _ovl_Bg_Spot01_IdosokoSegmentRomStart[]; extern u8 _ovl_Bg_Spot01_IdosokoSegmentRomEnd[];
extern u8 _ovl_En_SaSegmentStart[]; extern u8 _ovl_En_SaSegmentEnd[]; extern u8 _ovl_En_SaSegmentRomStart[]; extern u8 _ovl_En_SaSegmentRomEnd[];
extern u8 _ovl_En_Wonder_TalkSegmentStart[]; extern u8 _ovl_En_Wonder_TalkSegmentEnd[]; extern u8 _ovl_En_Wonder_TalkSegmentRomStart[]; extern u8 _ovl_En_Wonder_TalkSegmentRomEnd[];
extern u8 _ovl_Bg_Gjyo_BridgeSegmentStart[]; extern u8 _ovl_Bg_Gjyo_BridgeSegmentEnd[]; extern u8 _ovl_Bg_Gjyo_BridgeSegmentRomStart[]; extern u8 _ovl_Bg_Gjyo_BridgeSegmentRomEnd[];
extern u8 _ovl_En_DsSegmentStart[]; extern u8 _ovl_En_DsSegmentEnd[]; extern u8 _ovl_En_DsSegmentRomStart[]; extern u8 _ovl_En_DsSegmentRomEnd[];
extern u8 _ovl_En_MkSegmentStart[]; extern u8 _ovl_En_MkSegmentEnd[]; extern u8 _ovl_En_MkSegmentRomStart[]; extern u8 _ovl_En_MkSegmentRomEnd[];
extern u8 _ovl_En_Bom_Bowl_ManSegmentStart[]; extern u8 _ovl_En_Bom_Bowl_ManSegmentEnd[]; extern u8 _ovl_En_Bom_Bowl_ManSegmentRomStart[]; extern u8 _ovl_En_Bom_Bowl_ManSegmentRomEnd[];
extern u8 _ovl_En_Bom_Bowl_PitSegmentStart[]; extern u8 _ovl_En_Bom_Bowl_PitSegmentEnd[]; extern u8 _ovl_En_Bom_Bowl_PitSegmentRomStart[]; extern u8 _ovl_En_Bom_Bowl_PitSegmentRomEnd[];
extern u8 _ovl_En_OwlSegmentStart[]; extern u8 _ovl_En_OwlSegmentEnd[]; extern u8 _ovl_En_OwlSegmentRomStart[]; extern u8 _ovl_En_OwlSegmentRomEnd[];
extern u8 _ovl_En_IshiSegmentStart[]; extern u8 _ovl_En_IshiSegmentEnd[]; extern u8 _ovl_En_IshiSegmentRomStart[]; extern u8 _ovl_En_IshiSegmentRomEnd[];
extern u8 _ovl_Obj_HanaSegmentStart[]; extern u8 _ovl_Obj_HanaSegmentEnd[]; extern u8 _ovl_Obj_HanaSegmentRomStart[]; extern u8 _ovl_Obj_HanaSegmentRomEnd[];
extern u8 _ovl_Obj_LightswitchSegmentStart[]; extern u8 _ovl_Obj_LightswitchSegmentEnd[]; extern u8 _ovl_Obj_LightswitchSegmentRomStart[]; extern u8 _ovl_Obj_LightswitchSegmentRomEnd[];
extern u8 _ovl_Obj_Mure2SegmentStart[]; extern u8 _ovl_Obj_Mure2SegmentEnd[]; extern u8 _ovl_Obj_Mure2SegmentRomStart[]; extern u8 _ovl_Obj_Mure2SegmentRomEnd[];
extern u8 _ovl_En_GoSegmentStart[]; extern u8 _ovl_En_GoSegmentEnd[]; extern u8 _ovl_En_GoSegmentRomStart[]; extern u8 _ovl_En_GoSegmentRomEnd[];
extern u8 _ovl_En_FuSegmentStart[]; extern u8 _ovl_En_FuSegmentEnd[]; extern u8 _ovl_En_FuSegmentRomStart[]; extern u8 _ovl_En_FuSegmentRomEnd[];
extern u8 _ovl_En_ChangerSegmentStart[]; extern u8 _ovl_En_ChangerSegmentEnd[]; extern u8 _ovl_En_ChangerSegmentRomStart[]; extern u8 _ovl_En_ChangerSegmentRomEnd[];
extern u8 _ovl_Bg_Jya_MegamiSegmentStart[]; extern u8 _ovl_Bg_Jya_MegamiSegmentEnd[]; extern u8 _ovl_Bg_Jya_MegamiSegmentRomStart[]; extern u8 _ovl_Bg_Jya_MegamiSegmentRomEnd[];
extern u8 _ovl_Bg_Jya_LiftSegmentStart[]; extern u8 _ovl_Bg_Jya_LiftSegmentEnd[]; extern u8 _ovl_Bg_Jya_LiftSegmentRomStart[]; extern u8 _ovl_Bg_Jya_LiftSegmentRomEnd[];
extern u8 _ovl_Bg_Jya_BigmirrorSegmentStart[]; extern u8 _ovl_Bg_Jya_BigmirrorSegmentEnd[]; extern u8 _ovl_Bg_Jya_BigmirrorSegmentRomStart[]; extern u8 _ovl_Bg_Jya_BigmirrorSegmentRomEnd[];
extern u8 _ovl_Bg_Jya_BombchuiwaSegmentStart[]; extern u8 _ovl_Bg_Jya_BombchuiwaSegmentEnd[]; extern u8 _ovl_Bg_Jya_BombchuiwaSegmentRomStart[]; extern u8 _ovl_Bg_Jya_BombchuiwaSegmentRomEnd[];
extern u8 _ovl_Bg_Jya_AmishutterSegmentStart[]; extern u8 _ovl_Bg_Jya_AmishutterSegmentEnd[]; extern u8 _ovl_Bg_Jya_AmishutterSegmentRomStart[]; extern u8 _ovl_Bg_Jya_AmishutterSegmentRomEnd[];
extern u8 _ovl_Bg_Jya_BombiwaSegmentStart[]; extern u8 _ovl_Bg_Jya_BombiwaSegmentEnd[]; extern u8 _ovl_Bg_Jya_BombiwaSegmentRomStart[]; extern u8 _ovl_Bg_Jya_BombiwaSegmentRomEnd[];
extern u8 _ovl_Bg_Spot18_BasketSegmentStart[]; extern u8 _ovl_Bg_Spot18_BasketSegmentEnd[]; extern u8 _ovl_Bg_Spot18_BasketSegmentRomStart[]; extern u8 _ovl_Bg_Spot18_BasketSegmentRomEnd[];
extern u8 _ovl_En_Ganon_OrganSegmentStart[]; extern u8 _ovl_En_Ganon_OrganSegmentEnd[]; extern u8 _ovl_En_Ganon_OrganSegmentRomStart[]; extern u8 _ovl_En_Ganon_OrganSegmentRomEnd[];
extern u8 _ovl_En_SiofukiSegmentStart[]; extern u8 _ovl_En_SiofukiSegmentEnd[]; extern u8 _ovl_En_SiofukiSegmentRomStart[]; extern u8 _ovl_En_SiofukiSegmentRomEnd[];
extern u8 _ovl_En_StreamSegmentStart[]; extern u8 _ovl_En_StreamSegmentEnd[]; extern u8 _ovl_En_StreamSegmentRomStart[]; extern u8 _ovl_En_StreamSegmentRomEnd[];
extern u8 _ovl_En_MmSegmentStart[]; extern u8 _ovl_En_MmSegmentEnd[]; extern u8 _ovl_En_MmSegmentRomStart[]; extern u8 _ovl_En_MmSegmentRomEnd[];
extern u8 _ovl_En_KoSegmentStart[]; extern u8 _ovl_En_KoSegmentEnd[]; extern u8 _ovl_En_KoSegmentRomStart[]; extern u8 _ovl_En_KoSegmentRomEnd[];
extern u8 _ovl_En_KzSegmentStart[]; extern u8 _ovl_En_KzSegmentEnd[]; extern u8 _ovl_En_KzSegmentRomStart[]; extern u8 _ovl_En_KzSegmentRomEnd[];
extern u8 _ovl_En_Weather_TagSegmentStart[]; extern u8 _ovl_En_Weather_TagSegmentEnd[]; extern u8 _ovl_En_Weather_TagSegmentRomStart[]; extern u8 _ovl_En_Weather_TagSegmentRomEnd[];
extern u8 _ovl_Bg_Sst_FloorSegmentStart[]; extern u8 _ovl_Bg_Sst_FloorSegmentEnd[]; extern u8 _ovl_Bg_Sst_FloorSegmentRomStart[]; extern u8 _ovl_Bg_Sst_FloorSegmentRomEnd[];
extern u8 _ovl_En_AniSegmentStart[]; extern u8 _ovl_En_AniSegmentEnd[]; extern u8 _ovl_En_AniSegmentRomStart[]; extern u8 _ovl_En_AniSegmentRomEnd[];
extern u8 _ovl_En_Ex_ItemSegmentStart[]; extern u8 _ovl_En_Ex_ItemSegmentEnd[]; extern u8 _ovl_En_Ex_ItemSegmentRomStart[]; extern u8 _ovl_En_Ex_ItemSegmentRomEnd[];
extern u8 _ovl_Bg_Jya_IronobjSegmentStart[]; extern u8 _ovl_Bg_Jya_IronobjSegmentEnd[]; extern u8 _ovl_Bg_Jya_IronobjSegmentRomStart[]; extern u8 _ovl_Bg_Jya_IronobjSegmentRomEnd[];
extern u8 _ovl_En_JsSegmentStart[]; extern u8 _ovl_En_JsSegmentEnd[]; extern u8 _ovl_En_JsSegmentRomStart[]; extern u8 _ovl_En_JsSegmentRomEnd[];
extern u8 _ovl_En_JsjutanSegmentStart[]; extern u8 _ovl_En_JsjutanSegmentEnd[]; extern u8 _ovl_En_JsjutanSegmentRomStart[]; extern u8 _ovl_En_JsjutanSegmentRomEnd[];
extern u8 _ovl_En_CsSegmentStart[]; extern u8 _ovl_En_CsSegmentEnd[]; extern u8 _ovl_En_CsSegmentRomStart[]; extern u8 _ovl_En_CsSegmentRomEnd[];
extern u8 _ovl_En_MdSegmentStart[]; extern u8 _ovl_En_MdSegmentEnd[]; extern u8 _ovl_En_MdSegmentRomStart[]; extern u8 _ovl_En_MdSegmentRomEnd[];
extern u8 _ovl_En_HySegmentStart[]; extern u8 _ovl_En_HySegmentEnd[]; extern u8 _ovl_En_HySegmentRomStart[]; extern u8 _ovl_En_HySegmentRomEnd[];
extern u8 _ovl_En_Ganon_MantSegmentStart[]; extern u8 _ovl_En_Ganon_MantSegmentEnd[]; extern u8 _ovl_En_Ganon_MantSegmentRomStart[]; extern u8 _ovl_En_Ganon_MantSegmentRomEnd[];
extern u8 _ovl_En_Okarina_EffectSegmentStart[]; extern u8 _ovl_En_Okarina_EffectSegmentEnd[]; extern u8 _ovl_En_Okarina_EffectSegmentRomStart[]; extern u8 _ovl_En_Okarina_EffectSegmentRomEnd[];
extern u8 _ovl_En_MagSegmentStart[]; extern u8 _ovl_En_MagSegmentEnd[]; extern u8 _ovl_En_MagSegmentRomStart[]; extern u8 _ovl_En_MagSegmentRomEnd[];
extern u8 _ovl_Door_GerudoSegmentStart[]; extern u8 _ovl_Door_GerudoSegmentEnd[]; extern u8 _ovl_Door_GerudoSegmentRomStart[]; extern u8 _ovl_Door_GerudoSegmentRomEnd[];
extern u8 _ovl_Elf_Msg2SegmentStart[]; extern u8 _ovl_Elf_Msg2SegmentEnd[]; extern u8 _ovl_Elf_Msg2SegmentRomStart[]; extern u8 _ovl_Elf_Msg2SegmentRomEnd[];
extern u8 _ovl_Demo_GtSegmentStart[]; extern u8 _ovl_Demo_GtSegmentEnd[]; extern u8 _ovl_Demo_GtSegmentRomStart[]; extern u8 _ovl_Demo_GtSegmentRomEnd[];
extern u8 _ovl_En_Po_FieldSegmentStart[]; extern u8 _ovl_En_Po_FieldSegmentEnd[]; extern u8 _ovl_En_Po_FieldSegmentRomStart[]; extern u8 _ovl_En_Po_FieldSegmentRomEnd[];
extern u8 _ovl_Efc_ErupcSegmentStart[]; extern u8 _ovl_Efc_ErupcSegmentEnd[]; extern u8 _ovl_Efc_ErupcSegmentRomStart[]; extern u8 _ovl_Efc_ErupcSegmentRomEnd[];
extern u8 _ovl_Bg_ZgSegmentStart[]; extern u8 _ovl_Bg_ZgSegmentEnd[]; extern u8 _ovl_Bg_ZgSegmentRomStart[]; extern u8 _ovl_Bg_ZgSegmentRomEnd[];
extern u8 _ovl_En_Heishi4SegmentStart[]; extern u8 _ovl_En_Heishi4SegmentEnd[]; extern u8 _ovl_En_Heishi4SegmentRomStart[]; extern u8 _ovl_En_Heishi4SegmentRomEnd[];
extern u8 _ovl_En_Zl3SegmentStart[]; extern u8 _ovl_En_Zl3SegmentEnd[]; extern u8 _ovl_En_Zl3SegmentRomStart[]; extern u8 _ovl_En_Zl3SegmentRomEnd[];
extern u8 _ovl_Boss_Ganon2SegmentStart[]; extern u8 _ovl_Boss_Ganon2SegmentEnd[]; extern u8 _ovl_Boss_Ganon2SegmentRomStart[]; extern u8 _ovl_Boss_Ganon2SegmentRomEnd[];
extern u8 _ovl_En_KakasiSegmentStart[]; extern u8 _ovl_En_KakasiSegmentEnd[]; extern u8 _ovl_En_KakasiSegmentRomStart[]; extern u8 _ovl_En_KakasiSegmentRomEnd[];
extern u8 _ovl_En_Takara_ManSegmentStart[]; extern u8 _ovl_En_Takara_ManSegmentEnd[]; extern u8 _ovl_En_Takara_ManSegmentRomStart[]; extern u8 _ovl_En_Takara_ManSegmentRomEnd[];
extern u8 _ovl_Obj_MakeoshihikiSegmentStart[]; extern u8 _ovl_Obj_MakeoshihikiSegmentEnd[]; extern u8 _ovl_Obj_MakeoshihikiSegmentRomStart[]; extern u8 _ovl_Obj_MakeoshihikiSegmentRomEnd[];
extern u8 _ovl_Oceff_SpotSegmentStart[]; extern u8 _ovl_Oceff_SpotSegmentEnd[]; extern u8 _ovl_Oceff_SpotSegmentRomStart[]; extern u8 _ovl_Oceff_SpotSegmentRomEnd[];
extern u8 _ovl_End_TitleSegmentStart[]; extern u8 _ovl_End_TitleSegmentEnd[]; extern u8 _ovl_End_TitleSegmentRomStart[]; extern u8 _ovl_End_TitleSegmentRomEnd[];
extern u8 _ovl_En_TorchSegmentStart[]; extern u8 _ovl_En_TorchSegmentEnd[]; extern u8 _ovl_En_TorchSegmentRomStart[]; extern u8 _ovl_En_TorchSegmentRomEnd[];
extern u8 _ovl_Demo_EcSegmentStart[]; extern u8 _ovl_Demo_EcSegmentEnd[]; extern u8 _ovl_Demo_EcSegmentRomStart[]; extern u8 _ovl_Demo_EcSegmentRomEnd[];
extern u8 _ovl_Shot_SunSegmentStart[]; extern u8 _ovl_Shot_SunSegmentEnd[]; extern u8 _ovl_Shot_SunSegmentRomStart[]; extern u8 _ovl_Shot_SunSegmentRomEnd[];
extern u8 _ovl_En_Dy_ExtraSegmentStart[]; extern u8 _ovl_En_Dy_ExtraSegmentEnd[]; extern u8 _ovl_En_Dy_ExtraSegmentRomStart[]; extern u8 _ovl_En_Dy_ExtraSegmentRomEnd[];
extern u8 _ovl_En_Wonder_Talk2SegmentStart[]; extern u8 _ovl_En_Wonder_Talk2SegmentEnd[]; extern u8 _ovl_En_Wonder_Talk2SegmentRomStart[]; extern u8 _ovl_En_Wonder_Talk2SegmentRomEnd[];
extern u8 _ovl_En_Ge2SegmentStart[]; extern u8 _ovl_En_Ge2SegmentEnd[]; extern u8 _ovl_En_Ge2SegmentRomStart[]; extern u8 _ovl_En_Ge2SegmentRomEnd[];
extern u8 _ovl_Obj_RoomtimerSegmentStart[]; extern u8 _ovl_Obj_RoomtimerSegmentEnd[]; extern u8 _ovl_Obj_RoomtimerSegmentRomStart[]; extern u8 _ovl_Obj_RoomtimerSegmentRomEnd[];
extern u8 _ovl_En_SshSegmentStart[]; extern u8 _ovl_En_SshSegmentEnd[]; extern u8 _ovl_En_SshSegmentRomStart[]; extern u8 _ovl_En_SshSegmentRomEnd[];
extern u8 _ovl_En_SthSegmentStart[]; extern u8 _ovl_En_SthSegmentEnd[]; extern u8 _ovl_En_SthSegmentRomStart[]; extern u8 _ovl_En_SthSegmentRomEnd[];
extern u8 _ovl_Oceff_WipeSegmentStart[]; extern u8 _ovl_Oceff_WipeSegmentEnd[]; extern u8 _ovl_Oceff_WipeSegmentRomStart[]; extern u8 _ovl_Oceff_WipeSegmentRomEnd[];
extern u8 _ovl_Oceff_StormSegmentStart[]; extern u8 _ovl_Oceff_StormSegmentEnd[]; extern u8 _ovl_Oceff_StormSegmentRomStart[]; extern u8 _ovl_Oceff_StormSegmentRomEnd[];
extern u8 _ovl_En_WeiyerSegmentStart[]; extern u8 _ovl_En_WeiyerSegmentEnd[]; extern u8 _ovl_En_WeiyerSegmentRomStart[]; extern u8 _ovl_En_WeiyerSegmentRomEnd[];
extern u8 _ovl_Bg_Spot05_SokoSegmentStart[]; extern u8 _ovl_Bg_Spot05_SokoSegmentEnd[]; extern u8 _ovl_Bg_Spot05_SokoSegmentRomStart[]; extern u8 _ovl_Bg_Spot05_SokoSegmentRomEnd[];
extern u8 _ovl_Bg_Jya_1fliftSegmentStart[]; extern u8 _ovl_Bg_Jya_1fliftSegmentEnd[]; extern u8 _ovl_Bg_Jya_1fliftSegmentRomStart[]; extern u8 _ovl_Bg_Jya_1fliftSegmentRomEnd[];
extern u8 _ovl_Bg_Jya_HahenironSegmentStart[]; extern u8 _ovl_Bg_Jya_HahenironSegmentEnd[]; extern u8 _ovl_Bg_Jya_HahenironSegmentRomStart[]; extern u8 _ovl_Bg_Jya_HahenironSegmentRomEnd[];
extern u8 _ovl_Bg_Spot12_GateSegmentStart[]; extern u8 _ovl_Bg_Spot12_GateSegmentEnd[]; extern u8 _ovl_Bg_Spot12_GateSegmentRomStart[]; extern u8 _ovl_Bg_Spot12_GateSegmentRomEnd[];
extern u8 _ovl_Bg_Spot12_SakuSegmentStart[]; extern u8 _ovl_Bg_Spot12_SakuSegmentEnd[]; extern u8 _ovl_Bg_Spot12_SakuSegmentRomStart[]; extern u8 _ovl_Bg_Spot12_SakuSegmentRomEnd[];
extern u8 _ovl_En_HintnutsSegmentStart[]; extern u8 _ovl_En_HintnutsSegmentEnd[]; extern u8 _ovl_En_HintnutsSegmentRomStart[]; extern u8 _ovl_En_HintnutsSegmentRomEnd[];
extern u8 _ovl_En_NutsballSegmentStart[]; extern u8 _ovl_En_NutsballSegmentEnd[]; extern u8 _ovl_En_NutsballSegmentRomStart[]; extern u8 _ovl_En_NutsballSegmentRomEnd[];
extern u8 _ovl_Bg_Spot00_BreakSegmentStart[]; extern u8 _ovl_Bg_Spot00_BreakSegmentEnd[]; extern u8 _ovl_Bg_Spot00_BreakSegmentRomStart[]; extern u8 _ovl_Bg_Spot00_BreakSegmentRomEnd[];
extern u8 _ovl_En_ShopnutsSegmentStart[]; extern u8 _ovl_En_ShopnutsSegmentEnd[]; extern u8 _ovl_En_ShopnutsSegmentRomStart[]; extern u8 _ovl_En_ShopnutsSegmentRomEnd[];
extern u8 _ovl_En_ItSegmentStart[]; extern u8 _ovl_En_ItSegmentEnd[]; extern u8 _ovl_En_ItSegmentRomStart[]; extern u8 _ovl_En_ItSegmentRomEnd[];
extern u8 _ovl_En_GeldBSegmentStart[]; extern u8 _ovl_En_GeldBSegmentEnd[]; extern u8 _ovl_En_GeldBSegmentRomStart[]; extern u8 _ovl_En_GeldBSegmentRomEnd[];
extern u8 _ovl_Oceff_Wipe2SegmentStart[]; extern u8 _ovl_Oceff_Wipe2SegmentEnd[]; extern u8 _ovl_Oceff_Wipe2SegmentRomStart[]; extern u8 _ovl_Oceff_Wipe2SegmentRomEnd[];
extern u8 _ovl_Oceff_Wipe3SegmentStart[]; extern u8 _ovl_Oceff_Wipe3SegmentEnd[]; extern u8 _ovl_Oceff_Wipe3SegmentRomStart[]; extern u8 _ovl_Oceff_Wipe3SegmentRomEnd[];
extern u8 _ovl_En_Niw_GirlSegmentStart[]; extern u8 _ovl_En_Niw_GirlSegmentEnd[]; extern u8 _ovl_En_Niw_GirlSegmentRomStart[]; extern u8 _ovl_En_Niw_GirlSegmentRomEnd[];
extern u8 _ovl_En_DogSegmentStart[]; extern u8 _ovl_En_DogSegmentEnd[]; extern u8 _ovl_En_DogSegmentRomStart[]; extern u8 _ovl_En_DogSegmentRomEnd[];
extern u8 _ovl_En_SiSegmentStart[]; extern u8 _ovl_En_SiSegmentEnd[]; extern u8 _ovl_En_SiSegmentRomStart[]; extern u8 _ovl_En_SiSegmentRomEnd[];
extern u8 _ovl_Bg_Spot01_Objects2SegmentStart[]; extern u8 _ovl_Bg_Spot01_Objects2SegmentEnd[]; extern u8 _ovl_Bg_Spot01_Objects2SegmentRomStart[]; extern u8 _ovl_Bg_Spot01_Objects2SegmentRomEnd[];
extern u8 _ovl_Obj_CombSegmentStart[]; extern u8 _ovl_Obj_CombSegmentEnd[]; extern u8 _ovl_Obj_CombSegmentRomStart[]; extern u8 _ovl_Obj_CombSegmentRomEnd[];
extern u8 _ovl_Bg_Spot11_BakudankabeSegmentStart[]; extern u8 _ovl_Bg_Spot11_BakudankabeSegmentEnd[]; extern u8 _ovl_Bg_Spot11_BakudankabeSegmentRomStart[]; extern u8 _ovl_Bg_Spot11_BakudankabeSegmentRomEnd[];
extern u8 _ovl_Obj_Kibako2SegmentStart[]; extern u8 _ovl_Obj_Kibako2SegmentEnd[]; extern u8 _ovl_Obj_Kibako2SegmentRomStart[]; extern u8 _ovl_Obj_Kibako2SegmentRomEnd[];
extern u8 _ovl_En_Dnt_DemoSegmentStart[]; extern u8 _ovl_En_Dnt_DemoSegmentEnd[]; extern u8 _ovl_En_Dnt_DemoSegmentRomStart[]; extern u8 _ovl_En_Dnt_DemoSegmentRomEnd[];
extern u8 _ovl_En_Dnt_JijiSegmentStart[]; extern u8 _ovl_En_Dnt_JijiSegmentEnd[]; extern u8 _ovl_En_Dnt_JijiSegmentRomStart[]; extern u8 _ovl_En_Dnt_JijiSegmentRomEnd[];
extern u8 _ovl_En_Dnt_NomalSegmentStart[]; extern u8 _ovl_En_Dnt_NomalSegmentEnd[]; extern u8 _ovl_En_Dnt_NomalSegmentRomStart[]; extern u8 _ovl_En_Dnt_NomalSegmentRomEnd[];
extern u8 _ovl_En_GuestSegmentStart[]; extern u8 _ovl_En_GuestSegmentEnd[]; extern u8 _ovl_En_GuestSegmentRomStart[]; extern u8 _ovl_En_GuestSegmentRomEnd[];
extern u8 _ovl_Bg_Bom_GuardSegmentStart[]; extern u8 _ovl_Bg_Bom_GuardSegmentEnd[]; extern u8 _ovl_Bg_Bom_GuardSegmentRomStart[]; extern u8 _ovl_Bg_Bom_GuardSegmentRomEnd[];
extern u8 _ovl_En_Hs2SegmentStart[]; extern u8 _ovl_En_Hs2SegmentEnd[]; extern u8 _ovl_En_Hs2SegmentRomStart[]; extern u8 _ovl_En_Hs2SegmentRomEnd[];
extern u8 _ovl_Demo_KekkaiSegmentStart[]; extern u8 _ovl_Demo_KekkaiSegmentEnd[]; extern u8 _ovl_Demo_KekkaiSegmentRomStart[]; extern u8 _ovl_Demo_KekkaiSegmentRomEnd[];
extern u8 _ovl_Bg_Spot08_BakudankabeSegmentStart[]; extern u8 _ovl_Bg_Spot08_BakudankabeSegmentEnd[]; extern u8 _ovl_Bg_Spot08_BakudankabeSegmentRomStart[]; extern u8 _ovl_Bg_Spot08_BakudankabeSegmentRomEnd[];
extern u8 _ovl_Bg_Spot17_BakudankabeSegmentStart[]; extern u8 _ovl_Bg_Spot17_BakudankabeSegmentEnd[]; extern u8 _ovl_Bg_Spot17_BakudankabeSegmentRomStart[]; extern u8 _ovl_Bg_Spot17_BakudankabeSegmentRomEnd[];
extern u8 _ovl_Obj_Mure3SegmentStart[]; extern u8 _ovl_Obj_Mure3SegmentEnd[]; extern u8 _ovl_Obj_Mure3SegmentRomStart[]; extern u8 _ovl_Obj_Mure3SegmentRomEnd[];
extern u8 _ovl_En_TgSegmentStart[]; extern u8 _ovl_En_TgSegmentEnd[]; extern u8 _ovl_En_TgSegmentRomStart[]; extern u8 _ovl_En_TgSegmentRomEnd[];
extern u8 _ovl_En_MuSegmentStart[]; extern u8 _ovl_En_MuSegmentEnd[]; extern u8 _ovl_En_MuSegmentRomStart[]; extern u8 _ovl_En_MuSegmentRomEnd[];
extern u8 _ovl_En_Go2SegmentStart[]; extern u8 _ovl_En_Go2SegmentEnd[]; extern u8 _ovl_En_Go2SegmentRomStart[]; extern u8 _ovl_En_Go2SegmentRomEnd[];
extern u8 _ovl_En_WfSegmentStart[]; extern u8 _ovl_En_WfSegmentEnd[]; extern u8 _ovl_En_WfSegmentRomStart[]; extern u8 _ovl_En_WfSegmentRomEnd[];
extern u8 _ovl_En_SkbSegmentStart[]; extern u8 _ovl_En_SkbSegmentEnd[]; extern u8 _ovl_En_SkbSegmentRomStart[]; extern u8 _ovl_En_SkbSegmentRomEnd[];
extern u8 _ovl_Demo_GjSegmentStart[]; extern u8 _ovl_Demo_GjSegmentEnd[]; extern u8 _ovl_Demo_GjSegmentRomStart[]; extern u8 _ovl_Demo_GjSegmentRomEnd[];
extern u8 _ovl_Demo_GeffSegmentStart[]; extern u8 _ovl_Demo_GeffSegmentEnd[]; extern u8 _ovl_Demo_GeffSegmentRomStart[]; extern u8 _ovl_Demo_GeffSegmentRomEnd[];
extern u8 _ovl_Bg_Gnd_FiremeiroSegmentStart[]; extern u8 _ovl_Bg_Gnd_FiremeiroSegmentEnd[]; extern u8 _ovl_Bg_Gnd_FiremeiroSegmentRomStart[]; extern u8 _ovl_Bg_Gnd_FiremeiroSegmentRomEnd[];
extern u8 _ovl_Bg_Gnd_DarkmeiroSegmentStart[]; extern u8 _ovl_Bg_Gnd_DarkmeiroSegmentEnd[]; extern u8 _ovl_Bg_Gnd_DarkmeiroSegmentRomStart[]; extern u8 _ovl_Bg_Gnd_DarkmeiroSegmentRomEnd[];
extern u8 _ovl_Bg_Gnd_SoulmeiroSegmentStart[]; extern u8 _ovl_Bg_Gnd_SoulmeiroSegmentEnd[]; extern u8 _ovl_Bg_Gnd_SoulmeiroSegmentRomStart[]; extern u8 _ovl_Bg_Gnd_SoulmeiroSegmentRomEnd[];
extern u8 _ovl_Bg_Gnd_NisekabeSegmentStart[]; extern u8 _ovl_Bg_Gnd_NisekabeSegmentEnd[]; extern u8 _ovl_Bg_Gnd_NisekabeSegmentRomStart[]; extern u8 _ovl_Bg_Gnd_NisekabeSegmentRomEnd[];
extern u8 _ovl_Bg_Gnd_IceblockSegmentStart[]; extern u8 _ovl_Bg_Gnd_IceblockSegmentEnd[]; extern u8 _ovl_Bg_Gnd_IceblockSegmentRomStart[]; extern u8 _ovl_Bg_Gnd_IceblockSegmentRomEnd[];
extern u8 _ovl_En_GbSegmentStart[]; extern u8 _ovl_En_GbSegmentEnd[]; extern u8 _ovl_En_GbSegmentRomStart[]; extern u8 _ovl_En_GbSegmentRomEnd[];
extern u8 _ovl_En_GsSegmentStart[]; extern u8 _ovl_En_GsSegmentEnd[]; extern u8 _ovl_En_GsSegmentRomStart[]; extern u8 _ovl_En_GsSegmentRomEnd[];
extern u8 _ovl_Bg_Mizu_BwallSegmentStart[]; extern u8 _ovl_Bg_Mizu_BwallSegmentEnd[]; extern u8 _ovl_Bg_Mizu_BwallSegmentRomStart[]; extern u8 _ovl_Bg_Mizu_BwallSegmentRomEnd[];
extern u8 _ovl_Bg_Mizu_ShutterSegmentStart[]; extern u8 _ovl_Bg_Mizu_ShutterSegmentEnd[]; extern u8 _ovl_Bg_Mizu_ShutterSegmentRomStart[]; extern u8 _ovl_Bg_Mizu_ShutterSegmentRomEnd[];
extern u8 _ovl_En_Daiku_KakarikoSegmentStart[]; extern u8 _ovl_En_Daiku_KakarikoSegmentEnd[]; extern u8 _ovl_En_Daiku_KakarikoSegmentRomStart[]; extern u8 _ovl_En_Daiku_KakarikoSegmentRomEnd[];
extern u8 _ovl_Bg_Bowl_WallSegmentStart[]; extern u8 _ovl_Bg_Bowl_WallSegmentEnd[]; extern u8 _ovl_Bg_Bowl_WallSegmentRomStart[]; extern u8 _ovl_Bg_Bowl_WallSegmentRomEnd[];
extern u8 _ovl_En_Wall_TuboSegmentStart[]; extern u8 _ovl_En_Wall_TuboSegmentEnd[]; extern u8 _ovl_En_Wall_TuboSegmentRomStart[]; extern u8 _ovl_En_Wall_TuboSegmentRomEnd[];
extern u8 _ovl_En_Po_DesertSegmentStart[]; extern u8 _ovl_En_Po_DesertSegmentEnd[]; extern u8 _ovl_En_Po_DesertSegmentRomStart[]; extern u8 _ovl_En_Po_DesertSegmentRomEnd[];
extern u8 _ovl_En_CrowSegmentStart[]; extern u8 _ovl_En_CrowSegmentEnd[]; extern u8 _ovl_En_CrowSegmentRomStart[]; extern u8 _ovl_En_CrowSegmentRomEnd[];
extern u8 _ovl_Door_KillerSegmentStart[]; extern u8 _ovl_Door_KillerSegmentEnd[]; extern u8 _ovl_Door_KillerSegmentRomStart[]; extern u8 _ovl_Door_KillerSegmentRomEnd[];
extern u8 _ovl_Bg_Spot11_OasisSegmentStart[]; extern u8 _ovl_Bg_Spot11_OasisSegmentEnd[]; extern u8 _ovl_Bg_Spot11_OasisSegmentRomStart[]; extern u8 _ovl_Bg_Spot11_OasisSegmentRomEnd[];
extern u8 _ovl_Bg_Spot18_FutaSegmentStart[]; extern u8 _ovl_Bg_Spot18_FutaSegmentEnd[]; extern u8 _ovl_Bg_Spot18_FutaSegmentRomStart[]; extern u8 _ovl_Bg_Spot18_FutaSegmentRomEnd[];
extern u8 _ovl_Bg_Spot18_ShutterSegmentStart[]; extern u8 _ovl_Bg_Spot18_ShutterSegmentEnd[]; extern u8 _ovl_Bg_Spot18_ShutterSegmentRomStart[]; extern u8 _ovl_Bg_Spot18_ShutterSegmentRomEnd[];
extern u8 _ovl_En_Ma3SegmentStart[]; extern u8 _ovl_En_Ma3SegmentEnd[]; extern u8 _ovl_En_Ma3SegmentRomStart[]; extern u8 _ovl_En_Ma3SegmentRomEnd[];
extern u8 _ovl_En_CowSegmentStart[]; extern u8 _ovl_En_CowSegmentEnd[]; extern u8 _ovl_En_CowSegmentRomStart[]; extern u8 _ovl_En_CowSegmentRomEnd[];
extern u8 _ovl_Bg_Ice_TuraraSegmentStart[]; extern u8 _ovl_Bg_Ice_TuraraSegmentEnd[]; extern u8 _ovl_Bg_Ice_TuraraSegmentRomStart[]; extern u8 _ovl_Bg_Ice_TuraraSegmentRomEnd[];
extern u8 _ovl_Bg_Ice_ShutterSegmentStart[]; extern u8 _ovl_Bg_Ice_ShutterSegmentEnd[]; extern u8 _ovl_Bg_Ice_ShutterSegmentRomStart[]; extern u8 _ovl_Bg_Ice_ShutterSegmentRomEnd[];
extern u8 _ovl_En_Kakasi2SegmentStart[]; extern u8 _ovl_En_Kakasi2SegmentEnd[]; extern u8 _ovl_En_Kakasi2SegmentRomStart[]; extern u8 _ovl_En_Kakasi2SegmentRomEnd[];
extern u8 _ovl_En_Kakasi3SegmentStart[]; extern u8 _ovl_En_Kakasi3SegmentEnd[]; extern u8 _ovl_En_Kakasi3SegmentRomStart[]; extern u8 _ovl_En_Kakasi3SegmentRomEnd[];
extern u8 _ovl_Oceff_Wipe4SegmentStart[]; extern u8 _ovl_Oceff_Wipe4SegmentEnd[]; extern u8 _ovl_Oceff_Wipe4SegmentRomStart[]; extern u8 _ovl_Oceff_Wipe4SegmentRomEnd[];
extern u8 _ovl_En_EgSegmentStart[]; extern u8 _ovl_En_EgSegmentEnd[]; extern u8 _ovl_En_EgSegmentRomStart[]; extern u8 _ovl_En_EgSegmentRomEnd[];
extern u8 _ovl_Bg_Menkuri_NisekabeSegmentStart[]; extern u8 _ovl_Bg_Menkuri_NisekabeSegmentEnd[]; extern u8 _ovl_Bg_Menkuri_NisekabeSegmentRomStart[]; extern u8 _ovl_Bg_Menkuri_NisekabeSegmentRomEnd[];
extern u8 _ovl_En_ZoSegmentStart[]; extern u8 _ovl_En_ZoSegmentEnd[]; extern u8 _ovl_En_ZoSegmentRomStart[]; extern u8 _ovl_En_ZoSegmentRomEnd[];
extern u8 _ovl_Obj_MakekinsutaSegmentStart[]; extern u8 _ovl_Obj_MakekinsutaSegmentEnd[]; extern u8 _ovl_Obj_MakekinsutaSegmentRomStart[]; extern u8 _ovl_Obj_MakekinsutaSegmentRomEnd[];
extern u8 _ovl_En_Ge3SegmentStart[]; extern u8 _ovl_En_Ge3SegmentEnd[]; extern u8 _ovl_En_Ge3SegmentRomStart[]; extern u8 _ovl_En_Ge3SegmentRomEnd[];
extern u8 _ovl_Obj_TimeblockSegmentStart[]; extern u8 _ovl_Obj_TimeblockSegmentEnd[]; extern u8 _ovl_Obj_TimeblockSegmentRomStart[]; extern u8 _ovl_Obj_TimeblockSegmentRomEnd[];
extern u8 _ovl_Obj_HamishiSegmentStart[]; extern u8 _ovl_Obj_HamishiSegmentEnd[]; extern u8 _ovl_Obj_HamishiSegmentRomStart[]; extern u8 _ovl_Obj_HamishiSegmentRomEnd[];
extern u8 _ovl_En_Zl4SegmentStart[]; extern u8 _ovl_En_Zl4SegmentEnd[]; extern u8 _ovl_En_Zl4SegmentRomStart[]; extern u8 _ovl_En_Zl4SegmentRomEnd[];
extern u8 _ovl_En_Mm2SegmentStart[]; extern u8 _ovl_En_Mm2SegmentEnd[]; extern u8 _ovl_En_Mm2SegmentRomStart[]; extern u8 _ovl_En_Mm2SegmentRomEnd[];
extern u8 _ovl_Bg_Jya_BlockSegmentStart[]; extern u8 _ovl_Bg_Jya_BlockSegmentEnd[]; extern u8 _ovl_Bg_Jya_BlockSegmentRomStart[]; extern u8 _ovl_Bg_Jya_BlockSegmentRomEnd[];
extern u8 _ovl_Obj_Warp2blockSegmentStart[]; extern u8 _ovl_Obj_Warp2blockSegmentEnd[]; extern u8 _ovl_Obj_Warp2blockSegmentRomStart[]; extern u8 _ovl_Obj_Warp2blockSegmentRomEnd[];
extern u8 _gameplay_keepSegmentRomStart[]; extern u8 _gameplay_keepSegmentRomEnd[];
extern u8 _gameplay_field_keepSegmentRomStart[]; extern u8 _gameplay_field_keepSegmentRomEnd[];
extern u8 _gameplay_dangeon_keepSegmentRomStart[]; extern u8 _gameplay_dangeon_keepSegmentRomEnd[];
extern u8 _object_humanSegmentRomStart[]; extern u8 _object_humanSegmentRomEnd[];
extern u8 _object_okutaSegmentRomStart[]; extern u8 _object_okutaSegmentRomEnd[];
extern u8 _object_crowSegmentRomStart[]; extern u8 _object_crowSegmentRomEnd[];
extern u8 _object_pohSegmentRomStart[]; extern u8 _object_pohSegmentRomEnd[];
extern u8 _object_dy_objSegmentRomStart[]; extern u8 _object_dy_objSegmentRomEnd[];
extern u8 _object_wallmasterSegmentRomStart[]; extern u8 _object_wallmasterSegmentRomEnd[];
extern u8 _object_dodongoSegmentRomStart[]; extern u8 _object_dodongoSegmentRomEnd[];
extern u8 _object_fireflySegmentRomStart[]; extern u8 _object_fireflySegmentRomEnd[];
extern u8 _object_boxSegmentRomStart[]; extern u8 _object_boxSegmentRomEnd[];
extern u8 _object_fireSegmentRomStart[]; extern u8 _object_fireSegmentRomEnd[];
extern u8 _object_bubbleSegmentRomStart[]; extern u8 _object_bubbleSegmentRomEnd[];
extern u8 _object_niwSegmentRomStart[]; extern u8 _object_niwSegmentRomEnd[];
extern u8 _object_link_boySegmentRomStart[]; extern u8 _object_link_boySegmentRomEnd[];
extern u8 _object_link_childSegmentRomStart[]; extern u8 _object_link_childSegmentRomEnd[];
extern u8 _object_titeSegmentRomStart[]; extern u8 _object_titeSegmentRomEnd[];
extern u8 _object_reebaSegmentRomStart[]; extern u8 _object_reebaSegmentRomEnd[];
extern u8 _object_peehatSegmentRomStart[]; extern u8 _object_peehatSegmentRomEnd[];
extern u8 _object_kingdodongoSegmentRomStart[]; extern u8 _object_kingdodongoSegmentRomEnd[];
extern u8 _object_horseSegmentRomStart[]; extern u8 _object_horseSegmentRomEnd[];
extern u8 _object_zfSegmentRomStart[]; extern u8 _object_zfSegmentRomEnd[];
extern u8 _object_gomaSegmentRomStart[]; extern u8 _object_gomaSegmentRomEnd[];
extern u8 _object_zl1SegmentRomStart[]; extern u8 _object_zl1SegmentRomEnd[];
extern u8 _object_golSegmentRomStart[]; extern u8 _object_golSegmentRomEnd[];
extern u8 _object_dodojrSegmentRomStart[]; extern u8 _object_dodojrSegmentRomEnd[];
extern u8 _object_torch2SegmentRomStart[]; extern u8 _object_torch2SegmentRomEnd[];
extern u8 _object_blSegmentRomStart[]; extern u8 _object_blSegmentRomEnd[];
extern u8 _object_tpSegmentRomStart[]; extern u8 _object_tpSegmentRomEnd[];
extern u8 _object_oA1SegmentRomStart[]; extern u8 _object_oA1SegmentRomEnd[];
extern u8 _object_stSegmentRomStart[]; extern u8 _object_stSegmentRomEnd[];
extern u8 _object_bwSegmentRomStart[]; extern u8 _object_bwSegmentRomEnd[];
extern u8 _object_eiSegmentRomStart[]; extern u8 _object_eiSegmentRomEnd[];
extern u8 _object_horse_normalSegmentRomStart[]; extern u8 _object_horse_normalSegmentRomEnd[];
extern u8 _object_oB1SegmentRomStart[]; extern u8 _object_oB1SegmentRomEnd[];
extern u8 _object_o_animeSegmentRomStart[]; extern u8 _object_o_animeSegmentRomEnd[];
extern u8 _object_spot04_objectsSegmentRomStart[]; extern u8 _object_spot04_objectsSegmentRomEnd[];
extern u8 _object_ddan_objectsSegmentRomStart[]; extern u8 _object_ddan_objectsSegmentRomEnd[];
extern u8 _object_hidan_objectsSegmentRomStart[]; extern u8 _object_hidan_objectsSegmentRomEnd[];
extern u8 _object_horse_ganonSegmentRomStart[]; extern u8 _object_horse_ganonSegmentRomEnd[];
extern u8 _object_oA2SegmentRomStart[]; extern u8 _object_oA2SegmentRomEnd[];
extern u8 _object_spot00_objectsSegmentRomStart[]; extern u8 _object_spot00_objectsSegmentRomEnd[];
extern u8 _object_mbSegmentRomStart[]; extern u8 _object_mbSegmentRomEnd[];
extern u8 _object_bombfSegmentRomStart[]; extern u8 _object_bombfSegmentRomEnd[];
extern u8 _object_sk2SegmentRomStart[]; extern u8 _object_sk2SegmentRomEnd[];
extern u8 _object_oE1SegmentRomStart[]; extern u8 _object_oE1SegmentRomEnd[];
extern u8 _object_oE_animeSegmentRomStart[]; extern u8 _object_oE_animeSegmentRomEnd[];
extern u8 _object_oE2SegmentRomStart[]; extern u8 _object_oE2SegmentRomEnd[];
extern u8 _object_ydan_objectsSegmentRomStart[]; extern u8 _object_ydan_objectsSegmentRomEnd[];
extern u8 _object_gndSegmentRomStart[]; extern u8 _object_gndSegmentRomEnd[];
extern u8 _object_amSegmentRomStart[]; extern u8 _object_amSegmentRomEnd[];
extern u8 _object_dekubabaSegmentRomStart[]; extern u8 _object_dekubabaSegmentRomEnd[];
extern u8 _object_oA3SegmentRomStart[]; extern u8 _object_oA3SegmentRomEnd[];
extern u8 _object_oA4SegmentRomStart[]; extern u8 _object_oA4SegmentRomEnd[];
extern u8 _object_oA5SegmentRomStart[]; extern u8 _object_oA5SegmentRomEnd[];
extern u8 _object_oA6SegmentRomStart[]; extern u8 _object_oA6SegmentRomEnd[];
extern u8 _object_oA7SegmentRomStart[]; extern u8 _object_oA7SegmentRomEnd[];
extern u8 _object_jjSegmentRomStart[]; extern u8 _object_jjSegmentRomEnd[];
extern u8 _object_oA8SegmentRomStart[]; extern u8 _object_oA8SegmentRomEnd[];
extern u8 _object_oA9SegmentRomStart[]; extern u8 _object_oA9SegmentRomEnd[];
extern u8 _object_oB2SegmentRomStart[]; extern u8 _object_oB2SegmentRomEnd[];
extern u8 _object_oB3SegmentRomStart[]; extern u8 _object_oB3SegmentRomEnd[];
extern u8 _object_oB4SegmentRomStart[]; extern u8 _object_oB4SegmentRomEnd[];
extern u8 _object_horse_zeldaSegmentRomStart[]; extern u8 _object_horse_zeldaSegmentRomEnd[];
extern u8 _object_opening_demo1SegmentRomStart[]; extern u8 _object_opening_demo1SegmentRomEnd[];
extern u8 _object_warp1SegmentRomStart[]; extern u8 _object_warp1SegmentRomEnd[];
extern u8 _object_b_heartSegmentRomStart[]; extern u8 _object_b_heartSegmentRomEnd[];
extern u8 _object_dekunutsSegmentRomStart[]; extern u8 _object_dekunutsSegmentRomEnd[];
extern u8 _object_oE3SegmentRomStart[]; extern u8 _object_oE3SegmentRomEnd[];
extern u8 _object_oE4SegmentRomStart[]; extern u8 _object_oE4SegmentRomEnd[];
extern u8 _object_menkuri_objectsSegmentRomStart[]; extern u8 _object_menkuri_objectsSegmentRomEnd[];
extern u8 _object_oE5SegmentRomStart[]; extern u8 _object_oE5SegmentRomEnd[];
extern u8 _object_oE6SegmentRomStart[]; extern u8 _object_oE6SegmentRomEnd[];
extern u8 _object_oE7SegmentRomStart[]; extern u8 _object_oE7SegmentRomEnd[];
extern u8 _object_oE8SegmentRomStart[]; extern u8 _object_oE8SegmentRomEnd[];
extern u8 _object_oE9SegmentRomStart[]; extern u8 _object_oE9SegmentRomEnd[];
extern u8 _object_oE10SegmentRomStart[]; extern u8 _object_oE10SegmentRomEnd[];
extern u8 _object_oE11SegmentRomStart[]; extern u8 _object_oE11SegmentRomEnd[];
extern u8 _object_oE12SegmentRomStart[]; extern u8 _object_oE12SegmentRomEnd[];
extern u8 _object_valiSegmentRomStart[]; extern u8 _object_valiSegmentRomEnd[];
extern u8 _object_oA10SegmentRomStart[]; extern u8 _object_oA10SegmentRomEnd[];
extern u8 _object_oA11SegmentRomStart[]; extern u8 _object_oA11SegmentRomEnd[];
extern u8 _object_mizu_objectsSegmentRomStart[]; extern u8 _object_mizu_objectsSegmentRomEnd[];
extern u8 _object_fhgSegmentRomStart[]; extern u8 _object_fhgSegmentRomEnd[];
extern u8 _object_ossanSegmentRomStart[]; extern u8 _object_ossanSegmentRomEnd[];
extern u8 _object_mori_hineri1SegmentRomStart[]; extern u8 _object_mori_hineri1SegmentRomEnd[];
extern u8 _object_BbSegmentRomStart[]; extern u8 _object_BbSegmentRomEnd[];
extern u8 _object_toki_objectsSegmentRomStart[]; extern u8 _object_toki_objectsSegmentRomEnd[];
extern u8 _object_yukabyunSegmentRomStart[]; extern u8 _object_yukabyunSegmentRomEnd[];
extern u8 _object_zl2SegmentRomStart[]; extern u8 _object_zl2SegmentRomEnd[];
extern u8 _object_mjinSegmentRomStart[]; extern u8 _object_mjinSegmentRomEnd[];
extern u8 _object_mjin_flashSegmentRomStart[]; extern u8 _object_mjin_flashSegmentRomEnd[];
extern u8 _object_mjin_darkSegmentRomStart[]; extern u8 _object_mjin_darkSegmentRomEnd[];
extern u8 _object_mjin_flameSegmentRomStart[]; extern u8 _object_mjin_flameSegmentRomEnd[];
extern u8 _object_mjin_iceSegmentRomStart[]; extern u8 _object_mjin_iceSegmentRomEnd[];
extern u8 _object_mjin_soulSegmentRomStart[]; extern u8 _object_mjin_soulSegmentRomEnd[];
extern u8 _object_mjin_windSegmentRomStart[]; extern u8 _object_mjin_windSegmentRomEnd[];
extern u8 _object_mjin_okaSegmentRomStart[]; extern u8 _object_mjin_okaSegmentRomEnd[];
extern u8 _object_haka_objectsSegmentRomStart[]; extern u8 _object_haka_objectsSegmentRomEnd[];
extern u8 _object_spot06_objectsSegmentRomStart[]; extern u8 _object_spot06_objectsSegmentRomEnd[];
extern u8 _object_ice_objectsSegmentRomStart[]; extern u8 _object_ice_objectsSegmentRomEnd[];
extern u8 _object_relay_objectsSegmentRomStart[]; extern u8 _object_relay_objectsSegmentRomEnd[];
extern u8 _object_po_fieldSegmentRomStart[]; extern u8 _object_po_fieldSegmentRomEnd[];
extern u8 _object_po_composerSegmentRomStart[]; extern u8 _object_po_composerSegmentRomEnd[];
extern u8 _object_mori_hineri1aSegmentRomStart[]; extern u8 _object_mori_hineri1aSegmentRomEnd[];
extern u8 _object_mori_hineri2SegmentRomStart[]; extern u8 _object_mori_hineri2SegmentRomEnd[];
extern u8 _object_mori_hineri2aSegmentRomStart[]; extern u8 _object_mori_hineri2aSegmentRomEnd[];
extern u8 _object_mori_objectsSegmentRomStart[]; extern u8 _object_mori_objectsSegmentRomEnd[];
extern u8 _object_mori_texSegmentRomStart[]; extern u8 _object_mori_texSegmentRomEnd[];
extern u8 _object_spot08_objSegmentRomStart[]; extern u8 _object_spot08_objSegmentRomEnd[];
extern u8 _object_warp2SegmentRomStart[]; extern u8 _object_warp2SegmentRomEnd[];
extern u8 _object_hataSegmentRomStart[]; extern u8 _object_hataSegmentRomEnd[];
extern u8 _object_birdSegmentRomStart[]; extern u8 _object_birdSegmentRomEnd[];
extern u8 _object_wood02SegmentRomStart[]; extern u8 _object_wood02SegmentRomEnd[];
extern u8 _object_lightboxSegmentRomStart[]; extern u8 _object_lightboxSegmentRomEnd[];
extern u8 _object_pu_boxSegmentRomStart[]; extern u8 _object_pu_boxSegmentRomEnd[];
extern u8 _object_trapSegmentRomStart[]; extern u8 _object_trapSegmentRomEnd[];
extern u8 _object_vaseSegmentRomStart[]; extern u8 _object_vaseSegmentRomEnd[];
extern u8 _object_imSegmentRomStart[]; extern u8 _object_imSegmentRomEnd[];
extern u8 _object_taSegmentRomStart[]; extern u8 _object_taSegmentRomEnd[];
extern u8 _object_tkSegmentRomStart[]; extern u8 _object_tkSegmentRomEnd[];
extern u8 _object_xcSegmentRomStart[]; extern u8 _object_xcSegmentRomEnd[];
extern u8 _object_vmSegmentRomStart[]; extern u8 _object_vmSegmentRomEnd[];
extern u8 _object_bvSegmentRomStart[]; extern u8 _object_bvSegmentRomEnd[];
extern u8 _object_hakach_objectsSegmentRomStart[]; extern u8 _object_hakach_objectsSegmentRomEnd[];
extern u8 _object_efc_crystal_lightSegmentRomStart[]; extern u8 _object_efc_crystal_lightSegmentRomEnd[];
extern u8 _object_efc_fire_ballSegmentRomStart[]; extern u8 _object_efc_fire_ballSegmentRomEnd[];
extern u8 _object_efc_flashSegmentRomStart[]; extern u8 _object_efc_flashSegmentRomEnd[];
extern u8 _object_efc_lgt_showerSegmentRomStart[]; extern u8 _object_efc_lgt_showerSegmentRomEnd[];
extern u8 _object_efc_star_fieldSegmentRomStart[]; extern u8 _object_efc_star_fieldSegmentRomEnd[];
extern u8 _object_god_lgtSegmentRomStart[]; extern u8 _object_god_lgtSegmentRomEnd[];
extern u8 _object_light_ringSegmentRomStart[]; extern u8 _object_light_ringSegmentRomEnd[];
extern u8 _object_triforce_spotSegmentRomStart[]; extern u8 _object_triforce_spotSegmentRomEnd[];
extern u8 _object_bdan_objectsSegmentRomStart[]; extern u8 _object_bdan_objectsSegmentRomEnd[];
extern u8 _object_sdSegmentRomStart[]; extern u8 _object_sdSegmentRomEnd[];
extern u8 _object_rdSegmentRomStart[]; extern u8 _object_rdSegmentRomEnd[];
extern u8 _object_po_sistersSegmentRomStart[]; extern u8 _object_po_sistersSegmentRomEnd[];
extern u8 _object_heavy_objectSegmentRomStart[]; extern u8 _object_heavy_objectSegmentRomEnd[];
extern u8 _object_gnddSegmentRomStart[]; extern u8 _object_gnddSegmentRomEnd[];
extern u8 _object_fdSegmentRomStart[]; extern u8 _object_fdSegmentRomEnd[];
extern u8 _object_duSegmentRomStart[]; extern u8 _object_duSegmentRomEnd[];
extern u8 _object_fwSegmentRomStart[]; extern u8 _object_fwSegmentRomEnd[];
extern u8 _object_medalSegmentRomStart[]; extern u8 _object_medalSegmentRomEnd[];
extern u8 _object_horse_link_childSegmentRomStart[]; extern u8 _object_horse_link_childSegmentRomEnd[];
extern u8 _object_spot02_objectsSegmentRomStart[]; extern u8 _object_spot02_objectsSegmentRomEnd[];
extern u8 _object_hakaSegmentRomStart[]; extern u8 _object_hakaSegmentRomEnd[];
extern u8 _object_ru1SegmentRomStart[]; extern u8 _object_ru1SegmentRomEnd[];
extern u8 _object_syokudaiSegmentRomStart[]; extern u8 _object_syokudaiSegmentRomEnd[];
extern u8 _object_fd2SegmentRomStart[]; extern u8 _object_fd2SegmentRomEnd[];
extern u8 _object_dhSegmentRomStart[]; extern u8 _object_dhSegmentRomEnd[];
extern u8 _object_rlSegmentRomStart[]; extern u8 _object_rlSegmentRomEnd[];
extern u8 _object_efc_twSegmentRomStart[]; extern u8 _object_efc_twSegmentRomEnd[];
extern u8 _object_demo_tre_lgtSegmentRomStart[]; extern u8 _object_demo_tre_lgtSegmentRomEnd[];
extern u8 _object_gi_keySegmentRomStart[]; extern u8 _object_gi_keySegmentRomEnd[];
extern u8 _object_mir_raySegmentRomStart[]; extern u8 _object_mir_raySegmentRomEnd[];
extern u8 _object_brobSegmentRomStart[]; extern u8 _object_brobSegmentRomEnd[];
extern u8 _object_gi_jewelSegmentRomStart[]; extern u8 _object_gi_jewelSegmentRomEnd[];
extern u8 _object_spot09_objSegmentRomStart[]; extern u8 _object_spot09_objSegmentRomEnd[];
extern u8 _object_spot18_objSegmentRomStart[]; extern u8 _object_spot18_objSegmentRomEnd[];
extern u8 _object_bdoorSegmentRomStart[]; extern u8 _object_bdoorSegmentRomEnd[];
extern u8 _object_spot17_objSegmentRomStart[]; extern u8 _object_spot17_objSegmentRomEnd[];
extern u8 _object_shop_dungenSegmentRomStart[]; extern u8 _object_shop_dungenSegmentRomEnd[];
extern u8 _object_nbSegmentRomStart[]; extern u8 _object_nbSegmentRomEnd[];
extern u8 _object_moSegmentRomStart[]; extern u8 _object_moSegmentRomEnd[];
extern u8 _object_sbSegmentRomStart[]; extern u8 _object_sbSegmentRomEnd[];
extern u8 _object_gi_melodySegmentRomStart[]; extern u8 _object_gi_melodySegmentRomEnd[];
extern u8 _object_gi_heartSegmentRomStart[]; extern u8 _object_gi_heartSegmentRomEnd[];
extern u8 _object_gi_compassSegmentRomStart[]; extern u8 _object_gi_compassSegmentRomEnd[];
extern u8 _object_gi_bosskeySegmentRomStart[]; extern u8 _object_gi_bosskeySegmentRomEnd[];
extern u8 _object_gi_medalSegmentRomStart[]; extern u8 _object_gi_medalSegmentRomEnd[];
extern u8 _object_gi_nutsSegmentRomStart[]; extern u8 _object_gi_nutsSegmentRomEnd[];
extern u8 _object_saSegmentRomStart[]; extern u8 _object_saSegmentRomEnd[];
extern u8 _object_gi_heartsSegmentRomStart[]; extern u8 _object_gi_heartsSegmentRomEnd[];
extern u8 _object_gi_arrowcaseSegmentRomStart[]; extern u8 _object_gi_arrowcaseSegmentRomEnd[];
extern u8 _object_gi_bombpouchSegmentRomStart[]; extern u8 _object_gi_bombpouchSegmentRomEnd[];
extern u8 _object_inSegmentRomStart[]; extern u8 _object_inSegmentRomEnd[];
extern u8 _object_trSegmentRomStart[]; extern u8 _object_trSegmentRomEnd[];
extern u8 _object_spot16_objSegmentRomStart[]; extern u8 _object_spot16_objSegmentRomEnd[];
extern u8 _object_oE1sSegmentRomStart[]; extern u8 _object_oE1sSegmentRomEnd[];
extern u8 _object_oE4sSegmentRomStart[]; extern u8 _object_oE4sSegmentRomEnd[];
extern u8 _object_os_animeSegmentRomStart[]; extern u8 _object_os_animeSegmentRomEnd[];
extern u8 _object_gi_bottleSegmentRomStart[]; extern u8 _object_gi_bottleSegmentRomEnd[];
extern u8 _object_gi_stickSegmentRomStart[]; extern u8 _object_gi_stickSegmentRomEnd[];
extern u8 _object_gi_mapSegmentRomStart[]; extern u8 _object_gi_mapSegmentRomEnd[];
extern u8 _object_oF1d_mapSegmentRomStart[]; extern u8 _object_oF1d_mapSegmentRomEnd[];
extern u8 _object_ru2SegmentRomStart[]; extern u8 _object_ru2SegmentRomEnd[];
extern u8 _object_gi_shield_1SegmentRomStart[]; extern u8 _object_gi_shield_1SegmentRomEnd[];
extern u8 _object_dekujrSegmentRomStart[]; extern u8 _object_dekujrSegmentRomEnd[];
extern u8 _object_gi_magicpotSegmentRomStart[]; extern u8 _object_gi_magicpotSegmentRomEnd[];
extern u8 _object_gi_bomb_1SegmentRomStart[]; extern u8 _object_gi_bomb_1SegmentRomEnd[];
extern u8 _object_oF1sSegmentRomStart[]; extern u8 _object_oF1sSegmentRomEnd[];
extern u8 _object_ma2SegmentRomStart[]; extern u8 _object_ma2SegmentRomEnd[];
extern u8 _object_gi_purseSegmentRomStart[]; extern u8 _object_gi_purseSegmentRomEnd[];
extern u8 _object_hniSegmentRomStart[]; extern u8 _object_hniSegmentRomEnd[];
extern u8 _object_twSegmentRomStart[]; extern u8 _object_twSegmentRomEnd[];
extern u8 _object_rrSegmentRomStart[]; extern u8 _object_rrSegmentRomEnd[];
extern u8 _object_bxaSegmentRomStart[]; extern u8 _object_bxaSegmentRomEnd[];
extern u8 _object_anubiceSegmentRomStart[]; extern u8 _object_anubiceSegmentRomEnd[];
extern u8 _object_gi_gerudoSegmentRomStart[]; extern u8 _object_gi_gerudoSegmentRomEnd[];
extern u8 _object_gi_arrowSegmentRomStart[]; extern u8 _object_gi_arrowSegmentRomEnd[];
extern u8 _object_gi_bomb_2SegmentRomStart[]; extern u8 _object_gi_bomb_2SegmentRomEnd[];
extern u8 _object_gi_eggSegmentRomStart[]; extern u8 _object_gi_eggSegmentRomEnd[];
extern u8 _object_gi_scaleSegmentRomStart[]; extern u8 _object_gi_scaleSegmentRomEnd[];
extern u8 _object_gi_shield_2SegmentRomStart[]; extern u8 _object_gi_shield_2SegmentRomEnd[];
extern u8 _object_gi_hookshotSegmentRomStart[]; extern u8 _object_gi_hookshotSegmentRomEnd[];
extern u8 _object_gi_ocarinaSegmentRomStart[]; extern u8 _object_gi_ocarinaSegmentRomEnd[];
extern u8 _object_gi_milkSegmentRomStart[]; extern u8 _object_gi_milkSegmentRomEnd[];
extern u8 _object_ma1SegmentRomStart[]; extern u8 _object_ma1SegmentRomEnd[];
extern u8 _object_ganonSegmentRomStart[]; extern u8 _object_ganonSegmentRomEnd[];
extern u8 _object_sstSegmentRomStart[]; extern u8 _object_sstSegmentRomEnd[];
extern u8 _object_nySegmentRomStart[]; extern u8 _object_nySegmentRomEnd[];
extern u8 _object_nySegmentRomStart[]; extern u8 _object_nySegmentRomEnd[];
extern u8 _object_frSegmentRomStart[]; extern u8 _object_frSegmentRomEnd[];
extern u8 _object_gi_pachinkoSegmentRomStart[]; extern u8 _object_gi_pachinkoSegmentRomEnd[];
extern u8 _object_gi_boomerangSegmentRomStart[]; extern u8 _object_gi_boomerangSegmentRomEnd[];
extern u8 _object_gi_bowSegmentRomStart[]; extern u8 _object_gi_bowSegmentRomEnd[];
extern u8 _object_gi_glassesSegmentRomStart[]; extern u8 _object_gi_glassesSegmentRomEnd[];
extern u8 _object_gi_liquidSegmentRomStart[]; extern u8 _object_gi_liquidSegmentRomEnd[];
extern u8 _object_aniSegmentRomStart[]; extern u8 _object_aniSegmentRomEnd[];
extern u8 _object_demo_6kSegmentRomStart[]; extern u8 _object_demo_6kSegmentRomEnd[];
extern u8 _object_gi_shield_3SegmentRomStart[]; extern u8 _object_gi_shield_3SegmentRomEnd[];
extern u8 _object_gi_letterSegmentRomStart[]; extern u8 _object_gi_letterSegmentRomEnd[];
extern u8 _object_spot15_objSegmentRomStart[]; extern u8 _object_spot15_objSegmentRomEnd[];
extern u8 _object_jya_objSegmentRomStart[]; extern u8 _object_jya_objSegmentRomEnd[];
extern u8 _object_gi_clothesSegmentRomStart[]; extern u8 _object_gi_clothesSegmentRomEnd[];
extern u8 _object_gi_beanSegmentRomStart[]; extern u8 _object_gi_beanSegmentRomEnd[];
extern u8 _object_gi_fishSegmentRomStart[]; extern u8 _object_gi_fishSegmentRomEnd[];
extern u8 _object_gi_sawSegmentRomStart[]; extern u8 _object_gi_sawSegmentRomEnd[];
extern u8 _object_gi_hammerSegmentRomStart[]; extern u8 _object_gi_hammerSegmentRomEnd[];
extern u8 _object_gi_grassSegmentRomStart[]; extern u8 _object_gi_grassSegmentRomEnd[];
extern u8 _object_gi_longswordSegmentRomStart[]; extern u8 _object_gi_longswordSegmentRomEnd[];
extern u8 _object_spot01_objectsSegmentRomStart[]; extern u8 _object_spot01_objectsSegmentRomEnd[];
extern u8 _object_mdSegmentRomStart[]; extern u8 _object_mdSegmentRomEnd[];
extern u8 _object_mdSegmentRomStart[]; extern u8 _object_mdSegmentRomEnd[];
extern u8 _object_km1SegmentRomStart[]; extern u8 _object_km1SegmentRomEnd[];
extern u8 _object_kw1SegmentRomStart[]; extern u8 _object_kw1SegmentRomEnd[];
extern u8 _object_zoSegmentRomStart[]; extern u8 _object_zoSegmentRomEnd[];
extern u8 _object_kzSegmentRomStart[]; extern u8 _object_kzSegmentRomEnd[];
extern u8 _object_umajumpSegmentRomStart[]; extern u8 _object_umajumpSegmentRomEnd[];
extern u8 _object_masterkokiriSegmentRomStart[]; extern u8 _object_masterkokiriSegmentRomEnd[];
extern u8 _object_masterkokiriheadSegmentRomStart[]; extern u8 _object_masterkokiriheadSegmentRomEnd[];
extern u8 _object_mastergolonSegmentRomStart[]; extern u8 _object_mastergolonSegmentRomEnd[];
extern u8 _object_masterzooraSegmentRomStart[]; extern u8 _object_masterzooraSegmentRomEnd[];
extern u8 _object_aobSegmentRomStart[]; extern u8 _object_aobSegmentRomEnd[];
extern u8 _object_ikSegmentRomStart[]; extern u8 _object_ikSegmentRomEnd[];
extern u8 _object_ahgSegmentRomStart[]; extern u8 _object_ahgSegmentRomEnd[];
extern u8 _object_cneSegmentRomStart[]; extern u8 _object_cneSegmentRomEnd[];
extern u8 _object_gi_niwatoriSegmentRomStart[]; extern u8 _object_gi_niwatoriSegmentRomEnd[];
extern u8 _object_skjSegmentRomStart[]; extern u8 _object_skjSegmentRomEnd[];
extern u8 _object_gi_bottle_letterSegmentRomStart[]; extern u8 _object_gi_bottle_letterSegmentRomEnd[];
extern u8 _object_bjiSegmentRomStart[]; extern u8 _object_bjiSegmentRomEnd[];
extern u8 _object_bbaSegmentRomStart[]; extern u8 _object_bbaSegmentRomEnd[];
extern u8 _object_gi_ocarina_0SegmentRomStart[]; extern u8 _object_gi_ocarina_0SegmentRomEnd[];
extern u8 _object_dsSegmentRomStart[]; extern u8 _object_dsSegmentRomEnd[];
extern u8 _object_aneSegmentRomStart[]; extern u8 _object_aneSegmentRomEnd[];
extern u8 _object_bojSegmentRomStart[]; extern u8 _object_bojSegmentRomEnd[];
extern u8 _object_spot03_objectSegmentRomStart[]; extern u8 _object_spot03_objectSegmentRomEnd[];
extern u8 _object_spot07_objectSegmentRomStart[]; extern u8 _object_spot07_objectSegmentRomEnd[];
extern u8 _object_fzSegmentRomStart[]; extern u8 _object_fzSegmentRomEnd[];
extern u8 _object_bobSegmentRomStart[]; extern u8 _object_bobSegmentRomEnd[];
extern u8 _object_ge1SegmentRomStart[]; extern u8 _object_ge1SegmentRomEnd[];
extern u8 _object_yabusame_pointSegmentRomStart[]; extern u8 _object_yabusame_pointSegmentRomEnd[];
extern u8 _object_gi_boots_2SegmentRomStart[]; extern u8 _object_gi_boots_2SegmentRomEnd[];
extern u8 _object_gi_seedSegmentRomStart[]; extern u8 _object_gi_seedSegmentRomEnd[];
extern u8 _object_gnd_magicSegmentRomStart[]; extern u8 _object_gnd_magicSegmentRomEnd[];
extern u8 _object_d_elevatorSegmentRomStart[]; extern u8 _object_d_elevatorSegmentRomEnd[];
extern u8 _object_d_hsblockSegmentRomStart[]; extern u8 _object_d_hsblockSegmentRomEnd[];
extern u8 _object_d_liftSegmentRomStart[]; extern u8 _object_d_liftSegmentRomEnd[];
extern u8 _object_mamenokiSegmentRomStart[]; extern u8 _object_mamenokiSegmentRomEnd[];
extern u8 _object_goroiwaSegmentRomStart[]; extern u8 _object_goroiwaSegmentRomEnd[];
extern u8 _object_toryoSegmentRomStart[]; extern u8 _object_toryoSegmentRomEnd[];
extern u8 _object_daikuSegmentRomStart[]; extern u8 _object_daikuSegmentRomEnd[];
extern u8 _object_nwcSegmentRomStart[]; extern u8 _object_nwcSegmentRomEnd[];
extern u8 _object_blkobjSegmentRomStart[]; extern u8 _object_blkobjSegmentRomEnd[];
extern u8 _object_gmSegmentRomStart[]; extern u8 _object_gmSegmentRomEnd[];
extern u8 _object_msSegmentRomStart[]; extern u8 _object_msSegmentRomEnd[];
extern u8 _object_hsSegmentRomStart[]; extern u8 _object_hsSegmentRomEnd[];
extern u8 _object_ingateSegmentRomStart[]; extern u8 _object_ingateSegmentRomEnd[];
extern u8 _object_lightswitchSegmentRomStart[]; extern u8 _object_lightswitchSegmentRomEnd[];
extern u8 _object_kusaSegmentRomStart[]; extern u8 _object_kusaSegmentRomEnd[];
extern u8 _object_tsuboSegmentRomStart[]; extern u8 _object_tsuboSegmentRomEnd[];
extern u8 _object_gi_glovesSegmentRomStart[]; extern u8 _object_gi_glovesSegmentRomEnd[];
extern u8 _object_gi_coinSegmentRomStart[]; extern u8 _object_gi_coinSegmentRomEnd[];
extern u8 _object_kanbanSegmentRomStart[]; extern u8 _object_kanbanSegmentRomEnd[];
extern u8 _object_gjyo_objectsSegmentRomStart[]; extern u8 _object_gjyo_objectsSegmentRomEnd[];
extern u8 _object_owlSegmentRomStart[]; extern u8 _object_owlSegmentRomEnd[];
extern u8 _object_mkSegmentRomStart[]; extern u8 _object_mkSegmentRomEnd[];
extern u8 _object_fuSegmentRomStart[]; extern u8 _object_fuSegmentRomEnd[];
extern u8 _object_gi_ki_tan_maskSegmentRomStart[]; extern u8 _object_gi_ki_tan_maskSegmentRomEnd[];
extern u8 _object_gi_redead_maskSegmentRomStart[]; extern u8 _object_gi_redead_maskSegmentRomEnd[];
extern u8 _object_gi_skj_maskSegmentRomStart[]; extern u8 _object_gi_skj_maskSegmentRomEnd[];
extern u8 _object_gi_rabit_maskSegmentRomStart[]; extern u8 _object_gi_rabit_maskSegmentRomEnd[];
extern u8 _object_gi_truth_maskSegmentRomStart[]; extern u8 _object_gi_truth_maskSegmentRomEnd[];
extern u8 _object_ganon_objectsSegmentRomStart[]; extern u8 _object_ganon_objectsSegmentRomEnd[];
extern u8 _object_siofukiSegmentRomStart[]; extern u8 _object_siofukiSegmentRomEnd[];
extern u8 _object_streamSegmentRomStart[]; extern u8 _object_streamSegmentRomEnd[];
extern u8 _object_mmSegmentRomStart[]; extern u8 _object_mmSegmentRomEnd[];
extern u8 _object_faSegmentRomStart[]; extern u8 _object_faSegmentRomEnd[];
extern u8 _object_osSegmentRomStart[]; extern u8 _object_osSegmentRomEnd[];
extern u8 _object_gi_eye_lotionSegmentRomStart[]; extern u8 _object_gi_eye_lotionSegmentRomEnd[];
extern u8 _object_gi_powderSegmentRomStart[]; extern u8 _object_gi_powderSegmentRomEnd[];
extern u8 _object_gi_mushroomSegmentRomStart[]; extern u8 _object_gi_mushroomSegmentRomEnd[];
extern u8 _object_gi_ticketstoneSegmentRomStart[]; extern u8 _object_gi_ticketstoneSegmentRomEnd[];
extern u8 _object_gi_brokenswordSegmentRomStart[]; extern u8 _object_gi_brokenswordSegmentRomEnd[];
extern u8 _object_jsSegmentRomStart[]; extern u8 _object_jsSegmentRomEnd[];
extern u8 _object_csSegmentRomStart[]; extern u8 _object_csSegmentRomEnd[];
extern u8 _object_gi_prescriptionSegmentRomStart[]; extern u8 _object_gi_prescriptionSegmentRomEnd[];
extern u8 _object_gi_braceletSegmentRomStart[]; extern u8 _object_gi_braceletSegmentRomEnd[];
extern u8 _object_gi_soldoutSegmentRomStart[]; extern u8 _object_gi_soldoutSegmentRomEnd[];
extern u8 _object_gi_frogSegmentRomStart[]; extern u8 _object_gi_frogSegmentRomEnd[];
extern u8 _object_magSegmentRomStart[]; extern u8 _object_magSegmentRomEnd[];
extern u8 _object_door_gerudoSegmentRomStart[]; extern u8 _object_door_gerudoSegmentRomEnd[];
extern u8 _object_gtSegmentRomStart[]; extern u8 _object_gtSegmentRomEnd[];
extern u8 _object_efc_erupcSegmentRomStart[]; extern u8 _object_efc_erupcSegmentRomEnd[];
extern u8 _object_zl2_anime1SegmentRomStart[]; extern u8 _object_zl2_anime1SegmentRomEnd[];
extern u8 _object_zl2_anime2SegmentRomStart[]; extern u8 _object_zl2_anime2SegmentRomEnd[];
extern u8 _object_gi_golonmaskSegmentRomStart[]; extern u8 _object_gi_golonmaskSegmentRomEnd[];
extern u8 _object_gi_zoramaskSegmentRomStart[]; extern u8 _object_gi_zoramaskSegmentRomEnd[];
extern u8 _object_gi_gerudomaskSegmentRomStart[]; extern u8 _object_gi_gerudomaskSegmentRomEnd[];
extern u8 _object_ganon2SegmentRomStart[]; extern u8 _object_ganon2SegmentRomEnd[];
extern u8 _object_kaSegmentRomStart[]; extern u8 _object_kaSegmentRomEnd[];
extern u8 _object_tsSegmentRomStart[]; extern u8 _object_tsSegmentRomEnd[];
extern u8 _object_zgSegmentRomStart[]; extern u8 _object_zgSegmentRomEnd[];
extern u8 _object_gi_hoverbootsSegmentRomStart[]; extern u8 _object_gi_hoverbootsSegmentRomEnd[];
extern u8 _object_gi_m_arrowSegmentRomStart[]; extern u8 _object_gi_m_arrowSegmentRomEnd[];
extern u8 _object_ds2SegmentRomStart[]; extern u8 _object_ds2SegmentRomEnd[];
extern u8 _object_ecSegmentRomStart[]; extern u8 _object_ecSegmentRomEnd[];
extern u8 _object_fishSegmentRomStart[]; extern u8 _object_fishSegmentRomEnd[];
extern u8 _object_gi_sutaruSegmentRomStart[]; extern u8 _object_gi_sutaruSegmentRomEnd[];
extern u8 _object_gi_goddessSegmentRomStart[]; extern u8 _object_gi_goddessSegmentRomEnd[];
extern u8 _object_sshSegmentRomStart[]; extern u8 _object_sshSegmentRomEnd[];
extern u8 _object_bigokutaSegmentRomStart[]; extern u8 _object_bigokutaSegmentRomEnd[];
extern u8 _object_bgSegmentRomStart[]; extern u8 _object_bgSegmentRomEnd[];
extern u8 _object_spot05_objectsSegmentRomStart[]; extern u8 _object_spot05_objectsSegmentRomEnd[];
extern u8 _object_spot12_objSegmentRomStart[]; extern u8 _object_spot12_objSegmentRomEnd[];
extern u8 _object_bombiwaSegmentRomStart[]; extern u8 _object_bombiwaSegmentRomEnd[];
extern u8 _object_hintnutsSegmentRomStart[]; extern u8 _object_hintnutsSegmentRomEnd[];
extern u8 _object_rsSegmentRomStart[]; extern u8 _object_rsSegmentRomEnd[];
extern u8 _object_spot00_breakSegmentRomStart[]; extern u8 _object_spot00_breakSegmentRomEnd[];
extern u8 _object_glaSegmentRomStart[]; extern u8 _object_glaSegmentRomEnd[];
extern u8 _object_shopnutsSegmentRomStart[]; extern u8 _object_shopnutsSegmentRomEnd[];
extern u8 _object_geldbSegmentRomStart[]; extern u8 _object_geldbSegmentRomEnd[];
extern u8 _object_grSegmentRomStart[]; extern u8 _object_grSegmentRomEnd[];
extern u8 _object_dogSegmentRomStart[]; extern u8 _object_dogSegmentRomEnd[];
extern u8 _object_jya_ironSegmentRomStart[]; extern u8 _object_jya_ironSegmentRomEnd[];
extern u8 _object_jya_doorSegmentRomStart[]; extern u8 _object_jya_doorSegmentRomEnd[];
extern u8 _object_spot11_objSegmentRomStart[]; extern u8 _object_spot11_objSegmentRomEnd[];
extern u8 _object_kibako2SegmentRomStart[]; extern u8 _object_kibako2SegmentRomEnd[];
extern u8 _object_dnsSegmentRomStart[]; extern u8 _object_dnsSegmentRomEnd[];
extern u8 _object_dnkSegmentRomStart[]; extern u8 _object_dnkSegmentRomEnd[];
extern u8 _object_gi_fireSegmentRomStart[]; extern u8 _object_gi_fireSegmentRomEnd[];
extern u8 _object_gi_insectSegmentRomStart[]; extern u8 _object_gi_insectSegmentRomEnd[];
extern u8 _object_gi_butterflySegmentRomStart[]; extern u8 _object_gi_butterflySegmentRomEnd[];
extern u8 _object_gi_ghostSegmentRomStart[]; extern u8 _object_gi_ghostSegmentRomEnd[];
extern u8 _object_gi_soulSegmentRomStart[]; extern u8 _object_gi_soulSegmentRomEnd[];
extern u8 _object_bowlSegmentRomStart[]; extern u8 _object_bowlSegmentRomEnd[];
extern u8 _object_demo_kekkaiSegmentRomStart[]; extern u8 _object_demo_kekkaiSegmentRomEnd[];
extern u8 _object_efc_doughnutSegmentRomStart[]; extern u8 _object_efc_doughnutSegmentRomEnd[];
extern u8 _object_gi_dekupouchSegmentRomStart[]; extern u8 _object_gi_dekupouchSegmentRomEnd[];
extern u8 _object_ganon_anime1SegmentRomStart[]; extern u8 _object_ganon_anime1SegmentRomEnd[];
extern u8 _object_ganon_anime2SegmentRomStart[]; extern u8 _object_ganon_anime2SegmentRomEnd[];
extern u8 _object_ganon_anime3SegmentRomStart[]; extern u8 _object_ganon_anime3SegmentRomEnd[];
extern u8 _object_gi_rupySegmentRomStart[]; extern u8 _object_gi_rupySegmentRomEnd[];
extern u8 _object_spot01_matoyaSegmentRomStart[]; extern u8 _object_spot01_matoyaSegmentRomEnd[];
extern u8 _object_spot01_matoyabSegmentRomStart[]; extern u8 _object_spot01_matoyabSegmentRomEnd[];
extern u8 _object_muSegmentRomStart[]; extern u8 _object_muSegmentRomEnd[];
extern u8 _object_wfSegmentRomStart[]; extern u8 _object_wfSegmentRomEnd[];
extern u8 _object_skbSegmentRomStart[]; extern u8 _object_skbSegmentRomEnd[];
extern u8 _object_gjSegmentRomStart[]; extern u8 _object_gjSegmentRomEnd[];
extern u8 _object_geffSegmentRomStart[]; extern u8 _object_geffSegmentRomEnd[];
extern u8 _object_haka_doorSegmentRomStart[]; extern u8 _object_haka_doorSegmentRomEnd[];
extern u8 _object_gsSegmentRomStart[]; extern u8 _object_gsSegmentRomEnd[];
extern u8 _object_psSegmentRomStart[]; extern u8 _object_psSegmentRomEnd[];
extern u8 _object_bwallSegmentRomStart[]; extern u8 _object_bwallSegmentRomEnd[];
extern u8 _object_cowSegmentRomStart[]; extern u8 _object_cowSegmentRomEnd[];
extern u8 _object_cobSegmentRomStart[]; extern u8 _object_cobSegmentRomEnd[];
extern u8 _object_gi_sword_1SegmentRomStart[]; extern u8 _object_gi_sword_1SegmentRomEnd[];
extern u8 _object_door_killerSegmentRomStart[]; extern u8 _object_door_killerSegmentRomEnd[];
extern u8 _object_ouke_hakaSegmentRomStart[]; extern u8 _object_ouke_hakaSegmentRomEnd[];
extern u8 _object_timeblockSegmentRomStart[]; extern u8 _object_timeblockSegmentRomEnd[];
extern u8 _object_zl4SegmentRomStart[]; extern u8 _object_zl4SegmentRomEnd[];
extern u8 _g_pn_01SegmentRomStart[]; extern u8 _g_pn_01SegmentRomEnd[];
extern u8 _g_pn_02SegmentRomStart[]; extern u8 _g_pn_02SegmentRomEnd[];
extern u8 _g_pn_03SegmentRomStart[]; extern u8 _g_pn_03SegmentRomEnd[];
extern u8 _g_pn_04SegmentRomStart[]; extern u8 _g_pn_04SegmentRomEnd[];
extern u8 _g_pn_05SegmentRomStart[]; extern u8 _g_pn_05SegmentRomEnd[];
extern u8 _g_pn_06SegmentRomStart[]; extern u8 _g_pn_06SegmentRomEnd[];
extern u8 _g_pn_07SegmentRomStart[]; extern u8 _g_pn_07SegmentRomEnd[];
extern u8 _g_pn_08SegmentRomStart[]; extern u8 _g_pn_08SegmentRomEnd[];
extern u8 _g_pn_09SegmentRomStart[]; extern u8 _g_pn_09SegmentRomEnd[];
extern u8 _g_pn_10SegmentRomStart[]; extern u8 _g_pn_10SegmentRomEnd[];
extern u8 _g_pn_11SegmentRomStart[]; extern u8 _g_pn_11SegmentRomEnd[];
extern u8 _g_pn_12SegmentRomStart[]; extern u8 _g_pn_12SegmentRomEnd[];
extern u8 _g_pn_13SegmentRomStart[]; extern u8 _g_pn_13SegmentRomEnd[];
extern u8 _g_pn_14SegmentRomStart[]; extern u8 _g_pn_14SegmentRomEnd[];
extern u8 _g_pn_15SegmentRomStart[]; extern u8 _g_pn_15SegmentRomEnd[];
extern u8 _g_pn_16SegmentRomStart[]; extern u8 _g_pn_16SegmentRomEnd[];
extern u8 _g_pn_17SegmentRomStart[]; extern u8 _g_pn_17SegmentRomEnd[];
extern u8 _g_pn_18SegmentRomStart[]; extern u8 _g_pn_18SegmentRomEnd[];
extern u8 _g_pn_19SegmentRomStart[]; extern u8 _g_pn_19SegmentRomEnd[];
extern u8 _g_pn_20SegmentRomStart[]; extern u8 _g_pn_20SegmentRomEnd[];
extern u8 _g_pn_21SegmentRomStart[]; extern u8 _g_pn_21SegmentRomEnd[];
extern u8 _g_pn_22SegmentRomStart[]; extern u8 _g_pn_22SegmentRomEnd[];
extern u8 _g_pn_23SegmentRomStart[]; extern u8 _g_pn_23SegmentRomEnd[];
extern u8 _g_pn_24SegmentRomStart[]; extern u8 _g_pn_24SegmentRomEnd[];
extern u8 _g_pn_25SegmentRomStart[]; extern u8 _g_pn_25SegmentRomEnd[];
extern u8 _g_pn_26SegmentRomStart[]; extern u8 _g_pn_26SegmentRomEnd[];
extern u8 _g_pn_27SegmentRomStart[]; extern u8 _g_pn_27SegmentRomEnd[];
extern u8 _g_pn_28SegmentRomStart[]; extern u8 _g_pn_28SegmentRomEnd[];
extern u8 _g_pn_29SegmentRomStart[]; extern u8 _g_pn_29SegmentRomEnd[];
extern u8 _g_pn_30SegmentRomStart[]; extern u8 _g_pn_30SegmentRomEnd[];
extern u8 _g_pn_31SegmentRomStart[]; extern u8 _g_pn_31SegmentRomEnd[];
extern u8 _g_pn_32SegmentRomStart[]; extern u8 _g_pn_32SegmentRomEnd[];
extern u8 _g_pn_33SegmentRomStart[]; extern u8 _g_pn_33SegmentRomEnd[];
extern u8 _g_pn_34SegmentRomStart[]; extern u8 _g_pn_34SegmentRomEnd[];
extern u8 _g_pn_35SegmentRomStart[]; extern u8 _g_pn_35SegmentRomEnd[];
extern u8 _g_pn_36SegmentRomStart[]; extern u8 _g_pn_36SegmentRomEnd[];
extern u8 _g_pn_37SegmentRomStart[]; extern u8 _g_pn_37SegmentRomEnd[];
extern u8 _g_pn_38SegmentRomStart[]; extern u8 _g_pn_38SegmentRomEnd[];
extern u8 _g_pn_39SegmentRomStart[]; extern u8 _g_pn_39SegmentRomEnd[];
extern u8 _g_pn_40SegmentRomStart[]; extern u8 _g_pn_40SegmentRomEnd[];
extern u8 _g_pn_41SegmentRomStart[]; extern u8 _g_pn_41SegmentRomEnd[];
extern u8 _g_pn_42SegmentRomStart[]; extern u8 _g_pn_42SegmentRomEnd[];
extern u8 _g_pn_43SegmentRomStart[]; extern u8 _g_pn_43SegmentRomEnd[];
extern u8 _g_pn_44SegmentRomStart[]; extern u8 _g_pn_44SegmentRomEnd[];
extern u8 _g_pn_45SegmentRomStart[]; extern u8 _g_pn_45SegmentRomEnd[];
extern u8 _g_pn_46SegmentRomStart[]; extern u8 _g_pn_46SegmentRomEnd[];
extern u8 _g_pn_47SegmentRomStart[]; extern u8 _g_pn_47SegmentRomEnd[];
extern u8 _g_pn_48SegmentRomStart[]; extern u8 _g_pn_48SegmentRomEnd[];
extern u8 _g_pn_49SegmentRomStart[]; extern u8 _g_pn_49SegmentRomEnd[];
extern u8 _g_pn_50SegmentRomStart[]; extern u8 _g_pn_50SegmentRomEnd[];
extern u8 _g_pn_51SegmentRomStart[]; extern u8 _g_pn_51SegmentRomEnd[];
extern u8 _g_pn_52SegmentRomStart[]; extern u8 _g_pn_52SegmentRomEnd[];
extern u8 _g_pn_53SegmentRomStart[]; extern u8 _g_pn_53SegmentRomEnd[];
extern u8 _g_pn_54SegmentRomStart[]; extern u8 _g_pn_54SegmentRomEnd[];
extern u8 _g_pn_55SegmentRomStart[]; extern u8 _g_pn_55SegmentRomEnd[];
extern u8 _g_pn_56SegmentRomStart[]; extern u8 _g_pn_56SegmentRomEnd[];
extern u8 _g_pn_57SegmentRomStart[]; extern u8 _g_pn_57SegmentRomEnd[];
extern u8 _z_select_staticSegmentRomStart[]; extern u8 _z_select_staticSegmentRomEnd[];
extern u8 _nintendo_rogo_staticSegmentRomStart[]; extern u8 _nintendo_rogo_staticSegmentRomEnd[];
extern u8 _title_staticSegmentRomStart[]; extern u8 _title_staticSegmentRomEnd[];
extern u8 _parameter_staticSegmentRomStart[]; extern u8 _parameter_staticSegmentRomEnd[];
extern u8 _vr_fine0_staticSegmentRomStart[]; extern u8 _vr_fine0_staticSegmentRomEnd[];
extern u8 _vr_fine0_pal_staticSegmentRomStart[]; extern u8 _vr_fine0_pal_staticSegmentRomEnd[];
extern u8 _vr_fine1_staticSegmentRomStart[]; extern u8 _vr_fine1_staticSegmentRomEnd[];
extern u8 _vr_fine1_pal_staticSegmentRomStart[]; extern u8 _vr_fine1_pal_staticSegmentRomEnd[];
extern u8 _vr_fine2_staticSegmentRomStart[]; extern u8 _vr_fine2_staticSegmentRomEnd[];
extern u8 _vr_fine2_pal_staticSegmentRomStart[]; extern u8 _vr_fine2_pal_staticSegmentRomEnd[];
extern u8 _vr_fine3_staticSegmentRomStart[]; extern u8 _vr_fine3_staticSegmentRomEnd[];
extern u8 _vr_fine3_pal_staticSegmentRomStart[]; extern u8 _vr_fine3_pal_staticSegmentRomEnd[];
extern u8 _vr_cloud0_staticSegmentRomStart[]; extern u8 _vr_cloud0_staticSegmentRomEnd[];
extern u8 _vr_cloud0_pal_staticSegmentRomStart[]; extern u8 _vr_cloud0_pal_staticSegmentRomEnd[];
extern u8 _vr_cloud1_staticSegmentRomStart[]; extern u8 _vr_cloud1_staticSegmentRomEnd[];
extern u8 _vr_cloud1_pal_staticSegmentRomStart[]; extern u8 _vr_cloud1_pal_staticSegmentRomEnd[];
extern u8 _vr_cloud2_staticSegmentRomStart[]; extern u8 _vr_cloud2_staticSegmentRomEnd[];
extern u8 _vr_cloud2_pal_staticSegmentRomStart[]; extern u8 _vr_cloud2_pal_staticSegmentRomEnd[];
extern u8 _vr_cloud3_staticSegmentRomStart[]; extern u8 _vr_cloud3_staticSegmentRomEnd[];
extern u8 _vr_cloud3_pal_staticSegmentRomStart[]; extern u8 _vr_cloud3_pal_staticSegmentRomEnd[];
extern u8 _vr_holy0_staticSegmentRomStart[]; extern u8 _vr_holy0_staticSegmentRomEnd[];
extern u8 _vr_holy0_pal_staticSegmentRomStart[]; extern u8 _vr_holy0_pal_staticSegmentRomEnd[];
extern u8 _vr_holy1_staticSegmentRomStart[]; extern u8 _vr_holy1_staticSegmentRomEnd[];
extern u8 _vr_holy1_pal_staticSegmentRomStart[]; extern u8 _vr_holy1_pal_staticSegmentRomEnd[];
extern u8 _vr_MDVR_staticSegmentRomStart[]; extern u8 _vr_MDVR_staticSegmentRomEnd[];
extern u8 _vr_MDVR_pal_staticSegmentRomStart[]; extern u8 _vr_MDVR_pal_staticSegmentRomEnd[];
extern u8 _vr_MNVR_staticSegmentRomStart[]; extern u8 _vr_MNVR_staticSegmentRomEnd[];
extern u8 _vr_MNVR_pal_staticSegmentRomStart[]; extern u8 _vr_MNVR_pal_staticSegmentRomEnd[];
extern u8 _vr_RUVR_staticSegmentRomStart[]; extern u8 _vr_RUVR_staticSegmentRomEnd[];
extern u8 _vr_RUVR_pal_staticSegmentRomStart[]; extern u8 _vr_RUVR_pal_staticSegmentRomEnd[];
extern u8 _vr_LHVR_staticSegmentRomStart[]; extern u8 _vr_LHVR_staticSegmentRomEnd[];
extern u8 _vr_KHVR_staticSegmentRomStart[]; extern u8 _vr_KHVR_staticSegmentRomEnd[];
extern u8 _vr_K3VR_staticSegmentRomStart[]; extern u8 _vr_K3VR_staticSegmentRomEnd[];
extern u8 _vr_K4VR_staticSegmentRomStart[]; extern u8 _vr_K4VR_staticSegmentRomEnd[];
extern u8 _vr_K5VR_staticSegmentRomStart[]; extern u8 _vr_K5VR_staticSegmentRomEnd[];
extern u8 _vr_SP1a_staticSegmentRomStart[]; extern u8 _vr_SP1a_staticSegmentRomEnd[];
extern u8 _vr_MLVR_staticSegmentRomStart[]; extern u8 _vr_MLVR_staticSegmentRomEnd[];
extern u8 _vr_KKRVR_staticSegmentRomStart[]; extern u8 _vr_KKRVR_staticSegmentRomEnd[];
extern u8 _vr_KR3VR_staticSegmentRomStart[]; extern u8 _vr_KR3VR_staticSegmentRomEnd[];
extern u8 _vr_IPVR_staticSegmentRomStart[]; extern u8 _vr_IPVR_staticSegmentRomEnd[];
extern u8 _vr_KSVR_staticSegmentRomStart[]; extern u8 _vr_KSVR_staticSegmentRomEnd[];
extern u8 _vr_GLVR_staticSegmentRomStart[]; extern u8 _vr_GLVR_staticSegmentRomEnd[];
extern u8 _vr_ZRVR_staticSegmentRomStart[]; extern u8 _vr_ZRVR_staticSegmentRomEnd[];
extern u8 _vr_DGVR_staticSegmentRomStart[]; extern u8 _vr_DGVR_staticSegmentRomEnd[];
extern u8 _vr_ALVR_staticSegmentRomStart[]; extern u8 _vr_ALVR_staticSegmentRomEnd[];
extern u8 _vr_NSVR_staticSegmentRomStart[]; extern u8 _vr_NSVR_staticSegmentRomEnd[];
extern u8 _vr_LBVR_staticSegmentRomStart[]; extern u8 _vr_LBVR_staticSegmentRomEnd[];
extern u8 _vr_TTVR_staticSegmentRomStart[]; extern u8 _vr_TTVR_staticSegmentRomEnd[];
extern u8 _vr_FCVR_staticSegmentRomStart[]; extern u8 _vr_FCVR_staticSegmentRomEnd[];
extern u8 _elf_message_fieldSegmentRomStart[]; extern u8 _elf_message_fieldSegmentRomEnd[];
extern u8 _elf_message_ydanSegmentRomStart[]; extern u8 _elf_message_ydanSegmentRomEnd[];
extern u8 _ydan_sceneSegmentRomStart[]; extern u8 _ydan_sceneSegmentRomEnd[];
extern u8 _ydan_room_0SegmentRomStart[]; extern u8 _ydan_room_0SegmentRomEnd[];
extern u8 _ydan_room_1SegmentRomStart[]; extern u8 _ydan_room_1SegmentRomEnd[];
extern u8 _ydan_room_2SegmentRomStart[]; extern u8 _ydan_room_2SegmentRomEnd[];
extern u8 _ydan_room_3SegmentRomStart[]; extern u8 _ydan_room_3SegmentRomEnd[];
extern u8 _ydan_room_4SegmentRomStart[]; extern u8 _ydan_room_4SegmentRomEnd[];
extern u8 _ydan_room_5SegmentRomStart[]; extern u8 _ydan_room_5SegmentRomEnd[];
extern u8 _ydan_room_6SegmentRomStart[]; extern u8 _ydan_room_6SegmentRomEnd[];
extern u8 _ydan_room_7SegmentRomStart[]; extern u8 _ydan_room_7SegmentRomEnd[];
extern u8 _ydan_room_8SegmentRomStart[]; extern u8 _ydan_room_8SegmentRomEnd[];
extern u8 _ydan_room_9SegmentRomStart[]; extern u8 _ydan_room_9SegmentRomEnd[];
extern u8 _ydan_room_10SegmentRomStart[]; extern u8 _ydan_room_10SegmentRomEnd[];
extern u8 _ydan_room_11SegmentRomStart[]; extern u8 _ydan_room_11SegmentRomEnd[];
extern u8 _ddan_sceneSegmentRomStart[]; extern u8 _ddan_sceneSegmentRomEnd[];
extern u8 _ddan_room_0SegmentRomStart[]; extern u8 _ddan_room_0SegmentRomEnd[];
extern u8 _ddan_room_1SegmentRomStart[]; extern u8 _ddan_room_1SegmentRomEnd[];
extern u8 _ddan_room_2SegmentRomStart[]; extern u8 _ddan_room_2SegmentRomEnd[];
extern u8 _ddan_room_3SegmentRomStart[]; extern u8 _ddan_room_3SegmentRomEnd[];
extern u8 _ddan_room_4SegmentRomStart[]; extern u8 _ddan_room_4SegmentRomEnd[];
extern u8 _ddan_room_5SegmentRomStart[]; extern u8 _ddan_room_5SegmentRomEnd[];
extern u8 _ddan_room_6SegmentRomStart[]; extern u8 _ddan_room_6SegmentRomEnd[];
extern u8 _ddan_room_7SegmentRomStart[]; extern u8 _ddan_room_7SegmentRomEnd[];
extern u8 _ddan_room_8SegmentRomStart[]; extern u8 _ddan_room_8SegmentRomEnd[];
extern u8 _ddan_room_9SegmentRomStart[]; extern u8 _ddan_room_9SegmentRomEnd[];
extern u8 _ddan_room_10SegmentRomStart[]; extern u8 _ddan_room_10SegmentRomEnd[];
extern u8 _ddan_room_11SegmentRomStart[]; extern u8 _ddan_room_11SegmentRomEnd[];
extern u8 _ddan_room_12SegmentRomStart[]; extern u8 _ddan_room_12SegmentRomEnd[];
extern u8 _ddan_room_13SegmentRomStart[]; extern u8 _ddan_room_13SegmentRomEnd[];
extern u8 _ddan_room_14SegmentRomStart[]; extern u8 _ddan_room_14SegmentRomEnd[];
extern u8 _ddan_room_15SegmentRomStart[]; extern u8 _ddan_room_15SegmentRomEnd[];
extern u8 _ddan_room_16SegmentRomStart[]; extern u8 _ddan_room_16SegmentRomEnd[];
extern u8 _bdan_sceneSegmentRomStart[]; extern u8 _bdan_sceneSegmentRomEnd[];
extern u8 _bdan_room_0SegmentRomStart[]; extern u8 _bdan_room_0SegmentRomEnd[];
extern u8 _bdan_room_1SegmentRomStart[]; extern u8 _bdan_room_1SegmentRomEnd[];
extern u8 _bdan_room_2SegmentRomStart[]; extern u8 _bdan_room_2SegmentRomEnd[];
extern u8 _bdan_room_3SegmentRomStart[]; extern u8 _bdan_room_3SegmentRomEnd[];
extern u8 _bdan_room_4SegmentRomStart[]; extern u8 _bdan_room_4SegmentRomEnd[];
extern u8 _bdan_room_5SegmentRomStart[]; extern u8 _bdan_room_5SegmentRomEnd[];
extern u8 _bdan_room_6SegmentRomStart[]; extern u8 _bdan_room_6SegmentRomEnd[];
extern u8 _bdan_room_7SegmentRomStart[]; extern u8 _bdan_room_7SegmentRomEnd[];
extern u8 _bdan_room_8SegmentRomStart[]; extern u8 _bdan_room_8SegmentRomEnd[];
extern u8 _bdan_room_9SegmentRomStart[]; extern u8 _bdan_room_9SegmentRomEnd[];
extern u8 _bdan_room_10SegmentRomStart[]; extern u8 _bdan_room_10SegmentRomEnd[];
extern u8 _bdan_room_11SegmentRomStart[]; extern u8 _bdan_room_11SegmentRomEnd[];
extern u8 _bdan_room_12SegmentRomStart[]; extern u8 _bdan_room_12SegmentRomEnd[];
extern u8 _bdan_room_13SegmentRomStart[]; extern u8 _bdan_room_13SegmentRomEnd[];
extern u8 _bdan_room_14SegmentRomStart[]; extern u8 _bdan_room_14SegmentRomEnd[];
extern u8 _bdan_room_15SegmentRomStart[]; extern u8 _bdan_room_15SegmentRomEnd[];
extern u8 _Bmori1_sceneSegmentRomStart[]; extern u8 _Bmori1_sceneSegmentRomEnd[];
extern u8 _Bmori1_room_0SegmentRomStart[]; extern u8 _Bmori1_room_0SegmentRomEnd[];
extern u8 _Bmori1_room_1SegmentRomStart[]; extern u8 _Bmori1_room_1SegmentRomEnd[];
extern u8 _Bmori1_room_2SegmentRomStart[]; extern u8 _Bmori1_room_2SegmentRomEnd[];
extern u8 _Bmori1_room_3SegmentRomStart[]; extern u8 _Bmori1_room_3SegmentRomEnd[];
extern u8 _Bmori1_room_4SegmentRomStart[]; extern u8 _Bmori1_room_4SegmentRomEnd[];
extern u8 _Bmori1_room_5SegmentRomStart[]; extern u8 _Bmori1_room_5SegmentRomEnd[];
extern u8 _Bmori1_room_6SegmentRomStart[]; extern u8 _Bmori1_room_6SegmentRomEnd[];
extern u8 _Bmori1_room_7SegmentRomStart[]; extern u8 _Bmori1_room_7SegmentRomEnd[];
extern u8 _Bmori1_room_8SegmentRomStart[]; extern u8 _Bmori1_room_8SegmentRomEnd[];
extern u8 _Bmori1_room_9SegmentRomStart[]; extern u8 _Bmori1_room_9SegmentRomEnd[];
extern u8 _Bmori1_room_10SegmentRomStart[]; extern u8 _Bmori1_room_10SegmentRomEnd[];
extern u8 _Bmori1_room_11SegmentRomStart[]; extern u8 _Bmori1_room_11SegmentRomEnd[];
extern u8 _Bmori1_room_12SegmentRomStart[]; extern u8 _Bmori1_room_12SegmentRomEnd[];
extern u8 _Bmori1_room_13SegmentRomStart[]; extern u8 _Bmori1_room_13SegmentRomEnd[];
extern u8 _Bmori1_room_14SegmentRomStart[]; extern u8 _Bmori1_room_14SegmentRomEnd[];
extern u8 _Bmori1_room_15SegmentRomStart[]; extern u8 _Bmori1_room_15SegmentRomEnd[];
extern u8 _Bmori1_room_16SegmentRomStart[]; extern u8 _Bmori1_room_16SegmentRomEnd[];
extern u8 _Bmori1_room_17SegmentRomStart[]; extern u8 _Bmori1_room_17SegmentRomEnd[];
extern u8 _Bmori1_room_18SegmentRomStart[]; extern u8 _Bmori1_room_18SegmentRomEnd[];
extern u8 _Bmori1_room_19SegmentRomStart[]; extern u8 _Bmori1_room_19SegmentRomEnd[];
extern u8 _Bmori1_room_20SegmentRomStart[]; extern u8 _Bmori1_room_20SegmentRomEnd[];
extern u8 _Bmori1_room_21SegmentRomStart[]; extern u8 _Bmori1_room_21SegmentRomEnd[];
extern u8 _Bmori1_room_22SegmentRomStart[]; extern u8 _Bmori1_room_22SegmentRomEnd[];
extern u8 _HIDAN_sceneSegmentRomStart[]; extern u8 _HIDAN_sceneSegmentRomEnd[];
extern u8 _HIDAN_room_0SegmentRomStart[]; extern u8 _HIDAN_room_0SegmentRomEnd[];
extern u8 _HIDAN_room_1SegmentRomStart[]; extern u8 _HIDAN_room_1SegmentRomEnd[];
extern u8 _HIDAN_room_2SegmentRomStart[]; extern u8 _HIDAN_room_2SegmentRomEnd[];
extern u8 _HIDAN_room_3SegmentRomStart[]; extern u8 _HIDAN_room_3SegmentRomEnd[];
extern u8 _HIDAN_room_4SegmentRomStart[]; extern u8 _HIDAN_room_4SegmentRomEnd[];
extern u8 _HIDAN_room_5SegmentRomStart[]; extern u8 _HIDAN_room_5SegmentRomEnd[];
extern u8 _HIDAN_room_6SegmentRomStart[]; extern u8 _HIDAN_room_6SegmentRomEnd[];
extern u8 _HIDAN_room_7SegmentRomStart[]; extern u8 _HIDAN_room_7SegmentRomEnd[];
extern u8 _HIDAN_room_8SegmentRomStart[]; extern u8 _HIDAN_room_8SegmentRomEnd[];
extern u8 _HIDAN_room_9SegmentRomStart[]; extern u8 _HIDAN_room_9SegmentRomEnd[];
extern u8 _HIDAN_room_10SegmentRomStart[]; extern u8 _HIDAN_room_10SegmentRomEnd[];
extern u8 _HIDAN_room_11SegmentRomStart[]; extern u8 _HIDAN_room_11SegmentRomEnd[];
extern u8 _HIDAN_room_12SegmentRomStart[]; extern u8 _HIDAN_room_12SegmentRomEnd[];
extern u8 _HIDAN_room_13SegmentRomStart[]; extern u8 _HIDAN_room_13SegmentRomEnd[];
extern u8 _HIDAN_room_14SegmentRomStart[]; extern u8 _HIDAN_room_14SegmentRomEnd[];
extern u8 _HIDAN_room_15SegmentRomStart[]; extern u8 _HIDAN_room_15SegmentRomEnd[];
extern u8 _HIDAN_room_16SegmentRomStart[]; extern u8 _HIDAN_room_16SegmentRomEnd[];
extern u8 _HIDAN_room_17SegmentRomStart[]; extern u8 _HIDAN_room_17SegmentRomEnd[];
extern u8 _HIDAN_room_18SegmentRomStart[]; extern u8 _HIDAN_room_18SegmentRomEnd[];
extern u8 _HIDAN_room_19SegmentRomStart[]; extern u8 _HIDAN_room_19SegmentRomEnd[];
extern u8 _HIDAN_room_20SegmentRomStart[]; extern u8 _HIDAN_room_20SegmentRomEnd[];
extern u8 _HIDAN_room_21SegmentRomStart[]; extern u8 _HIDAN_room_21SegmentRomEnd[];
extern u8 _HIDAN_room_22SegmentRomStart[]; extern u8 _HIDAN_room_22SegmentRomEnd[];
extern u8 _HIDAN_room_23SegmentRomStart[]; extern u8 _HIDAN_room_23SegmentRomEnd[];
extern u8 _HIDAN_room_24SegmentRomStart[]; extern u8 _HIDAN_room_24SegmentRomEnd[];
extern u8 _HIDAN_room_25SegmentRomStart[]; extern u8 _HIDAN_room_25SegmentRomEnd[];
extern u8 _HIDAN_room_26SegmentRomStart[]; extern u8 _HIDAN_room_26SegmentRomEnd[];
extern u8 _MIZUsin_sceneSegmentRomStart[]; extern u8 _MIZUsin_sceneSegmentRomEnd[];
extern u8 _MIZUsin_room_0SegmentRomStart[]; extern u8 _MIZUsin_room_0SegmentRomEnd[];
extern u8 _MIZUsin_room_1SegmentRomStart[]; extern u8 _MIZUsin_room_1SegmentRomEnd[];
extern u8 _MIZUsin_room_2SegmentRomStart[]; extern u8 _MIZUsin_room_2SegmentRomEnd[];
extern u8 _MIZUsin_room_3SegmentRomStart[]; extern u8 _MIZUsin_room_3SegmentRomEnd[];
extern u8 _MIZUsin_room_4SegmentRomStart[]; extern u8 _MIZUsin_room_4SegmentRomEnd[];
extern u8 _MIZUsin_room_5SegmentRomStart[]; extern u8 _MIZUsin_room_5SegmentRomEnd[];
extern u8 _MIZUsin_room_6SegmentRomStart[]; extern u8 _MIZUsin_room_6SegmentRomEnd[];
extern u8 _MIZUsin_room_7SegmentRomStart[]; extern u8 _MIZUsin_room_7SegmentRomEnd[];
extern u8 _MIZUsin_room_8SegmentRomStart[]; extern u8 _MIZUsin_room_8SegmentRomEnd[];
extern u8 _MIZUsin_room_9SegmentRomStart[]; extern u8 _MIZUsin_room_9SegmentRomEnd[];
extern u8 _MIZUsin_room_10SegmentRomStart[]; extern u8 _MIZUsin_room_10SegmentRomEnd[];
extern u8 _MIZUsin_room_11SegmentRomStart[]; extern u8 _MIZUsin_room_11SegmentRomEnd[];
extern u8 _MIZUsin_room_12SegmentRomStart[]; extern u8 _MIZUsin_room_12SegmentRomEnd[];
extern u8 _MIZUsin_room_13SegmentRomStart[]; extern u8 _MIZUsin_room_13SegmentRomEnd[];
extern u8 _MIZUsin_room_14SegmentRomStart[]; extern u8 _MIZUsin_room_14SegmentRomEnd[];
extern u8 _MIZUsin_room_15SegmentRomStart[]; extern u8 _MIZUsin_room_15SegmentRomEnd[];
extern u8 _MIZUsin_room_16SegmentRomStart[]; extern u8 _MIZUsin_room_16SegmentRomEnd[];
extern u8 _MIZUsin_room_17SegmentRomStart[]; extern u8 _MIZUsin_room_17SegmentRomEnd[];
extern u8 _MIZUsin_room_18SegmentRomStart[]; extern u8 _MIZUsin_room_18SegmentRomEnd[];
extern u8 _MIZUsin_room_19SegmentRomStart[]; extern u8 _MIZUsin_room_19SegmentRomEnd[];
extern u8 _MIZUsin_room_20SegmentRomStart[]; extern u8 _MIZUsin_room_20SegmentRomEnd[];
extern u8 _MIZUsin_room_21SegmentRomStart[]; extern u8 _MIZUsin_room_21SegmentRomEnd[];
extern u8 _MIZUsin_room_22SegmentRomStart[]; extern u8 _MIZUsin_room_22SegmentRomEnd[];
extern u8 _jyasinzou_sceneSegmentRomStart[]; extern u8 _jyasinzou_sceneSegmentRomEnd[];
extern u8 _jyasinzou_room_0SegmentRomStart[]; extern u8 _jyasinzou_room_0SegmentRomEnd[];
extern u8 _jyasinzou_room_1SegmentRomStart[]; extern u8 _jyasinzou_room_1SegmentRomEnd[];
extern u8 _jyasinzou_room_2SegmentRomStart[]; extern u8 _jyasinzou_room_2SegmentRomEnd[];
extern u8 _jyasinzou_room_3SegmentRomStart[]; extern u8 _jyasinzou_room_3SegmentRomEnd[];
extern u8 _jyasinzou_room_4SegmentRomStart[]; extern u8 _jyasinzou_room_4SegmentRomEnd[];
extern u8 _jyasinzou_room_5SegmentRomStart[]; extern u8 _jyasinzou_room_5SegmentRomEnd[];
extern u8 _jyasinzou_room_6SegmentRomStart[]; extern u8 _jyasinzou_room_6SegmentRomEnd[];
extern u8 _jyasinzou_room_7SegmentRomStart[]; extern u8 _jyasinzou_room_7SegmentRomEnd[];
extern u8 _jyasinzou_room_8SegmentRomStart[]; extern u8 _jyasinzou_room_8SegmentRomEnd[];
extern u8 _jyasinzou_room_9SegmentRomStart[]; extern u8 _jyasinzou_room_9SegmentRomEnd[];
extern u8 _jyasinzou_room_10SegmentRomStart[]; extern u8 _jyasinzou_room_10SegmentRomEnd[];
extern u8 _jyasinzou_room_11SegmentRomStart[]; extern u8 _jyasinzou_room_11SegmentRomEnd[];
extern u8 _jyasinzou_room_12SegmentRomStart[]; extern u8 _jyasinzou_room_12SegmentRomEnd[];
extern u8 _jyasinzou_room_13SegmentRomStart[]; extern u8 _jyasinzou_room_13SegmentRomEnd[];
extern u8 _jyasinzou_room_14SegmentRomStart[]; extern u8 _jyasinzou_room_14SegmentRomEnd[];
extern u8 _jyasinzou_room_15SegmentRomStart[]; extern u8 _jyasinzou_room_15SegmentRomEnd[];
extern u8 _jyasinzou_room_16SegmentRomStart[]; extern u8 _jyasinzou_room_16SegmentRomEnd[];
extern u8 _jyasinzou_room_17SegmentRomStart[]; extern u8 _jyasinzou_room_17SegmentRomEnd[];
extern u8 _jyasinzou_room_18SegmentRomStart[]; extern u8 _jyasinzou_room_18SegmentRomEnd[];
extern u8 _jyasinzou_room_19SegmentRomStart[]; extern u8 _jyasinzou_room_19SegmentRomEnd[];
extern u8 _jyasinzou_room_20SegmentRomStart[]; extern u8 _jyasinzou_room_20SegmentRomEnd[];
extern u8 _jyasinzou_room_21SegmentRomStart[]; extern u8 _jyasinzou_room_21SegmentRomEnd[];
extern u8 _jyasinzou_room_22SegmentRomStart[]; extern u8 _jyasinzou_room_22SegmentRomEnd[];
extern u8 _jyasinzou_room_23SegmentRomStart[]; extern u8 _jyasinzou_room_23SegmentRomEnd[];
extern u8 _jyasinzou_room_24SegmentRomStart[]; extern u8 _jyasinzou_room_24SegmentRomEnd[];
extern u8 _jyasinzou_room_25SegmentRomStart[]; extern u8 _jyasinzou_room_25SegmentRomEnd[];
extern u8 _jyasinzou_room_26SegmentRomStart[]; extern u8 _jyasinzou_room_26SegmentRomEnd[];
extern u8 _jyasinzou_room_27SegmentRomStart[]; extern u8 _jyasinzou_room_27SegmentRomEnd[];
extern u8 _jyasinzou_room_28SegmentRomStart[]; extern u8 _jyasinzou_room_28SegmentRomEnd[];
extern u8 _HAKAdan_sceneSegmentRomStart[]; extern u8 _HAKAdan_sceneSegmentRomEnd[];
extern u8 _HAKAdan_room_0SegmentRomStart[]; extern u8 _HAKAdan_room_0SegmentRomEnd[];
extern u8 _HAKAdan_room_1SegmentRomStart[]; extern u8 _HAKAdan_room_1SegmentRomEnd[];
extern u8 _HAKAdan_room_2SegmentRomStart[]; extern u8 _HAKAdan_room_2SegmentRomEnd[];
extern u8 _HAKAdan_room_3SegmentRomStart[]; extern u8 _HAKAdan_room_3SegmentRomEnd[];
extern u8 _HAKAdan_room_4SegmentRomStart[]; extern u8 _HAKAdan_room_4SegmentRomEnd[];
extern u8 _HAKAdan_room_5SegmentRomStart[]; extern u8 _HAKAdan_room_5SegmentRomEnd[];
extern u8 _HAKAdan_room_6SegmentRomStart[]; extern u8 _HAKAdan_room_6SegmentRomEnd[];
extern u8 _HAKAdan_room_7SegmentRomStart[]; extern u8 _HAKAdan_room_7SegmentRomEnd[];
extern u8 _HAKAdan_room_8SegmentRomStart[]; extern u8 _HAKAdan_room_8SegmentRomEnd[];
extern u8 _HAKAdan_room_9SegmentRomStart[]; extern u8 _HAKAdan_room_9SegmentRomEnd[];
extern u8 _HAKAdan_room_10SegmentRomStart[]; extern u8 _HAKAdan_room_10SegmentRomEnd[];
extern u8 _HAKAdan_room_11SegmentRomStart[]; extern u8 _HAKAdan_room_11SegmentRomEnd[];
extern u8 _HAKAdan_room_12SegmentRomStart[]; extern u8 _HAKAdan_room_12SegmentRomEnd[];
extern u8 _HAKAdan_room_13SegmentRomStart[]; extern u8 _HAKAdan_room_13SegmentRomEnd[];
extern u8 _HAKAdan_room_14SegmentRomStart[]; extern u8 _HAKAdan_room_14SegmentRomEnd[];
extern u8 _HAKAdan_room_15SegmentRomStart[]; extern u8 _HAKAdan_room_15SegmentRomEnd[];
extern u8 _HAKAdan_room_16SegmentRomStart[]; extern u8 _HAKAdan_room_16SegmentRomEnd[];
extern u8 _HAKAdan_room_17SegmentRomStart[]; extern u8 _HAKAdan_room_17SegmentRomEnd[];
extern u8 _HAKAdan_room_18SegmentRomStart[]; extern u8 _HAKAdan_room_18SegmentRomEnd[];
extern u8 _HAKAdan_room_19SegmentRomStart[]; extern u8 _HAKAdan_room_19SegmentRomEnd[];
extern u8 _HAKAdan_room_20SegmentRomStart[]; extern u8 _HAKAdan_room_20SegmentRomEnd[];
extern u8 _HAKAdan_room_21SegmentRomStart[]; extern u8 _HAKAdan_room_21SegmentRomEnd[];
extern u8 _HAKAdan_room_22SegmentRomStart[]; extern u8 _HAKAdan_room_22SegmentRomEnd[];
extern u8 _HAKAdanCH_sceneSegmentRomStart[]; extern u8 _HAKAdanCH_sceneSegmentRomEnd[];
extern u8 _HAKAdanCH_room_0SegmentRomStart[]; extern u8 _HAKAdanCH_room_0SegmentRomEnd[];
extern u8 _HAKAdanCH_room_1SegmentRomStart[]; extern u8 _HAKAdanCH_room_1SegmentRomEnd[];
extern u8 _HAKAdanCH_room_2SegmentRomStart[]; extern u8 _HAKAdanCH_room_2SegmentRomEnd[];
extern u8 _HAKAdanCH_room_3SegmentRomStart[]; extern u8 _HAKAdanCH_room_3SegmentRomEnd[];
extern u8 _HAKAdanCH_room_4SegmentRomStart[]; extern u8 _HAKAdanCH_room_4SegmentRomEnd[];
extern u8 _HAKAdanCH_room_5SegmentRomStart[]; extern u8 _HAKAdanCH_room_5SegmentRomEnd[];
extern u8 _HAKAdanCH_room_6SegmentRomStart[]; extern u8 _HAKAdanCH_room_6SegmentRomEnd[];
extern u8 _ice_doukutu_sceneSegmentRomStart[]; extern u8 _ice_doukutu_sceneSegmentRomEnd[];
extern u8 _ice_doukutu_room_0SegmentRomStart[]; extern u8 _ice_doukutu_room_0SegmentRomEnd[];
extern u8 _ice_doukutu_room_1SegmentRomStart[]; extern u8 _ice_doukutu_room_1SegmentRomEnd[];
extern u8 _ice_doukutu_room_2SegmentRomStart[]; extern u8 _ice_doukutu_room_2SegmentRomEnd[];
extern u8 _ice_doukutu_room_3SegmentRomStart[]; extern u8 _ice_doukutu_room_3SegmentRomEnd[];
extern u8 _ice_doukutu_room_4SegmentRomStart[]; extern u8 _ice_doukutu_room_4SegmentRomEnd[];
extern u8 _ice_doukutu_room_5SegmentRomStart[]; extern u8 _ice_doukutu_room_5SegmentRomEnd[];
extern u8 _ice_doukutu_room_6SegmentRomStart[]; extern u8 _ice_doukutu_room_6SegmentRomEnd[];
extern u8 _ice_doukutu_room_7SegmentRomStart[]; extern u8 _ice_doukutu_room_7SegmentRomEnd[];
extern u8 _ice_doukutu_room_8SegmentRomStart[]; extern u8 _ice_doukutu_room_8SegmentRomEnd[];
extern u8 _ice_doukutu_room_9SegmentRomStart[]; extern u8 _ice_doukutu_room_9SegmentRomEnd[];
extern u8 _ice_doukutu_room_10SegmentRomStart[]; extern u8 _ice_doukutu_room_10SegmentRomEnd[];
extern u8 _ice_doukutu_room_11SegmentRomStart[]; extern u8 _ice_doukutu_room_11SegmentRomEnd[];
extern u8 _ganon_sceneSegmentRomStart[]; extern u8 _ganon_sceneSegmentRomEnd[];
extern u8 _ganon_room_0SegmentRomStart[]; extern u8 _ganon_room_0SegmentRomEnd[];
extern u8 _ganon_room_1SegmentRomStart[]; extern u8 _ganon_room_1SegmentRomEnd[];
extern u8 _ganon_room_2SegmentRomStart[]; extern u8 _ganon_room_2SegmentRomEnd[];
extern u8 _ganon_room_3SegmentRomStart[]; extern u8 _ganon_room_3SegmentRomEnd[];
extern u8 _ganon_room_4SegmentRomStart[]; extern u8 _ganon_room_4SegmentRomEnd[];
extern u8 _ganon_room_5SegmentRomStart[]; extern u8 _ganon_room_5SegmentRomEnd[];
extern u8 _ganon_room_6SegmentRomStart[]; extern u8 _ganon_room_6SegmentRomEnd[];
extern u8 _ganon_room_7SegmentRomStart[]; extern u8 _ganon_room_7SegmentRomEnd[];
extern u8 _ganon_room_8SegmentRomStart[]; extern u8 _ganon_room_8SegmentRomEnd[];
extern u8 _ganon_room_9SegmentRomStart[]; extern u8 _ganon_room_9SegmentRomEnd[];
extern u8 _men_sceneSegmentRomStart[]; extern u8 _men_sceneSegmentRomEnd[];
extern u8 _men_room_0SegmentRomStart[]; extern u8 _men_room_0SegmentRomEnd[];
extern u8 _men_room_1SegmentRomStart[]; extern u8 _men_room_1SegmentRomEnd[];
extern u8 _men_room_2SegmentRomStart[]; extern u8 _men_room_2SegmentRomEnd[];
extern u8 _men_room_3SegmentRomStart[]; extern u8 _men_room_3SegmentRomEnd[];
extern u8 _men_room_4SegmentRomStart[]; extern u8 _men_room_4SegmentRomEnd[];
extern u8 _men_room_5SegmentRomStart[]; extern u8 _men_room_5SegmentRomEnd[];
extern u8 _men_room_6SegmentRomStart[]; extern u8 _men_room_6SegmentRomEnd[];
extern u8 _men_room_7SegmentRomStart[]; extern u8 _men_room_7SegmentRomEnd[];
extern u8 _men_room_8SegmentRomStart[]; extern u8 _men_room_8SegmentRomEnd[];
extern u8 _men_room_9SegmentRomStart[]; extern u8 _men_room_9SegmentRomEnd[];
extern u8 _men_room_10SegmentRomStart[]; extern u8 _men_room_10SegmentRomEnd[];
extern u8 _gerudoway_sceneSegmentRomStart[]; extern u8 _gerudoway_sceneSegmentRomEnd[];
extern u8 _gerudoway_room_0SegmentRomStart[]; extern u8 _gerudoway_room_0SegmentRomEnd[];
extern u8 _gerudoway_room_1SegmentRomStart[]; extern u8 _gerudoway_room_1SegmentRomEnd[];
extern u8 _gerudoway_room_2SegmentRomStart[]; extern u8 _gerudoway_room_2SegmentRomEnd[];
extern u8 _gerudoway_room_3SegmentRomStart[]; extern u8 _gerudoway_room_3SegmentRomEnd[];
extern u8 _gerudoway_room_4SegmentRomStart[]; extern u8 _gerudoway_room_4SegmentRomEnd[];
extern u8 _gerudoway_room_5SegmentRomStart[]; extern u8 _gerudoway_room_5SegmentRomEnd[];
extern u8 _ganontika_sceneSegmentRomStart[]; extern u8 _ganontika_sceneSegmentRomEnd[];
extern u8 _ganontika_room_0SegmentRomStart[]; extern u8 _ganontika_room_0SegmentRomEnd[];
extern u8 _ganontika_room_1SegmentRomStart[]; extern u8 _ganontika_room_1SegmentRomEnd[];
extern u8 _ganontika_room_2SegmentRomStart[]; extern u8 _ganontika_room_2SegmentRomEnd[];
extern u8 _ganontika_room_3SegmentRomStart[]; extern u8 _ganontika_room_3SegmentRomEnd[];
extern u8 _ganontika_room_4SegmentRomStart[]; extern u8 _ganontika_room_4SegmentRomEnd[];
extern u8 _ganontika_room_5SegmentRomStart[]; extern u8 _ganontika_room_5SegmentRomEnd[];
extern u8 _ganontika_room_6SegmentRomStart[]; extern u8 _ganontika_room_6SegmentRomEnd[];
extern u8 _ganontika_room_7SegmentRomStart[]; extern u8 _ganontika_room_7SegmentRomEnd[];
extern u8 _ganontika_room_8SegmentRomStart[]; extern u8 _ganontika_room_8SegmentRomEnd[];
extern u8 _ganontika_room_9SegmentRomStart[]; extern u8 _ganontika_room_9SegmentRomEnd[];
extern u8 _ganontika_room_10SegmentRomStart[]; extern u8 _ganontika_room_10SegmentRomEnd[];
extern u8 _ganontika_room_11SegmentRomStart[]; extern u8 _ganontika_room_11SegmentRomEnd[];
extern u8 _ganontika_room_12SegmentRomStart[]; extern u8 _ganontika_room_12SegmentRomEnd[];
extern u8 _ganontika_room_13SegmentRomStart[]; extern u8 _ganontika_room_13SegmentRomEnd[];
extern u8 _ganontika_room_14SegmentRomStart[]; extern u8 _ganontika_room_14SegmentRomEnd[];
extern u8 _ganontika_room_15SegmentRomStart[]; extern u8 _ganontika_room_15SegmentRomEnd[];
extern u8 _ganontika_room_16SegmentRomStart[]; extern u8 _ganontika_room_16SegmentRomEnd[];
extern u8 _ganontika_room_17SegmentRomStart[]; extern u8 _ganontika_room_17SegmentRomEnd[];
extern u8 _ganontika_room_18SegmentRomStart[]; extern u8 _ganontika_room_18SegmentRomEnd[];
extern u8 _ganontika_room_19SegmentRomStart[]; extern u8 _ganontika_room_19SegmentRomEnd[];
extern u8 _ganon_sonogo_sceneSegmentRomStart[]; extern u8 _ganon_sonogo_sceneSegmentRomEnd[];
extern u8 _ganon_sonogo_room_0SegmentRomStart[]; extern u8 _ganon_sonogo_room_0SegmentRomEnd[];
extern u8 _ganon_sonogo_room_1SegmentRomStart[]; extern u8 _ganon_sonogo_room_1SegmentRomEnd[];
extern u8 _ganon_sonogo_room_2SegmentRomStart[]; extern u8 _ganon_sonogo_room_2SegmentRomEnd[];
extern u8 _ganon_sonogo_room_3SegmentRomStart[]; extern u8 _ganon_sonogo_room_3SegmentRomEnd[];
extern u8 _ganon_sonogo_room_4SegmentRomStart[]; extern u8 _ganon_sonogo_room_4SegmentRomEnd[];
extern u8 _ganontikasonogo_sceneSegmentRomStart[]; extern u8 _ganontikasonogo_sceneSegmentRomEnd[];
extern u8 _ganontikasonogo_room_0SegmentRomStart[]; extern u8 _ganontikasonogo_room_0SegmentRomEnd[];
extern u8 _ganontikasonogo_room_1SegmentRomStart[]; extern u8 _ganontikasonogo_room_1SegmentRomEnd[];
extern u8 _takaraya_sceneSegmentRomStart[]; extern u8 _takaraya_sceneSegmentRomEnd[];
extern u8 _takaraya_room_0SegmentRomStart[]; extern u8 _takaraya_room_0SegmentRomEnd[];
extern u8 _takaraya_room_1SegmentRomStart[]; extern u8 _takaraya_room_1SegmentRomEnd[];
extern u8 _takaraya_room_2SegmentRomStart[]; extern u8 _takaraya_room_2SegmentRomEnd[];
extern u8 _takaraya_room_3SegmentRomStart[]; extern u8 _takaraya_room_3SegmentRomEnd[];
extern u8 _takaraya_room_4SegmentRomStart[]; extern u8 _takaraya_room_4SegmentRomEnd[];
extern u8 _takaraya_room_5SegmentRomStart[]; extern u8 _takaraya_room_5SegmentRomEnd[];
extern u8 _takaraya_room_6SegmentRomStart[]; extern u8 _takaraya_room_6SegmentRomEnd[];
extern u8 _ydan_boss_sceneSegmentRomStart[]; extern u8 _ydan_boss_sceneSegmentRomEnd[];
extern u8 _ydan_boss_room_0SegmentRomStart[]; extern u8 _ydan_boss_room_0SegmentRomEnd[];
extern u8 _ydan_boss_room_1SegmentRomStart[]; extern u8 _ydan_boss_room_1SegmentRomEnd[];
extern u8 _ddan_boss_sceneSegmentRomStart[]; extern u8 _ddan_boss_sceneSegmentRomEnd[];
extern u8 _ddan_boss_room_0SegmentRomStart[]; extern u8 _ddan_boss_room_0SegmentRomEnd[];
extern u8 _ddan_boss_room_1SegmentRomStart[]; extern u8 _ddan_boss_room_1SegmentRomEnd[];
extern u8 _bdan_boss_sceneSegmentRomStart[]; extern u8 _bdan_boss_sceneSegmentRomEnd[];
extern u8 _bdan_boss_room_0SegmentRomStart[]; extern u8 _bdan_boss_room_0SegmentRomEnd[];
extern u8 _bdan_boss_room_1SegmentRomStart[]; extern u8 _bdan_boss_room_1SegmentRomEnd[];
extern u8 _moribossroom_sceneSegmentRomStart[]; extern u8 _moribossroom_sceneSegmentRomEnd[];
extern u8 _moribossroom_room_0SegmentRomStart[]; extern u8 _moribossroom_room_0SegmentRomEnd[];
extern u8 _moribossroom_room_1SegmentRomStart[]; extern u8 _moribossroom_room_1SegmentRomEnd[];
extern u8 _FIRE_bs_sceneSegmentRomStart[]; extern u8 _FIRE_bs_sceneSegmentRomEnd[];
extern u8 _FIRE_bs_room_0SegmentRomStart[]; extern u8 _FIRE_bs_room_0SegmentRomEnd[];
extern u8 _FIRE_bs_room_1SegmentRomStart[]; extern u8 _FIRE_bs_room_1SegmentRomEnd[];
extern u8 _MIZUsin_bs_sceneSegmentRomStart[]; extern u8 _MIZUsin_bs_sceneSegmentRomEnd[];
extern u8 _MIZUsin_bs_room_0SegmentRomStart[]; extern u8 _MIZUsin_bs_room_0SegmentRomEnd[];
extern u8 _MIZUsin_bs_room_1SegmentRomStart[]; extern u8 _MIZUsin_bs_room_1SegmentRomEnd[];
extern u8 _jyasinboss_sceneSegmentRomStart[]; extern u8 _jyasinboss_sceneSegmentRomEnd[];
extern u8 _jyasinboss_room_0SegmentRomStart[]; extern u8 _jyasinboss_room_0SegmentRomEnd[];
extern u8 _jyasinboss_room_1SegmentRomStart[]; extern u8 _jyasinboss_room_1SegmentRomEnd[];
extern u8 _jyasinboss_room_2SegmentRomStart[]; extern u8 _jyasinboss_room_2SegmentRomEnd[];
extern u8 _jyasinboss_room_3SegmentRomStart[]; extern u8 _jyasinboss_room_3SegmentRomEnd[];
extern u8 _HAKAdan_bs_sceneSegmentRomStart[]; extern u8 _HAKAdan_bs_sceneSegmentRomEnd[];
extern u8 _HAKAdan_bs_room_0SegmentRomStart[]; extern u8 _HAKAdan_bs_room_0SegmentRomEnd[];
extern u8 _HAKAdan_bs_room_1SegmentRomStart[]; extern u8 _HAKAdan_bs_room_1SegmentRomEnd[];
extern u8 _ganon_boss_sceneSegmentRomStart[]; extern u8 _ganon_boss_sceneSegmentRomEnd[];
extern u8 _ganon_boss_room_0SegmentRomStart[]; extern u8 _ganon_boss_room_0SegmentRomEnd[];
extern u8 _ganon_final_sceneSegmentRomStart[]; extern u8 _ganon_final_sceneSegmentRomEnd[];
extern u8 _ganon_final_room_0SegmentRomStart[]; extern u8 _ganon_final_room_0SegmentRomEnd[];
extern u8 _entra_sceneSegmentRomStart[]; extern u8 _entra_sceneSegmentRomEnd[];
extern u8 _entra_room_0SegmentRomStart[]; extern u8 _entra_room_0SegmentRomEnd[];
extern u8 _entra_n_sceneSegmentRomStart[]; extern u8 _entra_n_sceneSegmentRomEnd[];
extern u8 _entra_n_room_0SegmentRomStart[]; extern u8 _entra_n_room_0SegmentRomEnd[];
extern u8 _enrui_sceneSegmentRomStart[]; extern u8 _enrui_sceneSegmentRomEnd[];
extern u8 _enrui_room_0SegmentRomStart[]; extern u8 _enrui_room_0SegmentRomEnd[];
extern u8 _market_alley_sceneSegmentRomStart[]; extern u8 _market_alley_sceneSegmentRomEnd[];
extern u8 _market_alley_room_0SegmentRomStart[]; extern u8 _market_alley_room_0SegmentRomEnd[];
extern u8 _market_alley_n_sceneSegmentRomStart[]; extern u8 _market_alley_n_sceneSegmentRomEnd[];
extern u8 _market_alley_n_room_0SegmentRomStart[]; extern u8 _market_alley_n_room_0SegmentRomEnd[];
extern u8 _market_day_sceneSegmentRomStart[]; extern u8 _market_day_sceneSegmentRomEnd[];
extern u8 _market_day_room_0SegmentRomStart[]; extern u8 _market_day_room_0SegmentRomEnd[];
extern u8 _market_night_sceneSegmentRomStart[]; extern u8 _market_night_sceneSegmentRomEnd[];
extern u8 _market_night_room_0SegmentRomStart[]; extern u8 _market_night_room_0SegmentRomEnd[];
extern u8 _market_ruins_sceneSegmentRomStart[]; extern u8 _market_ruins_sceneSegmentRomEnd[];
extern u8 _market_ruins_room_0SegmentRomStart[]; extern u8 _market_ruins_room_0SegmentRomEnd[];
extern u8 _shrine_sceneSegmentRomStart[]; extern u8 _shrine_sceneSegmentRomEnd[];
extern u8 _shrine_room_0SegmentRomStart[]; extern u8 _shrine_room_0SegmentRomEnd[];
extern u8 _shrine_n_sceneSegmentRomStart[]; extern u8 _shrine_n_sceneSegmentRomEnd[];
extern u8 _shrine_n_room_0SegmentRomStart[]; extern u8 _shrine_n_room_0SegmentRomEnd[];
extern u8 _shrine_r_sceneSegmentRomStart[]; extern u8 _shrine_r_sceneSegmentRomEnd[];
extern u8 _shrine_r_room_0SegmentRomStart[]; extern u8 _shrine_r_room_0SegmentRomEnd[];
extern u8 _kokiri_home_sceneSegmentRomStart[]; extern u8 _kokiri_home_sceneSegmentRomEnd[];
extern u8 _kokiri_home_room_0SegmentRomStart[]; extern u8 _kokiri_home_room_0SegmentRomEnd[];
extern u8 _kokiri_home3_sceneSegmentRomStart[]; extern u8 _kokiri_home3_sceneSegmentRomEnd[];
extern u8 _kokiri_home3_room_0SegmentRomStart[]; extern u8 _kokiri_home3_room_0SegmentRomEnd[];
extern u8 _kokiri_home4_sceneSegmentRomStart[]; extern u8 _kokiri_home4_sceneSegmentRomEnd[];
extern u8 _kokiri_home4_room_0SegmentRomStart[]; extern u8 _kokiri_home4_room_0SegmentRomEnd[];
extern u8 _kokiri_home5_sceneSegmentRomStart[]; extern u8 _kokiri_home5_sceneSegmentRomEnd[];
extern u8 _kokiri_home5_room_0SegmentRomStart[]; extern u8 _kokiri_home5_room_0SegmentRomEnd[];
extern u8 _kakariko_sceneSegmentRomStart[]; extern u8 _kakariko_sceneSegmentRomEnd[];
extern u8 _kakariko_room_0SegmentRomStart[]; extern u8 _kakariko_room_0SegmentRomEnd[];
extern u8 _kakariko3_sceneSegmentRomStart[]; extern u8 _kakariko3_sceneSegmentRomEnd[];
extern u8 _kakariko3_room_0SegmentRomStart[]; extern u8 _kakariko3_room_0SegmentRomEnd[];
extern u8 _shop1_sceneSegmentRomStart[]; extern u8 _shop1_sceneSegmentRomEnd[];
extern u8 _shop1_room_0SegmentRomStart[]; extern u8 _shop1_room_0SegmentRomEnd[];
extern u8 _kokiri_shop_sceneSegmentRomStart[]; extern u8 _kokiri_shop_sceneSegmentRomEnd[];
extern u8 _kokiri_shop_room_0SegmentRomStart[]; extern u8 _kokiri_shop_room_0SegmentRomEnd[];
extern u8 _golon_sceneSegmentRomStart[]; extern u8 _golon_sceneSegmentRomEnd[];
extern u8 _golon_room_0SegmentRomStart[]; extern u8 _golon_room_0SegmentRomEnd[];
extern u8 _zoora_sceneSegmentRomStart[]; extern u8 _zoora_sceneSegmentRomEnd[];
extern u8 _zoora_room_0SegmentRomStart[]; extern u8 _zoora_room_0SegmentRomEnd[];
extern u8 _drag_sceneSegmentRomStart[]; extern u8 _drag_sceneSegmentRomEnd[];
extern u8 _drag_room_0SegmentRomStart[]; extern u8 _drag_room_0SegmentRomEnd[];
extern u8 _alley_shop_sceneSegmentRomStart[]; extern u8 _alley_shop_sceneSegmentRomEnd[];
extern u8 _alley_shop_room_0SegmentRomStart[]; extern u8 _alley_shop_room_0SegmentRomEnd[];
extern u8 _night_shop_sceneSegmentRomStart[]; extern u8 _night_shop_sceneSegmentRomEnd[];
extern u8 _night_shop_room_0SegmentRomStart[]; extern u8 _night_shop_room_0SegmentRomEnd[];
extern u8 _face_shop_sceneSegmentRomStart[]; extern u8 _face_shop_sceneSegmentRomEnd[];
extern u8 _face_shop_room_0SegmentRomStart[]; extern u8 _face_shop_room_0SegmentRomEnd[];
extern u8 _link_home_sceneSegmentRomStart[]; extern u8 _link_home_sceneSegmentRomEnd[];
extern u8 _link_home_room_0SegmentRomStart[]; extern u8 _link_home_room_0SegmentRomEnd[];
extern u8 _impa_sceneSegmentRomStart[]; extern u8 _impa_sceneSegmentRomEnd[];
extern u8 _impa_room_0SegmentRomStart[]; extern u8 _impa_room_0SegmentRomEnd[];
extern u8 _malon_stable_sceneSegmentRomStart[]; extern u8 _malon_stable_sceneSegmentRomEnd[];
extern u8 _malon_stable_room_0SegmentRomStart[]; extern u8 _malon_stable_room_0SegmentRomEnd[];
extern u8 _labo_sceneSegmentRomStart[]; extern u8 _labo_sceneSegmentRomEnd[];
extern u8 _labo_room_0SegmentRomStart[]; extern u8 _labo_room_0SegmentRomEnd[];
extern u8 _hylia_labo_sceneSegmentRomStart[]; extern u8 _hylia_labo_sceneSegmentRomEnd[];
extern u8 _hylia_labo_room_0SegmentRomStart[]; extern u8 _hylia_labo_room_0SegmentRomEnd[];
extern u8 _tent_sceneSegmentRomStart[]; extern u8 _tent_sceneSegmentRomEnd[];
extern u8 _tent_room_0SegmentRomStart[]; extern u8 _tent_room_0SegmentRomEnd[];
extern u8 _hut_sceneSegmentRomStart[]; extern u8 _hut_sceneSegmentRomEnd[];
extern u8 _hut_room_0SegmentRomStart[]; extern u8 _hut_room_0SegmentRomEnd[];
extern u8 _daiyousei_izumi_sceneSegmentRomStart[]; extern u8 _daiyousei_izumi_sceneSegmentRomEnd[];
extern u8 _daiyousei_izumi_room_0SegmentRomStart[]; extern u8 _daiyousei_izumi_room_0SegmentRomEnd[];
extern u8 _yousei_izumi_tate_sceneSegmentRomStart[]; extern u8 _yousei_izumi_tate_sceneSegmentRomEnd[];
extern u8 _yousei_izumi_tate_room_0SegmentRomStart[]; extern u8 _yousei_izumi_tate_room_0SegmentRomEnd[];
extern u8 _yousei_izumi_yoko_sceneSegmentRomStart[]; extern u8 _yousei_izumi_yoko_sceneSegmentRomEnd[];
extern u8 _yousei_izumi_yoko_room_0SegmentRomStart[]; extern u8 _yousei_izumi_yoko_room_0SegmentRomEnd[];
extern u8 _kakusiana_sceneSegmentRomStart[]; extern u8 _kakusiana_sceneSegmentRomEnd[];
extern u8 _kakusiana_room_0SegmentRomStart[]; extern u8 _kakusiana_room_0SegmentRomEnd[];
extern u8 _kakusiana_room_1SegmentRomStart[]; extern u8 _kakusiana_room_1SegmentRomEnd[];
extern u8 _kakusiana_room_2SegmentRomStart[]; extern u8 _kakusiana_room_2SegmentRomEnd[];
extern u8 _kakusiana_room_3SegmentRomStart[]; extern u8 _kakusiana_room_3SegmentRomEnd[];
extern u8 _kakusiana_room_4SegmentRomStart[]; extern u8 _kakusiana_room_4SegmentRomEnd[];
extern u8 _kakusiana_room_5SegmentRomStart[]; extern u8 _kakusiana_room_5SegmentRomEnd[];
extern u8 _kakusiana_room_6SegmentRomStart[]; extern u8 _kakusiana_room_6SegmentRomEnd[];
extern u8 _kakusiana_room_7SegmentRomStart[]; extern u8 _kakusiana_room_7SegmentRomEnd[];
extern u8 _kakusiana_room_8SegmentRomStart[]; extern u8 _kakusiana_room_8SegmentRomEnd[];
extern u8 _kakusiana_room_9SegmentRomStart[]; extern u8 _kakusiana_room_9SegmentRomEnd[];
extern u8 _kakusiana_room_10SegmentRomStart[]; extern u8 _kakusiana_room_10SegmentRomEnd[];
extern u8 _kakusiana_room_11SegmentRomStart[]; extern u8 _kakusiana_room_11SegmentRomEnd[];
extern u8 _kakusiana_room_12SegmentRomStart[]; extern u8 _kakusiana_room_12SegmentRomEnd[];
extern u8 _kakusiana_room_13SegmentRomStart[]; extern u8 _kakusiana_room_13SegmentRomEnd[];
extern u8 _hakaana_sceneSegmentRomStart[]; extern u8 _hakaana_sceneSegmentRomEnd[];
extern u8 _hakaana_room_0SegmentRomStart[]; extern u8 _hakaana_room_0SegmentRomEnd[];
extern u8 _hakaana2_sceneSegmentRomStart[]; extern u8 _hakaana2_sceneSegmentRomEnd[];
extern u8 _hakaana2_room_0SegmentRomStart[]; extern u8 _hakaana2_room_0SegmentRomEnd[];
extern u8 _hakaana_ouke_sceneSegmentRomStart[]; extern u8 _hakaana_ouke_sceneSegmentRomEnd[];
extern u8 _hakaana_ouke_room_0SegmentRomStart[]; extern u8 _hakaana_ouke_room_0SegmentRomEnd[];
extern u8 _hakaana_ouke_room_1SegmentRomStart[]; extern u8 _hakaana_ouke_room_1SegmentRomEnd[];
extern u8 _hakaana_ouke_room_2SegmentRomStart[]; extern u8 _hakaana_ouke_room_2SegmentRomEnd[];
extern u8 _syatekijyou_sceneSegmentRomStart[]; extern u8 _syatekijyou_sceneSegmentRomEnd[];
extern u8 _syatekijyou_room_0SegmentRomStart[]; extern u8 _syatekijyou_room_0SegmentRomEnd[];
extern u8 _tokinoma_sceneSegmentRomStart[]; extern u8 _tokinoma_sceneSegmentRomEnd[];
extern u8 _tokinoma_room_0SegmentRomStart[]; extern u8 _tokinoma_room_0SegmentRomEnd[];
extern u8 _tokinoma_room_1SegmentRomStart[]; extern u8 _tokinoma_room_1SegmentRomEnd[];
extern u8 _kenjyanoma_sceneSegmentRomStart[]; extern u8 _kenjyanoma_sceneSegmentRomEnd[];
extern u8 _kenjyanoma_room_0SegmentRomStart[]; extern u8 _kenjyanoma_room_0SegmentRomEnd[];
extern u8 _hairal_niwa_sceneSegmentRomStart[]; extern u8 _hairal_niwa_sceneSegmentRomEnd[];
extern u8 _hairal_niwa_room_0SegmentRomStart[]; extern u8 _hairal_niwa_room_0SegmentRomEnd[];
extern u8 _hairal_niwa_n_sceneSegmentRomStart[]; extern u8 _hairal_niwa_n_sceneSegmentRomEnd[];
extern u8 _hairal_niwa_n_room_0SegmentRomStart[]; extern u8 _hairal_niwa_n_room_0SegmentRomEnd[];
extern u8 _hiral_demo_sceneSegmentRomStart[]; extern u8 _hiral_demo_sceneSegmentRomEnd[];
extern u8 _hiral_demo_room_0SegmentRomStart[]; extern u8 _hiral_demo_room_0SegmentRomEnd[];
extern u8 _hakasitarelay_sceneSegmentRomStart[]; extern u8 _hakasitarelay_sceneSegmentRomEnd[];
extern u8 _hakasitarelay_room_0SegmentRomStart[]; extern u8 _hakasitarelay_room_0SegmentRomEnd[];
extern u8 _hakasitarelay_room_1SegmentRomStart[]; extern u8 _hakasitarelay_room_1SegmentRomEnd[];
extern u8 _hakasitarelay_room_2SegmentRomStart[]; extern u8 _hakasitarelay_room_2SegmentRomEnd[];
extern u8 _hakasitarelay_room_3SegmentRomStart[]; extern u8 _hakasitarelay_room_3SegmentRomEnd[];
extern u8 _hakasitarelay_room_4SegmentRomStart[]; extern u8 _hakasitarelay_room_4SegmentRomEnd[];
extern u8 _hakasitarelay_room_5SegmentRomStart[]; extern u8 _hakasitarelay_room_5SegmentRomEnd[];
extern u8 _hakasitarelay_room_6SegmentRomStart[]; extern u8 _hakasitarelay_room_6SegmentRomEnd[];
extern u8 _turibori_sceneSegmentRomStart[]; extern u8 _turibori_sceneSegmentRomEnd[];
extern u8 _turibori_room_0SegmentRomStart[]; extern u8 _turibori_room_0SegmentRomEnd[];
extern u8 _nakaniwa_sceneSegmentRomStart[]; extern u8 _nakaniwa_sceneSegmentRomEnd[];
extern u8 _nakaniwa_room_0SegmentRomStart[]; extern u8 _nakaniwa_room_0SegmentRomEnd[];
extern u8 _bowling_sceneSegmentRomStart[]; extern u8 _bowling_sceneSegmentRomEnd[];
extern u8 _bowling_room_0SegmentRomStart[]; extern u8 _bowling_room_0SegmentRomEnd[];
extern u8 _souko_sceneSegmentRomStart[]; extern u8 _souko_sceneSegmentRomEnd[];
extern u8 _souko_room_0SegmentRomStart[]; extern u8 _souko_room_0SegmentRomEnd[];
extern u8 _souko_room_1SegmentRomStart[]; extern u8 _souko_room_1SegmentRomEnd[];
extern u8 _souko_room_2SegmentRomStart[]; extern u8 _souko_room_2SegmentRomEnd[];
extern u8 _miharigoya_sceneSegmentRomStart[]; extern u8 _miharigoya_sceneSegmentRomEnd[];
extern u8 _miharigoya_room_0SegmentRomStart[]; extern u8 _miharigoya_room_0SegmentRomEnd[];
extern u8 _mahouya_sceneSegmentRomStart[]; extern u8 _mahouya_sceneSegmentRomEnd[];
extern u8 _mahouya_room_0SegmentRomStart[]; extern u8 _mahouya_room_0SegmentRomEnd[];
extern u8 _ganon_demo_sceneSegmentRomStart[]; extern u8 _ganon_demo_sceneSegmentRomEnd[];
extern u8 _ganon_demo_room_0SegmentRomStart[]; extern u8 _ganon_demo_room_0SegmentRomEnd[];
extern u8 _kinsuta_sceneSegmentRomStart[]; extern u8 _kinsuta_sceneSegmentRomEnd[];
extern u8 _kinsuta_room_0SegmentRomStart[]; extern u8 _kinsuta_room_0SegmentRomEnd[];
extern u8 _spot00_sceneSegmentRomStart[]; extern u8 _spot00_sceneSegmentRomEnd[];
extern u8 _spot00_room_0SegmentRomStart[]; extern u8 _spot00_room_0SegmentRomEnd[];
extern u8 _spot01_sceneSegmentRomStart[]; extern u8 _spot01_sceneSegmentRomEnd[];
extern u8 _spot01_room_0SegmentRomStart[]; extern u8 _spot01_room_0SegmentRomEnd[];
extern u8 _spot02_sceneSegmentRomStart[]; extern u8 _spot02_sceneSegmentRomEnd[];
extern u8 _spot02_room_0SegmentRomStart[]; extern u8 _spot02_room_0SegmentRomEnd[];
extern u8 _spot02_room_1SegmentRomStart[]; extern u8 _spot02_room_1SegmentRomEnd[];
extern u8 _spot03_sceneSegmentRomStart[]; extern u8 _spot03_sceneSegmentRomEnd[];
extern u8 _spot03_room_0SegmentRomStart[]; extern u8 _spot03_room_0SegmentRomEnd[];
extern u8 _spot03_room_1SegmentRomStart[]; extern u8 _spot03_room_1SegmentRomEnd[];
extern u8 _spot04_sceneSegmentRomStart[]; extern u8 _spot04_sceneSegmentRomEnd[];
extern u8 _spot04_room_0SegmentRomStart[]; extern u8 _spot04_room_0SegmentRomEnd[];
extern u8 _spot04_room_1SegmentRomStart[]; extern u8 _spot04_room_1SegmentRomEnd[];
extern u8 _spot04_room_2SegmentRomStart[]; extern u8 _spot04_room_2SegmentRomEnd[];
extern u8 _spot05_sceneSegmentRomStart[]; extern u8 _spot05_sceneSegmentRomEnd[];
extern u8 _spot05_room_0SegmentRomStart[]; extern u8 _spot05_room_0SegmentRomEnd[];
extern u8 _spot06_sceneSegmentRomStart[]; extern u8 _spot06_sceneSegmentRomEnd[];
extern u8 _spot06_room_0SegmentRomStart[]; extern u8 _spot06_room_0SegmentRomEnd[];
extern u8 _spot07_sceneSegmentRomStart[]; extern u8 _spot07_sceneSegmentRomEnd[];
extern u8 _spot07_room_0SegmentRomStart[]; extern u8 _spot07_room_0SegmentRomEnd[];
extern u8 _spot07_room_1SegmentRomStart[]; extern u8 _spot07_room_1SegmentRomEnd[];
extern u8 _spot08_sceneSegmentRomStart[]; extern u8 _spot08_sceneSegmentRomEnd[];
extern u8 _spot08_room_0SegmentRomStart[]; extern u8 _spot08_room_0SegmentRomEnd[];
extern u8 _spot09_sceneSegmentRomStart[]; extern u8 _spot09_sceneSegmentRomEnd[];
extern u8 _spot09_room_0SegmentRomStart[]; extern u8 _spot09_room_0SegmentRomEnd[];
extern u8 _spot10_sceneSegmentRomStart[]; extern u8 _spot10_sceneSegmentRomEnd[];
extern u8 _spot10_room_0SegmentRomStart[]; extern u8 _spot10_room_0SegmentRomEnd[];
extern u8 _spot10_room_1SegmentRomStart[]; extern u8 _spot10_room_1SegmentRomEnd[];
extern u8 _spot10_room_2SegmentRomStart[]; extern u8 _spot10_room_2SegmentRomEnd[];
extern u8 _spot10_room_3SegmentRomStart[]; extern u8 _spot10_room_3SegmentRomEnd[];
extern u8 _spot10_room_4SegmentRomStart[]; extern u8 _spot10_room_4SegmentRomEnd[];
extern u8 _spot10_room_5SegmentRomStart[]; extern u8 _spot10_room_5SegmentRomEnd[];
extern u8 _spot10_room_6SegmentRomStart[]; extern u8 _spot10_room_6SegmentRomEnd[];
extern u8 _spot10_room_7SegmentRomStart[]; extern u8 _spot10_room_7SegmentRomEnd[];
extern u8 _spot10_room_8SegmentRomStart[]; extern u8 _spot10_room_8SegmentRomEnd[];
extern u8 _spot10_room_9SegmentRomStart[]; extern u8 _spot10_room_9SegmentRomEnd[];
extern u8 _spot11_sceneSegmentRomStart[]; extern u8 _spot11_sceneSegmentRomEnd[];
extern u8 _spot11_room_0SegmentRomStart[]; extern u8 _spot11_room_0SegmentRomEnd[];
extern u8 _spot12_sceneSegmentRomStart[]; extern u8 _spot12_sceneSegmentRomEnd[];
extern u8 _spot12_room_0SegmentRomStart[]; extern u8 _spot12_room_0SegmentRomEnd[];
extern u8 _spot12_room_1SegmentRomStart[]; extern u8 _spot12_room_1SegmentRomEnd[];
extern u8 _spot13_sceneSegmentRomStart[]; extern u8 _spot13_sceneSegmentRomEnd[];
extern u8 _spot13_room_0SegmentRomStart[]; extern u8 _spot13_room_0SegmentRomEnd[];
extern u8 _spot13_room_1SegmentRomStart[]; extern u8 _spot13_room_1SegmentRomEnd[];
extern u8 _spot15_sceneSegmentRomStart[]; extern u8 _spot15_sceneSegmentRomEnd[];
extern u8 _spot15_room_0SegmentRomStart[]; extern u8 _spot15_room_0SegmentRomEnd[];
extern u8 _spot16_sceneSegmentRomStart[]; extern u8 _spot16_sceneSegmentRomEnd[];
extern u8 _spot16_room_0SegmentRomStart[]; extern u8 _spot16_room_0SegmentRomEnd[];
extern u8 _spot17_sceneSegmentRomStart[]; extern u8 _spot17_sceneSegmentRomEnd[];
extern u8 _spot17_room_0SegmentRomStart[]; extern u8 _spot17_room_0SegmentRomEnd[];
extern u8 _spot17_room_1SegmentRomStart[]; extern u8 _spot17_room_1SegmentRomEnd[];
extern u8 _spot18_sceneSegmentRomStart[]; extern u8 _spot18_sceneSegmentRomEnd[];
extern u8 _spot18_room_0SegmentRomStart[]; extern u8 _spot18_room_0SegmentRomEnd[];
extern u8 _spot18_room_1SegmentRomStart[]; extern u8 _spot18_room_1SegmentRomEnd[];
extern u8 _spot18_room_2SegmentRomStart[]; extern u8 _spot18_room_2SegmentRomEnd[];
extern u8 _spot18_room_3SegmentRomStart[]; extern u8 _spot18_room_3SegmentRomEnd[];
extern u8 _spot20_sceneSegmentRomStart[]; extern u8 _spot20_sceneSegmentRomEnd[];
extern u8 _spot20_room_0SegmentRomStart[]; extern u8 _spot20_room_0SegmentRomEnd[];
extern u8 _ganon_tou_sceneSegmentRomStart[]; extern u8 _ganon_tou_sceneSegmentRomEnd[];
extern u8 _ganon_tou_room_0SegmentRomStart[]; extern u8 _ganon_tou_room_0SegmentRomEnd[];
extern u8 _test01_sceneSegmentRomStart[]; extern u8 _test01_sceneSegmentRomEnd[];
extern u8 _test01_room_0SegmentRomStart[]; extern u8 _test01_room_0SegmentRomEnd[];
extern u8 _besitu_sceneSegmentRomStart[]; extern u8 _besitu_sceneSegmentRomEnd[];
extern u8 _besitu_room_0SegmentRomStart[]; extern u8 _besitu_room_0SegmentRomEnd[];
extern u8 _depth_test_sceneSegmentRomStart[]; extern u8 _depth_test_sceneSegmentRomEnd[];
extern u8 _depth_test_room_0SegmentRomStart[]; extern u8 _depth_test_room_0SegmentRomEnd[];
extern u8 _syotes_sceneSegmentRomStart[]; extern u8 _syotes_sceneSegmentRomEnd[];
extern u8 _syotes_room_0SegmentRomStart[]; extern u8 _syotes_room_0SegmentRomEnd[];
extern u8 _syotes2_sceneSegmentRomStart[]; extern u8 _syotes2_sceneSegmentRomEnd[];
extern u8 _syotes2_room_0SegmentRomStart[]; extern u8 _syotes2_room_0SegmentRomEnd[];
extern u8 _sutaru_sceneSegmentRomStart[]; extern u8 _sutaru_sceneSegmentRomEnd[];
extern u8 _sutaru_room_0SegmentRomStart[]; extern u8 _sutaru_room_0SegmentRomEnd[];
extern u8 _hairal_niwa2_sceneSegmentRomStart[]; extern u8 _hairal_niwa2_sceneSegmentRomEnd[];
extern u8 _hairal_niwa2_room_0SegmentRomStart[]; extern u8 _hairal_niwa2_room_0SegmentRomEnd[];
extern u8 _sasatest_sceneSegmentRomStart[]; extern u8 _sasatest_sceneSegmentRomEnd[];
extern u8 _sasatest_room_0SegmentRomStart[]; extern u8 _sasatest_room_0SegmentRomEnd[];
extern u8 _testroom_sceneSegmentRomStart[]; extern u8 _testroom_sceneSegmentRomEnd[];
extern u8 _testroom_room_0SegmentRomStart[]; extern u8 _testroom_room_0SegmentRomEnd[];
extern u8 _testroom_room_1SegmentRomStart[]; extern u8 _testroom_room_1SegmentRomEnd[];
extern u8 _testroom_room_2SegmentRomStart[]; extern u8 _testroom_room_2SegmentRomEnd[];
extern u8 _testroom_room_3SegmentRomStart[]; extern u8 _testroom_room_3SegmentRomEnd[];
extern u8 _testroom_room_4SegmentRomStart[]; extern u8 _testroom_room_4SegmentRomEnd[];
extern u8 D_02000000[];
extern u8 D_02000400[];
extern u8 D_02000500[];
extern u8 D_02000900[];
extern u8 D_02000A00[][0x400];
extern u8 D_02001E00[];
extern u8 D_02001F00[];
extern u8 D_02002FC0[];
extern u8 D_02002000[];
extern u8 D_02002100[];
extern u8 D_02002500[];
extern u8 D_02002580[];
extern u8 D_02002600[];
extern u8 D_02002900[];
extern u8 D_02003040[][0x80];
extern u8 D_020035C0[][0x40];
extern u8 D_020038C0[];
extern u8 D_02003940[];
extern u8 D_02003AC0[];
extern u32 D_0300AA48;
extern u32 D_03012B20;
extern Gfx D_06006CC0[];
extern Gfx D_06016118[];
extern Gfx D_06025218[];
extern Gfx D_060252D8[];
extern Gfx D_06025438[];
extern Gfx D_06025598[];
extern Gfx D_06025658[];
extern Gfx D_060257B8[];
extern Gfx D_0602A738[];
extern Gfx D_0602CB48[];
extern u8 D_080895C0[];
extern u32 osTvType;
extern u32 osRomBase;
extern u32 osResetType;
extern u32 osMemSize;
extern u8 osAppNmiBuffer[];
extern u8 D_80009320[];
extern u8 D_800093F0[];
extern s8 D_80009430;
extern u32 D_80009460;
extern u32 gDmaMgrDmaBuffSize;
extern vu8 gViConfigUseDefault;
extern u8 gViConfigAdditionalScanLines;
extern u32 gViConfigFeatures;
extern f32 gViConfigXScale;
extern f32 gViConfigYScale;
extern OSPiHandle* gCartHandle;
extern u32 gCurrentRegion;
extern u32 __osPiAccessQueueEnabled;
extern OSViMode osViModePalLan1;
extern u64 osClockRate;
extern s32 osViClock;
extern u32 __osShutdown;
extern u32 __OSGlobalIntMask;
extern OSThread* __osThreadTail[];
extern OSThread* __osRunQueue;
extern OSThread* __osActiveQueue;
extern OSThread* __osRunningThread;
extern OSThread* __osFaultedThread;
extern OSPiHandle* __osPiTable;
extern OSPiHandle* __osCurrentHandle[];
extern OSTimer* __osTimerList;
extern OSViMode osViModeNtscLan1;
extern OSViMode osViModeMpalLan1;
extern OSViContext* __osViCurr;
extern OSViContext* __osViNext;
extern OSViMode osViModeFpalLan1;
extern u32 __additional_scanline;
extern u8 gBuildTeam[];
extern u8 gBuildDate[];
extern u8 gBuildMakeOption[];
extern OSMesgQueue gPiMgrCmdQ;
extern OSViMode gViConfigMode;
extern u8 D_80013960;
extern OSMesg piAccessBuf;
extern OSMesgQueue __osPiAccessQueue;
extern OSPiHandle __Dom1SpeedParam;
extern OSPiHandle __Dom2SpeedParam;
extern OSThread __osThreadSave;
extern OSTimer __osBaseTimer;
extern OSTime __osCurrentTime;
extern u32 __osBaseCounter;
extern u32 __osViIntrCount;
extern u32 __osTimerCounter;
extern OSPiHandle __CartRomHandle;
extern DmaEntry gDmaDataTable[0x60C];
extern u8 D_801120C0[];
extern u8 D_80113070[];
extern u8 D_80114930[];
extern EffectSsOverlay gEffectSsOverlayTable[EFFECT_SS_TYPE_MAX];
extern Gfx D_80116280[];
extern ActorOverlay gActorOverlayTable[ACTOR_ID_MAX];
extern s32 gMaxActorId;
extern s32 gDbgCamEnabled;
extern s16 D_8011E0B0;
extern GameStateOverlay gGameStateOverlayTable[6];
extern u8 D_8011FB30;
extern u8 D_8011FB34;
extern u8 D_8011FB38;
extern u8 D_8011FB3C;
extern u16 D_8011FB40;
extern s32 gZeldaArenaLogSeverity;
extern s16 D_80120130;
extern MapData gMapDataTable;
extern s16 gSpoilingItems[3];
extern s16 gSpoilingItemReverts[3];
extern FlexSkeletonHeader* gPlayerSkelHeaders[2];
extern u8 gPlayerModelTypes[][5];
extern Gfx* D_80125D68[];
extern Gfx* D_80125DE8[];
extern Gfx* D_80125E08[];
extern Gfx* D_80125E18[];
extern Gfx* D_80125E58[];
extern Gfx* D_80125EF8[];
extern Gfx gCullBackDList[];
extern Gfx gCullFrontDList[];
extern Gfx gEmptyDL[];
extern u32 gBitFlags[32];
extern u16 gEquipMasks[4];
extern u16 gEquipNegMasks[4];
extern u32 gUpgradeMasks[8];
extern u32 gUpgradeNegMasks[8];
extern u8 gEquipShifts[4];
extern u8 gUpgradeShifts[8];
extern u16 gUpgradeCapacities[8][4];
extern u32 D_8012723C[4];
extern u32 D_8012724C[4];
extern u32 gItemIcons[0x82];
extern u8 gItemSlots[56];
extern void (*gSceneCmdHandlers[26])(GlobalContext*, SceneCmd*);
extern s16 gLinkObjectIds[2];
extern u32 gObjectTableSize;
extern RomFile gObjectTable[OBJECT_ID_MAX];
extern EntranceInfo gEntranceTable[1556];
extern Scene gSceneTable[SCENE_ID_MAX];
extern u16 gSramSlotOffsets[2][3];
extern u8 gLetterTLUT[4][32];
extern u8 gFontFF[];
extern KaleidoManagerOvl gKaleidoMgrOverlayTable[2];
extern KaleidoManagerOvl* gKaleidoMgrCurOvl;
extern void* D_8012D1F0;
extern s32 gScreenWidth;
extern s32 gScreenHeight;
extern u32 gSystemHeapSize;
extern Mtx gMtxClear;
extern MtxF gMtxFClear;
extern u8 D_8012DBB0;
extern u32 D_8012DBC0;
extern vu32 gIrqMgrResetStatus;
extern volatile OSTime gIrqMgrRetraceTime;
extern s32 gDebugArenaLogSeverity;
extern s16* gWaveSamples[6];
extern f32 gPitchBendFrequencyScale[256];
extern f32 D_8012F4B4[256];
extern f32 gNoteFrequencies[];
extern u8 gDefaultShortNoteVelocityTable[16];
extern u8 gDefaultShortNoteDurationTable[16];
extern AdsrEnvelope gDefaultEnvelope[3];
extern NoteSubEu gZeroNoteSub;
extern NoteSubEu gDefaultNoteSub;
extern u16 gHeadsetPanQuantization[0x10];
extern f32 gHeadsetPanVolume[128];
extern f32 gStereoPanVolume[128];
extern f32 gDefaultPanVolume[128];
extern s16 D_80130228[];
extern s16 D_80130328[];
extern f32 D_80130510;
extern s32 D_80130514;
extern u8 D_80130570[8];
extern u8 D_80130578[4][7];
extern u8 D_80130594[4][7];
extern u8* gFrogsSongPtr;
extern u8* gScarecrowCustomSongPtr;
extern u8* gScarecrowSpawnSongPtr;
extern u8 D_80133340[4];
extern s32 D_8013338C;
extern s32 D_80133390[];
extern s32 D_80133398[];
extern u8 D_801333A0;
extern u8 D_801333A4;
extern SoundBankEntry* gSoundBanks[7];
extern u8 sBankSizes[7];
extern u8 D_801333CC;
extern u16 D_801333D0;
extern Vec3f D_801333D4;
extern f32 D_801333E0;
extern f32 D_801333E8;
extern u8 D_801333F0;
extern u8 D_801333F4;
extern u8 D_801333F8;
extern AudioSessionSettings gAudioSessionPresets[];
extern s32 gOverlayLogSeverity;
extern s32 gSystemArenaLogSeverity;
extern u32 gOSSiAccessQueueCreated;
extern u32 gOSContInitialized;
extern s32 __osPfsInodeCacheChannel;
extern u8 __osPfsInodeCacheBank;
extern s32 __osPfsLastChannel;
extern char D_80136208[];
extern char D_80136218[];
extern char D_80136228[];
extern char D_80136238[];
extern char D_80136A54[];
extern char D_80136A68[];
extern char D_80136A7C[];
extern char D_80136A90[];
extern char D_80136AA4[];
extern char D_80136AB8[];
extern f32 D_80136D3C;
extern f32 D_80136D40;
extern f32 D_80136D44;
extern char D_8013C190[];
extern char D_8013C860[];
extern char D_8013C874[];
extern f32 D_8013C888;
extern f32 D_8013C88C;
extern f32 D_8013C890;
extern f32 D_8013C894;
extern f32 D_8013C898;
extern f32 D_8013CB80;
extern u32* D_8013E960;
extern u32* D_8013E99C;
extern char D_80141030[];
extern char D_80145F68[];
extern char D_80145F94[];
extern char D_80145FA0[];
extern char D_80145FFC[];
extern char D_80146014[];
extern char D_801461CC[];
extern char D_80146230[];
extern char D_80146238[];
extern s16 gTatumsPerBeat;
extern u8 D_80155F50[];
extern u8 D_80157580[];
extern u8 D_801579A0[];
extern u8 D_80157D30[];
extern SaveContext gSaveContext;
extern GameInfo* gGameInfo;
extern u16 D_8015FCC0;
extern u16 D_8015FCC2;
extern u16 D_8015FCC4;
extern u8 D_8015FCF0;
extern Vec3f D_8015FCF8;
extern s16 D_8015FD04;
extern s16 D_8015FD06;
extern f32 D_8015FD08;
extern s16 D_8015FD0C;
extern u8 D_8015FD70;
extern MapData* gMapData;
extern u8 D_80161010;
extern u8 D_801610D4;
extern u8 D_801610D5;
extern u8 D_801610DA;
extern s32 gTrnsnUnkState;
extern Color_RGBA8_u32 D_801614B0;
extern SpeedMeter gSpeedMeter;
extern PreNmiBuff* gAppNmiBufferPtr;
extern SchedContext gSchedContext;
extern PadMgr gPadMgr;
extern u32 gSegments[(16)];
extern volatile OSTime D_8016A520;
extern volatile OSTime D_8016A528;
extern volatile OSTime D_8016A530;
extern volatile OSTime D_8016A538;
extern volatile OSTime D_8016A540;
extern volatile OSTime D_8016A548;
extern volatile OSTime D_8016A550;
extern volatile OSTime D_8016A558;
extern volatile OSTime gRSPAudioTotalTime;
extern volatile OSTime gRSPGFXTotalTime;
extern volatile OSTime gRSPOtherTotalTime;
extern volatile OSTime gRDPTotalTime;
extern SpeedMeterTimeEntry* gSpeedMeterTimeEntryPtr;
extern FaultThreadStruct gFaultStruct;
extern SoundBankEntry D_8016BAD0[9];
extern SoundBankEntry D_8016BC80[12];
extern SoundBankEntry D_8016BEC0[22];
extern SoundBankEntry D_8016C2E0[20];
extern SoundBankEntry D_8016C6A0[8];
extern SoundBankEntry D_8016C820[3];
extern SoundBankEntry D_8016C8B0[5];
extern u8 D_8016E1A0[7];
extern u8 D_8016E1A8[7];
extern u8 D_8016E1B0[7];
extern u8 D_8016E260;
extern u8 D_8016E264[];
extern u16 D_8016E2E0[];
extern u16 D_8016E2F8[];
extern u8 D_8016E310[];
extern AudioContext gAudioContext;
extern NotePool gNoteFreeLists;
extern u32 __osMalloc_FreeBlockTest_Enable;
extern Arena gSystemArena;
extern OSPifRam osPifBuffers[4];
extern OSMesg osSiMesgBuff[2];
extern OSMesgQueue gOSSiMessageQueue;
extern OSPifRam __osPifInternalBuff;
extern u8 __osContLastPoll;
extern u8 __osMaxControllers;
extern OSMesgQueue __osContMesgQueue;
extern OSMesg __osContMesgBuff[4];
extern __OSInode __osPfsInodeCache;
extern OSPifRam pifMempakBuf;
extern u16 gZBuffer[240][320];
extern u64 gGfxSPTaskOutputBuffer[0x3000];
extern u8 gGfxSPTaskYieldBuffer[0xC00];
extern u8 gGfxSPTaskStack[0x400];
extern GfxPool gGfxPools[2];
extern u8 gAudioHeap[0x38000];
extern u8 gSystemHeap[];
extern MapMarksData* gMapMarkDataTable[];
extern GraphicsContext* __gfxCtx;
void func_800AC030(OSViMode* osvimodep) {
    LOG("osvimodep", osvimodep, "%08x", "../z_vimode.c", 87);
    LOG("osvimodep->comRegs.ctrl", osvimodep->comRegs.ctrl, "%08x", "../z_vimode.c", 88);
    LOG("osvimodep->comRegs.width", osvimodep->comRegs.width, "%08x", "../z_vimode.c", 89);
    LOG("osvimodep->comRegs.burst", osvimodep->comRegs.burst, "%08x", "../z_vimode.c", 90);
    LOG("osvimodep->comRegs.vSync", osvimodep->comRegs.vSync, "%08x", "../z_vimode.c", 91);
    LOG("osvimodep->comRegs.hSync", osvimodep->comRegs.hSync, "%08x", "../z_vimode.c", 92);
    LOG("osvimodep->comRegs.leap", osvimodep->comRegs.leap, "%08x", "../z_vimode.c", 93);
    LOG("osvimodep->comRegs.hStart", osvimodep->comRegs.hStart, "%08x", "../z_vimode.c", 94);
    LOG("osvimodep->comRegs.xScale", osvimodep->comRegs.xScale, "%08x", "../z_vimode.c", 95);
    LOG("osvimodep->fldRegs[0].vStart", osvimodep->fldRegs[0].vStart, "%08x", "../z_vimode.c", 96);
    LOG("osvimodep->fldRegs[0].vBurst", osvimodep->fldRegs[0].vBurst, "%08x", "../z_vimode.c", 97);
    LOG("osvimodep->fldRegs[0].origin", osvimodep->fldRegs[0].origin, "%08x", "../z_vimode.c", 98);
    LOG("osvimodep->fldRegs[0].yScale", osvimodep->fldRegs[0].yScale, "%08x", "../z_vimode.c", 99);
    LOG("osvimodep->fldRegs[0].vIntr", osvimodep->fldRegs[0].vIntr, "%08x", "../z_vimode.c", 100);
    LOG("osvimodep->fldRegs[1].vStart", osvimodep->fldRegs[1].vStart, "%08x", "../z_vimode.c", 101);
    LOG("osvimodep->fldRegs[1].vBurst", osvimodep->fldRegs[1].vBurst, "%08x", "../z_vimode.c", 102);
    LOG("osvimodep->fldRegs[1].origin", osvimodep->fldRegs[1].origin, "%08x", "../z_vimode.c", 103);
    LOG("osvimodep->fldRegs[1].yScale", osvimodep->fldRegs[1].yScale, "%08x", "../z_vimode.c", 104);
    LOG("osvimodep->fldRegs[1].vIntr", osvimodep->fldRegs[1].vIntr, "%08x", "../z_vimode.c", 105);
}
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
        (!unk_7C ? 0x01 | 0x02 : 0x02) |
        (0x1000 | 0x2000 | 0x04 | 0x08) |
        (!cond2 ? 0x40 : 0) |
        (!unk_74 ? 0x10 : 0);
    if (cond4) {
        this->viMode.comRegs.ctrl |= 0x100;
    } else if ((cond5 | cond6)) {
        this->viMode.comRegs.ctrl |= 0x100 | 0x200;
    } else if (unk_74) {
        this->viMode.comRegs.ctrl |= 0x200;
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
void func_800AC89C(ViModeContext* this) {
    gGameInfo->data[1 * 6 * 16 + 48] = this->unk_68;
    gGameInfo->data[1 * 6 * 16 + 49] = this->width;
    gGameInfo->data[1 * 6 * 16 + 50] = this->height;
    gGameInfo->data[1 * 6 * 16 + 51] = this->unk_64;
    gGameInfo->data[1 * 6 * 16 + 52] = this->unk_60;
    gGameInfo->data[1 * 6 * 16 + 53] = this->unk_5C;
    gGameInfo->data[1 * 6 * 16 + 54] = this->unk_58;
    if (gGameInfo->data[1 * 6 * 16 + 58] == 1) {
        gGameInfo->data[1 * 6 * 16 + 58] = 0;
        switch (gGameInfo->data[1 * 6 * 16 + 59]) {
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
void func_800AC9A4(ViModeContext* this) {
    if ((gGameInfo->data[1 * 6 * 16 + 49] & ~3) == 1) {
        gGameInfo->data[1 * 6 * 16 + 49] += 4;
    }
    this->unk_68 = gGameInfo->data[1 * 6 * 16 + 48];
    this->width = gGameInfo->data[1 * 6 * 16 + 49] & ~0x3;
    this->height = gGameInfo->data[1 * 6 * 16 + 50];
    this->unk_64 = gGameInfo->data[1 * 6 * 16 + 51];
    this->unk_60 = gGameInfo->data[1 * 6 * 16 + 52];
    this->unk_5C = gGameInfo->data[1 * 6 * 16 + 53];
    this->unk_58 = gGameInfo->data[1 * 6 * 16 + 54];
}
void func_800ACA28(ViModeContext* this) {
    this->unk_68 = 0;
    this->width = 320;
    this->height = 240;
    this->unk_5C = 0;
    this->unk_58 = 0;
    this->unk_64 = 0;
    this->unk_60 = 0;
    this->viFeatures = 0x0040 | 0x0002;
    this->tvType = osTvType;
    this->unk_7C = 1;
    this->unk_78 = 1;
    this->unk_74 = 0;
    this->unk_70 = 1;
    func_800AC89C(this);
}
void func_800ACA90(ViModeContext* this) {
}
void func_800ACA98(ViModeContext* this, s32 flag) {
    s32 mode = this->viMode.comRegs.ctrl;
    if (flag & 0x0001) {
        mode |= 0x08;
    }
    if (flag & 0x0002) {
        mode &= ~0x08;
    }
    if (flag & 0x0004) {
        mode |= 0x04;
    }
    if (flag & 0x0008) {
        mode &= ~0x04;
    }
    if (flag & 0x0010) {
        mode |= 0x10;
    }
    if (flag & 0x0020) {
        mode &= ~0x10;
    }
    this->viMode.comRegs.ctrl = mode;
}
void func_800ACAF8(ViModeContext* this, Input* input) {
    func_800AC9A4(this);
    if (this->unk_68 == 1 || this->unk_68 == 2 || this->unk_68 == 3) {
        gScreenWidth = this->width;
        gScreenHeight = this->height;
        if ((~((input->cur.button) | ~(0x1000 | 0x0001 | 0x0008)) == 0)) {
            func_800ACA28(this);
        }
        if ((~((input->cur.button) | ~(0x0008)) == 0)) {
            if ((~((input->cur.button) | ~(0x0800)) == 0)) {
                this->unk_64--;
            }
            if ((~((input->cur.button) | ~(0x0400)) == 0)) {
                this->unk_64++;
            }
            if ((~((input->cur.button) | ~(0x0200)) == 0)) {
                this->unk_5C--;
            }
            if ((~((input->cur.button) | ~(0x0100)) == 0)) {
                this->unk_5C++;
            }
        }
        if ((~((input->cur.button) | ~(0x0001)) == 0)) {
            if ((~((input->cur.button) | ~(0x0800)) == 0)) {
                this->unk_60--;
            }
            if ((~((input->cur.button) | ~(0x0400)) == 0)) {
                this->unk_60++;
            }
            if ((~((input->cur.button) | ~(0x0200)) == 0)) {
                this->unk_58--;
            }
            if ((~((input->cur.button) | ~(0x0100)) == 0)) {
                this->unk_58++;
            }
        }
        if ((~((input->cur.button) | ~(0x0004)) == 0)) {
            if ((~((input->press.button) | ~(0x0800)) == 0)) {
                this->unk_70 = !this->unk_70;
            }
            if ((~((input->press.button) | ~(0x0400)) == 0)) {
                this->unk_74 = !this->unk_74;
            }
            if ((~((input->press.button) | ~(0x0200)) == 0)) {
                this->unk_78 = !this->unk_78;
            }
            if ((~((input->press.button) | ~(0x0100)) == 0)) {
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
