// color.c (Simba 13.sept.97)

#include <ansi.h>

inherit F_CLEAN_UP;
//�޸���������
int main(object me,string arg)
{
    string cishu;
    object kaijia;
    if(!arg)
    {    
    if(!me->query("kaijias"))
    return notify_fail("�㻹û�������أ�\n");
    return notify_fail(INPUTTXT("������", "kaijialong $txt#") + "\n");	
    }
    if(!me->query("kaijias"))
    return notify_fail("�㻹û�������أ�\n");
    if (me->query("yuanbao") < 1000)
	return notify_fail("��Ǯׯ���㣬���ܽ����޸����֣���Ҫ1000��ʯ��\n");
    if (sscanf(arg,"%s",cishu) != 1)     
	return 1;	
    kaijia->set("name",cishu);
    me->add("yuanbao",-1000);
    write(HIC"�������\n"NOR);
	
}
