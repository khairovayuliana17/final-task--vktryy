#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <sstream>
#include "original.h"
#include "doppelganger.h"

TEST_CASE("Vampire basic functionality", "[Vampire]") {
    Vampire v("Дэймон", 170);

    SECTION("Initial state") {
        REQUIRE(v.getName() == "Дэймон");
        REQUIRE(v.getAge() == 170);
        REQUIRE(v.getIsAlive() == true);
        REQUIRE(v.getHungerLevel() == 100);
    }

    SECTION("Drinking blood") {
        v.drinkBlood();
        REQUIRE(v.getHungerLevel() == 75);

        std::ostringstream oss;
        std::streambuf* oldCout = std::cout.rdbuf(oss.rdbuf());
        v.drinkBlood();
        std::cout.rdbuf(oldCout);

        REQUIRE(oss.str() == "Дэймон пьёт кровь...\n");
    }

    SECTION("Dying") {
        v.die();
        REQUIRE(v.getIsAlive() == false);
    }
}

TEST_CASE("OriginalVampire functionality", "[OriginalVampire]") {
    OriginalVampire ov("Клаус", 1000);

    SECTION("Initial state") {
        REQUIRE(ov.getName() == "Клаус");
        REQUIRE(ov.getAge() == 1000);
        REQUIRE(ov.getIsAlive() == true);
        REQUIRE(ov.getSireLine() == 0);
    }

    SECTION("Compel ability") {
        std::ostringstream oss;
        std::streambuf* oldCout = std::cout.rdbuf(oss.rdbuf());
        ov.compel();
        std::cout.rdbuf(oldCout);

        REQUIRE(oss.str() == "Клаус использует силу принуждения!\n");
    }

    SECTION("Creating vampires") {
        ov.createVampire();
        REQUIRE(ov.getSireLine() == 1);

        std::ostringstream oss;
        std::streambuf* oldCout = std::cout.rdbuf(oss.rdbuf());
        ov.createVampire();
        std::cout.rdbuf(oldCout);

        REQUIRE(ov.getSireLine() == 2);
        REQUIRE(oss.str() == "Клаус создал нового вампира! Теперь в его линии 2 вампиров\n");
    }

    SECTION("Creating vampires when dead") {
        ov.die();
        REQUIRE(ov.getIsAlive() == false);

        std::ostringstream oss;
        std::streambuf* oldCout = std::cout.rdbuf(oss.rdbuf());
        ov.createVampire();
        std::cout.rdbuf(oldCout);

        REQUIRE(ov.getSireLine() == 0);
        REQUIRE(
            oss.str() == "Мёртвые вампиры не могут создавать новых. Вся кровная линия мертва\n");
    }
}

TEST_CASE("Doppelganger functionality", "[Doppelganger]") {
    Doppelganger d("Елена", 18, "Катерина");

    SECTION("Initial state") {
        REQUIRE(d.getName() == "Елена");
        REQUIRE(d.getAge() == 18);
        REQUIRE(d.getIsAlive() == true);
        REQUIRE(d.getOriginalName() == "Катерина");
        REQUIRE(d.getBloodMagicReserve() == 100);
    }

    SECTION("Confusing enemies") {
        std::ostringstream oss;
        std::streambuf* oldCout = std::cout.rdbuf(oss.rdbuf());
        d.confuseEnemy();
        std::cout.rdbuf(oldCout);

        REQUIRE(oss.str() == "Елена путает врагов, выдавая себя за Катерина\n");
    }

    SECTION("Decreasing blood magic reserve") {
        std::ostringstream oss;
        std::streambuf* oldCout = std::cout.rdbuf(oss.rdbuf());

        d.decreaseBloodMagicReserve();
        REQUIRE(d.getBloodMagicReserve() == 90);

        for (int i = 0; i < 8; i++) {
            d.decreaseBloodMagicReserve();
        }

        REQUIRE(d.getBloodMagicReserve() == 10);
        REQUIRE(d.getIsAlive() == false);

        std::cout.rdbuf(oldCout);

        REQUIRE(oss.str() == "Елена умер от потери магической крови!\n");
    }
}
