#ifndef CONF_H
#define CONF_H

/* OMXPlayer options */
#define ADEV		"hdmi"		// audio output: hdmi/local
#define ADDCMD		" --refresh"	// additional commands, -r is a workaround for omxplayer issue #22

/* GUI options */
#define AMOUNT_ENTRIES 	15	//  number of entries
#define ENTRY_X		150	//  offset x for an entry 
#define ENTRY_Y		50	//  offset y for an entry

/* Font preferences */
#define FONT	    "/usr/share/fonts/truetype/freefont/FreeMono.ttf"	    // default font
#define FONT2	    "/usr/share/fonts/truetype/freefont/FreeMono-Bold.ttf"  // second font, currently unused
#define FONTSIZE    60

/* GUI Colors */
#define COLOR_BACK_R	255 
#define COLOR_BACK_G	255
#define COLOR_BACK_B	255
#define COLOR_FRONT_R	25
#define COLOR_FRONT_G	25
#define COLOR_FRONT_B	25
#define COLOR_DIR_R	0
#define COLOR_DIR_G	0
#define COLOR_DIR_B	255
#define COLOR_MARKED_R	100
#define COLOR_MARKED_G	100
#define COLOR_MARKED_B	100
#define COLOR_PLUGIN_R	200
#define COLOR_PLUGIN_G	0
#define COLOR_PLUGIN_B	0

/* Video plugin options */
#define PLUGIN_VIDEO_HOME   "/"	    // root for video files, default directory on plugin load

/* Misc */
#define WAIT_TIME 20	// waiting time between input events to lower CPU useage

#endif
