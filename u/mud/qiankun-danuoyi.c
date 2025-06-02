// This program is a part of NT MudLIB
// qiankun-danuoyi.c Ǭ����Ų��

#include <ansi.h>;
#include <combat.h>

inherit SKILL;

string type() { return "martial"; }
string martialtype() { return "parry"; }
int qk_layer(object me);
//string main_skill() { return "yinyang-shiertian"; }

string *parry_msg = ({
        HIY"$Nһ�л���$n���ϣ�ȴ��$n����Ǭ����Ų�ƣ�����������������¡�\n"NOR,
        HIW"$n����һ����$N�����Լ������ػ��������ŵ������˼�����\n"NOR,
        HIC"$n�ֱۻ�ת����$N����������һ�ƣ�$N������ա�\n"NOR,
        HIG"$n�����������$N����������һ����$N���Ʋ�ס��ֱ��ǰ��ȥ��\n"NOR,
        MAG"$n���β�����$Nһ�л��£�����ʯ���󺣣�������ס�ˡ�\n"NOR,
        HIM"$n��ǣ������$N��������������ת�˺ü���Ȧ��\n"NOR,
        GRN"$n˫�ֻ�Ȧ��$Nֻ����ǰ�������һ��ǽ����Ҳ������ȥ��\n"NOR,
        HIY"$n����һת��$Nһ�л��ڵ��ϣ�ֻ��ó������\n"NOR,
});
mapping *action = ({
([      "action": "$n����һת��һ�л��ڵ��ϣ�ֻ��ó������",
        "force" : 350,
        "attack": 90,
        "dodge" : -90,
        "parry" : -90,
        "damage": 100,
        "damage_type":  "����"
]),
});
string *pfail_msg = ({
        "$n����Ǭ����Ų�ƣ���ͼ����������������£�Ȼ��$N���ѿ������а�������仯Ī�⡣\n",
        "$n����һ����$N�����Լ������ػ���������æ���У���ת���⣬����$n����ʤ����\n",
        "$n�ֱۻ�ת����$N����������һ�ƣ�Ȼ��$N��������һ�䣬��δ��ա�\n",
        "$n�����������$N����������һ����$N���Ʋ�ס��˳�Ʊ�����ǰֱ����\n",
        "$n��ǣ������$N����������˳�Ʊ��У�Բת���⣬����������\n",
        "$n˫�ֻ�Ȧ��$Nֻ����ǰ�������һ��ǽ����Ȼ���ѣ�������һ�㣬�����Է���\n",
});
string *dodge_msg = ({
        "$Nһ�л���$n���ϣ�ȴ��$n����Ǭ����Ų�ƣ�����������������¡�\n",
        "$n����һ����$N�����Լ������ػ��������ŵ������˼�����\n",
        "$n�ֱۻ�ת����$N����������һ�ƣ�$N������ա�\n",
        "$n�����������$N����������һ����$N���Ʋ�ס��ֱ��ǰ��ȥ��\n",
        "$n���β�����$Nһ�л��£�����ʯ���󺣣�������ס�ˡ�\n",
        "$n��ǣ������$N��������������ת�˺ü���Ȧ��\n",
        "$n˫�ֻ�Ȧ��$Nֻ����ǰ�������һ��ǽ����Ҳ������ȥ��\n",
        "$n����һת��$Nһ�л��ڵ��ϣ�ֻ��ó������\n",
});

int valid_enable(string usage)
{
        return (usage == "parry") /*|| (usage == "dodge") || (usage=="move")*/;
}

string query_parry_msg(string limb)
{
        return parry_msg[random(sizeof(parry_msg))];
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int valid_research(object me)
{
        int canlvl;
        canlvl = ((int)query("int", me) - 30 ) * 50;

        if (query("int", me) < 34 &&
                me->query_skill("qiankun-danuoyi", 1) >= canlvl )
                return notify_fail(HIG "����ø����ε�Ǭ����Ų��ʵ��������ޱȣ�ȫȻ�޷���⡣\n" NOR);

        if (me->query_skill("qiankun-danuoyi", 1) < 310)
                return notify_fail(HIG "���Ǭ����Ų�Ƶ���ʶ�������������о���ߣ�\n" NOR);

        return 1;
}

int valid_learn(object me)
{
        int layer;

        if( (!me->query_family() ||
            me->query_family() != "����") && (!query("reborn/times", me) || member_array("����", query("reborn/fams", me)) == -1) )
                return notify_fail("�㲻���������ˣ��޷���ϰ��\n");

        if (query("gender", me) == "����" &&
            me->query_skill("qiankun-danuoyi", 1) >= 50)
                return notify_fail("����ͼ�����ķ�������Ų�ƣ�ȴ"
                                   "��������һ����ã�����Լ�����\n");

        if (me->query_condition("qiankun-except"))
                return notify_fail("������������������֫�Ժ������"
                                   "����޷����������񹦡�\n");

        layer = (int)me->query_skill("qiankun-danuoyi", 1) / 50;
        if (layer > 7) layer = 7;

        if (query("int", me) < 27 + layer)
                return notify_fail("����õ�" + chinese_number(layer) +
                                   "��Ǭ����Ų��ʵ��������ޱȣ�ȫȻ�޷���⡣\n");

        if ((int)query("max_neili", me) < 6000)
                return notify_fail("���������Ϊ̫��޷�����Ǭ����Ų�ơ�\n");

        if ((int)me->query_skill("force") < 450)
                return notify_fail("����ڹ���򲻹����޷�����Ǭ����Ų�ơ�\n");

        if ((int)me->query_skill("parry", 1) < (int)me->query_skill("qiankun-danuoyi", 1))
                return notify_fail("��Ļ����мܻ�����ޣ��޷����������Ǭ����Ų�ơ�\n");

        if ((int)me->query_skill("force", 1) < (int)me->query_skill("qiankun-danuoyi", 1))
                return notify_fail("��Ļ����ڹ�������ޣ��޷����������Ǭ����Ų�ơ�\n");

        return 1;
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mapping result;
        string msg;
        mapping sk, ma;
        int ap, dp, mp;
        string wn, na;
                string vid;
                
        if (!ob || ! living(ob))
                return; 
                vid = query("id", ob);          
        sk = ob->query_skills();
        ma = ob->query_skill_map();

        if ((int)me->query_skill("qiankun-danuoyi", 1) < 100
           || ! living(me))
                return;
       
        mp = ob->query_skill("count", 1);
        ap = attack_power(ob,"force") + mp;
        dp = defense_power(me,"parry");
        
                //����Ǭ����Ų�ƵĲ���
                ap+= ap*qk_layer(me)/10; 
                
        // Ų��Ǭ��Ч��
        if (query_temp("nuozhuan", me))
        {
                me->stop_busy();
                me->clear_weak();
                me->clear_freeze();
        }

        if( (ap / 3 + random(ap/3) < dp || (query_temp("nuozhuan", me) && random(100) < 90))
        //&&  !me->is_busy()
        && playerp(me)
        &&  !query_temp("nuoyi", me)
        &&  !query_temp("nuoyi", ob)
        &&  me->query_skill("qiankun-danuoyi", 1) > 350
        //&&  query("max_neili", me) > random(query("max_neili", ob))
        &&  sizeof(sk)
        &&  sizeof(ma) != 0
        &&  mapp(ma))
        {
                if (objectp(weapon = query_temp("weapon", ob)))
                {
                        wn = query("skill_type", weapon);
                        na = ob->query_skill_mapped(wn);
                } else

                if (ob->query_skill_prepared("finger"))
                        na = ob->query_skill_mapped("finger");
                else

                if (ob->query_skill_prepared("strike"))
                        na = ob->query_skill_mapped("strike");
                else

                if (ob->query_skill_prepared("claw"))
                        na = ob->query_skill_mapped("claw");
                else

                if (ob->query_skill_prepared("cuff"))
                        na = ob->query_skill_mapped("cuff");
                else

                if (ob->query_skill_prepared("hand"))
                        na = ob->query_skill_mapped("hand");
                else
                        na = ob->query_skill_mapped("unarmed");

                msg = HIM "\n$N" HIM "һ�й�����ȴ��$n" HIM "ӭ���"
                      "�ϣ���Ц����������" + CHINESE_D->chinese(na) +
                      HIM "�������ҺΣ���\n$n" HIM "��������Ǭ����Ų"
                      "�Ƶ��߲��ķ�����ͼŲ��$N" HIM "�Ĺ��ơ�\n\n" NOR;
                                          
                set_temp("nuoyi/"+vid, 1, me);
                me->start_call_out((: call_other, __FILE__, "nuoyi",
                                      ob, me, damage, vid :), 1);
                // me->start_busy(2);

                result = ([ "damage" : -damage,
                            "msg"    : msg ]);

                return result;
        } else
        if (ap / 4 + random(ap/4) < dp || (query_temp("nuozhuan", me) && random(100) < 90))
        {
                msg = parry_msg[random(sizeof(parry_msg))];
                msg = replace_string(msg, "$N", "$N" HIG);
                msg = replace_string(msg, "$n", "$n" HIG);
                msg = HIG + msg + NOR;

                result = ([ "damage": -damage,
                            "msg"   : msg ]);

                return result;
        } else
        if (mp >= 100)
        {
                msg = pfail_msg[random(sizeof(pfail_msg))];
                msg = replace_string(msg, "$N", "$N" HIY);
                msg = replace_string(msg, "$n", "$n" HIY);
                msg = HIY + msg + NOR;
                COMBAT_D->set_bhinfo(msg);
        }
}

void skill_improved(object me)
{
        int lvl;
        int layer;

        lvl = me->query_skill("qiankun-danuoyi", 1);
        layer = lvl / 50;
        if (layer > 7) layer = 7;

        if (! layer)
        {
                tell_object(me, HIM "��Ǳ������Ǭ����Ų"
                            "���ķ�����������\n" NOR);
        } else
        if ((lvl % 50) == 0)
        {
                tell_object(me, HIM "���������˵�" + chinese_number(layer) +
                            "���Ǭ����Ų���ķ���\n" NOR);
        } else
                tell_object(me, HIM "��Ե�" + chinese_number(layer) +
                            "���Ǭ����Ų���ķ��ּ�����һ���˽⡣\n" NOR);

        if( query("special_skill/nopoison", me) ) return;
        if (lvl > me->query_skill("force") * 2 / 3)
        {
                if (lvl < me->query_skill("force") * 2 / 3 + 10)
                {
                        tell_object(me, HIG "�������Ϣһ�����ң�����ʱ��ʱ"
                                        "�ȣ����ɵô��һ����\n����Ī������"
                                        "����ħ������Խ��Խ�Ǻ��䣬��Ϊ����"
                                        "��\n" NOR);

                        message("vision", HIG + me->name() + HIG "����ɫ����"
                                          "���̣���ò�ͣ��ֻ�ǻ����������"
                                          "��ʮ��ʹ�ࡣ\n" NOR,
                                          environment(me), ({ me }));
                        return;
                }
                tell_object(me, HIB "���Ȼ���õ�������һ���⣬��ʱ����֫"
                                "����һ���ú����ޱȣ��̲�ס����������\n" NOR);

                message("vision", HIB + me->name() + HIB "��Ȼһ������ɫ��Ȼ"
                                  "��òҰף���Ȼ������һ��������������ֹ��"
                                  "\n" NOR, environment(me), ({ me }));
        } else

        if (lvl < 350 && (lvl * 20 + 4000) > query("max_neili", me))
        {
                if ((lvl * 20 + 4000) < query("max_neili", me) + 200)
                {
                        tell_object(me, HIR "��������ת��һ����Ϣ��һʱ������"
                              "�����ã��������ǲ�ҪóȻ������Ų���񹦡�\n" NOR);
                        return;
                }

                tell_object(me, HIR "��������ת��һ����Ϣ����Ȼ����һ����"
                      "��Ȼת����������ʱ���н�ʹ���������˼�����Ѫ��\n" NOR);
                message("vision", HIR + me->name() + HIR "��ɫ��Ȼ"
                        "һ�䣬Ż��������Ѫ����Ŀ���ġ�\n" NOR,
                        environment(me), ({ me }));
        } else
                return;

        me->apply_condition("qiankun-except", lvl +
           (int)me->query_condition("qiankun-except"));
}

void nuoyi(object ob, object me, int damage,string vid)
{
        string msg;
        int ap, dp, delta, jy, qk, fmsk, flagremote;

        if (! ob
           || ! living(me)
           || ! me->is_fighting(ob)
           || ! query_temp("nuoyi/" + vid, me))
                   {
                      set_temp("nuoyi/"+vid, 0, me);
              return;
                        }

        msg = HIM "\n$N" HIM "Ǭ����Ų�Ƶ��߲��ķ�ʩչ�������ٽ���ǰ������"
              "��ʮ��������鲢Ϊһ�ƣ���$n" HIM "���Ķ����������һ�����"
              "��ɽ�鱬��ʱ�����˺�ˮȴͻȻ��������ˮ�������һ�㡣\n" NOR;
                          
        jy = me->query_skill("jiuyang-shengong",1);
                qk = me->query_skill("qiankun-danuoyi",1);
                fmsk = me->query_skill("guangming-jing",1);
                
                if(jy > 6000  || qk > 5000) flagremote = SPECIAL_ATTACK;
                if(jy > 12000 || qk > 10000) flagremote = REMOTE_ATTACK;
                
        ap = attack_power(me, "unarmed");
        dp = defense_power(ob, "force");
        ap+= ap*fmsk/100*5/100;
        // me->start_busy(2);
        delta = ABILITY_D->check_ability(me, "power-qkdny-nuozhuan"); // ����ab
        if( delta ) 
                {
                    ap += ap*delta/100;
            damage += damage*delta/100;
                }
        damage *= 10;
        if (dp / 2 + random(dp) < ap)
        {
                msg += COMBAT_D->do_damage(me, ob, flagremote, damage, 200+fmsk/10,
                                           HIR "ֻ��$n" HIR "һ���ҽУ���$N"
                                           HIR "���ص��������˸�ʮ�㣬ȫ��"
                                           "�꿦��һ����죬��ǡ��۹ǡ����"
                                           "���߹Ǿ�Ȼһ���۶ϡ�\n" NOR);
        } else
        {
                msg += HIC "$n" HIC "�ۼ�$P������ӿ������"
                       "���⣬ʩ������������⿪����\n" NOR;
        }
 
        message_sort(msg, me, ob);
}

int practice_skill(object me)
{
        return notify_fail("Ǭ����Ų��ֻ��ͨ����<<Ǭ����Ų���ķ�>>��ߡ�\n");
}
int qk_layer(object me)
{
        int lvl;
                lvl = me->query_skill("qiankun-danuoyi", 1);
                
                if(lvl < 30)    return 1;
                if(lvl <240)    return 2;
                if(lvl <810)    return 3;
                if(lvl <1920)   return 4;
                if(lvl <3750)   return 5;
                if(lvl <6780)   return 6;
                if(lvl <10290)  return 7;
                return 8;
}
int query_effect_parry(object attacker, object me)
{
        int lvl;

        lvl = me->query_skill("qiankun-danuoyi", 1);
        if (lvl < 50) return 50;
        if (lvl < 100) return 80;
        if (lvl < 150) return 100;
        if (lvl < 200) return 120;
        if (lvl < 250) return 130;
        if (lvl < 300) return 140;
        if (lvl < 350) return 150;
        if (lvl < 400) return 200;
        return 220;
}

string perform_action_file(string action)
{
        return __DIR__"qiankun-danuoyi/" + action;
}

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1.5; }

int help(object me)
{
        write(HIC"\nǬ����Ų�ƣ�"NOR"\n");
        write(@HELP

    ��Ǭ����Ų�ơ������������ഫһ�����������书�������̵�
�����񹦡�Ϊ��˹���ɽ������������ר�Ž�������ʹ���ķ��š�
��ԭ���õ������٣���������ʮ�����������������󣬼���ʧ����
���������޼�һ�����������������ڹ�һ�����ɡ�Ǭ����Ų��ֻ
���мܺ��Ṧ�ã����߹�����������֮�����ǿ��԰ѱ��˵�������
�����ڶԷ���
    Ǭ����Ų���񹦵���ּ�����ڵߵ�һ��һ�ᡢһ��һ����Ǭ��
�����������ֳ����֮ɫ����������ѪҺ�����������任֮����
��������ʱ��ȫ���ܺ�����࣬�������߲�ʱ����������ת����
��֪����֮�䣬�����ϱ���Ҳ�Ʋ��������ˡ����������Ҳ����
��ΰ��ֻ�������󼤷�����Ǳ����Ȼ��ǣ��Ų�Ƶо���������
�仯���棬ȴ�Ƿ�����˼��

        ѧϰҪ��
                �����ڹ�100�������õ���Ǭ����Ų�Ƶļ���
                �����񹦲��õ���Ǭ����Ų�Ƶļ���
                ����1500�����õ���Ǭ����Ų�Ƶļ����15��
                ̫���޷�����100�����ϵ�Ǭ����Ų��
HELP
        );
        return 1;
}

