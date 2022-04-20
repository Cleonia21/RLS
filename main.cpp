#include <iostream>

using namespace std;

enum e_target
{
	AIRCRAFT = 1,
	MISSILE = 2
};

#define DT 1.

class TTarget
{
protected:

	TTarget()
	{
		cout << "Default constructor from TTarget colled" << endl;
	}

	TTarget(double x, double y, double V, double K)
	{
		cout << "Param constructor from TTarget colled" << endl;
		_x0 = x;
		_y0 = y;
		_V = V;
		_K = K;
		_t = 0;
	}

	virtual void Move(double ti) = 0;

	~TTarget()
	{
		cout << "Destructor from TTarget colled" << endl;
	}

	double _x0, _y0, _V, _K, _x, _y, _t;
	int _type;
};

class TAircraft : public TTarget
{
public:

	TAircraft()
	{
		cout << "Default constructor from TAircraft colled" << endl;
	}

	TAircraft(double x, double y, double V, double K)
		: TTarget(x, y, V, K)
	{
		cout << "Param constructor from TAircraft colled" << endl;
		this->_type = AIRCRAFT;
	}

	void Move(double ti)
	{
		_x = _x0 - _V * cos(_K) * (ti - _t);
		_y = _y0 - _V * sin(_K) * (ti - _t);
	}

};

class TMissile : public TTarget
{
public:

	TMissile()
	{
		cout << "Default constructor from TMissile colled" << endl;
	}

	TMissile(double x, double y, double V, double K, double N)
		: TTarget(x, y, V, K), _N(N)
	{
		cout << "Param constructor from TMissile colled" << endl;
		this->_type = MISSILE;
	}

	void Move(double ti)
	{
		_x = _x0 - (_V + _N * (ti - _t)) * cos(_K) * (ti - _t);
		_y = _y0 - (_V + _N * (ti - _t)) * sin(_K) * (ti - _t);
	}

private:

	double _N;
};

class RLS
{
	RLS()
	{
		cout << "Defaul constructor from RLS colled" << endl;
	}

	RLS(double x, double y, double R, TTarget **targets)
		: _x(x), _y(y), _R(R), _targets(targets)
	{
		cout << "Param constructor from RLS colled" << endl;
	}

	void Peleng(double t0, double tk)
	{
		for (int t = t0; t < tk; t += DT)
		{
			for (int i = 0; _targets[i] != NULL; i++)
			{
				
			}
		}
	}

	~RLS()
	{
		cout << "Destructor from RLS colled" << endl;
	}

	double _x, _y, _R;
	TTarget **_targets;
};

int main( void )
{



	return (0);
}