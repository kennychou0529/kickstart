#ifndef MIXERALGORITHMSIMPLEADDWITHNORMALIZATION_HPP
#define MIXERALGORITHMSIMPLEADDWITHNORMALIZATION_HPP


#include "MixerAlgorithm.hpp"
#include "MixerAlgorithmDataElement.hpp"


class MixerAlgorithmSimpleAddWithNormalization : public MixerAlgorithm
{

public:
    MixerAlgorithmSimpleAddWithNormalization(std::string& algorithmName)
        : MixerAlgorithm(algorithmName) {}
    virtual void mixSamples(int16_t** const inputSampleBufferArray, const uint32_t nrOfStreams, int16_t* const outputSampleBuffer);
    virtual void printAlgorithmConfiguration(void) const;
    virtual inline const MixerAlgorithmDataElement& getMixerAlgorithmDataElementPrototype(void) {return s_mixerAlgorithmDataElement;};

private:
    MixerAlgorithmSimpleAddWithNormalization(const MixerAlgorithmSimpleAddWithNormalization&);
    MixerAlgorithmSimpleAddWithNormalization& operator=(const MixerAlgorithmSimpleAddWithNormalization&);

private:
    static const MixerAlgorithmDataElement s_mixerAlgorithmDataElement;
    static const uint32_t s_nrOfSamplesPerChunk = 1;
};


#endif