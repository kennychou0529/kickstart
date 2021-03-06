#ifndef MIXERALGORITHMRMSGAINAFTERSUM_HPP
#define MIXERALGORITHMRMSGAINAFTERSUM_HPP


#include "MixerAlgorithm.hpp"
#include "RMSCalculator.hpp"



class MixerAlgorithmRMSGainAfterSum : public MixerAlgorithm
{
public:
    MixerAlgorithmRMSGainAfterSum(std::string& algorithmName);
    virtual void mixSamples(int16_t** const inputSampleBufferArray, const uint32_t nrOfStreams, int16_t* const outputSampleBuffer);
    virtual void printAlgorithmConfiguration(void) const;
    virtual inline const MixerAlgorithmDataElement& getMixerAlgorithmDataElementPrototype(void) {return s_mixerAlgorithmDataElement;};

private:
    MixerAlgorithmRMSGainAfterSum(const MixerAlgorithmRMSGainAfterSum&);
    MixerAlgorithmRMSGainAfterSum& operator=(const MixerAlgorithmRMSGainAfterSum&);

private:
    static const uint32_t s_nrOfSamplesPerChunk = 1;
    static const MixerAlgorithmDataElement s_mixerAlgorithmDataElement;

    // 16000 samples per second @ 16khz sampling rate
    // 1ms ~ 16 samples - 64ms ~ 1024 samples
    // 1ms ~ 16 samples - 8ms ~ 128 samples
    static const uint32_t s_outputSignalRMSCalculatorBufferSizeInSample = 1024;
    static const float s_staticOutputSampleGainFactor = 0.3;
    RMSCalculator<int32_t, s_outputSignalRMSCalculatorBufferSizeInSample> m_outputSignalRMSCalculator;
};


#endif