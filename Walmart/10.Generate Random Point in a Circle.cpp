  double x_c, y_c, r;
    Solution(double radius, double x_center, double y_center) {
        x_c = x_center;
        y_c = y_center;
        r = radius;
          srand(time(0));
    }
    
    double random(){
        return (double)rand() / RAND_MAX; // for generating random points between 0 to 1
    }
    
    vector<double> randPoint() {
        double x, y, l = sqrt(random())*r, deg = 2*M_PI*random();
        x = x_c + l*cos(deg);
        y = y_c + l*sin(deg);

        return {x,y};
    }
