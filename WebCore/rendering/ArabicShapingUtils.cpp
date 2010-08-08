
#include "ArabicShapingUtils.h"

//#include "platform/graphics/Debugs.h"

//#include "unicode/ushape.h" 

using namespace std;

namespace WebCore {


RefPtr<StringImpl> ArabicShapingUtils::shape (RefPtr<StringImpl> txt)
{
    UErrorCode errorCode = U_ZERO_ERROR;
    int retVal = 0;
       
    //LOGE("TEXT: %s", txt->characters());
    
    UChar *shapedStr = new UChar[txt->length()];
    
    retVal = u_shapeArabic (txt->characters(),
                   txt->length(), 
                   shapedStr,
                   txt->length(),
                   U_SHAPE_LETTERS_SHAPE | U_SHAPE_LENGTH_FIXED_SPACES_AT_END,
                   &errorCode);
    if (retVal > 0)
    {
        txt = StringImpl::create (shapedStr, txt->length());
    }
     
    //LOGE("ERROR CODE: %d - Hex=%x - Name: %s", errorCode, errorCode, u_errorName(errorCode));
    //LOGE("String Len: %d", txt->length());
    //ArabicShapingUtils::printUniStr("After Shaping", shapedStr, txt->length());
    //LOGE("retVal = %d", retVal);
    
    
    
    delete shapedStr;
    
    return txt;
}

void ArabicShapingUtils::printUniStr(char *msg, const UChar *s, int len)
{
    char* ss = new char[len+1];
    
    for (int i = 0; i < len; i++)
        ss[i] = (char) s[i];
    
    ss[len] = '\0';
        
    //LOGE("%s: %s",msg, ss);
}

}
