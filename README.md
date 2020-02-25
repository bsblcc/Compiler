# Compiler
编译原理课程的作业项目. 实现了一个C编译器, 支持指针 数组 结构体 函数等基本语法. 输出是AT&T格式的汇编代码, 调用约定等等沿用的是linux x64下的abi.

这是我写了最久的一个作业项目. 前端的词法 语法分析因为作业规定, 用的是现成的yacc bison等工具. 
所以工作重心在生成显式的语法树AST之后. 中端的语意分析包括类型系统, 作用域上的符号表等等. 主要难点在于函数, 指针等语法之间的并用, 比如函数指针, 
使得类型系统的设计复杂.

后端那里又把带语意信息的AST翻译成三地址指令的中间语言
(我记得是三地址, 但是代码里命名是quad, 具体原因忘了), 并且划分基本块, 构成控制流图. 基于控制流图做了一些简单优化, 比如删除不可达的块, 合并多余块等等.

最后根据控制流图, 按照quad逐行解释成汇编代码. 这里还针对寄存器分配等问题做了简单优化, 比如在没有寄存器空闲时, 优先选择这样一个寄存器: 
它目前保存的内容在此基本块接下来的代码中用不到.

在设计上浪费了很多时间, 尤其是反复修改某些设计, 如类型系统等. 因为实现到后面才会发现前面的某些设计很别扭, 然后又要从头改.
