######################################################################
# Automatically generated by qmake (1.02a) Tue Jul 16 20:40:47 2002
######################################################################

TEMPLATE = lib
TARGET = mythtv
CONFIG += thread staticlib 

include ( ../../settings.pro )

INCLUDEPATH += ../libmyth ../  ../libavcodec ../libavformat ../libdvbdev
DEPENDPATH += ../libmyth ../libvbitext ../libavcodec ../libavformat ../libdvbdev

QMAKE_CXXFLAGS_RELEASE += `freetype-config --cflags`
QMAKE_CXXFLAGS_DEBUG += `freetype-config --cflags`

# Input
HEADERS += channel.h commercial_skip.h filter.h format.h frame.h frequencies.h 
HEADERS += guidegrid.h infodialog.h infostructs.h jitterometer.h lzoconf.h 
HEADERS += minilzo.h mmx.h NuppelVideoPlayer.h NuppelVideoRecorder.h osd.h 
HEADERS += osdtypes.h programinfo.h recordingprofile.h remoteencoder.h
HEADERS += remoteutil.h RingBuffer.h RTjpegN.h scheduledrecording.h
HEADERS += ttfont.h tv_play.h tv_rec.h videosource.h XJ.h yuv2rgb.h
HEADERS += progfind.h decoderbase.h nuppeldecoder.h avformatdecoder.h
HEADERS += recorderbase.h mpegrecorder.h channelbase.h dvbrecorder.h
HEADERS += dvbchannel.h vsync.h proglist.h

SOURCES += channel.cpp commercial_skip.cpp filter.c frequencies.c guidegrid.cpp
SOURCES += infodialog.cpp infostructs.cpp jitterometer.cpp minilzo.cpp 
SOURCES += NuppelVideoPlayer.cpp NuppelVideoRecorder.cpp osd.cpp
SOURCES += osdtypes.cpp programinfo.cpp recordingprofile.cpp remoteencoder.cpp
SOURCES += remoteutil.cpp RingBuffer.cpp RTjpegN.cpp scheduledrecording.cpp
SOURCES += ttfont.cpp tv_play.cpp tv_rec.cpp videosource.cpp XJ.cpp yuv2rgb.cpp
SOURCES += progfind.cpp nuppeldecoder.cpp avformatdecoder.cpp recorderbase.cpp
SOURCES += mpegrecorder.cpp channelbase.cpp dvbrecorder.cpp dvbchannel.cpp
SOURCES += vsync.c proglist.cpp
