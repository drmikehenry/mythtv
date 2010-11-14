#ifndef MYTHSYSTEM_H_
#define MYTHSYSTEM_H_

#include <QString>
#include <QStringList>
#include <QBuffer>
#include <QMutex>
#include <QMap>
#include <QThread>
#include <unistd.h>  // for pid_t

#include "mythexp.h"

typedef enum MythSystemMask {
    kMSNone                     = 0x00000000,
    kMSDontBlockInputDevs       = 0x00000001, //< avoid blocking LIRC & Joystick Menu
    kMSDontDisableDrawing       = 0x00000002, //< avoid disabling UI drawing
    kMSRunBackground            = 0x00000004, //< run child in the background
    kMSProcessEvents            = 0x00000008, //< process events while waiting
    kMSInUi                     = 0x00000010, //< the parent is in the UI
    kMSStdIn                    = 0x00000011, //< allow access to stdin
    kMSStdOut                   = 0x00000012, //< allow access to stdout
    kMSStdErr                   = 0x00000014, //< allow access to stderr
    kMSBuffered                 = 0x00000018, //< buffer the IO channels
    kMSRunShell                 = 0x00000020, //< run process through bourne shell
} MythSystemFlag;

class MythSystem;

typedef QMap<pid_t, MythSystem *> MSMap_t;

class MythSystemManager : public QThread
{
    public:
        void run(void);
        void append(MythSystem *);
    private:
        MSMap_t  m_pMap;
        QMutex   m_mapLock;
};

class MPUBLIC MythSystem : public QObject
{
    public:
        MythSystem(const QString &, uint);
        MythSystem(const QString &, const QStringList &, uint);
        MythSystem(const MythSystem &other);
        ~MythSystem(void);

        void Run(time_t);
        uint Wait(time_t);

        ssize_t Write(const QByteArray*);
        QByteArray *Read(int size);
        QByteArray *ReadErr(int size);
        QByteArray *ReadAll() const;
        QByteArray *ReadAllErr() const;

        void Term(bool);
        void Kill() const;
        void Stop() const;
        void Cont() const;
        void HangUp() const;
        void USR1() const;
        void USR2() const;
        bool isBackground() const;

        friend class MythSystemManager;

    private:
        void ProcessFlags(uint);
        void HandlePreRun();
        void HandlePostRun();
        void Fork();
        QByteArray *_read(int, int);
        QByteArray *_readall(int) const;

        uint   m_status;
        pid_t  m_pid;
        QMutex m_pmutex;
        time_t m_timeout;

        QString     m_command;
        QStringList m_args;

        int     m_stdpipe[3]; // should there be a means of hitting these directly?
        QBuffer m_stdbuff[2]; // do these need to be allocated?

        // move to a struct to keep things clean?
        // perhaps allow overloaded input using the struct
        //   rather than the bitwise
        bool  m_runinbackground;
        bool  m_isinui;
        bool  m_blockinputdevs;
        bool  m_disabledrawing;
        bool  m_processevents;
        bool  m_usestdin;
        bool  m_usestdout;
        bool  m_usestderr;
        bool  m_bufferedio;
        bool  m_useshell;
};

MPUBLIC unsigned int myth_system(const QString &command, 
                                 uint flags = kMSNone,
                                 uint timeout = 0);

#endif

/*
 * vim:ts=4:sw=4:ai:et:si:sts=4
 */
