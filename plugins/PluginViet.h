#ifndef PLUGIN_VIET_H
#define PLUGIN_VIET_H

#include "PluginEntry.h"

#include <list>
#include <string>

#define LINK_VTV1a	    "http://112.197.2.16:1935/live/vtv1.stream/playlist.m3u8"
#define LINK_VTV1b  	    "http://123.30.191.152/live/vtv1-1500-flv?fmtx264_1500K_flvcpidsize640X480&start=0"
#define LINK_VTV2   	    "http://112.197.2.16:1935/live/vtv2.stream/playlist.m3u8"
#define LINK_VTV3  	    "http://112.197.2.16:1935/live/vtv3.stream/playlist.m3u8"
//#define LINK_VTV3a  	    "http://118.69.198.230:1935/live/VTV3.stream/playlist.m3u8"
//#define LINK_VTV3b  	    "http://123.30.191.151/live/vtv3_1500k_flv?fmt=x264_1500k_flv&size=640x480&start=0"
#define LINK_VTV4   	    "http://112.197.2.16:1935/live/vtv4.stream/playlist.m3u8"
#define LINK_VTV6   	    "http://112.197.2.16:1935/live/vtv6.stream/playlist.m3u8"
#define LINK_VTV9   	    "http://112.197.2.16:1935/live/vtv9.stream/playlist.m3u8"
#define LINK_HTV2   	    "http://118.69.198.230:1935/live/HTV2.stream/playlist.m3u8"
#define LINK_HTV7a  	    "http://118.69.198.230:1935/live/HTV7.stream/playlist.m3u8"
#define LINK_HTV7b  	    "http://112.197.2.16:1935/live/htv7.stream/playlist.m3u8"
#define LINK_HTV9a  	    "http://112.197.2.16:1935/live/htv9.stream/playlist.m3u8"
#define LINK_HTV9b  	    "http://118.69.198.230:1935/live/HTV9.stream/playlist.m3u8"
#define LINK_HTVCHD_YEAHTVa "rtmp://221.133.7.133/yeah1live/mp4:yeah1live.480p"
#define LINK_HTVCHD_YEAHTVb "http://118.69.198.230:1935/live/yeah1.stream/playlist.m3u8"
#define LINK_VTC1  	    "http://123.30.191.118/live/ts2flv_vtc1_1500K?fmt=x264_1500K_flv&cpid=&size=720X576&start=0"
#define LINK_VCTV3  	    "http://118.69.198.230:1935/live/VCTV3.stream/playlist.m3u8"
#define LINK_VTC6a  	    "http://118.69.198.230:1935/live/VTC6.stream/playlist.m3u8"
#define LINK_VTC6b	    "rtmp://113.161.70.112/live/livestream"
#define LINK_VCTV7  	    "http://118.69.198.230:1935/live/VCTV7.stream/playlist.m3u8"
#define LINK_VTC9  	    "http://118.69.198.230:1935/live/VTC9.stream/playlist.m3u8"
#define LINK_VTC13  	    "http://118.69.198.230:1935/live/VTC13.stream/playlist.m3u8"
#define LINK_VCTV9  	    "mms://222.255.31.252/InfoTVChannel"
#define LINK_ITV  	    "rtmp://210.245.82.6/live/itvw_hh"
#define LINK_SCTV1  	    "http://112.197.2.16:1935/live/SDsctv1.stream/playlist.m3u8"
#define LINK_SCTV2  	    "http://112.197.2.16:1935/live/SDsctv2.stream/playlist.m3u8"
#define LINK_SCTV3  	    "http://112.197.2.16:1935/live/SDsctv3.stream/playlist.m3u8"
#define LINK_SCTV4  	    "http://112.197.2.16:1935/live/SDsctv4.stream/playlist.m3u8"
#define LINK_SCTV5  	    "http://112.197.2.16:1935/live/SDsctv5.stream/playlist.m3u8"
#define LINK_SCTV6  	    "http://112.197.2.16:1935/live/SDsctv6.stream/playlist.m3u8"
#define LINK_SCTV7  	    "http://112.197.2.16:1935/live/SDsctv7.stream/playlist.m3u8"
#define LINK_SCTV8  	    "http://112.197.2.16:1935/live/SDsctv8.stream/playlist.m3u8"
#define LINK_SCTV9  	    "http://112.197.2.16:1935/live/SDsctv9.stream/playlist.m3u8"
#define LINK_SCTV10  	    "http://112.197.2.16:1935/live/SDsctv10.stream/playlist.m3u8"
#define LINK_SCTV11  	    "http://112.197.2.16:1935/live/SDsctv11.stream/playlist.m3u8"
#define LINK_SCTV12  	    "http://112.197.2.16:1935/live/SDsctv12.stream/playlist.m3u8"
#define LINK_SCTV13  	    "http://112.197.2.16:1935/live/SDsctv13.stream/playlist.m3u8"
#define LINK_SCTV14  	    "http://112.197.2.16:1935/live/SDsctv14.stream/playlist.m3u8"
#define LINK_SCTV15  	    "http://112.197.2.16:1935/live/SDsctv15.stream/playlist.m3u8"
#define LINK_SCTV16  	    "http://112.197.2.16:1935/live/SDsctv16.stream/playlist.m3u8"
#define LINK_SCTV17  	    "http://112.197.2.16:1935/live/SDsctv17.stream/playlist.m3u8"
#define LINK_SCTV18  	    "http://112.197.2.16:1935/live/SDsctv18.stream/playlist.m3u8"
#define LINK_LONG_AN  	    "http://112.197.2.16:1935/live/la34.stream/playlist.m3u8"
#define LINK_HANOI  	    "http://112.197.2.16:1935/live/hn1.stream/playlist.m3u8"
#define LINK_VINH_LONG1	    "http://112.197.2.11:1935/live/thvl1.stream/playlist.m3u8"
#define LINK_VINH_LONG2	    "http://player.longtailvideo.com/player.swf?streamer=rtmp://123.30.108.77/live/THVL2/&file=THVL2&autostart=true"
#define LINK_HAU_GIANG	    "http://112.197.2.16:1935/live/thhg.stream/playlist.m3u8"
#define LINK_SOC_TRANG	    "http://112.197.2.16:1935/live/thst.stream/playlist.m3u8"
#define LINK_DONG_THAP	    "http://112.197.2.16:1935/live/thdt.stream/playlist.m3u8"
#define LINK_QUANG_NAM	    "http://112.197.2.16:1935/live/qrt.stream/playlist.m3u8"
#define LINK_BINH_THUAN	    "http://112.197.2.16:1935/live/bthtv.stream/playlist.m3u8"
#define LINK_ANTV	    "http://112.197.2.16:1935/live/antv.stream/playlist.m3u8"
#define LINK_DONG_NAI1	    "http://112.197.2.16:1935/live/dn1.stream/playlist.m3u8"
#define LINK_DONG_NAI2	    "http://player.longtailvideo.com/player.swf?streamer=rtmp://123.30.107.3:1935/live/dn2/&file=livestream&autostart=true"
#define LINK_CANTHO1	    "rtmp://113.161.204.167/live/livestream"
#define LINK_CANTHO2	    "rtmp://113.161.204.168/live/livestream"
#define LINK_DANANGTV	    "rtmp://222.255.167.149/live/livestream"
#define LINK_TRT1_HUE	    "rtmp://118.69.176.149/live/trt"
#define LINK_TTXVN	    "rtmp://live.vnanet.vn/Live/DRC"
#define LINK_LIFETVa	    "rtmp://video.lifetv.vn/live/Stream1"
#define LINK_LIFETVb	    "http://118.69.198.230:1935/live/Lifetv.stream/playlist.m3u8"
#define LINK_BINH_DUONG1    "rtmp://202.43.109.147/live/btv1.stream/playlist.m3u8"
#define LINK_BINH_DUONG2    "rtmp://202.43.109.147/rtplive/btv2.stream/playlist.m3u8"
#define LINK_DAKLAK	    "mms://118.69.161.10/Push"
#define LINK_AN_GIANG	    "rtmp://113.161.212.25/live/atv1"
#define LINK_TIEN_GIANG	    "mms://118.69.201.97/rtv"
#define LINK_BAC_LIEU	    "rtmp://113.161.218.10/live/BTV.test"
#define LINK_CAN_THO	    "rtmp://tv.canthotv.vn/live/thct.tv"
#define LINK_THAI_NGUYEN    "rtmp://123.30.84.242/live/tntv"
#define LINK_PHU_THO	    "rtmp://210.211.99.74/live/livestream"
#define LINK_VINH_PHUC	    "rtmp://210.245.87.165/live/thvp"

class PluginViet : public PluginEntry{
    public:
	PluginViet();
	~PluginViet()  {}

	virtual const char* title() { return "Vietnamese live TV"; }

	virtual bool input(const SDL_Event& event);
	void pressReturn();

    private:
	inline void addLabelLink(const char* label, const char* url);
	void addAll();
};

#endif
