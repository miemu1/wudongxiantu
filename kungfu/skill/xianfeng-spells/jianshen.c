#include <ansi.h>

string query_name() { return "����"; }
inherit F_SSERVER;

int perform(object me, object target)
{
        int skill;
        object ob;
        object weapon;

        if(me->query("family/family_name")!="��ɽ��")
                return notify_fail("��������֪�󱲣�û�й������ң������ٻ��ң�\n");

   if(me->query("shushan/jianshen_cast")!=1)
          return notify_fail("�㻹û��ᡸ���񡹣�\n");

        if ((int)me->query_skill("xianfeng-spells", 1) < 800)
                return notify_fail("����ɷ���������Ϊ������\n");

        if (me->query_skill_mapped("spells") != "xianfeng-spells")
                return notify_fail("�㻹û�м����ɷ��������ء�\n");

        if (find_living(me->query("id") + "jianshen"))
                return notify_fail("���ٻ����Ľ����������䣬��δ������硣\n");

        skill = me->query_skill("xianfeng-spells", 1);
        //me->add("mana", -1000);

        message_combatd(HIC "\n$N" HIC "���������дǣ�ͻȻ����г��֡����񡹵���Ӱ��\n\n" NOR, me);

        // ���ý���
        ob = new("/kungfu/class/misc/jianshen");
        ob->init_npc(me);
        ob->move(environment(me));

        me->start_busy(3);

        return 1;
}
