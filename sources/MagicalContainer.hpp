#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace ariel
{
    class MagicalContainer
    {
    private:
        vector<int> container;

    public:
        MagicalContainer();                        // defult constructor.
        MagicalContainer(MagicalContainer &other); // copy constructor.
        ~MagicalContainer();                       // destructor.

        void addElement(int element);
        size_t size() const;
        void removeElement(int element);
        //-----------------------------------------------------

        class AscendingIterator
        {
        private:
            const MagicalContainer &container;
            size_t size_i;

        public:
            AscendingIterator(const MagicalContainer &container);
            AscendingIterator(const AscendingIterator &other);

            AscendingIterator begin() const;
            AscendingIterator end() const;

            AscendingIterator &operator=(const AscendingIterator &other);
            bool operator==(const AscendingIterator &other) const;
            bool operator!=(const AscendingIterator &other) const;
            bool operator>(const AscendingIterator &other) const;
            bool operator<(const AscendingIterator &other) const;

            AscendingIterator &operator++();
            int operator*() const;
        };

        //------------------------------------------------------

        class SideCrossIterator
        {

        private:
            const MagicalContainer &container;
            size_t foward_i;
            size_t backward_i;

        public:
            SideCrossIterator(const MagicalContainer &container, size_t foward_i = 0, size_t backward_i = 0);
            SideCrossIterator(const SideCrossIterator &other);

            SideCrossIterator begin() const;
            SideCrossIterator end() const;

            SideCrossIterator &operator=(const SideCrossIterator &other);
            bool operator==(const SideCrossIterator &other) const;
            bool operator!=(const SideCrossIterator &other) const;
            bool operator>(const SideCrossIterator &other) const;
            bool operator<(const SideCrossIterator &other) const;

            SideCrossIterator &operator++();
            int operator*() const;
        };
        //-------------------------------------------------------------
        class PrimeIterator
        {
        private:
            const MagicalContainer &container;
            size_t size_i;

            // bool isPrime(int num);

        public:
            PrimeIterator(const MagicalContainer &container);
            PrimeIterator(const PrimeIterator &other);

            PrimeIterator begin() const;
            PrimeIterator end() const;

            PrimeIterator &operator=(const PrimeIterator &other);
            bool operator==(const PrimeIterator &other) const;
            bool operator!=(const PrimeIterator &other) const;
            bool operator>(const PrimeIterator &other) const;
            bool operator<(const PrimeIterator &other) const;

            PrimeIterator &operator++();
            int operator*() const;
        };
    };
}
