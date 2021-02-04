#include <ultra64.h>
#include <z64.h>
#include "face_shop_scene.h"
#include <z64.h>
#include <segment_symbols.h>
#include <command_macros_base.h>
#include <z64cutscene_commands.h>
#include <variables.h>



SCmdSoundSettings _face_shop_scene_set0000_cmd00 = { 0x15, 0x05, 0x00, 0x00, 0x00, 0x00, 0x13, 0x55 }; // 0x0000
SCmdRoomList _face_shop_scene_set0000_cmd01 = { 0x04, 0x01, (u32)&_face_shop_scene_roomList_00000060 }; // 0x0008
SCmdMiscSettings _face_shop_scene_set0000_cmd02 = { 0x19, 0x10, 0x0000000E }; // 0x0010
SCmdColHeader _face_shop_scene_set0000_cmd03 = { 0x03, 0x00, (u32)&_face_shop_scene_collisionHeader_00000338}; // 0x0018
SCmdEntranceList _face_shop_scene_set0000_cmd04 = { 0x06, 0x00, (u32)&_face_shop_scene_entranceList_00000068 }; // 0x0020
SCmdSpawnList _face_shop_scene_set0000_cmd05 = { 0x00, 0x01, (u32)&_face_shop_scene_startPositionList_00000050}; // 0x0028
SCmdSkyboxSettings _face_shop_scene_set0000_cmd06 = { 0x11, 0x00, 0x00, 0x00, 0x0B, 0x00, 0x01}; // 0x0030
SCmdExitList _face_shop_scene_set0000_cmd07 = { 0x13, 0x00, (u32)&_face_shop_scene_exitList_0000006C }; // 0x0038
SCmdLightSettingList _face_shop_scene_set0000_cmd08 = { 0x0F, 1, (u32)&_face_shop_scene_lightSettings_00000070}; // 0x0040
SCmdEndMarker _face_shop_scene_set0000_cmd09 = { 0x14, 0x00, 0x00 }; // 0x0048
ActorEntry _face_shop_scene_startPositionList_00000050[] = 
{
	{ ACTOR_PLAYER, 0, 1, 108, 0, -32768, 0, 0x0EFF },
};

RomFile _face_shop_scene_roomList_00000060[] = 
{
	{ (u32)_face_shop_room_0SegmentRomStart, (u32)_face_shop_room_0SegmentRomEnd },
};

EntranceEntry _face_shop_scene_entranceList_00000068[] = 
{
	{ 0x00, 0x00 }, //0x00000068 
	{ 0x00, 0x00 }, //0x0000006A 
};

u16 _face_shop_scene_exitList_0000006C[] = 
{
	0x01D1,
	0x0000,
};

LightSettings _face_shop_scene_lightSettings_00000070[] = 
{
	{ 0x46, 0x28, 0x28, 0x3D, 0x39, 0x5E, 0xE6, 0xD2, 0xC8, 0xF4, 0x25, 0x78, 0x64, 0x5A, 0x3C, 0x0A, 0x0A, 0x0A, 0x07E0, 0x07D0 }, // 0x00000070 
};

static u8 unaccounted0088[] = 
{
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

CamPosData _face_shop_scene_camPosData_00000090[] = 
{
	{ 60, 52, 300, -546, -30948, 0, 5000, -1, 0xFFFF }, // 0x02000090
	{ 0, 60, 20, 0, -32768, 0, -1, -1, 0xFFFF }, // 0x020000A2
};

CamData _face_shop_scene_camData_000000B4 = { 0x0019, 0x0003, (u32)_face_shop_scene_camPosData_00000090 };

CamPosDataEntry _face_shop_scene_camPosDataEntries_000000BC[] = 
{
	{ 0x00170003, (u32)&_face_shop_scene_camPosData_00000090[1] }, // 0x000000BC
	{ 0x00000000, 0x00000000 }, // 0x000000C4
};

u32 _face_shop_scene_polygonTypes_000000CC[] = 
{
	 0x00000102, 0x000C3FC2, 
	 0x00000102, 0x00003FC2, 
	 0x00000002, 0x00003FC2, 
	 0x00000002, 0x00003802, 
};

RoomPoly _face_shop_scene_polygons_000000EC[] = 
{
	{ 0x0000, 0x0000, 0x2001, 0x0002, 0x0000, 0x7FFF, 0x0000, 0xFFFF }, // 0x000000EC
	{ 0x0000, 0x0001, 0x2003, 0x0002, 0x0000, 0x7FFF, 0x0000, 0xFFFF }, // 0x000000FC
	{ 0x0001, 0x0003, 0x0004, 0x0002, 0x0000, 0x7FFF, 0x0000, 0xFFFF }, // 0x0000010C
	{ 0x0000, 0x0003, 0x2005, 0x0004, 0x0000, 0x7FFF, 0x0000, 0xFFFF }, // 0x0000011C
	{ 0x0000, 0x0005, 0x2006, 0x0004, 0x0000, 0x7FFF, 0x0000, 0xFFFF }, // 0x0000012C
	{ 0x0001, 0x0005, 0x0007, 0x0006, 0x0000, 0x7FFF, 0x0000, 0xFFFF }, // 0x0000013C
	{ 0x0000, 0x0007, 0x2008, 0x0006, 0x0000, 0x7FFF, 0x0000, 0xFFFF }, // 0x0000014C
	{ 0x0002, 0x0009, 0x000A, 0x000B, 0x7FFF, 0x0000, 0x0000, 0x00A0 }, // 0x0000015C
	{ 0x0002, 0x0009, 0x000B, 0x000C, 0x7FFF, 0x0000, 0x0000, 0x00A0 }, // 0x0000016C
	{ 0x0002, 0x000C, 0x000D, 0x000E, 0x0000, 0x7FFF, 0x0000, 0x0000 }, // 0x0000017C
	{ 0x0002, 0x000C, 0x000E, 0x0009, 0x0000, 0x7FFF, 0x0000, 0x0000 }, // 0x0000018C
	{ 0x0002, 0x000F, 0x0010, 0x0011, 0x0000, 0x0000, 0x7FFF, 0x0028 }, // 0x0000019C
	{ 0x0002, 0x000F, 0x0011, 0x0012, 0x0000, 0x0000, 0x7FFF, 0x0028 }, // 0x000001AC
	{ 0x0002, 0x000A, 0x0009, 0x000E, 0x0000, 0x0000, 0x7FFF, 0x00C8 }, // 0x000001BC
	{ 0x0002, 0x000A, 0x000E, 0x0013, 0x0000, 0x0000, 0x7FFF, 0x00C8 }, // 0x000001CC
	{ 0x0002, 0x000D, 0x0014, 0x0013, 0x8001, 0x0000, 0x0000, 0x00A0 }, // 0x000001DC
	{ 0x0002, 0x000D, 0x0013, 0x000E, 0x8001, 0x0000, 0x0000, 0x00A0 }, // 0x000001EC
	{ 0x0003, 0x0015, 0x0016, 0x0017, 0x8001, 0x0000, 0x0000, 0xFF94 }, // 0x000001FC
	{ 0x0003, 0x0015, 0x0017, 0x0018, 0x8001, 0x0000, 0x0000, 0xFF94 }, // 0x0000020C
	{ 0x0003, 0x000F, 0x0012, 0x0019, 0x7FFF, 0x0000, 0x0000, 0xFF94 }, // 0x0000021C
	{ 0x0003, 0x000F, 0x0019, 0x001A, 0x7FFF, 0x0000, 0x0000, 0xFF94 }, // 0x0000022C
	{ 0x0003, 0x001A, 0x0019, 0x0016, 0x0000, 0x0000, 0x7FFF, 0xFFF4 }, // 0x0000023C
	{ 0x0003, 0x001A, 0x0016, 0x0015, 0x0000, 0x0000, 0x7FFF, 0xFFF4 }, // 0x0000024C
	{ 0x0003, 0x001B, 0x001C, 0x001D, 0x2AE1, 0x0000, 0x789A, 0x0012 }, // 0x0000025C
	{ 0x0003, 0x001B, 0x001D, 0x001E, 0x2AE1, 0x0000, 0x789A, 0x0012 }, // 0x0000026C
};

Vec3s _face_shop_scene_vertices_0000027C[31] = 
{
	{ 160, 1, 80 }, // 0x0000027C
	{ 140, 1, 80 }, // 0x00000282
	{ 160, 1, 320 }, // 0x00000288
	{ 100, 1, 140 }, // 0x0000028E
	{ 0, 1, 320 }, // 0x00000294
	{ -80, 1, 140 }, // 0x0000029A
	{ -160, 1, 320 }, // 0x000002A0
	{ -140, 1, 80 }, // 0x000002A6
	{ -160, 1, 80 }, // 0x000002AC
	{ -160, 0, -200 }, // 0x000002B2
	{ -160, 320, -200 }, // 0x000002B8
	{ -160, 320, 320 }, // 0x000002BE
	{ -160, 0, 320 }, // 0x000002C4
	{ 160, 0, 320 }, // 0x000002CA
	{ 160, 0, -200 }, // 0x000002D0
	{ 108, 0, -40 }, // 0x000002D6
	{ 160, 0, -40 }, // 0x000002DC
	{ 160, 160, -40 }, // 0x000002E2
	{ 108, 160, -40 }, // 0x000002E8
	{ 160, 320, -200 }, // 0x000002EE
	{ 160, 320, 320 }, // 0x000002F4
	{ -108, 0, 12 }, // 0x000002FA
	{ -108, 160, 12 }, // 0x00000300
	{ -108, 160, -36 }, // 0x00000306
	{ -108, 0, -36 }, // 0x0000030C
	{ 108, 160, 12 }, // 0x00000312
	{ 108, 0, 12 }, // 0x00000318
	{ -160, 160, 38 }, // 0x0000031E
	{ -160, 0, 38 }, // 0x00000324
	{ -70, 0, 6 }, // 0x0000032A
	{ -70, 160, 6 }, // 0x00000330
};

CollisionHeader _face_shop_scene_collisionHeader_00000338 = { 0xFF54, 0xFFF5, 0xFF38, 0x00AC, 0x0140, 0x0140, 31, _face_shop_scene_vertices_0000027C, 0x0019, _face_shop_scene_polygons_000000EC, _face_shop_scene_polygonTypes_000000CC, &_face_shop_scene_camData_000000B4, 0x0000, 0 };
static u32 pad364 = 0;
static u32 pad368 = 0;
static u32 pad36C = 0;

