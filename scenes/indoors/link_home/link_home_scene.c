#include <ultra64.h>
#include <z64.h>
#include "link_home_scene.h"
#include <z64.h>
#include <segment_symbols.h>
#include <command_macros_base.h>
#include <z64cutscene_commands.h>
#include <variables.h>



SCmdAltHeaders _link_home_scene_set0000_cmd00 = { 0x18, 0, (u32)&_link_home_scene_alternateHeaders_00000060}; // 0x0000
SCmdSoundSettings _link_home_scene_set0000_cmd01 = { 0x15, 0x05, 0x00, 0x00, 0x00, 0x00, 0x13, 0x1F }; // 0x0008
SCmdRoomList _link_home_scene_set0000_cmd02 = { 0x04, 0x01, (u32)&_link_home_scene_roomList_00000094 }; // 0x0010
SCmdMiscSettings _link_home_scene_set0000_cmd03 = { 0x19, 0x20, 0x00000004 }; // 0x0018
SCmdColHeader _link_home_scene_set0000_cmd04 = { 0x03, 0x00, (u32)&_link_home_scene_collisionHeader_00000E4C}; // 0x0020
SCmdEntranceList _link_home_scene_set0000_cmd05 = { 0x06, 0x00, (u32)&_link_home_scene_entranceList_0000009C }; // 0x0028
SCmdSpecialFiles _link_home_scene_set0000_cmd06 = { 0x07, 0x00, 0x0003}; // 0x0030
SCmdSpawnList _link_home_scene_set0000_cmd07 = { 0x00, 0x02, (u32)&_link_home_scene_startPositionList_00000074}; // 0x0038
SCmdSkyboxSettings _link_home_scene_set0000_cmd08 = { 0x11, 0x00, 0x00, 0x00, 0x07, 0x00, 0x01}; // 0x0040
SCmdExitList _link_home_scene_set0000_cmd09 = { 0x13, 0x00, (u32)&_link_home_scene_exitList_000000A0 }; // 0x0048
SCmdLightSettingList _link_home_scene_set0000_cmd0A = { 0x0F, 1, (u32)&_link_home_scene_lightSettings_000000A4}; // 0x0050
SCmdEndMarker _link_home_scene_set0000_cmd0B = { 0x14, 0x00, 0x00 }; // 0x0058
u32 _link_home_scene_alternateHeaders_00000060[] = 
{
	0,
	0,
	0,
	(u32)&_link_home_scene_set0E80_cmd00,
	(u32)&_link_home_scene_set0F60_cmd00,
};

ActorEntry _link_home_scene_startPositionList_00000074[] = 
{
	{ ACTOR_PLAYER, 1, 0, 95, 0, -32768, 0, 0x0D00 },
	{ ACTOR_PLAYER, -4, 0, -114, 0, 0, 0, 0x0EFF },
};

RomFile _link_home_scene_roomList_00000094[] = 
{
	{ (u32)_link_home_room_0SegmentRomStart, (u32)_link_home_room_0SegmentRomEnd },
};

EntranceEntry _link_home_scene_entranceList_0000009C[] = 
{
	{ 0x00, 0x00 }, //0x0000009C 
	{ 0x01, 0x00 }, //0x0000009E 
};

u16 _link_home_scene_exitList_000000A0[] = 
{
	0x0211,
	0x0211,
};

LightSettings _link_home_scene_lightSettings_000000A4[] = 
{
	{ 0x46, 0x3C, 0x28, 0x2A, 0x3C, 0x67, 0xFA, 0xE6, 0xE6, 0x02, 0xFA, 0x82, 0x96, 0xA0, 0xB4, 0x0A, 0x0A, 0x0A, 0x07E0, 0x07D0 }, // 0x000000A4 
};

static u8 unaccounted00BC[] = 
{
	0x00, 0x00, 0x00, 0x00, 
};

CamPosData _link_home_scene_camPosData_000000C0[] = 
{
	{ -118, 345, 47, 12743, 20389, 0, 4683, -1, 0xFFFF }, // 0x020000C0
	{ 0, 34, 0, 0, 16384, 0, 6000, -1, 0xFFFF }, // 0x020000D2
};

CamData _link_home_scene_camData_000000E4 = { 0x0019, 0x0003, (u32)_link_home_scene_camPosData_000000C0 };

CamPosDataEntry _link_home_scene_camPosDataEntries_000000EC[] = 
{
	{ 0x001A0003, (u32)&_link_home_scene_camPosData_000000C0[1] }, // 0x000000EC
	{ 0x00000000, 0x00000000 }, // 0x000000F4
};

u32 _link_home_scene_polygonTypes_000000FC[] = 
{
	 0x00200002, 0x00000FC0, 
	 0x00200002, 0x00000FCA, 
	 0x00200002, 0x00000800, 
	 0x00000002, 0x0000080A, 
	 0x00200002, 0x0000080A, 
	 0x00000202, 0x040C080A, 
	 0x00000002, 0x00000FC0, 
};

RoomPoly _link_home_scene_polygons_00000134[] = 
{
	{ 0x0000, 0x002F, 0x0030, 0x0031, 0x5F24, 0x0000, 0x55A0, 0xFFD8 }, // 0x00000134
	{ 0x0000, 0x002F, 0x0031, 0x0032, 0x5F24, 0x0000, 0x55A0, 0xFFD8 }, // 0x00000144
	{ 0x0001, 0x0033, 0x0034, 0x0035, 0xA0DC, 0x0000, 0xAA60, 0x0000 }, // 0x00000154
	{ 0x0001, 0x0033, 0x0035, 0x0036, 0xA0DC, 0x0000, 0xAA60, 0x0000 }, // 0x00000164
	{ 0x0000, 0x0034, 0x0033, 0x0031, 0xAA60, 0x0000, 0x5F24, 0x006C }, // 0x00000174
	{ 0x0000, 0x0034, 0x0031, 0x0030, 0xAA60, 0x0000, 0x5F24, 0x006C }, // 0x00000184
	{ 0x0002, 0x0037, 0x0038, 0x0039, 0x0000, 0x0000, 0x7FFF, 0x005C }, // 0x00000194
	{ 0x0002, 0x0037, 0x0039, 0x003A, 0x0000, 0x0000, 0x7FFF, 0x005C }, // 0x000001A4
	{ 0x0002, 0x0038, 0x003B, 0x003C, 0xCF44, 0x0000, 0x765B, 0x0070 }, // 0x000001B4
	{ 0x0002, 0x0038, 0x003C, 0x0039, 0xCF44, 0x0000, 0x765B, 0x0070 }, // 0x000001C4
	{ 0x0002, 0x003B, 0x003D, 0x003E, 0xC6C2, 0x0000, 0x727C, 0x0071 }, // 0x000001D4
	{ 0x0002, 0x003B, 0x003E, 0x003C, 0xC6C2, 0x0000, 0x727C, 0x0071 }, // 0x000001E4
	{ 0x0002, 0x003D, 0x003F, 0x0040, 0xACB4, 0x0000, 0x612F, 0x006D }, // 0x000001F4
	{ 0x0002, 0x003D, 0x0040, 0x003E, 0xACB4, 0x0000, 0x612F, 0x006D }, // 0x00000204
	{ 0x0002, 0x003F, 0x0041, 0x0042, 0x8033, 0x0000, 0x071A, 0x0030 }, // 0x00000214
	{ 0x0002, 0x003F, 0x0042, 0x0040, 0x8033, 0x0000, 0x071A, 0x0030 }, // 0x00000224
	{ 0x0003, 0x0003, 0x0002, 0x0043, 0x0000, 0x7FFF, 0x0000, 0x0000 }, // 0x00000234
	{ 0x0003, 0x0003, 0x0043, 0x0007, 0x0000, 0x7FFF, 0x0000, 0x0000 }, // 0x00000244
	{ 0x0003, 0x0003, 0x0007, 0x0006, 0x0000, 0x7FFF, 0x0000, 0x0000 }, // 0x00000254
	{ 0x0003, 0x0003, 0x0006, 0x0009, 0x0000, 0x7FFF, 0x0000, 0x0000 }, // 0x00000264
	{ 0x0003, 0x0003, 0x0009, 0x000B, 0x0000, 0x7FFF, 0x0000, 0x0000 }, // 0x00000274
	{ 0x0003, 0x0003, 0x000B, 0x000D, 0x0000, 0x7FFF, 0x0000, 0x0000 }, // 0x00000284
	{ 0x0004, 0x0000, 0x0001, 0x0002, 0x899F, 0x0000, 0x30AE, 0x008C }, // 0x00000294
	{ 0x0004, 0x0000, 0x0002, 0x0003, 0x899F, 0x0000, 0x30AE, 0x008C }, // 0x000002A4
	{ 0x0004, 0x0004, 0x0005, 0x0006, 0x7661, 0x0000, 0x30AE, 0x008C }, // 0x000002B4
	{ 0x0004, 0x0004, 0x0006, 0x0007, 0x7661, 0x0000, 0x30AE, 0x008C }, // 0x000002C4
	{ 0x0004, 0x0005, 0x0008, 0x0009, 0x7661, 0x0000, 0xCF52, 0x008C }, // 0x000002D4
	{ 0x0004, 0x0005, 0x0009, 0x0006, 0x7661, 0x0000, 0xCF52, 0x008C }, // 0x000002E4
	{ 0x0004, 0x0008, 0x000A, 0x000B, 0x30AE, 0x0000, 0x899F, 0x008C }, // 0x000002F4
	{ 0x0004, 0x0008, 0x000B, 0x0009, 0x30AE, 0x0000, 0x899F, 0x008C }, // 0x00000304
	{ 0x0004, 0x000A, 0x000C, 0x000D, 0xCF52, 0x0000, 0x899F, 0x008C }, // 0x00000314
	{ 0x0004, 0x000A, 0x000D, 0x000B, 0xCF52, 0x0000, 0x899F, 0x008C }, // 0x00000324
	{ 0x0004, 0x000C, 0x0000, 0x0003, 0x899F, 0x0000, 0xCF52, 0x008C }, // 0x00000334
	{ 0x0004, 0x000C, 0x0003, 0x000D, 0x899F, 0x0000, 0xCF52, 0x008C }, // 0x00000344
	{ 0x0004, 0x000E, 0x0004, 0x0007, 0x3066, 0x0000, 0x767E, 0x008C }, // 0x00000354
	{ 0x0004, 0x000E, 0x0007, 0x000F, 0x3066, 0x0000, 0x767E, 0x008C }, // 0x00000364
	{ 0x0002, 0x0001, 0x0010, 0x0011, 0xCF9A, 0x0000, 0x767E, 0x008C }, // 0x00000374
	{ 0x0004, 0x0001, 0x0011, 0x0002, 0xCF9A, 0x0000, 0x767E, 0x008C }, // 0x00000384
	{ 0x0005, 0x000F, 0x2011, 0x0044, 0x0000, 0x7FFF, 0x0000, 0x0000 }, // 0x00000394
	{ 0x0005, 0x000F, 0x2044, 0x0045, 0x0000, 0x7FFF, 0x0000, 0x0000 }, // 0x000003A4
	{ 0x0002, 0x8011, 0x0010, 0x0046, 0x8001, 0x0000, 0x0000, 0x0024 }, // 0x000003B4
	{ 0x0002, 0x8011, 0x0046, 0x0044, 0x8001, 0x0000, 0x0000, 0x0024 }, // 0x000003C4
	{ 0x0004, 0x0044, 0x0046, 0x0047, 0x0000, 0x0000, 0x7FFF, 0x00D8 }, // 0x000003D4
	{ 0x0004, 0x0044, 0x0047, 0x0045, 0x0000, 0x0000, 0x7FFF, 0x00D8 }, // 0x000003E4
	{ 0x0004, 0x0045, 0x0047, 0x000E, 0x7FFF, 0x0000, 0x0000, 0x0024 }, // 0x000003F4
	{ 0x0004, 0x0045, 0x000E, 0x000F, 0x7FFF, 0x0000, 0x0000, 0x0024 }, // 0x00000404
	{ 0x0003, 0x0048, 0x0049, 0x004A, 0x0000, 0x7FFF, 0x0000, 0xFFF4 }, // 0x00000414
	{ 0x0003, 0x0048, 0x004A, 0x004B, 0x0000, 0x7FFF, 0x0000, 0xFFF4 }, // 0x00000424
	{ 0x0003, 0x0048, 0x004B, 0x004C, 0x0000, 0x7FFF, 0x0000, 0xFFF4 }, // 0x00000434
	{ 0x0003, 0x0048, 0x004C, 0x004D, 0x0000, 0x7FFF, 0x0000, 0xFFF4 }, // 0x00000444
	{ 0x0003, 0x0048, 0x004D, 0x004E, 0x0000, 0x7FFF, 0x0000, 0xFFF4 }, // 0x00000454
	{ 0x0003, 0x0048, 0x004E, 0x004F, 0x0000, 0x7FFF, 0x0000, 0xFFF4 }, // 0x00000464
	{ 0x0003, 0x0048, 0x004F, 0x0050, 0x0000, 0x7FFF, 0x0000, 0xFFF4 }, // 0x00000474
	{ 0x0003, 0x0048, 0x0050, 0x0049, 0x0000, 0x7FFF, 0x0000, 0xFFF4 }, // 0x00000484
	{ 0x0004, 0x0051, 0x0052, 0x004A, 0x6FE4, 0x0000, 0xC1D7, 0xFFB3 }, // 0x00000494
	{ 0x0004, 0x0051, 0x004A, 0x0049, 0x6FE4, 0x0000, 0xC1D7, 0xFFB3 }, // 0x000004A4
	{ 0x0004, 0x0052, 0x0053, 0x004B, 0xB240, 0x0000, 0x9A53, 0x006F }, // 0x000004B4
	{ 0x0004, 0x0052, 0x004B, 0x004A, 0xB240, 0x0000, 0x9A53, 0x006F }, // 0x000004C4
	{ 0x0004, 0x0053, 0x0054, 0x004C, 0xBE26, 0x0000, 0x923F, 0x006A }, // 0x000004D4
	{ 0x0004, 0x0053, 0x004C, 0x004B, 0xBE26, 0x0000, 0x923F, 0x006A }, // 0x000004E4
	{ 0x0004, 0x0054, 0x0055, 0x004D, 0x8929, 0x0000, 0xD077, 0x0070 }, // 0x000004F4
	{ 0x0004, 0x0054, 0x004D, 0x004C, 0x8929, 0x0000, 0xD077, 0x0070 }, // 0x00000504
	{ 0x0002, 0x0055, 0x0056, 0x004E, 0x923F, 0x0000, 0x41DA, 0x002A }, // 0x00000514
	{ 0x0002, 0x0055, 0x004E, 0x004D, 0x923F, 0x0000, 0x41DA, 0x002A }, // 0x00000524
	{ 0x0004, 0x0056, 0x0057, 0x004F, 0xE6E6, 0x0000, 0x7D83, 0xFFC7 }, // 0x00000534
	{ 0x0004, 0x0056, 0x004F, 0x004E, 0xE6E6, 0x0000, 0x7D83, 0xFFC7 }, // 0x00000544
	{ 0x0004, 0x0057, 0x0058, 0x0050, 0xC6C2, 0x0000, 0x727C, 0xFFE7 }, // 0x00000554
	{ 0x0004, 0x0057, 0x0050, 0x004F, 0xC6C2, 0x0000, 0x727C, 0xFFE7 }, // 0x00000564
	{ 0x0004, 0x0058, 0x0051, 0x0049, 0x7A0E, 0x0000, 0x268B, 0xFF73 }, // 0x00000574
	{ 0x0004, 0x0058, 0x0049, 0x0050, 0x7A0E, 0x0000, 0x268B, 0xFF73 }, // 0x00000584
	{ 0x0003, 0x0059, 0x005A, 0x005B, 0x0000, 0x7FFF, 0x0000, 0xFFF4 }, // 0x00000594
	{ 0x0003, 0x0059, 0x005B, 0x005C, 0x0000, 0x7FFF, 0x0000, 0xFFF4 }, // 0x000005A4
	{ 0x0003, 0x0059, 0x005C, 0x005D, 0x0000, 0x7FFF, 0x0000, 0xFFF4 }, // 0x000005B4
	{ 0x0003, 0x0059, 0x005D, 0x005E, 0x0000, 0x7FFF, 0x0000, 0xFFF4 }, // 0x000005C4
	{ 0x0003, 0x0059, 0x005E, 0x005F, 0x0000, 0x7FFF, 0x0000, 0xFFF4 }, // 0x000005D4
	{ 0x0003, 0x0059, 0x005F, 0x0060, 0x0000, 0x7FFF, 0x0000, 0xFFF4 }, // 0x000005E4
	{ 0x0003, 0x0059, 0x0060, 0x0061, 0x0000, 0x7FFF, 0x0000, 0xFFF4 }, // 0x000005F4
	{ 0x0003, 0x0059, 0x0061, 0x005A, 0x0000, 0x7FFF, 0x0000, 0xFFF4 }, // 0x00000604
	{ 0x0004, 0x0062, 0x0063, 0x005B, 0x1F0B, 0x0000, 0x83D3, 0xFFE7 }, // 0x00000614
	{ 0x0004, 0x0062, 0x005B, 0x005A, 0x1F0B, 0x0000, 0x83D3, 0xFFE7 }, // 0x00000624
	{ 0x0004, 0x0063, 0x0064, 0x005C, 0x2F89, 0x0000, 0x8929, 0xFFD6 }, // 0x00000634
	{ 0x0004, 0x0063, 0x005C, 0x005B, 0x2F89, 0x0000, 0x8929, 0xFFD6 }, // 0x00000644
	{ 0x0004, 0x0064, 0x0065, 0x005D, 0xD077, 0x0000, 0x8929, 0x0033 }, // 0x00000654
	{ 0x0004, 0x0064, 0x005D, 0x005C, 0xD077, 0x0000, 0x8929, 0x0033 }, // 0x00000664
	{ 0x0004, 0x0065, 0x0066, 0x005E, 0x8929, 0x0000, 0xD077, 0x0072 }, // 0x00000674
	{ 0x0004, 0x0065, 0x005E, 0x005D, 0x8929, 0x0000, 0xD077, 0x0072 }, // 0x00000684
	{ 0x0004, 0x0066, 0x0067, 0x005F, 0x8929, 0x0000, 0x2F89, 0x0069 }, // 0x00000694
	{ 0x0002, 0x0066, 0x005F, 0x005E, 0x8929, 0x0000, 0x2F89, 0x0069 }, // 0x000006A4
	{ 0x0004, 0x0067, 0x0068, 0x0060, 0x83D3, 0x0000, 0x1F0B, 0x0070 }, // 0x000006B4
	{ 0x0004, 0x0067, 0x0060, 0x005F, 0x83D3, 0x0000, 0x1F0B, 0x0070 }, // 0x000006C4
	{ 0x0004, 0x0068, 0x0069, 0x0061, 0x2E64, 0x0000, 0x774B, 0xFFB0 }, // 0x000006D4
	{ 0x0004, 0x0068, 0x0061, 0x0060, 0x2E64, 0x0000, 0x774B, 0xFFB0 }, // 0x000006E4
	{ 0x0004, 0x0069, 0x0062, 0x005A, 0x774B, 0x0000, 0x2E64, 0xFF70 }, // 0x000006F4
	{ 0x0004, 0x0069, 0x005A, 0x0061, 0x774B, 0x0000, 0x2E64, 0xFF70 }, // 0x00000704
	{ 0x0002, 0x006A, 0x006B, 0x006C, 0x622A, 0x0000, 0x5223, 0x0075 }, // 0x00000714
	{ 0x0002, 0x006A, 0x006C, 0x006D, 0x622A, 0x0000, 0x5223, 0x0075 }, // 0x00000724
	{ 0x0002, 0x006E, 0x006F, 0x006C, 0xAFA6, 0x0000, 0x63A2, 0xFFE3 }, // 0x00000734
	{ 0x0002, 0x006E, 0x006C, 0x006B, 0xAFA6, 0x0000, 0x63A2, 0xFFE3 }, // 0x00000744
	{ 0x0004, 0x006D, 0x0070, 0x0071, 0x505A, 0x0000, 0x9C5E, 0xFFDD }, // 0x00000754
	{ 0x0004, 0x006D, 0x0071, 0x006A, 0x505A, 0x0000, 0x9C5E, 0xFFDD }, // 0x00000764
	{ 0x0004, 0x0012, 0x0013, 0x0014, 0x75A6, 0x0000, 0xCD94, 0xFFEE }, // 0x00000774
	{ 0x0004, 0x0012, 0x0014, 0x0015, 0x75A6, 0x0000, 0xCD94, 0xFFEE }, // 0x00000784
	{ 0x0004, 0x0013, 0x0016, 0x0017, 0x326C, 0x0000, 0x8A5A, 0xFFEE }, // 0x00000794
	{ 0x0004, 0x0013, 0x0017, 0x0014, 0x326C, 0x0000, 0x8A5A, 0xFFEE }, // 0x000007A4
	{ 0x0004, 0x0016, 0x0018, 0x0019, 0xCD94, 0x0000, 0x8A5A, 0xFFEE }, // 0x000007B4
	{ 0x0004, 0x0016, 0x0019, 0x0017, 0xCD94, 0x0000, 0x8A5A, 0xFFEE }, // 0x000007C4
	{ 0x0004, 0x0018, 0x001A, 0x001B, 0x8A5A, 0x0000, 0xCD94, 0xFFEE }, // 0x000007D4
	{ 0x0004, 0x0018, 0x001B, 0x0019, 0x8A5A, 0x0000, 0xCD94, 0xFFEE }, // 0x000007E4
	{ 0x0004, 0x001A, 0x001C, 0x001D, 0x8A5A, 0x0000, 0x326C, 0xFFEE }, // 0x000007F4
	{ 0x0004, 0x001A, 0x001D, 0x001B, 0x8A5A, 0x0000, 0x326C, 0xFFEE }, // 0x00000804
	{ 0x0004, 0x001C, 0x001E, 0x001F, 0xCD94, 0x0000, 0x75A6, 0xFFEE }, // 0x00000814
	{ 0x0004, 0x001C, 0x001F, 0x001D, 0xCD94, 0x0000, 0x75A6, 0xFFEE }, // 0x00000824
	{ 0x0002, 0x001E, 0x0020, 0x0021, 0x326C, 0x0000, 0x75A6, 0xFFEE }, // 0x00000834
	{ 0x0002, 0x001E, 0x0021, 0x001F, 0x326C, 0x0000, 0x75A6, 0xFFEE }, // 0x00000844
	{ 0x0002, 0x0020, 0x0012, 0x0015, 0x75A6, 0x0000, 0x326C, 0xFFEE }, // 0x00000854
	{ 0x0002, 0x0020, 0x0015, 0x0021, 0x75A6, 0x0000, 0x326C, 0xFFEE }, // 0x00000864
	{ 0x0003, 0x002E, 0x0015, 0x0014, 0x0000, 0x7FFF, 0x0000, 0xFFEB }, // 0x00000874
	{ 0x0003, 0x002E, 0x0014, 0x0017, 0x0000, 0x7FFF, 0x0000, 0xFFEB }, // 0x00000884
	{ 0x0003, 0x002E, 0x0017, 0x0019, 0x0000, 0x7FFF, 0x0000, 0xFFEB }, // 0x00000894
	{ 0x0003, 0x002E, 0x0019, 0x001B, 0x0000, 0x7FFF, 0x0000, 0xFFEB }, // 0x000008A4
	{ 0x0003, 0x002E, 0x001B, 0x001D, 0x0000, 0x7FFF, 0x0000, 0xFFEB }, // 0x000008B4
	{ 0x0003, 0x002E, 0x001D, 0x001F, 0x0000, 0x7FFF, 0x0000, 0xFFEB }, // 0x000008C4
	{ 0x0003, 0x002E, 0x001F, 0x0021, 0x0000, 0x7FFF, 0x0000, 0xFFEB }, // 0x000008D4
	{ 0x0003, 0x002E, 0x0021, 0x0015, 0x0000, 0x7FFF, 0x0000, 0xFFEB }, // 0x000008E4
	{ 0x0003, 0x0079, 0x007A, 0x007B, 0x0000, 0x7FFF, 0x0000, 0xFF82 }, // 0x000008F4
	{ 0x0003, 0x0079, 0x007B, 0x007C, 0x0000, 0x7FFF, 0x0000, 0xFF82 }, // 0x00000904
	{ 0x0002, 0x007A, 0x0079, 0x007D, 0xF344, 0x0000, 0x7F5C, 0xFFD8 }, // 0x00000914
	{ 0x0002, 0x007A, 0x007D, 0x007E, 0xF344, 0x0000, 0x7F5C, 0xFFD8 }, // 0x00000924
	{ 0x0004, 0x007F, 0x007C, 0x007B, 0x0CFE, 0x0000, 0x80AA, 0xFFDC }, // 0x00000934
	{ 0x0004, 0x007F, 0x007B, 0x0080, 0x0CFE, 0x0000, 0x80AA, 0xFFDC }, // 0x00000944
	{ 0x0004, 0x007E, 0x0080, 0x007B, 0x7F99, 0x0000, 0x0A13, 0x005F }, // 0x00000954
	{ 0x0004, 0x007E, 0x007B, 0x007A, 0x7F99, 0x0000, 0x0A13, 0x005F }, // 0x00000964
	{ 0x0003, 0x0072, 0x0073, 0x0074, 0x0000, 0x7FFF, 0x0000, 0xFF82 }, // 0x00000974
	{ 0x0003, 0x0072, 0x0074, 0x0075, 0x0000, 0x7FFF, 0x0000, 0xFF82 }, // 0x00000984
	{ 0x0002, 0x0073, 0x0072, 0x0076, 0xD30F, 0x0000, 0x77D9, 0xFFEC }, // 0x00000994
	{ 0x0002, 0x0073, 0x0076, 0x0051, 0xD30F, 0x0000, 0x77D9, 0xFFEC }, // 0x000009A4
	{ 0x0004, 0x0077, 0x0075, 0x0074, 0x2CF1, 0x0000, 0x8827, 0xFFE9 }, // 0x000009B4
	{ 0x0004, 0x0077, 0x0074, 0x0078, 0x2CF1, 0x0000, 0x8827, 0xFFE9 }, // 0x000009C4
	{ 0x0004, 0x0075, 0x0077, 0x0076, 0x87CC, 0x0000, 0xD406, 0x005B }, // 0x000009D4
	{ 0x0004, 0x0075, 0x0076, 0x0072, 0x87CC, 0x0000, 0xD406, 0x005B }, // 0x000009E4
	{ 0x0002, 0x0081, 0x0082, 0x0083, 0x182C, 0x0000, 0x7DB1, 0x0066 }, // 0x000009F4
	{ 0x0002, 0x0081, 0x0083, 0x0084, 0x182C, 0x0000, 0x7DB1, 0x0066 }, // 0x00000A04
	{ 0x0002, 0x0082, 0x0085, 0x0086, 0x5F24, 0x0000, 0x55A0, 0x0065 }, // 0x00000A14
	{ 0x0002, 0x0082, 0x0086, 0x0083, 0x5F24, 0x0000, 0x55A0, 0x0065 }, // 0x00000A24
	{ 0x0002, 0x0085, 0x0087, 0x0088, 0x7F8E, 0x0000, 0xF55F, 0x0017 }, // 0x00000A34
	{ 0x0002, 0x0085, 0x0088, 0x0086, 0x7F8E, 0x0000, 0xF55F, 0x0017 }, // 0x00000A44
	{ 0x0000, 0x0022, 0x0023, 0x0024, 0x0000, 0x0000, 0x8001, 0x0068 }, // 0x00000A54
	{ 0x0000, 0x0022, 0x0024, 0x0025, 0x0000, 0x0000, 0x8001, 0x0068 }, // 0x00000A64
	{ 0x0000, 0x0026, 0x0027, 0x0022, 0x7FFF, 0x0000, 0x0000, 0x0020 }, // 0x00000A74
	{ 0x0000, 0x0026, 0x0022, 0x0028, 0x7FFF, 0x0000, 0x0000, 0x0020 }, // 0x00000A84
	{ 0x0000, 0x0029, 0x0025, 0x002A, 0x7FFF, 0x0000, 0x0000, 0xFFE0 }, // 0x00000A94
	{ 0x0000, 0x0029, 0x002A, 0x002B, 0x7FFF, 0x0000, 0x0000, 0xFFE0 }, // 0x00000AA4
	{ 0x0006, 0x002C, 0x002D, 0x0024, 0x0000, 0x7FFF, 0x0000, 0xFFF2 }, // 0x00000AB4
	{ 0x0006, 0x002C, 0x0024, 0x0023, 0x0000, 0x7FFF, 0x0000, 0xFFF2 }, // 0x00000AC4
	{ 0x0000, 0x002B, 0x002A, 0x0025, 0x8001, 0x0000, 0x0000, 0x0020 }, // 0x00000AD4
	{ 0x0000, 0x002B, 0x0025, 0x0029, 0x8001, 0x0000, 0x0000, 0x0020 }, // 0x00000AE4
	{ 0x0000, 0x0028, 0x0022, 0x0027, 0x8001, 0x0000, 0x0000, 0xFFE0 }, // 0x00000AF4
	{ 0x0000, 0x0028, 0x0027, 0x0026, 0x8001, 0x0000, 0x0000, 0xFFE0 }, // 0x00000B04
};

Vec3s _link_home_scene_vertices_00000B14[137] = 
{
	{ 151, 126, 0 }, // 0x00000B14
	{ 107, 126, -107 }, // 0x00000B1A
	{ 107, 0, -107 }, // 0x00000B20
	{ 151, 0, 0 }, // 0x00000B26
	{ -107, 126, -107 }, // 0x00000B2C
	{ -151, 126, 0 }, // 0x00000B32
	{ -151, 0, 0 }, // 0x00000B38
	{ -107, 0, -107 }, // 0x00000B3E
	{ -107, 126, 107 }, // 0x00000B44
	{ -107, 0, 107 }, // 0x00000B4A
	{ 0, 126, 151 }, // 0x00000B50
	{ 0, 0, 151 }, // 0x00000B56
	{ 107, 126, 107 }, // 0x00000B5C
	{ 107, 0, 107 }, // 0x00000B62
	{ -36, 120, -136 }, // 0x00000B68
	{ -36, 0, -136 }, // 0x00000B6E
	{ 36, 120, -136 }, // 0x00000B74
	{ 36, 0, -136 }, // 0x00000B7A
	{ 20, 0, 0 }, // 0x00000B80
	{ 14, 0, -14 }, // 0x00000B86
	{ 14, 21, -14 }, // 0x00000B8C
	{ 20, 21, 0 }, // 0x00000B92
	{ 0, 0, -20 }, // 0x00000B98
	{ 0, 21, -20 }, // 0x00000B9E
	{ -14, 0, -14 }, // 0x00000BA4
	{ -14, 21, -14 }, // 0x00000BAA
	{ -20, 0, 0 }, // 0x00000BB0
	{ -20, 21, 0 }, // 0x00000BB6
	{ -14, 0, 14 }, // 0x00000BBC
	{ -14, 21, 14 }, // 0x00000BC2
	{ 0, 0, 20 }, // 0x00000BC8
	{ 0, 21, 20 }, // 0x00000BCE
	{ 14, 0, 14 }, // 0x00000BD4
	{ 14, 21, 14 }, // 0x00000BDA
	{ -32, 0, 104 }, // 0x00000BE0
	{ -32, 14, 104 }, // 0x00000BE6
	{ 32, 14, 104 }, // 0x00000BEC
	{ 32, 0, 104 }, // 0x00000BF2
	{ -32, 42, 136 }, // 0x00000BF8
	{ -32, 0, 136 }, // 0x00000BFE
	{ -32, 42, 104 }, // 0x00000C04
	{ 32, 0, 136 }, // 0x00000C0A
	{ 32, 42, 104 }, // 0x00000C10
	{ 32, 42, 136 }, // 0x00000C16
	{ -32, 14, 144 }, // 0x00000C1C
	{ 32, 14, 144 }, // 0x00000C22
	{ 0, 21, 0 }, // 0x00000C28
	{ 129, 120, -83 }, // 0x00000C2E
	{ 102, 120, -53 }, // 0x00000C34
	{ 102, 0, -53 }, // 0x00000C3A
	{ 129, 0, -83 }, // 0x00000C40
	{ 72, 0, -80 }, // 0x00000C46
	{ 72, 120, -80 }, // 0x00000C4C
	{ 99, 120, -110 }, // 0x00000C52
	{ 99, 0, -110 }, // 0x00000C58
	{ 82, 120, -92 }, // 0x00000C5E
	{ 72, 120, -92 }, // 0x00000C64
	{ 72, 0, -92 }, // 0x00000C6A
	{ 82, 0, -92 }, // 0x00000C70
	{ 55, 120, -99 }, // 0x00000C76
	{ 55, 0, -99 }, // 0x00000C7C
	{ 49, 120, -102 }, // 0x00000C82
	{ 49, 0, -102 }, // 0x00000C88
	{ 42, 120, -108 }, // 0x00000C8E
	{ 42, 0, -108 }, // 0x00000C94
	{ 41, 120, -126 }, // 0x00000C9A
	{ 41, 0, -126 }, // 0x00000CA0
	{ 0, 0, -151 }, // 0x00000CA6
	{ 36, 0, -216 }, // 0x00000CAC
	{ -36, 0, -216 }, // 0x00000CB2
	{ 36, 120, -216 }, // 0x00000CB8
	{ -36, 120, -216 }, // 0x00000CBE
	{ 99, 12, 71 }, // 0x00000CC4
	{ 126, 12, 69 }, // 0x00000CCA
	{ 116, 12, 51 }, // 0x00000CD0
	{ 99, 12, 64 }, // 0x00000CD6
	{ 94, 12, 67 }, // 0x00000CDC
	{ 92, 12, 72 }, // 0x00000CE2
	{ 95, 12, 77 }, // 0x00000CE8
	{ 100, 12, 78 }, // 0x00000CEE
	{ 120, 12, 88 }, // 0x00000CF4
	{ 126, 0, 69 }, // 0x00000CFA
	{ 116, 0, 51 }, // 0x00000D00
	{ 99, 0, 64 }, // 0x00000D06
	{ 94, 0, 67 }, // 0x00000D0C
	{ 92, 0, 72 }, // 0x00000D12
	{ 95, 0, 77 }, // 0x00000D18
	{ 100, 0, 78 }, // 0x00000D1E
	{ 120, 0, 88 }, // 0x00000D24
	{ 125, 12, 12 }, // 0x00000D2A
	{ 150, 12, 12 }, // 0x00000D30
	{ 130, 12, 7 }, // 0x00000D36
	{ 125, 12, 5 }, // 0x00000D3C
	{ 120, 12, 7 }, // 0x00000D42
	{ 118, 12, 12 }, // 0x00000D48
	{ 120, 12, 17 }, // 0x00000D4E
	{ 125, 12, 37 }, // 0x00000D54
	{ 143, 12, 30 }, // 0x00000D5A
	{ 150, 0, 12 }, // 0x00000D60
	{ 130, 0, 7 }, // 0x00000D66
	{ 125, 0, 5 }, // 0x00000D6C
	{ 120, 0, 7 }, // 0x00000D72
	{ 118, 0, 12 }, // 0x00000D78
	{ 120, 0, 17 }, // 0x00000D7E
	{ 125, 0, 37 }, // 0x00000D84
	{ 143, 0, 30 }, // 0x00000D8A
	{ -69, 120, -100 }, // 0x00000D90
	{ -110, 120, -51 }, // 0x00000D96
	{ -110, 0, -51 }, // 0x00000D9C
	{ -69, 0, -100 }, // 0x00000DA2
	{ -141, 120, -76 }, // 0x00000DA8
	{ -141, 0, -76 }, // 0x00000DAE
	{ -100, 0, -125 }, // 0x00000DB4
	{ -100, 120, -125 }, // 0x00000DBA
	{ 78, 126, 51 }, // 0x00000DC0
	{ 126, 126, 69 }, // 0x00000DC6
	{ 141, 126, 28 }, // 0x00000DCC
	{ 93, 126, 10 }, // 0x00000DD2
	{ 78, 0, 51 }, // 0x00000DD8
	{ 93, 0, 10 }, // 0x00000DDE
	{ 141, 0, 28 }, // 0x00000DE4
	{ -148, 126, 25 }, // 0x00000DEA
	{ -98, 126, 30 }, // 0x00000DF0
	{ -92, 126, -46 }, // 0x00000DF6
	{ -141, 126, -51 }, // 0x00000DFC
	{ -148, 0, 25 }, // 0x00000E02
	{ -98, 0, 30 }, // 0x00000E08
	{ -141, 0, -51 }, // 0x00000E0E
	{ -92, 0, -46 }, // 0x00000E14
	{ -77, 0, -89 }, // 0x00000E1A
	{ -51, 0, -94 }, // 0x00000E20
	{ -51, 120, -94 }, // 0x00000E26
	{ -77, 120, -89 }, // 0x00000E2C
	{ -33, 0, -114 }, // 0x00000E32
	{ -33, 120, -114 }, // 0x00000E38
	{ -35, 0, -138 }, // 0x00000E3E
	{ -35, 120, -138 }, // 0x00000E44
};

CollisionHeader _link_home_scene_collisionHeader_00000E4C = { 0xFF69, 0xFFFF, 0xFF28, 0x0097, 0x007E, 0x0097, 137, _link_home_scene_vertices_00000B14, 0x009E, _link_home_scene_polygons_00000134, _link_home_scene_polygonTypes_000000FC, &_link_home_scene_camData_000000E4, 0x0000, 0 };
static u32 padE78 = 0;
static u32 padE7C = 0;

SCmdSoundSettings _link_home_scene_set0E80_cmd00 = { 0x15, 0x05, 0x00, 0x00, 0x00, 0x00, 0x13, 0x1F }; // 0x0E80
SCmdRoomList _link_home_scene_set0E80_cmd01 = { 0x04, 0x01, (u32)&_link_home_scene_roomList_00000EF0 }; // 0x0E88
SCmdMiscSettings _link_home_scene_set0E80_cmd02 = { 0x19, 0x20, 0x00000004 }; // 0x0E90
SCmdColHeader _link_home_scene_set0E80_cmd03 = { 0x03, 0x00, (u32)&_link_home_scene_collisionHeader_00000E4C}; // 0x0E98
SCmdEntranceList _link_home_scene_set0E80_cmd04 = { 0x06, 0x00, (u32)&_link_home_scene_entranceList_00000EF8 }; // 0x0EA0
SCmdSpecialFiles _link_home_scene_set0E80_cmd05 = { 0x07, 0x00, 0x0003}; // 0x0EA8
SCmdSpawnList _link_home_scene_set0E80_cmd06 = { 0x00, 0x01, (u32)&_link_home_scene_startPositionList_00000EE0}; // 0x0EB0
SCmdSkyboxSettings _link_home_scene_set0E80_cmd07 = { 0x11, 0x00, 0x00, 0x00, 0x07, 0x00, 0x01}; // 0x0EB8
SCmdExitList _link_home_scene_set0E80_cmd08 = { 0x13, 0x00, (u32)&_link_home_scene_exitList_00000EFC }; // 0x0EC0
SCmdLightSettingList _link_home_scene_set0E80_cmd09 = { 0x0F, 4, (u32)&_link_home_scene_lightSettings_00000F00}; // 0x0EC8
SCmdCutsceneData _link_home_scene_set0E80_cmd0A = { 0x17, 0, (u32)&_link_home_scene_cutsceneData_00001040 }; // 0x0ED0
SCmdEndMarker _link_home_scene_set0E80_cmd0B = { 0x14, 0x00, 0x00 }; // 0x0ED8
ActorEntry _link_home_scene_startPositionList_00000EE0[] = 
{
	{ ACTOR_PLAYER, -112, 22, -4, 0, 16384, 0, 0x0F00 },
};

RomFile _link_home_scene_roomList_00000EF0[] = 
{
	{ (u32)_link_home_room_0SegmentRomStart, (u32)_link_home_room_0SegmentRomEnd },
};

EntranceEntry _link_home_scene_entranceList_00000EF8[] = 
{
	{ 0x00, 0x00 }, //0x00000EF8 
	{ 0x00, 0x00 }, //0x00000EFA 
};

u16 _link_home_scene_exitList_00000EFC[] = 
{
	0x0211,
	0x0211,
};

LightSettings _link_home_scene_lightSettings_00000F00[] = 
{
	{ 0x32, 0x32, 0x32, 0x2A, 0x3C, 0x67, 0x96, 0x82, 0x82, 0x02, 0xFA, 0x82, 0x50, 0x50, 0x64, 0x1E, 0x0A, 0x0A, 0x07E0, 0x3200 }, // 0x00000F00 
	{ 0x69, 0x5A, 0x5A, 0x49, 0x49, 0x49, 0xFF, 0xFF, 0xF0, 0xB7, 0xB7, 0xB7, 0x32, 0x32, 0x5A, 0x64, 0x64, 0x78, 0x07E4, 0x3200 }, // 0x00000F16 
	{ 0x78, 0x5A, 0x00, 0x49, 0x49, 0x49, 0xFA, 0x87, 0x32, 0xB7, 0xB7, 0xB7, 0x1E, 0x1E, 0x3C, 0x1C, 0x14, 0x00, 0x07E1, 0x3200 }, // 0x00000F2C 
	{ 0x28, 0x28, 0x46, 0x49, 0x49, 0x49, 0x14, 0x14, 0x23, 0xB7, 0xB7, 0xB7, 0x32, 0x32, 0x64, 0x00, 0x00, 0x1E, 0x07E0, 0x3200 }, // 0x00000F42 
};

static u8 unaccounted0F58[] = 
{
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

SCmdSoundSettings _link_home_scene_set0F60_cmd00 = { 0x15, 0x05, 0x00, 0x00, 0x00, 0x00, 0x13, 0x00 }; // 0x0F60
SCmdRoomList _link_home_scene_set0F60_cmd01 = { 0x04, 0x01, (u32)&_link_home_scene_roomList_00000FD0 }; // 0x0F68
SCmdMiscSettings _link_home_scene_set0F60_cmd02 = { 0x19, 0x20, 0x00000004 }; // 0x0F70
SCmdColHeader _link_home_scene_set0F60_cmd03 = { 0x03, 0x00, (u32)&_link_home_scene_collisionHeader_00000E4C}; // 0x0F78
SCmdEntranceList _link_home_scene_set0F60_cmd04 = { 0x06, 0x00, (u32)&_link_home_scene_entranceList_00000FD8 }; // 0x0F80
SCmdSpecialFiles _link_home_scene_set0F60_cmd05 = { 0x07, 0x00, 0x0003}; // 0x0F88
SCmdSpawnList _link_home_scene_set0F60_cmd06 = { 0x00, 0x01, (u32)&_link_home_scene_startPositionList_00000FC0}; // 0x0F90
SCmdSkyboxSettings _link_home_scene_set0F60_cmd07 = { 0x11, 0x00, 0x00, 0x00, 0x07, 0x00, 0x01}; // 0x0F98
SCmdExitList _link_home_scene_set0F60_cmd08 = { 0x13, 0x00, (u32)&_link_home_scene_exitList_00000FDC }; // 0x0FA0
SCmdLightSettingList _link_home_scene_set0F60_cmd09 = { 0x0F, 4, (u32)&_link_home_scene_lightSettings_00000FE0}; // 0x0FA8
SCmdCutsceneData _link_home_scene_set0F60_cmd0A = { 0x17, 0, (u32)&_link_home_scene_cutsceneData_000015D0 }; // 0x0FB0
SCmdEndMarker _link_home_scene_set0F60_cmd0B = { 0x14, 0x00, 0x00 }; // 0x0FB8
ActorEntry _link_home_scene_startPositionList_00000FC0[] = 
{
	{ ACTOR_PLAYER, -112, 22, -4, 0, 16384, 0, 0x0F00 },
};

RomFile _link_home_scene_roomList_00000FD0[] = 
{
	{ (u32)_link_home_room_0SegmentRomStart, (u32)_link_home_room_0SegmentRomEnd },
};

EntranceEntry _link_home_scene_entranceList_00000FD8[] = 
{
	{ 0x00, 0x00 }, //0x00000FD8 
	{ 0x00, 0x00 }, //0x00000FDA 
};

u16 _link_home_scene_exitList_00000FDC[] = 
{
	0x0211,
	0x0211,
};

LightSettings _link_home_scene_lightSettings_00000FE0[] = 
{
	{ 0x32, 0x32, 0x32, 0x2A, 0x3C, 0x67, 0x96, 0x82, 0x82, 0x02, 0xFA, 0x82, 0x50, 0x50, 0x64, 0x1E, 0x0A, 0x0A, 0x07E0, 0x3200 }, // 0x00000FE0 
	{ 0x69, 0x5A, 0x5A, 0x49, 0x49, 0x49, 0xFF, 0xFF, 0xF0, 0xB7, 0xB7, 0xB7, 0x32, 0x32, 0x5A, 0x64, 0x64, 0x78, 0x07E4, 0x3200 }, // 0x00000FF6 
	{ 0x78, 0x5A, 0x00, 0x49, 0x49, 0x49, 0xFA, 0x87, 0x32, 0xB7, 0xB7, 0xB7, 0x1E, 0x1E, 0x3C, 0x1C, 0x14, 0x00, 0x07E1, 0x3200 }, // 0x0000100C 
	{ 0x28, 0x28, 0x46, 0x49, 0x49, 0x49, 0x14, 0x14, 0x23, 0xB7, 0xB7, 0xB7, 0x32, 0x32, 0x64, 0x00, 0x00, 0x1E, 0x07E0, 0x3200 }, // 0x00001022 
};

static u8 unaccounted1038[] = 
{
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

// SIZE = 0x0588
s32 _link_home_scene_cutsceneData_00001040[] = 
{
	CS_BEGIN_CUTSCENE(11, 3000),
	CS_UNK_DATA_LIST(0x3D, 1),
	CS_UNK_DATA(65536, 196608000, 0, 0, -42, -100, 0, -42, -100, 0, 0, 0),
	CS_NPC_ACTION_LIST(62, 8),
	CS_NPC_ACTION(0x0001, 0, 1, 0x0000, 0x0000, 0x0000, -2, 40, -183, -2, 40, -183, 0, 0, 0),
	CS_NPC_ACTION(0x0002, 1, 61, 0x0071, 0x0000, 0x0000, -2, 40, -183, 0, 30, 0, 1023969417, -1104500053, -1123514231),
	CS_NPC_ACTION(0x0004, 61, 100, 0x0000, 0x0000, 0x0000, 0, 30, 0, 0, 50, 110, 0, 1057179701, 0),
	CS_NPC_ACTION(0x0004, 100, 250, 0x0000, 0x0000, 0x0000, 0, 50, 110, 0, 50, 110, 0, 0, 0),
	CS_NPC_ACTION(0x0003, 250, 350, 0x0000, 0x0000, 0x0000, 0, 50, 110, 0, 50, 110, 0, 0, 0),
	CS_NPC_ACTION(0x0004, 350, 390, 0x0000, 0x0000, 0x0000, 0, 50, 110, 0, 50, 110, 0, 0, 0),
	CS_NPC_ACTION(0x0002, 390, 480, 0x5526, 0x0000, 0x0000, 0, 50, 110, 35, 30, 90, 1053236338, -1100771783, -1094247310),
	CS_NPC_ACTION(0x0004, 480, 859, 0x0000, 0xFFFF8000, 0x0000, 35, 30, 90, 35, 30, 90, 1053236338, -1100771783, -1094247310),
	CS_NPC_ACTION_LIST(10, 5),
	CS_NPC_ACTION(0x001C, 0, 80, 0x0000, 0xFFFF8000, 0xFFFFFC72, 0, 2, 116, 0, 2, 116, 1053236338, 0, 1),
	CS_NPC_ACTION(0x001C, 80, 200, 0x0000, 0xFFFF8000, 0x0000, 0, 2, 116, 0, 2, 116, 1053236338, 0, 1),
	CS_NPC_ACTION(0x001D, 200, 320, 0x0000, 0xFFFF8000, 0x0000, 0, 2, 116, 0, 2, 116, 1053236338, 0, 1),
	CS_NPC_ACTION(0x001E, 320, 580, 0x0000, 0xFFFF8000, 0x0000, 0, 2, 116, 0, 2, 116, 1053236338, 0, 1),
	CS_NPC_ACTION(0x001F, 580, 645, 0x0000, 0xFFFF8000, 0x0000, 0, 2, 116, 0, 2, 116, 1053236338, 0, 1),
	CS_MISC_LIST(1),
		CS_MISC(0x000E, 645, 646, 0x0000, 0x0000, 0x0000, 0, 1, 0, 0, 1, 0, 0, 0, 538572464),
	CS_MISC_LIST(1),
		CS_MISC(0x000C, 647, 648, 0x0000, 0x0000, 0x0001, 0, 2, 1, 0, 2, 0, 0, 0, 538572464),
	CS_NPC_ACTION_LIST(10, 1),
	CS_NPC_ACTION(0x0005, 645, 786, 0x0000, 0xFFFF8000, 0x0000, 0, 0, 60, 0, 0, 60, 0, 0, 1),
	CS_CAM_POS_LIST(0, 1121),
		CS_CAM_POS(0, 0, 0, 0x42700000, 0, 34, 0, -44),
		CS_CAM_POS(0, 0, 0, 0x42700000, 0, 34, 0, 68),
		CS_CAM_POS(0, 0, 0, 0x42700000, 0, 34, 0, 180),
		CS_CAM_POS(0, 0, 0, 0x42700000, 0, 34, 0, 292),
		CS_CAM_POS(0, 0, 0, 0x42700000, 0, 34, 0, 404),
		CS_CAM_POS(-1, 0, 0, 0x42700000, 0, 34, 0, -5448),
	CS_CAM_POS_LIST(70, 221),
		CS_CAM_POS(0, 0, 0, 0x42700000, 0, 34, 0, -44),
		CS_CAM_POS(0, 0, 0, 0x42700000, 0, 34, 0, 68),
		CS_CAM_POS(0, 0, 0, 0x42700000, 0, 34, 0, 180),
		CS_CAM_POS(0, 0, 0, 0x42700000, 0, 34, 0, 292),
		CS_CAM_POS(0, 0, 0, 0x42700000, 0, 34, 0, 404),
		CS_CAM_POS(-1, 0, 0, 0x42700000, 0, 34, 0, -5448),
	CS_CAM_FOCUS_POINT_LIST(0, 1150),
		CS_CAM_FOCUS_POINT(0, 0, 30, 0x42700000, 0, 34, -118, -44),
		CS_CAM_FOCUS_POINT(0, 0, 30, 0x42700000, 0, 34, -118, 68),
		CS_CAM_FOCUS_POINT(0, 0, 30, 0x42700000, 0, 34, -118, 180),
		CS_CAM_FOCUS_POINT(0, 0, 1000, 0x42700000, 0, 34, -118, 292),
		CS_CAM_FOCUS_POINT(0, 0, 30, 0x42700000, 0, 34, -118, 404),
		CS_CAM_FOCUS_POINT(-1, 0, 30, 0x42700000, 0, 34, -118, -5448),
	CS_CAM_FOCUS_POINT_LIST(70, 250),
		CS_CAM_FOCUS_POINT(0, 0, 30, 0x42700000, 0, 34, 118, -44),
		CS_CAM_FOCUS_POINT(0, 0, 30, 0x42700000, 0, 34, 118, 68),
		CS_CAM_FOCUS_POINT(0, 0, 30, 0x42700000, 0, 34, 118, 180),
		CS_CAM_FOCUS_POINT(0, 0, 30, 0x42700000, 0, 34, 118, 292),
		CS_CAM_FOCUS_POINT(0, 0, 30, 0x42700000, 0, 34, 118, 404),
		CS_CAM_FOCUS_POINT(-1, 0, 30, 0x42700000, 0, 34, 118, -5448),
	CS_TEXT_LIST(8),
		CS_TEXT_NONE(0, 160),
		CS_TEXT_DISPLAY_TEXTBOX(4245, 160, 200, 0, 0, 0), // [sound 6844]Hello, [Link]! Wake up!  The Great Deku Tree wants to talk to you! [Link], get up!
		CS_TEXT_NONE(200, 250),
		CS_TEXT_DISPLAY_TEXTBOX(4246, 250, 300, 0, 0, 0), // [sound 685F]Hey! C'mon!  Can Hyrule's destiny really depend on such a lazy boy?
		CS_TEXT_NONE(300, 550),
		CS_TEXT_DISPLAY_TEXTBOX(4096, 550, 560, 0, 0, 0), // You finally woke up! I'm Navi the fairy!  The Great Deku Tree asked me to be your partner from now on! Nice to meet you!
		CS_TEXT_NONE(560, 570),
		CS_TEXT_DISPLAY_TEXTBOX(4248, 570, 580, 0, 0, 0), // The Great Deku Tree  has summoned you! So let's get going, right now!
	CS_END(),
};
static u32 pad15C8 = 0;
static u32 pad15CC = 0;

// SIZE = 0x0590
s32 _link_home_scene_cutsceneData_000015D0[] = 
{
	CS_BEGIN_CUTSCENE(15, 3000),
	CS_UNK_DATA_LIST(0x3D, 1),
	CS_UNK_DATA(65536, 196608000, 0, 0, -42, -100, 0, -42, -100, 0, 0, 0),
	CS_NPC_ACTION_LIST(10, 3),
	CS_NPC_ACTION(0x001C, 0, 80, 0x0000, 0xFFFF8000, 0xFFFFFC72, 0, 2, 116, 0, 2, 116, 0, 0, 1),
	CS_NPC_ACTION(0x001C, 80, 200, 0x0000, 0xFFFF8000, 0x0000, 0, 2, 116, 0, 2, 116, 0, 0, 1),
	CS_NPC_ACTION(0x001D, 200, 320, 0x0000, 0xFFFF8000, 0x0000, 0, 2, 116, 0, 2, 116, 0, 0, 1),
	CS_SCENE_TRANS_FX(12, 55, 81, 537846144),
	CS_SCENE_TRANS_FX(13, 230, 301, 537880320),
	CS_MISC_LIST(1),
		CS_MISC(0x000E, 40, 41, 0x0000, 0x0000, 0xFFFFFFFE, 0, -6, -2, 0, -6, 0, 0, 0, 1545639184),
	CS_MISC_LIST(1),
		CS_MISC(0x000E, 130, 131, 0x0000, 0x0000, 0xFFFFFFFE, 0, 4, -2, 0, 4, 0, 0, 0, 1545639184),
	CS_TEXT_LIST(6),
		CS_TEXT_NONE(0, 40),
		CS_TEXT_DISPLAY_TEXTBOX(4253, 40, 50, 0, 0, 0), // In the vast, deep forest of Hyrule...Long have I served as the guardian spirit... I am known as the Deku Tree...
		CS_TEXT_NONE(50, 100),
		CS_TEXT_DISPLAY_TEXTBOX(4254, 100, 120, 0, 0, 0), // The children of the forest, the Kokiri, live here with me.Each Kokiri has his or her own guardian fairy.
		CS_TEXT_NONE(120, 160),
		CS_TEXT_DISPLAY_TEXTBOX(4255, 160, 165, 0, 0, 0), // However, there is one boy who does not have a fairy...
	CS_CAM_POS_LIST(0, 1211),
		CS_CAM_POS(0, 0, 0, 0x42700000, 0, 34, 0, 0),
		CS_CAM_POS(0, 0, 0, 0x42700000, 0, 34, 0, 8924),
		CS_CAM_POS(0, 0, 0, 0x42700000, 0, 34, 0, 16648),
		CS_CAM_POS(0, 0, 0, 0x42700000, 0, 34, 0, 0),
		CS_CAM_POS(0, 0, 0, 0x42700000, 0, 34, 0, 8888),
		CS_CAM_POS(0, 0, 0, 0x42700000, 0, 34, 0, 0),
		CS_CAM_POS(0, 0, 0, 0x42700000, 0, 34, 0, 26735),
		CS_CAM_POS(0, 0, 0, 0x42700000, 0, 34, 0, 356),
		CS_CAM_POS(-1, 0, 0, 0x42700000, 0, 34, 0, 9248),
	CS_CAM_POS_LIST(130, 1311),
		CS_CAM_POS(0, 0, 0, 0x42700000, 0, 34, 0, 0),
		CS_CAM_POS(0, 0, 0, 0x42700000, 0, 34, 0, 8924),
		CS_CAM_POS(0, 0, 0, 0x42700000, 0, 34, 0, 16648),
		CS_CAM_POS(0, 0, 0, 0x42700000, 0, 34, 0, 0),
		CS_CAM_POS(0, 0, 0, 0x42700000, 0, 34, 0, 8888),
		CS_CAM_POS(0, 0, 0, 0x42700000, 0, 34, 0, 0),
		CS_CAM_POS(0, 0, 0, 0x42700000, 0, 34, 0, 26735),
		CS_CAM_POS(-1, 0, 0, 0x42700000, 0, 34, 0, 356),
	CS_CAM_POS_LIST(180, 511),
		CS_CAM_POS(0, 0, 0, 0x42700000, 0, 34, 0, 0),
		CS_CAM_POS(0, 0, 0, 0x42700000, 0, 34, 0, 8924),
		CS_CAM_POS(0, 0, 0, 0x42700000, 0, 34, 0, 16648),
		CS_CAM_POS(0, 0, 0, 0x42700000, 0, 34, 0, 0),
		CS_CAM_POS(0, 0, 0, 0x42700000, 0, 34, 0, 8888),
		CS_CAM_POS(0, 0, 0, 0x42700000, 0, 34, 0, 0),
		CS_CAM_POS(0, 0, 0, 0x42700000, 0, 34, 0, 26735),
		CS_CAM_POS(0, 0, 0, 0x42700000, 0, 34, 0, 356),
		CS_CAM_POS(-1, 0, 0, 0x42700000, 0, 34, 0, 9248),
	CS_CAM_FOCUS_POINT_LIST(0, 1240),
		CS_CAM_FOCUS_POINT(0, 0, 30, 0x42700000, 0, 31, 118, 0),
		CS_CAM_FOCUS_POINT(0, 0, 30, 0x42700000, 0, 31, 118, 8924),
		CS_CAM_FOCUS_POINT(0, 0, 30, 0x42700000, 0, 31, 118, 16648),
		CS_CAM_FOCUS_POINT(0, 0, 30, 0x42700000, 0, 31, 118, 0),
		CS_CAM_FOCUS_POINT(0, 0, 30, 0x42700000, 0, 31, 118, 8888),
		CS_CAM_FOCUS_POINT(0, 0, 1000, 0x42700000, 0, 31, 118, 0),
		CS_CAM_FOCUS_POINT(0, 0, 30, 0x42700000, 0, 31, 118, 26735),
		CS_CAM_FOCUS_POINT(0, 0, 30, 0x42700000, 0, 31, 117, 356),
		CS_CAM_FOCUS_POINT(-1, 0, 30, 0x42700000, 0, 31, 117, 9248),
	CS_CAM_FOCUS_POINT_LIST(130, 1340),
		CS_CAM_FOCUS_POINT(0, 0, 30, 0x42700000, 0, 31, 118, 0),
		CS_CAM_FOCUS_POINT(0, 0, 30, 0x42700000, 0, 31, 118, 8924),
		CS_CAM_FOCUS_POINT(0, 0, 30, 0x42700000, 0, 31, 118, 16648),
		CS_CAM_FOCUS_POINT(0, 0, 30, 0x42700000, 0, 31, 118, 0),
		CS_CAM_FOCUS_POINT(0, 0, 30, 0x42700000, 0, 31, 118, 8888),
		CS_CAM_FOCUS_POINT(0, 0, 1000, 0x42700000, 0, 31, 118, 0),
		CS_CAM_FOCUS_POINT(0, 0, 30, 0x42700000, 0, 31, 118, 26735),
		CS_CAM_FOCUS_POINT(-1, 0, 30, 0x42700000, 0, 31, 117, 356),
	CS_CAM_FOCUS_POINT_LIST(180, 540),
		CS_CAM_FOCUS_POINT(0, 0, 30, 0x42700000, 0, 31, 117, 0),
		CS_CAM_FOCUS_POINT(0, 0, 30, 0x42700000, 0, 31, 117, 8924),
		CS_CAM_FOCUS_POINT(0, 0, 60, 0x42700000, 0, 31, 117, 16648),
		CS_CAM_FOCUS_POINT(0, 0, 60, 0x42700000, 0, 64, 113, 0),
		CS_CAM_FOCUS_POINT(0, 0, 60, 0x42700000, 0, 64, 113, 8888),
		CS_CAM_FOCUS_POINT(0, 0, 30, 0x42700000, 0, 64, 113, 0),
		CS_CAM_FOCUS_POINT(0, 0, 30, 0x42700000, 0, 64, 113, 26735),
		CS_CAM_FOCUS_POINT(0, 0, 30, 0x42700000, 0, 64, 113, 356),
		CS_CAM_FOCUS_POINT(-1, 0, 30, 0x42700000, 0, 64, 113, 9248),
	CS_NPC_ACTION_LIST(62, 1),
	CS_NPC_ACTION(0x0001, 0, 272, 0x0000, 0x0000, 0x0000, -201, -25, 78, -201, -25, 78, 0, 0, 0),
	CS_TERMINATOR(0x0023, 280, 281, 0x0119),
	CS_END(),
};


