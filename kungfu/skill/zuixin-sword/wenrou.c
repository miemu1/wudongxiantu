#include <ansi.h>

inherit F_SSERVER;
string query_name() { return "�������һ��"; }
int perform(object me, object target)
{
        object weapon;
        int attackp, defendp;


        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("�������һ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( !objectp(target) || target->query("id") == "mu ren" )
                return notify_fail("��Ҫ����˭��������\n");
           
        if( me->query_temp("sucked") )
                return notify_fail("��ո��˹��������һ��!\n");

//        if( objectp(me->query_temp("weapon")) )
//                return notify_fail("�������ֲ���ʩ�û����󷨻���������\n");

        if (!objectp(weapon = me->query_temp("weapon")) 
        || (string)weapon->query("skill_type") != "sword")
                  return notify_fail("������һ������ʼʱ�����н����֣�\n");

        if( (int)me->query_skill("beiming-shengong", 1) < 150 )
                return notify_fail("��ı�ڤ�񹦲�����죬�������Է����������\n");

        

        if( (int)me->query("neili",1) < 500 )
                return notify_fail("�����������������ʹ�û����󷨡�\n");

       

          message_vision( HIR "$NͻȻ�����ü������ᣬ���б����������ǰһ�ͣ�������$n�Ĳ�֪ʲô��λƮȥ��\n" NOR,
                me, target );

        attackp = me->query_skill("force", 1) + me->query_skill("beiming-shengong", 1) + me->query_skill("lingbo-weibu", 1) / 2;
        defendp = target->query_skill("force") + target->query_skill("dodge");

        me->set_temp("sucked", 1);

        if( attackp / 2 + random(attackp) > defendp || !living(target) )
        {
                  message_vision(HIY "$pһʱ�������ܣ�ֻ�û�����˫�ֽ�����һ��,˫�ֵ�ʱ�类ճסһ��Ľ����ڽ����ϡ���\n" NOR, me, target );
                tell_object(me, HIB "���" + target->name() + "��ˣ���������ڤ�񹦣����Է�����������������...\n" NOR);
                 message_vision(HIY "$p�ƺ���˵ʲô������ȫ���������ֳ�����ʹ��ı��飬˫��ȴ�ֳ��Ѳ�������\n" NOR, me, target );
                tell_object(
                        target, HIB "����������΢΢һ��������ԴԴ������˳�ŶԷ�$w��ס����ӿȥ����\n" + 
                        "��ʱ����һ����ȫȻ�᲻������������ֻ���ζԷ���ȡ��������������\n" 
                        NOR);

                target->add("neili", -1*((int)me->query_skill("beiming-shengong", 1) + target->query("jiali")) );
                if ( target->query("neili") <1 ) target->set("neili",0);
                me->add("neili", (int)me->query_skill("beiming-shengong", 1) + target->query("jiali") );
                me->add("neili", 100);

                if( target->query("combat_exp") >= me->query("combat_exp") )
                {
                        if( (int)me->query("potential") - (int)me->query("learned_points") < 110 )
                        me->add("potential", 7);
                        me->add("combat_exp", 20);
                }

                me->start_busy(2);
                target->start_busy(1);
                me->add("neili", -200);

                call_out("del_sucked", 10, me);
        }
        else
        {       
                message_vision(HIY "����$p������$P����ͼ��Ѹ�ٵرܿ�����һ����\n" NOR, me, target);
                me->start_busy(3);
                call_out("del_sucked", 17, me);
        }

        return 1;
}

void del_sucked(object me)
{
        if ( me->query_temp("sucked"))
        me->delete_temp("sucked");
}


