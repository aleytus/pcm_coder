#ifndef PCMLINEGENERATOR_H
#define PCMLINEGENERATOR_H

#include "pcmline.h"

#include "samplegenerator.h"

#include "LockingQueue.h"

struct PCMLineGenerator {
  //  из присланного набора сеплов генерирует PCMLine кладет в очередь

  PCMLineGenerator(LockingQueue<PCMLine> &outputQueue);

  void input(const std::vector<SampleGenerator::o_samples_format> &samples);

  void flush();

  PCMLineGenerator &set14BitMode(bool mode14Bit = true);
  PCMLineGenerator &setGenerateP(bool generateP = true);
  PCMLineGenerator &setGenerateQ(bool generateQ = true);

private:
  std::vector<SampleGenerator::o_samples_format> overflow;
  LockingQueue<PCMLine> &outputQueue;
  bool mode14Bit, generateP, generateQ;

  void sendLine(const PCMLine &line) { outputQueue.push(line); }

  template <typename T>
  void write_sample(T &it, const SampleGenerator::o_samples_format &sample) {
    *it++ = sample.L;
    *it++ = sample.R;
  }

  template <typename T> void write_overflow(T &it) {
    for (auto &v : overflow) {
      write_sample(it, v);
    }
  }
};

#endif // PCMLINEGENERATOR_H
