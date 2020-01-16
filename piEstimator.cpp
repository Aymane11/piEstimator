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
    int in_circle = 0, in_square = 0;
    uniform_real_distribution<double> uni_dist(0, 1);
    for (int i = 0; i < n; i++){
        double x = uni_dist(gen);
        double y = uni_dist(gen);
        double d = sqrt((x * x) + (y * y));
        //calculating the number of points inside the circle (distance(point,center)<1)
        if (d < 1)  in_circle++;
        in_square++;
    }
    return 4 * (double) in_circle / in_square;
}
int main(){
    int n=1;
    while (n > 0){
        cout << "number of points to generate = ";
        cin >> n;
        cout << PI(n)<< endl;
    }
    return 0;
}
