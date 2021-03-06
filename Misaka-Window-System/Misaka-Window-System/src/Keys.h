#pragma once

#define MISAKA_BUTTON_NONE                  0x00
#define MISAKA_BUTTON_LEFT                  0x01
#define MISAKA_BUTTON_RIGHT                 0x02
#define MISAKA_BUTTON_MIDDLE                0x04

#define MISAKA_SCROLL_NONE                  0x00
#define MISAKA_SCROLL_UP                    0x780000
#define MISAKA_SCROLL_DOWN                  0xFF880000

#define MISAKA_KEY_NONE                     0x00
#define MISAKA_KEY_LBUTTON                  0x01
#define MISAKA_KEY_RBUTTON                  0x02
#define MISAKA_KEY_CANCEL                   0x03
#define MISAKA_KEY_MBUTTON                  0x04
#define MISAKA_KEY_XBUTTON1                 0x05
#define MISAKA_KEY_XBUTTON2                 0x06
#define MISAKA_KEY_UNDEFINED                0x07
#define MISAKA_KEY_BACK                     0x08
#define MISAKA_KEY_TAB                      0x09
#define MISAKA_KEY_CLEAR                    0x0C
#define MISAKA_KEY_RETURN                   0x0D
#define MISAKA_KEY_SHIFT                    0x10
#define MISAKA_KEY_CONTROL                  0x11
#define MISAKA_KEY_MENU                     0x12
#define MISAKA_KEY_PAUSE                    0x13
#define MISAKA_KEY_CAPITAL                  0x14
#define MISAKA_KEY_KANA                     0x15
#define MISAKA_KEY_HANGUEL                  0x15
#define MISAKA_KEY_HANGUL                   0x15
#define MISAKA_KEY_IME_ON                   0x16
#define MISAKA_KEY_JUNJA                    0x17
#define MISAKA_KEY_FINAL                    0x18
#define MISAKA_KEY_HANJA                    0x19
#define MISAKA_KEY_KANJI                    0x19
#define MISAKA_KEY_IME_OFF                  0x1A
#define MISAKA_KEY_ESCAPE                   0x1B
#define MISAKA_KEY_CONVERT                  0x1C
#define MISAKA_KEY_NONCONVERT               0x1D
#define MISAKA_KEY_ACCEPT                   0x1E
#define MISAKA_KEY_MODECHANGE               0x1F
#define MISAKA_KEY_SPACE                    0x20
#define MISAKA_KEY_PRIOR                    0x21
#define MISAKA_KEY_NEXT                     0x22
#define MISAKA_KEY_END                      0x23
#define MISAKA_KEY_HOME                     0x24
#define MISAKA_KEY_LEFT                     0x25
#define MISAKA_KEY_UP                       0x26
#define MISAKA_KEY_RIGHT                    0x27
#define MISAKA_KEY_DOWN                     0x28
#define MISAKA_KEY_SELECT                   0x29
#define MISAKA_KEY_PRINT                    0x2A
#define MISAKA_KEY_EXECUTE                  0x2B
#define MISAKA_KEY_SNAPSHOT                 0x2C
#define MISAKA_KEY_INSERT                   0x2D
#define MISAKA_KEY_DELETE                   0x2E
#define MISAKA_KEY_HELP                     0x2F
#define MISAKA_KEY_0                        0x30
#define MISAKA_KEY_1                        0x31
#define MISAKA_KEY_2                        0x32
#define MISAKA_KEY_3                        0x33
#define MISAKA_KEY_4                        0x34
#define MISAKA_KEY_5                        0x35
#define MISAKA_KEY_6                        0x36
#define MISAKA_KEY_7                        0x37
#define MISAKA_KEY_8                        0x38
#define MISAKA_KEY_9                        0x39
#define MISAKA_KEY_A                        0x41
#define MISAKA_KEY_B                        0x42
#define MISAKA_KEY_C                        0x43
#define MISAKA_KEY_D                        0x44
#define MISAKA_KEY_E                        0x45
#define MISAKA_KEY_F                        0x46
#define MISAKA_KEY_G                        0x47
#define MISAKA_KEY_H                        0x48
#define MISAKA_KEY_I                        0x49
#define MISAKA_KEY_J                        0x4A
#define MISAKA_KEY_K                        0x4B
#define MISAKA_KEY_L                        0x4C
#define MISAKA_KEY_M                        0x4D
#define MISAKA_KEY_N                        0x4E
#define MISAKA_KEY_O                        0x4F
#define MISAKA_KEY_P                        0x50
#define MISAKA_KEY_Q                        0x51
#define MISAKA_KEY_R                        0x52
#define MISAKA_KEY_S                        0x53
#define MISAKA_KEY_T                        0x54
#define MISAKA_KEY_U                        0x55
#define MISAKA_KEY_V                        0x56
#define MISAKA_KEY_W                        0x57
#define MISAKA_KEY_X                        0x58
#define MISAKA_KEY_Y                        0x59
#define MISAKA_KEY_Z                        0x5A
#define MISAKA_KEY_LWIN                     0x5B
#define MISAKA_KEY_RWIN                     0x5C
#define MISAKA_KEY_APPS                     0x5D
#define MISAKA_KEY_SLEEP                    0x5F
#define MISAKA_KEY_NUMPAD0                  0x60
#define MISAKA_KEY_NUMPAD1                  0x61
#define MISAKA_KEY_NUMPAD2                  0x62
#define MISAKA_KEY_NUMPAD3                  0x63
#define MISAKA_KEY_NUMPAD4                  0x64
#define MISAKA_KEY_NUMPAD5                  0x65
#define MISAKA_KEY_NUMPAD6                  0x66
#define MISAKA_KEY_NUMPAD7                  0x67
#define MISAKA_KEY_NUMPAD8                  0x68
#define MISAKA_KEY_NUMPAD9                  0x69
#define MISAKA_KEY_MULTIPLY                 0x6A
#define MISAKA_KEY_ADD                      0x6B
#define MISAKA_KEY_SEPARATOR                0x6C
#define MISAKA_KEY_SUBTRACT                 0x6D
#define MISAKA_KEY_DECIMAL                  0x6E
#define MISAKA_KEY_DIVIDE                   0x6F
#define MISAKA_KEY_F1                       0x70
#define MISAKA_KEY_F2                       0x71
#define MISAKA_KEY_F3                       0x72
#define MISAKA_KEY_F4                       0x73
#define MISAKA_KEY_F5                       0x74
#define MISAKA_KEY_F6                       0x75
#define MISAKA_KEY_F7                       0x76
#define MISAKA_KEY_F8                       0x77
#define MISAKA_KEY_F9                       0x78
#define MISAKA_KEY_F10                      0x79
#define MISAKA_KEY_F11                      0x7A
#define MISAKA_KEY_F12                      0x7B
#define MISAKA_KEY_F13                      0x7C
#define MISAKA_KEY_F14                      0x7D
#define MISAKA_KEY_F15                      0x7E
#define MISAKA_KEY_F16                      0x7F
#define MISAKA_KEY_F17                      0x80
#define MISAKA_KEY_F18                      0x81
#define MISAKA_KEY_F19                      0x82
#define MISAKA_KEY_F20                      0x83
#define MISAKA_KEY_F21                      0x84
#define MISAKA_KEY_F22                      0x85
#define MISAKA_KEY_F23                      0x86
#define MISAKA_KEY_F24                      0x87
#define MISAKA_KEY_NUMLOCK                  0x90
#define MISAKA_KEY_SCROLL                   0x91
#define MISAKA_KEY_LSHIFT                   0xA0
#define MISAKA_KEY_RSHIFT                   0xA1
#define MISAKA_KEY_LCONTROL                 0xA2
#define MISAKA_KEY_RCONTROL                 0xA3
#define MISAKA_KEY_LMENU                    0xA4
#define MISAKA_KEY_RMENU                    0xA5
#define MISAKA_KEY_BROWSER_BACK             0xA6
#define MISAKA_KEY_BROWSER_FORWARD          0xA7
#define MISAKA_KEY_BROWSER_REFRESH          0xA8
#define MISAKA_KEY_BROWSER_STOP             0xA9
#define MISAKA_KEY_BROWSER_SEARCH           0xAA
#define MISAKA_KEY_BROWSER_FAVORITES        0xAB
#define MISAKA_KEY_BROWSER_HOME             0xAC
#define MISAKA_KEY_VOLUME_MUTE              0xAD
#define MISAKA_KEY_VOLUME_DOWN              0xAE
#define MISAKA_KEY_VOLUME_UP                0xAF
#define MISAKA_KEY_MEDIA_NEXT_TRACK         0xB0
#define MISAKA_KEY_MEDIA_PREV_TRACK         0xB1
#define MISAKA_KEY_MEDIA_STOP               0xB2
#define MISAKA_KEY_MEDIA_PLAY_PAUSE         0xB3
#define MISAKA_KEY_LAUNCH_MAIL              0xB4
#define MISAKA_KEY_LAUNCH_MEDIA_SELECT      0xB5
#define MISAKA_KEY_LAUNCH_APP1              0xB6
#define MISAKA_KEY_LAUNCH_APP2              0xB7
#define MISAKA_KEY_OEM_1                    0xBA
#define MISAKA_KEY_OEM_PLUS                 0xBB
#define MISAKA_KEY_OEM_COMMA                0xBC
#define MISAKA_KEY_OEM_MINUS                0xBD
#define MISAKA_KEY_OEM_PERIOD               0xBE
#define MISAKA_KEY_OEM_2                    0xBF
#define MISAKA_KEY_OEM_3                    0xC0
#define MISAKA_KEY_OEM_4                    0xDB
#define MISAKA_KEY_OEM_5                    0xDC
#define MISAKA_KEY_OEM_6                    0xDD
#define MISAKA_KEY_OEM_7                    0xDE
#define MISAKA_KEY_OEM_8                    0xDF
#define MISAKA_KEY_OEM_102                  0xE2
#define MISAKA_KEY_PROCESSKEY               0xE5
#define MISAKA_KEY_PACKET                   0XE7
#define MISAKA_KEY_ATTN                     0xF6
#define MISAKA_KEY_CRSEL                    0xF7
#define MISAKA_KEY_EXSEL                    0xF8
#define MISAKA_KEY_EREOF                    0xF9
#define MISAKA_KEY_PLAY                     0xFA
#define MISAKA_KEY_ZOOM                     0xFB
#define MISAKA_KEY_NONAME                   0xFC
#define MISAKA_KEY_PA1                      0xFD
#define MISAKA_KEY_OEM_CLEAR                0xFE