#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string attack1(object me, object target, int damage);
string attack2(object me, object target, int damage);
string attack3(object me, object target, int damage);
string attack4(object me, object target, int damage);
string attack5(object me, object target, int damage);
string attack6(object me, object target, int damage);

string name() { return HIR "�����ֻ�" NOR; }
string query_name() { return "����"ZJBR"�ֻ�"; }
int perform(object me, object target)
{
        object weapon;
        string wn, msg;
        object sroom, room;
        int ap, dp, damage;
        int wait_time;
        int in_shejingdong;

        /*
        // ����Ƿ񾭹�������Ч�����ֻص�6��
        if( !query("scborn/perform_zhen_saishenlong", me) && !query("thborn/ok", me) )
        {
                // �ֻص����6���Զ��۳������ñ�־
                if( query("scborn/cur_lunhui_point", me) >= 6 )
                {
                        addn("scborn/cur_lunhui_point", -6, me);
                        set("scborn/perform_zhen_saishenlong", 1, me);
                        me->save();
                }
                // �����޷�ʩչ����
                else
                        return notify_fail("�Բ�����������ֻص������⣬����ʱ�޷�ʩչ���У�����μ����š�\n");
        }
        */

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(name() + "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( !objectp(weapon=me->query_temp("weapon") )
            || weapon->query("skill_type") != "sword" )
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" + name() + "��\n");

        if( me->query("max_neili")<10000 )
                return notify_fail("���������Ϊ����������ʩչ" + name() + "��\n");

        if ((int)me->query_skill("buddhism", 1) < 500)
                return notify_fail("��������ķ����򲻹�������ʩչ" + name() + "��\n");

        if ((int)me->query_skill("lunhui-sword", 1) < 300)
                return notify_fail("�������ɾ���򲻹�������ʩչ" + name() + "��\n");

        if( me->query("neili")<4000 )
                return notify_fail("��������������������ʩչ" + name() + "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        wait_time = 30;

        if (me->query_skill("lunhui-sword", 1) >= 300)
                wait_time = 22;

        if (me->query_skill("lunhui-sword", 1) >= 400)
                wait_time = 14;

        if (me->query_skill("lunhui-sword", 1) >= 600)
                wait_time = 6;

        if( time()-me->query_temp("last_perform_zhen")<wait_time )
                return notify_fail("���ʩչ��" + name() + "������������û����ȫ˳������ʱ����ǿ���˹���\n");


        wn = weapon->name();

        message_combatd(HIW "$N" HIW "��¶�黨֮�⣬��������" + wn +
                        HIW "����ʱ�̲���ת���������ɣ�˵��������͡�"
                        "\n" NOR, me, target);

        //  ��¼������ķ���
        if (! objectp(sroom = environment(me)))
                return 1;

        if (base_name(sroom) == "/d/shenlong/shejingdong" ||
            base_name(sroom) == "/d/shenlong/huodong1" ||
            sroom->query("fight_room") )
                in_shejingdong = 1;

        ap = me->query_skill("sword");
        dp = target->query_skill("force");

        damage = me->query_skill("sword")*3;

        // �����ֻ�֮�˼��
        room = find_object("/d/death/liudaolunhui/rendao");
        if (! room) room = load_object("/d/death/liudaolunhui/rendao");

        if (! in_shejingdong)me->move(room);
        if (! in_shejingdong)target->move(room);

        message_combatd(HIY "\n$N" HIY "��������һ�����������ֵ�" + wn +
                       HIY "�������죬����˵����������������\n" NOR, me, target);

        if (ap * 4 / 5 + random(ap) > dp)
        {
                msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 200,
                                           (: attack1, me, target, damage :));
        } else
        {
                msg = CYN "����$n" CYN "�������񣬷�����"
                      "�ܣ�������ж�����Ρ�\n" NOR;
        }
        message_combatd(msg, me, target);

        // �����ֻ�֮������
        room = find_object("/d/death/liudaolunhui/chushengdao");
        if (! room) room = load_object("/d/death/liudaolunhui/chushengdao");

        if (! in_shejingdong)me->move(room);
        if (! in_shejingdong)target->move(room);

        message_combatd(HIY "\nȴ��$N" HIY "���ޱ��飬������" + wn +
                       HIY "�͵���ǰһ�ݣ����綾�߰�����$n" HIY "��\n"
                       NOR, me, target);

        if (ap * 4 / 5  + random(ap) > dp)
        {
                msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 200,
                                           (: attack2, me, target, damage :));
        } else
        {
                msg = CYN "����$n" CYN "�������񣬷�����"
                      "�ܣ�������ж�����Ρ�\n" NOR;
        }
        message_combatd(msg, me, target);

        // �����ֻ�֮�����
        room = find_object("/d/death/liudaolunhui/eguidao");
        if (! room) room = load_object("/d/death/liudaolunhui/eguidao");

        if (! in_shejingdong)me->move(room);
        if (! in_shejingdong)target->move(room);

        message_combatd(HIY "\n$N" HIY "һ����̾���������Ž���������" +
                       wn + HIY "��Ѫ��֮����Ũ����$n" HIY "ӭͷն�䡣\n"
                       NOR, me, target);

        if (ap * 4 / 5  + random(ap) > dp)
        {
                if( target->query("death_skill/guimai") )
                        msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage / 2, 100,
                                                   (: attack3, me, target, damage :));
                else

                        msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 300,
                                                   (: attack3, me, target, damage :));
        } else
        {
                msg = CYN "����$n" CYN "�������񣬷�����"
                      "�ܣ�������ж�����Ρ�\n" NOR;
        }
        message_combatd(msg, me, target);

        // �����ֻ�֮���޵�
        room = find_object("/d/death/liudaolunhui/xiuluodao");
        if (! room) room = load_object("/d/death/liudaolunhui/xiuluodao");

        if (! in_shejingdong)me->move(room);
        if (! in_shejingdong)target->move(room);

        message_combatd(HIY "\n����$N" HIY "����΢�Σ���ʱ�ó�ʮ������"
                       "Ӱ��ʮ����" + wn + HIY "����$n" HIY "��ȥ��"
                       "\n" NOR, me, target);

        if (ap * 4 / 5  + random(ap) > dp)
        {
                if( target->query("death_skill/lonely") )
                        msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage / 2, 100,
                                                   (: attack4, me, target, damage :));
                else

                        msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 400,
                                                   (: attack4, me, target, damage :));
        } else
        {
                msg = CYN "����$n" CYN "�������񣬷�����"
                      "�ܣ�������ж�����Ρ�\n" NOR;
        }
        message_combatd(msg, me, target);

        // �����ֻ�֮������
        room = find_object("/d/death/liudaolunhui/diyudao");
        if (! room) room = load_object("/d/death/liudaolunhui/diyudao");

        if (! in_shejingdong)me->move(room);
        if (! in_shejingdong)target->move(room);

        message_combatd(HIY "\n������$N" HIY + wn + HIY "һ������������"
                       "����������һ�����캮������������ɢ��ȥ��\n" NOR,
                       me, target);

        if (ap * 4 / 5 + random(ap) > dp)
        {
                msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 500,
                                           (: attack5, me, target, damage :));
        } else
        {
                msg = CYN "����$n" CYN "�������񣬷�����"
                      "�ܣ�������ж�����Ρ�\n" NOR;
        }
        message_combatd(msg, me, target);

        // �����ֻ�֮�켫��
        room = find_object("/d/death/liudaolunhui/tiandao");
        if (! room) room = load_object("/d/death/liudaolunhui/tiandao");

        if (! in_shejingdong)me->move(room);
        if (! in_shejingdong)target->move(room);

        message_combatd(HIY "\n$N" HIY "���⻯�����⻯��������" + wn +
                       HIY "���������ڿգ����Ƽ��գ����Ϊ֮ʧɫ��\n"
                       NOR, me, target);

        if (ap * 4 / 5 + random(ap) > dp)
        {
                if( target->query("death_skill/emperor") )
                        msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage / 2, 100,
                                                   (: attack6, me, target, damage :));
                else

                        msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 600,
                                                   (: attack6, me, target, damage :));
        } else
        {
                msg = CYN "����$n" CYN "�������񣬷�����"
                      "�ܣ�������ж�����Ρ�\n" NOR;
        }
        message_combatd(msg, me, target);

        me->start_busy(4 + random(4));
        me->add("neili", -4000);
        me->set_temp("last_perform_zhen", time());

        // Ϊʲô���У�Ϊ�˻����Ϊ������Ŀ����
        tell_object(me, "\n\n");
        tell_object(target, "\n\n");

        // ת�ƻ�����ķ���
        if (! in_shejingdong)me->move(sroom);
        if (! in_shejingdong)target->move(sroom);

        return 1;
}

string attack1(object me, object target, int damage)
{
        string msg;

        msg = HIR "$n" HIR "ֻ����ͷһ����࣬���̲�סҪ��"
              "������������һ��Ż��һ����Ѫ��\n" NOR;

        if( !target->query_temp("liudaolunhui") )
        {
                msg += WHT "$p��Ȼ�����ȫ�����������һ˿"
                       "˿Զ���Լ���ȥ������֮����\n" NOR;

                target->add_temp("apply/attack", -damage/10);
                target->add_temp("apply/parry", -damage/10);
                target->add_temp("apply/dodge", -damage/10);

                if( target->query_temp("apply/attack")<0 )
                        target->set_temp("apply/attack", 0);
                if( target->query_temp("apply/parry")<0 )
                        target->set_temp("apply/parry", 0);
                if( target->query_temp("apply/dodge")<0 )
                        target->set_temp("apply/dodge", 0);

                target->set_temp("liudaolunhui", 1);
        }
        return msg;
}

string attack2(object me, object target, int damage)
{
        object weapon;
        string wn, msg;

        msg = HIR "��Ȼ��$n" HIR "�е��ؿڴ�һ����ȣ�����"
              "Ϯ�壬����һ��Ѫ�ꡣ\n" NOR;

        if( objectp(weapon=target->query_temp("weapon")) )
        {                
                wn = weapon->name();
                msg += WHT "�����������ϡ��������죬$n" WHT "��" + wn +
                       WHT "����$N" WHT "�ʳ��˿����Ƭ��\n" NOR;

                weapon->set("consistence", 0);
                weapon->move(target);
        }
        return msg;
}

string attack3(object me, object target, int damage)
{
        int shd;
        string msg;

        msg = HIR "�����������������Ѫ�ˣ�$n" HIR "ֻ��ͷ��Ŀ"
              "ѣ����֫������������ս��\n" NOR;

        if( target->query_temp("shield") )
        {
                shd=target->query_temp("apply/armor");

                target->add_temp("apply/armor", -shd);

                if( target->query_temp("apply/armor")<0 )
                        target->set_temp("apply/armor", 0);

                target->delete_temp("shield");

                msg += WHT "$N" WHT "����ӿ�������������ʱ��$n"
                       WHT "�Ļ��������ݻٵõ�Ȼ�޴档\n" NOR;
        }
        return msg;
}

string attack4(object me, object target, int damage)
{
        object cloth, armor;
        string cn, an, msg;

        msg = HIR "$n" HIR "��ʱ��ʧɫ��˲���ѱ�$N" HIR "����"
              "������ֱ����Ѫ��ģ����\n" NOR;

        if( objectp(cloth=target->query_temp("armor/cloth")) )
        {
                cn = cloth->name();
                msg += WHT "������Ȼ��������$n" WHT "���ŵ�" + cn +
                       WHT "��$N" WHT "���������£�������÷��顣\n"
                       NOR;

                cloth->set("consistence", 0);
                cloth->move(target);
        } else
        if( objectp(armor=target->query_temp("armor/armor")) )
        {                
                an = armor->name();
                msg += WHT "������������һ�����죬$n" WHT "���ŵ�" +
                       an + WHT "����$N" WHT "���ѣ����ɿ����Ƭ��\n"
                       NOR;

                armor->set("consistence", 0);
                armor->move(target);
        }
        return msg;
}

string attack5(object me, object target, int damage)
{
        string msg;

        msg = HIR "ֻ��$n" HIR "ȫ��һ��鴤����������Я�ļ�������"
              "�������У���ʹ�ѵ���\n" NOR;

        if (! target->query_condition("poison"))
        {
                target->affect_by("poison",
                        (["level":me->query("jiali")*3+random(me->query("jiali")),
                           "name"     : "��������",
                           "id":me->query("id"),
                           "duration" : 80 ]));

                msg += WHT "��ʱ��$n" WHT "����һ���溮ɢ���߾�����"
                       "���·���ѪҺ��ֹͣ��������\n" NOR;
        }
        return msg;
}
void clear_no_exert(object target)
{
        if (! objectp(target))return;

        target->delete_temp("no_exert");
}

string attack6(object me, object target, int damage)
{

        string msg;

        msg = HIR "$N" HIR "����Ѹ��֮������$n" HIR "�����м���أ�"
              "�����ӵ��������ִ��С�\n" NOR;

        if( !target->query_temp("no_exert") )
        {
                target->set_temp("no_exert", 1);
                remove_call_out("clear_no_exert");
                call_out("clear_no_exert", 20, target);

                msg += WHT "$n" WHT "ֻ�е�ȫ��������ɢ����Ԫ�߽⣬��"
                       "�����е��书�������Ŵ�����\n" NOR;
        }
        return msg;
}