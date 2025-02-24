/**
 * Evolis C library
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
 * ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
 * PARTICULAR PURPOSE.
 */
#pragma once

/// Printer flags.
typedef enum evolis_flag_e {
    EVOLIS_CFG_X01 = 0,                        //!< Raised for Primacy, KC200B, KC200, Issengo
    EVOLIS_CFG_X02 = 1,                        //!< Raised for Zenius
    EVOLIS_CFG_R02 = 2,                        //!< Raised for Agilia
    EVOLIS_CFG_X04 = 3,                        //!< Raised for Elypso
    EVOLIS_CFG_EXTENSION_1 = 4,                //!< Extension 1 is used
    EVOLIS_CFG_S01 = 5,                        //!< Raised for Badgy, Apteo
    EVOLIS_CFG_X07 = 6,                        //!< Not used
    EVOLIS_CFG_KC200 = 7,                      //!< Raised for KC200B, KC200
    EVOLIS_CFG_WIFI = 8,                       //!< WiFi option is detected
    EVOLIS_CFG_ETHERNET = 9,                   //!< Ethernet option is detected
    EVOLIS_CFG_USB_OVER_IP = 10,               //!< USB over IP option is set
    EVOLIS_CFG_FLIP = 11,                      //!< Flip-over option is detected
    EVOLIS_CFG_CONTACTLESS = 12,               //!< Contactless option is detected
    EVOLIS_CFG_SMART = 13,                     //!< Smart option is detected
    EVOLIS_CFG_MAGNETIC = 14,                  //!< Magnetic option is detected
    EVOLIS_CFG_REWRITE = 15,                   //!< Rewrite mode is activated
    EVOLIS_CFG_FEED_MANUALLY = 16,             //!< Card feeding is configured as manual
    EVOLIS_CFG_FEED_BY_CDE = 17,               //!< Card feeding is set as manual once the feeding command is received
    EVOLIS_CFG_FEED_BY_FEEDER = 18,            //!< Card feeding is configured as feeder
    EVOLIS_CFG_EJECT_REVERSE = 19,             //!< Card ejection goes to manual feeder
    EVOLIS_CFG_FEED_CDE_REVERSE = 20,          //!< Card insertion is set to the rear of the printer
    EVOLIS_CFG_EXTENDED_RESOLUTION = 21,       //!< Extended resolution supported (600DPI, 1200DPI)
    EVOLIS_CFG_LCD = 22,                       //!< LCD option detected
    EVOLIS_CFG_LOCK = 23,                      //!< Locking system detected
    EVOLIS_CFG_OEM = 24,                       //!< Raised for rebranded products
    EVOLIS_CFG_JIS_MAG_HEAD = 25,              //!< JIS magnetic option detected
    EVOLIS_CFG_REJECT_SLOT = 26,               //!< Reject slot enabled
    EVOLIS_CFG_IO_EXT = 27,                    //!< IO extender detected
    EVOLIS_CFG_MONO_ONLY = 28,                 //!< Monochrome only printing authorized
    EVOLIS_CFG_KC100 = 29,                     //!< Raised for KC100
    EVOLIS_CFG_KINE = 30,                      //!< Kineclipse option is available
    EVOLIS_CFG_WIFI_ENA = 31,                  //!< WiFi option is activated
    EVOLIS_CFG_EXTENSION_2 = 32,               //!< Extension 2 is used
    EVOLIS_CFG_KIOSK = 33,                     //!< Raised for KM500B, KM2000B
    EVOLIS_CFG_QUANTUM = 34,                   //!< Raised for Quantum
    EVOLIS_CFG_SECURION = 35,                  //!< Raised for Securion
    EVOLIS_CFG_DUALYS = 36,                    //!< Raised for Dualys
    EVOLIS_CFG_PEBBLE = 37,                    //!< Raised for Pebble
    EVOLIS_CFG_SCANNER = 38,                   //!< Scanner option is detected
    EVOLIS_CFG_MEM_LAMINATION_MODULE_2 = 39,   //!< Printer has previously seen 2 lamination modules simultaneously
    EVOLIS_CFG_SEICO_FEEDER = 40,              //!< Seico feeder configured
    EVOLIS_CFG_KYTRONIC_FEEDER = 41,           //!< Kytronics feeder configured
    EVOLIS_CFG_HOPPER = 42,                    //!< Not used
    EVOLIS_CFG_LAMINATOR = 43,                 //!< Lamination module detected
    EVOLIS_CFG_BEZEL = 44,                     //!< Bezel option installed
    EVOLIS_CFG_EXTENSION_3 = 45,               //!< Extension 3 is used
    EVOLIS_CFG_LAMINATION_MODULE_2 = 46,       //!< Second lamination module detected
    EVOLIS_CFG_EXTENSION_4 = 47,               //!< Extension 4 is used
    EVOLIS_CFG_BRIDGE = 48,                    //!< Configuration for bridge module
    EVOLIS_CFG_INDENTING = 49,                 //!< Configuration for indenting module
    EVOLIS_INF_CLAIM = 50,                     //!< Raised when EPS printing
    EVOLIS_INF_CARD_HOPPER = 51,               //!< Card present at the hopper
    EVOLIS_INF_CARD_FEEDER = 52,               //!< Card present in the feeder
    EVOLIS_INF_CARD_FLIP = 53,                 //!< Card present in the flip-over
    EVOLIS_INF_CARD_CONTACTLESS = 54,          //!< Card present in contactless card station
    EVOLIS_INF_CARD_SMART = 55,                //!< Card present in smart card station
    EVOLIS_INF_CARD_PRINT = 56,                //!< Card present in printing position
    EVOLIS_INF_CARD_EJECT = 57,                //!< Card present in eject position
    EVOLIS_INF_PRINTER_MASTER = 58,            //!< Error management is set to 'printer'
    EVOLIS_INF_PCSVC_LOCKED = 59,              //!< The EPS is supervising the printer
    EVOLIS_INF_SLEEP_MODE = 60,                //!< Printer is in sleep mode
    EVOLIS_INF_UNKNOWN_RIBBON = 61,            //!< Installed ribbon is unknown/unreadable
    EVOLIS_INF_RIBBON_LOW = 62,                //!< Remaining ribbon is below low limit
    EVOLIS_INF_CLEANING_MANDATORY = 63,        //!< Cleaning is mandatory
    EVOLIS_INF_CLEANING = 64,                  //!< Cleaning is recommended
    EVOLIS_INF_RESET = 65,                     //!< Printer has just rebooted
    EVOLIS_INF_CLEAN_OUTWARRANTY = 66,         //!< Warranty lost, cleaning has not been done in time
    EVOLIS_INF_CLEAN_LAST_OUTWARRANTY = 67,    //!< Cleaning is mandatory, next card printed will lose the warranty
    EVOLIS_INF_CLEAN_2ND_PASS = 68,            //!< Cleaning sequence requires the second cleaning card
    EVOLIS_INF_READY_FOR_CLEANING = 69,        //!< Printer ready for cleaning (ribbon has been removed and cover closed)
    EVOLIS_INF_CLEANING_ADVANCED = 70,         //!< Advanced cleaning requested
    EVOLIS_INF_WRONG_ZONE_RIBBON = 71,         //!< Installed ribbon has not the right zone
    EVOLIS_INF_RIBBON_CHANGED = 72,            //!< Installed ribbon is different from the previous one
    EVOLIS_INF_CLEANING_REQUIRED = 73,         //!< Cleaning is required
    EVOLIS_INF_PRINTING_RUNNING = 74,          //!< Printing is in progress
    EVOLIS_INF_ENCODING_RUNNING = 75,          //!< Encoding is in progress (smart, contactless or magnetic)
    EVOLIS_INF_CLEANING_RUNNING = 76,          //!< Cleaning is in progress
    EVOLIS_INF_WRONG_ZONE_ALERT = 77,          //!< Installed ribbon has wrong zone, there are only a few prints remaining before printing is blocked
    EVOLIS_INF_WRONG_ZONE_EXPIRED = 78,        //!< Installed ribbon has wrong zone, printing is not allowed
    EVOLIS_INF_SYNCH_PRINT_CENTER = 79,        //!< Raised by EPS during a pop-up
    EVOLIS_INF_UPDATING_FIRMWARE = 80,         //!< Firmware is currently downloading
    EVOLIS_INF_BUSY = 81,                      //!< The printer is busy (printing, encoding)
    EVOLIS_INF_NO_LAMINATION_TO_DO = 82,       //!< Lamination module is set to 'pass through' mode
    EVOLIS_INF_LAMI_ALLOW_TO_INSERT = 83,      //!< Lamination module ready to insert card
    EVOLIS_INF_LAMINATING_RUNNING = 84,        //!< Lamination process is running
    EVOLIS_INF_CLEAN_REMINDER = 85,            //!< Reminder to clean the laminator
    EVOLIS_INF_LAMI_TEMP_NOT_READY = 86,       //!< Lamination roller is heating up, but its temperature is currently too low for the lamination process
    EVOLIS_INF_SYNCHRONOUS_MODE = 87,          //!< Lamination process is set to synchronous
    EVOLIS_INF_LCD_BUT_ACK = 88,               //!< LCD pop up button acknowledged
    EVOLIS_INF_LCD_BUT_OK = 89,                //!< LCD pop up OK button pressed
    EVOLIS_INF_LCD_BUT_RETRY = 90,             //!< LCD pop up Retry button pressed
    EVOLIS_INF_LCD_BUT_CANCEL = 91,            //!< LCD pop up Cancel button pressed
    EVOLIS_INF_FEEDER_NEAR_EMPTY = 92,         //!< Feeder is near empty (low level sensor)
    EVOLIS_INF_FEEDER1_EMPTY = 93,             //!< Feeder 1 is empty for KM2000B
    EVOLIS_INF_FEEDER2_EMPTY = 94,             //!< Feeder 2 is empty for KM2000B
    EVOLIS_INF_FEEDER3_EMPTY = 95,             //!< Feeder 3 is empty for KM2000B
    EVOLIS_INF_FEEDER4_EMPTY = 96,             //!< Feeder 4 is empty for KM2000B
    EVOLIS_INF_FEEDER1_NEAR_EMPTY = 97,        //!< Feeder 1 is near empty for KM2000B
    EVOLIS_INF_FEEDER2_NEAR_EMPTY = 98,        //!< Feeder 2 is near empty for KM2000B
    EVOLIS_INF_FEEDER3_NEAR_EMPTY = 99,        //!< Feeder 3 is near empty for KM2000B
    EVOLIS_INF_FEEDER4_NEAR_EMPTY = 100,       //!< Feeder 4 is near empty for KM2000B
    EVOLIS_INF_SA_PROCESSING = 101,            //!< Sensor adjustment is running
    EVOLIS_INF_SCP_PROCESSING = 102,           //!< Cleaning sequence is running
    EVOLIS_INF_OPT_PROCESSING = 103,           //!< Option activation is running (with activation key)
    EVOLIS_INF_X08_PRINTER_UNLOCKED = 104,     //!< Lock system currently unlocked
    EVOLIS_INF_X08_FEEDER_OPEN = 105,          //!< Feeder cover is open (used with locking system)
    EVOLIS_INF_X08_EJECTBOX_FULL = 106,        //!< Locking system feeder eject box full
    EVOLIS_INF_X08_PRINT_UNLOCKED = 107,       //!< Printing is currently unlocked, both mechanically and firmware-wise
    EVOLIS_INF_LAMINATE_UNKNOWN = 108,         //!< Installed laminate film is unknown/unreadable
    EVOLIS_INF_LAMINATE_LOW = 109,             //!< Laminate film is close to its end
    EVOLIS_INF_LAMI_CARD = 110,                //!< Card present in the lamination module
    EVOLIS_INF_LAMI_CLEANING_RUNNING = 111,    //!< Lamination module cleaning process is running
    EVOLIS_INF_LAMI_UPDATING_FIRMWARE = 112,   //!< Lamination module firmware update is running
    EVOLIS_INF_LAMI_READY_FOR_CLEANING = 113,  //!< Lamination module ready for cleaning (no laminate film and cover closed)
    EVOLIS_INF_CARD_REAR = 114,                //!< Card present at the rear of the printer
    EVOLIS_INF_CLEAR_UNKNOWN = 115,            //!< Installed clear ribbon is unknown
    EVOLIS_INF_CLEAR_LOW = 116,                //!< Remaining clear ribbon is below the low limit
    EVOLIS_INF_WRONG_ZONE_CLEAR = 117,         //!< Installed clear ribbon has not the right zone
    EVOLIS_INF_CLEAR_CHANGED = 118,            //!< Installed clear ribbon is different from the previous one
    EVOLIS_INF_WRONG_ZONE_CLEAR_ALERT = 119,   //!< Installed clear ribbon has wrong zone: only a few prints remaining before printing is blocked
    EVOLIS_INF_WRONG_ZONE_CLEAR_EXPIRED = 120, //!< Installed clear ribbon has wrong zone: printing not allowed
    EVOLIS_INF_RETRANSFER_RUNNING = 121,       //!< Retransfer sequence is running
    EVOLIS_INF_HEATING = 122,                  //!< Printer is heating up
    EVOLIS_INF_CARD_MAN_FEED = 123,            //!< Card present in the manual feeding module
    EVOLIS_INF_HEAT_ROLLER_WORN_OUT = 124,     //!< Heat roller reached its maximum recommended of retransfers
    EVOLIS_INF_PRE_HEATING_PRINT_HEAD = 125,   //!< Print head pre heating in progress
    EVOLIS_INF_CARD_BRIDGE = 126,              //!< The card is located in the bridge module
    EVOLIS_INF_CARD_INDENTING = 127,           //!< The card is located in the indenting module
    EVOLIS_INF_BRIDGE_UPDATING_FIRMWARE = 128, //!< Bridge module firmware update is running
    EVOLIS_INF_CASSETTE_PRESENCE = 129,        //!< Internal K7 is inserted into feeder
    EVOLIS_WAR_POWER_SUPPLY = 130,             //!< Power supply voltage is too low
    EVOLIS_WAR_REMOVE_RIBBON = 131,            //!< Ribbon must be removed (in rewrite mode)
    EVOLIS_WAR_RECEPTACLE_OPEN = 132,          //!< Not used
    EVOLIS_WAR_REJECT_BOX_FULL = 133,          //!< Reject box is full
    EVOLIS_WAR_CARD_ON_EJECT = 134,            //!< Card in eject position and has to be removed (in manual insertion mode)
    EVOLIS_WAR_WAIT_CARD = 135,                //!< Printer is waiting for manual card insertion
    EVOLIS_WAR_FEEDER_EMPTY = 136,             //!< Feeder is empty
    EVOLIS_WAR_COOLING = 137,                  //!< Print head temperature too high: cooling down
    EVOLIS_WAR_HOPPER_FULL = 138,              //!< Printer hopper is full
    EVOLIS_WAR_RIBBON_ENDED = 139,             //!< Installed ribbon reached its end
    EVOLIS_WAR_PRINTER_LOCKED = 140,           //!< Printer is locked (used with locking system)
    EVOLIS_WAR_COVER_OPEN = 141,               //!< Printer cover is opened
    EVOLIS_WAR_NO_RIBBON = 142,                //!< No ribbon detected in the printer
    EVOLIS_WAR_UNSUPPORTED_RIBBON = 143,       //!< Installed ribbon is not supported by the printer
    EVOLIS_WAR_NO_CLEAR = 144,                 //!< No clear ribbon installed
    EVOLIS_WAR_CLEAR_END = 145,                //!< Clear ribbon reached its end
    EVOLIS_WAR_CLEAR_UNSUPPORTED = 146,        //!< Installed clear ribbon is not supported by the printer
    EVOLIS_WAR_REJECT_BOX_COVER_OPEN = 147,    //!< Reject box cover is open
    EVOLIS_WAR_EPS_NO_AUTO = 148,              //!< For tagless ribbons, indicates to the EPS to not automatically set the ribbon
    EVOLIS_WAR_FEEDER_OPEN = 149,              //!< Printer feeder is opened
    EVOLIS_WAR_NO_LAMINATE = 150,              //!< No laminate film installed
    EVOLIS_WAR_LAMI_COVER_OPEN = 151,          //!< Lamination module cover is open
    EVOLIS_WAR_LAMINATE_END = 152,             //!< Laminate film reached its end
    EVOLIS_WAR_LAMI_HOPPER_FULL = 153,         //!< Lamination module hopper is full
    EVOLIS_WAR_LAMINATE_UNSUPPORTED = 154,     //!< Installed laminate film is not supported
    EVOLIS_WAR_REJECT_BOX_ALMOST_FULL = 155,   //!< Reject box is almost full
    EVOLIS_ERR_HEAD_TEMP = 156,                //!< Job interrupted because the print head temperature was too high
    EVOLIS_ERR_NO_OPTION = 157,                //!< Requested option is not available
    EVOLIS_ERR_FEEDER_ERROR = 158,             //!< Error while feeding a card
    EVOLIS_ERR_RIBBON_ERROR = 159,             //!< Ribbon error during printing
    EVOLIS_ERR_COVER_OPEN = 160,               //!< Job interrupted by an open cover
    EVOLIS_ERR_MECHANICAL = 161,               //!< Mechanical error (card jam, ribbon jam, ...)
    EVOLIS_ERR_REJECT_BOX_FULL = 162,          //!< Card sent to reject box but it was full
    EVOLIS_ERR_BAD_RIBBON = 163,               //!< Job interrupted because the installed ribbon is not the one expected
    EVOLIS_ERR_RIBBON_ENDED = 164,             //!< Job interrupted because the ribbon is finished
    EVOLIS_ERR_HOPPER_FULL = 165,              //!< Card sent to hopper but it was full
    EVOLIS_ERR_BLANK_TRACK = 166,              //!< No data on track after magnetic reading
    EVOLIS_ERR_MAGNETIC_DATA = 167,            //!< Magnetic data is not matching the settings
    EVOLIS_ERR_READ_MAGNETIC = 168,            //!< Corrupted/absent data on track after magnetic reading
    EVOLIS_ERR_WRITE_MAGNETIC = 169,           //!< Corrupted/absent data on track after magnetic encoding
    EVOLIS_ERR_FEATURE = 170,                  //!< Job sent is not supported by the printer
    EVOLIS_ERR_RET_TEMPERATURE = 171,          //!< Retransfer roller couldn't reach its operating temperature in time
    EVOLIS_ERR_CLEAR_ERROR = 172,              //!< Clear ribbon error during printing
    EVOLIS_ERR_CLEAR_ENDED = 173,              //!< Job interrupted because the clear ribbon is finished
    EVOLIS_ERR_BAD_CLEAR = 174,                //!< Job interrupted because the installed clear ribbon is not the one expected
    EVOLIS_ERR_REJECT_BOX_COVER_OPEN = 175,    //!< Card sent to reject box but its cover was open
    EVOLIS_ERR_CARD_ON_EJECT = 176,            //!< Card in eject position was not removed in time (in manual insertion mode)
    EVOLIS_ERR_NO_CARD_INSERTED = 177,         //!< No card was presented in time (in manual insertion mode)
    EVOLIS_ERR_FEEDER_OPEN = 178,              //!< Job interrupted because the printer feeder is opened
    EVOLIS_ERR_LAMI_TEMPERATURE = 179,         //!< Job interrupted because the laminator temperature was too high
    EVOLIS_ERR_LAMINATE = 180,                 //!< Error on the laminate film
    EVOLIS_ERR_LAMI_MECHANICAL = 181,          //!< Mechanical error on the lamination module (card jam, ribbon jam, ...)
    EVOLIS_ERR_LAMINATE_END = 182,             //!< Job interrupted because the laminate film is finished
    EVOLIS_ERR_LAMI_COVER_OPEN = 183,          //!< Job interrupted by an open lamination module cover
    EVOLIS_ERR_PRE_HEATING_PRINT_HEAD = 184,   //!< Print head pre heating : target not reach under the timeout on the last cycle
    EVOLIS_RSV_WAR_0X20000000 = 185,           //!< Reserved flag WAR:0x20000000
    EVOLIS_RSV_WAR_0X00800000 = 186,           //!< Reserved flag WAR:0x00800000
    EVOLIS_RSV_WAR_0X00400000 = 187,           //!< Reserved flag WAR:0x00400000
    EVOLIS_RSV_WAR_0X00004000 = 188,           //!< Reserved flag WAR:0x00004000
    EVOLIS_RSV_WAR_0X00000080 = 189,           //!< Reserved flag WAR:0x00000080
    EVOLIS_RSV_WAR_0X00000040 = 190,           //!< Reserved flag WAR:0x00000040
    EVOLIS_RSV_WAR_0X00000020 = 191,           //!< Reserved flag WAR:0x00000020
    EVOLIS_RSV_WAR_0X00000010 = 192,           //!< Reserved flag WAR:0x00000010
    EVOLIS_RSV_WAR_0X00000008 = 193,           //!< Reserved flag WAR:0x00000008
    EVOLIS_RSV_WAR_0X00000004 = 194,           //!< Reserved flag WAR:0x00000004
    EVOLIS_RSV_WAR_0X00000002 = 195,           //!< Reserved flag WAR:0x00000002
    EVOLIS_RSV_WAR_0X00000001 = 196,           //!< Reserved flag WAR:0x00000001
    EVOLIS_RSV_ERR_0X80000000 = 197,           //!< Reserved flag ERR:0x80000000
    EVOLIS_RSV_ERR_0X40000000 = 198,           //!< Reserved flag ERR:0x40000000
    EVOLIS_RSV_ERR_0X00000040 = 199,           //!< Reserved flag ERR:0x00000040
    EVOLIS_RSV_ERR_0X00000020 = 200,           //!< Reserved flag ERR:0x00000020
    EVOLIS_RSV_ERR_0X00000010 = 201,           //!< Reserved flag ERR:0x00000010
    EVOLIS_RSV_ERR_0X00000008 = 202,           //!< Reserved flag ERR:0x00000008
    EVOLIS_RSV_ERR_0X00000004 = 203,           //!< Reserved flag ERR:0x00000004
    EVOLIS_RSV_ERR_0X00000002 = 204,           //!< Reserved flag ERR:0x00000002
    EVOLIS_RSV_ERR_0X00000001 = 205,           //!< Reserved flag ERR:0x00000001
    EVOLIS_RSV_EX3_0X10000000 = 206,           //!< Reserved flag EX3:0x10000000
    EVOLIS_RSV_EX3_0X00800000 = 207,           //!< Reserved flag EX3:0x00800000
    EVOLIS_RSV_EX3_0X00400000 = 208,           //!< Reserved flag EX3:0x00400000
    EVOLIS_RSV_EX3_0X00200000 = 209,           //!< Reserved flag EX3:0x00200000
    EVOLIS_RSV_EX3_0X00100000 = 210,           //!< Reserved flag EX3:0x00100000
    EVOLIS_RSV_EX3_0X00080000 = 211,           //!< Reserved flag EX3:0x00080000
    EVOLIS_RSV_EX3_0X00040000 = 212,           //!< Reserved flag EX3:0x00040000
    EVOLIS_RSV_EX3_0X00020000 = 213,           //!< Reserved flag EX3:0x00020000
    EVOLIS_RSV_EX3_0X00010000 = 214,           //!< Reserved flag EX3:0x00010000
    EVOLIS_RSV_EX3_0X00008000 = 215,           //!< Reserved flag EX3:0x00008000
    EVOLIS_RSV_EX3_0X00004000 = 216,           //!< Reserved flag EX3:0x00004000
    EVOLIS_RSV_EX3_0X00002000 = 217,           //!< Reserved flag EX3:0x00002000
    EVOLIS_RSV_EX3_0X00001000 = 218,           //!< Reserved flag EX3:0x00001000
    EVOLIS_RSV_EX3_0X00000800 = 219,           //!< Reserved flag EX3:0x00000800
    EVOLIS_RSV_EX3_0X00000400 = 220,           //!< Reserved flag EX3:0x00000400
    EVOLIS_RSV_EX3_0X00000200 = 221,           //!< Reserved flag EX3:0x00000200
    EVOLIS_RSV_EX3_0X00000100 = 222,           //!< Reserved flag EX3:0x00000100
    EVOLIS_RSV_EX3_0X00000001 = 223,           //!< Reserved flag EX3:0x00000001
} evolis_flag_t;

/// Flag values. The resulting structure is as follow:
/// X(NAME, TYPE, BITMASK, COMMENT, DSE_NAME)
#define EVOLIS_FLAGS(X) \
    X(EVOLIS_CFG_X01, CFG, 0x80000000, "Raised for Primacy, KC200B, KC200, Issengo", DSE_STDEVOLIS_CFG_X01) \
    X(EVOLIS_CFG_X02, CFG, 0x40000000, "Raised for Zenius", DSE_STDEVOLIS_CFG_X02) \
    X(EVOLIS_CFG_R02, CFG, 0x20000000, "Raised for Agilia", DSE_STDEVOLIS_CFG_R02) \
    X(EVOLIS_CFG_X04, CFG, 0x10000000, "Raised for Elypso", DSE_STDEVOLIS_CFG_X04) \
    X(EVOLIS_CFG_EXTENSION_1, CFG, 0x08000000, "Extension 1 is used", DSE_STDEVOLIS_CFG_EXTENSION_1) \
    X(EVOLIS_CFG_S01, CFG, 0x04000000, "Raised for Badgy, Apteo", DSE_STDEVOLIS_CFG_S01) \
    X(EVOLIS_CFG_X07, CFG, 0x02000000, "Not used", DSE_STDEVOLIS_CFG_X07) \
    X(EVOLIS_CFG_KC200, CFG, 0x01000000, "Raised for KC200B, KC200", DSE_STDEVOLIS_CFG_KC200) \
    X(EVOLIS_CFG_WIFI, CFG, 0x00800000, "WiFi option is detected", DSE_STDEVOLIS_CFG_WIFI) \
    X(EVOLIS_CFG_ETHERNET, CFG, 0x00400000, "Ethernet option is detected", DSE_STDEVOLIS_CFG_ETHERNET) \
    X(EVOLIS_CFG_USB_OVER_IP, CFG, 0x00200000, "USB over IP option is set", DSE_STDEVOLIS_CFG_USB_OVER_IP) \
    X(EVOLIS_CFG_FLIP, CFG, 0x00100000, "Flip-over option is detected", DSE_STDEVOLIS_CFG_FLIP) \
    X(EVOLIS_CFG_CONTACTLESS, CFG, 0x00080000, "Contactless option is detected", DSE_STDEVOLIS_CFG_CONTACTLESS) \
    X(EVOLIS_CFG_SMART, CFG, 0x00040000, "Smart option is detected", DSE_STDEVOLIS_CFG_SMART) \
    X(EVOLIS_CFG_MAGNETIC, CFG, 0x00020000, "Magnetic option is detected", DSE_STDEVOLIS_CFG_MAGNETIC) \
    X(EVOLIS_CFG_REWRITE, CFG, 0x00010000, "Rewrite mode is activated", DSE_STDEVOLIS_CFG_REWRITE) \
    X(EVOLIS_CFG_FEED_MANUALLY, CFG, 0x00008000, "Card feeding is configured as manual", DSE_STDEVOLIS_CFG_FEED_MANUALLY) \
    X(EVOLIS_CFG_FEED_BY_CDE, CFG, 0x00004000, "Card feeding is set as manual once the feeding command is received", DSE_STDEVOLIS_CFG_FEED_BY_CDE) \
    X(EVOLIS_CFG_FEED_BY_FEEDER, CFG, 0x00002000, "Card feeding is configured as feeder", DSE_STDEVOLIS_CFG_FEED_BY_FEEDER) \
    X(EVOLIS_CFG_EJECT_REVERSE, CFG, 0x00001000, "Card ejection goes to manual feeder", DSE_STDEVOLIS_CFG_EJECT_REVERSE) \
    X(EVOLIS_CFG_FEED_CDE_REVERSE, CFG, 0x00000800, "Card insertion is set to the rear of the printer", DSE_STDEVOLIS_CFG_FEED_CDE_REVERSE) \
    X(EVOLIS_CFG_EXTENDED_RESOLUTION, CFG, 0x00000400, "Extended resolution supported (600DPI, 1200DPI)", DSE_STDEVOLIS_CFG_EXTENDED_RESOLUTION) \
    X(EVOLIS_CFG_LCD, CFG, 0x00000200, "LCD option detected", DSE_STDEVOLIS_CFG_LCD) \
    X(EVOLIS_CFG_LOCK, CFG, 0x00000100, "Locking system detected", DSE_STDEVOLIS_CFG_LOCK) \
    X(EVOLIS_CFG_OEM, CFG, 0x00000080, "Raised for rebranded products", DSE_STDEVOLIS_CFG_OEM) \
    X(EVOLIS_CFG_JIS_MAG_HEAD, CFG, 0x00000040, "JIS magnetic option detected", DSE_STDEVOLIS_CFG_JIS_MAG_HEAD) \
    X(EVOLIS_CFG_REJECT_SLOT, CFG, 0x00000020, "Reject slot enabled", DSE_STDEVOLIS_CFG_REJECT_SLOT) \
    X(EVOLIS_CFG_IO_EXT, CFG, 0x00000010, "IO extender detected", DSE_STDEVOLIS_CFG_IO_EXT) \
    X(EVOLIS_CFG_MONO_ONLY, CFG, 0x00000008, "Monochrome only printing authorized", DSE_STDEVOLIS_CFG_MONO_ONLY) \
    X(EVOLIS_CFG_KC100, CFG, 0x00000004, "Raised for KC100", DSE_STDEVOLIS_CFG_KC100) \
    X(EVOLIS_CFG_KINE, CFG, 0x00000002, "Kineclipse option is available", DSE_UNDEFINED) \
    X(EVOLIS_CFG_WIFI_ENA, CFG, 0x00000001, "WiFi option is activated", DSE_STDEVOLIS_CFG_WIFI_ENA) \
    X(EVOLIS_CFG_EXTENSION_2, EX1, 0x80000000, "Extension 2 is used", DSE_STDEVOLIS_CFG_EXTENSION_2) \
    X(EVOLIS_CFG_KIOSK, EX1, 0x40000000, "Raised for KM500B, KM2000B", DSE_STDEVOLIS_CFG_KIOSK) \
    X(EVOLIS_CFG_QUANTUM, EX1, 0x20000000, "Raised for Quantum", DSE_STDEVOLIS_CFG_QUANTUM) \
    X(EVOLIS_CFG_SECURION, EX1, 0x10000000, "Raised for Securion", DSE_STDEVOLIS_CFG_SECURION) \
    X(EVOLIS_CFG_DUALYS, EX1, 0x08000000, "Raised for Dualys", DSE_STDEVOLIS_CFG_DUALYS) \
    X(EVOLIS_CFG_PEBBLE, EX1, 0x04000000, "Raised for Pebble", DSE_STDEVOLIS_CFG_PEBBLE) \
    X(EVOLIS_CFG_SCANNER, EX1, 0x02000000, "Scanner option is detected", DSE_UNDEFINED) \
    X(EVOLIS_CFG_MEM_LAMINATION_MODULE_2, EX1, 0x01000000, "Printer has previously seen 2 lamination modules simultaneously", DSE_LAMINATOR_CFG_MEM_LAMINATION_MODULE_2) \
    X(EVOLIS_CFG_SEICO_FEEDER, EX1, 0x00400000, "Seico feeder configured", DSE_STDEVOLIS_CFG_SEICO_FEEDER) \
    X(EVOLIS_CFG_KYTRONIC_FEEDER, EX1, 0x00200000, "Kytronics feeder configured", DSE_STDEVOLIS_CFG_KYTRONIC_FEEDER) \
    X(EVOLIS_CFG_HOPPER, EX1, 0x00100000, "Not used", DSE_STDEVOLIS_CFG_HOPPER) \
    X(EVOLIS_CFG_LAMINATOR, EX1, 0x00080000, "Lamination module detected", DSE_LAMINATOR_CFG_LAMINATOR) \
    X(EVOLIS_CFG_BEZEL, EX1, 0x00000200, "Bezel option installed", DSE_STDEVOLIS_CFG_BEZEL) \
    X(EVOLIS_CFG_EXTENSION_3, EX2, 0x80000000, "Extension 3 is used", DSE_STDEVOLIS_CFG_EXTENSION_3) \
    X(EVOLIS_CFG_LAMINATION_MODULE_2, EX2, 0x00800000, "Second lamination module detected", DSE_LAMINATOR_CFG_LAMINATION_MODULE_2) \
    X(EVOLIS_CFG_EXTENSION_4, EX3, 0x80000000, "Extension 4 is used", DSE_STDEVOLIS_CFG_EXTENSION_4) \
    X(EVOLIS_CFG_BRIDGE, EX3, 0x00000080, "Configuration for bridge module", DSE_UNDEFINED) \
    X(EVOLIS_CFG_INDENTING, EX3, 0x00000020, "Configuration for indenting module", DSE_UNDEFINED) \
    X(EVOLIS_INF_CLAIM, INF, 0x80000000, "Raised when EPS printing", DSE_STDEVOLIS_INF_CLAIM) \
    X(EVOLIS_INF_CARD_HOPPER, INF, 0x40000000, "Card present at the hopper", DSE_STDEVOLIS_INF_CARD_HOPPER) \
    X(EVOLIS_INF_CARD_FEEDER, INF, 0x20000000, "Card present in the feeder", DSE_STDEVOLIS_INF_CARD_FEEDER) \
    X(EVOLIS_INF_CARD_FLIP, INF, 0x10000000, "Card present in the flip-over", DSE_STDEVOLIS_INF_CARD_FLIP) \
    X(EVOLIS_INF_CARD_CONTACTLESS, INF, 0x08000000, "Card present in contactless card station", DSE_STDEVOLIS_INF_CARD_CONTACTLESS) \
    X(EVOLIS_INF_CARD_SMART, INF, 0x04000000, "Card present in smart card station", DSE_STDEVOLIS_INF_CARD_SMART) \
    X(EVOLIS_INF_CARD_PRINT, INF, 0x02000000, "Card present in printing position", DSE_STDEVOLIS_INF_CARD_PRINT) \
    X(EVOLIS_INF_CARD_EJECT, INF, 0x01000000, "Card present in eject position", DSE_STDEVOLIS_INF_CARD_EJECT) \
    X(EVOLIS_INF_PRINTER_MASTER, INF, 0x00800000, "Error management is set to 'printer'", DSE_STDEVOLIS_INF_PRINTER_MASTER) \
    X(EVOLIS_INF_PCSVC_LOCKED, INF, 0x00400000, "The EPS is supervising the printer", DSE_STDEVOLIS_INF_PCSVC_LOCKED) \
    X(EVOLIS_INF_SLEEP_MODE, INF, 0x00200000, "Printer is in sleep mode", DSE_DEVICE_INF_SLEEP_MODE) \
    X(EVOLIS_INF_UNKNOWN_RIBBON, INF, 0x00100000, "Installed ribbon is unknown/unreadable", DSE_STDEVOLIS_INF_UNKNOWN_RIBBON) \
    X(EVOLIS_INF_RIBBON_LOW, INF, 0x00080000, "Remaining ribbon is below low limit", DSE_STDEVOLIS_INF_RIBBON_LOW) \
    X(EVOLIS_INF_CLEANING_MANDATORY, INF, 0x00040000, "Cleaning is mandatory", DSE_STDEVOLIS_INF_CLEANING_MANDATORY) \
    X(EVOLIS_INF_CLEANING, INF, 0x00020000, "Cleaning is recommended", DSE_STDEVOLIS_INF_CLEANING) \
    X(EVOLIS_INF_RESET, INF, 0x00010000, "Printer has just rebooted", DSE_STDEVOLIS_INF_RESET) \
    X(EVOLIS_INF_CLEAN_OUTWARRANTY, INF, 0x00008000, "Warranty lost, cleaning has not been done in time", DSE_STDEVOLIS_INF_CLEAN_OUTWARRANTY) \
    X(EVOLIS_INF_CLEAN_LAST_OUTWARRANTY, INF, 0x00004000, "Cleaning is mandatory, next card printed will lose the warranty", DSE_STDEVOLIS_INF_CLEAN_LAST_OUTWARRANTY) \
    X(EVOLIS_INF_CLEAN_2ND_PASS, INF, 0x00002000, "Cleaning sequence requires the second cleaning card", DSE_STDEVOLIS_INF_CLEAN_2ND_PASS) \
    X(EVOLIS_INF_READY_FOR_CLEANING, INF, 0x00001000, "Printer ready for cleaning (ribbon has been removed and cover closed)", DSE_STDEVOLIS_INF_READY_FOR_CLEANING) \
    X(EVOLIS_INF_CLEANING_ADVANCED, INF, 0x00000800, "Advanced cleaning requested", DSE_STDEVOLIS_INF_CLEANING_ADVANCED) \
    X(EVOLIS_INF_WRONG_ZONE_RIBBON, INF, 0x00000400, "Installed ribbon has not the right zone", DSE_STDEVOLIS_INF_WRONG_ZONE_RIBBON) \
    X(EVOLIS_INF_RIBBON_CHANGED, INF, 0x00000200, "Installed ribbon is different from the previous one", DSE_STDEVOLIS_INF_RIBBON_CHANGED) \
    X(EVOLIS_INF_CLEANING_REQUIRED, INF, 0x00000100, "Cleaning is required", DSE_STDEVOLIS_INF_CLEANING_REQUIRED) \
    X(EVOLIS_INF_PRINTING_RUNNING, INF, 0x00000080, "Printing is in progress", DSE_STDEVOLIS_INF_PRINTING_RUNNING) \
    X(EVOLIS_INF_ENCODING_RUNNING, INF, 0x00000040, "Encoding is in progress (smart, contactless or magnetic)", DSE_STDEVOLIS_INF_ENCODING_RUNNING) \
    X(EVOLIS_INF_CLEANING_RUNNING, INF, 0x00000020, "Cleaning is in progress", DSE_STDEVOLIS_INF_CLEANING_RUNNING) \
    X(EVOLIS_INF_WRONG_ZONE_ALERT, INF, 0x00000010, "Installed ribbon has wrong zone, there are only a few prints remaining before printing is blocked", DSE_STDEVOLIS_INF_WRONG_ZONE_ALERT) \
    X(EVOLIS_INF_WRONG_ZONE_EXPIRED, INF, 0x00000008, "Installed ribbon has wrong zone, printing is not allowed", DSE_STDEVOLIS_INF_WRONG_ZONE_EXPIRED) \
    X(EVOLIS_INF_SYNCH_PRINT_CENTER, INF, 0x00000004, "Raised by EPS during a pop-up", DSE_STDEVOLIS_INF_SYNCH_PRINT_CENTER) \
    X(EVOLIS_INF_UPDATING_FIRMWARE, INF, 0x00000002, "Firmware is currently downloading", DSE_STDEVOLIS_INF_UPDATING_FIRMWARE) \
    X(EVOLIS_INF_BUSY, INF, 0x00000001, "The printer is busy (printing, encoding)", DSE_STDEVOLIS_INF_BUSY) \
    X(EVOLIS_INF_NO_LAMINATION_TO_DO, EX1, 0x00800000, "Lamination module is set to 'pass through' mode", DSE_LAMINATOR_INF_NO_LAMINATION_TO_DO) \
    X(EVOLIS_INF_LAMI_ALLOW_TO_INSERT, EX1, 0x00040000, "Lamination module ready to insert card", DSE_LAMINATOR_INF_LAMI_ALLOW_TO_INSERT) \
    X(EVOLIS_INF_LAMINATING_RUNNING, EX1, 0x00020000, "Lamination process is running", DSE_LAMINATOR_INF_LAMINATING_RUNNING) \
    X(EVOLIS_INF_CLEAN_REMINDER, EX1, 0x00010000, "Reminder to clean the laminator", DSE_STDEVOLIS_INF_CLEAN_REMINDER) \
    X(EVOLIS_INF_LAMI_TEMP_NOT_READY, EX1, 0x00008000, "Lamination roller is heating up, but its temperature is currently too low for the lamination process", DSE_LAMINATOR_INF_LAMI_TEMP_NOT_READY) \
    X(EVOLIS_INF_SYNCHRONOUS_MODE, EX1, 0x00004000, "Lamination process is set to synchronous", DSE_LAMINATOR_INF_SYNCHRONOUS_MODE) \
    X(EVOLIS_INF_LCD_BUT_ACK, EX1, 0x00002000, "LCD pop up button acknowledged", DSE_STDEVOLIS_INF_LCD_BUT_ACK) \
    X(EVOLIS_INF_LCD_BUT_OK, EX1, 0x00001000, "LCD pop up OK button pressed", DSE_STDEVOLIS_INF_LCD_BUT_OK) \
    X(EVOLIS_INF_LCD_BUT_RETRY, EX1, 0x00000800, "LCD pop up Retry button pressed", DSE_STDEVOLIS_INF_LCD_BUT_RETRY) \
    X(EVOLIS_INF_LCD_BUT_CANCEL, EX1, 0x00000400, "LCD pop up Cancel button pressed", DSE_STDEVOLIS_INF_LCD_BUT_CANCEL) \
    X(EVOLIS_INF_FEEDER_NEAR_EMPTY, EX1, 0x00000100, "Feeder is near empty (low level sensor)", DSE_STDEVOLIS_INF_FEEDER_NEAR_EMPTY) \
    X(EVOLIS_INF_FEEDER1_EMPTY, EX1, 0x00000080, "Feeder 1 is empty for KM2000B", DSE_STDEVOLIS_INF_FEEDER1_EMPTY) \
    X(EVOLIS_INF_FEEDER2_EMPTY, EX1, 0x00000040, "Feeder 2 is empty for KM2000B", DSE_STDEVOLIS_INF_FEEDER2_EMPTY) \
    X(EVOLIS_INF_FEEDER3_EMPTY, EX1, 0x00000020, "Feeder 3 is empty for KM2000B", DSE_STDEVOLIS_INF_FEEDER3_EMPTY) \
    X(EVOLIS_INF_FEEDER4_EMPTY, EX1, 0x00000010, "Feeder 4 is empty for KM2000B", DSE_STDEVOLIS_INF_FEEDER4_EMPTY) \
    X(EVOLIS_INF_FEEDER1_NEAR_EMPTY, EX1, 0x00000008, "Feeder 1 is near empty for KM2000B", DSE_STDEVOLIS_INF_FEEDER1_NEAR_EMPTY) \
    X(EVOLIS_INF_FEEDER2_NEAR_EMPTY, EX1, 0x00000004, "Feeder 2 is near empty for KM2000B", DSE_STDEVOLIS_INF_FEEDER2_NEAR_EMPTY) \
    X(EVOLIS_INF_FEEDER3_NEAR_EMPTY, EX1, 0x00000002, "Feeder 3 is near empty for KM2000B", DSE_STDEVOLIS_INF_FEEDER3_NEAR_EMPTY) \
    X(EVOLIS_INF_FEEDER4_NEAR_EMPTY, EX1, 0x00000001, "Feeder 4 is near empty for KM2000B", DSE_STDEVOLIS_INF_FEEDER4_NEAR_EMPTY) \
    X(EVOLIS_INF_SA_PROCESSING, EX2, 0x40000000, "Sensor adjustment is running", DSE_STDEVOLIS_INF_SA_PROCESSING) \
    X(EVOLIS_INF_SCP_PROCESSING, EX2, 0x20000000, "Cleaning sequence is running", DSE_STDEVOLIS_INF_SCP_PROCESSING) \
    X(EVOLIS_INF_OPT_PROCESSING, EX2, 0x10000000, "Option activation is running (with activation key)", DSE_STDEVOLIS_INF_OPT_PROCESSING) \
    X(EVOLIS_INF_X08_PRINTER_UNLOCKED, EX2, 0x08000000, "Lock system currently unlocked", DSE_STDEVOLIS_INF_X08_PRINTER_UNLOCKED) \
    X(EVOLIS_INF_X08_FEEDER_OPEN, EX2, 0x04000000, "Feeder cover is open (used with locking system)", DSE_STDEVOLIS_INF_X08_FEEDER_OPEN) \
    X(EVOLIS_INF_X08_EJECTBOX_FULL, EX2, 0x02000000, "Locking system feeder eject box full", DSE_STDEVOLIS_INF_X08_EJECTBOX_FULL) \
    X(EVOLIS_INF_X08_PRINT_UNLOCKED, EX2, 0x01000000, "Printing is currently unlocked, both mechanically and firmware-wise", DSE_STDEVOLIS_INF_X08_PRINT_UNLOCKED) \
    X(EVOLIS_INF_LAMINATE_UNKNOWN, EX2, 0x00400000, "Installed laminate film is unknown/unreadable", DSE_LAMINATOR_INF_LAMINATE_UNKNOWN) \
    X(EVOLIS_INF_LAMINATE_LOW, EX2, 0x00200000, "Laminate film is close to its end", DSE_LAMINATOR_INF_LAMINATE_LOW) \
    X(EVOLIS_INF_LAMI_CARD, EX2, 0x00100000, "Card present in the lamination module", DSE_LAMINATOR_INF_LAMI_CARD) \
    X(EVOLIS_INF_LAMI_CLEANING_RUNNING, EX2, 0x00080000, "Lamination module cleaning process is running", DSE_LAMINATOR_INF_LAMI_CLEANING_RUNNING) \
    X(EVOLIS_INF_LAMI_UPDATING_FIRMWARE, EX2, 0x00040000, "Lamination module firmware update is running", DSE_LAMINATOR_INF_LAMI_UPDATING_FIRMWARE) \
    X(EVOLIS_INF_LAMI_READY_FOR_CLEANING, EX2, 0x00020000, "Lamination module ready for cleaning (no laminate film and cover closed)", DSE_LAMINATOR_INF_LAMI_READY_FOR_CLEANING) \
    X(EVOLIS_INF_CARD_REAR, EX2, 0x00010000, "Card present at the rear of the printer", DSE_STDEVOLIS_INF_CARD_REAR) \
    X(EVOLIS_INF_CLEAR_UNKNOWN, EX2, 0x00000400, "Installed clear ribbon is unknown", DSE_STDEVOLIS_INF_CLEAR_UNKNOWN) \
    X(EVOLIS_INF_CLEAR_LOW, EX2, 0x00000200, "Remaining clear ribbon is below the low limit", DSE_STDEVOLIS_INF_CLEAR_LOW) \
    X(EVOLIS_INF_WRONG_ZONE_CLEAR, EX2, 0x00000100, "Installed clear ribbon has not the right zone", DSE_STDEVOLIS_INF_WRONG_ZONE_CLEAR) \
    X(EVOLIS_INF_CLEAR_CHANGED, EX2, 0x00000004, "Installed clear ribbon is different from the previous one", DSE_STDEVOLIS_INF_CLEAR_CHANGED) \
    X(EVOLIS_INF_WRONG_ZONE_CLEAR_ALERT, EX2, 0x00000002, "Installed clear ribbon has wrong zone: only a few prints remaining before printing is blocked", DSE_STDEVOLIS_INF_WRONG_ZONE_CLEAR_ALERT) \
    X(EVOLIS_INF_WRONG_ZONE_CLEAR_EXPIRED, EX2, 0x00000001, "Installed clear ribbon has wrong zone: printing not allowed", DSE_STDEVOLIS_INF_WRONG_ZONE_CLEAR_EXPIRED) \
    X(EVOLIS_INF_RETRANSFER_RUNNING, EX3, 0x40000000, "Retransfer sequence is running", DSE_STDEVOLIS_INF_RETRANSFER_RUNNING) \
    X(EVOLIS_INF_HEATING, EX3, 0x20000000, "Printer is heating up", DSE_STDEVOLIS_INF_HEATING) \
    X(EVOLIS_INF_CARD_MAN_FEED, EX3, 0x08000000, "Card present in the manual feeding module", DSE_STDEVOLIS_INF_CARD_MAN_FEED) \
    X(EVOLIS_INF_HEAT_ROLLER_WORN_OUT, EX3, 0x04000000, "Heat roller reached its maximum recommended of retransfers", DSE_STDEVOLIS_INF_HEAT_ROLLER_WORN_OUT) \
    X(EVOLIS_INF_PRE_HEATING_PRINT_HEAD, EX3, 0x02000000, "Print head pre heating in progress", DSE_STDEVOLIS_INF_PRE_HEATING_PRINT_HEAD) \
    X(EVOLIS_INF_CARD_BRIDGE, EX3, 0x00000040, "The card is located in the bridge module", DSE_UNDEFINED) \
    X(EVOLIS_INF_CARD_INDENTING, EX3, 0x00000010, "The card is located in the indenting module", DSE_UNDEFINED) \
    X(EVOLIS_INF_BRIDGE_UPDATING_FIRMWARE, EX3, 0x00000008, "Bridge module firmware update is running", DSE_UNDEFINED) \
    X(EVOLIS_INF_CASSETTE_PRESENCE, EX3, 0x00000002, "Internal K7 is inserted into feeder", DSE_UNDEFINED) \
    X(EVOLIS_WAR_POWER_SUPPLY, WAR, 0x80000000, "Power supply voltage is too low", DSE_STDEVOLIS_DEF_POWER_SUPPLY) \
    X(EVOLIS_WAR_REMOVE_RIBBON, WAR, 0x40000000, "Ribbon must be removed (in rewrite mode)", DSE_STDEVOLIS_DEF_REMOVE_RIBBON) \
    X(EVOLIS_WAR_RECEPTACLE_OPEN, WAR, 0x10000000, "Not used", DSE_STDEVOLIS_DEF_RECEPTACLE_OPEN) \
    X(EVOLIS_WAR_REJECT_BOX_FULL, WAR, 0x08000000, "Reject box is full", DSE_STDEVOLIS_DEF_REJECT_BOX_FULL) \
    X(EVOLIS_WAR_CARD_ON_EJECT, WAR, 0x04000000, "Card in eject position and has to be removed (in manual insertion mode)", DSE_STDEVOLIS_DEF_CARD_ON_EJECT) \
    X(EVOLIS_WAR_WAIT_CARD, WAR, 0x02000000, "Printer is waiting for manual card insertion", DSE_STDEVOLIS_DEF_WAIT_CARD) \
    X(EVOLIS_WAR_FEEDER_EMPTY, WAR, 0x01000000, "Feeder is empty", DSE_STDEVOLIS_DEF_FEEDER_EMPTY) \
    X(EVOLIS_WAR_COOLING, WAR, 0x00200000, "Print head temperature too high: cooling down", DSE_STDEVOLIS_DEF_COOLING) \
    X(EVOLIS_WAR_HOPPER_FULL, WAR, 0x00100000, "Printer hopper is full", DSE_STDEVOLIS_DEF_HOPPER_FULL) \
    X(EVOLIS_WAR_RIBBON_ENDED, WAR, 0x00080000, "Installed ribbon reached its end", DSE_STDEVOLIS_DEF_RIBBON_ENDED) \
    X(EVOLIS_WAR_PRINTER_LOCKED, WAR, 0x00040000, "Printer is locked (used with locking system)", DSE_STDEVOLIS_DEF_PRINTER_LOCKED) \
    X(EVOLIS_WAR_COVER_OPEN, WAR, 0x00020000, "Printer cover is opened", DSE_STDEVOLIS_DEF_COVER_OPEN) \
    X(EVOLIS_WAR_NO_RIBBON, WAR, 0x00010000, "No ribbon detected in the printer", DSE_STDEVOLIS_DEF_NO_RIBBON) \
    X(EVOLIS_WAR_UNSUPPORTED_RIBBON, WAR, 0x00008000, "Installed ribbon is not supported by the printer", DSE_STDEVOLIS_DEF_UNSUPPORTED_RIBBON) \
    X(EVOLIS_WAR_NO_CLEAR, WAR, 0x00002000, "No clear ribbon installed", DSE_STDEVOLIS_DEF_NO_CLEAR) \
    X(EVOLIS_WAR_CLEAR_END, WAR, 0x00001000, "Clear ribbon reached its end", DSE_STDEVOLIS_DEF_CLEAR_END) \
    X(EVOLIS_WAR_CLEAR_UNSUPPORTED, WAR, 0x00000800, "Installed clear ribbon is not supported by the printer", DSE_STDEVOLIS_DEF_CLEAR_UNSUPPORTED) \
    X(EVOLIS_WAR_REJECT_BOX_COVER_OPEN, WAR, 0x00000400, "Reject box cover is open", DSE_STDEVOLIS_DEF_REJECT_BOX_COVER_OPEN) \
    X(EVOLIS_WAR_EPS_NO_AUTO, WAR, 0x00000200, "For tagless ribbons, indicates to the EPS to not automatically set the ribbon", DSE_STDEVOLIS_DEF_EPS_NO_AUTO) \
    X(EVOLIS_WAR_FEEDER_OPEN, WAR, 0x00000100, "Printer feeder is opened", DSE_STDEVOLIS_DEF_FEEDER_OPEN) \
    X(EVOLIS_WAR_NO_LAMINATE, EX2, 0x00008000, "No laminate film installed", DSE_LAMINATOR_DEF_NO_LAMINATE) \
    X(EVOLIS_WAR_LAMI_COVER_OPEN, EX2, 0x00004000, "Lamination module cover is open", DSE_LAMINATOR_DEF_LAMI_COVER_OPEN) \
    X(EVOLIS_WAR_LAMINATE_END, EX2, 0x00002000, "Laminate film reached its end", DSE_LAMINATOR_DEF_LAMINATE_END) \
    X(EVOLIS_WAR_LAMI_HOPPER_FULL, EX2, 0x00001000, "Lamination module hopper is full", DSE_LAMINATOR_DEF_LAMI_HOPPER_FULL) \
    X(EVOLIS_WAR_LAMINATE_UNSUPPORTED, EX2, 0x00000800, "Installed laminate film is not supported", DSE_LAMINATOR_DEF_LAMINATE_UNSUPPORTED) \
    X(EVOLIS_WAR_REJECT_BOX_ALMOST_FULL, EX3, 0x00000004, "Reject box is almost full", DSE_UNDEFINED) \
    X(EVOLIS_ERR_HEAD_TEMP, ERR, 0x20000000, "Job interrupted because the print head temperature was too high", DSE_STDEVOLIS_ERR_HEAD_TEMP) \
    X(EVOLIS_ERR_NO_OPTION, ERR, 0x10000000, "Requested option is not available", DSE_STDEVOLIS_ERR_NO_OPTION) \
    X(EVOLIS_ERR_FEEDER_ERROR, ERR, 0x08000000, "Error while feeding a card", DSE_STDEVOLIS_ERR_FEEDER_ERROR) \
    X(EVOLIS_ERR_RIBBON_ERROR, ERR, 0x04000000, "Ribbon error during printing", DSE_STDEVOLIS_ERR_RIBBON_ERROR) \
    X(EVOLIS_ERR_COVER_OPEN, ERR, 0x02000000, "Job interrupted by an open cover", DSE_STDEVOLIS_ERR_COVER_OPEN) \
    X(EVOLIS_ERR_MECHANICAL, ERR, 0x01000000, "Mechanical error (card jam, ribbon jam, ...)", DSE_STDEVOLIS_ERR_MECHANICAL) \
    X(EVOLIS_ERR_REJECT_BOX_FULL, ERR, 0x00800000, "Card sent to reject box but it was full", DSE_STDEVOLIS_ERR_REJECT_BOX_FULL) \
    X(EVOLIS_ERR_BAD_RIBBON, ERR, 0x00400000, "Job interrupted because the installed ribbon is not the one expected", DSE_STDEVOLIS_ERR_BAD_RIBBON) \
    X(EVOLIS_ERR_RIBBON_ENDED, ERR, 0x00200000, "Job interrupted because the ribbon is finished", DSE_STDEVOLIS_ERR_RIBBON_ENDED) \
    X(EVOLIS_ERR_HOPPER_FULL, ERR, 0x00100000, "Card sent to hopper but it was full", DSE_STDEVOLIS_ERR_HOPPER_FULL) \
    X(EVOLIS_ERR_BLANK_TRACK, ERR, 0x00080000, "No data on track after magnetic reading", DSE_STDEVOLIS_ERR_BLANK_TRACK) \
    X(EVOLIS_ERR_MAGNETIC_DATA, ERR, 0x00040000, "Magnetic data is not matching the settings", DSE_STDEVOLIS_ERR_MAGNETIC_DATA) \
    X(EVOLIS_ERR_READ_MAGNETIC, ERR, 0x00020000, "Corrupted/absent data on track after magnetic reading", DSE_STDEVOLIS_ERR_READ_MAGNETIC) \
    X(EVOLIS_ERR_WRITE_MAGNETIC, ERR, 0x00010000, "Corrupted/absent data on track after magnetic encoding", DSE_STDEVOLIS_ERR_WRITE_MAGNETIC) \
    X(EVOLIS_ERR_FEATURE, ERR, 0x00008000, "Job sent is not supported by the printer", DSE_STDEVOLIS_ERR_FEATURE) \
    X(EVOLIS_ERR_RET_TEMPERATURE, ERR, 0x00004000, "Retransfer roller couldn't reach its operating temperature in time", DSE_STDEVOLIS_ERR_RET_TEMPERATURE) \
    X(EVOLIS_ERR_CLEAR_ERROR, ERR, 0x00002000, "Clear ribbon error during printing", DSE_STDEVOLIS_ERR_CLEAR_ERROR) \
    X(EVOLIS_ERR_CLEAR_ENDED, ERR, 0x00001000, "Job interrupted because the clear ribbon is finished", DSE_STDEVOLIS_ERR_CLEAR_ENDED) \
    X(EVOLIS_ERR_BAD_CLEAR, ERR, 0x00000800, "Job interrupted because the installed clear ribbon is not the one expected", DSE_STDEVOLIS_ERR_BAD_CLEAR) \
    X(EVOLIS_ERR_REJECT_BOX_COVER_OPEN, ERR, 0x00000400, "Card sent to reject box but its cover was open", DSE_STDEVOLIS_ERR_REJECT_BOX_COVER_OPEN) \
    X(EVOLIS_ERR_CARD_ON_EJECT, ERR, 0x00000200, "Card in eject position was not removed in time (in manual insertion mode)", DSE_STDEVOLIS_ERR_CARD_ON_EJECT) \
    X(EVOLIS_ERR_NO_CARD_INSERTED, ERR, 0x00000100, "No card was presented in time (in manual insertion mode)", DSE_STDEVOLIS_ERR_NO_CARD_INSERTED) \
    X(EVOLIS_ERR_FEEDER_OPEN, ERR, 0x00000080, "Job interrupted because the printer feeder is opened", DSE_STDEVOLIS_ERR_FEEDER_OPEN) \
    X(EVOLIS_ERR_LAMI_TEMPERATURE, EX2, 0x00000080, "Job interrupted because the laminator temperature was too high", DSE_LAMINATOR_ERR_LAMI_TEMPERATURE) \
    X(EVOLIS_ERR_LAMINATE, EX2, 0x00000040, "Error on the laminate film", DSE_LAMINATOR_ERR_LAMINATE) \
    X(EVOLIS_ERR_LAMI_MECHANICAL, EX2, 0x00000020, "Mechanical error on the lamination module (card jam, ribbon jam, ...)", DSE_LAMINATOR_ERR_LAMI_MECHANICAL) \
    X(EVOLIS_ERR_LAMINATE_END, EX2, 0x00000010, "Job interrupted because the laminate film is finished", DSE_LAMINATOR_ERR_LAMINATE_END) \
    X(EVOLIS_ERR_LAMI_COVER_OPEN, EX2, 0x00000008, "Job interrupted by an open lamination module cover", DSE_LAMINATOR_ERR_LAMI_COVER_OPEN) \
    X(EVOLIS_ERR_PRE_HEATING_PRINT_HEAD, EX3, 0x01000000, "Print head pre heating : target not reach under the timeout on the last cycle", DSE_STDEVOLIS_ERR_PRE_HEATING_PRINT_HEAD) \
    X(EVOLIS_RSV_WAR_0X20000000, WAR, 0x20000000, "Reserved flag WAR:0x20000000", DSE_UNDEFINED) \
    X(EVOLIS_RSV_WAR_0X00800000, WAR, 0x00800000, "Reserved flag WAR:0x00800000", DSE_UNDEFINED) \
    X(EVOLIS_RSV_WAR_0X00400000, WAR, 0x00400000, "Reserved flag WAR:0x00400000", DSE_UNDEFINED) \
    X(EVOLIS_RSV_WAR_0X00004000, WAR, 0x00004000, "Reserved flag WAR:0x00004000", DSE_UNDEFINED) \
    X(EVOLIS_RSV_WAR_0X00000080, WAR, 0x00000080, "Reserved flag WAR:0x00000080", DSE_UNDEFINED) \
    X(EVOLIS_RSV_WAR_0X00000040, WAR, 0x00000040, "Reserved flag WAR:0x00000040", DSE_UNDEFINED) \
    X(EVOLIS_RSV_WAR_0X00000020, WAR, 0x00000020, "Reserved flag WAR:0x00000020", DSE_UNDEFINED) \
    X(EVOLIS_RSV_WAR_0X00000010, WAR, 0x00000010, "Reserved flag WAR:0x00000010", DSE_UNDEFINED) \
    X(EVOLIS_RSV_WAR_0X00000008, WAR, 0x00000008, "Reserved flag WAR:0x00000008", DSE_UNDEFINED) \
    X(EVOLIS_RSV_WAR_0X00000004, WAR, 0x00000004, "Reserved flag WAR:0x00000004", DSE_UNDEFINED) \
    X(EVOLIS_RSV_WAR_0X00000002, WAR, 0x00000002, "Reserved flag WAR:0x00000002", DSE_UNDEFINED) \
    X(EVOLIS_RSV_WAR_0X00000001, WAR, 0x00000001, "Reserved flag WAR:0x00000001", DSE_UNDEFINED) \
    X(EVOLIS_RSV_ERR_0X80000000, ERR, 0x80000000, "Reserved flag ERR:0x80000000", DSE_UNDEFINED) \
    X(EVOLIS_RSV_ERR_0X40000000, ERR, 0x40000000, "Reserved flag ERR:0x40000000", DSE_UNDEFINED) \
    X(EVOLIS_RSV_ERR_0X00000040, ERR, 0x00000040, "Reserved flag ERR:0x00000040", DSE_UNDEFINED) \
    X(EVOLIS_RSV_ERR_0X00000020, ERR, 0x00000020, "Reserved flag ERR:0x00000020", DSE_UNDEFINED) \
    X(EVOLIS_RSV_ERR_0X00000010, ERR, 0x00000010, "Reserved flag ERR:0x00000010", DSE_UNDEFINED) \
    X(EVOLIS_RSV_ERR_0X00000008, ERR, 0x00000008, "Reserved flag ERR:0x00000008", DSE_UNDEFINED) \
    X(EVOLIS_RSV_ERR_0X00000004, ERR, 0x00000004, "Reserved flag ERR:0x00000004", DSE_UNDEFINED) \
    X(EVOLIS_RSV_ERR_0X00000002, ERR, 0x00000002, "Reserved flag ERR:0x00000002", DSE_UNDEFINED) \
    X(EVOLIS_RSV_ERR_0X00000001, ERR, 0x00000001, "Reserved flag ERR:0x00000001", DSE_UNDEFINED) \
    X(EVOLIS_RSV_EX3_0X10000000, EX3, 0x10000000, "Reserved flag EX3:0x10000000", DSE_UNDEFINED) \
    X(EVOLIS_RSV_EX3_0X00800000, EX3, 0x00800000, "Reserved flag EX3:0x00800000", DSE_UNDEFINED) \
    X(EVOLIS_RSV_EX3_0X00400000, EX3, 0x00400000, "Reserved flag EX3:0x00400000", DSE_UNDEFINED) \
    X(EVOLIS_RSV_EX3_0X00200000, EX3, 0x00200000, "Reserved flag EX3:0x00200000", DSE_UNDEFINED) \
    X(EVOLIS_RSV_EX3_0X00100000, EX3, 0x00100000, "Reserved flag EX3:0x00100000", DSE_UNDEFINED) \
    X(EVOLIS_RSV_EX3_0X00080000, EX3, 0x00080000, "Reserved flag EX3:0x00080000", DSE_UNDEFINED) \
    X(EVOLIS_RSV_EX3_0X00040000, EX3, 0x00040000, "Reserved flag EX3:0x00040000", DSE_UNDEFINED) \
    X(EVOLIS_RSV_EX3_0X00020000, EX3, 0x00020000, "Reserved flag EX3:0x00020000", DSE_UNDEFINED) \
    X(EVOLIS_RSV_EX3_0X00010000, EX3, 0x00010000, "Reserved flag EX3:0x00010000", DSE_UNDEFINED) \
    X(EVOLIS_RSV_EX3_0X00008000, EX3, 0x00008000, "Reserved flag EX3:0x00008000", DSE_UNDEFINED) \
    X(EVOLIS_RSV_EX3_0X00004000, EX3, 0x00004000, "Reserved flag EX3:0x00004000", DSE_UNDEFINED) \
    X(EVOLIS_RSV_EX3_0X00002000, EX3, 0x00002000, "Reserved flag EX3:0x00002000", DSE_UNDEFINED) \
    X(EVOLIS_RSV_EX3_0X00001000, EX3, 0x00001000, "Reserved flag EX3:0x00001000", DSE_UNDEFINED) \
    X(EVOLIS_RSV_EX3_0X00000800, EX3, 0x00000800, "Reserved flag EX3:0x00000800", DSE_UNDEFINED) \
    X(EVOLIS_RSV_EX3_0X00000400, EX3, 0x00000400, "Reserved flag EX3:0x00000400", DSE_UNDEFINED) \
    X(EVOLIS_RSV_EX3_0X00000200, EX3, 0x00000200, "Reserved flag EX3:0x00000200", DSE_UNDEFINED) \
    X(EVOLIS_RSV_EX3_0X00000100, EX3, 0x00000100, "Reserved flag EX3:0x00000100", DSE_UNDEFINED) \
    X(EVOLIS_RSV_EX3_0X00000001, EX3, 0x00000001, "Reserved flag EX3:0x00000001", DSE_UNDEFINED) \

#define EVOLIS_STATUS_EX_COUNT 4

/// Evolis status buffer.
typedef struct evolis_status_s {
    uint32_t config;
    uint32_t information;
    uint32_t warning;
    uint32_t error;
    uint32_t exts[EVOLIS_STATUS_EX_COUNT];
    uint16_t session;
} evolis_status_t;

/// Reads the status of the printer.
EVOLIS_WRA int evolis_status(_In_ evolis_t* printer, _Out_ evolis_status_t* status);

/// Enables the status fields in the printer's replies.
EVOLIS_WRA int evolis_status_enable(_In_ evolis_t* printer);

/// Send a command to get the status of the printer
EVOLIS_WRA int evolis_status_send_request(_In_ evolis_t* printer, _Out_ evolis_status_t* status);

/// Check if given flag is up or not.
EVOLIS_WRA bool evolis_status_is_on(_In_ const evolis_status_t* status, _In_ evolis_flag_t f);

/// Get current session id.
EVOLIS_LIB uint16_t evolis_status_get_sid(_In_ const evolis_status_t* status);

/// Serialize status struct as string.
EVOLIS_WRA size_t evolis_status_to_string(_In_ const evolis_status_t* status, _Out_ char* outStr, _In_ size_t outSize);

/// Deserialize string to the given status structure.
EVOLIS_LIB bool evolis_status_from_string(_In_ const char* s, _Out_ evolis_status_t* status);


#define EVOLIS_CFG_VALUES(X) \
    X(CFG_X01,                        0x80000000, "Raised for Primacy, KC200B, KC200, Issengo") \
    X(CFG_X02,                        0x40000000, "Raised for Zenius") \
    X(CFG_R02,                        0x20000000, "Raised for Agilia") \
    X(CFG_X04,                        0x10000000, "Raised for Elypso") \
    X(CFG_EXTENSION_1,                0x08000000, "Extension 1 is used") \
    X(CFG_S01,                        0x04000000, "Raised for Badgy, Apteo") \
    X(CFG_X07,                        0x02000000, "Not used") \
    X(CFG_KC200,                      0x01000000, "Raised for KC200B, KC200") \
    X(CFG_WIFI,                       0x00800000, "WiFi option is detected") \
    X(CFG_ETHERNET,                   0x00400000, "Ethernet option is detected") \
    X(CFG_USB_OVER_IP,                0x00200000, "USB over IP option is set") \
    X(CFG_FLIP,                       0x00100000, "Flip-over option is detected") \
    X(CFG_CONTACTLESS,                0x00080000, "Contactless option is detected") \
    X(CFG_SMART,                      0x00040000, "Smart option is detected") \
    X(CFG_MAGNETIC,                   0x00020000, "Magnetic option is detected") \
    X(CFG_REWRITE,                    0x00010000, "Rewrite mode is activated") \
    X(CFG_FEED_MANUALLY,              0x00008000, "Card feeding is configured as manual") \
    X(CFG_FEED_BY_CDE,                0x00004000, "Card feeding is set as manual once the feeding command is received") \
    X(CFG_FEED_BY_FEEDER,             0x00002000, "Card feeding is configured as feeder") \
    X(CFG_EJECT_REVERSE,              0x00001000, "Card ejection goes to manual feeder") \
    X(CFG_FEED_CDE_REVERSE,           0x00000800, "Card insertion is set to the rear of the printer") \
    X(CFG_EXTENDED_RESOLUTION,        0x00000400, "Extended resolution supported (600DPI, 1200DPI)") \
    X(CFG_LCD,                        0x00000200, "LCD option detected") \
    X(CFG_LOCK,                       0x00000100, "Locking system detected") \
    X(CFG_OEM,                        0x00000080, "Raised for rebranded products") \
    X(CFG_JIS_MAG_HEAD,               0x00000040, "JIS magnetic option detected") \
    X(CFG_REJECT_SLOT,                0x00000020, "Reject slot enabled") \
    X(CFG_IO_EXT,                     0x00000010, "IO extender detected") \
    X(CFG_MONO_ONLY,                  0x00000008, "Monochrome only printing authorized") \
    X(CFG_KC100,                      0x00000004, "Raised for KC100") \
    X(CFG_KINE,                       0x00000002, "Kineclipse option is available") \
    X(CFG_WIFI_ENA,                   0x00000001, "WiFi option is activated") \


#define EVOLIS_INF_VALUES(X) \
    X(INF_CLAIM,                      0x80000000, "Raised when EPS printing") \
    X(INF_CARD_HOPPER,                0x40000000, "Card present at the hopper") \
    X(INF_CARD_FEEDER,                0x20000000, "Card present in the feeder") \
    X(INF_CARD_FLIP,                  0x10000000, "Card present in the flip-over") \
    X(INF_CARD_CONTACTLESS,           0x08000000, "Card present in contactless card station") \
    X(INF_CARD_SMART,                 0x04000000, "Card present in smart card station") \
    X(INF_CARD_PRINT,                 0x02000000, "Card present in printing position") \
    X(INF_CARD_EJECT,                 0x01000000, "Card present in eject position") \
    X(INF_PRINTER_MASTER,             0x00800000, "Error management is set to 'printer'") \
    X(INF_PCSVC_LOCKED,               0x00400000, "The EPS is supervising the printer") \
    X(INF_SLEEP_MODE,                 0x00200000, "Printer is in sleep mode") \
    X(INF_UNKNOWN_RIBBON,             0x00100000, "Installed ribbon is unknown/unreadable") \
    X(INF_RIBBON_LOW,                 0x00080000, "Remaining ribbon is below low limit") \
    X(INF_CLEANING_MANDATORY,         0x00040000, "Cleaning is mandatory") \
    X(INF_CLEANING,                   0x00020000, "Cleaning is recommended") \
    X(INF_RESET,                      0x00010000, "Printer has just rebooted") \
    X(INF_CLEAN_OUTWARRANTY,          0x00008000, "Warranty lost, cleaning has not been done in time") \
    X(INF_CLEAN_LAST_OUTWARRANTY,     0x00004000, "Cleaning is mandatory, next card printed will lose the warranty") \
    X(INF_CLEAN_2ND_PASS,             0x00002000, "Cleaning sequence requires the second cleaning card") \
    X(INF_READY_FOR_CLEANING,         0x00001000, "Printer ready for cleaning (ribbon has been removed and cover closed)") \
    X(INF_CLEANING_ADVANCED,          0x00000800, "Advanced cleaning requested") \
    X(INF_WRONG_ZONE_RIBBON,          0x00000400, "Installed ribbon has not the right zone") \
    X(INF_RIBBON_CHANGED,             0x00000200, "Installed ribbon is different from the previous one") \
    X(INF_CLEANING_REQUIRED,          0x00000100, "Cleaning is required") \
    X(INF_PRINTING_RUNNING,           0x00000080, "Printing is in progress") \
    X(INF_ENCODING_RUNNING,           0x00000040, "Encoding is in progress (smart, contactless or magnetic)") \
    X(INF_CLEANING_RUNNING,           0x00000020, "Cleaning is in progress") \
    X(INF_WRONG_ZONE_ALERT,           0x00000010, "Installed ribbon has wrong zone, there are only a few prints remaining before printing is blocked") \
    X(INF_WRONG_ZONE_EXPIRED,         0x00000008, "Installed ribbon has wrong zone, printing is not allowed") \
    X(INF_SYNCH_PRINT_CENTER,         0x00000004, "Raised by EPS during a pop-up") \
    X(INF_UPDATING_FIRMWARE,          0x00000002, "Firmware is currently downloading") \
    X(INF_BUSY,                       0x00000001, "The printer is busy (printing, encoding)") \


#define EVOLIS_WAR_VALUES(X) \
    X(DEF_POWER_SUPPLY,               0x80000000, "Power supply voltage is too low") \
    X(DEF_REMOVE_RIBBON,              0x40000000, "Ribbon must be removed (in rewrite mode)") \
    X(RSV_DEF_0X20000000,             0x20000000, "Reserved flag WAR:0x20000000") \
    X(DEF_RECEPTACLE_OPEN,            0x10000000, "Not used") \
    X(DEF_REJECT_BOX_FULL,            0x08000000, "Reject box is full") \
    X(DEF_CARD_ON_EJECT,              0x04000000, "Card in eject position and has to be removed (in manual insertion mode)") \
    X(DEF_WAIT_CARD,                  0x02000000, "Printer is waiting for manual card insertion") \
    X(DEF_FEEDER_EMPTY,               0x01000000, "Feeder is empty") \
    X(RSV_DEF_0X00800000,             0x00800000, "Reserved flag WAR:0x00800000") \
    X(RSV_DEF_0X00400000,             0x00400000, "Reserved flag WAR:0x00400000") \
    X(DEF_COOLING,                    0x00200000, "Print head temperature too high: cooling down") \
    X(DEF_HOPPER_FULL,                0x00100000, "Printer hopper is full") \
    X(DEF_RIBBON_ENDED,               0x00080000, "Installed ribbon reached its end") \
    X(DEF_PRINTER_LOCKED,             0x00040000, "Printer is locked (used with locking system)") \
    X(DEF_COVER_OPEN,                 0x00020000, "Printer cover is opened") \
    X(DEF_NO_RIBBON,                  0x00010000, "No ribbon detected in the printer") \
    X(DEF_UNSUPPORTED_RIBBON,         0x00008000, "Installed ribbon is not supported by the printer") \
    X(RSV_DEF_0X00004000,             0x00004000, "Reserved flag WAR:0x00004000") \
    X(DEF_NO_CLEAR,                   0x00002000, "No clear ribbon installed") \
    X(DEF_CLEAR_END,                  0x00001000, "Clear ribbon reached its end") \
    X(DEF_CLEAR_UNSUPPORTED,          0x00000800, "Installed clear ribbon is not supported by the printer") \
    X(DEF_REJECT_BOX_COVER_OPEN,      0x00000400, "Reject box cover is open") \
    X(DEF_EPS_NO_AUTO,                0x00000200, "For tagless ribbons, indicates to the EPS to not automatically set the ribbon") \
    X(DEF_FEEDER_OPEN,                0x00000100, "Printer feeder is opened") \
    X(RSV_DEF_0X00000080,             0x00000080, "Reserved flag WAR:0x00000080") \
    X(RSV_DEF_0X00000040,             0x00000040, "Reserved flag WAR:0x00000040") \
    X(RSV_DEF_0X00000020,             0x00000020, "Reserved flag WAR:0x00000020") \
    X(RSV_DEF_0X00000010,             0x00000010, "Reserved flag WAR:0x00000010") \
    X(RSV_DEF_0X00000008,             0x00000008, "Reserved flag WAR:0x00000008") \
    X(RSV_DEF_0X00000004,             0x00000004, "Reserved flag WAR:0x00000004") \
    X(RSV_DEF_0X00000002,             0x00000002, "Reserved flag WAR:0x00000002") \
    X(RSV_DEF_0X00000001,             0x00000001, "Reserved flag WAR:0x00000001") \


#define EVOLIS_ERR_VALUES(X) \
    X(RSV_ERR_0X80000000,             0x80000000, "Reserved flag ERR:0x80000000") \
    X(RSV_ERR_0X40000000,             0x40000000, "Reserved flag ERR:0x40000000") \
    X(ERR_HEAD_TEMP,                  0x20000000, "Job interrupted because the print head temperature was too high") \
    X(ERR_NO_OPTION,                  0x10000000, "Requested option is not available") \
    X(ERR_FEEDER_ERROR,               0x08000000, "Error while feeding a card") \
    X(ERR_RIBBON_ERROR,               0x04000000, "Ribbon error during printing") \
    X(ERR_COVER_OPEN,                 0x02000000, "Job interrupted by an open cover") \
    X(ERR_MECHANICAL,                 0x01000000, "Mechanical error (card jam, ribbon jam, ...)") \
    X(ERR_REJECT_BOX_FULL,            0x00800000, "Card sent to reject box but it was full") \
    X(ERR_BAD_RIBBON,                 0x00400000, "Job interrupted because the installed ribbon is not the one expected") \
    X(ERR_RIBBON_ENDED,               0x00200000, "Job interrupted because the ribbon is finished") \
    X(ERR_HOPPER_FULL,                0x00100000, "Card sent to hopper but it was full") \
    X(ERR_BLANK_TRACK,                0x00080000, "No data on track after magnetic reading") \
    X(ERR_MAGNETIC_DATA,              0x00040000, "Magnetic data is not matching the settings") \
    X(ERR_READ_MAGNETIC,              0x00020000, "Corrupted/absent data on track after magnetic reading") \
    X(ERR_WRITE_MAGNETIC,             0x00010000, "Corrupted/absent data on track after magnetic encoding") \
    X(ERR_FEATURE,                    0x00008000, "Job sent is not supported by the printer") \
    X(ERR_RET_TEMPERATURE,            0x00004000, "Retransfer roller couldn't reach its operating temperature in time") \
    X(ERR_CLEAR_ERROR,                0x00002000, "Clear ribbon error during printing") \
    X(ERR_CLEAR_ENDED,                0x00001000, "Job interrupted because the clear ribbon is finished") \
    X(ERR_BAD_CLEAR,                  0x00000800, "Job interrupted because the installed clear ribbon is not the one expected") \
    X(ERR_REJECT_BOX_COVER_OPEN,      0x00000400, "Card sent to reject box but its cover was open") \
    X(ERR_CARD_ON_EJECT,              0x00000200, "Card in eject position was not removed in time (in manual insertion mode)") \
    X(ERR_NO_CARD_INSERTED,           0x00000100, "No card was presented in time (in manual insertion mode)") \
    X(ERR_FEEDER_OPEN,                0x00000080, "Job interrupted because the printer feeder is opened") \
    X(RSV_ERR_0X00000040,             0x00000040, "Reserved flag ERR:0x00000040") \
    X(RSV_ERR_0X00000020,             0x00000020, "Reserved flag ERR:0x00000020") \
    X(RSV_ERR_0X00000010,             0x00000010, "Reserved flag ERR:0x00000010") \
    X(RSV_ERR_0X00000008,             0x00000008, "Reserved flag ERR:0x00000008") \
    X(RSV_ERR_0X00000004,             0x00000004, "Reserved flag ERR:0x00000004") \
    X(RSV_ERR_0X00000002,             0x00000002, "Reserved flag ERR:0x00000002") \
    X(RSV_ERR_0X00000001,             0x00000001, "Reserved flag ERR:0x00000001") \


#define EVOLIS_EX1_VALUES(X) \
    X(CFG_EXTENSION_2,                0x80000000, "Extension 2 is used") \
    X(CFG_KIOSK,                      0x40000000, "Raised for KM500B, KM2000B") \
    X(CFG_QUANTUM,                    0x20000000, "Raised for Quantum") \
    X(CFG_SECURION,                   0x10000000, "Raised for Securion") \
    X(CFG_DUALYS,                     0x08000000, "Raised for Dualys") \
    X(CFG_PEBBLE,                     0x04000000, "Raised for Pebble") \
    X(CFG_SCANNER,                    0x02000000, "Scanner option is detected") \
    X(CFG_MEM_LAMINATION_MODULE_2,    0x01000000, "Printer has previously seen 2 lamination modules simultaneously") \
    X(INF_NO_LAMINATION_TO_DO,        0x00800000, "Lamination module is set to 'pass through' mode") \
    X(CFG_SEICO_FEEDER,               0x00400000, "Seico feeder configured") \
    X(CFG_KYTRONIC_FEEDER,            0x00200000, "Kytronics feeder configured") \
    X(CFG_HOPPER,                     0x00100000, "Not used") \
    X(CFG_LAMINATOR,                  0x00080000, "Lamination module detected") \
    X(INF_LAMI_ALLOW_TO_INSERT,       0x00040000, "Lamination module ready to insert card") \
    X(INF_LAMINATING_RUNNING,         0x00020000, "Lamination process is running") \
    X(INF_CLEAN_REMINDER,             0x00010000, "Reminder to clean the laminator") \
    X(INF_LAMI_TEMP_NOT_READY,        0x00008000, "Lamination roller is heating up, but its temperature is currently too low for the lamination process") \
    X(INF_SYNCHRONOUS_MODE,           0x00004000, "Lamination process is set to synchronous") \
    X(INF_LCD_BUT_ACK,                0x00002000, "LCD pop up button acknowledged") \
    X(INF_LCD_BUT_OK,                 0x00001000, "LCD pop up OK button pressed") \
    X(INF_LCD_BUT_RETRY,              0x00000800, "LCD pop up Retry button pressed") \
    X(INF_LCD_BUT_CANCEL,             0x00000400, "LCD pop up Cancel button pressed") \
    X(CFG_BEZEL,                      0x00000200, "Bezel option installed") \
    X(INF_FEEDER_NEAR_EMPTY,          0x00000100, "Feeder is near empty (low level sensor)") \
    X(INF_FEEDER1_EMPTY,              0x00000080, "Feeder 1 is empty for KM2000B") \
    X(INF_FEEDER2_EMPTY,              0x00000040, "Feeder 2 is empty for KM2000B") \
    X(INF_FEEDER3_EMPTY,              0x00000020, "Feeder 3 is empty for KM2000B") \
    X(INF_FEEDER4_EMPTY,              0x00000010, "Feeder 4 is empty for KM2000B") \
    X(INF_FEEDER1_NEAR_EMPTY,         0x00000008, "Feeder 1 is near empty for KM2000B") \
    X(INF_FEEDER2_NEAR_EMPTY,         0x00000004, "Feeder 2 is near empty for KM2000B") \
    X(INF_FEEDER3_NEAR_EMPTY,         0x00000002, "Feeder 3 is near empty for KM2000B") \
    X(INF_FEEDER4_NEAR_EMPTY,         0x00000001, "Feeder 4 is near empty for KM2000B") \

/// @deprecated Use `evolis_flag_t` instead.
typedef enum evolis_ex1_flag_e {
    EVOLIS_EX1_CFG_EXTENSION_2             = (int) 0x80000000, //!< Extension 2 is used
    EVOLIS_EX1_CFG_KIOSK                   = (int) 0x40000000, //!< Raised for KM500B, KM2000B
    EVOLIS_EX1_CFG_QUANTUM                 = (int) 0x20000000, //!< Raised for Quantum
    EVOLIS_EX1_CFG_SECURION                = (int) 0x10000000, //!< Raised for Securion
    EVOLIS_EX1_CFG_DUALYS                  = (int) 0x08000000, //!< Raised for Dualys
    EVOLIS_EX1_CFG_PEBBLE                  = (int) 0x04000000, //!< Raised for Pebble
    EVOLIS_EX1_CFG_SCANNER                 = (int) 0x02000000, //!< Scanner option is detected
    EVOLIS_EX1_CFG_MEM_LAMINATION_MODULE_2 = (int) 0x01000000, //!< Printer has previously seen 2 lamination modules simultaneously
    EVOLIS_EX1_INF_NO_LAMINATION_TO_DO     = (int) 0x00800000, //!< Lamination module is set to 'pass through' mode
    EVOLIS_EX1_CFG_SEICO_FEEDER            = (int) 0x00400000, //!< Seico feeder configured
    EVOLIS_EX1_CFG_KYTRONIC_FEEDER         = (int) 0x00200000, //!< Kytronics feeder configured
    EVOLIS_EX1_CFG_HOPPER                  = (int) 0x00100000, //!< Not used
    EVOLIS_EX1_CFG_LAMINATOR               = (int) 0x00080000, //!< Lamination module detected
    EVOLIS_EX1_INF_LAMI_ALLOW_TO_INSERT    = (int) 0x00040000, //!< Lamination module ready to insert card
    EVOLIS_EX1_INF_LAMINATING_RUNNING      = (int) 0x00020000, //!< Lamination process is running
    EVOLIS_EX1_INF_CLEAN_REMINDER          = (int) 0x00010000, //!< Reminder to clean the laminator
    EVOLIS_EX1_INF_LAMI_TEMP_NOT_READY     = (int) 0x00008000, //!< Lamination roller is heating up, but its temperature is currently too low for the lamination process
    EVOLIS_EX1_INF_SYNCHRONOUS_MODE        = (int) 0x00004000, //!< Lamination process is set to synchronous
    EVOLIS_EX1_INF_LCD_BUT_ACK             = (int) 0x00002000, //!< LCD pop up button acknowledged
    EVOLIS_EX1_INF_LCD_BUT_OK              = (int) 0x00001000, //!< LCD pop up OK button pressed
    EVOLIS_EX1_INF_LCD_BUT_RETRY           = (int) 0x00000800, //!< LCD pop up Retry button pressed
    EVOLIS_EX1_INF_LCD_BUT_CANCEL          = (int) 0x00000400, //!< LCD pop up Cancel button pressed
    EVOLIS_EX1_CFG_BEZEL                   = (int) 0x00000200, //!< Bezel option installed
    EVOLIS_EX1_INF_FEEDER_NEAR_EMPTY       = (int) 0x00000100, //!< Feeder is near empty (low level sensor)
    EVOLIS_EX1_INF_FEEDER1_EMPTY           = (int) 0x00000080, //!< Feeder 1 is empty for KM2000B
    EVOLIS_EX1_INF_FEEDER2_EMPTY           = (int) 0x00000040, //!< Feeder 2 is empty for KM2000B
    EVOLIS_EX1_INF_FEEDER3_EMPTY           = (int) 0x00000020, //!< Feeder 3 is empty for KM2000B
    EVOLIS_EX1_INF_FEEDER4_EMPTY           = (int) 0x00000010, //!< Feeder 4 is empty for KM2000B
    EVOLIS_EX1_INF_FEEDER1_NEAR_EMPTY      = (int) 0x00000008, //!< Feeder 1 is near empty for KM2000B
    EVOLIS_EX1_INF_FEEDER2_NEAR_EMPTY      = (int) 0x00000004, //!< Feeder 2 is near empty for KM2000B
    EVOLIS_EX1_INF_FEEDER3_NEAR_EMPTY      = (int) 0x00000002, //!< Feeder 3 is near empty for KM2000B
    EVOLIS_EX1_INF_FEEDER4_NEAR_EMPTY      = (int) 0x00000001, //!< Feeder 4 is near empty for KM2000B
} evolis_ex1_flag_t;

#define EVOLIS_EX2_VALUES(X) \
    X(CFG_EXTENSION_3,                0x80000000, "Extension 3 is used") \
    X(INF_SA_PROCESSING,              0x40000000, "Sensor adjustment is running") \
    X(INF_SCP_PROCESSING,             0x20000000, "Cleaning sequence is running") \
    X(INF_OPT_PROCESSING,             0x10000000, "Option activation is running (with activation key)") \
    X(INF_X08_PRINTER_UNLOCKED,       0x08000000, "Lock system currently unlocked") \
    X(INF_X08_FEEDER_OPEN,            0x04000000, "Feeder cover is open (used with locking system)") \
    X(INF_X08_EJECTBOX_FULL,          0x02000000, "Locking system feeder eject box full") \
    X(INF_X08_PRINT_UNLOCKED,         0x01000000, "Printing is currently unlocked, both mechanically and firmware-wise") \
    X(CFG_LAMINATION_MODULE_2,        0x00800000, "Second lamination module detected") \
    X(INF_LAMINATE_UNKNOWN,           0x00400000, "Installed laminate film is unknown/unreadable") \
    X(INF_LAMINATE_LOW,               0x00200000, "Laminate film is close to its end") \
    X(INF_LAMI_CARD,                  0x00100000, "Card present in the lamination module") \
    X(INF_LAMI_CLEANING_RUNNING,      0x00080000, "Lamination module cleaning process is running") \
    X(INF_LAMI_UPDATING_FIRMWARE,     0x00040000, "Lamination module firmware update is running") \
    X(INF_LAMI_READY_FOR_CLEANING,    0x00020000, "Lamination module ready for cleaning (no laminate film and cover closed)") \
    X(INF_CARD_REAR,                  0x00010000, "Card present at the rear of the printer") \
    X(DEF_NO_LAMINATE,                0x00008000, "No laminate film installed") \
    X(DEF_LAMI_COVER_OPEN,            0x00004000, "Lamination module cover is open") \
    X(DEF_LAMINATE_END,               0x00002000, "Laminate film reached its end") \
    X(DEF_LAMI_HOPPER_FULL,           0x00001000, "Lamination module hopper is full") \
    X(DEF_LAMINATE_UNSUPPORTED,       0x00000800, "Installed laminate film is not supported") \
    X(INF_CLEAR_UNKNOWN,              0x00000400, "Installed clear ribbon is unknown") \
    X(INF_CLEAR_LOW,                  0x00000200, "Remaining clear ribbon is below the low limit") \
    X(INF_WRONG_ZONE_CLEAR,           0x00000100, "Installed clear ribbon has not the right zone") \
    X(ERR_LAMI_TEMPERATURE,           0x00000080, "Job interrupted because the laminator temperature was too high") \
    X(ERR_LAMINATE,                   0x00000040, "Error on the laminate film") \
    X(ERR_LAMI_MECHANICAL,            0x00000020, "Mechanical error on the lamination module (card jam, ribbon jam, ...)") \
    X(ERR_LAMINATE_END,               0x00000010, "Job interrupted because the laminate film is finished") \
    X(ERR_LAMI_COVER_OPEN,            0x00000008, "Job interrupted by an open lamination module cover") \
    X(INF_CLEAR_CHANGED,              0x00000004, "Installed clear ribbon is different from the previous one") \
    X(INF_WRONG_ZONE_CLEAR_ALERT,     0x00000002, "Installed clear ribbon has wrong zone: only a few prints remaining before printing is blocked") \
    X(INF_WRONG_ZONE_CLEAR_EXPIRED,   0x00000001, "Installed clear ribbon has wrong zone: printing not allowed") \

/// @deprecated Use `evolis_flag_t` instead.
typedef enum evolis_ex2_flag_e {
    EVOLIS_EX2_CFG_EXTENSION_3             = (int) 0x80000000, //!< Extension 3 is used
    EVOLIS_EX2_INF_SA_PROCESSING           = (int) 0x40000000, //!< Sensor adjustment is running
    EVOLIS_EX2_INF_SCP_PROCESSING          = (int) 0x20000000, //!< Cleaning sequence is running
    EVOLIS_EX2_INF_OPT_PROCESSING          = (int) 0x10000000, //!< Option activation is running (with activation key)
    EVOLIS_EX2_INF_X08_PRINTER_UNLOCKED    = (int) 0x08000000, //!< Lock system currently unlocked
    EVOLIS_EX2_INF_X08_FEEDER_OPEN         = (int) 0x04000000, //!< Feeder cover is open (used with locking system)
    EVOLIS_EX2_INF_X08_EJECTBOX_FULL       = (int) 0x02000000, //!< Locking system feeder eject box full
    EVOLIS_EX2_INF_X08_PRINT_UNLOCKED      = (int) 0x01000000, //!< Printing is currently unlocked, both mechanically and firmware-wise
    EVOLIS_EX2_CFG_LAMINATION_MODULE_2     = (int) 0x00800000, //!< Second lamination module detected
    EVOLIS_EX2_INF_LAMINATE_UNKNOWN        = (int) 0x00400000, //!< Installed laminate film is unknown/unreadable
    EVOLIS_EX2_INF_LAMINATE_LOW            = (int) 0x00200000, //!< Laminate film is close to its end
    EVOLIS_EX2_INF_LAMI_CARD               = (int) 0x00100000, //!< Card present in the lamination module
    EVOLIS_EX2_INF_LAMI_CLEANING_RUNNING   = (int) 0x00080000, //!< Lamination module cleaning process is running
    EVOLIS_EX2_INF_LAMI_UPDATING_FIRMWARE  = (int) 0x00040000, //!< Lamination module firmware update is running
    EVOLIS_EX2_INF_LAMI_READY_FOR_CLEANING = (int) 0x00020000, //!< Lamination module ready for cleaning (no laminate film and cover closed)
    EVOLIS_EX2_INF_CARD_REAR               = (int) 0x00010000, //!< Card present at the rear of the printer
    EVOLIS_EX2_DEF_NO_LAMINATE             = (int) 0x00008000, //!< No laminate film installed
    EVOLIS_EX2_DEF_LAMI_COVER_OPEN         = (int) 0x00004000, //!< Lamination module cover is open
    EVOLIS_EX2_DEF_LAMINATE_END            = (int) 0x00002000, //!< Laminate film reached its end
    EVOLIS_EX2_DEF_LAMI_HOPPER_FULL        = (int) 0x00001000, //!< Lamination module hopper is full
    EVOLIS_EX2_DEF_LAMINATE_UNSUPPORTED    = (int) 0x00000800, //!< Installed laminate film is not supported
    EVOLIS_EX2_INF_CLEAR_UNKNOWN           = (int) 0x00000400, //!< Installed clear ribbon is unknown
    EVOLIS_EX2_INF_CLEAR_LOW               = (int) 0x00000200, //!< Remaining clear ribbon is below the low limit
    EVOLIS_EX2_INF_WRONG_ZONE_CLEAR        = (int) 0x00000100, //!< Installed clear ribbon has not the right zone
    EVOLIS_EX2_ERR_LAMI_TEMPERATURE        = (int) 0x00000080, //!< Job interrupted because the laminator temperature was too high
    EVOLIS_EX2_ERR_LAMINATE                = (int) 0x00000040, //!< Error on the laminate film
    EVOLIS_EX2_ERR_LAMI_MECHANICAL         = (int) 0x00000020, //!< Mechanical error on the lamination module (card jam, ribbon jam, ...)
    EVOLIS_EX2_ERR_LAMINATE_END            = (int) 0x00000010, //!< Job interrupted because the laminate film is finished
    EVOLIS_EX2_ERR_LAMI_COVER_OPEN         = (int) 0x00000008, //!< Job interrupted by an open lamination module cover
    EVOLIS_EX2_INF_CLEAR_CHANGED           = (int) 0x00000004, //!< Installed clear ribbon is different from the previous one
    EVOLIS_EX2_INF_WRONG_ZONE_CLEAR_ALERT  = (int) 0x00000002, //!< Installed clear ribbon has wrong zone: only a few prints remaining before printing is blocked
    EVOLIS_EX2_INF_WRONG_ZONE_CLEAR_EXPIRED = (int) 0x00000001, //!< Installed clear ribbon has wrong zone: printing not allowed
} evolis_ex2_flag_t;

#define EVOLIS_EX3_VALUES(X) \
    X(CFG_EXTENSION_4,                0x80000000, "Extension 4 is used") \
    X(INF_RETRANSFER_RUNNING,         0x40000000, "Retransfer sequence is running") \
    X(INF_HEATING,                    0x20000000, "Printer is heating up") \
    X(RSV_EX3_0X10000000,             0x10000000, "Reserved flag EX3:0x10000000") \
    X(INF_CARD_MAN_FEED,              0x08000000, "Card present in the manual feeding module") \
    X(INF_HEAT_ROLLER_WORN_OUT,       0x04000000, "Heat roller reached its maximum recommended of retransfers") \
    X(INF_PRE_HEATING_PRINT_HEAD,     0x02000000, "Print head pre heating in progress") \
    X(ERR_PRE_HEATING_PRINT_HEAD,     0x01000000, "Print head pre heating : target not reach under the timeout on the last cycle") \
    X(RSV_EX3_0X00800000,             0x00800000, "Reserved flag EX3:0x00800000") \
    X(RSV_EX3_0X00400000,             0x00400000, "Reserved flag EX3:0x00400000") \
    X(RSV_EX3_0X00200000,             0x00200000, "Reserved flag EX3:0x00200000") \
    X(RSV_EX3_0X00100000,             0x00100000, "Reserved flag EX3:0x00100000") \
    X(RSV_EX3_0X00080000,             0x00080000, "Reserved flag EX3:0x00080000") \
    X(RSV_EX3_0X00040000,             0x00040000, "Reserved flag EX3:0x00040000") \
    X(RSV_EX3_0X00020000,             0x00020000, "Reserved flag EX3:0x00020000") \
    X(RSV_EX3_0X00010000,             0x00010000, "Reserved flag EX3:0x00010000") \
    X(RSV_EX3_0X00008000,             0x00008000, "Reserved flag EX3:0x00008000") \
    X(RSV_EX3_0X00004000,             0x00004000, "Reserved flag EX3:0x00004000") \
    X(RSV_EX3_0X00002000,             0x00002000, "Reserved flag EX3:0x00002000") \
    X(RSV_EX3_0X00001000,             0x00001000, "Reserved flag EX3:0x00001000") \
    X(RSV_EX3_0X00000800,             0x00000800, "Reserved flag EX3:0x00000800") \
    X(RSV_EX3_0X00000400,             0x00000400, "Reserved flag EX3:0x00000400") \
    X(RSV_EX3_0X00000200,             0x00000200, "Reserved flag EX3:0x00000200") \
    X(RSV_EX3_0X00000100,             0x00000100, "Reserved flag EX3:0x00000100") \
    X(CFG_BRIDGE,                     0x00000080, "Configuration for bridge module") \
    X(INF_CARD_BRIDGE,                0x00000040, "The card is located in the bridge module") \
    X(CFG_INDENTING,                  0x00000020, "Configuration for indenting module") \
    X(INF_CARD_INDENTING,             0x00000010, "The card is located in the indenting module") \
    X(INF_BRIDGE_UPDATING_FIRMWARE,   0x00000008, "Bridge module firmware update is running") \
    X(DEF_REJECT_BOX_ALMOST_FULL,     0x00000004, "Reject box is almost full") \
    X(INF_CASSETTE_PRESENCE,          0x00000002, "Internal K7 is inserted into feeder") \
    X(RSV_EX3_0X00000001,             0x00000001, "Reserved flag EX3:0x00000001") \

/// @deprecated Use `evolis_flag_t` instead.
typedef enum evolis_ex3_flag_e {
    EVOLIS_EX3_CFG_EXTENSION_4             = (int) 0x80000000, //!< Extension 4 is used
    EVOLIS_EX3_INF_RETRANSFER_RUNNING      = (int) 0x40000000, //!< Retransfer sequence is running
    EVOLIS_EX3_INF_HEATING                 = (int) 0x20000000, //!< Printer is heating up
    EVOLIS_EX3_RSV_EX3_0X10000000          = (int) 0x10000000, //!< Reserved flag EX3:0x10000000
    EVOLIS_EX3_INF_CARD_MAN_FEED           = (int) 0x08000000, //!< Card present in the manual feeding module
    EVOLIS_EX3_INF_HEAT_ROLLER_WORN_OUT    = (int) 0x04000000, //!< Heat roller reached its maximum recommended of retransfers
    EVOLIS_EX3_INF_PRE_HEATING_PRINT_HEAD  = (int) 0x02000000, //!< Print head pre heating in progress
    EVOLIS_EX3_ERR_PRE_HEATING_PRINT_HEAD  = (int) 0x01000000, //!< Print head pre heating : target not reach under the timeout on the last cycle
    EVOLIS_EX3_RSV_EX3_0X00800000          = (int) 0x00800000, //!< Reserved flag EX3:0x00800000
    EVOLIS_EX3_RSV_EX3_0X00400000          = (int) 0x00400000, //!< Reserved flag EX3:0x00400000
    EVOLIS_EX3_RSV_EX3_0X00200000          = (int) 0x00200000, //!< Reserved flag EX3:0x00200000
    EVOLIS_EX3_RSV_EX3_0X00100000          = (int) 0x00100000, //!< Reserved flag EX3:0x00100000
    EVOLIS_EX3_RSV_EX3_0X00080000          = (int) 0x00080000, //!< Reserved flag EX3:0x00080000
    EVOLIS_EX3_RSV_EX3_0X00040000          = (int) 0x00040000, //!< Reserved flag EX3:0x00040000
    EVOLIS_EX3_RSV_EX3_0X00020000          = (int) 0x00020000, //!< Reserved flag EX3:0x00020000
    EVOLIS_EX3_RSV_EX3_0X00010000          = (int) 0x00010000, //!< Reserved flag EX3:0x00010000
    EVOLIS_EX3_RSV_EX3_0X00008000          = (int) 0x00008000, //!< Reserved flag EX3:0x00008000
    EVOLIS_EX3_RSV_EX3_0X00004000          = (int) 0x00004000, //!< Reserved flag EX3:0x00004000
    EVOLIS_EX3_RSV_EX3_0X00002000          = (int) 0x00002000, //!< Reserved flag EX3:0x00002000
    EVOLIS_EX3_RSV_EX3_0X00001000          = (int) 0x00001000, //!< Reserved flag EX3:0x00001000
    EVOLIS_EX3_RSV_EX3_0X00000800          = (int) 0x00000800, //!< Reserved flag EX3:0x00000800
    EVOLIS_EX3_RSV_EX3_0X00000400          = (int) 0x00000400, //!< Reserved flag EX3:0x00000400
    EVOLIS_EX3_RSV_EX3_0X00000200          = (int) 0x00000200, //!< Reserved flag EX3:0x00000200
    EVOLIS_EX3_RSV_EX3_0X00000100          = (int) 0x00000100, //!< Reserved flag EX3:0x00000100
    EVOLIS_EX3_CFG_BRIDGE                  = (int) 0x00000080, //!< Configuration for bridge module
    EVOLIS_EX3_INF_CARD_BRIDGE             = (int) 0x00000040, //!< The card is located in the bridge module
    EVOLIS_EX3_CFG_INDENTING               = (int) 0x00000020, //!< Configuration for indenting module
    EVOLIS_EX3_INF_CARD_INDENTING          = (int) 0x00000010, //!< The card is located in the indenting module
    EVOLIS_EX3_INF_BRIDGE_UPDATING_FIRMWARE = (int) 0x00000008, //!< Bridge module firmware update is running
    EVOLIS_EX3_DEF_REJECT_BOX_ALMOST_FULL  = (int) 0x00000004, //!< Reject box is almost full
    EVOLIS_EX3_INF_CASSETTE_PRESENCE       = (int) 0x00000002, //!< Internal K7 is inserted into feeder
    EVOLIS_EX3_RSV_EX3_0X00000001          = (int) 0x00000001, //!< Reserved flag EX3:0x00000001
} evolis_ex3_flag_t;

/// Check if config flag is on.
/// @deprecated Use `evolis_status_is_on()` instead.
EVOLIS_DEPRECATED
EVOLIS_WRA bool evolis_status_is_on_cfg(_In_ const evolis_status_t* status, _In_ evolis_flag_t f);

/// Check if information flag is on.
/// @deprecated Use `evolis_status_is_on()` instead.
EVOLIS_DEPRECATED
EVOLIS_WRA bool evolis_status_is_on_inf(_In_ const evolis_status_t* status, _In_ evolis_flag_t f);

/// Check if warning flag is on.
/// @deprecated Use `evolis_status_is_on()` instead.
EVOLIS_DEPRECATED
EVOLIS_WRA bool evolis_status_is_on_war(_In_ const evolis_status_t* status, _In_ evolis_flag_t f);

/// Check if error flag is on.
/// @deprecated Use `evolis_status_is_on()` instead.
EVOLIS_DEPRECATED
EVOLIS_WRA bool evolis_status_is_on_err(_In_ const evolis_status_t* status, _In_ evolis_flag_t f);

/// Check if extension 1 flag is on.
/// @deprecated Use `evolis_status_is_on()` instead.
EVOLIS_DEPRECATED
EVOLIS_WRA bool evolis_status_is_on_ex1(_In_ const evolis_status_t* status, _In_ evolis_ex1_flag_t f);

/// Check if extension 2 flag is on.
/// @deprecated Use `evolis_status_is_on()` instead.
EVOLIS_DEPRECATED
EVOLIS_WRA bool evolis_status_is_on_ex2(_In_ const evolis_status_t* status, _In_ evolis_ex2_flag_t f);

/// Check if extension 3 flag is on.
/// @deprecated Use `evolis_status_is_on()` instead.
EVOLIS_DEPRECATED
EVOLIS_WRA bool evolis_status_is_on_ex3(_In_ const evolis_status_t* status, _In_ evolis_ex3_flag_t f);

