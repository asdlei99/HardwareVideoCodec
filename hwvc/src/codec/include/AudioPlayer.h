/*
* Copyright (c) 2018-present, lmyooyo@gmail.com.
*
* This source code is licensed under the GPL license found in the
* LICENSE file in the root directory of this source tree.
*/
#ifndef HARDWAREVIDEOCODEC_AUDIOPLAYER_H
#define HARDWAREVIDEOCODEC_AUDIOPLAYER_H

#include <string>
#include <SLES/OpenSLES.h>
#include <SLES/OpenSLES_Android.h>
#include <Object.h>
#include "RecyclerBlockQueue.h"

using namespace std;

class AudioPlayer : public Object {
public:
    AudioPlayer(int channels, int sampleHz, int minBufferSize);

    virtual ~AudioPlayer();

    virtual int start();

    virtual void stop();

    virtual int write(uint8_t *buffer, size_t size);

    string getString();

    void bufferEnqueue(SLBufferQueueItf slBufferQueueItf);

private:
    unsigned int channels = 0;
    unsigned int sampleHz = 0;
    int minBufferSize = 0;
    uint8_t *buffer = nullptr;
    RecyclerBlockQueue<uint8_t *> *recycler = nullptr;
    SLObjectItf engineObject = nullptr;
    SLEngineItf engineItf = nullptr;
    SLObjectItf mixObject = nullptr;
    SLObjectItf playObject = nullptr;
    SLPlayItf playItf = nullptr;
    SLBufferQueueItf bufferQueueItf = nullptr;

    int createEngine();

    void destroyEngine();

    int createBufferQueueAudioPlayer();
};


#endif //HARDWAREVIDEOCODEC_AUDIOPLAYER_H
