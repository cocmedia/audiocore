
#include "audioeffect.hpp"
#include "eq.hpp"

namespace ac {

void audioEffectRegister()
{
    EffectClass::effectClassInit(EffectClass_Object(AudioEffect));

    EffectClass::effectClassInit(EffectClass_Object(AudioEQ));
}

}
