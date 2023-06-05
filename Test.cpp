#include "doctest.h"
#include "sources/MagicalContainer.hpp"

#include <stdexcept>

using namespace ariel;

TEST_CASE("MagicalContainer tests")
{
    MagicalContainer container;
    CHECK_NOTHROW(container.addElement(7));
    CHECK_NOTHROW(container.removeElement(7));
    CHECK_THROWS(container.removeElement(7));

    container.addElement(1);
    container.addElement(2);
    CHECK_EQ(container.size(), 2);

    container.removeElement(2);
    CHECK_EQ(container.size(), 1);
    CHECK_THROWS(container.removeElement(5));
}

TEST_CASE("AscendingItarator tests")
{
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    MagicalContainer::AscendingIterator Ascontainer(container);

    auto it = Ascontainer.begin();
    CHECK_EQ(*it, 1);
    CHECK_NOTHROW(++it);
    CHECK_EQ(*it, 2);
    CHECK_NOTHROW(++it);
    CHECK_EQ(*it, 3);
    CHECK_THROWS(++it);

    CHECK(*Ascontainer.begin() < *Ascontainer.end());
    CHECK_FALSE(*Ascontainer.begin() > *Ascontainer.end());
    CHECK(*Ascontainer.begin() != *Ascontainer.end());
    CHECK_FALSE(*Ascontainer.begin() == *Ascontainer.end());
}

TEST_CASE("SideCrossIterator tests")
{
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    MagicalContainer::SideCrossIterator Sidecontainer(container);

    auto it = Sidecontainer.begin();
    CHECK_EQ(*it, 1);
    CHECK_NOTHROW(++it);
    CHECK_EQ(*it, 4);
    CHECK_NOTHROW(++it);
    CHECK_EQ(*it, 2);
    CHECK_NOTHROW(++it);
    CHECK_EQ(*it, 3);
    CHECK_THROWS(++it);

    CHECK(*Sidecontainer.begin() < *Sidecontainer.end());
    CHECK_FALSE(*Sidecontainer.begin() > *Sidecontainer.end());
    CHECK(*Sidecontainer.begin() != *Sidecontainer.end());
    CHECK_FALSE(*Sidecontainer.begin() == *Sidecontainer.end());
}

TEST_CASE("PrimeIterator tests")
{
    MagicalContainer container, container2;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(5);
    container.addElement(6);
    container.addElement(7);
    container.addElement(11);

    container2.addElement(4);
    container2.addElement(6);
    container2.addElement(8);

    MagicalContainer::PrimeIterator Pricontainer(container);
    MagicalContainer::PrimeIterator Pricontainer2(container2);

    auto it = Pricontainer.begin();
    CHECK_EQ(*it, 2);
    CHECK_NOTHROW(++it);
    CHECK_EQ(*it, 3);
    CHECK_NOTHROW(++it);
    CHECK_EQ(*it, 5);
    CHECK_NOTHROW(++it);
    CHECK_EQ(*it, 7);
    CHECK_NOTHROW(++it);
    CHECK_EQ(*it, 11);
    CHECK_THROWS(++it);

    CHECK(*Pricontainer.begin() < *Pricontainer.end());
    CHECK_FALSE(*Pricontainer.begin() > *Pricontainer.end());
    CHECK(*Pricontainer.begin() != *Pricontainer.end());
    CHECK_FALSE(*Pricontainer.begin() == *Pricontainer.end());

    CHECK(&Pricontainer2 == nullptr);
}
