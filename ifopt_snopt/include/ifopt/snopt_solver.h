/******************************************************************************
Copyright (c) 2017, Alexander W. Winkler, ETH Zurich. All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright notice,
      this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice,
      this list of conditions and the following disclaimer in the documentation
      and/or other materials provided with the distribution.
    * Neither the name of ETH ZURICH nor the names of its contributors may be
      used to endorse or promote products derived from this software without
      specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL ETH ZURICH BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
******************************************************************************/

#ifndef IFOPT_SRC_IFOPT_SNOPT_INCLUDE_IFOPT_SNOPT_H_
#define IFOPT_SRC_IFOPT_SNOPT_INCLUDE_IFOPT_SNOPT_H_

#include <ifopt/problem.h>
#include <ifopt/solver.h>
#include <string>
#include <unordered_map>

namespace ifopt {

/**
 * @brief An interface to SNOPT, fully hiding its implementation.
 *
 * @ingroup Solvers
 */
class SnoptSolver : public Solver {
 public:
  using Ptr = std::shared_ptr<SnoptSolver>;

  /**
   * @brief Creates a snoptProblemA from @a nlp and solves it.
   * @param [in/out]  nlp  The specific problem to be used and modified.
   */
  void Solve(Problem& nlp) override;

  void SetIntParameter(const char* stropt, int opt);
  void SetRealParameter(const char* stropt, double opt);

 protected:
  std::unordered_map<std::string, int> intParameters;
  std::unordered_map<std::string, double> realParameters;
};

} /* namespace ifopt */

#endif /* IFOPT_SRC_IFOPT_SNOPT_INCLUDE_IFOPT_SNOPT_H_ */
