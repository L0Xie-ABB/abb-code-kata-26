#define APPROVALS_GOOGLETEST
#include <ApprovalTests.hpp>

#include "GildedRose.h"
#include <ranges>

std::ostream &operator<<(std::ostream &os, const Item &obj)
{
    return os << "name: " << obj.name << ", sellIn: " << obj.sellIn
              << ", quality: " << obj.quality;
}

TEST(GildedRoseApprovalTests, VerifyFoo)
{
    std::vector<std::string> names{"Foo"};
    std::vector<int> sellIns{};
    for (int i = -10; i < 10; i++)
    {
        sellIns.push_back(i);
    }
    std::vector<int> qualities{};
    for (int i = 0; i < 51; i++)
    {
        qualities.push_back(i);
    }

    auto f = [](std::string name, int sellIn, int quality)
    {
        std::vector<Item> items = {Item(name, sellIn, quality)};
        GildedRose app(items);
        app.updateQuality();
        return items[0];
    };

    ApprovalTests::CombinationApprovals::verifyAllCombinations(f, names, sellIns,
                                                               qualities);
}

TEST(GildedRoseApprovalTests, VerifySulfuras)
{
    std::vector<std::string> names{"Sulfuras, Hand of Ragnaros"};
    std::vector<int> sellIns{};
    for (int i = -10; i < 10; i++)
    {
        sellIns.push_back(i);
    }
    std::vector<int> qualities{80};

    auto f = [](std::string name, int sellIn, int quality)
    {
        std::vector<Item> items = {Item(name, sellIn, quality)};
        GildedRose app(items);
        app.updateQuality();
        return items[0];
    };

    ApprovalTests::CombinationApprovals::verifyAllCombinations(f, names, sellIns,
                                                               qualities);
}

TEST(GildedRoseApprovalTests, VerifyBrie)
{
    std::vector<std::string> names{"Aged Brie"};
    std::vector<int> sellIns{};
    for (int i = -10; i < 10; i++)
    {
        sellIns.push_back(i);
    }
    std::vector<int> qualities{};
    for (int i = 0; i < 51; i++)
    {
        qualities.push_back(i);
    }

    auto f = [](std::string name, int sellIn, int quality)
    {
        std::vector<Item> items = {Item(name, sellIn, quality)};
        GildedRose app(items);
        app.updateQuality();
        return items[0];
    };

    ApprovalTests::CombinationApprovals::verifyAllCombinations(f, names, sellIns,
                                                               qualities);
}

TEST(GildedRoseApprovalTests, VerifyPass)
{
    std::vector<std::string> names{"Backstage passes to a TAFKAL80ETC concert"};
    std::vector<int> sellIns{};
    for (int i = -5; i < 15; i++)
    {
        sellIns.push_back(i);
    }
    std::vector<int> qualities{};
    for (int i = 0; i < 51; i++)
    {
        qualities.push_back(i);
    }

    auto f = [](std::string name, int sellIn, int quality)
    {
        std::vector<Item> items = {Item(name, sellIn, quality)};
        GildedRose app(items);
        app.updateQuality();
        return items[0];
    };

    ApprovalTests::CombinationApprovals::verifyAllCombinations(f, names, sellIns,
                                                               qualities);
}