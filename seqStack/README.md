# ˳��ջ
��Ӧ˳��ջ������ʽջ<br>

˳��ջʹ�����ж�ջ���б��棬��Ҫ��ջ���еĲ����У�<br>
* isEmpty();//����ջ��top��λ���Ƿ���ڳ�ʼֵ���в�������
* Top();//ȡջ��Ԫ��
* isFull()//ջ��top==stackSize-1ʱջ��
* Push();//stack[++top] = item; ��ջ,���isFull()��changeStackSize�ı�ջ�ռ�
* Pop();//��ջstack[top--].~T();��ջʱ�������͵��������ͷſռ�,���ʣ��ռ�϶�changeStackSize
* changeStackSize(T* &stack, const int oldSize, const int newSize);//�ȷ���newSize�Ŀռ����std::copy()<br>
��ջ�������·���ռ��˳��ջ
* printStack()//��top��ʼ��ӡջ��Ԫ��