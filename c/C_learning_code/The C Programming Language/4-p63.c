//�����沨����ʾ����ʹ��ջʵ�ּ���������(+/-/*//)
/*
�沨������ʽ�ֽ�����׺����ʽ����ͨ���ı���ʽ�У���Ԫ���������������֮��ص������������֮�䣬���ֱ�ʾ��Ҳ��Ϊ��׺��ʾ�������߼�ѧ��J.Lukasiewicz��1929���������һ�ֱ�ʾ����ʽ�ķ��������˷�����ÿһ��������������������֮�󣬹ʳ�Ϊ��׺��ʾ��
a+b ---> a,b,+
a+(b-c) ---> a,b,c,-,+
a+(b-c)*d ---> a,b,c,-,d,*,+
a+d*(b-c)--->a,d,b,c,-,*,+
1����һ���������ʽת����Ϊ�沨������ʽ
��������ջS1��S2��S1������ű���ʽ��S2������ʱ���������������ɺ󣬸�ջ����յġ�
��1����������������֣�ֱ�ӽ�ջS1
��2������������������ţ���ջS2
��3������������������ţ���S2�е������ȫ����ջѹ��S1�У�ע�����Ų�ѹ��
��4����������������
         1.�����ʱջS2Ϊ�գ���ֱ�ӽ���������뵽ջS2�У�
         2.�����ʱջS2��Ϊ�գ���ǰ����������ȼ����ڵ���ջ������������ȼ�����ôֱ����ջS2��
         3.�����ʱջS2��Ϊ�գ���ǰ����������ȼ�С��ջ������������ȼ�����ջ�������һֱ��ջѹ�뵽ջS1�У�  ֱ��ջΪ�ջ�������һ������������ȼ�С�ڵ��ڵ�ǰ����������������ȼ���Ȼ�󽫸������ѹ�뵽ջS2�С�    
��5�������������������ʽ֮�����ջS2����Ȼ�������������ô����Щ��������γ�ջѹ�뵽ջS1�У�ֱ��ջΪ�ա�
2�������沨������ʽ��ֵ
ά��һ�����ջS3����ջ����ŵ��Ǳ���ʽ��ֵ���������ҵı���ջS1
��1����������������֣�ֱ�ӽ�����ѹ�뵽S3��
��2������������ǵ�Ŀ�������ȡS3ջ����һ��Ԫ�ؽ�������֮�󣬽����ѹ�뵽ջS3��
��3�������������˫Ŀ�������ȡS3ջ��������Ԫ�أ����ȳ�ջ�����󣬺��ջ�����ҽ���˫Ŀ������ļ��㣬�����ѹ�뵽S3��
����������ջS1�����S3�е�ֵ�����沨������ʽ��ֵ��
*/