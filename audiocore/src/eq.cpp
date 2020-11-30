

#include <iostream>
#include "audioeffect.hpp"
#include "eq.hpp"

namespace ac {

IMPLEMENT_DYNCREATE(AudioEQ, AudioEffect)

AudioEQ eq;

AudioEQ::AudioEQ()
{
    //cout<<"AudioEQ constrct is called";
}

AudioEQ::~AudioEQ()
{
    //cout<<"AudioEQ deconstrct is called";
}


}
