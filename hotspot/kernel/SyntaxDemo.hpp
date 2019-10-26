//
//  SyntaxDemo.hpp
//  hotspot
//
//  Created by GuanZF on 2019/9/26.
//  Copyright © 2019 gzfeng. All rights reserved.
//

#ifndef SyntaxDemo_hpp
#define SyntaxDemo_hpp

#include <stdio.h>

class SyntaxDemo {
public:
    static void run();
    static void syntax_test();
};

typedef class markOopDesc *markOop;

typedef class oopDesc *oop;

class markOopDesc {
public:
    long value() {
        return (long) this;
    }
};

class oopDesc {
private:
    markOop _mark;
public:
    markOop mark() {
        return _mark;
    }
    
    void set_mark(markOop mark) {
        _mark = mark;
    }
};


#endif /* SyntaxDemo_hpp */
