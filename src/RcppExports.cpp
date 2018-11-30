// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// gfpopTransfert_Gauss
List gfpopTransfert_Gauss(NumericVector vectData, NumericVector vectWeight, DataFrame mygraph, double K, double a, double min, double max);
RcppExport SEXP _gfpop_gfpopTransfert_Gauss(SEXP vectDataSEXP, SEXP vectWeightSEXP, SEXP mygraphSEXP, SEXP KSEXP, SEXP aSEXP, SEXP minSEXP, SEXP maxSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type vectData(vectDataSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type vectWeight(vectWeightSEXP);
    Rcpp::traits::input_parameter< DataFrame >::type mygraph(mygraphSEXP);
    Rcpp::traits::input_parameter< double >::type K(KSEXP);
    Rcpp::traits::input_parameter< double >::type a(aSEXP);
    Rcpp::traits::input_parameter< double >::type min(minSEXP);
    Rcpp::traits::input_parameter< double >::type max(maxSEXP);
    rcpp_result_gen = Rcpp::wrap(gfpopTransfert_Gauss(vectData, vectWeight, mygraph, K, a, min, max));
    return rcpp_result_gen;
END_RCPP
}
// gfpopTransfert_Poisson
List gfpopTransfert_Poisson(NumericVector vectData, NumericVector vectWeight, DataFrame mygraph, double K, double a, double min, double max);
RcppExport SEXP _gfpop_gfpopTransfert_Poisson(SEXP vectDataSEXP, SEXP vectWeightSEXP, SEXP mygraphSEXP, SEXP KSEXP, SEXP aSEXP, SEXP minSEXP, SEXP maxSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type vectData(vectDataSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type vectWeight(vectWeightSEXP);
    Rcpp::traits::input_parameter< DataFrame >::type mygraph(mygraphSEXP);
    Rcpp::traits::input_parameter< double >::type K(KSEXP);
    Rcpp::traits::input_parameter< double >::type a(aSEXP);
    Rcpp::traits::input_parameter< double >::type min(minSEXP);
    Rcpp::traits::input_parameter< double >::type max(maxSEXP);
    rcpp_result_gen = Rcpp::wrap(gfpopTransfert_Poisson(vectData, vectWeight, mygraph, K, a, min, max));
    return rcpp_result_gen;
END_RCPP
}
// gfpopTransfert_Binomial
List gfpopTransfert_Binomial(NumericVector vectData, NumericVector vectWeight, DataFrame mygraph, double K, double a, double min, double max);
RcppExport SEXP _gfpop_gfpopTransfert_Binomial(SEXP vectDataSEXP, SEXP vectWeightSEXP, SEXP mygraphSEXP, SEXP KSEXP, SEXP aSEXP, SEXP minSEXP, SEXP maxSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type vectData(vectDataSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type vectWeight(vectWeightSEXP);
    Rcpp::traits::input_parameter< DataFrame >::type mygraph(mygraphSEXP);
    Rcpp::traits::input_parameter< double >::type K(KSEXP);
    Rcpp::traits::input_parameter< double >::type a(aSEXP);
    Rcpp::traits::input_parameter< double >::type min(minSEXP);
    Rcpp::traits::input_parameter< double >::type max(maxSEXP);
    rcpp_result_gen = Rcpp::wrap(gfpopTransfert_Binomial(vectData, vectWeight, mygraph, K, a, min, max));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_gfpop_gfpopTransfert_Gauss", (DL_FUNC) &_gfpop_gfpopTransfert_Gauss, 7},
    {"_gfpop_gfpopTransfert_Poisson", (DL_FUNC) &_gfpop_gfpopTransfert_Poisson, 7},
    {"_gfpop_gfpopTransfert_Binomial", (DL_FUNC) &_gfpop_gfpopTransfert_Binomial, 7},
    {NULL, NULL, 0}
};

RcppExport void R_init_gfpop(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}