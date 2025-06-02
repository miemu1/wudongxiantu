 // roar.c
#include <ansi.h>

void give_effect(object me,int extra,int level);
void take_effect(object me,object target,int level);
#include <combat.h>
inherit F_SSERVER;
inherit F_CLEAN_UP;
string query_name() { return "��м"ZJBR"��ת"; }
int perform(object me, object target, int amount)
{
        object *ob;
        int i, skill, force,extra,level;

        if( !me->is_fighting() )
                return notify_fail("��м��תֻ����ս����ʹ�á�\n");
        if (me->query_temp("xingxiexuanzhuan")+10>time())
                                        return notify_fail("�㲻����ô���ʩչ��һ����м��ת��\n");
        skill = me->query_skill("mingyu-gong",1);
        extra = me->query_skill("force");
        force = (int)me->query("neili");
        if (skill<180 && userp(me)) return notify_fail("���������δ�ﵽ�ھ��أ�����ʩչ��м��ת��\n");
        level = skill/20;
        if (level>11)
                        level = 11;
        if( userp(me) && level<10 && force < 1500 )
                return notify_fail("�������������\n");


        message_combatd(HIW"$N����һ�������߶���"+chinese_number(level)+"�ص�����,����ͻȻ��÷Ǻ�ǰף������˾���͸���ģ�\n",me);
        message_combatd("$N�������ÿһ�޽��磬ÿһ�޹�ͷ���ݷ��ܿ������������˵�����Ĺ��ؿ��£�\n"NOR,me);

        me->set_temp("xingxiexuanzhuan",time());

        if (me->query_busy()<2) me->start_busy(2);
        me->start_call_out( (:call_other, __FILE__, "give_effect",me,extra,level:),1);
        //me->ccommand("say ����¥��");

        return 1;
}

void give_effect(object me,int extra,int level)
{
        object* enemy;
        int i,count,extra_enemy;
        enemy = me->query_enemy();
        if (!sizeof(enemy)) return;
        message_combatd(HIW"$N�����ǵ�������ӷ������������������Ե���Ϊ�����γ��������У�\n"NOR,me);
        for (i=0;i<sizeof(enemy);i++)
                {
                        extra_enemy =  enemy[i]->query_skill("force");
                        count = (extra-extra_enemy)/50;
                        //count = 5;
                        if (count<4) count = 4;
                        if (enemy[i]->query_temp("condition/mingyu")<count)
                                        enemy[i]->set_temp("condition/mingyu",count);
                        take_effect(me,enemy[i],level);

                        }

        }

void take_effect(object me,object target,int level)
{
        int i,j,k,max_force;
        string msg;
        object* inv;

        if (/*target->query("step_less") || */!target->query_temp("condition/mingyu") || !objectp(me) || !objectp(target) || !target->is_fighting(me))
            {
                msg = HIW"$N���ڰ��������񹦵��������С�\n"NOR;
                        message_combatd(msg,target);
                        target->delete_temp("condition/mingyu");
				return;
			}
		target->add_temp("condition/mingyu",-1);
		i = random(2);
                                                switch (i)
													{
                                                        case 0:
                                                                                if (level>=10)
                                                                                                msg = GRN"$N�����񹦵����������У�ͻ���ٲ�Ψ�裡��\n"NOR;
                                                                                else
                                                                                                msg = YEL"$N�����񹦵����������У�ͻ���ٲ�Ψ�裡��\n"NOR;
                                                                                message_combatd(msg,target);
                                                                                if (level>=10)
                                                                                                //true_busy(target,2+random(2));
                                                                                                target->start_advanced_busy(2+random(2),0,me);
                                                                                else {
                                                                                                target->start_busy(2+random(2),0,me);
                                                                                }
                                                                                break;
                                                        case 1:

                                                                                if (!target->query("neili") && level<11) {
                                                                                                msg = YEL"$N�����ľ����Ų����ǣ�ҡҡ��׹��\n"NOR;
                                                                                                message_combatd(msg,target);
                                                                                                if (target->query_busy()<2) target->start_busy(2);
                                                                                                break;
                                                                                }
                                                                                if (level>=11)
                                                                                                msg = RED"$N�����񹦵����������У�ȫ����Ѫ����ѩ�㿪ʼ��ʧ��\n"NOR;
                                                                                else
                                                                                                msg = WHT"$N�����񹦵����������У�ȫ��������ѩ�㿪ʼ��ʧ��\n"NOR;
                                                                                message_combatd(msg,target);
                                                                                max_force = target->query("max_neili");
                                                                                if(level>=11 && max_force<=1200)
                                                                                                max_force = 1200;
                                                                                target->add("neili",-max_force/3);
                                                                                if (target->query("neili")<0) target->set("neili",0);
                                                                                if(userp(me) )
                                                                                        me->add("neili",1200);
                                                                                else
                                                                                        me->add("neili",1200);

                                                                                break;

                                                                default:
																	return 0;
													}
        //target->reomve_call_out((:call_other, __FILE__, "take_effect":))
        target->start_call_out( (:call_other, __FILE__, "take_effect",me,target,level:),2);

        return;
}