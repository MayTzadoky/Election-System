#ifndef __MilitaryCoronaBB_H
#define __MilitaryCoronaBB_H

#include "CoronaBB.h"
#include "MilitaryBB.h"

class MilitaryCoronaBB : public CoronaBB, public MilitaryBB
{
private:

public:
	MilitaryCoronaBB(const BallotBox& bb);
	virtual ~MilitaryCoronaBB();

	virtual void toOs(ostream& os) const override;
};
#endif // __MilitaryCoronaBB_H