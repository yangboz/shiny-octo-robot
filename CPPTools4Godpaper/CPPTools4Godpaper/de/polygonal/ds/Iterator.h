//
//  Iterator.h
//  CPPTools4Godpaper
//  @see:https://github.com/yangboz/godpaper/blob/master/TheKnightErrant/src/de/polygonal/ds/Iterator.as
//  Created by yangboz on 15-5-9.
//  Copyright (c) 2015年 GODPAPER. All rights reserved.
//

#ifndef CPPTools4Godpaper_Iterator_h
#define CPPTools4Godpaper_Iterator_h

#include "Interface.h"
/**
 * A 'java-style' iterator interface.
 */
//public interface Iterator
//{
DeclareInterface(Iterator)

    /**
     * Returns the current item and moves the iterator to the next item
     * in the collection. Note that the next() method returns the
     * <i>first</i> item in the collection when it's first called.
     *
     * @return The next item in the collection.
     */
//    function next():*
virtual Obj next();
    /**
     * Checks if a next item exists.
     *
     * @return True if a next item exists, otherwise false.
     */
//    function hasNext():Boolean
virtual bool hasNext();
    /**
     * Moves the iterator to the first item in the collection.
     */
//    function start():void
virtual void start();
    /**
     * Grants access to the current item being referenced by the iterator.
     * This provides a quick way to read or write the current data.
     */
//    function get data():*
virtual Obj getData();
    /**
     * @private
     */
//    function set data(obj:*):void
virtual void setData(Obj value);
//}
EndInterface

#endif
