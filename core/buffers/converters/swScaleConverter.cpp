#include "swScaleConverter.h"

#include "core/math/mathUtils.h"

extern "C" {
#include "libavutil/avutil.h"
#include "libswscale/swscale.h"
}

using namespace corecvs;

template<typename InputBufferType, typename OutputBufferType>
OutputBufferType *SWScaleConverter::convert(InputBufferType *input, float swScaleSrcFormatId, float swScaleDstFormatId)
{
    return convert(input, fround(swScaleSrcFormatId), fround(swScaleDstFormatId));
}

template<typename InputBufferType, typename OutputBufferType>
OutputBufferType *SWScaleConverter::convert(InputBufferType *input, int swScaleSrcFormatId, int swScaleDstFormatId)
{
    OutputBufferType *toReturn = new OutputBufferType(input->h, input->w, false);

    uint8_t *inData[1]  = { (uint8_t *)input->data    };
    uint8_t *outData[1] = { (uint8_t *)toReturn->data };

    int inStride [1] = { input->stride    * sizeof(typename InputBufferType::InternalElementType) };
    int outStride[1] = { toReturn->stride * sizeof(typename OutputBufferType::InternalElementType) };

    SwsContext *scaleContext = sws_getContext(
                input->w,
                input->h,
                (AVPixelFormat)swScaleSrcFormatId,
                input->w,
                input->h,
                (AVPixelFormat)swScaleDstFormatId,
                SWS_BILINEAR , NULL, NULL, NULL);


    sws_scale(scaleContext,
        inData,
        inStride,
        0,
        input->h,
        outData,
        outStride);

    sws_freeContext(scaleContext);

    return toReturn;
}

SWScaleConverter::SWScaleConverter()
{

}
