
#ifndef EQ_HPP
#define EQ_HPP

namespace ac {
class AudioEQ : public AudioEffect
{
public:
    AudioEQ();
    virtual ~AudioEQ();

    AUDIOEFFECT_DYNCREATE(AudioEQ)

};

}

#endif // EQ_HPP
