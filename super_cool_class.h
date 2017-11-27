//
// Created by David Cleres on 27.11.17.
//

#ifndef PCSC2017_GROUP5_SUPER_COOL_CLASS_H
#define PCSC2017_GROUP5_SUPER_COOL_CLASS_H


struct Vector{

    double val[3];
};


class SuperCoolClass {

public:
    Vector getPosition(unsigned int dir){
        return Vector();
    };

protected:

    int var;
};


class SuperCoolClass2 : public SuperCoolClass {

};

#endif //PCSC2017_GROUP5_SUPER_COOL_CLASS_H
