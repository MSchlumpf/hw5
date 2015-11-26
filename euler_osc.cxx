/* Homework 5
 * solves linear harmonic oscillator
 * 
 * Written by: Michael Stumpf
 */

#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <fstream>


using namespace std;

int main(){
  double t0 = 0;		// start time
  double Pi = M_PI;		// value pi
  double tEnd = 20*Pi;		// end time
  double dt = Pi/100;		// time steps
  int N = (tEnd-t0)/dt+1;	// number of calculations
  double t = 0, temp1, temp2;	// some variables
  double yf[2], yb[2], ya[2];	// arrays for forward, backward and analytical solution
  
    yf[0] = 1;	// x(0)		// start values....
    yf[1] = 0;	// xdot(0)
    yb[0] = 1;	// x(0)
    yb[1] = 0;	// xdot(0)
    ya[0] = 1;	// x(0)
    ya[1] = 0;	// xdot(0)
  
    ofstream forout("forward.txt");	// opening files for saving
    ofstream backout("backward.txt"); 
    ofstream anaout("analytical.txt");
    
    forout 	<< t << "\t" << yf[0] << "\t" << yf[1] << endl;	// writes start values in files
    backout 	<< t << "\t" << yb[0] << "\t" << yb[1] << endl; 
    anaout 	<< t << "\t" << ya[0] << "\t" << ya[1] << endl;
    
    for(int i=0; i<N; i++){	// for-loop for N-1 calculations
      t = (i+1)* dt;		// calculates time
      
      temp1 = yf[0];		// storing some temporal values
      temp2 = yf[1];
      yf[0] = 1*	temp1 + dt *	temp2;	// calculates forward solution
      yf[1] = -dt*	temp1 + 1 *	temp2;
      forout 	<< t << "\t" << yf[0] << "\t" << yf[1] << endl;
      
      temp1 = yb[0];		// storing some temporal values
      temp2 = yb[1];
      yb[0] = (temp1+dt*temp2)/(1+dt*dt);	// calculates backward solution
      yb[1] = (temp2-dt*temp1)/(1+dt*dt);
      backout 	<< t << "\t" << yb[0] << "\t" << yb[1] << endl; 
      
      ya[0] = cos(t);				// calculates analytical solution
      ya[1] = -sin(t);
      anaout 	<< t << "\t" << ya[0] << "\t" << ya[1] << endl;
    }
    forout.close();
    backout.close();			// close files
    anaout.close();
  
    return 0;
  
}