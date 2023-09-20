/**
 * Evolis C library
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
 * ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
 * PARTICULAR PURPOSE.
 */
#pragma once

#define X(NAME, VALUE, DESCRIPTION) EVOLIS_##NAME = VALUE,

#define EVOLIS_CFG_VALUES(X) \
    X(CFG_X01,                       0x80000000, "Raised for Primacy, KC200B, KC200, Issengo") \
    X(CFG_X02,                       0x40000000, "Raised for Zenius") \
    X(CFG_R02,                       0x20000000, "Raised for Agilia") \
    X(CFG_X04,                       0x10000000, "Raised for Elypso") \
    X(CFG_EXTENSION_1,               0x08000000, "Extension 1 is used") \
    X(CFG_S01,                       0x04000000, "Raised for Badgy, Apteo") \
    X(CFG_X07,                       0x02000000, "Not used") \
    X(CFG_KC200,                     0x01000000, "Raised for KC200B, KC200") \
    X(CFG_WIFI,                      0x00800000, "WiFi option is detected") \
    X(CFG_ETHERNET,                  0x00400000, "Ethernet option is detected") \
    X(CFG_USB_OVER_IP,               0x00200000, "USB over IP option is set") \
    X(CFG_FLIP,                      0x00100000, "Flip-over option is detected") \
    X(CFG_CONTACTLESS,               0x00080000, "Contactless option is detected") \
    X(CFG_SMART,                     0x00040000, "Smart option is detected") \
    X(CFG_MAGNETIC,                  0x00020000, "Magnetic option is detected") \
    X(CFG_REWRITE,                   0x00010000, "Rewrite mode is activated") \
    X(CFG_FEED_MANUALLY,             0x00008000, "Card feeding is configured as manual") \
    X(CFG_FEED_BY_CDE,               0x00004000, "Card feeding is set as manual once the feeding command is received") \
    X(CFG_FEED_BY_FEEDER,            0x00002000, "Card feeding is configured as feeder") \
    X(CFG_EJECT_REVERSE,             0x00001000, "Card ejection goes to manual feeder") \
    X(CFG_FEED_CDE_REVERSE,          0x00000800, "Card insertion is set to the rear of the printer") \
    X(CFG_EXTENDED_RESOLUTION,       0x00000400, "Extended resolution supported (600DPI, 1200DPI)") \
    X(CFG_LCD,                       0x00000200, "LCD option detected") \
    X(CFG_LOCK,                      0x00000100, "Locking system detected") \
    X(CFG_OEM,                       0x00000080, "Raised for rebranded products") \
    X(CFG_JIS_MAG_HEAD,              0x00000040, "JIS magnetic option detected") \
    X(CFG_REJECT_SLOT,               0x00000020, "Reject slot enabled") \
    X(CFG_IO_EXT,                    0x00000010, "IO extender detected") \
    X(CFG_MONO_ONLY,                 0x00000008, "Monochrome only printing authorized") \
    X(CFG_KC100,                     0x00000004, "Raised for KC100") \
    X(CFG_KINE,                      0x00000002, "Kineclipse option is available") \
    X(CFG_WIFI_ENA,                  0x00000001, "WiFi option is activated") \

typedef enum evolis_cfg_flag_e {
    EVOLIS_CFG_X01                         = 0x80000000, //!< Raised for Primacy, KC200B, KC200, Issengo
    EVOLIS_CFG_X02                         = 0x40000000, //!< Raised for Zenius
    EVOLIS_CFG_R02                         = 0x20000000, //!< Raised for Agilia
    EVOLIS_CFG_X04                         = 0x10000000, //!< Raised for Elypso
    EVOLIS_CFG_EXTENSION_1                 = 0x08000000, //!< Extension 1 is used
    EVOLIS_CFG_S01                         = 0x04000000, //!< Raised for Badgy, Apteo
    EVOLIS_CFG_X07                         = 0x02000000, //!< Not used
    EVOLIS_CFG_KC200                       = 0x01000000, //!< Raised for KC200B, KC200
    EVOLIS_CFG_WIFI                        = 0x00800000, //!< WiFi option is detected
    EVOLIS_CFG_ETHERNET                    = 0x00400000, //!< Ethernet option is detected
    EVOLIS_CFG_USB_OVER_IP                 = 0x00200000, //!< USB over IP option is set
    EVOLIS_CFG_FLIP                        = 0x00100000, //!< Flip-over option is detected
    EVOLIS_CFG_CONTACTLESS                 = 0x00080000, //!< Contactless option is detected
    EVOLIS_CFG_SMART                       = 0x00040000, //!< Smart option is detected
    EVOLIS_CFG_MAGNETIC                    = 0x00020000, //!< Magnetic option is detected
    EVOLIS_CFG_REWRITE                     = 0x00010000, //!< Rewrite mode is activated
    EVOLIS_CFG_FEED_MANUALLY               = 0x00008000, //!< Card feeding is configured as manual
    EVOLIS_CFG_FEED_BY_CDE                 = 0x00004000, //!< Card feeding is set as manual once the feeding command is received
    EVOLIS_CFG_FEED_BY_FEEDER              = 0x00002000, //!< Card feeding is configured as feeder
    EVOLIS_CFG_EJECT_REVERSE               = 0x00001000, //!< Card ejection goes to manual feeder
    EVOLIS_CFG_FEED_CDE_REVERSE            = 0x00000800, //!< Card insertion is set to the rear of the printer
    EVOLIS_CFG_EXTENDED_RESOLUTION         = 0x00000400, //!< Extended resolution supported (600DPI, 1200DPI)
    EVOLIS_CFG_LCD                         = 0x00000200, //!< LCD option detected
    EVOLIS_CFG_LOCK                        = 0x00000100, //!< Locking system detected
    EVOLIS_CFG_OEM                         = 0x00000080, //!< Raised for rebranded products
    EVOLIS_CFG_JIS_MAG_HEAD                = 0x00000040, //!< JIS magnetic option detected
    EVOLIS_CFG_REJECT_SLOT                 = 0x00000020, //!< Reject slot enabled
    EVOLIS_CFG_IO_EXT                      = 0x00000010, //!< IO extender detected
    EVOLIS_CFG_MONO_ONLY                   = 0x00000008, //!< Monochrome only printing authorized
    EVOLIS_CFG_KC100                       = 0x00000004, //!< Raised for KC100
    EVOLIS_CFG_KINE                        = 0x00000002, //!< Kineclipse option is available
    EVOLIS_CFG_WIFI_ENA                    = 0x00000001, //!< WiFi option is activated
} evolis_cfg_flag_t;

#define EVOLIS_INF_VALUES(X) \
    X(INF_CLAIM,                     0x80000000, "Raised when EPS printing") \
    X(INF_CARD_HOPPER,               0x40000000, "Card present at the hopper") \
    X(INF_CARD_FEEDER,               0x20000000, "Card present in the feeder") \
    X(INF_CARD_FLIP,                 0x10000000, "Card present in the flip-over") \
    X(INF_CARD_CONTACTLESS,          0x08000000, "Card present in contactless card station") \
    X(INF_CARD_SMART,                0x04000000, "Card present in smart card station") \
    X(INF_CARD_PRINT,                0x02000000, "Card present in printing position") \
    X(INF_CARD_EJECT,                0x01000000, "Card present in eject position") \
    X(INF_PRINTER_MASTER,            0x00800000, "Error management is set to 'printer'") \
    X(INF_PCSVC_LOCKED,              0x00400000, "The EPS is supervising the printer") \
    X(INF_SLEEP_MODE,                0x00200000, "Printer is in sleep mode") \
    X(INF_UNKNOWN_RIBBON,            0x00100000, "Installed ribbon is unknown/unreadable") \
    X(INF_RIBBON_LOW,                0x00080000, "Remaining ribbon is below low limit") \
    X(INF_CLEANING_MANDATORY,        0x00040000, "Cleaning is mandatory") \
    X(INF_CLEANING,                  0x00020000, "Cleaning is recommended") \
    X(INF_RESET,                     0x00010000, "Printer has just rebooted") \
    X(INF_CLEAN_OUTWARRANTY,         0x00008000, "Warranty lost, cleaning has not been done in time") \
    X(INF_CLEAN_LAST_OUTWARRANTY,    0x00004000, "Cleaning is mandatory, next card printed will lose the warranty") \
    X(INF_CLEAN_2ND_PASS,            0x00002000, "Cleaning sequence requires the second cleaning card") \
    X(INF_READY_FOR_CLEANING,        0x00001000, "Printer ready for cleaning (ribbon has been removed and cover closed)") \
    X(INF_CLEANING_ADVANCED,         0x00000800, "Advanced cleaning requested") \
    X(INF_WRONG_ZONE_RIBBON,         0x00000400, "Installed ribbon has not the right zone") \
    X(INF_RIBBON_CHANGED,            0x00000200, "Installed ribbon is different from the previous one") \
    X(INF_CLEANING_REQUIRED,         0x00000100, "Cleaning is required") \
    X(INF_PRINTING_RUNNING,          0x00000080, "Printing is in progress") \
    X(INF_ENCODING_RUNNING,          0x00000040, "Encoding is in progress (smart, contactless or magnetic)") \
    X(INF_CLEANING_RUNNING,          0x00000020, "Cleaning is in progress") \
    X(INF_WRONG_ZONE_ALERT,          0x00000010, "Installed ribbon has wrong zone, there are only a few prints remaining before printing is blocked") \
    X(INF_WRONG_ZONE_EXPIRED,        0x00000008, "Installed ribbon has wrong zone, printing is not allowed") \
    X(INF_SYNCH_PRINT_CENTER,        0x00000004, "Raised by EPS during a pop-up") \
    X(INF_UPDATING_FIRMWARE,         0x00000002, "Firmware is currently downloading") \
    X(INF_BUSY,                      0x00000001, "The printer is busy (printing, encoding)") \

typedef enum evolis_inf_flag_e {
    EVOLIS_INF_CLAIM                       = 0x80000000, //!< Raised when EPS printing
    EVOLIS_INF_CARD_HOPPER                 = 0x40000000, //!< Card present at the hopper
    EVOLIS_INF_CARD_FEEDER                 = 0x20000000, //!< Card present in the feeder
    EVOLIS_INF_CARD_FLIP                   = 0x10000000, //!< Card present in the flip-over
    EVOLIS_INF_CARD_CONTACTLESS            = 0x08000000, //!< Card present in contactless card station
    EVOLIS_INF_CARD_SMART                  = 0x04000000, //!< Card present in smart card station
    EVOLIS_INF_CARD_PRINT                  = 0x02000000, //!< Card present in printing position
    EVOLIS_INF_CARD_EJECT                  = 0x01000000, //!< Card present in eject position
    EVOLIS_INF_PRINTER_MASTER              = 0x00800000, //!< Error management is set to 'printer'
    EVOLIS_INF_PCSVC_LOCKED                = 0x00400000, //!< The EPS is supervising the printer
    EVOLIS_INF_SLEEP_MODE                  = 0x00200000, //!< Printer is in sleep mode
    EVOLIS_INF_UNKNOWN_RIBBON              = 0x00100000, //!< Installed ribbon is unknown/unreadable
    EVOLIS_INF_RIBBON_LOW                  = 0x00080000, //!< Remaining ribbon is below low limit
    EVOLIS_INF_CLEANING_MANDATORY          = 0x00040000, //!< Cleaning is mandatory
    EVOLIS_INF_CLEANING                    = 0x00020000, //!< Cleaning is recommended
    EVOLIS_INF_RESET                       = 0x00010000, //!< Printer has just rebooted
    EVOLIS_INF_CLEAN_OUTWARRANTY           = 0x00008000, //!< Warranty lost, cleaning has not been done in time
    EVOLIS_INF_CLEAN_LAST_OUTWARRANTY      = 0x00004000, //!< Cleaning is mandatory, next card printed will lose the warranty
    EVOLIS_INF_CLEAN_2ND_PASS              = 0x00002000, //!< Cleaning sequence requires the second cleaning card
    EVOLIS_INF_READY_FOR_CLEANING          = 0x00001000, //!< Printer ready for cleaning (ribbon has been removed and cover closed)
    EVOLIS_INF_CLEANING_ADVANCED           = 0x00000800, //!< Advanced cleaning requested
    EVOLIS_INF_WRONG_ZONE_RIBBON           = 0x00000400, //!< Installed ribbon has not the right zone
    EVOLIS_INF_RIBBON_CHANGED              = 0x00000200, //!< Installed ribbon is different from the previous one
    EVOLIS_INF_CLEANING_REQUIRED           = 0x00000100, //!< Cleaning is required
    EVOLIS_INF_PRINTING_RUNNING            = 0x00000080, //!< Printing is in progress
    EVOLIS_INF_ENCODING_RUNNING            = 0x00000040, //!< Encoding is in progress (smart, contactless or magnetic)
    EVOLIS_INF_CLEANING_RUNNING            = 0x00000020, //!< Cleaning is in progress
    EVOLIS_INF_WRONG_ZONE_ALERT            = 0x00000010, //!< Installed ribbon has wrong zone, there are only a few prints remaining before printing is blocked
    EVOLIS_INF_WRONG_ZONE_EXPIRED          = 0x00000008, //!< Installed ribbon has wrong zone, printing is not allowed
    EVOLIS_INF_SYNCH_PRINT_CENTER          = 0x00000004, //!< Raised by EPS during a pop-up
    EVOLIS_INF_UPDATING_FIRMWARE           = 0x00000002, //!< Firmware is currently downloading
    EVOLIS_INF_BUSY                        = 0x00000001, //!< The printer is busy (printing, encoding)
} evolis_inf_flag_t;

#define EVOLIS_WAR_VALUES(X) \
    X(WAR_POWER_SUPPLY,              0x80000000, "Power supply voltage is too low") \
    X(WAR_REMOVE_RIBBON,             0x40000000, "Ribbon must be removed (in rewrite mode)") \
    X(WAR_RECEPTACLE_OPEN,           0x10000000, "Not used") \
    X(WAR_REJECT_BOX_FULL,           0x08000000, "Reject box is full") \
    X(WAR_CARD_ON_EJECT,             0x04000000, "Card in eject position and has to be removed (in manual insertion mode)") \
    X(WAR_WAIT_CARD,                 0x02000000, "Printer is waiting for manual card insertion") \
    X(WAR_FEEDER_EMPTY,              0x01000000, "Feeder is empty") \
    X(WAR_COOLING,                   0x00200000, "Print head temperature too high: cooling down") \
    X(WAR_HOPPER_FULL,               0x00100000, "Printer hopper is full") \
    X(WAR_RIBBON_ENDED,              0x00080000, "Installed ribbon reached its end") \
    X(WAR_PRINTER_LOCKED,            0x00040000, "Printer is locked (used with locking system)") \
    X(WAR_COVER_OPEN,                0x00020000, "Printer cover is opened") \
    X(WAR_NO_RIBBON,                 0x00010000, "No ribbon detected in the printer") \
    X(WAR_UNSUPPORTED_RIBBON,        0x00008000, "Installed ribbon is not supported by the printer") \
    X(WAR_NO_CLEAR,                  0x00002000, "No clear ribbon installed") \
    X(WAR_CLEAR_END,                 0x00001000, "Clear ribbon reached its end") \
    X(WAR_CLEAR_UNSUPPORTED,         0x00000800, "Installed clear ribbon is not supported by the printer") \
    X(WAR_REJECT_BOX_COVER_OPEN,     0x00000400, "Reject box cover is open") \
    X(WAR_EPS_NO_AUTO,               0x00000200, "For tagless ribbons, indicates to the EPS to not automatically set the ribbon") \
    X(WAR_FEEDER_OPEN,               0x00000100, "Printer feeder is opened") \

typedef enum evolis_war_flag_e {
    EVOLIS_WAR_POWER_SUPPLY                = 0x80000000, //!< Power supply voltage is too low
    EVOLIS_WAR_REMOVE_RIBBON               = 0x40000000, //!< Ribbon must be removed (in rewrite mode)
    EVOLIS_WAR_RECEPTACLE_OPEN             = 0x10000000, //!< Not used
    EVOLIS_WAR_REJECT_BOX_FULL             = 0x08000000, //!< Reject box is full
    EVOLIS_WAR_CARD_ON_EJECT               = 0x04000000, //!< Card in eject position and has to be removed (in manual insertion mode)
    EVOLIS_WAR_WAIT_CARD                   = 0x02000000, //!< Printer is waiting for manual card insertion
    EVOLIS_WAR_FEEDER_EMPTY                = 0x01000000, //!< Feeder is empty
    EVOLIS_WAR_COOLING                     = 0x00200000, //!< Print head temperature too high: cooling down
    EVOLIS_WAR_HOPPER_FULL                 = 0x00100000, //!< Printer hopper is full
    EVOLIS_WAR_RIBBON_ENDED                = 0x00080000, //!< Installed ribbon reached its end
    EVOLIS_WAR_PRINTER_LOCKED              = 0x00040000, //!< Printer is locked (used with locking system)
    EVOLIS_WAR_COVER_OPEN                  = 0x00020000, //!< Printer cover is opened
    EVOLIS_WAR_NO_RIBBON                   = 0x00010000, //!< No ribbon detected in the printer
    EVOLIS_WAR_UNSUPPORTED_RIBBON          = 0x00008000, //!< Installed ribbon is not supported by the printer
    EVOLIS_WAR_NO_CLEAR                    = 0x00002000, //!< No clear ribbon installed
    EVOLIS_WAR_CLEAR_END                   = 0x00001000, //!< Clear ribbon reached its end
    EVOLIS_WAR_CLEAR_UNSUPPORTED           = 0x00000800, //!< Installed clear ribbon is not supported by the printer
    EVOLIS_WAR_REJECT_BOX_COVER_OPEN       = 0x00000400, //!< Reject box cover is open
    EVOLIS_WAR_EPS_NO_AUTO                 = 0x00000200, //!< For tagless ribbons, indicates to the EPS to not automatically set the ribbon
    EVOLIS_WAR_FEEDER_OPEN                 = 0x00000100, //!< Printer feeder is opened
} evolis_war_flag_t;

#define EVOLIS_ERR_VALUES(X) \
    X(ERR_HEAD_TEMP,                 0x20000000, "Job interrupted because the print head temperature was too high") \
    X(ERR_NO_OPTION,                 0x10000000, "Requested option is not available") \
    X(ERR_FEEDER_ERROR,              0x08000000, "Error while feeding a card") \
    X(ERR_RIBBON_ERROR,              0x04000000, "Ribbon error during printing") \
    X(ERR_COVER_OPEN,                0x02000000, "Job interrupted by an open cover") \
    X(ERR_MECHANICAL,                0x01000000, "Mechanical error (card jam, ribbon jam, ...)") \
    X(ERR_REJECT_BOX_FULL,           0x00800000, "Card sent to reject box but it was full") \
    X(ERR_BAD_RIBBON,                0x00400000, "Job interrupted because the installed ribbon is not the one expected") \
    X(ERR_RIBBON_ENDED,              0x00200000, "Job interrupted because the ribbon is finished") \
    X(ERR_HOPPER_FULL,               0x00100000, "Card sent to hopper but it was full") \
    X(ERR_BLANK_TRACK,               0x00080000, "No data on track after magnetic reading") \
    X(ERR_MAGNETIC_DATA,             0x00040000, "Magnetic data is not matching the settings") \
    X(ERR_READ_MAGNETIC,             0x00020000, "Corrupted/absent data on track after magnetic reading") \
    X(ERR_WRITE_MAGNETIC,            0x00010000, "Corrupted/absent data on track after magnetic encoding") \
    X(ERR_FEATURE,                   0x00008000, "Job sent is not supported by the printer") \
    X(ERR_RET_TEMPERATURE,           0x00004000, "Retransfer roller couldn't reach its operating temperature in time") \
    X(ERR_CLEAR_ERROR,               0x00002000, "Clear ribbon error during printing") \
    X(ERR_CLEAR_ENDED,               0x00001000, "Job interrupted because the clear ribbon is finished") \
    X(ERR_BAD_CLEAR,                 0x00000800, "Job interrupted because the installed clear ribbon is not the one expected") \
    X(ERR_REJECT_BOX_COVER_OPEN,     0x00000400, "Card sent to reject box but its cover was open") \
    X(ERR_CARD_ON_EJECT,             0x00000200, "Card in eject position was not removed in time (in manual insertion mode)") \
    X(ERR_NO_CARD_INSERTED,          0x00000100, "No card was presented in time (in manual insertion mode)") \
    X(ERR_FEEDER_OPEN,               0x00000080, "Job interrupted because the printer feeder is opened") \

typedef enum evolis_err_flag_e {
    EVOLIS_ERR_HEAD_TEMP                   = 0x20000000, //!< Job interrupted because the print head temperature was too high
    EVOLIS_ERR_NO_OPTION                   = 0x10000000, //!< Requested option is not available
    EVOLIS_ERR_FEEDER_ERROR                = 0x08000000, //!< Error while feeding a card
    EVOLIS_ERR_RIBBON_ERROR                = 0x04000000, //!< Ribbon error during printing
    EVOLIS_ERR_COVER_OPEN                  = 0x02000000, //!< Job interrupted by an open cover
    EVOLIS_ERR_MECHANICAL                  = 0x01000000, //!< Mechanical error (card jam, ribbon jam, ...)
    EVOLIS_ERR_REJECT_BOX_FULL             = 0x00800000, //!< Card sent to reject box but it was full
    EVOLIS_ERR_BAD_RIBBON                  = 0x00400000, //!< Job interrupted because the installed ribbon is not the one expected
    EVOLIS_ERR_RIBBON_ENDED                = 0x00200000, //!< Job interrupted because the ribbon is finished
    EVOLIS_ERR_HOPPER_FULL                 = 0x00100000, //!< Card sent to hopper but it was full
    EVOLIS_ERR_BLANK_TRACK                 = 0x00080000, //!< No data on track after magnetic reading
    EVOLIS_ERR_MAGNETIC_DATA               = 0x00040000, //!< Magnetic data is not matching the settings
    EVOLIS_ERR_READ_MAGNETIC               = 0x00020000, //!< Corrupted/absent data on track after magnetic reading
    EVOLIS_ERR_WRITE_MAGNETIC              = 0x00010000, //!< Corrupted/absent data on track after magnetic encoding
    EVOLIS_ERR_FEATURE                     = 0x00008000, //!< Job sent is not supported by the printer
    EVOLIS_ERR_RET_TEMPERATURE             = 0x00004000, //!< Retransfer roller couldn't reach its operating temperature in time
    EVOLIS_ERR_CLEAR_ERROR                 = 0x00002000, //!< Clear ribbon error during printing
    EVOLIS_ERR_CLEAR_ENDED                 = 0x00001000, //!< Job interrupted because the clear ribbon is finished
    EVOLIS_ERR_BAD_CLEAR                   = 0x00000800, //!< Job interrupted because the installed clear ribbon is not the one expected
    EVOLIS_ERR_REJECT_BOX_COVER_OPEN       = 0x00000400, //!< Card sent to reject box but its cover was open
    EVOLIS_ERR_CARD_ON_EJECT               = 0x00000200, //!< Card in eject position was not removed in time (in manual insertion mode)
    EVOLIS_ERR_NO_CARD_INSERTED            = 0x00000100, //!< No card was presented in time (in manual insertion mode)
    EVOLIS_ERR_FEEDER_OPEN                 = 0x00000080, //!< Job interrupted because the printer feeder is opened
} evolis_err_flag_t;

#define EVOLIS_EX1_VALUES(X) \
    X(EX1_CFG_EXTENSION_2,           0x80000000, "Extension 2 is used") \
    X(EX1_CFG_KIOSK,                 0x40000000, "Raised for KM500B, KM2000B") \
    X(EX1_CFG_QUANTUM,               0x20000000, "Raised for Quantum") \
    X(EX1_CFG_SECURION,              0x10000000, "Raised for Securion") \
    X(EX1_CFG_DUALYS,                0x08000000, "Raised for Dualys") \
    X(EX1_CFG_PEBBLE,                0x04000000, "Raised for Pebble") \
    X(EX1_CFG_SCANNER,               0x02000000, "Scanner option is detected") \
    X(EX1_CFG_MEM_LAMINATION_MODULE_2, 0x01000000, "Printer has previously seen 2 lamination modules simultaneously") \
    X(EX1_INF_NO_LAMINATION_TO_DO,   0x00800000, "Lamination module is set to 'pass through' mode") \
    X(EX1_CFG_SEICO_FEEDER,          0x00400000, "Seico feeder configured") \
    X(EX1_CFG_KYTRONIC_FEEDER,       0x00200000, "Kytronics feeder configured") \
    X(EX1_CFG_HOPPER,                0x00100000, "Not used") \
    X(EX1_CFG_LAMINATOR,             0x00080000, "Lamination module detected") \
    X(EX1_INF_LAMI_ALLOW_TO_INSERT,  0x00040000, "Lamination module ready to insert card") \
    X(EX1_INF_LAMINATING_RUNNING,    0x00020000, "Lamination process is running") \
    X(EX1_INF_CLEAN_REMINDER,        0x00010000, "Reminder to clean the laminator") \
    X(EX1_INF_LAMI_TEMP_NOT_READY,   0x00008000, "Lamination roller is heating up, but its temperature is currently too low for the lamination process") \
    X(EX1_INF_SYNCHRONOUS_MODE,      0x00004000, "Lamination process is set to synchronous") \
    X(EX1_INF_LCD_BUT_ACK,           0x00002000, "LCD pop up button acknowledged") \
    X(EX1_INF_LCD_BUT_OK,            0x00001000, "LCD pop up OK button pressed") \
    X(EX1_INF_LCD_BUT_RETRY,         0x00000800, "LCD pop up Retry button pressed") \
    X(EX1_INF_LCD_BUT_CANCEL,        0x00000400, "LCD pop up Cancel button pressed") \
    X(EX1_CFG_BEZEL,                 0x00000200, "Bezel option installed") \
    X(EX1_INF_FEEDER_NEAR_EMPTY,     0x00000100, "Feeder is near empty (low level sensor)") \
    X(EX1_INF_FEEDER1_EMPTY,         0x00000080, "Feeder 1 is empty for KM2000B") \
    X(EX1_INF_FEEDER2_EMPTY,         0x00000040, "Feeder 2 is empty for KM2000B") \
    X(EX1_INF_FEEDER3_EMPTY,         0x00000020, "Feeder 3 is empty for KM2000B") \
    X(EX1_INF_FEEDER4_EMPTY,         0x00000010, "Feeder 4 is empty for KM2000B") \
    X(EX1_INF_FEEDER1_NEAR_EMPTY,    0x00000008, "Feeder 1 is near empty for KM2000B") \
    X(EX1_INF_FEEDER2_NEAR_EMPTY,    0x00000004, "Feeder 2 is near empty for KM2000B") \
    X(EX1_INF_FEEDER3_NEAR_EMPTY,    0x00000002, "Feeder 3 is near empty for KM2000B") \
    X(EX1_INF_FEEDER4_NEAR_EMPTY,    0x00000001, "Feeder 4 is near empty for KM2000B") \

typedef enum evolis_ex1_flag_e {
    EVOLIS_EX1_CFG_EXTENSION_2             = 0x80000000, //!< Extension 2 is used
    EVOLIS_EX1_CFG_KIOSK                   = 0x40000000, //!< Raised for KM500B, KM2000B
    EVOLIS_EX1_CFG_QUANTUM                 = 0x20000000, //!< Raised for Quantum
    EVOLIS_EX1_CFG_SECURION                = 0x10000000, //!< Raised for Securion
    EVOLIS_EX1_CFG_DUALYS                  = 0x08000000, //!< Raised for Dualys
    EVOLIS_EX1_CFG_PEBBLE                  = 0x04000000, //!< Raised for Pebble
    EVOLIS_EX1_CFG_SCANNER                 = 0x02000000, //!< Scanner option is detected
    EVOLIS_EX1_CFG_MEM_LAMINATION_MODULE_2 = 0x01000000, //!< Printer has previously seen 2 lamination modules simultaneously
    EVOLIS_EX1_INF_NO_LAMINATION_TO_DO     = 0x00800000, //!< Lamination module is set to 'pass through' mode
    EVOLIS_EX1_CFG_SEICO_FEEDER            = 0x00400000, //!< Seico feeder configured
    EVOLIS_EX1_CFG_KYTRONIC_FEEDER         = 0x00200000, //!< Kytronics feeder configured
    EVOLIS_EX1_CFG_HOPPER                  = 0x00100000, //!< Not used
    EVOLIS_EX1_CFG_LAMINATOR               = 0x00080000, //!< Lamination module detected
    EVOLIS_EX1_INF_LAMI_ALLOW_TO_INSERT    = 0x00040000, //!< Lamination module ready to insert card
    EVOLIS_EX1_INF_LAMINATING_RUNNING      = 0x00020000, //!< Lamination process is running
    EVOLIS_EX1_INF_CLEAN_REMINDER          = 0x00010000, //!< Reminder to clean the laminator
    EVOLIS_EX1_INF_LAMI_TEMP_NOT_READY     = 0x00008000, //!< Lamination roller is heating up, but its temperature is currently too low for the lamination process
    EVOLIS_EX1_INF_SYNCHRONOUS_MODE        = 0x00004000, //!< Lamination process is set to synchronous
    EVOLIS_EX1_INF_LCD_BUT_ACK             = 0x00002000, //!< LCD pop up button acknowledged
    EVOLIS_EX1_INF_LCD_BUT_OK              = 0x00001000, //!< LCD pop up OK button pressed
    EVOLIS_EX1_INF_LCD_BUT_RETRY           = 0x00000800, //!< LCD pop up Retry button pressed
    EVOLIS_EX1_INF_LCD_BUT_CANCEL          = 0x00000400, //!< LCD pop up Cancel button pressed
    EVOLIS_EX1_CFG_BEZEL                   = 0x00000200, //!< Bezel option installed
    EVOLIS_EX1_INF_FEEDER_NEAR_EMPTY       = 0x00000100, //!< Feeder is near empty (low level sensor)
    EVOLIS_EX1_INF_FEEDER1_EMPTY           = 0x00000080, //!< Feeder 1 is empty for KM2000B
    EVOLIS_EX1_INF_FEEDER2_EMPTY           = 0x00000040, //!< Feeder 2 is empty for KM2000B
    EVOLIS_EX1_INF_FEEDER3_EMPTY           = 0x00000020, //!< Feeder 3 is empty for KM2000B
    EVOLIS_EX1_INF_FEEDER4_EMPTY           = 0x00000010, //!< Feeder 4 is empty for KM2000B
    EVOLIS_EX1_INF_FEEDER1_NEAR_EMPTY      = 0x00000008, //!< Feeder 1 is near empty for KM2000B
    EVOLIS_EX1_INF_FEEDER2_NEAR_EMPTY      = 0x00000004, //!< Feeder 2 is near empty for KM2000B
    EVOLIS_EX1_INF_FEEDER3_NEAR_EMPTY      = 0x00000002, //!< Feeder 3 is near empty for KM2000B
    EVOLIS_EX1_INF_FEEDER4_NEAR_EMPTY      = 0x00000001, //!< Feeder 4 is near empty for KM2000B
} evolis_ex1_flag_t;

#define EVOLIS_EX2_VALUES(X) \
    X(EX2_CFG_EXTENSION_3,           0x80000000, "Extension 3 is used") \
    X(EX2_INF_SA_PROCESSING,         0x40000000, "Sensor adjustment is running") \
    X(EX2_INF_SCP_PROCESSING,        0x20000000, "Cleaning sequence is running") \
    X(EX2_INF_OPT_PROCESSING,        0x10000000, "Option activation is running (with activation key)") \
    X(EX2_INF_X08_PRINTER_UNLOCKED,  0x08000000, "Lock system currently unlocked") \
    X(EX2_INF_X08_FEEDER_OPEN,       0x04000000, "Feeder cover is open (used with locking system)") \
    X(EX2_INF_X08_EJECTBOX_FULL,     0x02000000, "Locking system feeder eject box full") \
    X(EX2_INF_X08_PRINT_UNLOCKED,    0x01000000, "Printing is currently unlocked, both mechanically and firmware-wise") \
    X(EX2_CFG_LAMINATION_MODULE_2,   0x00800000, "Second lamination module detected") \
    X(EX2_INF_LAMINATE_UNKNOWN,      0x00400000, "Installed laminate film is unknown/unreadable") \
    X(EX2_INF_LAMINATE_LOW,          0x00200000, "Laminate film is close to its end") \
    X(EX2_INF_LAMI_CARD,             0x00100000, "Card present in the lamination module") \
    X(EX2_INF_LAMI_CLEANING_RUNNING, 0x00080000, "Lamination module cleaning process is running") \
    X(EX2_INF_LAMI_UPDATING_FIRMWARE, 0x00040000, "Lamination module firmware update is running") \
    X(EX2_INF_LAMI_READY_FOR_CLEANING, 0x00020000, "Lamination module ready for cleaning (no laminate film and cover closed)") \
    X(EX2_INF_CARD_REAR,             0x00010000, "Card present at the rear of the printer") \
    X(EX2_DEF_NO_LAMINATE,           0x00008000, "No laminate film installed") \
    X(EX2_DEF_LAMI_COVER_OPEN,       0x00004000, "Lamination module cover is open") \
    X(EX2_DEF_LAMINATE_END,          0x00002000, "Laminate film reached its end") \
    X(EX2_DEF_LAMI_HOPPER_FULL,      0x00001000, "Lamination module hopper is full") \
    X(EX2_DEF_LAMINATE_UNSUPPORTED,  0x00000800, "Installed laminate film is not supported") \
    X(EX2_INF_CLEAR_UNKNOWN,         0x00000400, "Installed clear ribbon is unknown") \
    X(EX2_INF_CLEAR_LOW,             0x00000200, "Remaining clear ribbon is below the low limit") \
    X(EX2_INF_WRONG_ZONE_CLEAR,      0x00000100, "Installed clear ribbon has not the right zone") \
    X(EX2_ERR_LAMI_TEMPERATURE,      0x00000080, "Job interrupted because the laminator temperature was too high") \
    X(EX2_ERR_LAMINATE,              0x00000040, "Error on the laminate film") \
    X(EX2_ERR_LAMI_MECHANICAL,       0x00000020, "Mechanical error on the lamination module (card jam, ribbon jam, ...)") \
    X(EX2_ERR_LAMINATE_END,          0x00000010, "Job interrupted because the laminate film is finished") \
    X(EX2_ERR_LAMI_COVER_OPEN,       0x00000008, "Job interrupted by an open lamination module cover") \
    X(EX2_INF_CLEAR_CHANGED,         0x00000004, "Installed clear ribbon is different from the previous one") \
    X(EX2_INF_WRONG_ZONE_CLEAR_ALERT, 0x00000002, "Installed clear ribbon has wrong zone: only a few prints remaining before printing is blocked") \
    X(EX2_INF_WRONG_ZONE_CLEAR_EXPIRED, 0x00000001, "Installed clear ribbon has wrong zone: printing not allowed") \

typedef enum evolis_ex2_flag_e {
    EVOLIS_EX2_CFG_EXTENSION_3             = 0x80000000, //!< Extension 3 is used
    EVOLIS_EX2_INF_SA_PROCESSING           = 0x40000000, //!< Sensor adjustment is running
    EVOLIS_EX2_INF_SCP_PROCESSING          = 0x20000000, //!< Cleaning sequence is running
    EVOLIS_EX2_INF_OPT_PROCESSING          = 0x10000000, //!< Option activation is running (with activation key)
    EVOLIS_EX2_INF_X08_PRINTER_UNLOCKED    = 0x08000000, //!< Lock system currently unlocked
    EVOLIS_EX2_INF_X08_FEEDER_OPEN         = 0x04000000, //!< Feeder cover is open (used with locking system)
    EVOLIS_EX2_INF_X08_EJECTBOX_FULL       = 0x02000000, //!< Locking system feeder eject box full
    EVOLIS_EX2_INF_X08_PRINT_UNLOCKED      = 0x01000000, //!< Printing is currently unlocked, both mechanically and firmware-wise
    EVOLIS_EX2_CFG_LAMINATION_MODULE_2     = 0x00800000, //!< Second lamination module detected
    EVOLIS_EX2_INF_LAMINATE_UNKNOWN        = 0x00400000, //!< Installed laminate film is unknown/unreadable
    EVOLIS_EX2_INF_LAMINATE_LOW            = 0x00200000, //!< Laminate film is close to its end
    EVOLIS_EX2_INF_LAMI_CARD               = 0x00100000, //!< Card present in the lamination module
    EVOLIS_EX2_INF_LAMI_CLEANING_RUNNING   = 0x00080000, //!< Lamination module cleaning process is running
    EVOLIS_EX2_INF_LAMI_UPDATING_FIRMWARE  = 0x00040000, //!< Lamination module firmware update is running
    EVOLIS_EX2_INF_LAMI_READY_FOR_CLEANING = 0x00020000, //!< Lamination module ready for cleaning (no laminate film and cover closed)
    EVOLIS_EX2_INF_CARD_REAR               = 0x00010000, //!< Card present at the rear of the printer
    EVOLIS_EX2_DEF_NO_LAMINATE             = 0x00008000, //!< No laminate film installed
    EVOLIS_EX2_DEF_LAMI_COVER_OPEN         = 0x00004000, //!< Lamination module cover is open
    EVOLIS_EX2_DEF_LAMINATE_END            = 0x00002000, //!< Laminate film reached its end
    EVOLIS_EX2_DEF_LAMI_HOPPER_FULL        = 0x00001000, //!< Lamination module hopper is full
    EVOLIS_EX2_DEF_LAMINATE_UNSUPPORTED    = 0x00000800, //!< Installed laminate film is not supported
    EVOLIS_EX2_INF_CLEAR_UNKNOWN           = 0x00000400, //!< Installed clear ribbon is unknown
    EVOLIS_EX2_INF_CLEAR_LOW               = 0x00000200, //!< Remaining clear ribbon is below the low limit
    EVOLIS_EX2_INF_WRONG_ZONE_CLEAR        = 0x00000100, //!< Installed clear ribbon has not the right zone
    EVOLIS_EX2_ERR_LAMI_TEMPERATURE        = 0x00000080, //!< Job interrupted because the laminator temperature was too high
    EVOLIS_EX2_ERR_LAMINATE                = 0x00000040, //!< Error on the laminate film
    EVOLIS_EX2_ERR_LAMI_MECHANICAL         = 0x00000020, //!< Mechanical error on the lamination module (card jam, ribbon jam, ...)
    EVOLIS_EX2_ERR_LAMINATE_END            = 0x00000010, //!< Job interrupted because the laminate film is finished
    EVOLIS_EX2_ERR_LAMI_COVER_OPEN         = 0x00000008, //!< Job interrupted by an open lamination module cover
    EVOLIS_EX2_INF_CLEAR_CHANGED           = 0x00000004, //!< Installed clear ribbon is different from the previous one
    EVOLIS_EX2_INF_WRONG_ZONE_CLEAR_ALERT  = 0x00000002, //!< Installed clear ribbon has wrong zone: only a few prints remaining before printing is blocked
    EVOLIS_EX2_INF_WRONG_ZONE_CLEAR_EXPIRED = 0x00000001, //!< Installed clear ribbon has wrong zone: printing not allowed
} evolis_ex2_flag_t;

#define EVOLIS_EX3_VALUES(X) \
    X(EX3_CFG_EXTENSION_4,           0x80000000, "Extension 4 is used") \
    X(EX3_INF_RETRANSFER_RUNNING,    0x40000000, "Retransfer sequence is running") \
    X(EX3_INF_HEATING,               0x20000000, "Printer is heating up") \
    X(EX3_INF_CARD_MAN_FEED,         0x08000000, "Card present in the manual feeding module") \

typedef enum evolis_ex3_flag_e {
    EVOLIS_EX3_CFG_EXTENSION_4             = 0x80000000, //!< Extension 4 is used
    EVOLIS_EX3_INF_RETRANSFER_RUNNING      = 0x40000000, //!< Retransfer sequence is running
    EVOLIS_EX3_INF_HEATING                 = 0x20000000, //!< Printer is heating up
    EVOLIS_EX3_INF_CARD_MAN_FEED           = 0x08000000, //!< Card present in the manual feeding module
} evolis_ex3_flag_t;


#undef X

#define EVOLIS_STATUS_EX_COUNT 4

/// Evolis status buffer.
/// TODO - Add comment to properties.
typedef struct evolis_status_e {
    uint32_t config;
    uint32_t information;
    uint32_t warning;
    uint32_t error;
    uint32_t exts[EVOLIS_STATUS_EX_COUNT];
    uint16_t session;
} evolis_status_t;

/// Get status of the printer.
EVOLIS_WRA int evolis_status(evolis_t* printer, evolis_status_t* status);

/// Check if config flag is on.
EVOLIS_LIB bool evolis_status_is_on_cfg(const evolis_status_t* status, evolis_cfg_flag_t f);

/// Check if information flag is on.
EVOLIS_LIB bool evolis_status_is_on_inf(const evolis_status_t* status, evolis_inf_flag_t f);

/// Check if warning flag is on.
EVOLIS_LIB bool evolis_status_is_on_war(const evolis_status_t* status, evolis_war_flag_t f);

/// Check if error flag is on.
EVOLIS_LIB bool evolis_status_is_on_err(const evolis_status_t* status, evolis_err_flag_t f);

/// Check if extension 1 flag is on.
EVOLIS_LIB bool evolis_status_is_on_ex1(const evolis_status_t* status, evolis_ex1_flag_t f);

/// Check if extension 2 flag is on.
EVOLIS_LIB bool evolis_status_is_on_ex2(const evolis_status_t* status, evolis_ex2_flag_t f);

/// Check if extension 3 flag is on.
EVOLIS_LIB bool evolis_status_is_on_ex3(const evolis_status_t* status, evolis_ex3_flag_t f);
