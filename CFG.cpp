#include "CFG.h"

extern ofstream gout;



basicBlock_type* CFG_type::startBasicBlock()
{
	auto res = new basicBlock_type();
	CFG.push_back(res);


	return res;
}


CFG_type::CFG_type()
{

	CFGEntry_p = startBasicBlock();
	CFGExit_p = startBasicBlock();
	/*
	CFGEntry_p->reachable = true;
	CFGExit_p->reachable = true;
	*/
}


void CFG_type::print()
{
	gout << "CFG:" << endl;
	for (auto bb_p: CFG)
	{
		bb_p->print();
	}
	gout << "entry block: " << CFGEntry_p->id << endl;
	gout << "exit block: " << CFGExit_p->id << endl;


}

void CFG_type::contract()
{
	for (auto bb_p: CFG)
	{
		if (bb_p->exit.condEgress_p != nullptr)
		{
			if (bb_p->exit.condEgress_p == CFGExit_p)
			{
				continue;
			}
			if (bb_p->exit.condEgress_p->quadList.empty())
			{
				bb_p->exit.condEgress_p = bb_p->exit.condEgress_p->exit.defaultEgress_p;
			}
		}
		if (bb_p->exit.defaultEgress_p != nullptr)
		{
			if (bb_p->exit.defaultEgress_p == CFGExit_p)
			{
				continue;
			}
			if (bb_p->exit.defaultEgress_p->quadList.empty())
			{
				bb_p->exit.defaultEgress_p = bb_p->exit.condEgress_p->exit.defaultEgress_p;
			}
		}
	}
}

void CFG_type::dfs(basicBlock_type* bb_p)
{
	if (bb_p->reachable != false)
	{
		return;
	}
	bb_p->reachable = true;

	if (bb_p->exit.condEgress_p != nullptr)
	{
		dfs(bb_p->exit.condEgress_p);
	}
	if (bb_p->exit.defaultEgress_p != nullptr)
	{
		dfs(bb_p->exit.defaultEgress_p);
	}
}


void CFG_type::deleteUnreachable()
{
	dfs(CFGEntry_p);
	list<basicBlock_type*> tmp;
	for (auto bb_p: CFG)
	{
		if (bb_p->reachable == false)
		{
			continue;
		}
		tmp.push_back(bb_p);
		//bb_p->id = tmp.size();
	}
	CFG = tmp;
}


void CFG_type::optimize()
{
	contract();
	deleteUnreachable();
	for (auto bb_p: CFG)
	{
		bb_p->getVarList();
	}

	
}



void CFG_type::transASM()
{
	
	for (auto bb_p: CFG)
	{
		bb_p->startTrans();

	}
}