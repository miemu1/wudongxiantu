 //  rouwanduanyu.c
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
string query_name() { return "����"ZJBR"����"; }
int perform(object me, object target, int amount)
{
        int i, skill, damage,extra,force,max_force,state,base,res_kee;
        string msg;

        if( !me->is_fighting() )
                return notify_fail("�������ֻ����ս����ʹ�á�\n");
        force = (int)me->query("neili");
        if( force < 500 )
                return notify_fail("�������������\n");

        skill = me->query_skill("mingyu-gong",1);
        extra = me->query_skill("force");
        if (skill<120) return notify_fail("���������δ�ﵽ�����أ�����ʩչ�������\n");

                                if( !target || target==me) target = offensive_target(me);
                    if( !target
                    ||      !target->is_character()
                    ||      !me->is_fighting(target) )
                            return notify_fail("����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");


        //suppose: force: 220,mingyu-force: 180, max_force: 650+220*5=1750
        //xingxiexuanzhuan�������3�� max_force = 1750 * 3 =5250
        //dam_max = 5250 * 9= 47250
        damage = skill;
        damage = damage/2+random(damage);

        msg = HIY "$N�Ķ�����,����Ѹ�ٻû��ɼ��ǵ�͸������ɫ��\n"NOR;

        //state=damage/5000;
        //if (state>3) state=3;
        state = random(4);
        switch (state) {
                case 0:
                                msg += HIC "\n$N����΢΢һת��$n������$N�����ƿ�����ת���������϶���һ���������ӡ��\n\n"NOR;
                                break;
                case 1:
                                msg += HIG "\n$N����΢΢һת��$n�����ػ�������һ����˳�ȥ��\n\n"NOR;
                                break;
                case 2:
                                msg += HIR "\n$N����΢΢һת��һ��Ѫ����$n�������������\n\n"NOR;
                                break;
                case 3:
                                msg += HIM "\n$N����΢ת������ͻ�����䣬$nãȻ�޴��У�һ������͸�������\n\n"NOR;
                                break;
                }

        me->add("force",-force/4);



        message_combatd(msg,me,target);

        res_kee = 10+(skill-180)/2;
        if(res_kee>40)
                res_kee = 40;
        //state = target->query_temp("condition/mingyu");
        //res_kee=target->query("resistance/kee");
        //if (state)
        target->add_temp("resistance/jing",-res_kee);
                                extra=target->receive_damage("jing", damage, me);
        //if (state)
        target->add_temp("resistance/jing",res_kee);
        //CHANNEL_D->do_sys_channel("sys","damage is "+damage+" -res is "+res_kee+" final_damage is "+extra+"\n");
        COMBAT_D->report_status(target);
        if (me->query_busy()<3) me->start_busy(3);
        return 1;
}

