#include<iostream>
#include "dft.h"

int main()
{
    vector<float> timeDomain;
    vector<pair<float, float>> frequencyDomain;

    //Here we define a simple function to implement 
    //This can be visualized as a sawtooth wave form
    //if you want to extend the length to represent 
    //a much more realistic sampling margin you can extend with Karplus-Strong Algorithm
    //stay tuned for this implementation
    for(float i = 0; i < 1.02; i += 0.02)
    {
        timeDomain.push_back(i - 0.5);
    }

    //Here we call the DFT implementation can be found in dft.h
    frequencyDomain = DFT(timeDomain);
    
    //print time domain coefficients
    for(int i = 0; i < timeDomain.size(); i++)
    {
        cout << timeDomain.at(i) << " ";
    }

    //place space between the output
    cout << endl;

    //print out absolute value or magnitude of complex DFT coefficients
    //here |a + bi| = sqrt(a^2 + b^2)
    for(int i = 0; i < timeDomain.size(); i++)
    {
        cout << sqrt(pow(frequencyDomain.at(i).first, 2) + pow(frequencyDomain.at(i).second, 2)) << " ";
    }
   
    return 0;
}