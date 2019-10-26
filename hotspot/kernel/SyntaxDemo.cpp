//
//  SyntaxDemo.cpp
//  hotspot
//
//  Created by GuanZF on 2019/9/26.
//  Copyright © 2019 gzfeng. All rights reserved.
//

#include "SyntaxDemo.hpp"
#include <iostream>

using namespace std;

//
// typedef int *INT;
// INT i = INT(12);
// 相当于
// int *i = (int *) (12);
//

typedef SyntaxDemo *Syntax;

void SyntaxDemo::run() {
    
    markOop mark = markOop(0x11);
    
    
    oop o = oop(new oopDesc());
    
    o->set_mark(mark);
    
    cout << hex << mark->value() << endl;
    
    cout << hex << o->mark() << endl;
    
    Syntax s = Syntax(12);
    
    cout << (long) s << endl;
}

// ##表示字符连接 i##nt <==> int
#define INT i##nt

void SyntaxDemo::syntax_test() {
    INT i = 10;
    
    cout << i << endl;
}

