//A Special Judge For APIO'08 beads (user version)
//Author : yuscvscv

#ifndef _beads_
#define _beads_

#include <cstdio>
#include <cstdlib>

namespace _beads
{
	int state = 1;
	int remaining = 0;

	void error(int n)
	{
		switch (n)
		{
			case 0:
				puts("Error 0: You should not call getNumQuestion() now.");
				break;
			case 1:
				puts("Error 1: Read Input Error.");
				break;
			case 2:
				puts("Error 2: You should not call getQuestion() now.");
				break;
			case 3:
				puts("Error 3: You should not call answer() now.");
				break;
		}
		exit(0);
	}
}


inline int getNumQuestions();
inline void getQuestion(int &A, int &B);
inline void answer(int ans);

inline int getNumQuestions()
{
	if (_beads::state != 1)
		_beads::error(0);

	int q, t;
	t = scanf("%d", &q);
	if(t != 1)
		_beads::error(1);

	printf("Initialize done.\n");

	_beads::state = 2;
	_beads::remaining = q;
	return q;
}

inline void getQuestion(int &A, int &B)
{
	if (_beads::state != 2 || _beads::remaining <= 0)
		_beads::error(2);

	int a, b, t;
	t = scanf("%d %d", &a, &b);

	if(t != 2)
		_beads::error(1);

	A = a;
	B = b;
	_beads::state = 3;
	_beads::remaining--;
}

inline void answer(int ans)
{
	if (_beads::state != 3 || _beads::remaining < 0)
		_beads::error(3);

	printf("%d\n", ans);
	_beads::state = 2;
}

#endif
