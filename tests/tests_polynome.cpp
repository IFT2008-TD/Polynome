//
// Created by Pascal Charpentier on 2022-05-27.
//

#include "gtest/gtest.h"
#include "Polynome.h"

class Polynome_Vector_Test : public ::testing::Test {
protected:
    Polynome_Vector_Test() : pol_0({0}), pol_0000({0, 0, 0, 0}), pol_1({1}), pol_quad({1, 2, 3}), pol_quad_plus({1, 2, 3, 0, 0, 0}), pol_cub({4, 5, 6, 7}) {}

    Polynome_Vector<double> pol_0 ;
    Polynome_Vector<double> pol_0000 ;
    Polynome_Vector<double> pol_1 ;
    Polynome_Vector<double> pol_quad ;
    Polynome_Vector<double> pol_quad_plus ;
    Polynome_Vector<double> pol_cub ;
};

TEST_F(Polynome_Vector_Test, degre) {
    EXPECT_EQ(0, pol_0.degre()) ;
    EXPECT_EQ(0, pol_1.degre()) ;
    EXPECT_EQ(2, pol_quad.degre()) ;
    EXPECT_EQ(2, pol_quad_plus.degre()) ;
    EXPECT_EQ(3, pol_cub.degre()) ;
}

TEST_F(Polynome_Vector_Test, estNul) {
    EXPECT_TRUE(pol_0.estNul()) ;
    EXPECT_TRUE(pol_0000.estNul()) ;
    EXPECT_FALSE(pol_1.estNul()) ;
    EXPECT_FALSE(pol_quad_plus.estNul()) ;
}

TEST_F(Polynome_Vector_Test, lireCoefficient) {
    EXPECT_EQ(0, pol_0.lireCoefficient(0)) ;
    EXPECT_EQ(1, pol_1.lireCoefficient(0)) ;
    EXPECT_EQ(1, pol_quad.lireCoefficient(0)) ;
    EXPECT_EQ(2, pol_quad.lireCoefficient(1)) ;
    EXPECT_EQ(0, pol_quad_plus.lireCoefficient(5)) ;
    EXPECT_EQ(7, pol_cub.lireCoefficient(3)) ;
}

TEST_F(Polynome_Vector_Test, eval) {
    EXPECT_EQ(0, pol_0.eval(3)) ;
    EXPECT_EQ(1, pol_1.eval(45)) ;
    EXPECT_EQ(17, pol_quad.eval(2)) ;
    EXPECT_EQ(17, pol_quad_plus.eval(2)) ;
    EXPECT_EQ(1, pol_quad.eval(0)) ;
}

TEST_F(Polynome_Vector_Test, operateur_egalite_poynomes_egaux) {
    EXPECT_TRUE(pol_quad == pol_quad) ;
    EXPECT_TRUE(pol_quad == pol_quad_plus) ;
}

TEST_F(Polynome_Vector_Test, operateur_egalite_polynomes_degre_0) {
    EXPECT_TRUE(pol_0 == pol_0) ;
    EXPECT_TRUE(pol_0 == pol_0000) ;
}


