/*
  <mo.h"
  Copyright (C) DOLPHIN Project-Team, INRIA Lille - Nord Europe, 2006-2010

  Sébastien Verel, Arnaud Liefooghe, Jérémie Humeau

  This software is governed by the CeCILL license under French law and
  abiding by the rules of distribution of free software.  You can  use,
  modify and/ or redistribute the software under the terms of the CeCILL
  license as circulated by CEA, CNRS and INRIA at the following URL
  "http://www.cecill.info".

  As a counterpart to the access to the source code and  rights to copy,
  modify and redistribute granted by the license, users are provided only
  with a limited warranty  and the software's author,  the holder of the
  economic rights,  and the successive licensors  have only  limited liability.

  In this respect, the user's attention is drawn to the risks associated
  with loading,  using,  modifying and/or developing or reproducing the
  software by the user in light of its specific status of free software,
  that may mean  that it is complicated to manipulate,  and  that  also
  therefore means  that it is reserved for developers  and  experienced
  professionals having in-depth computer knowledge. Users are therefore
  encouraged to load and test the software's suitability as regards their
  requirements in conditions enabling the security of their systems and/or
  data to be ensured and,  more generally, to use and operate it in the
  same conditions as regards security.
  The fact that you are presently reading this means that you have had
  knowledge of the CeCILL license and that you accept its terms.

  ParadisEO WebSite : http://paradiseo.gforge.inria.fr
  Contact: paradiseo-help@lists.gforge.inria.fr
*/

#ifndef _newmo_h
#define _newmo_h

#include "mo/acceptCrit/moAcceptanceCriterion.h"
#include "mo/acceptCrit/moAlwaysAcceptCrit.h"
#include "mo/acceptCrit/moBetterAcceptCrit.h"

#include "mo/algo/moDummyLS.h"
#include "mo/algo/moFirstImprHC.h"
#include "mo/algo/moILS.h"
#include "mo/algo/moLocalSearch.h"
#include "mo/algo/moMetropolisHasting.h"
#include "mo/algo/moNeutralHC.h"
#include "mo/algo/moRandomBestHC.h"
#include "mo/algo/moRandomNeutralWalk.h"
#include "mo/algo/moRandomSearch.h"
#include "mo/algo/moRandomWalk.h"
#include "mo/algo/moSA.h"
#include "mo/algo/moSimpleHC.h"
#include "mo/algo/moTS.h"
#include "mo/algo/moVNS.h"
#include "mo/algo/eoDummyMonOp.h"

#include "mo/comparator/moComparator.h"
#include "mo/comparator/moNeighborComparator.h"
#include "mo/comparator/moEqualNeighborComparator.h"
#include "mo/comparator/moEqualSolNeighborComparator.h"
#include "mo/comparator/moSolComparator.h"
#include "mo/comparator/moEqualSolComparator.h"
#include "mo/comparator/moSolNeighborComparator.h"

#include "mo/continuator/moAverageFitnessNeighborStat.h"
#include "mo/continuator/moBestSoFarStat.h"
#include "mo/continuator/moBestFitnessStat.h"
#include "mo/continuator/moUnsignedStat.h"
#include "mo/continuator/moValueStat.h"
#include "mo/continuator/moBooleanStat.h"
#include "mo/continuator/moCheckpoint.h"
#include "mo/continuator/moCombinedContinuator.h"
#include "mo/continuator/moContinuator.h"
#include "mo/continuator/moCounterMonitorSaver.h"
#include "mo/continuator/moCounterStat.h"
#include "mo/continuator/moDistanceStat.h"
#include "mo/continuator/moFitContinuator.h"
#include "mo/continuator/moFitnessStat.h"
#include "mo/continuator/moFullEvalContinuator.h"
#include "mo/continuator/moEvalsContinuator.h"
#include "mo/continuator/moIterContinuator.h"
#include "mo/continuator/moMaxNeighborStat.h"
#include "mo/continuator/moMinNeighborStat.h"
#include "mo/continuator/moMinusOneCounterStat.h"
#include "mo/continuator/moNbInfNeighborStat.h"
#include "mo/continuator/moNbSupNeighborStat.h"
#include "mo/continuator/moNeighborBestStat.h"
#include "mo/continuator/moNeighborEvalContinuator.h"
#include "mo/continuator/moNeighborFitnessStat.h"
#include "mo/continuator/moNeighborhoodStat.h"
#include "mo/continuator/moNeutralDegreeNeighborStat.h"
#include "mo/continuator/moSecondMomentNeighborStat.h"
#include "mo/continuator/moSizeNeighborStat.h"
#include "mo/continuator/moSolutionStat.h"
#include "mo/continuator/moStat.h"
#include "mo/continuator/moStatBase.h"
#include "mo/continuator/moStatFromStat.h"
#include "mo/continuator/moStdFitnessNeighborStat.h"
#include "mo/continuator/moTimeContinuator.h"
#include "mo/continuator/moTrueContinuator.h"
#include "mo/continuator/moVectorMonitor.h"

#include "mo/coolingSchedule/moCoolingSchedule.h"
#include "mo/coolingSchedule/moDynSpanCoolingSchedule.h"
#include "mo/coolingSchedule/moSimpleCoolingSchedule.h"
#include "mo/coolingSchedule/moDynSpanCoolingSchedule.h"

#include "mo/eval/moDummyEval.h"
#include "mo/eval/moEval.h"
#include "mo/eval/moEvalCounter.h"
#include "mo/eval/moFullEvalByCopy.h"
#include "mo/eval/moFullEvalByModif.h"
#include "mo/eval/moDoubleIncrNeighborhoodEval.h"

#include "mo/explorer/moDummyExplorer.h"
#include "mo/explorer/moFirstImprHCexplorer.h"
#include "mo/explorer/moILSexplorer.h"
#include "mo/explorer/moMetropolisHastingExplorer.h"
#include "mo/explorer/moNeighborhoodExplorer.h"
#include "mo/explorer/moNeutralHCexplorer.h"
#include "mo/explorer/moRandomBestHCexplorer.h"
#include "mo/explorer/moRandomNeutralWalkExplorer.h"
#include "mo/explorer/moRandomSearchExplorer.h"
#include "mo/explorer/moRandomWalkExplorer.h"
#include "mo/explorer/moSAexplorer.h"
#include "mo/explorer/moSimpleHCexplorer.h"
#include "mo/explorer/moTSexplorer.h"
#include "mo/explorer/moVNSexplorer.h"

#include "mo/memory/moAspiration.h"
#include "mo/memory/moBestImprAspiration.h"
#include "mo/memory/moCountMoveMemory.h"
#include "mo/memory/moDiversification.h"
#include "mo/memory/moDummyDiversification.h"
#include "mo/memory/moDummyIntensification.h"
#include "mo/memory/moDummyMemory.h"
#include "mo/memory/moIndexedVectorTabuList.h"
#include "mo/memory/moIntensification.h"
#include "mo/memory/moMemory.h"
#include "mo/memory/moMonOpDiversification.h"
#include "mo/memory/moNeighborVectorTabuList.h"
#include "mo/memory/moRndIndexedVectorTabuList.h"
#include "mo/memory/moSolVectorTabuList.h"
#include "mo/memory/moRndIndexedVectorTabuList.h"
#include "mo/memory/moTabuList.h"

#include "mo/neighborhood/moBackableNeighbor.h"
#include "mo/neighborhood/moBackwardVectorVNSelection.h"
#include "mo/neighborhood/moDummyNeighbor.h"
#include "mo/neighborhood/moDummyNeighborhood.h"
#include "mo/neighborhood/moForwardVectorVNSelection.h"
#include "mo/neighborhood/moIndexNeighbor.h"
#include "mo/neighborhood/moIndexNeighborhood.h"
#include "mo/neighborhood/moNeighbor.h"
#include "mo/neighborhood/moNeighborhood.h"
#include "mo/neighborhood/moOrderNeighborhood.h"
#include "mo/neighborhood/moRndNeighborhood.h"
#include "mo/neighborhood/moRndVectorVNSelection.h"
#include "mo/neighborhood/moRndWithoutReplNeighborhood.h"
#include "mo/neighborhood/moRndWithReplNeighborhood.h"
#include "mo/neighborhood/moVariableNeighborhoodSelection.h"
#include "mo/neighborhood/moVectorVNSelection.h"
#include "mo/neighborhood/moEvaluatedNeighborhood.h"

#include "mo/perturb/moLocalSearchInit.h"
#include "mo/perturb/moMonOpPerturb.h"
#include "mo/perturb/moNeighborhoodPerturb.h"
#include "mo/perturb/moPerturbation.h"
#include "mo/perturb/moRestartPerturb.h"
#include "mo/perturb/moSolInit.h"

#include "mo/problems/bitString/moBitNeighbor.h"
#include "mo/problems/bitString/moBitsNeighbor.h"
#include "mo/problems/bitString/moBitsNeighborhood.h"
#include "mo/problems/bitString/moBitsWithoutReplNeighborhood.h"
#include "mo/problems/bitString/moBitsWithReplNeighborhood.h"

#include "mo/problems/permutation/moIndexedSwapNeighbor.h"
#include "mo/problems/permutation/moShiftNeighbor.h"
#include "mo/problems/permutation/moSwapNeighbor.h"
#include "mo/problems/permutation/moSwapNeighborhood.h"
#include "mo/problems/permutation/moTwoOptExNeighbor.h"
#include "mo/problems/permutation/moTwoOptExNeighborhood.h"

//#include "mo/problems/eval/moMaxSATincrEval.h"
//#include "mo/problems/eval/moOneMaxIncrEval.h"
//#include "mo/problems/eval/moQAPIncrEval.h"
//#include "mo/problems/eval/moRoyalRoadIncrEval.h"
//#include "mo/problems/eval/moUBQPSimpleIncrEval.h"
//#include "mo/problems/eval/moUBQPdoubleIncrEvaluation.h"
//#include "mo/problems/eval/moUBQPBitsIncrEval.h"


#include "mo/sampling/moAdaptiveWalkSampling.h"
#include "mo/sampling/moAutocorrelationSampling.h"
#include "mo/sampling/moDensityOfStatesSampling.h"
#include "mo/sampling/moFDCsampling.h"
#include "mo/sampling/moFitnessCloudSampling.h"
#include "mo/sampling/moHillClimberSampling.h"
#include "mo/sampling/moAdaptiveWalkSampling.h"
#include "mo/sampling/moMHBestFitnessCloudSampling.h"
#include "mo/sampling/moMHRndFitnessCloudSampling.h"
#include "mo/sampling/moNeutralDegreeSampling.h"
#include "mo/sampling/moNeutralWalkSampling.h"
#include "mo/sampling/moRndBestFitnessCloudSampling.h"
#include "mo/sampling/moRndRndFitnessCloudSampling.h"
#include "mo/sampling/moSampling.h"
#include "mo/sampling/moStatistics.h"

#endif
