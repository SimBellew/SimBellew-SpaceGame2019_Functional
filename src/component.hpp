#ifndef COMP_H_
#define COMP_H_

namespace components
{
    enum Types
    {
        kConduit = 0
    };

    struct Component
    {
        int id;
        Types type;
    };
}
#endif /* COMP_H_ */