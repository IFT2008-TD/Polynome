//
// Created by Pascal Charpentier on 2022-05-27.
//

#ifndef POLYNOME_POLYNOME_H
#define POLYNOME_POLYNOME_H

#include <cstddef>
#include <initializer_list>
#include <vector>
#include <cassert>
#include <algorithm>

template<typename T>
class Polynome_Generique {
public:
    Polynome_Generique() = default ;

    virtual size_t degre () const = 0 ;
    virtual bool   estNul () const = 0 ;
    virtual T      eval (T x) const = 0 ;
    virtual T      lireCoefficient(size_t degre) const = 0 ;

    virtual ~Polynome_Generique() = default ;

};

template<typename T>
class Polynome_Vector : public Polynome_Generique<T> {

public:

    Polynome_Vector(std::initializer_list<T> l) : Polynome_Generique<T>(), coefficients(l) {
        assert(!coefficients.empty()) ;
    }

private:
    explicit Polynome_Vector(std::vector<T> v) : Polynome_Generique<T>(), coefficients(v.cbegin(), v.cend()) {
        assert(!coefficients.empty()) ;
    }

public:

    size_t degre () const override {
        size_t imax = 0 ;
        for (size_t i = 0; i < coefficients.size(); ++i) if (lireCoefficient(i) != 0)  imax = i ;
        return imax ;
    }

    bool estNul () const override {
        return (degre() == 0) && (lireCoefficient(0) == 0) ;
    }

    T eval (T x) const override {
        auto it = coefficients.rbegin() ;
        T sum = *it ;
        ++it ;
        while (it != coefficients.rend()) {
            sum = sum * x + (*it) ;
            ++it ;
        }
        return sum ;
    }

    T lireCoefficient (size_t exposant) const override {
        assert(exposant < coefficients.size()) ;
        return coefficients.at(exposant) ;
    }

    bool operator == (const Polynome_Vector<T>& rhs) const {
        if (degre() != rhs.degre()) return false ;
        for (size_t i = 0; i <= degre(); ++i) if (lireCoefficient(i) != rhs.lireCoefficient(i)) return false ;
        return true ;
    }

    bool operator + (const Polynome_Vector<T>& rhs) const {
        size_t degreMax = degre () ;
        size_t degreMin = rhs.degre() ;
        const Polynome_Vector<T> * adressePolynomeMax = this ;
        const Polynome_Vector<T> * adressePolynomeMin = &rhs ;

        if (degreMin > degreMax) {
            std::swap(degreMax, degreMin) ;
            std::swap(adressePolynomeMax, adressePolynomeMin) ;
        }

        std::vector<T> resultat(degreMax) ;

        for (size_t i = 0; i <= degreMax; ++i) {
            resultat.at(i) = adressePolynomeMax->lireCoefficient(i) ;
            if (i <= degreMin) resultat.at(i) += adressePolynomeMin->lireCoefficient(i) ;
        }
        return Polynome_Vector<T>(resultat) ;
    }




private:

    std::vector<T> coefficients ;


};
#endif //POLYNOME_POLYNOME_H
