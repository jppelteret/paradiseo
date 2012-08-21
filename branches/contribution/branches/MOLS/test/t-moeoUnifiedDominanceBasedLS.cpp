/*
* <t-moeoUnifiedDominanceBasedLS.cpp>
* Copyright (C) DOLPHIN Project-Team, INRIA Lille-Nord Europe, 2006-2008
* (C) OPAC Team, LIFL, 2002-2008
*
* Arnaud Liefooghe
* Jeremie Humeau
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
// t-moeoUnifiedDominanceBasedLS.cpp
//-----------------------------------------------------------------------------

#include <eo>
#include <moeo>
#include <assert.h>
#include <set>
#include <iostream>
#include <moeoExhaustiveUnvisitedSelect.h>
#include <moeoTestClass.h>
#include <moeoUnifiedDominanceBasedLS.h>
#include <eoTenTimeContinue.h>
#include <moeoExhaustiveNeighborhoodExplorer.h>
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------

int main()
{
    std::cout << "[moeoUnifiedDominanceBasedLS] => ";



    moeoExhaustiveUnvisitedSelect < Solution > select;

    testEval eval;
    testMoveInit init;
	testMoveNext next;
	testMoveIncrEval2 incr;
	testMoveIncrEval3 incr2;
	moeoExhaustiveNeighborhoodExplorer < testMove > explorer(init, next, incr);

	moeoUnboundedArchive <Solution>  arch;
	eoCtrlCContinue <Solution> cont;
	moeoUnifiedDominanceBasedLS <testMove> algo(cont, eval, arch, explorer, select);

    // objective vectors
    eoPop < Solution > pop;
    pop.resize(2);
    pop[0].flag(0);
    pop[1].flag(0);

	algo(pop);

	assert(arch.size()==1);
	assert(arch[0].flag()==1);

	arch.resize(0);
	moeoExhaustiveNeighborhoodExplorer < testMove > explorer2(init, next, incr2);
	moeoUnifiedDominanceBasedLS <testMove> algo2(cont, eval, arch, explorer2, select);
	algo2(pop);
	assert(arch.size()==501);
	assert(arch[0].objectiveVector()[0]==500);
	assert(arch[0].objectiveVector()[1]==0);
	assert(arch[500].objectiveVector()[1]==500);
	assert(arch[500].objectiveVector()[0]==0);

    std::cout << "OK" << std::endl;
    return EXIT_SUCCESS;
}

//-----------------------------------------------------------------------------