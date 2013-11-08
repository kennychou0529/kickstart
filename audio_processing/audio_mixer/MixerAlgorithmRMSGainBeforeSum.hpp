#ifndef MIXERALGORITHMRMSGAINBEFORESUM_HPP
#define MIXERALGORITHMRMSGAINBEFORESUM_HPP

#include "MixerAlgorithm.hpp"
#include "MixerAlgorithmDataElement.hpp"
#include "RMSCalculator.hpp"


#define __NR_OF_SAMPLES_PER_CHUNK 1

// 16000 samples per second @ 16khz sampling rate
// 1ms ~ 16 samples - 64ms ~ 1024 samples
#define __NR_OF_INPUT_SIGNAL_RMSCALCULATOR_BUFFER_SIZE_IN_SAMPLES  1024


#define FIXME_FIXME_FIXME_MAX_NR_OF_CHANNELS 24


/**
 * @brief implementation of mixer that gains a signal depending on the RMS value before the sum
 *
 */
class MixerAlgorithmRMSGainBeforeSum : public MixerAlgorithm
{

public:
    MixerAlgorithmRMSGainBeforeSum(std::string& algorithmName);
    virtual void mixSamples(int16_t** const inputSampleBufferArray, const uint32_t nrOfStreams, int16_t* const outputSampleBuffer);
    virtual MixerAlgorithmDataElement& getMixerAlgorithmDataElementPrototype(void) {return m_mixerAlgorithmDataElement;};

private:
    MixerAlgorithmDataElement m_mixerAlgorithmDataElement;
    RMSCalculator<int16_t, __NR_OF_INPUT_SIGNAL_RMSCALCULATOR_BUFFER_SIZE_IN_SAMPLES> m_inputSignalRMSCalculatorArray[FIXME_FIXME_FIXME_MAX_NR_OF_CHANNELS];
};

#endif