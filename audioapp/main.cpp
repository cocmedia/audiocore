#include <iostream>
#include "audioeffect.hpp"
#include "eq.hpp"

using namespace std;

namespace ac {

extern void audioEffectRegister();

AudioEffect *createAudioEQ()
{
    EffectClass *pEffectClass;
    AudioEffect *pEffect = NULL;

    pEffectClass = EffectClass::FindEffectClass("AudioEQ");
    if(pEffectClass)
    {
        pEffect = pEffectClass->CreateEffect();

    }

    return pEffect;
}
}

int main()
{
    cout << "Hello world!"<< endl;
    ac::audioEffectRegister();
    ac::createAudioEQ();
    return 0;
}
