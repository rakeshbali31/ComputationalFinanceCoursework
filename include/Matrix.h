#ifndef Matrix_h
#define Matrix_h

#include <vector>
using namespace std;

typedef vector<double> Vector;
typedef vector<Vector> Matrix;

Vector operator*(const Matrix& C,const Vector& V);
Vector operator*(const double& a,const Vector& V);
Vector operator+(const double& a,const Vector& V);
Vector operator+(const Vector& V,const Vector& W);
Vector operator-(const Vector& V, const double& a);
Vector operator-(const Vector& V,const Vector& W);
Vector operator*(const Vector& V,const Vector& W);
double operator^(const Vector& V,const Vector& W);


#endif
