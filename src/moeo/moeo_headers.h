/* 
* <moeo>
* Copyright (C) DOLPHIN Project-Team, INRIA Futurs, 2006-2007
* (C) OPAC Team, LIFL, 2002-2007
*
* Arnaud Liefooghe
*
* This software is governed by the CeCILL license under French law and
* abiding by the rules of distribution of free software.  You can  use,
* modify and/ or redistribute the software under the terms of the CeCILL
* license as circulated by CEA, CNRS and INRIA at the following URL
* "http://www.cecill.info".
*
* As a counterpart to the access to the source code and  rights to copy,
* modify and redistribute granted by the license, users are provided only
* with a limited warranty  and the software's author,  the holder of the
* economic rights,  and the successive licensors  have only  limited liability.
*
* In this respect, the user's attention is drawn to the risks associated
* with loading,  using,  modifying and/or developing or reproducing the
* software by the user in light of its specific status of free software,
* that may mean  that it is complicated to manipulate,  and  that  also
* therefore means  that it is reserved for developers  and  experienced
* professionals having in-depth computer knowledge. Users are therefore
* encouraged to load and test the software's suitability as regards their
* requirements in conditions enabling the security of their systems and/or
* data to be ensured and,  more generally, to use and operate it in the
* same conditions as regards security.
* The fact that you are presently reading this means that you have had
* knowledge of the CeCILL license and that you accept its terms.
*
* ParadisEO WebSite : http://paradiseo.gforge.inria.fr
* Contact: paradiseo-help@lists.gforge.inria.fr
*
*/
//-----------------------------------------------------------------------------

#ifndef MOEO_
#define MOEO_


#include "eo.h"

#include "moeo/algo/moeoAlgo.h"
#include "moeo/algo/moeoASEEA.h"
#include "moeo/algo/moeoEA.h"
#include "moeo/algo/moeoEasyEA.h"
#include "moeo/algo/moeoIBEA.h"
#include "moeo/algo/moeoMOGA.h"
#include "moeo/algo/moeoNSGA.h"
#include "moeo/algo/moeoNSGAII.h"
#include "moeo/algo/moeoPLS1.h"
#include "moeo/algo/moeoPLS2.h"
#include "moeo/algo/moeoPopAlgo.h"
#include "moeo/algo/moeoPopLS.h"
#include "moeo/algo/moeoSEEA.h"
#include "moeo/algo/moeoSPEA2.h"
#include "moeo/algo/moeoUnifiedDominanceBasedLS.h"

#include "moeo/archive/moeo2DMinHypervolumeArchive.h"
#include "moeo/archive/moeoArchive.h"
#include "moeo/archive/moeoBoundedArchive.h"
#include "moeo/archive/moeoEpsilonHyperboxArchive.h"
#include "moeo/archive/moeoFitDivBoundedArchive.h"
#include "moeo/archive/moeoFixedSizeArchive.h"
#include "moeo/archive/moeoImprOnlyBoundedArchive.h"
#include "moeo/archive/moeoSPEA2Archive.h"
#include "moeo/archive/moeoUnboundedArchive.h"

#include "moeo/comparator/moeoAggregativeComparator.h"
#include "moeo/comparator/moeoComparator.h"
#include "moeo/comparator/moeoDiversityThenFitnessComparator.h"
#include "moeo/comparator/moeoEpsilonObjectiveVectorComparator.h"
#include "moeo/comparator/moeoFitnessComparator.h"
#include "moeo/comparator/moeoFitnessThenDiversityComparator.h"
#include "moeo/comparator/moeoGDominanceObjectiveVectorComparator.h"
#include "moeo/comparator/moeoObjectiveObjectiveVectorComparator.h"
#include "moeo/comparator/moeoObjectiveVectorComparator.h"
#include "moeo/comparator/moeoOneObjectiveComparator.h"
#include "moeo/comparator/moeoParetoObjectiveVectorComparator.h"
#include "moeo/comparator/moeoParetoDualObjectiveVectorComparator.h"
#include "moeo/comparator/moeoPtrComparator.h"
#include "moeo/comparator/moeoStrictObjectiveVectorComparator.h"
#include "moeo/comparator/moeoWeakObjectiveVectorComparator.h"

#include "moeo/core/MOEO.h"
#include "moeo/core/moeoBitVector.h"
#include "moeo/core/moeoEvalFunc.h"
#include "moeo/core/moeoIntVector.h"
#include "moeo/core/moeoObjectiveVector.h"
#include "moeo/core/moeoObjectiveVectorTraits.h"
#include "moeo/core/moeoScalarObjectiveVector.h"
#include "moeo/core/moeoRealObjectiveVector.h"
#include "moeo/core/moeoDualRealObjectiveVector.h"
#include "moeo/core/moeoRealVector.h"
#include "moeo/core/moeoVector.h"

#include "moeo/distance/moeoDistance.h"
#include "moeo/distance/moeoDistanceMatrix.h"
#include "moeo/distance/moeoEuclideanDistance.h"
#include "moeo/distance/moeoManhattanDistance.h"
#include "moeo/distance/moeoNormalizedDistance.h"
#include "moeo/distance/moeoObjSpaceDistance.h"

#include "moeo/diversity/moeoCrowdingDiversityAssignment.h"
#include "moeo/diversity/moeoDiversityAssignment.h"
#include "moeo/diversity/moeoDummyDiversityAssignment.h"
#include "moeo/diversity/moeoFrontByFrontCrowdingDiversityAssignment.h"
#include "moeo/diversity/moeoFrontByFrontSharingDiversityAssignment.h"
#include "moeo/diversity/moeoNearestNeighborDiversityAssignment.h"
#include "moeo/diversity/moeoSharingDiversityAssignment.h"

#include "moeo/explorer/moeoExhaustiveNeighborhoodExplorer.h"
#include "moeo/explorer/moeoFirstImprovingNeighborhoodExplorer.h"
#include "moeo/explorer/moeoNoDesimprovingNeighborhoodExplorer.h"
#include "moeo/explorer/moeoPopNeighborhoodExplorer.h"
#include "moeo/explorer/moeoSimpleSubNeighborhoodExplorer.h"
#include "moeo/explorer/moeoSubNeighborhoodExplorer.h"

#include "moeo/fitness/moeoAggregationFitnessAssignment.h"
#include "moeo/fitness/moeoBinaryIndicatorBasedFitnessAssignment.h"
#include "moeo/fitness/moeoConstraintFitnessAssignment.h"
#include "moeo/fitness/moeoCriterionBasedFitnessAssignment.h"
#include "moeo/fitness/moeoDominanceBasedFitnessAssignment.h"
#include "moeo/fitness/moeoDominanceCountFitnessAssignment.h"
#include "moeo/fitness/moeoDominanceCountRankingFitnessAssignment.h"
#include "moeo/fitness/moeoDominanceDepthFitnessAssignment.h"
#include "moeo/fitness/moeoDominanceRankFitnessAssignment.h"
#include "moeo/fitness/moeoDummyFitnessAssignment.h"
#include "moeo/fitness/moeoExpBinaryIndicatorBasedFitnessAssignment.h"
#include "moeo/fitness/moeoExpBinaryIndicatorBasedDualFitnessAssignment.h"
#include "moeo/fitness/moeoFitnessAssignment.h"
#include "moeo/fitness/moeoIndicatorBasedFitnessAssignment.h"
#include "moeo/fitness/moeoReferencePointIndicatorBasedFitnessAssignment.h"
#include "moeo/fitness/moeoScalarFitnessAssignment.h"
#include "moeo/fitness/moeoSingleObjectivization.h"
#include "moeo/fitness/moeoUnaryIndicatorBasedFitnessAssignment.h"

#include "moeo/hybridization/moeoDMLSGenUpdater.h"
#include "moeo/hybridization/moeoDMLSMonOp.h"

#include "moeo/metric/moeoAdditiveEpsilonBinaryMetric.h"
#include "moeo/metric/moeoContributionMetric.h"
#include "moeo/metric/moeoDistanceMetric.h"
#include "moeo/metric/moeoEntropyMetric.h"
#include "moeo/metric/moeoHypervolumeBinaryMetric.h"
#include "moeo/metric/moeoHyperVolumeDifferenceMetric.h"
#include "moeo/metric/moeoDualHyperVolumeDifferenceMetric.h"
#include "moeo/metric/moeoHyperVolumeMetric.h"
#include "moeo/metric/moeoMetric.h"
#include "moeo/metric/moeoNormalizedSolutionVsSolutionBinaryMetric.h"
#include "moeo/metric/moeoVecVsVecAdditiveEpsilonBinaryMetric.h"
#include "moeo/metric/moeoVecVsVecEpsilonBinaryMetric.h"
#include "moeo/metric/moeoVecVsVecMultiplicativeEpsilonBinaryMetric.h"

#include "moeo/replacement/moeoElitistReplacement.h"
#include "moeo/replacement/moeoEnvironmentalReplacement.h"
#include "moeo/replacement/moeoGenerationalReplacement.h"
#include "moeo/replacement/moeoReplacement.h"

//#include "moeo/scalarStuffs/algo/moeoHC.h"
//#include "moeo/scalarStuffs/algo/moeoILS.h"
//#include "moeo/scalarStuffs/algo/moeoSA.h"
//#include "moeo/scalarStuffs/algo/moeoSolAlgo.h"
//#include "moeo/scalarStuffs/algo/moeoTS.h"
//#include "moeo/scalarStuffs/algo/moeoVFAS.h"
//#include "moeo/scalarStuffs/algo/moeoVNS.h"
#include "moeo/scalarStuffs/archive/moeoArchiveIndex.h"
#include "moeo/scalarStuffs/archive/moeoIndexedArchive.h"
//#include "moeo/scalarStuffs/archive/moeoQuadTree.h"
//#include "moeo/scalarStuffs/archive/moeoQuadTreeArchive.h"
#include "moeo/scalarStuffs/archive/moeoQuickUnboundedArchiveIndex.h"
//#include "moeo/scalarStuffs/distance/moeoAchievementScalarizingFunctionDistance.h"
//#include "moeo/scalarStuffs/distance/moeoAugmentedAchievementScalarizingFunctionDistance.h"
#include "moeo/scalarStuffs/distance/moeoAugmentedWeightedChebychevDistance.h"
//#include "moeo/scalarStuffs/distance/moeoWeightedChebychevDistance.h"
//#include "moeo/scalarStuffs/explorer/moeoHCMoveLoopExpl.h"
//#include "moeo/scalarStuffs/explorer/moeoTSMoveLoopExpl.h"
#include "moeo/scalarStuffs/fitness/moeoAchievementFitnessAssignment.h"
#include "moeo/scalarStuffs/fitness/moeoAchievementScalarizingFunctionMetricFitnessAssignment.h"
#include "moeo/scalarStuffs/fitness/moeoAugmentedAchievementScalarizingFunctionMetricFitnessAssignment.h"
#include "moeo/scalarStuffs/fitness/moeoAugmentedWeightedChebychevMetricFitnessAssignment.h"
//#include "moeo/scalarStuffs/fitness/moeoIncrEvalSingleObjectivizer.h"
//#include "moeo/scalarStuffs/fitness/moeoMetricFitnessAssignment.h"
#include "moeo/scalarStuffs/fitness/moeoWeightedChebychevMetricFitnessAssignment.h"
//#include "moeo/scalarStuffs/weighting/moeoAnytimeWeightStrategy.h"
//#include "moeo/scalarStuffs/weighting/moeoAugmentedQexploreWeightStrategy.h"
//#include "moeo/scalarStuffs/weighting/moeoDichoWeightStrategy.h"
//#include "moeo/scalarStuffs/weighting/moeoDummyRefPointStrategy.h"
//#include "moeo/scalarStuffs/weighting/moeoDummyWeightStrategy.h"
//#include "moeo/scalarStuffs/weighting/moeoFixedTimeBothDirectionWeightStrategy.h"
//#include "moeo/scalarStuffs/weighting/moeoFixedTimeOneDirectionWeightStrategy.h"
//#include "moeo/scalarStuffs/weighting/moeoQexploreWeightStrategy.h"
//#include "moeo/scalarStuffs/weighting/moeoRandWeightStrategy.h"
//#include "moeo/scalarStuffs/weighting/moeoVariableRefPointStrategy.h"
//#include "moeo/scalarStuffs/weighting/moeoVariableWeightStrategy.h"

#include "moeo/selection/moeoDetArchiveSelect.h"
#include "moeo/selection/moeoDetTournamentSelect.h"
#include "moeo/selection/moeoExhaustiveUnvisitedSelect.h"
#include "moeo/selection/moeoNumberUnvisitedSelect.h"
#include "moeo/selection/moeoRandomSelect.h"
#include "moeo/selection/moeoRouletteSelect.h"
#include "moeo/selection/moeoSelectFromPopAndArch.h"
#include "moeo/selection/moeoSelectOne.h"
#include "moeo/selection/moeoSelectors.h"
#include "moeo/selection/moeoStochTournamentSelect.h"
#include "moeo/selection/moeoUnvisitedSelect.h"

#include "moeo/utils/moeoArchiveObjectiveVectorSavingUpdater.h"
#include "moeo/utils/moeoArchiveUpdater.h"
#include "moeo/utils/moeoAverageObjVecStat.h"
#include "moeo/utils/moeoBestObjVecStat.h"
#include "moeo/utils/moeoBinaryMetricSavingUpdater.h"
#include "moeo/utils/moeoBinaryMetricStat.h"
#include "moeo/utils/moeoConvertPopToObjectiveVectors.h"
#include "moeo/utils/moeoDominanceMatrix.h"
#include "moeo/utils/moeoObjectiveVectorNormalizer.h"
#include "moeo/utils/moeoObjVecStat.h"

#include "moeo/continue/moeoHypContinue.h"
#include "moeo/continue/moeoDualHypContinue.h"

#endif /*MOEO_*/
