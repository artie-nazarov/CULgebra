/**
 * The following is an interface for the CULgebra Matrix clas
 * Matrix is a core object which is used to perform Linear Algebra algorithms defined in CULgebra.
 * 
 * Features:
 *  1. Variable sizes. 
 *      A Matrix can represent a matrix, a simple vector, and even a scalar value!
 *  2. Dynamically scalable rows. 
 *      Using <vector> as an underlying array storage. You can add extra rows with a fixed number of columns defined at initialization time.  
 *  3. Operator overloading. 
 *      Use arithmetic operators +,-,*,/ to perform quick hand matrix operations.
 *  4. A collection of matrix transformation operations:
 *      transpose, ...
 *  5. A collection of Linear Algebra algorithms compatible with Matrix objects:
 *      * Matrix inverse
 *      * Eigen values/vectos
 *      * Convolutions
 *  6. Support for CUDA.
 *      You can create CUDA supported Matrix objects. Note: most algorithms in CULgebra will initially be implemented on GPU's.
 *      CUDA supported Matrix objects can have at most 3 dimensions (x, y, z)
 * 
 * Implementation Notes:
    * The underlying data storage is a flat std::vector. Indexing offsets are used to accomodate Matrices with dim size > 1
    * Matrix module is designed as a generic Matrix object for numerical Linear Algebra algorithms; hence Matrix only supports numeric data types 
 * 
 * TODO List:
    * Support for arbitrary Matrix dimensions (currently only supporting up to 3 dimensions)

 */

#ifndef CUL_MAT_H
#define CUL_MAT_H

// Imports
#include <vector>

// Supported Data Types
#define INT32 "int32"
#define UINT32 "uint32"
#define FLOAT32 "float32"
#define DOUBLE64 "double64"
#define BOOL "boolean"

template<typename T>
class Matrix {
    public:
        /**
         * Default Matrix constructor
         * Creates a vector with uninitialized Dimensions (0,)
        */
        Matrix();
        /**
         * 1D Vector constructor / Scalar
         * Creates an empty (0 filled) 1D vector with Dimensions (dim,) 
        */
        Matrix(int dim);
        /**
         * 2D Matrix constructor
         * Creates an empty (0 filled) matrix with Dimensions (n, m) 
        */
        Matrix(int n, int m);
        /**
         * 3D Matrix constructor
         * Creates an empty (0 filled) matrix with Dimensions (x, y, z) 
        */
        Matrix(int x, int y, int z);
        /**
         * 1D Vector constructor from an existing 1D std::vector
        */
        Matrix(int dim, std::vector<T> vector);
        /**
         * 2D Matrix constructor from an existing 2D std::vector
        */
        Matrix(int x, int y, std::vector<std::vector<T>> vector);
        /**
         * 3D Matrix constructor from an existing 3D std::vector
        */
        Matrix(int x, int y, int z, std::vector<std::vector<std::vector<T>>> vector);
        /**
         * Arbitrary Matrix dimension constructor from an existing 1D std::vector
         * @param dim std::vector<int> containing desired Matrix dimensions (x, y, z, ..., n)
         * @param vector a flat std::vector<T>. This vector will be reshaped to produce a Matrix objects with dimensions defined in dim
        */
        Matrix(std::vector<int> dim, std::vector<T> vector);
        // Matrix Copy constructor
        Matrix(const Matrix&);
        // Matrix Destructor
        ~Matrix();

        // get X dimension
        const int dimX();
        // get Y dimension
        const int dimY();
        // get Z dimension
        const int dimZ();
        // get a pointer to the first Matrix element (in 2D example, ptr to 1st row and 1st column)
        T *first();
        // get a pointer to a specified row (0 indexed X coordinate)
};

#endif