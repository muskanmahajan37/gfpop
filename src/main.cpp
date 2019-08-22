//#include <iostream>
#include <string>
#include<math.h>

#include<Rcpp.h>

#include"Omega.h"
#include"Cost.h"
#include"ExternFunctions.h"

#include"Data.h"
#include"Graph.h"
#include"Edge.h"
#include"Bound.h"
#include"Robust.h"

using namespace Rcpp;

// [[Rcpp::export]]
List gfpopTransfer(NumericVector vectData, DataFrame mygraph, std::string type, NumericVector vectWeight)
{

  ///////////////////////////////////////////
  /////////// DATA TRANSFORMATION ///////////
  ///////////////////////////////////////////
  double epsilon = pow(10,-12);

  if(type == "variance")
  {
    double mean = 0;
    for(int i = 0; i < vectData.size(); i++){mean = mean + vectData[i];}
    mean = mean/vectData.size();
    for(int i = 0; i < vectData.size(); i++){vectData[i] = vectData[i] - mean; if(vectData[i] == 0){vectData[i] = epsilon;}}
  }

  if(type == "exp")
  {
    for(int i = 0; i < vectData.size(); i++){if(vectData[i] <= 0){throw std::range_error("Data has to be all positive");}}
  }

  if(type == "poisson")
  {
    for(int i = 0; i < vectData.size(); i++){if(vectData[i] < 0 || (vectData[i]  > floor(vectData[i]))){throw std::range_error("There are some non-integer data");}}
  }

  if(type == "negbin")
  {
    int windowSize = 100;
    int k = vectData.size() / windowSize;
    double mean = 0;
    double variance = 0;
    double disp = 0;

    for(int j = 0; j < k; j++)
    {
      mean = 0;
      variance = 0;
      for(int i = j * windowSize; i < (j + 1)*windowSize; i++){mean = mean + vectData[i];}
      mean = mean/windowSize;
      for(int i =  j * windowSize; i < (j + 1)*windowSize; i++){variance = variance + (vectData[i] - mean) * (vectData[i] - mean);}
      variance = variance/(windowSize - 1);
      disp = disp  + (mean * mean / (variance - mean));
    }
    disp = disp/k;
    for(int i = 0; i < vectData.size(); i++){vectData[i] = vectData[i]/disp; if(vectData[i] == 0){vectData[i] = epsilon/(1- epsilon);}}
  }

  // BEGIN TRANSFERT into C++ objects  // BEGIN TRANSFERT into C++ objects  // BEGIN TRANSFERT into C++ objects
  // BEGIN TRANSFERT into C++ objects  // BEGIN TRANSFERT into C++ objects  // BEGIN TRANSFERT into C++ objects

  /////////////////////////////////
  /////////// DATA COPY ///////////
  /////////////////////////////////
  Data data = Data(); // in any case, add a file name. by default = "nofile"
  int n = vectData.length();
  int nw = vectWeight.length();
  data.copy(vectData, vectWeight, n, nw);
  //data.show(false);

  //////////////////////////////////
  /////////// GRAPH COPY ///////////
  //////////////////////////////////

  Graph graph = Graph();
  Edge newedge;

  Rcpp::IntegerVector state1 = mygraph["state1"];
  Rcpp::IntegerVector state2 = mygraph["state2"];
  Rcpp::CharacterVector typeEdge = mygraph["type"];
  Rcpp::NumericVector penalty = mygraph["penalty"];
  Rcpp::NumericVector parameter = mygraph["parameter"];

  for (int i = 0 ; i < mygraph.nrow(); i++)
    {graph << Edge(penalty[i], state1[i], state2[i], typeEdge[i], parameter[i]);}
  ///Include start and end states if specified

  graph.show();


  /////////////////////////////////////////////
  /////////// COST FUNCTION LOADING ///////////
  /////////////////////////////////////////////

  cost_coeff = coeff_factory(type);
  cost_min = min_factory(type);
  cost_argmin = argmin_factory(type);
  cost_intervalInterRoots = intervalInterRoots_factory(type);
  cost_age = age_factory(type);



  ///////////TO DELETE
  Bound bound = Bound(0, 0, false);
  Robust robust = Robust(1000,1000);

  // END TRANSFERT// END TRANSFERT// END TRANSFERT// END TRANSFERT// END TRANSFERT// END TRANSFERT
  // END TRANSFERT// END TRANSFERT// END TRANSFERT// END TRANSFERT// END TRANSFERT// END TRANSFERT

  ///////////
  /////////// OMEGA
  ///////////

  Omega omega(graph, bound, robust);
  omega.gfpop(data);

  ///////////
  /////////// RETURN
  ///////////

  List res = List::create(
    _["changepoints"] = omega.GetChangepoints(),
    _["states"] = omega.GetStates(),
    _["forced"] = omega.GetForced(),
    _["param"] = omega.GetParameters(),
    _["cost"] = omega.GetGlobalCost()
  );

  return res;
}


