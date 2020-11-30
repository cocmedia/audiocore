#include "audioeffect.hpp"

namespace ac {


//dynamic create
EffectClass *EffectClass::gpFirstEffectClass = NULL;
EffectClass AudioEffect::classAudioEffect = {
    "AudioEffect",
    sizeof(AudioEffect),
    NULL, // can't create AudioEffect. Only can be created in child class.
    NULL, // no base class anymore.
    NULL, // Next effect class = NULL
};

static int classNameCmp(const char *first, const char *second)
{
    int ret = -1;
    int index = 0;
    if(first && second){
        while(first[index] && second[index])
        {
            if(first[index] != second[index])
            {
                break;
            }
            index++;
        }
        ret = (first[index] - second[index]);
    }
    return ret;
}

AudioEffect* EffectClass::CreateEffect()
{
	if (mpfnCreateEffect == NULL)
	{
		//cout<<"Error: Trying to create object which is not "<<endl;

	}

	AudioEffect* pAudioEffect = NULL;
	pAudioEffect = (*mpfnCreateEffect)();

	return pAudioEffect;
}

EffectClass* EffectClass::FindEffectClass(const char* className)
{
	EffectClass* pClass;

	for (pClass = gpFirstEffectClass; pClass != NULL; pClass = pClass->mpNextEffectClass)
	{
		if (classNameCmp(className, pClass->mEffectClassName) == 0)
			return pClass;
	}

	//cout<<"Error: Class not found: "<<className<<endl;
	return NULL;
}

// update the list of effect class
void EffectClass::effectClassInit(EffectClass *pEffectClass)
{
    pEffectClass->mpNextEffectClass = EffectClass::gpFirstEffectClass;
    EffectClass::gpFirstEffectClass = pEffectClass;
}

AudioEffect::AudioEffect()
{

}

AudioEffect::~AudioEffect()
{

}

EffectClass *AudioEffect::getEffectClass() const
{
    return &AudioEffect::classAudioEffect;
}


}
