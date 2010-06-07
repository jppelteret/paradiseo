/*
  <moPopBitEval.h>
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

#ifndef moPopBitEval_H
#define moPopBitEval_H

#include <eoFunctor.h>
#include <eval/moEval.h>

/**
 * Abstract class for the evaluation
 */
template<class Neighbor>
class moPopBitEval : public moEval<Neighbor>
{
public:
    typedef typename Neighbor::EOT EOT;
    typedef typename Neighbor::SUBEOT SUBEOT;

    typedef typename EOT::Fitness Fitness;

    moPopBitEval(eoEvalFunc<SUBEOT>& _eval, unsigned int _p):eval(_eval), p(_p){

    }

    void operator()(EOT& _sol, Neighbor& _n){
    	if(_sol[0].size()>0){
    		unsigned int size=_sol[0].size();
    		unsigned int s=_n.index()/size;
    		unsigned int b=_n.index()%size;
    		subfit=_sol[s].fitness();
    		_sol[s][b]=!_sol[s][b];
    		_sol[s].invalidate();
    		eval(_sol[s]);
        	double fit=0;
            for (unsigned int i = 0; i < _sol.size(); i++){
            	fit+=pow(_sol[i].fitness(), p);
            }
            fit=pow(fit, (double)1/p);
            _n.setSubFit(_sol[s].fitness());
            _n.fitness(fit);
            _sol[s][b]=!_sol[s][b];
            _sol[s].fitness(subfit);
    	}
    }

private:
    eoEvalFunc<SUBEOT> & eval;
    unsigned int p;
    Fitness subfit;

};

#endif