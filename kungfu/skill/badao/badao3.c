#include <ansi.h>

string name() { return HIW "����" NOR; }
string query_name() { return "����"; }
inherit F_SSERVER;

int perform(object me, object target)
{
        int skill;
        object ob;
        object weapon;

        if( me->query("neili")<50000 )
                return notify_fail("�������������\n");
			
        if( me->query("qi")<50000 )
                return notify_fail("�����Ѫ������\n");

        if ((int)me->query_skill("badao", 1) < 300)
                return notify_fail("��Ŀ����ɾ���Ϊ������\n");

        if (me->query_skill_mapped("blade") != "badao")
                return notify_fail("�㻹û�м��������ɾ��ء�\n");

        if (find_living(me->query("id") + "daohun"))
                return notify_fail("��ĵ��껹û����ʧ����ʱ����ʩչ���С�\n");

        if( !objectp(weapon=me->query_temp("weapon")) ||
            weapon->query("skill_type") != "blade" )
                return notify_fail("��ʹ�õ��������ԣ�\n");

        skill = me->query_skill("blade", 1);
        me->add("neili", -50000);
        me->add("qi", -50000);

        message_combatd(HIY "\n$N" HIY "��������" + weapon->name() + HIY "��ɲ�Ǽ仪������һ��"
                        "��Ӱ��" + weapon->name() + HIY "�лû����� ����\n\n" NOR, me);

        // ���õ���
        ob = new("/kungfu/class/misc/daohun");
        ob->init_npc(me);
        ob->move(environment(me));

        me->start_busy(3);

        return 1;
}
