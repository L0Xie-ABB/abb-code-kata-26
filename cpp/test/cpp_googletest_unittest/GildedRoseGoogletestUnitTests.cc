#include <gtest/gtest.h>
#include "GildedRose.h"

TEST(GildedRoseTest, Foo)
{
    std::vector<Item> items;
    items.push_back(Item("Sulfuras, Hand of Ragnaros", 1000, 80));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ("Sulfuras, Hand of Ragnaros", app.items[0].name);
    EXPECT_EQ(1000, app.items[0].sellIn);
    EXPECT_EQ(80, app.items[0].quality);
}

TEST(GildedRoseTest, PassTenPlus)
{
    std::vector<Item> items;
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 15, 10));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ("Backstage passes to a TAFKAL80ETC concert", app.items[0].name);
    EXPECT_EQ(14, app.items[0].sellIn);
    EXPECT_EQ(11, app.items[0].quality);
}

TEST(GildedRoseTest, PassTenMinus)
{
    std::vector<Item> items;
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 9, 10));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ("Backstage passes to a TAFKAL80ETC concert", app.items[0].name);
    EXPECT_EQ(8, app.items[0].sellIn);
    EXPECT_EQ(12, app.items[0].quality);
}

TEST(GildedRoseTest, PassFiveMinus)
{
    std::vector<Item> items;
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 4, 10));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ("Backstage passes to a TAFKAL80ETC concert", app.items[0].name);
    EXPECT_EQ(3, app.items[0].sellIn);
    EXPECT_EQ(13, app.items[0].quality);
}

TEST(GildedRoseTest, PassPassed)
{
    std::vector<Item> items;
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 0, 10));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ("Backstage passes to a TAFKAL80ETC concert", app.items[0].name);
    EXPECT_EQ(-1, app.items[0].sellIn);
    EXPECT_EQ(0, app.items[0].quality);
}