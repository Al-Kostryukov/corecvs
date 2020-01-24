#include "core/buffers/converters/converterFactory.h"
#include "core/buffers/converters/converters.h"

//#if __cplusplus > 199711L
#if defined(WIN32) && (_MSC_VER < 1900) // we need a threadsafety singleton initialization described in paragraph 6.7.4 of the C++11 standard, msvc2013 doesn't support it fully... Don't care about gcc-versions
#include <mutex>
#include <atomic>
static std::mutex mtx;
std::atomic<corecvs::ConverterFactory *> instance(nullptr);
#endif

namespace corecvs {

ConverterFactory* ConverterFactory::getInstance()
{
#if defined(WIN32) && (_MSC_VER < 1900) // we need a threadsafety singleton initialization
    auto *p = instance.load(std::memory_order_acquire);
    if (!p)
    {
        std::lock_guard<std::mutex> lck(mtx);
        p = instance.load(std::memory_order_relaxed);
        if (!p)
        {
            p = new ConverterFactory;
            instance.store(p, std::memory_order_release);
        }
    }
    return p;
#else
    static ConverterFactory instance;
    return &instance;
#endif
}

ConverterFactory::ConverterFactory()
{
    registerConverter(FormatType::RGB, FormatType::G8, new RGBtoG8BufferConverter());
    registerConverter(FormatType::RGB, FormatType::G12, new RGBtoG12BufferConverter());
    // registerConverter(FormatType::G8, FormatType::RGB, new swscaleG8toRGBBufferConverter());


//    switch (srcBufferType) {
//        case BufferType::G8:
//            switch (dstBufferType) {
//                case BufferType::G12:
//                    return new swscaleG8toG12BufferConverter();
//                    break;
//                case BufferType::RGB:
//                    return new swscaleG8toRGBBufferConverter();
//                    break;
//                default:
//                    return null;
//                    break;
//            }
//            break;
//        case BufferType::G12:
//            switch (dstBufferType) {
//                case BufferType::G8:
//                    return new swscaleG12toG8BufferConverter();
//                    break;
//                case BufferType::RGB:
//                    return new swscaleG8toRGBBufferConverter();
//                    break;
//                default:
//                    return null;
//                    break;
//            }
//            break;
//        case BufferType::RGB:
//            switch (dstBufferType) {
//                case BufferType::G8:
//                    return new swscaleRGBtoG8BufferConverter();
//                    break;
//                case BufferType::G12:
//                    return new swscaleRGBtoG12BufferConverter();
//                    break;
//                default:
//                    return null;
//                    break;
//            }
//            break;
//        default:
//            return null;
//            break;
//    }
//#else
    // return null;
//#endif
}

ConverterFactory::~ConverterFactory()
{
    // delete all registered converters

//    for (auto it : mLoadersG12) { delete_safe(it); }
//    mLoadersG12.clear();

//    for (auto it : mLoadersG16) { delete_safe(it); }
//    mLoadersG16.clear();

//    for (auto it : mLoadersRGB24) { delete_safe(it); }
//    mLoadersRGB24.clear();

//    for (auto it : mLoadersRuntime) { delete_safe(it); }
//    mLoadersRuntime.clear();

//    for (auto it : mSaversRGB24) { delete_safe(it); }
//    mSaversRGB24.clear();

    //printf("ConverterFactory has been destroyed.\n");
}

} //namespace corecvs
