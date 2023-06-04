#include "MagicalContainer.hpp"
#include <cmath>
using namespace std;
bool isPrime(int num)
{
    if (num < 2)
    {
        return false;
    }
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}
namespace ariel
{
    /*______
    ( _____ )(  ___  )(  ____ \\__   __/(  ____ \(  ___  )( \        (  ____ \(  ___  )( (    /|\__   __/(  ___  )\__   __/( (    /|(  ____ \(  ____ )
    | () () || (   ) || (    \/   ) (   | (    \/| (   ) || (        | (    \/| (   ) ||  \  ( |   ) (   | (   ) |   ) (   |  \  ( || (    \/| (    )|
    | || || || (___) || |         | |   | |      | (___) || |        | |      | |   | ||   \ | |   | |   | (___) |   | |   |   \ | || (__    | (____)|
    | |(_)| ||  ___  || | ____    | |   | |      |  ___  || |        | |      | |   | || (\ \) |   | |   |  ___  |   | |   | (\ \) ||  __)   |     __)
    | |   | || (   ) || | \_  )   | |   | |      | (   ) || |        | |      | |   | || | \   |   | |   | (   ) |   | |   | | \   || (      | (\ (
    | )   ( || )   ( || (___) |___) (___| (____/\| )   ( || (____/\  | (____/\| (___) || )  \  |   | |   | )   ( |___) (___| )  \  || (____/\| ) \ \__
    |/     \||/     \|(_______)\_______/(_______/|/     \|(_______/  (_______/(_______)|/    )_)   )_(   |/     \|\_______/|/    )_)(_______/|/   \__/
    */
    void MagicalContainer::addElement(int element)
    {
        container.push_back(element);
        std::sort(container.begin(), container.end());
        if (isPrime(element))
        {
            primes.push_back(&container.back());
        }
    }

    void MagicalContainer::removeElement(int element)
    {
        auto it = std::find(container.begin(), container.end(), element);
        if (it == this->container.end())
            throw runtime_error("OUT OF BOUNDS\n");
        container.erase(it);
        primes.erase(std::remove(primes.begin(), primes.end(), &(*it)), primes.end());
    }

    int MagicalContainer::size()
    {

        return container.size();
    }
    /*(  ___  )(  ____ \(  ____ \(  ____ \( (    /|(  __  \ \__   __/( (    /|(  ____ \  \__   __/\__   __/(  ____ \(  ____ )(  ___  )\__   __/(  ___  )(  ____ )
      | (   ) || (    \/| (    \/| (    \/|  \  ( || (  \  )   ) (   |  \  ( || (    \/     ) (      ) (   | (    \/| (    )|| (   ) |   ) (   | (   ) || (    )|
      | (___) || (_____ | |      | (__    |   \ | || |   ) |   | |   |   \ | || |           | |      | |   | (__    | (____)|| (___) |   | |   | |   | || (____)|
      |  ___  |(_____  )| |      |  __)   | (\ \) || |   | |   | |   | (\ \) || | ____      | |      | |   |  __)   |     __)|  ___  |   | |   | |   | ||     __)
      | (   ) |      ) || |      | (      | | \   || |   ) |   | |   | | \   || | \_  )     | |      | |   | (      | (\ (   | (   ) |   | |   | |   | || (\ (
      | )   ( |/\____) || (____/\| (____/\| )  \  || (__/  )___) (___| )  \  || (___) |  ___) (___   | |   | (____/\| ) \ \__| )   ( |   | |   | (___) || ) \ \__
      |/     \|\_______)(_______/(_______/|/    )_)(______/ \_______/|/    )_)(_______)  \_______/   )_(   (_______/|/   \__/|/     \|   )_(   (_______)|/   \__/*/

    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &AscContainer) : AscContainer(AscContainer), curr(AscContainer.container.begin())
    {
    }

    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other) : AscContainer(other.AscContainer)
    {
        // other initialization code
    }
    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
    {
        // Do nothing - we can't reassign the reference member "container"
        return *this;
    }

    int MagicalContainer::AscendingIterator::operator*()
    {
        return 0; // Returns a dummy value
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
    {
        return *this; // Returns *this as a dummy value
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::begin()
    {
        return *this; // Returns *this as a dummy value
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::end()
    {
        return *this; // Returns *this as a dummy value
    }
    /*
    (  ____ \\__   __/(  __  \ (  ____ \(  ____ \(  ____ )(  ___  )(  ____ \(  ____ \  \__   __/\__   __/(  ____ \(  ____ )(  ___  )\__   __/(  ___  )(  ____ )
    | (    \/   ) (   | (  \  )| (    \/| (    \/| (    )|| (   ) || (    \/| (    \/     ) (      ) (   | (    \/| (    )|| (   ) |   ) (   | (   ) || (    )|
    | (_____    | |   | |   ) || (__    | |      | (____)|| |   | || (_____ | (_____      | |      | |   | (__    | (____)|| (___) |   | |   | |   | || (____)|
    (_____  )   | |   | |   | ||  __)   | |      |     __)| |   | |(_____  )(_____  )     | |      | |   |  __)   |     __)|  ___  |   | |   | |   | ||     __)
          ) |   | |   | |   ) || (      | |      | (\ (   | |   | |      ) |      ) |     | |      | |   | (      | (\ (   | (   ) |   | |   | |   | || (\ (
    /\____) |___) (___| (__/  )| (____/\| (____/\| ) \ \__| (___) |/\____) |/\____) |  ___) (___   | |   | (____/\| ) \ \__| )   ( |   | |   | (___) || ) \ \__
    \_______)\_______/(______/ (_______/(_______/|/   \__/(_______)\_______)\_______)  \_______/   )_(   (_______/|/   \__/|/     \|   )_(   (_______)|/   \__/*/
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &SideCrossCont) : SideCrossCont(SideCrossCont)
    {
        // other initialization code
    }

    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other) : SideCrossCont(other.SideCrossCont)
    {
        // other initialization code
    }
    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
    {
        // Do nothing - we can't reassign the reference member "container"
        return *this;
    }

    int &MagicalContainer::SideCrossIterator::operator*()
    {
        static int dummy = 0;
        return dummy; // Returns a reference to a dummy variable
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
    {
        return *this; // Returns *this as a dummy value
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::begin()
    {
        return *this; // Returns *this as a dummy value
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::end()
    {
        return *this; // Returns *this as a dummy value
    }
    /*
     _______  _______ _________ _______  _______   __________________ _______  _______  _______ _________ _______  _______
    (  ____ )(  ____ )\__   __/(       )(  ____ \  \__   __/\__   __/(  ____ \(  ____ )(  ___  )\__   __/(  ___  )(  ____ )
    | (    )|| (    )|   ) (   | () () || (    \/     ) (      ) (   | (    \/| (    )|| (   ) |   ) (   | (   ) || (    )|
    | (____)|| (____)|   | |   | || || || (__         | |      | |   | (__    | (____)|| (___) |   | |   | |   | || (____)|
    |  _____)|     __)   | |   | |(_)| ||  __)        | |      | |   |  __)   |     __)|  ___  |   | |   | |   | ||     __)
    | (      | (\ (      | |   | |   | || (           | |      | |   | (      | (\ (   | (   ) |   | |   | |   | || (\ (
    | )      | ) \ \_____) (___| )   ( || (____/\  ___) (___   | |   | (____/\| ) \ \__| )   ( |   | |   | (___) || ) \ \__
    |/       |/   \__/\_______/|/     \|(_______/  \_______/   )_(   (_______/|/   \__/|/     \|   )_(   (_______)|/   \__/
                                                                                                                       */
    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &PrimeCont) : PrimeCont(PrimeCont)
    {
        // other initialization code
    }

    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other) : PrimeCont(other.PrimeCont)
    {
        // other initialization code
    }
    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
    {
        // Do nothing - we can't reassign the reference member "container"
        return *this;
    }

    int &MagicalContainer::PrimeIterator::operator*()
    {
        static int dummy = 0;
        return dummy; // Returns a reference to a dummy variable
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
    {
        return *this; // Returns *this as a dummy value
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::begin()
    {
        return *this; // Returns *this as a dummy value
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::end()
    {
        return *this; // Returns *this as a dummy value
    }
} // namespace ariel