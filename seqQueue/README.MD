# 顺序队列 seq Queue 

* 使用链表存储的叫链式队列
* 队列 先进先出(FIFO) 后进后出(RIRO) 用于工作任务
* 队首队尾 Front Real<br>
* (rear+1) % capacity == front 队列满了
* int start = (front + 1) % capacity;//队首位置 判断有没有发生回绕<br>
  if(start < 2) // front默认为0,所以start<2时没有发生回绕 no wrap 否则就是回绕，<br>
  no wrap,直接copy到新空间;wrap 需要front~capacity copy一次,0~rearcopy一次
* /*if( rear = capacity-1)rear = 0;else rear++;*/<br>
  rear = (rear+1) % capacity;//与上面注释的代码效果一样 判断是否发生回绕
  
![image](https://github.com/fengyuxili/Algorithm/blob/master/seqQueue/seqQueue.PNG "sequence queue image")