#include <windows.h>
#include "osal_keys.h"

#ifdef __cplusplus
extern "C" {
#endif

static const unsigned char WIN_HID_TO_NATIVE[256] = {
255,255,255,255, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76,
 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 49, 50,
 51, 52, 53, 54, 55, 56, 57, 48, 13, 27,  8,  9, 32,189,187,219,
221,220,255,186,222,192,188,190,191, 20,112,113,114,115,116,117,
118,119,120,121,122,123, 44,145, 19, 45, 36, 33, 46, 35, 34, 39,
 37, 40, 38,144,111,106,109,107,255, 97, 98, 99,100,101,102,103,
104,105, 96,110,255,255,255,255,124,125,126,127,128,129,130,131,
132,133,134,135,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
 17, 16, 18,255,255,255,255,255,255,  1,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255
};

static const char KEYCODE_WINDOWS_NAME_DATA[] =
"\0'\0,\0-\0.\0/\0;\0=\0A\0B\0Backspace\0C\0Caps Lock\0D\0Delete\0E\0End\0"
"Enter\0Escape\0F\0F1\0F10\0F11\0F12\0F2\0F3\0F4\0F5\0F6\0F7\0F8\0F9\0G\0H"
"\0Home\0I\0Insert\0J\0K\0L\0Left\0Left Alt\0Left Control\0Left Shift\0Lef"
"t Windows\0M\0N\0O\0P\0Page Down\0Page Up\0Pause\0Print Screen\0Q\0R\0Rig"
"ht\0Right Alt\0Right Control\0Right Shift\0Right Windows\0S\0Scroll Lock"
"\0T\0Tab\0U\0V\0W\0X\0Y\0Z\0[\0\\\0]\0`";
static const unsigned short KEYCODE_WINDOWS_NAME_OFFSET[] = {
	0,0,0,0,15,17,29,41,50,69,110,112,119,128,130,132,185,187,189,191,230,232,
	290,304,310,312,314,316,318,320,72,84,90,93,96,99,102,105,108,76,0,62,19,
	306,0,5,13,322,326,324,0,11,1,328,3,7,9,31,71,86,89,92,95,98,101,104,107,74,
	78,82,217,292,211,121,114,203,43,52,193,234,134,198,208,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,56,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,148,161,139,172,250,264,240,276
};

EXPORT void CALL osal_keys_init()
{
}

EXPORT void CALL osal_keys_quit()
{
}

EXPORT void CALL osal_keys_update_state()
{
}

EXPORT unsigned int CALL osal_is_key_pressed(unsigned int _key, unsigned int _mask)
{
	if (_key == 0 || _key > 255)
		return 0;
	return GetAsyncKeyState(WIN_HID_TO_NATIVE[_key]) & _mask;
}

EXPORT const char * CALL osal_keycode_name(unsigned int _hidCode)
{
	unsigned offset;
	if (232 <= _hidCode)
		return NULL;
	offset = KEYCODE_WINDOWS_NAME_OFFSET[_hidCode];
	if (offset == 0)
		return NULL;
	return KEYCODE_WINDOWS_NAME_DATA + offset;
}

#ifdef __cplusplus
}
#endif
