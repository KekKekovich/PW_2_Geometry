#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <ctime>
#include <cmath>
#include <fstream>
#include <Random.h>

RandomSpectre::RandomSpectre(double mu, double sigma) : mu(mu), sigma(sigma) {}

double RandomSpectre::pdf(double mu, double sigma, double x) {    // Probability density function
    return ( 1 / sigma / sqrt(2 * Pi)) * exp( -(x - mu) * (x - mu) / 2 / sigma / sigma );
}

double RandomSpectre::Rand(double fMin, double fMax) {
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

void RandomSpectre::print (std::vector <double> A) {
    for (int i = 0; i < A.size(); i++) {
        std::cout << A[i] << ", ";
    }
    std::cout << std::endl;
}

double RandomSpectre::Mean(std::vector <double> A) {
    double sum = 0;
    for (double i = 0; i < A.size(); i++) {
        sum += A[i];
    }
    return ( sum / A.size() );

}

double RandomSpectre::Variance(std::vector <double> A) {
    double var = 0;
    for (double i = 0; i < A.size(); i++) {
        var += pow( (A[i] - Mean(A)), 2);
    }
    return var / (A.size() - 1);
}

std::vector <double> RandomSpectre::RandomVariate(double a, double b, double h, int N) {

    srand(time(0));

    std::vector <double> P1;
    std::vector <double> X;

    for (double i = a; i <= b; i += h) {
        P1.push_back( pdf(mu, sigma, i) );
        X.push_back(i);
    }

//    print(P1);

    double sum = 0;
    for (double i = 0; i < P1.size(); i++) {
        sum += P1[i];
    }
//    std::cout << "SUM: " << sum << std::endl; // Без нормировки

    double sum1 = 0;
    std::map <double, double> M1;
    for (double i = 0; i < P1.size(); i++) {
        sum1 += ( P1[i] / sum);
        M1.emplace(sum1, X[i]);
//        std::cout << sum1 << "  |  " << X[i] << std::endl;
    }
//    std::cout << std::endl;

    std::vector <double> POINTS;

    for (int i = 0;i<N;i++) {
        POINTS.push_back(M1.lower_bound(Rand(0,1)) -> second);
//        std::cout << POINTS[i] << ", ";
    }

    return POINTS;
}
