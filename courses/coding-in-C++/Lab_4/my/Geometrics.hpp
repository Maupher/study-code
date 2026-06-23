#ifndef GEOMETRICS_HPP
#define GEOMETRICS_HPP

class Geometrics{

    private:

    public:


    //Virtuall because its diffrent depending on the shape
    virtual double computeArea() = 0;

    //regarding the polymorphy 
    virtual ~Geometrics();

};


#endif //GEOMETRICS_HPP