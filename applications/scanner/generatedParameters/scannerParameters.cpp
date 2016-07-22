/**
 * \file scannerParameters.cpp
 * \attention This file is automatically generated and should not be in general modified manually
 *
 * \date MMM DD, 20YY
 * \author autoGenerator
 */

#include <vector>
#include <stddef.h>
#include "scannerParameters.h"

/**
 *  Looks extremely unsafe because it depends on the order of static initialization.
 *  Should check standard if this is ok
 *
 *  Also it's not clear why removing "= Reflection()" breaks the code;
 **/

namespace corecvs {
template<>
Reflection BaseReflection<ScannerParameters>::reflection = Reflection();
template<>
int BaseReflection<ScannerParameters>::dummy = ScannerParameters::staticInit();
} // namespace corecvs 

SUPPRESS_OFFSET_WARNING_BEGIN

int ScannerParameters::staticInit()
{

    ReflectionNaming &nameing = naming();
    nameing = ReflectionNaming(
        "Scanner Parameters",
        "Scanner parameters",
        ""
    );
     

    fields().push_back(
        new EnumField
        (
          ScannerParameters::CHANNEL_ID,
          offsetof(ScannerParameters, mChannel),
          0,
          "channel",
          "channel",
          "channel",
          new EnumReflection(15
          , new EnumOption(0,"R")
          , new EnumOption(1,"G")
          , new EnumOption(2,"B")
          , new EnumOption(3,"Alpha")
          , new EnumOption(4,"Y")
          , new EnumOption(5,"Cr")
          , new EnumOption(6,"Cb")
          , new EnumOption(7,"U")
          , new EnumOption(8,"V")
          , new EnumOption(9,"Chroma")
          , new EnumOption(10,"Gray")
          , new EnumOption(11,"Luma")
          , new EnumOption(12,"Hue")
          , new EnumOption(13,"Saturation")
          , new EnumOption(14,"Value")
          )
        )
    );
    fields().push_back(
        new EnumField
        (
          ScannerParameters::ALGO_ID,
          offsetof(ScannerParameters, mAlgo),
          0,
          "algo",
          "algo",
          "algo",
          new EnumReflection(3
          , new EnumOption(0,"Brightness")
          , new EnumOption(1,"Hue")
          , new EnumOption(2,"Dummy")
          )
        )
    );
    fields().push_back(
        new IntField
        (
          ScannerParameters::RED_THRESHOLD_ID,
          offsetof(ScannerParameters, mRedThreshold),
          200,
          "red threshold",
          "red threshold",
          "red threshold",
          true,
         0,
         255
        )
    );
    fields().push_back(
        new DoubleField
        (
          ScannerParameters::HEIGHT_ID,
          offsetof(ScannerParameters, mHeight),
          10,
          "height",
          "height",
          "height"
        )
    );
    fields().push_back(
        new IntField
        (
          ScannerParameters::GRAPH_LINE_ID,
          offsetof(ScannerParameters, mGraphLine),
          960,
          "Graph line",
          "Graph line",
          "Graph line",
          true,
         0,
         1920
        )
    );
    fields().push_back(
        new BoolField
        (
          ScannerParameters::USE_SSE_ID,
          offsetof(ScannerParameters, mUseSSE),
          true,
          "Use SSE",
          "Use SSE",
          "Use SSE"
        )
    );
    fields().push_back(
        new BoolField
        (
          ScannerParameters::CALCULATE_CONVOLUTION_ID,
          offsetof(ScannerParameters, mCalculateConvolution),
          true,
          "Calculate convolution",
          "Calculate convolution",
          "Calculate convolution"
        )
    );
    fields().push_back(
        new BoolField
        (
          ScannerParameters::CALIBRATIONMODE_ID,
          offsetof(ScannerParameters, mCalibrationMode),
          false,
          "CalibrationMode",
          "CalibrationMode",
          "CalibrationMode"
        )
    );
    fields().push_back(
        new DoubleField
        (
          ScannerParameters::CORNER_SCORE_ID,
          offsetof(ScannerParameters, mCornerScore),
          0.05,
          "Corner Score",
          "Corner Score",
          "Corner Score",
          true,
         0,
         255
        )
    );
    fields().push_back(
        new IntField
        (
          ScannerParameters::HARRIS_APPERTURE_ID,
          offsetof(ScannerParameters, mHarrisApperture),
          5,
          "Harris Apperture",
          "Harris Apperture",
          "Harris Apperture",
          true,
         0,
         255
        )
    );
   return 0;
}

SUPPRESS_OFFSET_WARNING_END


