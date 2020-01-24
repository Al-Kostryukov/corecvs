/**
 * \file    buffers/converters/converterFactory.h
 *
 * \author al-kostryukov
 * \date 28 Dec 2019
 *
 * Declares ConverterFactory class.
 */
#ifndef CONVERTER_FACTORY_H
#define CONVERTER_FACTORY_H

#include <vector>
#include "converters.h"

namespace corecvs {

enum class FormatType {
    RGB,
    G8,
    G12,
    YUVV
};

/** Singleton for format converting
 */
class ConverterFactory
{
public:
    std::map<std::pair<FormatType,FormatType>, vector<VoidFormatConverter>> formatConvertersMap;
    /** Public function to get the only one instance of this object.
     *  It will be automatically destroyed on shut down.
     */
    static ConverterFactory* getInstance();

    /**
     * Public function to add new converters
     **/
    template<typename T>
    bool registerConverter(FormatType srcFormat, FormatType dstFormat, T *converter)
    {
        formatConvertersMap[std::make_pair(srcFormat, dstFormat)].push_back((VoidFormatConverter)converter);
        return true;
    }

    template<typename T>
    FormatConverter *getConverter(FormatType srcFormat, FormatType dstFormat) {
        return new FormatConverter(formatConvertersMap[std::make_pair(srcFormat, dstFormat)][0]);
    }


private:
    ConverterFactory();
    virtual ~ConverterFactory();

};
} //namespace corecvs

#endif
