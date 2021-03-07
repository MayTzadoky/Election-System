#ifndef __CoronaBB_H
#define __CoronaBB_H

#include "Ballotbox.h"

class CoronaBB : virtual public BallotBox
{
protected:
	bool ifProtectiveSuit;
public:
	CoronaBB(const BallotBox& bb);
	virtual ~CoronaBB();
	bool setIfProtectiveSuit(bool tmpIfProtectiveSuit);
	bool getIfProtectiveSuit() const;
	virtual void toOs(ostream& os) const override;
};
#endif // __CoronaBB_H