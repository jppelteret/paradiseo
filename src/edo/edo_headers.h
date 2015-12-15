/*
The Evolving Distribution Objects framework (EDO) is a template-based,
ANSI-C++ evolutionary computation library which helps you to write your
own estimation of distribution algorithms.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

Copyright (C) 2010 Thales group
*/
/*
Authors:
    Johann Dréo <johann.dreo@thalesgroup.com>
    Caner Candan <caner.candan@thalesgroup.com>
*/

#ifndef _edo_
#define _edo_

#include <paradiseo/edo/edoAlgo.h>
//#include <paradiseo/edo/edoEDASA.h>
#include <paradiseo/edo/edoAlgoAdaptive.h>
#include <paradiseo/edo/edoAlgoStateless.h>

#include <paradiseo/edo/edoDistrib.h>
#include <paradiseo/edo/edoUniform.h>
#include <paradiseo/edo/edoNormalMono.h>
#include <paradiseo/edo/edoNormalMulti.h>
#include <paradiseo/edo/edoNormalAdaptive.h>
#include <paradiseo/edo/edoBinomial.h>
#include <paradiseo/edo/edoBinomialMulti.h>

#include <paradiseo/edo/edoEstimator.h>
#include <paradiseo/edo/edoEstimatorUniform.h>
#include <paradiseo/edo/edoEstimatorNormalMono.h>
#include <paradiseo/edo/edoEstimatorNormalMulti.h>
#include <paradiseo/edo/edoEstimatorAdaptive.h>
#include <paradiseo/edo/edoEstimatorNormalAdaptive.h>
#include <paradiseo/edo/edoEstimatorBinomial.h>
#include <paradiseo/edo/edoEstimatorBinomialMulti.h>

#include <paradiseo/edo/edoModifier.h>
#include <paradiseo/edo/edoModifierDispersion.h>
#include <paradiseo/edo/edoModifierMass.h>
#include <paradiseo/edo/edoUniformCenter.h>
#include <paradiseo/edo/edoNormalMonoCenter.h>
#include <paradiseo/edo/edoNormalMultiCenter.h>

#include <paradiseo/edo/edoSampler.h>
#include <paradiseo/edo/edoSamplerUniform.h>
#include <paradiseo/edo/edoSamplerNormalMono.h>
#include <paradiseo/edo/edoSamplerNormalMulti.h>
#include <paradiseo/edo/edoSamplerNormalAdaptive.h>
#include <paradiseo/edo/edoSamplerBinomial.h>
#include <paradiseo/edo/edoSamplerBinomialMulti.h>

#include <paradiseo/edo/edoVectorBounds.h>

#include <paradiseo/edo/edoRepairer.h>
#include <paradiseo/edo/edoRepairerDispatcher.h>
#include <paradiseo/edo/edoRepairerRound.h>
#include <paradiseo/edo/edoRepairerModulo.h>
#include <paradiseo/edo/edoBounder.h>
#include <paradiseo/edo/edoBounderNo.h>
#include <paradiseo/edo/edoBounderBound.h>
#include <paradiseo/edo/edoBounderRng.h>
#include <paradiseo/edo/edoBounderUniform.h>

#include <paradiseo/edo/edoContinue.h>
#include <paradiseo/edo/utils/edoCheckPoint.h>

#include <paradiseo/edo/utils/edoStat.h>
#include <paradiseo/edo/utils/edoStatUniform.h>
#include <paradiseo/edo/utils/edoStatNormalMono.h>
#include <paradiseo/edo/utils/edoStatNormalMulti.h>

#include <paradiseo/edo/utils/edoFileSnapshot.h>
#include <paradiseo/edo/utils/edoPopStat.h>

#include <paradiseo/edo/edoTransform.h>

#endif // !_edo_

// Local Variables:
// mode: C++
// End:
