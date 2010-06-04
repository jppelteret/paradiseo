/*
  <variable_neighborhood_search.cpp>
  Copyright (C) DOLPHIN Project-Team, INRIA Futurs, 2006-2008
  (C) OPAC Team, LIFL, 2002-2008

  Salma Mesmoudi (salma.mesmoudi@inria.fr), Jean-Charles Boisson

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

#include <eo>
#include <oldmo>
#include <tsp>
#include <vector>


//template <class T, class P>void add(T& var, P& vect);
void manage_configuration_file(eoParser & _parser);
//void ajouter (std::vector<moMoveInit<moMove<Route> > >& V, moMove<Route>& K)const ;

int
main (int _argc, char* _argv [])
{
  std::string instancePath, selectionType;
  unsigned int seed;

  eoParser parser(_argc, _argv);

  manage_configuration_file(parser);

  seed=atoi( (parser.getParamWithLongName("seed")->getValue()).c_str() );
  instancePath=parser.getParamWithLongName("instancePath")->getValue();
  selectionType=parser.getParamWithLongName("selectionType")->getValue();

  srand (seed);
  Graph::load(instancePath.c_str());

  Route solution;

  RouteInit initializer;
  initializer (solution);

  RouteEval full_evaluation;
  full_evaluation (solution);

  std :: cout << "[From] " << solution << std :: endl;
	//A neighbor is a local search or mutation

  /*Tools for an efficient (? :-))
     local search ! */
  //---------------------first neighbor----------------------------------

  TwoOptInit two_opt_initializer;

  TwoOptNext two_opt_next_move_generator;

  TwoOptIncrEval two_opt_incremental_evaluation;

  moMoveSelect<TwoOpt>* two_opt_selection;

  if(selectionType.compare("Best")==0)
    {
      two_opt_selection= new moBestImprSelect<TwoOpt>();
    }
  else if (selectionType.compare("First")==0)
    {
      two_opt_selection= new moFirstImprSelect<TwoOpt>();
    }
  else if (selectionType.compare("Random")==0)
    {
      two_opt_selection= new moRandImprSelect<TwoOpt>();
    }
  else
    {
      throw std::runtime_error("[hill_climbing.cpp]: the type of selection '"+selectionType+"' is not correct.");
    }


  moHC <TwoOpt> hill_climbing (two_opt_initializer, two_opt_next_move_generator, two_opt_incremental_evaluation,
			       *two_opt_selection, full_evaluation);


  //--------------------second neighbor-----------------

  CitySwap perturbation;

  //-----------neighbor vector--------------------------

  moExpl<Route> explorer(perturbation);
  explorer.addExplorer(hill_climbing);
  explorer.addExplorer(perturbation);

  //------------VNS application--------------------------

  moVNS<Route> vns(explorer, full_evaluation);
	vns(solution);
	//hill_climbing(solution);
  std :: cout << "[To] " << solution << std :: endl;

  delete(two_opt_selection);

  return EXIT_SUCCESS;
}


void
manage_configuration_file(eoParser & _parser)
{
  std::ofstream os;

  _parser.createParam(std::string("../examples/tsp/benchs/berlin52.tsp"), "instancePath", "Path to the instance.",
		      0, "Configuration", false);

  _parser.getORcreateParam((unsigned int)time(0), "seed", "Seed for rand.", 0, "Configuration", false);

  _parser.getORcreateParam(std::string("Best"), "selectionType", "Type of the selection: 'Best', 'First' or 'Random'.",
			   0, "Configuration", false);

  if (_parser.userNeedsHelp())
    {
      _parser.printHelp(std::cout);
      exit(EXIT_FAILURE);
    }

  os.open("current_param");
  if(!os.is_open())
    {
      throw std::runtime_error("[hill_climbing.cpp]: the file current_param cannot be created.");
    }
  os <<_parser;
  os.close();
}



