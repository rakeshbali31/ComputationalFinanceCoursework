#include "Matrix.h"

// Multiplies a matrix by a vector
Vector operator*(const Matrix& C,const Vector& V)
{
   int d = C.size();
   Vector W(d);
   for (int j=0; j<d; j++)
   {
      W[j]=0.0;
      for (int l=0; l<d; l++) W[j]=W[j]+C[j][l]*V[l];
   }
   return W;
}

// Adds two vectors element-wise.
Vector operator+(const Vector& V,const Vector& W)
{
   int d = V.size();
   Vector U(d);
   for (int j=0; j<d; j++) U[j] = V[j] + W[j];
   return U;
}

// Adds a scalar to each element of a vector.
Vector operator+(const double& a,const Vector& V)
{
   int d = V.size();
   Vector U(d);
   for (int j=0; j<d; j++) U[j] = a + V[j];
   return U;
}

// Multiplies each element of a vector by a scalar.
Vector operator*(const double& a,const Vector& V)
{
   int d = V.size();
   Vector U(d);
   for (int j=0; j<d; j++) U[j] = a*V[j];
   return U;
}

// Multiplies two vectors element-wise.
Vector operator*(const Vector& V,const Vector& W)
{
   int d = V.size();
   Vector U(d);
   for (int j=0; j<d; j++) U[j] = V[j] * W[j];
   return U;
}

// Computes the dot product of two vectors.
double operator^(const Vector& V,const Vector& W)
{
   double sum = 0.0;
   int d = V.size();
   for (int j=0; j<d; j++) sum = sum + V[j]*W[j];
   return sum;
}
