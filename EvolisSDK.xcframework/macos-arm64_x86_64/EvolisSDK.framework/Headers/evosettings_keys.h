/**
 * Evolis C library
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
 * ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
 * PARTICULAR PURPOSE.
 */
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  List of settings
 *  Some of the documented keys and values may be unavailable depending on the printer.
 */
#define EVOSETTINGS_KEYS(X)     \
    X(Unknown) \
    X(BBlackManagement) \
    X(BColorBrightness) \
    X(BColorContrast) \
    X(BDualDeposite) \
    X(BHalftoning) \
    X(BMonochromeContrast) \
    X(BOverlayContrast) \
    X(BOverlayManagement) \
    X(BOverlaySecondManagement) \
    X(BPageRotate180) \
    X(BRwErasingSpeed) \
    X(BRwErasingTemperature) \
    X(BRwManagement) \
    X(BRwPrintingSpeed) \
    X(BRwPrintingTemperature) \
    X(BUvBrightness) \
    X(BUvContrast) \
    X(BUvManagement) \
    X(BUvPremium) \
    X(Duplex) \
    X(FBlackManagement) \
    X(FColorBrightness) \
    X(FColorContrast) \
    X(FDualDeposite) \
    X(FHalftoning) \
    X(FMonochromeContrast) \
    X(FOverlayContrast) \
    X(FOverlayManagement) \
    X(FOverlaySecondManagement) \
    X(FPageRotate180) \
    X(FRwErasingSpeed) \
    X(FRwErasingTemperature) \
    X(FRwManagement) \
    X(FRwPrintingSpeed) \
    X(FRwPrintingTemperature) \
    X(FUvBrightness) \
    X(FUvContrast) \
    X(FUvManagement) \
    X(FUvPremium) \
    X(GCardPreloading) \
    X(GDigitalScrambling) \
    X(GDuplexType) \
    X(GFeederCfg) \
    X(GFeederPos) \
    X(GHighQualityMode) \
    X(GInputTray) \
    X(GMagCoercivity) \
    X(GMagT1Encoding) \
    X(GMagT2Encoding) \
    X(GMagT3Encoding) \
    X(GOutputTray) \
    X(GPipeDetection) \
    X(GRejectBox) \
    X(GRibbonType) \
    X(GRwCard) \
    X(GPrintingMode) \
    X(GShortPanelManagement) \
    X(GSmoothing) \
    X(IBBlackCustom) \
    X(IBBlackLevelValue) \
    X(IBDarkLevelValue) \
    X(IBNoTransferAreas) \
    X(IBOverlayCustom) \
    X(IBOverlayDefaultContent) \
    X(IBOverlaySecondCustom) \
    X(IBOverlaySecondDefaultContent) \
    X(IBRegionPrintingMode) \
    X(IBRwCustom) \
    X(IBRwCustomBitmap) \
    X(IBTextRegion) \
    X(IBThresholdValue) \
    X(IBUvContent) \
    X(IBUvCustom) \
    X(IFBlackCustom) \
    X(IFBlackLevelValue) \
    X(IFDarkLevelValue) \
    X(IFNoTransferAreas) \
    X(IFOverlayCustom) \
    X(IFOverlayDefaultContent) \
    X(IFOverlaySecondCustom) \
    X(IFOverlaySecondDefaultContent) \
    X(IFRegionPrintingMode) \
    X(IFRwCustom) \
    X(IFRwCustomBitmap) \
    X(IFTextRegion) \
    X(IFUvContent) \
    X(IFUvCustom) \
    X(IFThresholdValue) \
    X(IGBlackSub) \
    X(IGDuplexPreset) \
    X(IGIQLABC) \
    X(IGIQLABM) \
    X(IGIQLABY) \
    X(IGIQLACC) \
    X(IGIQLACM) \
    X(IGIQLACY) \
    X(IGMonoReaderType) \
    X(IGMonochromeSpeed) \
    X(IGRegionOrientation) \
    X(IGRibbonOptimization) \
    X(IGSendIQLA) \
    X(IGSendSpoolerSession) \
    X(IGDisableAutoEject) \
    X(IGStrictPageSetup) \
    X(IGTextRectErr) \
    X(IOverlayCustomContentAfnor) \
    X(IOverlayCustomContentIso) \
    X(IOverlayCustomContentMag) \
    X(IPipeDefinition) \
    X(IPostSmoothing) \
    X(ISendBlankPanel) \
    X(IShortPanelShift) \
    X(Orientation) \
    X(RawData) \
    X(Resolution) \
    X(Track1Data) \
    X(Track2Data) \
    X(Track3Data) \
    X(PrinterIsManaged) \
    X(srvAddress) \
    X(UIMagTrackSettingMode) \
    X(UIRibbonMode) \
    X(UpdatedByDrv) \
    X(UpdatedBySrv) \
    X(GColorProfileMode) \
    X(GColorProfile) \
    X(GColorProfileRendering) \
    X(IGColorProfileCustom) \
    X(IGColorProfileContent) \
    X(UIColorProfileName) \
    X(WIScanImageDepth) \
    X(WIScanImageResolution) \
    X(WIScanImageFileFormat) \
    X(WIScanSpeed) \
    X(WIScanOffset) \
    X(WIScanCardSides) \
    X(passthrough) \
    X(PaperSize) \
    X(FGamma) \
    X(FGammaFactor) \
    X(BGamma) \
    X(BGammaFactor) \
    X(FBlackPrinting) \
    X(BBlackPrinting) \
    X(FSilverManagement) \
    X(IFSilverCustom) \
    X(BSilverManagement) \
    X(IBSilverCustom) \
    X(UIScannerActivation) \

typedef enum evosettings_key_e {
    EVOSETTINGS_KE_Unknown,
    /**
     * EVOSETTINGS_KE_BBlackManagement
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: NOBLACKPOINT, ALLBLACKPOINT, TEXTINBLACK, BMPBLACK
     */
    EVOSETTINGS_KE_BBlackManagement,
    /**
     * EVOSETTINGS_KE_BColorBrightness
     * Usable in PrintSessions: true
     * Type: INT
     * Range: 1-20
     */
    EVOSETTINGS_KE_BColorBrightness,
    /**
     * EVOSETTINGS_KE_BColorContrast
     * Usable in PrintSessions: true
     * Type: INT
     * Range: 1-20
     */
    EVOSETTINGS_KE_BColorContrast,
    /**
     * EVOSETTINGS_KE_BDualDeposite
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: ON, OFF
     */
    EVOSETTINGS_KE_BDualDeposite,
    /**
     * EVOSETTINGS_KE_BHalftoning
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: THRESHOLD, FLOYD, DITHERING, CLUSTERED_DITHERING
     */
    EVOSETTINGS_KE_BHalftoning,
    /**
     * EVOSETTINGS_KE_BMonochromeContrast
     * Usable in PrintSessions: true
     * Type: INT
     * Range: 1-20
     */
    EVOSETTINGS_KE_BMonochromeContrast,
    /**
     * EVOSETTINGS_KE_BOverlayContrast
     * Usable in PrintSessions: true
     * Type: INT
     * Range: 1-20
     */
    EVOSETTINGS_KE_BOverlayContrast,
    /**
     * EVOSETTINGS_KE_BOverlayManagement
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: NOVARNISH, FULLVARNISH, BMPVARNISH
     */
    EVOSETTINGS_KE_BOverlayManagement,
    /**
     * EVOSETTINGS_KE_BOverlaySecondManagement
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: NOVARNISH, FULLVARNISH, BMPVARNISH
     */
    EVOSETTINGS_KE_BOverlaySecondManagement,
    /**
     * EVOSETTINGS_KE_BPageRotate180
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: ON, OFF
     */
    EVOSETTINGS_KE_BPageRotate180,
    /**
     * EVOSETTINGS_KE_BRwErasingSpeed
     * Usable in PrintSessions: true
     * Type: INT
     * Range: 1-10
     */
    EVOSETTINGS_KE_BRwErasingSpeed,
    /**
     * EVOSETTINGS_KE_BRwErasingTemperature
     * Usable in PrintSessions: true
     * Type: INT
     * Range: 1-20
     */
    EVOSETTINGS_KE_BRwErasingTemperature,
    /**
     * EVOSETTINGS_KE_BRwManagement
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: WRITEONLY, FULLREWRITE, BMPREWRITE
     */
    EVOSETTINGS_KE_BRwManagement,
    /**
     * EVOSETTINGS_KE_BRwPrintingSpeed
     * Usable in PrintSessions: true
     * Type: INT
     * Range: 1-10
     */
    EVOSETTINGS_KE_BRwPrintingSpeed,
    /**
     * EVOSETTINGS_KE_BRwPrintingTemperature
     * Usable in PrintSessions: true
     * Type: INT
     * Range: 1-20
     */
    EVOSETTINGS_KE_BRwPrintingTemperature,
    /**
     * EVOSETTINGS_KE_BUvBrightness
     * Usable in PrintSessions: true
     * Type: INT
     * Range: 1-20
     */
    EVOSETTINGS_KE_BUvBrightness,
    /**
     * EVOSETTINGS_KE_BUvContrast
     * Usable in PrintSessions: true
     * Type: INT
     * Range: 1-20
     */
    EVOSETTINGS_KE_BUvContrast,
    /**
     * EVOSETTINGS_KE_BUvManagement
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: NOUV, BMPUV
     */
    EVOSETTINGS_KE_BUvManagement,
    /**
     * EVOSETTINGS_KE_BUvPremium
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: ON, OFF
     */
    EVOSETTINGS_KE_BUvPremium,
    /**
     * EVOSETTINGS_KE_Duplex
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: NONE, HORIZONTAL
     */
    EVOSETTINGS_KE_Duplex,
    /**
     * EVOSETTINGS_KE_FBlackManagement
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: NOBLACKPOINT, ALLBLACKPOINT, TEXTINBLACK, BMPBLACK
     */
    EVOSETTINGS_KE_FBlackManagement,
    /**
     * EVOSETTINGS_KE_FColorBrightness
     * Usable in PrintSessions: true
     * Type: INT
     * Range: 1-20
     */
    EVOSETTINGS_KE_FColorBrightness,
    /**
     * EVOSETTINGS_KE_FColorContrast
     * Usable in PrintSessions: true
     * Type: INT
     * Range: 1-20
     */
    EVOSETTINGS_KE_FColorContrast,
    /**
     * EVOSETTINGS_KE_FDualDeposite
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: ON, OFF
     */
    EVOSETTINGS_KE_FDualDeposite,
    /**
     * EVOSETTINGS_KE_FHalftoning
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: THRESHOLD, FLOYD, DITHERING, CLUSTERED_DITHERING
     */
    EVOSETTINGS_KE_FHalftoning,
    /**
     * EVOSETTINGS_KE_FMonochromeContrast
     * Usable in PrintSessions: true
     * Type: INT
     * Range: 1-20
     */
    EVOSETTINGS_KE_FMonochromeContrast,
    /**
     * EVOSETTINGS_KE_FOverlayContrast
     * Usable in PrintSessions: true
     * Type: INT
     * Range: 1-20
     */
    EVOSETTINGS_KE_FOverlayContrast,
    /**
     * EVOSETTINGS_KE_FOverlayManagement
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: NOVARNISH, FULLVARNISH, BMPVARNISH
     */
    EVOSETTINGS_KE_FOverlayManagement,
    /**
     * EVOSETTINGS_KE_FOverlaySecondManagement
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: NOVARNISH, FULLVARNISH, BMPVARNISH
     */
    EVOSETTINGS_KE_FOverlaySecondManagement,
    /**
     * EVOSETTINGS_KE_FPageRotate180
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: ON, OFF
     */
    EVOSETTINGS_KE_FPageRotate180,
    /**
     * EVOSETTINGS_KE_FRwErasingSpeed
     * Usable in PrintSessions: true
     * Type: INT
     * Range: 1-10
     */
    EVOSETTINGS_KE_FRwErasingSpeed,
    /**
     * EVOSETTINGS_KE_FRwErasingTemperature
     * Usable in PrintSessions: true
     * Type: INT
     * Range: 1-20
     */
    EVOSETTINGS_KE_FRwErasingTemperature,
    /**
     * EVOSETTINGS_KE_FRwManagement
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: WRITEONLY, FULLREWRITE, BMPREWRITE
     */
    EVOSETTINGS_KE_FRwManagement,
    /**
     * EVOSETTINGS_KE_FRwPrintingSpeed
     * Usable in PrintSessions: true
     * Type: INT
     * Range: 1-10
     */
    EVOSETTINGS_KE_FRwPrintingSpeed,
    /**
     * EVOSETTINGS_KE_FRwPrintingTemperature
     * Usable in PrintSessions: true
     * Type: INT
     * Range: 1-20
     */
    EVOSETTINGS_KE_FRwPrintingTemperature,
    /**
     * EVOSETTINGS_KE_FUvBrightness
     * Usable in PrintSessions: true
     * Type: INT
     * Range: 1-20
     */
    EVOSETTINGS_KE_FUvBrightness,
    /**
     * EVOSETTINGS_KE_FUvContrast
     * Usable in PrintSessions: true
     * Type: INT
     * Range: 1-20
     */
    EVOSETTINGS_KE_FUvContrast,
    /**
     * EVOSETTINGS_KE_FUvManagement
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: NOUV, BMPUV
     */
    EVOSETTINGS_KE_FUvManagement,
    /**
     * EVOSETTINGS_KE_FUvPremium
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: ON, OFF
     */
    EVOSETTINGS_KE_FUvPremium,
    /**
     * EVOSETTINGS_KE_GCardPreloading
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: ON, OFF
     */
    EVOSETTINGS_KE_GCardPreloading,
    /**
     * EVOSETTINGS_KE_GDigitalScrambling
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: ON, OFF
     */
    EVOSETTINGS_KE_GDigitalScrambling,
    /**
     * EVOSETTINGS_KE_GDuplexType
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: DUPLEX_CC, DUPLEX_CM, DUPLEX_MC, DUPLEX_MM
     */
    EVOSETTINGS_KE_GDuplexType,
    /**
     * EVOSETTINGS_KE_GFeederCfg
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: PRINTER, AUTO, FEEDERA, FEEDERB, FEEDERC, FEEDERD, ALTERNATE, FEEDER1, FEEDER2, FEEDER3, FEEDER4, NONE
     */
    EVOSETTINGS_KE_GFeederCfg,
    /**
     * EVOSETTINGS_KE_GFeederPos
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: PRINTER, FEEDERA, FEEDERB, FEEDERC, FEEDERD, MIDDLE, OFF
     */
    EVOSETTINGS_KE_GFeederPos,
    /**
     * EVOSETTINGS_KE_GHighQualityMode
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: ON, OFF
     */
    EVOSETTINGS_KE_GHighQualityMode,
    /**
     * EVOSETTINGS_KE_GInputTray
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: PRINTER, FEEDER, AUTO, MANUAL, HOPPER, BEZEL
     */
    EVOSETTINGS_KE_GInputTray,
    /**
     * EVOSETTINGS_KE_GMagCoercivity
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: OFF, LOCO, HICO
     */
    EVOSETTINGS_KE_GMagCoercivity,
    /**
     * EVOSETTINGS_KE_GMagT1Encoding
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: ISO1, ISO2, ISO3, SIPASS, C2, JIS2, C4, NONE
     */
    EVOSETTINGS_KE_GMagT1Encoding,
    /**
     * EVOSETTINGS_KE_GMagT2Encoding
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: ISO1, ISO2, ISO3, SIPASS, C2, JIS2, C4, NONE
     */
    EVOSETTINGS_KE_GMagT2Encoding,
    /**
     * EVOSETTINGS_KE_GMagT3Encoding
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: ISO1, ISO2, ISO3, SIPASS, C2, JIS2, C4, NONE
     */
    EVOSETTINGS_KE_GMagT3Encoding,
    /**
     * EVOSETTINGS_KE_GOutputTray
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: PRINTER, HOPPER, REAR, MANUAL, REJECT, BEZEL
     */
    EVOSETTINGS_KE_GOutputTray,
    /**
     * EVOSETTINGS_KE_GPipeDetection
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: OFF, DEFAULT, CUSTOM
     */
    EVOSETTINGS_KE_GPipeDetection,
    /**
     * EVOSETTINGS_KE_GRejectBox
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: PRINTER, DEFAULTREJECT, HOPPER, MANUAL, REJECT, BEZEL
     */
    EVOSETTINGS_KE_GRejectBox,
    /**
     * EVOSETTINGS_KE_GRibbonType
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: RC_YMCKI, RC_YMCKKI, RC_YMCFK, RC_YMCK, RC_YMCKK, RC_YMCKO, RC_YMCKOS, RC_YMCKOS13, RC_YMCKOK, RC_YMCKOKS13, RC_YMCKOKOS, RC_YMCKOO, RM_KO, RM_KBLACK, RM_KWHITE, RM_KRED, RM_KGREEN, RM_KBLUE, RM_KSCRATCH, RM_KMETALSILVER, RM_KMETALGOLD, RM_KSIGNATURE, RM_KWAX, RM_KPREMIUM, RM_HOLO, RM_SOKO, RC_YMCK_A, RC_YMCKK_A, RC_YMCKI_A, RC_YMCKH_A, RC_YMCFK_A, RC_YMCKSI_A
     */
    EVOSETTINGS_KE_GRibbonType,
    /**
     * EVOSETTINGS_KE_GRwCard
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: MBLACK, MBLUE, CUSTOM_FRONT, CUSTOM_DUPLEX
     */
    EVOSETTINGS_KE_GRwCard,
    /**
     * EVOSETTINGS_KE_GPrintingMode
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: D2T2, RW_2IN1
     */
    EVOSETTINGS_KE_GPrintingMode,
    /**
     * EVOSETTINGS_KE_GShortPanelManagement
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: AUTO, CUSTOM, OFF
     */
    EVOSETTINGS_KE_GShortPanelManagement,
    /**
     * EVOSETTINGS_KE_GSmoothing
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: STDSMOOTH, ADVSMOOTH, NOSMOOTH
     */
    EVOSETTINGS_KE_GSmoothing,
    /**
     * EVOSETTINGS_KE_IBBlackCustom
     * Usable in PrintSessions: true
     * Type: TEXT
     */
    EVOSETTINGS_KE_IBBlackCustom,
    /**
     * EVOSETTINGS_KE_IBBlackLevelValue
     * Usable in PrintSessions: true
     * Type: INT
     * Range: 1-255
     */
    EVOSETTINGS_KE_IBBlackLevelValue,
    /**
     * EVOSETTINGS_KE_IBDarkLevelValue
     * Usable in PrintSessions: true
     * Type: INT
     * Range: 0-255
     */
    EVOSETTINGS_KE_IBDarkLevelValue,
    /**
     * EVOSETTINGS_KE_IBNoTransferAreas
     * Usable in PrintSessions: true
     * Type: TEXT
     */
    EVOSETTINGS_KE_IBNoTransferAreas,
    /**
     * EVOSETTINGS_KE_IBOverlayCustom
     * Usable in PrintSessions: true
     * Type: TEXT
     */
    EVOSETTINGS_KE_IBOverlayCustom,
    /**
     * EVOSETTINGS_KE_IBOverlayDefaultContent
     * Usable in PrintSessions: false
     * Type: BLOB
     */
    EVOSETTINGS_KE_IBOverlayDefaultContent,
    /**
     * EVOSETTINGS_KE_IBOverlaySecondCustom
     * Usable in PrintSessions: true
     * Type: TEXT
     */
    EVOSETTINGS_KE_IBOverlaySecondCustom,
    /**
     * EVOSETTINGS_KE_IBOverlaySecondDefaultContent
     * Usable in PrintSessions: false
     * Type: BLOB
     */
    EVOSETTINGS_KE_IBOverlaySecondDefaultContent,
    /**
     * EVOSETTINGS_KE_IBRegionPrintingMode
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: RESIN, BLACK_COMPOSITE
     */
    EVOSETTINGS_KE_IBRegionPrintingMode,
    /**
     * EVOSETTINGS_KE_IBRwCustom
     * Usable in PrintSessions: true
     * Type: TEXT
     */
    EVOSETTINGS_KE_IBRwCustom,
    /**
     * EVOSETTINGS_KE_IBRwCustomBitmap
     * Usable in PrintSessions: false
     * Type: BLOB
     */
    EVOSETTINGS_KE_IBRwCustomBitmap,
    /**
     * EVOSETTINGS_KE_IBTextRegion
     * Usable in PrintSessions: true
     * Type: TEXT
     */
    EVOSETTINGS_KE_IBTextRegion,
    /**
     * EVOSETTINGS_KE_IBThresholdValue
     * Usable in PrintSessions: true
     * Type: INT
     * Range: 1-255
     */
    EVOSETTINGS_KE_IBThresholdValue,
    /**
     * EVOSETTINGS_KE_IBUvContent
     * Usable in PrintSessions: false
     * Type: BLOB
     */
    EVOSETTINGS_KE_IBUvContent,
    /**
     * EVOSETTINGS_KE_IBUvCustom
     * Usable in PrintSessions: true
     * Type: TEXT
     */
    EVOSETTINGS_KE_IBUvCustom,
    /**
     * EVOSETTINGS_KE_IFBlackCustom
     * Usable in PrintSessions: true
     * Type: TEXT
     */
    EVOSETTINGS_KE_IFBlackCustom,
    /**
     * EVOSETTINGS_KE_IFBlackLevelValue
     * Usable in PrintSessions: true
     * Type: INT
     * Range: 1-255
     */
    EVOSETTINGS_KE_IFBlackLevelValue,
    /**
     * EVOSETTINGS_KE_IFDarkLevelValue
     * Usable in PrintSessions: true
     * Type: INT
     * Range: 0-255
     */
    EVOSETTINGS_KE_IFDarkLevelValue,
    /**
     * EVOSETTINGS_KE_IFNoTransferAreas
     * Usable in PrintSessions: true
     * Type: TEXT
     */
    EVOSETTINGS_KE_IFNoTransferAreas,
    /**
     * EVOSETTINGS_KE_IFOverlayCustom
     * Usable in PrintSessions: true
     * Type: TEXT
     */
    EVOSETTINGS_KE_IFOverlayCustom,
    /**
     * EVOSETTINGS_KE_IFOverlayDefaultContent
     * Usable in PrintSessions: false
     * Type: BLOB
     */
    EVOSETTINGS_KE_IFOverlayDefaultContent,
    /**
     * EVOSETTINGS_KE_IFOverlaySecondCustom
     * Usable in PrintSessions: true
     * Type: TEXT
     */
    EVOSETTINGS_KE_IFOverlaySecondCustom,
    /**
     * EVOSETTINGS_KE_IFOverlaySecondDefaultContent
     * Usable in PrintSessions: false
     * Type: BLOB
     */
    EVOSETTINGS_KE_IFOverlaySecondDefaultContent,
    /**
     * EVOSETTINGS_KE_IFRegionPrintingMode
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: RESIN, BLACK_COMPOSITE
     */
    EVOSETTINGS_KE_IFRegionPrintingMode,
    /**
     * EVOSETTINGS_KE_IFRwCustom
     * Usable in PrintSessions: true
     * Type: TEXT
     */
    EVOSETTINGS_KE_IFRwCustom,
    /**
     * EVOSETTINGS_KE_IFRwCustomBitmap
     * Usable in PrintSessions: false
     * Type: BLOB
     */
    EVOSETTINGS_KE_IFRwCustomBitmap,
    /**
     * EVOSETTINGS_KE_IFTextRegion
     * Usable in PrintSessions: true
     * Type: TEXT
     */
    EVOSETTINGS_KE_IFTextRegion,
    /**
     * EVOSETTINGS_KE_IFUvContent
     * Usable in PrintSessions: false
     * Type: BLOB
     */
    EVOSETTINGS_KE_IFUvContent,
    /**
     * EVOSETTINGS_KE_IFUvCustom
     * Usable in PrintSessions: true
     * Type: TEXT
     */
    EVOSETTINGS_KE_IFUvCustom,
    /**
     * EVOSETTINGS_KE_IFThresholdValue
     * Usable in PrintSessions: true
     * Type: INT
     * Range: 1-255
     */
    EVOSETTINGS_KE_IFThresholdValue,
    /**
     * EVOSETTINGS_KE_IGBlackSub
     * Usable in PrintSessions: true
     * Type: TEXT
     */
    EVOSETTINGS_KE_IGBlackSub,
    /**
     * EVOSETTINGS_KE_IGDuplexPreset
     * Usable in PrintSessions: false
     * Type: INT
     * Range: 0-99
     */
    EVOSETTINGS_KE_IGDuplexPreset,
    /**
     * EVOSETTINGS_KE_IGIQLABC
     * Usable in PrintSessions: true
     * Type: INT
     * Range: 0-20
     */
    EVOSETTINGS_KE_IGIQLABC,
    /**
     * EVOSETTINGS_KE_IGIQLABM
     * Usable in PrintSessions: true
     * Type: INT
     * Range: 0-20
     */
    EVOSETTINGS_KE_IGIQLABM,
    /**
     * EVOSETTINGS_KE_IGIQLABY
     * Usable in PrintSessions: true
     * Type: INT
     * Range: 0-20
     */
    EVOSETTINGS_KE_IGIQLABY,
    /**
     * EVOSETTINGS_KE_IGIQLACC
     * Usable in PrintSessions: true
     * Type: INT
     * Range: 0-20
     */
    EVOSETTINGS_KE_IGIQLACC,
    /**
     * EVOSETTINGS_KE_IGIQLACM
     * Usable in PrintSessions: true
     * Type: INT
     * Range: 0-20
     */
    EVOSETTINGS_KE_IGIQLACM,
    /**
     * EVOSETTINGS_KE_IGIQLACY
     * Usable in PrintSessions: true
     * Type: INT
     * Range: 0-20
     */
    EVOSETTINGS_KE_IGIQLACY,
    /**
     * EVOSETTINGS_KE_IGMonoReaderType
     * Usable in PrintSessions: false
     * Type: LIST
     * Possible values: REG, FILE
     */
    EVOSETTINGS_KE_IGMonoReaderType,
    /**
     * EVOSETTINGS_KE_IGMonochromeSpeed
     * Usable in PrintSessions: true
     * Type: INT
     * Range: 1-10
     */
    EVOSETTINGS_KE_IGMonochromeSpeed,
    /**
     * EVOSETTINGS_KE_IGRegionOrientation
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: LANDSCAPE, PORTRAIT
     */
    EVOSETTINGS_KE_IGRegionOrientation,
    /**
     * EVOSETTINGS_KE_IGRibbonOptimization
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: ON, OFF
     */
    EVOSETTINGS_KE_IGRibbonOptimization,
    /**
     * EVOSETTINGS_KE_IGSendIQLA
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: ON, OFF
     */
    EVOSETTINGS_KE_IGSendIQLA,
    /**
     * EVOSETTINGS_KE_IGSendSpoolerSession
     * Usable in PrintSessions: false
     * Type: LIST
     * Possible values: ON, OFF
     */
    EVOSETTINGS_KE_IGSendSpoolerSession,
    /**
     * EVOSETTINGS_KE_IGDisableAutoEject
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: ON, OFF
     */
    EVOSETTINGS_KE_IGDisableAutoEject,
    /**
     * EVOSETTINGS_KE_IGStrictPageSetup
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: ON, OFF
     */
    EVOSETTINGS_KE_IGStrictPageSetup,
    /**
     * EVOSETTINGS_KE_IGTextRectErr
     * Usable in PrintSessions: true
     * Type: INT
     * Range: 0-20
     */
    EVOSETTINGS_KE_IGTextRectErr,
    /**
     * EVOSETTINGS_KE_IOverlayCustomContentAfnor
     * Usable in PrintSessions: false
     * Type: BLOB
     */
    EVOSETTINGS_KE_IOverlayCustomContentAfnor,
    /**
     * EVOSETTINGS_KE_IOverlayCustomContentIso
     * Usable in PrintSessions: false
     * Type: BLOB
     */
    EVOSETTINGS_KE_IOverlayCustomContentIso,
    /**
     * EVOSETTINGS_KE_IOverlayCustomContentMag
     * Usable in PrintSessions: false
     * Type: BLOB
     */
    EVOSETTINGS_KE_IOverlayCustomContentMag,
    /**
     * EVOSETTINGS_KE_IPipeDefinition
     * Usable in PrintSessions: false
     * Type: TEXT
     */
    EVOSETTINGS_KE_IPipeDefinition,
    /**
     * EVOSETTINGS_KE_IPostSmoothing
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: STDSMOOTH, ADVSMOOTH, NOSMOOTH
     */
    EVOSETTINGS_KE_IPostSmoothing,
    /**
     * EVOSETTINGS_KE_ISendBlankPanel
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: ON, OFF
     */
    EVOSETTINGS_KE_ISendBlankPanel,
    /**
     * EVOSETTINGS_KE_IShortPanelShift
     * Usable in PrintSessions: true
     * Type: INT
     * Range: 0-9999
     */
    EVOSETTINGS_KE_IShortPanelShift,
    /**
     * EVOSETTINGS_KE_Orientation
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: LANDSCAPE_CC90, PORTRAIT
     */
    EVOSETTINGS_KE_Orientation,
    /**
     * EVOSETTINGS_KE_RawData
     * Usable in PrintSessions: false
     * Type: TEXT
     */
    EVOSETTINGS_KE_RawData,
    /**
     * EVOSETTINGS_KE_Resolution
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: DPI300260, DPI300, DPI600300, DPI600, DPI1200300
     */
    EVOSETTINGS_KE_Resolution,
    /**
     * EVOSETTINGS_KE_Track1Data
     * Usable in PrintSessions: false
     * Type: TEXT
     */
    EVOSETTINGS_KE_Track1Data,
    /**
     * EVOSETTINGS_KE_Track2Data
     * Usable in PrintSessions: false
     * Type: TEXT
     */
    EVOSETTINGS_KE_Track2Data,
    /**
     * EVOSETTINGS_KE_Track3Data
     * Usable in PrintSessions: false
     * Type: TEXT
     */
    EVOSETTINGS_KE_Track3Data,
    /**
     * EVOSETTINGS_KE_PrinterIsManaged
     * Usable in PrintSessions: false
     * Type: INT
     * Range: 0-1
     */
    EVOSETTINGS_KE_PrinterIsManaged,
    /**
     * EVOSETTINGS_KE_srvAddress
     * Usable in PrintSessions: false
     * Type: TEXT
     */
    EVOSETTINGS_KE_srvAddress,
    /**
     * EVOSETTINGS_KE_UIMagTrackSettingMode
     * Usable in PrintSessions: false
     * Type: INT
     * Range: 0-1
     */
    EVOSETTINGS_KE_UIMagTrackSettingMode,
    /**
     * EVOSETTINGS_KE_UIRibbonMode
     * Usable in PrintSessions: false
     * Type: INT
     * Range: 0-1
     */
    EVOSETTINGS_KE_UIRibbonMode,
    /**
     * EVOSETTINGS_KE_UpdatedByDrv
     * Usable in PrintSessions: false
     * Type: INT
     * Range: 0-1
     */
    EVOSETTINGS_KE_UpdatedByDrv,
    /**
     * EVOSETTINGS_KE_UpdatedBySrv
     * Usable in PrintSessions: false
     * Type: INT
     * Range: 0-1
     */
    EVOSETTINGS_KE_UpdatedBySrv,
    /**
     * EVOSETTINGS_KE_GColorProfileMode
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: NOPROFILE, DRIVERPROFILE, CUSTOM
     */
    EVOSETTINGS_KE_GColorProfileMode,
    /**
     * EVOSETTINGS_KE_GColorProfile
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: STDPROFILE
     */
    EVOSETTINGS_KE_GColorProfile,
    /**
     * EVOSETTINGS_KE_GColorProfileRendering
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: PERCEPTUAL, SATURATION
     */
    EVOSETTINGS_KE_GColorProfileRendering,
    /**
     * EVOSETTINGS_KE_IGColorProfileCustom
     * Usable in PrintSessions: true
     * Type: TEXT
     */
    EVOSETTINGS_KE_IGColorProfileCustom,
    /**
     * EVOSETTINGS_KE_IGColorProfileContent
     * Usable in PrintSessions: false
     * Type: BLOB
     */
    EVOSETTINGS_KE_IGColorProfileContent,
    /**
     * EVOSETTINGS_KE_UIColorProfileName
     * Usable in PrintSessions: false
     * Type: TEXT
     */
    EVOSETTINGS_KE_UIColorProfileName,
    /**
     * EVOSETTINGS_KE_WIScanImageDepth
     * Usable in PrintSessions: false
     * Type: LIST
     * Possible values: BPP8, BPP16, BPP24, BPP32
     */
    EVOSETTINGS_KE_WIScanImageDepth,
    /**
     * EVOSETTINGS_KE_WIScanImageResolution
     * Usable in PrintSessions: false
     * Type: LIST
     * Possible values: DPI300, DPI600
     */
    EVOSETTINGS_KE_WIScanImageResolution,
    /**
     * EVOSETTINGS_KE_WIScanImageFileFormat
     * Usable in PrintSessions: false
     * Type: LIST
     * Possible values: JPG, BMP, PNG
     */
    EVOSETTINGS_KE_WIScanImageFileFormat,
    /**
     * EVOSETTINGS_KE_WIScanSpeed
     * Usable in PrintSessions: false
     * Type: INT
     * Range: 0-40
     */
    EVOSETTINGS_KE_WIScanSpeed,
    /**
     * EVOSETTINGS_KE_WIScanOffset
     * Usable in PrintSessions: false
     * Type: INT
     * Range: 0-40
     */
    EVOSETTINGS_KE_WIScanOffset,
    /**
     * EVOSETTINGS_KE_WIScanCardSides
     * Usable in PrintSessions: false
     * Type: LIST
     * Possible values: FRONT_BACK, FRONT_ONLY, BACK_ONLY
     */
    EVOSETTINGS_KE_WIScanCardSides,
    /**
     * EVOSETTINGS_KE_passthrough
     * Usable in PrintSessions: false
     * Type: TEXT
     */
    EVOSETTINGS_KE_passthrough,
    /**
     * EVOSETTINGS_KE_PaperSize
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: CR80, ISOCR80, CR120X50, CR150X50, AVANSIACR80
     */
    EVOSETTINGS_KE_PaperSize,
    /**
     * EVOSETTINGS_KE_FGamma
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: ON, OFF
     */
    EVOSETTINGS_KE_FGamma,
    /**
     * EVOSETTINGS_KE_FGammaFactor
     * Usable in PrintSessions: true
     * Type: INT
     * Range: 0-100
     */
    EVOSETTINGS_KE_FGammaFactor,
    /**
     * EVOSETTINGS_KE_BGamma
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: ON, OFF
     */
    EVOSETTINGS_KE_BGamma,
    /**
     * EVOSETTINGS_KE_BGammaFactor
     * Usable in PrintSessions: true
     * Type: INT
     * Range: 0-100
     */
    EVOSETTINGS_KE_BGammaFactor,
    /**
     * EVOSETTINGS_KE_FBlackPrinting
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: ON, OFF
     */
    EVOSETTINGS_KE_FBlackPrinting,
    /**
     * EVOSETTINGS_KE_BBlackPrinting
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: ON, OFF
     */
    EVOSETTINGS_KE_BBlackPrinting,
    /**
     * EVOSETTINGS_KE_FSilverManagement
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: NOSILVER
     */
    EVOSETTINGS_KE_FSilverManagement,
    /**
     * EVOSETTINGS_KE_IFSilverCustom
     * Usable in PrintSessions: true
     * Type: TEXT
     */
    EVOSETTINGS_KE_IFSilverCustom,
    /**
     * EVOSETTINGS_KE_BSilverManagement
     * Usable in PrintSessions: true
     * Type: LIST
     * Possible values: NOSILVER
     */
    EVOSETTINGS_KE_BSilverManagement,
    /**
     * EVOSETTINGS_KE_IBSilverCustom
     * Usable in PrintSessions: true
     * Type: TEXT
     */
    EVOSETTINGS_KE_IBSilverCustom,
    EVOSETTINGS_KE_UIScannerActivation
} evosettings_key_t;


#ifdef __cplusplus
}
#endif

