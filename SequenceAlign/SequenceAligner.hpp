#ifndef _SEQUENCE_ALIGNER_HPP_
#define _SEQUENCE_ALIGNER_HPP_

#include <string>

int sequenceAlign(const std::string &X, const std::string &Y,
		  int gapPenalty, int mismatchPenalty);

#endif
