//FOI ATUALIZADO PARA 1.27/1.28
//testt
#include <cellstatus.h>
#include <sys/prx.h>
#include <sys/ppu_thread.h>
#include <string.h>
#include <sys/memory.h>
#include <sys/timer.h>
#include <sys/process.h>
#include <ppu_intrinsics.h>
#include <stdarg.h>
#include <stdio.h>
#include <cstdlib>
#include "Enums.h"
#include "Natives.h"
#include "math.h"
//
SYS_MODULE_INFO("GTAV_Native_Invoker", 0, 1, 1);
SYS_MODULE_START(PRX_ENTRY);

Vector3 get_coords_from_cam(float distance)
{
	Vector3 Rot = CAM::GET_GAMEPLAY_CAM_ROT(2);
	Vector3 Coord = CAM::GET_GAMEPLAY_CAM_COORD();

	Rot.y = distance * SYSTEM::COS(Rot.x);
	Coord.x = Coord.x + Rot.y * SYSTEM::SIN(Rot.z * -1.0f);
	Coord.y = Coord.y + Rot.y * SYSTEM::COS(Rot.z * -1.0f);
	Coord.z = Coord.z + distance * SYSTEM::SIN(Rot.x);

	return Coord;
}
//THE UMBRELLA VERSION DEX
/*

*/
#pragma region Variables
Native_s** g_Natives;
Hash WepArray[59] = { 0x42BF8A85, 0x99B507EA, 0x678B81B1, 0x4E875F73, 0x958A4A8F, 0x440E4788, 0x84BD7BFD, 0x1B06D571, 0x5EF9FEC4, 0x22D8FE39, 0x99AEEB3B, 0x13532244, 0x2BE6766B, 0xEFE7E2DF, 0xBFEFFF6D, 0x83BF0278, 0xAF113F99, 0x9D07F764, 0x7FD62962, 0x1D073A89, 0x7846A318, 0xE284C527, 0x9D61E50F, 0x3656C8C1, 0x5FC3C11, 0xC472FE2, 0xA284510B, 0x4DD2DC56, 0xB1CA77B1, 0x687652CE, 0x42BF8A85, 0x93E220BD, 0x2C3731D9, 0xFDBC8A50, 0xA0973D5E, 0x24B17070, 0x60EC506, 0x34A67B97, 0x23C9F95C, 0x497FACC3, 0xF9E6AA4B, 0x61012683, 0xD205520E, 0xBFD21232, 0x92A27487, 0x83839C4, 0xA89CB99E, 0xC0A3098D, 0x7F229F94, 0x7F7497E5, 0x787F0BB, 0xAB564B93, 0x63AB0442, 0x47757124, 0xA3D4D34, 0x3AABBBAA, 0xC734385A, 0xA3D4D34, 0xDC4DB296 };
uint32_t hash_veh;

bool givew = true;
int PickWeaps[] = { -105925489, -1989692173, 996550793, 496339155, 978070226, -214137936, -546236071, -1296747938, -1766583645, -1456120371, -1835415205, -30788308, 1765114797, -2050315855, -1298986476, 779501861, 1295434569, 792114228, 1577485217, 2081529176, 768803961, -962731009, 483787975, 663586612, -2115084258, 693539241, -2027042680, -1997886297, 1587637620, -887893374, 1724937680, 2017151059, 1735599485, 1274757841, -1888453608, -1521817673, -794112265, -863291131, -1200951717, -864236261, 772217690, -1491601256, -2066319660, 1705498857, 746606563, 160266735, 1125567497, -831529621, 545862290, 341217064, 1897726628, 1852930709, -2136239332, -831529621, 1426343849, -107080240, -482507216, 738282662, 155886031, 483577702, 513448440, -562499202, -31919185, 1575005502, -405862452, -723152950, 1575005502, -1514616151 };
char *Pickwaf[] = { "w_ex_molotov", "w_ex_molotov_hi", "w_ex_pe", "w_ex_pe_hi", "w_lr_40mm", "w_lr_40mm_pu", "w_lr_grenadelauncher", "w_lr_grenadelauncher_hi", "w_lr_rpg", "w_lr_rpg_hi", "w_lr_rpg_rocket", "w_lr_rpg_rocket_pu", "w_me_bat", "w_mg_minigun_hi", "w_pi_pistol50_mag2", "w_pi_pistol_hi", "w_pi_pistol_mag1", "w_pi_pistol_mag2", "w_pi_stungun", "w_pi_stungun_hi", "w_sb_assaultsmg", "w_sb_assaultsmg_hi", "w_sb_assaultsmg_mag1", "w_sb_assaultsmg_mag2", "w_sb_microsmg", "w_sb_microsmg_hi", "w_sb_microsmg_mag1", "w_sb_microsmg_mag2", "w_sb_smg", "w_sb_smg_hi", "w_sb_smg_mag1" };
char* Marker[] = { "Line", "Marker", "Box", "Head Marker", "Cylinder", "3 Esp Favorite", "Dronne Favorite" };
int MarkerVar1;
int MarkerVar;
int BoneVar;
bool AllESP = false;
bool hasESP = false;
int MarkerRed = 0;
int markergreen = 255;
int markerblue = 0;
bool SpawnVehicle;
int SpawnedVeh;
int submenu = 0;
int submenuLevel;
int lastSubmenu[66];
int lastOption[66];
int currentOption;
int optionCount;
bool optionPress = false;
bool rightPress = false;
bool leftPress = false;
bool fastRightPress = false;
bool fastLeftPress = false;
bool squarePress = false;
int selectedPlayer;
bool menuSounds = true;
bool keyboardActive = false;
int keyboardAction;
int *keyboardVar = 0;
char *infoText;

//BOOLS
bool newTimerTick = true;
int maxTimerCount;
bool newTimerTick2 = true;
int maxTimerCount2;
bool instructions = true;
bool slowmotion = false;
int instructCount;
int mov;
int telepaet_ = 0;
bool invincibleClientVeh[20];
bool instructionsSetupThisFrame;
bool xInstruction;
bool squareInstruction;
bool lrInstruction;
int bannerTextRed = 255;
int bannerTextGreen = 255;
int bannerTextBlue = 255;
int bannerTextOpacity = 255;
int bannerTextFont = 1;
int bannerTextFont1 = 6;
int bannerRectRed = 0;//0
int bannerRectGreen = 0;//157
int bannerRectBlue = 0;//0
int bannerRectOpacity = 160;//255//banner text
int backgroundRed = 16;
int backgroundGreen = 16;
int backgroundBlue = 16;
int backgroundOpacity = 160;
int optionsRed = 255;
int optionsGreen = 255;
int optionsBlue = 255;
int optionsOpacity = 255;
int optionsFont = 0;
int scrollerRed = 255;
int scrollerGreen = 255;
int scrollerBlue = 255;//scroller
int scrollerOpacity = 255;
int indicatorRed = 255;
int indicatorGreen = 255;
int indicatorBlue = 255;
int indicatorOpacity = 255;
float menuXCoord = 0.205f;
float MenuWidth = 0.26f;
float textXCoord = 0.08f;
int maxOptions = 14;
int mainTextFont = 1;
float SubTitleXCoord = 0.082f;
float OnOff = 0.32f;//31
float ObjectCode_Pitch = 0;
float ObjectCode_Roll = 0;
float ObjectCode_Yaw = 0;
Entity object_Hash = 0;
int PlayerParticleSize = 1;
int patrilesize = 1;
bool doTeleportClient;
bool gmode = false;
bool NoCops = false;
bool SuperJump = false;
bool SuperPunch = false;
bool NoTarget = false;
bool hasBossMode = false;
bool vgmode_ = false;
bool vinval_ = true;
bool carinvstext = false;
bool FlyCar = false;
bool _lower = false;
bool seatbelt = false;
int platetype = 0;
int vehwindow = 0;
bool Attacho = true;
bool MoveObject = true;
char* PreviousClanName = "";
char* PreviousClanTag = "";
bool l3break;
bool l2bboost;
bool leftfix;
bool r3boost;
bool bindFixVeh;
int vehr = 0;
int vehg = 0;
int vehb = 0;
bool looprainbow_;
bool LoopNeons_ = false;
bool drift;
bool hasNoCollision;
int spawnedped;
bool SpeedOMeter;
bool Meter;
bool heatvision = false;
bool nightvision = false;
bool texturemapps = false;
bool cleararea = false;
bool firstperson = false;
bool spawnWithInvincibility = false;
bool spawnSupedUp = false;
bool GodModeVehicle = false;
bool novisibledamage = false;
int wantedlevel = 0;
int flashspeedmodifier = 1;
int vehdoor = 0;
bool sticktoground = false;
bool FullBeam = false;
int DirtLevl = 0;
bool UnderWater = false;
bool BulletproofTyres = false;
bool Scorched = false;
bool nogravity = false;
int JumpHeight = 3;
int lightMultiply = 0;
int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
bool firegun;
bool BulletBags;
bool oneshotndisable = false;
bool TimeStopeed;
bool Black_Out = true;
bool DisablePhone = false;
bool minimap;
int hours = 0;
bool MeinCodewat;
int AirHeigt;
int FerrisWheele;
bool MeinCode;
bool loop40K_;
bool HeadLights = false, InteriorLights = false; 
bool TurnSignalLeft = false;
bool TurnSignalRight = false;
bool MoneyRain = false;
bool  tripzalarm, godcar_, undrivablecar_, boostcar_;
bool WaepLOOP = false;
bool Spanlllll = false;
bool Zusatz = false;
bool theflash = false;
bool Superman = false;
int SuspensionPart = 0;
int ArmorPart = 0;
int EnginePart = 0;
int BrakesPart = 0;
int SpoilersPart = 0;
int SkirtsPart = 0;
int TransmissionPart = 0;
int FrontBumper = 0;
int RearBumper = 0;
int redcolor = 0;
int greencolor = 0;
int bluecolor = 0;
int Pearlescant = 0;
int RimColor = 0;
int Hood = 0;
int Exhaust = 0;
int Grill = 0;
int FPCam = 0;
int MultiplyLight = 1;
int MultiplyTorque = 1;
int MultiplyEngine = 1;
bool VehEap;
bool ExplosiveBullets = false;
bool predator = false;
bool RocketGun = false;
bool BoostGunner = false;
char *Weapshsh[] = { "VEHICLE_WEAPON_TANK", "VEHICLE_WEAPON_SPACE_ROCKET", "VEHICLE_WEAPON_PLANE_ROCKET", "VEHICLE_WEAPON_PLAYER_LASER", "VEHICLE_WEAPON_ENEMY_LASER", "VEHICLE_WEAPON_PLAYER_BUZZARD" };
char *WeaponSHoot;
char *WeaponsMenu[] = { "Tank", "Space Rockets","Plane Rockets", "Green Laser", "Red Laser", "Buzzard" };
int WeapVar;
bool applyforceg = false;
bool applyforceg2 = false;
bool TPgun = false;
bool rainbow = false;
bool SlowMotionAim, SlowMotionBrake, BulletBagsPlayer, Firegun;
bool SPECTATE = false, FireAmmo = false, FireAmmoPlayer = false;
bool FreezeTime = false;
int Std = TIME::GET_CLOCK_HOURS(), Minute = TIME::GET_CLOCK_MINUTES(), Sekunde = TIME::GET_CLOCK_SECONDS();
bool PlayerAttached;
bool Cash_AirportSign = false;
bool loop40KFake_ = false;
char X[100];
char Y[100];
char Z[100];
char YAW[100];
char PTH[100];
char RLL[100];
char bufferO[100];
char NUM[100];
char VEH[100];
char PEDOO[100];
char HST[100];
char TLK[100];
char buffer[100];
bool PlayerGodmodeVeh = false;
Vector3 MyPos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
Vector3 MyPos1 = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
int TheirVeh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED(selectedPlayer), false);
int Me = PLAYER::PLAYER_PED_ID();
bool flash_run = false;
bool powergun = false;
bool forcefield;
bool SlingShot;
bool objpro = false;
bool ParticlePro = false;
bool clearreport = false;
bool objnearby = false;
bool WindmillProtection = false;
bool dalveh;
int a_Report_Values[17];
int AttachPreventionDelay = 0;
int AttachPreventionDelay2 = 0;
bool DpadSquare = true;
bool AntiFreeze = false;
bool clonep = false;
bool Firewall = false;
bool ShowTalking = false;
int InfoFont = 6;
bool ShowInfos = false;
bool showCoords = false;
bool Loop_Haybail = false;
bool Loop_Toilet = false;
bool alplayerscash;
bool Cash_Tree = false;
bool Cash_Weed = false;
bool Cash_Egg = false;
bool Cash_Bin = false;
bool Cash_Body = false;
bool Cash_Contaniner = false;
bool OffTheRadar = false;
bool DigitalSpeedo = true;
bool AnalogSpeedo = false;
bool Valentines;
bool Independence;
float checkboxshit = 0.855f;
int SelectedObject;
char* ObjectString;
int SpawnedObjects;
bool LoadingObject;
int SpawnedMapObject[20];
char* MapObjectNameArray[20];
int SelectedMapObject;
int SpawnedMapObjects;
bool LoadingMapObject;
int Object_Handle;
char* ObjectMapString;
float MapPitch = ENTITY::GET_ENTITY_PITCH(SelectedMapObject);
float MapRoll = ENTITY::GET_ENTITY_ROLL(SelectedMapObject);
float MapYaw = ENTITY::GET_ENTITY_HEADING(SelectedMapObject);
int MapHandle;
bool MoveMapObject = true;
bool MoveMapObjectZCoords = true;
float PosX_1, PosY_1, PosZ_1;
float Pitch = ENTITY::GET_ENTITY_PITCH(Object_Handle);
float Roll = ENTITY::GET_ENTITY_ROLL(Object_Handle);
float 	Yaw = ENTITY::GET_ENTITY_HEADING(Object_Handle);
float Pos_X, Pos_Y, Pos_Z;
bool HasSmokeLoop;
bool NY;
bool XMas;
char* Flash = { "DrivingFocusLight" };
int TkindicatorRed = 0, TkindicatorGreen = 255, TkindicatorBlue = 0, TkindicatorOpacity = 255;
int NumberPeds, Client, currenttime, firsttime;
int SelectedPed;
bool VehicleFreeezeProtection;
bool VehicleFreeezeProtection1;
bool FreezeeconsoleProtection;
bool cloneprotection = false;
int PXType;
int SizeType;
bool particleman = false;
// Particle Man Char
int ParticDelay2 = 0;
char *PXMenu[] = { "1", "2" };
int PXVar;
char *PXhsh[] = { "ent_sht_petrol_fire", "ent_sht_petrol_fire" };
int SizeVar;
char *PXMenu2[] = { "ent_damage", "ent_damage" };
int ParticalDelay1 = 0;
const int bones4fx[] = { 18905,  57005 , 31086 , 14201 , 52301 };
bool _test;
bool CloneProtection = false;
bool FirePlayerGun = false, VehicType = false, givemoneygun1 = false, PlayerStackGun = false, deletecarloopz = false, GetStreet = false, gmodePed = false, Firefeet = false;
bool explodingtypes = false;
int explodeint;
char* ExplodeNames[] = { "None", "Riding Train", "Climbing", "Pressing Horn", "Shooting", "Jumping", "Reloading", "Running", "Swimming" };
char* Talker;
float menuX1Coord = 0.845f, textX1Coord = 0.76f, tickCoord = 0.920f, tickCoord2 = 0.160f;
bool Tunable_Snow, frezzeplayer, explosionloop;
char* PTFX_Option;
char* FX_Option;
bool shhotcars_;
bool GrapGun = false;
int LLL = 120;
#pragma endregion
int hudColorR = 0;
int hudColorG = 0;
int hudColorB = 0;

//FREEZE CONSOLE v1
bool DoFreezeConsole = false;
int FreezeClient = 0;
bool DeleteSpawnedPedFreeze = false;
int FreezePedID = 0;
int DeleteSpawnedPedFreezeDelay = 0;


#pragma endregion
#pragma region Internals
void HookNative(int native, int dest) {
	int FuncBytes[1];
	FuncBytes[0] = *(int*)dest;
	memcpy((void*)native, FuncBytes, 4);
}
int write_process(void* destination, const void* source, size_t size)
{
	system_call_4(905, (uint64_t)sys_process_getpid(), (uint64_t)destination, size, (uint64_t)source);
	return_to_user_prog(int);
}
int32_t write_process(uint64_t ea, const void* data, uint32_t size)
{
	system_call_4(905, (uint64_t)sys_process_getpid(), ea, size, (uint64_t)data);
	return_to_user_prog(int32_t);
}
void PatchInJump(uint64_t Address, int Destination, bool Linked)
{
	int FuncBytes[4];													// Use this data to copy over the address.
	Destination = *(int*)Destination;									// Get the actual destination address (pointer to void).
	FuncBytes[0] = 0x3D600000 + ((Destination >> 16) & 0xFFFF);			// lis %r11, dest>>16
	if (Destination & 0x8000)											// if bit 16 is 1...
		FuncBytes[0] += 1;
	FuncBytes[1] = 0x396B0000 + (Destination & 0xFFFF);					// addi %r11, %r11, dest&OxFFFF
	FuncBytes[2] = 0x7D6903A6;											// mtctr %r11
	FuncBytes[3] = 0x4E800420;											// bctr
	if (Linked)
		FuncBytes[3] += 1;												// bctrl
	write_process((void*)Address, FuncBytes, 4 * 4);
	//memcpy((void*)Address, FuncBytes, 4 * 4);
}
unsigned int FindNativeTableAddress()
{
	unsigned int  l_uiNativeTableAddress = 0;
	unsigned int l_uiStartAddress = 0x390000;
	unsigned int l_uiAddress = 0;
	for (unsigned int i = 0; i < 0x10000; i++)
	{
		if (*(unsigned int*)(l_uiStartAddress + i) == 0x3C6072BD)
			if (*(unsigned int*)(l_uiStartAddress + i + 8) == 0x6063E002)
			{
				l_uiAddress = *(unsigned int*)(l_uiStartAddress + i + 0x10);
				l_uiAddress &= 0xFFFFFF;
				l_uiAddress += (l_uiStartAddress + i + 0x10) - 1;
				printf("address: 0x%08x\n", l_uiAddress);
				break;
			}
	}
	l_uiNativeTableAddress = (*(unsigned int*)(l_uiAddress + 0x24) << 16) + (*(unsigned int*)(l_uiAddress + 0x2C) & 0xFFFF);
	l_uiNativeTableAddress -= 0x10000;
	return l_uiNativeTableAddress;
}
int NativeAddress(int Native, bool PatchInJump = true)
{
	int Hash = Native & 0xFF;
	int Table = *(int*)(FindNativeTableAddress() + (Hash * 4));
	while (Table != 0)
	{
		int NativeCount = *(int*)(Table + 0x20);
		for (int i = 0; i < NativeCount; i++)
		{
			if (*(int*)((Table + 0x24) + (i * 4)) == Native)
			{
				if (PatchInJump)
				{
					int NativeLocation = *(int*)(*(int*)((Table + 4) + (i * 4)));
					for (int i = 0; i < 50; ++i)
					{
						short CurrentPlace = *(short*)(NativeLocation + (i * 4));
						if (CurrentPlace == 0x4AE6 || CurrentPlace == 0x4AA8 || CurrentPlace == 0x4AE4 || CurrentPlace == 0x4AE5)
						{
							return (((*(int*)(NativeLocation + (i * 4))) - 0x48000001) + (NativeLocation + (i * 4))) - 0x4000000;
						}
					}
				}
				else
				{
					return *(int*)((Table + 4) + (i * 4));
				}

			}
		}
		Table = *(int*)(Table);
	}
}
void sleep(usecond_t time)  //1 second = 1000
{
	sys_timer_usleep(time * 1000);
}
void set_text_component(char *text)
{
	GRAPHICS::_0x3AC9CB55("STRING");
	UI::_ADD_TEXT_COMPONENT_STRING(text);
	GRAPHICS::_0x386CE0B8();
}
void instructionsSetup()
{
	mov = GRAPHICS::REQUEST_SCALEFORM_MOVIE("instructional_buttons");
	GRAPHICS::_0x7B48E696(mov, 255, 255, 255, 0);
	GRAPHICS::_0x215ABBE8(mov, "CLEAR_ALL");
	GRAPHICS::_0x02DBF2D7();
	GRAPHICS::_0x215ABBE8(mov, "SET_CLEAR_SPACE");
	GRAPHICS::_0x716777CB(200);
	GRAPHICS::_0x02DBF2D7();
	instructCount = 0;
}
void addInstruction(int button, char *text)
{
	if (!instructionsSetupThisFrame)
	{
		instructionsSetup();
		instructionsSetupThisFrame = true;
	}
	GRAPHICS::_0x215ABBE8(mov, "SET_DATA_SLOT");
	GRAPHICS::_0x716777CB(instructCount);
	GRAPHICS::_0x716777CB(button);
	set_text_component(text);
	GRAPHICS::_0x02DBF2D7();
	instructCount++;
}
void instructionsClose()
{
	GRAPHICS::_0x215ABBE8(mov, "DRAW_INSTRUCTIONAL_BUTTONS");
	GRAPHICS::_0x02DBF2D7();
	GRAPHICS::_0x215ABBE8(mov, "SET_BACKGROUND_COLOUR");
	GRAPHICS::_0x716777CB(0);
	GRAPHICS::_0x716777CB(0);
	GRAPHICS::_0x716777CB(0);
	GRAPHICS::_0x716777CB(80);
	GRAPHICS::_0x02DBF2D7();
}
void drawText2(char *text, int font, float x, float y, float scalex, float scaley, int r, int g, int b, int a, bool center)
{
	UI::SET_TEXT_FONT(font);
	UI::SET_TEXT_SCALE(scalex, scaley);
	UI::SET_TEXT_CENTRE(center);
	if (currentOption == optionCount)
	{
		UI::SET_TEXT_WRAP(0.0f, 1.0f);
		UI::SET_TEXT_COLOUR(0, 0, 0, 100);
		UI::_SET_TEXT_ENTRY("STRING");
		UI::_ADD_TEXT_COMPONENT_STRING(text);
	}
	else
	{
		UI::SET_TEXT_COLOUR(r, g, b, a);
		UI::_SET_TEXT_ENTRY("STRING");
		UI::_ADD_TEXT_COMPONENT_STRING(text);
		UI::SET_TEXT_FONT(font);
		UI::SET_TEXT_SCALE(scalex, scaley);
		UI::SET_TEXT_WRAP(0.0f, 1.0f);
		UI::SET_TEXT_CENTRE(center);
	}
	UI::_DRAW_TEXT(x, y);
}

char opt[100];
void drawText(char * text, int font, float x, float y, float scalex, float scaley, int r, int b, int g, int a, bool center)
{
	if (strcmp(SCRIPT::GET_THIS_SCRIPT_NAME(), "ingamehud") == 0)
	{
		UI::SET_TEXT_FONT(font);
		UI::SET_TEXT_SCALE(scalex, scaley);
		UI::SET_TEXT_CENTRE(center);
		if (currentOption == optionCount)
		{
			UI::SET_TEXT_WRAP(0.0f, 1.0f);
			UI::SET_TEXT_COLOUR(0, 0, 0, 255);
			snprintf(opt, sizeof(opt), "%s", text);
			UI::_SET_TEXT_ENTRY("STRING");
			UI::_ADD_TEXT_COMPONENT_STRING(text);
		}
		else
		{
			UI::SET_TEXT_COLOUR(r, g, b, a);
			UI::_SET_TEXT_ENTRY("STRING");
			UI::_ADD_TEXT_COMPONENT_STRING(text);;
			UI::SET_TEXT_WRAP(0.0f, 1.0f);
		}
		UI::_DRAW_TEXT(x, y);
	}
}
void drawText1(char * text, int font, float x, float y, float scalex, float scaley, int r, int b, int g, int a, bool center)
{
	if (strcmp(SCRIPT::GET_THIS_SCRIPT_NAME(), "ingamehud") == 0)
	{
		UI::SET_TEXT_FONT(font);
		UI::SET_TEXT_SCALE(scalex, scaley);
		UI::SET_TEXT_CENTRE(center);
		if (currentOption == optionCount)
		{
			UI::SET_TEXT_WRAP(0.0f, 2.0f);
			UI::SET_TEXT_COLOUR(0, 0, 0, 255);
			snprintf(opt, sizeof(opt), "%s", text);
			UI::_SET_TEXT_ENTRY("STRING");
			UI::_ADD_TEXT_COMPONENT_STRING(text);
		}
		else
		{
			UI::SET_TEXT_COLOUR(r, g, b, a);
			UI::_SET_TEXT_ENTRY("STRING");
			UI::_ADD_TEXT_COMPONENT_STRING(text);;
			UI::SET_TEXT_WRAP(0.0f, 2.0f);
		}
		UI::_DRAW_TEXT(x, y);
	}
}
int communityID = 013;
char *modmenu = "";
char *checkModMenuID(int player)
{
	switch (PLAYER::GET_PLAYER_MAX_ARMOUR(player))
	{
	case 013:
		modmenu = "~w~Menu : ~r~The Umbrella"; break;
	case 23:
		modmenu = "~w~Menu : ~r~Metropolis"; break;
	case 28:
		modmenu = "~w~Menu : ~r~Jarvis"; break;
	case 33:
		modmenu = "~w~Menu : ~r~Project Lion"; break;
	case 50:
		modmenu = "~w~Menu: ~r~Player Not Modder"; break;
	case 69:
		modmenu = "~w~Menu : ~r~Tesseract"; break;
	case 71:
		modmenu = "~w~Menu : ~r~SPRX_K"; break;
	case 88:
		modmenu = "~w~Menu : ~r~Pheonix"; break;
	case 97:
		modmenu = "~w~Menu : ~r~Serendipity"; break;
	case 337:
		modmenu = "~w~Menu : ~r~GenocideFreeze"; break;
	case 420:
		modmenu = "~w~Menu : ~r~Glisten Is Gay"; break;
	case 631:
		modmenu = "~w~Menu : ~r~GNXKS"; break;
	case 666:
		modmenu = "~w~Menu : ~r~YetAnotherGTAMenu"; break;
	case 1084:
		modmenu = "~w~Menu : ~r~BlueWindow"; break;
	case 1234:
		modmenu = "~w~Menu : ~r~Lexicon"; break;
	case 1327:
		modmenu = "~w~Menu : ~r~Independence"; break;
	case 1337:
		modmenu = "~w~Menu : ~r~Plethora"; break;
	case 1420:
		modmenu = "~w~Menu : ~r~Toxication"; break;
	case 1996:
		modmenu = "~w~Menu : ~r~Power SPRX"; break;
	case 2000:
		modmenu = "~w~Menu : ~r~Ice SPRX"; break;
	case 2001:
		modmenu = "~w~Menu : ~r~Project Eke"; break;
	case 2027:
		modmenu = "~w~Menu : ~r~Limbo"; break;
	case 2147:
		modmenu = "~w~Menu : ~r~Synergy"; break;
	case 4269:
		modmenu = "~w~Menu : ~r~Cojones"; break;
	case 4321:
		modmenu = "~w~Menu : ~r~Serendipity"; break;
	case 5141:
		modmenu = "~w~Menu : ~r~iLLiCiT"; break;
	case 5150:
		modmenu = "~w~Menu : ~r~ Project Vendetta"; break;
	case 5759:
		modmenu = "~w~Menu : ~r~Trinity"; break;
	case 6969:
		modmenu = "~w~Menu : ~r~WILDE MODZ"; break;
	case 7777:
		modmenu = "~w~Menu : ~r~Predator"; break;
	case 9142:
		modmenu = "~w~Menu : ~r~Manticore"; break;
	case 1312:
		modmenu = "~w~Menu : ~r~KantelMods"; break;
	default:
		modmenu = "Menu: ~r~The Umbrella"; break;
	}
}
float menuXCoord1 = 0.855f;
bool sowmenuID = false;
void Menuidd()
{
	drawText1(checkModMenuID(selectedPlayer), bannerTextFont1, menuXCoord1, 0.4600, 0.35f, 0.70f, bannerTextRed, bannerTextGreen, bannerTextBlue, bannerTextOpacity, false);//true
}
void drawTextR(char *text, float y)
{
	UI::_SET_TEXT_ENTRY("STRING");
	UI::_ADD_TEXT_COMPONENT_STRING(text);
	UI::SET_TEXT_FONT(optionsFont);
	UI::SET_TEXT_SCALE(0.35f, 0.35f);
	UI::SET_TEXT_WRAP(0.1f, 0.325f);
	UI::SET_TEXT_RIGHT_JUSTIFY(true);
	UI::SET_TEXT_COLOUR(optionsRed, optionsGreen, optionsBlue, optionsOpacity);
	UI::_DRAW_TEXT(0.140f, y);
}
void InfoText(char * text, int font, float x, float y, float scalex, float scaley, int r, int b, int g, int a, bool center)
{
	UI::SET_TEXT_FONT(font);
	UI::SET_TEXT_SCALE(scalex, scaley);
	UI::SET_TEXT_COLOUR(r, g, b, a);
	UI::SET_TEXT_WRAP(0.0f, 1.0f);
	UI::SET_TEXT_CENTRE(center);
	UI::_SET_TEXT_ENTRY("STRING");
	UI::_ADD_TEXT_COMPONENT_STRING(text);
	UI::_DRAW_TEXT(x, y);
}
void titleText(char *text, int font, float x, float y, float scalex, float scaley, int r, int g, int b, int a, bool center)
{
	UI::SET_TEXT_FONT(font);
	UI::SET_TEXT_SCALE(scalex, scaley);
	UI::SET_TEXT_COLOUR(r, g, b, a);
	UI::SET_TEXT_WRAP(0.0f, 1.0f);
	UI::SET_TEXT_CENTRE(center);
	UI::SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
	UI::_SET_TEXT_ENTRY("STRING");
	UI::_ADD_TEXT_COMPONENT_STRING(text);
	UI::_DRAW_TEXT(x, y);
	UI::SET_TEXT_OUTLINE();
	UI::SET_TEXT_DROPSHADOW(0,0,0,0,0);
}

#pragma endregion
#pragma region Player Info
bool TheInfoBox = false;
float InfoX = 0.4479f;
float InfoTextX = 0.344f;
float InfoTextX2 = 0.464f;
float InfoLLX = 0.336f;
float InfoRLX = 0.5589f;
float _Money = 0.379f;
float _Rank = 0.369f;
float _K_D = 0.482f;
float _Weapon = 0.409f;
float _Alive = 0.369f;
float _Distance = 0.382f;
float __Xcoords = 0.474f;
float _In_Vehicle = 0.519f;
float __Xcoords2 = 0.492f;
int PlayerVehicle;
int VehicleType;
int Read_Global(int a_uiGlobalID)
{
	int Ptr = *(int*)((0x1E70374 - 0x04) + (((a_uiGlobalID / 0x40000) & 0x3F) * 4));
	if (Ptr != 0)
		return *(int*)(Ptr + ((a_uiGlobalID % 0x40000) * 4));
	return 0;
}
int getPlayerStat(int player, int stat) {
	return Read_Global(1581767 + (player * 306) + stat);
}
int getPlayerRank(int player) {
	return getPlayerStat(player, 185);
}
int getCash(int player) {
	return Read_Global(1581949 + player * 306);
}
void Player_Armed(int client)
{
	InfoText(WEAPON::IS_PED_ARMED(PLAYER::GET_PLAYER_PED(client), 7) ? (char*)"Has A Weapon: ~b~[ ~w~~b~Yes ~b~]" : (char*)"Has A Weapon: ~b~[ ~w~~r~No ~b~]", 6, InfoTextX, 0.185f, 0.5f, 0.5f, optionsRed, optionsGreen, optionsBlue, optionsOpacity, false);
}
void AliveDead(int client)
{
	InfoText(PED::_IS_PED_DEAD(PLAYER::GET_PLAYER_PED(client), true) ? (char*)"Player Is: ~b~[ ~w~~r~Dead ~b~]" : (char*)"Player Is: ~b~[ ~w~~b~Alive ~b~]", 6, InfoTextX, 0.215f, 0.5f, 0.5f, optionsRed, optionsGreen, optionsBlue, optionsOpacity, false);
}
int GetHost()
{
	return NETWORK::NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0);
}
char* GetHostName()
{
	return PLAYER::GET_PLAYER_NAME(GetHost());
}
void Whose_Host(int client)
{
	char HST[50];
	memset(HST, 0, sizeof(HST));
	char* Host = GetHostName();
	if (strcmp(Host, GetHostName()))
		Host = "";
	snprintf(HST, 100, "~b~[ ~w~%s ~b~]", GetHostName());
	InfoText(HST, 6, __Xcoords2, 0.275f, 0.5f, 0.5f, bannerTextRed, bannerTextGreen, bannerTextBlue, bannerTextOpacity, false);
	InfoText("Host:", 6, InfoTextX2, 0.275f, 0.5f, 0.5f, optionsRed, optionsGreen, optionsBlue, optionsOpacity, false);
}
void PlayerInVehicle(int client)
{
	if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::GET_PLAYER_PED(client), 0))
	{
		InfoText(PED::IS_PED_IN_ANY_VEHICLE(PLAYER::GET_PLAYER_PED(client), true) ? (char*)"In Vehicle: ~b~[ ~b~Yes ~b~]" : (char*)"In Vehicle: ~b~[ ~r~No ~b~]", 6, InfoTextX, 0.245f, 0.5f, 0.5f, optionsRed, optionsGreen, optionsBlue, optionsOpacity, false);
	}
	else
	{
		InfoText(PED::IS_PED_IN_ANY_VEHICLE(PLAYER::GET_PLAYER_PED(client), true) ? (char*)"In Vehicle: ~b~[ ~b~Yes ~b~]" : (char*)"In Vehicle: ~b~[ ~r~No ~b~]", 6, InfoTextX, 0.245f, 0.5f, 0.5f, optionsRed, optionsGreen, optionsBlue, optionsOpacity, false);
	}
}
void Player_Vehicle_Type(int client)
{
	PlayerVehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED(client), 0);
	VehicleType = ENTITY::GET_ENTITY_MODEL(PlayerVehicle);
	InfoText(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(VehicleType), 6, __Xcoords2, 0.245f, 0.5f, 0.5f, bannerTextRed, bannerTextGreen, bannerTextBlue, bannerTextOpacity, false);
}
int getPlayerKd(int player, int Kd)
{
	return Read_Global(1581767 + (player * 300) + Kd);
}
int getPlayerKdatio(int player)
{
	return getPlayerKd(player, 180);
}
int getSpeed(int client)
{
	if (PED::IS_PED_IN_ANY_VEHICLE(client, 0))
	{
		int theirspeed = ENTITY::GET_ENTITY_SPEED(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED(client), true));
		char speed[50];
		snprintf(speed, sizeof(speed), "~b~[ ~w~%i ~b~]", theirspeed);
		InfoText(speed, 6, _Money, 0.275f, 0.5f, 0.5f, bannerTextRed, bannerTextGreen, bannerTextBlue, bannerTextOpacity, false);
	}
	else
	{
		InfoText("~b~[ ~w~N/A ~b~]", 6, _Money, 0.275f, 0.5f, 0.5f, bannerTextRed, bannerTextGreen, bannerTextBlue, bannerTextOpacity, false);
	}
}
void drawNotification(char* msg)
{
	if (menuXCoord == 0.845f)
	{
		UI::_0x574EE85C("STRING");
		UI::_ADD_TEXT_COMPONENT_STRING(msg);
		UI::_SET_NOTIFICATION_MESSAGE("CHAR_SOCIAL_CLUB", "CHAR_SOCIAL_CLUB", true, 4, "The Umrella", "");
		UI::_DRAW_NOTIFICATION(false, true);
	}
	else
	{
		UI::_0xF42C43C7("STRING");
		UI::_ADD_TEXT_COMPONENT_STRING(msg);
		UI::_0x38F82261(3000, 1);
	}
}
/*
int XValue;
//FOR WHAT IS THIS CODE? IP LOCAL
#define BYTE unsigned int
// THE BYTE IS a variable,u can change it on other variable like: Foat char and etc...

bool Match(const BYTE* pData, const BYTE* bMask, const char* szMask)
{
	for (; *szMask; ++szMask, ++pData, ++bMask)
		if (*szMask == 'x' && *pData != *bMask)
			return false;
	return (*szMask) == NULL;
}
#define DWORD unsigned long
DWORD FindPattern(DWORD dwAddress, DWORD dwLen, BYTE *bMask, char * szMask)
{
	for (DWORD i = 0; i < dwLen; i++)
		if (Match((BYTE*)(dwAddress + i), bMask, szMask))
			return (DWORD)(dwAddress + i);

	return 0;
}
unsigned int* PBYTE;
BYTE tempName ;
DWORD PlayerNameAddress(int playerId)
{
	char tempName[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
	memcpy(tempName, PLAYER::GET_PLAYER_NAME(playerId), 0x10);
	DWORD tempAddr = FindPattern(0xC8992F5B, 0xFFFF, (PBYTE), "xxxxxxxxxxxx");
	return tempAddr;
}
#define UINT8 int
char* playerIPs[16];
char* GetIP(int playerId)
{
	if (PLAYER::IS_PLAYER_ONLINE() && NETWORK::NETWORK_IS_IN_SESSION())
	{
		if (PLAYER::IS_PLAYER_PLAYING(playerId))
		{
			DWORD Address = PlayerNameAddress(playerId);
			char output[64];
			unsigned char ip1 = *(UINT8*)(Address - 0x48);
			unsigned char ip2 = *(UINT8*)(Address - 0x47);
			unsigned char ip3 = *(UINT8*)(Address - 0x46);
			unsigned char ip4 = *(UINT8*)(Address - 0x45);
			sprintf(output, "%u.%u.%u.%u\n", ip1, ip2, ip3, ip4);
			printf("%s", output);
			return output;
		}
		else
			return "0.0.0.0";
	}
	else
		return "0.0.0.0";
}

void HideIP()
{
	if (PLAYER::IS_PLAYER_ONLINE() && NETWORK::NETWORK_IS_IN_SESSION())
	{
		if (PLAYER::IS_PLAYER_PLAYING(PLAYER::PLAYER_ID()))
		{
			DWORD Address = PlayerNameAddress(PLAYER::PLAYER_ID());
			if (*(UINT8*)(Address - 0x48) != 216 &&
				*(UINT8*)(Address - 0x47) != 58 &&
				*(UINT8*)(Address - 0x46) != 204 &&
				*(UINT8*)(Address - 0x45) != 78)
			{
				//Spoof our IP to google's IP xD
				*(UINT8*)(Address - 0x48) = 216;
				*(UINT8*)(Address - 0x47) = 58;
				*(UINT8*)(Address - 0x46) = 204;
				*(UINT8*)(Address - 0x45) = 78;
				drawNotification("Your IP spoofed to: ~r~216.58.204.78 Please search a new Lobby!");
			}
		}
	}
}

bool IS_THE_SAME_PLAYER(int playerId)
{
	if (GAMEPLAY::ARE_STRINGS_EQUAL(GetIP(playerId), playerIPs[playerId]))
	{
		return true;
	}
	else
	{
		return false;
	}
}

char* getIP(int playerId) // this is the function you need to loop in your ESP INFO BOX
{
	if (IS_THE_SAME_PLAYER(playerId))
	{
		return playerIPs[playerId];
	}
	else
	{
		char* ip = GetIP(playerId);
		playerIPs[playerId] = ip;
		return ip;
	}
}
void PrintText(char *text, int font, float x, float y, float scalex, float scaley, int r, int g, int b, int a, bool center, bool outline)
{
	UI::SET_TEXT_FONT(font);
	UI::SET_TEXT_SCALE(scalex, scaley);
	UI::SET_TEXT_COLOUR(r, g, b, a);
	UI::SET_TEXT_WRAP(0.0f, 1.0f);
	UI::SET_TEXT_CENTRE(center);
	UI::SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
	if (outline)
		UI::SET_TEXT_OUTLINE();
	UI::_SET_TEXT_ENTRY("STRING");
	UI::_ADD_TEXT_COMPONENT_STRING(text);
	UI::_DRAW_TEXT(x, y);
	UI::SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
}
Vector3 SelfPosition;
int selectedTextOpacity;
void PrintTextRightJustify_Stat(char *text, float x, float y, float scalex, float scaley, int r, int b, int g, int a, bool left)
{
	if (!left)
	{
		UI::SET_TEXT_FONT(0);
		UI::SET_TEXT_SCALE(scalex, scaley);
		UI::SET_TEXT_COLOUR(r, g, b, a);
		UI::SET_TEXT_RIGHT_JUSTIFY(true);
		UI::SET_TEXT_WRAP(0.0f, ((XValue)+0.230f) + 0.108f);
		UI::SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
		UI::SET_TEXT_EDGE(0, 0, 0, 0, 0);
		UI::_SET_TEXT_ENTRY("STRING");
		UI::_ADD_TEXT_COMPONENT_STRING(text);
		UI::_DRAW_TEXT(x, y);
	}
	else
	{
		UI::SET_TEXT_FONT(0);
		UI::SET_TEXT_SCALE(scalex, scaley);
		UI::SET_TEXT_COLOUR(r, g, b, a);
		UI::SET_TEXT_RIGHT_JUSTIFY(true);
		UI::SET_TEXT_WRAP(0.0f, ((XValue)-0.230f) + 0.108f);
		UI::SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
		UI::SET_TEXT_EDGE(0, 0, 0, 0, 0);
		UI::_SET_TEXT_ENTRY("STRING");
		UI::_ADD_TEXT_COMPONENT_STRING(text);
		UI::_DRAW_TEXT(x, y);
	}
}
void DrawDataRects(int player)
{
	{
		GRAPHICS::DRAW_RECT(menuXCoord - 0.230f, (9 * 0.035f) + 0.1250f, 0.225f, 0.035, 10, 10, 10, 80);
		PrintTextRightJustify_Stat(getIP(player), ((menuXCoord)-0.230f) + 0.108f, (9 * 0.035f) + 0.11f, 0.35f, 0.35f, optionsRed, optionsGreen, optionsBlue, selectedTextOpacity, true);
		PrintText("IP Address:", optionsFont, (-0.108f + (menuXCoord)) - 0.230f, (9 * 0.035f) + 0.11f, 0.35f, 0.35f, optionsRed, optionsGreen, optionsBlue, optionsOpacity, true, true);
	}
}*/
void ViewInfo(bool isSelected)
{
	Menuidd();
	GRAPHICS::DRAW_RECT(InfoX, 0.2170f, 0.225f, 0.19f, 0, 0, 0, 140); // Info Background			
	GRAPHICS::DRAW_RECT(InfoLLX, 0.2170f, 0.0019f, 0.19f, bannerRectRed, bannerRectGreen, bannerRectBlue, bannerRectOpacity); // Left Line
	GRAPHICS::DRAW_RECT(InfoRLX, 0.2170f, 0.0019f, 0.19f, bannerRectRed, bannerRectGreen, bannerRectBlue, bannerRectOpacity); // Right Line
	GRAPHICS::DRAW_RECT(InfoX, 0.3135f, 0.225f, 0.002f, bannerRectRed, bannerRectGreen, bannerRectBlue, bannerRectOpacity); // Bottom Line
	GRAPHICS::DRAW_RECT(InfoX, 0.1045f, 0.225f, 0.036f, bannerRectRed, bannerRectGreen, bannerRectBlue, bannerRectOpacity); // Info Header

	Player ui_slectedPlayer = selectedPlayer, ui_currentPlayer = currentOption - 1;
	Vector3 playerpos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(isSelected ? ui_slectedPlayer : ui_currentPlayer), true);
	char Money[50], Rank[50], K_D[50], Weapon[50], Distance[50], _X[50], _Y[50], _Z[50];

	snprintf(Money, sizeof(Money), "~b~[ ~w~%i ~b~]", (int)getCash(isSelected ? ui_slectedPlayer : ui_currentPlayer));
	snprintf(Rank, sizeof(Rank), "~b~[ ~w~%i ~b~]", (int)getPlayerRank(isSelected ? ui_slectedPlayer : ui_currentPlayer));
	snprintf(K_D, sizeof(K_D), "~b~[ ~w~%i ~b~]", (int)getPlayerKdatio(isSelected ? ui_slectedPlayer : ui_currentPlayer));
	Player_Armed(isSelected ? ui_slectedPlayer : ui_currentPlayer);
	AliveDead(isSelected ? ui_slectedPlayer : ui_currentPlayer);
	snprintf(Distance, sizeof(Distance), "~b~[ ~w~%i ~b~]", (int)getSpeed(isSelected ? ui_slectedPlayer : ui_currentPlayer));
	snprintf(_X, sizeof(_X), "~b~[ ~w~%i ~b~]", (int)playerpos.x);
	snprintf(_Y, sizeof(_Y), "~b~[ ~w~%i ~b~]", (int)playerpos.y);
	snprintf(_Z, sizeof(_Z), "~b~[ ~w~%i ~b~]", (int)playerpos.z);
	PlayerInVehicle(isSelected ? ui_slectedPlayer : ui_currentPlayer);
	Player_Vehicle_Type(isSelected ? ui_slectedPlayer : ui_currentPlayer);
	Whose_Host(isSelected ? ui_slectedPlayer : ui_currentPlayer);

	InfoText(PLAYER::GET_PLAYER_NAME(selectedPlayer), bannerTextFont, InfoX, 0.0855f, 0.5f, 0.5f, 255, 255, 255, 255, true);
	InfoText(Money, 6, _Money, 0.125f, 0.5f, 0.5f, 255, 255, 255, 255, false);
	InfoText(Rank, 6, _Rank, 0.155f, 0.5f, 0.5f, 255, 255, 255, 255, false);
	InfoText("                      ", 6, _K_D, 0.215f, 0.5f, 0.5f, 255, 255, 255, 255, false);
	InfoText(Weapon, 6, _Weapon, 0.215f, 0.5f, 0.5f, 255, 255, 255, 255, false);
	InfoText(_X, 6, __Xcoords, 0.125f, 0.5f, 0.5f, 255, 255, 255, 255, false);
	InfoText(_Y, 6, __Xcoords, 0.155f, 0.5f, 0.5f, 255, 255, 255, 255, false);
	InfoText(_Z, 6, __Xcoords, 0.185f, 0.5f, 0.5f, 255, 255, 255, 255, false);

	InfoText("Money:", 6, InfoTextX, 0.125f, 0.5f, 0.5f, 255, 255, 255, 255, false);
	InfoText("Rank:", 6, InfoTextX, 0.155f, 0.5f, 0.5f, 255, 255, 255, 255, false);
	InfoText("K/D:", 6, InfoTextX2, 0.215f, 0.5f, 0.5f, 255, 255, 255, 255, false);
	InfoText("Speed:", 6, InfoTextX, 0.275f, 0.5f, 0.5f, 255, 255, 255, 255, false);//
	InfoText("X:", 6, InfoTextX2, 0.125f, 0.5f, 0.5f, 255, 255, 255, 255, false);
	InfoText("Y:", 6, InfoTextX2, 0.155f, 0.5f, 0.5f, 255, 255, 255, 255, false);
	InfoText("Z:", 6, InfoTextX2, 0.185f, 0.5f, 0.5f, 255, 255, 255, 255, false);
	InfoText("Type:", 6, InfoTextX2, 0.245f, 0.5f, 0.5f, 255, 255, 255, 255, false);
}
#pragma endregion
#pragma region
void drawCount(char *text, int font, float scaleX, float scaleY, int r, int g, int b, int a, float start, float end, float x, float y, bool otherside)
{
	UI::_SET_TEXT_ENTRY("STRING");
	UI::SET_TEXT_RIGHT_JUSTIFY(otherside);
	UI::SET_TEXT_FONT(font);
	UI::SET_TEXT_SCALE(scaleX, scaleY);
	UI::SET_TEXT_WRAP(start, end);		
	UI::SET_TEXT_COLOUR(r, g, b, a);	
	UI::_ADD_TEXT_COMPONENT_STRING(text);	
	UI::_DRAW_TEXT(x, y);
}
void DrawSprite(char *Streamedtexture, char  *textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a)
{
	if (!GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED(Streamedtexture))
	{
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT(Streamedtexture, false);
	}
	else
	{
		GRAPHICS::DRAW_SPRITE(Streamedtexture, textureName, x, y, width, height, rotation, r, g, b, a);
	}
}
void Drawcredit(char* Text, float X, float Y, float scaleX, float scaleY, int R, int G, int B, int A)
{
	UI::SET_TEXT_FONT(0);
	UI::SET_TEXT_SCALE(scaleX, scaleY);
	UI::SET_TEXT_COLOUR(R, G, B, A);
	UI::SET_TEXT_OUTLINE();
	UI::SET_TEXT_WRAP(0, 1);
	UI::SET_TEXT_CENTRE(1);
	UI::_SET_TEXT_ENTRY("STRING");
	UI::_ADD_TEXT_COMPONENT_STRING(Text);
	UI::_DRAW_TEXT(X, Y);
}

void playSound(char* sound)
{
	if (menuSounds)
		AUDIO::PLAY_SOUND_FRONTEND(-1, sound, "HUD_FRONTEND_DEFAULT_SOUNDSET");
}
bool isNumericChar(char x)
{
	return (x >= '0' && x <= '9') ? true : false;
}
int StoI(char *str)
{
	if (*str == NULL)
		return 0;

	int res = 0,
		sign = 1,
		i = 0;

	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	for (; str[i] != '\0'; ++i)
	{
		if (isNumericChar(str[i]) == false)
			return 0;
		res = res * 10 + str[i] - '0';
	}
	return sign*res;
}
char *ItoS(int num)
{
	char buf[30];
	snprintf(buf, sizeof(buf), "%i", num);
	return buf;
}
char* FtoS(float input)
{
	char returnvalue[64];
	int wholenumber = (int)input;
	input -= wholenumber;
	input *= 100;
	sprintf(returnvalue, "%d.%d", wholenumber, (int)input);
	return returnvalue;
}
void startKeyboard(int action, char *defaultText, int maxLength)
{
	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(0, "FMMC_KEY_TIP8", "", defaultText, "", "", "", maxLength);
	keyboardAction = action;
	keyboardActive = true;
}
void GetKeyboard(KeyboardTypes KType, char* TitleType = "", char* Preset = "", int MaxNumberOfCharacters = 20, bool NumberOnly = false)
{
	keyboardAction = KType;
	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(0, TitleType, "", Preset, "", "", "", MaxNumberOfCharacters);
	keyboardActive = true;
}
void changeSubmenu(int newSubmenu)
{
	lastSubmenu[submenuLevel] = submenu;
	lastOption[submenuLevel] = currentOption;
	currentOption = 1;
	submenu = newSubmenu;
	submenuLevel++;
}
void SetupTimer(int tickTime)
{
	if (newTimerTick) {
		maxTimerCount = GAMEPLAY::GET_GAME_TIMER() + tickTime;
		newTimerTick = false;
	}
}
bool IsTimerReady()
{
	return GAMEPLAY::GET_GAME_TIMER() > maxTimerCount;
}
void ResetTimer()
{
	newTimerTick = true;
}
void SetupTimer2(int tickTime)
{
	if (newTimerTick2) {
		maxTimerCount2 = GAMEPLAY::GET_GAME_TIMER() + tickTime;
		newTimerTick2 = false;
	}
}
bool IsTimerReady2()
{
	return GAMEPLAY::GET_GAME_TIMER() > maxTimerCount2;
}
void ResetTimer2()
{
	newTimerTick2 = true;
}

int gGlareHandle; 
float gGlareDir;
float gGlarePosX = 0.625;
float gGlarePosY = 0.58;
float gGlareScaleX = 1.35;
float gGlareScaleY = 1.10;
float conv360(float base, float min, float max)
{
	float fVar0;
	if (min == max) return min;
	fVar0 = max - min;
	base -= round(base - min / fVar0) * fVar0;
	if (base < min) base += fVar0;
	return base;
}
void drawGlare()
{
	gGlareHandle = GRAPHICS::REQUEST_SCALEFORM_MOVIE("MP_MENU_GLARE");
	Vector3 rot = CAM::_GET_GAMEPLAY_CAM_ROT(2);
	float dir = conv360(rot.z, 0, 360);
	if ((gGlareDir == 0 || gGlareDir - dir > 0.5) || gGlareDir - dir < -0.5)
	{
		gGlareDir = dir;
		GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION(gGlareHandle, "SET_DATA_SLOT");
		GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_FLOAT(gGlareDir);
		GRAPHICS::_POP_SCALEFORM_MOVIE_FUNCTION_VOID();
	}
	if (strcmp(SCRIPT::GET_THIS_SCRIPT_NAME(), "ingamehud") == 0)
	{
		GRAPHICS::DRAW_SCALEFORM_MOVIE(gGlareHandle, gGlarePosX, gGlarePosY, gGlareScaleX, gGlareScaleY, 255, 255, 255, 255, 0);
		GRAPHICS::SET_SCALEFORM_MOVIE_AS_NO_LONGER_NEEDED(&gGlareHandle);
	}
}

#pragma endregion

#pragma region Option Helpers
void subTitle(char *title)
{
	drawText(title, 0, SubTitleXCoord, 0.18f, 0.35f, 0.35f, bannerTextRed, bannerTextGreen, bannerTextBlue, 255, false);
}
void addOption(char *option, char *info = NULL)
{
	optionCount++;
	if (currentOption == optionCount)
	{	
		if (menuXCoord == 0.815f)
		{

			drawCount(info, 6, 0.5f, 0.5f, 255, 255, 255, 100, 0.5f, 0.9225f, 0.92f, 0.179f, 1);
		}
		else if (menuXCoord == 0.188f)
		{
			drawCount(info, 6, 0.5f, 0.5f, 255, 255, 255, 100, -0.5f, 0.295f, 0.92f, 0.179f, 1);
		}
	}
	if (currentOption <= maxOptions && optionCount <= maxOptions)
	{
		drawText(option, optionsFont, textXCoord, (optionCount * 0.035f + 0.18f), 0.35f, 0.35f, optionsRed, optionsGreen, optionsBlue, optionsOpacity, false);
	}
	else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
	{
		drawText(option, optionsFont, textXCoord, ((optionCount - (currentOption - maxOptions)) * 0.035f + 0.18f), 0.35f, 0.35f, optionsRed, optionsGreen, optionsBlue, optionsOpacity, false);
	}
}
void addSmokeColor(char *option, int *var, int min, int max, bool keyboard, char *info = NULL)
{
	char buf[30];
	snprintf(buf, sizeof(buf), "%i~c~/%i", *var, max);
	drawTextR(buf, 0);
	addOption(option, info);
	if (currentOption == optionCount)
	{
		int vehicle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(vehicle);
		VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
		VEHICLE::TOGGLE_VEHICLE_MOD(vehicle, 20, 1);
		VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(vehicle, 0);

		lrInstruction = true;
		if (fastRightPress)
		{
			playSound("NAV_UP_DOWN");
			if (*var >= max)*var = min;
			else*var = *var + 1;
		}
		else if (fastLeftPress)
		{
			playSound("NAV_UP_DOWN");
			if (*var <= min)*var = max;
			else*var = *var - 1;
		}
		if (keyboard)
		{
			squareInstruction = true;
			if (squarePress)
			{
				startKeyboard(0, "", (strlen(ItoS(max)) + 1));
				keyboardVar = var;
			}
		}
	}
}
void drawTextRight(char *text)
{
	if (currentOption <= maxOptions && optionCount <= maxOptions)
	{
		if (strcmp(SCRIPT::GET_THIS_SCRIPT_NAME(), "ingamehud") == 0)
		{
			drawTextR(text, (optionCount * 0.035f + 0.215f)); // float Y = 0.215f
		}
	}
	else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
	{
		if (strcmp(SCRIPT::GET_THIS_SCRIPT_NAME(), "ingamehud") == 0)
		{
			drawTextR(text, ((optionCount - (currentOption - maxOptions)) * 0.035f + 0.215f));  // float Y = 0.215f
		}
	}
}
void SpriteOn()
{
	if (currentOption <= maxOptions && optionCount <= maxOptions)
	{
		DrawSprite("mprankbadge", "globe_bg", OnOff, (optionCount * 0.035f + 0.195f), 0.01 - 0.001, 0.02 - 0.001, 0, 0, 255, 0, 255);
	}
	else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
	{
		DrawSprite("mprankbadge", "globe_bg", OnOff, ((optionCount - (currentOption - maxOptions)) * 0.035f + 0.195f), 0.01 - 0.001, 0.02 - 0.001, 0, 0, 255, 0, 255);
	}
}
void SpriteOff()
{
	if (currentOption <= maxOptions && optionCount <= maxOptions)
	{
		DrawSprite("mprankbadge", "globe_bg", OnOff, (optionCount * 0.035f + 0.195f), 0.01 - 0.001, 0.02 - 0.001, 0, 255, 0, 0, 255);
	}
	else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
	{
		DrawSprite("mprankbadge", "globe_bg", OnOff, ((optionCount - (currentOption - maxOptions)) * 0.035f + 0.195f), 0.01 - 0.001, 0.02 - 0.001, 0, 255, 0, 0, 255);
	}
}
void TeleportGun1()
{
	float Loc[3];
	if (PED::IS_PED_SHOOTING(PLAYER::PLAYER_PED_ID()))
	{
		if (__GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::PLAYER_PED_ID(), Loc))
		{
			Vector3 Pos;
			Pos.x = Loc[0]; Pos.y = Loc[1]; Pos.z = Loc[2];
			ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), Pos.x, Pos.y, Pos.z, 0, 0, 0, 1);
		}
	}
}
void addSubmenuOption(char *option, int newSubmenu, char *info = NULL)
{
	addOption(option, info);
	if (currentOption == optionCount)
	{
		xInstruction = true;
		if (optionPress)
			changeSubmenu(newSubmenu);
	}
}
void PTFXgun(char* PTFX_LOADED, char* FX_LOOPED, float SCALE)
{
	float Loc[3];
	Vector3 Pos;
	if (PED::IS_PED_SHOOTING(PLAYER::PLAYER_PED_ID()))
	{
		if (__GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::PLAYER_PED_ID(), Loc))
		{

			Pos.x = Loc[0]; Pos.y = Loc[1]; Pos.z = Loc[2];
			if (STREAMING::_HAS_DLC_PTFX_LOADED(PTFX_LOADED))
			{
				GRAPHICS::_SET_PTFX_ASSET_NEXT_CALL(PTFX_LOADED);
				GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_AT_COORD_2(FX_LOOPED, Pos.x, Pos.y, Pos.z, 0, 0, 0, SCALE, 0, 0, 0);
			}
			else
			{
				STREAMING::_REQUEST_DLC_PTFX_ASSET(PTFX_LOADED);
			}
		}
	}
}
void FXchange2(char *option, char* PTFX_LOADED, char* FX_LOOPED, float SCALE, bool b00l, bool b00l2)
{
	char buf[30];
	if (b00l, b00l2)
	{
		DrawSprite("commonmenu", "mp_specitem_cash", OnOff, (optionCount * 0.035f + 0.195f), 0.03 - 0.003, 0.05 - 0.005, 0, 75, 174, 82, 220);
		PTFXgun(PTFX_LOADED, FX_LOOPED, SCALE);
		snprintf(buf, sizeof(buf), "%s", option);
		addOption(buf);
	}
	else
	{
		DrawSprite("commonmenu", "mp_specitem_cash", OnOff, (optionCount * 0.035f + 0.195f), 0.03 - 0.003, 0.05 - 0.005, 0, 174, 75, 82, 220);
		snprintf(buf, sizeof(buf), "%s", option);
		addOption(buf);
	}

}
void FXchange(char *option, char* PTFX_LOADED, char* FX_LOOPED, float SCALE, bool b00l, bool b00l2)
{
	char buf[30];
	if (b00l, b00l2)
	{
		DrawSprite("commonmenu", "mp_specitem_cash", OnOff, (optionCount * 0.035f + 0.195f), 0.03 - 0.003, 0.05 - 0.005, 0, 75, 174, 82, 220);
		PTFXgun(PTFX_LOADED, FX_LOOPED, SCALE);
		snprintf(buf, sizeof(buf), "%s", option);
		addOption(buf);
	}
	else
	{
		DrawSprite("commonmenu", "mp_specitem_cash", OnOff, (optionCount * 0.035f + 0.195f), 0.03 - 0.003, 0.05 - 0.005, 0, 174, 75, 82, 220);
		snprintf(buf, sizeof(buf), "%s", option);
		addOption(buf);
	}

}
void SpriteOff1()
{
	if (currentOption <= maxOptions && optionCount <= maxOptions)
	{
		DrawSprite("commonmenutu", "arrowright", OnOff, (optionCount * 0.035f + 0.195f), 0.01 - 0.001, 0.02 - 0.001, 0, 128, 128, 128, 255);
	}
	else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
	{
		DrawSprite("commonmenutu", "arrowright", OnOff, ((optionCount - (currentOption - maxOptions)) * 0.035f + 0.195f), 0.01 - 0.001, 0.02 - 0.001, 0, 128, 128, 128, 255);
	}
}
void spritemenu(char *right, bool b00l, char *info = NULL)
{
	char buf[30];
	if (b00l)
	{
		snprintf(buf, sizeof(buf), "%s", right);
		addOption(buf, info);
		SpriteOff1();
	}
}
void addBoolOption(char *right, bool b00l, char *info = NULL)
{
	char buf[30];
	if (b00l)
	{
		snprintf(buf, sizeof(buf), "%s", right);
		addOption(buf, info);
		SpriteOn();
	}
	else
	{
		snprintf(buf, sizeof(buf), "%s", right);
		addOption(buf, info);
		SpriteOff();

	}
}
void addBoolOption01(char *option, bool b00l, char *info = NULL)
{
	char buf[30];
	if (b00l)
	{
		snprintf(buf, sizeof(buf), "~w~Signal Flashing ~g~Left", option);
		addOption(buf, info);
	}
	else
	{
		snprintf(buf, sizeof(buf), "~w~Left Turn Signal", option);
		addOption(buf, info);
	}
}


void addBoolOption02(char *option, bool b00l, char *info = NULL)
{
	char buf[30];
	if (b00l)
	{
		snprintf(buf, sizeof(buf), "~w~Signal Flashing ~g~Right", option);
		addOption(buf, info);
	}
	else
	{
		snprintf(buf, sizeof(buf), "~w~Right Turn Signal", option);
		addOption(buf, info);
	}
}
template<typename TYPE>
void addCustomBoolOption(char *right, TYPE value, TYPE match, char *info = NULL)
{
	char buf[30];
	if (value == match)
	{
		snprintf(buf, sizeof(buf), "%s", right);
		addOption(buf, info);
		SpriteOn();
	}
	else
	{
		snprintf(buf, sizeof(buf), "%s", right);
		addOption(buf, info);
		SpriteOff();
	}
}
void addIntOption(char *option, int *var, int min, int max, bool keyboard, char *info = NULL)
{
	char buf[30];
	snprintf(buf, sizeof(buf), "%s: < %i >", option, *var);
	addOption(buf, info);
	if (currentOption == optionCount)
	{
		lrInstruction = true;
		if (rightPress)
		{
			playSound("NAV_UP_DOWN");
			if (*var >= max)
				*var = min;
			else
				*var = *var + 1;
		}
		else if (leftPress)
		{
			playSound("NAV_UP_DOWN");
			if (*var <= min)
				*var = max;
			else
				*var = *var - 1;
		}
		if (keyboard)
		{
			squareInstruction = true;
			if (squarePress)
			{
				startKeyboard(0, "", (strlen(ItoS(max)) + 1));
				keyboardVar = var;
			}
		}
	}
}
void addIntOption2(char *option, int *var, int min, int max, char *info = NULL)
{
	char buf[30];
	snprintf(buf, sizeof(buf), "%s: %i", option, *var);
	addOption(buf);
	if (currentOption == optionCount)
	{
		if (rightPress)
		{
			playSound("NAV_UP_DOWN");
			if (*var >= max)
				*var = min;
			else
				*var = *var + 1;
		}
		else if (leftPress)
		{
			playSound("NAV_UP_DOWN");
			if (*var <= min)
				*var = max;
			else
				*var = *var - 1;
		}
		else if (optionPress)
		{
			startKeyboard(0, "", (strlen(ItoS(max)) + 1));
			keyboardVar = var;
		}
	}
}
void addCharSwap(char *option, char **From, int*var, int min, int max, bool any = false)
{
	char buf[50];
	if (!any)
	{
		snprintf(buf, sizeof(buf), "%s: ~r~%s~w~ ", option, From[*var]);
		addOption(buf);
		if (currentOption == optionCount)
		{
			lrInstruction = true;
			if (rightPress)
			{
				playSound("NAV_UP_DOWN");
				if (*var >= max)
					*var = min;
				else
					*var = *var + 1;
			}
			else if (leftPress)
			{
				playSound("NAV_UP_DOWN");
				if (*var <= min)
					*var = max;
				else
					*var = *var - 1;
			}
		}
	}
	else
	{
		snprintf(buf, sizeof(buf), "%s: - ~b~%s~w~ +", option, From[*var]);
		addOption(buf);
		if (currentOption == optionCount)
		{
			lrInstruction = true;
			if (rightPress)
			{
				playSound("NAV_UP_DOWN");
				if (*var >= max)
					*var = min;
				else
					*var = *var + 1;
			}
			else if (leftPress)
			{
				playSound("NAV_UP_DOWN");
				if (*var <= min)
					*var = max;
				else
					*var = *var - 1;
			}
		}
	}
}
void addFloatOption1(char *optionOFF, char *OptionOn, bool b00l, float *var, float min, float max, float Movement = 0.01, char *info = NULL)
{
	char buf[50];

	if (b00l)
	{
		snprintf(buf, sizeof(buf), "%s: < %s >", OptionOn, FtoS(*var));
		addOption(buf, info);
		if (currentOption == optionCount)
		{
			lrInstruction = true;
			if (rightPress)
			{
				playSound("NAV_UP_DOWN");
				if (*var >= max)
					*var = min;
				else
					*var = *var + Movement;
			}
			else if (leftPress)
			{
				playSound("NAV_UP_DOWN");
				if (*var <= min)
					*var = max;
				else
					*var = *var - Movement;
			}
		}
	}
	else
	{
		snprintf(buf, sizeof(buf), "%s: ", optionOFF); //~r~Off"
		addOption(buf, info);
	}
}
void addFloatOption(char *option, float *var, float min, float max, bool holdPress, int p1 = 0, float var_ = 0.01, char *info = NULL)
{
	keyboardAction = p1;

	char buf[30];
	snprintf(buf, sizeof(buf), "%s: < %s >", option, FtoS(*var));
	addOption(buf, info);
	if (currentOption == optionCount)
	{
		lrInstruction = true;
		if (holdPress)
		{
			if (fastRightPress)
			{
				playSound("NAV_UP_DOWN");
				if (*var >= max)
					*var = min;
				else
					*var = *var + var_;
			}
			else if (fastLeftPress)
			{
				playSound("NAV_UP_DOWN");
				if (*var <= min)
					*var = max;
				else
					*var = *var - var_;
			}
		}
		else
		{
			if (rightPress)
			{
				playSound("NAV_UP_DOWN");
				if (*var >= max)
					*var = min;
				else
					*var = *var + var_;
			}
			else if (leftPress)
			{
				playSound("NAV_UP_DOWN");
				if (*var <= min)
					*var = max;
				else
					*var = *var - var_;
			}
		}
	}
	switch (keyboardAction)
	{
	case 0:
		break;
	case 1:
		ENTITY::SET_ENTITY_ROTATION(object_Hash, ObjectCode_Pitch, ObjectCode_Roll, ObjectCode_Yaw, 2, 1);
		break;
	}
}
float MoveSize = 0.1f;
void MoveCoordsOption(char *option, int Object, bool X_Coords = false, bool Y_Coords = false, bool Z_Coords = false, char *info = NULL)
{
	Vector3 Coords = ENTITY::GET_ENTITY_COORDS(Object, 0);
	char buf[30];
	snprintf(buf, sizeof(buf), "  <  %s  >", option);
	addOption(buf, info);
	if (currentOption == optionCount)
	{
		lrInstruction = true;
		if (fastRightPress)
		{
			playSound("NAV_UP_DOWN");
			if (X_Coords)
			{
				Coords.x = Coords.x + MoveSize;
				ENTITY::SET_ENTITY_COORDS(Object, Coords.x, Coords.y, Coords.z, 0, 0, 0, 1);
			}
			else if (Y_Coords)
			{
				Coords.y = Coords.y + MoveSize;
				ENTITY::SET_ENTITY_COORDS(Object, Coords.x, Coords.y, Coords.z, 0, 0, 0, 1);
			}

			else if (Z_Coords)
			{
				Coords.z = Coords.z + MoveSize;
				ENTITY::SET_ENTITY_COORDS(Object, Coords.x, Coords.y, Coords.z, 0, 0, 0, 1);
			}
		}
		else if (fastLeftPress)
		{
			playSound("NAV_UP_DOWN");
			if (X_Coords)
			{
				Coords.x = Coords.x - MoveSize;
				ENTITY::SET_ENTITY_COORDS(Object, Coords.x, Coords.y, Coords.z, 0, 0, 0, 1);
			}
			else if (Y_Coords)
			{
				Coords.y = Coords.y - MoveSize;
				ENTITY::SET_ENTITY_COORDS(Object, Coords.x, Coords.y, Coords.z, 0, 0, 0, 1);
			}
			else 	if (Z_Coords)
			{
				Coords.z = Coords.z - MoveSize;
				ENTITY::SET_ENTITY_COORDS(Object, Coords.x, Coords.y, Coords.z, 0, 0, 0, 1);
			}
		}
	}
}

void addWechselFloatOption(char *option, float *var, float min, float max, bool holdPress, char *info = NULL)
{
	char buf[30];
	snprintf(buf, sizeof(buf), "%s: < %s >", option, FtoS(*var));
	addOption(buf, info);
	if (currentOption == optionCount)
	{
		lrInstruction = true;
		if (holdPress)
		{
			if (fastRightPress)
			{
				playSound("NAV_UP_DOWN");
				if (*var >= max)
					*var = min;
				else
					*var = *var + MoveSize;
			}
			else if (fastLeftPress)
			{
				playSound("NAV_UP_DOWN");
				if (*var <= min)
					*var = max;
				else
					*var = *var - MoveSize;
			}
		}
		else
		{
			if (rightPress)
			{
				playSound("NAV_UP_DOWN");
				if (*var >= max)
					*var = min;
				else
					*var = *var + MoveSize;
			}
			else if (leftPress)
			{
				playSound("NAV_UP_DOWN");
				if (*var <= min)
					*var = max;
				else
					*var = *var - MoveSize;
			}
		}
	}
}

void Hud_Color(int hudColorR, int hudColorG, int hudColorB)//cor do sangue//
{
	UI::_SET_HUD_COLOUR1(hudColorR, hudColorG, hudColorB, 255);
}
void addCharBOOLSwap(char *optionON, char **From, int*var, int min, int max, bool B)
{
	char buf[30];
	snprintf(buf, sizeof(buf), "%s  < %s >", optionON, (From[*var]));
	addOption(buf);
	if (currentOption == optionCount)
	{
		if (rightPress)
		{
			playSound("NAV_UP_DOWN");
			if (*var >= max)
				*var = min;
			else
				*var = *var + 1;
		}
		else if (leftPress)
		{
			playSound("NAV_UP_DOWN");
			if (*var <= min)
				*var = max;
			else
				*var = *var - 1;
		}
	}
}
struct RGB
{
	int Red, Green, Blue, Opacity;
};
RGB TitleColour = { 255, 0, 0, 0 };
RGB OptionColour = { 255, 0, 0, 0 };
void Kiste(Vector3 Cords, float XXX, float ZZZ)
{
	GRAPHICS::DRAW_LINE(Cords.x + XXX, Cords.y + XXX, Cords.z + ZZZ, Cords.x + XXX, Cords.y - XXX, Cords.z + ZZZ, MarkerRed, markergreen, markerblue, 255);
	GRAPHICS::DRAW_LINE(Cords.x + XXX, Cords.y - XXX, Cords.z + ZZZ, Cords.x - XXX, Cords.y - XXX, Cords.z + ZZZ, MarkerRed, markergreen, markerblue, 255);
	GRAPHICS::DRAW_LINE(Cords.x - XXX, Cords.y - XXX, Cords.z + ZZZ, Cords.x - XXX, Cords.y + XXX, Cords.z + ZZZ, MarkerRed, markergreen, markerblue, 255);
	GRAPHICS::DRAW_LINE(Cords.x - XXX, Cords.y + XXX, Cords.z + ZZZ, Cords.x + XXX, Cords.y + XXX, Cords.z + ZZZ, MarkerRed, markergreen, markerblue, 255);
	GRAPHICS::DRAW_LINE(Cords.x + XXX, Cords.y + XXX, Cords.z - ZZZ, Cords.x + XXX, Cords.y - XXX, Cords.z - ZZZ, MarkerRed, markergreen, markerblue, 255);
	GRAPHICS::DRAW_LINE(Cords.x + XXX, Cords.y - XXX, Cords.z - ZZZ, Cords.x - XXX, Cords.y - XXX, Cords.z - ZZZ, MarkerRed, markergreen, markerblue, 255);
	GRAPHICS::DRAW_LINE(Cords.x - XXX, Cords.y - XXX, Cords.z - ZZZ, Cords.x - XXX, Cords.y + XXX, Cords.z - ZZZ, MarkerRed, markergreen, markerblue, 255);
	GRAPHICS::DRAW_LINE(Cords.x - XXX, Cords.y + XXX, Cords.z - ZZZ, Cords.x + XXX, Cords.y + XXX, Cords.z - ZZZ, MarkerRed, markergreen, markerblue, 255);
	GRAPHICS::DRAW_LINE(Cords.x + XXX, Cords.y + XXX, Cords.z - ZZZ, Cords.x + XXX, Cords.y + XXX, Cords.z + ZZZ, MarkerRed, markergreen, markerblue, 255);
	GRAPHICS::DRAW_LINE(Cords.x + XXX, Cords.y - XXX, Cords.z - ZZZ, Cords.x + XXX, Cords.y - XXX, Cords.z + ZZZ, MarkerRed, markergreen, markerblue, 255);
	GRAPHICS::DRAW_LINE(Cords.x - XXX, Cords.y - XXX, Cords.z - ZZZ, Cords.x - XXX, Cords.y - XXX, Cords.z + ZZZ, MarkerRed, markergreen, markerblue, 255);
	GRAPHICS::DRAW_LINE(Cords.x - XXX, Cords.y + XXX, Cords.z - ZZZ, Cords.x - XXX, Cords.y + XXX, Cords.z + ZZZ, MarkerRed, markergreen, markerblue, 255);
}
void drawESP(int client)
{
	Vector3 playerPosition = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS2(PLAYER::GET_PLAYER_PED(client), 10.0, 10.0, 0.0);
	playerPosition.z += 1.5;
	GRAPHICS::DRAW_MARKER(21, playerPosition.x, playerPosition.y, playerPosition.z, 0.0f, 0.0f, 0.0f, 180.0f, 0.0f, 0.0f, 0.9f, 0.9f, 0.9f, MarkerRed, markergreen, markerblue, 255, true, false, 2, true, false, false, false);
}
void Linie(int Client)
{
	int PedID = PLAYER::GET_PLAYER_PED(Client);
	Vector3 LocalPed = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	Vector3 TargetPed = ENTITY::GET_ENTITY_COORDS(PedID, 1);
	float start[] = { LocalPed.x, LocalPed.y, LocalPed.z };
	float end[] = { TargetPed.x, TargetPed.y, TargetPed.z };
	GRAPHICS::DRAW_LINE(start[0], start[1], start[2], end[0], end[1], end[2], MarkerRed, markergreen, markerblue, 255);
	GRAPHICS::_DRAW_RECT(start, end, MarkerRed, markergreen, markerblue, 255);
}
void drawESP2(int client)
{
	Vector3 	playerPosition = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::GET_PLAYER_PED(client), 10.0, 10.0, 0.0);
	playerPosition.z -= 1.5;
	GRAPHICS::DRAW_MARKER(1, playerPosition.x, playerPosition.y, playerPosition.z, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.9f, 0.9f, 3.0f, TitleColour.Red, TitleColour.Green, TitleColour.Blue, 255, false, false, 2, true, false, false, false);
}
void TEST10(int client)
{
	Vector3 playerPosition = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::GET_PLAYER_PED(client), 10.0, 10.0, 0.0);
	playerPosition.z += 1.5;
	GRAPHICS::DRAW_MARKER(20, playerPosition.x, playerPosition.y, playerPosition.z, 0.0f, 0.0f, 180.0f, 180.0f, 0.0f, 0.0f, 0.9f, 0.9f, 0.9f, TitleColour.Red, TitleColour.Green, TitleColour.Blue, 255, false, true, 2, true, false, false, false);
}
void TEST6(int client)
{
	Vector3 playerPosition = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::GET_PLAYER_PED(client), 10.0, 10.0, 0.0);
	playerPosition.z += 1.5;
	GRAPHICS::DRAW_MARKER(7, playerPosition.x, playerPosition.y, playerPosition.z, 0.0f, 0.0f, 180.0f, 180.0f, 0.0f, 0.0f, 0.9f, 0.9f, 0.9f, TitleColour.Red, TitleColour.Green, TitleColour.Blue, 255, false, true, 2, true, false, false, false);
}
void DoFX(char* asset, char *PTFX)//
{
	STREAMING::_REQUEST_DLC_PTFX_ASSET(asset);
	GRAPHICS::_SET_PTFX_ASSET_NEXT_CALL(asset);
	GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2(PTFX, PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0.0f, 0.0f, 0.0f, 0x60f0, patrilesize, 0, 0, 0);
}
void addFXOption(char *option, char *asset, char* FX)
{
	addOption(option);
	if (currentOption == optionCount && optionPress)
	{
		DoFX(asset, FX);
	}
}
void changeModel(char* Model)
{

	int ModelHash = GAMEPLAY::GET_HASH_KEY(Model);
	if (STREAMING::IS_MODEL_IN_CDIMAGE(ModelHash))
	{
		if (STREAMING::IS_MODEL_VALID(ModelHash))
		{
			STREAMING::REQUEST_MODEL(ModelHash);
			if (STREAMING::HAS_MODEL_LOADED(ModelHash))
			{
				PLAYER::SET_PLAYER_MODEL(PLAYER::PLAYER_ID(), ModelHash);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(ModelHash);
				DoFX("scr_rcbarry2", "scr_clown_death");
				DoFX("scr_oddjobtraffickingair", "scr_ojdg4_boat_exp");
			}
		}
	}
}

void DoFXonPlayer(char* asset, char *PTFX)
{
	Ped playerPed = PLAYER::GET_PLAYER_PED(selectedPlayer);
	Vector3 coords = ENTITY::GET_ENTITY_COORDS(selectedPlayer, true);

	STREAMING::_REQUEST_DLC_PTFX_ASSET(asset);
	GRAPHICS::_SET_PTFX_ASSET_NEXT_CALL(asset);
	GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2(PTFX, playerPed, coords.x, coords.y, coords.z, 0.0f, 0.0f, 0.0f, 0x60f0, PlayerParticleSize, 0, 0, 0);

}
void addPlayerFX(char *option, char *asset, char* FX)
{
	addOption(option);
	if (currentOption == optionCount && optionPress)
	{
		DoFXonPlayer(asset, FX);
	}
}
bool RunSpeed = false;
void playerMovementSpeed()
{
	if (!RunSpeed)
	{
		PLAYER::_SET_MOVE_SPEED_MULTIPLIER(PLAYER::PLAYER_ID(), 1.49f);
		RunSpeed = true;
	}
	else
	{
		PLAYER::_SET_MOVE_SPEED_MULTIPLIER(PLAYER::PLAYER_ID(), 1);
		RunSpeed = false;
	}
}
int SpawnedObject[20]; char* ObjectNameArray[20];
bool Create_Object2(char* ObjectName, float Name, float Pos, bool custom = false, int hash = 0)
{
	if (STREAMING::IS_MODEL_IN_CDIMAGE(GAMEPLAY::GET_HASH_KEY(ObjectName)))
	{
		if (STREAMING::IS_MODEL_VALID(GAMEPLAY::GET_HASH_KEY(ObjectName)))
		{
			STREAMING::REQUEST_MODEL(GAMEPLAY::GET_HASH_KEY(ObjectName));
			Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
			if (STREAMING::HAS_MODEL_LOADED(GAMEPLAY::GET_HASH_KEY(ObjectName)))
			{
				SpawnedObject[SpawnedObjects] = OBJECT::CREATE_OBJECT(GAMEPLAY::GET_HASH_KEY(ObjectName), coords.x, coords.y, coords.z, 1, 0, 1);
				ObjectNameArray[SpawnedObjects] = ObjectName;
				if (ENTITY::DOES_ENTITY_EXIST(SpawnedObject[SpawnedObjects]))
				{
					Object_Handle = SpawnedObject[SpawnedObjects];
					ENTITY::ATTACH_ENTITY_TO_ENTITY(Object_Handle, PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 1);

					SpawnedObjects++;
					char buf[100];
					snprintf(buf, sizeof(buf), "Spawned: ~b~%s~HUD_COLOUR_WHITE~!", ObjectName);
					drawNotification(buf);
					if (SpawnedObjects >= 15)
						SpawnedObjects = 0;
					return true;
				}
				else return false;
			}
			else return false;
		}
	}
}
bool CreateObject(char* ObjectName, bool freeze = false)
{
	if (STREAMING::IS_MODEL_IN_CDIMAGE(GAMEPLAY::GET_HASH_KEY(ObjectName)))
	{
		if (STREAMING::IS_MODEL_VALID(GAMEPLAY::GET_HASH_KEY(ObjectName)))
		{
			STREAMING::REQUEST_MODEL(GAMEPLAY::GET_HASH_KEY(ObjectName));
			Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
			if (STREAMING::HAS_MODEL_LOADED(GAMEPLAY::GET_HASH_KEY(ObjectName)))
			{
				OBJECT::CREATE_OBJECT(GAMEPLAY::GET_HASH_KEY(ObjectName), coords.x, coords.y - 2, coords.z, 1, 1, 0);
			}
			else return false;
		}
	}
}
bool doForceField_;
void Dofroce()
{
	doForceField_ = !doForceField_;
}
#define FLT_MAX (3.40282347E+38F)
void doForceField(int client)
{
	Vector3 Pos = ENTITY::GET_ENTITY_COORDS(client, true);
	FIRE::ADD_EXPLOSION(Pos.x, Pos.y, Pos.z, 29, FLT_MAX, false, true, 0.0f);
	FIRE::ADD_EXPLOSION(Pos.x, Pos.y, Pos.z, 26, FLT_MAX, false, true, 0.0f);
}
bool mobileRadio;
void toggleMobileRadio()
{
	int station = AUDIO::GET_PLAYER_RADIO_STATION_INDEX();
	if (mobileRadio)
	{
		AUDIO::SET_MOBILE_RADIO_ENABLED_DURING_GAMEPLAY(false);
		AUDIO::SET_MOBILE_PHONE_RADIO_STATE(0);
		mobileRadio = false;
	}
	else
	{
		AUDIO::SET_MOBILE_RADIO_ENABLED_DURING_GAMEPLAY(true);
		AUDIO::SET_MOBILE_PHONE_RADIO_STATE(1);
		AUDIO::SET_RADIO_TO_STATION_INDEX(station);
		mobileRadio = true;
	}
}
bool Ammo_ = false;
void Ammo()
{
	int Ped1 = PLAYER::PLAYER_PED_ID();
	if (Ammo_ == false)
	{
		Ammo_ = true;
		WEAPON::SET_PED_INFINITE_AMMO_CLIP(Ped1, true);
	}
	else if (Ammo_ == true)
	{
		Ammo_ = false;
		WEAPON::SET_PED_INFINITE_AMMO_CLIP(Ped1, false);
	}
}
int ClonePed(int PedHandle)
{
	return PED::CLONE_PED(PedHandle, ENTITY::GET_ENTITY_HEADING(PedHandle), 1, 1);
}
void SetTunable(int index, int value)
{
	int TunablesAddress = (*(int*)0x1E70374) + 4; //0x1E60274
	{
		if (TunablesAddress != 0)
		{
			int temp = TunablesAddress;
			temp += (index * 4);
			*(int*)temp = value;
		}
	}
}
void addTeleportOption(char *option, float x, float y, float z, char *info = NULL)
{
	addOption(option);
	if (currentOption == optionCount && optionPress)
	{
		uint handle = PLAYER::PLAYER_PED_ID();
		if (PED::IS_PED_IN_ANY_VEHICLE(handle, 0))
			handle = PED::GET_VEHICLE_PED_IS_IN(handle, 0);
		ENTITY::SET_ENTITY_COORDS(handle, x, y, z, 0, 0, 0, 1);
		DoFX("scr_rcbarry2", "scr_clown_appears");
		DoFX("scr_oddjobtraffickingair", "scr_ojdg4_boat_exp");
		drawNotification("Teleported");		
	}
}
void northYankton()
{
	STREAMING::REQUEST_IPL("prologue01");
	STREAMING::REQUEST_IPL("prologue01c");
	STREAMING::REQUEST_IPL("prologue01d");
	STREAMING::REQUEST_IPL("prologue01e");
	STREAMING::REQUEST_IPL("prologue01f");
	STREAMING::REQUEST_IPL("prologue01g");
	STREAMING::REQUEST_IPL("prologue01h");
	STREAMING::REQUEST_IPL("prologue01i");
	STREAMING::REQUEST_IPL("prologue01j");
	STREAMING::REQUEST_IPL("prologue01k");
	STREAMING::REQUEST_IPL("prologue01z");
	STREAMING::REQUEST_IPL("prologue02");
	STREAMING::REQUEST_IPL("prologue03");
	STREAMING::REQUEST_IPL("prologue03b");
	STREAMING::REQUEST_IPL("prologue04");
	STREAMING::REQUEST_IPL("prologue04b");
	STREAMING::REQUEST_IPL("prologue05");
	STREAMING::REQUEST_IPL("prologue05b");
	STREAMING::REQUEST_IPL("prologue06");
	STREAMING::REQUEST_IPL("prologue06b");
	STREAMING::REQUEST_IPL("prologuerd");
	STREAMING::REQUEST_IPL("prologuerdb");
	STREAMING::REQUEST_IPL("prologue_m2_door");
	STREAMING::REQUEST_IPL("prologue_LODLights");
	STREAMING::REQUEST_IPL("prologue_DistantLights");
	STREAMING::REQUEST_IPL("prologue03_grv_cov");
	STREAMING::REQUEST_IPL("prologue03_grv_dug");
	STREAMING::REQUEST_IPL("prologue03_grv_fun");
	if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
	{
		int vehid4;
		vehid4 = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		Vector3 coords = { 3217.6970214844, -4834.826171875, 111.81479644775 };
		ENTITY::SET_ENTITY_COORDS(vehid4, coords.x, coords.y, coords.z, 1, 0, 0, 1);
	}
	else
	{
		Vector3 coords = { 3217.6970214844, -4834.826171875, 111.81479644775 };
		ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), coords.x, coords.y, coords.z, 1, 0, 0, 1);
	}
}
void pornYacht()
{
	STREAMING::REQUEST_IPL("smboat");
	Vector3 coords = { -2045.8f, -1031.2f, 11.9f };
	ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), coords.x, coords.y, coords.z, 1, 0, 0, 1);
}
void Hospital()
{
	STREAMING::REQUEST_IPL("RC12B_HospitalInterior");
	STREAMING::REQUEST_IPL("RC12B_Destroyed");
	Vector3 coords = { 356.8f, -590.1f, 43.3f };
	ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), coords.x, coords.y, coords.z, 1, 0, 0, 1);
}
void cargoship()
{
	STREAMING::REQUEST_IPL("cargoship");
	Vector3 coords = { -90.0f, -2365.8f, 14.3f };
	ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), coords.x, coords.y, coords.z, 1, 0, 0, 1);
}
bool Setped;
int CustomAbove = 0;
int CustomForward = 0;
int Above;
void above2m()
{
	Vector3 Coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 0.00, 2.0);
	int Handle = PLAYER::PLAYER_PED_ID();
	if (PED::IS_PED_IN_ANY_VEHICLE(Handle, 0))
		Handle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
	ENTITY::SET_ENTITY_COORDS_NO_OFFSET(Handle, Coords.x, Coords.y, Coords.z, 0, 0, 1);
	DoFX("scr_rcbarry2", "scr_exp_clown");//FLOR COM ROSAS

}
void above4m()
{
	Vector3 Coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 0.00, 4.0);
	int Handle = PLAYER::PLAYER_PED_ID();
	if (PED::IS_PED_IN_ANY_VEHICLE(Handle, 0))
		Handle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
	ENTITY::SET_ENTITY_COORDS_NO_OFFSET(Handle, Coords.x, Coords.y, Coords.z, 0, 0, 1);
	DoFX("scr_rcbarry2", "scr_exp_clown");//FLOR COM ROSAS

}
void above6m()
{
	Vector3 Coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 0.00, 6.0);
	int Handle = PLAYER::PLAYER_PED_ID();
	if (PED::IS_PED_IN_ANY_VEHICLE(Handle, 0))
		Handle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
	ENTITY::SET_ENTITY_COORDS_NO_OFFSET(Handle, Coords.x, Coords.y, Coords.z, 0, 0, 1);
	DoFX("scr_rcbarry2", "scr_exp_clown");//FLOR COM ROSAS

}
void above8m()
{
	Vector3 Coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 0.00, 8.0);
	int Handle = PLAYER::PLAYER_PED_ID();
	if (PED::IS_PED_IN_ANY_VEHICLE(Handle, 0))
		Handle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
	ENTITY::SET_ENTITY_COORDS_NO_OFFSET(Handle, Coords.x, Coords.y, Coords.z, 0, 0, 1);
	DoFX("scr_rcbarry2", "scr_exp_clown");//FLOR COM ROSAS

}
void above10m()
{
	Vector3 Coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 0.00, 10.0);
	int Handle = PLAYER::PLAYER_PED_ID();
	if (PED::IS_PED_IN_ANY_VEHICLE(Handle, 0))
		Handle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
	ENTITY::SET_ENTITY_COORDS_NO_OFFSET(Handle, Coords.x, Coords.y, Coords.z, 0, 0, 1);
	DoFX("scr_rcbarry2", "scr_exp_clown");//FLOR COM ROSAS

}
void forward2m()
{
	Vector3 Coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 2.0, 0.0);
	int Handle = PLAYER::PLAYER_PED_ID();
	if (PED::IS_PED_IN_ANY_VEHICLE(Handle, 0))
		Handle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
	ENTITY::SET_ENTITY_COORDS_NO_OFFSET(Handle, Coords.x, Coords.y, Coords.z, 0, 0, 1);
	DoFX("scr_rcbarry2", "scr_exp_clown");//FLOR COM ROSAS

}
void forward4m()
{
	Vector3 Coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 4.0, 0.0);
	int Handle = PLAYER::PLAYER_PED_ID();
	if (PED::IS_PED_IN_ANY_VEHICLE(Handle, 0))
		Handle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
	ENTITY::SET_ENTITY_COORDS_NO_OFFSET(Handle, Coords.x, Coords.y, Coords.z, 0, 0, 1);
	DoFX("scr_rcbarry2", "scr_exp_clown");//FLOR COM ROSAS

}
void forward6m()
{
	Vector3 Coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 6.0, 0.0);
	int Handle = PLAYER::PLAYER_PED_ID();
	if (PED::IS_PED_IN_ANY_VEHICLE(Handle, 0))
		Handle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
	ENTITY::SET_ENTITY_COORDS_NO_OFFSET(Handle, Coords.x, Coords.y, Coords.z, 0, 0, 1);
	DoFX("scr_rcbarry2", "scr_exp_clown");//FLOR COM ROSAS

}
void forward8m()
{
	Vector3 Coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 8.0, 0.0);
	int Handle = PLAYER::PLAYER_PED_ID();
	if (PED::IS_PED_IN_ANY_VEHICLE(Handle, 0))
		Handle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
	ENTITY::SET_ENTITY_COORDS_NO_OFFSET(Handle, Coords.x, Coords.y, Coords.z, 0, 0, 1);
	DoFX("scr_rcbarry2", "scr_exp_clown");//FLOR COM ROSAS

}
void forward10m()
{
	Vector3 Coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 10.0, 0.0);
	int Handle = PLAYER::PLAYER_PED_ID();
	if (PED::IS_PED_IN_ANY_VEHICLE(Handle, 0))
		Handle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
	ENTITY::SET_ENTITY_COORDS_NO_OFFSET(Handle, Coords.x, Coords.y, Coords.z, 0, 0, 1);
	DoFX("scr_rcbarry2", "scr_exp_clown");//FLOR COM ROSAS

}

void spawnCarOption(char *option, char *model)//, char *notification)
{
	addOption(option);
	if (currentOption == optionCount && optionPress)
	{
		hash_veh = GAMEPLAY::GET_HASH_KEY(model);
		SpawnVehicle = true;
	}
}
void addVehOption(char *option, char *model, char *info = NULL)//
{
	addOption(option);
	if (currentOption == optionCount && optionPress)
	{
		//CREATE_VEHL(model);
		hash_veh = GAMEPLAY::GET_HASH_KEY(model);
		SpawnVehicle = true;
		DoFX("scr_rcbarry2", "scr_clown_appears");
		drawNotification("~y~Vehicle Spawneed !");
	}
}
void addVehOption1(char *option, char *model, char *info = NULL)
{
	addOption(option);
	if (currentOption == optionCount && optionPress)
	{
		//CREATE_VEHL(model);
		hash_veh = GAMEPLAY::GET_HASH_KEY(model);
		SpawnVehicle = true;
		DoFX("scr_agencyheist", "scr_fbi_dd_breach_smoke"); //fogo spawn //innovation 
		DoFX("des_fib_floor", "ent_ray_fbi5a_ramp_metal_imp");
		drawNotification("~y~Vehicle Spawneed !");
	}
}
bool RequestNetworkControl(uint vehID)
{
	int Tries = 0;
	bool
		hasControl = false,
		giveUp = false;
	do
	{
		hasControl = NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(vehID);
		Tries++;
		if (Tries > 300)
			giveUp = true;
	} while (!hasControl && !giveUp);

	if (giveUp)
		return false;
	else return true;
}
void VehGmode()
{
	vgmode_ = !vgmode_;
	int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
	RequestNetworkControl(VehID);
	if (vgmode_ = false)
	{
		ENTITY::SET_ENTITY_INVINCIBLE(VehID, false);
	}
	else if (vgmode_ == true)
	{
		ENTITY::SET_ENTITY_INVINCIBLE(VehID, true);
	}
}
void PaintVehRan()
{
	int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
	NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(VehID);
	if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(VehID))
	{
		VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(VehID, GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255));
		VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(VehID, GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255));
	}
}
void vehlower()
{
	int ped = PLAYER::PLAYER_PED_ID();
	int veh = PED::GET_VEHICLE_PED_IS_IN(ped, true);
	if (PED::IS_PED_IN_VEHICLE(ped, veh, true))
	{
		ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, 0, 0, -0.2, 0, 0, 0, 1, false, true, true, true, true);
	}
}
void changeplate(int platetype)
{
	VEHICLE::SET_VEHICLE_MOD_KIT(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 0);
	VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), platetype);
}
void PaintCustom(int r, int g, int b)
{
	int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
	NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(VehID);
	if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(VehID))
	{
		VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(VehID, r, g, b);
		VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(VehID, r, g, b);
	}
}
bool Neons_;
int NeonR = 0, NeonG = 0, NeonB = 0;
void addNeonsOption(char *option, int R, int G, int B)
{
	addOption(option);
	if (currentOption == optionCount && optionPress)
	{
		NeonR = R;
		NeonG = G;
		NeonB = B;
	}
}
bool pimpin;
void  LowRider()
{
	int LeftRight = CONTROLS::GET_CONTROL_VALUE(0, 188);
	int UpDown = CONTROLS::GET_CONTROL_VALUE(0, 189);
	int VehicleHandle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
	if (VEHICLE::IS_VEHICLE_ON_ALL_WHEELS(VehicleHandle))
	{
		if (UpDown == 254)
		{
			ENTITY::APPLY_FORCE_TO_ENTITY(VehicleHandle, 1, 0, 0, 0.078, 0, 3.05, 0, 1, 1, 1, 1, 0, 1);
		}
		if (UpDown == 0)
		{
			ENTITY::APPLY_FORCE_TO_ENTITY(VehicleHandle, 1, 0, 0, 0.078, 0, -3.05, 0, 1, 1, 1, 1, 0, 1);
		}
		if (LeftRight == 254)
		{
			ENTITY::APPLY_FORCE_TO_ENTITY(VehicleHandle, 1, 0, 0, 0.23, 0.98, 0, 0, 1, 1, 1, 1, 0, 1);
		}
		if (LeftRight == 0)
		{
			ENTITY::APPLY_FORCE_TO_ENTITY(VehicleHandle, 1, 0, 0, 0.23, -0.98, 0, 0, 1, 1, 1, 1, 0, 1);
		}
	}
}
bool WheelieCar = false;
float EINS = 0.05;
float ZWEI = 1.3;
bool Wiiili;
void WWiiiliCar()
{
	if (!Wiiili) {
		Wiiili = true;
	}
	else {
		Wiiili = false;
	}
}
void drawSpeedo(char* Text)
{
	UI::SET_TEXT_FONT(4);
	UI::SET_TEXT_SCALE(0.780, 0.780);
	UI::SET_TEXT_COLOUR(255, 255, 255, 255);
	UI::SET_TEXT_OUTLINE();
	UI::SET_TEXT_WRAP(0, 1);
	UI::SET_TEXT_CENTRE(1);
	UI::_SET_TEXT_ENTRY("STRING");
	UI::_ADD_TEXT_COMPONENT_STRING(Text);
	UI::_DRAW_TEXT(0.140 + 0.138f, 0.930 - 0.055f);
}


int SpawnedObjects_;
char *ObjectModel;
bool _ObjectModel;
void DeleteEntity(int Handle)
{
	NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(Handle);
	ENTITY::SET_ENTITY_AS_MISSION_ENTITY(Handle, 1, 1);
	ENTITY::DELETE_ENTITY(&Handle);
}
bool SpawnWheel()
{
	int ObjectName = GAMEPLAY::GET_HASH_KEY("prop_ld_ferris_wheel");
	if (STREAMING::IS_MODEL_IN_CDIMAGE(ObjectName))
	{
		if (STREAMING::IS_MODEL_VALID(ObjectName))
		{
			STREAMING::REQUEST_MODEL(ObjectName);
			Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
			if (STREAMING::HAS_MODEL_LOADED(ObjectName))
			{
				FerrisWheele = OBJECT::CREATE_OBJECT(ObjectName, coords.x, coords.y, coords.z, 1, 0, 1);
				if (ENTITY::DOES_ENTITY_EXIST(FerrisWheele))
				{
					Vector3 Me = ENTITY::GET_ENTITY_COORDS(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), 1);
					ENTITY::SET_ENTITY_COORDS(FerrisWheele, Me.x, Me.y, AirHeigt, 1, 0, 0, 1);
					ENTITY::SET_ENTITY_ROTATION(FerrisWheele, 180, 90, 180, 2, 1);
					ENTITY::SET_ENTITY_VISIBLE(FerrisWheele, false);
					ENTITY::SET_ENTITY_ALPHA(FerrisWheele, 0, 0);
					ENTITY::FREEZE_ENTITY_POSITION(FerrisWheele, true);
					if (!MeinCodewat)
						ENTITY::SET_ENTITY_COORDS(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), Me.x, Me.y, AirHeigt + 2, 1, 0, 0, 1);
					Zusatz = true;
					return true;
				}
				else return false;
			}
			else return false;
		}
	}
}
void DriveAir()
{
	if (!MeinCode)
	{
		AirHeigt = 360;
		MeinCode = true;
		Spanlllll = true;
		MeinCodewat = false;
	}
	else
	{
		MeinCode = false;
		Zusatz = false;
		DeleteEntity(FerrisWheele);
	}
}
void DriveWater()
{
	if (!MeinCodewat)
	{
		MeinCodewat = true;
		AirHeigt = -1.6;
		Spanlllll = true;
		MeinCode = false;
	}
	else
	{
		MeinCodewat = false;
		Zusatz = false;
		DeleteEntity(FerrisWheele);
	}
}
#pragma endregion
#pragma region
bool cstrcmp(const char* s1, const char* s2)
{
	while (*s1 && (*s1 == *s2))
		s1++, s2++;
	if (*(const unsigned char*)s1 - *(const unsigned char*)s2 == 0)
		return true;
	else
		return false;
}
#pragma endregion
#pragma region Models+Outfits

int fam;
void changeAppearance(char* family, int model, int texture)
{
	if (cstrcmp(family, "HATS") || cstrcmp(family, "GLASSES") || cstrcmp(family, "EARS"))
	{
		if (cstrcmp(family, "HATS"))
			fam = 0;
		else if (cstrcmp(family, "GLASSES"))
			fam = 1;
		else if (cstrcmp(family, "EARS"))
			fam = 2;
		PED::SET_PED_PROP_INDEX(PLAYER::PLAYER_PED_ID(), fam, model - 1, texture, 1);
	}
	else
	{
		if (cstrcmp(family, "FACE"))
			fam = 0;
		else if (cstrcmp(family, "MASK"))
			fam = 1;
		else if (cstrcmp(family, "HAIR"))
			fam = 2;
		else if (cstrcmp(family, "TORSO"))
			fam = 3;
		else if (cstrcmp(family, "LEGS"))
			fam = 4;
		else if (cstrcmp(family, "HANDS"))
			fam = 5;
		else if (cstrcmp(family, "SHOES"))
			fam = 6;
		else if (cstrcmp(family, "SPECIAL1"))
			fam = 7;
		else if (cstrcmp(family, "SPECIAL2"))
			fam = 8;
		else if (cstrcmp(family, "SPECIAL3"))
			fam = 9;
		else if (cstrcmp(family, "TEXTURE"))
			fam = 10;
		else if (cstrcmp(family, "TORSO2"))
			fam = 11;
		PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), fam, model, texture, 0);
	}
}
void ResetAppearance()
{
	PED::CLEAR_ALL_PED_PROPS(PLAYER::PLAYER_PED_ID());
	PED::CLEAR_PED_DECORATIONS(PLAYER::PLAYER_PED_ID());
	PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 1, 0, 0, 0);
	PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 5, 0, 0, 0);
	PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 9, 0, 0, 0);
}
#pragma endregion
#pragma region
int Face_ = 0;
int Glasses_ = 0;
int Ears_ = 0;
int Mask_ = 0;
int Hair_ = 0;
int Torso_ = 0;
int Legs_ = 0;
int Hands_ = 0;
int Shoes_ = 0;
int Watches_ = 0;
int Special1_ = 0;
int Special2_ = 0;
int Special3_ = 0;
int Texture_ = 0;
int Torso2_ = 0;
bool walldrive_ = false;
#pragma endregion
#pragma region
void walldrive()
{
	int ped = PLAYER::PLAYER_PED_ID();
	int veh = PED::GET_VEHICLE_PED_IS_IN(ped, true);
	if (PED::IS_PED_IN_VEHICLE(ped, veh, true))
	{
		ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, 0, 0, -0.1, 0, 0, 0, 1, true, true, true, true, true);
	}
}
Ped PlayerSelf()
{
	return PLAYER::PLAYER_PED_ID();
}
void UsePhone(int phone)
{
	MOBILE::SET_MOBILE_PHONE_SCALE(450);
	MOBILE::SET_MOBILE_PHONE_POSITION(70, 30, 2);
	MOBILE::CREATE_MOBILE_PHONE(phone);
	AI::TASK_USE_MOBILE_PHONE(PlayerSelf(), 1);
}
void CreatePhone(int phone)
{
	MOBILE::SET_MOBILE_PHONE_SCALE(450);
	MOBILE::SET_MOBILE_PHONE_POSITION(70, 30, 2);
	MOBILE::CREATE_MOBILE_PHONE(phone);
}
void DestroyPhone(int phone)
{
	MOBILE::DESTROY_MOBILE_PHONE();
}
void spawnobject(const char* objectname)
{
	Vector3 mycoords;
	mycoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	int obj = GAMEPLAY::GET_HASH_KEY2(objectname);
	OBJECT::CREATE_OBJECT(obj, mycoords.x, mycoords.y, mycoords.z, 1, 1, 0);
}
bool Write_Global(int a_uiGlobalID, int a_uiValue)
{
	int Ptr = *(int*)((0x1E70374 - 0x04) + (((a_uiGlobalID / 0x40000) & 0x3F) * 4));
	if (Ptr != 0)
	{
		*(int*)(Ptr + ((a_uiGlobalID % 0x40000) * 4)) = a_uiValue;
		return true;
	}
	return false;
}
bool revealPeople;
void RevealPlayers()
{
	if (!revealPeople)
	{
		revealPeople = true;
		Write_Global(2394218 + 56, 2147483647);
		Write_Global(2390201 + PLAYER::PLAYER_ID() * 223 + 172, 1);
	}
	else
	{
		revealPeople = false;
		Write_Global(2390201 + PLAYER::PLAYER_ID() * 223 + 172, 0);
	}
}


int FOVCu = 0;
bool fPerson;
void FirstPerson()
{
	if (!fPerson)
	{
		fPerson = true;
		FPCam = CAM::CREATE_CAMERA(26379945, false);
		CAM::ATTACH_CAM_TO_PED_BONE(FPCam, PLAYER::PLAYER_PED_ID(), Head, 0, 0, 0, false);
		CAM::SET_CAM_NEAR_CLIP(FPCam, 0.225f);
		CAM::SET_CAM_ACTIVE(FPCam, true);
		CAM::RENDER_SCRIPT_CAMS(1, 0, 3000, 1, 0);
	}
	else
	{
		fPerson = false;
		CAM::DESTROY_CAM(FPCam, 0);
		CAM::RENDER_SCRIPT_CAMS(0, 0, 3000, 1, 0);
		FPCam = 0;
	}
}
void addKeyboardOption(char *option, int action, char *defaultText, int maxLength, char *info = NULL)
{
	addOption(option, info);
	if (currentOption == optionCount)
	{
		//xInstruction = true;
		if (optionPress)
			startKeyboard(action, defaultText, maxLength);
	}
}
#pragma endregion

#pragma region Functions

bool firstopenmenu = false;
#pragma endregion
#pragma region
int getOption()
{
	xInstruction = true;
	if (optionPress)
		return currentOption;
	else return 0;
}
void monitorButtons()
{
	SetupTimer(20);
	if (submenu == Closed)
	{
		if (IsTimerReady())
		{
			if (CONTROLS::IS_CONTROL_PRESSED(0, Button_R1) && CONTROLS::IS_CONTROL_PRESSED(0, Dpad_Left))
			{
				submenu = Main_Menu;
				submenuLevel = 0;
				currentOption = 1;
				playSound("YES");

				if (firstopenmenu == false)//version menu
				{
					drawNotification("~h~Welcome To The Umbrella 3.1 ! \n ~h~Menu Created by: ~y~WEB H4CKER");
					firstopenmenu = true;
				}
			}
			ResetTimer();
		}
	}
	else {
		if (IsTimerReady())
		{
			if (CONTROLS::IS_CONTROL_JUST_PRESSED(0, Button_B))
			{
				if (submenu == Main_Menu)
				{
					submenu = Closed;
				}
				else {
					submenu = lastSubmenu[submenuLevel - 1];
					currentOption = lastOption[submenuLevel - 1];
					submenuLevel--;
				}
				playSound("Back");
			}
			else if (CONTROLS::IS_CONTROL_JUST_PRESSED(0, Button_A))
			{
				optionPress = true;
				playSound("SELECT");
			}
			else if (CONTROLS::IS_CONTROL_JUST_PRESSED(0, Dpad_Up))
			{
				currentOption--;
				if (currentOption < 1)
				{
					currentOption = optionCount;
				}
				playSound("NAV_UP_DOWN");
			}
			else if (CONTROLS::IS_CONTROL_JUST_PRESSED(0, Dpad_Down))
			{
				currentOption++;
				if (currentOption > optionCount)
				{
					currentOption = 1;
				}
				playSound("NAV_UP_DOWN");
			}
			else if (CONTROLS::IS_CONTROL_JUST_PRESSED(0, Dpad_Right))
			{
				rightPress = true;
			}
			else if (CONTROLS::IS_CONTROL_JUST_PRESSED(0, Dpad_Left))
			{
				leftPress = true;
			}
			else if (CONTROLS::IS_CONTROL_PRESSED(0, Dpad_Right))
			{
				fastRightPress = true;
			}
			else if (CONTROLS::IS_CONTROL_PRESSED(0, Dpad_Left))
			{
				fastLeftPress = true;
			}
			else if (CONTROLS::IS_CONTROL_JUST_PRESSED(0, Button_X))
			{
				squarePress = true;
			}
			ResetTimer();
		}
	}
}
void drawTextinfo(char * text, int font, float x, float y, float scalex, float scaley, int r, int b, int g, int a, bool center)
{
	UI::SET_TEXT_FONT(0);
	UI::SET_TEXT_SCALE(scalex, scaley);
	UI::SET_TEXT_COLOUR(r, g, b, a);
	UI::SET_TEXT_WRAP(0.0f, 1.0f);
	UI::SET_TEXT_CENTRE(center);
	UI::SET_TEXT_OUTLINE();
	UI::_SET_TEXT_ENTRY("STRING");
	UI::_ADD_TEXT_COMPONENT_STRING(text);
	UI::_DRAW_TEXT(x, y);
}
float titlebox3 = 0.319f;//0.319
float
UpDown = .1370f, //1680//1370//
SpriteWidht = .3225f;
int normalMenuActions()
{
	UI::HIDE_HELP_TEXT_THIS_FRAME();
	CAM::SET_CINEMATIC_BUTTON_ACTIVE(0);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(6);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(7);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(9);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(8);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 19);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 20);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 21);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 27);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 54);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 123);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 124);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 125);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 126);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 138);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 139);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 140);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 177);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 178);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 179);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 207);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 166);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 167);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 177);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 178);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 193);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 194);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 195);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 202);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 203);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 204);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 205);
	if (strcmp(SCRIPT::GET_THIS_SCRIPT_NAME(), "ingamehud") == 0)
	{
		titleText("  The Umbrella", bannerTextFont, menuXCoord, 0.095f, 1.2f, 1.2f, 255, 255, 255, 255, true); // Banner Title
		if (optionCount > maxOptions)
		{

			GRAPHICS::DRAW_RECT(menuXCoord, 0.135f, MenuWidth, 0.098f, bannerRectRed, bannerRectGreen, bannerRectBlue, bannerRectOpacity); // Banner
			GRAPHICS::DRAW_RECT(menuXCoord, 0.198f, MenuWidth, 0.035f, 0, 0, 0, 180); // Sub Info
			GRAPHICS::DRAW_RECT(menuXCoord, (((maxOptions * 0.035f) / 2) + 0.215f), MenuWidth, (maxOptions * 0.035f), backgroundRed, backgroundGreen, backgroundBlue, backgroundOpacity); // Background
			if (currentOption > maxOptions)
			{
				GRAPHICS::DRAW_RECT(menuXCoord, ((maxOptions * 0.035f) + 0.197f), MenuWidth, 0.035f, scrollerRed, scrollerGreen, scrollerBlue, scrollerOpacity); // Scroller
			}
			else
			{
				GRAPHICS::DRAW_RECT(menuXCoord, ((currentOption * 0.035f) + 0.197f), MenuWidth, 0.035f, scrollerRed, scrollerGreen, scrollerBlue, scrollerOpacity); // Scroller
			}
		}
		else
		{
			GRAPHICS::DRAW_RECT(menuXCoord, 0.135f, MenuWidth, 0.098f, bannerRectRed, bannerRectGreen, bannerRectBlue, bannerRectOpacity); // Banner
			GRAPHICS::DRAW_RECT(menuXCoord, 0.198f, MenuWidth, 0.035f, 0, 0, 0, 180); // Sub Info
			GRAPHICS::DRAW_RECT(menuXCoord, (((optionCount * 0.035f) / 2) + 0.215f), MenuWidth, (optionCount * 0.035f), backgroundRed, backgroundGreen, backgroundBlue, backgroundOpacity); // Background
			GRAPHICS::DRAW_RECT(menuXCoord, ((currentOption * 0.035f) + 0.197f), MenuWidth, 0.035f, scrollerRed, scrollerGreen, scrollerBlue, scrollerOpacity); // Scroller
		}
		if (TheInfoBox)
		{
		ViewInfo(selectedPlayer);
		}
	}
	{
		char buf[30];
		snprintf(buf, sizeof(buf), "%i / %i", currentOption, optionCount);
		drawTextinfo(buf, 0, titlebox3, UpDown + .050f, 0.35f, 0.35f, bannerTextRed, bannerTextGreen, bannerTextBlue, bannerTextOpacity, true);

		//DrawSprite("commonmenu", "shop_arrows_upanddown", 0.845f, (((10 + 1) * 0.035f) + UpDown + .0645), 0.02, 0.045, 0, 255, 255, 255, 255);//0.6610
	}
	SetupTimer2(20);
	if (instructions)
	{
		if (IsTimerReady2())
		{
			if (xInstruction)
				addInstruction(BUTTON_A, "Select");
			if (squareInstruction)
				addInstruction(BUTTON_X, "Keyboard");
			if (lrInstruction)
				addInstruction(BUTTON_DPAD_LEFT_RIGHT, "Scroll");
			addInstruction(BUTTON_DPAD_UP_DOWN, "Scroll");
			addInstruction(BUTTON_B, "Back");
			instructionsClose();
			ResetTimer2();
		}
		drawGlare();
	}
}
#pragma endregion
#pragma region
void GiveWeapons()
{
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0x3656C8C1, 9999, 1); // stun gun
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0x99B507EA, 9999, 1); // knife
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0x678B81B1, 9999, 1); // night stick
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0x4E875F73, 9999, 1); // hammer
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0x958A4A8F, 9999, 1); // bat
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0x440E4788, 9999, 1); // golf club
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0x84BD7BFD, 9999, 1); // crowbar
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0x1B06D571, 9999, 1); // pistol
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0x5EF9FEC4, 9999, 1); // combat pistol
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0x22D8FE39, 9999, 1); // ap pistol
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0x99AEEB3B, 9999, 1); // pistol 50.
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0x13532244, 9999, 1); // micro smg
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0x2BE6766B, 9999, 1); // smg
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0xEFE7E2DF, 9999, 1); // assault smg
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0xBFEFFF6D, 9999, 1); // assault rifle
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0x83BF0278, 9999, 1); // carbine rifle
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0xAF113F99, 9999, 1); // advanced rifle
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0x9D07F764, 9999, 1); // MG
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0x7FD62962, 9999, 1); // combat mg
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0x1D073A89, 9999, 1); // pump shotgun
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0x7846A318, 9999, 1); // sawnoff shotgun
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0xE284C527, 9999, 1); // assault shotgun
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0x9D61E50F, 9999, 1); // bullpupshotgun
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0x05FC3C11, 9999, 1); // sniper
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0x0C472FE2, 9999, 1); // heavy sniper
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0xA284510B, 9999, 1); // grenade launcher
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0xB1CA77B1, 9999, 1); // rpg
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0x42BF8A85, 9999, 1); // minigun
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0x93E220BD, 9999, 1); // grenades
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0x2C3731D9, 9999, 1); // sticky bomb
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0xFDBC8A50, 9999, 1); // smoke grenade
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0x34A67B97, 9999, 1); // petrol can
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0x060EC506, 9999, 1); // fire extinguisher
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0x24B17070, 9999, 1); // moltovs
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0x497FACC3, 9999, 1); // flare
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0xFDBADCED, 9999, 1); // digiscanner
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0x687652CE, 9999, 1); // stinger
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 600439132, 9999, 1); // ball
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0xF9E6AA4B, 9999, 1);
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0x61012683, 9999, 1);
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0xC0A3098D, 9999, 1);
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0xD205520E, 9999, 1);
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0xBFD21232, 9999, 1);
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0x7F229F94, 9999, 1);
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0x92A27487, 9999, 1);
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0x083839C4, 9999, 1);
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0x7F7497E5, 9999, 1);
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0xA89CB99E, 9999, 1);
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0x3AABBBAA, 9999, 1);
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0xC734385A, 9999, 1);
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0x787F0BB, 9999, 1);
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0x47757124, 9999, 1);
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0xD04C944D, 9999, 1);
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0x33058E22, 9999, 1);
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0x4DD2DC56, 9999, 1);
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0x23C9F95C, 9999, 1);
}
void BoostGun()
{
	int Target = 0;
	float Speed = 100;
	if (PLAYER::_GET_AIMED_ENTITY(PLAYER::PLAYER_ID(), &Target))
	{
		if (PED::IS_PED_SHOOTING(PLAYER::PLAYER_PED_ID()))
		{
			if (ENTITY::IS_ENTITY_A_PED(Target))
			{
				if (PED::IS_PED_IN_ANY_VEHICLE(Target, false))
				{
					Target = PED::GET_VEHICLE_PED_IS_IN(Target, false);
				}
			}
			if (ENTITY::IS_ENTITY_A_VEHICLE(Target))
			{
				VEHICLE::SET_VEHICLE_FORWARD_SPEED(Target, Speed);
			}
		}
	}
}
void changenae(const char *newname = "")
{
	strncpy((char*)0x41143344, newname, strlen(newname));
	*(char*)(0x41143344 + strlen(newname)) = 0;
	strncpy((char*)0x01FF248C, newname, strlen(newname));
	*(char*)(0x01FF248C + strlen(newname)) = 0;
}
void sendText(int player, char *text, int font)
{
	if (player == PLAYER::PLAYER_ID())
	{
		UI::SET_TEXT_FONT(font);
		UI::_0x574EE85C("STRING");
		UI::_ADD_TEXT_COMPONENT_STRING(text);
		UI::_DRAW_NOTIFICATION(false, true);
	}
	else
	{
		int NetHandleBuffer = 0x10070200;
		NETWORK::NETWORK_HANDLE_FROM_PLAYER(player, NetHandleBuffer, 13);
		NETWORK::NETWORK_SEND_TEXT_MESSAGE(text, NetHandleBuffer);
	}
}
void PRINT(char *text, int font)
{
	UI::SET_TEXT_FONT(font);
	UI::_0x574EE85C("STRING");
	UI::_ADD_TEXT_COMPONENT_STRING(text);
	UI::_DRAW_NOTIFICATION(false, true);
}
bool KEYBOARD_PROMPT = false;
int KeyboardIndex = 0;
void doKeyboardFunc(char* Result, int KBIndex, int Client)
{
	char buf[100];
	switch (KBIndex)
	{
	case 0: PRINT(Result, 2000); break;// looks right idk whats wrong maybe your functio.
	case 1: sendText(PLAYER::GET_PLAYER_PED(selectedPlayer), Result, 0); break;
	case 2:	changenae(Result); break;
	}
	KeyboardIndex = 0;// y
}
bool RagDoll = false;
void RagDollOn()
{
	int Ped = PLAYER::PLAYER_PED_ID();
	if (RagDoll == false)
	{
		PED::SET_PED_CAN_BE_DRAGGED_OUT(PLAYER::PLAYER_ID(), false);
		PED::SET_PED_CAN_RAGDOLL(Ped, false);
		PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(Ped, false);
		PLAYER::SET_PLAYER_INVINCIBLE(PLAYER::PLAYER_ID(), true);
		ENTITY::SET_ENTITY_INVINCIBLE(Ped, true);
		PED::SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(Ped, false);
		PLAYER::GIVE_PLAYER_RAGDOLL_CONTROL(Ped, true);
		PED::SET_PED_RAGDOLL_ON_COLLISION(Ped, false);
		RagDoll = true;
	}
	else
	{
		PED::SET_PED_CAN_BE_DRAGGED_OUT(PLAYER::PLAYER_ID(), true);
		PED::SET_PED_CAN_RAGDOLL(Ped, true);
		PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(Ped, true);
		PLAYER::GET_PLAYER_INVINCIBLE(PLAYER::PLAYER_ID());
		ENTITY::SET_ENTITY_INVINCIBLE(Ped, false);
		PED::SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(Ped, true);
		PLAYER::GIVE_PLAYER_RAGDOLL_CONTROL(Ped, false);
		PED::SET_PED_RAGDOLL_ON_COLLISION(Ped, true);
		RagDoll = false;
	}
}
void RainbowGun()
{
	Hash WeapHash;
	WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
	WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, GAMEPLAY::GET_RANDOM_INT_IN_RANGE(-1, 8));
}
void Maxupgrade(int VehicleHandle)
{
	VEHICLE::SET_VEHICLE_MOD_KIT(VehicleHandle, 0);
	VEHICLE::SET_VEHICLE_COLOURS(VehicleHandle, 120, 120);
	VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(VehicleHandle, "WEB HACKER");
	VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(VehicleHandle, 1);;
	VEHICLE::TOGGLE_VEHICLE_MOD(VehicleHandle, 18, 1);
	VEHICLE::TOGGLE_VEHICLE_MOD(VehicleHandle, 22, 1);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 16, 5, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 12, 2, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 11, 3, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 14, 14, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 15, 3, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 13, 2, 0);
	VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehicleHandle, 2);
	VEHICLE::SET_VEHICLE_WINDOW_TINT(VehicleHandle, 5);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 23, 18, 1);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 0, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 1, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 2, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 3, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 4, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 5, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 6, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 7, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 8, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 9, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 10, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 16, 4, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 3, 0, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 16, 4, 0);
}
void TeleportToLoc(float x, float y, float z)
{
	if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
	{
		int vehid = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		ENTITY::SET_ENTITY_COORDS_TP(vehid, x, y, z, 1, 0, 0, 1);
		DoFX("scr_rcbarry2", "scr_clown_appears");
		DoFX("scr_trevor1", "scr_trev1_trailer_boosh");
	}
	else
	{
		ENTITY::SET_ENTITY_COORDS_TP(PLAYER::PLAYER_PED_ID(), x, y, z, 1, 0, 0, 1);
		DoFX("scr_rcbarry2", "scr_clown_appears");
		DoFX("scr_trevor1", "scr_trev1_trailer_boosh");
	}
}
void TeleportToPLayer(int client)
{
	if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
	{
		Vector3 Coords12 = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(client), 1);
		int vehid = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		ENTITY::SET_ENTITY_COORDS(vehid, Coords12.x, Coords12.y, Coords12.z, 1, 0, 0, 1);
		DoFX("scr_rcbarry2", "scr_clown_appears");
	}
	else
	{
		Vector3 Coords12 = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(client), 1);
		ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), Coords12.x, Coords12.y, Coords12.z, 1, 0, 0, 1);
		DoFX("scr_rcbarry2", "scr_clown_appears");
	}
}
void ToNearestCar()
{
	Vector3 Coords16 = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	int VehID = VEHICLE::GET_CLOSEST_VEHICLE(Coords16.x, Coords16.y, Coords16.z, 150.0, 0, 71);
	PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), VehID, -1);
}
void TeleportTo(int PedHandle, float X, float Y, float Z) {
	if (PED::IS_PED_IN_ANY_VEHICLE(PedHandle, 0)) {
		int Vehhandle = PED::GET_VEHICLE_PED_IS_IN(PedHandle, 0);
		ENTITY::SET_ENTITY_COORDS(Vehhandle, X, Y, Z, 0, 0, 0, 1);
		ENTITY::SET_ENTITY_ALPHA(Vehhandle, 255, 0);
	}
}
void SpectatePlayer(Ped playerped)
{
	Any SpectateCam;
	Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS1(playerped, false);
	SpectateCam = CAM::CREATE_CAM_WITH_PARAMS("DEFAULT_SCRIPTED_FLY_CAMERA", playerPosition.x, playerPosition.y, playerPosition.z, 0.0, 0.0, 0.0, 50.0, 0, 2);
	CAM::ATTACH_CAM_TO_ENTITY(SpectateCam, playerped, 0, -5, 1, 1);
	CAM::SET_CAM_ACTIVE(playerped, 1);
}
void SpectateMode(bool Active, Ped selectedPed)
{
	NETWORK::NETWORK_SET_IN_SPECTATOR_MODE(Active, selectedPed);
}
void GiveMoneyGun()
{
	if (PED::IS_PED_SHOOTING(PLAYER::GET_PLAYER_PED(selectedPlayer)))
	{
		float Loc[3];
		if (__GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::GET_PLAYER_PED(selectedPlayer), Loc))
		{
			Vector3 Pos;
			Pos.x = Loc[0]; Pos.y = Loc[1]; Pos.z = Loc[2];
			STREAMING::REQUEST_MODEL(0x113FD533);
			if (STREAMING::HAS_MODEL_LOADED(0x113FD533) == 1)
			{
				OBJECT::CREATE_AMBIENT_PICKUP(0xCE6FDD6B, Pos.x, Pos.y, Pos.z, 0, 40000, 0x113FD533, 0, 1);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(0x113FD533);
			}
		}

	}
}
void ExplodePlayer(int PedHandle)
{
	Vector3 Pos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(PedHandle), true);
	FIRE::ADD_EXPLOSION(Pos.x, Pos.y, Pos.z, 29, 0.5f, true, false, 5.0f);
}
char *dict = "oddjobs@bailbond_mountain";
char *anim = "excited_idle_c";
//char *dict = "mp_am_hold_up";
//char *anim = "handsup_base";

void teleportToMeFoot(int player)// 
{
	int targ_ped = PLAYER::GET_PLAYER_PED(player);
	STREAMING::REQUEST_ANIM_DICT(dict);
	if (STREAMING::HAS_ANIM_DICT_LOADED(dict))
	{
		Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
		int sceneID = NETWORK::NETWORK_CREATE_SYNCHRONISED_SCENE(coords.x, coords.y, coords.z, 0, 0, 0, 2, 0, 1, 1.0f, 0.0f, 1.0f);
		NETWORK::NETWORK_ADD_PED_TO_SYNCHRONISED_SCENE(targ_ped, sceneID, dict, anim, 1000, -1000, 269, 0, 1000, 1);
		NETWORK::NETWORK_START_SYNCHRONISED_SCENE(sceneID);
		DoFX("scr_rcbarry1", "scr_alien_disintegrate");
		DoFX("scr_rcbarry1", "scr_alien_teleport");
	}
}
void TpClientOnFootLocation(char *option, char *dict, char *anim, float x, float y, float z)
{
	if (currentOption == optionCount && optionPress)
	{
		int targ_ped = PLAYER::GET_PLAYER_PED(selectedPlayer);
		STREAMING::REQUEST_ANIM_DICT(dict);
		if (STREAMING::HAS_ANIM_DICT_LOADED(dict))
		{
			int sceneID = NETWORK::NETWORK_CREATE_SYNCHRONISED_SCENE(x, y, z, 0, 0, 0, 2, 0, 1, 1.0f, 0.0f, 1.0f);
			NETWORK::NETWORK_ADD_PED_TO_SYNCHRONISED_SCENE(targ_ped, sceneID, dict, anim, 1000, -1000, 269, 0, 1000, 1);
			NETWORK::NETWORK_START_SYNCHRONISED_SCENE(sceneID);
		}
	}
}

void doAnimationP(int player, char *dict, char *anim)
{
	int targ_ped = PLAYER::GET_PLAYER_PED(player);
	STREAMING::REQUEST_ANIM_DICT(dict);
	if (STREAMING::HAS_ANIM_DICT_LOADED(dict))
	{
		Vector3 coords = ENTITY::GET_ENTITY_COORDS(targ_ped, 1);
		int sceneID = NETWORK::NETWORK_CREATE_SYNCHRONISED_SCENE(coords.x, coords.y, coords.z, 0, 0, 0, 2, 0, 1, 1.0f, 0.0f, 1.0f);
		NETWORK::NETWORK_ADD_PED_TO_SYNCHRONISED_SCENE(targ_ped, sceneID, dict, anim, 8.0f, -8.0f, 120, 0, 100, 1);
		NETWORK::NETWORK_START_SYNCHRONISED_SCENE(sceneID);
	}
}
void DoAdminations(char *option, char *dict, char* anim)
{
	addOption(option);
	if (currentOption == optionCount && optionPress)
	{
		int targ_ped = PLAYER::GET_PLAYER_PED(selectedPlayer);
		STREAMING::REQUEST_ANIM_DICT(dict);
		if (STREAMING::HAS_ANIM_DICT_LOADED(dict))
		{
			Vector3 coords = ENTITY::GET_ENTITY_COORDS(targ_ped, 1);
			int sceneID = NETWORK::NETWORK_CREATE_SYNCHRONISED_SCENE(coords.x, coords.y, coords.z, 0, 0, 0, 2, 0, 1, 1.0f, 0.0f, 1.0f);
			NETWORK::NETWORK_ADD_PED_TO_SYNCHRONISED_SCENE(targ_ped, sceneID, dict, anim, 8.0f, -8.0f, 120, 0, 100, 1);
			NETWORK::NETWORK_START_SYNCHRONISED_SCENE(sceneID);
		}
	}
}
void AnimationsForAll(char* dict, char* anim)
{
	for (int i = 0; i < 18; i++)
	{
		int targ_ped = PLAYER::GET_PLAYER_PED(i);
		Vector3 coords = ENTITY::GET_ENTITY_COORDS(targ_ped, 1);
		int sceneID = NETWORK::NETWORK_CREATE_SYNCHRONISED_SCENE(coords.x, coords.y, coords.z, 0, 0, 0, 2, 0, 1, 1.0f, 0.0f, 1.0f);
		STREAMING::REQUEST_ANIM_DICT(dict);
		if (STREAMING::HAS_ANIM_DICT_LOADED(dict))
		{
			Vector3 coords = ENTITY::GET_ENTITY_COORDS(targ_ped, 1);
			int sceneID = NETWORK::NETWORK_CREATE_SYNCHRONISED_SCENE(coords.x, coords.y, coords.z, 0, 0, 0, 2, 0, 1, 1.0f, 0.0f, 1.0f);
			NETWORK::NETWORK_ADD_PED_TO_SYNCHRONISED_SCENE(targ_ped, sceneID, dict, anim, 8.0f, -8.0f, 269, 0, 100.0f,false);
			NETWORK::NETWORK_START_SYNCHRONISED_SCENE(sceneID);
		}
	}
}
void SelectedWeapon(char *option, Hash weapon)
{
	addOption(option);
	if (currentOption == optionCount && optionPress)
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(selectedPlayer), weapon, -1, true, true);
	}
}

void MoneyBagGun()
{
	float Loc[3];
	if (PED::IS_PED_SHOOTING(PLAYER::PLAYER_PED_ID()))
	{
		if (__GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::PLAYER_PED_ID(), Loc))
		{
			Vector3 Pos;
			Pos.x = Loc[0]; Pos.y = Loc[1]; Pos.z = Loc[2];
			DrawSprite("commonmenu", "mp_specitem_cash", 0.500, 0.500, 0.0350, 0.05, 0, TkindicatorRed, TkindicatorGreen, TkindicatorBlue, TkindicatorOpacity);
			STREAMING::REQUEST_MODEL(0x113FD533);
			if (STREAMING::HAS_MODEL_LOADED(0x113FD533) == 1)
			{
				OBJECT::CREATE_AMBIENT_PICKUP(0xCE6FDD6B, Pos.x, Pos.y, Pos.z, 0, 40000, 0x113FD533, 0, 1);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(0x113FD533);
			}
		}
	}
}
bool cstrcmp1(const char* s1, const char* s2)
{
	while (*s1 && (*s1 == *s2))
		s1++, s2++;
	if (*(const unsigned char*)s1 - *(const unsigned char*)s2 == 0)
		return true;
	else
		return false;
}
void toggleAttach(int Player)
{
	if (!(cstrcmp1(PLAYER::GET_PLAYER_NAME(Player), PLAYER::GET_PLAYER_NAME(PLAYER::PLAYER_ID()))))
	{
		if (!PlayerAttached)
		{
			if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
			{
				int att = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				int player = PLAYER::GET_PLAYER_PED(Player);
				Vector3 One, Two;
				One.x = 0;
				One.y = 0;
				One.z = 0;
				Two.x = 0;
				Two.y = 0;
				Two.z = 0;
				ENTITY::ATTACH_ENTITY_TO_ENTITY(att, player, 0, One.x, One.y, One.z, Two.x, Two.y, Two.z, 0, 1, 0, 0, 2, 1);
				ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), false);
				ENTITY::SET_ENTITY_COLLISION(att, 0, 0);
			}
			else
			{
				int att = PLAYER::PLAYER_PED_ID();
				int player = PLAYER::GET_PLAYER_PED(Player);
				Vector3 One, Two;
				One.x = 0;
				One.y = -0.20;
				One.z = 0;
				Two.x = 0;
				Two.y = 0;
				Two.z = 0;
				ENTITY::ATTACH_ENTITY_TO_ENTITY(att, player, 0, One.x, One.y, One.z, Two.x, Two.y, Two.z, 0, 1, 0, 0, 2, 1);
				ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), false);
				ENTITY::SET_ENTITY_COLLISION(att, 0, 0);
			}
			PlayerAttached = true;
		}
		else
		{
			if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
			{
				int att = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				int player = PLAYER::GET_PLAYER_PED(Player);
				ENTITY::DETACH_ENTITY(att, player, 1);
				ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), true);
				ENTITY::SET_ENTITY_COLLISION(att, 1, 1);
			}
			else
			{
				int att = PLAYER::PLAYER_PED_ID();
				int player = PLAYER::GET_PLAYER_PED(Player);
				ENTITY::DETACH_ENTITY(att, player, 1);
				ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), true);
				ENTITY::SET_ENTITY_COLLISION(att, 1, 1);
			}
			PlayerAttached = false;
		}
	}
}
void HijackVehicle(int client)
{
	if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::GET_PLAYER_PED(client), 0))
	{
		AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::GET_PLAYER_PED(client));
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED(client), 0);
		VEHICLE::SET_VEHICLE_ENGINE_ON(veh, 1, 1);
		PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), veh, GET_FREE_SEAT(veh));
	}
}
void BurstSelectedPlayerTires(Ped selectedPed)
{
	if (PED::IS_PED_IN_ANY_VEHICLE(selectedPed, false))
	{
		Vehicle selectedVehicle = PED::GET_VEHICLE_PED_IS_USING(selectedPed);
		RequestNetworkControl(selectedVehicle);
		if (VEHICLE::GET_VEHICLE_TYRES_CAN_BURST(selectedVehicle))
		{
			VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(selectedVehicle, true);
		}
		static int tireID = 0;
		for (tireID = 0; tireID < 8; tireID++)
		{
			RequestNetworkControl(selectedVehicle);
			VEHICLE::SET_VEHICLE_TYRE_BURST(selectedVehicle, tireID, true, 1000.0);
		}
	}
}
void BurstSelectedPlayerTires2(Ped selectedPed)
{
	int PedHandle = PLAYER::GET_PLAYER_PED(Client);
	if (PED::IS_PED_IN_ANY_VEHICLE(PedHandle, 0))
	{
		int VehHandle = PED::GET_VEHICLE_PED_IS_IN(PedHandle, 0);
		if (NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(VehHandle))
		{
			static int tireID = 0;
			for (tireID = 0; tireID < 8; tireID++)
			{
				VEHICLE::SET_VEHICLE_TYRE_BURST(VehHandle, tireID, true, 1000.0);
			}
		}
	}
}
int GetCurrentVehicle(int ped) {
	return PED::GET_VEHICLE_PED_IS_USING(ped);
}
bool isWindowSmashed = false;
void ToggleVehicleWindowsBroken(int dummy)
{
	int player = PLAYER::GET_PLAYER_PED(Client);
	if (PED::IS_PED_IN_ANY_VEHICLE(player, true))
	{
		if (isWindowSmashed == false)
		{
			for (int i = 0; i <= 7; i++)
			{
				VEHICLE::SMASH_VEHICLE_WINDOW(GetCurrentVehicle(player), i);
			}

			isWindowSmashed == true;
		}
	}
	else
	{
		drawNotification("~r~Player is not in a vehicle");
	}
}
bool AttachDetach;
void AttachToPlayer(int me, int cli)
{
	Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(cli), true);
	if (AttachDetach == false)
	{
		ENTITY::ATTACH_ENTITY_TO_ENTITY(me, cli, 0, MyCoords.x, MyCoords.y, MyCoords.z, 0, 0, 0, 1, 1, 0, 0, 2, 1);
		drawNotification("Attached To Player");
		AttachDetach = true;
	}
	else if (AttachDetach == true)
	{
		ENTITY::DETACH_ENTITY(PLAYER::PLAYER_PED_ID(), true, true);
		drawNotification("Detched From Player");
		AttachDetach = false;
	}
}
bool AttachGuitar(int PlayerID)
{
	Vector3 PlayerCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(PlayerID), true);
	int hash = GAMEPLAY::GET_HASH_KEY("prop_acc_guitar_01");
	STREAMING::REQUEST_MODEL(hash);
	int back = PED::GET_PED_BONE_INDEX(PLAYER::GET_PLAYER_PED(PlayerID), 23553);// SKEL_Spine0
	if (STREAMING::HAS_MODEL_LOADED(hash))
	{
		int attachobj = ___CREATE_OBJECT(hash, &PlayerCoords, 1, 1, 0, 0, 1);
		if (ENTITY::DOES_ENTITY_EXIST(attachobj))
		{
			Vector3 One, Two;
			One.x = 0.5;// up & down
			One.y = -0.2;// Forward & Backward
			One.z = 0;// Left & Right
			Two.x = 0;
			Two.y = 75.0;
			Two.z = 0;
			___ATTACH_ENTITY_TO_ENTITY(attachobj, PLAYER::GET_PLAYER_PED(PlayerID), back, &One, &Two, 0, 1, 0, 0, 2, 1);
			ENTITY::SET_ENTITY_COLLISION2(attachobj, 0);
			return 1;
		}
		return 0;
	}
	return 0;
}
bool atachWEED(int PlayerID)
{
	Vector3 PlayerCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(PlayerID), true);
	int hash = GAMEPLAY::GET_HASH_KEY("prop_weed_01");
	STREAMING::REQUEST_MODEL(hash);
	int back = PED::GET_PED_BONE_INDEX(PLAYER::GET_PLAYER_PED(PlayerID), 23553);// SKEL_Spine0
	if (STREAMING::HAS_MODEL_LOADED(hash))
	{
		int attachobj = ___CREATE_OBJECT(hash, &PlayerCoords, 1, 1, 0, 0, 1);
		if (ENTITY::DOES_ENTITY_EXIST(attachobj))
		{
			Vector3 One, Two;
			One.x = 0.5;// up & down
			One.y = -0.2;// Forward & Backward
			One.z = 0;// Left & Right
			Two.x = 0;
			Two.y = 75.0;
			Two.z = 0;
			___ATTACH_ENTITY_TO_ENTITY(attachobj, PLAYER::GET_PLAYER_PED(PlayerID), back, &One, &Two, 0, 1, 0, 0, 2, 1);
			ENTITY::SET_ENTITY_COLLISION2(attachobj, 0);
			return 1;
		}
		return 0;
	}
	return 0;
}
void TripAlarm2(Ped selectedPed)
{
	Vehicle VehicleHandle3 = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED(selectedPlayer), true);
	if (ENTITY::DOES_ENTITY_EXIST(VehicleHandle3))
	{
		ENTITY::SET_ENTITY_AS_MISSION_ENTITY(VehicleHandle3, 1, 1);
		VEHICLE::SET_VEHICLE_ALARM(VehicleHandle3, true);
		VEHICLE::START_VEHICLE_ALARM(VehicleHandle3);
	}
}
void godcar()
{
	Ped playerPed = PLAYER::GET_PLAYER_PED(selectedPlayer);
	if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		Vehicle playerVeh = PED::GET_VEHICLE_PED_IS_IN(playerPed, false);
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(playerVeh);
		if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(playerVeh))
		{
			ENTITY::SET_ENTITY_INVINCIBLE(selectedPlayer, true);
			invincibleClientVeh[selectedPlayer] = true;
			godcar_ = false;
		}
	}
	else
	{
		drawNotification("~r~Player Is Not In A Vehicle");
		godcar_ = false;
	}
}
bool prbeachfire(int PlayerID)
{
	Vector3 PlayerCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(PlayerID), true);
	int hash = GAMEPLAY::GET_HASH_KEY("prop_beach_fire");
	STREAMING::REQUEST_MODEL(hash);
	int back = PED::GET_PED_BONE_INDEX(PLAYER::GET_PLAYER_PED(PlayerID), 23553);// SKEL_Spine0
	if (STREAMING::HAS_MODEL_LOADED(hash))
	{
		int attachobj = ___CREATE_OBJECT(hash, &PlayerCoords, 1, 1, 0, 0, 1);
		if (ENTITY::DOES_ENTITY_EXIST(attachobj))
		{
			Vector3 One, Two;
			One.x = 0.5;// up & down
			One.y = -0.2;// Forward & Backward
			One.z = 0;// Left & Right
			Two.x = 0;
			Two.y = 75.0;
			Two.z = 0;
			___ATTACH_ENTITY_TO_ENTITY(attachobj, PLAYER::GET_PLAYER_PED(PlayerID), back, &One, &Two, 0, 1, 0, 0, 2, 1);
			ENTITY::SET_ENTITY_COLLISION2(attachobj, 0);
			return 1;
		}
		return 0;
	}
	return 0;
}
char* PedNameArray[15];
int SpawnedPed[15];
int SpawnedPed_;
bool LoadingPed;
bool Spawnped = false;
char *ped_moel;
bool Create_Ped1(char* ObjectName, char* Name, float Pos, float y, float z, char *meg, bool custom = false, int hash = 0)
{
	if (Spawnped)
	{
		if (custom)
		{
			if (STREAMING::IS_MODEL_IN_CDIMAGE(hash))
			{
				if (STREAMING::IS_MODEL_VALID(hash))
				{
					STREAMING::REQUEST_MODEL(hash);
					if (STREAMING::HAS_MODEL_LOADED(hash))
					{
						SpawnedPed[SpawnedPed_] = PED::CREATE_PED(15, GAMEPLAY::GET_HASH_KEY(ObjectName), Pos, y, z, 1, 1, 0);
						PedNameArray[SpawnedPed_] = Name;
						if (ENTITY::DOES_ENTITY_EXIST(SpawnedPed[SpawnedPed_]))
						{
							SpawnedPed_++;
							char buf[100];
							//__snprintf(buf, sizeof(buf), "Spawned: ~b~%s~HUD_COLOUR_WHITE~!", Name);
							//PRINT(buf, 2000);
							if (SpawnedPed_ >= 15)
								SpawnedPed_ = 0;
							drawNotification(meg);
							return true;
						}
						else return false;
					}
					else return false;
				}
			}
		}
		else
		{
			if (STREAMING::IS_MODEL_IN_CDIMAGE(GAMEPLAY::GET_HASH_KEY(ObjectName)))
			{
				if (STREAMING::IS_MODEL_VALID(GAMEPLAY::GET_HASH_KEY(ObjectName)))
				{
					STREAMING::REQUEST_MODEL(GAMEPLAY::GET_HASH_KEY(ObjectName));
					Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
					if (STREAMING::HAS_MODEL_LOADED(GAMEPLAY::GET_HASH_KEY(ObjectName)))
					{
						//	static Any CREATE_OBJECT(Hash ObjectHash, float XCoord, float YCoord, float ZCoord, int p4, BOOL p5, BOOL dynamic) { return invoke<Any>(0x2F7AA05C, ObjectHash, XCoord, YCoord, ZCoord, p4, p5, dynamic); } // 0x2F7AA05C
						SpawnedPed[SpawnedPed_] = PED::CREATE_PED(21, GAMEPLAY::GET_HASH_KEY(ObjectName), Pos, y, z, 1, 1, 0);
						PedNameArray[SpawnedPed_] = ObjectName;
						if (ENTITY::DOES_ENTITY_EXIST(SpawnedPed[SpawnedPed_]))
						{
							SpawnedPed_++;
							char buf[100];
							//__snprintf(buf, sizeof(buf), "Spawned: ~b~%s~HUD_COLOUR_WHITE~!", ObjectName);
							//PRINT(buf, 2000);
							if (SpawnedPed_ >= 15)
								SpawnedPed_ = 0;


							Spawnped = false;
							return true;
						}
						else return false;
					}
					else return false;
				}
			}
		}
	}
}
bool poislick01(int PlayerID)
{
	Vector3 PlayerCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(PlayerID), true);
	int hash = GAMEPLAY::GET_HASH_KEY("p_oil_slick_01");
	STREAMING::REQUEST_MODEL(hash);
	int back = PED::GET_PED_BONE_INDEX(PLAYER::GET_PLAYER_PED(PlayerID), 23553);// SKEL_Spine0
	if (STREAMING::HAS_MODEL_LOADED(hash))
	{
		int attachobj = ___CREATE_OBJECT(hash, &PlayerCoords, 1, 1, 0, 0, 1);
		if (ENTITY::DOES_ENTITY_EXIST(attachobj))
		{
			Vector3 One, Two;
			One.x = 0.5;// up & down
			One.y = -0.2;// Forward & Backward
			One.z = 0;// Left & Right
			Two.x = 0;
			Two.y = 75.0;
			Two.z = 0;
			___ATTACH_ENTITY_TO_ENTITY(attachobj, PLAYER::GET_PLAYER_PED(PlayerID), back, &One, &Two, 0, 1, 0, 0, 2, 1);
			ENTITY::SET_ENTITY_COLLISION2(attachobj, 0);
			return 1;
		}
		return 0;
	}
	return 0;
}
bool prbeachlgsurf(int PlayerID)
{
	Vector3 PlayerCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(PlayerID), true);
	int hash = GAMEPLAY::GET_HASH_KEY("prop_beach_lg_surf");
	STREAMING::REQUEST_MODEL(hash);
	int back = PED::GET_PED_BONE_INDEX(PLAYER::GET_PLAYER_PED(PlayerID), 23553);// SKEL_Spine0
	if (STREAMING::HAS_MODEL_LOADED(hash))
	{
		int attachobj = ___CREATE_OBJECT(hash, &PlayerCoords, 1, 1, 0, 0, 1);
		if (ENTITY::DOES_ENTITY_EXIST(attachobj))
		{
			Vector3 One, Two;
			One.x = 0.5;// up & down
			One.y = -0.2;// Forward & Backward
			One.z = 0;// Left & Right
			Two.x = 0;
			Two.y = 75.0;
			Two.z = 0;
			___ATTACH_ENTITY_TO_ENTITY(attachobj, PLAYER::GET_PLAYER_PED(PlayerID), back, &One, &Two, 0, 1, 0, 0, 2, 1);
			ENTITY::SET_ENTITY_COLLISION2(attachobj, 0);
			return 1;
		}
		return 0;
	}
	return 0;
}
bool precolaan(int PlayerID)
{
	Vector3 PlayerCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(PlayerID), true);
	int hash = GAMEPLAY::GET_HASH_KEY("prop_ecola_can");
	STREAMING::REQUEST_MODEL(hash);
	int back = PED::GET_PED_BONE_INDEX(PLAYER::GET_PLAYER_PED(PlayerID), 23553);// SKEL_Spine0
	if (STREAMING::HAS_MODEL_LOADED(hash))
	{
		int attachobj = ___CREATE_OBJECT(hash, &PlayerCoords, 1, 1, 0, 0, 1);
		if (ENTITY::DOES_ENTITY_EXIST(attachobj))
		{
			Vector3 One, Two;
			One.x = 0.5;// up & down
			One.y = -0.2;// Forward & Backward
			One.z = 0;// Left & Right
			Two.x = 0;
			Two.y = 75.0;
			Two.z = 0;
			___ATTACH_ENTITY_TO_ENTITY(attachobj, PLAYER::GET_PLAYER_PED(PlayerID), back, &One, &Two, 0, 1, 0, 0, 2, 1);
			ENTITY::SET_ENTITY_COLLISION2(attachobj, 0);
			return 1;
		}
		return 0;
	}
	return 0;
}
bool propelguitar03(int PlayerID)
{
	Vector3 PlayerCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(PlayerID), true);
	int hash = GAMEPLAY::GET_HASH_KEY("prop_el_guitar_03");
	STREAMING::REQUEST_MODEL(hash);
	int back = PED::GET_PED_BONE_INDEX(PLAYER::GET_PLAYER_PED(PlayerID), 23553);// SKEL_Spine0
	if (STREAMING::HAS_MODEL_LOADED(hash))
	{
		int attachobj = ___CREATE_OBJECT(hash, &PlayerCoords, 1, 1, 0, 0, 1);
		if (ENTITY::DOES_ENTITY_EXIST(attachobj))
		{
			Vector3 One, Two;
			One.x = 0.5;// up & down
			One.y = -0.2;// Forward & Backward
			One.z = 0;// Left & Right
			Two.x = 0;
			Two.y = 75.0;
			Two.z = 0;
			___ATTACH_ENTITY_TO_ENTITY(attachobj, PLAYER::GET_PLAYER_PED(PlayerID), back, &One, &Two, 0, 1, 0, 0, 2, 1);
			ENTITY::SET_ENTITY_COLLISION2(attachobj, 0);
			return 1;
		}
		return 0;
	}
	return 0;
}
bool guittarrazika(int PlayerID)
{
	Vector3 PlayerCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(PlayerID), true);
	int hash = GAMEPLAY::GET_HASH_KEY("prop_el_guitar_02");
	STREAMING::REQUEST_MODEL(hash);
	int back = PED::GET_PED_BONE_INDEX(PLAYER::GET_PLAYER_PED(PlayerID), 23553);// SKEL_Spine0
	if (STREAMING::HAS_MODEL_LOADED(hash))
	{
		int attachobj = ___CREATE_OBJECT(hash, &PlayerCoords, 1, 1, 0, 0, 1);
		if (ENTITY::DOES_ENTITY_EXIST(attachobj))
		{
			Vector3 One, Two;
			One.x = 0.5;// up & down
			One.y = -0.2;// Forward & Backward
			One.z = 0;// Left & Right
			Two.x = 0;
			Two.y = 75.0;
			Two.z = 0;
			___ATTACH_ENTITY_TO_ENTITY(attachobj, PLAYER::GET_PLAYER_PED(PlayerID), back, &One, &Two, 0, 1, 0, 0, 2, 1);
			ENTITY::SET_ENTITY_COLLISION2(attachobj, 0);
			return 1;
		}
		return 0;
	}
	return 0;
}
bool prmrraspberry01(int PlayerID)
{
	Vector3 PlayerCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(PlayerID), true);
	int hash = GAMEPLAY::GET_HASH_KEY("prop_mr_raspberry_01");
	STREAMING::REQUEST_MODEL(hash);
	int back = PED::GET_PED_BONE_INDEX(PLAYER::GET_PLAYER_PED(PlayerID), 23553);// SKEL_Spine0
	if (STREAMING::HAS_MODEL_LOADED(hash))
	{
		int attachobj = ___CREATE_OBJECT(hash, &PlayerCoords, 1, 1, 0, 0, 1);
		if (ENTITY::DOES_ENTITY_EXIST(attachobj))
		{
			Vector3 One, Two;
			One.x = 0.5;// up & down
			One.y = -0.2;// Forward & Backward
			One.z = 0;// Left & Right
			Two.x = 0;
			Two.y = 75.0;
			Two.z = 0;
			___ATTACH_ENTITY_TO_ENTITY(attachobj, PLAYER::GET_PLAYER_PED(PlayerID), back, &One, &Two, 0, 1, 0, 0, 2, 1);
			ENTITY::SET_ENTITY_COLLISION2(attachobj, 0);
			return 1;
		}
		return 0;
	}
	return 0;
}
bool propornmag04(int PlayerID)
{
	Vector3 PlayerCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(PlayerID), true);
	int hash = GAMEPLAY::GET_HASH_KEY("prop_porn_mag_04");
	STREAMING::REQUEST_MODEL(hash);
	int back = PED::GET_PED_BONE_INDEX(PLAYER::GET_PLAYER_PED(PlayerID), 23553);// SKEL_Spine0
	if (STREAMING::HAS_MODEL_LOADED(hash))
	{
		int attachobj = ___CREATE_OBJECT(hash, &PlayerCoords, 1, 1, 0, 0, 1);
		if (ENTITY::DOES_ENTITY_EXIST(attachobj))
		{
			Vector3 One, Two;
			One.x = 0.5;// up & down
			One.y = -0.2;// Forward & Backward
			One.z = 0;// Left & Right
			Two.x = 0;
			Two.y = 75.0;
			Two.z = 0;
			___ATTACH_ENTITY_TO_ENTITY(attachobj, PLAYER::GET_PLAYER_PED(PlayerID), back, &One, &Two, 0, 1, 0, 0, 2, 1);
			ENTITY::SET_ENTITY_COLLISION2(attachobj, 0);
			return 1;
		}
		return 0;
	}
	return 0;
}
bool procorakelp3d(int PlayerID)
{
	Vector3 PlayerCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(PlayerID), true);
	int hash = GAMEPLAY::GET_HASH_KEY("prop_coral_kelp_03d");
	STREAMING::REQUEST_MODEL(hash);
	int back = PED::GET_PED_BONE_INDEX(PLAYER::GET_PLAYER_PED(PlayerID), 23553);// SKEL_Spine0
	if (STREAMING::HAS_MODEL_LOADED(hash))
	{
		int attachobj = ___CREATE_OBJECT(hash, &PlayerCoords, 1, 1, 0, 0, 1);
		if (ENTITY::DOES_ENTITY_EXIST(attachobj))
		{
			Vector3 One, Two;
			One.x = 0.5;// up & down
			One.y = -0.2;// Forward & Backward
			One.z = 0;// Left & Right
			Two.x = 0;
			Two.y = 75.0;
			Two.z = 0;
			___ATTACH_ENTITY_TO_ENTITY(attachobj, PLAYER::GET_PLAYER_PED(PlayerID), back, &One, &Two, 0, 1, 0, 0, 2, 1);
			ENTITY::SET_ENTITY_COLLISION2(attachobj, 0);
			return 1;
		}
		return 0;
	}
	return 0;
}
bool prolicdosurround(int PlayerID)
{
	Vector3 PlayerCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(PlayerID), true);
	int hash = GAMEPLAY::GET_HASH_KEY("prop_police_door_surround");
	STREAMING::REQUEST_MODEL(hash);
	int back = PED::GET_PED_BONE_INDEX(PLAYER::GET_PLAYER_PED(PlayerID), 23553);// SKEL_Spine0
	if (STREAMING::HAS_MODEL_LOADED(hash))
	{
		int attachobj = ___CREATE_OBJECT(hash, &PlayerCoords, 1, 1, 0, 0, 1);
		if (ENTITY::DOES_ENTITY_EXIST(attachobj))
		{
			Vector3 One, Two;
			One.x = 0.5;// up & down
			One.y = -0.2;// Forward & Backward
			One.z = 0;// Left & Right
			Two.x = 0;
			Two.y = 75.0;
			Two.z = 0;
			___ATTACH_ENTITY_TO_ENTITY(attachobj, PLAYER::GET_PLAYER_PED(PlayerID), back, &One, &Two, 0, 1, 0, 0, 2, 1);
			ENTITY::SET_ENTITY_COLLISION2(attachobj, 0);
			return 1;
		}
		return 0;
	}
	return 0;
}
bool prwatcorpse1(int PlayerID)
{
	Vector3 PlayerCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(PlayerID), true);
	int hash = GAMEPLAY::GET_HASH_KEY("prop_water_corpse_01");
	STREAMING::REQUEST_MODEL(hash);
	int back = PED::GET_PED_BONE_INDEX(PLAYER::GET_PLAYER_PED(PlayerID), 23553);// SKEL_Spine0
	if (STREAMING::HAS_MODEL_LOADED(hash))
	{
		int attachobj = ___CREATE_OBJECT(hash, &PlayerCoords, 1, 1, 0, 0, 1);
		if (ENTITY::DOES_ENTITY_EXIST(attachobj))
		{
			Vector3 One, Two;
			One.x = 0.5;// up & down
			One.y = -0.2;// Forward & Backward
			One.z = 0;// Left & Right
			Two.x = 0;
			Two.y = 75.0;
			Two.z = 0;
			___ATTACH_ENTITY_TO_ENTITY(attachobj, PLAYER::GET_PLAYER_PED(PlayerID), back, &One, &Two, 0, 1, 0, 0, 2, 1);
			ENTITY::SET_ENTITY_COLLISION2(attachobj, 0);
			return 1;
		}
		return 0;
	}
	return 0;
}

bool bigshit(int PlayerID)
{
	Vector3 PlayerCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(PlayerID), true);
	int hash = GAMEPLAY::GET_HASH_KEY("prop_big_shit_02");
	STREAMING::REQUEST_MODEL(hash);
	int back = PED::GET_PED_BONE_INDEX(PLAYER::GET_PLAYER_PED(PlayerID), 23553);// SKEL_Spine0
	if (STREAMING::HAS_MODEL_LOADED(hash))
	{
		int attachobj = ___CREATE_OBJECT(hash, &PlayerCoords, 1, 1, 0, 0, 1);
		if (ENTITY::DOES_ENTITY_EXIST(attachobj))
		{
			Vector3 One, Two;
			One.x = 0.7;// up & down//cabeça
			One.y = 0.0;// Forward & Backward
			One.z = 0;// Left & Right
			Two.x = 0;
			Two.y = 75.0;
			Two.z = 0;
			___ATTACH_ENTITY_TO_ENTITY(attachobj, PLAYER::GET_PLAYER_PED(PlayerID), back, &One, &Two, 0, 1, 0, 0, 2, 1);
			ENTITY::SET_ENTITY_COLLISION2(attachobj, 0);
			return 1;
		}
		return 0;
	}
	return 0;
}
bool barriltoxicocabeca(int PlayerID)
{
	Vector3 PlayerCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(PlayerID), true);
	int hash = GAMEPLAY::GET_HASH_KEY("prop_rad_waste_barrel_01");
	STREAMING::REQUEST_MODEL(hash);
	int back = PED::GET_PED_BONE_INDEX(PLAYER::GET_PLAYER_PED(PlayerID), 23553);// SKEL_Spine0
	if (STREAMING::HAS_MODEL_LOADED(hash))
	{
		int attachobj = ___CREATE_OBJECT(hash, &PlayerCoords, 1, 1, 0, 0, 1);
		if (ENTITY::DOES_ENTITY_EXIST(attachobj))
		{
			Vector3 One, Two;
			One.x = 0.7;// up & down//cabeça
			One.y = 0.0;// Forward & Backward
			One.z = 0;// Left & Right
			Two.x = 0;
			Two.y = 75.0;
			Two.z = 0;
			___ATTACH_ENTITY_TO_ENTITY(attachobj, PLAYER::GET_PLAYER_PED(PlayerID), back, &One, &Two, 0, 1, 0, 0, 2, 1);
			ENTITY::SET_ENTITY_COLLISION2(attachobj, 0);
			return 1;
		}
		return 0;
	}
	return 0;
}
bool Luzcocabeca(int PlayerID)//luz na cabeça
{
	Vector3 PlayerCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(PlayerID), true);
	int hash = GAMEPLAY::GET_HASH_KEY("prop_spot_01");
	STREAMING::REQUEST_MODEL(hash);
	int back = PED::GET_PED_BONE_INDEX(PLAYER::GET_PLAYER_PED(PlayerID), 23553);// SKEL_Spine0
	if (STREAMING::HAS_MODEL_LOADED(hash))
	{
		int attachobj = ___CREATE_OBJECT(hash, &PlayerCoords, 1, 1, 0, 0, 1);
		if (ENTITY::DOES_ENTITY_EXIST(attachobj))
		{
			Vector3 One, Two;
			One.x = 0.7;// up & down//cabeça
			One.y = 0.0;// Forward & Backward
			One.z = 0;// Left & Right
			Two.x = 0;
			Two.y = 75.0;
			Two.z = 0;
			___ATTACH_ENTITY_TO_ENTITY(attachobj, PLAYER::GET_PLAYER_PED(PlayerID), back, &One, &Two, 0, 1, 0, 0, 2, 1);
			ENTITY::SET_ENTITY_COLLISION2(attachobj, 0);
			return 1;
		}
		return 0;
	}
	return 0;
}
bool pishit(int PlayerID)
{
	Vector3 PlayerCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(PlayerID), true);
	int hash = GAMEPLAY::GET_HASH_KEY("prop_cs_meth_pipe");
	STREAMING::REQUEST_MODEL(hash);
	int back = PED::GET_PED_BONE_INDEX(PLAYER::GET_PLAYER_PED(PlayerID), 23553);// SKEL_Spine0
	if (STREAMING::HAS_MODEL_LOADED(hash))
	{
		int attachobj = ___CREATE_OBJECT(hash, &PlayerCoords, 1, 1, 0, 0, 1);
		if (ENTITY::DOES_ENTITY_EXIST(attachobj))
		{
			Vector3 One, Two;
			One.x = 0.7;// up & down//cabeça
			One.y = 0.0;// Forward & Backward
			One.z = 0;// Left & Right
			Two.x = 0;
			Two.y = 75.0;
			Two.z = 0;
			___ATTACH_ENTITY_TO_ENTITY(attachobj, PLAYER::GET_PLAYER_PED(PlayerID), back, &One, &Two, 0, 1, 0, 0, 2, 1);
			ENTITY::SET_ENTITY_COLLISION2(attachobj, 0);
			return 1;
		}
		return 0;
	}
	return 0;
}
bool ishit(int PlayerID)//missel de piroca
{
	Vector3 PlayerCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(PlayerID), true);
	int hash = GAMEPLAY::GET_HASH_KEY("prop_ld_bomb_anim");
	STREAMING::REQUEST_MODEL(hash);
	int back = PED::GET_PED_BONE_INDEX(PLAYER::GET_PLAYER_PED(PlayerID), 23553);// SKEL_Spine0
	if (STREAMING::HAS_MODEL_LOADED(hash))
	{
		int attachobj = ___CREATE_OBJECT(hash, &PlayerCoords, 1, 1, 0, 0, 1);
		if (ENTITY::DOES_ENTITY_EXIST(attachobj))
		{
			Vector3 One, Two;
			One.x = 0.0;// up & down//cabeça
			One.y = 0.7;// Forward & Backward
			One.z = 0;// Left & Right
			Two.x = 180.0;//180.0, para ficar de piroca
			Two.y = 90.0;//90.0
			Two.z = 0;
			___ATTACH_ENTITY_TO_ENTITY(attachobj, PLAYER::GET_PLAYER_PED(PlayerID), back, &One, &Two, 0, 1, 0, 0, 2, 1);
			ENTITY::SET_ENTITY_COLLISION2(attachobj, 0);
			return 1;
		}
		return 0;
	}
	return 0;
}
bool misselmediorola(int PlayerID)//missel de piroca
{
	Vector3 PlayerCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(PlayerID), true);
	int hash = GAMEPLAY::GET_HASH_KEY("prop_ld_bomb_01");
	STREAMING::REQUEST_MODEL(hash);
	int back = PED::GET_PED_BONE_INDEX(PLAYER::GET_PLAYER_PED(PlayerID), 23553);// SKEL_Spine0
	if (STREAMING::HAS_MODEL_LOADED(hash))
	{
		int attachobj = ___CREATE_OBJECT(hash, &PlayerCoords, 1, 1, 0, 0, 1);
		if (ENTITY::DOES_ENTITY_EXIST(attachobj))
		{
			Vector3 One, Two;
			One.x = 0.0;// up & down//cabeça
			One.y = 0.7;// Forward & Backward
			One.z = 0;// Left & Right
			Two.x = 180.0;//180.0, para ficar de piroca
			Two.y = 90.0;//90.0
			Two.z = 0;
			___ATTACH_ENTITY_TO_ENTITY(attachobj, PLAYER::GET_PLAYER_PED(PlayerID), back, &One, &Two, 0, 1, 0, 0, 2, 1);
			ENTITY::SET_ENTITY_COLLISION2(attachobj, 0);
			return 1;
		}
		return 0;
	}
	return 0;
}
bool semrolagigante(int PlayerID)//
{
	Vector3 PlayerCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(PlayerID), true);
	int hash = GAMEPLAY::GET_HASH_KEY("prop_sam_01");
	STREAMING::REQUEST_MODEL(hash);
	int back = PED::GET_PED_BONE_INDEX(PLAYER::GET_PLAYER_PED(PlayerID), 23553);// SKEL_Spine0
	if (STREAMING::HAS_MODEL_LOADED(hash))
	{
		int attachobj = ___CREATE_OBJECT(hash, &PlayerCoords, 1, 1, 0, 0, 1);
		if (ENTITY::DOES_ENTITY_EXIST(attachobj))
		{
			Vector3 One, Two;
			One.x = 0.0;// up & down//cabeça
			One.y = 0.7;// Forward & Backward
			One.z = 0;// Left & Right
			Two.x = 180.0;//180.0, para ficar de piroca
			Two.y = 90.0;//90.0
			Two.z = 0;
			___ATTACH_ENTITY_TO_ENTITY(attachobj, PLAYER::GET_PLAYER_PED(PlayerID), back, &One, &Two, 0, 1, 0, 0, 2, 1);
			ENTITY::SET_ENTITY_COLLISION2(attachobj, 0);
			return 1;
		}
		return 0;
	}
	return 0;
}
bool misseldickopen(int PlayerID)//missel de piroca
{
	Vector3 PlayerCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(PlayerID), true);
	int hash = GAMEPLAY::GET_HASH_KEY("prop_ld_bomb_01_open");
	STREAMING::REQUEST_MODEL(hash);
	int back = PED::GET_PED_BONE_INDEX(PLAYER::GET_PLAYER_PED(PlayerID), 23553);// SKEL_Spine0
	if (STREAMING::HAS_MODEL_LOADED(hash))
	{
		int attachobj = ___CREATE_OBJECT(hash, &PlayerCoords, 1, 1, 0, 0, 1);
		if (ENTITY::DOES_ENTITY_EXIST(attachobj))
		{
			Vector3 One, Two;
			One.x = 0.0;// up & down//cabeça
			One.y = 0.7;// Forward & Backward
			One.z = 0;// Left & Right
			Two.x = 180.0;//180.0, para ficar de piroca
			Two.y = 90.0;//90.0
			Two.z = 0;
			___ATTACH_ENTITY_TO_ENTITY(attachobj, PLAYER::GET_PLAYER_PED(PlayerID), back, &One, &Two, 0, 1, 0, 0, 2, 1);
			ENTITY::SET_ENTITY_COLLISION2(attachobj, 0);
			return 1;
		}
		return 0;
	}
	return 0;
}
bool PAZINHAdeROLA(int PlayerID)
{
	Vector3 PlayerCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(PlayerID), true);
	int hash = GAMEPLAY::GET_HASH_KEY("prop_ld_shovel");
	STREAMING::REQUEST_MODEL(hash);
	int back = PED::GET_PED_BONE_INDEX(PLAYER::GET_PLAYER_PED(PlayerID), 23553);// SKEL_Spine0
	if (STREAMING::HAS_MODEL_LOADED(hash))
	{
		int attachobj = ___CREATE_OBJECT(hash, &PlayerCoords, 1, 1, 0, 0, 1);
		if (ENTITY::DOES_ENTITY_EXIST(attachobj))
		{
			Vector3 One, Two;
			One.x = 0.0;// up & down//cabeça
			One.y = 0.7;// Forward & Backward
			One.z = 0;// Left & Right
			Two.x = 180.0;//180.0, para ficar de piroca
			Two.y = 90.0;//90.0
			Two.z = 0;
			___ATTACH_ENTITY_TO_ENTITY(attachobj, PLAYER::GET_PLAYER_PED(PlayerID), back, &One, &Two, 0, 1, 0, 0, 2, 1);
			ENTITY::SET_ENTITY_COLLISION2(attachobj, 0);
			return 1;
		}
		return 0;
	}
	return 0;
}
bool SPACERIFLEDICK(int PlayerID)
{
	Vector3 PlayerCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(PlayerID), true);
	int hash = GAMEPLAY::GET_HASH_KEY("prop_Space_Rifle");
	STREAMING::REQUEST_MODEL(hash);
	int back = PED::GET_PED_BONE_INDEX(PLAYER::GET_PLAYER_PED(PlayerID), 23553);// SKEL_Spine0
	if (STREAMING::HAS_MODEL_LOADED(hash))
	{
		int attachobj = ___CREATE_OBJECT(hash, &PlayerCoords, 1, 1, 0, 0, 1);
		if (ENTITY::DOES_ENTITY_EXIST(attachobj))
		{
			Vector3 One, Two;
			One.x = 0.0;// up & down//cabeça
			One.y = 0.7;// Forward & Backward
			One.z = 0;// Left & Right
			Two.x = 180.0;//180.0, para ficar de piroca
			Two.y = 90.0;//90.0
			Two.z = 0;
			___ATTACH_ENTITY_TO_ENTITY(attachobj, PLAYER::GET_PLAYER_PED(PlayerID), back, &One, &Two, 0, 1, 0, 0, 2, 1);
			ENTITY::SET_ENTITY_COLLISION2(attachobj, 0);
			return 1;
		}
		return 0;
	}
	return 0;
}
bool pinodebolicherola(int PlayerID)
{
	Vector3 PlayerCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(PlayerID), true);
	int hash = GAMEPLAY::GET_HASH_KEY("prop_bowling_pin");
	STREAMING::REQUEST_MODEL(hash);
	int back = PED::GET_PED_BONE_INDEX(PLAYER::GET_PLAYER_PED(PlayerID), 23553);// SKEL_Spine0
	if (STREAMING::HAS_MODEL_LOADED(hash))
	{
		int attachobj = ___CREATE_OBJECT(hash, &PlayerCoords, 1, 1, 0, 0, 1);
		if (ENTITY::DOES_ENTITY_EXIST(attachobj))
		{
			Vector3 One, Two;
			One.x = 0.0;// up & down//cabeça
			One.y = 0.7;// Forward & Backward
			One.z = 0;// Left & Right
			Two.x = 180.0;//180.0, para ficar de piroca
			Two.y = 90.0;//90.0
			Two.z = 0;
			___ATTACH_ENTITY_TO_ENTITY(attachobj, PLAYER::GET_PLAYER_PED(PlayerID), back, &One, &Two, 0, 1, 0, 0, 2, 1);
			ENTITY::SET_ENTITY_COLLISION2(attachobj, 0);
			return 1;
		}
		return 0;
	}
	return 0;
}
bool fishit(int PlayerID)
{
	Vector3 PlayerCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(PlayerID), true);
	int hash = GAMEPLAY::GET_HASH_KEY("prop_ld_fireaxe");
	STREAMING::REQUEST_MODEL(hash);
	int back = PED::GET_PED_BONE_INDEX(PLAYER::GET_PLAYER_PED(PlayerID), 23553);// SKEL_Spine0
	if (STREAMING::HAS_MODEL_LOADED(hash))
	{
		int attachobj = ___CREATE_OBJECT(hash, &PlayerCoords, 1, 1, 0, 0, 1);
		if (ENTITY::DOES_ENTITY_EXIST(attachobj))
		{
			Vector3 One, Two;
			One.x = 0.7;// up & down//cabeça
			One.y = 0.0;// Forward & Backward
			One.z = 0;// Left & Right
			Two.x = 0;
			Two.y = 75.0;
			Two.z = 0;
			___ATTACH_ENTITY_TO_ENTITY(attachobj, PLAYER::GET_PLAYER_PED(PlayerID), back, &One, &Two, 0, 1, 0, 0, 2, 1);
			ENTITY::SET_ENTITY_COLLISION2(attachobj, 0);
			return 1;
		}
		return 0;
	}
	return 0;
}
bool afishit(int PlayerID)
{
	Vector3 PlayerCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(PlayerID), true);
	int hash = GAMEPLAY::GET_HASH_KEY("prop_drop_armscrate_01");
	STREAMING::REQUEST_MODEL(hash);
	int back = PED::GET_PED_BONE_INDEX(PLAYER::GET_PLAYER_PED(PlayerID), 23553);// SKEL_Spine0
	if (STREAMING::HAS_MODEL_LOADED(hash))
	{
		int attachobj = ___CREATE_OBJECT(hash, &PlayerCoords, 1, 1, 0, 0, 1);
		if (ENTITY::DOES_ENTITY_EXIST(attachobj))
		{
			Vector3 One, Two;
			One.x = 0.7;// up & down//cabeça
			One.y = 0.0;// Forward & Backward
			One.z = 0;// Left & Right
			Two.x = 0;
			Two.y = 75.0;
			Two.z = 0;
			___ATTACH_ENTITY_TO_ENTITY(attachobj, PLAYER::GET_PLAYER_PED(PlayerID), back, &One, &Two, 0, 1, 0, 0, 2, 1);
			ENTITY::SET_ENTITY_COLLISION2(attachobj, 0);
			return 1;
		}
		return 0;
	}
	return 0;
}
bool doAnimation(char* anim, char* animid)
{
	int pPlayer = PLAYER::PLAYER_PED_ID();
	NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(pPlayer);
	STREAMING::REQUEST_ANIM_DICT(anim);
	if (STREAMING::HAS_ANIM_DICT_LOADED((anim)))
	{
		AI::TASK_PLAY_ANIM(pPlayer, anim, animid, 8.0f, 0.0f, -1, 9, 0, 0, 0, 0);
		Vector3 PedCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
		return true;
	}
	return false;
}
void ChangeWalkingType(char *WalkType)
{
	STREAMING::_REQUEST_ANIM_SET(WalkType);
	if (STREAMING::_HAS_ANIM_SET_LOADED(WalkType))
	{
		PED::_SET_PED_MOVEMENT_CLIPSET(PLAYER::PLAYER_PED_ID(), WalkType, 1048576000);
	}
}
void ShootFirePlayer()
{
	float Loc[3];
	if (PED::IS_PED_SHOOTING(PLAYER::GET_PLAYER_PED(selectedPlayer)))
	{
		if (__GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::GET_PLAYER_PED(selectedPlayer), Loc))
		{
			Vector3 Pos;
			Pos.x = Loc[0]; Pos.y = Loc[1]; Pos.z = Loc[2];
			FIRE::ADD_OWNED_EXPLOSION(PLAYER::GET_PLAYER_PED(selectedPlayer), Pos.x, Pos.y, Pos.z, 12, 1.0f, true, true, 0.0f);
			FIRE::ADD_EXPLOSION(Pos.x, Pos.y, Pos.z, 29, 0.5f, true, false, 0.0f);
		}
	}
}
void GiveMoneyGun1()
{
	if (SpawnedPed[SelectedPed])
	{
		float Loc[3];
		if (__GET_PED_LAST_WEAPON_IMPACT_COORD(SpawnedPed[SelectedPed], Loc))
		{
			Vector3 Pos;
			Pos.x = Loc[0]; Pos.y = Loc[1]; Pos.z = Loc[2];
			STREAMING::REQUEST_MODEL(0x113FD533);
			if (STREAMING::HAS_MODEL_LOADED(0x113FD533) == 1)
			{
				OBJECT::CREATE_AMBIENT_PICKUP(0xCE6FDD6B, Pos.x, Pos.y, Pos.z, 0, 5, 0x113FD533, 0, 1);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(0x113FD533);
			}
		}
	}
}
void GiveAllWeapons(int Pedhandle)
{
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), -1716189206, -1, true, true);//WEAPON_KNIFE
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 1737195953, -1, true, true);//WEAPON_NIGHTSTICK
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 1317494643, -1, true, true);//WEAPON_HAMMER
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), -1786099057, -1, true, true);//WEAPON_BAT
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 1141786504, -1, true, true);//WEAPON_GOLFCLUB
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), -2067956739, -1, true, true);//WEAPON_CROWBAR
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 453432689, -1, true, true);//WEAPON_PISTOL
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 1593441988, -1, true, true);//WEAPON_COMBATPISTOL
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 584646201, -1, true, true);//WEAPON_APPISTO
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), -1716589765, -1, true, true);//WEAPON_PISTOL50
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 324215364, -1, true, true);//WEAPON_MICROSMG
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 736523883, -1, true, true);//WEAPON_SMG
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), -270015777, -1, true, true);//WEAPON_ASSAULTSMG
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), -1074790547, -1, true, true);//WEAPON_ASSAULTRIFLE
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), -2084633992, -1, true, true);//WEAPON_CARBINERIFLE
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), -1357824103, -1, true, true);//WEAPON_ADVANCEDRIFLE
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), -1660422300, -1, true, true);//WEAPON_MG
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 2144741730, -1, true, true);//WEAPON_COMBATMG
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 487013001, -1, true, true);//WEAPON_PUMPSHOTGUN
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 2017895192, -1, true, true);//WEAPON_SAWNOFFSHOTGUN
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), -494615257, -1, true, true);//WEAPON_ASSAULTSHOTGUN
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), -1654528753, -1, true, true);//WEAPON_BULLPUPSHOTGUN
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 911657153, -1, true, true);//WEAPON_STUNGUN**********************
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 100416529, -1, true, true);//WEAPON_SNIPERRIFLE
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 205991906, -1, true, true);//WEAPON_HEAVYSNIPER
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), -1568386805, -1, true, true);//WEAPON_GRENADELAUNCHER
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 1312131151, -1, true, true);//WEAPON_RPG
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 1752584910, -1, true, true);//WEAPON_STINGER
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 1119849093, -1, true, true);//WEAPON_MINIGUN
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), -1813897027, -1, true, true);//WEAPON_GRENADE
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 741814745, -1, true, true);//WEAPON_STICKYBOMB
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), -37975472, -1, true, true);//WEAPON_SMOKEGRENADE
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), -615608432, -1, true, true);//WEAPON_MOLOTOV
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 101631238, -1, true, true);//WEAPON_FIREEXTINGUISHER
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 883325847, -1, true, true);//WEAPON_PETROLCAN
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 600439132, -1, true, true);//WEAPON_BALL
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 1233104067, -1, true, true);//WEAPON_FLARE
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 1627465347, -1, true, true);//WEAPON_GUSENBERG
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 4192643659, -1, true, true);//WEAPON_BOTTLE
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 3231910285, -1, true, true);//WEAPON_SPECIALCARBINE
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 3523564046, -1, true, true);//WEAPON_HEAVYPISTOL
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 3218215474, -1, true, true);//WEAPON_SNSPISTOL
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 2132975508, -1, true, true);//WEAPON_BULLPUPRIFLE
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 2460120199, -1, true, true);//WEAPON_DAGGER
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 137902532, -1, true, true);//WEAPON_VINTAGEPISTOL
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 2138347493, -1, true, true);//WEAPON_FIREWORK
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 2828843422, -1, true, true);//WEAPON_MUSKET
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 984333226, -1, true, true);//WEAPON_HEAVYSHOTGUN 
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 3342088282, -1, true, true);//WEAPON_MARKSMANRIFLE
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 1672152130, -1, true, true);//WEAPON_HOMINGLAUNCHER
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 2874559379, -1, true, true);//WEAPON_PROXMINE
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 126349499, -1, true, true);//WEAPON_SNOWBALL
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 1198879012, -1, true, true);//WEAPON_FLAREGUN
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 171789620, -1, true, true);//WEAPON_COMBATPDW
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 3696079510, -1, true, true);//WEAPON_MARKSMANPISTOL
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 3638508604, -1, true, true);//WEAPON_KNUCKLE
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 4222310262, -1, true, true);//GADGET_PARACHUTE
}
void DeleteVehicle(int VehicleHandle)
{
	if (ENTITY::DOES_ENTITY_EXIST(VehicleHandle))
	{
		ENTITY::SET_ENTITY_AS_MISSION_ENTITY(VehicleHandle, 1, 1);
		VEHICLE::DELETE_VEHICLE(&VehicleHandle);
	}
}
void RemoveEclipseWindmill()
{
	Vector3 windmillCoords;
	windmillCoords.x = 229.3570f;
	windmillCoords.y = -992.9106f;
	windmillCoords.z = -98.9999f;
	Object obj = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(windmillCoords.x, windmillCoords.y, windmillCoords.z, 25.0f, 0x745F3383, false,1,0);//prop_windmill_01
	if (NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(obj) && NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(obj))
	{
		ENTITY::DETACH_ENTITY(obj, 1, 1);
		ENTITY::DELETE_ENTITY(&obj);
		ENTITY::SET_ENTITY_COORDS(obj, 6000.0, 6000.0, 6000.0, true, false, false, true);
	}
}
void Modelo(char* family, int model, int texture)
{
	if (cstrcmp(family, "HATS") || cstrcmp(family, "GLASSES") || cstrcmp(family, "EARS"))
	{
		if (cstrcmp(family, "HATS"))
			fam = 0;
		else if (cstrcmp(family, "GLASSES"))
			fam = 1;
		else if (cstrcmp(family, "EARS"))
			fam = 2;
		ADDR::__SET_PED_PROP_INDEX(ADDR::__PLAYER_PED_ID(), fam, model - 1, texture);
	}
	else
	{
		if (cstrcmp(family, "FACE"))
			fam = 0;
		else if (cstrcmp(family, "MASK"))
			fam = 1;
		else if (cstrcmp(family, "HAIR"))
			fam = 2;
		else if (cstrcmp(family, "TORSO"))
			fam = 3;
		else if (cstrcmp(family, "LEGS"))
			fam = 4;
		else if (cstrcmp(family, "HANDS"))
			fam = 5;
		else if (cstrcmp(family, "SHOES"))
			fam = 6;
		else if (cstrcmp(family, "SPECIAL1"))
			fam = 7;
		else if (cstrcmp(family, "SPECIAL2"))
			fam = 8;
		else if (cstrcmp(family, "SPECIAL3"))
			fam = 9;
		else if (cstrcmp(family, "TEXTURE"))
			fam = 10;
		else if (cstrcmp(family, "TORSO2"))
			fam = 11;
		ADDR::__SET_PED_COMPONENT_VARIATION(ADDR::__PLAYER_PED_ID(), fam, model, texture);
	}
}

void Create_Ped(char* ObjectName, char* Name, float Pos, float y, float z, char *meg, bool custom = false, int hash = 0)
{
	drawNotification(meg);
	ped_moel = ObjectName;
	Spawnped = true;
}

void CleanPed(int PedHandle)
{
	PED::CLEAR_PED_BLOOD_DAMAGE(PedHandle);
	PED::RESET_PED_VISIBLE_DAMAGE(PedHandle);
	PED::SET_PED_ARMOUR(PLAYER::GET_PLAYER_PED(PedHandle), 9999999);
	DoFX("scr_rcbarry1", "scr_alien_disintegrate");
	DoFX("scr_rcbarry1", "scr_alien_teleport");
}
bool PedG_;
bool SpawnedPedHasGodmode[15];
bool PedClearTasks;
bool setpedonplayer;
void SetGMod(int ped)
{
	if (PedG_ == false)
	{
		if (RequestNetworkControl(ped))
		{
			ENTITY::SET_ENTITY_CAN_BE_DAMAGED(ped, false);
			ENTITY::SET_ENTITY_INVINCIBLE(ped, true);
			drawNotification("God Mode: ~g~Enabled");
			PedG_ = true;
		}
	}
	else if (PedG_ == true)
	{
		ENTITY::SET_ENTITY_CAN_BE_DAMAGED(ped, true);
		ENTITY::SET_ENTITY_INVINCIBLE(ped, false);
		drawNotification("God Mode: ~r~Disabled");
		PedG_ = false;
	}

}
char* SoundToPlay;
char* SoundSetToPlay;
bool PlaySounds;

void PlaySoundz(char* SoundName, char* SoundSetName)
{
	AUDIO::PLAY_SOUND_FRONTEND(-1, SoundName, SoundSetName);
}
bool forcedefense;
void ForceDefense()//loopthis
{
	bool exploded = false;
	int LocalID = PLAYER::PLAYER_ID();
	int LocalPED = PLAYER::PLAYER_PED_ID();
	for (int i = 0; i < 30; i++)
	{
		if (PLAYER::IS_PLAYER_TARGETTING_ENTITY(i, LocalPED) && !exploded)
		{
			Vector3 Pos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(i), true);
			FIRE::ADD_EXPLOSION(Pos.x, Pos.y, Pos.z, 1, 5.0, 0, 1, 0);
			exploded = true;
		}
	}
}
void ForceBoost()//loopthis
{

	const int numElements = 10;
	const int arrSize = numElements * 2 + 2;
	Vehicle veh[arrSize];
	veh[0] = numElements;
	int count = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), veh);
	if (veh != NULL)
	{
		for (int i = 1; i <= count; i++)
		{
			int offsettedID = i;
			if (veh[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(veh[offsettedID]))
			{
				RequestNetworkControl(veh[offsettedID]);
				VEHICLE::SET_VEHICLE_FORWARD_SPEED(veh[offsettedID], 100.0f);
			}
		}
	}
}
bool forceexplodewave = false;
void ForceExplodeWavePED()//loopthis
{
	if (CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, INPUT_SCRIPT_RB))
	{
		const int numElements = 10;
		const int arrSize = numElements * 2 + 2;
		Ped ped[arrSize];
		ped[0] = numElements;
		int count = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), ped, 1);
		if (ped != NULL)
		{
			for (int i = 1; i <= count; i++)
			{
				int offsettedID = i;
				if (ped[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(ped[offsettedID]))
				{
					int TargetHandle = PLAYER::GET_PLAYER_PED(PLAYER::GET_PLAYER_PED(selectedPlayer));
					RequestNetworkControl(ped[offsettedID]);
					ENTITY::SET_ENTITY_HEALTH(ped[offsettedID], 0);
				}
			}
		}
	}
}
void ForceExplodeWave()//loopthis
{
	const int numElements = 10;
	const int arrSize = numElements * 2 + 2;
	Vehicle veh[arrSize];
	veh[0] = numElements;
	int count = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), veh);
	if (veh != NULL)
	{
		for (int i = 1; i <= count; i++)
		{
			int offsettedID = i;
			if (veh[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(veh[offsettedID]))
			{
				Vector3 Pos = ENTITY::GET_ENTITY_COORDS(veh[offsettedID], true);
				FIRE::ADD_EXPLOSION(Pos.x, Pos.y, Pos.z, 29, 0.5f, true, true, 1.0f);

				char *dict = "rcmcollect_paperleadinout@";
				char *anim = "meditiate_idle";
				STREAMING::REQUEST_ANIM_DICT(dict);
				AI::TASK_PLAY_ANIM(PLAYER::PLAYER_PED_ID(), dict, anim, 1, 1, -1, 16, 0, false, 0, false);
			}
		}
	}
}

bool forcewave = false;//loopthis
void ForceWave() {

	const int numElements = 10;
	const int arrSize = numElements * 2 + 2;
	STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_reconstructionaccident");
	DoFX("scr_reconstructionaccident", "scr_reconstruct_pipe_impact");
	DoFX("scr_reconstructionaccident", "scr_reconstruct_pipe_impact");
	Vehicle veh[arrSize];
	veh[0] = numElements;
	int count = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), veh);
	if (veh != NULL)
	{
		for (int i = 1; i <= count; i++)
		{
			int offsettedID = i;
			if (veh[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(veh[offsettedID]))
			{
				ENTITY::APPLY_FORCE_TO_ENTITY(veh[offsettedID], 1, 9, 9, 0, 0, 0, 0, 1, true, true, true, true, true);

				char *dict = "rcmcollect_paperleadinout@";
				char *anim = "meditiate_idle";
				STREAMING::REQUEST_ANIM_DICT(dict);
				AI::TASK_PLAY_ANIM(PLAYER::PLAYER_PED_ID(), dict, anim, 1, 1, -1, 16, 0, false, 0, false);
			}
		}
	}
}
void DeletePed(int pedID)
{
	if (!NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(pedID))
		while (!NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(pedID));

	ENTITY::SET_ENTITY_AS_MISSION_ENTITY(pedID, 1, 1);
	PED::DELETE_PED(&pedID);
}
void makePedHostile(uint Ped, int Target, bool choporswat = false, bool isClone = false)
{
	if (choporswat)
	{
		int TargetHandle = PLAYER::GET_PLAYER_PED(Target);
		AI::TASK_COMBAT_PED(Ped, TargetHandle, 0, 16);
		PED::SET_PED_CAN_SWITCH_WEAPON(Ped, true);
	}
	else
	{
		if (isClone)
		{
			int Hash = ENTITY::GET_ENTITY_MODEL(Ped);
			DeletePed(Ped);

			STREAMING::REQUEST_MODEL(Hash);
			Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(Target), 1);
			if (STREAMING::HAS_MODEL_LOADED(Hash))
			{
				int newPed = PED::CREATE_PED(21, Hash, coords.x, coords.y, coords.z, 0, 1, 0);
				if (ENTITY::GET_ENTITY_HEALTH(newPed) == ENTITY::GET_ENTITY_MAX_HEALTH(newPed))
				{
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(Hash);
					RequestNetworkControl(newPed);
					int TargetHandle = PLAYER::GET_PLAYER_PED(Target);
					AI::TASK_COMBAT_PED(newPed, TargetHandle, 0, 16);
					PED::SET_PED_CAN_SWITCH_WEAPON(Ped, true);
				}
			}
		}
		else
		{
			int TargetHandle = PLAYER::GET_PLAYER_PED(Target);
			AI::TASK_COMBAT_PED(Ped, TargetHandle, 0, 16);
		}
	}
}
#pragma region Animation Stuff

bool LoadingAnim = false;
bool LoadingAnimForPed = false;
char* Anim;
char* AnimID;
int PedToDoAnim;
void setAnimation(char* anim, char* animid)
{
	Anim = anim;
	AnimID = animid;
	LoadingAnim = true;
}
void ForceThrow()//loopthis
{
	const int numElements = 10;
	const int arrSize = numElements * 2 + 2;
	Vehicle veh[arrSize];
	veh[0] = numElements;
	setAnimation("rcmpaparazzo_4", "lift_hands_in_air_loop");
	int count = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), veh);
	if (veh != NULL)
	{
		for (int i = 1; i <= count; i++)
		{
			int offsettedID = i;
			if (veh[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(veh[offsettedID]))
			{
				ENTITY::APPLY_FORCE_TO_ENTITY(veh[offsettedID], 1, 0, 0, 5, 0, 0, 0, 1, false, true, true, true, true);
				STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_trevor1");
				GRAPHICS::_SET_PTFX_ASSET_NEXT_CALL("scr_trevor1");
				DoFX("scr_trevor1", "scr_trev1_trailer_boosh");
				//draw(sizeof(veh));
			}
		}
	}
}
void GiveWeaponPed(int Ped, int WeaponHash)
{
	WEAPON::GIVE_WEAPON_TO_PED(Ped, WeaponHash, 9999, 1, 1);

}
bool mcriot = false;//loopthis
void MCRiot()
{
	const int numElements = 10;
	const int arrSize = numElements * 2 + 2;
	Ped ped[arrSize];
	ped[0] = numElements;
	int count = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), ped, 1);
	if (ped != NULL)
	{
		for (int i = 1; i <= count; i++)
		{
			int offsettedID = i;
			if (ped[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(ped[offsettedID]))
			{
				int TargetHandle = PLAYER::GET_PLAYER_PED(PLAYER::GET_PLAYER_PED(selectedPlayer));
				RequestNetworkControl(ped[offsettedID]);
				GiveWeaponPed(ped[offsettedID], 0x47757124);
				makePedHostile(ped[offsettedID], TargetHandle, true);
			}
		}
	}
}
bool mcdance = false;//loopthis
void MCDance()
{

	const int numElements = 10;
	const int arrSize = numElements * 2 + 2;
	Ped ped[arrSize];
	ped[0] = numElements;
	int count = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), ped, 1);
	if (ped != NULL)
	{
		for (int i = 1; i <= count; i++)
		{
			int offsettedID = i;
			if (ped[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(ped[offsettedID]))
			{
				int TargetHandle = PLAYER::GET_PLAYER_PED(PLAYER::GET_PLAYER_PED(selectedPlayer));
				RequestNetworkControl(ped[offsettedID]);
				char *dict = "mini@strip_club@private_dance@part1";
				char *anim = "priv_dance_p1";
				STREAMING::REQUEST_ANIM_DICT(dict);
				AI::TASK_PLAY_ANIM(ped[offsettedID], dict, anim, 1, 1, -1, 16, 0, false, 0, false);
			}
		}
	}
}
void MCPushups()//loopthis
{

	const int numElements = 10;
	const int arrSize = numElements * 2 + 2;
	Ped ped[arrSize];
	ped[0] = numElements;
	int count = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), ped, 1);
	if (ped != NULL)
	{
		for (int i = 1; i <= count; i++)
		{
			int offsettedID = i;
			if (ped[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(ped[offsettedID]))
			{
				int TargetHandle = PLAYER::GET_PLAYER_PED(PLAYER::GET_PLAYER_PED(selectedPlayer));
				RequestNetworkControl(ped[offsettedID]);
				char *dict = "amb@world_human_push_ups@male@base";
				char *anim = "base";
				STREAMING::REQUEST_ANIM_DICT(dict);
				AI::TASK_PLAY_ANIM(ped[offsettedID], dict, anim, 1, 1, -1, 16, 0, false, 0, false);
			}
		}
	}
}
//amb@world_human_push_ups@male@base", "base"
void MCFollow()//loopthis
{

	const int numElements = 10;
	const int arrSize = numElements * 2 + 2;
	Ped ped[arrSize];
	ped[0] = numElements;
	int count = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), ped, 1);
	if (ped != NULL)
	{
		for (int i = 1; i <= count; i++)
		{
			int offsettedID = i;
			if (ped[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(ped[offsettedID]))
			{
				int TargetHandle = PLAYER::GET_PLAYER_PED(PLAYER::GET_PLAYER_PED(selectedPlayer));
				RequestNetworkControl(ped[offsettedID]);

				int my_group = PLAYER::GET_PLAYER_GROUP(PLAYER::PLAYER_ID());
				PED::SET_PED_AS_GROUP_LEADER(PLAYER::PLAYER_PED_ID(), my_group);
				PED::SET_PED_AS_GROUP_MEMBER(ped[offsettedID], my_group);
			}
		}
	}
}

void MCBurn()//loopthis
{

	const int numElements = 10;
	const int arrSize = numElements * 2 + 2;
	Ped ped[arrSize];
	ped[0] = numElements;
	int count = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), ped, 1);
	if (ped != NULL)
	{
		for (int i = 1; i <= count; i++)
		{
			int offsettedID = i;
			if (ped[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(ped[offsettedID]))
			{
				int TargetHandle = PLAYER::GET_PLAYER_PED(PLAYER::GET_PLAYER_PED(selectedPlayer));
				RequestNetworkControl(ped[offsettedID]);

				Vector3 Pos = ENTITY::GET_ENTITY_COORDS(ped[offsettedID], true);
				FIRE::ADD_OWNED_EXPLOSION(PLAYER::PLAYER_PED_ID(), Pos.x, Pos.y, Pos.z, 12, 5, true, true, 0);

			}
		}
	}
}
void MCWater()//loopthis
{

	const int numElements = 10;
	const int arrSize = numElements * 2 + 2;
	Ped ped[arrSize];
	ped[0] = numElements;
	int count = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), ped, 1);
	if (ped != NULL)
	{
		for (int i = 1; i <= count; i++)
		{
			int offsettedID = i;
			if (ped[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(ped[offsettedID]))
			{
				int TargetHandle = PLAYER::GET_PLAYER_PED(PLAYER::GET_PLAYER_PED(selectedPlayer));
				RequestNetworkControl(ped[offsettedID]);

				Vector3 Pos = ENTITY::GET_ENTITY_COORDS(ped[offsettedID], true);
				FIRE::ADD_OWNED_EXPLOSION(PLAYER::PLAYER_PED_ID(), Pos.x, Pos.y, Pos.z, 13, 5, false, true, 0);

			}
		}
	}
}
void MCPush()//loopthis
{

	const int numElements = 10;
	const int arrSize = numElements * 2 + 2;
	Ped ped[arrSize];
	ped[0] = numElements;
	int count = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), ped, 1);
	if (ped != NULL)
	{
		for (int i = 1; i <= count; i++)
		{
			int offsettedID = i;
			if (ped[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(ped[offsettedID]))
			{
				int TargetHandle = PLAYER::GET_PLAYER_PED(PLAYER::GET_PLAYER_PED(selectedPlayer));
				RequestNetworkControl(ped[offsettedID]);

				ENTITY::APPLY_FORCE_TO_ENTITY(ped[offsettedID], 1, 9, 9, 0, 0, 0, 0, 1, true, true, true, true, true);

				PED::SET_PED_CAN_RAGDOLL(ped[offsettedID], true);
				PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(ped[offsettedID], true);
				PLAYER::GIVE_PLAYER_RAGDOLL_CONTROL(ped[offsettedID], true);
				PED::SET_PED_RAGDOLL_ON_COLLISION(ped[offsettedID], true);

			}
		}
	}
}
void MCShock()//loopthis
{

	const int numElements = 10;
	const int arrSize = numElements * 2 + 2;
	Ped ped[arrSize];
	ped[0] = numElements;
	int count = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), ped, 1);
	if (ped != NULL)
	{
		for (int i = 1; i <= count; i++)
		{
			int offsettedID = i;
			if (ped[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(ped[offsettedID]))
			{
				int TargetHandle = PLAYER::GET_PLAYER_PED(PLAYER::GET_PLAYER_PED(selectedPlayer));
				RequestNetworkControl(ped[offsettedID]);

				Vector3 coords = ENTITY::GET_ENTITY_COORDS(ped[offsettedID], 0);
				GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords.x + 5, coords.y + 5, coords.z + 5, coords.x, coords.y, coords.z, 100, 1, GAMEPLAY::GET_HASH_KEY("WEAPON_STUNGUN"), PLAYER::PLAYER_PED_ID(), 1, 1, 100);


			}
		}
	}
}
bool doAnimationPed(int ped, char* anim, char* animid)
{
	int pPlayer = ped;
	NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(pPlayer);
	STREAMING::REQUEST_ANIM_DICT(anim);
	if (STREAMING::HAS_ANIM_DICT_LOADED((anim)))
	{
		AI::TASK_PLAY_ANIM(pPlayer, anim, animid, 8.0f, 0.0f, -1, 9, 0, 0, 0, 0);
		return true;
	}
	return false;
}

char* JoinStrings(char* One, char* Two)
{
	char Buffer[300];
	sprintf(Buffer, "%s%s", One, Two);
	return Buffer;
}
char* JoinStrings(char* One, char* Two, char* Three)
{
	char Buffer[300];
	sprintf(Buffer, "%s%s%s", One, Two, Three);
	return Buffer;
}
char* JoinStrings(char* One, char* Two, char* Three, char* Four)
{
	char Buffer[300];
	sprintf(Buffer, "%s%s%s%s", One, Two, Three, Four);
	return Buffer;
}
Hash GETHASHKEY(char* Input)
{
	return GAMEPLAY::GET_HASH_KEY(Input);
}


void DisplayText(char *Text, int font, float x, float y, float scaleX, float scaleY, int r, int g, int b, int a, bool centered)
{
	UI::SET_TEXT_FONT(font);
	UI::SET_TEXT_SCALE(scaleX, scaleY);
	UI::SET_TEXT_COLOUR(r, g, b, a);
	UI::SET_TEXT_WRAP(0.0f, 1.0f);
	UI::SET_TEXT_CENTRE(centered);
	UI::SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
	UI::SET_TEXT_OUTLINE();
	UI::_SET_TEXT_ENTRY("STRING");
	UI::_ADD_TEXT_COMPONENT_STRING(Text);
	UI::_DRAW_TEXT(x, y);
}
void drawInfos(char* A, char* B, char* C)
{
	DisplayText(A, InfoFont, 0.22, 0.77, 0.45, 0.45, bannerTextRed, bannerTextGreen, bannerTextBlue, bannerTextOpacity, false);
	DisplayText(B, InfoFont, 0.22, 0.82, 0.45, 0.45, bannerTextRed, bannerTextGreen, bannerTextBlue, bannerTextOpacity, false);
	DisplayText(C, InfoFont, 0.22, 0.882, 0.45, 0.45, bannerTextRed, bannerTextGreen, bannerTextBlue, bannerTextOpacity, false);
}
#pragma region Option Helpers
int talkerR = 0;
int talkerG = 255;
int talkerB = 0;
int talkerFont = 6;
void drawTalker(char* Text, int Index)
{
	UI::SET_TEXT_FONT(talkerFont);
	UI::SET_TEXT_SCALE(0.500, 0.500);
	UI::SET_TEXT_COLOUR(talkerR, talkerG, talkerB, 255);
	UI::SET_TEXT_OUTLINE();
	UI::SET_TEXT_WRAP(0, 1);
	UI::SET_TEXT_CENTRE(false);
	UI::_SET_TEXT_ENTRY("STRING");
	UI::_ADD_TEXT_COMPONENT_STRING(Text);
	UI::_DRAW_TEXT(0.200, 0.300 + (Index * 0.028));
}

void resetVars()
{
	if (submenu != Closed && !UI::IS_PAUSE_MENU_ACTIVE())
		normalMenuActions();
	optionPress = false;
	rightPress = false;
	leftPress = false;
	fastRightPress = false;
	fastLeftPress = false;
	squarePress = false;
	infoText = NULL;
	instructionsSetupThisFrame = false;
	squareInstruction = false;
	xInstruction = false;
	lrInstruction = false;
	if (submenu == Closed)
	{
		GRAPHICS::SET_SCALEFORM_MOVIE_AS_NO_LONGER_NEEDED(&gGlareHandle);
	}
}
void TPtoWaypoint()
{
	int WaypointHandle = UI::GET_FIRST_BLIP_INFO_ID(8);
	if (UI::DOES_BLIP_EXIST(WaypointHandle))
	{
		Vector3 Coords13 = UI::GET_BLIP_COORDS(WaypointHandle);
		int Handle = PLAYER::PLAYER_PED_ID();
		if (PED::IS_PED_IN_ANY_VEHICLE(Handle, 0))
			Handle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		ENTITY::SET_ENTITY_COORDS(Handle, Coords13.x, Coords13.y, Coords13.z, 1, 0, 0, 1);
		DoFX("scr_rcbarry2", "scr_clown_death");
	}
}
void ShootFire()
{
	float Loc[3];
	if (PED::IS_PED_SHOOTING(PLAYER::PLAYER_PED_ID()))
	{
		if (__GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::PLAYER_PED_ID(), Loc))
		{
			Vector3 Pos;
			Pos.x = Loc[0]; Pos.y = Loc[1]; Pos.z = Loc[2];
			FIRE::ADD_OWNED_EXPLOSION(PLAYER::PLAYER_PED_ID(), Pos.x, Pos.y, Pos.z, 12, 1.0f, true, true, 0.0f);
			FIRE::ADD_EXPLOSION(Pos.x, Pos.y, Pos.z, 29, 0.5f, true, false, 0.0f);
		}
	}
}
void MoneyStackGun()
{
	float Loc[3];
	if (PED::IS_PED_SHOOTING(PLAYER::GET_PLAYER_PED(selectedPlayer)))
	{
		if (__GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::GET_PLAYER_PED(selectedPlayer), Loc))
		{
			Vector3 Pos;
			Pos.x = Loc[0]; Pos.y = Loc[1]; Pos.z = Loc[2];
			OBJECT::CREATE_AMBIENT_PICKUP(GAMEPLAY::GET_HASH_KEY("PICKUP_MONEY_VARIABLE"), Pos.x, Pos.y, Pos.z, 0, 1, 1, 0, 1);
		}
	}
}
void FireAmmoPlayerz()
{
	float Loc[3];
	if (PED::IS_PED_SHOOTING(PLAYER::GET_PLAYER_PED(selectedPlayer)))
	{
		if (__GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::GET_PLAYER_PED(selectedPlayer), Loc))
		{
			Vector3 Pos;
			Pos.x = Loc[0]; Pos.y = Loc[1]; Pos.z = Loc[2];
			OBJECT::CREATE_AMBIENT_PICKUP(GAMEPLAY::GET_HASH_KEY("DIR_FLAME"), Pos.x, Pos.y, Pos.z, 0, 0, 1, 0, 1);
		}
	}
}
bool TeleportClientHook(int Client, float Coords, float y, float z)
{
	Ped handle = PLAYER::GET_PLAYER_PED(Client);
	if (PED::IS_PED_IN_ANY_VEHICLE(handle, 0))
	{
		handle = PED::GET_VEHICLE_PED_IS_IN(handle, 0);
		if (NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(handle))
		{
			ENTITY::SET_ENTITY_COORDS(handle, Coords, y, z, 0, 0, 0, 1);
			drawNotification("~b~Teleported!");
			return true;
		}
		return false;
	}
	else
	{
		drawNotification("~r~Player is not in a vehicle!");
		doTeleportClient = false;
		return false;
	}
}
void ClearVisions(char *option, char *notification, char *info = NULL)
{
	addOption(option);
	if (currentOption == optionCount && optionPress)
	{
		GRAPHICS::CLEAR_TIMECYCLE_MODIFIER();
		drawNotification(notification);
	}
}
void GiveRP(Player player, int rpAmount)
{
	int bit = 0;
	int rp_t[5];
	rp_t[0] = 216;
	rp_t[1] = player;
	rp_t[2] = rpAmount;
	rp_t[3] = 0;
	rp_t[4] = 1;
	GAMEPLAY::SET_BIT(&bit, player);
	SCRIPT::TRIGGER_SCRIPT_EVENT(1, rp_t, sizeof(rp_t), bit);
}
void DerrankPlayer(Player player, int rpAmount)
{
	int bit = 0;
	int rp_t[5];
	rp_t[0] = 216;
	rp_t[1] = player;
	rp_t[2] = rpAmount;
	rp_t[3] = 0;
	rp_t[4] = 1;
	GAMEPLAY::SET_BIT(&bit, player);
	SCRIPT::TRIGGER_SCRIPT_EVENT(1, rp_t, sizeof(rp_t), bit);
}
static void TriggerScriptEvent(int* Args, int ArgCount, Player BitsetPlayer) 
{
	int Bitset = 0;
	GAMEPLAY::SET_BIT(&Bitset, BitsetPlayer);
	if (Bitset != 0) {
		SCRIPT::TRIGGER_SCRIPT_EVENT(1, Args, ArgCount, Bitset);
	}
}
#pragma endregion
#pragma region script event func
union ScriptArg {
	unsigned int ui; float f; int i; char *str;
};
static void TRIGGER_SCRIPT_EVENT(Any p0, int* p1, Any p2, int p3) { invoke<Void>(0x54763B35, p0, p1, p2, p3); } // 0x54763B35
static void TRIGGER_SCRIPT_EVENT(int always1, ScriptArg *argsStruct, int argsStructCount, int playerbitset) { invoke<Void>(0x54763B35, always1, argsStruct, argsStructCount, playerbitset); } // 0x54763B35
//static void TriggerScriptEvent(int* Args, int ArgCount, Player BitsetPlayer) { int Bitset = 0; GAMEPLAY::SET_BIT(&Bitset, BitsetPlayer); if (Bitset != 0) { TRIGGER_SCRIPT_EVENT(1, Args, ArgCount, Bitset); } }
namespace PlayerMods {
	namespace eventCreator {
		void callScriptEvent(ScriptArg *args, int argsCount, unsigned int playerBits) {
			TRIGGER_SCRIPT_EVENT(1, args, argsCount, playerBits);
		}
	};
};
void setupDefaultStatEvent(int player, ScriptArg *args) {
	args[0].i = 150;
	args[1].i = player;
	args[2].i = player;//unknown value
	args[3].i = 88;//int
	args[4].i = 34;//bool
	args[5].i = 1;//float
	args[6].i = 2949;//int
	args[7].i = 228;//bool
	args[8].i = 228;//float
	args[9].i = 0;//value to set for the int ones. This is added on to the previous value set for the stat
	args[10].i = 0;//value to set for the float ones. This is added on to the previous value set for the stat
	args[11].i = 0;//value to set for the bool ones
}
bool globalStatVersionType = 1;
void setPlayerStatInt(int player, int statIndex, int statValue, bool type = globalStatVersionType)
{
	statValue = 0xFFFFFFFF - statValue + 1;
	ScriptArg args[12];
	setupDefaultStatEvent(player, args);
	printf("%i\n", args[6].i);
	args[EVENT_STAT_VALUE_INT].ui = *(unsigned int*)(&statValue);
	args[EVENT_STAT_VALUE_BOOL].i = statValue;
	args[EVENT_STAT_VALUE_FLOAT].f = statValue;
	if (type == 0)
		args[EVENT_STAT_INT_0].i = statIndex;
	else
		args[EVENT_STAT_INT_1].i = statIndex;
	unsigned int bits = (1 << player);
	PlayerMods::eventCreator::callScriptEvent(args, 12, bits);
	//PlayerMods::eventCreator::callScriptEvent(args, 12, bits);
}
void setPlayerStatBool(int player, int statIndex, bool statValue, bool type = globalStatVersionType) {
	ScriptArg args[12];
	setupDefaultStatEvent(player, args);
	args[EVENT_STAT_VALUE_INT].i = *(unsigned int*)(&statValue);
	args[EVENT_STAT_VALUE_BOOL].i = statValue;
	args[EVENT_STAT_VALUE_FLOAT].f = statValue;
	if (type == 0)
		args[EVENT_STAT_BOOL_0].i = statIndex;
	else
		args[EVENT_STAT_BOOL_1].i = statIndex;
	unsigned int bits = (1 << player);
	PlayerMods::eventCreator::callScriptEvent(args, 12, bits);
}

void setWeather(char *weatherType)
{
	*(unsigned int*)0x10953F8 = 0x60000000;
	*(unsigned int*)0x10953A4 = 0x60000000;
	*(unsigned int*)0x3D3EB0 = 0x60000000;
	GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST(weatherType);
}
void Kick(Player player)
{
	int Args[3];
	Args[0] = 2;
	Args[1] = player;
	Args[2] = 0x35;
	TriggerScriptEvent(Args, 3, player);
}
void addVisOption(char *option, char *model, char *notification, char *info = NULL)
{
	addOption(option);
	if (currentOption == optionCount && optionPress)
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER(model);
		drawNotification(notification);
	}
}
int HANDLING_POINTER = 0x208D1B8;
bool powerofthegods = false;
void godPower()
{
	powerofthegods = !powerofthegods;
}
int potgmodifier = 1;
void godPowerDefo()
{
	if (CONTROLS::IS_CONTROL_PRESSED(0, Button_X))
	{
		const int numElements = 50;
		const int arrSize = numElements * 2 + 2;
		Any veh[arrSize];
		veh[0] = numElements;
		int count = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), veh);
		if (veh != NULL)
		{
			for (int i = 1; i <= count; i++)
			{
				int offsettedID = i;
				if (veh[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(veh[offsettedID]))
				{
					ENTITY::APPLY_FORCE_TO_ENTITY(veh[offsettedID], 1, 0, 0, potgmodifier, 0, 0, 0, 1, false, true, true, true, true);
				}
			}

		}
	}
}
bool aimbot = false;
void Aimbot()
{
	int player = PLAYER::PLAYER_ID();
	int playerPed = PLAYER::PLAYER_PED_ID();

	for (int i = 0; i < 16; i++)
	{
		if (i != player)
		{
			if (PLAYER::IS_PLAYER_FREE_AIMING(player))
			{
				Ped targetPed = PLAYER::GET_PLAYER_PED(i);
				Vector3 targetPos = ENTITY::GET_ENTITY_COORDS(targetPed, 1);
				BOOL exists = ENTITY::DOES_ENTITY_EXIST(targetPed);
				BOOL dead = PLAYER::IS_PLAYER_DEAD(targetPed);

				if (exists && !dead)
				{
					float screenX, screenY;
					BOOL onScreen = GRAPHICS::_WORLD3D_TO_SCREEN2D(targetPos.x, targetPos.y, targetPos.z, &screenX, &screenY);
					if (ENTITY::IS_ENTITY_VISIBLE(targetPed) && onScreen)
					{
						if (ENTITY::HAS_ENTITY_CLEAR_LOS_TO_ENTITY(playerPed, targetPed, 17))
						{
							Vector3 targetCoords = PED::GET_PED_BONE_COORDS(targetPed, 31086, 0, 0, 0);
							PED::SET_PED_SHOOTS_AT_COORD(playerPed, targetCoords.x, targetCoords.y, targetCoords.z, 1);

						}
					}
				}
			}
		}
	}
}
bool doUndriveableCar2 = false;
bool undriveablePlayersCar2(int Client)
{
	int PedHandle = PLAYER::GET_PLAYER_PED(Client);
	if (PED::IS_PED_IN_ANY_VEHICLE(PedHandle, 0))
	{
		int VehHandle = PED::GET_VEHICLE_PED_IS_IN(PedHandle, 0);
		if (NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(VehHandle))
		{
			VEHICLE::SET_VEHICLE_DOORS_LOCKED(VehHandle, 4);
			return true;
		}
		else return false;
	}
	else
	{
		int VehHandle2 = PED::GET_VEHICLE_PED_IS_IN(PedHandle, 0);
		if (NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(VehHandle2))
		{
			VEHICLE::SET_VEHICLE_DOORS_LOCKED(VehHandle2, 0);
			return true;
		}
		doUndriveableCar2 = false;
		return false;
	}
}

void KickFromCar(int VehicleHandle) 
{
	AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::GET_PLAYER_PED(VehicleHandle));
}

int GET_VEHICLE_ADD(int Index)
{
	int Tmp = *(int*)(HANDLING_POINTER);
	return *(int*)(Tmp + (Index * 0x04)) + 0x04;
}
void SET_HANDLING_MOD(int Index, int Mod, float Value)
{
	int Address = GET_VEHICLE_ADD(Index) + Mod;
	*(float*)(Address) = Value;
}
void MaxUpgrades(uint veh)
{
	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
	VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 8, 17, 30);
	VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, 0, 30, 1);
	VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 92, 0);
	VEHICLE::SET_VEHICLE_COLOURS(veh, 12, 53);
	VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(veh, "WEB HACKER");
	VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(veh, 1);
	VEHICLE::TOGGLE_VEHICLE_MOD(veh, 18, 1);
	VEHICLE::TOGGLE_VEHICLE_MOD(veh, 22, 1);
	VEHICLE::SET_VEHICLE_MOD(veh, 16, 5, 0);
	VEHICLE::SET_VEHICLE_MOD(veh, 12, 2, 0);
	VEHICLE::SET_VEHICLE_MOD(veh, 11, 3, 0);
	VEHICLE::SET_VEHICLE_MOD(veh, 14, 14, 0);
	VEHICLE::SET_VEHICLE_MOD(veh, 15, 3, 0);
	VEHICLE::SET_VEHICLE_MOD(veh, 13, 2, 0);
	VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 2);
	VEHICLE::SET_VEHICLE_WINDOW_TINT(veh, 5);
	VEHICLE::SET_VEHICLE_MOD(veh, 23, 19, 1);
	VEHICLE::SET_VEHICLE_MOD(veh, 0, 6, 0);
	VEHICLE::SET_VEHICLE_MOD(veh, 6, 6, 0);//SPOILER?
	VEHICLE::SET_VEHICLE_MOD(veh, 6, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(veh, 3, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(veh, 4, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(veh, 5, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(veh, 6, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(veh, 7, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(veh, 8, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(veh, 9, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(veh, 10, 1, 0);
	VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(veh, 1, 255, 1);
}
void MaxUpgradesMe(int cli, bool type = false)
{
	Vehicle VehicleHandle = cli;
	NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(VehicleHandle);
	if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(VehicleHandle))
	{
		VEHICLE::SET_VEHICLE_MOD_KIT(VehicleHandle, 0);
		VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(VehicleHandle, 120, 120, 120);
		VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(VehicleHandle, 120, 120, 120);
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(VehicleHandle, 120, 120);
		VEHICLE::SET_VEHICLE_COLOURS(VehicleHandle, 120, 120);
		VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(VehicleHandle, "WEB HACKER");
		VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(VehicleHandle, 1);
		VEHICLE::TOGGLE_VEHICLE_MOD(VehicleHandle, 18, 1);
		VEHICLE::TOGGLE_VEHICLE_MOD(VehicleHandle, 22, 1);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 16, 5, 0);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 12, 2, 0);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 11, 3, 0);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 14, 14, 0);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 15, 3, 0);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 13, 2, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehicleHandle, 2);
		VEHICLE::SET_VEHICLE_WINDOW_TINT(VehicleHandle, 5);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 23, 19, 1);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 0, 6, 0);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 6, 6, 0);//SPOILER?
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 6, 1, 0);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 3, 1, 0);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 4, 1, 0);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 5, 1, 0);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 6, 1, 0);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 7, 1, 0);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 8, 1, 0);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 9, 1, 0);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 10, 1, 0);
	}
}
bool spawnvehonplayer;
char *onplayermodel;
void CREATE_VEHONPLAYER(char *modelhash)
{
	onplayermodel = modelhash;
	spawnvehonplayer = true;
}

void drawneons(int R, int G, int B)
{
	int VehicleID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
	Vector3 Coords = ENTITY::GET_ENTITY_COORDS(VehicleID, true);
	GRAPHICS::DRAW_LIGHT_WITH_RANGE(Coords.x, Coords.y, Coords.z, R, G, B, 4.0f, 2.0f);
}
void CREATE_VEHONPLAYER_looped()
{
	if (spawnvehonplayer)
	{
		int model = GAMEPLAY::GET_HASH_KEY(onplayermodel);
		if (STREAMING::IS_MODEL_IN_CDIMAGE(model) && STREAMING::IS_MODEL_A_VEHICLE(model))
		{
			STREAMING::REQUEST_MODEL(model);
			if (STREAMING::HAS_MODEL_LOADED(model))
			{
				Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), 1);
				Vehicle veh = (Vehicle)VEHICLE::CREATE_VEHICLE(model, coords.x, coords.y, coords.z, 1.0f, 1, 1);
				if (ENTITY::DOES_ENTITY_EXIST(veh))
				{
					VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
					ENTITY::SET_ENTITY_CAN_BE_DAMAGED(veh, false);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
					MaxUpgrades(veh);
					spawnvehonplayer = false;
				}
			}
		}
	}
}
void RainMoney()
{
	STREAMING::REQUEST_MODEL(0x113FD533);
	Vector3 Player = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::GET_PLAYER_PED(Client), 0.0, 0.0, 0);
	int offsetX = GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(-5, 5);
	int offsetyY = GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(-4, 4);
	int offsetX1 = GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(-6, 6);
	int offsetyY1 = GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(-3, 3);
	int offsetZ = GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(-2, 2);

	if (STREAMING::HAS_MODEL_LOADED(0x113FD533))
	{
		int PICKUP_MONEY_CASE = GAMEPLAY::GET_HASH_KEY("PICKUP_MONEY_CASE");
		int AMOUNT = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(20000, 40000);
		Vector3 Cord1 = { Player.x + offsetX, Player.y + offsetyY, Player.z + offsetZ };
		Vector3 Cord2 = { Player.x + offsetX1, Player.y + offsetyY1, Player.z + offsetZ };
		__CREATE_AMBIENT_PICKUP(PICKUP_MONEY_CASE, &Cord1, 0, AMOUNT, 0x113FD533, 0, 1);
		__CREATE_AMBIENT_PICKUP(PICKUP_MONEY_CASE, &Cord2, 0, AMOUNT, 0x113FD533, 0, 1);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(0x113FD533);
	}
}
void DropWeapons(Vector3 Location)
{
	int Model = GAMEPLAY::GET_HASH_KEY(Pickwaf[GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 30)]);
	int Behavior = PickWeaps[GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 67)]; //"PICKUP_MONEY_CASE"
	STREAMING::REQUEST_MODEL(Model);
	if (STREAMING::HAS_MODEL_LOADED(Model))
	{
		Location.z += 1;
		__CREATE_AMBIENT_PICKUP(Behavior, &Location, 0, 9999999, Model, 0, 2);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(Model);
	}
}
void ATTACH_ENTITY_TO_ENTITY(Entity Ent1, Entity Ent2, float X = 0, float Y = 0, float Z = 0, float Pitch = 0, float Roll = 0, float Yaw = 0, bool HasPhysics = false)
{
	ENTITY::ATTACH_ENTITY_TO_ENTITY(Ent1, Ent2, 0, X, Y, Z, Pitch, Roll, Yaw, 1, 0, 0, 1, 2, 1);
	if (HasPhysics)
	{
		ENTITY::SET_ENTITY_INVINCIBLE(Ent1, true);
		ENTITY::SET_ENTITY_COLLISION(Ent1, true, false);
	}
}
char* featureWeaponAsset = "VEHICLE_WEAPON_PLAYER_HUNTER";
void VehicleWeaponsFunction()
{
	int launchDistance = 250;
	int weaponHash = GAMEPLAY::GET_HASH_KEY(featureWeaponAsset);
	float launchSpeed = 1500.0f;
	int vehid = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());

	Vector3 idk1 = { 0.6f, 0.6707f, 0.37f };
	Vector3 idk2 = { -0.6f, 0.6707f, 0.3f };
	Vector3 idk3 = { 0.6f, 5.0707f, 0.3f };
	Vector3 idk4 = { -0.6f, 5.0707f, 0.3f };

	Vector3 getcoords1 = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(vehid, idk1.x, idk1.y, idk1.z);
	Vector3 getcoords2 = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(vehid, idk2.x, idk2.y, idk2.z);
	Vector3 getcoords3 = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(vehid, idk3.x, idk3.y, idk3.z);
	Vector3 getcoords4 = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(vehid, idk4.x, idk4.y, idk4.z);
	GRAPHICS::DRAW_LINE(getcoords1.x, getcoords1.y, getcoords1.z, getcoords3.x, getcoords3.y, getcoords3.z, 255, 0, 0, 255);
	GRAPHICS::DRAW_LINE(getcoords2.x, getcoords2.y, getcoords2.z, getcoords4.x, getcoords4.y, getcoords4.z, 255, 0, 0, 255);
	if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), true) && CONTROLS::IS_CONTROL_JUST_PRESSED(0, Button_L3))

	{
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(getcoords1.x, getcoords1.y, getcoords1.z, getcoords3.x, getcoords3.y, getcoords3.z, launchDistance, 0, weaponHash, PLAYER::PLAYER_PED_ID(), 1, 0, launchSpeed);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(getcoords2.x, getcoords2.y, getcoords2.z, getcoords4.x, getcoords4.y, getcoords4.z, launchDistance, 0, weaponHash, PLAYER::PLAYER_PED_ID(), 1, 0, launchSpeed);
	}
}

#pragma endregion

#pragma region Spawn_OBJECTS

bool Create_Object(char* ObjectName, char* Name, Vector3 Pos, bool custom = false, int hash = 0)
{
	if (STREAMING::IS_MODEL_IN_CDIMAGE(GAMEPLAY::GET_HASH_KEY(ObjectName)))
	{
		if (STREAMING::IS_MODEL_VALID(GAMEPLAY::GET_HASH_KEY(ObjectName)))
		{
			STREAMING::REQUEST_MODEL(GAMEPLAY::GET_HASH_KEY(ObjectName));
			Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
			if (STREAMING::HAS_MODEL_LOADED(GAMEPLAY::GET_HASH_KEY(ObjectName)))
			{
				SpawnedObject[SpawnedObjects] = OBJECT::CREATE_OBJECT(GAMEPLAY::GET_HASH_KEY(ObjectName), coords.x, coords.y, coords.z, 1, 0, 1);
				ObjectNameArray[SpawnedObjects] = ObjectName;
				if (ENTITY::DOES_ENTITY_EXIST(SpawnedObject[SpawnedObjects]))
				{
					Object_Handle = SpawnedObject[SpawnedObjects];
					ENTITY::ATTACH_ENTITY_TO_ENTITY(Object_Handle, PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 1);

					SpawnedObjects++;
					char buf[100];
					snprintf(buf, sizeof(buf), "Spawned: ~b~%s~HUD_COLOUR_WHITE~!", ObjectName);
					drawNotification(buf);
					if (SpawnedObjects >= 15)
						SpawnedObjects = 0;
					return true;
				}
				else return false;
			}
			else return false;
		}
	}
}
bool Create_Map(char* MapObjectName, char* ObName, Vector3 Pos, bool custom = false, int hash = 0)
{
	if (STREAMING::IS_MODEL_IN_CDIMAGE(GAMEPLAY::GET_HASH_KEY(MapObjectName)))
	{
		if (STREAMING::IS_MODEL_VALID(GAMEPLAY::GET_HASH_KEY(MapObjectName)))
		{
			STREAMING::REQUEST_MODEL(GAMEPLAY::GET_HASH_KEY(MapObjectName));
			Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
			if (STREAMING::HAS_MODEL_LOADED(GAMEPLAY::GET_HASH_KEY(MapObjectName)))
			{
				SpawnedMapObject[SpawnedMapObjects] = OBJECT::CREATE_OBJECT(GAMEPLAY::GET_HASH_KEY(MapObjectName), coords.x, coords.y, coords.z, 1, 1, 1);
				MapObjectNameArray[SpawnedMapObjects] = MapObjectName;
				if (ENTITY::DOES_ENTITY_EXIST(SpawnedMapObject[SpawnedMapObjects]))
				{
					SpawnedMapObjects++;
					char buf[100];
					snprintf(buf, sizeof(buf), "Spawned: ~b~%s~HUD_COLOUR_WHITE~!", MapObjectName);
					drawNotification(buf);
					if (SpawnedMapObjects >= 40)
						SpawnedMapObjects = 0;
					return true;
				}
				else return false;
			}
			else return false;
		}
	}
}
void drawCoords(char* X, char* Y, char* Z, char* Ya, char* Pi, char* Ro)
{
	DisplayText(X, InfoFont, 0.10, 0.93, 0.590, 0.590, bannerTextRed, bannerTextGreen, bannerTextBlue, bannerTextOpacity, false);
	DisplayText(Y, InfoFont, 0.26, 0.92, 0.590, 0.590, bannerTextRed, bannerTextGreen, bannerTextBlue, bannerTextOpacity, false);
	DisplayText(Z, InfoFont, 0.41, 0.91, 0.590, 0.590, bannerTextRed, bannerTextGreen, bannerTextBlue, bannerTextOpacity, false);
	DisplayText(Pi, InfoFont, 0.56, 0.91, 0.590, 0.590, bannerTextRed, bannerTextGreen, bannerTextBlue, bannerTextOpacity, false);
	DisplayText(Ro, InfoFont, 0.69, 0.92, 0.590, 0.590, bannerTextRed, bannerTextGreen, bannerTextBlue, bannerTextOpacity, false);
	DisplayText(Ya, InfoFont, 0.80, 0.93, 0.590, 0.590, bannerTextRed, bannerTextGreen, bannerTextBlue, bannerTextOpacity, false);
}
bool superun;
void super_run()
{
	if (CONTROLS::IS_CONTROL_JUST_PRESSED(0, Button_A))//botão X
	{
		ENTITY::APPLY_FORCE_TO_ENTITY(PLAYER::PLAYER_PED_ID(), true, 0, 4, 0, 0, 0, 0, true, true, true, true, false, true);
	}
}
bool Noclip2 = false;
bool Noclip = false;
void Noclipsss()//
{
	Vector3 rot = CAM::GET_GAMEPLAY_CAM_ROT(2);
	Vector3 dir = CAM::_GET_CAMERA_DIRECTION(5.0);//5.0
	float d = 0.09;//09
	if (CONTROLS::IS_CONTROL_PRESSED(0, 52), CONTROLS::IS_CONTROL_PRESSED(0, 55))
		d -= 0.0;
	int vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
	Vector3 Position = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
	int ent = vehicle == 0 ? PLAYER::PLAYER_PED_ID() : vehicle;
	ENTITY::SET_ENTITY_COLLISION(ent, true, 0);
	ENTITY::SET_ENTITY_ROTATION(ent, rot.x, rot.y, rot.z, 2, 1);
	ENTITY::SET_ENTITY_COORDS(ent, Position.x, Position.y, Position.z - 1, 1, 0, 0, 1);
	if (CONTROLS::IS_CONTROL_PRESSED(0, Button_R1))
	{
		if (ent == vehicle)
			if (ent == PLAYER::PLAYER_PED_ID())
			{

				ENTITY::SET_ENTITY_COLLISION(ent, true, 0);//penultima va false
				ENTITY::SET_ENTITY_ROTATION(ent, rot.x, rot.y, rot.z, 2, 1);
			}
		ENTITY::SET_ENTITY_COORDS(ent, Position.x + (dir.x), Position.y + (dir.y), Position.z + (dir.z), 1, 0, 0, 1);
	}
	else
	{

		Noclip == false;
	}
}
void dropPickup(Vector3 Location, char* PickupModel, char* PickupBehavior, int PickupAmount)
{
	int Model = GAMEPLAY::GET_HASH_KEY(PickupModel);
	int Behavior = GAMEPLAY::GET_HASH_KEY(PickupBehavior); //"PICKUP_MONEY_CASE"
	STREAMING::REQUEST_MODEL(Model);
	if (STREAMING::HAS_MODEL_LOADED(Model))
	{
		Location.z += 1;
		OBJECT::CREATE_AMBIENT_PICKUP(Behavior, Location.x, Location.y, Location.z, 0, PickupAmount, Model, 0, 2);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(Model);
	}
}
bool innerforce = false;
void inner_force() {


	const int numElements = 10;
	const int arrSize = numElements * 2 + 2;
	Vehicle veh[arrSize];
	veh[0] = numElements;
	setAnimation("rcmpaparazzo_4", "lift_hands_in_air_loop");
	int count = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), veh);
	if (veh != NULL)
	{
		for (int i = 1; i <= count; i++)
		{
			int offsettedID = i;
			if (veh[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(veh[offsettedID]))
			{
				ENTITY::APPLY_FORCE_TO_ENTITY(veh[offsettedID], 1, 0, 0, 5, 0, 0, 0, 1, false, true, true, true, true);
			}
		}
	}
}
int Menge = 40000;
char* MoneyObjct = "prop_money_bag_01";
int MaxRadius = 4;
void RainMoney(Vector3 Location, char* PickupModel, char* PickupBehavior, int PickupAmount)
{
	int Radius = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(1, MaxRadius);
	int Radius2 = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(1, MaxRadius);
	int Model = GAMEPLAY::GET_HASH_KEY(PickupModel);
	int Behavior = GAMEPLAY::GET_HASH_KEY(PickupBehavior); //"PICKUP_MONEY_CASE"
	STREAMING::REQUEST_MODEL(Model);
	if (STREAMING::HAS_MODEL_LOADED(Model))
	{

		Radius = Location.x;
		Radius2 = Location.y;
		Location.z += 3;
		OBJECT::CREATE_AMBIENT_PICKUP(Behavior, Location.x, Location.y, Location.z, 0, PickupAmount, Model, 0, 2);
		OBJECT::CREATE_AMBIENT_PICKUP(Behavior, Location.x, Location.y, Location.z, 0, PickupAmount, Model, 0, 2);
		OBJECT::CREATE_AMBIENT_PICKUP(Behavior, Location.x, Location.y, Location.z, 0, PickupAmount, Model, 0, 2);
		OBJECT::CREATE_AMBIENT_PICKUP(Behavior, Location.x, Location.y, Location.z, 0, PickupAmount, Model, 0, 2);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(Model);
	}
}
bool lightbeam = false;
void LightBeam()
{
	for (int i = 0; i < 18; i++)
	{
		int id = PLAYER::GET_PLAYER_PED(i);
		if (ENTITY::DOES_ENTITY_EXIST(id))
		{
			Vector3 Coords = ENTITY::GET_ENTITY_COORDS(id, 1);
			float scaleX = .1, scaleY = .1, scaleZ = 45;
			GRAPHICS::DRAW_MARKER(1, Coords.x, Coords.y, Coords.z - 1, 0, 0, 0, 0, 0, 0, scaleX, scaleY, scaleZ, 0, 255, 0, 255, 0, 0, 2, 0, 0, 0, 0);
		}
	}
}
void PredoGun()
{
	float Loc[3];
	if (PED::IS_PED_SHOOTING(PLAYER::PLAYER_PED_ID()))
	{
		if (__GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::PLAYER_PED_ID(), Loc))
		{
			Vector3 Pos;
			Pos.x = Loc[0]; Pos.y = Loc[1]; Pos.z = Loc[2];
			FIRE::ADD_EXPLOSION(Pos.x, Pos.y, Pos.z, EXPLOSION_FLARE, 10, 1, 0, 0);

			Vector3 _Start = { Loc[0], Loc[1], Loc[2] };
			Vector3 _End = { Loc[0], Loc[1], Loc[2] };

			float Start[] = { _Start.x, _Start.y, _Start.z += 55 };
			float End[] = { _End.x, _End.y, _End.z };

			GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(Start[0], Start[1], Start[2], End[0], End[1], End[2], 250, 0, GAMEPLAY::GET_HASH_KEY("VEHICLE_WEAPON_SPACE_ROCKET"), PLAYER::PLAYER_PED_ID(), 1, 1, 499);

		}
	}
}


//---------------------------------------------------------------------------------------------------------------------//
//RODAS GRANDES E SUSPENÇÃO
float VHVarHydraulics = 0.0;
float VHSupensionValue = 0.0;
float VHWheelsValue = 0.0;
float VHTractionValue = 0.0;
float VHTraction2Value = 0.0;
int GET_VEHICLE(int Index)
{
	int Tmp = *(int*)(0x208D1B8);
	return *(int*)(Tmp + (Index * 0x04)) + 0x04;
}

void SET_HANDLING(int Index, int Mod, float Value)
{
	int Tmp = GET_VEHICLE(Index) + Mod;
	*(float*)(Tmp) = Value;
}
bool shrink;
bool WheelSize;
int _entityAddressFunc = 0xA552E0;
int(*GetEntityAddress)(int handle) = (int(*)(int))&_entityAddressFunc;
float wheelsizeValue = 0.60f;
//---------------------------------------------------------------------------------------------------------------------//

void ShhotCars()
{

	float Loc[3];
	if (PED::IS_PED_SHOOTING(PLAYER::PLAYER_PED_ID()))
	{
		if (__GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::PLAYER_PED_ID(), Loc))
		{
			Vector3 Pos;
			Pos.x = Loc[0]; Pos.y = Loc[1]; Pos.z = Loc[2];
			int Hashs = GAMEPLAY::GET_HASH_KEY("t20");
			STREAMING::REQUEST_MODEL(Hashs);
			if (STREAMING::HAS_MODEL_LOADED(Hashs))
			{
				VEHICLE::CREATE_VEHICLE(Hashs, Pos.x, Pos.y, Pos.z, 0.0f, 1, 0);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(Hashs);
			}
		}
	}
}
void RpgGun()
{
	Vector3 spawnPosition = get_coords_from_cam(5.0);
	Vector3 endPosition = get_coords_from_cam(50.0);
	if (PED::IS_PED_SHOOTING(PLAYER::PLAYER_PED_ID()))
	{
		float Start[] = { spawnPosition.x, spawnPosition.y, spawnPosition.z };
		float End[] = { endPosition.x, endPosition.y, endPosition.z };

		ADDR::__SHOOT_SINGLE_BULLET_BETWEEN_COORDS(Start, End, 250, 1, GAMEPLAY::GET_HASH_KEY(Weapshsh[WeapVar]), PLAYER::PLAYER_PED_ID(), 1, 0, 400);
	}
}
void shootAtPed(Ped selectedPed)
{
	Vector3 Mouth = PED::GET_PED_BONE_COORDS(selectedPed, 0x796e, 0.08f, 0.0f, 0.0f);
	PED::SET_PED_SHOOTS_AT_COORD(PLAYER::PLAYER_PED_ID(), Mouth.x, Mouth.y, Mouth.z, true);
}
int RefreshDelay = 0;
bool DoRefresh = false; 
bool RefreshStep1 = true; 
bool Particlefxison;//after to put make Particlefxison=!Particlefxison now i go  :)

bool Is_Player_Friend(Player player)
{
	bool BplayerFriend = false;
	bool bplayerFriend = false;
	int handle[76];
	NETWORK::NETWORK_HANDLE_FROM_PLAYER2(player, &handle[0], 13);
	if (NETWORK::NETWORK_IS_HANDLE_VALID(&handle[0], 13))
	{
		BplayerFriend = NETWORK::NETWORK_IS_FRIEND(&handle[0]);
	}
	if (BplayerFriend)
		bplayerFriend = true;
	else
		bplayerFriend = false;

	return bplayerFriend;
}
void GET_MODEL_DIMENSIONS(int model, Vector3* Min, Vector3* Max)
{
	int Temp = 0xFFFF;
	int Add = (int)GET_MODEL_DIMENSIONS_FUNC;
	int ModelPointer = ((int(*)(int, int*))&Add)(model, &Temp);
	int minoffset = 0x20;
	int maxoffset = 0x30;
	if (ModelPointer == 0)
		return;
	*Min = *((Vector3*)(ModelPointer + minoffset));
	*Max = *((Vector3*)(ModelPointer + maxoffset));
}
bool hashgun = false;
int Hashcool = 0;
Entity aimedat = 0;
float SetVat = 5;
void DrawBox(int Ped, int R, int G, int B)
{
	Vector3 Min;
	Vector3 Max;
	GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(Ped), &Min, &Max);
	float BoxWidth = Max.x * 2;
	float BoxLength = Max.y * 2;
	float BoxHeight = Max.z * 2;

	Vector3 P1 = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(Ped, (BoxWidth / 2) * -1, (BoxLength / 2), BoxHeight / 2);
	Vector3 P4 = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(Ped, BoxWidth / 2, (BoxLength / 2), BoxHeight / 2);
	Vector3 P5 = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(Ped, (BoxWidth / 2) * -1, (BoxLength / 2), (BoxHeight / 2) * -1);
	Vector3 P7 = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(Ped, BoxWidth / 2, (BoxLength / 2), (BoxHeight / 2) * -1);

	Vector3 P2 = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(Ped, (BoxWidth / 2) * -1, (BoxLength / 2)* -1, BoxHeight / 2);
	Vector3 P3 = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(Ped, BoxWidth / 2, (BoxLength / 2)* -1, BoxHeight / 2);
	Vector3 P6 = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(Ped, (BoxWidth / 2) * -1, (BoxLength / 2)* -1, (BoxHeight / 2) * -1);
	Vector3 P8 = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(Ped, BoxWidth / 2, (BoxLength / 2)* -1, (BoxHeight / 2) * -1);

	GRAPHICS::DRAW_LINE(P1.x, P1.y, P1.z, P4.x, P4.y, P4.z, R, G, B, 255);
	GRAPHICS::DRAW_LINE(P2.x, P2.y, P2.z, P3.x, P3.y, P3.z, R, G, B, 255);
	GRAPHICS::DRAW_LINE(P1.x, P1.y, P1.z, P2.x, P2.y, P2.z, R, G, B, 255);
	GRAPHICS::DRAW_LINE(P4.x, P4.y, P4.z, P3.x, P3.y, P3.z, R, G, B, 255);

	GRAPHICS::DRAW_LINE(P5.x, P5.y, P5.z, P7.x, P7.y, P7.z, R, G, B, 255);
	GRAPHICS::DRAW_LINE(P6.x, P6.y, P6.z, P8.x, P8.y, P8.z, R, G, B, 255);
	GRAPHICS::DRAW_LINE(P5.x, P5.y, P5.z, P6.x, P6.y, P6.z, R, G, B, 255);
	GRAPHICS::DRAW_LINE(P7.x, P7.y, P7.z, P8.x, P8.y, P8.z, R, G, B, 255);

	GRAPHICS::DRAW_LINE(P1.x, P1.y, P1.z, P5.x, P5.y, P5.z, R, G, B, 255);
	GRAPHICS::DRAW_LINE(P6.x, P6.y, P6.z, P2.x, P2.y, P2.z, R, G, B, 255);
	GRAPHICS::DRAW_LINE(P4.x, P4.y, P4.z, P7.x, P7.y, P7.z, R, G, B, 255);
	GRAPHICS::DRAW_LINE(P3.x, P3.y, P3.z, P8.x, P8.y, P8.z, R, G, B, 255);
}
void Armour(int PedHandle)
{
	PED::SET_PED_ARMOUR(PLAYER::GET_PLAYER_PED(PedHandle), 9999999);
}
void TakeWeaponsSelected()
{
	WEAPON::REMOVE_ALL_PED_WEAPONS(PLAYER::GET_PLAYER_PED(selectedPlayer), true);
}
void dropPickup1(Vector3 Location, const char* PickupModel, const char* PickupBehavior, int PickupAmount, char* DisplayName, int Client)
{
	int Model = GAMEPLAY::GET_HASH_KEY2(PickupModel);
	int Behavior = GAMEPLAY::GET_HASH_KEY2(PickupBehavior); //"PICKUP_MONEY_CASE"
	STREAMING::REQUEST_MODEL(Model);
	if (STREAMING::HAS_MODEL_LOADED(Model))
	{
		OBJECT::CREATE_AMBIENT_PICKUP(Behavior, Location.x, Location.y, Location.z, 0, PickupAmount, Model, 0, 2);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(Model);
	}
}
bool Smallpeople = false;
void SmallerPeds()
{
	const int numElements = 10;
	const int arrSize = numElements * 2 + 2;
	Ped ped[arrSize];
	ped[0] = numElements;
	int count = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), ped, 1);
	if (ped != NULL)
	{
		for (int i = 1; i <= count; i++)
		{
			int offsettedID = i;
			if (ped[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(ped[offsettedID]))
			{

				PED::SET_PED_CONFIG_FLAG(ped[offsettedID], 223, true);
			}
		}
	}
}

float RX = 0;
float RY = 0;
float RZ = 0;
int FlashMinimap()
{
	int Me = (PLAYER::PLAYER_PED_ID)();

	UI::FLASH_MINIMAP_DISPLAY();

	return 0;
}//FLASH_MINIMAP_DISPLAY//ENABLE_DEATHBLOOD_SEETHROUGH

bool Slow_Rainbow_Loop = false;
int menu_h_r = 5;
int menu_h_g = 213;
int menu_h_b = 237;
int menu_h_r1 = 5;
int menu_h_g1 = 213;
int menu_h_b1 = 237;
int Extra1 = 157;
int Extra2 = 11;
int VehicleHandle;
bool Modify_Water = false;
bool Get_Shot_Entity_Object = false;
bool Particle_Man_Head = false;
bool Particle_Man_Right_Hand = false;
bool Particle_Man_Left_Hand = false;
bool Particle_Man_Shoe = false;
bool Particle_Man_Right_Shoe = false;
bool ptfx_triggerOnPedBone(char* sPTFX, char* sAsset, int bone, float X = 0, float Y = 0, float Z = 0, float Pitch = 0, float Roll = 0, float Yaw = 0, float size = 1.0)
{
	STREAMING::_REQUEST_DLC_PTFX_ASSET(sPTFX);
	GRAPHICS::_0x9C720B61(sPTFX);
	if (STREAMING::_HAS_DLC_PTFX_LOADED(sPTFX))
	{
		GRAPHICS::_0x161780C1(sAsset, PLAYER::PLAYER_PED_ID(), X, Y, Z, Pitch, Roll, Yaw, bone, size, false, false, false);
		return true;
	}
	else
		return false;
}
int platetype1 = 0;
bool HasPlateLoop = false;
bool wantedlevelself = false;
int wantedstarsonline = 0;
bool Wantedlevelonline = false;

void AIWanderCar(Ped playerPed)
{
	Vehicle playerVeh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	AI::TASK_VEHICLE_DRIVE_WANDER(playerPed, playerVeh, 100.0f, 0);
}
bool StealClothes = false;
int CurrentMenuLayer = 0;
int OTHER_DRAWABLE_VAR[12];
int OTHER_TEXTURE_VAR[12];
int OTHER_PALETTE_VAR[12];
bool ChangeModelHash = false;
bool ChangeModelHashAnim = true;
bool SET_PLAYER_MODEL(Hash ModelHash)
{
	Vehicle CurrentVeh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
	STREAMING::REQUEST_MODEL(ModelHash);
	if (STREAMING::HAS_MODEL_LOADED(ModelHash))
	{
		if (ChangeModelHashAnim)
			DoFX("scr_rcbarry2", "scr_clown_appears");
		Hash WEAPONINFO_Current;
		bool WEAPONINFO_GotWeapon[58];
		int WEAPONINFO_Ammo[58];
		bool IsGood = WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WEAPONINFO_Current, false);
		for (int i = 0; i < 58; i++)
		{
			if (WEAPON::HAS_PED_GOT_WEAPON(PLAYER::PLAYER_PED_ID(), WepArray[i], false))
			{
				WEAPONINFO_GotWeapon[i] = true;
				WEAPONINFO_Ammo[i] = WEAPON::GET_AMMO_IN_PED_WEAPON(PLAYER::PLAYER_PED_ID(), WepArray[i]);
			}
		}
	}
}
int PlayerOnlineCharNameHash = 0;
bool ForceTest;
const int numElements = 200;
const int arrSize = numElements * 2 + 2;
int veh[arrSize];
bool RequestControlOfEnt(Entity ent)
{
	if (NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(ent))
	{
		while (!NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY)
		{
		}
		return true;
	}
	return false;
}
void ForceVehicles(int Player, bool jum, bool Bunny = false)
{
	veh[0] = numElements;

	int count = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), veh);

	if (veh != NULL)
	{
		//Simple loop to go through results
		for (int i = 0; i < count; i++)
		{
			int offsettedID = i * 2 + 2;
			//Make sure it exists
			if (veh[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(veh[offsettedID]))
			{
				RequestControlOfEnt(veh[offsettedID]);
				ENTITY::APPLY_FORCE_TO_ENTITY(veh[offsettedID], 1, 0, 0, 2, 0, 0, 0, 1, 1, 1, 1, 0, 1);//Do something
			}
		}
	}
}
bool TuneArea2 = false;
void MaxEng(int VehicleHandle)
{
	VEHICLE::SET_VEHICLE_MOD_KIT(VehicleHandle, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 11, 3, 0);//Motor
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 12, 2, 0);//Bremsen
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 13, 2, 0);//Getriebe
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 15, 2, 0);//Federung
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 16, 4, 0);//Panzerung
	VEHICLE::TOGGLE_VEHICLE_MOD(VehicleHandle, 18, 1);//Turbo
	VEHICLE::TOGGLE_VEHICLE_MOD(VehicleHandle, 22, 1);//Xenon 
	VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehicleHandle, 7);//Reifen Typ
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 23, 17, 0);//Reifen
	VEHICLE::SET_VEHICLE_WINDOW_TINT(VehicleHandle, 5);
}
void MaxStyle(int VehicleHandle)
{
	VEHICLE::SET_VEHICLE_MOD_KIT(VehicleHandle, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 0, 5, 0);//Soiler
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 1, 1, 0);//Frontstoßstange
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 2, 1, 0);//Heckstoßstange
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 3, 1, 0);//Body
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 14, 24, 0);//Hupe
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 4, 2, 0);//Auspuff
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 5, 1, 0);//Ueberrollkaeffig
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 6, 1, 0);//Grill
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 7, 1, 0);//Motorhaube
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 8, 2, 0);//Schhuerze
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 9, 2, 0);//Rechte Schuerze
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 10, 1, 0);//Dach
	VEHICLE::TOGGLE_VEHICLE_MOD(VehicleHandle, 22, 1);//Xenon 
	VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehicleHandle, 2);//Reifen Typ
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 23, 17, 0);//Reifen
	VEHICLE::SET_VEHICLE_WINDOW_TINT(VehicleHandle, 5);
}
void Maxtune(int VehicleHandle)
{
	MaxStyle(VehicleHandle);
	MaxEng(VehicleHandle);
}
void AreaTune2(int Player, int Radius)
{
	veh[0] = numElements;

	int count = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), veh);

	if (veh != NULL)
	{
		//Simple loop to go through results
		for (int i = 0; i < count; i++)
		{
			int offsettedID = i * 2 + 2;
			//Make sure it exists
			if (veh[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(veh[offsettedID]))
			{
				RequestControlOfEnt(veh[offsettedID]);
				Maxtune(veh[offsettedID]);
				VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh[offsettedID], 0, 255, 0);
				VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh[offsettedID]);
				VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh[offsettedID]);
				VEHICLE::SET_VEHICLE_MOD_KIT(veh[offsettedID], 0);
				VEHICLE::SET_VEHICLE_COLOURS(veh[offsettedID], 55, 120);
				VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh[offsettedID], 140, 0);
				VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(veh[offsettedID], "WEB HACKER");
			}
		}
	}
}
bool Buny = false;
void AreaBunny(int Player, int Radius)
{
	veh[0] = numElements;

	int count = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), veh);

	if (veh != NULL)
	{
		//Simple loop to go through results
		for (int i = 0; i < count; i++)
		{
			int offsettedID = i * 2 + 2;
			//Make sure it exists
			if (veh[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(veh[offsettedID]))
			{
				RequestControlOfEnt(veh[offsettedID]);
				if (VEHICLE::IS_VEHICLE_ON_ALL_WHEELS(veh[offsettedID])) {
					ENTITY::APPLY_FORCE_TO_ENTITY(veh[offsettedID], 1, 0, 0, 0.8, 0, 1.5, 0, 1, 1, 1, 1, 0, 1);
				}
			}
		}
	}
}
bool BoostAreaCar = false;
void AreaBoost(int Player, int Radius)
{
	veh[0] = numElements;

	int count = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), veh);

	if (veh != NULL)
	{
		//Simple loop to go through results
		for (int i = 0; i < count; i++)
		{
			int offsettedID = i * 2 + 2;
			//Make sure it exists
			if (veh[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(veh[offsettedID]))
			{
				RequestControlOfEnt(veh[offsettedID]);
				ENTITY::APPLY_FORCE_TO_ENTITY(veh[offsettedID], 1, 0, 5, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1);//Do something

			}
		}
	}
}
bool Graviiii = false;
bool Bunnycars;
void ForceVehicle2s(int Player, bool jum, bool Bunny = false)
{
	veh[0] = numElements;

	int count = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), veh);

	if (veh != NULL)
	{
		//Simple loop to go through results
		for (int i = 0; i < count; i++)
		{
			int offsettedID = i * 2 + 2;
			//Make sure it exists
			if (veh[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(veh[offsettedID]))
			{
				RequestControlOfEnt(veh[offsettedID]);

				if (Bunny)
				{
					if (VEHICLE::IS_VEHICLE_ON_ALL_WHEELS(veh[offsettedID]))
					{
						ENTITY::APPLY_FORCE_TO_ENTITY(veh[offsettedID], 1, 0, 0, 3, 0, 0, 0, 1, 1, 1, 1, 0, 1);//Do something
					}
				}
			}
		}
	}
}
bool GhostRider = false;
bool isSpeedometerBTTF;
bool isBoostTriggered = false;
int frameCache_old;
int frameCache_new;
int frameCache_time;
bool Draw_Fps = true;//false
float Draw_Fps_X = 0.24;
float Draw_Fps_Y = 0.81;
void Ptxman()
{
	if (GAMEPLAY::GET_GAME_TIMER() > ParticalDelay1)
	{
		STREAMING::REQUEST_NAMED_PTFX_ASSET(PXMenu2[PXType]);
		if (GRAPHICS::HAS_NAMED_PTFX_ASSET_LOADED(PXMenu2[PXType]))
		{
			for (int i = 0; i < sizeof(bones4fx) / 4; i++)
			{
				GRAPHICS::_SET_PTFX_ASSET_NEXT_CALL(PXMenu2[PXType]);
				GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2((PXhsh[PXType]), PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, bones4fx[i], 0.2f, 0, 0, 0);
				ParticalDelay1 = GAMEPLAY::GET_GAME_TIMER() + 550;
			}

		}
	}
}

int Shooting_Ability = 10000;
int UserSlot = 0;
void STAT_SET_INT(char *stat, int value, bool save)
{
	char sbuf[50];
	snprintf(sbuf, sizeof(sbuf), "MP%i_%s", UserSlot, stat);
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY(sbuf), value, save);
}
int MoneyAmmount = 1000000;
int MinusMoney = 1000000;
void GiveMoney()
{
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(MoneyAmmount);
}
void RemoveMoney()
{
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(-MinusMoney);
}
bool Shrink = false;
bool funnyScreenEnabled = false;
void funnyScreen(bool enabled)
{
	if (enabled == true) 
	{
		*(char*)(0x1D260) = 0x40, 0x00, 0x00, 0x00;
	}
	else 
	{
		*(char*)(0x1D260) = 0x3F, 0x80, 0x00, 0x00;
	}
}
bool ShowTalking1 = false;
void DRAW_SPRITE(char* TextOne, char* TextTwo, float X, float Y, float Width, float Height, float Rotation, int R = 255, int G = 255, int B = 255, int A = 255)
{
	GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT(TextOne, false);
	if (GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED(TextOne))
		GRAPHICS::DRAW_SPRITE(TextOne, TextTwo, X, Y, Width, Height, Rotation, R, G, B, A);
}
int Height = 1;
float PixelY(int Input)
{
	return (float)Input / (float)720;
}
float PixelX(int Input)
{
	return (float)Input / (float)1280;
}
void DRAW_TEXT(char* Text, float X, float Y, float S_X, float S_Y, int Font, bool Outline, bool Shadow, bool Center, bool RightJustify, int R, int G, int B, int A)
{
	UI::SET_TEXT_FONT(Font);
	UI::SET_TEXT_SCALE(S_X, S_Y);
	UI::SET_TEXT_COLOUR(R, G, B, A);
	if (Outline)
		UI::SET_TEXT_OUTLINE();
	if (Shadow)
		UI::SET_TEXT_DROP_SHADOW();
	if (Center)
		UI::SET_TEXT_CENTRE(1);
	if (RightJustify)
		UI::SET_TEXT_RIGHT_JUSTIFY(1);
	UI::_SET_TEXT_ENTRY("STRING");
	UI::_ADD_TEXT_COMPONENT_STRING(Text);
	UI::_DRAW_TEXT(X, Y);
}
struct RGB1
{
	int Red, Green, Blue, Opacity;
	int R, G, B;
};
RGB1 SelectColour = { 255, 255, 255 };
RGB1 TitleColour1 = { 255, 255, 255, 255 };
bool Vehicle_Atach;
int Vehicle_Hash = 0; 
bool featureDeleteGun = 0;
Entity tempEntity;
Entity deletegun_locked;
void DeleteAimingObjectFunction()
{
	PLAYER::DISABLE_PLAYER_FIRING(PLAYER::PLAYER_ID(), 1);
	//Hash tempWeap;
	//GET_CURRENT_PED_WEAPON(PLAYER_PED_ID(), &tempWeap, 1);
	if (CONTROLS::IS_CONTROL_JUST_PRESSED(2, Button_L2) && CONTROLS::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &tempEntity) && ENTITY::DOES_ENTITY_EXIST(tempEntity))
	{ deletegun_locked = !deletegun_locked;
	if (ENTITY::IS_ENTITY_A_PED(tempEntity) && PED::IS_PED_IN_ANY_VEHICLE(tempEntity, 1))
	{ tempEntity = PED::GET_VEHICLE_PED_IS_IN(tempEntity, 0); } }
	if (deletegun_locked)
	{
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(tempEntity);
		ENTITY::SET_ENTITY_AS_MISSION_ENTITY(tempEntity, 0, 1);
		ENTITY::DELETE_ENTITY(&tempEntity);
	}
	else
	{
		if (ENTITY::DOES_ENTITY_EXIST(tempEntity) && (ENTITY::IS_ENTITY_A_PED(tempEntity) || ENTITY::IS_ENTITY_A_VEHICLE(tempEntity)))
		{
			ENTITY::SET_ENTITY_HEADING(tempEntity, ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID()));
			ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&tempEntity);
		}
	}
}
void clearArea()
{
	Vector3 Pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	GAMEPLAY::CLEAR_AREA(Pos.x, Pos.y, Pos.z, 1000, 0, 0, 0, 0);
	GAMEPLAY::CLEAR_AREA_OF_COPS(Pos.x, Pos.y, Pos.z, 1000, 0);
	GAMEPLAY::CLEAR_AREA_OF_OBJECTS(Pos.x, Pos.y, Pos.z, 1000, 0);
	GAMEPLAY::CLEAR_AREA_OF_VEHICLES(Pos.x, Pos.y, Pos.z, 1000, 0, 0, 0, 0, 0);
	GAMEPLAY::CLEAR_AREA_OF_PROJECTILES(Pos.x, Pos.y, Pos.z, 1000, 0);
}
void StealOutfit()
{
	int player = PLAYER::GET_PLAYER_PED(selectedPlayer);
	if (ENTITY::GET_ENTITY_MODEL(PLAYER::PLAYER_PED_ID()) != ENTITY::GET_ENTITY_MODEL(PLAYER::GET_PLAYER_PED(selectedPlayer)))
		SET_PLAYER_MODEL(ENTITY::GET_ENTITY_MODEL(PLAYER::GET_PLAYER_PED(selectedPlayer)));

	for (int i = 0; i < 12; i++) {
		int e_drawable = PED::GET_PED_DRAWABLE_VARIATION(PLAYER::GET_PLAYER_PED(selectedPlayer), i);
		int e_texture = PED::GET_PED_TEXTURE_VARIATION(PLAYER::GET_PLAYER_PED(selectedPlayer), e_drawable);
		PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), i, e_drawable, e_texture, 0);
	}
}
bool featurePlayerUltraJump = false;
Player player = PLAYER::PLAYER_ID();
Ped playerPed = PLAYER::PLAYER_PED_ID();
BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);

bool Hoverboard;
bool Hoverboard_Ped;
bool Hoverboard_object;
int CustomVehicle = 0;
bool DeleteBoardSkate;//
bool Hover_Board_Delete;
int CREATE_VEHICLE(Hash VehicleHash, Vector3 Location, bool Invisible = false)
{
	Vehicle Handle = 0;
	STREAMING::REQUEST_MODEL(VehicleHash);
	if (STREAMING::HAS_MODEL_LOADED(VehicleHash))
	{
		Handle = VEHICLE::CREATE_VEHICLE(VehicleHash, Location.x, Location.y, Location.z, 0, true, false);

		if (Invisible)
			ENTITY::SET_ENTITY_VISIBLE(Handle, false);
		if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false))
		{
			Vehicle Prev = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
			Vector3 PrevRotation = ENTITY::GET_ENTITY_ROTATION(Prev, false);
			Vector3 Location = ENTITY::GET_ENTITY_COORDS(Prev, false);
			float Speed = ENTITY::GET_ENTITY_SPEED(Prev);
			VEHICLE::DELETE_VEHICLE(&Prev);
			VEHICLE::SET_VEHICLE_ENGINE_ON(Handle, true, true);
			ENTITY::SET_ENTITY_COORDS(Handle, Location.x, Location.y, Location.z, true, false, false, true);
			ENTITY::SET_ENTITY_ROTATION(Handle, PrevRotation.x, PrevRotation.y, PrevRotation.z, 0, false);
			VEHICLE::SET_VEHICLE_FORWARD_SPEED(Handle, Speed);
		}
		else
		{
			ENTITY::SET_ENTITY_HEADING(Handle, ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID()));
		}
		ENTITY::SET_ENTITY_HEADING(Handle, ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID()));
		PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Handle, -1);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(VehicleHash);
	}
	return Handle;
}

Entity Hoverboard_object1 = 0;
Entity Hoverboard_object2 = 0;
Entity Hoverboard_object3 = 0;
Entity Hoverboard_object4 = 0;
Entity Hoverboard_object5 = 0;
Entity Hoverboard_object6 = 0;
Entity Hoverboard_object7 = 0;
Entity Hoverboard_object8 = 0;
Entity Hoverboard_object9 = 0;
Entity Hoverboard_object10 = 0;
Entity Hoverboard_object11 = 0;
Entity HoverboardPed = 0;
bool HoverboardFX;
Vector3 MyCoordsRightNow = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
bool TASK_PLAY_ANIM(Ped Ped, char* AnimDict, char* Anim, float Speed = 8)
{
	STREAMING::REQUEST_ANIM_DICT(AnimDict);
	if (STREAMING::HAS_ANIM_DICT_LOADED(AnimDict))
	{
		AI::TASK_PLAY_ANIM(Ped, AnimDict, Anim, Speed, Speed, -1, 9, Speed, 0, 0, 0);
		return true;
	}
	else
		return false;
}
float ParticleFX_S = 1;

bool ParticleFX(char* FXType, char* FXName, int Entity = PLAYER::PLAYER_PED_ID(), float X = 0, float Y = 0, float Z = 0, float Pitch = 0, float Roll = 0, float Yaw = 0, float scale = ParticleFX_S)
{
	STREAMING::_REQUEST_DLC_PTFX_ASSET(FXType);
	GRAPHICS::_0x9C720B61(FXType);
	if (STREAMING::_HAS_DLC_PTFX_LOADED(FXType))
	{
		GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_ENTITY_2(FXName, Entity, X, Y, Z, Pitch, Roll, Yaw, scale, false, false, false);
		return true;
	}
	else
		return false;
}
Entity TargettedEntity;
void AimedEnit()
{

	if (PLAYER::_GET_AIMED_ENTITY(PLAYER::PLAYER_ID(), &TargettedEntity))
	{
		ENTITY::APPLY_FORCE_TO_ENTITY(TargettedEntity, 1, 0, 0, 3, 0, 0, 0, 1, false, true, true, true, true);
	}
}

bool ArmorRegener;
bool HealthRegener;
int timer = 0;
void ArmorRegen()
{
	if (ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()))
	{
		if (timer > 199)
		{
			if (ENTITY::GET_ENTITY_HEALTH(PLAYER::PLAYER_PED_ID()) < ENTITY::GET_ENTITY_MAX_HEALTH(PLAYER::PLAYER_PED_ID()))
				ENTITY::SET_ENTITY_HEALTH(PLAYER::PLAYER_PED_ID(), ENTITY::GET_ENTITY_HEALTH(PLAYER::PLAYER_PED_ID()) + 1);
			timer = 0;
		}
		else
		{
			PED::ADD_ARMOUR_TO_PED(PLAYER::PLAYER_PED_ID(), 1);
			timer = 0;
		}
	}
	else
	{
		timer = timer + 1;
	}
}
void HealthRegen()
{
	if (ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()))
	{
		if (timer > 199)
		{
			if (ENTITY::GET_ENTITY_HEALTH(PLAYER::PLAYER_PED_ID()) < ENTITY::GET_ENTITY_MAX_HEALTH(PLAYER::PLAYER_PED_ID()))
				ENTITY::SET_ENTITY_HEALTH(PLAYER::PLAYER_PED_ID(), ENTITY::GET_ENTITY_HEALTH(PLAYER::PLAYER_PED_ID()) + 1);
			timer = 0;
		}
		else
		{
			ENTITY::SET_ENTITY_HEALTH(PLAYER::PLAYER_PED_ID(), ENTITY::GET_ENTITY_HEALTH(PLAYER::PLAYER_PED_ID()) + 1);
			timer = 0;
		}
	}
	else
	{
		timer = timer + 1;
	}
}
int CREATE_PED_NORMAL(Hash Name, Vector3 Location)
{
	Hash Hash = (Name);
	int Ped = 0;
	STREAMING::REQUEST_MODEL(Hash);
	if (STREAMING::HAS_MODEL_LOADED(Hash))
	{
		Ped = PED::CREATE_PED(21, Hash, Location.x, Location.y, Location.z, ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID()), true, false);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(Hash);
	}
	return Ped;
}
bool instantrevenge = false;
void AddEntityExplosion(int entity, int explosionId, bool invisible, bool playsound)
{
	Vector3 Pos = ENTITY::GET_ENTITY_COORDS(entity,1);
	if (ENTITY::DOES_ENTITY_EXIST(entity))
	{
		FIRE::ADD_EXPLOSION(Pos.x, Pos.y, Pos.z, explosionId, FLT_MAX, playsound, invisible, 0.0f);
	}
}
void RevengeLoop()
{
	int killer;
	if (ENTITY::IS_ENTITY_DEAD(PLAYER::PLAYER_PED_ID()))
	{
		killer = PED::_0x84ADF9EB(PLAYER::PLAYER_PED_ID());
		if (!ENTITY::IS_ENTITY_DEAD(killer))
		{
			AddEntityExplosion(killer, GRENADE,1,1);
		}
	}
}

bool Aimprotect = false;
int playerAiming;
void AimProtection1()
{
	for (int i = 0; i < 16; i++)
	{
		if (PLAYER::IS_PLAYER_FREE_AIMING_AT_ENTITY(i, PLAYER::PLAYER_PED_ID())) {
			playerAiming = i;
			int pedID = PLAYER::GET_PLAYER_PED(playerAiming);
			AddEntityExplosion(pedID, GRENADE,1,1);
		}
	}
}

void DELETE_VEHICLE_FUNCTION(int vehicle)
{
	NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(vehicle);
	ENTITY::SET_ENTITY_AS_MISSION_ENTITY(vehicle, 0, 1);
	VEHICLE::DELETE_VEHICLE(&vehicle);
}
void GET_PED_NEARBY_VEHICLES_H4X(int type)//loopthis
{
	int MYCAR = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
	const int numElements = 10;
	const int arrSize = numElements * 2 + 2;
	int veh[arrSize];
	veh[0] = numElements;
	int count = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), veh);
	if (veh != NULL)
	{
		for (int i = 1; i <= count; i++)
		{
			int offsettedID = i;
			if (veh[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(veh[offsettedID]))
			{
				Vector3 Pos = ENTITY::GET_ENTITY_COORDS(veh[offsettedID], true);

				if (type == 1) {
					if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0)) {
						if (ENTITY::IS_ENTITY_TOUCHING_ENTITY(veh[offsettedID], PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0)))
						{
							if (MYCAR != veh[offsettedID])
							{
								int ThatFaggot = veh[offsettedID];
								Vector3 Pos = ENTITY::GET_ENTITY_COORDS(ThatFaggot, true);
								DELETE_VEHICLE_FUNCTION(ThatFaggot);
							}
						}
					}
				}
			}
		}
	}
}
int BadSportCar;
int YES;
bool SpawnVehicleLoopfraud = false;
bool RamProtect = false;
bool fakemodz = false;
int Loading;
int badsportplayercurrent;
int lookDir;
void AddOwnedEntityExplosion(int entity, int player, int explosionId, bool invisible, bool playsound)
{
	Vector3 Pos = ENTITY::GET_ENTITY_COORDS(entity, YES);
	if (ENTITY::DOES_ENTITY_EXIST(entity))
		FIRE::ADD_OWNED_EXPLOSION(player, Pos.x, Pos.y, Pos.z, explosionId, FLT_MAX, playsound, invisible, 0.0f);
}
void PutPlayerInBadSport(int player)
{
	int blownup = 0;
	badsportplayercurrent = player;
	while (blownup < 100)
	{
		AddOwnedEntityExplosion(BadSportCar, badsportplayercurrent, BLIMP, 1, 0);
		if (!SpawnVehicleLoopfraud)
			SpawnVehicleLoopfraud = true;
		if (ENTITY::DOES_ENTITY_EXIST(BadSportCar))
		{
			AddOwnedEntityExplosion(BadSportCar, badsportplayercurrent, BLIMP, 1, 0);
			AddOwnedEntityExplosion(BadSportCar, badsportplayercurrent, BLIMP, 1, 0);
			//DECORATOR::DECOR_REGISTER("Player_Vehicle", 3);
			//DECORATOR::DECOR_SET_INT(BadSportCar, "Player_Vehicle", NETWORK::_0xF8D7AF3B(PLAYER::PLAYER_ID()));
			//if (DECORATOR::_0x74EF9C40(BadSportCar, "Player_Vehicle") && DECORATOR::_0xDDDE59B5(BadSportCar, "Player_Vehicle") == NETWORK::_0xF8D7AF3B(PLAYER::PLAYER_ID()))
			AddOwnedEntityExplosion(BadSportCar, badsportplayercurrent, BLIMP, 1, 0);
			blownup++;
			blownup++;
			drawNotification("Forced player to explode %i vehicles!");
			BadSportCar = 0;
		}
	}
}
void FunGunEnable()
{
	STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
	STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
	GRAPHICS::SET_CAMERA_ENDTIME(true);
}

void FunGunDisable()
{
	GRAPHICS::SET_CAMERA_ENDTIME(false);
}

bool PaintVehGunBool = false;

bool HasControlOfEntity(int entity)
{
	if (NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(entity))
	{
		if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(entity))
		{
			return true;
		}
	}
	return false;
}
void PaintVehGun()
{
	int Entity = 0;
	if (CONTROLS::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &Entity))
	{
		drawNotification("Good Color");
		if (PED::IS_PED_SHOOTING(PLAYER::PLAYER_PED_ID()))
		{
			if (ENTITY::DOES_ENTITY_EXIST(Entity) && HasControlOfEntity(Entity))
			{
				if (ENTITY::IS_ENTITY_A_VEHICLE(Entity))
				{
					VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Entity, GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255));
					VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Entity, GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255));
				}
			}
		}
	}
}

bool Particle_Man_clown = false;
bool Particle_Man_Appers = false;
bool Particle_Man_breach_smoke = false;
bool Particle_Man_petrol_fire = false;
bool IMFAMOUSFX = false;
bool expclown = false;

char* ParticleType1 = ("scr_rcbarry2");//Particle_Man_Appers
char* ParticleName1 = ("scr_clown_death");//Particle_Man_Appers
										  //
char* ParticleType2 = ("scr_rcbarry2");//Particle_Man_clown
char* ParticleName2 = ("scr_clown_death");//Particle_Man_clown
										  //
char* ParticleType3 = ("scr_agencyheist");//Particle_Man_breach_smoke
char* ParticleName3 = ("scr_fbi_dd_breach_smoke");//Particle_Man_breach_smoke
												  //
char* ParticleType4 = ("ent_damage");//Particle_Man_petrol_fire
char* ParticleName4 = ("ent_sht_petrol_fire");//Particle_Man_petrol_fire
											  //
char* ParticleType5 = ("ent_damage_spark");//Particle_Man_petrol_fire
char* ParticleName5 = ("ent_sht_electrical_box");//Particle_Man_petrol_fire

char* ParticleType6 = ("scr_rcbarry2");//Particle_Man_petrol_fire
char* ParticleName6 = ("scr_exp_clown");//Particle_Man_petrol_fire

bool AutoUpgradeLoop = false;
bool vehlights = false;
int VehicleAlpha;

void BrightVehLights(float multiplier)
{
	VEHICLE::SET_VEHICLE_LIGHT_MULTIPLIER(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), multiplier);
}
bool waypoint;
Vector3 wpcoords;
void DriveToWP()
{
	waypoint = true;
	int driver = PLAYER::PLAYER_PED_ID();
	int Waypoint = UI::GET_FIRST_BLIP_INFO_ID(8);
	if (UI::DOES_BLIP_EXIST(Waypoint))
	{
		wpcoords = UI::GET_BLIP_COORDS(Waypoint);
		if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
		{
			int vehicle = PED::GET_VEHICLE_PED_IS_IN(driver, 0);
			int model = ENTITY::GET_ENTITY_MODEL(vehicle);
			AI::TASK_VEHICLE_DRIVE_TO_COORD_LONGRANGE(driver, vehicle, wpcoords.x, wpcoords.y, wpcoords.z, 45.0f, 262460, 20);
			PED::SET_DRIVER_ABILITY(driver, 1.0f);
			drawNotification("~g~Taking you to the set waypoint.");
		}
		else
		{
			drawNotification("~r~You are not in a vehicle.");
		}
	}
	else
	{
		drawNotification("~r~No waypoint has been set.");
	}
}

int moneyDropamt;
bool LSC_Drop = false;

bool Maze_Drop = false;
bool Chilliad_Drop = false;
int locationamount;
void lscdrop()
{
	if (LSC_Drop)
	{
		STREAMING::REQUEST_MODEL(0x113FD533);
		if (STREAMING::HAS_MODEL_LOADED(0x113FD533))
		{

			OBJECT::CREATE_AMBIENT_PICKUP(0xCE6FDD6B, -387.945007, -128.110916, 40.922359, 0, 40000, 0x113FD533, 0, 1);
			OBJECT::CREATE_AMBIENT_PICKUP(0xCE6FDD6B, -387.945007, -128.110916, 40.922359, 0, 40000, 0x113FD533, 0, 1);
			OBJECT::CREATE_AMBIENT_PICKUP(0xCE6FDD6B, -387.945007, -128.110916, 40.922359, 0, 40000, 0x113FD533, 0, 1);

			Vector3 Pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
			Vector3 Pos2 = ENTITY::GET_ENTITY_COORDS(40000, true);
			GRAPHICS::DRAW_LINE(Pos.x, Pos.y, Pos.z, Pos2.x, Pos2.y, Pos2.z, 133, 8, 255, 255);
		}
	}
}
void chilliaddrop()
{
	if (Chilliad_Drop)
	{
		STREAMING::REQUEST_MODEL(0x113FD533);
		if (STREAMING::HAS_MODEL_LOADED(0x113FD533)) {
			OBJECT::CREATE_AMBIENT_PICKUP(0xCE6FDD6B, 501.389465, 5600.842773, 798.374207, 0, 40000, 0x113FD533, 0, 1);
			OBJECT::CREATE_AMBIENT_PICKUP(0xCE6FDD6B, 501.389465, 5600.842773, 798.374207, 0, 40000, 0x113FD533, 0, 1);
			OBJECT::CREATE_AMBIENT_PICKUP(0xCE6FDD6B, 501.389465, 5600.842773, 798.374207, 0, 40000, 0x113FD533, 0, 1);
		}
	}
}
void MazeDrop()
{
	if (Maze_Drop)
	{
		STREAMING::REQUEST_MODEL(0x113FD533);
		if (STREAMING::HAS_MODEL_LOADED(0x113FD533)) {
			OBJECT::CREATE_AMBIENT_PICKUP(0xCE6FDD6B, -75.278778, -819.667053, 328.543488, 0, 40000, 0x113FD533, 0, 1);
			OBJECT::CREATE_AMBIENT_PICKUP(0xCE6FDD6B, -75.278778, -819.667053, 328.543488, 0, 40000, 0x113FD533, 0, 1);
		}
	}
}
void teleportPlayertoMe()
{
	for (int i = 0; i < 16; i++)
	{
		if (i != PLAYER::PLAYER_ID()) {
			Ped ped = PLAYER::GET_PLAYER_PED(i);
			int selectedPed = PLAYER::GET_PLAYER_PED(selectedPlayer);
			Vector3 MyPosition = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(Me, 0.0, 0.0, 0.0);

			int sceneID = NETWORK::NETWORK_CREATE_SYNCHRONISED_SCENE(MyPosition.x, MyPosition.y, MyPosition.z, 0, 0, 0, 2, 0, 1, 1.0f, 0.0f, 1.0f);
			NETWORK::NETWORK_ADD_PED_TO_SYNCHRONISED_SCENE(selectedPed, sceneID, "move_f@sexy@a", "idle", 1000.0f, -1000.0f, 0, 1, 1000.0f, 1);
			NETWORK::NETWORK_START_SYNCHRONISED_SCENE(sceneID);
		}
	}
}
void teleportPlayertoMission() 
{
	for (int i = 0; i < 16; i++)
	{
		if (i != PLAYER::PLAYER_ID()) {
			Ped ped = PLAYER::GET_PLAYER_PED(i);
			int sceneID = NETWORK::NETWORK_CREATE_SYNCHRONISED_SCENE(-547.429199, -166.696289, 37.836823, 0.0f, 0.0f, 0.0f, 2, 0, 0, 1065353216, 0, 1065353216);
			NETWORK::NETWORK_ADD_PED_TO_SYNCHRONISED_SCENE(ped, sceneID, "move_f@sexy@a", "idle", 1000.0f, -1000.0f, 0, 1, 1000.0f, 1);
			NETWORK::NETWORK_START_SYNCHRONISED_SCENE(sceneID);
		}
	}
}




bool WaterLoopAll = false;
void WaterLoopAll1()
{
	if (WaterLoopAll)
	{
		for (int i = 0; i < 16; i++)
		{
			if (i != PLAYER::PLAYER_ID()) {
				Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(i), 0);
				FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, 13, 5, 1, 0, 0);
			}
		}
	}
}
bool FireLoopAll = false;
bool FreezeAll = false;
void FireLoopAll1()
{
	if (FireLoopAll)
	{
		for (int i = 0; i < 16; i++)
		{
			if (i != PLAYER::PLAYER_ID()) {
				Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(i), 0);
				FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, 14, 5, 1, 0, 0);
			}
		}
	}
}
void WeaponsRemoveAll()
{
	for (int i = 0; i < 16; i++)
	{
		if (i != PLAYER::PLAYER_ID()) {
			WEAPON::REMOVE_ALL_PED_WEAPONS(PLAYER::GET_PLAYER_PED(i), true);
		}
	}
}
bool TracerLoop = false;
int ESPHUDa;
void PlayerTracer()
{
	for (int i = 0; i < 18; ++i)
	{
		Ped ped = PLAYER::GET_PLAYER_PED(i);
		Vector3 playerPedCoords = ENTITY::GET_ENTITY_COORDS(ped, true);
		Vector3 SelfPosition = ENTITY::GET_ENTITY_COORDS(ped, true);
		char* name = PLAYER::GET_PLAYER_NAME(i);
		float x, y;
		if (GRAPHICS::_0x1F950E4B(playerPedCoords.x, playerPedCoords.y, playerPedCoords.z, &x, &y))
		{
			if (ped != PLAYER::PLAYER_PED_ID() && !GAMEPLAY::ARE_STRINGS_EQUAL(name, "Empty Slot"))
			{
				char text[16];
				//sprintf_(text, "%s\n", name);
				UI::SET_TEXT_FONT(0);
				UI::SET_TEXT_SCALE(0.35, 0.35);
				UI::SET_TEXT_COLOUR(255, 255, 255, ESPHUDa);
				UI::SET_TEXT_WRAP(0.0, 1.0);
				UI::SET_TEXT_CENTRE(1);
				UI::_SET_TEXT_ENTRY("STRING");
				UI::_ADD_TEXT_COMPONENT_STRING(text);
				UI::_DRAW_TEXT(x, y);

				GRAPHICS::DRAW_LINE(playerPedCoords.x, playerPedCoords.y, playerPedCoords.z, SelfPosition.x, SelfPosition.y, SelfPosition.z, bannerRectRed, bannerRectGreen, bannerRectBlue, bannerRectOpacity);
			}
		}
	}
}
void ClientTracer()
{
	if (TracerLoop)
		PlayerTracer();
}
void FreezeLoopAll()
{
	if (FreezeAll)
	{
		for (int i = 0; i < 16; i++)
		{
			if (i != PLAYER::PLAYER_ID()) {
				AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::GET_PLAYER_PED(i));
			}
		}
	}
}

void WeaponsGiveAll()
{
	for (int i = 0; i < 16; i++)
	{
		if (i != PLAYER::PLAYER_ID()) {
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0x3656C8C1, 9999, true); // stun gun
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0x99B507EA, 9999, true); // knife
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0x678B81B1, 9999, true); // night stick
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0x4E875F73, 9999, true); // hammer
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0x958A4A8F, 9999, true); // bat
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0x440E4788, 9999, true); // golf club
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0x84BD7BFD, 9999, true); // crowbar
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0x1B06D571, 9999, true); // pistol
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0x5EF9FEC4, 9999, true); // combat pistol
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0x22D8FE39, 9999, true); // ap pistol
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0x99AEEB3B, 9999, true); // pistol 50.
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0x13532244, 9999, true); // micro smg
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0x2BE6766B, 9999, true); // smg
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0xEFE7E2DF, 9999, true); // assault smg
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0xBFEFFF6D, 9999, true); // assault rifle
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0x83BF0278, 9999, true); // carbine rifle
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0xAF113F99, 9999, true); // advanced rifle
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0x9D07F764, 9999, true); // MG
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0x7FD62962, 9999, true); // combat mg
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0x1D073A89, 9999, true); // pump shotgun
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0x7846A318, 9999, true); // sawnoff shotgun
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0xE284C527, 9999, true); // assault shotgun
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0x9D61E50F, 9999, true); // bullpupshotgun
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0x05FC3C11, 9999, true); // sniper
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0x0C472FE2, 9999, true); // heavy sniper
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0xA284510B, 9999, true); // grenade launcher
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0xB1CA77B1, 9999, true); // rpg
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0x42BF8A85, 9999, true); // minigun
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0x93E220BD, 9999, true); // grenades
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0x2C3731D9, 9999, true); // sticky bomb
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0xFDBC8A50, 9999, true); // smoke grenade
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0x34A67B97, 9999, true); // petrol can
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0x060EC506, 9999, true); // fire extinguisher
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0x24B17070, 9999, true); // moltovs
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0x497FACC3, 9999, true); // flare
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0xFDBADCED, 9999, true); // digiscanner
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0x687652CE, 9999, true); // stinger
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 600439132, 9999, true); // ball
																		  //DLC Weapons
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0xF9E6AA4B, 9999, true); // bottle
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0x61012683, 9999, true); // gusenerg
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0xC0A3098D, 9999, true); // special carbine
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0xD205520E, 9999, true); // heavy pistol
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0xBFD21232, 9999, true); // sns pistol
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0x7F229F94, 9999, true); // bullpup rifle
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0x92A27487, 9999, true); // dagger
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0x083839C4, 9999, true); // vintage pistol
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0x7F7497E5, 9999, true); // firework launcher
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0xA89CB99E, 9999, true); // musket
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0x63AB0442, 9999, true); // homing launcher
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0xAB564B93, 9999, true); // proxmine
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0x787F0BB, 9999, true); // snowball
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0xC734385A, 9999, true); // marksman rifle
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0x47757124, 9999, true); // flare gun
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0x0A3D4D34, 9999, true); // Combat PDW
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0xF9D04ADB, 9999, true); // marksman pistol
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0xB32BE614, 9999, true); // knuckle dusters
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, 0x0A3D4D34, 9999, true); // combat pdw
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(i, GAMEPLAY::GET_HASH_KEY("PICKUP_WEAPON_HEAVYSHOTGUN"), 9999, true); // HEAVYSHOTGUN
		}
	}
}
void PTFX_AT_COORDS(char *PtfxnameSpace, char *Ptfxname, float x, float y, float z, float scale) {
	STREAMING::_REQUEST_DLC_PTFX_ASSET(PtfxnameSpace);
	GRAPHICS::_0x9C720B61(PtfxnameSpace);
	GRAPHICS::START_PARTICLE_FX_NON_LOOPED_AT_COORD1(Ptfxname, x, y, z, 0.0, 0.0, 0.0, scale, false, false, false);
}

bool antiParticleFXCrash = false;
void antiParticleFX22()
{
	Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	GRAPHICS::REMOVE_PARTICLE_FX_IN_RANGE(coords.x, coords.y, coords.z, 10);
}
float Range2 = 50.0f;
float SKIP = 0.0f;
int custombinary = 20503;
int custombinary2 = 12294;
int custombinary3 = 12294;

bool NonHostKick_Protection = false;
bool spawninfade = false;
bool Votekickprotect = false;
bool remotescriptleave = false;
bool AntblamePlayer = false;
bool Protection123 = false;
bool RequestControl = false;
#pragma region Other Loop
void otherLoop()
{
	if (RequestControl)
	{
		*(int*)(0x12BE18C) = 0x7C0802A6; //request control //desativar
	}
	else
	{
		*(int*)(0x12BE18C) = 0x4E800020; //request control/ /ativar
	}
	if (Protection123)
	{
		//GET ENTITY FOR PROTECTION
		Ped ped = PLAYER::PLAYER_PED_ID();
		Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(ped, false);
		//Get Range To Detect Planes
		SKIP = 0.0f;
		//GET PLANES
		int veh = VEHICLE::GET_CLOSEST_VEHICLE(playerPosition.x, playerPosition.y, playerPosition.z, Range2, 0, custombinary);
		//Planes Detection
		if (ENTITY::DOES_ENTITY_EXIST(veh))
		{
			bool Contin = true;
			//Planes Detach and Delete
			if (Contin)
			{
				if (NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(veh))
				{
					////////TELEPORT PROTECTION///////
					int X = GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(-3000.0, 3000.0);
					int Y = GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(-3000.0, 3000.0);
					int Z = GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(0.0, 300.0);
					Ped ped = PLAYER::PLAYER_PED_ID();
					Entity entityToTele = ped;
					if (PED::IS_PED_SITTING_IN_ANY_VEHICLE(ped))
						entityToTele = PED::GET_VEHICLE_PED_IS_USING(ped);
					Vector3 PedCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
					ENTITY::SET_ENTITY_COORDS(entityToTele, X, Y, Z, false, false, false, true);
					/////////////////////////////////
					ENTITY::DETACH_ENTITY(veh, 1, 1);
					ENTITY::DETACH_ENTITY(veh, 1, 1);
					ENTITY::DETACH_ENTITY(veh, 1, 1);
					ENTITY::DETACH_ENTITY(veh, 1, 1);
					ENTITY::DETACH_ENTITY(veh, 1, 1);
					ENTITY::SET_ENTITY_AS_MISSION_ENTITY(veh, 0, 1);
					ENTITY::SET_ENTITY_AS_MISSION_ENTITY(veh, 0, 1);
					ENTITY::SET_ENTITY_AS_MISSION_ENTITY(veh, 0, 1);
					ENTITY::SET_ENTITY_AS_MISSION_ENTITY(veh, 0, 1);
					ENTITY::SET_ENTITY_AS_MISSION_ENTITY(veh, 0, 1);
					VEHICLE::DELETE_VEHICLE(&veh);
					VEHICLE::DELETE_VEHICLE(&veh);
					VEHICLE::DELETE_VEHICLE(&veh);
					VEHICLE::DELETE_VEHICLE(&veh);
					VEHICLE::DELETE_VEHICLE(&veh);
					drawNotification("~r~!!ALERT!! Malicious activity detected, ~w~you're protected. ~r~!!ALERT!!");
					//FloatingHelpTextMoneydropp("if another modder spawns a plane in you, it will be randomly teleported on the map");
					Contin = false;
				}
			}
		}
	}
	if (AntblamePlayer)
	{
		NETWORK::NETWORK_SET_FRIENDLY_FIRE_OPTION(false);
	}
	else
	{
		NETWORK::NETWORK_SET_FRIENDLY_FIRE_OPTION(true);
	}
	if (antiParticleFXCrash)
		antiParticleFX22();
	if (spawninfade)
	{
		NETWORK::NETWORK_FADE_IN_ENTITY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), true), 1);
	}
	if (remotescriptleave)
	{
		*(int*)0x12C96B4 = 0x7C0802A6;//remote script leave //desativar
	}
	else
	{
		*(int*)0x12C96B4 = 0x4E800020;//remote script leave //ativar
	}
	if (Votekickprotect)
	{
		*(int*)0x12D1E28 = 0x7C0802A6;//vote kick
	}
	else
	{
		*(int*)0x12D1E28 = 0x4E800020;//vote kick
	}
	if (NonHostKick_Protection)
	{
		*(int*)0x12C96B4 = 0x7C0802A6;//remote script leave
		*(int*)0x12D1E28 = 0x7C0802A6;//vote kick
		*(int*)0x172D73C = 0x40820068;//nonhost
	}
	else
	{
		*(int*)0x12C96B4 = 0x4E800020;//remote script leave
		*(int*)0x12D1E28 = 0x4E800020;//vote kick
		*(int*)0x172D73C = 0x41820094;//nonhost
	}
	ClientTracer();
	FreezeLoopAll();
	FireLoopAll1();
	WaterLoopAll1();
	lscdrop();
	chilliaddrop();
	MazeDrop();
	if (AutoUpgradeLoop)
		MaxUpgrades(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0));
	if (vehlights)
		BrightVehLights(50.0f);
	else if (!vehlights)
		BrightVehLights(1.0f);
	if (waypoint)
	{
		int waypointv = UI::GET_FIRST_BLIP_INFO_ID(8);
		if (!UI::DOES_BLIP_EXIST(waypointv))
		{
			AI::CLEAR_PED_TASKS(PLAYER::PLAYER_PED_ID());
			drawNotification("~g~Stopped driving.");
			AI::CLEAR_PED_TASKS(PLAYER::PLAYER_PED_ID());
			waypoint = false;
			AI::TASK_VEHICLE_TEMP_ACTION(PLAYER::PLAYER_PED_ID(), PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), 27, 1500);
		}
	}

	if (PaintVehGunBool)
		PaintVehGun();

	
	if (RamProtect)
		GET_PED_NEARBY_VEHICLES_H4X(1);
	if (Aimprotect)
		AimProtection1();
	if (instantrevenge)
		RevengeLoop();
	if (Firefeet) 
	{
		ADD_EXPLOSION_ALT(&ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1), 3, 0.34f, false, false, 0.42f); 
	}
	if (ArmorRegener) { ArmorRegen(); }
	if (HealthRegener) { HealthRegen(); }
	
	if (applyforceg) { AimedEnit(); }
	if (shrink)//crescer rodas
	{
		PED::SET_PED_CONFIG_FLAG(PLAYER::PLAYER_PED_ID(), 223, 1);
		WheelSize = true;
		shrink = true;
	}
	else
	{
		PED::SET_PED_CONFIG_FLAG(PLAYER::PLAYER_PED_ID(), 223, 0);
		WheelSize = false;
		shrink = false;
	}
	
	if (WheelSize)//crescer rodas
	{
		if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 1) && PED::IS_PED_SITTING_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID()))
		{
			//int vehicle = GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID());
			//SET_VEHICLE_MOD_KIT(vehicle, 0);
			//SET_VEHICLE_MOD(vehicle, 23, 1, 0);
			//SET_VEHICLE_WHEEL_TYPE(vehicle, 0/*ID< SPORT*/);
			if (VEHICLE::GET_VEHICLE_MOD_VARIATION(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), 23))
			{
				*(float*)((*(int*)((*(int*)(GetEntityAddress(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0)) + 40)) + 304)) + 4) = wheelsizeValue;
			}
			else
			{
				drawNotification("~r~First set max upgrades.");
				WheelSize = false;
				shrink = false;
			}
		}
		else
		{
			WheelSize = false;
			shrink = false;
		}
	}
       //skateboard
	if (Hover_Board_Delete)
	{
		int V = PLAYER::GET_PLAYERS_LAST_VEHICLE();
		if (ENTITY::DOES_ENTITY_EXIST(V))
		{
			ENTITY::SET_ENTITY_COORDS(V, 6000.0, 6000.0, 6000.0, true, false, false, true);
			//VEHICLE::DELETE_VEHICLE(&V);
			Hover_Board_Delete = false;
		}
	}
	if (DeleteBoardSkate)
	{
		Ped DELETE = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 1);
		if (ENTITY::DOES_ENTITY_EXIST(DELETE))
		{
			ENTITY::SET_ENTITY_AS_MISSION_ENTITY(DELETE, 1, 1);
			VEHICLE::DELETE_VEHICLE(&DELETE);
		}
	}
	if (Hoverboard)
	{
		CustomVehicle = CREATE_VEHICLE(0x4B6C568A, ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false), true);
		if (ENTITY::DOES_ENTITY_EXIST(CustomVehicle))
		{
			ENTITY::SET_ENTITY_VISIBLE(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), false);
			Hoverboard_object = true;
			Hoverboard_Ped = true;
			Hoverboard = false;
		}
	}
	if (Hoverboard_object)
	{
		CustomVehicle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
		int prop_cs_silver_tray = GAMEPLAY::GET_HASH_KEY("prop_cs_silver_tray");
		int prop_scaffold_pole = GAMEPLAY::GET_HASH_KEY("prop_scaffold_pole");
		int prop_power_cell = GAMEPLAY::GET_HASH_KEY("prop_power_cell");
		int prop_cs_film_reel_01 = GAMEPLAY::GET_HASH_KEY("prop_cs_film_reel_01");
		Hoverboard_object1 = OBJECT::CREATE_OBJECT(prop_cs_silver_tray, MyCoordsRightNow.x, MyCoordsRightNow.y, MyCoordsRightNow.z, true, true, true);
		if (ENTITY::DOES_ENTITY_EXIST(Hoverboard_object1))
		{
			ENTITY::ATTACH_ENTITY_TO_ENTITY(Hoverboard_object1, CustomVehicle, -1, 0.0000, 0.0000, 0.0000, 0.0000, 180.0000, -90.0000, 1, 0, 0, 0, 2, 1);
			Hoverboard_object2 = OBJECT::CREATE_OBJECT(prop_cs_silver_tray, MyCoordsRightNow.x, MyCoordsRightNow.y, MyCoordsRightNow.z, true, true, true);
			if (ENTITY::DOES_ENTITY_EXIST(Hoverboard_object2))
			{
				ENTITY::ATTACH_ENTITY_TO_ENTITY(Hoverboard_object2, CustomVehicle, -1, 0.0000, 0.5000, 0.0000, 0.0000, 180.0000, -90.0000, 1, 0, 0, 0, 2, 1);
				Hoverboard_object3 = OBJECT::CREATE_OBJECT(prop_cs_silver_tray, MyCoordsRightNow.x, MyCoordsRightNow.y, MyCoordsRightNow.z, true, true, true);
				if (ENTITY::DOES_ENTITY_EXIST(Hoverboard_object3))
				{
					ENTITY::ATTACH_ENTITY_TO_ENTITY(Hoverboard_object3, CustomVehicle, -1, 0.0000, -0.5000, 0.0000, 0.0000, 180.0000, -90.0000, 1, 0, 0, 0, 2, 1);
					Hoverboard_object4 = OBJECT::CREATE_OBJECT(prop_scaffold_pole, MyCoordsRightNow.x, MyCoordsRightNow.y, MyCoordsRightNow.z, true, true, true);
					if (ENTITY::DOES_ENTITY_EXIST(Hoverboard_object4))
					{
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Hoverboard_object4, CustomVehicle, -1, -0.1600, 0.4700, 0.0000, 90.0000, 0.0000, 0.0000, 1, 0, 0, 0, 2, 1);
						Hoverboard_object5 = OBJECT::CREATE_OBJECT(prop_scaffold_pole, MyCoordsRightNow.x, MyCoordsRightNow.y, MyCoordsRightNow.z, true, true, true);
						if (ENTITY::DOES_ENTITY_EXIST(Hoverboard_object5))
						{
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Hoverboard_object5, CustomVehicle, -1, 0.1600, 0.4700, 0.0000, 90.0000, 0.0000, 0.0000, 1, 0, 0, 0, 2, 1);
							Hoverboard_object6 = OBJECT::CREATE_OBJECT(prop_power_cell, MyCoordsRightNow.x, MyCoordsRightNow.y, MyCoordsRightNow.z, true, true, true);
							if (ENTITY::DOES_ENTITY_EXIST(Hoverboard_object6))
							{
								ENTITY::ATTACH_ENTITY_TO_ENTITY(Hoverboard_object6, CustomVehicle, -1, 0.0000, -1.0000, 0.0000, 0.0000, 0.0000, -90.0000, 1, 0, 0, 0, 2, 1);
								Hoverboard_object7 = OBJECT::CREATE_OBJECT(prop_scaffold_pole, MyCoordsRightNow.x, MyCoordsRightNow.y, MyCoordsRightNow.z, true, true, true);
								if (ENTITY::DOES_ENTITY_EXIST(Hoverboard_object7))
								{
									ENTITY::ATTACH_ENTITY_TO_ENTITY(Hoverboard_object7, CustomVehicle, -1, -0.1600, -0.4500, 0.0000, 90.0000, 0.0000, 0.0000, 1, 0, 0, 0, 2, 1);
									Hoverboard_object8 = OBJECT::CREATE_OBJECT(prop_scaffold_pole, MyCoordsRightNow.x, MyCoordsRightNow.y, MyCoordsRightNow.z, true, true, true);
									if (ENTITY::DOES_ENTITY_EXIST(Hoverboard_object8))
									{
										ENTITY::ATTACH_ENTITY_TO_ENTITY(Hoverboard_object8, CustomVehicle, -1, 0.1600, -0.4500, 0.0000, 90.0000, 0.0000, 0.0000, 1, 0, 0, 0, 2, 1);
										Hoverboard_object9 = OBJECT::CREATE_OBJECT(prop_cs_film_reel_01, MyCoordsRightNow.x, MyCoordsRightNow.y, MyCoordsRightNow.z, true, true, true);
										if (ENTITY::DOES_ENTITY_EXIST(Hoverboard_object9))
										{
											ENTITY::ATTACH_ENTITY_TO_ENTITY(Hoverboard_object9, CustomVehicle, -1, 0.0000, 0.0000, -0.0200, 0.0000, 0.0000, 0.0000, 1, 0, 0, 0, 2, 1);
											Hoverboard_object10 = OBJECT::CREATE_OBJECT(prop_cs_film_reel_01, MyCoordsRightNow.x, MyCoordsRightNow.y, MyCoordsRightNow.z, true, true, true);
											if (ENTITY::DOES_ENTITY_EXIST(Hoverboard_object10))
											{
												ENTITY::ATTACH_ENTITY_TO_ENTITY(Hoverboard_object10, CustomVehicle, -1, 0.0000, -0.5000, -0.0200, 0.0000, 0.0000, 0.0000, 1, 0, 0, 0, 2, 1);
												Hoverboard_object11 = OBJECT::CREATE_OBJECT(prop_cs_film_reel_01, MyCoordsRightNow.x, MyCoordsRightNow.y, MyCoordsRightNow.z, true, true, true);
												if (ENTITY::DOES_ENTITY_EXIST(Hoverboard_object11))
												{
													ENTITY::ATTACH_ENTITY_TO_ENTITY(Hoverboard_object11, CustomVehicle, -1, 0.0000, 0.5000, -0.0200, 0.0000, 0.0000, 0.0000, 1, 0, 0, 0, 2, 1);
													ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), false);
													HoverboardFX = true;
													Hoverboard_object = false;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if (HoverboardFX)
	{
		if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
		{
			ParticleFX("scr_rcbarry2", "scr_clown_death", Hoverboard_object4, 0, 0, 1.52, 0, 0, 0, 0.15);
			ParticleFX("scr_rcbarry2", "scr_clown_death", Hoverboard_object5, 0, 0, 1.52, 0, 0, 0, 0.15);
		}
		else
		{
			HoverboardFX = false;
		}
	}
	if (Hoverboard_Ped)
	{
		HoverboardPed = PED::CLONE_PED(PLAYER::PLAYER_PED_ID(), 1, 0, 0);
		if (ENTITY::DOES_ENTITY_EXIST(HoverboardPed))
		{
			CustomVehicle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
			ENTITY::ATTACH_ENTITY_TO_ENTITY(HoverboardPed, CustomVehicle, -1, 0.0000, -0.1500, 1.0000, 0.0000, 0.0000, 0.0000, 1, 0, 0, 0, 2, 1);
			//TASK_PLAY_ANIM(HoverboardPed, "oddjobs@bailbond_mountain", "base_jump_idle");
			TASK_PLAY_ANIM(HoverboardPed, "move_strafe@stealth", "idle");
			Hoverboard_Ped = false;
		}
	}//skateboard


	if (featurePlayerUltraJump)
	{
		GAMEPLAY::SET_SUPER_JUMP_THIS_FRAME(player);
		WEAPON::REMOVE_WEAPON_FROM_PED(playerPed, GAMEPLAY::GET_HASH_KEY("GADGET_PARACHUTE"));
		if (PED::IS_PED_JUMPING(playerPed))
		{
			ENTITY::APPLY_FORCE_TO_ENTITY(playerPed, true, 0, 0, 120, 0, 0, 0, true, true, true, true, false, true);
		}
	}
	if (featureDeleteGun) { DeleteAimingObjectFunction(); }
	if (Vehicle_Atach)
	{
		STREAMING::REQUEST_MODEL(Vehicle_Hash);
		if(STREAMING::HAS_MODEL_LOADED(Vehicle_Hash));
		{
			Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
			int Handle = VEHICLE::CREATE_VEHICLE(Vehicle_Hash, Coords.x, Coords.y, Coords.z, 0, true, false);
			if (ENTITY::DOES_ENTITY_EXIST(Handle))
			{
				ENTITY::ATTACH_ENTITY_TO_ENTITY(Handle, PLAYER::GET_PLAYER_PED(selectedPlayer), 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 1);
				Vehicle_Atach = false;
			}
		}

	}
	if (ShowTalking1)
	{
		for (int i = 0; i < 16; i++)
		{
			if (NETWORK::NETWORK_PLAYER_HAS_HEADSET(i))
				Height++;
		}
		if (Height <= 1)
			Height = 0;
		float BoxHeight = PixelY(30 * Height);

		GRAPHICS::DRAW_RECT(PixelX(25 + 125), PixelY(45) + (BoxHeight / 2), PixelX(250), BoxHeight, 0, 0, 0, 0);//Background
		if (Height != 0)
			DRAW_TEXT("   ", PixelX(45), PixelY(50) + (PixelY(30) * 0), 0.5, 0.5, 0, true, false, false, false, SelectColour.R, SelectColour.G, SelectColour.B, 255);
		int Current = 1;
		for (int i = 0; i < 16; i++)
		{
			if (NETWORK::NETWORK_PLAYER_HAS_HEADSET(i))
			{
				char* Icon = "leaderboard_audio_inactive";
				DRAW_TEXT(PLAYER::GET_PLAYER_NAME(i), PixelX(60), PixelY(50) + (PixelY(30) * Current), 0.4, 0.4, 0, true, false, false, false, 255, 255, 255, 255);
				if (NETWORK::NETWORK_IS_PLAYER_MUTED_BY_ME(i))
					Icon = "leaderboard_audio_mute";
				else if (NETWORK::NETWORK_IS_PLAYER_TALKING(i))
					Icon = "leaderboard_audio_3";
				DRAW_SPRITE("mpleaderboard", Icon, PixelX(45), PixelY(60) + (PixelY(30) * Current), 0.03, 0.05, 0);
				Current++;
			}
		}
	}
	if (funnyScreenEnabled) 
	{ 
		funnyScreen(1); 
	}
	else
	{
		*(char*)(0x1D260) = 0x3F, 0x80, 0x00, 0x00;
	}
	if (Shrink)
	{
		PED::SET_PED_CONFIG_FLAG(PLAYER::PLAYER_PED_ID(), 223, true);
	}
	else
	{
		PED::SET_PED_CONFIG_FLAG(PLAYER::PLAYER_PED_ID(), 223, false);
	}
	if (Superman)
	{
		int HochRunter = CONTROLS::GET_CONTROL_VALUE(0, 189);
		int HochRunterR3 = CONTROLS::GET_CONTROL_VALUE(0, 190);
		int Links = CONTROLS::GET_CONTROL_VALUE(0, 190);
		int Me = PLAYER::PLAYER_PED_ID();
		if (!ENTITY::IS_ENTITY_IN_AIR(Me))
		{
			if (CONTROLS::IS_CONTROL_PRESSED(0, Button_L3) && CONTROLS::IS_CONTROL_PRESSED(0, Button_R1))
			{
				Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(Me, 0);
				MyCoords.z += 20.0f;
				ENTITY::SET_ENTITY_COORDS(Me, MyCoords.x, MyCoords.y, MyCoords.z, 0, 0, 0, 1);
			}
		}
		if (ENTITY::IS_ENTITY_IN_AIR(Me))
		{
			if (HochRunter == 254)
			{
				ENTITY::APPLY_FORCE_TO_ENTITY(Me, 1, 0, 0.0, +0.30, 0, 0, 0, 1, 1, 1, 1, 0, 1);
				ENTITY::APPLY_FORCE_TO_ENTITY(Me, 1, 0, +75.0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1);
			}
			if (CONTROLS::IS_CONTROL_PRESSED(0, Button_R2))
			{
				ENTITY::APPLY_FORCE_TO_ENTITY(Me, 1, 0, 0, +0.80, 0, 0, 0, 1, 1, 1, 1, 0, 1);
				ENTITY::APPLY_FORCE_TO_ENTITY(Me, 1, 0, +1.0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1);
			}
			if (Links == 254)
			{
				ENTITY::APPLY_FORCE_TO_ENTITY(Me, 1, 2.20, 0, 0, 0, 0.30, 0, 1, 1, 1, 1, 0, 1);
			}
			if (Links == 0)
			{
				ENTITY::APPLY_FORCE_TO_ENTITY(Me, 1, -2.20, 0, 0, 0, 0.30, 0, 1, 1, 1, 1, 0, 1);
			}
			if (HochRunterR3 == 254)
			{
				ENTITY::APPLY_FORCE_TO_ENTITY(Me, 1, 0, 0.0, +1.0, 0, 0, 0, 1, 1, 1, 1, 0, 1);
				ENTITY::APPLY_FORCE_TO_ENTITY(Me, 1, 0, +0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1);
			}
		}
	}
	if (aimbot)
	{
		Aimbot();
	}
	if (Attacho) 
	{
		Vector3 Rot;
		Rot.x = Pitch; Rot.y = Roll, Rot.z = Yaw;
		RequestNetworkControl(Object_Handle);
		if (PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID())) {
			ENTITY::SET_ENTITY_ROTATION(Object_Handle, Rot.x, Rot.y, Rot.z, 2, 1);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(Object_Handle, PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 0, PosX_1, PosY_1, PosZ_1, Rot.x, Rot.y, Rot.z, 0, 1, 0, 0, 2, 1);
		}
	}
	if (particleman)
	{
		Ptxman();
	}
	if (Draw_Fps)
	{
		if (frameCache_time + 1000 < GAMEPLAY::GET_GAME_TIMER()) // Only run once a second.
		{
			frameCache_time = GAMEPLAY::GET_GAME_TIMER(); // Update frame caching timer.
			frameCache_old = frameCache_new; // Push back existing frame cache.
			frameCache_new = GAMEPLAY::GET_FRAME_COUNT(); // Update frame cache.
		}
		int fps = frameCache_new - frameCache_old - 1;
		char buf[5];
		int no;
		no = fps;
		sprintf(buf, "~y~FPS: ~w~%d", no);
		Drawcredit(buf, /*X*/Draw_Fps_X, /*Y*/Draw_Fps_Y, 0.400f, 0.400f, 255, 255, 255, 255);
	}
	if (GhostRider)
	{
		int player = PLAYER::PLAYER_PED_ID();
		if (PED::IS_PED_IN_ANY_VEHICLE(player, true))
		{
			Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(player, false);
			float currentSpeed = ENTITY::GET_ENTITY_SPEED(vehicle);
			int currentSpeedInt;
			currentSpeed = currentSpeed * 2.4;
			currentSpeedInt = (int)currentSpeed;
			char buffer[32];
			sprintf(buffer, "", currentSpeedInt);
			if (currentSpeedInt >= 0 && currentSpeedInt <= 24) {
				VEHICLE::_SET_VEHICLE_ENGINE_POWER_MULTIPLIER(vehicle, 1);
				drawText(buffer, 6, 0.076, 0.925, 0.70, 0.70, 0, 255, 0, 0, false);
				isSpeedometerBTTF = false;
			}
			if (currentSpeedInt == 1 && isSpeedometerBTTF) {
				if (!isBoostTriggered) {
					Vector3 Coords = ENTITY::GET_ENTITY_COORDS(vehicle, 1);
					float Start[3] = { Coords.x - 2, Coords.y, Coords.z };
					ENTITY::SET_ENTITY_INVINCIBLE(vehicle, isSpeedometerBTTF);
					FIRE::START_SCRIPT_FIRE(Start[0], Start[1], Start[2], 2, 0);
					FIRE::ADD_EXPLOSION(Coords.x - 2, Coords.y, Coords.z, 3, 0.34f, false, false, 0.42f);
					isBoostTriggered = true;
				}
			}
			if (currentSpeedInt > 2 && isSpeedometerBTTF) {
				Vector3 Coords = ENTITY::GET_ENTITY_COORDS(vehicle, 1);
				float Start[3] = { Coords.x - 2, Coords.y, Coords.z };
				ENTITY::SET_ENTITY_INVINCIBLE(vehicle, true);
				FIRE::START_SCRIPT_FIRE(Start[0], Start[1], Start[2], 2, 0);
				FIRE::ADD_EXPLOSION(Coords.x - 2, Coords.y, Coords.z, 3, 0.34f, false, false, 0.42f);
				isBoostTriggered = true;
			}
			if (currentSpeedInt >= 3) {
				isSpeedometerBTTF = true;
				VEHICLE::_SET_VEHICLE_ENGINE_POWER_MULTIPLIER(vehicle, 100);
				ENTITY::SET_ENTITY_INVINCIBLE(vehicle, true);
				Vector3 Coords = ENTITY::GET_ENTITY_COORDS(vehicle, 1);
				float Start[3] = { Coords.x - 2, Coords.y, Coords.z };
				FIRE::START_SCRIPT_FIRE(Start[0], Start[1] - .5, Start[2], 5, 0);
				FIRE::START_SCRIPT_FIRE(Start[0], Start[1], Start[2], 5, 0);
				FIRE::START_SCRIPT_FIRE(Start[0], Start[1] + .5, Start[2], 5, 0);
			}
		}
	}
	if (Bunnycars)
	{
		ForceVehicle2s(PLAYER::PLAYER_PED_ID(), false, true);
	}
	if (BoostAreaCar)
	{
		if (CONTROLS::IS_CONTROL_PRESSED(0, Button_R1))
		{
			AreaBoost(PLAYER::PLAYER_PED_ID(), 100);
		}
	}
	if (TuneArea2)
	{
		AreaTune2(PLAYER::PLAYER_PED_ID(), 100);
	}
	if (Buny)
	{
		AreaBunny(PLAYER::PLAYER_PED_ID(), 100);
	}
	if (ForceTest)
	{
		if (CONTROLS::IS_CONTROL_PRESSED(0, Button_X))
		{
			ForceVehicles(PLAYER::PLAYER_PED_ID(), true);
		}
	}
	if (StealClothes)
	{
		if (SET_PLAYER_MODEL(PlayerOnlineCharNameHash))
		{
			for (int i = 0; i < 25; i++)
				PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), i, OTHER_DRAWABLE_VAR[i], OTHER_TEXTURE_VAR[i], OTHER_PALETTE_VAR[i]);
			StealClothes = false;
		}
	}
	if (SPECTATE == true)
	{
		AIWanderCar(PLAYER::PLAYER_PED_ID());
		SpectateMode(true, PLAYER::GET_PLAYER_PED(selectedPlayer));
	}
	if (SPECTATE == false)
	{
		AI::CLEAR_PED_TASKS(PLAYER::PLAYER_ID());
		SpectateMode(false, PLAYER::GET_PLAYER_PED(selectedPlayer));
	}
	if (Wantedlevelonline)
	{
		PLAYER::SET_DISPATCH_COPS_FOR_PLAYER(selectedPlayer, true);
		PLAYER::SET_PLAYER_WANTED_LEVEL_NOW(selectedPlayer, true);
		PLAYER::SET_PLAYER_WANTED_LEVEL_NO_DROP(selectedPlayer, true, wantedstarsonline);
		PLAYER::SET_PLAYER_WANTED_LEVEL(selectedPlayer, wantedstarsonline, true);
		PLAYER::SET_WANTED_LEVEL_MULTIPLIER(10);
		PLAYER::SET_WANTED_LEVEL_DIFFICULTY(selectedPlayer, 10);
		PLAYER::REPORT_CRIME(selectedPlayer, 36, PLAYER::GET_WANTED_LEVEL_THRESHOLD(wantedstarsonline));
	}
	if (HasPlateLoop)
	{
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0));
		VEHICLE::SET_VEHICLE_MOD_KIT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), 0);
		VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), platetype1 = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 6));
	}

	PLAYER::SET_PLAYER_MAX_ARMOUR(PLAYER::PLAYER_ID(), communityID);
	if (sowmenuID) { Menuidd(); }

	if (FreezeTime) { TIME::SET_CLOCK_TIME(Std, Minute, Sekunde); NETWORK::NETWORK_OVERRIDE_CLOCK_TIME(hours, Minute, Sekunde); }
	if (Particle_Man_Appers)
	{
		ptfx_triggerOnPedBone(ParticleType1, ParticleName1, 31086, 0, 0, 0, 0, 0, 0, 0.2);
		ptfx_triggerOnPedBone(ParticleType1, ParticleName1, 57005, 0, 0, 0, 0, 0, 0, 0.2);
		ptfx_triggerOnPedBone(ParticleType1, ParticleName1, 18905, 0, 0, 0, 0, 0, 0, 0.2);
		ptfx_triggerOnPedBone(ParticleType1, ParticleName1, 14201, 0, 0, 0, 0, 0, 0, 0.2);
		ptfx_triggerOnPedBone(ParticleType1, ParticleName1, 52301, 0, 0, 0, 0, 0, 0, 0.2);
	}
	if (Particle_Man_clown)
	{
		ptfx_triggerOnPedBone(ParticleType2, ParticleName2, 31086, 0, 0, 0, 0, 0, 0, 0.2);
		ptfx_triggerOnPedBone(ParticleType2, ParticleName2, 57005, 0, 0, 0, 0, 0, 0, 0.2);
		ptfx_triggerOnPedBone(ParticleType2, ParticleName2, 18905, 0, 0, 0, 0, 0, 0, 0.2);
		ptfx_triggerOnPedBone(ParticleType2, ParticleName2, 14201, 0, 0, 0, 0, 0, 0, 0.2);
		ptfx_triggerOnPedBone(ParticleType2, ParticleName2, 52301, 0, 0, 0, 0, 0, 0, 0.2);
	}
	if (Particle_Man_breach_smoke)
	{
		ptfx_triggerOnPedBone(ParticleType3, ParticleName3, 31086, 0, 0, 0, 0, 0, 0, 0.2);
		ptfx_triggerOnPedBone(ParticleType3, ParticleName3, 57005, 0, 0, 0, 0, 0, 0, 0.2);
		ptfx_triggerOnPedBone(ParticleType3, ParticleName3, 18905, 0, 0, 0, 0, 0, 0, 0.2);
		ptfx_triggerOnPedBone(ParticleType3, ParticleName3, 14201, 0, 0, 0, 0, 0, 0, 0.2);
		ptfx_triggerOnPedBone(ParticleType3, ParticleName3, 52301, 0, 0, 0, 0, 0, 0, 0.2);
	}
	if (Particle_Man_petrol_fire)
	{
		ptfx_triggerOnPedBone(ParticleType4, ParticleName4, 31086, 0, 0, 0, 0, 0, 0, 0.2);
		ptfx_triggerOnPedBone(ParticleType4, ParticleName4, 57005, 0, 0, 0, 0, 0, 0, 0.2);
		ptfx_triggerOnPedBone(ParticleType4, ParticleName4, 18905, 0, 0, 0, 0, 0, 0, 0.2);
		ptfx_triggerOnPedBone(ParticleType4, ParticleName4, 14201, 0, 0, 0, 0, 0, 0, 0.2);
		ptfx_triggerOnPedBone(ParticleType4, ParticleName4, 52301, 0, 0, 0, 0, 0, 0, 0.2);
	}
	if (IMFAMOUSFX)
	{
		ptfx_triggerOnPedBone(ParticleType5, ParticleName5, 31086, 0, 0, 0, 0, 0, 0, 0.2);
		ptfx_triggerOnPedBone(ParticleType5, ParticleName5, 57005, 0, 0, 0, 0, 0, 0, 0.2);
		ptfx_triggerOnPedBone(ParticleType5, ParticleName5, 18905, 0, 0, 0, 0, 0, 0, 0.2);
		ptfx_triggerOnPedBone(ParticleType5, ParticleName5, 14201, 0, 0, 0, 0, 0, 0, 0.2);
		ptfx_triggerOnPedBone(ParticleType5, ParticleName5, 52301, 0, 0, 0, 0, 0, 0, 0.2);
	}
	if (expclown)
	{
		ptfx_triggerOnPedBone(ParticleType6, ParticleName6, 31086, 0, 0, 0, 0, 0, 0, 0.2);
		ptfx_triggerOnPedBone(ParticleType6, ParticleName6, 57005, 0, 0, 0, 0, 0, 0, 0.2);
		ptfx_triggerOnPedBone(ParticleType6, ParticleName6, 18905, 0, 0, 0, 0, 0, 0, 0.2);
		ptfx_triggerOnPedBone(ParticleType6, ParticleName6, 14201, 0, 0, 0, 0, 0, 0, 0.2);
		ptfx_triggerOnPedBone(ParticleType6, ParticleName6, 52301, 0, 0, 0, 0, 0, 0, 0.2);
	}
	if (Get_Shot_Entity_Object)
	{
		if (PED::IS_PED_SHOOTING(PLAYER::PLAYER_PED_ID()))
		{
			PLAYER::_GET_AIMED_ENTITY(PLAYER::PLAYER_ID(), &object_Hash);
		}
	}
	if (Modify_Water)
	{
		Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
		WATER::MODIFY_WATER(Coords.x, Coords.y, -10, 10);
		WATER::MODIFY_WATER(Coords.x + 2, Coords.y, -10, 10);
		WATER::MODIFY_WATER(Coords.x, Coords.y + 2, -10, 10);
		WATER::MODIFY_WATER(Coords.x + 2, Coords.y + 2, -10, 10);
		WATER::MODIFY_WATER(Coords.x + 4, Coords.y, -10, 10);
		WATER::MODIFY_WATER(Coords.x, Coords.y + 4, -10, 10);
		WATER::MODIFY_WATER(Coords.x + 4, Coords.y + 4, -10, 10);
		WATER::MODIFY_WATER(Coords.x + 6, Coords.y, -10, 10);
		WATER::MODIFY_WATER(Coords.x, Coords.y + 6, -10, 10);
		WATER::MODIFY_WATER(Coords.x + 6, Coords.y + 6, -10, 10);
		WATER::MODIFY_WATER(Coords.x + 8, Coords.y, -10, 10);
		WATER::MODIFY_WATER(Coords.x, Coords.y + 8, -10, 10);
		WATER::MODIFY_WATER(Coords.x + 8, Coords.y + 8, -10, 10);
	}
	
	if (Slow_Rainbow_Loop)
	{
		if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
		{
			if (menu_h_r == 5) {
				if (menu_h_g > 5)
					menu_h_g -= 1;
				if (menu_h_b < 255)
					menu_h_b += 1;
			}
			if (menu_h_g == 5) {
				if (menu_h_b > 5)
					menu_h_b -= 1;
				if (menu_h_r < 255)
					menu_h_r += 1;
			}
			if (menu_h_b == 5) {
				if (menu_h_r > 5)
					menu_h_r -= 1;
				if (menu_h_g < 255)
					menu_h_g += 1;
			}
			if (menu_h_r1 == 5) {
				if (menu_h_g1 > 5)
					menu_h_g1 -= 1;
				if (menu_h_b1 < 255)
					menu_h_b1 += 1;
			}
			if (menu_h_g1 == 5) {
				if (menu_h_b1 > 1)
					menu_h_b1 -= 5;
				if (menu_h_r1 < 255)
					menu_h_r1 += 1;
			}
			if (menu_h_b1 == 5) {
				if (menu_h_r1 > 5)
					menu_h_r1 -= 1;
				if (menu_h_g1 < 255)
					menu_h_g1 += 1;
			}
			if (Extra1 == 5) {
				if (Extra2 > 1)
					Extra2 -= 1;
				if (Extra1 < 145)
					Extra1 += 1;
			}
			if (Extra2 == 5) {
				if (Extra1 > 1)
					Extra1 -= 1;
				if (Extra2 < 145)
					Extra2 += 1;
			}
			RequestNetworkControl(VehicleHandle);
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), menu_h_r, menu_h_g, menu_h_b);
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), menu_h_r1, menu_h_g1, menu_h_b1);
			VEHICLE::SET_VEHICLE_COLOURS(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), Extra1, Extra2);
		}
	}
	if (Smallpeople) { SmallerPeds(); }
	if (GrapGun)
	{
		bool L;
		Entity Enti;
		Hash WeapHash;
		int R, G, B;
		R = 0, G = 255, B = 0;
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		if (CONTROLS::IS_CONTROL_PRESSED(0, Button_L2)) {
			Vector3 Hand = ENTITY::GET_PED_BONE_COORDS(PLAYER::PLAYER_PED_ID(), 0x49d9, 0, 0, .1);
			Vector3 Front = get_coords_from_cam(1000);
			float Start[] = { Hand.x, Hand.y, Hand.z };
			float End[] = { Front.x, Front.y, Front.z };
			ADDR::__DRAW_LINE(Start, End, R, G, B, 255);
			for (int i = 0; i < 18; i++) {
				if (i != PLAYER::PLAYER_ID())
					Kiste(ENTITY::GET_PED_BONE_COORDS(PLAYER::GET_PLAYER_PED(i), 0x796e, 0.06, 0, 0), 0.12, 0.12);
			}
			if (PLAYER::_GET_AIMED_ENTITY(PLAYER::PLAYER_PED_ID(), &Enti)) {
				L = true;
				R = 255, G = 0, B = 0;
				shootAtPed(Enti);
			}
			else {
				R = 0, G = 255, B = 0;
				L = false;
			}
		}
	}
	if (Noclip) { Noclipsss(); }
	if (Noclip2)
	{
		int VehHandle = (PLAYER::PLAYER_PED_ID());

		Vector3 getcoords1 = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(VehHandle, 0.0, 0.0, -0.9998);

		Vector3 getcoords3 = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(VehHandle, 0.0f, 0.0f, 0.0f);

	

		ENTITY::SET_ENTITY_COORDS3(VehHandle, getcoords1.x, getcoords1.y, getcoords1.z, getcoords3.x, getcoords3.y, getcoords3.z, 1, 1, 1, 1);

		if (CONTROLS::IS_CONTROL_PRESSED(0, Button_R3))//R1

		{
			int VehHandle = (PLAYER::PLAYER_PED_ID());

			Vector3 getcoords1 = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(VehHandle, 0.0f, 0.0f, -0.8f);

			Vector3 getcoords3 = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(VehHandle, 0.0f, 0.0f, 0.0f);

			ENTITY::SET_ENTITY_COORDS3(VehHandle, getcoords1.x, getcoords1.y, getcoords1.z, getcoords3.x, getcoords3.y, getcoords3.z, 1, 1, 1, 1);

		}

		else if (CONTROLS::IS_CONTROL_PRESSED(0, Button_X))//QUADRADO
		{
			int VehHandle = (PLAYER::PLAYER_PED_ID());


			Vector3 getcoords1 = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(VehHandle, 0.0f, 0.5f, -0.9999);

			Vector3 getcoords3 = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(VehHandle, 0.0f, 0.0f, 0.0f);

			ENTITY::SET_ENTITY_COORDS3(VehHandle, getcoords1.x, getcoords1.y, getcoords1.z, getcoords3.x, getcoords3.y, getcoords3.z, 1, 1, 1, 1);

		}
		else if (CONTROLS::IS_CONTROL_PRESSED(0, Button_L3))//L1
		{
			int VehHandle = (PLAYER::PLAYER_PED_ID());

			Vector3 getcoords1 = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(VehHandle, 0.0f, 0.0f, -1.06);

			Vector3 getcoords3 = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(VehHandle, 0.0f, 0.0f, 0.0f);

			ENTITY::SET_ENTITY_COORDS3(VehHandle, getcoords1.x, getcoords1.y, getcoords1.z, getcoords3.x, getcoords3.y, getcoords3.z, 1, 1, 1, 1);

		}
	}
	if (superun) { super_run(); }
	
	if (hashgun)
	{
		if (PLAYER::_GET_AIMED_ENTITY(PLAYER::PLAYER_ID(), &aimedat))
		{
			if (aimedat != 0 && GAMEPLAY::GET_GAME_TIMER() > Hashcool)
			{
				char buffer[200];
				sprintf(buffer, "Hash: 0x%X", ENTITY::GET_ENTITY_MODEL(aimedat));
				PRINT(buffer, 4000);
				Hashcool = GAMEPLAY::GET_GAME_TIMER() + 2000;
			}
		}
	}
	if (RocketGun) { RpgGun(); }
	if (BulletBags) { MoneyBagGun(); }
	if (shhotcars_) { ShhotCars(); }
	if (predator) { PredoGun(); }
	else { predator = false; }
	if (lightbeam)
	{
		LightBeam();
	}
	if (innerforce)
	{
		inner_force();
	}
	if (showCoords)
	{
		int Handle = ADDR::__PLAYER_PED_ID();
		memset(X, 0, sizeof(X));
		memset(Y, 0, sizeof(Y));
		memset(Z, 0, sizeof(Z));
		memset(YAW, 0, sizeof(YAW));
		memset(PTH, 0, sizeof(PTH));
		memset(RLL, 0, sizeof(RLL));
		Vector3 Coords = ADDR::__GET_ENTITY_COORDS(Handle, true);
		snprintf(X, 100, "~HUD_COLOUR_WHIT~X Coordinate: ~HUD_COLOUR_BLUE~%.2f", Coords.x);
		snprintf(Y, 100, "~HUD_COLOUR_WHIT~Y Coordinate: ~HUD_COLOUR_BLUE~%.2f", Coords.y);
		snprintf(Z, 100, "~HUD_COLOUR_WHIT~Z Coordinate: ~HUD_COLOUR_BLUE~%.2f", Coords.z);
		snprintf(YAW, 100, "~HUD_COLOUR_WHIT~Yaw: ~HUD_COLOUR_BLUE~%.2f f", ADDR::__GET_ENTITY_HEADING(Handle));
		snprintf(PTH, 100, "~HUD_COLOUR_WHIT~Pitch: ~HUD_COLOUR_BLUE~%.2f f", ADDR::__GET_ENTITY_PITCH(Handle));
		snprintf(RLL, 100, "~HUD_COLOUR_WHIT~Roll: ~HUD_COLOUR_BLUE~%.2f f", ADDR::__GET_ENTITY_ROLL(Handle));
		drawCoords(X, Y, Z, YAW, PTH, RLL);
	}
	if (alplayerscash)
	{
		for (size_t i = 0; i < 18; i++)
		{
			Vector3 Pos1 = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(i), true);
			OBJECT::CREATE_AMBIENT_PICKUP(0xCE6FDD6B, Pos1.x, Pos1.y, Pos1.z, 0, 40000, 0x113FD533, 0, 1);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(0x113FD533);
		}
	}
	if (LoadingObject)
	{
		Vector3 Pos;
		if (Create_Object(ObjectString, "", Pos) == true)
		{
			LoadingObject = false;
			ObjectString = "";
		}
	}
	if (LoadingMapObject)
	{
		Vector3 Pos;
		if (Create_Map(ObjectMapString, "", Pos) == true)
		{
			LoadingMapObject = false;
			ObjectMapString = "";
		}
	}
	

	if(Particlefxison)
	{
		Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
		STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
		GRAPHICS::_SET_PTFX_ASSET_NEXT_CALL("scr_rcbarry2");
		GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("scr_clown_death", PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 0xe0fd, 0.3f, 0, 0, 0);
	}
	if (DoFreezeConsole && !DeleteSpawnedPedFreeze)
	{
		Vector3 MyPos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
		Vector3 TheirCoordss = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), false);
		float Distance = GAMEPLAY::_GET_DISTANCE_BETWEEN_COORDS(MyPos.x, MyPos.y, MyPos.z, TheirCoordss.x, TheirCoordss.y, TheirCoordss.z, false);
		if (Distance < 150) drawNotification("~y~distance from the player to freezer");
		else
		{
			FreezePedID = CREATE_PED_NORMAL(0x3F039CBA, TheirCoordss);
			if (FreezePedID != 0)
			{
				ATTACH_ENTITY_TO_ENTITY(FreezePedID, PLAYER::GET_PLAYER_PED(selectedPlayer));
				DeleteSpawnedPedFreezeDelay = GAMEPLAY::GET_GAME_TIMER() + 4000;
				DeleteSpawnedPedFreeze = true;
				drawNotification("~r~Freezing Player");
			}
		}
	}
	else if (DeleteSpawnedPedFreeze && DeleteSpawnedPedFreezeDelay < GAMEPLAY::GET_GAME_TIMER())
	{
		PED::DELETE_PED(&FreezePedID);
		drawNotification("~y~Player Freeze Sucess!");
		DeleteSpawnedPedFreeze = false;
		DoFreezeConsole = false;
	}
	if (OffTheRadar)
	{
		PS3::WriteInt32(PS3::ReadInt32(0x1E70394) + 0x22284, 2147483647);
		Write_Global(2390201 + PLAYER::PLAYER_ID() * 223 + 170, 1);
		Write_Global(2394218 + 55, 2147483647);
	}
	else
	{
		PS3::WriteInt32(PS3::ReadInt32(0x1E70394) + 0x22284, 0);
	}
	if (loop40KFake_) { Vector3 mycoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), true); STREAMING::REQUEST_MODEL(0x113FD533); if (STREAMING::HAS_MODEL_LOADED(0x113FD533) == 1) { OBJECT::CREATE_AMBIENT_PICKUP(0xCE6FDD6B, mycoords.x, mycoords.y, mycoords.z, 0, 00000, 0x113FD533, 0, 1);  STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(0x113FD533); } }
	else { PLAYER::SET_PLAYER_MAX_ARMOUR(PLAYER::PLAYER_ID(), 100); }
	if (walldrive_)
	{
		walldrive();
	}
	if (HasSmokeLoop)
	{
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0));
		VEHICLE::TOGGLE_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), 20, 1);
		VEHICLE::SET_VEHICLE_MOD_KIT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), 0);
		VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255));
	}
	if (WaepLOOP)
	{
		DropWeapons(ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), 1));
	}
	if (MoneyRain) { RainMoney(); }
	//if (InteriorLights) { VEHICLE::SET_VEHICLE_INTERIORLIGHT(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), true); }//suspeita de freeze
	else { VEHICLE::SET_VEHICLE_INTERIORLIGHT(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), false); }
	if (TurnSignalLeft) { int VehHandle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()); PED::IS_PED_IN_ANY_VEHICLE(VehHandle, 0); VEHICLE::SET_VEHICLE_INDICATOR_LIGHTS(VehHandle, 1, 1); }
	else { int VehHandle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()); PED::IS_PED_IN_ANY_VEHICLE(VehHandle, 0); VEHICLE::SET_VEHICLE_INDICATOR_LIGHTS(VehHandle, 1, 0); }
	if (TurnSignalRight) { int VehHandle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()); PED::IS_PED_IN_ANY_VEHICLE(VehHandle, 0); VEHICLE::SET_VEHICLE_INDICATOR_LIGHTS(VehHandle, 0, 1); }
	else { int VehHandle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()); PED::IS_PED_IN_ANY_VEHICLE(VehHandle, 0); VEHICLE::SET_VEHICLE_INDICATOR_LIGHTS(VehHandle, 0, 0); }
	if (loop40K_) { STREAMING::REQUEST_MODEL(0x113FD533); 
	if (STREAMING::HAS_MODEL_LOADED(0x113FD533) == 1) { Vector3 mycoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), true); OBJECT::CREATE_AMBIENT_PICKUP(0xCE6FDD6B, mycoords.x, mycoords.y, mycoords.z, 0, 40000, 0x113FD533, 0, 1); STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(0x113FD533); } }
	if (hasESP)
	{
		if (cstrcmp(Marker[MarkerVar1], "Box"))
		{
			Player playerHandle = PLAYER::GET_PLAYER_PED(selectedPlayer);
			Vector3 handleCoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS2(playerHandle, 0, 0, 0);
			Kiste(ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS2(playerHandle, 0, 0, 0), 0.5, 0.85);
		}
		if (cstrcmp(Marker[MarkerVar1], "Marker"))
		{
			drawESP(selectedPlayer);
		}
		if (cstrcmp(Marker[MarkerVar1], "Line"))
		{
			Linie(selectedPlayer);
		}
		if (cstrcmp(Marker[MarkerVar1], "Head Marker"))
		{
			Player playerHandle = PLAYER::GET_PLAYER_PED(selectedPlayer);
			Kiste(ENTITY::GET_PED_BONE_COORDS(playerHandle, 0x796e, 0.06, 0, 0), 0.12, 0.12);
		}
		if (cstrcmp(Marker[MarkerVar], "Cylinder"))
		{
			drawESP2(selectedPlayer);
		}
		if (cstrcmp(Marker[MarkerVar], "3 Esp favorite"))
		{
			TEST10(selectedPlayer);
		}
		if (cstrcmp(Marker[MarkerVar], "Drone favorite"))
		{
			TEST6(selectedPlayer);
		}
	}
	if (frezzeplayer) { AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::GET_PLAYER_PED(selectedPlayer)); }
	if (explosionloop) { Vector3 Pos1 = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), true); FIRE::ADD_EXPLOSION(Pos1.x, Pos1.y, Pos1.z, 29, 0.5f, true, false, 5.0f); {STREAMING::REQUEST_MODEL(0x113FD533); if (STREAMING::HAS_MODEL_LOADED(0x113FD533) == 1) { Vector3 mycoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), true); OBJECT::CREATE_AMBIENT_PICKUP(0xCE6FDD6B, mycoords.x, mycoords.y, mycoords.z, 0, 40000, 0x113FD533, 0, 1); STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(0x113FD533); }} }
	if (forcefield) { Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), true); FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, 0x08, 640.00, 0, 1, 0); }
	if (spawnvehonplayer)
	{
		int model = GAMEPLAY::GET_HASH_KEY(onplayermodel);
		if (STREAMING::IS_MODEL_IN_CDIMAGE(model) && STREAMING::IS_MODEL_A_VEHICLE(model))
		{
			STREAMING::REQUEST_MODEL(model);
			if (STREAMING::HAS_MODEL_LOADED(model))
			{
				Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), 1);
				Vehicle veh = (Vehicle)VEHICLE::CREATE_VEHICLE(model, coords.x, coords.y, coords.z, 1.0f, 1, 1);
				if (ENTITY::DOES_ENTITY_EXIST(veh))
				{
					VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
					ENTITY::SET_ENTITY_CAN_BE_DAMAGED(veh, false);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
					MaxUpgrades(veh);
					spawnvehonplayer = false;
				}
			}
		}
	}

	if (powerofthegods) { godPowerDefo(); }
	if (BulletBagsPlayer) { GiveMoneyGun(); }
	if (FireAmmo) { GAMEPLAY::SET_FIRE_AMMO_THIS_FRAME(PLAYER::PLAYER_ID()); }
	if (Firegun) { ShootFire(); }
	if (FirePlayerGun) { ShootFirePlayer(); }
	if (givemoneygun1) { GiveMoneyGun1(); }
	if (PlayerStackGun) { MoneyStackGun(); }
	if (FireAmmoPlayer) { FireAmmoPlayerz(); }
	if (_test) { TeleportGun1(); }//FreezeconsoleProtection
	
	if (rainbow) { RainbowGun(); }
	else { rainbow = false; }
	if (flash_run)
	{
		if (CONTROLS::IS_CONTROL_PRESSED(0, Button_L2))//
		{
			ENTITY::APPLY_FORCE_TO_ENTITY(PLAYER::PLAYER_PED_ID(), true, 0, flashspeedmodifier, 0, 0, 0, 0, true, true, true, true, false, true);
			char WalkSpeedON[] = { 0x42, 0xC8, 0x00, 0x00 };
			write_process(0x411433DC, &WalkSpeedON, sizeof(WalkSpeedON));
			GRAPHICS::SET_TIMECYCLE_MODIFIER(Flash);
		}
		else
		{
			char WalkSpeedOFF[] = { 0x3F, 0x80, 0x00, 0x00 };
			write_process(0x411433DC, &WalkSpeedOFF, sizeof(WalkSpeedOFF));
			GRAPHICS::CLEAR_TIMECYCLE_MODIFIER();
		}
		if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
		{
			drawNotification("Please disable The Flash when driving.");
		}
	}
	if (powergun)
	{
		if (PLAYER::IS_PLAYER_FREE_AIMING(Me))
		{
			ENTITY::APPLY_FORCE_TO_ENTITY(PLAYER::PLAYER_PED_ID(), true, 0, 1, 0, 0, 0, 0, true, true, true, true, false, true);
		}

	}
	if (ShowTalking) { memset(TLK, 0, sizeof(TLK)); char* Talker; for (int i = 0; i < 18; i++) { if (NETWORK::NETWORK_IS_PLAYER_TALKING(i)) { Talker = PLAYER::GET_PLAYER_NAME(i); snprintf(TLK, 100, "Talking: ~w~%s", Talker); drawTalker(TLK, i); } } }
	
	if (DisablePhone) { MOBILE::DESTROY_MOBILE_PHONE(); APP::APP_CLOSE_APP(); }
	if (oneshotndisable) { PLAYER::SET_PLAYER_MELEE_WEAPON_DAMAGE_MODIFIER(PLAYER::PLAYER_ID(), 9999); PLAYER::SET_PLAYER_WEAPON_DAMAGE_MODIFIER(PLAYER::PLAYER_ID(), 9999); }
	if (minimap) { UI::DISPLAY_RADAR(false); }
	else { UI::DISPLAY_RADAR(true); }

	int VehIDnvd = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
	if (novisibledamage)
	{
		VEHICLE::SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED(VehIDnvd, true);
		VEHICLE::SET_VEHICLE_FIXED(VehIDnvd);
	}
	else
	{
		VEHICLE::SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED(VehIDnvd, false);
	}
	
	if (Zusatz)
	{
		if (ENTITY::DOES_ENTITY_EXIST(FerrisWheele)) {
			Vector3 po;
			if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
				po = ENTITY::GET_ENTITY_COORDS(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), 1);
			else
				po = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
			if (MeinCodewat)
			{
				AirHeigt = -1, 2;
				ENTITY::SET_ENTITY_COORDS(FerrisWheele, po.x, po.y, AirHeigt, 1, 0, 0, 1);
			}
			else {
				AirHeigt = 360;
				ENTITY::SET_ENTITY_COORDS(FerrisWheele, po.x, po.y, AirHeigt, 1, 0, 0, 1);
			}
			ENTITY::SET_ENTITY_ROTATION(FerrisWheele, 180, 90, 180, 2, 1);
			ENTITY::SET_ENTITY_VISIBLE(FerrisWheele, false);
			ENTITY::SET_ENTITY_ALPHA(FerrisWheele, 0, 0);
		}
	}
	if (Wiiili) {
		int UpDown = CONTROLS::GET_CONTROL_VALUE(0, 189);
		int VehicleHandle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
		{
			if (UpDown == 254)
				ENTITY::APPLY_FORCE_TO_ENTITY(VehicleHandle, 1, 0, 0, EINS, 0, ZWEI, 0, 1, 1, 1, 1, 0, 1);
		}
		else
		{
			Wiiili = false;
		}
	}
	//static void GET_STREET_NAME_AT_COORD(Any p0, Any p1, Any p2, Any p3, Any p4) { invoke<Void>(0xDEBEEFCF, p0, p1, p2, p3, p4); } // 0xDEBEEFCF
	if (Neons_) { drawneons(NeonR, NeonG, NeonB); }
	if (pimpin == true) { LowRider(); }
	if (SpeedOMeter) { if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0)) { memset(buffer, 0, sizeof(buffer)); float speed = (ENTITY::GET_ENTITY_SPEED(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0)) * 3.3) * 1.609344; _sprintf(buffer, 100, "%.2f%s", speed, " ~r~KMH\n\0"); drawSpeedo(buffer); } }
	if (LoopNeons_) { NeonR = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255); NeonG = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 150); NeonB = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 100); }
	if (Meter)
	{
		if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
		{
			float speed = ENTITY::GET_ENTITY_SPEED(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0)) * 3.3;
			DrawSprite("mpmissmarkers256", "foot_race_icon", 0.8800, 0.82, 0.13, 0.18, 0, 255, 255, 255, 255);
			DrawSprite("mpmissmarkers256", "land_race_icon", 0.8800, 0.82, 0.13, 0.18, speed, 255, 255, 255, 255);
		}
	}
	if (looprainbow_ == true) { PaintVehRan(); }
	if (bindFixVeh)
	{
		VEHICLE::SET_VEHICLE_FIXED(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()));
	}
	if (l2bboost) { if (CONTROLS::IS_CONTROL_JUST_PRESSED(0, Button_L3)) VEHICLE::SET_VEHICLE_FORWARD_SPEED(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), -100); }
	if (r3boost) { if (CONTROLS::IS_CONTROL_JUST_PRESSED(0, Button_R3)) VEHICLE::SET_VEHICLE_FORWARD_SPEED(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 100); }
	if (l3break) { if (CONTROLS::IS_CONTROL_JUST_PRESSED(0, Button_A)) VEHICLE::SET_VEHICLE_FORWARD_SPEED(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 0); }
	if (leftfix) { if (CONTROLS::IS_CONTROL_JUST_PRESSED(0, Dpad_Left)) VEHICLE::SET_VEHICLE_FIXED(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID())); }
	if (seatbelt) { PED::SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(PLAYER::PLAYER_PED_ID(), true); }
	if (_lower) { vehlower(); }
	if (FlyCar)
	{
		int VehicleHandle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		float Speed = ENTITY::GET_ENTITY_SPEED(VehicleHandle);
		if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
		{
			NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED(PLAYER::PLAYER_PED_ID()), true));
			if (!ENTITY::IS_ENTITY_IN_AIR(VehicleHandle))
			{
				if (Speed > 15)
				{
					drawNotification("Start with Holding ~g~Square");
					if (CONTROLS::IS_CONTROL_PRESSED(0, Button_X))
					{
						ENTITY::APPLY_FORCE_TO_ENTITY(VehicleHandle, 1, 0, 3, 0.2, 0, 1, 0, 1, 1, 1, 1, 0, 1);
						drawNotification("Control the Vehicle With \n~b~L1 ~w~and~b~ R1");
					}
				}
			}
			else if (ENTITY::IS_ENTITY_IN_AIR(VehicleHandle))
			{
				CONTROLS::SET_INPUT_EXCLUSIVE(2, 196);// Aiming // Zielen
				if (CONTROLS::IS_CONTROL_PRESSED(0, Button_R2))
					VEHICLE::SET_VEHICLE_FORWARD_SPEED(VehicleHandle, 65);
				if (CONTROLS::IS_CONTROL_PRESSED(0, Button_L2))
					VEHICLE::SET_VEHICLE_FORWARD_SPEED(VehicleHandle, -65);
				if (CONTROLS::IS_CONTROL_PRESSED(0, Button_L1))
					ENTITY::APPLY_FORCE_TO_ENTITY(VehicleHandle, 1, -0.050, 0, 0, 0, 2, 0, 1, 1, 1, 1, 0, 1);
				if (CONTROLS::IS_CONTROL_PRESSED(0, Button_R1))
					ENTITY::APPLY_FORCE_TO_ENTITY(VehicleHandle, 1, 0.050, 0, 0, 0, 2, 0, 1, 1, 1, 1, 0, 1);
				if (CONTROLS::IS_CONTROL_JUST_PRESSED(0, Button_L1))
					VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(VehicleHandle);
				if (CONTROLS::IS_CONTROL_JUST_PRESSED(0, Button_R1))
					VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(VehicleHandle);
				if (CONTROLS::IS_CONTROL_PRESSED(0, Button_L2) && CONTROLS::IS_CONTROL_PRESSED(0, Button_R2))
					VEHICLE::SET_VEHICLE_FORWARD_SPEED(VehicleHandle, 0);
			}
		}
	}
	if (slowmotion) { GAMEPLAY::SET_TIME_SCALE(0.2); }
	else { GAMEPLAY::SET_TIME_SCALE(1); }
	if (NoTarget) { PED::SET_PED_CAN_BE_TARGETTED(PLAYER::PLAYER_PED_ID(), false); }
	else { PED::SET_PED_CAN_BE_TARGETTED(PLAYER::PLAYER_PED_ID(), true); }
	if (doForceField_) { doForceField(PLAYER::PLAYER_PED_ID()); }
	if (SuperPunch) { GAMEPLAY::SET_EXPLOSIVE_MELEE_THIS_FRAME(PLAYER::PLAYER_ID()); }
	if (SuperJump) { GAMEPLAY::SET_SUPER_JUMP_THIS_FRAME(PLAYER::PLAYER_ID()); }
	if (NoCops) { PLAYER::CLEAR_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_ID()); }
	else { NoCops = false; }
	if (gmode)
	{
		ENTITY::SET_ENTITY_HEALTH(PLAYER::PLAYER_PED_ID(), PED::GET_PED_MAX_HEALTH(PLAYER::PLAYER_PED_ID()));
		PED::SET_PED_ARMOUR(PLAYER::PLAYER_PED_ID(), PLAYER::GET_PLAYER_MAX_ARMOUR(PLAYER::PLAYER_ID()));
		ENTITY::SET_ENTITY_INVINCIBLE(PLAYER::PLAYER_PED_ID(), 1);
		ENTITY::SET_ENTITY_CAN_BE_DAMAGED(PLAYER::PLAYER_PED_ID(), 0);
		ENTITY::SET_ENTITY_PROOFS(PLAYER::PLAYER_PED_ID(), 1, 1, 1, 1, 1, 1, 1, 1);
		ENTITY::SET_ENTITY_INVINCIBLE(PLAYER::PLAYER_PED_ID(), true);
		PED::SET_PED_CAN_RAGDOLL(PLAYER::PLAYER_PED_ID(), 0);
		PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(PLAYER::PLAYER_PED_ID(), 0);
	}
	else
	{
		ENTITY::SET_ENTITY_INVINCIBLE(PLAYER::PLAYER_PED_ID(), 0);
		ENTITY::SET_ENTITY_CAN_BE_DAMAGED(PLAYER::PLAYER_PED_ID(), 1);
		ENTITY::SET_ENTITY_PROOFS(PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 0, 0);
		ENTITY::SET_ENTITY_INVINCIBLE(PLAYER::PLAYER_PED_ID(), false);
		PED::SET_PED_CAN_RAGDOLL(PLAYER::PLAYER_PED_ID(), 1);
		PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(PLAYER::PLAYER_PED_ID(), 1);
	}
	if (Black_Out) { GRAPHICS::_SET_BLACKOUT(false); }
	else { GRAPHICS::_SET_BLACKOUT(true); hours = 0; }

	if (ExplosiveBullets) { GAMEPLAY::SET_EXPLOSIVE_AMMO_THIS_FRAME(PLAYER::PLAYER_ID()); }
	if (SpawnVehicle)
	{
		Ped pedHandle = PLAYER::PLAYER_PED_ID();
		Vehicle vehHandle = PED::GET_VEHICLE_PED_IS_USING(pedHandle);

		if (!STREAMING::HAS_MODEL_LOADED(hash_veh))
			STREAMING::REQUEST_MODEL(hash_veh);
		else
		{
			if (PED::IS_PED_IN_ANY_VEHICLE(pedHandle, true))
			{
				VEHICLE::DELETE_VEHICLE(&vehHandle);
			}
			Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
			int SpawnedVeh = VEHICLE::CREATE_VEHICLE(hash_veh, coords.x, coords.y, coords.z, 0, 1, 0);//INDENTIFICAR O VEICULO NO MAPA
			if (ENTITY::DOES_ENTITY_EXIST(SpawnedVeh))
			{
				ENTITY::SET_ENTITY_HEADING(SpawnedVeh, ENTITY::GET_ENTITY_HEADING(pedHandle));
				PED::SET_PED_INTO_VEHICLE(pedHandle, SpawnedVeh, -1);
				ENTITY::SET_ENTITY_INVINCIBLE(SpawnedVeh, true);
				VEHICLE::SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED(SpawnedVeh, false);
				VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(SpawnedVeh, "WEB HACKER");
				//int Bli = UI::ADD_BLIP_FOR_ENTITY(Vehicle);//INDENTIFICAR O VEICULO NO MAPA
				int Bli1 = UI::ADD_BLIP_FOR_ENTITY(SpawnedVeh);//INDENTIFICAR O VEICULO NO MAPA//ADICIONADO RECENTE
				UI::SET_BLIP_SPRITE(Bli1, 225);//INDENTIFICAR O VEICULO NO MAPA
				if (spawnWithInvincibility)
				{
					ENTITY::SET_ENTITY_PROOFS(SpawnedVeh, true, true, true, true, true, true, true, true);
				}

				if (spawnSupedUp)
				{
					MaxUpgradesMe(SpawnedVeh, true);
				}
				{
					VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(SpawnedVeh, 102, 0, 255);
					VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(SpawnedVeh, 102, 0, 255);
				}
				SpawnVehicle = false;
			}
		}
	}
	if (nightvision)
	{
		GRAPHICS::SET_NIGHTVISION(true);
	}
	else
	{
		GRAPHICS::SET_NIGHTVISION(false);
	}
	if (heatvision)
	{
		GRAPHICS::SET_SEETHROUGH(true);
	}
	else
	{
		GRAPHICS::SET_SEETHROUGH(false);
	}
	if (keyboardActive)
	{
		if (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 1)
		{
			keyboardActive = false;
			switch (keyboardAction)
			{
			case 0: //addIntOption
				*keyboardVar = StoI(GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT());
				break;
			}
		}
		else if (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 2 || GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 3)
		{
			keyboardActive = false;
		}
	}
}

#pragma endregion
int Hook()
{
	monitorButtons();
	otherLoop();
	optionCount = 0;
	switch (submenu)
	{
#pragma region Main Menu
	case Main_Menu:
		subTitle("Version Menu 3.0 - Web Hacker");//
		addSubmenuOption("Network Options", Network_Options);
		addSubmenuOption("Self Options", Self_Options);//added
		addSubmenuOption("Teleport Options", Teleportation1);//added 
		addSubmenuOption("Spawn Vehicle", VehSpawner);//added all
		addSubmenuOption("Vehicle Options", Vehicle_Options);//added
		addSubmenuOption("Weapon Options", Weapon_Options1);//added
		addSubmenuOption("Animations Options", Animations);//added
		addSubmenuOption("Model Changer", Change_Model);//added
		addSubmenuOption("Weather Options", Weather_Options);//added
		addSubmenuOption("Spawn Objects", SpawnObj);//added
		addSubmenuOption("Traffic Options", Traffic_Options);
		addSubmenuOption("Modder Protection", ModdedProtectt);//added
		addSubmenuOption("Miscelaneous", OneClickOptions);// added
		addSubmenuOption("Settings", Settings);//added
		//addSubmenuOption("Debugg Options", DebuggDev);//added
		break;

		int WaterHeight;
#pragma endregion
#pragma region options betas
	case Network_Options:
		subTitle("Networks");
		addOption("Client List");//added
		addOption("All Clients");
		switch (getOption())
		{
		case 1: changeSubmenu(Players_List); break;
		case 2: changeSubmenu(ALL_Players); break;
		} break;


#pragma endregion
#pragma region options betas
	case WeatherOptions:
		subTitle("Changer Weater All");
			addOption("SNOWLIGHT");
			addOption("BLIZZARD");
			addOption("FOGGY");
			addOption("CLOUDY");
			addOption("OVERCAST");
			addOption("THUNDER");
			addOption("SNOW");
			addOption("SUNNY");
			addOption("CLEAR");
			addOption("NEUTRAL");
			addOption("SMOG");
			addOption("RAIN");
			addOption("EXTRASUNNY");
			addOption("CLEARING");
			switch (getOption())
			{
			case 1: setWeather("SNOWLIGHT"); break;
			case 2: setWeather("BLIZZARD"); break;
			case 3: setWeather("FOGGY"); break;
			case 4:	setWeather("CLOUDS"); break;
			case 5: setWeather("OVERCAST"); break;
			case 6: setWeather("THUNDER"); break;
			case 7: setWeather("SNOW"); break;
			case 8: setWeather("SUNNY"); break;
			case 9: setWeather("CLEAR"); break;
			case 10: setWeather("NEUTRAL"); break;
			case 11: setWeather("SMOG"); break;
			case 12: setWeather("RAIN"); break;
			case 13: setWeather("EXTRASUNNY"); break;
			case 14: setWeather("CLEARING"); break;
		} break;
#pragma endregion
#pragma region options betas
	case ALL_Players:
		subTitle("All Players Options");
		addOption("Teleport All clients");
		addBoolOption("Water Loop", WaterLoopAll);
		addBoolOption("Fire Loop", FireLoopAll);
		addBoolOption("Freeze Loop", FreezeAll);
		addBoolOption("ESP All Players", TracerLoop);
		addOption("Teleport All To Mission");
		addOption("Remove All Weapons");
		addOption("Give All Weapons");
		addSubmenuOption("Change Weather All", WeatherOptions);
		switch (getOption())
		{
		case 1: teleportPlayertoMe();
			drawNotification("Teleport all clients to your world coordinates"); break;
		case 2: WaterLoopAll = !WaterLoopAll;
			drawNotification("Spawns water on all clients constantly."); break;
		case 3: FireLoopAll = !FireLoopAll; 
			drawNotification("Spawns fire on all clients constantly."); break;
		case 4: FreezeAll = !FreezeAll; 
			drawNotification("Clears all clients tasks constantly."); break;
		case 5: TracerLoop = !TracerLoop;
			drawNotification("Draw lines to identify clients in current session."); break;
		case 6: teleportPlayertoMission(); break;
			drawNotification("Teleports all clients to a mission."); break;
		case 7: WeaponsRemoveAll(); 
			drawNotification("Removed all clients weapons."); break;
		case 8: WeaponsGiveAll(); 
			drawNotification("Gived all clients weapons."); break;
		} break;

#pragma endregion
#pragma region options betas
	case DebuggDev:
		subTitle("~h~Debugg Options Developer");
		addIntOption("Red Hud", &hudColorR, 0, 255, true);//Hud_Color
		addIntOption("Green Hud", &hudColorG, 0, 255, true);
		addIntOption("Blue Hud", &hudColorB, 0, 255, true);
		switch (getOption())
		{
		} break;
#pragma endregion
#pragma region options betas
	case Betatestrs:
		subTitle("~h~Ghost Ride÷");
		addOption("Transform Ghost Ride");
		addBoolOption("Fire on body parts", Particle_Man_petrol_fire, " ");
		addVehOption1("Ghost Bike", "innovation");
		addBoolOption("Fire on motorcycle tires", GhostRider);
		switch (getOption())
		{
		case 1:
			ResetAppearance();
			changeAppearance("TORSO", 17, 0);
			changeAppearance("MASK", 2, 0);//mascara
			changeAppearance("HATS", 12, 0);//capacete
			changeAppearance("HAIR", 0, 0);
			changeAppearance("GLASSES", 8, 0);//oculos
			changeAppearance("LEGS", 4, 0);//calças
			changeAppearance("SHOES", 28, 1);//sapatos
			changeAppearance("SPECIAL1", 11, 0);//das algemas
			changeAppearance("SPECIAL2", 15, 0);//da policia
			changeAppearance("SPECIAL3", 1, 1);//coletes
			changeAppearance("TEXTURES", 0, 0);
			changeAppearance("TORSO2", 37, 2);//blusas
			changeAppearance("HANDS", 45, 0);//muchila
			DoFX("scr_agencyheist", "scr_fbi_dd_breach_smoke"); //fogo spawn //innovation 
			drawNotification("motorcyclist turned ghost climb \nthe picture and activate \nthe option below");
			break;
		case 2:Particle_Man_petrol_fire = !Particle_Man_petrol_fire; break;
		case 3: break;
		case 4: if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), true)) 
		{ GhostRider = !GhostRider; }
				 else { drawNotification("Must Be In Vehicle To Use This Options"); }break;//
		} break;

#pragma endregion
#pragma region Players List
	case Players_List:
		subTitle("Players List");
		for (int i = 0; i < 18; i++)
		{
			selectedPlayer = -1;
			Linie(selectedPlayer);
			char * Name = PLAYER::GET_PLAYER_NAME(i);
			char NameBuffer[30];
			//if host and Friend
			if (i == NETWORK::NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0) && Is_Player_Friend(i) == true)
			{
				sprintf(NameBuffer, "~b~[H/F] %s", Name);
				Name = NameBuffer;
				addOption(Name);

			}
			//if friend
			else if (Is_Player_Friend(i) == true)
			{
				sprintf(NameBuffer, "~y~[F] %s", Name);
				Name = NameBuffer;
				addOption(Name);
			}
			//if host and you
			else if (i == NETWORK::NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0) && PLAYER::GET_PLAYER_PED(i) == PLAYER::PLAYER_PED_ID())
			{
				sprintf(NameBuffer, "~h~~o~÷[H] %s", Name);
				Name = NameBuffer;
				addOption(Name);
			}
			//if host only
			else if (i == NETWORK::NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0))
			{
				sprintf(NameBuffer, "~g~[H] %s", Name);
				Name = NameBuffer;
				addOption(Name);
			}
			//if you only
			else if (PLAYER::GET_PLAYER_PED(i) == PLAYER::PLAYER_PED_ID())
			{
				sprintf(NameBuffer, "~h~~p~÷ %s", Name);
				Name = NameBuffer;
				addOption(Name);
			}
			// all other xD
			else
			{
				addOption(Name);
			}
		}
		if (optionPress && PLAYER::IS_PLAYER_PLAYING(currentOption - 1))
		{
			selectedPlayer = currentOption - 1;
			changeSubmenu(Player_Options);
			sowmenuID = false;

		}
		break;
#pragma endregion
#pragma region Traffic options 
	case Traffic_Options:
		subTitle("Traffic Options");
		addBoolOption("Force Traffic (Square)", ForceTest);
		addBoolOption("Tuned Traffic", TuneArea2);
		addBoolOption("Boost Traffic (R1)", BoostAreaCar);
		addBoolOption("Lowrider Traffic", Buny);
		addBoolOption("Gravity", Graviiii);
		addBoolOption("Jumping Cars", Bunnycars);
		//addBoolOption("Weird Car", KAAAA);
		switch (getOption())
		{
		case 1: ForceTest = !ForceTest; 
			drawNotification("~h~Use Square To force !"); break;
		case 2: TuneArea2 = !TuneArea2;  break;
		case 3: BoostAreaCar = !BoostAreaCar;  break;
		case 4: Buny = !Buny; break;
		case 5: Graviiii = !Graviiii; break;
		case 6:	Bunnycars = !Bunnycars; break;
			//case 7: CarForceMod(); break;		
		}
		break;
		int PlayerAlpha;
#pragma endregion
#pragma region Self Options
	case Self_Options:
		subTitle("~h~Self Options");
		addBoolOption("God Mode", gmode);
		addBoolOption("No Police", NoCops);
		addBoolOption("Invisibility", !ENTITY::IS_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID()));
		addOption("Clone Player");
		addBoolOption("Heat Vision", heatvision);
		addBoolOption("Night Vision", nightvision);
		addBoolOption("Super Jump", SuperJump);
		addBoolOption("Super Punch", SuperPunch);
		addBoolOption("Fast Run", RunSpeed);
		addBoolOption("Force Field", doForceField_);
		spritemenu("Change Name", " ");
		addBoolOption("Mobile Radio", mobileRadio);
		addBoolOption("Not Targeted", NoTarget);
		addBoolOption("Boss Mode", hasBossMode);
		addBoolOption("Slow Motion", slowmotion);
		addOption("Disable Idle Kick");
		addBoolOption("Infinite Ammo", Ammo_);
		addOption("Clean Player");
		addOption("All Weapons");
		addBoolOption("Anti-RagDoll", RagDoll);
		addBoolOption("Super Run [X]", superun);
		addBoolOption("No Clip Mode", Noclip);
		addBoolOption("Superman", Superman);
		addOption("Flash Minimap");
		addBoolOption("Moises Mode", Modify_Water);//
		spritemenu("Particle Man FX", " ");
		spritemenu("Smoke Color Editor", " ");
		spritemenu("Player Opacity Level", " ");
		addBoolOption("Magic Carpet Mode", Noclip2);
		addBoolOption("Aimbot To Players", aimbot);
		addBoolOption("Shrink Player", Shrink);
		addBoolOption("Funny Screen Player", funnyScreenEnabled);
		addBoolOption("Health Regenerate", HealthRegener);
		addBoolOption("Armour Regenerate", ArmorRegener);
		addBoolOption("Fire Feet", Firefeet);
		switch (getOption())
		{
		case 1: gmode = !gmode; break;
		case 2: NoCops = !NoCops; break;
		case 3: ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), !ENTITY::IS_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID())); break;
		case 4: ClonePed(PLAYER::PLAYER_PED_ID()); break;
		case 5: heatvision = !heatvision; break;
		case 6: nightvision = !nightvision; break;
		case 7: SuperJump = !SuperJump; break;
		case 8: SuperPunch = !SuperPunch; break;
		case 9: playerMovementSpeed(); break;
		case 10: Dofroce(); break;
		case 11: changeSubmenu(Namechanger);  break;
		case 12: toggleMobileRadio(); break;
		case 13: NoTarget = !NoTarget; break;
		case 14: hasBossMode = !hasBossMode; break;
		case 15: slowmotion = !slowmotion; break;
		case 16: SetTunable(73, 1); SetTunable(74, 1); SetTunable(75, 1); SetTunable(76, 0x3B9AC9FF); break;
		case 17: Ammo(); break;
		case 18: CleanPed(PLAYER::PLAYER_PED_ID()); break;
		case 19: for (int i = 0; i < 59; i++)
		{
			int Ammo = -1;
			WEAPON::GET_MAX_AMMO(PLAYER::PLAYER_PED_ID(), WepArray[i], &Ammo);
			WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), WepArray[i], Ammo, false, true);
		}
				 break;
		case 20: RagDollOn(); break;
		case 21: superun = !superun; break;
			drawNotification("~h~Use [X]"); break;
		case 22: Noclip = !Noclip;
			drawNotification("~h~Use R1 To Move No Clip\n Dpad Down And Dpad UP"); break;
		case 23: dropPickup(ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1), "prop_parachute", "PICKUP_PARACHUTE", 2);
			Superman = !Superman; 
			drawNotification("Start the fly with ~b~L3 ~w~and ~b~R1\nControl with ~b~right stick\nR2 Up"); break;
		case 24: FlashMinimap(); break;
		case 25: Modify_Water = !Modify_Water;
			drawNotification("~h~Teleport to Beach And Use moises mode"); break;
		case 26: changeSubmenu(Particlesman);  break; 
		case 27: changeSubmenu(SmorkColor);  break;
		case 28: changeSubmenu(PlayerOcpacit); break;
		case 29: Noclip2 = !Noclip2; 
			drawNotification("~h~Square = ~r~Front \n~h~~w~Button R3 = ~r~UP \n~h~~w~Button L3 = ~r~Down"); break;
		case 30: aimbot = !aimbot;
			drawNotification("Aim gun and it will ~b~auto fire ~w~at nearby players head"); break;
		case 31: Shrink = !Shrink; break;
		case 32: funnyScreenEnabled = !funnyScreenEnabled; 
			drawNotification("~h~Switch Weapon \n ~h~and Disable the option \n ~h~to stay with Big Weapons"); break;
		case 33: HealthRegener = !HealthRegener; break; 
		case 34: ArmorRegener = !ArmorRegener; break;
		case 35: Firefeet = !Firefeet; break;
		}
		break;
#pragma endregion
#pragma region Smoke_option
	case PlayerOcpacit:
		subTitle("Player Ocupacity");
		addOption("Alpha Level 0%");
		addOption("Alpha Level 20%");
		addOption("Alpha Level 40%");
		addOption("Alpha Level 60%");
		addOption("Alpha Level 80%");
		addOption("Alpha Level 100%");
		switch (getOption())
		{
		case 1: ENTITY::SET_ENTITY_ALPHA(PLAYER::PLAYER_PED_ID(), 0, false);
			break;
		case 2: ENTITY::SET_ENTITY_ALPHA(PLAYER::PLAYER_PED_ID(), 50, false);
			break;
		case 3: ENTITY::SET_ENTITY_ALPHA(PLAYER::PLAYER_PED_ID(), 100, false);
			break;
		case 4: ENTITY::SET_ENTITY_ALPHA(PLAYER::PLAYER_PED_ID(), 150, false);
			break;
		case 5: ENTITY::SET_ENTITY_ALPHA(PLAYER::PLAYER_PED_ID(), 200, false);
			break;
		case 6: ENTITY::SET_ENTITY_ALPHA(PLAYER::PLAYER_PED_ID(), 255, false);
			break;
		}
		break;
#pragma endregion
#pragma region Smoke_option
	case SmorkColor:
		subTitle("Smoke Colors");
		addOption("Purple", " ");
		addOption("light blue", " ");
		addOption("White Full", " ");
		addOption("Green", " ");
		addOption("Blue", " ");
		addOption("yellow", " ");
		addOption("Red", " ");
		addOption("pink", " ");
		addOption("black", " ");
		switch (getOption())
		{//
		case 1:
			char bytes[] = { 0x3F, 0x80, 0x00, 0x00, 0x02, 0x80, 0x00, 0x00, 0x3F };
			write_process(0x1E60FF0, &bytes, sizeof(bytes));
			drawNotification("Use Particle Man \nAnd Explosion Smokes");
			break;
		case 2:
			char bytes2[] = { 0x01, 0x80, 0x00, 0x00, 0x3F, 0x80, 0x00, 0x00, 0x3F };
			write_process(0x1E60FF0, &bytes2, sizeof(bytes2));
			drawNotification("Use Particle Man \nAnd Explosion Smokes");
			break;
		case 3:
			char bytes3[] = { 0x3F, 0x80, 0x00, 0x00, 0x3F, 0x80, 0x00, 0x00, 0x3F };
			write_process(0x1E60FF0, &bytes3, sizeof(bytes3));
			drawNotification("Use Particle Man \nAnd Explosion Smokes");
			break;
		case 4:
			char bytes4[] = { 0x3D, 0x80, 0x00, 0x00, 0x3F, 0x80, 0x00, 0x00, 0xFF };
			write_process(0x1E60FF0, &bytes4, sizeof(bytes4));
			drawNotification("Use Particle Man \nAnd Explosion Smokes");
			break;
		case 5:
			char bytes5[] = { 0x2F, 0x00, 0x00, 0x00, 0x2F, 0x80, 0x00, 0x00, 0x3F };
			write_process(0x1E60FF0, &bytes5, sizeof(bytes5));
			drawNotification("Use Particle Man \nAnd Explosion Smokes");
			break;
		case 6:
			char bytes6[] = { 0x5F, 0x00, 0x00, 0x00, 0x4F, 0x80, 0x00, 0x00, 0x8F };
			write_process(0x1E60FF0, &bytes6, sizeof(bytes6));
			drawNotification("Use Particle Man \nAnd Explosion Smokes");
			break;
		case 7:
			char bytes7[] = { 0x6F, 0x00, 0x00, 0x00, 0xFF, 0x80, 0x00, 0x00, 0xFF };
			write_process(0x1E60FF0, &bytes7, sizeof(bytes7));
			drawNotification("Use Particle Man \nAnd Explosion Smokes");
			break;
		case 8:
			char bytes8[] = { 0x7F, 0x00, 0x00, 0x00, 0x3F, 0x80, 0x00, 0x00, 0x7F };
			write_process(0x1E60FF0, &bytes8, sizeof(bytes8));
			drawNotification("Use Particle Man \nAnd Explosion Smokes");
			break;
		case 9:
			char bytes9[] = { 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x80, 0x00, 0x00, 0xFF };
			write_process(0x1E60FF0, &bytes9, sizeof(bytes9));
			drawNotification("Use Particle Man \nAnd Explosion Smokes");
			break;
		}
		break;

#pragma endregion
#pragma region Particle Man
	case Particlesman:
		subTitle("~h~Particle Man");//
		addBoolOption(" Clown Appers", Particle_Man_Appers, " ");
		addBoolOption(" Clown Death", Particle_Man_clown, " ");
		addBoolOption(" breach smoke", Particle_Man_breach_smoke, " ");
		addBoolOption("Petrol Fire", Particle_Man_petrol_fire, " ");
		addBoolOption("Imfamous FX ", IMFAMOUSFX, " ");
		addBoolOption("Explosion Clown", expclown, " ");
		switch (getOption())
		{
		case 1:Particle_Man_Appers = !Particle_Man_Appers; break;
		case 2:Particle_Man_clown = !Particle_Man_clown; break;
		case 3: Particle_Man_breach_smoke = !Particle_Man_breach_smoke; break;
		case 4:Particle_Man_petrol_fire = !Particle_Man_petrol_fire; break;
		case 5:IMFAMOUSFX = !IMFAMOUSFX; break;
		case 6:expclown = !expclown; break;
		}
		break;
#pragma endregion
#pragma region Settings
	case Namechanger:
		subTitle("~h~Name Changer");
		addOption("The Umbrella ~y~Support!");
		addOption("The Umbrella ~r~Dev!");
		addOption("**Invalid**");
		addOption("÷ Rockstar Developer ÷");
		addOption("I Love Modding");
		addOption("~c~Pogo ~c~Modding");
		addOption("WEB HACKER");
		addOption("Rockstar");
		switch (getOption())
		{
		case 1: changenae("The Umbrella ~y~Support!");
			PRINT("~b~Name changed~w~, Change the lobby!", 2500); break;
		case 2: changenae("The Umbrella ~r~Dev!");
			PRINT("~b~Name changed~w~, Change the lobby!", 2500); break;
		case 3: changenae("**Invalid**");
			PRINT("~b~Name changed~w~, Change the lobby!", 2500); break;
		case 4: changenae("÷ Rockstar Developer ÷");
			PRINT("~b~Name changed~w~, Change the lobby!", 2500); break;
		case 5: changenae("I Love Modding");
			PRINT("~b~Name changed~w~, Change the lobby!", 2500); break;
		case 6: changenae("~c~Pogo ~c~Modding");
			PRINT("~b~Name changed~w~, Change the lobby!", 2500); break;
		case 7: changenae("Web Hacker Dev");
			PRINT("~b~Name changed~w~, Change the lobby!", 2500); break;
		case 8: changenae("Rockstar");
			PRINT("~b~Name changed~w~, Change the lobby!", 2500); break;
		}break;
#pragma endregion
#pragma region Player Options
	case Player_Options:
		//sowmenuID = true;
		ViewInfo(true);
		drawESP(selectedPlayer);
		subTitle(PLAYER::GET_PLAYER_NAME(selectedPlayer));
		spritemenu("Player Options", " ");
		spritemenu("Teleport Options", " ");
		spritemenu("Weapon Options", " ");
		spritemenu("Drops Options", " ");
		spritemenu("Force Player Options ~c~(Food)", " ");
		spritemenu("Spawn Vehicle Player", " ");
		spritemenu("Vehicle Options", " ");
		spritemenu("Attach Vehicle Freeze Console", " ");
		addOption("Kick From Session                                      ~c~(Host)", " ");
		addOption("No host Kick");
		addOption("Give RP 8000"); 
		addOption("Derrank Player");
		spritemenu("~h~~y~Remote Recovery Player", " ");
		switch (getOption())
		{
		case 1:  changeSubmenu(OnlinePlayerOption); break;
		case 2:  changeSubmenu(Player_TP_Options); break;
		case 3:  changeSubmenu(Player_Weapon_Options); break;
		case 4:  changeSubmenu(Player_GoodStuff); break;
		case 5:  changeSubmenu(Forceplayer); break;
		case 6:  changeSubmenu(Spawn_pLAVeh); break;
		case 7: changeSubmenu(Player_BadStuff); break;
		case 8: changeSubmenu(Frezeatg); break;
		case 9: if (NETWORK::NETWORK_IS_HOST())
		{
			if (selectedPlayer)
			{
				for (int i = 0; i < 16; i++)
				{
					if (i != PLAYER::PLAYER_ID())
						NETWORK::NETWORK_SESSION_KICK_PLAYER(i);
				}
			}
			else
				NETWORK::NETWORK_SESSION_KICK_PLAYER(selectedPlayer);
		}
				 else
					 drawNotification("~c~You are not the session host."); break;
		case 10: Kick(selectedPlayer); break;
		case 11: GiveRP(selectedPlayer, -1787576850);  break;
		case 12: DerrankPlayer(selectedPlayer, 1787576850);  break;
		case 13:  changeSubmenu(RemoteRecoveryPlayer); break;
		}
		break;
#pragma endregion
#pragma region 
	case RemoteRecoveryPlayer:
		ViewInfo(true);
		drawESP(selectedPlayer); 
		subTitle("~y~Remote Recovery Player");
		addOption("Unlock All Complete");
		addOption("Player Unlock Heist Vehicles");
		addOption("Player Redesign Character");
		addOption("Player Unlock All Hair Cuts");
		addOption("Player Unlock All Tattoos");
		addOption("Player Remove Badsport");
		addOption("Player Give Badsport");
		addOption("Player Enable Roosevelt");
		addOption("Player Bypass Vehicle Sell Time");
		addOption("Unlock Parachutes");
		switch (getOption())
		{
		case 1:
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_1_FM_UNLCK"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_2_FM_UNLCK"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_3_FM_UNLCK"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_4_FM_UNLCK"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_5_FM_UNLCK"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_6_FM_UNLCK"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_7_FM_UNLCK"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_8_FM_UNLCK"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_9_FM_UNLCK"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_10_FM_UNLCK"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_11_FM_UNLCK"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_12_FM_UNLCK"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE2"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE3"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE4"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE5"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE6"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE7"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE8"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE9"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE10"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE11"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE12"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_RACES_WON"), 50, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_CARMOD_1_UNLCK"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_CARMOD_2_UNLCK"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_CARMOD_3_UNLCK"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_CARMOD_4_UNLCK"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_CARMOD_5_UNLCK"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_CARMOD_6_UNLCK"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_CARMOD_7_UNLCK"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMRALLYWONDRIVE"), 1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMRALLYWONNAV"), 1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMWINSEARACE"), 1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMWINAIRRACE"), 1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_NUMBER_TURBO_STARTS_IN_RACE"), 50, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_USJS_COMPLETED"), 50, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_RACES_FASTEST_LAP"), 50, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_NUMBER_SLIPSTREAMS_IN_RACE"), 100, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_WIN_CAPTURES"), 25, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_DROPOFF_CAP_PACKAGES"), 100, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_KILL_CARRIER_CAPTURE"), 100, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FINISH_HEISTS"), 50, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FINISH_HEIST_SETUP_JOB"), 50, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_NIGHTVISION_KILLS"), 100, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_WIN_LAST_TEAM_STANDINGS"), 50, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_ONLY_PLAYER_ALIVE_LTS"), 50, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_DM_WINS"), 50, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_TDM_MVP"), 50, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_DM_TOTALKILLS"), 500, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMATTGANGHQ"), 1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMBBETWIN"), 50000, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMWINEVERYGAMEMODE"), 1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMRACEWORLDRECHOLDER"), 1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMFULLYMODDEDCAR"), 1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMMOSTKILLSSURVIVE"), 1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMKILL3ANDWINGTARACE"), 1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMKILLBOUNTY"), 25, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMREVENGEKILLSDM"), 50, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMKILLSTREAKSDM"), 1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_HOLD_UP_SHOPS"), 20, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_LAPDANCES"), 25, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_SECURITY_CARS_ROBBED"), 25, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_RACES_WON"), 50, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_CAR_BOMBS_ENEMY_KILLS"), 25, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_PLAYER_HEADSHOTS"), 500, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DB_PLAYER_KILLS"), 1000, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_HAIR"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_HAIR_1"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_HAIR_2"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_HAIR_3"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_HAIR_4"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_HAIR_5"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_HAIR_6"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_HAIR_7"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_JBIB"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_JBIB_1"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_JBIB_2"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_JBIB_3"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_JBIB_4"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_JBIB_5"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_JBIB_6"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_JBIB_7"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_LEGS"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_LEGS_1"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_LEGS_2"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_LEGS_3"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_LEGS_4"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_LEGS_5"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_LEGS_6"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_LEGS_7"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_FEET"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_FEET_1"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_FEET_2"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_FEET_3"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_FEET_4"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_FEET_5"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_FEET_6"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_FEET_7"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_BERD"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_BERD_1"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_BERD_2"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_BERD_3"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_BERD_4"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_BERD_5"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_BERD_6"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_BERD_7"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_PROPS"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_PROPS_1"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_PROPS_2"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_PROPS_3"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_PROPS_4"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_PROPS_5"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_PROPS_6"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_PROPS_7"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_PROPS_8"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_PROPS_9"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_PROPS_10"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_OUTFIT"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_HAIR"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_HAIR_1"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_HAIR_2"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_HAIR_3"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_HAIR_4"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_HAIR_5"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_HAIR_6"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_HAIR_7"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_JBIB"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_JBIB_1"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_JBIB_2"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_JBIB_3"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_JBIB_4"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_JBIB_5"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_JBIB_6"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_JBIB_7"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_LEGS"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_LEGS_1"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_LEGS_2"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_LEGS_3"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_LEGS_4"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_LEGS_5"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_LEGS_6"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_LEGS_7"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_FEET"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_FEET_1"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_FEET_2"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_FEET_3"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_FEET_4"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_FEET_5"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_FEET_6"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_FEET_7"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_BERD"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_BERD_1"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_BERD_2"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_BERD_3"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_BERD_4"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_BERD_5"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_BERD_6"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_BERD_7"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_PROPS"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_PROPS_1"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_PROPS_2"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_PROPS_3"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_PROPS_4"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_PROPS_5"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_PROPS_6"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_PROPS_7"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_PROPS_8"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_PROPS_9"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_PROPS_10"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_OUTFIT"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_TORSO"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_SPECIAL"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_SPECIAL_1"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_SPECIAL_2"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_SPECIAL_3"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_SPECIAL_4"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_SPECIAL_5"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_SPECIAL_6"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_SPECIAL_7"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_SPECIAL2"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_SPECIAL2_1"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_DECL"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_TEETH"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_TEETH_1"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_AVAILABLE_TEETH_2"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_TORSO"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_SPECIAL"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_SPECIAL_1"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_SPECIAL_2"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_SPECIAL_3"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_SPECIAL_4"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_SPECIAL_5"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_SPECIAL_6"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_SPECIAL_7"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_SPECIAL2"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_SPECIAL2_1"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_DECL"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_TEETH"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_TEETH_1"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("CLTHS_ACQUIRED_TEETH_2"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("DLC_APPAREL_ACQUIRED_0"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("DLC_APPAREL_ACQUIRED_1"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("DLC_APPAREL_ACQUIRED_2"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("DLC_APPAREL_ACQUIRED_3"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("DLC_APPAREL_ACQUIRED_4"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("DLC_APPAREL_ACQUIRED_5"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("DLC_APPAREL_ACQUIRED_6"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("DLC_APPAREL_ACQUIRED_7"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("DLC_APPAREL_ACQUIRED_8"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("DLC_APPAREL_ACQUIRED_9"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("DLC_APPAREL_ACQUIRED_10"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("DLC_APPAREL_ACQUIRED_11"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("DLC_APPAREL_ACQUIRED_12"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("DLC_APPAREL_ACQUIRED_13"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("DLC_APPAREL_ACQUIRED_14"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("DLC_APPAREL_ACQUIRED_15"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("DLC_APPAREL_ACQUIRED_16"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("DLC_APPAREL_ACQUIRED_17"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("DLC_APPAREL_ACQUIRED_18"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("DLC_APPAREL_ACQUIRED_19"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("DLC_APPAREL_ACQUIRED_20"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("DLC_APPAREL_ACQUIRED_21"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("DLC_APPAREL_ACQUIRED_22"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("DLC_APPAREL_ACQUIRED_23"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("DLC_APPAREL_ACQUIRED_24"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("DLC_APPAREL_ACQUIRED_25"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("DLC_APPAREL_ACQUIRED_26"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("DLC_APPAREL_ACQUIRED_27"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("DLC_APPAREL_ACQUIRED_28"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("DLC_APPAREL_ACQUIRED_29"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("DLC_APPAREL_ACQUIRED_30"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("DLC_APPAREL_ACQUIRED_31"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("DLC_APPAREL_ACQUIRED_32"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("DLC_APPAREL_ACQUIRED_33"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("DLC_APPAREL_ACQUIRED_34"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("DLC_APPAREL_ACQUIRED_35"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("DLC_APPAREL_ACQUIRED_36"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("ADMIN_CLOTHES_GV_BS_1"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("ADMIN_CLOTHES_GV_BS_2"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("ADMIN_CLOTHES_GV_BS_3"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("ADMIN_CLOTHES_GV_BS_4"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("ADMIN_CLOTHES_GV_BS_5"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("ADMIN_CLOTHES_GV_BS_6"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("ADMIN_CLOTHES_GV_BS_7"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("ADMIN_CLOTHES_GV_BS_8"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("ADMIN_CLOTHES_GV_BS_9"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("ADMIN_CLOTHES_GV_BS_10"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("ADMIN_CLOTHES_GV_BS_11"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMHORDWAVESSURVIVE"), 10, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMPICKUPDLCCRATE1ST"), 1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_WIN_CAPTURE_DONT_DYING"), 25, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_DO_HEIST_AS_MEMBER"), 25, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_PICKUP_CAP_PACKAGES"), 100, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FINISH_HEIST_NO_DAMAGE"), 1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_WIN_GOLD_MEDAL_HEISTS"), 25, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_KILL_TEAM_YOURSELF_LTS"), 25, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_KILL_PSYCHOPATHS"), 100, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_DO_HEIST_AS_THE_LEADER"), 25, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_STORE_20_CAR_IN_GARAGES"), 1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_1"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_2"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_3"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_4"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_5"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_6"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_7"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_VEHICLE_1_UNLCK"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_VEHICLE_2_UNLCK"), -1, 1), 1); break;
		case 2:
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_VEHICLE_1_UNLCK"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_VEHICLE_2_UNLCK"), -1, 1), 1); break;
			
		case 3: setPlayerStatBool(selectedPlayer, STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_FM_CHANGECHAR_ASKED"), 0, 1), 1);  break;
		case 4:
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_1"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_2"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_3"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_4"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_5"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_6"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_7"), -1, 1), 1); break;
		case 5:
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_DM_WINS"), 50, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_TDM_MVP"), 50, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_DM_TOTALKILLS"), 500, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMATTGANGHQ"), 1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMBBETWIN"), 50000, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMWINEVERYGAMEMODE"), 1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMRACEWORLDRECHOLDER"), 1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMFULLYMODDEDCAR"), 1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMMOSTKILLSSURVIVE"), 1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMKILL3ANDWINGTARACE"), 1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMKILLSTREAKSDM"), 1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMKILLBOUNTY"), 25, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_LAPDANCES"), 25, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_CAR_BOMBS_ENEMY_KILLS"), 25, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_SECURITY_CARS_ROBBED"), 25, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_HOLD_UP_SHOPS"), 20, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMREVENGEKILLSDM"), 50, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_RACES_WON"), 50, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_PLAYER_HEADSHOTS"), 500, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DB_PLAYER_KILLS"), 1000, 1), 1); break;
		case 6:
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_BAD_SPORT_BITSET"), 0, 0), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_WAS_I_BAD_SPORT"), 0, 0), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_OVERALL_BADSPORT"), 0, 0), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_CHAR_IS_BADSPORT"), 0, 0), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_BECAME_BADSPORT_NUM"), 0, 0), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_DESTROYED_PVEHICLES"), 0, 0), 1); break;
		case 7:
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_BAD_SPORT_BITSET"), 1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_WAS_I_BAD_SPORT"), 1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_OVERALL_BADSPORT"), 1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_CHAR_IS_BADSPORT"), 1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_BECAME_BADSPORT_NUM"), 1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_DESTROYED_PVEHICLES"), 1, 1), 1); break;
		case 8: setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_VEHICLE_ID_ADMIN_WEB"), 117401876, 1), 1); break;

		case 9: setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_VEHICLE_SELL_TIME"), 0, 1), 1); break;

		case 10: setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_1_FM_UNLCK"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_2_FM_UNLCK"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_3_FM_UNLCK"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_4_FM_UNLCK"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_5_FM_UNLCK"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_6_FM_UNLCK"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_7_FM_UNLCK"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_8_FM_UNLCK"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_9_FM_UNLCK"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_10_FM_UNLCK"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_11_FM_UNLCK"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_12_FM_UNLCK"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE2"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE3"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE4"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE5"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE6"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE7"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE8"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE9"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE10"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE11"), -1, 1), 1);
			setPlayerStatInt(selectedPlayer, STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE12"), -1, 1), 1); break;
		}
		break;
#pragma endregion
#pragma region Freeze Vehicle Atach
	case Frezeatg:
		ViewInfo(true);
		drawESP(selectedPlayer);
		subTitle("Freeze Vehicle Atach");
		addOption("Adder");
		addOption("Taxi");
		addOption("Space Docker");
		addOption("caddy 2");
		addOption("Tank Rhino");
		addOption("Bmx Biker");
		addOption("Hotknife");
		addOption("Tornado2");
		addOption("Ztype");
		addOption("Faggio2");
		addOption("Cruiser police");
		switch (getOption())
		{
		case 1: 
			Vehicle_Hash = GAMEPLAY::GET_HASH_KEY("Adder");
			Vehicle_Atach = true;
			break;
		case 2:
			Vehicle_Hash = GAMEPLAY::GET_HASH_KEY("Taxi");
			Vehicle_Atach = true;
			break;
		case 3:
			Vehicle_Hash = GAMEPLAY::GET_HASH_KEY("Dune2");
			Vehicle_Atach = true;
			break;
		case 4:
			Vehicle_Hash = GAMEPLAY::GET_HASH_KEY("Caddy2");
			Vehicle_Atach = true;
			break;
		case 5:
			Vehicle_Hash = GAMEPLAY::GET_HASH_KEY("rhino");
			Vehicle_Atach = true;
			break;
		case 6:
			Vehicle_Hash = GAMEPLAY::GET_HASH_KEY("bmx");
			Vehicle_Atach = true;
			break;
		case 7:
			Vehicle_Hash = GAMEPLAY::GET_HASH_KEY("Hotknife");
			Vehicle_Atach = true;
			break;
		case 8:
			Vehicle_Hash = GAMEPLAY::GET_HASH_KEY("Tornado2");
			Vehicle_Atach = true;
			break;
		case 9:
			Vehicle_Hash = GAMEPLAY::GET_HASH_KEY("Ztype");
			Vehicle_Atach = true;
			break;
		case 10:
			Vehicle_Hash = GAMEPLAY::GET_HASH_KEY("Faggio2");
			Vehicle_Atach = true;
			break;
		case 11:
			Vehicle_Hash = GAMEPLAY::GET_HASH_KEY("police");
			Vehicle_Atach = true;
			break;
		} break;
#pragma endregion
#pragma region PlayerVehicleOptions
	case Player_BadStuff:
		ViewInfo(true);
		drawESP(selectedPlayer);
		Vehicle VehicleHandle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED(selectedPlayer), true);
		subTitle(PLAYER::GET_PLAYER_NAME(selectedPlayer));
		addOption("Delete Vehicle", " ");
		addOption("Kick From Vehicle", " ");
		addBoolOption("Lock Doors", doUndriveableCar2, " ");
		addBoolOption("Delete Car Loop", deletecarloopz, " ");
		addOption("Hijack Vehicle", " ");
		addOption("Burst Tyres", " "); 
		addOption("Trigger Alarm", " ");
		addOption("Godmode Vehicle", " ");
		addOption("Boost Car", " ");
		addOption("Smash Out Windows", " ");
		switch (getOption())
		{
		case 1: if (ENTITY::DOES_ENTITY_EXIST(VehicleHandle))
		{
			ENTITY::SET_ENTITY_AS_MISSION_ENTITY(VehicleHandle, 1, 1);
			VEHICLE::DELETE_VEHICLE(&VehicleHandle);
		} break;
		case 2: KickFromCar(selectedPlayer); break;
		case 3: undriveablePlayersCar2(selectedPlayer); break;
		case 4: deletecarloopz = !deletecarloopz; break;
		case 5: HijackVehicle(selectedPlayer); break;
		case 6: BurstSelectedPlayerTires2(selectedPlayer); break;
		case 7: TripAlarm2(selectedPlayer); break;
		case 8: godcar_ = true; break;
		case 9: NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(VehicleHandle);
			if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(VehicleHandle))
			{
				VEHICLE::SET_VEHICLE_FORWARD_SPEED(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED(selectedPlayer), true), 100);
			} break;
		case 10: ToggleVehicleWindowsBroken(selectedPlayer); break;
		}
		break;
#pragma region spawn veh
	case Spawn_pLAVeh:
		ViewInfo(true);
		drawESP(selectedPlayer);
		subTitle("Spawn Vehicle Player");
		spritemenu("~h~Super Cars", " ");//1
		spritemenu("Sports Cars", " ");//2
		spritemenu("Classics Cars", " ");//3
		spritemenu("Muscle Cars", " ");//4
		spritemenu("Sedans", " ");//5
		spritemenu("Coupes", " ");//6
		spritemenu("Compact Wagen", " ");//7
		spritemenu("SUV and Pickups", " ");//8
		spritemenu("Trucks", " ");//9
		spritemenu("Vans", " ");//10
		spritemenu("Off-Road", " ");//11
		spritemenu("~h~Cargos And Helicopters", " ");//12
		spritemenu("~h~Police Vehicles", " ");//13
		spritemenu("Service Vehicles", " ");//14
		spritemenu("Military Vehicles", " ");//15
		spritemenu("Motorcycles", " ");//16
		spritemenu("Bicycles", " ");//17
		spritemenu("Commercial Vehicles", " ");//18
		spritemenu("Boats", " ");//19
		spritemenu("Trailers", " ");//20
		spritemenu("Heist", " ");//21
		spritemenu("Vehicles Especial", " ");//22
		switch (getOption())
		{
		case 1: changeSubmenu(spawnplayer1);  break;
		case 2: changeSubmenu(spawnplayer2);  break;
		case 3: changeSubmenu(spawnplayer3);  break;
		case 4: changeSubmenu(spawnplayer4);  break;
		case 5: changeSubmenu(spawnplayer5);  break;
		case 6: changeSubmenu(spawnplayer6);  break;
		case 7: changeSubmenu(spawnplayer7);  break;
		case 8: changeSubmenu(spawnplayer8);  break;
		case 9: changeSubmenu(spawnplayer9);  break;
		case 10: changeSubmenu(spawnplayer10);  break;
		case 11: changeSubmenu(spawnplayer11);  break;
		case 12: changeSubmenu(spawnplayer12);  break;
		case 13: changeSubmenu(spawnplayer13);  break;
		case 14: changeSubmenu(spawnplayer14);  break;
		case 15: changeSubmenu(spawnplayer15);  break;
		case 16: changeSubmenu(spawnplayer16);  break;
		case 17: changeSubmenu(spawnplayer17);  break;
		case 18: changeSubmenu(spawnplayer18);  break;
		case 19: changeSubmenu(spawnplayer19);  break;
		case 20: changeSubmenu(spawnplayer20);  break;
		case 21: changeSubmenu(spawnplayer21);  break;
		case 22: changeSubmenu(spawnplayer22);  break;
		}
		break;
			//CREATE_VEHONPLAYER("adder");
#pragma endregion
#pragma region Super
	case spawnplayer22:
		subTitle("~h~Vehicles Especial");
		addOption("Space Docker");
		addOption("Bmx Biker");
		addOption("Dock Handler");
		addOption("Dozer bulldozer");
		addOption("Hotknife");
		addOption("Blazer");
		addOption("Tourbus");
		addOption("Limo");
		addOption("Bus");
		addOption("Clown Van");
		addOption("Airtug");
		addOption("Caddy");
		addOption("Docktug");
		addOption("Tractor");
		addOption("Forklift");
		addOption("Lawn Mower");
		addOption("Tow Truck");
		addOption("HVY Cutter");
		switch (getOption())
		{
		case 1:  CREATE_VEHONPLAYER("dune2"); break;
		case 2:  CREATE_VEHONPLAYER("bmx"); break;
		case 3:  CREATE_VEHONPLAYER("handler"); break;
		case 4:  CREATE_VEHONPLAYER("bulldozer"); break;
		case 5:  CREATE_VEHONPLAYER("hotknife"); break;
		case 6:  CREATE_VEHONPLAYER("blazer3"); break;
		case 7:  CREATE_VEHONPLAYER("tourbus"); break;
		case 8:  CREATE_VEHONPLAYER("stretch"); break;
		case 9:  CREATE_VEHONPLAYER("bus"); break;
		case 10:  CREATE_VEHONPLAYER("speedo2"); break;
		case 11:  CREATE_VEHONPLAYER("airtug"); break;
		case 12:  CREATE_VEHONPLAYER("caddy2"); break;
		case 13:  CREATE_VEHONPLAYER("docktug"); break;
		case 14:  CREATE_VEHONPLAYER("tractor"); break;
		case 15:  CREATE_VEHONPLAYER("forklift"); break;
		case 16:  CREATE_VEHONPLAYER("mower"); break;
		case 17:  CREATE_VEHONPLAYER("towtruck"); break;
		case 18:  CREATE_VEHONPLAYER("cutter"); break;
		}
		break;
#pragma endregion
#pragma region Super
	case spawnplayer1:
		subTitle("~h~SUPER");
		addOption("Adder");
		addOption("Bullet");
		addOption("Cheetah");
		addOption("Entity XF");
		addOption("Infernus");
		addOption("Turismo");
		addOption("Vacca");
		addOption("Voltic");
		addOption("Osiris");
		addOption("Zentorno");
		addOption("Progen T20");
		switch (getOption())
		{
		case 1:  CREATE_VEHONPLAYER("adder"); break;
		case 2:  CREATE_VEHONPLAYER("bullet"); break;
		case 3:  CREATE_VEHONPLAYER("cheetah"); break;
		case 4:  CREATE_VEHONPLAYER("ENTITYXF"); break;
		case 5:  CREATE_VEHONPLAYER("infernus"); break;
		case 6:  CREATE_VEHONPLAYER("turismor"); break;
		case 7:  CREATE_VEHONPLAYER("vacca"); break;
		case 8:  CREATE_VEHONPLAYER("voltic"); break;
		case 9:  CREATE_VEHONPLAYER("osiris"); break;
		case 10:  CREATE_VEHONPLAYER("zentorno"); break;
		case 11:  CREATE_VEHONPLAYER("t20"); break;
		}
		break;
#pragma endregion
#pragma region Sports
	case spawnplayer2:
		subTitle("~h~SPORTS");
		addOption("Annis Elegy RH8");
		addOption("Hijak Khamelion");
		addOption("Grotti Carbonizzare");
		addOption("Benefactor Feltzer 1");
		addOption("Benefactor Feltzer 2 ");
		addOption("Dewbauchee Rapid GT 1 ");
		addOption("Dewbauchee Rapid GT 2");
		addOption("Inverto Coquette 1");
		addOption("Obey 9F Cabrio ");
		addOption("Obey 9F");
		addOption("Benefactor Surano");
		addOption("Bravado Banshee");
		addOption("Pfister Comet");
		addOption("Benefactor Schwartzer");
		addOption("Schyster Fusilade");
		addOption("Bravado Buffalo");
		addOption("Bravado Buffalo 2");
		addOption("Maibatsu Penumbra");
		addOption("Karin Sultan");
		addOption("Karin Futo");
		addOption("Lampadati Furore GT");
		addOption("Dewbauchee Massacro 1");
		addOption("Dewbauchee Massacro 2");
		addOption("Dinka Jester 1");
		addOption("Dinka Jester 2");
		addOption("Enus Windsor");
		addOption("Albany Alpha");
		addOption("Karin Kuruma 1");
		addOption("Karin Kuruma 2");
		switch (getOption())
		{
		case 1:  CREATE_VEHONPLAYER("elegy2"); break;
		case 2:  CREATE_VEHONPLAYER("khamelion"); break;
		case 3:  CREATE_VEHONPLAYER("carbonizzare"); break;
		case 4:  CREATE_VEHONPLAYER("feltzer2"); break;
		case 5:  CREATE_VEHONPLAYER("feltzer3"); break;
		case 6:  CREATE_VEHONPLAYER("rapidgt"); break;
		case 7:  CREATE_VEHONPLAYER("rapidgt2"); break;
		case 8:  CREATE_VEHONPLAYER("coquette"); break;
		case 9:  CREATE_VEHONPLAYER("surano"); break;
		case 10:  CREATE_VEHONPLAYER("ninef2"); break;
		case 11:  CREATE_VEHONPLAYER("banshee"); break;
		case 12:  CREATE_VEHONPLAYER("comet"); break;
		case 13:  CREATE_VEHONPLAYER("schwarzer"); break;
		case 14:  CREATE_VEHONPLAYER("fusilade"); break;
		case 15:  CREATE_VEHONPLAYER("buffalo"); break;
		case 16:  CREATE_VEHONPLAYER("buffalo2"); break;
		case 17:  CREATE_VEHONPLAYER("penumbra"); break;
		case 18:  CREATE_VEHONPLAYER("sultan"); break;
		case 19:  CREATE_VEHONPLAYER("futo"); break;
		case 20:  CREATE_VEHONPLAYER("furoregt"); break;
		case 21:  CREATE_VEHONPLAYER("massacro"); break;
		case 22:  CREATE_VEHONPLAYER("massacro2"); break;
		case 23:  CREATE_VEHONPLAYER("jester"); break;
		case 24:  CREATE_VEHONPLAYER("jester2"); break;
		case 25:  CREATE_VEHONPLAYER("windsor"); break;
		case 26:  CREATE_VEHONPLAYER("alpha"); break;
		case 27:  CREATE_VEHONPLAYER("kuruma"); break;
		case 28:  CREATE_VEHONPLAYER("kuruma2"); break;
		}
		break;
#pragma endregion
#pragma region Classics
	case spawnplayer3:
		subTitle("~h~CLASSICS");
		addOption("Inverto Coquette 2");
		addOption("Inverto Coquette 3");
		addOption("Truffade Z-Type");
		addOption("Grotti Stinger GT");
		addOption("Grotti Stinger");
		addOption("Pegassi Monroe");
		addOption("Dewbauchee JB 700");
		addOption("Declasse Tornado 1");
		addOption("Declasse Tornado 2");
		addOption("Declasse Tornado 3");
		addOption("Declasse Tornado 4");
		addOption("Vapid Peyote");
		addOption("Albany Manana");
		addOption("Albany Virgo");
		addOption("Albany Roosevelt");
		addOption("Vapid Blade");
		addOption("Benefactor Glendale");
		addOption("Lampadati Pigalle");
		addOption("Lampadati Casco");
		addOption("Vapid Chino");
		switch (getOption())
		{
		case 1:  CREATE_VEHONPLAYER("coquette2"); break;
		case 2:  CREATE_VEHONPLAYER("coquette3"); break;
		case 3:  CREATE_VEHONPLAYER("ztype"); break;
		case 4:  CREATE_VEHONPLAYER("stingergt"); break;
		case 5:  CREATE_VEHONPLAYER("stinger"); break;
		case 6:  CREATE_VEHONPLAYER("monroe"); break;
		case 7:  CREATE_VEHONPLAYER("jb700"); break;
		case 8:  CREATE_VEHONPLAYER("tornado"); break;
		case 9:  CREATE_VEHONPLAYER("tornado2"); break;
		case 10:  CREATE_VEHONPLAYER("tornado3"); break;
		case 11:  CREATE_VEHONPLAYER("tornado4"); break;
		case 12:  CREATE_VEHONPLAYER("peyote"); break;
		case 13:  CREATE_VEHONPLAYER("manana"); break;
		case 14:  CREATE_VEHONPLAYER("virgo"); break;
		case 15:  CREATE_VEHONPLAYER("btype"); break;
		case 16:  CREATE_VEHONPLAYER("buffalo2"); break;
		case 17:  CREATE_VEHONPLAYER("blade"); break;
		case 18:  CREATE_VEHONPLAYER("glendale"); break;
		case 19:  CREATE_VEHONPLAYER("pigalle"); break;
		case 20:  CREATE_VEHONPLAYER("casco"); break;
		case 21:  CREATE_VEHONPLAYER("chino"); break;
		} break;
#pragma endregion
#pragma region Muscle 
	case spawnplayer4:
		subTitle("~h~MUSCLE");
		addOption("Vapid Hotknife");
		addOption("Bravado Gauntlet");
		addOption("Declasse Vigero");
		addOption("Vapid Dominator");
		addOption("Albany Buccaneer");
		addOption("Imponte Phoenix");
		addOption("Declasse Sabre Turbo");
		addOption("Imponte Ruiner");
		addOption("Declasse Voodoo");
		addOption("Cheval Picador");
		addOption("Rat Loader 1");
		addOption("Rat Loader 2");
		switch (getOption())
		{
		case 1:  CREATE_VEHONPLAYER("hotknife"); break;
		case 2:  CREATE_VEHONPLAYER("gauntlet"); break;
		case 3:  CREATE_VEHONPLAYER("vigero"); break;
		case 4:  CREATE_VEHONPLAYER("dominator"); break;
		case 5:  CREATE_VEHONPLAYER("buccaneer"); break;
		case 6:  CREATE_VEHONPLAYER("phoenix"); break;
		case 7:  CREATE_VEHONPLAYER("sabregt"); break;
		case 8:  CREATE_VEHONPLAYER("ruiner"); break;
		case 9:  CREATE_VEHONPLAYER("voodoo2"); break;
		case 10:  CREATE_VEHONPLAYER("picador"); break;
		case 11:  CREATE_VEHONPLAYER("ratloader"); break;
		case 12:  CREATE_VEHONPLAYER("ratloader2"); break;
		}
		break;
#pragma endregion
#pragma region Sedans 
	case spawnplayer5:
		subTitle("~h~SEDANS");
		addOption("Enus Super Diamond");
		addOption("Ubermacht Oracle I");
		addOption("Ubermacht Oracle II");
		addOption("Dundreary Stretch");
		addOption("Cheval Fugitive");
		addOption("Cheval Surge");
		addOption("Benefactor Schafter");
		addOption("Karin Asterope");
		addOption("Karin Intruder");
		addOption("Albany Washington");
		addOption("Vapid Stanier");
		addOption("Vulcan Ingot");
		addOption("Albany Emperor I");
		addOption("Albany Emperor II");
		addOption("Albany Emperor III");
		addOption("Albany Primo");
		addOption("Dundreary Regina");
		addOption("Chariot Romero Hearse");
		addOption("Obey Tailgater");
		addOption("Declasse Premier");
		addOption("Zirconium Stratum");
		addOption("Declasse Asea I");
		addOption("Declasse Asea II");
		switch (getOption())
		{
		case 1:  CREATE_VEHONPLAYER("superd"); break;
		case 2:  CREATE_VEHONPLAYER("oracle"); break;
		case 3:  CREATE_VEHONPLAYER("oracle2"); break;
		case 4:  CREATE_VEHONPLAYER("stretch"); break;
		case 5:  CREATE_VEHONPLAYER("fugitive"); break;
		case 6:  CREATE_VEHONPLAYER("surge"); break;
		case 7:  CREATE_VEHONPLAYER("schafter2"); break;
		case 8:  CREATE_VEHONPLAYER("asterope"); break;
		case 9:  CREATE_VEHONPLAYER("intruder"); break;
		case 10:  CREATE_VEHONPLAYER("washington"); break;
		case 11:  CREATE_VEHONPLAYER("stanier"); break;
		case 12:  CREATE_VEHONPLAYER("ingot"); break;
		case 13:  CREATE_VEHONPLAYER("emperor"); break;
		case 14:  CREATE_VEHONPLAYER("emperor2"); break;
		case 15:  CREATE_VEHONPLAYER("emperor3"); break;
		case 16:  CREATE_VEHONPLAYER("primo"); break;
		case 17:  CREATE_VEHONPLAYER("regina"); break;
		case 18:  CREATE_VEHONPLAYER("romero"); break;
		case 19:  CREATE_VEHONPLAYER("tailgater"); break;
		case 20:  CREATE_VEHONPLAYER("premier"); break;
		case 21:  CREATE_VEHONPLAYER("stratum"); break;
		case 22:  CREATE_VEHONPLAYER("asea"); break;
		case 23:  CREATE_VEHONPLAYER("asea2"); break;
		}
		break;
#pragma endregion
#pragma region Coupes 
	case spawnplayer6:
		subTitle("~h~COUPES");
		addOption("Dewbauchee Exemplar");
		addOption("Enus Cognoscenti Cabrio");
		addOption("Lampadati Felon GT");
		addOption("Lampadati Felon,");
		addOption("Ubermacht Zion Cabri");
		addOption("Ubermacht Zion");
		addOption("Ubermacht Sentinel XS");
		addOption("Ubermacht Sentinel");
		addOption("Ocelot F620");
		addOption("Ocelot Jackal");
		switch (getOption())
		{
		case 1:  CREATE_VEHONPLAYER("exemplar"); break;
		case 2:  CREATE_VEHONPLAYER("cogcabrio"); break;
		case 3:  CREATE_VEHONPLAYER("felon2"); break;
		case 4:  CREATE_VEHONPLAYER("felon"); break;
		case 5:  CREATE_VEHONPLAYER("zion"); break;
		case 6:  CREATE_VEHONPLAYER("zion2"); break;
		case 7:  CREATE_VEHONPLAYER("sentinel"); break;
		case 8:  CREATE_VEHONPLAYER("sentinel2"); break;
		case 9:  CREATE_VEHONPLAYER("f620"); break;
		case 10:  CREATE_VEHONPLAYER("jackal"); break;
		}
		break;
#pragma endregion
#pragma region Compaktwagen 
	case spawnplayer7:
		subTitle("~h~COMPACT WAGEN");
		addOption("Karin Dilettante I");
		addOption("Karin Dilettante II");
		addOption("Weeny Issi");
		addOption("Bollokan Prairie");
		addOption("Dinka Blista");
		addOption("Declasse Rhapsody");
		addOption("Vulcar Warrener");
		addOption("Benefactor Panto");
		switch (getOption())
		{
		case 1:  CREATE_VEHONPLAYER("dilettante"); break;
		case 2:  CREATE_VEHONPLAYER("dilettante2"); break;
		case 3:  CREATE_VEHONPLAYER("issi2"); break;
		case 4:  CREATE_VEHONPLAYER("prairie"); break;
		case 5:  CREATE_VEHONPLAYER("blista"); break;
		case 6:  CREATE_VEHONPLAYER("rhapsody"); break;
		case 7:  CREATE_VEHONPLAYER("warrener"); break;
		case 8:  CREATE_VEHONPLAYER("panto"); break;
		}
		break;
#pragma endregion
#pragma region SUV Pickups 
	case spawnplayer8:
		subTitle("~h~SUV & PICKUPS");
		addOption("Gallivanter Baller 1");
		addOption("Gallivanter Baller 2");
		addOption("Obey Rocoto");
		addOption("Albany Cavalcade 1");
		addOption("Albany Cavalcade 2");
		addOption("Benefactor Dubsta 1");
		addOption("Benefactor Dubsta 2");
		addOption("Benefactor Dubsta 3");
		addOption("Benefactor Serrano");
		addOption("Dundreary Landstalker");
		addOption("Fathom FQ 2");
		addOption("Mammoth Patriot");
		addOption("Emperor Habanero");
		addOption("Vapid Radius");
		addOption("Declasse Granger");
		addOption("Canis Mesa 1");
		addOption("Canis Mesa 2");
		addOption("Canis Seminole");
		addOption("Canis Kalahari");
		addOption("Bravado Gresley");
		addOption("Karin BeeJay XL");
		addOption("Enus Huntley");
		addOption("Sadler 1");
		addOption("Sadler 2");
		addOption("Vapid Guardian");
		addOption("HVY Insurgent 1");
		addOption("HVY Insurgent 2");
		addOption("Karin Technical");
		switch (getOption())
		{
		case 1:  CREATE_VEHONPLAYER("baller"); break;
		case 2:  CREATE_VEHONPLAYER("baller2"); break;
		case 3:  CREATE_VEHONPLAYER("rocoto"); break;
		case 4:  CREATE_VEHONPLAYER("cavalcade"); break;
		case 5:  CREATE_VEHONPLAYER("cavalcade2"); break;
		case 6:  CREATE_VEHONPLAYER("dubsta"); break;
		case 7:  CREATE_VEHONPLAYER("dubsta2"); break;
		case 8:  CREATE_VEHONPLAYER("dubsta3"); break;
		case 9:  CREATE_VEHONPLAYER("serrano"); break;
		case 10:  CREATE_VEHONPLAYER("landstalker"); break;
		case 11:  CREATE_VEHONPLAYER("fq2"); break;
		case 12:  CREATE_VEHONPLAYER("patriot"); break;
		case 13:  CREATE_VEHONPLAYER("habanero"); break;
		case 14:  CREATE_VEHONPLAYER("radi"); break;
		case 15:  CREATE_VEHONPLAYER("granger"); break;
		case 16:  CREATE_VEHONPLAYER("mesa"); break;
		case 17:  CREATE_VEHONPLAYER("mesa2"); break;
		case 18:  CREATE_VEHONPLAYER("seminole"); break;
		case 19:  CREATE_VEHONPLAYER("kalahari"); break;
		case 20:  CREATE_VEHONPLAYER("gresley"); break;
		case 21:  CREATE_VEHONPLAYER("bjxl"); break;
		case 22:  CREATE_VEHONPLAYER("huntley"); break;
		case 23:  CREATE_VEHONPLAYER("sadler"); break;
		case 24:  CREATE_VEHONPLAYER("sadler2"); break;
		case 25:  CREATE_VEHONPLAYER("guardian"); break;
		case 26:  CREATE_VEHONPLAYER("insurgent2"); break;
		case 27:  CREATE_VEHONPLAYER("insurgent"); break;
		case 28:  CREATE_VEHONPLAYER("technical"); break;
		}
		break;
#pragma endregion
#pragma region Trucks 
	case spawnplayer9:
		subTitle("~h~TRUCKS");
		addOption("Monster Truck");
		addOption("Vapid Sandking XL");
		addOption("BF Dune Buggy");
		addOption("BF Dune 2 (Space Docker)");
		addOption("BF Injection");
		addOption("BF Bifta");
		addOption("Nagasaki Blazer 1");
		addOption("Nagasaki Blazer 2 (Trevors)");
		addOption("Canis Mesa (Merryweather");
		addOption("Vapid Sandking SWB");
		addOption("Bravado Duneloader");
		addOption("Canis Bodhi");
		addOption("Declasse Rancher XL 1");
		addOption("Declasse Rancher XL 2");
		addOption("Karin Rebel 1");
		addOption("Karin Rebel 2");
		addOption("Nagasaki Blazer Lifeguard");
		addOption("Coil Brawler");
		addOption("Dinka Enduro");
		switch (getOption())
		{
		case 1:  CREATE_VEHONPLAYER("monster"); break;
		case 2:  CREATE_VEHONPLAYER("sandking"); break;
		case 3:  CREATE_VEHONPLAYER("rocoto"); break;
		case 4:  CREATE_VEHONPLAYER("dune"); break;
		case 5:  CREATE_VEHONPLAYER("dune2"); break;
		case 6:  CREATE_VEHONPLAYER("bfinjection"); break;
		case 7:  CREATE_VEHONPLAYER("bifta"); break;
		case 8:  CREATE_VEHONPLAYER("blazer"); break;
		case 9:  CREATE_VEHONPLAYER("blazer3"); break;
		case 10:  CREATE_VEHONPLAYER("mesa3"); break;
		case 11:  CREATE_VEHONPLAYER("sandking2"); break;
		case 12:  CREATE_VEHONPLAYER("dloader"); break;
		case 13:  CREATE_VEHONPLAYER("bodhi2"); break;
		case 14:  CREATE_VEHONPLAYER("rancherxl"); break;
		case 15:  CREATE_VEHONPLAYER("rancherx2"); break;
		case 16:  CREATE_VEHONPLAYER("rebel"); break;
		case 17:  CREATE_VEHONPLAYER("rebel2"); break;
		case 18:  CREATE_VEHONPLAYER("blazer2"); break;
		case 19:  CREATE_VEHONPLAYER("brawler"); break;
		case 20:  CREATE_VEHONPLAYER("enduro"); break;
		}
		break;
#pragma endregion
#pragma region Vans 
	case spawnplayer10:
		subTitle("~h~VANS");
		addOption("Bravado Bison 1");
		addOption("Bravado Bison 2");
		addOption("Bravado Bison 3");
		addOption("Bravado Paradise");
		addOption("Zirconium Journey");
		addOption("Vapid Minivan");
		addOption("Brute Camper");
		addOption("Taco Van");
		addOption("BF Surfer");
		addOption("BF Surfer (Rusted)");
		addOption("Vapid Slamvan 1");
		addOption("Vapid Slamvan 2");
		switch (getOption())
		{
		case 1:  CREATE_VEHONPLAYER("bison"); break;
		case 2:  CREATE_VEHONPLAYER("bison2"); break;
		case 3:  CREATE_VEHONPLAYER("bison3"); break;
		case 4:  CREATE_VEHONPLAYER("paradise"); break;
		case 5:  CREATE_VEHONPLAYER("journey"); break;
		case 6:  CREATE_VEHONPLAYER("minivan"); break;
		case 7:  CREATE_VEHONPLAYER("camper"); break;
		case 8:  CREATE_VEHONPLAYER("taco"); break;
		case 9:  CREATE_VEHONPLAYER("surfer"); break;
		case 10:  CREATE_VEHONPLAYER("surfer2"); break;
		case 11:  CREATE_VEHONPLAYER("slamvan"); break;
		case 12:  CREATE_VEHONPLAYER("slamvan2"); break;
		}
		break;
#pragma endregion
#pragma region Off Road
	case spawnplayer11:
		subTitle("~h~OFF ROAD");
		addOption("Brawler");
		addOption("Dune Buggy");
		addOption("Liberator");
		addOption("Sanchez");
		switch (getOption())
		{
		case 1:  CREATE_VEHONPLAYER("brawler"); break;
		case 2:  CREATE_VEHONPLAYER("dune"); break;
		case 3:  CREATE_VEHONPLAYER("monster"); break;
		case 4:  CREATE_VEHONPLAYER("sanchez"); break;
		}
		break;
#pragma endregion
#pragma region Aircrafts
	case spawnplayer12:
		subTitle("~h~Cargos And Helicopters");
		addOption("~h~Big Cargo Plane");
		addOption("Annihilator");
		addOption("Buzzard");
		addOption("Cargobob");
		addOption("Maverick");
		addOption("Skylift");
		addOption("Trevor's Cargobob");
		addOption("Mammatus");
		addOption("Luxor");
		addOption("Lazer");
		addOption("Miljet");
		addOption("Titan");
		addOption("Vestra");
		addOption("Mallard");
		addOption("Frogger");
		addOption("Swift");
		addOption("Besra");
		addOption("Shamal");
		addOption("Cuban 800");
		addOption("Duster");
		addOption("Velum");
		addOption("~h~Atomic Blimp");
		switch (getOption())
		{
		case 1:  CREATE_VEHONPLAYER("cargoplane"); break;
		case 2:  CREATE_VEHONPLAYER("annihilator"); break;
		case 3:  CREATE_VEHONPLAYER("buzzard"); break;
		case 4:  CREATE_VEHONPLAYER("cargobob"); break;
		case 5:  CREATE_VEHONPLAYER("maverick"); break;
		case 6:  CREATE_VEHONPLAYER("skylift"); break;
		case 7:  CREATE_VEHONPLAYER("Cargobob"); break;
		case 8:  CREATE_VEHONPLAYER("mammatus"); break;
		case 9:  CREATE_VEHONPLAYER("luxor"); break;
		case 10:  CREATE_VEHONPLAYER("lazer"); break;
		case 11:  CREATE_VEHONPLAYER("miljet"); break;
		case 12:  CREATE_VEHONPLAYER("titan"); break;
		case 13:  CREATE_VEHONPLAYER("vestra"); break;
		case 14:  CREATE_VEHONPLAYER("stunt"); break;
		case 15:  CREATE_VEHONPLAYER("frogger"); break;
		case 16:  CREATE_VEHONPLAYER("swift"); break;
		case 17:  CREATE_VEHONPLAYER("besra"); break;
		case 18:  CREATE_VEHONPLAYER("shamal"); break;
		case 19:  CREATE_VEHONPLAYER("cuban800"); break;
		case 20:  CREATE_VEHONPLAYER("duster"); break;
		case 21:  CREATE_VEHONPLAYER("velum"); break;
		case 22:  CREATE_VEHONPLAYER("blimp"); break;
		}
		break;
#pragma endregion
#pragma region Emergency
	case spawnplayer13:
		subTitle("~h~EMERGENCY");
		addOption("FIB");
		addOption("FIB SUV");
		addOption("Firetruck");
		addOption("Ambulance");
		addOption("Police 1");
		addOption("Police 2");
		addOption("Police 3");
		addOption("Police 4");
		addOption("Police Bike");
		addOption("Police Old 1");
		addOption("Police Old 2");
		addOption("Police Van");
		addOption("Swat Truck");
		addOption("Sheriff 1");
		addOption("Sheriff 2");
		addOption("Prison Bus");
		addOption("Park Ranger");
		addOption("Life Guard SUV");
		switch (getOption())
		{
		case 1:  CREATE_VEHONPLAYER("fbi"); break;
		case 2:  CREATE_VEHONPLAYER("fbi2"); break;
		case 3:  CREATE_VEHONPLAYER("firetruk"); break;
		case 4:  CREATE_VEHONPLAYER("ambulance"); break;
		case 5:  CREATE_VEHONPLAYER("police"); break;
		case 6:  CREATE_VEHONPLAYER("police2"); break;
		case 7:  CREATE_VEHONPLAYER("police3"); break;
		case 8:  CREATE_VEHONPLAYER("police4"); break;
		case 9:  CREATE_VEHONPLAYER("policeb"); break;
		case 10:  CREATE_VEHONPLAYER("policeold1"); break;
		case 11:  CREATE_VEHONPLAYER("policeold2"); break;
		case 12:  CREATE_VEHONPLAYER("policet"); break;
		case 13:  CREATE_VEHONPLAYER("riot"); break;
		case 14:  CREATE_VEHONPLAYER("sheriff"); break;
		case 15:  CREATE_VEHONPLAYER("sheriff2"); break;
		case 16:  CREATE_VEHONPLAYER("pbus"); break;
		case 17:  CREATE_VEHONPLAYER("pranger"); break;
		case 18:  CREATE_VEHONPLAYER("lguard"); break;
		}
		break;
#pragma endregion
#pragma region Service_Vehicles 
	case spawnplayer14:
		subTitle("~h~SERVICE VEHICLES");
		addOption("Airport Bus");
		addOption("Dashhound");
		addOption("Bus");
		addOption("Rental Shuttle Bus");
		addOption("Tour Bus");
		addOption("Taxi");
		switch (getOption())
		{
		case 1:  CREATE_VEHONPLAYER("airbus"); break;
		case 2:  CREATE_VEHONPLAYER("coach"); break;
		case 3:  CREATE_VEHONPLAYER("bus"); break;
		case 4:  CREATE_VEHONPLAYER("rentalbus"); break;
		case 5:  CREATE_VEHONPLAYER("tourbus"); break;
		case 6:  CREATE_VEHONPLAYER("taxi"); break;
		}
		break;
#pragma endregion
#pragma region Military
	case spawnplayer15:
		subTitle("~h~MILITARY");
		addOption("Rhino Tank");
		addOption("Barracks 1");
		addOption("Barracks 2");
		addOption("Barracks 3 ");
		addOption("Canis Crusader");
		addOption("Tanker 1");
		addOption("Tanker 2");
		switch (getOption())
		{
		case 1:  CREATE_VEHONPLAYER("rhino"); break;
		case 2:  CREATE_VEHONPLAYER("barracks"); break;
		case 3:  CREATE_VEHONPLAYER("barracks2"); break;
		case 4:  CREATE_VEHONPLAYER("barracks3"); break;
		case 5:  CREATE_VEHONPLAYER("crusader"); break;
		case 6:  CREATE_VEHONPLAYER("tanker"); break;
		case 7:  CREATE_VEHONPLAYER("tanker2"); break;
		}
		break;
#pragma endregion
#pragma region Motorcycles
	case spawnplayer16:
		subTitle("~h~MOTOCYCLES");
		addOption("Nagasaki Carbon RS");
		addOption("Pegassi Bati 801");
		addOption("LCC Hexer");
		addOption("LCC Innovation");
		addOption("Dinka Double-T");
		addOption("Dinka Thrust");
		addOption("Dinka Vindicator");
		addOption("Pegassi Ruffian");
		addOption("Shitzu Vader");
		addOption("Shitzu PCJ 600");
		addOption("Shitzu Hakuchou");
		addOption("Dinka Akuma");
		addOption("Maibatsu Sanchez (Decal)");
		addOption("Maibatsu Sanchez");
		addOption("Pegassi Faggio");
		addOption("Western Daemon");
		addOption("Western Bagger");
		addOption("Principe Nemesis");
		addOption("Sovereign");
		addOption("Principe Lectro");
		switch (getOption())
		{
		case 1:  CREATE_VEHONPLAYER("carbonrs"); break;
		case 2:  CREATE_VEHONPLAYER("bati2"); break;
		case 3:  CREATE_VEHONPLAYER("hexer"); break;
		case 4:  CREATE_VEHONPLAYER("innovation"); break;
		case 5:  CREATE_VEHONPLAYER("double"); break;
		case 6:  CREATE_VEHONPLAYER("thrust"); break;
		case 7:  CREATE_VEHONPLAYER("vindicator"); break;
		case 8:  CREATE_VEHONPLAYER("ruffian"); break;
		case 9:  CREATE_VEHONPLAYER("vader"); break;
		case 10:  CREATE_VEHONPLAYER("pcj"); break;
		case 11:  CREATE_VEHONPLAYER("hakuchou"); break;
		case 12:  CREATE_VEHONPLAYER("akuma"); break;
		case 13:  CREATE_VEHONPLAYER("sanchez"); break;
		case 14:  CREATE_VEHONPLAYER("sanchez2"); break;
		case 15:  CREATE_VEHONPLAYER("faggio2"); break;
		case 16:  CREATE_VEHONPLAYER("daemon"); break;
		case 17:  CREATE_VEHONPLAYER("bagger"); break;
		case 18:  CREATE_VEHONPLAYER("nemesis"); break;
		case 19:  CREATE_VEHONPLAYER("sovereign"); break;
		case 20:  CREATE_VEHONPLAYER("lectro"); break;
		}
		break;
#pragma endregion
#pragma region Bicycles 
	case spawnplayer17:
		subTitle("~h~BICYCLES");
		addOption("Whippet Race Bike");
		addOption("Tri-Cycles Race Bike");
		addOption("Scorcher");
		addOption("Endurex Race Bike");
		addOption("Cruiser");
		addOption("BMX");
		addOption("Fixter");
		switch (getOption())
		{
		case 1:  CREATE_VEHONPLAYER("tribike"); break;
		case 2:  CREATE_VEHONPLAYER("tribike3"); break;
		case 3:  CREATE_VEHONPLAYER("scorcher"); break;
		case 4:  CREATE_VEHONPLAYER("tribike2"); break;
		case 5:  CREATE_VEHONPLAYER("cruiser"); break;
		case 6:  CREATE_VEHONPLAYER("bmx"); break;
		case 7:  CREATE_VEHONPLAYER("fixter"); break;
		}
		break;
#pragma endregion
#pragma region Commercial_Vehicles 
	case spawnplayer18:
		subTitle("~h~COMMERCIAL VEHICLES");
		addOption("Mixer 1");
		addOption("Mixer 2");
		addOption("Flatbed Truck");
		addOption("Airport Ripley");
		addOption("Rubble");
		addOption("Vapid Scrap Truck");
		addOption("Lawnmower");
		addOption("Dock Tug");
		addOption("Airport Tug");
		addOption("Tractor 1");
		addOption("Tractor 2");
		addOption("Tractor 3");
		addOption("Caddy 1");
		addOption("Caddy 2");
		switch (getOption())
		{
		case 1:  CREATE_VEHONPLAYER("mixer"); break;
		case 2:  CREATE_VEHONPLAYER("mixer2"); break;
		case 3:  CREATE_VEHONPLAYER("flatbed"); break;
		case 4:  CREATE_VEHONPLAYER("ripley"); break;
		case 5:  CREATE_VEHONPLAYER("rubble"); break;
		case 6:  CREATE_VEHONPLAYER("scrap"); break;
		case 7:  CREATE_VEHONPLAYER("mower"); break;
		case 8:  CREATE_VEHONPLAYER("docktug"); break;
		case 9:  CREATE_VEHONPLAYER("airtug"); break;
		case 10:  CREATE_VEHONPLAYER("tractor"); break;
		case 11:  CREATE_VEHONPLAYER("tractor2"); break;
		case 12:  CREATE_VEHONPLAYER("tractor3"); break;
		case 13:  CREATE_VEHONPLAYER("caddy"); break;
		case 14:  CREATE_VEHONPLAYER("caddy2"); break;
		}
		break;
#pragma endregion
#pragma region Boats 
	case spawnplayer19:
		subTitle("~h~BOATS");
		addOption("Dinka Marqui");
		addOption("Shitzu Jetmax");
		addOption("Shitzu Squalo");
		addOption("Shitzu Suntrap");
		addOption("Shitzu Tropic");
		addOption("Speedophile Seashark 1");
		addOption("Speedophile Seashark 2");
		addOption("Police Predator");
		addOption("Submarine");
		addOption("Pegassi Speeder");
		addOption("Nagasaki Dinghy 1");
		addOption("Nagasaki Dinghy 2");
		addOption("Nagasaki Dinghy 3");
		addOption("Lampadati Toro");
		switch (getOption())
		{
		case 1:  CREATE_VEHONPLAYER("marquis"); break;
		case 2:  CREATE_VEHONPLAYER("jetmax"); break;
		case 3:  CREATE_VEHONPLAYER("squalo"); break;
		case 4:  CREATE_VEHONPLAYER("suntrap"); break;
		case 5:  CREATE_VEHONPLAYER("tropic"); break;
		case 6:  CREATE_VEHONPLAYER("seashark"); break;
		case 7:  CREATE_VEHONPLAYER("seashark2"); break;
		case 8:  CREATE_VEHONPLAYER("predator"); break;
		case 9:  CREATE_VEHONPLAYER("submersible"); break;
		case 10:  CREATE_VEHONPLAYER("speeder"); break;
		case 11:  CREATE_VEHONPLAYER("dinghy"); break;
		case 12:  CREATE_VEHONPLAYER("dinghy2"); break;
		case 13:  CREATE_VEHONPLAYER("dinghy3"); break;
		case 14:  CREATE_VEHONPLAYER("toro"); break;
		}
		break;
#pragma endregion
#pragma region Trailers 
	case spawnplayer20:
		subTitle("~h~TRAILERS");
		addOption("Army Tanker");
		addOption("Army Tanker 1");
		addOption("Trailers 1");
		addOption("Trailers 2");
		addOption("Trailers 3");
		addOption("Trailer Small");
		addOption("Trailer Flat");
		addOption("Tv Trailer");
		switch (getOption())
		{
		case 1:  CREATE_VEHONPLAYER("armytanker"); break;
		case 2:  CREATE_VEHONPLAYER("armytrailer"); break;
		case 3:  CREATE_VEHONPLAYER("trailers"); break;
		case 4:  CREATE_VEHONPLAYER("trailers2"); break;
		case 5:  CREATE_VEHONPLAYER("trailers3"); break;
		case 6:  CREATE_VEHONPLAYER("trailersmall"); break;
		case 7:  CREATE_VEHONPLAYER("trflat"); break;
		case 8:  CREATE_VEHONPLAYER("tvtrailer"); break;
		}
		break;
#pragma endregion
#pragma region Heist
	case spawnplayer21:
		subTitle("~h~HEIST");
		addOption("Enduro");
		addOption("Guardian");
		addOption("Kuruma");
		addOption("Armored Kuruma");
		addOption("Casco");
		addOption("Seater Velum");
		addOption("Hydra", "hydra");
		addOption("Insurgent 50cal");
		addOption("Insurgent Pick-Up");
		addOption("Valkyrie", "valkyrie");
		addOption("Technical", "technical");
		addOption("Savage", "savage");
		addOption("Lectro", "lectro");
		addOption("Lost Slamvan");
		switch (getOption())
		{
		case 1:  CREATE_VEHONPLAYER("enduro"); break;
		case 2:  CREATE_VEHONPLAYER("guardian"); break;
		case 3:  CREATE_VEHONPLAYER("kuruma"); break;
		case 4:  CREATE_VEHONPLAYER("kuruma2"); break;
		case 5:  CREATE_VEHONPLAYER("casco"); break;
		case 6:  CREATE_VEHONPLAYER("velum2"); break;
		case 7:  CREATE_VEHONPLAYER("hydra"); break;
		case 8:  CREATE_VEHONPLAYER("insurgent"); break;
		case 9:  CREATE_VEHONPLAYER("insurgent2"); break;
		case 10:  CREATE_VEHONPLAYER("valkyrie"); break;
		case 11:  CREATE_VEHONPLAYER("technical"); break;
		case 12:  CREATE_VEHONPLAYER("savage"); break;
		case 13:  CREATE_VEHONPLAYER("lectro"); break;
		case 14:  CREATE_VEHONPLAYER("slamvan2"); break;
		}
		break;
#pragma endregion
#pragma region Naughty Things
	case Forceplayer:
		ViewInfo(true);
		drawESP(selectedPlayer);
		subTitle("~h~Force Player Options");
		addOption("Stop Animation");//spritemenu
		spritemenu("Force Player Animations", " ");
		addOption("Force Teleport To Mee~c~(Food)", " ");
		switch (getOption())
		{
		case 1: AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::GET_PLAYER_PED(selectedPlayer)); break;
		case 2: changeSubmenu(PlayerAnimate); break;
		case 3: teleportToMeFoot(selectedPlayer);
			drawNotification("~y~Click To Stop Animation Player"); break;
		} break;
#pragma endregion
#pragma region Force Animation
	case PlayerAnimate:
		ViewInfo(true);
		drawESP(selectedPlayer);
		subTitle(PLAYER::GET_PLAYER_NAME(selectedPlayer));
		addOption("Stop Animation");
		DoAdminations("Private Pole Dance", "mini@strip_club@pole_dance@pole_dance1", "pd_dance_01");
		DoAdminations("Honor Me Now", "oddjobs@bailbond_mountain", "excited_idle_c");
		DoAdminations("Hands Up", "mp_am_hold_up", "handsup_base");
		DoAdminations("Get Fucked", "rcmpaparazzo_2", "shag_loop_poppy");
		DoAdminations("Private Striper Dance", "mini@strip_club@private_dance@part1", "priv_dance_p1");
		DoAdminations("Pole Dance Striper", "mini@strip_club@pole_dance@pole_dance1", "pd_dance_01");
		DoAdminations("Push-Ups", "amb@world_human_push_ups@male@base", "base");
		DoAdminations("Sit-Ups", "amb@world_human_sit_ups@male@base", "base");
		DoAdminations("Car Sex", "ODDJOBS@ASSASSINATE@VICE@SEX", "frontseat_carsex_loop_m");
		DoAdminations("Electrocution", "ragdoll@human", "electrocute");
		DoAdminations("Suicide", "mp_suicide", "pistol");
		DoAdminations("Shower", "mp_safehouseshower@male@", "male_shower_idle_b");
		DoAdminations("Jogging", "rcmfanatic1", "jogging_up");
		DoAdminations("Balcony Fight", "random@domestic", "balcony_fight_male");
		DoAdminations("Sex Giver", "rcmpaparazzo_2", "shag_loop_a");
		DoAdminations("Dog Fucking", "missfra0_chop_find", "hump_loop_chop");
		DoAdminations("Dog Pissing", "creatures@rottweiler@move", "pee_right_idle");
		DoAdminations("ped on fire", "ragdoll@human", "on_fire");
		DoAdminations("lap dance sex", "mini@strip_club@pole_dance@pole_dance2", "pd_dance_02");
		DoAdminations("lap dance player", "mp_am_stripper", "lap_dance_player");
		DoAdminations("damage vehicle", "stungun@sitting", "damage_vehicle");
		DoAdminations("sex loop male", "mini@prostitutes@sexnorm_veh", "sex_loop_male");
		DoAdminations("Prostitute sex loop", "mini@prostitutes@sexnorm_veh", "sex_loop_prostitute");
		DoAdminations("Prostitute male", "mini@prostitutes@sexnorm_veh", "bj_loop_male");
		DoAdminations("Prostitute looping", "mini@prostitutes@sexnorm_veh", "bj_loop_prostitute");
		DoAdminations("Prostitute Car Sex 1", "random@drunk_driver_2", "cardrunksex_loop_m");
		DoAdminations("Prostitute Car Sex 2", "random@drunk_driver_2", "cardrunksex_loop_f");
		DoAdminations("emp 2", "creatures@retriever@amb@world_dog_barking@base", "base_facial");
		DoAdminations("Dog Sitting", "creatures@retriever@amb@world_dog_sitting@base", "base");
		DoAdminations("emp", "amb@world_human_statue@base", "base");
		DoAdminations("human Statue Muscles", "amb@world_human_statue@enter", "enter");
		DoAdminations("Human Statue Thanks", "amb@world_human_statue@idle_b", "idle_f");
		DoAdminations("zumbie Special", "special_ped@zombie@monologue_8@monologue_8g", "whosayscosplayisa_6");
		DoAdminations("trevor jerking", "switch@trevor@jerking_off", "trev_jerking_off_loop");
		DoAdminations("trevor Crazy", "switch@trevor@drunk_howling", "loop");
		DoAdminations("refen Loop", "misstrevor2ig_5c", "plead_loop");
		DoAdminations("approach no ball", "mini@golfai", "putt_approach_no_ball");
		DoAdminations("Barrel Rolls Loop", "misschinese2_barrelroll", "barrel_roll_loop_A");
		switch (getOption())
		{
		case 1: AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::GET_PLAYER_PED(selectedPlayer)); break;
		}
		break;
#pragma endregion
#pragma region Player Drops
	case Player_GoodStuff:
		ViewInfo(true);
		drawESP(selectedPlayer);
		subTitle(PLAYER::GET_PLAYER_NAME(selectedPlayer));//spritemenu
		spritemenu("Money Lobby Options", " ");
		addOption("Give Armour", " ");
		addOption("Give Stun Gun", " ");
		spritemenu("Give Weapon", " ");
		addOption("Give All Weapons", " ");
		addOption("Remove All Weapons", " ");
		addOption("Drop Ammunition", " ");
		addOption("Drop Parachute", " ");
		addOption("Drop Armour", " ");
		switch (getOption())
		{
		case 1: changeSubmenu(MoneyOOP); break;
		case 2: Armour(selectedPlayer); break;
		case 3: WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(selectedPlayer), 911657153, -1, true, true); break;
		case 4: changeSubmenu(giveplayerweapon); break;
		case 5: GiveAllWeapons(selectedPlayer); break;
		case 6: TakeWeaponsSelected(); break;
		case 7: dropPickup1(ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), 1), "prop_ld_ammo_pack_01", "PICKUP_AMMO_BULLET_MP", 10, "Ammunition", selectedPlayer); break;
		case 8: dropPickup1(ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), 1), "prop_parachute", "PICKUP_PARACHUTE", 1, "Parachute", selectedPlayer); break;
		case 9: dropPickup1(ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), 1), "prop_armour_pickup", "PICKUP_ARMOUR_STANDARD", 100, "Armour", selectedPlayer); break;
		} break;
#pragma endregion
#pragma region money options
	case MoneyOOP:
		drawESP(selectedPlayer);
		ViewInfo(true);
		subTitle("~h~Money Lobby Options");
		addBoolOption("Loop 40K", loop40K_, " ");
		addBoolOption("Fake Loop 40K", loop40KFake_, " ");
		addBoolOption("Money rain", MoneyRain, " ");
		addIntOption("Money Rain Radius", &MaxRadius, 1, 50, false, " ");
		switch (getOption())
		{
		case 1: loop40K_ = !loop40K_; break;
		case 2: loop40KFake_ = !loop40KFake_; break;
		case 3: MoneyRain = !MoneyRain; break;
		case 4: break;
		} break;
#pragma endregion
#pragma region Player Weapon Options
	case Player_Weapon_Options:
		ViewInfo(true);
		drawESP(selectedPlayer);
		subTitle(PLAYER::GET_PLAYER_NAME(selectedPlayer));
		spritemenu("Give Selected Weapon", " ");
		addOption("Give All Weapons", " ");
		addOption("Remove All Weapons", " ");
		addOption("Remove Stun Gun", " ");
		addBoolOption("Give Money Gun", BulletBagsPlayer, " ");
		addBoolOption("Give Fireball Gun", FirePlayerGun, " ");
		addBoolOption("Give Money Stack Gun", PlayerStackGun, " ");
		switch (getOption())
		{
		case 1:  changeSubmenu(Selected_Weapon); break;
		case 2:  GiveAllWeapons(selectedPlayer); break;
		case 3:  WEAPON::REMOVE_ALL_PED_WEAPONS(PLAYER::GET_PLAYER_PED(selectedPlayer), 1); break;
		case 4:  WEAPON::REMOVE_WEAPON_FROM_PED(PLAYER::GET_PLAYER_PED(selectedPlayer), 911657153); break;
		case 5:  BulletBagsPlayer = !BulletBagsPlayer; break;
		case 6:  FirePlayerGun = !FirePlayerGun; break;
		case 7:  PlayerStackGun = !PlayerStackGun; break;
		}
		break;
#pragma endregion
#pragma region Player Selected Weapon
	case Selected_Weapon:
		drawESP(selectedPlayer);
		subTitle(PLAYER::GET_PLAYER_NAME(selectedPlayer));
		addSubmenuOption("Melee", Melee_Weapon);
		addSubmenuOption("Pistol", Pistol_Weapon);
		addSubmenuOption("Shotgun", Shotgun_Weapon);
		addSubmenuOption("Assault", Assault_Weapon);
		addSubmenuOption("Rifle", Rifle_Weapon);
		addSubmenuOption("RPGs", RPGs_Weapon);
		break;
#pragma endregion
#pragma region Melee Weapon
	case Melee_Weapon:
		drawESP(selectedPlayer);
		subTitle(PLAYER::GET_PLAYER_NAME(selectedPlayer));
		SelectedWeapon("Knuckle", 0xD8DF3C3C);
		SelectedWeapon("Knife", 0x99B507EA);
		SelectedWeapon("Bottle", 0xF9E6AA4B);
		SelectedWeapon("Molotov", 0x24B17070);
		SelectedWeapon("Nightstick", 0x678B81B1);
		SelectedWeapon("Hammer", 0x4E875F73);
		SelectedWeapon("Bat", 0x958A4A8F);
		SelectedWeapon("Golfclub", 0x440E4788);
		SelectedWeapon("Crowbar", 0x84BD7BFD);
		SelectedWeapon("Ball", 0x23C9F95C);
		SelectedWeapon("Snowball", 0x787F0BB);
		SelectedWeapon("Grenade", 0x93E220BD);
		SelectedWeapon("Sticky Bomb", 0x2C3731D9);
		SelectedWeapon("Proxmine", 0xAB564B93);
		SelectedWeapon("Dagger", 0x92A27487);
		SelectedWeapon("Smoke Grenade", 0xFDBC8A50);
		SelectedWeapon("BZgas", 0xA0973D5E);
		SelectedWeapon("Fire Extinguisher", 0x060EC506);
		SelectedWeapon("Petrolcan", 0x34A67B97);
		SelectedWeapon("Digi Scanner", 0xFDBADCED);
		SelectedWeapon("Brief Case", 0x88C78EB7);
		SelectedWeapon("Breif Case 2", 0x01B79F17);
		SelectedWeapon("Flare", 0x497FACC3);
		SelectedWeapon("Parachute", 0xFBAB5776);
		break;
#pragma endregion
#pragma region Pistol Weapon
	case Pistol_Weapon:
		drawESP(selectedPlayer);
		subTitle(PLAYER::GET_PLAYER_NAME(selectedPlayer));
		SelectedWeapon("Pistol", 0x1B06D571);
		SelectedWeapon("Combat Pistol", 0x5EF9FEC4);
		SelectedWeapon("AP Pistol", 0x22D8FE39);
		SelectedWeapon("Marksman Pistol", 0xDC4DB296);
		SelectedWeapon("Vintage Pistol", 0x083839C4);
		SelectedWeapon("Heavy Pistol", 0xD205520E);
		SelectedWeapon("SNS Pistol", 0xBFD21232);
		SelectedWeapon("Flaregun", 0x47757124);
		SelectedWeapon("50 Cal", -1716589765);
		SelectedWeapon("Stun Gun", 911657153);
		break;
#pragma endregion
#pragma region Shotgun Weapon
	case Shotgun_Weapon:
		drawESP(selectedPlayer);
		subTitle(PLAYER::GET_PLAYER_NAME(selectedPlayer));
		SelectedWeapon("Pump Shotgun", 0x1D073A89);
		SelectedWeapon("Sawoff Shotgun", 0x7846A318);
		SelectedWeapon("Assault Shotgun", 0xE284C527);
		SelectedWeapon("Bullpup Shotgun", 0x9D61E50F);
		SelectedWeapon("Heavy Shotgun", 0x3AABBBAA);
		break;
#pragma endregion
#pragma region Assault Weapon
	case Assault_Weapon:
		drawESP(selectedPlayer);
		subTitle(PLAYER::GET_PLAYER_NAME(selectedPlayer));
		SelectedWeapon("Gusenberg", 0x61012683);
		SelectedWeapon("Special Carbine", 0xC0A3098D);
		SelectedWeapon("Combat PDW", 0x0A3D4D34);
		SelectedWeapon("Micro SMG", 0x13532244);
		SelectedWeapon("SMG", 0x2BE6766B);
		SelectedWeapon("Assault SMG", 0xEFE7E2DF);
		SelectedWeapon("MG", 0x9D07F764);
		SelectedWeapon("Combat MG", 0x7FD62962);
		SelectedWeapon("Minigun", 0x42BF8A85);
		break;
#pragma endregion
#pragma region Rifle Weapon
	case Rifle_Weapon:
		drawESP(selectedPlayer);
		subTitle(PLAYER::GET_PLAYER_NAME(selectedPlayer));
		SelectedWeapon("Musket", 0xA89CB99E);
		SelectedWeapon("Marksman Rifle", 0xC734385A);
		SelectedWeapon("Bullpup Rifle", 0x7F229F94);
		SelectedWeapon("Assault Rifle", 0xBFEFFF6D);
		SelectedWeapon("Carbine Rifle", 0x83BF0278);
		SelectedWeapon("Advanced Rifle", 0xAF113F99);
		SelectedWeapon("Sniper Rifle", 0x05FC3C11);
		SelectedWeapon("Heavy Sniper", 0x0C472FE2);
		break;
#pragma endregion
#pragma region RPGs Weapon
	case RPGs_Weapon:
		drawESP(selectedPlayer);
		subTitle(PLAYER::GET_PLAYER_NAME(selectedPlayer));
		SelectedWeapon("Homing Launcher", 0x63AB0442);
		SelectedWeapon("Firwork", 0x7F7497E5);
		SelectedWeapon("Grenade Launcher", 0xA284510B);
		SelectedWeapon("Grenade Launcher Smoke", 0x4DD2DC56);
		SelectedWeapon("RPG", 0xB1CA77B1);
		break;
#pragma endregion
#pragma region Player Tp Options
	case Player_TP_Options:
		ViewInfo(true);
		drawESP(selectedPlayer);
		subTitle(PLAYER::GET_PLAYER_NAME(selectedPlayer));
		addOption("Teleport To Player", " ");
		addOption("Teleport Into Vehicle", " ");
		addOption("Teleport To Me~c~(Vehicle)", " ");
		addOption("TP In Vehicle", " ");
		//addSubmenuOption("TP On Foot        ~c~(Force)", OnFootLocations, " ");
		switch (getOption())
		{
		case 1:  TeleportToPLayer(selectedPlayer); break;
		case 2:  if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::GET_PLAYER_PED(selectedPlayer), 0))
		{
			int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED(selectedPlayer), 0);
			PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), veh, GET_FREE_SEAT(veh));
		}  break;
		case 3: Vector3 My = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1); 
			TeleportClientHook(selectedPlayer, My.x, My.y, My.z); doTeleportClient = true; break;
			//case 4: changeSubmenu(Player_Teleport); break;
		case 4: break;
		}
		break;
#pragma endregion
#pragma region OnlinePlayer
	case OnlinePlayerOption:
		ViewInfo(true);
		drawESP(selectedPlayer);
		subTitle(PLAYER::GET_PLAYER_NAME(selectedPlayer));
		addOption("Passive Kill");
		addCharBOOLSwap("Esp Player", Marker, &MarkerVar1, 0, 6, hasESP);
		addOption("Clone Player", " ");
		spritemenu("Force Animation", " ");
		addOption("Force Teleport To Me", " ");
		addBoolOption("Freeze Player", frezzeplayer, " ");
		addBoolOption("Explosion loop", explosionloop, " ");
		addOption("Explode Player", " ");
		addBoolOption("Forcefield", forcefield, " ");
		addBoolOption("Spectate Player", SPECTATE, " ");
		addIntOption("Give Stars", &wantedstarsonline, 0, 5, true);
		addBoolOption("~r~Freeze Console", DoFreezeConsole);//test By WEB HACKER
		addOption("Copy Outfix Player");
		switch (getOption())
		{
		case 1: Vector3 Pos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), true);
			FIRE::ADD_OWNED_EXPLOSION(PLAYER::GET_PLAYER_PED(selectedPlayer), Pos.x, Pos.y, Pos.z, 1, 5, true, 0, 0);
			drawNotification("~b~Killed in Passive!!");	break;
		case 2: hasESP = !hasESP;  break; break;
		case 3: ClonePed(PLAYER::GET_PLAYER_PED(selectedPlayer)); break;
		case 4: changeSubmenu(PlayerAnimate); break;
		case 5: teleportToMeFoot(selectedPlayer); 
			drawNotification("~y~Click To Stop Animation Player"); break;
		case 6: frezzeplayer = !frezzeplayer; break;
		case 7: if (explosionloop == false) { drawNotification("Explosion Loop~b~ On"); explosionloop = true; }
			  else if (explosionloop == true) { drawNotification("Explosion Loop~r~ Off"); explosionloop = false; } break;
		case 8: ExplodePlayer(selectedPlayer); break;
		case 9: forcefield = !forcefield; break;
		case 10: SPECTATE = !SPECTATE; break;
		case 11: Wantedlevelonline = !Wantedlevelonline; break;
		case 12: if (DoFreezeConsole == false) { DoFreezeConsole = true; }
				 else if (DoFreezeConsole == true) { DoFreezeConsole = false; }
				 drawNotification("~y~10 Sec Freeze Player"); break;
		case 13: StealOutfit(); break;
		} break; break;
#pragma endregion
#pragma region Teleport
	case Teleportation1:
		subTitle("TELEPORT OPTIONS");//spritemenu
		spritemenu("Above", " ");
		spritemenu("Forward", " ");
		spritemenu("Favorites", " ");
		spritemenu("Shops", " ");
		spritemenu("Glitches", " ");
		spritemenu("Roofs Modd", " ");
		spritemenu("History Mod", " ");
		spritemenu("Map Loader", " ");
		addOption("To Waypoint");
		switch (getOption())
		{
		case 1: changeSubmenu(abovemenu);  break;
		case 2: changeSubmenu(forwardmenu);  break;
		case 3: changeSubmenu(Buildings);  break;
		case 4: changeSubmenu(Shops);  break;
		case 5: changeSubmenu(Glitches);  break;
		case 6: changeSubmenu(Roofs);  break;
		case 7: changeSubmenu(Land);  break;
		case 8: changeSubmenu(maploader);  break;
		case 9:  TPtoWaypoint(); break;
		} break;

#pragma endregion
#pragma region maploader
	case maploader:
		subTitle("~h~Maps Loadder");
		addOption("North Yankton");
		addOption("Porn Yacht");
		addOption("Hospital");
		addOption("Cargoship");
		switch (getOption())
		{
		case 1: northYankton(); break;
		case 2: pornYacht(); break;
		case 3: Hospital(); break;
		case 4: cargoship(); break;
		}
		break;
#pragma endregion
#pragma region abovemenu
	case abovemenu:
		subTitle("~h~Above Teleport");
		addOption("Above 2m");
		addOption("Above 4m");
		addOption("Above 6m");
		addOption("Above 8m");
		addOption("Above 10m");
		addIntOption("Custom Above", &CustomAbove, 0, 1000, true);
		switch (getOption())
		{
		case 1: above2m(); break;
		case 2: above4m(); break;
		case 3: above6m(); break;
		case 4: above8m(); break;
		case 5: above10m(); break;
		case 6: Vector3 Coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 0.00, CustomAbove);
			int Handle = PLAYER::PLAYER_PED_ID();
			if (PED::IS_PED_IN_ANY_VEHICLE(Handle, 0))
				Handle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(Handle, Coords.x, Coords.y, Coords.z, 0, 0, 1); break;
		}
		break;
#pragma endregion 
#pragma region forwardmenu
	case forwardmenu:
		subTitle("~h~Forward Teleport");
		addOption("Forward 2m");
		addOption("Forward 4m");
		addOption("Forward 6m");
		addOption("Forward 8m");
		addOption("Forward 10m");
		addIntOption("Custom Forward", &CustomForward, 0, 1000, true);
		switch (getOption())
		{
		case 1: forward2m(); break;
		case 2: forward4m(); break;
		case 3: forward6m(); break;
		case 4: forward8m(); break;
		case 5: forward10m(); break;
		case 6: Vector3 Coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, CustomForward, 0.0);
			int Handle = PLAYER::PLAYER_PED_ID();
			if (PED::IS_PED_IN_ANY_VEHICLE(Handle, 0))
				Handle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(Handle, Coords.x, Coords.y, Coords.z, 0, 0, 1); break;
		}
		break;
#pragma endregion
#pragma region Buildings
	case Buildings:
		subTitle("FAVORITES");
		addTeleportOption("Los Santos Airport", -1102.2910f, -2894.5160f, 13.9467f);
		addTeleportOption("Franklin's New House", 7.4150, 535.5486, 176.0279);
		addTeleportOption("Web Hacker Favorite", -1576.464, 2101.646, 68.169);
		addTeleportOption("Windmill Top", 2026.676, 1840.359, 133.098);
		addTeleportOption("Airport Favorite", -1085.888, -3516.348, 14.143);
		addTeleportOption("Atmosfera Los Santos", -129.964, 8130.873, 6705.286);
		addTeleportOption("quarry", 2954.196, 2783.410, 41.003);
		addTeleportOption("Police station", 441.404, -975.783, 30.690);
		addTeleportOption("Playboy Mansion", -1460.300, 177.782, 62.363);
		addTeleportOption("Paleto Bay Pier", -275.522, 6635.835, 7.425);
		addTeleportOption("Pacific Bank", 235.046, 216.434, 106.287);
		addTeleportOption("Noose Park", 2535.243, -383.799, 92.993);
		addTeleportOption("MT Chiliad Favorite", 450.412, 5566.958, 806.182);
		addTeleportOption("Marlowe Vineyads", 2098.373, 4775.498, 56.991);
		addTeleportOption("Los Santos LSC", -408.301, -113.646, 71.107);
		addTeleportOption("Fort Zancudo Favorite", -2225.026, 3105.161, 56.311);
		addTeleportOption("Airport field", -1336.001, -3044.000, 13.523);
		addTeleportOption("Airport Entrace", -1034.601, -2733.599, 13.333);
		addTeleportOption("Devin Weston House", -2646.388, 1870.179, 159.710);
		addTeleportOption("North San Andreas", 24.970, 7644.027, 18.402);
		addTeleportOption("Emergency Helipad", 308.9238f, -1458.9330f, 46.5095f);
		addTeleportOption("Inside IAA Building", 113.9319f, -618.5334f, 206.0465f);
		addTeleportOption("IAA Building Roof", 130.6824f, -634.9446f, 262.8510f);
		addTeleportOption("Waterfall", -597.9525f, 4475.2910f, 25.6890f);
		addTeleportOption("Bank Vault", 255.5819f, 217.6896f, 101.6834f);
		addTeleportOption("Inside FIB Building", 135.5220f, -749.0003f, 260.0000f);
		addTeleportOption("FIB Building Roof", 135.5220f, -749.0009f, 266.6102f);
		addTeleportOption("Dirtbike Trail", -1202.0910f, 2802.44f, 14.8256f);
		addTeleportOption("400k Apartment Inside", -878.5444f, -445.3285f, 125.6352f);
		addTeleportOption("400k Garage (Outside)", -795.46f, 308.89f, 85.71f);
		addTeleportOption("400k Apartment (Outside)", -775.0500f, 312.32f, 85.7f);
		addTeleportOption("400k Apartment (Roof)", -769.8004f, 331.2076f, 234.2694f);
		addTeleportOption("Airport Overwatch", -985.1005f, -2642.046f, 63.5170f);
		break; break;
#pragma endregion
#pragma region Shops
	case Shops:
		subTitle("SHOPS");
		addTeleportOption("Ponsonbys (Clothing)", -159.2996, -304.3292, 39.7333);
		addTeleportOption("Ammunation (Desert)", 1696.1050, 3755.1670, 34.7053);
		addTeleportOption("Ammunation (City)", 247.3652, -45.8777, 69.9411);
		addTeleportOption("LS Customs", -371.40, -130.12, 38.65);
		addTeleportOption("Beekers Garage", 175.98, 6603.27, 31.38);
		break; break;
#pragma endregion
#pragma region Glitches
	case Glitches:
		subTitle("GLITCHES");
		addTeleportOption("Under the bridge", -721.6599, -1000.6510, 23.5455);
		addTeleportOption("FIB Roof", 135.9541, -749.8984, 258.1520);
		addTeleportOption("City Wall", -254.9432, -147.3534, 42.7314);
		addTeleportOption("Mechanic", 546.0365, -183.3675, 54.4982);
		addTeleportOption("Apartment wall", 220.5997, -1006.7580, -98.9999);
		addTeleportOption("Under Parking Garage", -359.4955, -781.3347, 31.7852);
		addTeleportOption("Another Bridge", -615.2986, -577.6776, 30.6693);
		addTeleportOption("The Ocean", 4499.9470, -3946.6510, -100016.9000);
		addTeleportOption("Unknown Building", -11.5143, -691.2623, 54.7947);
		addTeleportOption("Location for Deer", 159.1143, 3226.0780, 40.9329);
		addTeleportOption("Wall Glitch", -134.4927, -667.1520, 36.177);
		addTeleportOption("Wall Glitch 2", -135.0291, -668.5015, 35.0691);
		addTeleportOption("Building GLitch", -91.6870, 33.0948, 71.4655);
		addTeleportOption("Building wall", -224.9551, -79.6451, 80.0779);
		addTeleportOption("Building wall 2", -224.9551, -79.6451, 80.0779);
		addTeleportOption("Under the bridge", 721.6599, -1000.6510, 23.5455);
		addTeleportOption("400k Apartment", -785.4869, 314.7161, 90.2189);
		break; break;
#pragma endregion
#pragma region Roofs
	case Roofs:
		subTitle("GOOD ROFS");
		addTeleportOption("FIB Building roof", 135.5220, -749.0009, 266.6102);
		addTeleportOption("IAA Building roof", 130.6824, -634.9446, 262.8510);
		addTeleportOption("Police parking roof", 334.2101, -1644.7660, 98.4960);
		addTeleportOption("400K apartment roof", -769.8004, 331.2076, 234.2694);
		addTeleportOption("Rooftop Rumble drop off", -1025.4400, 697.5500, 161.7000);
		addTeleportOption("Mount Chiliad", 449.3493, 5568.5380, 796.1312);
		addTeleportOption("Los Santos Customs roof 1", -354.8817, -150.8228, 74.2741);
		addTeleportOption("Roof (Scenic View)", -118.8224, -195.4712, 94.8497);
		addTeleportOption("BuildingTop/ledge(Scenic)", 201.9763, 567.6195, 131.6675);
		addTeleportOption("Rooftop brawl", -149.7626, -943.4242, 254.0494);
		addTeleportOption("Cannibal Camp roof", -1143.1450, 4951.1880, 230.1531);
		addTeleportOption("Under Roof", -1883.7390, 2062.8590, 144.8217);
		addTeleportOption("Emergency HeliPad", 308.9238, -1458.9330, 46.5095);
		addTeleportOption("Police HeliPad", 369.4300, -1601.8320, 36.9502);
		addTeleportOption("Maze Bank Helipad", -74.9424, -818.63446, 326.1743);
		addTeleportOption("Ontop of Vinewood Logo", 776.8780, 1175.6080, 345.9564);
		addTeleportOption("Hospital Helipads", 322.0547, -1448.0380, 46.5095);
		addTeleportOption("In the Sky", -74.3454, -821.6638, 2590.2230);
		addTeleportOption("Above Clouds", -73.4489, -833.5170, 5841.4240);
		addTeleportOption("HeliPad", -736.7500, -1437.750, 5.0003);
		break; break;
#pragma endregion
#pragma region Land
	case Land:
		subTitle("LANDS FAVORITE");
		addTeleportOption("Mount Chiliad", 495.0000, 5586.0000, 794.0000);
		addTeleportOption("Airport", -1102.2910, -2894.5160, 13.9467);
		addTeleportOption("Trevor's Air Field", 1741.4960, 3269.2570, 41.6014);
		addTeleportOption("Grapeseed Air Field", 2124.0330, 4800.5860, 41.0031);
		addTeleportOption("Fort Zacundo", -2012.8470, 2956.5270, 32.8101);
		addTeleportOption("Crane 1", -167.9822, -1001.9265, 296.2061);
		addTeleportOption("Crane 2", -120.3508, -977.8608, 304.2478);
		addTeleportOption("Crane 3", -119.859985, -976.43866, 306.3385);
		addTeleportOption("Mount Chiliad Jump", 430.2037, 5614.7340, 766.1684);
		addTeleportOption("Mount Chiliad Skyline", 446.5404, 5571.6250, 781.1896);
		addTeleportOption("Mount Chiliad", 413.4706, 5572.8210, 779.6819);
		addTeleportOption("Construction site on building", -147.5930, -964.6947, 254.1325);
		addTeleportOption("Far away beach", 178.3295, 7041.8220, 1.8671);
		addTeleportOption("Coral Reef", 106.6972, 7282.0550, 1.8821);
		addTeleportOption("Far end beach island", -125.6544, 7271.8940, 16.7366);
		addTeleportOption("Far Island", 17.8323, 7630.0140, 13.5068);
		addTeleportOption("Underwater ocean", 103.4720, 7744.1870, -158.1106);
		addTeleportOption("Dirtbike trail", -1202.0910, 2802.4400, 14.8256);
		addTeleportOption("Zancudo river", -558.9814, 2945.7010, 14.5917);
		addTeleportOption("Private hangout 2", -597.9525, 4475.2910, 25.6890);
		addTeleportOption("Creek swimming", -589.5320, 4395.3900, 18.1481);
		addTeleportOption("Helipad", -716.74, -1495.01, 5.41);
		addTeleportOption("FIB Building Inside", 135.5220, -749.0009, 260.0000);
		addTeleportOption("IAA Building Inside", 113.9319, -618.5334, 206.0465);
		addTeleportOption("Apartment", -878.5444, -445.3285, 125.6352);
		addTeleportOption("Michaels House", -813.6030, 179.4738, 72.1589);
		addTeleportOption("10 cars garage", 229.3570, -992.9106, -98.9999);
		addTeleportOption("Trevors Office Strip Club", 97.2707, -1290.9940, 29.2688);
		addTeleportOption("Trevors House", 1974.7580, 3819.4570, 33.4363);
		addTeleportOption("Franklins House (New)", 7.4150, 535.5486, 176.0279);
		addTeleportOption("Franklins House (OLD)", -14.9693, -1436.4430, 31.1185);
		addTeleportOption("Lesters House", 1248.1830, -1728.1040, 56.0000);
		addTeleportOption("Trevors Meth Lab", 1397.5240, 3607.4230, 38.9419);
		addTeleportOption("Humane Lab", 3617.2310, 3739.8710, 28.6901);
		addTeleportOption("Police Station", 441.2090, -983.1136, 30.6895);
		addTeleportOption("Bank Vault", 255.5819, 217.6896, 101.6834);
		addTeleportOption("Blaine County Bank", -104.2072, 6469.2650, 31.6267);
		addTeleportOption("Waynes Cousins House", -1159.0340, -1521.1800, 10.6327);
		addTeleportOption("Airport Terminal", -1561.5250, -3232.3460, 26.3361);
		addTeleportOption("Humane Lab 2", 3531.7030, 3673.6420, 28.1212);
		addTeleportOption("Inside casino", 937.4756, 42.4248, 80.8990);
		addTeleportOption("Behind bar in strip club", 126.1211, -1278.5130, 29.2696);
		addTeleportOption("Empty closed in room", 134.1213, -1289.5810, 29.2696);
		addTeleportOption("Gun range", 22.8730, -1073.8800, 29.7970);
		addTeleportOption("Miltary Base Tower", -2501.9390, 3309.8980, 91.9665);
		addTeleportOption("Franklins Bedroom", 2.6014, 525.5179, 170.6172);
		addTeleportOption("Building Wireframe", -129.3836, -951.1331, 218.8816);
		addTeleportOption("Garage (second room)", 222.5924, -968.1003, -98.9999);
		addTeleportOption("Humane Lab (Waterbody)", 3524.0700, 3711.9500, 20.9913);
		addTeleportOption("Garage car tools", 211.2500, -962.7500, 24.9667);
		addTeleportOption("Private Garage", 3601.3830, 3668.7930, 33.8718);
		addTeleportOption("Union Depository", -20.4297, -685.1064, 32.3381);
		addTeleportOption("Inside random building", -278.6654, 6185.8690, 31.4861);
		addTeleportOption("Alta St apartment Enter", -266.0524, -968.6304, 31.2243);
		addTeleportOption("Private Hangout(Creek)", -463.6622, 4483.6540, 36.0373);
		addTeleportOption("Inside Jonny Tung", -879.0649, -247.7447, 40.1937);
		addTeleportOption("Fort Zancudo (Inside Tower)", -2356.0940, 3248.6450, 101.4505);
		addTeleportOption("Elysian Island Base", 574.3914, -3121.3220, 18.7687);
		addTeleportOption("Prison", 1679.0490, 2513.7110, 45.5649);
		addTeleportOption("Prison Yard", 1640.7910, 2530.0440, 45.5649);
		addTeleportOption("Trapped in box", -655.6762, -160.8557, 42.1480);
		addTeleportOption("Prison Tower", 1541.6290, 2470.1400, 62.8751);
		addTeleportOption("IOU Tower", -866.4975, -251.8129, 40.1102);
		addTeleportOption("Creek (Mountain Tower)", 2784.6060, 6000.8770, 357.2007);
		break; break;
#pragma endregion
#pragma region spawn carrs
	case VehSpawner://spritemenu
		subTitle("Spawn Vehicles");
		spritemenu("Spawn Vehicles Options", " ");
		spritemenu("~r~Freeze Consolle Options", " ");
		spritemenu("Vehicles Freeze Console", " ");
		spritemenu("Super Cars", " ");
		spritemenu("Sports Cars", " ");
		spritemenu("Classics Cars", " ");
		spritemenu("Muscle Cars", " ");
		spritemenu("Sedans", " ");
		spritemenu("Coupes", " ");
		spritemenu("Compact Wagen", " ");
		spritemenu("SUV and Pickups", " ");
		spritemenu("Trucks", " ");
		spritemenu("Vans", " ");
		spritemenu("Off-Road", " ");
		spritemenu("Aircrafts", " ");
		spritemenu("Emergency Vehicles", " ");
		spritemenu("Service Vehicles", " ");
		spritemenu("Military Vehicles", " ");
		spritemenu("Motorcycles", " ");
		spritemenu("Bicycles", " ");
		spritemenu("Commercial Vehicles", " ");
		spritemenu("Boats", " ");
		spritemenu("Trailers", " ");
		spritemenu("Heist", " ");
		spritemenu("Vehicles Especial", " ");
		switch (getOption())
		{
		case 1: changeSubmenu(spawnoopd);  break;
		case 2: changeSubmenu(freezecomveh); break;
		case 3: changeSubmenu(spawnfreed);  break;
		case 4: changeSubmenu(Super);  break;
		case 5: changeSubmenu(Sports);  break;
		case 6: changeSubmenu(Classics);  break;
		case 7: changeSubmenu(Muscle);  break;
		case 8: changeSubmenu(Sedans);  break;
		case 9: changeSubmenu(Coupes);  break;
		case 10: changeSubmenu(Compaktwagen);  break;
		case 11: changeSubmenu(SUV_Pickups);  break;
		case 12: changeSubmenu(Trucks);  break;
		case 13: changeSubmenu(Vans);  break;
		case 14: changeSubmenu(Off_Road);  break;
		case 15: changeSubmenu(Aircrafts);  break;
		case 16: changeSubmenu(Emergency);  break;
		case 17: changeSubmenu(Service_Vehicles);  break;
		case 18: changeSubmenu(Military);  break;
		case 19: changeSubmenu(Motorcycles);  break;
		case 20: changeSubmenu(Bicycles);  break;
		case 21: changeSubmenu(Commercial_Vehicles);  break;
		case 22: changeSubmenu(Boats);  break;
		case 23: changeSubmenu(Trailers);  break;
		case 24: changeSubmenu(Heist);  break;
		case 25: changeSubmenu(eppveh);  break;
		}
		break;
#pragma endregion
#pragma region Super
	case spawnfreed:
		subTitle("~h~Vehicles Freeze Console");
		addVehOption("Space Docker", "dune2");
		addVehOption("Adder", "adder");
		 break;
#pragma endregion
#pragma region Super
	case spawnoopd:
		subTitle("~h~Spawn Vehicles Options");
		addBoolOption("Spawn God Mode", spawnWithInvincibility);
		addBoolOption("Full Upgrade", spawnSupedUp);
		addBoolOption("Full Upgrade", spawnSupedUp);
		//addFloatOption("Suspension", &VHSupensionValue, -10.0, 10.0, true); //freeze arrumar
		//addFloatOption("Wheels Size ~r~Freeze", &VHWheelsValue, -10.0, 10.0, true);//arrumar freeze///
		addFloatOption1("Wheels Size", "Wheels Size:", shrink, &wheelsizeValue, 0.0, 100, 0.1);//addFloatOption1
		//addOption("Real Drift");
		//addFloatOption("Traction", &VHTractionValue, -10.0, 10.0, true);//arrumar freeze///
		//addFloatOption("Traction 2", &VHTraction2Value, -10.0, 10.0, true);//arrumar freeze///
		switch (getOption())
		{
		case 1: spawnWithInvincibility = !spawnWithInvincibility; break;
		case 2: spawnSupedUp = !spawnSupedUp; break;
		//case 3: VEHICLE::SET_VEHICLE_FIXED(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0));
		//	for (int i = 0; i < 0x133; i++) SET_HANDLING(i, 0xBC, VHSupensionValue); break; //i have mine as a on off option so the float is on then move
		case 3: shrink = !shrink; break;
		case 4: /*Drift Car*/ break;
		//case 5: VEHICLE::SET_VEHICLE_FIXED(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED(PLAYER::PLAYER_ID()), 0)); for (int i = 0; i < 0x133; i++) SET_HANDLING(i, 0x74, VHTractionValue); break;
		//case 6: VEHICLE::SET_VEHICLE_FIXED(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED(PLAYER::PLAYER_ID()), 0)); for (int i = 0; i < 0x133; i++) SET_HANDLING(i, 0x7C, VHTraction2Value); break;
		} break;
#pragma endregion
#pragma region Super
	case eppveh:
		subTitle("~h~Vehicles Especial");
		addVehOption("Space Docker", "dune2", "Spawned: Space Docker");
		addVehOption("Bmx", "bmx", "Spawned: Bmx");
		addVehOption("Dock Handler", "handler", "Spawned: Dock Handler");
		addVehOption("Dozer", "bulldozer", "Spawned: Dozer");
		addVehOption("Hotknife", "hotknife", "Spawned: Hotknife");
		addVehOption("Blazer", "blazer3", "Spawned: Blazer");
		addVehOption("Tourbus", "tourbus", "Spawned: Tourbus");
		addVehOption("Limo", "stretch", "Spawned: Limo");
		addVehOption("Bus", "bus", "Spawned: Bus");
		addVehOption("Clown Van", "speedo2", "Spawned: Clown Van");
		addVehOption("Airtug", "airtug", "Spawned: Airtug");
		addVehOption("Caddy", "caddy2", "Spawned: Caddy");
		addVehOption("Docktug", "docktug", "Spawned: Docktug");
		addVehOption("Tractor", "tractor", "Spawned: Tractor");
		addVehOption("Forklift", "forklift", "Spawned: Forklift");
		addVehOption("Lawn Mower", "mower", "Spawned: Lawn Mower");
		addVehOption("Tow Truck", "towtruck", "Spawned: Tow Truck");
		addVehOption("HVY Cutter", "cutter", "Spawned: HVY Cutter");
		break;
#pragma endregion
#pragma region Super
	case Super:
		subTitle("~h~SUPER");
		addVehOption("Adder", "adder", " ");
		addVehOption("Bullet", "bullet", " ");
		addVehOption("Cheetah", "cheetah", " ");
		addVehOption("Entity XF", "ENTITYXF", " ");
		addVehOption("Infernus", "infernus", " ");
		addVehOption("Turismo", "turismor", " ");
		addVehOption("Vacca", "vacca", " ");
		addVehOption("Voltic", "voltic", " ");
		addVehOption("Osiris", "osiris", " ");
		addVehOption("Zentorno", "zentorno", " ");
		addVehOption("Progen T20", "t20", " ");
		break;
#pragma endregion
#pragma region Sports
	case Sports:
		subTitle("~h~SPORTS");
		addVehOption("Annis Elegy RH8", "elegy2", " ");
		addVehOption("Hijak Khamelion", "khamelion");
		addVehOption("Grotti Carbonizzare ", "carbonizzare");
		addVehOption("Benefactor Feltzer 1", "feltzer2");
		addVehOption("Benefactor Feltzer 2 ", "feltzer3");
		addVehOption("Dewbauchee Rapid GT 1 ", "rapidgt");
		addVehOption("Dewbauchee Rapid GT 2", "rapidgt2");
		addVehOption("Inverto Coquette 1", "coquette");
		addVehOption("Obey 9F Cabrio ", "ninef");
		addVehOption("Obey 9F", "ninef2");
		addVehOption("Benefactor Surano", "surano");
		addVehOption("Bravado Banshee", "banshee");
		addVehOption("Pfister Comet", "comet");
		addVehOption("Benefactor Schwartzer", "schwarzer");
		addVehOption("Schyster Fusilade", "fusilade");
		addVehOption("Bravado Buffalo", "buffalo");
		addVehOption("Bravado Buffalo 2", "buffalo2");
		addVehOption("Maibatsu Penumbra", "penumbra");
		addVehOption("Karin Sultan", "sultan");
		addVehOption("Karin Futo", "futo");
		addVehOption("Lampadati Furore GT", "furoregt");
		addVehOption("Dewbauchee Massacro 1", "massacro");
		addVehOption("Dewbauchee Massacro 2", "massacro2");
		addVehOption("Dinka Jester 1", "jester");
		addVehOption("Dinka Jester 2", "jester2");
		addVehOption("Enus Windsor", "windsor");
		addVehOption("Albany Alpha", "alpha");
		addVehOption("Karin Kuruma 1", "kuruma");
		addVehOption("Karin Kuruma 2", "kuruma2");
		break;
#pragma endregion
#pragma region Classics
	case Classics:
		subTitle("~h~CLASSICS");
		addVehOption("Inverto Coquette 2", "coquette2");
		addVehOption("Inverto Coquette 3", "coquette3");
		addVehOption("Truffade Z-Type", "ztype");
		addVehOption("Grotti Stinger GT", "stingergt");
		addVehOption("Grotti Stinger", "stinger");
		addVehOption("Pegassi Monroe", "monroe");
		addVehOption("Dewbauchee JB 700", "jb700");
		addVehOption("Declasse Tornado 1", "tornado");
		addVehOption("Declasse Tornado 2", "tornado2");
		addVehOption("Declasse Tornado 3", "tornado3");
		addVehOption("Declasse Tornado 4", "tornado4");
		addVehOption("Vapid Peyote", "peyote");
		addVehOption("Albany Manana", "manana");
		addVehOption("Albany Virgo", "virgo");
		addVehOption("Albany Roosevelt", "btype");
		addVehOption("Vapid Blade", "blade");
		addVehOption("Benefactor Glendale", "glendale");
		addVehOption("Lampadati Pigalle", "pigalle");
		addVehOption("Lampadati Casco", "casco");
		addVehOption("Vapid Chino", "chino");
		break;
#pragma endregion
#pragma region Muscle 
	case Muscle:
		subTitle("~h~MUSCLE");
		addVehOption("Vapid Hotknife", "hotknife");
		addVehOption("Bravado Gauntlet", "gauntlet");
		addVehOption("Declasse Vigero", "vigero");
		addVehOption("Vapid Dominator", "dominator");
		addVehOption("Albany Buccaneer", "buccaneer");
		addVehOption("Imponte Phoenix", "phoenix");
		addVehOption("Declasse Sabre Turbo", "sabregt");
		addVehOption("Imponte Ruiner", "ruiner");
		addVehOption("Declasse Voodoo", "voodoo2");
		addVehOption("Cheval Picador", "picador");
		addVehOption("Rat Loader 1", "ratloader");
		addVehOption("Rat Loader 2", "ratloader2");
		break;
#pragma endregion
#pragma region Sedans 
	case Sedans:
		subTitle("~h~SEDANS");
		addVehOption("Enus Super Diamond", "superd");
		addVehOption("Ubermacht Oracle I", "oracle");
		addVehOption("Ubermacht Oracle II", "oracle2");
		addVehOption("Dundreary Stretch", "stretch");
		addVehOption("Cheval Fugitive", "fugitive");
		addVehOption("Cheval Surge", "surge");
		addVehOption("Benefactor Schafter", "schafter2");
		addVehOption("Karin Asterope", "asterope");
		addVehOption("Karin Intruder", "intruder");
		addVehOption("Albany Washington", "washington");
		addVehOption("Vapid Stanier", "stanier");
		addVehOption("Vulcan Ingot", "ingot");
		addVehOption("Albany Emperor I", "emperor");
		addVehOption("Albany Emperor II", "emperor2");
		addVehOption("Albany Emperor III", "emperor3");
		addVehOption("Albany Primo", "primo");
		addVehOption("Dundreary Regina", "regina");
		addVehOption("Chariot Romero Hearse", "romero");
		addVehOption("Obey Tailgater", "tailgater");
		addVehOption("Declasse Premier", "premier");
		addVehOption("Zirconium Stratum", "stratum");
		addVehOption("Declasse Asea I", "asea");
		addVehOption("Declasse Asea II", "asea2");
		break;
#pragma endregion
#pragma region Coupes 
	case Coupes:
		subTitle("~h~COUPES");
		addVehOption("Dewbauchee Exemplar", "exemplar");
		addVehOption("Enus Cognoscenti Cabrio", "cogcabrio");
		addVehOption("Lampadati Felon GT", "felon2");
		addVehOption("Lampadati Felon,", "felon");
		addVehOption("Ubermacht Zion Cabri", "zion");
		addVehOption("Ubermacht Zion", "zion2");
		addVehOption("Ubermacht Sentinel XS", "sentinel");
		addVehOption("Ubermacht Sentinel", "sentinel2");
		addVehOption("Ocelot F620", "f620");
		addVehOption("Ocelot Jackal", "jackal");
		break;
#pragma endregion
#pragma region Compaktwagen 
	case Compaktwagen:
		subTitle("~h~COMPACT WAGEN");
		addVehOption("Karin Dilettante I", "dilettante");
		addVehOption("Karin Dilettante II", "dilettante2");
		addVehOption("Weeny Issi", "issi2");
		addVehOption("Bollokan Prairie", "prairie");
		addVehOption("Dinka Blista", "blista");
		addVehOption("Declasse Rhapsody", "rhapsody");
		addVehOption("Vulcar Warrener", "warrener");
		addVehOption("Benefactor Panto", "panto");
		break;
#pragma endregion
#pragma region SUV Pickups 
	case SUV_Pickups:
		subTitle("~h~SUV & PICKUPS");
		addVehOption("Gallivanter Baller 1", "baller");
		addVehOption("Gallivanter Baller 2", "baller2");
		addVehOption("Obey Rocoto", "rocoto");
		addVehOption("Albany Cavalcade 1", "cavalcade");
		addVehOption("Albany Cavalcade 2", "cavalcade2");
		addVehOption("Benefactor Dubsta 1", "dubsta");
		addVehOption("Benefactor Dubsta 2", "dubsta2");
		addVehOption("Benefactor Dubsta 3", "dubsta3");
		addVehOption("Benefactor Serrano", "serrano");
		addVehOption("Dundreary Landstalker", "landstalker");
		addVehOption("Fathom FQ 2", "fq2");
		addVehOption("Mammoth Patriot", "patriot");
		addVehOption("Emperor Habanero", "habanero");
		addVehOption("Vapid Radius", "radi");
		addVehOption("Declasse Granger", "granger");
		addVehOption("Canis Mesa 1", "mesa");
		addVehOption("Canis Mesa 2", "mesa2");
		addVehOption("Canis Seminole", "seminole");
		addVehOption("Canis Kalahari", "kalahari");
		addVehOption("Bravado Gresley", "gresley");
		addVehOption("Karin BeeJay XL", "bjxl");
		addVehOption("Enus Huntley", "huntley");
		addVehOption("Sadler 1", "sadler");
		addVehOption("Sadler 2", "sadler2");
		addVehOption("Vapid Guardian", "guardian");
		addVehOption("HVY Insurgent 1", "insurgent2");
		addVehOption("HVY Insurgent 2", "insurgent");
		addVehOption("Karin Technical", "technical");
		break;
#pragma endregion
#pragma region Trucks 
	case Trucks:
		subTitle("~h~TRUCKS");
		addVehOption("Monster Truck", "monster");
		addVehOption("Vapid Sandking XL", "sandking");
		addVehOption("BF Dune Buggy", "dune");
		addVehOption("BF Dune 2 (Space Docker)", "dune2");
		addVehOption("BF Injection", "bfinjection");
		addVehOption("BF Bifta", "bifta");
		addVehOption("Nagasaki Blazer 1", "blazer");
		addVehOption("Nagasaki Blazer 2 (Trevors)", "blazer3");
		addVehOption("Canis Mesa (Merryweather", "mesa3");
		addVehOption("Vapid Sandking SWB", "sandking2");
		addVehOption("Bravado Duneloader", "dloader");
		addVehOption("Canis Bodhi", "bodhi2");
		addVehOption("Declasse Rancher XL 1", "rancherxl");
		addVehOption("Declasse Rancher XL 2", "rancherxl2");
		addVehOption("Karin Rebel 1", "rebel");
		addVehOption("Karin Rebel 2", "rebel2");;
		addVehOption("Nagasaki Blazer Lifeguard", "blazer2");
		addVehOption("Coil Brawler", "brawler");
		addVehOption("Dinka Enduro", "enduro");;
		break;
#pragma endregion
#pragma region Vans 
	case Vans:
		subTitle("~h~VANS");
		addVehOption("Bravado Bison 1", "bison");
		addVehOption("Bravado Bison 2", "bison2");
		addVehOption("Bravado Bison 3", "bison3");
		addVehOption("Bravado Paradise", "paradise");
		addVehOption("Zirconium Journey", "journey");
		addVehOption("Vapid Minivan", "minivan");
		addVehOption("Vapid Bobcat XL", "bobcatxl");
		addVehOption("Bravado Rumpo 1", "rumpo");
		addVehOption("Bravado Rumpo 2", "rumpo2");
		addVehOption("Brute Pony 1", "pony");
		addVehOption("Brute Pony 2", "pony2");
		addVehOption("Declasse Burrito 1", "burrito");
		addVehOption("Declasse Burrito 2", "burrito2");
		addVehOption("Declasse Burrito 3", "burrito3");
		addVehOption("Declasse Burrito 4", "burrito4");
		addVehOption("Declasse Burrito 5", "burrito5");
		addVehOption("Declasse Burrito 6", "burrito6");
		addVehOption("Declasse Burrito 7", "burrito7");
		addVehOption("Vapid Speedo 1", "speedo");
		addVehOption("Vapid Speedo 2", "speedo2");
		addVehOption("Bravado Youga", "youga");
		addVehOption("Boxville 1", "boxville");
		addVehOption("Boxville 2", "boxville2");
		addVehOption("Boxville 3", "boxville3");
		addVehOption("Boxville 4", "boxville4");
		addVehOption("Brute Camper", "camper");
		addVehOption("Taco Van", "taco");
		addVehOption("BF Surfer", "surfer");
		addVehOption("BF Surfer (Rusted)", "surfer2");
		addVehOption("Vapid Slamvan 1", "slamvan");
		addVehOption("Vapid Slamvan 2", "slamvan2");
		break;
#pragma endregion
#pragma region Off Road
	case Off_Road:
		subTitle("~h~OFF ROAD");
		addVehOption("Brawler", "brawler", "Spawned: Brawler");
		addVehOption("Dune Buggy", "dune", "Spawned: Dune Buggy");
		addVehOption("Liberator", "monster", "Spawned: Liberator");
		addVehOption("Sanchez", "sanchez", "Spawned: Sanchez");
		break;
#pragma endregion
#pragma region Aircrafts
	case Aircrafts:
		subTitle("~h~AIRCRAFTS");
		addVehOption("Big Cargo Plane", "cargoplane", "Spawned: Big Cargo Plane");
		addVehOption("Annihilator", "annihilator", "Spawned: Annihilator");
		addVehOption("Buzzard", "buzzard", "Spawned: Buzzard");
		addVehOption("Cargobob", "cargobob", "Spawned: Cargobob");
		addVehOption("Maverick", "maverick", "Spawned: Maverick");
		addVehOption("Skylift", "skylift", "Spawned: Skylift");
		addVehOption("Trevor's Cargobob", "cargobob3", "Spawned: Trevor's Cargobob");
		addVehOption("Mammatus", "mammatus", "Spawned: Mammatus");
		addVehOption("Luxor", "luxor", "Spawned: Luxor");
		addVehOption("Lazer", "lazer", "Spawned: Lazer");
		addVehOption("Miljet", "miljet", "Spawned: Miljet");
		addVehOption("Titan", "titan", "Spawned: Titan");
		addVehOption("Vestra", "vestra", "Spawned: Vestra");
		addVehOption("Mallard", "stunt", "Spawned: Mallard");
		addVehOption("Frogger", "frogger", "Spawned: Frogger");
		addVehOption("Swift", "swift", "Spawned: Swift");
		addVehOption("Besra", "besra", "Spawned: Besra");
		addVehOption("Shamal", "shamal", "Spawned: Shamal");
		addVehOption("Cuban 800", "cuban800", "Spawned: Cuban 800");
		addVehOption("Duster", "duster", "Spawned: Duster");
		addVehOption("Velum", "velum", "Spawned: Velum");
		addVehOption("Atomic Blimp", "blimp", "Spawned: Atomic Blimp");
		break;
#pragma endregion
#pragma region Emergency
	case Emergency:
		subTitle("~h~EMERGENCY");
		addVehOption("FIB", "fbi");
		addVehOption("FIB SUV", "fbi2");
		addVehOption("Firetruck", "firetruk");
		addVehOption("Ambulance", "ambulance");
		addVehOption("Police 1", "police");
		addVehOption("Police 2", "police2");
		addVehOption("Police 3", "police3");
		addVehOption("Police 4", "police4");
		addVehOption("Police Bike", "policeb");
		addVehOption("Police Old 1", "policeold1");
		addVehOption("Police Old 2", "policeold2");
		addVehOption("Police Van", "policet");
		addVehOption("Swat Truck", "riot");
		addVehOption("Sheriff 1", "sheriff");
		addVehOption("Sheriff 2", "sheriff2");
		addVehOption("Prison Bus", "pbus");
		addVehOption("Park Ranger", "pranger");
		addVehOption("Life Guard SUV", "lguard");
		break;
#pragma endregion
#pragma region Service_Vehicles 
	case Service_Vehicles:
		subTitle("~h~SERVICE VEHICLES");
		addVehOption("Airport Bus", "airbus");
		addVehOption("Dashhound", "coach");
		addVehOption("Bus", "bus");
		addVehOption("Rental Shuttle Bus", "rentalbus");
		addVehOption("Tour Bus", "tourbus");
		addVehOption("Taxi", "taxi");
		break;
#pragma endregion
#pragma region Military
	case Military:
		subTitle("~h~MILITARY");
		addVehOption("Rhino Tank", "rhino");
		addVehOption("Barracks 1", "barracks");
		addVehOption("Barracks 2", "barracks2");
		addVehOption("Barracks 3 ", "barracks3");
		addVehOption("Canis Crusader", "crusader");
		addVehOption("Tanker 1", "tanker");
		addVehOption("Tanker 2", "tanker2");
		break;
#pragma endregion
#pragma region Motorcycles
	case Motorcycles:
		subTitle("~h~MOTOCYCLES");
		addVehOption("Nagasaki Carbon RS", "carbonrs");
		addVehOption("Pegassi Bati 801", "bati2");
		addVehOption("LCC Hexer", "hexer");
		addVehOption("LCC Innovation", "innovation");
		addVehOption("Dinka Double-T", "double");
		addVehOption("Dinka Thrust", "thrust");
		addVehOption("Dinka Vindicator", "vindicator");
		addVehOption("Pegassi Ruffian", "ruffian");
		addVehOption("Shitzu Vader", "vader");
		addVehOption("Shitzu PCJ 600", "pcj");
		addVehOption("Shitzu Hakuchou", "hakuchou");
		addVehOption("Dinka Akuma", "akuma");
		addVehOption("Maibatsu Sanchez (Decal)", "sanchez");
		addVehOption("Maibatsu Sanchez", "sanchez2");
		addVehOption("Pegassi Faggio", "faggio2");
		addVehOption("Western Daemon", "daemon");
		addVehOption("Western Bagger", "bagger");
		addVehOption("Principe Nemesis", "nemesis");
		addVehOption("Sovereign", "sovereign");
		addVehOption("Principe Lectro", "lectro");
		break;
#pragma endregion
#pragma region Bicycles 
	case Bicycles:
		subTitle("~h~BICYCLES");
		addVehOption("Whippet Race Bike", "tribike");
		addVehOption("Tri-Cycles Race Bike", "tribike3");
		addVehOption("Scorcher", "scorcher");
		addVehOption("Endurex Race Bike", "tribike2");
		addVehOption("Cruiser", "cruiser");
		addVehOption("BMX", "bmx");
		addVehOption("Fixter", "fixter");
		break;
#pragma endregion
#pragma region Commercial_Vehicles 
	case Commercial_Vehicles:
		subTitle("~h~COMMERCIAL VEHICLES");
		addVehOption("Maibatsu Mule 1", "mule");
		addVehOption("Maibatsu Mule 2", "mule2");
		addVehOption("Maibatsu Mule 3", "mule3");
		addVehOption("JoBuilt Phantom", "phantom");
		addVehOption("Vapid Benson", "benson");
		addVehOption("MTL Packer", "packer");
		addVehOption("MTL Pounder", "pounder");
		addVehOption("JoBuilt Hauler", "hauler");
		addVehOption("Brute Stockade 1", "stockade");
		addVehOption("Brute Stockade 2", "stockade3");
		addVehOption("HVY Biff", "biff");
		addVehOption("HVY Dump", "dump");
		addVehOption("HVY Dozer", "bulldozer");
		addVehOption("HVY Forklift", "forklift");
		addVehOption("HVY Handler", "handler");
		addVehOption("HVY Cutter", "cutter");
		addVehOption("Utility Truck 1", "utillitruck");
		addVehOption("Utility Truck 2", "utillitruck2");
		addVehOption("Utility Truck 3", "utillitruck3");
		addVehOption("Trashmaster 1", "trash");
		addVehOption("Trashmaster 2", "trash2");
		addVehOption("Towtruck 1", "towtruck");
		addVehOption("Towtruck 2", "towtruck2");
		addVehOption("TipTruck 1", "tiptruck");
		addVehOption("TipTruck 2", "tiptruck2");
		addVehOption("Mixer 1", "mixer");
		addVehOption("Mixer 2", "mixer2");
		addVehOption("Flatbed Truck", "flatbed");
		addVehOption("Airport Ripley", "ripley");
		addVehOption("Rubble", "rubble");
		addVehOption("Vapid Scrap Truck", "scrap");
		addVehOption("Lawnmower", "mower");
		addVehOption("Dock Tug", "docktug");
		addVehOption("Airport Tug", "airtug");
		addVehOption("Tractor 1", "tractor");
		addVehOption("Tractor 2", "tractor2");
		addVehOption("Tractor 3", "tractor3");
		addVehOption("Caddy 1", "caddy");
		addVehOption("Caddy 2", "caddy2");
		break;
#pragma endregion
#pragma region Boats 
	case Boats:
		subTitle("~h~BOATS");
		addVehOption("Dinka Marqui", "marquis");
		addVehOption("Shitzu Jetmax", "jetmax");
		addVehOption("Shitzu Squalo, ", "squalo");
		addVehOption("Shitzu Suntrap", "suntrap");
		addVehOption("Shitzu Tropic", "tropic");
		addVehOption("Speedophile Seashark 1", "seashark");
		addVehOption("Speedophile Seashark 2", "seashark2");
		addVehOption("Police Predator", "predator");
		addVehOption("Submarine", "submersible");
		addVehOption("Pegassi Speeder", "speeder");
		addVehOption("Nagasaki Dinghy 1", "dinghy");
		addVehOption("Nagasaki Dinghy 2", "dinghy2");
		addVehOption("Nagasaki Dinghy 3", "dinghy3");
		addVehOption("Lampadati Toro", "toro");
		break;
#pragma endregion
#pragma region Trailers 
	case Trailers:
		subTitle("~h~TRAILERS");
		addVehOption("Army Tanker", "armytanker");
		addVehOption("Army Tanker 1", "armytrailer");
		addVehOption("Army Tanker 2", "armytrailer2");
		addVehOption("Bale Trailer", "baletrailer");
		addVehOption("Boat Trailer", "boattrailer");
		addVehOption("Cablecar", "cablecar");
		addVehOption("Dock Trailer", "docktrailer");
		addVehOption("Freight Car 1", "freight");
		addVehOption("Freight Car 2", "freightcar");
		addVehOption("Freight Container 1", "freightcont1");
		addVehOption("Freight Container 2", "freightcont2");
		addVehOption("Freight Train Boxcar", "freightgrain");
		addVehOption("Grain Trailer", "graintrailer");
		addVehOption("Metro Train", "metrotrain");
		addVehOption("Mobile Home Trailer", "proptrailer");
		addVehOption("Rake Trailer", "raketrailer");
		addVehOption("Train Fuel Tank Car", "tankercar");
		addVehOption("Car Carrier Trailer", "tr2");
		addVehOption("Marquis Trailer", "tr3");
		addVehOption("Super Car Carrier Trailer", "tr4");
		addVehOption("Trailer Logs", "trailerlogs");
		addVehOption("Trailers 1", "trailers");
		addVehOption("Trailers 2", "trailers2");
		addVehOption("Trailers 3", "trailers3");
		addVehOption("Trailer Small", "trailersmall");
		addVehOption("Trailer Flat", "trflat");
		addVehOption("Tv Trailer", "tvtrailer");
		break;
#pragma endregion
#pragma region Heist
	case Heist:
		subTitle("~h~HEIST");
		addVehOption("Enduro", "enduro", "Spawned: Enduro");
		addVehOption("Guardian", "guardian", "Spawned: Guardian");
		addVehOption("Kuruma", "kuruma", "Spawned: Kuruma");
		addVehOption("Armored Kuruma", "kuruma2", "Spawned: Armored Kuruma");
		addVehOption("Casco", "casco", "Spawned: Casco");
		addVehOption("Seater Velum", "velum2", "Spawned: Seater Velum");
		addVehOption("Hydra", "hydra", "Spawned: Hydra");
		addVehOption("Insurgent 50cal", "insurgent", "Spawned: Insurgent");
		addVehOption("Insurgent Pick-Up", "insurgent2", "Spawned: Insurgent Pick-Up");
		addVehOption("Valkyrie", "valkyrie", "Spawned: Valkyrie");
		addVehOption("Technical", "technical", "Spawned: Technical");
		addVehOption("Savage", "savage", "Spawned: Savage");
		addVehOption("Lectro", "lectro", "Spawned: Lectro");
		addVehOption("Lost Slamvan", "slamvan2", "Spawned: Lost Slamvan");
		break;
#pragma endregion
#pragma region Freeze console v1
	case freezecomveh:
		subTitle("~h~Select Freeze Vehicle");
		addOption("~r~Space Docker Plane");
		addOption("~r~Space Docker heli");
		addOption("~r~adder Plane");
		addOption("~r~adder heli");
		switch (getOption())
		{
		case 1:	char bytes1[] = { 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x04 };
				write_process(0x402BBC98, &bytes1, sizeof(bytes1));
				drawNotification("Use Space docker to freeze console");//space docker plane
				break;
		case 2:	char bytes2[] = { 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x04 };
				write_process(0x402BBC98, &bytes2, sizeof(bytes2));
				drawNotification("Use Space docker to freeze console");//space docker heli
				break;
		case 3:	char bytes3[] = { 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x04 };
				write_process(0x402DEAC8, &bytes3, sizeof(bytes3));
				drawNotification("Use adder to freeze console");//adder plane
				break;
		case 4:	char bytes4[] = { 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x04 };
				write_process(0x402DEAC8, &bytes4, sizeof(bytes4));
				drawNotification("Use adder to freeze console");//adder heli
				break;//acima funciona perfeitamente
		} break;
#pragma endregion
#pragma region Edit Vehicle
	case Vehicle_Options:
		subTitle("EDIT VEHICLE");
		addOption("Fix Vehicle");
		addBoolOption("Invisibility", carinvstext);
		addBoolOption("Flying Vehicle", FlyCar);
		addBoolOption("God Mode", GodModeVehicle);
		addOption("Flip Vehicle Upright");
		addOption("Paint Random");
		addBoolOption("No Fall Vehicle", seatbelt);
		addBoolOption("No Visible Damage", novisibledamage);
		addSubmenuOption("Los Santos Customs", LSC);//
		addSubmenuOption("Manage Binds", VehicleBindsSelf);
		addSubmenuOption("Neons", neons);
		addSubmenuOption("Drive Types", drivetype);
		addSubmenuOption("Vehicle Weapons", vehicleweapons);
		addSubmenuOption("Extra Options", vehMiscellaneous);
		addBoolOption("Smoke Loop", HasSmokeLoop);//needs work
		addBoolOption("Drive on Walls", walldrive_);
		addBoolOption("Drift", drift);
		addBoolOption("No Collision", hasNoCollision);
		addBoolOption("Hydraulics", pimpin);
		addBoolOption("Wheelie Car", Wiiili);
		addBoolOption("Speed-O-Meter", SpeedOMeter);
		addBoolOption("Lower Vehicle", _lower);
		addBoolOption("Random Color loop", looprainbow_);
		addBoolOption("Rainbow Car Slow", Slow_Rainbow_Loop);
		addBoolOption("left arrow", TurnSignalLeft);
		addBoolOption("right arrow", TurnSignalRight);
		addIntOption("Change Plate Type", &platetype1, 0, 5, true);
		addSubmenuOption("Tire Smoke Menu", Tire_Smoke);
		addSubmenuOption("Vehicle Door Options", OpenShut_Doors);
		addBoolOption("License Plate Loop", HasPlateLoop);
		spritemenu("Vehicle Creator", " ");
		addBoolOption("Max Upgrade Loop", AutoUpgradeLoop);//new
		addBoolOption("Bright Lights", vehlights);//new
		addOption("Auto-Drive To WayPoint");//new
		addIntOption("Player Vehicle Alpha", &VehicleAlpha, 0, 255, 1);//new
		int VehIDedit = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		switch (getOption())
		{
		case 1: NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(VehIDedit);
			if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(VehIDedit)) {
				VEHICLE::SET_VEHICLE_FIXED(VehIDedit);
			}
			break;
		case 2: carinvstext = !carinvstext; vinval_ = !vinval_; NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(VehIDedit);
			if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(VehIDedit)) {
				ENTITY::SET_ENTITY_VISIBLE(VehIDedit, vinval_);
			}
			break;
		case 3: FlyCar = !FlyCar; break;
		case 4: GodModeVehicle = !GodModeVehicle; break;
		case 5: NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(VehIDedit);
			if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(VehIDedit))
			{
				VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(VehIDedit);
			}
			break;
		case 6: PaintVehRan(); break;
		case 7: seatbelt = !seatbelt; break;
		case 8: novisibledamage = !novisibledamage; break;
		case 9: break;
		case 10: break;
		case 11: break;
		case 12: break;
		case 13: break;
		case 14: changeSubmenu(vehMiscellaneous);  break;
		case 15: if (HasSmokeLoop)
		{
			HasSmokeLoop = false;
			drawNotification("Smoke Loop: ~r~Stopped");
		}
				else
				{
					HasSmokeLoop = true;
					drawNotification("Smoke Loop: ~b~Started");
				} break;
		case 16: walldrive_ = !walldrive_;
			drawNotification("~b~Use a monster truck and get your wheels on a wall before enabling!!!"); break;
		case 17: int vehicle;
			vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
			if (!drift)
			{
				VEHICLE::SET_VEHICLE_REDUCE_GRIP(vehicle, 1);
			}
			else if (drift)
			{
				VEHICLE::SET_VEHICLE_REDUCE_GRIP(vehicle, 0);
			}
			drift = !drift; break;
		case 18:  if (hasNoCollision)
		{
			NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0));
			ENTITY::SET_ENTITY_COLLISION(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), true, true);
			hasNoCollision = false;
		}
				 else
				 {
					 NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0));
					 ENTITY::SET_ENTITY_COLLISION(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), false, false);
					 hasNoCollision = true;
				 }
				 break;
		case 19: pimpin = !pimpin; if (pimpin == true) { drawNotification("L3 To Use!"); } break;
		case 20: WWiiiliCar();
			drawNotification("L3 To Use!"); break;
		case 21:  if (SpeedOMeter) { SpeedOMeter = false; }
				 else { SpeedOMeter = true; } break;
		case 22: _lower = !_lower; break;
		case 23: looprainbow_ = !looprainbow_; break;
		case 24: Slow_Rainbow_Loop = !Slow_Rainbow_Loop;	break;
		case 25: TurnSignalLeft = !TurnSignalLeft; break; break;
		case 26: TurnSignalRight = !TurnSignalRight; break; break;
		case 27: changeplate(platetype1); break;
		case 28: break;
		case 29: break;
		case 30: HasPlateLoop = !HasPlateLoop; break;
		case 31: changeSubmenu(VEHICLECREATOR); break;
		case 32: AutoUpgradeLoop = !AutoUpgradeLoop;
			drawNotification("Fully upgrade any vehicle you sit on."); break;
		case 33: vehlights = !vehlights;
			drawNotification("Every vehicle you get in will have very bright lights."); break;
		case 34: DriveToWP();
			drawNotification("Drive automatically to the waypoint."); break;
		case 35: ENTITY::SET_ENTITY_ALPHA(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), VehicleAlpha, 0); break;
		} break;
#pragma endregion
#pragma region Vehicle cREATOR
	case VEHICLECREATOR:
		subTitle("Vehicle Creator");
		addOption("Manager Objects");
		addOption("Jetski Ramp");
		addOption("Water Ramp 01");
		addOption("Water Ramp 02");
		addOption("Water Ramp 03");
		addOption("MP Ramp 01");
		addOption("cs bowie knife");
		addOption("ld fireaxe");
		addOption("prop haybail");
		addOption("waste barrel");
		addOption("Parachute drop arms");
		addOption("bumper car");
		addOption("prop wheel");
		addOption("car engine");
		addOption("heist emp");
		addOption("power cell");
		addOption("prop minigun");
		addOption("cs tablet");
		addOption("prop flare");
		addOption("dlc roller");
		addOption("hd seats");
		addOption("tool broom");
		addOption("road cone 01");
		addOption("tool box");
		addOption("des barge");
		addOption("ballistic shield");
		addOption("cons plank");
		addOption("uv cheetah");
		addOption("air lights");
		addOption("prop teddy");
		addOption("stinger 04");
		switch (getOption())
		{
		case 1: changeSubmenu(Object_Manager); break;
		case 2: ObjectString = "prop_jetski_ramp_01";
			LoadingObject = true;
			break;
		case 3: ObjectString = "prop_water_ramp_01";
			LoadingObject = true;
			break;
		case 4: ObjectString = "prop_water_ramp_02";
			LoadingObject = true;
			break;
		case 5: ObjectString = "prop_water_ramp_03";
			LoadingObject = true;
			break;
		case 6: ObjectString = "prop_mp_ramp_01";
			LoadingObject = true;
			break;
		case 7: ObjectString = "prop_cs_bowie_knife";
			LoadingObject = true;
			break;
		case 8: ObjectString = "prop_ld_fireaxe";
			LoadingObject = true;
			break;
		case 9: ObjectString = "prop_ld_haybail";
			LoadingObject = true;
			break;
		case 10: ObjectString = "prop_rad_waste_barrel_01";
			LoadingObject = true;
			break;
		case 11: ObjectString = "prop_drop_armscrate_01";
			LoadingObject = true;
			break;
		case 12: ObjectString = "prop_bumper_car_01";
			LoadingObject = true;
			break;
		case 13: ObjectString = "prop_wheel_01";
			LoadingObject = true;
			break;
		case 14: ObjectString = "prop_car_engine_01";
			LoadingObject = true;
			break;
		case 15: ObjectString = "hei_prop_heist_emp";
			LoadingObject = true;
			break;
		case 16: ObjectString = "prop_power_cell";
			LoadingObject = true;
			break;
		case 17: ObjectString = "prop_minigun_01";
			LoadingObject = true;
			break;
		case 18: ObjectString = "prop_cs_tablet";
			LoadingObject = true;
			break;
		case 19: ObjectString = "prop_flare_01";
			LoadingObject = true;
			break;
		case 20: ObjectString = "ind_prop_dlc_roller_car";
			LoadingObject = true;
			break;
		case 21: ObjectString = "prop_hd_seats_01";
			LoadingObject = true;
			break;
		case 22: ObjectString = "prop_tool_broom";
			LoadingObject = true;
			break;
		case 23: ObjectString = "prop_roadcone01a";
			LoadingObject = true;
			break;
		case 24: ObjectString = "prop_tool_box_02";
			LoadingObject = true;
			break;
		case 25: ObjectString = "prop_lev_des_barge_01";
			LoadingObject = true;
			break;
		case 26: ObjectString = "prop_ballistic_shield";
			LoadingObject = true;
			break;
		case 27: ObjectString = "prop_cons_plank";
			LoadingObject = true;
			break;
		case 28: ObjectString = "v_ilev_uvcheetah";
			LoadingObject = true;
			break;
		case 29: ObjectString = "prop_air_lights_05a";
			LoadingObject = true;
			break;
		case 30: ObjectString = "prop_mem_teddy_02";
			LoadingObject = true;
			break;
		case 31: ObjectString = "p_stinger_04";
			LoadingObject = true;
			break;
		}
		break;
#pragma endregion
#pragma region Object_Manager
	case Object_Manager:
		subTitle("Vehicle creator");
		for (int i = 0; i < 15; i++)
		{
			if (ENTITY::DOES_ENTITY_EXIST(SpawnedObject[i]))
			{
				addOption(ObjectNameArray[i], "");
			}
			else
			{
				addOption("~c~No Object Spawned", "");
			}
		}
		if (optionPress && ENTITY::DOES_ENTITY_EXIST(SpawnedObject[currentOption - 1]))
		{
			SelectedObject = currentOption - 1;
			changeSubmenu(Object_Movement);
		}
		break;
#pragma endregion
#pragma region Object_Movement
	case Object_Movement:
		subTitle(ObjectNameArray[SelectedObject]);
		addFloatOption("Movement Speed", &MoveSize, 0.00, 2.01, true);
		addWechselFloatOption("X Axis", &PosX_1, -180, +180, true);
		addWechselFloatOption("Y Axis", &PosY_1, -180, +180, true);
		addWechselFloatOption("Z Axis", &PosZ_1, -180, +180, true);
		addWechselFloatOption("Pitch", &Pitch, -180, +180, true);
		addWechselFloatOption("Roll", &Roll, -180, +180, true);
		addWechselFloatOption("Yaw", &Yaw, -180, +180, true);
		addOption("Copy Object");
		addOption("Delete Object");
		switch (getOption())
		{
		case 2: Attacho = true; break;
		case 3: Attacho = true; break;
		case 4: Attacho = true; break;
		case 5:
			if (ENTITY::DOES_ENTITY_EXIST(SpawnedObject[SelectedObject]));
			{
				Object_Handle = SpawnedObject[SelectedObject];
				MoveObject = true;
				char buf[100];
				snprintf(buf, sizeof(buf), "Moved Pitch: ~b~object", ObjectNameArray[SelectedObject]);
				drawNotification(buf);
			}
			break;
		case 6:
			if (ENTITY::DOES_ENTITY_EXIST(SpawnedObject[SelectedObject]));
			{
				Object_Handle = SpawnedObject[SelectedObject];
				MoveObject = true;
				char buf[100];
				snprintf(buf, sizeof(buf), "Moved Roll: ~b~object", ObjectNameArray[SelectedObject]);
				drawNotification(buf);
			}
			break;
		case 7:
			if (ENTITY::DOES_ENTITY_EXIST(SpawnedObject[SelectedObject]));
			{
				Object_Handle = SpawnedObject[SelectedObject];
				MoveObject = true;
				char buf[100];
				snprintf(buf, sizeof(buf), "Moved Yaw: ~b~object", ObjectNameArray[SelectedObject]);
				drawNotification(buf);
			}
			break;
		case 8:
			if (ENTITY::DOES_ENTITY_EXIST(SpawnedObject[SelectedObject]));
			{
				int hash = ENTITY::GET_ENTITY_MODEL(SpawnedObject[SelectedObject]);
				Vector3 pos = ENTITY::GET_ENTITY_COORDS(SpawnedObject[SelectedObject], true);
				pos.z += 0.60;
				Create_Object("", ObjectNameArray[SelectedObject], pos, true, hash);
				char buf[100];
				snprintf(buf, sizeof(buf), "Copied: ~b~object", ObjectNameArray[SelectedObject]);
				drawNotification(buf);
			}
			break;
		case 9:
			if (ENTITY::DOES_ENTITY_EXIST(SpawnedObject[SelectedObject]));
			{
				DeleteEntity(SpawnedObject[SelectedObject]);
				char buf[100];
				snprintf(buf, sizeof(buf), "Deleted: ~b~object", ObjectNameArray[SelectedObject]);
				drawNotification(buf);
			}
			break;
		case 11:
			if (ENTITY::DOES_ENTITY_EXIST(SpawnedObject[SelectedObject]));
			{
				Object_Handle = SpawnedObject[SelectedObject];
				Attacho = !Attacho;
			}
			break;
		}
		break;
#pragma endregion
#pragma region Open/Shut Doors
   case vehMiscellaneous:
	   subTitle("~h~veh Miscellaneous");
	   addIntOption("Open Vehicle Door", &vehdoor, 0, 6, true);
	   addOption("Shut Vehicle Doors");
	   addBoolOption("Stick To Ground", sticktoground);
	   addBoolOption("Interior Light", InteriorLights);
	   addBoolOption("Full Beam", FullBeam);
	   addIntOption("Dirt Level", &DirtLevl, 0, 15, true);
	   addBoolOption("Bulletproof Tyres", BulletproofTyres);
	   addBoolOption("Scorched Vehicle", Scorched);
	   addBoolOption("No Gravity", nogravity);
	   addIntOption("Light Multiplier", &lightMultiply, 0, 100, true);
	   int vehicle;
	   vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
	   switch (getOption())
	   {
	   case 1: VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), vehdoor, 0, 1); break;
	   case 2: VEHICLE::SET_VEHICLE_DOORS_SHUT(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), vehdoor); break;
	   case 3: sticktoground = !sticktoground; break;
	   case 4: InteriorLights = !InteriorLights; break;
	   case 5: FullBeam = !FullBeam; break;
	   case 6: VEHICLE::SET_VEHICLE_DIRT_LEVEL(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), DirtLevl); break;
	   case 7:
		   if (!BulletproofTyres)
		   {
			   VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(VehID, false);
		   }
		   else if (BulletproofTyres)
		   {
			   VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(VehID, true);
		   }
		   BulletproofTyres = !BulletproofTyres; break;
	   case 8:
		   if (!Scorched)
		   {
			   ENTITY::SET_ENTITY_RENDER_SCORCHED(vehicle, true);
		   }
		   else if (Scorched)
		   {
			   ENTITY::SET_ENTITY_RENDER_SCORCHED(vehicle, false);
		   }
		   Scorched = !Scorched; break;
	   case 9:
		   if (!nogravity)
		   {
			   VEHICLE::SET_VEHICLE_GRAVITY(vehicle, false);
		   }
		   else if (nogravity)
		   {
			   VEHICLE::SET_VEHICLE_GRAVITY(vehicle, true);
		   }
		   nogravity = !nogravity; break;
	   case 10: VEHICLE::SET_VEHICLE_LIGHT_MULTIPLIER(vehicle, lightMultiply); break;
	   }
	   break;
#pragma endregion
#pragma region Open/Shut Doors
   case OpenShut_Doors:
	   subTitle("Door Options");
	   addIntOption("Power Window Down", &vehwindow, 0, 6, true);
	   addIntOption("Power Window Up", &vehwindow, 0, 6, true);
	   addIntOption("Open Vehicle Door", &vehdoor, 0, 6, true);
	   addOption("Shut Vehicle Doors");
	   switch (getOption())
	   {
	   case 1: VEHICLE::ROLL_DOWN_WINDOW(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), vehwindow); break;
	   case 2: VEHICLE::ROLL_UP_WINDOW(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), vehwindow); break;
	   case 3: VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), vehdoor, 0, 1); break;
	   case 4: VEHICLE::SET_VEHICLE_DOORS_SHUT(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), vehdoor); break;
	   }
	   break;
#pragma endregion
#pragma region Tire_Smoke
   case Tire_Smoke:
	   subTitle("Tire Smoke");
	   addSmokeColor("Tire Color Red", &redcolor, 0, 255, true);
	   addSmokeColor("Tire Color Blue", &bluecolor, 0, 255, true);
	   addSmokeColor("Tire Color Green", &greencolor, 0, 255, true);
	   addOption("Apply Smoke Color");
	   addBoolOption("Tire Smoke Loop", HasSmokeLoop);
	   switch (getOption())
	   {
	   case 4: int vehicle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
		   NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(vehicle);
		   VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
		   VEHICLE::TOGGLE_VEHICLE_MOD(vehicle, 20, 1);
		   VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(vehicle, 0);
		   VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(vehicle, redcolor, greencolor, bluecolor); break;
	   case 5: HasSmokeLoop = !HasSmokeLoop; break;
	   }
	   break;
#pragma endregion 
#pragma region vehicle weapons
	case vehicleweapons:
		subTitle("VEHICLE WEAPONS");
		addBoolOption("Weapons", VehEap);
		addOption("RPG");
		addOption("FireWork");
		addOption("Red Laser");
		addOption("Green Laser");
		addOption("Tank");
		addOption("Space Rocket");
		addOption("Plane Rocket");
		addOption("Buzzard");
		switch (getOption())
		{
		case 1: VehEap = !VehEap; break;
		case 2: featureWeaponAsset = "WEAPON_RPG"; break;
		case 3: featureWeaponAsset = "WEAPON_FIREWORK"; break;
		case 4: featureWeaponAsset = "VEHICLE_WEAPON_ENEMY_LASER"; break;
		case 5: featureWeaponAsset = "VEHICLE_WEAPON_PLAYER_LASER"; break;
		case 6: featureWeaponAsset = "VEHICLE_WEAPON_TANK"; break;
		case 7: featureWeaponAsset = "VEHICLE_WEAPON_SPACE_ROCKET"; break;
		case 8: featureWeaponAsset = "VEHICLE_WEAPON_PLANE_ROCKET"; break;
		case 9: featureWeaponAsset = "VEHICLE_WEAPON_PLAYER_BUZZARD"; break;
		}
		break;
#pragma endregion
#pragma region drivetype
	case drivetype:
		subTitle("DRIVE TYPES");
		addBoolOption("Drive on Air", MeinCode);
		addBoolOption("Drive on Water", MeinCodewat);
		switch (getOption())
		{
		case 1: DriveAir(); break;
		case 2: DriveWater(); break;
		}
		break;
#pragma endregion
#pragma region veh colocur
	case vehcolour:
		subTitle("VEHICLE COLOURS");
		addOption("Black");
		addOption("Graphite");
		addOption("Black Steel");
		addOption("Dark Steel");
		addOption("Silver");
		addOption("Bluish Silver");
		addOption("Rolled Silver");
		addOption("Shadow Silver");
		addOption("Cast Iron Silver");
		addOption("Anthracite Black");
		addOption("Matte Black");
		addOption("Matte Grey");
		addOption("Light Grey");
		addOption("Util Black");
		addOption("Util Black Poly");
		addOption("Util Dark Silver");
		addOption("Util Shadow Silver");
		addOption("Worn Black"); //18
		addOption("Worn Graphite");
		addOption("Worn Silver Grey");
		addOption("Worn Silver");
		addOption("Worn Blue Silver");
		addOption("Worn Shadow Silver");
		addOption("Red");
		addOption("Blaze Red");
		addOption("Grace Red");
		addOption("Garnet Red");
		addOption("Sunset Red");
		addOption("Cabernet Red");
		addOption("Candy Red");
		addOption("Sunrise Orange");
		addOption("Gold");
		addOption("Dark Red");
		addOption("Matte Orange");
		addOption("Yellow");
		addOption("Util Red");
		addOption("Util Bright Red");
		addOption("Util Garnet Red");
		addOption("Worn Red");
		addOption("Worn Golden Red");
		addOption("Metallic Racing Green");
		addOption("Sea Green");
		addOption("Olive Green");
		addOption("Bright Green");
		addOption("Metallic Gasoline Green");
		addOption("Matte Lime Green");
		addOption("Dark Green");
		addOption("Worn Green");
		addOption("Metallic Dark Blue");
		addOption("Galaxy Blue");
		addOption("Dark Blue");
		addOption("Saxon Blue");
		addOption("Blue");
		addOption("Mariner Blue");
		addOption("Harbour Blue");
		addOption("Diamond Blue");
		addOption("Ultra Blue");
		addOption("Schafter Purpler");
		addOption("Metallic Ultra Blue");
		addOption("Racing Blue");
		addOption("Light Blue");
		addOption("Util Midnight Blue");
		addOption("Util Blue");
		addOption("Util Sea Foam Blue");
		addOption("Moss Brown");
		addOption("Bison Brown");
		addOption("Woodbeach Brown");
		addOption("Beachwood Brown");
		addOption("Straw Brown");
		addOption("Sandy Brown");
		addOption("Bleached Brown");
		addOption("Cream");
		addOption("Util Light Brown");
		addOption("Ice White");
		addOption("Frosty White");
		addOption("Worn Honey Beige");
		addOption("Worn Brown");
		addOption("Dark Brown");
		addOption("Worn Straw Beige");
		addOption("Brushed Steel");
		addOption("Chrome");
		addOption("Worn Off-White");
		addOption("Util Off-White");
		addOption("Worn Orange");
		addOption("Worn Light Orange");
		addOption("Pea Green");
		addOption("Worn Taxi Yellow");
		addOption("Police Blue");
		addOption("Worn Orange");
		addOption("Ice White");
		addOption("Worn White");
		addOption("Worn Olive Army Green");
		addOption("Pure White");
		addOption("Hot Pink");
		addOption("Salmon Pink");
		addOption("Pfister Pink");
		addOption("Flourescent Blue");
		addOption("Midnight Blue");
		addOption("Midnight Purple");
		addOption("Wine Red");
		addOption("Hunter Green");
		addOption("Bright Purple");
		addOption("Midnight Purple");
		addOption("Carbon Black");
		addOption("Metallic Lava Red");
		addOption("Olive Green");
		addOption("Matte Olive Drab");
		addOption("Dark Earth");
		addOption("Desert Tan");
		addOption("Matte Foilage Green");
		addOption("Default Alloy");
		addOption("Epsilon Blue");
		addOption("Secret Gold");
		int VehIDColours = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		switch (getOption())
		{
		case 1: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 000, 000); break;
		case 2: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 001, 001); break;
		case 3: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 002, 002); break;
		case 4: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 003, 003); break;//dark steel   
		case 5: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 004, 004); break;//silver    
		case 6: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 005, 005); break;//bluish silver   
		case 7: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 006, 006); break; //rolled silver  
		case 8: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 007, 007); break; //shadow silver  
		case 9: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 010, 010); break;//cast iron silver
		case 10: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 011, 011); break;//anthracite black 
		case 11: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 012, 012); break;//matte black     
		case 12: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 013, 013); break;//matte grey 
		case 13: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 014, 014); break;//light grey 
		case 14: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 015, 015); break;//util black    
		case 15: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 016, 016); break;//util black poly 
		case 16: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 017, 017); break;//util dark silver   
		case 17: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 020, 020); break;//util shadow silver  
		case 18: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 021, 021); break;//worn black   
		case 19: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 022, 022); break;//worn graphite 
		case 20: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 023, 023); break;//worn silver grey
		case 21: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 024, 024); break;//worn silver 
		case 22: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 025, 025); break; //worn blue silver   
		case 23: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 026, 026); break; //worn shadow silver
		case 24: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 027, 027); break;//red   
		case 25: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 030, 030); break; //blaze red
		case 26: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 031, 031); break;//grace red 
		case 27: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 032, 032); break;//garnet red 
		case 28: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 033, 033); break;//sunset red
		case 29: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 034, 034); break;//cabernet red
		case 30: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 035, 035); break;//candy red 
		case 31: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 036, 036); break;//sunrise orange
		case 32: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 037, 037); break; // gold  
		case 33: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 040, 040); break;// dark red
		case 34: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 041, 041); break;//matte orange  
		case 35: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 042, 042); break;// yellow    
		case 36: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 043, 043); break;//util red       
		case 37: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 044, 044); break;// util bright red   
		case 38: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 045, 045); break;//util garnet red
		case 39: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 046, 046); break;//warn red  
		case 40: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 047, 047); break;//worn golden red  
		case 41: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 050, 050); break;//metallic racing green 
		case 42: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 051, 051); break;//sea green  
		case 43: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 052, 052); break;//olive green 
		case 44: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 053, 053); break;//bright green
		case 45: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 054, 054); break;//matallic gasoline green
		case 46: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 055, 055); break; //matte lime green
		case 47: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 056, 056); break;//dark green
		case 48: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 057, 057); break;//worn green
		case 49: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 060, 060); break; //metallic dark blue
		case 50: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 061, 061); break;//galaxy blue
		case 51: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 062, 062); break;// dark blue
		case 52: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 063, 063); break;// saxon blue               
		case 53: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 064, 064); break;//blue
		case 54: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 065, 065); break;//mariner blue
		case 55: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 066, 066); break;// harbour blue
		case 56: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 067, 067); break;//diamond blue 
		case 57: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 070, 070); break;//ultra blue 
		case 58: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 071, 071); break;//schafter purpler
		case 59: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 072, 072); break;//metallic ultra blue
		case 60: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 073, 073); break;//racing blue
		case 61: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 074, 074); break;//light blue  
		case 62: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 075, 075); break;//util midnight blue 
		case 63: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 076, 076); break;//util blue
		case 64: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 077, 077); break;//util sea foam blue  
		case 65: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 100, 100); break;//moss brown  
		case 66: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 101, 101); break;//bison brown
		case 67: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 102, 102); break; //woodbeech brown
		case 68: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 103, 103); break;//beechwood brown
		case 69: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 104, 104); break;//straw brown
		case 70: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 105, 105); break;//sandy brown 
		case 71: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 106, 106); break; // bleached brown
		case 72: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 107, 107); break; // cream
		case 73: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 110, 110); break; //util light brown
		case 74: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 111, 111); break; //ice white
		case 75: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 112, 112); break;//frost white
		case 76: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 113, 113); break;//worn honey beige
		case 77: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 114, 114); break;//worn brown
		case 78: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 115, 115); break;//dark brown
		case 79: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 116, 116); break;//worn straw beige
		case 80: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 117, 117); break;//brushed steel
		case 81: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 120, 120); break;//chrome
		case 82: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 121, 121); break; //worn off-white
		case 83: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 122, 122); break;//util off-white
		case 84: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 123, 123); break;//worn orange
		case 85: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 124, 124); break;//worn light orange
		case 86: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 125, 125); break;//pea green
		case 87: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 126, 126); break; //worn taxi yellow
		case 88: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 127, 127); break;//police blue
		case 89: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 130, 130); break; //worn orange
		case 90: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 131, 131); break;//ice white
		case 91: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 132, 132); break;//worn white
		case 92: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 133, 133); break;//worn olive army green
		case 93: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 134, 134); break;//pure white
		case 94: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 135, 135); break;//hot pink
		case 95: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 136, 136); break;//salmon pink
		case 96: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 137, 137); break;//pfister pink
		case 97: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 140, 140); break; //flourescent blue
		case 98: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 141, 141); break;//midnight blue
		case 99: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 142, 142); break;//midnight purple
		case 100: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 143, 143); break; //wine red
		case 101: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 144, 144); break;//hunter green
		case 102: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 145, 145); break; //bright purple
		case 103: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 146, 146); break;//midnight purple
		case 104: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 147, 147); break; //carbon black
		case 105: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 150, 150); break; //metallic lava red
		case 106: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 151, 151); break;//olive green
		case 107: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 152, 152); break; //matte olive drab
		case 108: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 153, 153); break; //dark earth
		case 109: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 154, 154); break;//desert tan
		case 110: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 155, 155); break; //matte foilage green
		case 111: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 156, 156); break;//dafault allloy
		case 112: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 157, 157); break; //epsilon blue
		case 113: VEHICLE::SET_VEHICLE_MOD_KIT(VehIDColours, 0); VEHICLE::SET_VEHICLE_COLOURS(VehIDColours, 160, 160); break; //secret gold
		}
		break;
		Vehicle veh;
		int getOptionint();
		{
			return currentOption;
		}
#pragma endregion 
#pragma region veh colocur
	case ModdedColor:
		subTitle("VEHICLE COLOURS MODDED");
		addOption("Apply Pearl Color");
		addOption("Apply Chrome");
		addOption("Apply Gold");
		addOption("Apply Aluminum");
		addOption("Apply Black Steel");
		addOption("Apply Epsilon Blue"); //157
		addOption("Matte Purple Blue Pearl");
		int VEHICLE = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		switch (getOption())
		{
		case 1: VEHICLE::SET_VEHICLE_EXTRA_COLOURS(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), Pearlescant, RimColor); break; //RimColor
		case 2: VEHICLE::SET_VEHICLE_MOD_KIT(VEHICLE, 0); VEHICLE::SET_VEHICLE_COLOURS(VEHICLE, 120, 120); drawNotification("Color: ~b~Chrome"); break;
		case 3: VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(VEHICLE); VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(VEHICLE); VEHICLE::SET_VEHICLE_MOD_KIT(VEHICLE, 0); VEHICLE::SET_VEHICLE_COLOURS(VEHICLE, 37, 37); drawNotification("Color: ~b~Gold"); break;
		case 4: VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(VEHICLE); VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(VEHICLE); VEHICLE::SET_VEHICLE_MOD_KIT(VEHICLE, 0); VEHICLE::SET_VEHICLE_COLOURS(VEHICLE, 119, 119); drawNotification("Color: ~b~Aluminum"); break;
		case 5: VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(VEHICLE); VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(VEHICLE); VEHICLE::SET_VEHICLE_MOD_KIT(VEHICLE, 0); VEHICLE::SET_VEHICLE_COLOURS(VEHICLE, 118, 118); drawNotification("Color: ~b~Black Steel"); break;
		case 6: VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(VEHICLE); VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(VEHICLE); VEHICLE::SET_VEHICLE_MOD_KIT(VEHICLE, 0); VEHICLE::SET_VEHICLE_COLOURS(VEHICLE, 157, 157); drawNotification("Color: ~b~Epsilon Blue"); break;
		case 7: VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(VEHICLE);
			VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(VEHICLE);
			VEHICLE::SET_VEHICLE_MOD_KIT(VEHICLE, 0);
			VEHICLE::SET_VEHICLE_COLOURS(VEHICLE, 148, 148);
			VEHICLE::SET_VEHICLE_EXTRA_COLOURS(VEHICLE, 140, 0);
			drawNotification("Color: ~b~Matte Purple Blue"); break;
		}
		break;//
#pragma endregion
#pragma region LSC
	case LSC:
		subTitle("LOS SANTOS CUSTOMS");
		addIntOption("Armor", &ArmorPart, 0, 5, true);
		addIntOption("Engine", &EnginePart, 0, 5, true);
		addIntOption("Brakes", &BrakesPart, 0, 5, true);
		addIntOption("Spoilers", &SpoilersPart, 0, 7, true);
		addIntOption("Side Skirt", &SkirtsPart, 0, 5, true);
		addIntOption("Suspension", &SuspensionPart, 0, 5, true);
		addIntOption("Transmission", &TransmissionPart, 0, 5, true);
		addIntOption("Front Bumper", &FrontBumper, 0, 5, true);
		addIntOption("Rear Bumper", &RearBumper, 0, 5, true);
		addIntOption("Hood", &Hood, 0, 4, true);
		addIntOption("Exhaust", &Exhaust, 0, 6, true);
		addIntOption("Grill", &Grill, 0, 3, true);
		addIntOption("Change Plate Type", &platetype, 0, 6, true);
		addSubmenuOption("Vehicle Colour", vehcolour);
		addSubmenuOption("Custom RGB", vehcustomrgb);
		addSubmenuOption("Color Modded Vehicle", ModdedColor);// NÃO ADICIONADO AINDA
		addOption("Max Upgrades");
		addIntOption("Engine Multiplier", &MultiplyEngine, 0, 100, true);
		addIntOption("Torque Multiplier", &MultiplyTorque, 0, 100, true);
		int VehIDLSC = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		switch (getOption())
		{
		case 1: VEHICLE::SET_VEHICLE_MOD_KIT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false), 0); VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false), 16, ArmorPart, 0);
		case 2: VEHICLE::SET_VEHICLE_MOD_KIT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false), 0); VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false), 11, EnginePart, 0);
		case 3: VEHICLE::SET_VEHICLE_MOD_KIT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false), 0); VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false), 12, BrakesPart, 0);
		case 4: VEHICLE::SET_VEHICLE_MOD_KIT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false), 0); VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false), 0, SpoilersPart, 0);
		case 5: VEHICLE::SET_VEHICLE_MOD_KIT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false), 0); VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false), 3, SkirtsPart, 0);
		case 6: VEHICLE::SET_VEHICLE_MOD_KIT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false), 0); VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false), 15, SuspensionPart, 0);
		case 7: VEHICLE::SET_VEHICLE_MOD_KIT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false), 0); VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false), 13, TransmissionPart, 0);
		case 8: VEHICLE::SET_VEHICLE_MOD_KIT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false), 0); VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false), 1, FrontBumper, 0);
		case 9: VEHICLE::SET_VEHICLE_MOD_KIT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false), 0); VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false), 2, RearBumper, 0);
		case 10: VEHICLE::SET_VEHICLE_MOD_KIT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false), 0); VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false), 7, Hood, 0);
		case 11: VEHICLE::SET_VEHICLE_MOD_KIT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false), 0); VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false), 4, Exhaust, 0);
		case 12: VEHICLE::SET_VEHICLE_MOD_KIT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false), 0); VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false), 6, Grill, 0);
		case 13: changeplate(platetype); break;
		case 14: break;
		case 15: break;
		case 16: break;
		case 17: NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(VehIDLSC);
			if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(VehIDLSC))
			{
				MaxUpgradesMe(VehIDLSC, true);
			}
			break;
		case 18: VEHICLE::_SET_VEHICLE_ENGINE_POWER_MULTIPLIER(VehIDLSC, MultiplyEngine); break;
		case 19: VEHICLE::_SET_VEHICLE_ENGINE_TORQUE_MULTIPLIER(VehIDLSC, MultiplyTorque); break;
		}
		/*char buf[30];
		snprintf(buf, sizeof(buf), "%i", ArmorPart);
		drawText2(buf, bannerTextFont2, menuXCoord1014infoforhealth, 0.1660, 0.40, 0.40f, bannerTextRed, bannerTextGreen, bannerTextBlue, bannerTextOpacity, true);*/
		break;
#pragma endregion 
#pragma region VehicleBindsSelf
	case VehicleBindsSelf:
		subTitle("VEHICLE BINDS");
		addBoolOption("Boost (R3)", r3boost);
		addBoolOption("Back Boost (L3)", l2bboost);
		addBoolOption("Insta Stop (X)", l3break);
		addBoolOption("Fix (D-Left)", leftfix);
		switch (getOption())
		{
		case 1: r3boost = !r3boost; break;
		case 2: l2bboost = !l2bboost; break;
		case 3: l3break = !l3break; break;
		case 4: leftfix = !leftfix; break;
		}
		break;
#pragma endregion  
#pragma region vehcustomrgb
	case vehcustomrgb:
		subTitle("CUSTOM RGB");
		addIntOption2("Red", &vehr, 0, 255);
		addIntOption2("Green", &vehg, 0, 255);
		addIntOption2("Blue", &vehb, 0, 255);
		addOption("Set Custom Color");
		switch (getOption())
		{
		case 4: PaintCustom(vehr, vehg, vehb); break; // p rim
		}
		break;
#pragma endregion
#pragma region neons
	case neons:
		subTitle("NEONS");
		addBoolOption("Activate", Neons_);
		addNeonsOption("Blue", 0, 43, 255);
		addNeonsOption("Red", 255, 0, 0);
		addNeonsOption("Green", 0, 255, 43);
		addNeonsOption("Pink", 255, 0, 255);
		addNeonsOption("Orange", 255, 128, 0);
		addNeonsOption("Purple", 196, 0, 255);
		addNeonsOption("Cyan", 0, 255, 255);
		addNeonsOption("Black", 0, 0, 0);
		addNeonsOption("Gold", 150, 150, 0);
		addNeonsOption("Grey", 150, 150, 150);
		addBoolOption("Flashing", LoopNeons_);
		switch (getOption())
		{
		case 1: Neons_ = !Neons_; break;
		case 12: LoopNeons_ = !LoopNeons_; break;
		}
		break;
		bool FunGunBoolean = false;
#pragma endregion
#pragma region Weapon Options
	case Weapon_Options1:
		subTitle("Weapon Options");
		addBoolOption("Teleport Gun", _test);
		addOption("Unlimited Ammo");
		addBoolOption("MoneyBag Gun", BulletBags);
		addBoolOption("Predator Gun", predator);
		addBoolOption("Fire Ammo", firegun);
		addBoolOption("Power Gun", powergun);
		addBoolOption("Rainbow Camo", rainbow);
		addBoolOption("Hash Gun", hashgun);
		addBoolOption("1 Shot 1 Kill", oneshotndisable);
		addOption("All Weapons");
		addBoolOption("Explosive Bullets", ExplosiveBullets);
		addBoolOption("Shoot Cars", shhotcars_);
		addCharBOOLSwap("Rocket Gun", WeaponsMenu, &WeapVar, 0, 5, RocketGun);
		addBoolOption("Fireball Gun", Firegun, " ");
		addBoolOption("Delete Entity Gun", featureDeleteGun);
		addBoolOption("Apply Froce Gun", applyforceg);
		addBoolOption("Paint Vehicle Gun", PaintVehGunBool);
		switch (getOption())
		{
		case 1: _test = !_test; break;
		case 2: for (int i = 0; i < 58; i++)
		{
			WEAPON::SET_PED_INFINITE_AMMO(PLAYER::PLAYER_PED_ID(), true, WepArray[i]);
			WEAPON::SET_PED_INFINITE_AMMO_CLIP(PLAYER::PLAYER_PED_ID(), true);
			drawNotification("You All Weapons Infinite");
		} break;
		case 3: BulletBags = !BulletBags; break;
		case 4: predator = !predator; break;
		case 5: firegun = !firegun; break;
		case 6: powergun = !powergun;
			drawNotification("Zoom in to activate the Power Gun. Move L3 up or Down to slow down");  break;
		case 7: rainbow = !rainbow; break;
		case 8: hashgun = !hashgun; break;
		case 9: oneshotndisable = !oneshotndisable; break;
		case 10: for (int i = 0; i < 59; i++)
		{
			int Ammo = -1;
			WEAPON::GET_MAX_AMMO(PLAYER::PLAYER_PED_ID(), WepArray[i], &Ammo);
			WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), WepArray[i], Ammo, false, true);
		}
				 break;
		case 11:  ExplosiveBullets = !ExplosiveBullets; break;
		case 12: shhotcars_ = !shhotcars_; break;
		case 13:  RocketGun = !RocketGun; WeaponSHoot = "VEHICLE_WEAPON_PLAYER_LASER"; break;
	    case 14: Firegun = !Firegun; break;
		case 15: featureDeleteGun = !featureDeleteGun; break;
		case 16: applyforceg = !applyforceg; break;
		case 17: PaintVehGunBool = !PaintVehGunBool; break;
		}
		break;
#pragma endregion
#pragma region Change Model
	case Change_Model:
		subTitle("Model Options");
		addOption("~h~Model Changer Black");
		addOption("Man Character Online", "");
		addOption("Alien", "");
		addOption("Impotent Rage", "");
		addOption("Topless Girl", "");
		addOption("Black Ops Soldier", "");
		addOption("Babyd", "");
		addOption("Cop", "");
		addOption("Jesus", "");
		addOption("Black Mafia", "");
		addOption("Pogo Monkey", "");
		addOption("Gay Male", "");
		addOption("Bouncer", "");
		addOption("Fat + White", "");
		addOption("Indian", "");
		addOption("Business Man", "");
		addOption("Paparazzi", "");
		addOption("Skater", "");
		addOption("Hacker Shit", "");
		addOption("Gunman Gun", "");
		addOption("Tanisha", "");
		switch (getOption())
		{
		case 1: changeAppearance("TORSO", 0, 1);
			changeAppearance("MASK", 1, 1);//mascara
			changeAppearance("HATS", 1, 1);//capacete
			changeAppearance("FACE", 0, 1);//face
			changeAppearance("HAIR", 1, 2);
			changeAppearance("GLASSES", 1, 1);//oculos
			changeAppearance("LEGS", 0, 1);//calças
			changeAppearance("SHOES", 0, 1);//sapatos
			changeAppearance("SPECIAL1", 0, 1);//das algemas
			changeAppearance("SPECIAL2", 0, 1);//da policia
			changeAppearance("SPECIAL3", 0, 1);//coletes
			changeAppearance("TEXTURES", 0, 1);
			changeAppearance("TORSO2", 0, 1);//blusas
			changeAppearance("HANDS", 0, 1);//muchila
			break;
		case 2: changeModel("mp_m_freemode_01"); break; break;//male
		case 3: changeModel("s_m_m_movalien_01"); break;
		case 4: changeModel("u_m_y_imporage");  break;
		case 5: changeModel("a_f_y_topless_01");  break;
		case 6: changeModel("s_m_y_blackops_01");  break;
		case 7: changeModel("u_m_y_babyd");  break;
		case 8: changeModel("s_m_y_cop_01");  break;
		case 9: changeModel("u_m_m_jesus_01");  break;
		case 10: changeModel("a_m_m_og_boss_01");  break;
		case 11: changeModel("u_m_y_pogo_01");  break;
		case 12: changeModel("a_m_y_gay_01");  break;
		case 13: changeModel("s_m_m_bouncer_01");  break;
		case 14: changeModel("a_f_m_fatwhite_01");  break;
		case 15: changeModel("a_f_y_indian_01");  break;
		case 16: changeModel("a_m_m_business_01");  break;
		case 17: changeModel("a_m_m_paparazzi_01");  break;
		case 18: changeModel("a_m_m_skater_01");  break;
		case 19: changeModel("hc_hacker");  break;//ig_tanisha
		case 20: changeModel("hc_gunman");  break;
		case 21: changeModel("ig_tanisha");  break;
		} break;
#pragma endregion
#pragma region Animations
	case Animations:
		subTitle("Animations");//spritemenu
		spritemenu("Player Scenarios", " ");
		spritemenu("Player Scenarios 2", " ");
		spritemenu("Player Animations", " ");
		spritemenu("Walk Animations", " ");
		switch (getOption())
		{
		case 1: changeSubmenu(Scenarios); break;
		case 2: changeSubmenu(Scenarios2); break;
		case 3: changeSubmenu(animationss); break;
		case 4: changeSubmenu(walktypes); break;
		}
		break;
#pragma endregion
#pragma region walktypes
	case walktypes:
		subTitle("WALK ANIMATIONS");
		addOption("Default Male");
		addOption("Default Female");
		addOption("Injured");
		addOption("Drunk");
		addOption("Over Weight");
		addOption("Running");
		addOption("Business Man");
		addOption("Hiking");
		switch (getOption())
		{
		case 1: ChangeWalkingType("move_m@generic"); break;
		case 2: ChangeWalkingType("move_f@generic"); break;
		case 3: ChangeWalkingType("move_m@injured"); break;
		case 4: ChangeWalkingType("move_m@drunk@verydrunk"); break;
		case 5: ChangeWalkingType("move_m@fat@a"); break;
		case 6: ChangeWalkingType("move_f@film_reel"); break;
		case 7: ChangeWalkingType("move_m@business@a"); break;
		case 8: ChangeWalkingType("move_m@hiking"); break;
		}
		break;
#pragma endregion
#pragma region animation sub
	case animationss:
		subTitle("PLAYER ANIMATIONS");
		addOption("Stop Player Animations");
		addOption("Celebrate");
		addOption("Pole Dance");
		addOption("Push-Ups");
		addOption("Suicide");
		addOption("Stripper Dance");
		addOption("Sit-Ups");
		addOption("Electrocution");
		addOption("Monkey Dance");
		addOption("Air Guitar");
		addOption("Fishing");
		addOption("Dance");
		addOption("Sex Recieve");
		addOption("Sex Give");
		addOption("Freak Out");
		addOption("Poo");
		addOption("Shower");
		switch (getOption())
		{
		case 1: AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::PLAYER_PED_ID()); break;
		case 2: doAnimation("rcmfanatic1celebrate", "celebrate"); break;
		case 3: doAnimation("mini@strip_club@pole_dance@pole_dance1", "pd_dance_01"); break;
		case 4: doAnimation("amb@world_human_push_ups@male@base", "base"); break;
		case 5: doAnimation("mp_suicide", "pistol"); break;
		case 6: doAnimation("mini@strip_club@private_dance@part1", "priv_dance_p1"); break;
		case 7: doAnimation("amb@world_human_sit_ups@male@base", "base"); break;
		case 8: doAnimation("ragdoll@human", "electrocute"); break;
		case 9: doAnimation("missfbi5ig_30monkeys", "monkey_a_freakout_loop"); break;
		case 10: doAnimation("switch@trevor@guitar_beatdown", "001370_02_trvs_8_guitar_beatdown_idle_busker"); break;
		case 11: doAnimation("amb@world_human_stand_fishing@base", "base"); break;
		case 12: doAnimation("misschinese2_crystalmazemcs1_cs", "dance_loop_tao"); break;
		case 13: doAnimation("rcmpaparazzo_2", "shag_loop_poppy"); break;
		case 14: doAnimation("rcmpaparazzo_2", "shag_loop_a"); break;
		case 15: doAnimation("missfbi5ig_30monkeys", "monkey_b_freakout_loop"); break;
		case 16: doAnimation("missfbi3ig_0", "shit_loop_trev"); break;
		case 17: doAnimation("mp_safehouseshower@male@", "male_shower_idle_b"); break;
		}
		break;
#pragma endregion
#pragma region animation Scenarios
	case Scenarios:
		subTitle("PLAYER SCENARIOS");
		addOption("Stop Scenarios");
		addOption("Play Music");
		addOption("Paparazzi");
		addOption("Binoculars");
		addOption("Drink");
		addOption("Play Golf");
		addOption("Lift Weights");
		addOption("Smoke Pot");
		addOption("Handyman");
		addOption("Yoga");
		addOption("Flex Muscles");
		addOption("Mechanic");
		addOption("Welding");
		addOption("Cheering");
		addOption("Hold Clipboard");
		addOption("Drill");
		addOption("Deal Drugs");
		addOption("Gardener Leaf Blower");
		addOption("Gardener Plant");
		addOption("Guard Patrol");
		addOption("Guard Stand");
		addOption("Human Statue");
		addOption("Maid Clean");
		addOption("Partying");
		addOption("Picnic");
		addOption("Prostitute Low Class");
		addOption("Prostitute High Class");
		addOption("Shine Torch");
		addOption("Sunbathe");
		addOption("Sunbathe Back");
		addOption("Superhero");
		addOption("Swimming");
		addOption("Play Tennis");
		addOption("Tourist Holding Map");
		addOption("BBQ");
		switch (getOption())
		{
		case 1: AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::PLAYER_PED_ID()); break;
		case 2: AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_MUSICIAN", 0, 1); break;
		case 3: AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_PAPARAZZI", 0, 1); break;
		case 4: AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_BINOCULARS", 0, 1); break;
		case 5: AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_DRINKING", 0, 1); break;
		case 6: AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_GOLF_PLAYER", 0, 1); break;
		case 7: AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_MUSCLE_FREE_WEIGHTS", 0, 1); break;
		case 8: AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_SMOKING_POT", 0, 1); break;
		case 9: AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_HAMMERING", 0, 1); break;
		case 10: AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_YOGA", 0, 1); break;
		case 11: AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_MUSCLE_FLEX", 0, 1); break;
		case 12: AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_VEHICLE_MECHANIC", 0, 1); break;
		case 13: AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_WELDING", 0, 1); break;
		case 14: AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_CHEERING", 0, 1); break;
		case 15: AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_CLIPBOARD", 0, 1); break;
		case 16: AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_CONST_DRILL", 0, 1); break;
		case 17: AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_DRUG_DEALER", 0, 1); break;
		case 18: AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_GARDENER_LEAF_BLOWER", 0, 1); break;
		case 19: AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_GARDENER_PLANT", 0, 1); break;
		case 20: AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_GUARD_PATROL", 0, 1); break;
		case 21: AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_GUARD_STAND", 0, 1); break;
		case 22: AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_HUMAN_STATUE", 0, 1); break;
		case 23: AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_MAID_CLEAN", 0, 1); break;
		case 24: AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_PARTYING", 0, 1); break;
		case 25: AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_PICNIC", 0, 1); break;
		case 26: AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_PROSTITUTE_LOW_CLASS", 0, 1); break;
		case 27: AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_PROSTITUTE_HIGH_CLASS", 0, 1); break;
		case 28: AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_SECURITY_SHINE_TORCH", 0, 1); break;
		case 29: AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_SUNBATHE", 0, 1); break;
		case 30: AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_SUNBATHE_BACK", 0, 1); break;
		case 31: AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_SUPERHERO", 0, 1); break;
		case 32: AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_SWIMMING", 0, 1); break;
		case 33: AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_TENNIS_PLAYER", 0, 1); break;
		case 34: AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_TOURIST_MAP", 0, 1); break;
		case 35: AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "PROP_HUMAN_BBQ", 0, 1); break;
		}
		break;
#pragma endregion
#pragma region animation Scenarios 2
	case Scenarios2:
		subTitle("PLAYER SCENARIOS 2");
		addOption("Stop Player Scenarios");
		addOption("Seat: Armchair");
		addOption("Seat: Bar");
		addOption("Seat: Bench");
		addOption("Seat: Bus Stop");
		addOption("Seat: Chair");
		addOption("Seat: Computer");
		addOption("Seat: Deckchair");
		addOption("Seat: Sewing");
		addOption("Seat: Sunlounger");
		switch (getOption())
		{
		case 1: AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::PLAYER_PED_ID()); break;
		case 2: AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "PROP_HUMAN_SEAT_ARMCHAIR", 0, 1); break;
		case 3: AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "PROP_HUMAN_SEAT_BAR", 0, 1); break;
		case 4: AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "PROP_HUMAN_SEAT_BENCH", 0, 1); break;
		case 5: AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "PROP_HUMAN_SEAT_BUS_STOP_WAIT", 0, 1); break;
		case 6: AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "PROP_HUMAN_SEAT_CHAIR", 0, 1); break;
		case 7: AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "PROP_HUMAN_SEAT_COMPUTER", 0, 1); break;
		case 8: AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "PROP_HUMAN_SEAT_DECKCHAIR", 0, 1); break;
		case 9: AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "PROP_HUMAN_SEAT_SEWING", 0, 1); break;
		case 10: AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "PROP_HUMAN_SEAT_SUNLOUNGER", 0, 1); break;
		}
		break;
#pragma endregion
#pragma region environment
	case Weather_Options:
		subTitle("WORD OPTIONS");
		addBoolOption("Freeze Time", FreezeTime);
		addOption("Clear");
		addOption("Extra Sunny");
		addOption("Light Snow");
		addOption("Blizzard");
		addOption("Fog");
		addOption("Neutral");
		addOption("Cloudy");
		addOption("Overcast");
		addOption("Smog");
		addOption("Thunder");
		addOption("Rain");
		addOption("Snow");
		addBoolOption("Black Out", Black_Out);
		addIntOption("Change Time", &hours, 0, 12, true);
		addOption("Set Time To Day");
		addOption("Set Time To Night");
		switch (getOption())
		{
		case 1: FreezeTime = !FreezeTime; break;
		case 2: GAMEPLAY::SET_OVERRIDE_WEATHER("CLEAR"); break;
		case 3: GAMEPLAY::SET_OVERRIDE_WEATHER("EXTRASUNNY"); break;
		case 4: GAMEPLAY::SET_OVERRIDE_WEATHER("SNOWLIGHT"); break;
		case 5: GAMEPLAY::SET_OVERRIDE_WEATHER("BLIZZARD"); break;
		case 6: GAMEPLAY::SET_OVERRIDE_WEATHER("FOGGY"); break;
		case 7: GAMEPLAY::SET_OVERRIDE_WEATHER("NEUTRAL"); break;
		case 8: GAMEPLAY::SET_OVERRIDE_WEATHER("CLOUDS"); break;
		case 9: GAMEPLAY::SET_OVERRIDE_WEATHER("OVERCAST"); break;
		case 10: GAMEPLAY::SET_OVERRIDE_WEATHER("SMOG"); break;
		case 11: GAMEPLAY::SET_OVERRIDE_WEATHER("THUNDER"); break;
		case 12: GAMEPLAY::SET_OVERRIDE_WEATHER("RAIN"); break;
		case 13: GAMEPLAY::SET_OVERRIDE_WEATHER("SNOW"); break;
		case 14: Black_Out = !Black_Out; NETWORK::NETWORK_OVERRIDE_CLOCK_TIME(0, 0, 0); break;
		case 15: NETWORK::NETWORK_OVERRIDE_CLOCK_TIME(hours, 1, 0); break;
		case 16: NETWORK::NETWORK_OVERRIDE_CLOCK_TIME(12, 0, 0); break;
		case 17: NETWORK::NETWORK_OVERRIDE_CLOCK_TIME(0, 0, 0); break;
		}
		break;
#pragma endregion
#pragma region Spawn object
	case SpawnObj:
		subTitle("Spawn Object");
		spritemenu("~h~Object Manager", " ");
		addOption("xmas ext", " ");
		addOption("raspberry 01", " ");
		addOption("med jet 1", " ");
		addOption("greenscreen 1", " ");
		addOption("UFO", " ");
		addOption("Windmill", " ");
		addOption("Huge Barge", " ");
		addOption("e cola can", " ");
		addOption("Huge Ball", " ");
		addOption("Coca Cola Big", " ");
		addOption("Crashed Tram", " ");
		addOption("orange tree", " ");
		addOption("Spinning", " ");
		addOption("Radar", " ");
		addOption("Tug Boat", " ");
		addOption("Cable Car", " ");
		addOption("Soccer Ball", " ");
		addOption("Large Whale Bones", " ");
		addOption("Roller Car", " ");
		addOption("Ferris Wheel", " ");
		addOption("Bank Safe", " ");
		addOption("Oil Slick", " ");
		addOption("ATM Machine", " ");
		addOption("Crane", " ");
		addOption("Biggest Jet", " ");
		switch (getOption())
		{
		case 1: changeSubmenu(ObjManager); break;
		case 2: spawnobject("prop_xmas_ext"); break;
		case 3: spawnobject("prop_mr_raspberry_01"); break;
		case 4: spawnobject("prop_med_jet_01"); break;
		case 5: spawnobject("prop_ld_greenscreen_01"); break;
		case 6: spawnobject("p_spinning_anus_s"); break;
		case 7: spawnobject("prop_windmill_01"); break;
		case 8: spawnobject("prop_lev_des_barge_02"); break;
		case 9: spawnobject("prop_ecola_can"); break;
		case 10: spawnobject("prop_juicestand"); break;
		case 11: spawnobject("prop_inflatearch_01"); break;//
		case 12: spawnobject("p_tram_crash_s"); break;
		case 13: spawnobject("prop_veg_crop_orange"); break;
		case 14: spawnobject("prop_air_bigradar"); break;
		case 15: spawnobject("hei_prop_carrier_radar_1"); break;
		case 16: spawnobject("hei_prop_heist_tug"); break;
		case 17: spawnobject("p_cablecar_s"); break;
		case 18: spawnobject("p_ld_soc_ball_01"); break;
		case 19: spawnobject("p_seabed_whalebones"); break;
		case 20: spawnobject("prop_roller_car_01"); break;
		case 21: spawnobject("prop_Ld_ferris_wheel"); break;
		case 22: spawnobject("p_v_43_safe_s"); break;
		case 23: spawnobject("p_oil_slick_01"); break;
		case 24: spawnobject("prop_atm_01"); break;
		case 25: spawnobject("PROP_DOCK_CRANE_02"); break;
		case 26: spawnobject("PROP_MED_JET_01"); break;
		} break;

		bool featureDeleteObjects = false;
		bool featureGetNearEntities = false;
		bool featureRemoveOnME = false;
#pragma endregion
#pragma region Modder Protection
	case ModdedProtectt:
		subTitle("Modder Protection");
		addBoolOption("Ram Protection", RamProtect, "Vehicles that ram into you will be exploded");
		addBoolOption("Aim Protection", Aimprotect, "Any players that aim at you will be exploded");//
		addBoolOption("Explode Killer", instantrevenge, "Any player that kills you will be killed immediately");
		addBoolOption("Non Host Kick Protect", NonHostKick_Protection);
		addBoolOption("Vote Kick Protect", Votekickprotect);
		addBoolOption("remote script leave Protect", remotescriptleave);
		addBoolOption("Particle fx Protect", antiParticleFXCrash);
		addBoolOption("Ant Blame Protect", AntblamePlayer);
		addBoolOption("Ant Cargo Plane Protect", Protection123);//
		addBoolOption("Request Control Protect", RequestControl);
		switch (getOption())
		{
		case 1: RamProtect = !RamProtect; break;
		case 2: Aimprotect = !Aimprotect; break;
		case 3: instantrevenge = !instantrevenge; break;
		case 4: NonHostKick_Protection = !NonHostKick_Protection; break;
		case 5:  Votekickprotect = !Votekickprotect; break;
		case 6: remotescriptleave = !remotescriptleave; break;
		case 7: antiParticleFXCrash = !antiParticleFXCrash; break;
		case 8: AntblamePlayer = !AntblamePlayer; break;
		case 9: Protection123 = !Protection123; break;
		case 10: RequestControl = !RequestControl; break;
		}
		break;
#pragma endregion
#pragma region ObjManager
	case ObjManager:
		subTitle("Object Manager");
		addBoolOption("Get Shot Entity", Get_Shot_Entity_Object, " ");//3
		addOption("+ X Axis", " ");//4
		addOption("- X Axis", " ");//5
		addOption("+ Y Axis", " ");
		addOption("- Y Axis", " ");
		addOption("+ Z Axis", " ");
		addOption("- Z Axis", " ");
		addFloatOption("Pitch", &ObjectCode_Pitch, -500, 500, true, 1,1.0);//8
		addFloatOption("Roll", &ObjectCode_Roll, -500, 500, true, 1, 1.0);//9
		addFloatOption("Yaw", &ObjectCode_Yaw, -500, 500, true, 1,1.0);//10
		addOption("Freeze Object", " ");
		addOption("Delete Object", " ");
		Vector3 Coords12 = ENTITY::GET_ENTITY_COORDS(object_Hash, 1);
		switch (getOption())
		{
		case 1:Get_Shot_Entity_Object = !Get_Shot_Entity_Object;
			drawNotification("target and shoot \nthe object to move"); break;
		case 2:
			if (NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(object_Hash) && NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(object_Hash))
			{
				ENTITY::SET_ENTITY_COORDS(object_Hash, Coords12.x + 0.9, Coords12.y, Coords12.z, 0, 1, 0, 1);
			}
			break;
		case 3:
			if (NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(object_Hash) && NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(object_Hash))
			{
				ENTITY::SET_ENTITY_COORDS(object_Hash, Coords12.x - 0.9, Coords12.y, Coords12.z, 0, 1, 0, 1);
			}
			break;
		case 4:
			if (NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(object_Hash) && NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(object_Hash))
			{
				ENTITY::SET_ENTITY_COORDS(object_Hash, Coords12.x, Coords12.y + 0.9, Coords12.z, 0, 1, 0, 1);
			}
			break;
		case 5:
			if (NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(object_Hash) && NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(object_Hash))
			{
				ENTITY::SET_ENTITY_COORDS(object_Hash, Coords12.x, Coords12.y - 0.9, Coords12.z, 0, 1, 0, 1);//cima baixo
			}
			break;
		case 6:
			if (NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(object_Hash) && NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(object_Hash))//rool
			{
				ENTITY::SET_ENTITY_COORDS(object_Hash, Coords12.x, Coords12.y, Coords12.z + 0.5, 0, 1, 0, 1);
			}
			break;
		case 7:
			if (NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(object_Hash) && NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(object_Hash))
			{
				ENTITY::SET_ENTITY_COORDS(object_Hash, Coords12.x, Coords12.y, Coords12.z - 0.5, 0, 1, 0, 1);
			}
			break;
		case 11:
			if (NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(object_Hash) && NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(object_Hash))
			{
				ENTITY::FREEZE_ENTITY_POSITION(object_Hash, 1);
			}
			break;
		case 12:
			if (NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(object_Hash) && NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(object_Hash))
			{
				OBJECT::DELETE_OBJECT(&object_Hash);
				ENTITY::DELETE_ENTITY(&object_Hash);
			}
			break;
		} 
		break;
#pragma endregion
#pragma region
	case OneClickOptions:
		subTitle("Miscelaneous");
		spritemenu("Force Abusive Menu", " ");
		addBoolOption("Reveal Players", revealPeople, " ");
		addBoolOption("Off The Radar", OffTheRadar, " ");
		addBoolOption("First Person View", fPerson, " ");
		addOption("BullShark", " ");
		addBoolOption("Mobile Radio", mobileRadio, " ");
		addBoolOption("Disable Phone", DisablePhone);
		addBoolOption("Remove Mini Map", minimap);
		addBoolOption("Players Talking", ShowTalking);//
		addBoolOption("The Flash", flash_run);
		addIntOption("The Flash Speed Mod", &flashspeedmodifier, 0, 10, true);
		addBoolOption("Power of The Gods", powerofthegods);
		addIntOption("Power of The Gods Mod", &potgmodifier, 0, 10, true);
		spritemenu("Modify Tunables", " ");
		spritemenu("Screen Visions", " ");
		spritemenu("Particle FX", " ");
		addBoolOption("Inner Force", innerforce);
		addBoolOption("Player Markers", lightbeam);
		addBoolOption("Draw Fps Show", Draw_Fps);
		addBoolOption("Box Players Talking", ShowTalking1);
		addOption("Clear Area");
		spritemenu("Ghost Rider", " ");
		addOption("Skate Mode Board Beta");
		addOption("Delete Skate Mode Board");
		spritemenu("Modify Tunables", " ");
		//addFloatOption("Draw Fps X", &Draw_Fps_X, 0, 1, true, 0);//9
		//addFloatOption("Draw Fps Y", &Draw_Fps_Y, 0, 1, true, 0);//9
		switch (getOption())
		{
		case 1: changeSubmenu(Forcepowerrs); break;
		case 2: RevealPlayers();  break;
		case 3: OffTheRadar = !OffTheRadar; break;
		case 4: FirstPerson(); break;
		case 5: PS3::WriteInt32(PS3::ReadInt32(0x1E70394) + 0x24C18, 5); break;
		case 6: toggleMobileRadio(); break;
		case 7: DisablePhone = !DisablePhone; break;
		case 8: minimap = !minimap; break;
		case 9: ShowTalking = !ShowTalking; break;
		case 10: flash_run = !flash_run;
			drawNotification("Remove Weapon From Hand! \nSpam X while holding L2 to use The Flash efficiency.");  break;
		case 11: break;
		case 12: godPower(); break;
		case 13: break;
		case 14: changeSubmenu(tunables); break;
		case 15: changeSubmenu(All_Visions); break;
		case 16: changeSubmenu(particlefx); break;
		case 17:
		{
				innerforce = !innerforce;
				if (innerforce == true)
				{
					drawNotification("Inner Force: ~b~Enabled \nUse ~b~R1~w~ to use");
				}
				else if (innerforce == false)
				{
					drawNotification("Inner Force: ~r~Disabled");
				}
			} break;
		case 18: {
			lightbeam = !lightbeam;
			if (lightbeam == true)
			{
				drawNotification("Players Marker: ~b~Enabled");

			}
			else if (lightbeam == false)
			{
				drawNotification("Players Marker: ~r~Disabled");
			}
		} break;
		case 19: Draw_Fps = !Draw_Fps; true;
		//case 25: break;
		//case 26: break;
		case 20: ShowTalking1 = !ShowTalking1; break;
		case 21: clearArea(); break;
		case 22: changeSubmenu(Betatestrs); break;
		case 23: Hoverboard = true; break;
		case 24: AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::PLAYER_PED_ID());
			ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), true);
			Hover_Board_Delete = true; break;
		case 25: changeSubmenu(Forcepowerrs); break;
		} break;
#pragma endregion
#pragma region outfit changer
	case OutifitEDD:
		subTitle("Outfits Editor");
		spritemenu("Outfits Man", " ");
		spritemenu("Outfits Female", " ");
		switch (getOption())
		{
		case 1: changeSubmenu(OutftsMen); break;
		case 2: changeSubmenu(OutftsWomen); break;
		} break;

#pragma endregion
#pragma region Outfts Men
	case OutftsMen:
		subTitle("Outfits Editor");
		addOption("Modded Brazil Combate");
		addOption("Police Outfit", " ");
		addOption("modded oufit", " ");
		addOption("Penguin Outfit", " ");
		addOption("Splinter Cell", " ");
		addOption("Pilot", " ");
		addOption("Special Ops", " ");
		addOption("Special Ops Heavy", " ");
		addOption("Balla's Gang", " ");
		addOption("THE Elf", " ");
		addOption("THE Thug", " ");
		addOption("THE Santa", " ");
		addOption("THE Snowman", " ");
		addOption("Web Hacker", " ");
		addOption("Xadrez Modded Oufitt", " ");
		addOption("Black Combat", " ");
		addOption("The Strength", " ");
		addOption("Security", " ");
		addOption("The Familes", " ");
		addOption("The Hacker");
		addOption("Rng Death Math");
		addOption("Invisible Ccombate");
		addOption("Special Trash Modded");
		addOption("Modded Outfitts 2");
		addOption("Modded Outfitts 3");
		addOption("New modded Rng");
		addOption("New modded Rng 2");
		addOption("Independence Modded");
		addOption("ultimate rng");
		addOption("ultimate rng 2");
		addOption("Combate day black");
		addOption("Modded GTA Brazil");
		addOption("The Ippple");
		switch (getOption())
		{
		case 1:
			ResetAppearance();
			changeAppearance("TORSO", 17, 0);
			changeAppearance("MASK", 36, 0);//mascara
			changeAppearance("HATS", 40, 3);//capacete
			changeAppearance("HAIR", 0, 0);
			changeAppearance("GLASSES", 0, 0);//oculos
			changeAppearance("LEGS", 33, 0);//calças
			changeAppearance("SHOES", 28, 0);//sapatos
			changeAppearance("SPECIAL1", 11, 0);//das algemas
			changeAppearance("SPECIAL2", 22, 4);//da policia
			changeAppearance("SPECIAL3", 0, 0);//coletes
			changeAppearance("TEXTURES", 0, 0);
			changeAppearance("TORSO2", 22, 0);//blusas
			changeAppearance("HANDS", 41, 0);//muchila
			DoFX("scr_rcbarry2", "scr_clown_appears");
			DoFX("scr_trevor1", "scr_trev1_trailer_boosh");
			drawNotification("Outfit: ~g~Modded Brazil Combate");
			break;
		case 2: //Police Modded
			ResetAppearance();
			changeAppearance("TORSO", 59, 0);
			changeAppearance("HATS", 47, 0);
			changeAppearance("MASK", 36, 0);
			changeAppearance("GLASSES", 2, 0);
			changeAppearance("LEGS", 33, 0);
			changeAppearance("SHOES", 28, 1);
			changeAppearance("SPECIAL1", 41, 0);
			changeAppearance("SPECIAL2", 58, 0);
			changeAppearance("TORSO2", 55, 0);
			changeAppearance("HANDS", 45, 0);
			DoFX("scr_rcbarry2", "scr_clown_appears");
			DoFX("scr_trevor1", "scr_trev1_trailer_boosh");
			drawNotification("Outfit: ~g~Police Modded");
			break;
		case 3://modded Outfit
			ResetAppearance();
			changeAppearance("TORSO", 17, 0);
			changeAppearance("MASK", 29, 0);
			changeAppearance("HATS", 28, 0);
			changeAppearance("HAIR", 0, 0);
			changeAppearance("GLASSES", 0, 1);
			changeAppearance("LEGS", 31, 0);
			changeAppearance("SHOES", 24, 0);
			changeAppearance("SPECIAL", 30, 2);
			changeAppearance("SPECIAL2", 15, 0);
			changeAppearance("TORSO2", 50, 0);
			changeAppearance("HANDS", 0, 0);
			DoFX("scr_rcbarry2", "scr_clown_appears");
			drawNotification("Outfit: ~b~modded Outfit");
			break;
		case 4://Penguin Outfit
			ResetAppearance();
			changeAppearance("TORSO", 0, 0);
			changeAppearance("MASK", 31, 0);
			changeAppearance("HATS", 0, 0);
			changeAppearance("HAIR", 0, 0);
			changeAppearance("GLASSES", 0, 0);
			changeAppearance("LEGS", 32, 0);
			changeAppearance("SHOES", 17, 0);
			changeAppearance("SPECIAL1", 0, 0);
			changeAppearance("SPECIAL2", 57, 0);
			//changeAppearance("SPECIAL3", 0, 0);
			changeAppearance("TEXTURES", 0, 0);
			changeAppearance("TORSO2", 51, 0);
			changeAppearance("HANDS", 0, 0);
			DoFX("scr_rcbarry2", "scr_clown_appears");
			DoFX("scr_trevor1", "scr_trev1_trailer_boosh");
			drawNotification("Outfit: ~b~Penguin Outfit");
			break;
		case 5://Splinter Cell
			ResetAppearance();
			changeAppearance("TORSO", 96, 0);
			changeAppearance("MASK", 57, 0);
			changeAppearance("HATS", 40, 0);
			changeAppearance("HAIR", 23, 0);
			changeAppearance("GLASSES", 0, 1);
			changeAppearance("LEGS", 31, 0);
			changeAppearance("SHOES", 25, 0);
			//changeAppearance("SPECIAL1", 0, 0);
			changeAppearance("SPECIAL2", 58, 0);
			//changeAppearance("SPECIAL3", 0, 0);
			changeAppearance("TEXTURES", 3, 0);
			changeAppearance("TORSO2", 50, 0);
			changeAppearance("HANDS", 0, 0);
			DoFX("scr_trevor1", "scr_trev1_trailer_boosh");
			drawNotification("Outfit: ~b~Splinter Cell");
			break;
		case 6://The Pilot
			ResetAppearance();
			changeAppearance("HATS", 40, 0);
			changeAppearance("GLASSES", 6, 0);
			changeAppearance("TORSO", 16, 0);
			changeAppearance("LEGS", 30, 0);
			changeAppearance("HANDS", 39, 4);
			changeAppearance("SHOES", 24, 0);
			changeAppearance("SPECIAL2", 15, 0);
			changeAppearance("TORSO2", 48, 0);
			DoFX("scr_trevor1", "scr_trev1_trailer_boosh");
			drawNotification("Outfit: ~b~Pilot");
			break;
		case 7: //Night Soldier
			ResetAppearance();
			changeAppearance("TORSO", 96, 0);
			changeAppearance("HATS", 40, 0);
			changeAppearance("MASK", 2, 0);
			changeAppearance("GLASSES", 0, 1);
			changeAppearance("LEGS", 34, 0);
			changeAppearance("SHOES", 25, 0);
			changeAppearance("SPECIAL1", 0, 0);
			changeAppearance("SPECIAL2", 58, 0);
			changeAppearance("TORSO2", 53, 0);
			changeAppearance("HANDS", 51, 0);
			DoFX("scr_rcbarry2", "scr_clown_appears");
			drawNotification("Outfit: ~b~Night Soldier");
			break;
		case 8: //Night Soldier 2
			ResetAppearance();
			changeAppearance("HATS", 40, 0);
			changeAppearance("MASK", 28, 0);
			changeAppearance("TORSO", 44, 0);
			changeAppearance("LEGS", 34, 0);
			changeAppearance("HANDS", 45, 0);
			changeAppearance("SHOES", 25, 0);
			changeAppearance("SPECIAL2", 56, 1);
			changeAppearance("TORSO2", 53, 0);
			DoFX("scr_rcbarry2", "scr_clown_death");
			drawNotification("Outfit: ~b~Night Soldier 2");
			break;
		case 9: //Ballas Member
			ResetAppearance();
			changeAppearance("HATS", 10, 7);
			changeAppearance("GLASSES", 17, 6);
			changeAppearance("MASK", 51, 6);
			changeAppearance("TORSO", 14, 0);
			changeAppearance("LEGS", 5, 9);
			changeAppearance("SHOES", 9, 5);
			changeAppearance("SPECIAL2", 23, 0);
			changeAppearance("TORSO2", 7, 9);
			DoFX("scr_trevor1", "scr_trev1_trailer_boosh");
			drawNotification("Outfit: ~b~Ballas Member");
		case 10: //THE Elf
			ResetAppearance();
			changeAppearance("MASK", 34, 0);
			changeAppearance("TORSO", 4, 0);
			changeAppearance("LEGS", 19, 1);
			changeAppearance("SHOES", 22, 1);
			changeAppearance("SPECIAL1", 18, 0);
			changeAppearance("SPECIAL2", 28, 8);
			changeAppearance("TORSO2", 19, 1);
			DoFX("scr_rcbarry2", "scr_clown_appears");
			drawNotification("Outfit: ~b~Elf");
			break;
		case 11: // the Thug
			ResetAppearance();
			changeAppearance("HATS", 46, 1);
			changeAppearance("GLASSES", 17, 6);
			changeAppearance("MASK", 51, 7);
			changeAppearance("TORSO", 22, 0);
			changeAppearance("LEGS", 7, 0);
			changeAppearance("HANDS", 44, 0);
			changeAppearance("SHOES", 12, 6);
			changeAppearance("SPECIAL2", 15, 0);
			changeAppearance("TORSO2", 14, 7);
			DoFX("scr_rcbarry2", "scr_clown_appears");
			DoFX("scr_trevor1", "scr_trev1_trailer_boosh");
			drawNotification("Outfit: ~b~Thug");
			break;
		case 12: //Santa
			ResetAppearance();
			changeAppearance("MASK", 8, 0);
			changeAppearance("TORSO", 12, 0);
			changeAppearance("LEGS", 19, 0);
			changeAppearance("SHOES", 4, 4);
			changeAppearance("SPECIAL1", 10, 0);
			changeAppearance("SPECIAL2", 21, 2);
			changeAppearance("TORSO2", 19, 0);
			DoFX("scr_trevor1", "scr_trev1_trailer_boosh");
			drawNotification("Outfit: ~b~Santa");
			break;
		case 13: //Snowman
			ResetAppearance();
			changeAppearance("MASK", 10, 0);
			changeAppearance("TORSO", 12, 0);
			changeAppearance("LEGS", 20, 0);
			changeAppearance("SHOES", 18, 1);
			changeAppearance("SPECIAL1", 24, 2);
			changeAppearance("SPECIAL2", 22, 4);
			changeAppearance("TORSO2", 25, 7);
			DoFX("scr_trevor1", "scr_trev1_trailer_boosh");
			drawNotification("Outfit: ~b~Snowman");
			break;
		case 14: //Web Hacker
			ResetAppearance();
			changeAppearance("TORSO", 95, 1);
			changeAppearance("MASK", 51, 5);
			changeAppearance("HATS", 24, 0);
			changeAppearance("HAIR", 14, 4);
			changeAppearance("GLASSES", 2, 7);
			changeAppearance("LEGS", 4, 15);
			changeAppearance("SHOES", 0, 15);
			changeAppearance("SPECIAL1", 40, 0);
			//changeAppearance("SPECIAL2", 15, 0);
			//changeAppearance("SPECIAL3", 0, 0);
			changeAppearance("TEXTURES", 0, 0);
			changeAppearance("TORSO2", 15, 0);
			changeAppearance("HANDS", 45, 0);
			DoFX("scr_rcbarry2", "scr_clown_death");
			drawNotification("Outfit: ~g~Web Hacker");
			break;
		case 15: //Xadrez oufitt
			ResetAppearance();
			changeAppearance("TORSO", 95, 1);
			changeAppearance("MASK", 36, 0);
			changeAppearance("HATS", 10, 6);
			changeAppearance("HAIR", 14, 4);
			changeAppearance("GLASSES", 2, 7);
			changeAppearance("LEGS", 4, 15);
			changeAppearance("SHOES", 0, 15);
			changeAppearance("SPECIAL1", 40, 0);
			//changeAppearance("SPECIAL2", 15, 0);
			//changeAppearance("SPECIAL3", 0, 0);
			changeAppearance("TEXTURES", 0, 0);
			changeAppearance("TORSO2", 11, 15);
			changeAppearance("HANDS", 15, 12);
			DoFX("scr_rcbarry1", "scr_alien_teleport");
			drawNotification("Outfit: ~g~Xadrez oufitt");
			break;
		case 16: //Black Combat
			ResetAppearance();
			changeAppearance("TORSO", 96, 0);
			changeAppearance("MASK", 3, 0);
			changeAppearance("HATS", 40, 0);
			changeAppearance("HAIR", 14, 4);
			changeAppearance("GLASSES", 2, 7);
			changeAppearance("LEGS", 33, 0);
			changeAppearance("SHOES", 28, 1);
			changeAppearance("SPECIAL1", 40, 0);
			changeAppearance("SPECIAL2", 58, 0);
			changeAppearance("SPECIAL3", 4, 1);
			changeAppearance("TEXTURES", 0, 0);
			changeAppearance("TORSO2", 68, 0);
			changeAppearance("HANDS", 45, 0);
			DoFX("scr_rcbarry1", "scr_alien_disintegrate");
			drawNotification("Outfit: ~g~Black Combat");
			break;
		case 17: //The Strength
			ResetAppearance();
			changeAppearance("HATS", 40, 0);
			changeAppearance("MASK", 28, 0);
			changeAppearance("TORSO", 44, 0);
			changeAppearance("LEGS", 34, 0);
			changeAppearance("HANDS", 45, 0);
			changeAppearance("SHOES", 25, 0);
			changeAppearance("SPECIAL2", 56, 1);
			changeAppearance("TORSO2", 53, 0);
			DoFX("scr_rcbarry1", "scr_alien_disintegrate");
			DoFX("scr_rcbarry1", "scr_alien_teleport");
			drawNotification("Outfit: ~g~The Strength");
			break;
		case 18: //The Security
			ResetAppearance();
			changeAppearance("HATS", 7, 1);
			changeAppearance("GLASSES", 9, 6);
			changeAppearance("EARS", 1, 0);
			changeAppearance("TORSO", 4, 0);
			changeAppearance("LEGS", 26, 0);
			changeAppearance("SHOES", 24, 0);
			changeAppearance("SPECIAL2", 58, 0);
			changeAppearance("TORSO2", 53, 0);
			DoFX("scr_rcbarry1", "scr_alien_disintegrate");
			DoFX("scr_trevor1", "scr_trev1_trailer_boosh");
			DoFX("scr_rcbarry1", "scr_alien_teleport");
			drawNotification("Outfit: ~g~The Security");
			break;
		case 19: //The Families
			ResetAppearance();
			changeAppearance("HATS", 10, 5);
			changeAppearance("GLASSES", 17, 5);
			changeAppearance("MASK", 51, 5);
			changeAppearance("TORSO", 14, 0);
			changeAppearance("LEGS", 5, 6);
			changeAppearance("SHOES", 9, 10);
			changeAppearance("SPECIAL2", 23, 0);
			changeAppearance("TORSO2", 7, 6);
			DoFX("scr_rcbarry1", "scr_alien_disintegrate");
			DoFX("scr_trevor1", "scr_trev1_trailer_boosh");
			DoFX("scr_rcbarry1", "scr_alien_teleport");
			drawNotification("Outfit: ~g~The Families");
			break;
		case 20: //THE HACKER
			ResetAppearance();
			changeAppearance("TORSO", 96, 0);
			changeAppearance("MASK", 7, 3);
			changeAppearance("HATS", 40, 0);
			changeAppearance("HAIR", 14, 4);
			changeAppearance("GLASSES", 2, 7);
			changeAppearance("LEGS", 26, 0);
			changeAppearance("SHOES", 1, 2);
			changeAppearance("SPECIAL1", 40, 0);
			changeAppearance("SPECIAL2", 56, 1);
			changeAppearance("SPECIAL3", 7, 1);
			changeAppearance("TEXTURES", 0, 0);
			changeAppearance("TORSO2", 68, 0);
			changeAppearance("HANDS", 37, 0);
			DoFX("scr_rcbarry1", "scr_alien_teleport");
			DoFX("scr_rcbarry1", "scr_alien_disintegrate");
			DoFX("scr_trevor1", "scr_trev1_trailer_boosh");
			drawNotification("Outfit: ~g~THE HACKER");
			break;
		case 21:// RNG DEATH MATH
			ResetAppearance();
			changeAppearance("TORSO", 21, 0);
			changeAppearance("MASK", 36, 0);
			changeAppearance("HATS", 40, 0);
			changeAppearance("HAIR", 14, 4);
			changeAppearance("GLASSES", 2, 7);
			changeAppearance("LEGS", 33, 0);
			changeAppearance("SHOES", 9, 4);
			changeAppearance("SPECIAL1", 31, 0);
			changeAppearance("SPECIAL2", 15, 1);
			//changeAppearance("SPECIAL3", 7, 1);
			changeAppearance("TEXTURES", 0, 0);
			changeAppearance("TORSO2", 21, 1);
			changeAppearance("HANDS", 37, 0);
			DoFX("scr_rcbarry1", "scr_alien_teleport");
			DoFX("scr_rcbarry1", "scr_alien_disintegrate");
			DoFX("scr_trevor1", "scr_trev1_trailer_boosh");
			drawNotification("Outfit: ~g~RNG DEATH MATH");
			break;
		case 22:// INVISIBLE COMBATTE
			ResetAppearance();
			changeAppearance("TORSO", 3, 0);
			changeAppearance("MASK", 36, 0);
			changeAppearance("HATS", 40, 0);
			changeAppearance("HAIR", 14, 4);
			changeAppearance("GLASSES", 2, 7);
			changeAppearance("LEGS", 11, 0);
			changeAppearance("SHOES", 13, 0);
			//changeAppearance("SPECIAL1", 31, 0);
			changeAppearance("SPECIAL2", 15, 1);
			//changeAppearance("SPECIAL3", 7, 1);
			changeAppearance("TEXTURES", 0, 0);
			changeAppearance("TORSO2", 15, 0);
			//changeAppearance("HANDS", 15, 0);
			DoFX("scr_rcbarry1", "scr_alien_teleport");
			DoFX("scr_rcbarry1", "scr_alien_disintegrate");
			DoFX("scr_trevor1", "scr_trev1_trailer_boosh");
			drawNotification("Outfit: ~g~INVISIBLE COMBATTE");
			break;
		case 23:// SPECIAL TRASH
			ResetAppearance();
			changeAppearance("TORSO", 1, 0);
			changeAppearance("MASK", 36, 0);
			changeAppearance("HATS", 38, 1);
			changeAppearance("HAIR", 14, 4);
			changeAppearance("GLASSES", 2, 7);
			changeAppearance("LEGS", 36, 0);
			changeAppearance("SHOES", 27, 0);
			//changeAppearance("SPECIAL1", 31, 0);
			changeAppearance("SPECIAL2", 59, 0);
			//changeAppearance("SPECIAL3", 7, 1);
			changeAppearance("TEXTURES", 0, 0);
			changeAppearance("TORSO2", 57, 0);
			changeAppearance("HANDS", 41, 0);
			DoFX("scr_rcbarry1", "scr_alien_teleport");
			DoFX("scr_rcbarry1", "scr_alien_disintegrate");
			DoFX("scr_trevor1", "scr_trev1_trailer_boosh");
			drawNotification("Outfit: ~g~SPECIAL TRASH MODDED");
			break;
		case 24:// Modded Outfitts 2
			ResetAppearance();
			changeAppearance("TORSO", 96, 0);
			changeAppearance("MASK", 46, 0);
			changeAppearance("HATS", 40, 0);
			changeAppearance("HAIR", 14, 4);
			changeAppearance("GLASSES", 2, 7);
			changeAppearance("LEGS", 33, 0);
			changeAppearance("SHOES", 28, 2);
			changeAppearance("SPECIAL1", 41, 0);
			changeAppearance("SPECIAL2", 55, 0);
			//changeAppearance("SPECIAL3", 7, 1);
			changeAppearance("TEXTURES", 0, 0);
			changeAppearance("TORSO2", 51, 0);
			changeAppearance("HANDS", 45, 0);
			DoFX("scr_rcbarry1", "scr_alien_teleport");
			DoFX("scr_rcbarry1", "scr_alien_disintegrate");
			DoFX("scr_trevor1", "scr_trev1_trailer_boosh");
			drawNotification("Outfit: ~g~Modded Outfitts 2");
			break;
		case 25:// Modded Outfitts 3
			ResetAppearance();
			changeAppearance("TORSO", 96, 0);
			changeAppearance("MASK", 46, 0);
			changeAppearance("HATS", 40, 0);
			changeAppearance("HAIR", 14, 4);
			changeAppearance("GLASSES", 2, 7);
			changeAppearance("LEGS", 33, 0);
			changeAppearance("SHOES", 28, 2);
			changeAppearance("SPECIAL1", 41, 0);
			changeAppearance("SPECIAL2", 55, 0);
			//changeAppearance("SPECIAL3", 7, 1);
			changeAppearance("TEXTURES", 0, 0);
			changeAppearance("TORSO2", 67, 2);
			changeAppearance("HANDS", 45, 0);
			DoFX("scr_rcbarry1", "scr_alien_teleport");
			DoFX("scr_rcbarry1", "scr_alien_disintegrate");
			DoFX("scr_trevor1", "scr_trev1_trailer_boosh");
			drawNotification("Outfit: ~g~Modded Outfitts 3");
			break;
		case 26:// New modded
			ResetAppearance();
			changeAppearance("TORSO", 96, 0);
			changeAppearance("MASK", 51, 0);
			changeAppearance("HATS", 40, 0);
			changeAppearance("HAIR", 14, 4);
			changeAppearance("GLASSES", 2, 7);
			changeAppearance("LEGS", 33, 0);
			changeAppearance("SHOES", 28, 0);
			changeAppearance("SPECIAL1", 41, 0);
			changeAppearance("SPECIAL2", 22, 4);
			changeAppearance("SPECIAL3", 2, 1);
			changeAppearance("TEXTURES", 0, 0);
			changeAppearance("TORSO2", 22, 0);
			changeAppearance("HANDS", 45, 0);
			DoFX("scr_rcbarry1", "scr_alien_teleport");
			DoFX("scr_rcbarry1", "scr_alien_disintegrate");
			DoFX("scr_trevor1", "scr_trev1_trailer_boosh");
			drawNotification("Outfit: ~g~New modded RNG");
			break;
		case 27:// New modded rNG 2
			ResetAppearance();
			changeAppearance("TORSO", 96, 0);
			changeAppearance("MASK", 2, 3);
			changeAppearance("HATS", 40, 0);
			changeAppearance("HAIR", 14, 4);
			changeAppearance("GLASSES", 2, 7);
			changeAppearance("LEGS", 33, 0);
			changeAppearance("SHOES", 28, 1);
			changeAppearance("SPECIAL1", 41, 0);
			changeAppearance("SPECIAL2", 22, 0);
			changeAppearance("SPECIAL3", 2, 1);
			changeAppearance("TEXTURES", 0, 0);
			changeAppearance("TORSO2", 22, 1);
			changeAppearance("HANDS", 45, 0);
			DoFX("scr_rcbarry1", "scr_alien_teleport");
			DoFX("scr_rcbarry1", "scr_alien_disintegrate");
			DoFX("scr_trevor1", "scr_trev1_trailer_boosh");
			drawNotification("Outfit: ~g~New modded RNG 2");
			break;
		case 28:// Independence Modded
			ResetAppearance();
			changeAppearance("TORSO", 77, 0);
			changeAppearance("MASK", 16, 7);
			changeAppearance("HATS", 40, 0);
			changeAppearance("HAIR", 14, 4);
			changeAppearance("GLASSES", 2, 7);
			changeAppearance("LEGS", 33, 0);
			changeAppearance("SHOES", 9, 3);
			changeAppearance("SPECIAL1", 41, 0);
			changeAppearance("SPECIAL2", 22, 0);
			changeAppearance("SPECIAL3", 2, 1);
			changeAppearance("TEXTURES", 0, 0);
			changeAppearance("TORSO2", 45, 0);
			changeAppearance("HANDS", 45, 0);
			DoFX("scr_rcbarry1", "scr_alien_teleport");
			DoFX("scr_rcbarry1", "scr_alien_disintegrate");
			DoFX("scr_trevor1", "scr_trev1_trailer_boosh");
			drawNotification("Outfit: ~g~Independence Modded");
			break;
		case 29:// ultimate rng
			ResetAppearance();
			changeAppearance("TORSO", 77, 0);
			changeAppearance("MASK", 16, 7);
			changeAppearance("HATS", 40, 0);
			changeAppearance("HAIR", 14, 4);
			changeAppearance("GLASSES", 2, 7);
			changeAppearance("LEGS", 33, 0);
			changeAppearance("SHOES", 6, 0);
			changeAppearance("SPECIAL1", 41, 0);
			changeAppearance("SPECIAL2", 33, 0);
			changeAppearance("SPECIAL3", 2, 1);
			changeAppearance("TEXTURES", 0, 0);
			changeAppearance("TORSO2", 53, 0);
			changeAppearance("HANDS", 45, 0);
			DoFX("scr_rcbarry1", "scr_alien_teleport");
			DoFX("scr_rcbarry1", "scr_alien_disintegrate");
			DoFX("scr_trevor1", "scr_trev1_trailer_boosh");
			drawNotification("Outfit: ~g~ultimate rng");
			break;
		case 30:// ultimate rng 2
			ResetAppearance();
			changeAppearance("TORSO", 77, 0);
			changeAppearance("MASK", 29, 3);//mascara
			changeAppearance("HATS", 40, 3);//capacete
			changeAppearance("HAIR", 14, 4);
			changeAppearance("GLASSES", 2, 7);//oculos
			changeAppearance("LEGS", 31, 3);//calças
			changeAppearance("SHOES", 9, 0);//sapatos
			changeAppearance("SPECIAL1", 41, 0);//das algemas
			changeAppearance("SPECIAL2", 33, 0);//da policia
			changeAppearance("SPECIAL3", 2, 3);//coletes
			changeAppearance("TEXTURES", 0, 0);
			changeAppearance("TORSO2", 53, 2);//blusas
			changeAppearance("HANDS", 41, 0);//muchila
			DoFX("scr_rcbarry1", "scr_alien_teleport");
			DoFX("scr_rcbarry1", "scr_alien_disintegrate");
			DoFX("scr_trevor1", "scr_trev1_trailer_boosh");
			drawNotification("Outfit: ~g~ultimate rng 2");
			break;
		case 31:// ultimate rng 2
			ResetAppearance();
			changeAppearance("TORSO", 88, 0);
			changeAppearance("MASK", 3, 0);//mascara
			changeAppearance("HATS", 40, 0);//capacete
			changeAppearance("HAIR", 0, 0);
			changeAppearance("GLASSES", 0, 0);//oculos
			changeAppearance("LEGS", 33, 0);//calças
			changeAppearance("SHOES", 6, 0);//sapatos
			changeAppearance("SPECIAL1", 41, 0);//das algemas
			changeAppearance("SPECIAL2", 55, 0);//da policia
			changeAppearance("SPECIAL3", 2, 3);//coletes
			changeAppearance("TEXTURES", 0, 0);
			changeAppearance("TORSO2", 67, 3);//blusas
			changeAppearance("HANDS", 45, 0);//muchila
			DoFX("scr_rcbarry1", "scr_alien_teleport");
			DoFX("scr_rcbarry1", "scr_alien_disintegrate");
			DoFX("scr_trevor1", "scr_trev1_trailer_boosh");
			drawNotification("Outfit: ~g~Combate Day black");
			break;
		case 32:
			ResetAppearance();
			changeAppearance("TORSO", 90, 0);
			changeAppearance("MASK", 3, 0);//mascara
			changeAppearance("HATS", 0, 0);//capacete
			changeAppearance("HAIR", 0, 0);
			changeAppearance("GLASSES", 2, 0);//oculos
			changeAppearance("LEGS", 6, 14);//calças
			changeAppearance("SHOES", 6, 0);//sapatos
			changeAppearance("SPECIAL1", 45, 1);//das algemas
			changeAppearance("SPECIAL2", 2, 3);//da policia
			changeAppearance("SPECIAL3", 2, 0);//coletes
			changeAppearance("TEXTURES", 0, 0);
			changeAppearance("TORSO2", 78, 15);//blusas
			changeAppearance("HANDS", 45, 0);//muchila
			DoFX("scr_rcbarry1", "scr_alien_teleport");
			DoFX("scr_rcbarry1", "scr_alien_disintegrate");
			DoFX("scr_trevor1", "scr_trev1_trailer_boosh");
			drawNotification("Outfit: ~g~Modded GTA Brazil");
			break;
		case 33:
			ResetAppearance();
			changeAppearance("TORSO", 82, 0);
			changeAppearance("MASK", 38, 3);//mascara
			changeAppearance("HATS", 40, 0);//capacete
			changeAppearance("HAIR", 0, 0);
			changeAppearance("GLASSES", 0, 0);//oculos
			changeAppearance("LEGS", 11, 0);//calças
			changeAppearance("SHOES", 26, 3);//sapatos
			changeAppearance("SPECIAL1", 40, 0);//das algemas
			changeAppearance("SPECIAL2", 60, 0);//da policia
			changeAppearance("SPECIAL3", 0, 0);//coletes
			changeAppearance("TEXTURES", 0, 0);
			changeAppearance("TORSO2", 58, 0);//blusas
			changeAppearance("HANDS", 0, 0);//muchila
			DoFX("scr_rcbarry1", "scr_alien_teleport");
			DoFX("scr_rcbarry1", "scr_alien_disintegrate");
			DoFX("scr_trevor1", "scr_trev1_trailer_boosh");
			drawNotification("Outfit: ~g~The Ippple");
			break;
		} break;
#pragma endregion
#pragma region Outfts Female
	case OutftsWomen:
		subTitle("Clothing Female");
		addOption("Pilot", " ");
		addOption("Strength", " ");
		addOption("Security", " ");
		addOption("Biker", " ");
		addOption("Business", " ");
		addOption("Cop", " ");
		addOption("Whore", " ");
		switch (getOption())
		{
		case 1: // The Pilot
			ResetAppearance();
			changeAppearance("HATS", 20, 0);
			changeAppearance("GLASSES", 12, 1);
			changeAppearance("TORSO", 17, 0);
			changeAppearance("LEGS", 29, 0);
			changeAppearance("HANDS", 39, 4);
			changeAppearance("SHOES", 24, 0);
			changeAppearance("SPECIAL2", 2, 0);
			changeAppearance("TORSO2", 41, 0);
			DoFX("scr_rcbarry2", "scr_clown_appears");
			DoFX("scr_trevor1", "scr_trev1_trailer_boosh");
			drawNotification("Outfit: ~g~The Pilot");
			break;
		case 2: // The Strength
			ResetAppearance();
			changeAppearance("HATS", 39, 0);
			changeAppearance("MASK", 28, 0);
			changeAppearance("TORSO", 36, 0);
			changeAppearance("LEGS", 33, 0);
			changeAppearance("HANDS", 45, 0);
			changeAppearance("SHOES", 25, 0);
			changeAppearance("SPECIAL2", 33, 1);
			changeAppearance("TORSO2", 46, 0);
			DoFX("scr_rcbarry1", "scr_alien_disintegrate");
			DoFX("scr_trevor1", "scr_trev1_trailer_boosh");
			DoFX("scr_rcbarry1", "scr_alien_teleport");
			drawNotification("Outfit: ~g~The Strength");
			break;
		case 3: // The Security
			ResetAppearance();
			changeAppearance("HATS", 15, 0);
			changeAppearance("GLASSES", 12, 3);
			changeAppearance("EARS", 1, 0);
			changeAppearance("TORSO", 36, 0);
			changeAppearance("LEGS", 30, 0);
			changeAppearance("SHOES", 24, 0);
			changeAppearance("SPECIAL2", 35, 0);
			changeAppearance("TORSO2", 46, 0);
			DoFX("scr_trevor1", "scr_trev1_trailer_boosh");
			DoFX("scr_rcbarry1", "scr_alien_teleport");
			drawNotification("Outfit: ~g~The Security");
			break;
		case 4: // The Biker
			ResetAppearance();
			changeAppearance("HATS", 7, 0);
			changeAppearance("GLASSES", 12, 1);
			changeAppearance("TORSO", 23, 0);
			changeAppearance("LEGS", 27, 0);
			changeAppearance("SHOES", 7, 0);
			changeAppearance("SPECIAL2", 14, 0);
			changeAppearance("TORSO2", 55, 0);
			DoFX("scr_trevor1", "scr_trev1_trailer_boosh");
			DoFX("scr_rcbarry1", "scr_alien_teleport");
			drawNotification("Outfit: ~g~The Biker");
			break;
		case 5: // The Business
			ResetAppearance();
			changeAppearance("GLASSES", 8, 5);
			changeAppearance("TORSO", 5, 0);
			changeAppearance("LEGS", 23, 0);
			changeAppearance("SHOES", 7, 3);
			changeAppearance("SPECIAL1", 6, 1);
			changeAppearance("SPECIAL2", 3, 0);
			changeAppearance("TORSO2", 57, 7);
			DoFX("scr_trevor1", "scr_trev1_trailer_boosh");
			DoFX("scr_rcbarry1", "scr_alien_teleport");
			drawNotification("Outfit: ~g~The Business");
			break;
		case 6: // The Cop
			ResetAppearance();
			changeAppearance("TORSO", 14, 0);
			changeAppearance("GLASSES", 12, 1);
			changeAppearance("LEGS", 34, 0);
			changeAppearance("SHOES", 25, 0);
			changeAppearance("SPECIAL2", 35, 0);
			changeAppearance("TORSO2", 48, 0);
			DoFX("scr_trevor1", "scr_josh3_light_explosion");
			DoFX("scr_rcbarry1", "scr_alien_teleport");
			drawNotification("Outfit: ~g~The Copps");
			break;
		case 7: // The Whore
			ResetAppearance();
			changeAppearance("TORSO", 15, 0);
			changeAppearance("LEGS", 22, 2);
			changeAppearance("HAIRS", 4, 0);
			changeAppearance("SHOES", 14, 0);
			changeAppearance("SPECIAL1", 2, 0);
			changeAppearance("SPECIAL2", 2, 0);
			changeAppearance("TORSO2", 0, 16);
			DoFX("scr_trevor1", "scr_alien_charging");
			DoFX("scr_rcbarry1", "scr_alien_teleport");
			drawNotification("Outfit: ~g~The Whore");
			break;
		}
		break;

		int forcepunch = 1;
#pragma endregion
#pragma region Force Powers
	case Forcepowerrs:
		subTitle("ABUSIVE OPTIONS FORCE");
		addOption("Force Explode Cars");
		addOption("Force Push Cars");
		addOption("Force Lift Cars");
		addOption("Force Persuade - Dance");
		addOption("Force Persuade - Riot");
		addOption("Force Persuade - Follow Me");
		addOption("Force Persuade - Push-Ups");
		addOption("Force Burn Peds");
		addOption("Force Shock Peds");
		addOption("Force Throw Peds");
		addOption("Force Push Peds");
		addOption("Force Launch Cars");
		addBoolOption("Kill Attackers", forcedefense);
		addIntOption("Force Punch", &forcepunch, 1, 1000, true);

		if (getOption() == 1)
		{
			DoFX("scr_trevor1", "scr_alien_disintegrate");
			ForceExplodeWave();
			char *dict = "rcmcollect_paperleadinout@";
			char *anim = "meditiate_idle";
			STREAMING::REQUEST_ANIM_DICT(dict);
			AI::TASK_PLAY_ANIM(PLAYER::PLAYER_PED_ID(), dict, anim, 1, 1, -1, 16, 0, false, 0, false);
			SoundToPlay = "FocusIn";
			SoundSetToPlay = "HintCamSounds";
			PlaySounds = true;
		}
		if (getOption() == 2)
		{
			DoFX("scr_trevor1", "scr_alien_disintegrate");
			ForceWave();
			char *dict = "rcmcollect_paperleadinout@";
			char *anim = "meditiate_idle";
			STREAMING::REQUEST_ANIM_DICT(dict);
			AI::TASK_PLAY_ANIM(PLAYER::PLAYER_PED_ID(), dict, anim, 1, 1, -1, 16, 0, false, 0, false);
			SoundToPlay = "FocusIn";
			SoundSetToPlay = "HintCamSounds";
			PlaySounds = true;
		}
		if (getOption() == 3)
		{
			DoFX("scr_trevor1", "scr_alien_disintegrate");
			ForceThrow();
			char *dict = "rcmcollect_paperleadinout@";
			char *anim = "meditiate_idle";
			STREAMING::REQUEST_ANIM_DICT(dict);
			AI::TASK_PLAY_ANIM(PLAYER::PLAYER_PED_ID(), dict, anim, 1, 1, -1, 16, 0, false, 0, false);
			SoundToPlay = "FocusIn";
			SoundSetToPlay = "HintCamSounds";
			PlaySounds = true;
		}
		if (getOption() == 4)
		{
			DoFX("scr_trevor1", "scr_alien_teleport");
			MCDance();
			char *dict = "rcmcollect_paperleadinout@";
			char *anim = "meditiate_idle";
			STREAMING::REQUEST_ANIM_DICT(dict);
			AI::TASK_PLAY_ANIM(PLAYER::PLAYER_PED_ID(), dict, anim, 1, 1, -1, 16, 0, false, 0, false);
			SoundToPlay = "FocusIn";
			SoundSetToPlay = "HintCamSounds";
			PlaySounds = true;
		}
		if (getOption() == 5)
		{
			DoFX("scr_trevor1", "scr_alien_teleport"); 
			MCRiot();
			char *dict = "rcmcollect_paperleadinout@";
			char *anim = "meditiate_idle";
			STREAMING::REQUEST_ANIM_DICT(dict);
			AI::TASK_PLAY_ANIM(PLAYER::PLAYER_PED_ID(), dict, anim, 1, 1, -1, 16, 0, false, 0, false);
			SoundToPlay = "FocusIn";
			SoundSetToPlay = "HintCamSounds";
			PlaySounds = true;
		}
		if (getOption() == 6)
		{
			DoFX("scr_trevor1", "scr_alien_teleport"); 
			MCFollow();
			char *dict = "rcmcollect_paperleadinout@";
			char *anim = "meditiate_idle";
			STREAMING::REQUEST_ANIM_DICT(dict);
			AI::TASK_PLAY_ANIM(PLAYER::PLAYER_PED_ID(), dict, anim, 1, 1, -1, 16, 0, false, 0, false);
			SoundToPlay = "FocusIn";
			SoundSetToPlay = "HintCamSounds";
			PlaySounds = true;
		}//amb@world_human_push_ups@male@base", "base"
		if (getOption() == 7)
		{
			DoFX("scr_trevor1", "scr_alien_teleport"); 
			MCPushups();
			char *dict = "rcmcollect_paperleadinout@";
			char *anim = "meditiate_idle";
			STREAMING::REQUEST_ANIM_DICT(dict);
			AI::TASK_PLAY_ANIM(PLAYER::PLAYER_PED_ID(), dict, anim, 1, 1, -1, 16, 0, false, 0, false);
			SoundToPlay = "FocusIn";
			SoundSetToPlay = "HintCamSounds";
			PlaySounds = true;
		}
		if (getOption() == 8)
		{
			DoFX("scr_trevor1", "scr_alien_disintegrate");
			MCBurn();
			char *dict = "rcmcollect_paperleadinout@";
			char *anim = "meditiate_idle";
			STREAMING::REQUEST_ANIM_DICT(dict);
			AI::TASK_PLAY_ANIM(PLAYER::PLAYER_PED_ID(), dict, anim, 1, 1, -1, 16, 0, false, 0, false);
			SoundToPlay = "FocusIn";
			SoundSetToPlay = "HintCamSounds";
			PlaySounds = true;
		}
		if (getOption() == 9)
		{
			DoFX("scr_trevor1", "scr_trev1_trailer_boosh");
			MCShock();
			char *dict = "rcmcollect_paperleadinout@";
			char *anim = "meditiate_idle";
			STREAMING::REQUEST_ANIM_DICT(dict);
			AI::TASK_PLAY_ANIM(PLAYER::PLAYER_PED_ID(), dict, anim, 1, 1, -1, 16, 0, false, 0, false);
			SoundToPlay = "FocusIn";
			SoundSetToPlay = "HintCamSounds";
			PlaySounds = true;
		}
		if (getOption() == 10)
		{
			DoFX("scr_trevor1", "scr_alien_disintegrate");
			MCWater();
			char *dict = "rcmcollect_paperleadinout@";
			char *anim = "meditiate_idle";
			STREAMING::REQUEST_ANIM_DICT(dict);
			AI::TASK_PLAY_ANIM(PLAYER::PLAYER_PED_ID(), dict, anim, 1, 1, -1, 16, 0, false, 0, false);
			SoundToPlay = "FocusIn";
			SoundSetToPlay = "HintCamSounds";
			PlaySounds = true;
		}
		if (getOption() == 11)
		{
			DoFX("scr_rcbarry2", "scr_clown_appears");
			MCPush();
			char *dict = "switch@trevor@pushes_bodybuilder";
			char *anim = "001426_03_trvs_5_pushes_bodybuilder_exit_trv";
			//STREAMING::REQUEST_ANIM_DICT(dict);
			//AI::TASK_PLAY_ANIM(PLAYER::PLAYER_PED_ID(), dict, anim, 1, 1, -1, 16, 0, false, 0, false);
			SoundToPlay = "FocusIn";
			SoundSetToPlay = "HintCamSounds";
			PlaySounds = true;
		}
		if (getOption() == 12)//////////////////
		{
			DoFX("scr_reconstructionaccident", "scr_reconstruct_pipe_impact");
			ForceBoost();
			char *dict = "rcmcollect_paperleadinout@";
			char *anim = "meditiate_idle";
			STREAMING::REQUEST_ANIM_DICT(dict);
			AI::TASK_PLAY_ANIM(PLAYER::PLAYER_PED_ID(), dict, anim, 1, 1, -1, 16, 0, false, 0, false);
			SoundToPlay = "FocusIn";
			SoundSetToPlay = "HintCamSounds";
			PlaySounds = true;
		}
		if (getOption() == 13)
		{
			forcedefense = !forcedefense;
			if (forcedefense == true)
			{
				drawNotification("Force Defense: ~b~Enabled");
				drawNotification("~b~Anyone player aims at you");
				drawNotification("~b~the force will destroy them!");
			}
			else if (forcedefense == false)
			{
				drawNotification("Force Defense: ~r~Disabled");
			}
		}
		if (getOption() == 14)
		{
			PLAYER::SET_PLAYER_MELEE_WEAPON_DAMAGE_MODIFIER(PLAYER::PLAYER_ID(), forcepunch);
		} break;
#pragma endregion
#pragma region particlefx
	case particlefx:
		subTitle("PARTICLE FX");
		addIntOption("Particle Scale", &patrilesize, 0, 20, true);
		addPlayerFX("clown appears", "scr_rcbarry2", "scr_clown_appears");
		addPlayerFX("alien teleport", "scr_rcbarry1", "scr_alien_teleport");
		addPlayerFX("alien disintegrate", "scr_rcbarry1", "scr_alien_disintegrate");
		addPlayerFX("clown death", "scr_rcbarry2", "scr_clown_death");
		addPlayerFX("clown Pinks", "scr_rcbarry2", "scr_clown_bul");//FLOR COM ROSAS
		addPlayerFX("clown explosion", "scr_rcbarry2", "scr_exp_clown");//FLOR COM ROSAS
		addPlayerFX("fbi crash", "scr_fbi4", "scr_fbi4_trucks_crash");
		addPlayerFX("fam4 sparks", "scr_family4", "scr_fam4_trailer_sparks");
		addPlayerFX("lighter sparks", "scr_mp_house", "scr_sh_lighter_sparks");
		addPlayerFX("fbi drips", "scr_agencyheist", "scr_fbi_mop_drips");
		addPlayerFX("fbi squeeze", "scr_agencyheist", "scr_fbi_mop_squeeze");
		addPlayerFX("landing tyre smoke", "scr_mp_creator", "scr_mp_plane_landing_tyre_smoke");
		addPlayerFX("mich2 blood", "scr_michael2", "scr_mich2_blood_stab");
		addPlayerFX("trev1 trailer splash", "scr_trevor1", "scr_trev1_trailer_splash");
		addPlayerFX("trev1_trailer boosh", "scr_trevor1", "scr_trev1_trailer_boosh");
		addPlayerFX("trev4 blood impact", "scr_solomon3", "scr_trev4_747_blood_impact");
		switch (getOption())
		{
		case 1: break;
		}
		break;
#pragma endregion
#pragma region All Visions
	case All_Visions:
		subTitle("Screen Visions");
		ClearVisions("Set back To Default", "Set To Default");
		addVisOption("Bank_HLWD", "Bank_HLWD", "Chnaged To: Bank_HLWD");
		addVisOption("Barry1_Stoned", "Barry1_Stoned", "Chnaged To: Barry1_Stoned");
		addVisOption("BarryFadeOut", "BarryFadeOut", "Chnaged To: BarryFadeOut");
		addVisOption("baseTONEMAPPING", "baseTONEMAPPING", "Chnaged To: baseTONEMAPPING");
		addVisOption("Bikers", "Bikers", "Chnaged To: Bikers");
		addVisOption("BikersSPLASH", "BikersSPLASH", "Chnaged To: BikersSPLASH");
		addVisOption("blackNwhite", "blackNwhite", "Chnaged To: blackNwhite");
		addVisOption("BlackOut", "BlackOut", "Chnaged To: BlackOut");
		addVisOption("Bloom", "Bloom", "Chnaged To: Bloom");
		addVisOption("BloomLight", "BloomLight", "Chnaged To: BloomLight");
		addVisOption("buildingTOP", "buildingTOP", "Chnaged To: buildingTOP");
		addVisOption("BulletTimeDark", "BulletTimeDark", "Chnaged To: BulletTimeDark");
		addVisOption("BulletTimeLight", "BulletTimeLight", "Chnaged To: BulletTimeLight");
		addVisOption("CAMERA_BW", "CAMERA_BW", "Chnaged To: CAMERA_BW");
		addVisOption("CAMERA_secuirity", "CAMERA_secuirity", "Chnaged To: CAMERA_secuirity");
		addVisOption("CAMERA_secuirity_FUZZ", "CAMERA_secuirity_FUZZ", "Chnaged To: CAMERA_secuirity_FUZZ");
		addVisOption("canyon_mission", "canyon_mission", "Chnaged To: canyon_mission");
		addVisOption("carMOD_underpass", "carMOD_underpass", "Chnaged To: carMOD_underpass");
		addVisOption("carpark", "carpark", "Chnaged To: carpark");
		addVisOption("carpark_dt1_02", "carpark_dt1_02", "Chnaged To: carpark_dt1_02");
		addVisOption("carpark_dt1_03", "carpark_dt1_03", "Chnaged To: carpark_dt1_03");
		addVisOption("cashdepot", "cashdepot", "Chnaged To: cashdepot");
		addVisOption("cashdepotEMERGENCY", "cashdepotEMERGENCY", "Chnaged To: cashdepotEMERGENCY");
		addVisOption("cBank_back", "cBank_back", "Chnaged To: cBank_back");
		addVisOption("cBank_front", "cBank_front", "Chnaged To: cBank_front");
		addVisOption("ch2_tunnel_whitelight", "ch2_tunnel_whitelight", "Chnaged To: ch2_tunnel_whitelight");
		addVisOption("CH3_06_water", "CH3_06_water", "Chnaged To: CH3_06_water");
		addVisOption("CHOP", "CHOP", "Chnaged To: CHOP");
		addVisOption("cinema", "cinema", "Chnaged To: cinema");
		addVisOption("cinema_001", "cinema_001", "Chnaged To: cinema_001");
		addVisOption("cops", "cops", "Chnaged To: cops");
		addVisOption("CopsSPLASH", "CopsSPLASH", "Chnaged To: CopsSPLASH");
		addVisOption("crane_cam", "crane_cam", "Chnaged To: crane_cam");
		addVisOption("crane_cam_cinematic", "crane_cam_cinematic", "Chnaged To: crane_cam_cinematic");
		addVisOption("CS1_railwayB_tunnel", "CS1_railwayB_tunnel", "Chnaged To: CS1_railwayB_tunnel");
		addVisOption("CS3_rail_tunnel", "CS3_rail_tunnel", "Chnaged To: CS3_rail_tunnel");
		addVisOption("CUSTOM_streetlight", "CUSTOM_streetlight", "Chnaged To: CUSTOM_streetlight");
		addVisOption("damage", "damage", "Chnaged To: damage");
		addVisOption("death", "death", "Chnaged To: death");
		addVisOption("DEFAULT", "DEFAULT", "Chnaged To: DEFAULT");
		addVisOption("DefaultColorCode", "DefaultColorCode", "Chnaged To: DefaultColorCode");
		addVisOption("DONT_overide_sunpos", "DONT_overide_sunpos", "Chnaged To: DONT_overide_sunpos");
		addVisOption("Dont_tazeme_bro", "Dont_tazeme_bro", "Chnaged To: Dont_tazeme_bro");
		addVisOption("dont_tazeme_bro_b", "dont_tazeme_bro_b", "Chnaged To: dont_tazeme_bro_b");
		addVisOption("downtown_FIB_cascades_opt", "downtown_FIB_cascades_opt", "Chnaged To: downtown_FIB_cascades_opt");
		addVisOption("DrivingFocusDark", "DrivingFocusDark", "Chnaged To: DrivingFocusDark");
		addVisOption("DrivingFocusLight", "DrivingFocusLight", "Chnaged To: DrivingFocusLight");
		addVisOption("DRUG_2_drive", "DRUG_2_drive", "Chnaged To: DRUG_2_drive");
		addVisOption("Drug_deadman", "Drug_deadman", "Chnaged To: Drug_deadman");
		addVisOption("Drug_deadman_blend", "Drug_deadman_blend", "Chnaged To: Drug_deadman_blend");
		addVisOption("drug_drive_blend01", "drug_drive_blend01", "Chnaged To: drug_drive_blend01");
		addVisOption("drug_drive_blend02", "drug_drive_blend02", "Chnaged To: drug_drive_blend02");
		addVisOption("drug_flying_01", "drug_flying_01", "Chnaged To: drug_flying_01");
		addVisOption("drug_flying_02", "drug_flying_02", "Chnaged To: drug_flying_02");
		addVisOption("drug_flying_base", "drug_flying_base", "Chnaged To: drug_flying_base");
		addVisOption("DRUG_gas_huffin", "DRUG_gas_huffin", "Chnaged To: DRUG_gas_huffin");
		addVisOption("drug_wobbly", "drug_wobbly", "Chnaged To: drug_wobbly");
		addVisOption("Drunk", "Drunk", "Chnaged To: Drunk");
		addVisOption("dying", "dying", "Chnaged To: dying");
		addVisOption("eatra_bouncelight_beach", "eatra_bouncelight_beach", "Chnaged To: eatra_bouncelight_beach");
		addVisOption("epsilion", "epsilion", "Chnaged To: epsilion");
		addVisOption("exile1_exit", "exile1_exit", "Chnaged To: exile1_exit");
		addVisOption("exile1_plane", "exile1_plane", "Chnaged To: exile1_plane");
		addVisOption("ExplosionJosh", "ExplosionJosh", "Chnaged To: ExplosionJosh");
		addVisOption("ext_int_extlight_large", "ext_int_extlight_large", "Chnaged To: ext_int_extlight_large");
		addVisOption("EXTRA_bouncelight", "EXTRA_bouncelight", "Chnaged To: EXTRA_bouncelight");
		addVisOption("eyeINtheSKY", "eyeINtheSKY", "Chnaged To: eyeINtheSKY");
		addVisOption("Facebook_NEW", "Facebook_NEW", "Chnaged To: Facebook_NEW");
		addVisOption("facebook_serveroom", "facebook_serveroom", "Chnaged To: facebook_serveroom");
		addVisOption("FIB_5", "FIB_5", "Chnaged To: FIB_5");
		addVisOption("FIB_6", "FIB_6", "Chnaged To: FIB_6");
		addVisOption("FIB_A", "FIB_A", "Chnaged To: FIB_A");
		addVisOption("FIB_B", "FIB_B", "Chnaged To: FIB_B");
		addVisOption("FIB_interview", "FIB_interview", "Chnaged To: FIB_interview");
		addVisOption("FIB_interview_optimise", "FIB_interview_optimise", "Chnaged To: FIB_interview_optimise");
		addVisOption("FinaleBank", "FinaleBank", "Chnaged To: FinaleBank");
		addVisOption("FinaleBankexit", "FinaleBankexit", "Chnaged To: FinaleBankexit");
		addVisOption("FinaleBankMid", "FinaleBankMid", "Chnaged To: FinaleBankMid");
		addVisOption("fireDEPT", "fireDEPT", "Chnaged To: fireDEPT");
		addVisOption("FORdoron_delete", "FORdoron_delete", "Chnaged To: FORdoron_delete");
		addVisOption("Forest", "Forest", "Chnaged To: Forest");
		addVisOption("FrankilinsHOUSEhills", "FrankilinsHOUSEhills", "Chnaged To: FrankilinsHOUSEhills");
		addVisOption("frankilnsAUNTS_new", "frankilnsAUNTS_new", "Chnaged To: frankilnsAUNTS_new");
		addVisOption("frankilnsAUNTS_SUNdir", "frankilnsAUNTS_SUNdir", "Chnaged To: frankilnsAUNTS_SUNdir");
		addVisOption("FRANKLIN", "FRANKLIN", "Chnaged To: FRANKLIN");
		addVisOption("FranklinColorCode", "FranklinColorCode", "Chnaged To: FranklinColorCode");
		addVisOption("FranklinColorCodeBasic", "FranklinColorCodeBasic", "Chnaged To: FranklinColorCodeBasic");
		addVisOption("FullAmbientmult_interior", "FullAmbientmult_interior", "Chnaged To: FullAmbientmult_interior");
		addVisOption("gallery_refmod", "gallery_refmod", "Chnaged To: gallery_refmod");
		addVisOption("garage", "garage", "Chnaged To: garage");
		addVisOption("gorge_reflection_gpu", "gorge_reflection_gpu", "Chnaged To: gorge_reflection_gpu");
		addVisOption("gorge_reflectionoffset", "gorge_reflectionoffset", "Chnaged To: gorge_reflectionoffset");
		addVisOption("gorge_reflectionoffset2", "gorge_reflectionoffset2", "Chnaged To: gorge_reflectionoffset2");
		addVisOption("graveyard_shootout", "graveyard_shootout", "Chnaged To: graveyard_shootout");
		addVisOption("gunclub", "gunclub", "Chnaged To: gunclub");
		addVisOption("gunclubrange", "gunclubrange", "Chnaged To: gunclubrange");
		addVisOption("gunshop", "gunshop", "Chnaged To: gunshop");
		addVisOption("gunstore", "gunstore", "Chnaged To: gunstore");
		addVisOption("half_direct", "half_direct", "Chnaged To: half_direct");
		addVisOption("hangar_lightsmod", "hangar_lightsmod", "Chnaged To: hangar_lightsmod");
		addVisOption("Hanger_INTmods", "Hanger_INTmods", "Chnaged To: Hanger_INTmods");
		addVisOption("heathaze", "heathaze", "Chnaged To: heathaze");
		addVisOption("helicamfirst", "helicamfirst", "Chnaged To: helicamfirst");
		addVisOption("Hicksbar", "Hicksbar", "Chnaged To: Hicksbar");
		addVisOption("HicksbarNEW", "HicksbarNEW", "Chnaged To: HicksbarNEW");
		addVisOption("hillstunnel", "hillstunnel", "Chnaged To: hillstunnel");
		addVisOption("Hint_cam", "Hint_cam", "Chnaged To: Hint_cam");
		addVisOption("hitped", "hitped", "Chnaged To: hitped");
		addVisOption("hud_def_blur", "hud_def_blur", "Chnaged To: hud_def_blur");
		addVisOption("hud_def_colorgrade", "hud_def_colorgrade", "Chnaged To: hud_def_colorgrade");
		addVisOption("hud_def_desat_cold", "hud_def_desat_cold", "Chnaged To: hud_def_desat_cold");
		addVisOption("hud_def_desat_cold_kill", "hud_def_desat_cold_kill", "Chnaged To: hud_def_desat_cold_kill");
		addVisOption("hud_def_desat_Franklin", "hud_def_desat_Franklin", "Chnaged To: hud_def_desat_Franklin");
		addVisOption("hud_def_desat_Michael", "hud_def_desat_Michael", "Chnaged To: hud_def_desat_Michael");
		addVisOption("hud_def_desat_Neutral", "hud_def_desat_Neutral", "Chnaged To: hud_def_desat_Neutral");
		addVisOption("hud_def_desat_switch", "hud_def_desat_switch", "Chnaged To: hud_def_desat_switch");
		addVisOption("hud_def_desat_Trevor", "hud_def_desat_Trevor", "Chnaged To: hud_def_desat_Trevor");
		addVisOption("hud_def_desatcrunch", "hud_def_desatcrunch", "Chnaged To: hud_def_desatcrunch");
		addVisOption("hud_def_flash", "hud_def_flash", "Chnaged To: hud_def_flash");
		addVisOption("hud_def_focus", "hud_def_focus", "Chnaged To: hud_def_focus");
		addVisOption("hud_def_Franklin", "hud_def_Franklin", "Chnaged To: hud_def_Franklin");
		addVisOption("hud_def_lensdistortion", "hud_def_lensdistortion", "Chnaged To: hud_def_lensdistortion");
		addVisOption("hud_def_Michael", "hud_def_Michael", "Chnaged To: hud_def_Michael");
		addVisOption("hud_def_Trevor", "hud_def_Trevor", "Chnaged To: hud_def_Trevor");
		addVisOption("id1_11_tunnel", "id1_11_tunnel", "Chnaged To: id1_11_tunnel");
		addVisOption("int_amb_mult_large", "int_amb_mult_large", "Chnaged To: int_amb_mult_large");
		addVisOption("int_Barber1", "int_Barber1", "Chnaged To: int_Barber1");
		addVisOption("int_carmod_small", "int_carmod_small", "Chnaged To: int_carmod_small");
		addVisOption("int_carshowroom", "int_carshowroom", "Chnaged To: int_carshowroom");
		addVisOption("int_chopshop", "int_chopshop", "Chnaged To: int_chopshop");
		addVisOption("int_clean_extlight_large", "int_clean_extlight_large", "Chnaged To: int_clean_extlight_large");
		addVisOption("int_clean_extlight_none", "int_clean_extlight_none", "Chnaged To: int_clean_extlight_none");
		addVisOption("int_clean_extlight_small", "int_clean_extlight_small", "Chnaged To: int_clean_extlight_small");
		addVisOption("int_ClothesHi", "int_ClothesHi", "Chnaged To: int_ClothesHi");
		addVisOption("int_clotheslow_large", "int_clotheslow_large", "Chnaged To: int_clotheslow_large");
		addVisOption("int_cluckinfactory_none", "int_cluckinfactory_none", "Chnaged To: int_cluckinfactory_none");
		addVisOption("int_cluckinfactory_small", "int_cluckinfactory_small", "Chnaged To: int_cluckinfactory_small");
		addVisOption("int_ControlTower_none", "int_ControlTower_none", "Chnaged To: int_ControlTower_none");
		addVisOption("int_ControlTower_small", "int_ControlTower_small", "Chnaged To: int_ControlTower_small");
		addVisOption("int_dockcontrol_small", "int_dockcontrol_small", "Chnaged To: int_dockcontrol_small");
		addVisOption("int_extlght_sm_cntrst", "int_extlght_sm_cntrst", "Chnaged To: int_extlght_sm_cntrst");
		addVisOption("int_extlight_large", "int_extlight_large", "Chnaged To: int_extlight_large");
		addVisOption("int_extlight_large_fog", "int_extlight_large_fog", "Chnaged To: int_extlight_large_fog");
		addVisOption("int_extlight_none", "int_extlight_none", "Chnaged To: int_extlight_none");
		addVisOption("int_extlight_none_dark", "int_extlight_none_dark", "Chnaged To: int_extlight_none_dark");
		addVisOption("int_extlight_none_dark_fog", "int_extlight_none_dark_fog", "Chnaged To: int_extlight_none_dark_fog");
		addVisOption("int_extlight_none_fog", "int_extlight_none_fog", "Chnaged To: int_extlight_none_fog");
		addVisOption("int_extlight_small", "int_extlight_small", "Chnaged To: int_extlight_small");
		addVisOption("int_extlight_small_clipped", "int_extlight_small_clipped", "Chnaged To: int_extlight_small_clipped");
		addVisOption("int_extlight_small_fog", "int_extlight_small_fog", "Chnaged To: int_extlight_small_fog");
		addVisOption("int_Farmhouse_none", "int_Farmhouse_none", "Chnaged To: int_Farmhouse_none");
		addVisOption("int_Farmhouse_small", "int_Farmhouse_small", "Chnaged To: int_Farmhouse_small");
		addVisOption("int_FranklinAunt_small", "int_FranklinAunt_small", "Chnaged To: int_FranklinAunt_small");
		addVisOption("INT_FullAmbientmult", "INT_FullAmbientmult", "Chnaged To: INT_FullAmbientmult");
		addVisOption("INT_FULLAmbientmult_art", "INT_FULLAmbientmult_art", "Chnaged To: INT_FULLAmbientmult_art");
		addVisOption("INT_FULLAmbientmult_both", "INT_FULLAmbientmult_both", "Chnaged To: INT_FULLAmbientmult_both");
		addVisOption("INT_garage", "INT_garage", "Chnaged To: INT_garage");
		addVisOption("int_GasStation", "int_GasStation", "Chnaged To: int_GasStation");
		addVisOption("int_hanger_none", "int_hanger_none", "Chnaged To: int_hanger_none");
		addVisOption("int_hanger_small", "int_hanger_small", "Chnaged To: int_hanger_small");
		addVisOption("int_Hospital2_DM", "int_Hospital2_DM", "Chnaged To: int_Hospital2_DM");
		addVisOption("int_Hospital_Blue", "int_Hospital_Blue", "Chnaged To: int_Hospital_Blue");
		addVisOption("int_Hospital_BlueB", "int_Hospital_BlueB", "Chnaged To: int_Hospital_BlueB");
		addVisOption("int_Hospital_DM", "int_Hospital_DM", "Chnaged To: int_Hospital_DM");
		addVisOption("int_lesters", "int_lesters", "Chnaged To: int_lesters");
		addVisOption("int_Lost_none", "int_Lost_none", "Chnaged To: int_Lost_none");
		addVisOption("int_Lost_small", "int_Lost_small", "Chnaged To: int_Lost_small");
		addVisOption("int_methlab_small", "int_methlab_small", "Chnaged To: int_methlab_small");
		addVisOption("int_motelroom", "int_motelroom", "Chnaged To: int_motelroom");
		addVisOption("INT_NO_fogALPHA", "INT_NO_fogALPHA", "Chnaged To: INT_NO_fogALPHA");
		addVisOption("INT_NoAmbientmult", "INT_NoAmbientmult", "Chnaged To: INT_NoAmbientmult");
		addVisOption("INT_NoAmbientmult_art", "INT_NoAmbientmult_art", "Chnaged To: INT_NoAmbientmult_art");
		addVisOption("INT_NoAmbientmult_both", "INT_NoAmbientmult_both", "Chnaged To: INT_NoAmbientmult_both");
		addVisOption("INT_NOdirectLight", "INT_NOdirectLight", "Chnaged To: INT_NOdirectLight");
		addVisOption("INT_nowaterREF", "INT_nowaterREF", "Chnaged To: INT_nowaterREF");
		addVisOption("int_office_Lobby", "int_office_Lobby", "Chnaged To: int_office_Lobby");
		addVisOption("int_office_LobbyHall", "int_office_LobbyHall", "Chnaged To: int_office_LobbyHall");
		addVisOption("INT_posh_hairdresser", "INT_posh_hairdresser", "Chnaged To: INT_posh_hairdresser");
		addVisOption("INT_streetlighting", "INT_streetlighting", "Chnaged To: INT_streetlighting");
		addVisOption("int_tattoo", "int_tattoo", "Chnaged To: int_tattoo");
		addVisOption("int_tattoo_B", "int_tattoo_B", "Chnaged To: int_tattoo_B");
		addVisOption("int_tunnel_none_dark", "int_tunnel_none_dark", "Chnaged To: int_tunnel_none_dark");
		addVisOption("interior_WATER_lighting", "interior_WATER_lighting", "Chnaged To: interior_WATER_lighting");
		addVisOption("introblue", "introblue", "Chnaged To: introblue");
		addVisOption("jewel_gas", "jewel_gas", "Chnaged To: jewel_gas");
		addVisOption("jewel_optim", "jewel_optim", "Chnaged To: jewel_optim");
		addVisOption("jewelry_entrance", "jewelry_entrance", "Chnaged To: jewelry_entrance");
		addVisOption("jewelry_entrance_INT", "jewelry_entrance_INT", "Chnaged To: jewelry_entrance_INT");
		addVisOption("jewelry_entrance_INT_fog", "jewelry_entrance_INT_fog", "Chnaged To: jewelry_entrance_INT_fog");
		addVisOption("KT_underpass", "KT_underpass", "Chnaged To: KT_underpass");
		addVisOption("lab_none", "lab_none", "Chnaged To: lab_none");
		addVisOption("lab_none_dark", "lab_none_dark", "Chnaged To: lab_none_dark");
		addVisOption("lab_none_dark_fog", "lab_none_dark_fog", "Chnaged To: lab_none_dark_fog");
		addVisOption("lab_none_exit", "lab_none_exit", "Chnaged To: lab_none_exit");
		addVisOption("LifeInvaderLOD", "LifeInvaderLOD", "Chnaged To: LifeInvaderLOD");
		addVisOption("lightning", "lightning", "Chnaged To: lightning");
		addVisOption("lightning_cloud", "lightning_cloud", "Chnaged To: lightning_cloud");
		addVisOption("lightning_strong", "lightning_strong", "Chnaged To: lightning_strong");
		addVisOption("lightning_weak", "lightning_weak", "Chnaged To: lightning_weak");
		addVisOption("LightPollutionHills", "LightPollutionHills", "Chnaged To: LightPollutionHills");
		addVisOption("lightpolution", "lightpolution", "Chnaged To: lightpolution");
		addVisOption("LIGHTSreduceFALLOFF", "LIGHTSreduceFALLOFF", "Chnaged To: LIGHTSreduceFALLOFF");
		addVisOption("LODmult_global_reduce", "LODmult_global_reduce", "Chnaged To: LODmult_global_reduce");
		addVisOption("LODmult_global_reduce_NOHD", "LODmult_global_reduce_NOHD", "Chnaged To: LODmult_global_reduce_NOHD");
		addVisOption("LODmult_HD_orphan_LOD_reduce", "LODmult_HD_orphan_LOD_reduce", "Chnaged To: LODmult_HD_orphan_LOD_reduce");
		addVisOption("LODmult_HD_orphan_reduce", "LODmult_HD_orphan_reduce", "Chnaged To: LODmult_HD_orphan_reduce");
		addVisOption("LODmult_LOD_reduce", "LODmult_LOD_reduce", "Chnaged To: LODmult_LOD_reduce");
		addVisOption("LODmult_SLOD1_reduce", "LODmult_SLOD1_reduce", "Chnaged To: LODmult_SLOD1_reduce");
		addVisOption("LODmult_SLOD2_reduce", "LODmult_SLOD2_reduce", "Chnaged To: LODmult_SLOD2_reduce");
		addVisOption("LODmult_SLOD3_reduce", "LODmult_SLOD3_reduce", "Chnaged To: LODmult_SLOD3_reduce");
		addVisOption("metro", "metro", "Chnaged To: metro");
		addVisOption("METRO_platform", "METRO_platform", "Chnaged To: METRO_platform");
		addVisOption("METRO_Tunnels", "METRO_Tunnels", "Chnaged To: METRO_Tunnels");
		addVisOption("METRO_Tunnels_entrance", "METRO_Tunnels_entrance", "Chnaged To: METRO_Tunnels_entrance");
		addVisOption("MichaelColorCode", "MichaelColorCode", "Chnaged To: MichaelColorCode");
		addVisOption("MichaelColorCodeBasic", "MichaelColorCodeBasic", "Chnaged To: MichaelColorCodeBasic");
		addVisOption("MichaelsDarkroom", "MichaelsDarkroom", "Chnaged To: MichaelsDarkroom");
		addVisOption("MichaelsDirectional", "MichaelsDirectional", "Chnaged To: MichaelsDirectional");
		addVisOption("MichaelsNODirectional", "MichaelsNODirectional", "Chnaged To: MichaelsNODirectional");
		addVisOption("micheal", "micheal", "Chnaged To: micheal");
		addVisOption("micheals_lightsOFF", "micheals_lightsOFF", "Chnaged To: micheals_lightsOFF");
		addVisOption("michealspliff", "michealspliff", "Chnaged To: michealspliff");
		addVisOption("michealspliff_blend", "michealspliff_blend", "Chnaged To: michealspliff_blend");
		addVisOption("michealspliff_blend02", "michealspliff_blend02", "Chnaged To: michealspliff_blend02");
		addVisOption("militarybase_nightlight", "militarybase_nightlight", "Chnaged To: militarybase_nightlight");
		addVisOption("morebloomnumMods=3", "morebloomnumMods=3", "Chnaged To: morebloomnumMods=3");
		addVisOption("morgue_dark", "morgue_dark", "Chnaged To: morgue_dark");
		addVisOption("Mp_apart_mid", "Mp_apart_mid", "Chnaged To: Mp_apart_mid");
		addVisOption("MP_Bull_tost", "MP_Bull_tost", "Chnaged To: MP_Bull_tost");
		addVisOption("MP_Bull_tost_blend", "MP_Bull_tost_blend", "Chnaged To: MP_Bull_tost_blend");
		addVisOption("MP_corona_switch", "MP_corona_switch", "Chnaged To: MP_corona_switch");
		addVisOption("MP_death_grade", "MP_death_grade", "Chnaged To: MP_death_grade");
		addVisOption("MP_death_grade_blend01", "MP_death_grade_blend01", "Chnaged To: MP_death_grade_blend01");
		addVisOption("MP_death_grade_blend02", "MP_death_grade_blend02", "Chnaged To: MP_death_grade_blend02");
		addVisOption("MP_Garage_L", "MP_Garage_L", "Chnaged To: MP_Garage_L");
		addVisOption("MP_heli_cam", "MP_heli_cam", "Chnaged To: MP_heli_cam");
		addVisOption("MP_intro_logo", "MP_intro_logo", "Chnaged To: MP_intro_logo");
		addVisOption("MP_job_load", "MP_job_load", "Chnaged To: MP_job_load");
		addVisOption("MP_job_lose", "MP_job_lose", "Chnaged To: MP_job_lose");
		addVisOption("MP_job_win", "MP_job_win", "Chnaged To: MP_job_win");
		addVisOption("MP_Killstreak", "MP_Killstreak", "Chnaged To: MP_Killstreak");
		addVisOption("MP_Killstreak_blend", "MP_Killstreak_blend", "Chnaged To: MP_Killstreak_blend");
		addVisOption("MP_Loser", "MP_Loser", "Chnaged To: MP_Loser");
		addVisOption("MP_Loser_blend", "MP_Loser_blend", "Chnaged To: MP_Loser_blend");
		addVisOption("MP_lowgarage", "MP_lowgarage", "Chnaged To: MP_lowgarage");
		addVisOption("MP_MedGarage", "MP_MedGarage", "Chnaged To: MP_MedGarage");
		addVisOption("MP_Powerplay", "MP_Powerplay", "Chnaged To: MP_Powerplay");
		addVisOption("MP_Powerplay_blend", "MP_Powerplay_blend", "Chnaged To: MP_Powerplay_blend");
		addVisOption("MP_race_finish", "MP_race_finish", "Chnaged To: MP_race_finish");
		addVisOption("MP_select", "MP_select", "Chnaged To: MP_select");
		addVisOption("MP_Studio_Lo", "MP_Studio_Lo", "Chnaged To: MP_Studio_Lo");
		addVisOption("MPApartHigh", "MPApartHigh", "Chnaged To: MPApartHigh");
		addVisOption("Multipayer_spectatorCam", "Multipayer_spectatorCam", "Chnaged To: Multipayer_spectatorCam");
		addVisOption("multiplayer_ped_fight", "multiplayer_ped_fight", "Chnaged To: multiplayer_ped_fight");
		addVisOption("nervousRON_fog", "nervousRON_fog", "Chnaged To: nervousRON_fog");
		addVisOption("NeutralColorCode", "NeutralColorCode", "Chnaged To: NeutralColorCode");
		addVisOption("NeutralColorCodeBasic", "NeutralColorCodeBasic", "Chnaged To: NeutralColorCodeBasic");
		addVisOption("NeutralColorCodeLight", "NeutralColorCodeLight", "Chnaged To: NeutralColorCodeLight");
		addVisOption("NEW_abattoir", "NEW_abattoir", "Chnaged To: NEW_abattoir");
		addVisOption("new_bank", "new_bank", "Chnaged To: new_bank");
		addVisOption("NEW_jewel", "NEW_jewel", "Chnaged To: NEW_jewel");
		addVisOption("NEW_jewel_EXIT", "NEW_jewel_EXIT", "Chnaged To: NEW_jewel_EXIT");
		addVisOption("NEW_lesters", "NEW_lesters", "Chnaged To: NEW_lesters");
		addVisOption("NEW_ornate_bank", "NEW_ornate_bank", "Chnaged To: NEW_ornate_bank");
		addVisOption("NEW_ornate_bank_entrance", "NEW_ornate_bank_entrance", "Chnaged To: NEW_ornate_bank_entrance");
		addVisOption("NEW_ornate_bank_office", "NEW_ornate_bank_office", "Chnaged To: NEW_ornate_bank_office");
		addVisOption("NEW_ornate_bank_safe", "NEW_ornate_bank_safe", "Chnaged To: NEW_ornate_bank_safe");
		addVisOption("New_sewers", "New_sewers", "Chnaged To: New_sewers");
		addVisOption("NEW_shrinksOffice", "NEW_shrinksOffice", "Chnaged To: NEW_shrinksOffice");
		addVisOption("NEW_station_unfinished", "NEW_station_unfinished", "Chnaged To: NEW_station_unfinished");
		addVisOption("new_stripper_changing", "new_stripper_changing", "Chnaged To: new_stripper_changing");
		addVisOption("NEW_trevorstrailer", "NEW_trevorstrailer", "Chnaged To: NEW_trevorstrailer");
		addVisOption("NEW_tunnels", "NEW_tunnels", "Chnaged To: NEW_tunnels");
		addVisOption("NEW_tunnels_ditch", "NEW_tunnels_ditch", "Chnaged To: NEW_tunnels_ditch");
		addVisOption("new_tunnels_entrance", "new_tunnels_entrance", "Chnaged To: new_tunnels_entrance");
		addVisOption("NEW_tunnels_hole", "NEW_tunnels_hole", "Chnaged To: NEW_tunnels_hole");
		addVisOption("NEW_yellowtunnels", "NEW_yellowtunnels", "Chnaged To: NEW_yellowtunnels");
		addVisOption("NewMicheal", "NewMicheal", "Chnaged To: NewMicheal");
		addVisOption("NewMicheal_night", "NewMicheal_night", "Chnaged To: NewMicheal_night");
		addVisOption("NewMicheal_upstairs", "NewMicheal_upstairs", "Chnaged To: NewMicheal_upstairs");
		addVisOption("NewMichealgirly", "NewMichealgirly", "Chnaged To: NewMichealgirly");
		addVisOption("NewMichealstoilet", "NewMichealstoilet", "Chnaged To: NewMichealstoilet");
		addVisOption("NewMichealupstairs", "NewMichealupstairs", "Chnaged To: NewMichealupstairs");
		addVisOption("NewMod", "NewMod", "Chnaged To: NewMod");
		addVisOption("nextgen", "nextgen", "Chnaged To: nextgen");
		addVisOption("NO_coronas", "NO_coronas", "Chnaged To: NO_coronas");
		addVisOption("NO_fog_alpha", "NO_fog_alpha", "Chnaged To: NO_fog_alpha");
		addVisOption("NO_streetAmbient", "NO_streetAmbient", "Chnaged To: NO_streetAmbient");
		addVisOption("NO_weather", "NO_weather", "Chnaged To: NO_weather");
		addVisOption("NoAmbientmult", "NoAmbientmult", "Chnaged To: NoAmbientmult");
		addVisOption("NoAmbientmult_interior", "NoAmbientmult_interior", "Chnaged To: NoAmbientmult_interior");
		addVisOption("NOdirectLight", "NOdirectLight", "Chnaged To: NOdirectLight");
		addVisOption("NOrain", "NOrain", "Chnaged To: NOrain");
		addVisOption("overwater", "overwater", "Chnaged To: overwater");
		addVisOption("Paleto", "Paleto", "Chnaged To: Paleto");
		addVisOption("paleto_nightlight", "paleto_nightlight", "Chnaged To: paleto_nightlight");
		addVisOption("paleto_opt", "paleto_opt", "Chnaged To: paleto_opt");
		addVisOption("PERSHING_water_reflect", "PERSHING_water_reflect", "Chnaged To: PERSHING_water_reflect");
		addVisOption("phone_cam", "phone_cam", "Chnaged To: phone_cam");
		addVisOption("phone_cam1", "phone_cam1", "Chnaged To: phone_cam1");
		addVisOption("phone_cam10", "phone_cam10", "Chnaged To: phone_cam10");
		addVisOption("phone_cam11", "phone_cam11", "Chnaged To: phone_cam11");
		addVisOption("phone_cam12", "phone_cam12", "Chnaged To: phone_cam12");
		addVisOption("phone_cam13", "phone_cam13", "Chnaged To: phone_cam13");
		addVisOption("phone_cam2", "phone_cam2", "Chnaged To: phone_cam2");
		addVisOption("phone_cam3", "phone_cam3", "Chnaged To: phone_cam3");
		addVisOption("phone_cam4", "phone_cam4", "Chnaged To: phone_cam4");
		addVisOption("phone_cam5", "phone_cam5", "Chnaged To: phone_cam5");
		addVisOption("phone_cam6", "phone_cam6", "Chnaged To: phone_cam6");
		addVisOption("phone_cam7", "phone_cam7", "Chnaged To: phone_cam7");
		addVisOption("phone_cam9", "phone_cam9", "Chnaged To: phone_cam9");
		addVisOption("plane_inside_mode", "plane_inside_mode", "Chnaged To: plane_inside_mode");
		addVisOption("player_transition", "player_transition", "Chnaged To: player_transition");
		addVisOption("player_transition_no_scanlines", "player_transition_no_scanlines", "Chnaged To: player_transition_no_scanlines");
		addVisOption("player_transition_scanlines", "player_transition_scanlines", "Chnaged To: player_transition_scanlines");
		addVisOption("PlayerSwitchNeutralFlash", "PlayerSwitchNeutralFlash", "Chnaged To: PlayerSwitchNeutralFlash");
		addVisOption("PlayerSwitchPulse", "PlayerSwitchPulse", "Chnaged To: PlayerSwitchPulse");
		addVisOption("PoliceStation", "PoliceStation", "Chnaged To: PoliceStation");
		addVisOption("PoliceStationDark", "PoliceStationDark", "Chnaged To: PoliceStationDark");
		addVisOption("polluted", "polluted", "Chnaged To: polluted");
		addVisOption("poolsidewaterreflection2", "poolsidewaterreflection2", "Chnaged To: poolsidewaterreflection2");
		addVisOption("PORT_heist_underwater", "PORT_heist_underwater", "Chnaged To: PORT_heist_underwater");
		addVisOption("powerplant_nightlight", "powerplant_nightlight", "Chnaged To: powerplant_nightlight");
		addVisOption("powerstation", "powerstation", "Chnaged To: powerstation");
		addVisOption("prison_nightlight", "prison_nightlight", "Chnaged To: prison_nightlight");
		addVisOption("projector", "projector", "Chnaged To: projector");
		addVisOption("prologue", "prologue", "Chnaged To: prologue");
		addVisOption("prologue_ending_fog", "prologue_ending_fog", "Chnaged To: prologue_ending_fog");
		addVisOption("prologue_ext_art_amb", "prologue_ext_art_amb", "Chnaged To: prologue_ext_art_amb");
		addVisOption("prologue_reflection_opt", "prologue_reflection_opt", "Chnaged To: prologue_reflection_opt");
		addVisOption("prologue_shootout", "prologue_shootout", "Chnaged To: prologue_shootout");
		addVisOption("Prologue_shootout_opt", "Prologue_shootout_opt", "Chnaged To: Prologue_shootout_opt");
		addVisOption("pulse", "pulse", "Chnaged To: pulse");
		addVisOption("RaceTurboDark", "RaceTurboDark", "Chnaged To: RaceTurboDark");
		addVisOption("RaceTurboFlash", "RaceTurboFlash", "Chnaged To: RaceTurboFlash");
		addVisOption("RaceTurboLight", "RaceTurboLight", "Chnaged To: RaceTurboLight");
		addVisOption("ranch", "ranch", "Chnaged To: ranch");
		addVisOption("REDMIST", "REDMIST", "Chnaged To: REDMIST");
		addVisOption("REDMIST_blend", "REDMIST_blend", "Chnaged To: REDMIST_blend");
		addVisOption("ReduceDrawDistance", "ReduceDrawDistance", "Chnaged To: ReduceDrawDistance");
		addVisOption("ReduceDrawDistanceMAP", "ReduceDrawDistanceMAP", "Chnaged To: ReduceDrawDistanceMAP");
		addVisOption("ReduceDrawDistanceMission", "ReduceDrawDistanceMission", "Chnaged To: ReduceDrawDistanceMission");
		addVisOption("reducelightingcost", "reducelightingcost", "Chnaged To: reducelightingcost");
		addVisOption("ReduceSSAO", "ReduceSSAO", "Chnaged To: ReduceSSAO");
		addVisOption("reducewaterREF", "reducewaterREF", "Chnaged To: reducewaterREF");
		addVisOption("refit", "refit", "Chnaged To: refit");
		addVisOption("reflection_correct_ambient", "reflection_correct_ambient", "Chnaged To: reflection_correct_ambient");
		addVisOption("RemoteSniper", "RemoteSniper", "Chnaged To: RemoteSniper");
		addVisOption("resvoire_reflection", "resvoire_reflection", "Chnaged To: resvoire_reflection");
		addVisOption("SALTONSEA", "SALTONSEA", "Chnaged To: SALTONSEA");
		addVisOption("sandyshore_nightlight", "sandyshore_nightlight", "Chnaged To: sandyshore_nightlight");
		addVisOption("SAWMILL", "SAWMILL", "Chnaged To: SAWMILL");
		addVisOption("scanline_cam", "scanline_cam", "Chnaged To: scanline_cam");
		addVisOption("scanline_cam_cheap", "scanline_cam_cheap", "Chnaged To: scanline_cam_cheap");
		addVisOption("scope_zoom_in", "scope_zoom_in", "Chnaged To: scope_zoom_in");
		addVisOption("scope_zoom_out", "scope_zoom_out", "Chnaged To: scope_zoom_out");
		addVisOption("secret_camera", "secret_camera", "Chnaged To: secret_camera");
		addVisOption("services_nightlight", "services_nightlight", "Chnaged To: services_nightlight");
		addVisOption("shades_pink", "shades_pink", "Chnaged To: shades_pink");
		addVisOption("shades_yellow", "shades_yellow", "Chnaged To: shades_yellow");
		addVisOption("SheriffStation", "SheriffStation", "Chnaged To: SheriffStation");
		addVisOption("ship_explosion_underwater", "ship_explosion_underwater", "Chnaged To: ship_explosion_underwater");
		addVisOption("ship_lighting", "ship_lighting", "Chnaged To: ship_lighting");
		addVisOption("Shop247", "Shop247", "Chnaged To: Shop247");
		addVisOption("Shop247_none", "Shop247_none", "Chnaged To: Shop247_none");
		addVisOption("sleeping", "sleeping", "Chnaged To: sleeping");
		addVisOption("SnipernumMods=7", "SnipernumMods=7", "Chnaged To: SnipernumMods=7");
		addVisOption("SP1_03_drawDistance", "SP1_03_drawDistance", "Chnaged To: SP1_03_drawDistance");
		addVisOption("spectator1", "spectator1", "Chnaged To: spectator1");
		addVisOption("spectator10", "spectator10", "Chnaged To: spectator10");
		addVisOption("spectator2", "spectator2", "Chnaged To: spectator2");
		addVisOption("spectator3", "spectator3", "Chnaged To: spectator3");
		addVisOption("spectator4", "spectator4", "Chnaged To: spectator4");
		addVisOption("spectator5", "spectator5", "Chnaged To: spectator5");
		addVisOption("spectator6", "spectator6", "Chnaged To: spectator6");
		addVisOption("spectator7", "spectator7", "Chnaged To: spectator7");
		addVisOption("spectator8", "spectator8", "Chnaged To: spectator8");
		addVisOption("spectator9", "spectator9", "Chnaged To: spectator9");
		addVisOption("StadLobby", "StadLobby", "Chnaged To: StadLobby");
		addVisOption("stc_coroners", "stc_coroners", "Chnaged To: stc_coroners");
		addVisOption("stc_deviant_bedroom", "stc_deviant_bedroom", "Chnaged To: stc_deviant_bedroom");
		addVisOption("stc_deviant_lounge", "stc_deviant_lounge", "Chnaged To: stc_deviant_lounge");
		addVisOption("stc_franklinsHouse", "stc_franklinsHouse", "Chnaged To: stc_franklinsHouse");
		addVisOption("stc_trevors", "stc_trevors", "Chnaged To: stc_trevors");
		addVisOption("stoned", "stoned", "Chnaged To: stoned");
		addVisOption("stoned_aliens", "stoned_aliens", "Chnaged To: stoned_aliens");
		addVisOption("stoned_cutscene", "stoned_cutscene", "Chnaged To: stoned_cutscene");
		addVisOption("stoned_monkeys", "stoned_monkeys", "Chnaged To: stoned_monkeys");
		addVisOption("StreetLightingJunction", "StreetLightingJunction", "Chnaged To: StreetLightingJunction");
		addVisOption("StreetLightingtraffic", "StreetLightingtraffic", "Chnaged To: StreetLightingtraffic");
		addVisOption("STRIP_changing", "STRIP_changing", "Chnaged To: STRIP_changing");
		addVisOption("STRIP_nofog", "STRIP_nofog", "Chnaged To: STRIP_nofog");
		addVisOption("STRIP_office", "STRIP_office", "Chnaged To: STRIP_office");
		addVisOption("STRIP_stage", "STRIP_stage", "Chnaged To: STRIP_stage");
		addVisOption("subBASE_water_ref", "subBASE_water_ref", "Chnaged To: subBASE_water_ref");
		addVisOption("sunglasses", "sunglasses", "Chnaged To: sunglasses");
		addVisOption("superDARK", "superDARK", "Chnaged To: superDARK");
		addVisOption("switch_cam_1", "switch_cam_1", "Chnaged To: switch_cam_1");
		addVisOption("switch_cam_2", "switch_cam_2", "Chnaged To: switch_cam_2");
		addVisOption("telescope", "telescope", "Chnaged To: telescope");
		addVisOption("torpedo", "torpedo", "Chnaged To: torpedo");
		addVisOption("traffic_skycam", "traffic_skycam", "Chnaged To: traffic_skycam");
		addVisOption("trailer_explosion_optimise", "trailer_explosion_optimise", "Chnaged To: trailer_explosion_optimise");
		addVisOption("TREVOR", "TREVOR", "Chnaged To: TREVOR");
		addVisOption("TrevorColorCode", "TrevorColorCode", "Chnaged To: TrevorColorCode");
		addVisOption("TrevorColorCodeBasic", "TrevorColorCodeBasic", "Chnaged To: TrevorColorCodeBasic");
		addVisOption("Trevors_room", "Trevors_room", "Chnaged To: Trevors_room");
		addVisOption("trevorspliff", "trevorspliff", "Chnaged To: trevorspliff");
		addVisOption("trevorspliff_blend", "trevorspliff_blend", "Chnaged To: trevorspliff_blend");
		addVisOption("trevorspliff_blend02", "trevorspliff_blend02", "Chnaged To: trevorspliff_blend02");
		addVisOption("Tunnel", "Tunnel", "Chnaged To: Tunnel");
		addVisOption("tunnel_entrance", "tunnel_entrance", "Chnaged To: tunnel_entrance");
		addVisOption("tunnel_entrance_INT", "tunnel_entrance_INT", "Chnaged To: tunnel_entrance_INT");
		addVisOption("TUNNEL_green", "TUNNEL_green", "Chnaged To: TUNNEL_green");
		addVisOption("Tunnel_green1", "Tunnel_green1", "Chnaged To: Tunnel_green1");
		addVisOption("TUNNEL_green_ext", "TUNNEL_green_ext", "Chnaged To: TUNNEL_green_ext");
		addVisOption("TUNNEL_orange", "TUNNEL_orange", "Chnaged To: TUNNEL_orange");
		addVisOption("TUNNEL_orange_exterior", "TUNNEL_orange_exterior", "Chnaged To: TUNNEL_orange_exterior");
		addVisOption("TUNNEL_white", "TUNNEL_white", "Chnaged To: TUNNEL_white");
		addVisOption("TUNNEL_yellow", "TUNNEL_yellow", "Chnaged To: TUNNEL_yellow");
		addVisOption("TUNNEL_yellow_ext", "TUNNEL_yellow_ext", "Chnaged To: TUNNEL_yellow_ext");
		addVisOption("ufo", "ufo", "Chnaged To: ufo");
		addVisOption("ufo_deathray", "ufo_deathray", "Chnaged To: ufo_deathray");
		addVisOption("underwater", "underwater", "Chnaged To: underwater");
		addVisOption("underwater_deep", "underwater_deep", "Chnaged To: underwater_deep");
		addVisOption("underwater_deep_clear", "underwater_deep_clear", "Chnaged To: underwater_deep_clear");
		addVisOption("v_abattoir", "v_abattoir", "Chnaged To: v_abattoir");
		addVisOption("V_Abattoir_Cold", "V_Abattoir_Cold", "Chnaged To: V_Abattoir_Cold");
		addVisOption("v_bahama", "v_bahama", "Chnaged To: v_bahama");
		addVisOption("v_cashdepot", "v_cashdepot", "Chnaged To: v_cashdepot");
		addVisOption("V_FIB_IT3", "V_FIB_IT3", "Chnaged To: V_FIB_IT3");
		addVisOption("V_FIB_IT3_alt", "V_FIB_IT3_alt", "Chnaged To: V_FIB_IT3_alt");
		addVisOption("V_FIB_IT3_alt5", "V_FIB_IT3_alt5", "Chnaged To: V_FIB_IT3_alt5");
		addVisOption("V_FIB_stairs", "V_FIB_stairs", "Chnaged To: V_FIB_stairs");
		addVisOption("v_foundry", "v_foundry", "Chnaged To: v_foundry");
		addVisOption("v_janitor", "v_janitor", "Chnaged To: v_janitor");
		addVisOption("v_jewel2", "v_jewel2", "Chnaged To: v_jewel2");
		addVisOption("v_metro", "v_metro", "Chnaged To: v_metro");
		addVisOption("V_Metro2", "V_Metro2", "Chnaged To: V_Metro2");
		addVisOption("V_Metro_station", "V_Metro_station", "Chnaged To: V_Metro_station");
		addVisOption("v_michael", "v_michael", "Chnaged To: v_michael");
		addVisOption("v_michael_lounge", "v_michael_lounge", "Chnaged To: v_michael_lounge");
		addVisOption("V_Office_smoke", "V_Office_smoke", "Chnaged To: V_Office_smoke");
		addVisOption("V_Office_smoke_ext", "V_Office_smoke_ext", "Chnaged To: V_Office_smoke_ext");
		addVisOption("V_Office_smoke_Fire", "V_Office_smoke_Fire", "Chnaged To: V_Office_smoke_Fire");
		addVisOption("v_recycle", "v_recycle", "Chnaged To: v_recycle");
		addVisOption("V_recycle_dark", "V_recycle_dark", "Chnaged To: V_recycle_dark");
		addVisOption("V_recycle_light", "V_recycle_light", "Chnaged To: V_recycle_light");
		addVisOption("V_recycle_mainroom", "V_recycle_mainroom", "Chnaged To: V_recycle_mainroom");
		addVisOption("v_rockclub", "v_rockclub", "Chnaged To: v_rockclub");
		addVisOption("V_Solomons", "V_Solomons", "Chnaged To: V_Solomons");
		addVisOption("v_strip3", "v_strip3", "Chnaged To: v_strip3");
		addVisOption("V_strip_nofog", "V_strip_nofog", "Chnaged To: V_strip_nofog");
		addVisOption("V_strip_office", "V_strip_office", "Chnaged To: V_strip_office");
		addVisOption("v_strpchangerm", "v_strpchangerm", "Chnaged To: v_strpchangerm");
		addVisOption("v_sweat", "v_sweat", "Chnaged To: v_sweat");
		addVisOption("v_sweat_entrance", "v_sweat_entrance", "Chnaged To: v_sweat_entrance");
		addVisOption("v_sweat_NoDirLight", "v_sweat_NoDirLight", "Chnaged To: v_sweat_NoDirLight");
		addVisOption("v_torture", "v_torture", "Chnaged To: v_torture");
		addVisOption("Vagos", "Vagos", "Chnaged To: Vagos");
		addVisOption("vagos_extlight_small", "vagos_extlight_small", "Chnaged To: vagos_extlight_small");
		addVisOption("VAGOS_new_garage", "VAGOS_new_garage", "Chnaged To: VAGOS_new_garage");
		addVisOption("VAGOS_new_hangout", "VAGOS_new_hangout", "Chnaged To: VAGOS_new_hangout");
		addVisOption("VagosSPLASH", "VagosSPLASH", "Chnaged To: VagosSPLASH");
		addVisOption("VC_tunnel_entrance", "VC_tunnel_entrance", "Chnaged To: VC_tunnel_entrance");
		addVisOption("venice_canal_tunnel", "venice_canal_tunnel", "Chnaged To: venice_canal_tunnel");
		addVisOption("vespucci_garage", "vespucci_garage", "Chnaged To: vespucci_garage");
		addVisOption("warehouse", "warehouse", "Chnaged To: warehouse");
		addVisOption("WATER_hills", "WATER_hills", "Chnaged To: WATER_hills");
		addVisOption("WATER_lab", "WATER_lab", "Chnaged To: WATER_lab");
		addVisOption("WATER_lab_cooling", "WATER_lab_cooling", "Chnaged To: WATER_lab_cooling");
		addVisOption("WATER_militaryPOOP", "WATER_militaryPOOP", "Chnaged To: WATER_militaryPOOP");
		addVisOption("WATER_muddy", "WATER_muddy", "Chnaged To: WATER_muddy");
		addVisOption("WATER_port", "WATER_port", "Chnaged To: WATER_port");
		addVisOption("WATER_REF_malibu", "WATER_REF_malibu", "Chnaged To: WATER_REF_malibu");
		addVisOption("WATER_refmap_high", "WATER_refmap_high", "Chnaged To: WATER_refmap_high");
		addVisOption("WATER_refmap_hollywoodlake", "WATER_refmap_hollywoodlake", "Chnaged To: WATER_refmap_hollywoodlake");
		addVisOption("WATER_refmap_low", "WATER_refmap_low", "Chnaged To: WATER_refmap_low");
		addVisOption("WATER_refmap_med", "WATER_refmap_med", "Chnaged To: WATER_refmap_med");
		addVisOption("WATER_refmap_off", "WATER_refmap_off", "Chnaged To: WATER_refmap_off");
		addVisOption("WATER_refmap_poolside", "WATER_refmap_poolside", "Chnaged To: WATER_refmap_poolside");
		addVisOption("WATER_refmap_silverlake", "WATER_refmap_silverlake", "Chnaged To: WATER_refmap_silverlake");
		addVisOption("WATER_refmap_venice", "WATER_refmap_venice", "Chnaged To: WATER_refmap_venice");
		addVisOption("WATER_refmap_verylow", "WATER_refmap_verylow", "Chnaged To: WATER_refmap_verylow");
		addVisOption("WATER_resevoir", "WATER_resevoir", "Chnaged To: WATER_resevoir");
		addVisOption("WATER_river", "WATER_river", "Chnaged To: WATER_river");
		addVisOption("WATER_salton", "WATER_salton", "Chnaged To: WATER_salton");
		addVisOption("WATER_salton_bottom", "WATER_salton_bottom", "Chnaged To: WATER_salton_bottom");
		addVisOption("WATER_shore", "WATER_shore", "Chnaged To: WATER_shore");
		addVisOption("WATER_silty", "WATER_silty", "Chnaged To: WATER_silty");
		addVisOption("WATER_silverlake", "WATER_silverlake", "Chnaged To: WATER_silverlake");
		addVisOption("whitenightlighting", "whitenightlighting", "Chnaged To: whitenightlighting");
		addVisOption("WhiteOut", "WhiteOut", "Chnaged To: WhiteOut");
		addVisOption("yell_tunnel_nodirect", "yell_tunnel_nodirect", "Chnaged To: yell_tunnel_nodirect");
		break;
#pragma endregion
#pragma region tunables
	case tunables:
		subTitle("MODIFY TUNABLES");
		addOption("Free Shopping");
		addOption("Remove Betting Limit");
		addOption("Remove LSC Price Cap");
		addBoolOption("Valentines Day DLC", Valentines);
		addBoolOption("Toggle Christmas DLC", XMas);
		addBoolOption("Independence Day DLC", Independence);
		addBoolOption("Toggle New Year DLC", NY);
		addBoolOption("Snow Onliine", Tunable_Snow);
		switch (getOption())
		{
		case 1:
			SetTunable(58, 0x00000000);
			SetTunable(60, 0x00000000);
			SetTunable(60, 0x00000000);
			SetTunable(61, 0x00000000);
			SetTunable(63, 0x00000000);
			SetTunable(64, 0x00000000);
			SetTunable(65, 0x00000000);
			SetTunable(66, 0x00000000);
			SetTunable(67, 0x00000000);
			break;
		case 2: SetTunable(82, 0x05F5E0FF); break;
		case 3: SetTunable(142, 0x05F5E0FF); break;
		case 4: if (Valentines == false)
		{
			Valentines = true;
			SetTunable(4824, 0x00000000);
		}
				else if (Valentines == true)
				{
					Valentines = false;
					SetTunable(4824, 0x00000001);
				}
				break;
		case 5: if (XMas == false)
		{
			SetTunable(6870, 0x00000000);
			SetTunable(6871, 0x00000000);
			SetTunable(6874, 0x00000000);
			SetTunable(6875, 0x00000000);
			SetTunable(6876, 0x00000000);
			XMas = true;
		}
				else if (XMas == true)
				{
					SetTunable(6870, 0x00000001);
					SetTunable(6871, 0x00000001);
					SetTunable(6874, 0x00000001);
					SetTunable(6875, 0x00000001);
					SetTunable(6876, 0x00000001);
					XMas = false;
				}
				break;
		case 6: if (Independence == false)
		{
			SetTunable(6000, 0x00000001);
			SetTunable(6008, 0x00000000);
			SetTunable(6014, 0x00000001);
			SetTunable(6046, 0x00000001);
			Independence = true;
		}
				else if (Independence == true)
				{
					SetTunable(6000, 0x00000000);
					SetTunable(6008, 0x00000001);
					SetTunable(6014, 0x00000000);
					SetTunable(6046, 0x00000000);
					Independence = false;
				}
				break;
		case 7: if (NY == false)
		{
			SetTunable(6926, 0x00000000);
			SetTunable(6927, 0x00000000);
			NY = true;
		}
				else if (NY == true)
				{
					SetTunable(6926, 0x00000001);
					SetTunable(6927, 0x00000001);
					NY = false;
				}
				break;
		case 8:
			Tunable_Snow = !Tunable_Snow;
			if (Tunable_Snow == false)
			{
				SetTunable(4715, 0);
			}
			else if (Tunable_Snow == true)
			{
				SetTunable(4715, 1);
			}
			break;
		}
		break;
#pragma endregion
#pragma region Settings
	case Settings:
		subTitle("Settings");
		addSubmenuOption("Banners", Settings_Banners, "1/8");
		addSubmenuOption("Body", Settings_Body, "2/8");
		addSubmenuOption("Scroller", Settings_Scroller, "3/8");
		addSubmenuOption("Indicators", Settings_Indicators, "4/8");
		addBoolOption("Sounds", menuSounds, "5/8");
		addBoolOption("Instructions", instructions, "6/8");
		addCustomBoolOption("Left Sided", menuXCoord, 0.815f, "7/8");
		addIntOption("Max Options", &maxOptions, 1, 16, false, "8/8");
		addSubmenuOption("Players Talking Options", playerstalking);
		addSubmenuOption("Esp Players Colors", EspColor);
		switch (getOption())
		{
		case 1: break;
		case 2: break;
		case 3: break;
		case 4: break;
		case 5: menuSounds = !menuSounds; break;
		case 6: instructions = !instructions; break;
		case 7: if (menuXCoord == 0.815f)
				{
					menuXCoord = 0.188f; textXCoord = 0.08f; SubTitleXCoord = 0.082f; OnOff = 0.29f;
					InfoX = 0.4135f; InfoLLX = 0.302f; InfoRLX = 0.5245f; InfoTextX = 0.31f; InfoTextX2 = 0.43f;
					_Money = 0.345f; _Rank = 0.335f; _K_D = 0.33f; _Weapon = 0.375f; _Alive = 0.335f; _Distance = 0.35f; __Xcoords = 0.44f; _In_Vehicle = 0.485f; __Xcoords2 = 0.465f;
				}
				else
				{
					menuXCoord = 0.815f; textXCoord = 0.71f; SubTitleXCoord = 0.71f; OnOff = 0.9f;
					InfoX = 0.59f; InfoLLX = 0.4785f; InfoRLX = 0.7015f; InfoTextX = 0.485f; InfoTextX2 = 0.6f;
					_Money = 0.52f; _Rank = 0.51f; _K_D = 0.505f; _Weapon = 0.55f; _Alive = 0.510f; _Distance = 0.525f; __Xcoords = 0.61f; _In_Vehicle = 0.655f; __Xcoords2 = 0.635f;
				}
				break;
		case 8: break;
		case 9: break;
		case 10: break;
		}	break;
#pragma endregion 
#pragma region playerstalking
	case EspColor:
		subTitle("ESP PLAYERS COLOR");
		addIntOption("Red", &MarkerRed, 0, 255, true);
		addIntOption("Green", &markergreen, 0, 255, true);
		addIntOption("Blue", &markerblue, 0, 255, true);
		//addFloatOption("Draw Fps X", &Draw_Fps_X, 0, 1, true, 0);//9
		//addFloatOption("Draw Fps Y", &Draw_Fps_Y, 0, 1, true, 0);//9
		break;
#pragma endregion 
#pragma region playerstalking
	case playerstalking:
		subTitle("PLAYERS TALKING OPTIONS");
		addIntOption("Red", &talkerR, 0, 255, true);
		addIntOption("Green", &talkerG, 0, 255, true);
		addIntOption("Blue", &talkerB, 0, 255, true);
		addIntOption("Font", &talkerFont, 0, 7, true);
		//addFloatOption("Draw Fps X", &Draw_Fps_X, 0, 1, true, 0);//9
		//addFloatOption("Draw Fps Y", &Draw_Fps_Y, 0, 1, true, 0);//9
		break;

#pragma endregion
#pragma region
	case Settings_Banners:
		subTitle("Banner");
		addIntOption("Text Red", &bannerTextRed, 0, 255, true, "1/9");
		addIntOption("Text Green", &bannerTextGreen, 0, 255, true, "2/9");
		addIntOption("Text Blue", &bannerTextBlue, 0, 255, true, "3/9");
		addIntOption("Text Opacity", &bannerTextOpacity, 0, 255, true, "4/9");
		addIntOption("Text Font", &bannerTextFont, 0, 7, false, "5/9");
		addIntOption("Rect Red", &bannerRectRed, 0, 255, true, "6/9");
		addIntOption("Rect Green", &bannerRectGreen, 0, 255, true, "7/9");
		addIntOption("Rect Blue", &bannerRectBlue, 0, 255, true, "8/9");
		addIntOption("Rect Opacity", &bannerRectOpacity, 0, 255, true, "9/9");
		break;
#pragma endregion
#pragma region
	case Settings_Body:
		subTitle("BODY");
		addIntOption("Text Red", &optionsRed, 0, 255, true, "1/9");
		addIntOption("Text Green", &optionsGreen, 0, 255, true, "2/9");
		addIntOption("Text Blue", &optionsBlue, 0, 255, true, "3/9");
		addIntOption("Text Opacity", &optionsOpacity, 0, 255, true, "4/9");
		addIntOption("Text Font", &optionsFont, 0, 7, false, "5/9");
		addIntOption("Rect Red", &backgroundRed, 0, 255, true, "6/9");
		addIntOption("Rect Green", &backgroundGreen, 0, 255, true, "7/9");
		addIntOption("Rect Blue", &backgroundBlue, 0, 255, true, "8/9");
		addIntOption("Rect Opacity", &backgroundOpacity, 0, 255, true, "9/9");
		break;
#pragma endregion
#pragma region
	case Settings_Scroller:
		subTitle("SCROLLER");
		addIntOption("Red", &scrollerRed, 0, 255, true, "1/4");
		addIntOption("Green", &scrollerGreen, 0, 255, true, "2/4");
		addIntOption("Blue", &scrollerBlue, 0, 255, true, "3/4");
		addIntOption("Opacity", &scrollerOpacity, 0, 255, true, "4/4");
		break;
#pragma endregion
#pragma region
	case Settings_Indicators:
		subTitle("INDICATORS");
		addIntOption("Red", &indicatorRed, 0, 255, true, "1/4");
		addIntOption("Green", &indicatorGreen, 0, 255, true, "2/4");
		addIntOption("Blue", &indicatorBlue, 0, 255, true, "3/4");
		addIntOption("Opacity", &indicatorOpacity, 0, 255, true, "4/4");
		break; 
#pragma endregion
#pragma region
	}
	resetVars();
	return true;
}//

void Thread(uint64_t nothing)
{
	sleep(30000); //Wait until native table initialization
	g_Natives = (Native_s**)FindNativeTableAddress();
	PatchInJump(NativeAddress(0x9FAB6729, true), (int)Hook, false);
	sys_ppu_thread_exit(nothing);
}
extern "C" int PRX_ENTRY()
{
	sys_ppu_thread_t ThreadModuleID;
	sys_ppu_thread_create(&ThreadModuleID, Thread, 0, 10, 0x10, 0, "THE UMBRELLA 1.27");
	return SYS_PRX_RESIDENT;
}