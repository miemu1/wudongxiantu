 //  rouwanduanyu.c
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
inherit F_CLEAN_UP;
string query_name() { return "�һ�"ZJBR"����"; }
int perform(object me, object target, int amount)
{
        object *enemys;
        int i, skill, damage,force,extra,extra_enemy,state,base,res_kee,last_damage;
        string msg;

        if( !me->is_fighting() )
                return notify_fail("�һ�����ֻ����ս����ʹ�á�\n");
        force = (int)me->query("neili");
        if( force < 500 )
                return notify_fail("�������������\n");

        skill = me->query_skill("mingyu-gong",1);
        extra = me->query_skill("force");
        if (skill<160) return notify_fail("���������δ�ﵽ�ڰ��أ�����ʩչ�һ�����\n");


                if (amount<0) amount=0;
                if (amount)
                        force = force /amount;

        me->add("force", -force/3);

        //suppose: force: 220,mingyu-force: 180, max_force: 650+220*5=1750
        //xingxiexuanzhuan�������3�� max_force = 1750 * 3 =5250
        //dam_max = 5250 * 9= 47250
        damage = skill;
        damage = damage/2+random(damage);

        //����������û��condition/mingyu��
        state = 0;
        enemys = me->query_enemy();
        for (i=0;i<sizeof(enemys);i++)
                        {
                                state = enemys[i]->query_temp("condition/mingyu");
                                if (state) break;
                                }

        if (state)
                {
                msg = HIW "$N˫Ŀ΢�գ����ﴦ����һ���ޱȴ������ţ���������ͻȻ��ʧ��\n"NOR;
                msg += HIW "\n���ű��ѿ����������ܵ����������â���Ժ��������ԣ�\n\n"NOR;
                }
        else
                {
                msg = HIW "$Nһ����Х��������Ȼ��ת������\n"NOR;
                msg += HIW "\n$N�ӵ����ɢ����������������ǧ������룬������˷���ȥ��\n\n"NOR;
                }


        message_combatd(msg, me);


        for (i=0;i<sizeof(enemys);i++)
        {
            state = enemys[i]->query_temp("condition/mingyu");
            extra_enemy = enemys[i]->query_skill("force");
            last_damage = damage*2/3;
            if (last_damage<0) last_damage = 100;
            //write("damage is :"+(string)damage+"\n");
            if (random(extra+extra_enemy)<extra_enemy)
            {
                last_damage = last_damage /2;
                message_combatd(HIR"$Nֻ����ǰ��â���ۣ���Χ�����������ڣ���֮����æ�����ڹ�������������\n"NOR,enemys[i]);
            }
            else
                message_combatd(HIR"$Nֻ����ǰ���������������漴ȫ��һ���ʹ������Ѫ�������������\n"NOR,enemys[i]);
            res_kee = 10+(skill-180)/3;
                        if(res_kee>40)
                                res_kee = 40;
            //write("last_damage is :"+(string)last_damage+"\n");
            //state = enemys[i]->query_temp("condition/mingyu");
            //res_kee=enemys[i]->query("resistance/kee");
            enemys[i]->add_temp("resistance/jing",-res_kee);
            enemys[i]->receive_damage("jing", last_damage, me);
            enemys[i]->add_temp("resistance/jing",res_kee);
            COMBAT_D->report_status(enemys[i]);
        }
        if (me->query_busy()<3) me->start_busy(3);
            return 1;
}

