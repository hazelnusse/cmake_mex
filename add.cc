#include <mex.h>

void mexFunction(int nlhs, mxArray* plhs[],
                 int nrhs, const mxArray* prhs[])
{
    // Check number of arguments supplied
    if (nrhs != 2) {
        mexErrMsgIdAndTxt("external:wrapper_template",
                          "Two parameters are required.");
    } else if (nlhs > 1) {
        mexErrMsgIdAndTxt("external:wrapper_template",
                          "One out argument required.");
    }

    // Check size of parameter vector
    size_t m0 = mxGetM(prhs[0]);
    size_t n0 = mxGetN(prhs[0]);
    size_t m1 = mxGetM(prhs[1]);
    size_t n1 = mxGetN(prhs[1]);

    if ((m0 != m1) ||
        (n0 != n1)) {
            mexErrMsgIdAndTxt("external:incompatible_dimensions",
                              "Arguments must have same dimension.");
    }

    // Create a matrices for the return argument
    plhs[0] = mxCreateDoubleMatrix(m0, n0, mxREAL); 

    // Add elements of input
    for (int i = 0; i < m0; ++i) {
        for (int j = 0; j < n0; ++j) {
            mxGetPr(plhs[0])[m0*j + i] = mxGetPr(prhs[0])[m0*j + i] +
                                         mxGetPr(prhs[1])[m0*j + i];
        } // j
    } // i

} // mexFunction

