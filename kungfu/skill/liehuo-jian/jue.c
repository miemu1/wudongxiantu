// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified
// in any form without the written permission from authors.
// jue.c �һ�������

#include <ansi.h>
#include <weapon.h>
inherit F_SSERVER;
 string query_name() { return "�һ�"ZJBR"������"; }
int perform(object me, object target)
{
        object weapon, ob;
        string msg;
        int i;

        if (! me->is_fighting())
                return notify_fail("��"+HIR"�һ�������"NOR+"��ֻ����ս����ʹ�á�\n");

        if (me->is_busy())
                return notify_fail("����æ���أ�\n");

        if (! objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("�������������\n");

        if ((int)me->query_skill("sword") < 100 ||
                me->query_skill_mapped("sword") != "liehuo-jian")
                return notify_fail("��ġ��һ𽣡��������ң��޷�ʹ�á�"+HIR"�һ�������"NOR+"����\n");

        msg = HIR "$N������������ʱ���б���������ˣ�������Է�������ȥ��\n" NOR;
        message_combatd(msg, me, target);
        me->clean_up_enemy();
        ob = me->select_opponent();
        me->add("neili", -300);

        for(i = 0; i < 3; i++)
        if (me->is_fighting(ob) && ob->is_fighting(me) && ob->query("eff_qi")>0)
        {
                me->set_temp("action_msg", "������");
                if (! weapon->query("equipped")) break;
                COMBAT_D->do_attack(me, ob,weapon, 0);
        } else break;

        me->start_busy(1 + random(2));
        return 1;
}


