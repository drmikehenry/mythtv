#ifndef MPEGRECORDER_H_
#define MPEGRECORDER_H_

#include "recorderbase.h"

struct AVFormatContext;
struct AVPacket;

class MpegRecorder : public RecorderBase
{
  public:
    MpegRecorder();
   ~MpegRecorder();

    void SetOption(const QString &opt, int value);
    void SetOption(const QString &name, const QString &value);
    void SetVideoFilters(QString &filters);

    void SetOptionsFromProfile(RecordingProfile *profile,
                               const QString &videodev, 
                               const QString &audiodev,
                               const QString &vbidev, int ispip);

    void Initialize(void);
    void StartRecording(void);
    void StopRecording(void);
    void Reset(void);

    void Pause(bool clear = true);
    void Unpause(void);
    bool GetPause(void);
    void WaitForPause(void);
    bool IsRecording(void);
    bool IsErrored(void) { return false; }

    long long GetFramesWritten(void);

    int GetVideoFd(void);

    long long GetKeyframePosition(long long desired);
    void GetBlankFrameMap(QMap<long long, int> &blank_frame_map);

  private:
    bool SetupRecording();
    void FinishRecording();

    bool PacketHasHeader(unsigned char *buf, int len, unsigned int startcode);
    void ProcessData(unsigned char *buffer, int len);

    bool recording;
    bool encoding;

    bool paused;
    bool mainpaused;
    bool cleartimeonpause;

    long long framesWritten;

    int width, height;
    int bitrate, maxbitrate, streamtype, aspectratio;
    int audtype, audsamplerate, audbitratel1, audbitratel2;
    int audvolume;

    int chanfd;
    int readfd;

    AVFormatContext *ic;

    int keyframedist;
    bool gopset;

    QMap<long long, long long> positionMap;

    long long prev_gop_save_pos;
    static const int audRateL1[];
    static const int audRateL2[];
    static const char* streamType[];
    static const char* aspectRatio[];
};
#endif
