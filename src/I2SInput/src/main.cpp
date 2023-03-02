#include <Arduino.h>
#include "AudioTools.h"
#include "AudioLibs/AudioRealFFT.h" // or AudioKissFFT
// #include "AudioLibs/AudioESP32FFT.h" // Using ESP32FFT

// FFT documentation : https://github.com/pschatzmann/arduino-audio-tools/wiki/FFT

int channels = 2;
int samples_per_second = 44100;
int bits_per_sample = 16;
float value=0;

I2SStream i2sStream; // Access I2S as stream
FilteredStream<int16_t, float> filtered(i2sStream, channels);  // Defiles the filter as BaseConverter
AudioRealFFT fft; // or AudioKissFFT
// AudioESP32FFT fft; // or AudioKissFFT
StreamCopy copier(fft, filtered);  // copy mic to tfl

// define FIR filter parameters
float coef[] = { 0.021, 0.096, 0.146, 0.096, 0.021};

// display fft result
void fftResult(AudioFFTBase &fft){
    float diff;
    auto result = fft.result();
    if (result.magnitude>100){
        Serial.print(result.frequency);
        Serial.print(" ");
        Serial.print(result.magnitude);  
        Serial.print(" => ");
        Serial.print(result.frequencyAsNote(diff));
        Serial.print( " diff: ");
        Serial.println(diff);
    }
}


void setup(void) {
    Serial.begin(115200);
    // AudioLogger::instance().begin(Serial, AudioLogger::Info);
    AudioLogger::instance().begin(Serial, AudioLogger::Warning);

    // setup filters for all available channels
    filtered.setFilter(0, new FIR<float>(coef));
    
    auto cfg = i2sStream.defaultConfig(RX_MODE);
    cfg.i2s_format = I2S_STD_FORMAT; // or try with I2S_LSB_FORMAT
    cfg.bits_per_sample = bits_per_sample;
    cfg.channels = channels;
    cfg.sample_rate = samples_per_second;
    cfg.is_master = true;
     // this module nees a master clock if the ESP32 is master
    cfg.use_apll = false;  // try with yes
    cfg.pin_mck = 3; 
    i2sStream.begin(cfg);

    // Setup FFT
    auto tcfg = fft.defaultConfig();
    tcfg.length = 8192;
    tcfg.channels = channels;
    tcfg.sample_rate = samples_per_second;
    tcfg.bits_per_sample = bits_per_sample;
    tcfg.callback = &fftResult;
    fft.begin(tcfg);

}

// Arduino loop - copy data
void loop() {
    copier.copy();
}