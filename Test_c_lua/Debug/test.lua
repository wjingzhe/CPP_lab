--���������������������������ԣ����Ҹ��������Եĳ�ʼֵ��
Class = {x=0,y=0}
--������ض���Ԫ�������������˵������䣬�������һ���ࡣ����Ľ��ͣ���ٶȡ�
Class.__index = Class
--�����壬������������������ģ�ϰ���Ը�Ϊnew()
function Class:new(x,y)
        local self = {}  --��ʼ��self�����û����䣬��ô���������Ķ���ı䣬�������󶼻�ı�
        setmetatable(self, Class)  --��self��Ԫ���趨ΪClass
        self.x = x   --����ֵ��ʼ��
        self.y = y
                     return self  --��������
end
--���ﶨ�������������
function Class:test()
    print(self.x,self.y)
end
function Class:plus()
    self.x = self.x + 1
    self.y = self.y + 1
end
a = Class:new(10,20)
a:test()
b = Class:new(11,23)
b:test()
b:plus()
b:test()
