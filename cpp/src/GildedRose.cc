#include "GildedRose.h"

using namespace std;

GildedRose::GildedRose(vector<Item> &items) : items(items)
{
}

void GildedRose::updateQuality()
{
    for (auto &item : items)
    {
        updateItem(item);
    }
}

void GildedRose::updateItem(Item &item)
{
    if (item.name != "Aged Brie" && item.name != "Backstage passes to a TAFKAL80ETC concert" && item.name != "Sulfuras, Hand of Ragnaros")
    {
        if (item.quality > 0)
        {
            item.quality = item.quality - 1;
        }

        item.sellIn--;
        if (item.sellIn < 0 && item.quality > 0)
        {
            item.quality = item.quality - 1;
        }
        return;
    }
    else if (item.name == "Backstage passes to a TAFKAL80ETC concert")
    {
        item.quality = item.quality + 1;

        if (item.sellIn < 11)
        {
            item.quality = item.quality + 1;
        }

        if (item.sellIn < 6)
        {
            item.quality = item.quality + 1;
        }

        if (item.quality > 50)
        {
            item.quality = 50;
        }

        item.sellIn = item.sellIn - 1;

        if (item.sellIn < 0)
        {
            item.quality = 0;
        }

        return;
    }
    else if (item.name == "Sulfuras, Hand of Ragnaros")
    {
        return;
    }
    else
    {
        if (item.quality < 50)
        {
            item.quality = item.quality + 1;
        }
    }

    if (item.name != "Sulfuras, Hand of Ragnaros")
    {
        item.sellIn = item.sellIn - 1;
    }

    if (item.sellIn < 0)
    {
        if (item.name != "Aged Brie")
        {
            if (item.name != "Backstage passes to a TAFKAL80ETC concert")
            {
                if (item.quality > 0)
                {
                    if (item.name != "Sulfuras, Hand of Ragnaros")
                    {
                        item.quality = item.quality - 1;
                    }
                }
            }
        }
        else
        {
            if (item.quality < 50)
            {
                item.quality = item.quality + 1;
            }
        }
    }
}
