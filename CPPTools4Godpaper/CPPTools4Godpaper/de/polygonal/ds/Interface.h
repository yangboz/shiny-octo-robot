//
//  Interface.h
//  CPPTools4Godpaper
//  @see http://www.codeguru.com/cpp/cpp/cpp_mfc/oop/article.php/c9989/Using-Interfaces-in-C.htm
//  Created by yangboz on 15-5-9.
//  Copyright (c) 2015年 GODPAPER. All rights reserved.
//

#ifndef CPPTools4Godpaper_Interface_h
#define CPPTools4Godpaper_Interface_h

#define Interface class

#define DeclareInterface(name) Interface name { \
public: \
virtual ~name() {}

#define DeclareBasedInterface(name, base) class name :
public base { \
    public: \
    virtual ~name() {}
    
#define EndInterface };
    
#define implements public

#endif
