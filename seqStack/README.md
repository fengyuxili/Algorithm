# 顺序栈
对应顺序栈的是链式栈<br>

顺序栈使用序列对栈进行保存，主要对栈进行的操作有：<br>
* isEmpty();//根据栈顶top的位置是否等于初始值进行布尔运算
* Top();//取栈顶元素
* isFull()//栈顶top==stackSize-1时栈满
* Push();//stack[++top] = item; 入栈,如果isFull()，changeStackSize改变栈空间
* Pop();//出栈stack[top--].~T();出栈时调用类型的析构，释放空间,如果剩余空间较多changeStackSize
* changeStackSize(T* &stack, const int oldSize, const int newSize);//先分配newSize的空间调用std::copy()<br>
将栈拷贝到新分配空间的顺序栈
* printStack()//从top开始打印栈内元素