// ̫������

#include <ansi.h>
#include <combat.h>

string name() { return HIM "̫������" NOR; }

inherit F_SSERVER;

string attack1(object me, object target, int damage);
string attack2(object me, object target, int damage);

int perform(object me, object target)
{
        mapping buff, data;
        int damage;
        string msg;
        object weapon;
        int ap, dp, fp;
        int xy, ngxy, taoism, tjss;
        int time;
        int delta;
         int flagremote;

        if( userp(me) && !query("yuanshen", me) )
                return notify_fail("����δ������޷�ʹ��̫�����⣡\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(name() + "ֻ����ս���жԶ���ʹ�á�\n");


        if( me->is_busy() )
                return notify_fail("����æ���ء�\n");

        if( !objectp(weapon=query_temp("weapon", me)) ||
            query("skill_type", weapon) != "sword" )
                return notify_fail("��ʹ�õ��������ԣ�\n");

        if ((int)me->query_skill("taiji-jian", 1) < 1000)
                return notify_fail("��̫������������죬�޷�ʩչ" + name() + "��\n");

        if( query("neili", me)<2000 )
                return notify_fail("�����������������޷�ʩչ" + name() + "��\n");

        if (me->query_skill_mapped("sword") != "taiji-jian")
                return notify_fail("��û�м���̫���������޷�ʹ��" + name() + "��\n");
        
        if( userp(me) ) 
        {
                if( (time = BUFF_D->get_buff_overtime(me, "tjj_jian")) > 0 )
                        return notify_fail(MAG"̫��������������̫��������ȴ�"+time+"�롣\n"NOR);
        }
        
        if (! living(target))
               return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        addn("neili", -1000, me);

        ap = attack_power(me, "sword");
        dp = defense_power(target, "dodge");
        fp = defense_power(target, "parry");


        xy = me->query_skill("tianwei-zhengqi", 1);
        ngxy = me->query_skill("force-cognize", 1);
        taoism = me->query_skill("taoism", 1);
                tjss = me->query_skill("taiji-shengong", 1);
                
        ap = ap + ap*(xy/100<10?10:xy/100)/10;
        if(target->is_bad())
                ap += ap/10;
                
        damage = damage_power(me, "sword");
        damage = damage + damage*(xy/50<10?10:xy/50)/10;
        damage *= 3;
        
        delta = ABILITY_D->check_ability(me, "ap_power-tjj-jian"); // ����ab
        if( delta ) ap += ap*delta/100;
        
        delta = ABILITY_D->check_ability(me, "da_power-tjj-jian"); // ����ab
        if( delta ) damage += damage*delta/100;
        
        //target->start_busy(10);

                if(taoism > 1200 && ngxy > 5000 && !userp(target)) 
                damage *= taoism/1200 + ngxy/1000;
        if(tjss > 10000 & taoism > 10000)
          {
             if(random(100) < tjss/120 || random(100) < 80)
             flagremote = 1;
                   }
                 if(tjss > 8000) damage += damage/8;
         if(tjss > 12000) damage += damage/7;
         if(tjss > 16000) damage += damage/6;
                 
        message_combatd(sort_msg(HIY "\n$N" HIY "����һת������" + weapon->name() + HIY "��������������"
                     "�������������������̬Ʈ������֮�����ľ�" HIC "̫�O" HIY "֮��" HIY "����\n" NOR), me);

        msg = HIM "$N" HIM "�����������ڽ��ϣ�����һ�������������������̡�\n" NOR;
        if (ap*2/3 + random(ap / 2) < dp)
                msg += CYN "$n" CYN "�����ֿ죬б��������\n" NOR;
        else
        {
                        
                msg += COMBAT_D->do_damage(me, target, (flagremote ? SPECIAL_ATTACK : WEAPON_ATTACK), damage, 100 + (xy / 2 + random(xy / 2)>500?500:xy / 2 + random(xy / 2)),
                                           (: attack1, me, target, damage :));
        }

        msg += HIM "\n$N" HIM "��ҡ" + weapon->name() + HIM "����ʱ�������ݺᣬ����է�֣�����Ŀ��Ͼ�ӡ�\n" NOR;
        if (ap*2/3 + random(ap / 2) < fp)

                msg += CYN "$n" CYN "����һ������������һ�����Ǳ��ض�����С�\n" NOR;
        else
        {
                msg += COMBAT_D->do_damage(me, target, (flagremote ? REMOTE_ATTACK : WEAPON_ATTACK), damage, 100 + (xy / 2 + random(xy / 2)>500?500:xy / 2 + random(xy / 2)),
                                           (: attack2, me, target, damage :));
        }

        me->start_busy(2 + random(3));
        message_combatd(msg, me, target);
        
        time = 40;
        time -= ABILITY_D->check_ability(me, "cd-tjj-jian"); // ab���ɼ�cd
        time -= ABILITY_D->check_ability(me, "reduce_cd", 2); // talent��cd  
                
        buff =  
        ([
                "caster" : me,
                "target" : me,
                "type"   : "cooldown",
                "type2"  : "tjj_jian",
                "attr"   : "curse",
                "name"   : "̫��������̫������",
                "time"   : time,
                "buff_msg" : "̫��������������̫��������ȴ�"+time+"�뷽���ٴ�ʩչ��\n",
                "disa_msg" : "",
                "disa_type": 0,
        ]);
        BUFF_D->buffup(buff);
        return 1;
}


string attack1(object me, object target, int damage)
{
        string msg;

        msg = HIR "$N" HIR "����Ʈ���ޱȣ���$n" HIR "���޷�Ӧ��"
              "���������������ز�����\n" NOR;

        // if( random(2) != 1 ) return msg;
        //if( target->query_condition("no_perform") ) return msg;

        target->apply_condition("no_perform", 5);

        msg += WHT "$n" WHT "�е���������ȫ���������ƻ�ɢ��һ�㣬ȫȻ�޷����ơ�\n" NOR;

        return msg;
}

string attack2(object me, object target, int damage)
{
        mapping buff, data;
        string msg;

        msg = HIR "$N" HIR "����Խ����������$n" HIR "�Ƶý������ˣ�"
              "����һ������$n" HIR "��Ҳ�޴Ӷ�ܡ�\n" NOR;

        if( random(2) != 1 ) return msg;
        
        data = ([
                "avoid_busy": -90,
                "reduce_busy": -36,
                "avoid_weak": -90,
                "avoid_locked": -90,
        ]);
        buff = ([
                "caster": me,
                "target": target,
                "type"  : "tjj_fengyin",
                "attr"  : "curse",
                "name"  : "̫����������ӡ",
                "time"  : 30,
                "buff_data": data,      
                "buff_msg" : msg,
                "disa_msg" : HIR "��ĺ�������������æ�ҡ����Ӿ����䶳�������ڽ����ӡ��\n" NOR,
                        
        ]);
        BUFF_D->buffup(buff);

        msg += WHT "$n" WHT "�е�����ĺ�������������æ�ҡ����Ӿ����䶳��������ӡ��\n" NOR;

        return msg;
}

