// color.c (Simba 13.sept.97)

#include <ansi.h>

inherit F_CLEAN_UP;
//�޸ĳ�������
int main(object me,string arg)
{
    string cishu;
    object pet;
    if(!arg)
    {    
    if(!me->query("pets"))
    return notify_fail("�㻹û�г����أ�\n");
	if(!(pet=present(me->query("id")+" pet",environment(me))))
	return notify_fail("��ĳ��ﲻ�����ǰ���޷������֣�\n");
    return notify_fail(INPUTTXT("������", "petlong $txt#") + "\n");	
    }
    if(!me->query("pets"))
    return notify_fail("�㻹û�г����أ�\n");
    if (me->query("balance") < 100000)
	return notify_fail("��Ǯׯ���㣬���ܽ����޸����֣���Ҫ10���ƽ�\n");
    if(!(pet=present(me->query("id")+" pet",environment(me))))
	return notify_fail("��ĳ��ﲻ�����ǰ���޷������֣�\n");
    if (sscanf(arg,"%s",cishu) != 1)     
	return 1;	
    pet->set("name",cishu);
    me->add("balance",-100000);
    write(HIC"�������\n"NOR);
	
}
