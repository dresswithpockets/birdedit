/**********************************************************************************************
*
*   rIcons - Icons pack intended for tools development with raygui
*
*   CONFIGURATION:
*
*   #define RICONS_IMPLEMENTATION
*       Generates the implementation of the library into the included file.
*       If not defined, the library is in header only mode and can be included in other headers
*       or source files without problems. But only ONE file should hold the implementation.
*
*   #define RICONS_STANDALONE
*       Avoid raylib.h header inclusion in this file. Icon drawing function must be provided by
*       the user (check library implementation for further details).
*
*   LICENSE: zlib/libpng
*
*   Copyright (c) 2019 Ramon Santamaria (@raysan5)
*
*   This software is provided "as-is", without any express or implied warranty. In no event
*   will the authors be held liable for any damages arising from the use of this software.
*
*   Permission is granted to anyone to use this software for any purpose, including commercial
*   applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*     1. The origin of this software must not be misrepresented; you must not claim that you
*     wrote the original software. If you use this software in a product, an acknowledgment
*     in the product documentation would be appreciated but is not required.
*
*     2. Altered source versions must be plainly marked as such, and must not be misrepresented
*     as being the original software.
*
*     3. This notice may not be removed or altered from any source distribution.
*
**********************************************************************************************/

#ifndef RICONS_H
#define RICONS_H

//----------------------------------------------------------------------------------
// Defines and Macros
//----------------------------------------------------------------------------------
#define RICON_MAX_ICONS       256       // Maximum number of icons
#define RICON_SIZE             16       // Size of icons (squared)

// Icons data is defined by bit array (every bit represents one pixel)
// Those arrays are stored as unsigned int data arrays, so every array
// element defines 32 pixels (bits) of information
// Number of elemens depend on RICON_SIZE (by default 16x16 pixels)
#define RICON_DATA_ELEMENTS   (RICON_SIZE*RICON_SIZE/32)

#define RICON_MAX_NAME_LENGTH  32       // Maximum length of icon name id

//----------------------------------------------------------------------------------
// Types and Structures Definition
//----------------------------------------------------------------------------------
// ...

//----------------------------------------------------------------------------------
// Icons enumeration
//----------------------------------------------------------------------------------
typedef enum {
    RICON_NONE                     = 0,
    RICON_FOLDER_FILE_OPEN         = 1,
    RICON_FILE_SAVE_CLASSIC        = 2,
    RICON_FOLDER_OPEN              = 3,
    RICON_FOLDER_SAVE              = 4,
    RICON_FILE_OPEN                = 5,
    RICON_FILE_SAVE                = 6,
    RICON_FILE_EXPORT              = 7,
    RICON_FILE_NEW                 = 8,
    RICON_FILE_DELETE              = 9,
    RICON_FILETYPE_TEXT            = 10,
    RICON_FILETYPE_AUDIO           = 11,
    RICON_FILETYPE_IMAGE           = 12,
    RICON_FILETYPE_PLAY            = 13,
    RICON_FILETYPE_VIDEO           = 14,
    RICON_FILETYPE_INFO            = 15,
    RICON_FILE_COPY                = 16,
    RICON_FILE_CUT                 = 17,
    RICON_FILE_PASTE               = 18,
    RICON_CURSOR_HAND              = 19,
    RICON_CURSOR_POINTER           = 20,
    RICON_CURSOR_CLASSIC           = 21,
    RICON_PENCIL                   = 22,
    RICON_PENCIL_BIG               = 23,
    RICON_BRUSH_CLASSIC            = 24,
    RICON_BRUSH_PAINTER            = 25,
    RICON_WATER_DROP               = 26,
    RICON_COLOR_PICKER             = 27,
    RICON_RUBBER                   = 28,
    RICON_COLOR_BUCKET             = 29,
    RICON_TEXT_T                   = 30,
    RICON_TEXT_A                   = 31,
    RICON_SCALE                    = 32,
    RICON_RESIZE                   = 33,
    RICON_FILTER_POINT             = 34,
    RICON_FILTER_BILINEAR          = 35,
    RICON_CROP                     = 36,
    RICON_CROP_ALPHA               = 37,
    RICON_SQUARE_TOGGLE            = 38,
    RICON_SIMMETRY                 = 39,
    RICON_SIMMETRY_HORIZONTAL      = 40,
    RICON_SIMMETRY_VERTICAL        = 41,
    RICON_LENS                     = 42,
    RICON_LENS_BIG                 = 43,
    RICON_EYE_ON                   = 44,
    RICON_EYE_OFF                  = 45,
    RICON_FILTER_TOP               = 46,
    RICON_FILTER                   = 47,
    RICON_TARGET_POINT             = 48,
    RICON_TARGET_SMALL             = 49,
    RICON_TARGET_BIG               = 50,
    RICON_TARGET_MOVE              = 51,
    RICON_CURSOR_MOVE              = 52,
    RICON_CURSOR_SCALE             = 53,
    RICON_CURSOR_SCALE_RIGHT       = 54,
    RICON_CURSOR_SCALE_LEFT        = 55,
    RICON_UNDO                     = 56,
    RICON_REDO                     = 57,
    RICON_REREDO                   = 58,
    RICON_MUTATE                   = 59,
    RICON_ROTATE                   = 60,
    RICON_REPEAT                   = 61,
    RICON_SHUFFLE                  = 62,
    RICON_EMPTYBOX                 = 63,
    RICON_TARGET                   = 64,
    RICON_TARGET_SMALL_FILL        = 65,
    RICON_TARGET_BIG_FILL          = 66,
    RICON_TARGET_MOVE_FILL         = 67,
    RICON_CURSOR_MOVE_FILL         = 68,
    RICON_CURSOR_SCALE_FILL        = 69,
    RICON_CURSOR_SCALE_RIGHT_FILL  = 70,
    RICON_CURSOR_SCALE_LEFT_FILL   = 71,
    RICON_UNDO_FILL                = 72,
    RICON_REDO_FILL                = 73,
    RICON_REREDO_FILL              = 74,
    RICON_MUTATE_FILL              = 75,
    RICON_ROTATE_FILL              = 76,
    RICON_REPEAT_FILL              = 77,
    RICON_SHUFFLE_FILL             = 78,
    RICON_EMPTYBOX_SMALL           = 79,
    RICON_BOX                      = 80,
    RICON_BOX_TOP                  = 81,
    RICON_BOX_TOP_RIGHT            = 82,
    RICON_BOX_RIGHT                = 83,
    RICON_BOX_BOTTOM_RIGHT         = 84,
    RICON_BOX_BOTTOM               = 85,
    RICON_BOX_BOTTOM_LEFT          = 86,
    RICON_BOX_LEFT                 = 87,
    RICON_BOX_TOP_LEFT             = 88,
    RICON_BOX_CENTER               = 89,
    RICON_BOX_CIRCLE_MASK          = 90,
    RICON_POT                      = 91,
    RICON_ALPHA_MULTIPLY           = 92,
    RICON_ALPHA_CLEAR              = 93,
    RICON_DITHERING                = 94,
    RICON_MIPMAPS                  = 95,
    RICON_BOX_GRID                 = 96,
    RICON_GRID                     = 97,
    RICON_BOX_CORNERS_SMALL        = 98,
    RICON_BOX_CORNERS_BIG          = 99,
    RICON_FOUR_BOXES               = 100,
    RICON_GRID_FILL                = 101,
    RICON_BOX_MULTISIZE            = 102,
    RICON_ZOOM_SMALL               = 103,
    RICON_ZOOM_MEDIUM              = 104,
    RICON_ZOOM_BIG                 = 105,
    RICON_ZOOM_ALL                 = 106,
    RICON_ZOOM_CENTER              = 107,
    RICON_BOX_DOTS_SMALL           = 108,
    RICON_BOX_DOTS_BIG             = 109,
    RICON_BOX_CONCENTRIC           = 110,
    RICON_BOX_GRID_BIG             = 111,
    RICON_OK_TICK                  = 112,
    RICON_CROSS                    = 113,
    RICON_ARROW_LEFT               = 114,
    RICON_ARROW_RIGHT              = 115,
    RICON_ARROW_BOTTOM             = 116,
    RICON_ARROW_TOP                = 117,
    RICON_ARROW_LEFT_FILL          = 118,
    RICON_ARROW_RIGHT_FILL         = 119,
    RICON_ARROW_BOTTOM_FILL        = 120,
    RICON_ARROW_TOP_FILL           = 121,
    RICON_AUDIO                    = 122,
    RICON_FX                       = 123,
    RICON_WAVE                     = 124,
    RICON_WAVE_SINUS               = 125,
    RICON_WAVE_SQUARE              = 126,
    RICON_WAVE_TRIANGULAR          = 127,
    RICON_CROSS_SMALL              = 128,
    RICON_PLAYER_PREVIOUS          = 129,
    RICON_PLAYER_PLAY_BACK         = 130,
    RICON_PLAYER_PLAY              = 131,
    RICON_PLAYER_PAUSE             = 132,
    RICON_PLAYER_STOP              = 133,
    RICON_PLAYER_NEXT              = 134,
    RICON_PLAYER_RECORD            = 135,
    RICON_MAGNET                   = 136,
    RICON_LOCK_CLOSE               = 137,
    RICON_LOCK_OPEN                = 138,
    RICON_CLOCK                    = 139,
    RICON_TOOLS                    = 140,
    RICON_GEAR                     = 141,
    RICON_GEAR_BIG                 = 142,
    RICON_BIN                      = 143,
    RICON_HAND_POINTER             = 144,
    RICON_LASER                    = 145,
    RICON_COIN                     = 146,
    RICON_EXPLOSION                = 147,
    RICON_1UP                      = 148,
    RICON_PLAYER                   = 149,
    RICON_PLAYER_JUMP              = 150,
    RICON_KEY                      = 151,
    RICON_DEMON                    = 152,
    RICON_TEXT_POPUP               = 153,
    RICON_GEAR_EX                  = 154,
    RICON_CRACK                    = 155,
    RICON_CRACK_POINTS             = 156,
    RICON_STAR                     = 157,
    RICON_DOOR                     = 158,
    RICON_EXIT                     = 159,
    RICON_MODE_2D                  = 160,
    RICON_MODE_3D                  = 161,
    RICON_CUBE                     = 162,
    RICON_CUBE_FACE_TOP            = 163,
    RICON_CUBE_FACE_LEFT           = 164,
    RICON_CUBE_FACE_FRONT          = 165,
    RICON_CUBE_FACE_BOTTOM         = 166,
    RICON_CUBE_FACE_RIGHT          = 167,
    RICON_CUBE_FACE_BACK           = 168,
    RICON_CAMERA                   = 169,
    RICON_SPECIAL                  = 170,
    RICON_LINK_NET                 = 171,
    RICON_LINK_BOXES               = 172,
    RICON_LINK_MULTI               = 173,
    RICON_LINK                     = 174,
    RICON_LINK_BROKE               = 175,
    RICON_TEXT_NOTES               = 176,
    RICON_NOTEBOOK                 = 177,
    RICON_SUITCASE                 = 178,
    RICON_SUITCASE_ZIP             = 179,
    RICON_MAILBOX                  = 180,
    RICON_MONITOR                  = 181,
    RICON_PRINTER                  = 182,
    RICON_PHOTO_CAMERA             = 183,
    RICON_PHOTO_CAMERA_FLASH       = 184,
    RICON_HOUSE                    = 185,
    RICON_HEART                    = 186,
    RICON_CORNER                   = 187,
    RICON_VERTICAL_BARS            = 188,
    RICON_VERTICAL_BARS_FILL       = 189,
    RICON_LIFE_BARS                = 190,
    RICON_INFO                     = 191,
    RICON_CROSSLINE                = 192,
    RICON_HELP                     = 193,
    RICON_FILETYPE_ALPHA           = 194,
    RICON_FILETYPE_HOME            = 195,
    RICON_LAYERS_VISIBLE           = 196,
    RICON_LAYERS                   = 197,
    RICON_WINDOW                   = 198,
    RICON_HIDPI                    = 199,
    RICON_200                      = 200,
    RICON_201                      = 201,
    RICON_202                      = 202,
    RICON_203                      = 203,
    RICON_204                      = 204,
    RICON_205                      = 205,
    RICON_206                      = 206,
    RICON_207                      = 207,
    RICON_208                      = 208,
    RICON_209                      = 209,
    RICON_210                      = 210,
    RICON_211                      = 211,
    RICON_212                      = 212,
    RICON_213                      = 213,
    RICON_214                      = 214,
    RICON_215                      = 215,
    RICON_216                      = 216,
    RICON_217                      = 217,
    RICON_218                      = 218,
    RICON_219                      = 219,
    RICON_220                      = 220,
    RICON_221                      = 221,
    RICON_222                      = 222,
    RICON_223                      = 223,
    RICON_224                      = 224,
    RICON_225                      = 225,
    RICON_226                      = 226,
    RICON_227                      = 227,
    RICON_228                      = 228,
    RICON_229                      = 229,
    RICON_230                      = 230,
    RICON_231                      = 231,
    RICON_232                      = 232,
    RICON_233                      = 233,
    RICON_234                      = 234,
    RICON_235                      = 235,
    RICON_236                      = 236,
    RICON_237                      = 237,
    RICON_238                      = 238,
    RICON_239                      = 239,
    RICON_240                      = 240,
    RICON_241                      = 241,
    RICON_242                      = 242,
    RICON_243                      = 243,
    RICON_244                      = 244,
    RICON_245                      = 245,
    RICON_246                      = 246,
    RICON_247                      = 247,
    RICON_248                      = 248,
    RICON_249                      = 249,
    RICON_250                      = 250,
    RICON_251                      = 251,
    RICON_252                      = 252,
    RICON_253                      = 253,
    RICON_254                      = 254,
    RICON_255                      = 255,
} guiIconName;

//----------------------------------------------------------------------------------
// Module Functions Declaration
//----------------------------------------------------------------------------------
void GuiDrawIcon(int iconId, Vector2 position, int pixelSize, Color color);

unsigned int *GuiGetIcons(void);                     // Get full icons data pointer

unsigned int *GuiGetIconData(int iconId);            // Get icon bit data
void GuiSetIconData(int iconId, unsigned int *data); // Set icon bit data

void GuiSetIconPixel(int iconId, int x, int y);      // Set icon pixel value
void GuiClearIconPixel(int iconId, int x, int y);    // Clear icon pixel value
bool GuiCheckIconPixel(int iconId, int x, int y);    // Check icon pixel value

#endif // RICONS_H

/***********************************************************************************
*
*   RICONS IMPLEMENTATION
*
************************************************************************************/

#if defined(RICONS_IMPLEMENTATION)

#if !defined(RICONS_STANDALONE)
#include "raylib.h"         // Required for: Icons drawing function: DrawRectangle()
#endif

#include <stdio.h>              // Required for: fopen(), fclose()...
#include <string.h>             // Required for: memset(), memcpy()
#include <stdlib.h>             // Required for: malloc()

//----------------------------------------------------------------------------------
// Global Variables Definition
//----------------------------------------------------------------------------------
// Gui icons array (allocated on heap by default)
// NOTE: A new icon set could be loaded over this array using GuiLoadIcons(),
// just note that loaded icons set must be same RICON_SIZE
static unsigned int guiIcons[RICON_MAX_ICONS*RICON_DATA_ELEMENTS] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_NONE
    0x3ff80000, 0x2f082008, 0x2042207e, 0x40027fc2, 0x40024002, 0x40024002, 0x40024002, 0x00007ffe,     // RICON_FOLDER_FILE_OPEN
    0x3ffe0000, 0x44226422, 0x400247e2, 0x5ffa4002, 0x57ea500a, 0x500a500a, 0x40025ffa, 0x00007ffe,     // RICON_FILE_SAVE_CLASSIC
    0x00000000, 0x0042007e, 0x40027fc2, 0x40024002, 0x41024002, 0x44424282, 0x793e4102, 0x00000100,     // RICON_FOLDER_OPEN
    0x00000000, 0x0042007e, 0x40027fc2, 0x40024002, 0x41024102, 0x44424102, 0x793e4282, 0x00000000,     // RICON_FOLDER_SAVE
    0x3ff00000, 0x201c2010, 0x20042004, 0x21042004, 0x24442284, 0x21042104, 0x20042104, 0x00003ffc,     // RICON_FILE_OPEN
    0x3ff00000, 0x201c2010, 0x20042004, 0x21042004, 0x21042104, 0x22842444, 0x20042104, 0x00003ffc,     // RICON_FILE_SAVE
    0x3ff00000, 0x201c2010, 0x00042004, 0x20041004, 0x20844784, 0x00841384, 0x20042784, 0x00003ffc,     // RICON_FILE_EXPORT
    0x3ff00000, 0x201c2010, 0x20042004, 0x20042004, 0x22042204, 0x22042f84, 0x20042204, 0x00003ffc,     // RICON_FILE_NEW
    0x3ff00000, 0x201c2010, 0x20042004, 0x20042004, 0x25042884, 0x25042204, 0x20042884, 0x00003ffc,     // RICON_FILE_DELETE
    0x3ff00000, 0x201c2010, 0x20042004, 0x20042ff4, 0x20042ff4, 0x20042ff4, 0x20042004, 0x00003ffc,     // RICON_FILETYPE_TEXT
    0x3ff00000, 0x201c2010, 0x27042004, 0x244424c4, 0x26442444, 0x20642664, 0x20042004, 0x00003ffc,     // RICON_FILETYPE_AUDIO
    0x3ff00000, 0x201c2010, 0x26042604, 0x20042004, 0x35442884, 0x2414222c, 0x20042004, 0x00003ffc,     // RICON_FILETYPE_IMAGE
    0x3ff00000, 0x201c2010, 0x20c42004, 0x22442144, 0x22442444, 0x20c42144, 0x20042004, 0x00003ffc,     // RICON_FILETYPE_PLAY
    0x3ff00000, 0x3ffc2ff0, 0x3f3c2ff4, 0x3dbc2eb4, 0x3dbc2bb4, 0x3f3c2eb4, 0x3ffc2ff4, 0x00002ff4,     // RICON_FILETYPE_VIDEO
    0x3ff00000, 0x201c2010, 0x21842184, 0x21842004, 0x21842184, 0x21842184, 0x20042184, 0x00003ffc,     // RICON_FILETYPE_INFO
    0x0ff00000, 0x381c0810, 0x28042804, 0x28042804, 0x28042804, 0x28042804, 0x20102ffc, 0x00003ff0,     // RICON_FILE_COPY
    0x00000000, 0x701c0000, 0x079c1e14, 0x55a000f0, 0x079c00f0, 0x701c1e14, 0x00000000, 0x00000000,     // RICON_FILE_CUT
    0x01c00000, 0x13e41bec, 0x3f841004, 0x204420c4, 0x20442044, 0x20442044, 0x207c2044, 0x00003fc0,     // RICON_FILE_PASTE
    0x00000000, 0x3aa00fe0, 0x2abc2aa0, 0x2aa42aa4, 0x20042aa4, 0x20042004, 0x3ffc2004, 0x00000000,     // RICON_CURSOR_HAND
    0x00000000, 0x003c000c, 0x030800c8, 0x30100c10, 0x10202020, 0x04400840, 0x01800280, 0x00000000,     // RICON_CURSOR_POINTER
    0x00000000, 0x00180000, 0x01f00078, 0x03e007f0, 0x07c003e0, 0x04000e40, 0x00000000, 0x00000000,     // RICON_CURSOR_CLASSIC
    0x00000000, 0x04000000, 0x11000a00, 0x04400a80, 0x01100220, 0x00580088, 0x00000038, 0x00000000,     // RICON_PENCIL
    0x04000000, 0x15000a00, 0x50402880, 0x14102820, 0x05040a08, 0x015c028c, 0x007c00bc, 0x00000000,     // RICON_PENCIL_BIG
    0x01c00000, 0x01400140, 0x01400140, 0x0ff80140, 0x0ff80808, 0x0aa80808, 0x0aa80aa8, 0x00000ff8,     // RICON_BRUSH_CLASSIC
    0x1ffc0000, 0x5ffc7ffe, 0x40004000, 0x00807f80, 0x01c001c0, 0x01c001c0, 0x01c001c0, 0x00000080,     // RICON_BRUSH_PAINTER
    0x00000000, 0x00800000, 0x01c00080, 0x03e001c0, 0x07f003e0, 0x036006f0, 0x000001c0, 0x00000000,     // RICON_WATER_DROP
    0x00000000, 0x3e003800, 0x1f803f80, 0x0c201e40, 0x02080c10, 0x00840104, 0x00380044, 0x00000000,     // RICON_COLOR_PICKER
    0x00000000, 0x07800300, 0x1fe00fc0, 0x3f883fd0, 0x0e021f04, 0x02040402, 0x00f00108, 0x00000000,     // RICON_RUBBER
    0x00c00000, 0x02800140, 0x08200440, 0x20081010, 0x2ffe3004, 0x03f807fc, 0x00e001f0, 0x00000040,     // RICON_COLOR_BUCKET
    0x00000000, 0x21843ffc, 0x01800180, 0x01800180, 0x01800180, 0x01800180, 0x03c00180, 0x00000000,     // RICON_TEXT_T
    0x00800000, 0x01400180, 0x06200340, 0x0c100620, 0x1ff80c10, 0x380c1808, 0x70067004, 0x0000f80f,     // RICON_TEXT_A
    0x78000000, 0x50004000, 0x00004800, 0x03c003c0, 0x03c003c0, 0x00100000, 0x0002000a, 0x0000000e,     // RICON_SCALE
    0x75560000, 0x5e004002, 0x54001002, 0x41001202, 0x408200fe, 0x40820082, 0x40820082, 0x00006afe,     // RICON_RESIZE
    0x00000000, 0x3f003f00, 0x3f003f00, 0x3f003f00, 0x00400080, 0x001c0020, 0x001c001c, 0x00000000,     // RICON_FILTER_POINT
    0x6d800000, 0x00004080, 0x40804080, 0x40800000, 0x00406d80, 0x001c0020, 0x001c001c, 0x00000000,     // RICON_FILTER_BILINEAR
    0x40080000, 0x1ffe2008, 0x14081008, 0x11081208, 0x10481088, 0x10081028, 0x10047ff8, 0x00001002,     // RICON_CROP
    0x00100000, 0x3ffc0010, 0x2ab03550, 0x22b02550, 0x20b02150, 0x20302050, 0x2000fff0, 0x00002000,     // RICON_CROP_ALPHA
    0x40000000, 0x1ff82000, 0x04082808, 0x01082208, 0x00482088, 0x00182028, 0x35542008, 0x00000002,     // RICON_SQUARE_TOGGLE
    0x00000000, 0x02800280, 0x06c006c0, 0x0ea00ee0, 0x1e901eb0, 0x3e883e98, 0x7efc7e8c, 0x00000000,     // RICON_SIMMETRY
    0x01000000, 0x05600100, 0x1d480d50, 0x7d423d44, 0x3d447d42, 0x0d501d48, 0x01000560, 0x00000100,     // RICON_SIMMETRY_HORIZONTAL
    0x01800000, 0x04200240, 0x10080810, 0x00001ff8, 0x00007ffe, 0x0ff01ff8, 0x03c007e0, 0x00000180,     // RICON_SIMMETRY_VERTICAL
    0x00000000, 0x010800f0, 0x02040204, 0x02040204, 0x07f00308, 0x1c000e00, 0x30003800, 0x00000000,     // RICON_LENS
    0x00000000, 0x061803f0, 0x08240c0c, 0x08040814, 0x0c0c0804, 0x23f01618, 0x18002400, 0x00000000,     // RICON_LENS_BIG
    0x00000000, 0x00000000, 0x1c7007c0, 0x638e3398, 0x1c703398, 0x000007c0, 0x00000000, 0x00000000,     // RICON_EYE_ON
    0x00000000, 0x10002000, 0x04700fc0, 0x610e3218, 0x1c703098, 0x001007a0, 0x00000008, 0x00000000,     // RICON_EYE_OFF
    0x00000000, 0x00007ffc, 0x40047ffc, 0x10102008, 0x04400820, 0x02800280, 0x02800280, 0x00000100,     // RICON_FILTER_TOP
    0x00000000, 0x40027ffe, 0x10082004, 0x04200810, 0x02400240, 0x02400240, 0x01400240, 0x000000c0,     // RICON_FILTER
    0x00800000, 0x00800080, 0x00000080, 0x3c9e0000, 0x00000000, 0x00800080, 0x00800080, 0x00000000,     // RICON_TARGET_POINT
    0x00800000, 0x00800080, 0x00800080, 0x3f7e01c0, 0x008001c0, 0x00800080, 0x00800080, 0x00000000,     // RICON_TARGET_SMALL
    0x00800000, 0x00800080, 0x03e00080, 0x3e3e0220, 0x03e00220, 0x00800080, 0x00800080, 0x00000000,     // RICON_TARGET_BIG
    0x01000000, 0x04400280, 0x01000100, 0x43842008, 0x43849ab2, 0x01002008, 0x04400100, 0x01000280,     // RICON_TARGET_MOVE
    0x01000000, 0x04400280, 0x01000100, 0x41042108, 0x41049ff2, 0x01002108, 0x04400100, 0x01000280,     // RICON_CURSOR_MOVE
    0x781e0000, 0x500a4002, 0x04204812, 0x00000240, 0x02400000, 0x48120420, 0x4002500a, 0x0000781e,     // RICON_CURSOR_SCALE
    0x00000000, 0x20003c00, 0x24002800, 0x01000200, 0x00400080, 0x00140024, 0x003c0004, 0x00000000,     // RICON_CURSOR_SCALE_RIGHT
    0x00000000, 0x0004003c, 0x00240014, 0x00800040, 0x02000100, 0x28002400, 0x3c002000, 0x00000000,     // RICON_CURSOR_SCALE_LEFT
    0x00000000, 0x00100020, 0x10101fc8, 0x10001020, 0x10001000, 0x10001000, 0x00001fc0, 0x00000000,     // RICON_UNDO
    0x00000000, 0x08000400, 0x080813f8, 0x00080408, 0x00080008, 0x00080008, 0x000003f8, 0x00000000,     // RICON_REDO
    0x00000000, 0x3ffc0000, 0x20042004, 0x20002000, 0x20402000, 0x3f902020, 0x00400020, 0x00000000,     // RICON_REREDO
    0x00000000, 0x3ffc0000, 0x20042004, 0x27fc2004, 0x20202000, 0x3fc82010, 0x00200010, 0x00000000,     // RICON_MUTATE
    0x00000000, 0x0ff00000, 0x10081818, 0x11801008, 0x10001180, 0x18101020, 0x00100fc8, 0x00000020,     // RICON_ROTATE
    0x00000000, 0x04000200, 0x240429fc, 0x20042204, 0x20442004, 0x3f942024, 0x00400020, 0x00000000,     // RICON_REPEAT
    0x00000000, 0x20001000, 0x22104c0e, 0x00801120, 0x11200040, 0x4c0e2210, 0x10002000, 0x00000000,     // RICON_SHUFFLE
    0x7ffe0000, 0x50024002, 0x44024802, 0x41024202, 0x40424082, 0x40124022, 0x4002400a, 0x00007ffe,     // RICON_EMPTYBOX
    0x00800000, 0x03e00080, 0x08080490, 0x3c9e0808, 0x08080808, 0x03e00490, 0x00800080, 0x00000000,     // RICON_TARGET
    0x00800000, 0x00800080, 0x00800080, 0x3ffe01c0, 0x008001c0, 0x00800080, 0x00800080, 0x00000000,     // RICON_TARGET_SMALL_FILL
    0x00800000, 0x00800080, 0x03e00080, 0x3ffe03e0, 0x03e003e0, 0x00800080, 0x00800080, 0x00000000,     // RICON_TARGET_BIG_FILL
    0x01000000, 0x07c00380, 0x01000100, 0x638c2008, 0x638cfbbe, 0x01002008, 0x07c00100, 0x01000380,     // RICON_TARGET_MOVE_FILL
    0x01000000, 0x07c00380, 0x01000100, 0x610c2108, 0x610cfffe, 0x01002108, 0x07c00100, 0x01000380,     // RICON_CURSOR_MOVE_FILL
    0x781e0000, 0x6006700e, 0x04204812, 0x00000240, 0x02400000, 0x48120420, 0x700e6006, 0x0000781e,     // RICON_CURSOR_SCALE_FILL
    0x00000000, 0x38003c00, 0x24003000, 0x01000200, 0x00400080, 0x000c0024, 0x003c001c, 0x00000000,     // RICON_CURSOR_SCALE_RIGHT
    0x00000000, 0x001c003c, 0x0024000c, 0x00800040, 0x02000100, 0x30002400, 0x3c003800, 0x00000000,     // RICON_CURSOR_SCALE_LEFT
    0x00000000, 0x00300020, 0x10301ff8, 0x10001020, 0x10001000, 0x10001000, 0x00001fc0, 0x00000000,     // RICON_UNDO_FILL
    0x00000000, 0x0c000400, 0x0c081ff8, 0x00080408, 0x00080008, 0x00080008, 0x000003f8, 0x00000000,     // RICON_REDO_FILL
    0x00000000, 0x3ffc0000, 0x20042004, 0x20002000, 0x20402000, 0x3ff02060, 0x00400060, 0x00000000,     // RICON_REREDO_FILL
    0x00000000, 0x3ffc0000, 0x20042004, 0x27fc2004, 0x20202000, 0x3ff82030, 0x00200030, 0x00000000,     // RICON_MUTATE_FILL
    0x00000000, 0x0ff00000, 0x10081818, 0x11801008, 0x10001180, 0x18301020, 0x00300ff8, 0x00000020,     // RICON_ROTATE_FILL
    0x00000000, 0x06000200, 0x26042ffc, 0x20042204, 0x20442004, 0x3ff42064, 0x00400060, 0x00000000,     // RICON_REPEAT_FILL
    0x00000000, 0x30001000, 0x32107c0e, 0x00801120, 0x11200040, 0x7c0e3210, 0x10003000, 0x00000000,     // RICON_SHUFFLE_FILL
    0x00000000, 0x30043ffc, 0x24042804, 0x21042204, 0x20442084, 0x20142024, 0x3ffc200c, 0x00000000,     // RICON_EMPTYBOX_SMALL
    0x00000000, 0x20043ffc, 0x20042004, 0x20042004, 0x20042004, 0x20042004, 0x3ffc2004, 0x00000000,     // RICON_BOX
    0x00000000, 0x23c43ffc, 0x23c423c4, 0x200423c4, 0x20042004, 0x20042004, 0x3ffc2004, 0x00000000,     // RICON_BOX_TOP
    0x00000000, 0x3e043ffc, 0x3e043e04, 0x20043e04, 0x20042004, 0x20042004, 0x3ffc2004, 0x00000000,     // RICON_BOX_TOP_RIGHT
    0x00000000, 0x20043ffc, 0x20042004, 0x3e043e04, 0x3e043e04, 0x20042004, 0x3ffc2004, 0x00000000,     // RICON_BOX_RIGHT
    0x00000000, 0x20043ffc, 0x20042004, 0x20042004, 0x3e042004, 0x3e043e04, 0x3ffc3e04, 0x00000000,     // RICON_BOX_BOTTOM_RIGHT
    0x00000000, 0x20043ffc, 0x20042004, 0x20042004, 0x23c42004, 0x23c423c4, 0x3ffc23c4, 0x00000000,     // RICON_BOX_BOTTOM
    0x00000000, 0x20043ffc, 0x20042004, 0x20042004, 0x207c2004, 0x207c207c, 0x3ffc207c, 0x00000000,     // RICON_BOX_BOTTOM_LEFT
    0x00000000, 0x20043ffc, 0x20042004, 0x207c207c, 0x207c207c, 0x20042004, 0x3ffc2004, 0x00000000,     // RICON_BOX_LEFT
    0x00000000, 0x207c3ffc, 0x207c207c, 0x2004207c, 0x20042004, 0x20042004, 0x3ffc2004, 0x00000000,     // RICON_BOX_TOP_LEFT
    0x00000000, 0x20043ffc, 0x20042004, 0x23c423c4, 0x23c423c4, 0x20042004, 0x3ffc2004, 0x00000000,     // RICON_BOX_CIRCLE_MASK
    0x7ffe0000, 0x40024002, 0x47e24182, 0x4ff247e2, 0x47e24ff2, 0x418247e2, 0x40024002, 0x00007ffe,     // RICON_BOX_CENTER
    0x7fff0000, 0x40014001, 0x40014001, 0x49555ddd, 0x4945495d, 0x400149c5, 0x40014001, 0x00007fff,     // RICON_POT
    0x7ffe0000, 0x53327332, 0x44ce4cce, 0x41324332, 0x404e40ce, 0x48125432, 0x4006540e, 0x00007ffe,     // RICON_ALPHA_MULTIPLY
    0x7ffe0000, 0x53327332, 0x44ce4cce, 0x41324332, 0x5c4e40ce, 0x44124432, 0x40065c0e, 0x00007ffe,     // RICON_ALPHA_CLEAR
    0x7ffe0000, 0x42fe417e, 0x42fe417e, 0x42fe417e, 0x42fe417e, 0x42fe417e, 0x42fe417e, 0x00007ffe,     // RICON_DITHERING
    0x07fe0000, 0x1ffa0002, 0x7fea000a, 0x402a402a, 0x5b2a512a, 0x5128552a, 0x40205128, 0x00007fe0,     // RICON_MIPMAPS
    0x00000000, 0x1ff80000, 0x12481248, 0x12481ff8, 0x1ff81248, 0x12481248, 0x00001ff8, 0x00000000,     // RICON_BOX_GRID
    0x12480000, 0x7ffe1248, 0x12481248, 0x12487ffe, 0x7ffe1248, 0x12481248, 0x12487ffe, 0x00001248,     // RICON_GRID
    0x00000000, 0x1c380000, 0x1c3817e8, 0x08100810, 0x08100810, 0x17e81c38, 0x00001c38, 0x00000000,     // RICON_BOX_CORNERS_SMALL
    0x700e0000, 0x700e5ffa, 0x20042004, 0x20042004, 0x20042004, 0x20042004, 0x5ffa700e, 0x0000700e,     // RICON_BOX_CORNERS_BIG
    0x3f7e0000, 0x21422142, 0x21422142, 0x00003f7e, 0x21423f7e, 0x21422142, 0x3f7e2142, 0x00000000,     // RICON_FOUR_BOXES
    0x00000000, 0x3bb80000, 0x3bb83bb8, 0x3bb80000, 0x3bb83bb8, 0x3bb80000, 0x3bb83bb8, 0x00000000,     // RICON_GRID_FILL
    0x7ffe0000, 0x7ffe7ffe, 0x77fe7000, 0x77fe77fe, 0x777e7700, 0x777e777e, 0x777e777e, 0x0000777e,     // RICON_BOX_MULTISIZE
    0x781e0000, 0x40024002, 0x00004002, 0x01800000, 0x00000180, 0x40020000, 0x40024002, 0x0000781e,     // RICON_ZOOM_SMALL
    0x781e0000, 0x40024002, 0x00004002, 0x03c003c0, 0x03c003c0, 0x40020000, 0x40024002, 0x0000781e,     // RICON_ZOOM_MEDIUM
    0x781e0000, 0x40024002, 0x07e04002, 0x07e007e0, 0x07e007e0, 0x400207e0, 0x40024002, 0x0000781e,     // RICON_ZOOM_BIG
    0x781e0000, 0x5ffa4002, 0x1ff85ffa, 0x1ff81ff8, 0x1ff81ff8, 0x5ffa1ff8, 0x40025ffa, 0x0000781e,     // RICON_ZOOM_ALL
    0x00000000, 0x2004381c, 0x00002004, 0x00000000, 0x00000000, 0x20040000, 0x381c2004, 0x00000000,     // RICON_ZOOM_CENTER
    0x00000000, 0x1db80000, 0x10081008, 0x10080000, 0x00001008, 0x10081008, 0x00001db8, 0x00000000,     // RICON_BOX_DOTS_SMALL
    0x35560000, 0x00002002, 0x00002002, 0x00002002, 0x00002002, 0x00002002, 0x35562002, 0x00000000,     // RICON_BOX_DOTS_BIG
    0x7ffe0000, 0x40024002, 0x48124ff2, 0x49924812, 0x48124992, 0x4ff24812, 0x40024002, 0x00007ffe,     // RICON_BOX_CONCENTRIC
    0x00000000, 0x10841ffc, 0x10841084, 0x1ffc1084, 0x10841084, 0x10841084, 0x00001ffc, 0x00000000,     // RICON_BOX_GRID_BIG
    0x00000000, 0x00000000, 0x10000000, 0x04000800, 0x01040200, 0x00500088, 0x00000020, 0x00000000,     // RICON_OK_TICK
    0x00000000, 0x10080000, 0x04200810, 0x01800240, 0x02400180, 0x08100420, 0x00001008, 0x00000000,     // RICON_CROSS
    0x00000000, 0x02000000, 0x00800100, 0x00200040, 0x00200010, 0x00800040, 0x02000100, 0x00000000,     // RICON_ARROW_LEFT
    0x00000000, 0x00400000, 0x01000080, 0x04000200, 0x04000800, 0x01000200, 0x00400080, 0x00000000,     // RICON_ARROW_RIGHT
    0x00000000, 0x00000000, 0x00000000, 0x08081004, 0x02200410, 0x00800140, 0x00000000, 0x00000000,     // RICON_ARROW_BOTTOM
    0x00000000, 0x00000000, 0x01400080, 0x04100220, 0x10040808, 0x00000000, 0x00000000, 0x00000000,     // RICON_ARROW_TOP
    0x00000000, 0x02000000, 0x03800300, 0x03e003c0, 0x03e003f0, 0x038003c0, 0x02000300, 0x00000000,     // RICON_ARROW_LEFT_FILL
    0x00000000, 0x00400000, 0x01c000c0, 0x07c003c0, 0x07c00fc0, 0x01c003c0, 0x004000c0, 0x00000000,     // RICON_ARROW_RIGHT_FILL
    0x00000000, 0x00000000, 0x00000000, 0x0ff81ffc, 0x03e007f0, 0x008001c0, 0x00000000, 0x00000000,     // RICON_ARROW_BOTTOM_FILL
    0x00000000, 0x00000000, 0x01c00080, 0x07f003e0, 0x1ffc0ff8, 0x00000000, 0x00000000, 0x00000000,     // RICON_ARROW_TOP_FILL
    0x00000000, 0x18a008c0, 0x32881290, 0x24822686, 0x26862482, 0x12903288, 0x08c018a0, 0x00000000,     // RICON_AUDIO
    0x00000000, 0x04800780, 0x004000c0, 0x662000f0, 0x08103c30, 0x130a0e18, 0x0000318e, 0x00000000,     // RICON_FX
    0x00000000, 0x00800000, 0x08880888, 0x2aaa0a8a, 0x0a8a2aaa, 0x08880888, 0x00000080, 0x00000000,     // RICON_WAVE
    0x00000000, 0x00600000, 0x01080090, 0x02040108, 0x42044204, 0x24022402, 0x00001800, 0x00000000,     // RICON_WAVE_SINUS
    0x00000000, 0x07f80000, 0x04080408, 0x04080408, 0x04080408, 0x7c0e0408, 0x00000000, 0x00000000,     // RICON_WAVE_SQUARE
    0x00000000, 0x00000000, 0x00a00040, 0x22084110, 0x08021404, 0x00000000, 0x00000000, 0x00000000,     // RICON_WAVE_TRIANGULAR
    0x00000000, 0x00000000, 0x04200000, 0x01800240, 0x02400180, 0x00000420, 0x00000000, 0x00000000,     // RICON_CROSS_SMALL
    0x00000000, 0x18380000, 0x12281428, 0x10a81128, 0x112810a8, 0x14281228, 0x00001838, 0x00000000,     // RICON_PLAYER_PREVIOUS
    0x00000000, 0x18000000, 0x11801600, 0x10181060, 0x10601018, 0x16001180, 0x00001800, 0x00000000,     // RICON_PLAYER_PLAY_BACK
    0x00000000, 0x00180000, 0x01880068, 0x18080608, 0x06081808, 0x00680188, 0x00000018, 0x00000000,     // RICON_PLAYER_PLAY
    0x00000000, 0x1e780000, 0x12481248, 0x12481248, 0x12481248, 0x12481248, 0x00001e78, 0x00000000,     // RICON_PLAYER_PAUSE
    0x00000000, 0x1ff80000, 0x10081008, 0x10081008, 0x10081008, 0x10081008, 0x00001ff8, 0x00000000,     // RICON_PLAYER_STOP
    0x00000000, 0x1c180000, 0x14481428, 0x15081488, 0x14881508, 0x14281448, 0x00001c18, 0x00000000,     // RICON_PLAYER_NEXT
    0x00000000, 0x03c00000, 0x08100420, 0x10081008, 0x10081008, 0x04200810, 0x000003c0, 0x00000000,     // RICON_PLAYER_RECORD
    0x00000000, 0x0c3007e0, 0x13c81818, 0x14281668, 0x14281428, 0x1c381c38, 0x08102244, 0x00000000,     // RICON_MAGNET
    0x07c00000, 0x08200820, 0x3ff80820, 0x23882008, 0x21082388, 0x20082108, 0x1ff02008, 0x00000000,     // RICON_LOCK_CLOSE
    0x07c00000, 0x08000800, 0x3ff80800, 0x23882008, 0x21082388, 0x20082108, 0x1ff02008, 0x00000000,     // RICON_LOCK_OPEN
    0x01c00000, 0x0c180770, 0x3086188c, 0x60832082, 0x60034781, 0x30062002, 0x0c18180c, 0x01c00770,     // RICON_CLOCK
    0x0a200000, 0x1b201b20, 0x04200e20, 0x04200420, 0x04700420, 0x0e700e70, 0x0e700e70, 0x04200e70,     // RICON_TOOLS
    0x01800000, 0x3bdc318c, 0x0ff01ff8, 0x7c3e1e78, 0x1e787c3e, 0x1ff80ff0, 0x318c3bdc, 0x00000180,     // RICON_GEAR
    0x01800000, 0x3ffc318c, 0x1c381ff8, 0x781e1818, 0x1818781e, 0x1ff81c38, 0x318c3ffc, 0x00000180,     // RICON_GEAR_BIG
    0x00000000, 0x08080ff8, 0x08081ffc, 0x0aa80aa8, 0x0aa80aa8, 0x0aa80aa8, 0x08080aa8, 0x00000ff8,     // RICON_BIN
    0x00000000, 0x00000000, 0x20043ffc, 0x08043f84, 0x04040f84, 0x04040784, 0x000007fc, 0x00000000,     // RICON_HAND_POINTER
    0x00000000, 0x24400400, 0x00001480, 0x6efe0e00, 0x00000e00, 0x24401480, 0x00000400, 0x00000000,     // RICON_LASER
    0x00000000, 0x03c00000, 0x08300460, 0x11181118, 0x11181118, 0x04600830, 0x000003c0, 0x00000000,     // RICON_COIN
    0x00000000, 0x10880080, 0x06c00810, 0x366c07e0, 0x07e00240, 0x00001768, 0x04200240, 0x00000000,     // RICON_EXPLOSION
    0x00000000, 0x3d280000, 0x2528252c, 0x3d282528, 0x05280528, 0x05e80528, 0x00000000, 0x00000000,     // RICON_1UP
    0x01800000, 0x03c003c0, 0x018003c0, 0x0ff007e0, 0x0bd00bd0, 0x0a500bd0, 0x02400240, 0x02400240,     // RICON_PLAYER
    0x01800000, 0x03c003c0, 0x118013c0, 0x03c81ff8, 0x07c003c8, 0x04400440, 0x0c080478, 0x00000000,     // RICON_PLAYER_JUMP
    0x3ff80000, 0x30183ff8, 0x30183018, 0x3ff83ff8, 0x03000300, 0x03c003c0, 0x03e00300, 0x000003e0,     // RICON_KEY
    0x3ff80000, 0x3ff83ff8, 0x33983ff8, 0x3ff83398, 0x3ff83ff8, 0x00000540, 0x0fe00aa0, 0x00000fe0,     // RICON_DEMON
    0x00000000, 0x0ff00000, 0x20041008, 0x25442004, 0x10082004, 0x06000bf0, 0x00000300, 0x00000000,     // RICON_TEXT_POPUP
    0x00000000, 0x11440000, 0x07f00be8, 0x1c1c0e38, 0x1c1c0c18, 0x07f00e38, 0x11440be8, 0x00000000,     // RICON_GEAR_EX
    0x00000000, 0x20080000, 0x0c601010, 0x07c00fe0, 0x07c007c0, 0x0c600fe0, 0x20081010, 0x00000000,     // RICON_CRACK
    0x00000000, 0x20080000, 0x0c601010, 0x04400fe0, 0x04405554, 0x0c600fe0, 0x20081010, 0x00000000,     // RICON_CRACK_POINTS
    0x00000000, 0x00800080, 0x01c001c0, 0x1ffc3ffe, 0x03e007f0, 0x07f003e0, 0x0c180770, 0x00000808,     // RICON_STAR
    0x0ff00000, 0x08180810, 0x08100818, 0x0a100810, 0x08180810, 0x08100818, 0x08100810, 0x00001ff8,     // RICON_DOOR
    0x0ff00000, 0x08100810, 0x08100810, 0x10100010, 0x4f902010, 0x10102010, 0x08100010, 0x00000ff0,     // RICON_EXIT
    0x00040000, 0x001f000e, 0x0ef40004, 0x12f41284, 0x0ef41214, 0x10040004, 0x7ffc3004, 0x10003000,     // RICON_MODE_2D
    0x78040000, 0x501f600e, 0x0ef44004, 0x12f41284, 0x0ef41284, 0x10140004, 0x7ffc300c, 0x10003000,     // RICON_MODE_3D
    0x7fe00000, 0x50286030, 0x47fe4804, 0x44224402, 0x44224422, 0x241275e2, 0x0c06140a, 0x000007fe,     // RICON_CUBE
    0x7fe00000, 0x5ff87ff0, 0x47fe4ffc, 0x44224402, 0x44224422, 0x241275e2, 0x0c06140a, 0x000007fe,     // RICON_CUBE_FACE_TOP
    0x7fe00000, 0x50386030, 0x47fe483c, 0x443e443e, 0x443e443e, 0x241e75fe, 0x0c06140e, 0x000007fe,     // RICON_CUBE_FACE_LEFT
    0x7fe00000, 0x50286030, 0x47fe4804, 0x47fe47fe, 0x47fe47fe, 0x27fe77fe, 0x0ffe17fe, 0x000007fe,     // RICON_CUBE_FACE_FRONT
    0x7fe00000, 0x50286030, 0x47fe4804, 0x44224402, 0x44224422, 0x3ff27fe2, 0x0ffe1ffa, 0x000007fe,     // RICON_CUBE_FACE_BOTTOM
    0x7fe00000, 0x70286030, 0x7ffe7804, 0x7c227c02, 0x7c227c22, 0x3c127de2, 0x0c061c0a, 0x000007fe,     // RICON_CUBE_FACE_RIGHT
    0x7fe00000, 0x7fe87ff0, 0x7ffe7fe4, 0x7fe27fe2, 0x7fe27fe2, 0x24127fe2, 0x0c06140a, 0x000007fe,     // RICON_CUBE_FACE_BACK
    0x00000000, 0x2a0233fe, 0x22022602, 0x22022202, 0x2a022602, 0x00a033fe, 0x02080110, 0x00000000,     // RICON_CAMERA
    0x00000000, 0x200c3ffc, 0x000c000c, 0x3ffc000c, 0x30003000, 0x30003000, 0x3ffc3004, 0x00000000,     // RICON_SPECIAL
    0x00000000, 0x0022003e, 0x012201e2, 0x0100013e, 0x01000100, 0x79000100, 0x4f004900, 0x00007800,     // RICON_LINK_NET
    0x00000000, 0x44007c00, 0x45004600, 0x00627cbe, 0x00620022, 0x45007cbe, 0x44004600, 0x00007c00,     // RICON_LINK_BOXES
    0x00000000, 0x0044007c, 0x0010007c, 0x3f100010, 0x3f1021f0, 0x3f100010, 0x3f0021f0, 0x00000000,     // RICON_LINK_MULTI
    0x00000000, 0x0044007c, 0x00440044, 0x0010007c, 0x00100010, 0x44107c10, 0x440047f0, 0x00007c00,     // RICON_LINK
    0x00000000, 0x0044007c, 0x00440044, 0x0000007c, 0x00000010, 0x44007c10, 0x44004550, 0x00007c00,     // RICON_LINK_BROKE
    0x02a00000, 0x22a43ffc, 0x20042004, 0x20042ff4, 0x20042ff4, 0x20042ff4, 0x20042004, 0x00003ffc,     // RICON_TEXT_NOTES
    0x3ffc0000, 0x20042004, 0x245e27c4, 0x27c42444, 0x2004201e, 0x201e2004, 0x20042004, 0x00003ffc,     // RICON_NOTEBOOK
    0x00000000, 0x07e00000, 0x04200420, 0x24243ffc, 0x24242424, 0x24242424, 0x3ffc2424, 0x00000000,     // RICON_SUITCASE
    0x00000000, 0x0fe00000, 0x08200820, 0x40047ffc, 0x7ffc5554, 0x40045554, 0x7ffc4004, 0x00000000,     // RICON_SUITCASE_ZIP
    0x00000000, 0x20043ffc, 0x3ffc2004, 0x13c81008, 0x100813c8, 0x10081008, 0x1ff81008, 0x00000000,     // RICON_MAILBOX
    0x00000000, 0x40027ffe, 0x5ffa5ffa, 0x5ffa5ffa, 0x40025ffa, 0x03c07ffe, 0x1ff81ff8, 0x00000000,     // RICON_MONITOR
    0x0ff00000, 0x6bfe7ffe, 0x7ffe7ffe, 0x68167ffe, 0x08106816, 0x08100810, 0x0ff00810, 0x00000000,     // RICON_PRINTER
    0x3ff80000, 0xfffe2008, 0x870a8002, 0x904a888a, 0x904a904a, 0x870a888a, 0xfffe8002, 0x00000000,     // RICON_PHOTO_CAMERA
    0x0fc00000, 0xfcfe0cd8, 0x8002fffe, 0x84428382, 0x84428442, 0x80028382, 0xfffe8002, 0x00000000,     // RICON_PHOTO_CAMERA_FLASH
    0x00000000, 0x02400180, 0x08100420, 0x20041008, 0x23c42004, 0x22442244, 0x3ffc2244, 0x00000000,     // RICON_HOUSE
    0x00000000, 0x1c700000, 0x3ff83ef8, 0x3ff83ff8, 0x0fe01ff0, 0x038007c0, 0x00000100, 0x00000000,     // RICON_HEART
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x80000000, 0xe000c000,     // RICON_CORNER
    0x00000000, 0x14001c00, 0x15c01400, 0x15401540, 0x155c1540, 0x15541554, 0x1ddc1554, 0x00000000,     // RICON_VERTICAL_BARS
    0x00000000, 0x03000300, 0x1b001b00, 0x1b601b60, 0x1b6c1b60, 0x1b6c1b6c, 0x1b6c1b6c, 0x00000000,     // RICON_VERTICAL_BARS_FILL
    0x00000000, 0x00000000, 0x403e7ffe, 0x7ffe403e, 0x7ffe0000, 0x43fe43fe, 0x00007ffe, 0x00000000,     // RICON_LIFE_BARS
    0x7ffc0000, 0x43844004, 0x43844284, 0x43844004, 0x42844284, 0x42844284, 0x40044384, 0x00007ffc,     // RICON_INFO
    0x40008000, 0x10002000, 0x04000800, 0x01000200, 0x00400080, 0x00100020, 0x00040008, 0x00010002,     // RICON_CROSSLINE
    0x00000000, 0x1ff01ff0, 0x18301830, 0x1f001830, 0x03001f00, 0x00000300, 0x03000300, 0x00000000,     // RICON_HELP
    0x3ff00000, 0x2abc3550, 0x2aac3554, 0x2aac3554, 0x2aac3554, 0x2aac3554, 0x2aac3554, 0x00003ffc,     // RICON_FILETYPE_ALPHA
    0x3ff00000, 0x201c2010, 0x22442184, 0x28142424, 0x29942814, 0x2ff42994, 0x20042004, 0x00003ffc,     // RICON_FILETYPE_HOME
    0x07fe0000, 0x04020402, 0x7fe20402, 0x44224422, 0x44224422, 0x402047fe, 0x40204020, 0x00007fe0,     // RICON_LAYERS_VISIBLE
    0x07fe0000, 0x04020402, 0x7c020402, 0x44024402, 0x44024402, 0x402047fe, 0x40204020, 0x00007fe0,     // RICON_LAYERS
    0x00000000, 0x40027ffe, 0x7ffe4002, 0x40024002, 0x40024002, 0x40024002, 0x7ffe4002, 0x00000000,     // RICON_WINDOW
    0x09100000, 0x09f00910, 0x09100910, 0x00000910, 0x24a2779e, 0x27a224a2, 0x709e20a2, 0x00000000,     // RICON_HIDPI
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_200
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_201
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_202
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_203
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_204
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_205
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_206
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_207
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_208
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_209
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_210
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_211
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_212
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_213
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_214
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_215
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_216
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_217
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_218
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_219
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_220
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_221
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_222
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_223
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_224
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_225
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_226
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_227
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_228
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_229
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_230
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_231
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_232
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_233
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_234
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_235
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_236
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_237
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_238
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_239
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_240
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_241
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_242
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_243
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_244
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_245
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_246
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_247
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_248
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_249
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_250
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_251
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_252
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_253
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_254
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,     // RICON_255
};

//----------------------------------------------------------------------------------
// Module Functions Definition
//----------------------------------------------------------------------------------

// Get full icons data pointer
unsigned int *GuiGetIcons(void) { return guiIcons; }

// Load raygui icons file (.rgi)
// NOTE: In case nameIds are required, they can be requested with loadIconsName,
// they are returned as a guiIconsName[iconsCount][RICON_MAX_NAME_LENGTH],
// guiIconsName[]][] memory should be manually freed!
char **GuiLoadIcons(const char *fileName, bool loadIconsName)
{
    // Style File Structure (.rgi)
    // ------------------------------------------------------
    // Offset  | Size    | Type       | Description
    // ------------------------------------------------------
    // 0       | 4       | char       | Signature: "rGI "
    // 4       | 2       | short      | Version: 100
    // 6       | 2       | short      | reserved

    // 8       | 2       | short      | Num icons (N)
    // 10      | 2       | short      | Icons size (Options: 16, 32, 64) (S)

    // Icons name id (32 bytes per name id)
    // foreach (icon)
    // {
    //   12+32*i  | 32   | char       | Icon NameId
    // }

    // Icons data: One bit per pixel, stored as unsigned int array (depends on icon size)
    // S*S pixels/32bit per unsigned int = K unsigned int per icon
    // foreach (icon)
    // {
    //   ...   | K       | unsigned int | Icon Data
    // }

    FILE *rgiFile = fopen(fileName, "rb");

    char **guiIconsName = NULL;

    if (rgiFile != NULL)
    {
        char signature[5] = "";
        short version = 0;
        short reserved = 0;
        short iconsCount = 0;
        short iconsSize = 0;

        fread(signature, 1, 4, rgiFile);
        fread(&version, 1, sizeof(short), rgiFile);
        fread(&reserved, 1, sizeof(short), rgiFile);
        fread(&iconsCount, 1, sizeof(short), rgiFile);
        fread(&iconsSize, 1, sizeof(short), rgiFile);

        if ((signature[0] == 'r') &&
            (signature[1] == 'G') &&
            (signature[2] == 'I') &&
            (signature[3] == ' '))
        {
            if (loadIconsName)
            {
                guiIconsName = (char **)malloc(iconsCount*sizeof(char **));
                for (int i = 0; i < iconsCount; i++)
                {
                    guiIconsName[i] = (char *)malloc(RICON_MAX_NAME_LENGTH);
                    fread(guiIconsName[i], 32, 1, rgiFile);
                }
            }

            // Read icons data directly over guiIcons data array
            fread(guiIcons, iconsCount*(iconsSize*iconsSize/32), sizeof(unsigned int), rgiFile);
        }

        fclose(rgiFile);
    }

    return guiIconsName;
}

// Draw selected icon using rectangles pixel-by-pixel
void GuiDrawIcon(int iconId, Vector2 position, int pixelSize, Color color)
{
#define BIT_CHECK(a,b) ((a) & (1<<(b)))

    for (int i = 0, y = 0; i < RICON_SIZE*RICON_SIZE/32; i++)
    {
        for (int k = 0; k < 32; k++)
        {
            if (BIT_CHECK(guiIcons[iconId*RICON_DATA_ELEMENTS + i], k))
            {
#if !defined(RICONS_STANDALONE)
                DrawRectangle(position.x + (k%RICON_SIZE)*pixelSize, position.y + y*pixelSize, pixelSize, pixelSize, color);
#endif
            }

            if ((k == 15) || (k == 31)) y++;
        }
    }
}

// Get icon bit data
// NOTE: Bit data array grouped as unsigned int (ICON_SIZE*ICON_SIZE/32 elements)
unsigned int *GuiGetIconData(int iconId)
{
    static unsigned int iconData[RICON_DATA_ELEMENTS] = { 0 };
    memset(iconData, 0, RICON_DATA_ELEMENTS*sizeof(unsigned int));

    if (iconId < RICON_MAX_ICONS) memcpy(iconData, &guiIcons[iconId*RICON_DATA_ELEMENTS], RICON_DATA_ELEMENTS*sizeof(unsigned int));

    return iconData;
}

// Set icon bit data
// NOTE: Data must be provided as unsigned int array (ICON_SIZE*ICON_SIZE/32 elements)
void GuiSetIconData(int iconId, unsigned int *data)
{
    if (iconId < RICON_MAX_ICONS) memcpy(&guiIcons[iconId*RICON_DATA_ELEMENTS], data, RICON_DATA_ELEMENTS*sizeof(unsigned int));
}

// Set icon pixel value
void GuiSetIconPixel(int iconId, int x, int y)
{
#define BIT_SET(a,b)   ((a) |= (1<<(b)))

    // This logic works for any RICON_SIZE pixels icons,
    // For example, in case of 16x16 pixels, every 2 lines fit in one unsigned int data element
    BIT_SET(guiIcons[iconId*RICON_DATA_ELEMENTS + y/(sizeof(unsigned int)*8/RICON_SIZE)], x + (y%(sizeof(unsigned int)*8/RICON_SIZE)*RICON_SIZE));
}

// Clear icon pixel value
void GuiClearIconPixel(int iconId, int x, int y)
{
#define BIT_CLEAR(a,b) ((a) &= ~((1)<<(b)))

    // This logic works for any RICON_SIZE pixels icons,
    // For example, in case of 16x16 pixels, every 2 lines fit in one unsigned int data element
    BIT_CLEAR(guiIcons[iconId*RICON_DATA_ELEMENTS + y/(sizeof(unsigned int)*8/RICON_SIZE)], x + (y%(sizeof(unsigned int)*8/RICON_SIZE)*RICON_SIZE));
}

// Check icon pixel value
bool GuiCheckIconPixel(int iconId, int x, int y)
{
#define BIT_CHECK(a,b) ((a) & (1<<(b)))

    return (BIT_CHECK(guiIcons[iconId*8 + y/2], x + (y%2*16)));
}

#endif      // RICONS_IMPLEMENTATION