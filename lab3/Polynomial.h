#ifndef LAB3_POLYNOMIAL_H
#define LAB3_POLYNOMIAL_H

class Polynomial {
private:
    double a;
    double b;
    double c;
    mutable int calculateRootCount;
    static int rootSearchCount;
public:
    int calculateRoots(double& x1, double& x2) const;
    int getCalculateRootCount() const;
    static int getRootSearchCount();
};



#endif //LAB3_POLYNOMIAL_H
