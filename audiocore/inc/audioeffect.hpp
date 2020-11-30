

namespace ac {

enum {
    MEM_TYPE_COMMON = 0,
    MEM_TYPE_PARAM = 1,
    MEM_TYPE_DATA = 2,
    MEM_TYPE_MAX = 3
};

enum {
    MEM_LEVEL_NORMAL = 0,
    MEM_LEVEL_FAST = 1
};

typedef char mem_type;
typedef char mem_level;

//void *(*gpMallocFunc)(size_t, mem_type, mem_level, char *effectName);
//void (*gpFreeFunc)(void *, size_t, mem_type, mem_level, char *effectName);

// overload operator new and delete
//extern void *operator new(size_t sz);
//extern void operator delete(void *p);

class AudioEffect;

struct EffectClass
{
    const char *mEffectClassName;
    unsigned int mEffectClassSize;

    AudioEffect *(*mpfnCreateEffect)();
    EffectClass *mpBaseEffectClass;
    EffectClass *mpNextEffectClass;

    AudioEffect *CreateEffect();
    // find the effect globally
    static EffectClass *FindEffectClass(const char* className);
    // first effect point to the list.
    static EffectClass *gpFirstEffectClass;
    static void effectClassInit(EffectClass *pClass);

};

// Macro for dynamic create
#define EffectClass_Object(className) (&className::class##className)
#define AUDIOEFFECT_DYNCREATE(className) \
public: \
    static EffectClass class##className; \
    static AudioEffect *CreateAudioEffect(); \
    virtual EffectClass *getEffectClass() const;

#define IMPLEMENT_DYNCREATE(className, baseClassName) \
    AudioEffect *className::CreateAudioEffect() \
        { return new className(); } \
    EffectClass className::class##className = { \
        #className, sizeof(className), className::CreateAudioEffect, \
        EffectClass_Object(baseClassName), NULL }; \
    EffectClass *className::getEffectClass() const \
    { return &className::class##className; }

    //EffectClassInit _init##className(&className::class##className);
class AudioEffect
{
public:
    AudioEffect();

    virtual ~AudioEffect();

    //void *allocParamMemory(size_t sz, mem_level level, int alignment);
    //void freeParamMemory(void *p, size_t sz, mem_level level);

public:
    // dynamic create related
    virtual EffectClass *getEffectClass() const;
    static EffectClass classAudioEffect;

private:
    const char *mDisplayName;
    int mEffectID;

};

}
