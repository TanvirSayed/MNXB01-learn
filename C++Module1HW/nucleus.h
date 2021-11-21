//nucleus.h
#ifndef nucleus_H
#define nucleus_H
#include <math.h>
#include <bits/stdc++.h>
class nucleus {
    public:
        nucleus() = default;
        nucleus(int proton, int neutron) : _proton{proton},_neutron{neutron} {}
        int _proton;
        int _neutron;

        int massNum() {
            return _proton + _neutron; 
        };
        double radius() {
            double A = _proton + _neutron;
            return 1.2 / pow(10,15) * std::cbrt(A); 
        };
        bool stable() {
            double Z = _proton;
            double A = _proton + _neutron;
            bool stable1 = false;
            if (Z*Z/A <= 35) {
                stable1 = true;
            };
            return stable1; 
        };
        auto alphaDecay() {
            const double mp = 927;
            const double mn = 928;
            const double av = 11;
            const double as = 22;
            const double ac = 33;
            const double aa = 44;
            const double ap = 55;
            double Z = _proton;
            double N = _neutron;
            double A = _proton + _neutron;
            double pair{0};
            if (A is even) {
                if (Z is even) {pair=...};
                else if (Z is odd) {pair=...};
            }
            double Ebind = 0 ;// formula
            double mass = 8 ;//

            return 0;



        };
};

#endif /* nucleus_H */
