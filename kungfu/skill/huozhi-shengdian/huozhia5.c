#include <ansi.h>

string name() { return HIW "[��ħ��]"ZJBR"�������" NOR; }
string query_name() { return "[��ħ��]"ZJBR"�������"; }
inherit F_SSERVER;

int perform(object me, object target)
{
        int spells;
        object ob;
        object weapon;

	if((int)me->query("neili")< 5000)
	return notify_fail("�������̫���ˣ�\n");

	if((int)me->query_skill("bingzhi-shengdian",1)< 400)
	return notify_fail("��Ļ�֮ʥ��̫���ˣ�\n");
    spells = me->query_skill("spells");
    if(spells < 200 )
    return notify_fail("��Ļ������������ߣ�\n");
        if (find_living(me->query("id") + "huoyanfeilong"))
                return notify_fail("��Ļ��������û����ʧ����ʱ�޷��ٻ���\n");

        spells = me->query_spells("bingzhi-shengdian", 1);
        me->add("neili", -1000);

        // ���õ���
        ob = new("/kungfu/class/misc/huoyanfeilong");
        ob->init_npc(me);
        ob->move(environment(me));
        ob = new("/kungfu/class/misc/huoyanfeilong");
        ob->init_npc(me);
        ob->move(environment(me));
        me->start_busy(3);

        return 1;
}
