#ifdef _MSC_VER
#pragma warning(disable:4786)
#endif

#include <gp/eoParseTree.h>
#include <eo>

using namespace gp_parse_tree;
using namespace std;

//-----------------------------------------------------------------------------

class SymregNode
{
public :

	enum Operator {X = 'x', Plus = '+', Min = '-', Mult = '*', PDiv = '/'};

	SymregNode(void)				{ init(); }
	SymregNode(Operator _op)		{ op = _op; }
	virtual ~SymregNode(void)			{}

	// arity function, need this function!
	int arity(void) const      { return op == X? 0 : 2; }

    void randomize(void) {}
    
	// evaluation function, single case, using first argument to give value of variable
	template <class Children>
	void operator()(double& result, Children args, double var) const
	{
        double r1, r2;

        if (arity() == 2)
        {
            args[0].apply(r1, var);
            args[1].apply(r2, var);
        }

		switch (op)
		{
		case Plus : result = r1 + r2; break;
		case Min  : result = r1 - r2; break;
		case Mult : result = r1 * r2; break;
		case PDiv : 
			{
				if (r2 == 0.0)
					result = 1.0; // protection a la Koza, realistic implementations should maybe throw an exception
                else
				    result = r1 / r2;
                break;
			}

		case X    : result = var; break;
		}

	}

    /// 'Pretty' print to ostream function
    template <class Children>
        void operator()(string& result, Children args) const
    {
        static const string lb = "(";
        static const string rb = ")";
        char opStr[4] = "   ";
        opStr[1] = op;
        
	    if (arity() == 0)
		{
            result = "x";
            return;
        }
        // else
        string r1;
        args[0].apply(r1);
        result = lb + r1;
        result += opStr; 
        args[1].apply(r1);
        result += r1 + rb;
    }

    Operator getOp(void) const { return op; }    

protected :

	void init(void)					{ op = X; }

private :

	Operator op; // the type of node
};

/// initializor
static SymregNode init_sequence[5] = {SymregNode::X, SymregNode::Plus, SymregNode::Min, SymregNode::Mult, SymregNode::PDiv}; // needed for intialization

//-----------------------------------------------------------
// saving, loading

std::ostream& operator<<(std::ostream& os, const SymregNode& eot)
{
    os << static_cast<char>(eot.getOp());
    return os;
}

std::istream& operator>>(std::istream& is, SymregNode& eot)
{
    char type;
    type = (char) is.get();
    eot = SymregNode(static_cast<SymregNode::Operator>(type));
    return is;
}


//-----------------------------------------------------------------------------
/** Implementation of a function evaluation object. */

double targetFunction(double x)
{ 
	return x * x * x * x - x * x * x + x * x * x - x * x + x - 10; 
}

// parameters controlling the sampling of points
const double xbegin = -10.0f;
const double xend   = 10.0f;
const double xstep  = 1.3f; 

template <class FType, class Node> struct RMS: public eoEvalFunc< eoParseTree<FType, Node> > 
{
public :

    typedef eoParseTree<FType, Node> EoType;

    typedef eoParseTree<FType, Node> argument_type;
    typedef double                   fitness_type;

	RMS(void) : eoEvalFunc<EoType>()
	{
		int n = int( (xend - xbegin) / xstep);
		
		inputs.resize(n);
		target.resize(n);

		int i = 0;

    	for (double x = xbegin; x < xend && i < n; ++i, x+=xstep)
		{
			target[i] = targetFunction(x);
			inputs[i] = x;
		}
	}

    ~RMS() {}
    
	void operator()( EoType & _eo )  
	{
		vector<double> outputs;
		outputs.resize(inputs.size());
		
        double fitness = 0.0;
        
	for (unsigned i = 0; i < inputs.size(); ++i)
        {
		    _eo.apply(outputs[i], inputs[i]);
	        fitness += (outputs[i] - target[i]) * (outputs[i] - target[i]);
        }
		
        fitness /= (double) target.size();
        fitness = sqrt(fitness);
			
		if (fitness > 1e+20)
			fitness = 1e+20;

		_eo.fitness(fitness);
	}

private :
	vector<double> inputs;
	vector<double> target;
};

template <class EOT, class FitnessType>
void print_best(eoPop<EOT>& pop)
{
    cout << endl;
    FitnessType best = pop[0].fitness();
    int index = 0;

    for (unsigned i = 1; i < pop.size(); ++i)
    {
        if (best < pop[i].fitness())
        {
            best = pop[i].fitness();
            index = i;
        }
    }
    
    cout << "\t";
        
    string str;
    pop[index].apply(str);
    
    cout << str.c_str();
    cout << endl << "RMS Error = " << pop[index].fitness() << endl;
}

int main()
{
    typedef eoMinimizingFitness FitnessType;
    typedef SymregNode GpNode;

    typedef eoParseTree<FitnessType, GpNode> EoType;
    typedef eoPop<EoType> Pop;	

    const int MaxSize = 75;
    const int nGenerations = 50;

    // Initializor sequence, contains the allowable nodes
    vector<GpNode> init(init_sequence, init_sequence + 5);

    // Depth Initializor, defaults to grow method.
    eoGpDepthInitializer<FitnessType, GpNode> initializer(10, init);
    
    // Root Mean Squared Error Measure
    RMS<FitnessType, GpNode>              eval;

    Pop pop(500, initializer);

    apply<EoType>(eval, pop);

    eoSubtreeXOver<FitnessType, GpNode>   xover(MaxSize);
    eoBranchMutation<FitnessType, GpNode> mutation(initializer, MaxSize);

    eoSequentialGOpSel<EoType>   seqSel;

    seqSel.addOp(mutation, 0.25);
    seqSel.addOp(xover, 0.75);
  
    eoDetTournament<EoType> selector(5);
  
    eoDetTournamentInserter<EoType> inserter(eval, 5);
  
    // Terminators
    eoGenContinue<EoType> term(nGenerations);

    eoCheckPoint<EoType> checkPoint(term);

    eoAverageStat<EoType>     avg;
    eoBestFitnessStat<EoType> best;
    eoStdoutMonitor monitor;

    checkPoint.add(monitor);
    checkPoint.add(avg);
    checkPoint.add(best);

    monitor.add(avg);
    monitor.add(best);

    // GP generation
    eoSteadyStateEA<EoType> gp(seqSel, selector, inserter, checkPoint);

    cout << "Initialization done" << endl;

    print_best<EoType, FitnessType>(pop);

    try
    {
      gp(pop);
    }
    catch (exception& e)
    {
	    cout << "exception: " << e.what() << endl;;
	    exit(EXIT_FAILURE);
    }

    print_best<EoType, FitnessType>(pop);

    return 1;
}


