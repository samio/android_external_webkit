#ifndef ARABICSHAPING_H
#define ARABICSHAPING_H


#include "config.h"

#include "RenderObject.h"

#include "unicode/ushape.h"

//#include "platform/graphics/Debugs.h"

namespace WebCore {

class InlineTextBox;
class StringImpl;

class ArabicShapingUtils
{
public:
    static RefPtr<StringImpl> shape (RefPtr<StringImpl> txt);
    static void printUniStr(char *msg, const UChar* s, int len);
};

}

#endif
