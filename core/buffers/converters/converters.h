/**
 * \file    buffers/converters/formatConverters.h
 *
 * \author al-kostryukov
 * \date 26 Dec 2020
 *
 * Declares Format Converters classes.
 */
#ifndef FORMAT_CONVERTERS_H
#define FORMAT_CONVERTERS_H

#include "core/buffers/g8Buffer.h"
#include "core/buffers/g12Buffer.h"
#include "core/buffers/rgb24/rgb24Buffer.h"

namespace corecvs {

typedef void *VoidFormatConverter;

template<typename OutputFormatType, typename InputFormatType, typename... Args>
class IFormatConverter {
public:
     virtual OutputFormatType convert(InputFormatType src, Args... args) = 0;
};

class FormatConverter // wrapper for real converter
{
private:
    VoidFormatConverter converter;
public:
    template<typename OutputFormatType, typename InputFormatType, typename... Args>
    OutputFormatType convert(InputFormatType src, Args... args) {
        auto typeCastedConverter = (IFormatConverter<OutputFormatType, InputFormatType, Args...> *)(this->convert);
        return typeCastedConverter->convert(src, std::forward<Args>(args)...);
    }

    FormatConverter(VoidFormatConverter converter) {
        this->converter = converter;
    }
};

class RGBtoG8BufferConverter : IFormatConverter<G8Buffer*, RGB24Buffer*, ImageChannel::ImageChannel>
{
public:
    G8Buffer *convert(RGB24Buffer *src, ImageChannel::ImageChannel channel) override;
};

class RGBtoG12BufferConverter : IFormatConverter<G12Buffer*, RGB24Buffer*>
{
public:
    G12Buffer *convert(RGB24Buffer *src) override;
};

}
#endif // FORMAT_CONVERTERS_H
