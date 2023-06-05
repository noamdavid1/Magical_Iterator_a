#include "MagicalContainer.hpp"

namespace ariel
{

    MagicalContainer::MagicalContainer() {}
    MagicalContainer::MagicalContainer(MagicalContainer &other)
    {
        container = other.container;
    }
    MagicalContainer::~MagicalContainer() {}

    void MagicalContainer::addElement(int element)
    {
        container.emplace_back(element);
    }
    size_t MagicalContainer::size() const { return this->container.size(); }
    void MagicalContainer::removeElement(int element)
    {
        for (auto it = container.begin(); it != container.end(); it++)
        {
            if (*it == element)
            {
                container.erase(it);
                break;
            }
        }
    }
    //-----------------------------------------------------------------------------------

    MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer &container) : container(container), size_i(0)
    {
    }

    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other) : container(other.container), size_i(other.size_i)
    {
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const
    {
        return *this;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const
    {
        return AscendingIterator(container);
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
    {
        return *this;
    }

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const
    {
        return true;
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
    {
        return !(*this == other);
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const
    {
        return true;
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const
    {
        return true;
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
    {
        this->size_i++;
        return *this;
    }

    int MagicalContainer::AscendingIterator::operator*() const
    {
        return 0;
    }

    //---------------------------------------------------------------------------------------

    MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer &container, size_t foward_i, size_t backward_i) : container(container), foward_i(0), backward_i(backward_i)
    {
    }

    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other) : container(other.container), foward_i(other.foward_i), backward_i(other.backward_i)
    {
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const
    {
        return *this;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const
    {
        return SideCrossIterator(container, 0, container.size());
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
    {
        return *this;
    }

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
    {
        return true;
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
    {
        return !(*this == other);
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const
    {
        return true;
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const
    {
        return true;
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
    {
        return *this;
    }

    int MagicalContainer::SideCrossIterator::operator*() const
    {
        return 0;
    }
    //---------------------------------------------------------------------

    MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer &container) : container(container), size_i(0)
    {
    }

    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other) : container(other.container), size_i(other.size_i)
    {
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const
    {
        return *this;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() const
    {
        return PrimeIterator(container);
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
    {
        return *this;
    }

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
    {
        return true;
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
    {
        return !(*this == other);
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const
    {
        return true;
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const
    {
        return true;
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
    {
        this->size_i++;
        return *this;
    }

    int MagicalContainer::PrimeIterator::operator*() const
    {
        return 1;
    }
}
