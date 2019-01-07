/*
 * Copyright (c) 2018-present, lmyooyo@gmail.com.
 *
 * This source code is licensed under the GPL license found in the
 * LICENSE file in the root directory of this source tree.
 */
#ifndef HARDWAREVIDEOCODEC_ABSVIDEODECODER_H
#define HARDWAREVIDEOCODEC_ABSVIDEODECODER_H

#include "AbsDecoder.h"

class AbsVideoDecoder : public AbsDecoder {
public:
    AbsVideoDecoder();

    virtual ~AbsVideoDecoder();

    virtual bool prepare(string path)=0;

    virtual int width()=0;

    virtual int height()=0;

    virtual int getChannels()=0;

    virtual int getSampleHz()=0;
};


#endif //HARDWAREVIDEOCODEC_ABSVIDEODECODER_H
