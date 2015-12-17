//-----------------------------------------------------------------------------
// eo
// (c) GeNeura Team 1998 - 2000
/*
    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

    Contact: todos@geneura.ugr.es, http://geneura.ugr.es
 */
//-----------------------------------------------------------------------------

#ifdef _MSC_VER
// to avoid long name warnings
#pragma warning(disable:4786)
#endif

#ifndef _eo_
#define _eo_

#ifdef HAVE_CONFIG_H
#include <paradiseo/eo/config.h>
#endif

// general purpose
#include <paradiseo/eo/utils/eoData.h>
#include <paradiseo/eo/eoObject.h>
#include <paradiseo/eo/eoPrintable.h>
#include <paradiseo/eo/eoPersistent.h>
#include <paradiseo/eo/eoScalarFitness.h>
#include <paradiseo/eo/eoDualFitness.h>
#include <paradiseo/eo/EO.h>

#include <paradiseo/eo/utils/rnd_generators.h>
#include <paradiseo/eo/eoFunctor.h>
#include <paradiseo/eo/apply.h>

// eo's
#include <paradiseo/eo/eoVector.h>

#include <paradiseo/eo/other/eoString.h>

#include <paradiseo/eo/utils/eoRndGenerators.h>
#include <paradiseo/eo/eoInit.h>
#include <paradiseo/eo/utils/eoUniformInit.h>

// the variation operators
#include <paradiseo/eo/eoOp.h>
#include <paradiseo/eo/eoGenOp.h>
#include <paradiseo/eo/eoCloneOps.h>
#include <paradiseo/eo/eoOpContainer.h>
// combinations of simple eoOps (eoMonOp and eoQuadOp)
#include <paradiseo/eo/eoProportionalCombinedOp.h>
// didactic (mimics SGA-like variation into an eoGenOp)
// calls crossover and mutation sequentially,
// with their respective mutation rates
#include <paradiseo/eo/eoSGAGenOp.h>
// its dual: crossover, mutation (and copy) - proportional choice
// w.r.t. given relative weights
#include <paradiseo/eo/eoPropGAGenOp.h>

// population
#include <paradiseo/eo/eoPop.h>

// Evaluation functions (all include eoEvalFunc.h)
#include <paradiseo/eo/eoPopEvalFunc.h>
#include <paradiseo/eo/eoEvalFuncPtr.h>
#include <paradiseo/eo/eoEvalCounterThrowException.h>
#include <paradiseo/eo/eoEvalTimeThrowException.h>
#include <paradiseo/eo/eoEvalUserTimeThrowException.h>

// Continuators - all include eoContinue.h
#include <paradiseo/eo/eoCombinedContinue.h>
#include <paradiseo/eo/eoGenContinue.h>
#include <paradiseo/eo/eoSteadyFitContinue.h>
#include <paradiseo/eo/eoEvalContinue.h>
#include <paradiseo/eo/eoFitContinue.h>
#include <paradiseo/eo/eoPeriodicContinue.h>
#include <paradiseo/eo/eoTimeContinue.h> // added th T.Legrand
#ifndef _MSC_VER
#include <paradiseo/eo/eoCtrlCContinue.h>  // CtrlC handling (using 2 global variables!)
#endif
// Selection
// the eoSelectOne's
#include <paradiseo/eo/eoRandomSelect.h>
#include <paradiseo/eo/eoSequentialSelect.h>
#include <paradiseo/eo/eoDetTournamentSelect.h>
#include <paradiseo/eo/eoProportionalSelect.h>
#include <paradiseo/eo/eoFitnessScalingSelect.h> // also contains eoLinearFitScaling.h
#include <paradiseo/eo/eoRankingSelect.h>
#include <paradiseo/eo/eoStochTournamentSelect.h>
#include <paradiseo/eo/eoSharingSelect.h>
// Embedding truncation selection
#include <paradiseo/eo/eoTruncatedSelectOne.h>

// the batch selection - from an eoSelectOne
#include <paradiseo/eo/eoSelectPerc.h>
#include <paradiseo/eo/eoSelectNumber.h>
#include <paradiseo/eo/eoSelectMany.h>
#include <paradiseo/eo/eoTruncatedSelectMany.h>

// other batch selections
// DetSelect can also be obtained as eoSequentialSelect, an eoSelectOne
// (using setup and an index)
#include <paradiseo/eo/eoDetSelect.h>
#include <paradiseo/eo/eoRankMuSelect.h>

// Breeders
#include <paradiseo/eo/eoGeneralBreeder.h>	// applies one eoGenOp, stop on offspring count
// #include <paradiseo/eo/eoOneToOneBreeder.h>	// parent + SINGLE offspring compete (e.g. DE) - not ready yet...

// Replacement
// #include <paradiseo/eo/eoReplacement.h>
#include <paradiseo/eo/eoMergeReduce.h>
#include <paradiseo/eo/eoReduceMerge.h>
#include <paradiseo/eo/eoSurviveAndDie.h>

// a simple transformer
#include <paradiseo/eo/eoSGATransform.h>

// Perf2Worth stuff - includes eoSelectFromWorth.h
#include <paradiseo/eo/eoNDSorting.h>


// Algorithms
#include <paradiseo/eo/eoEasyEA.h>
#include <paradiseo/eo/eoSGA.h>
// #include <paradiseo/eo/eoEvolutionStrategy.h>   removed for a while - until eoGenOp is done

// Utils
#include <paradiseo/eo/utils/eoCheckpoint_headers.h>
#include <paradiseo/eo/utils/eoRealVectorBounds.h> // includes eoRealBounds.h
#include <paradiseo/eo/utils/eoIntBounds.h>        // no eoIntVectorBounds

// aliens
#include <paradiseo/eo/other/eoExternalEO.h>
#include <paradiseo/eo/eoCounter.h>


//-----------------------------------------------------------------------------
// to be continued ...
//-----------------------------------------------------------------------------

/*** Particle Swarm Optimization stuff ***/

// basic particle definitions
#include <paradiseo/eo/PO.h>
#include <paradiseo/eo/eoVectorParticle.h>
#include <paradiseo/eo/eoBitParticle.h>
#include <paradiseo/eo/eoRealParticle.h>

// initialization
#include <paradiseo/eo/eoParticleBestInit.h>
#include <paradiseo/eo/eoInitializer.h>

// velocities
#include <paradiseo/eo/eoVelocity.h>
#include <paradiseo/eo/eoStandardVelocity.h>
#include <paradiseo/eo/eoExtendedVelocity.h>
#include <paradiseo/eo/eoIntegerVelocity.h>
#include <paradiseo/eo/eoConstrictedVelocity.h>
#include <paradiseo/eo/eoFixedInertiaWeightedVelocity.h>
#include <paradiseo/eo/eoVariableInertiaWeightedVelocity.h>
#include <paradiseo/eo/eoConstrictedVariableWeightVelocity.h>

// flights
#include <paradiseo/eo/eoFlight.h>
#include <paradiseo/eo/eoStandardFlight.h>
#include <paradiseo/eo/eoVelocityInit.h>
#include <paradiseo/eo/eoBinaryFlight.h>
#include <paradiseo/eo/eoSigBinaryFlight.h>

// topologies
#include <paradiseo/eo/eoTopology.h>
#include <paradiseo/eo/eoStarTopology.h>
#include <paradiseo/eo/eoLinearTopology.h>
#include <paradiseo/eo/eoRingTopology.h>
#include <paradiseo/eo/eoNeighborhood.h>
#include <paradiseo/eo/eoSocialNeighborhood.h>

// PS algorithms
#include <paradiseo/eo/eoPSO.h>
#include <paradiseo/eo/eoEasyPSO.h>
#include <paradiseo/eo/eoSyncEasyPSO.h>

// utils
#include <paradiseo/eo/eoRealBoundModifier.h>
#include <paradiseo/eo/eoRandomRealWeightUp.h>
#include <paradiseo/eo/eoWeightUpdater.h>
#include <paradiseo/eo/eoLinearDecreasingWeightUp.h>
#include <paradiseo/eo/eoGaussRealWeightUp.h>

#include <paradiseo/eo/utils/eoLogger.h>
#include <paradiseo/eo/utils/eoParallel.h>

// ga's
#include <paradiseo/eo/ga/eoBitOp.h>

// es's
#include <paradiseo/eo/es/CMAState.h>
#include <paradiseo/eo/es/CMAParams.h>
#include <paradiseo/eo/es/eoCMAInit.h>
#include <paradiseo/eo/es/eoCMABreed.h>
#include <paradiseo/eo/es/make_es.h>

#endif

// Local Variables:
// mode: C++
// End:
