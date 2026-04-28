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
