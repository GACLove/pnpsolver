// Copyright (c) 2021, ZJU and SenseTime 
// All rights reserved. 
// 
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions are met: 
// 
//  * Redistributions of source code must retain the above copyright notice, 
//    this list of conditions and the following disclaimer. 
//
//  * Redistributions in binary form must reproduce the above copyright 
//    notice, this list of conditions and the following disclaimer in the 
//    documentation and/or other materials provided with the distribution. 
//
//  * Neither the name of ZJU and SenseTime nor the names of its contributors 
//    may be used to endorse or promote products derived from this software 
//    without specific prior written permission. 
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE 
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
// POSSIBILITY OF SUCH DAMAGE. 
//
// Author: Hailin Yu

#include "weighted_sampler.h"

#include <numeric>

#include "util/random.h"
#include "util/misc.h"

namespace colmap {

WeigthedRandomSampler::WeigthedRandomSampler(const size_t num_samples)
        : num_samples_(num_samples){}

void WeigthedRandomSampler::Initialize(const size_t total_num_samples) {
    // pass
}

void WeigthedRandomSampler::SetPriors(const std::vector<double> &prob) {
    priors_.assign(prob.begin(), prob.end());
}

size_t WeigthedRandomSampler::MaxNumSamples() {
    return std::numeric_limits<size_t>::max();
}

std::vector<size_t> WeigthedRandomSampler::Sample() {
    return WeightedRandomSample(priors_, num_samples_);
}

} // namespace colmap