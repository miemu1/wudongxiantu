// summon. ȡ�ر���

#include <ansi.h>
#include <command.h>

inherit F_CLEAN_UP;

int main(object me, string str)
{
	object weapon;
	object gold;
	object *inv;
	int i;
    me = this_player();
	inv = all_inventory(me);
	if((!me->query("weapon/make")) ){
		say("�㻹û�������������ٻ�ʲô��\n");
		return 1;
	}
	for(i=0; i<sizeof(inv); i++) {
        if((int)(inv[i]->query("weapon_prop")&&inv[i]->query("ownmake")))
		{
			tell_object(me,sprintf(GRN"�����ϲ�����������\n"NOR));
	return 1;
		}


        if(me->is_busy())
		{
			tell_object(me,sprintf(GRN"����һ��������û����ɡ�\n"NOR));
	return 1;
		}


	if (me->query("weapon/type")) {
		switch((string)me->query("weapon/type"))
		{
			case "��":
			weapon = new("/d/npc/m_weapon/weapon/m_sword");
			weapon->move(me);
        me->start_busy(5);
		{
			tell_object(me,sprintf(GRN"�����ٻ��ɹ�!��\n"NOR));
	return 1;
		}
			case "��":
			weapon = new("/d/npc/m_weapon/weapon/m_blade");
			weapon->move(me);
        me->start_busy(5);
		{
			tell_object(me,sprintf(GRN"�����ٻ��ɹ�!��\n"NOR));
	return 1;
		}			case "��":
			weapon = new("/d/npc/m_weapon/weapon/m_whip");
			weapon->move(me);
        me->start_busy(5);
		{
			tell_object(me,sprintf(GRN"�����ٻ��ɹ�!��\n"NOR));
	return 1;
		}			case "��":
			weapon = new("/d/npc/m_weapon/weapon/m_staff");
			weapon->move(me);
        me->start_busy(5);
		{
			tell_object(me,sprintf(GRN"�����ٻ��ɹ�!��\n"NOR));
	return 1;
		}			case "��":
			weapon = new("/d/npc/m_weapon/weapon/m_club");
			weapon->move(me);
        me->start_busy(5);
		{
			tell_object(me,sprintf(GRN"�����ٻ��ɹ�!��\n"NOR));
	return 1;
		}		}
          }
else 
			{
			tell_object(me,sprintf(GRN"�����ٻ��ɹ�!��\n"NOR));
	return 1;
		}
}

	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : summon <��Ʒ��ID>

��ָ��������ĳЩ��Ʒ����������װ���ϣ���Ȼ�����һ����
����ʩչ�������С�
HELP );
	return 1;
}
