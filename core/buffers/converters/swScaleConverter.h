#ifndef SWSCALECONVERTER_H
#define SWSCALECONVERTER_H

#include "core/buffers/rgb24/rgb24Buffer.h"
#include "core/buffers/g12Buffer.h"
#include "core/buffers/g8Buffer.h"


class SWScaleConverter
{
public:
    SWScaleConverter();

template<typename InputBufferType, typename OutputBufferType>
    static OutputBufferType *convert(InputBufferType *input, float swScaleSrcFormatId, float swScaleDstFormatId);

private:

template<typename InputBufferType, typename OutputBufferType>
    static OutputBufferType *convert(InputBufferType *input, int swScaleSrcFormatId, int swScaleDstFormatId);

};
#endif // SWSCALECONVERTER_H
