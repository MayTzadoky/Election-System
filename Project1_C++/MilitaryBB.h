#ifndef __MilitaryBB_H
#define __MilitaryBB_H

#include "Ballotbox.h"

class MilitaryBB : virtual public BallotBox
{
protected:
	bool ifSoldier;
public:
	MilitaryBB(const BallotBox& bb);
	virtual ~MilitaryBB();
	virtual void toOs(ostream& os) const override;
};
#endif // __MilitaryBB_H