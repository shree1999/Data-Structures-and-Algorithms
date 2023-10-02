/*
This is an algorithm for the implementation of the Discrete Fourier Transform
or DFT. It is widely used in many signal and data processing applications and is mathematically
defined as a change of basis from the time domain to the frequency domain. It was first implemented
simply, as the Fourier Transform, by Joseph Fourier during his studies of the heat equation. 
This was made on the observation that an oscillatory measurement can be defined as a linear
combinations of simple sinusoids at different frequencies. Below is the implementation for the 
DFT:

The DFT is defined as the inner product of a signal to the complex plane C of intervals proportional to the
number of samples taken in the signal.

given a signal x(n) we can convert to the frequency X(k)

X(k) = SUM(x(n) * e^(i*theta)) with theta = (-j * 2pi * k * n) / N 
on the interval n = 0 to n = N - 1 for every value of k = 0 to k = N - 1

*/
#ifndef DFT_H
#define DFT_H

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

//Since the we know e^i * theta can be represented as euler's equation:
// e ^ i * theta = cos(theta) + i * sin(theta)
//The DFT must return two valued pairs as coordinates on the unit circle
//With the cos representing the Re or horizontal axis and sin representing
//the imaginary or veritcal axis
vector<pair<float,float>> DFT(vector<float> timeDomain)
{
    vector<pair<float, float>> frequencyDomain;

    //holds the position of the current DFT coefficient
    for(int i = 0; i < timeDomain.size(); i++)
    {

        //initialize two values to store the real and imaginary portion of
        //DFT coefficient
        float DFT_real = 0.0f;
        float DFT_imaginary = 0.0f;

        //Iterates over each value in the time domain signal 
        //and takes the sum of the products of the time domain value with
        //the complex exponential
        for(int j = 0; j < timeDomain.size(); j++)
        {
            //each value of splits the real and imaginary part
            DFT_real += timeDomain.at(j) * (cos((2*M_PI*i*j)/timeDomain.size()));
            DFT_imaginary += -1 * timeDomain.at(j) * sin((2*M_PI*i*j)/timeDomain.size());
        }

        //push next DFT coefficient to the vector
        frequencyDomain.push_back(make_pair(DFT_real, DFT_imaginary));
    }

    //return frequency representation of a signal
    return frequencyDomain;

}

#endif

