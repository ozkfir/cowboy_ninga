#include "doctest.h"
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
using namespace std;
#include <sys/time.h>
#include "sources/point.hpp" //no need for other includes
#include "sources/Team.hpp" //no need for other includes

using namespace ariel;


TEST_CASE("point") {

    CHECK_NOTHROW(Point{0, 0});
    Point a(0, 0), b(0, 3), c(-3, -4);
    SUBCASE("check initialization") {
        CHECK(a.distance(b) == b.distance(a));
        CHECK(a.distance(b) == 3);
        CHECK(a.distance(c) == 5);
        CHECK(a.distance(a) == 0);
    }
    SUBCASE("distance() features")
    {struct timeval time_now{};
    for (int i = 0; i<2;i++) {

        struct timeval time_now{};
        gettimeofday(&time_now, nullptr);
        srand(time_now.tv_usec);
        Point d(::rand(), ::rand()), e(::rand(), ::rand()), f(::rand(), ::rand());
        CHECK(d.distance(e) + e.distance(f) >= d.distance(f));
        CHECK(d.distance(e) >= 0);
    }
    for (int i = 0; i < 3;++i) {
        double distance_ab = a.distance(b);
        a=Point::moveTowards(a, b, 1);
        CHECK(a.distance(b) < distance_ab);
    }

    Point g1(10, 0), g2(10, 0);
    int distance_g12 = g1.distance(g2);
    Point::moveTowards(g2, g1, 10);
    CHECK(g1.distance(g2) == distance_g12);


    CHECK_THROWS(Point::moveTowards(b, c, -5));
    CHECK_THROWS(Point::moveTowards(b,a,-2));


}
}

TEST_CASE("teams smart") {
    Point b(14, 0), a(0, 0), c(-20, 0), d(-20, 0);
    Cowboy * tom_1 = new Cowboy("Tom", d);
    Cowboy * tom_2 = new Cowboy("Tom", c);
    Cowboy * tom_3 = new Cowboy("Tom", b);
    TrainedNinja * sushi_1 = new TrainedNinja ("sushi", a);
    YoungNinja * sushi_2 = new YoungNinja("sushi", a);
    OldNinja * sushi_3 = new OldNinja("sushi", a);
    int distance = tom_1->distance(sushi_1);

    Team bb(tom_1);
    Team aa(sushi_1);
    bb.add(tom_2);
    aa.add(sushi_2);
    bb.add(tom_3);
    aa.add(sushi_3);

    bb.attack(&aa);
    CHECK_EQ(distance-14,sushi_1->distance(tom_1));
    CHECK_EQ(distance-12,sushi_2->distance(tom_1));
    CHECK_EQ(distance-8,sushi_3->distance(tom_1));
    for (int i = 0; i < 4; ++i) {
    aa.attack((&bb));
    }
    CHECK_FALSE(sushi_1->isAlive());

}

TEST_CASE("teams"){
    Point b(14,0),a(0,0),c(-20,0),d(200,0);
    Cowboy * tom_1 = new Cowboy("Tom", d);
    Cowboy * tom_2 = new Cowboy("Tom", c);
    Cowboy * tom_3 = new Cowboy("Tom", b);
    OldNinja* sushi_1 = new OldNinja("sushi", a);
    OldNinja * sushi_2 = new OldNinja("sushi", a);
    OldNinja * sushi_3 = new OldNinja("sushi", a);
    int distance=tom_1->distance(sushi_1);

    Team bb(tom_1);
    Team aa(sushi_1);
    bb.add(tom_2);
    aa.add(sushi_2);
    bb.add(tom_3);
    aa.add(sushi_3);

    bb.attack(&aa);
    CHECK_EQ(distance-14,sushi_1->distance(tom_1));
    CHECK_EQ(distance-12,sushi_2->distance(tom_1));
    CHECK_EQ(distance-8,sushi_3->distance(tom_1));
    for (int i = 0; i < 10; ++i) {
        bb.attack(&aa);
    }    int distance_s1=sushi_1->distance(tom_2);
    int distance_s2=sushi_2->distance(tom_2);
    int distance_s3=sushi_3->distance(tom_2);
    aa.attack(&bb);
    CHECK_EQ(distance_s1-14,sushi_1->distance(tom_2));
    CHECK_EQ(distance_s2-12,sushi_2->distance(tom_2));
    CHECK_EQ(distance_s3-8,sushi_3->distance(tom_2));
    for (int i = 0; i < 10; ++i) {
        bb.attack(&aa);
    }
    distance_s1=sushi_1->distance(tom_3);
    distance_s2=sushi_2->distance(tom_3);
    distance_s3=sushi_3->distance(tom_3);
    aa.attack(&bb);
    CHECK_EQ(distance_s1-14,sushi_1->distance(tom_3));
    CHECK_EQ(distance_s2-12,sushi_2->distance(tom_3));
    CHECK_EQ(distance_s3-8,sushi_3->distance(tom_3));

}



TEST_CASE("Character function") {
    Point b(14,0),a(0,0),c(-20,0);

    Cowboy *tom = new Cowboy("Tom", b);
    Cowboy *sushi = new Cowboy("sushi", c);
    SUBCASE("check initialization") {
        CHECK(tom->isAlive());
        CHECK(sushi->isAlive());
    }
    SUBCASE("distance() features") {
        CHECK(tom->distance(tom) == 0);
        CHECK(sushi->distance(sushi) == 0);
        CHECK(tom->distance(sushi) == c.distance(b));
    }


    SUBCASE("isalive") {
        tom->hit(50);
        sushi->hit(50);
        CHECK(tom->isAlive());
        CHECK(sushi->isAlive());
        tom->hit(1000);
        sushi->hit(1000);
        CHECK(!tom->isAlive());
        CHECK(!sushi->isAlive());
    }
    SUBCASE("get_name"){
        CHECK_EQ(tom->getName(), "Tom");
        CHECK_EQ(sushi->getName(), "sushi");
    }
}

TEST_CASE("Cowboy & Ninja function"){
    Point b(14,0),a(0,0),c(-20,0);

    Cowboy *tom = new Cowboy("Tom", b);
    TrainedNinja *sushi =new TrainedNinja("sushi", c);
    TrainedNinja *noam = new TrainedNinja("noam", c);

    SUBCASE("to cowboy has 6 bullet in stack") {
        for (int i = 0; i <6;++i) {
            CHECK_EQ(tom->hasboolets(), true);
            tom->shoot(sushi);
        }
        CHECK_EQ(tom->hasboolets(), false);
        tom->reload();
        CHECK_EQ(tom->hasboolets(), true);
        for (int i = 0; i <6;++i) {
            tom->shoot(sushi);
        }
        CHECK(!sushi->isAlive());
    }
    SUBCASE("check initialization") {
        TrainedNinja *trainedNinja =  new TrainedNinja("sushi", c);
        OldNinja *oldNinja = new OldNinja("noam", c);
        Cowboy *cowboy =new Cowboy("roy",c);
        YoungNinja *youngNinja =new YoungNinja("oo",c);
        for (int k = 0; k < 10; ++k) {
            tom->shoot(youngNinja);
        }
        for (int k = 0; k < 11; ++k) {
            tom->shoot(cowboy);
        }
        for (int k = 0; k < 12; ++k) {
            tom->shoot(trainedNinja);
        }
        for (int k = 0; k < 15; ++k) {
            tom->shoot(oldNinja);
        }
        CHECK(!youngNinja->isAlive());
        CHECK(!cowboy->isAlive());
        CHECK(!trainedNinja->isAlive());
        CHECK(!oldNinja->isAlive());
    }


    SUBCASE("getLocation") {
        CHECK(tom->getLocation().distance(c) == c.distance(b));
        CHECK(tom->getLocation().distance(b) == c.distance(c));
        CHECK(tom->getLocation().distance(b) == 0);
        CHECK(tom->getLocation().distance(tom->getLocation()) == 0);
    }
}
TEST_CASE("slase and shoot"){
    Point c(1,0),b(0,0);
    Cowboy * tom_live = new Cowboy("Tom", b);
    TrainedNinja * sushi_live = new TrainedNinja("sushi", c);
    Cowboy * tom_dead = new Cowboy("Tom", b);
    TrainedNinja * sushi_dead = new TrainedNinja("sushi", c);
    SUBCASE("shot his kind"){
        CHECK_NOTHROW(tom_live->shoot(tom_dead));
        CHECK_NOTHROW(sushi_live->slash(sushi_dead));
    }
    tom_dead->hit(1000);
    sushi_dead->hit(1000);

    for (int i = 0; i < 10; ++i) {
        sushi_live->move(tom_live);
sushi_live->slash(tom_live);
}
CHECK_FALSE(tom_live->isAlive());
    CHECK(sushi_live->isAlive());
}

//
//TEST_CASE("Team"){
//    Point c(1000,0),b(0,0);
//    Cowboy * tom_1 = new Cowboy("Tom", b);
//    TrainedNinja * sushi_1 = new TrainedNinja("sushi", c);
//    Cowboy * tom_2 = new Cowboy("Tom", b);
//    TrainedNinja * sushi_2 = new TrainedNinja("sushi", c);
//    Team aa(tom_1);
//    Team bb(sushi_1);
//    CHECK_THROWS(bb.add(tom_1));
//    CHECK_THROWS(aa.add(sushi_1));
//    bb.add(tom_2);
//    aa.add(sushi_2);
//    CHECK_THROWS(bb.add(tom_2));
//    CHECK_THROWS(aa.add(sushi_2));
//
//    for (int i = 0; i < 8; ++i) {
//        aa.add(new Cowboy("zoo", Point(i*1000, i*1000)));
//    }
//    for (int i = 0; i < 8; ++i) {
//        bb.add(new YoungNinja("Yogi", Point(i, i)));
//    }
//    CHECK_THROWS(aa.add(new Cowboy("Yogi", Point(0, 0))));
//    CHECK_THROWS(bb.add(new YoungNinja("Yogi", Point(0, 0))));
//
//
//    for (int i = 0; i < 10; ++i) {
//        aa.attack(&bb);
//        aa.attack(&bb);
//        bb.attack(&aa);
//        aa.print();
//        bb.print();
//    }
//    CHECK_EQ(bb.stillAlive(),0);
//    CHECK_EQ(aa.stillAlive(),10);
//}

