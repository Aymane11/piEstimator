//========================================================================================
/*                               MONTE CARLO π Estimation                               *
 *                                 By : Aymane BOUMAAZA                                 */
//========================================================================================

#include <random>
#include <iostream>
#include <cmath>
using namespace std;
default_random_engine gen;
long double PI(int n){ 
    //initialising the number of points to zero
    int pts_in_circle = 0, pts_in_square = 0;
    uniform_real_distribution<double> uni_dist(0, 1);
    for (int i = 0; i < n; i++){
        //generating points coordinates
        double x = uni_dist(gen);
        double y = uni_dist(gen);
        double d = (x * x) + (y * y);
        //calculating the number of points inside the circle (distance(point,center)<1)
        if (d < 1)  pts_in_circle++;
        pts_in_square++;
    }
    return 4.0 * (double) pts_in_circle / pts_in_square;
}
int main(){
    int n;
    cout << "Number of points to generate = ";
    while(cin >> n){
        if(!n) break;
        cout << "pi (approx.) = " << PI(n)<< endl;
        cout << "Number of points to generate = ";
    }
    return 0;
}
