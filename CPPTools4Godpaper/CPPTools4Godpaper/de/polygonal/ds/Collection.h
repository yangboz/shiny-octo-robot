//
//  Collection.h
//  CPPTools4Godpaper
//  @see: https://github.com/yangboz/godpaper/blob/master/TheKnightErrant/src/de/polygonal/ds/Collection.as
//  Created by yangboz on 15-5-9.
//  Copyright (c) 2015年 GODPAPER. All rights reserved.
//

#ifndef CPPTools4Godpaper_Collection_h
#define CPPTools4Godpaper_Collection_h

#include "Interface.h"

    /**
     * A 'java-style' collection interface.
     */
//    public interface Collection
//    {
        /**
         * Determines if the collection contains a given item.
         *
         * @param obj The item to search for.
         *
         * @return True if the item exists, otherwise false.
         */
        function contains(obj:*):Boolean
        
        /**
         * Clears all items.
         */
        function clear():void
        
        /**
         * Initializes an iterator object pointing to the first item in the
         * collection.
         *
         * @return An iterator object.
         */
        function getIterator():Iterator
        
        /**
         * The total number of items.
         *
         * @return The size.
         */
        function get size():int;
        
        /**
         * Checks if the collection is empty.
         *
         * @return True if empty, otherwise false.
         */
        function isEmpty():Boolean
        
        /**
         * Converts the collection into an array.
         * 
         * @return An array.
         */
        function toArray():Array
//    }


#endif
