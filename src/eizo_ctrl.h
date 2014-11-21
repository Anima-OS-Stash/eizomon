#ifndef EZMON_EIZO_CTRL
#define EZMON_EIZO_CTRL

#include "hidapi.h"

#define EM_EIZO_FG_2421_VENDORID        0x056d
#define EM_EIZO_FG_2421_PRODUCTID       0x0002

#define EM_EIZO_FG_2421_CMD_MODE        0x03
#define EM_EIZO_FG_2421_CMD_VOLUME      0x36
#define EM_EIZO_FG_2421_CMD_BACKLIGHT   0x28

#define EM_EIZO_FG_2421_MODE_USER1      0x16
#define EM_EIZO_FG_2421_MODE_USER2      0x17
#define EM_EIZO_FG_2421_MODE_USER3      0x18
#define EM_EIZO_FG_2421_MODE_FPS1       0x28
#define EM_EIZO_FG_2421_MODE_FPS2       0x29
#define EM_EIZO_FG_2421_MODE_RTS        0x2a
#define EM_EIZO_FG_2421_MODE_WEB        0x2b

#define EM_MONITOR_BUFFER_SIZE  3

typedef struct eizo_ctrl_monitor {
    hid_device *handle;
    unsigned char buffer[EM_MONITOR_BUFFER_SIZE];
    unsigned char backlight_status;
} eizo_ctrl_monitor;

eizo_ctrl_monitor *eizo_ctrl_open(unsigned short vendor_id, unsigned short product_id, const wchar_t *serial_number);
int eizo_ctrl_command(eizo_ctrl_monitor *monitor, unsigned char command, unsigned char arg1, unsigned char arg2);

#endif
