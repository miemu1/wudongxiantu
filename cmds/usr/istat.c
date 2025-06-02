// This program is a part of NT MudLIB
// stats cmds

#include <ansi.h>
#include <mudlib.h>
#include <command.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob;
        string sp;

        seteuid(getuid(me));

        if( !wizardp(me) && time()-query_temp("last_stats", me)<5 )
                return notify_fail("ϵͳ�������̾���������� ....\n");

        set_temp("last_stats", time(), me);
        MYGIFT_D->check_mygift(me, "newbie_mygift/istat");

        if( arg && (arg == "-jingmai"
        ||  sscanf(arg, "-jingmai %s", arg)
        ||  sscanf(arg, "%s -jingmai", arg)) )
        {
                if( arg == "-jingmai" )
                        ob = me;
                else
                if( wizardp(me) || query("couple/child_id", me) )
                {
                        ob = present(arg, environment(me));

                        if (! ob || ! ob->is_character())
                                ob = find_player(arg);

                        if (! ob || ! ob->is_character())
                                ob = find_living(arg);

                        if (! ob || ! ob->is_character() || ! me->visible(ob))
                                return notify_fail("��Ҫ�쿴˭��״̬��\n");

                        if( !wizardp(me) && query("couple/child_id", me) != query("id", ob) )
                                return notify_fail("��Ҫ�쿴˭��״̬��\n");

                } else
                        return notify_fail("ֻ����ʦ�ܲ쿴���˵�״̬��\n");
                
        sp = ZJOBLONG;
        sp += HIM + (ob == me ? "��" : ob->name(1)) + "Ŀǰ�ĸ���������Ч��һ��\n" NOR;
        sp += HIC "��" HIY "������--==�츳�ӳ�==--������" HIC "��\n" NOR;;

                        sp += sprintf(HIC "���������ӡ�" HIG " %9d / %-9d"
                                      HIC "�����Ը��ӡ�" HIG " %9d / %d\n"
                                      HIC "�����Ǹ��ӡ�" HIG " %9d / %-9d"
                                      HIC "�������ӡ�" HIG " %9d / %d\n\n",
                                      ob->query_jingmai_buff("str"),2000,
                                      ob->query_jingmai_buff("int"),2000,
                                      ob->query_jingmai_buff("con"),2000,
                                      ob->query_jingmai_buff("dex"),2000);
        sp += HIC "��" HIY "������--==���޼ӳ�==--������" HIC "��\n" NOR;

                        sp += sprintf(HIC "��Ǳ�����ޡ�" HIM " %9d / %-9d"
                                      HIC "��������ޡ�" HIM " %9d / %d\n"
                                      HIC "���������ޡ�" HIM " %9d / %-9d"
                                      HIC "���������ޡ�" HIM " %9d / %d\n"
                                      HIC "����Ѫ���ޡ�" HIM " %9d / %-9d"
                                      HIC "���������ޡ�" HIM " %9d / %d\n\n",
                                      ob->query_jingmai_buff("max_potential"),10000000,
                                      ob->query_jingmai_buff("max_experience"),10000000,
                                      ob->query_jingmai_buff("max_neili"),2000000,
                                      ob->query_jingmai_buff("max_jingli"),1000000,
                                      ob->query_jingmai_buff("max_qi"),2000000,
                                      ob->query_jingmai_buff("max_jing"),1000000);   
     
        sp += HIC "��" HIY "������--==�����ӳ�==--������" HIC "��\n" NOR;

                        sp += sprintf(HIC "���о�������" HIY " %9d / %-9d"
                                      HIC "���о�Ч����" HIY " %9s / %s\n"
                                      HIC "����ϰ������" HIY " %9d / %-9d"
                                      HIC "����ϰЧ����" HIY " %9s / %s\n"
                                      HIC "��ѧϰ������" HIY " %9d / %-9d"
                                      HIC "��ѧϰЧ����" HIY " %9s / %s\n"
                                      HIC "����ȡ���ġ�" HIY " %9d / %-9d"
                                      HIC "����ȡЧ����" HIY " %9s / %s\n\n",
                                      ob->query_jingmai_buff("research_times"),2000,
                                      ob->query_jingmai_buff("research_effect")+"%","2000%",
                                      ob->query_jingmai_buff("practice_times"),2000,
                                      ob->query_jingmai_buff("practice_effect")+"%","2000%",
                                      ob->query_jingmai_buff("learn_times"),2000,
                                      ob->query_jingmai_buff("learn_effect")+"%","2000%",
                                      ob->query_jingmai_buff("derive_times"),2000,
                                      ob->query_jingmai_buff("derive_effect")+"%","2000%");

        sp += HIC "��" HIY "������--==���мӳ�==--������" HIC "��\n" NOR;
                        sp += sprintf(RED "���� �� ����" RED " %9s / %-9s"
                                      RED "����    ����" RED " %9s / %s\n"
                                      RED "��ħ �� ����" RED " %9s / %-9s"
                                      RED "����    ħ��" RED " %9s / %s\n"
                                      RED "���� �� ����" RED " %9s / %-9s"
                                      RED "����    ��" RED " %9s / %s\n"
                                      RED "��ľ �� ����" RED " %9s / %-9s"
                                      RED "����    ľ��" RED " %9s / %s\n"
                                      RED "��ˮ �� ����" RED " %9s / %-9s"
                                      RED "����    ˮ��" RED " %9s / %s\n"
                                      RED "���� �� ����" RED " %9s / %-9s"
                                      RED "����    ��" RED " %9s / %s\n"
                                      RED "���� �� ����" RED " %9s / %-9s"
                                      RED "����    ����" RED " %9s / %s\n\n",
                                      ob->query_jingmai_buff("add_poison")+"%","100%",ob->query_jingmai_buff("reduce_poison")+"%","100%",
                                      ob->query_jingmai_buff("add_magic")+"%","100%",ob->query_jingmai_buff("reduce_magic")+"%","100%",
                                      ob->query_jingmai_buff("add_metal")+"%","100%",ob->query_jingmai_buff("reduce_metal")+"%","100%",
                                      ob->query_jingmai_buff("add_wood")+"%","100%",ob->query_jingmai_buff("reduce_wood")+"%","100%",
                                      ob->query_jingmai_buff("add_water")+"%","100%",ob->query_jingmai_buff("reduce_water")+"%","100%",
                                      ob->query_jingmai_buff("add_fire")+"%","100%",ob->query_jingmai_buff("reduce_fire")+"%","100%",
                                      ob->query_jingmai_buff("add_earth")+"%","100%",ob->query_jingmai_buff("reduce_earth")+"%","100%");

        sp += HIC "��" HIY "������--==״̬�ָ�==--������" HIC "��\n" NOR;
                        sp += sprintf(HIB "��͵ȡ������" HIB " %9s / %-9s"
                                      HIB "��͵ȡ������" HIB " %9s / %s\n\n",
                                      ob->query_jingmai_buff("leech_neili")+"%","90%",
                                      ob->query_jingmai_buff("leech_qi")+"%","90%");

        sp += HIC "��" HIY "������--==ս���ӳ�==--������" HIC "��\n" NOR;

                        sp += sprintf(WHT "�������ȼ���" HIW " %9d / %-9d" NOR
                                      WHT "�������ȼ���" HIW " %9d / %d\n" NOR
                                      WHT "�������ȼ���" HIW " %9d / %-9d" NOR
                                      WHT "���мܵȼ���" HIW " %9d / %d\n" NOR
                                      WHT "���������С�" HIW " %9s / %-9s" NOR
                                      WHT "�����з�����" HIW " %9s / %s\n" NOR
                                      WHT "�������˺���" HIG " %9d / %-9d" NOR
                                      WHT "�������˺���" HIG " %9d / %d\n" NOR
                                      WHT "�������˺���" HIG " %9s / %-9s" NOR
                                      WHT "��ս��������" HIG " %9d / %d\n" NOR
                                      /*
                                      WHT "�������˺���" HIG " %9d / %-9d" NOR
                                      WHT "�����ӱ�����" HIG " %9d / %d\n" NOR
                                      WHT "�������˺���" HIG " %9d / %-9d" NOR
                                      WHT "�����챣����" HIG " %9d / %d\n" NOR
                                      */
                                      WHT "�������мܡ�" HIY " %9s / %-9s" NOR
                                      WHT "�����Ӷ�����" HIY " %9s / %s\n" NOR
                                      WHT "�������ع���" HIY " %9s / %-9s" NOR
                                      WHT "�������ڷ���" HIY " %9s / %s\n\n" NOR,
                                      ob->query_jingmai_buff("attack"),9000,
                                      ob->query_jingmai_buff("defense"),9000,
                                      ob->query_jingmai_buff("dodge"),9000,
                                      ob->query_jingmai_buff("parry"),9000,
                                      ob->query_jingmai_buff("ap_power")+"%","120%",
                                      ob->query_jingmai_buff("dp_power")+"%","120%",
                                      ob->query_jingmai_buff("damage"),200000,
                                      ob->query_jingmai_buff("unarmed_damage"),200000,
                                      ob->query_jingmai_buff("da_power")+"%","120%",
                                      ob->query_jingmai_buff("armor"),200000,
                                      //query_temp("apply/damage1", ob),200000,query_temp("apply/armor1", ob),200000,
                                      //query_temp("apply/damage2", ob),200000,query_temp("apply/armor2", ob),200000,
                                      ob->query_jingmai_buff("avoid_parry")+"%","90%",
                                      ob->query_jingmai_buff("avoid_dodge")+"%","90%",
                                      ob->query_jingmai_buff("avoid_attack")+"%","90%",
                                      ob->query_jingmai_buff("avoid_force")+"%","90%");                      
        sp += HIC "��" HIY "������--==�߼�����==--������" HIC "��\n" NOR;
                        sp += sprintf(HIW "������æ�ҡ�" HIM " %9d / %-9d"
                                      HIW "��Ѱ �� �ʡ�" HIM " %9s / %s\n"
                                      HIW "��˫���˺���" CYN " %9s / %-9s"
                                      HIW "����ת������" CYN " %9s / %s\n"  
                                      HIW "����    ä��" CYN " %9s / %-9s"
                                      HIW "��������ä��" CYN " %9s / %s\n"
                                      HIW "����͸�Ƽס�" CYN " %9s / %-9s"
                                      HIW "���ٶ����֡�" CYN " %9s / %s\n"
                                      HIW "��ս���塿" CYN " %9s / %-9s\n\n",
                                      ob->query_jingmai_buff("reduce_busy"),90,
                                      ob->query_jingmai_buff("magic_find")+"%","300%",
                                      ob->query_jingmai_buff("double_damage")+"%","200%",
                                      ob->query_jingmai_buff("qi_abs_neili")+"%","90%",
                                      ob->query_jingmai_buff("add_blind")+"%","90%",
                                      ob->query_jingmai_buff("avoid_blind")+"%","90%",
                                      ob->query_jingmai_buff("through_armor")+"%","90%",
                                      ob->query_jingmai_buff("avoid_poison")+"%","100%",
                                      ob->query_jingmai_buff("full_self")+"%","90%");
                      
        sp += HIC "��" HIY "������--==�ռ�����==--������" HIC "��\n" NOR;
                        sp += sprintf(HIY "����    ����" HIM " %9s / %-9s"
                                      HIY "�����ӱ�����" HIM " %9s / %s\n"
                                      /*
                                      HIY "��ѣ    �Ρ�" HIM " %9s / %-9s"
                                      HIY "������ѣ�Ρ�" HIM " %9s / %s\n"
                                      */
                                      HIY "����    ����" HIM " %9s / %-9s"
                                      HIY "������������" HIM " %9s / %s\n"
                                      HIY "��æ    �ҡ�" HIM " %9d / %-9d"
                                      HIY "������æ�ҡ�" HIM " %9s / %s\n"
                                      HIY "����    ����" HIM " %9s / %-9s"
                                      HIY "������������" HIM " %9s / %s\n"
                                      HIY "��׷���˺���" HIM " %9s / %-9s"
                                      HIY "�������˺���" HIM " %9s / %s\n"
                                      HIY "���˺����ɡ�" HIM " %9s / %-9s"
                                      HIY "��ԡѪ������" HIM " %9s / %s\n"                      
                                      HIY "������һ����" HIM " %9s / %-9s"
                                      HIY "���������ܡ�" HIM " %9d / %d\n\n",
                                      ob->query_jingmai_buff("add_freeze")+"%","90%",ob->query_jingmai_buff("avoid_freeze")+"%","90%",
                                      /*
                                      ob->query_jingmai_buff("add_dizziness")+"%","90%",ob->query_jingmai_buff("avoid_dizziness")+"%","90%",                    ;:207c
                                      */
                                      ob->query_jingmai_buff("add_forget")+"%","90%",ob->query_jingmai_buff("avoid_forget")+"%","90%",
                                      ob->query_jingmai_buff("add_busy"),90,ob->query_jingmai_buff("avoid_busy")+"%","90%",
                                      ob->query_jingmai_buff("add_weak")+"%","90%",ob->query_jingmai_buff("avoid_weak")+"%","90%",
                                      ob->query_jingmai_buff("add_damage")+"%","200%",
                                      ob->query_jingmai_buff("reduce_damage")+"%","90%",
                                      ob->query_jingmai_buff("counter_damage")+"%","90%",ob->query_jingmai_buff("avoid_die")+"%","90%",
                                      ob->query_jingmai_buff("fatal_blow")+"%","90%",ob->query_jingmai_buff("add_skill"),1200);

        sp += HIC "��" HIY "������--==���߹���==--������" HIC "��\n" NOR;

                        sp += sprintf(HIG + (ob == me ? "��" : ob->name()) + HIG "��%s���Ѿ������� " NOR + HIC "%s\n" NOR,
                                      LOCAL_MUD_NAME(), time_period(query("online_time", ob)));

                        if( MEMBER_D->is_valid_member(ob) )
                                sp += sprintf(HIG + (ob == me ? "��" : ob->name()) + HIG "��������������ʱ�仹�� " NOR + HIY "������\n" NOR);
                        else
                        {
                                if( query("online_time", ob)/3<query("offline_time", ob) )
                                        set("offline_time",query("online_time",  ob)/3, ob);
                                sp += sprintf(HIG + (ob == me ? "��" : ob->name()) + HIG "��������������ʱ�仹�� " NOR + HIY "%s\n" NOR,
                                              time_period(query("online_time", ob)/3-query("offline_time", ob)));
                        }

                        sp += sprintf(HIG + (ob == me ? "��" : ob->name()) + HIG "�����˫������ʱ�仹�� " NOR + HIW "%s\n" NOR,
                                      time_period(query("time_reward/quest", ob)));
                        sp += sprintf(HIG + (ob == me ? "��" : ob->name()) + HIG "����ĸ�Ч����ʱ�仹�� " NOR + HIM "%s\n" NOR,
                                      time_period(query("time_reward/study", ob)));


                        me->start_more(sp);
                        return 1;
        }

        if( arg && (arg == "-yuanshen"
        ||  sscanf(arg, "-yuanshen %s", arg)
        ||  sscanf(arg, "%s -yuanshen", arg)) )
        {
                if( arg == "-yuanshen" )
                        ob = me;
                else
                if( wizardp(me) || query("couple/child_id", me) )
                {
                        ob = present(arg, environment(me));

                        if (! ob || ! ob->is_character())
                                ob = find_player(arg);

                        if (! ob || ! ob->is_character())
                                ob = find_living(arg);

                        if (! ob || ! ob->is_character() || ! me->visible(ob))
                                return notify_fail("��Ҫ�쿴˭��״̬��\n");

                        if( !wizardp(me) && query("couple/child_id", me) != query("id", ob) )
                                return notify_fail("��Ҫ�쿴˭��״̬��\n");

                } else
                        return notify_fail("ֻ����ʦ�ܲ쿴���˵�״̬��\n");
                
                        sp = HIM + (ob == me ? "��" : ob->name(1)) + "Ŀǰ��Ԫ�񸽼�����Ч��һ��\n" NOR;
                        //sp += HIC "��" HIY "������������������������������������������������������������������������" HIC "��\n" NOR;
                        sp += HIC "��" HIY "����������������������������--==�츳�ӳ�==--����������������������������" HIC "��\n\n" NOR;

                        sp += sprintf(HIC "���������ӡ�" HIG " %9d / %-9d"
                                      HIC "�����Ը��ӡ�" HIG " %9d / %d\n"
                                      HIC "�����Ǹ��ӡ�" HIG " %9d / %-9d"
                                      HIC "�������ӡ�" HIG " %9d / %d\n\n",
                                      ob->query_yuanshen_buff("str"),2000,
                                      ob->query_yuanshen_buff("int"),2000,
                                      ob->query_yuanshen_buff("con"),2000,
                                      ob->query_yuanshen_buff("dex"),2000);
                        sp += HIC "��" HIY "������������������������������������������������������������������������" HIC "��\n" NOR;
                        sp += HIC "��" HIY "����������������������������--==���޼ӳ�==--����������������������������" HIC "��\n\n" NOR;
                        sp += sprintf(HIC "��Ǳ�����ޡ�" HIM " %9d / %-9d"
                                      HIC "��������ޡ�" HIM " %9d / %d\n"
                                      HIC "���������ޡ�" HIM " %9d / %-9d"
                                      HIC "���������ޡ�" HIM " %9d / %d\n"
                                      HIC "����Ѫ���ޡ�" HIM " %9d / %-9d"
                                      HIC "���������ޡ�" HIM " %9d / %d\n\n",
                                      ob->query_yuanshen_buff("max_potential"),10000000,
                                      ob->query_yuanshen_buff("max_experience"),10000000,
                                      ob->query_yuanshen_buff("max_neili"),2000000,
                                      ob->query_yuanshen_buff("max_jingli"),1000000,
                                      ob->query_yuanshen_buff("max_qi"),2000000,
                                      ob->query_yuanshen_buff("max_jing"),1000000);        
                        sp += HIC "��" HIY "������������������������������������������������������������������������" HIC "��\n" NOR;
                        sp += HIC "��" HIY "����������������������������--==�����ӳ�==--����������������������������" HIC "��\n\n" NOR;
                        sp += sprintf(HIC "���о�������" HIY " %9d / %-9d"
                                      HIC "���о�Ч����" HIY " %9s / %s\n"
                                      HIC "����ϰ������" HIY " %9d / %-9d"
                                      HIC "����ϰЧ����" HIY " %9s / %s\n"
                                      HIC "��ѧϰ������" HIY " %9d / %-9d"
                                      HIC "��ѧϰЧ����" HIY " %9s / %s\n"
                                      HIC "����ȡ���ġ�" HIY " %9d / %-9d"
                                      HIC "����ȡЧ����" HIY " %9s / %s\n\n",
                                      ob->query_yuanshen_buff("research_times"),2000,
                                      ob->query_yuanshen_buff("research_effect")+"%","2000%",
                                      ob->query_yuanshen_buff("practice_times"),2000,
                                      ob->query_yuanshen_buff("practice_effect")+"%","2000%",
                                      ob->query_yuanshen_buff("learn_times"),2000,
                                      ob->query_yuanshen_buff("learn_effect")+"%","2000%",
                                      ob->query_yuanshen_buff("derive_times"),2000,
                                      ob->query_yuanshen_buff("derive_effect")+"%","2000%");
                        sp += HIC "��" HIY "������������������������������������������������������������������������" HIC "��\n" NOR;
                        sp += HIC "��" HIY "����������������������������--==���мӳ�==--����������������������������" HIC "��\n\n" NOR;
                        sp += sprintf(RED "���� �� ����" RED " %9s / %-9s"
                                      RED "����    ����" RED " %9s / %s\n"
                                      RED "��ħ �� ����" RED " %9s / %-9s"
                                      RED "����    ħ��" RED " %9s / %s\n"
                                      RED "���� �� ����" RED " %9s / %-9s"
                                      RED "����    ��" RED " %9s / %s\n"
                                      RED "��ľ �� ����" RED " %9s / %-9s"
                                      RED "����    ľ��" RED " %9s / %s\n"
                                      RED "��ˮ �� ����" RED " %9s / %-9s"
                                      RED "����    ˮ��" RED " %9s / %s\n"
                                      RED "���� �� ����" RED " %9s / %-9s"
                                      RED "����    ��" RED " %9s / %s\n"
                                      RED "���� �� ����" RED " %9s / %-9s"
                                      RED "����    ����" RED " %9s / %s\n\n",
                                      ob->query_yuanshen_buff("add_poison")+"%","100%",ob->query_yuanshen_buff("reduce_poison")+"%","100%",
                                      ob->query_yuanshen_buff("add_magic")+"%","100%",ob->query_yuanshen_buff("reduce_magic")+"%","100%",
                                      ob->query_yuanshen_buff("add_metal")+"%","100%",ob->query_yuanshen_buff("reduce_metal")+"%","100%",
                                      ob->query_yuanshen_buff("add_wood")+"%","100%",ob->query_yuanshen_buff("reduce_wood")+"%","100%",
                                      ob->query_yuanshen_buff("add_water")+"%","100%",ob->query_yuanshen_buff("reduce_water")+"%","100%",
                                      ob->query_yuanshen_buff("add_fire")+"%","100%",ob->query_yuanshen_buff("reduce_fire")+"%","100%",
                                      ob->query_yuanshen_buff("add_earth")+"%","100%",ob->query_yuanshen_buff("reduce_earth")+"%","100%");
                        sp += HIC "��" HIY "������������������������������������������������������������������������" HIC "��\n" NOR;
                        sp += HIC "��" HIY "����������������������������--==״̬�ָ�==--����������������������������" HIC "��\n\n" NOR;              
                        sp += sprintf(HIB "��͵ȡ������" HIB " %9s / %-9s"
                                      HIB "��͵ȡ������" HIB " %9s / %s\n\n",
                                      ob->query_yuanshen_buff("leech_neili")+"%","90%",
                                      ob->query_yuanshen_buff("leech_qi")+"%","90%");
                        sp += HIC "��" HIY "������������������������������������������������������������������������" HIC "��\n" NOR;
                        sp += HIC "��" HIY "����������������������������--==ս���ӳ�==--����������������������������" HIC "��\n\n" NOR;
                        sp += sprintf(WHT "�������ȼ���" HIW " %9d / %-9d" NOR
                                      WHT "�������ȼ���" HIW " %9d / %d\n" NOR
                                      WHT "�������ȼ���" HIW " %9d / %-9d" NOR
                                      WHT "���мܵȼ���" HIW " %9d / %d\n" NOR
                                      WHT "���������С�" HIW " %9s / %-9s" NOR
                                      WHT "�����з�����" HIW " %9s / %s\n" NOR
                                      WHT "�������˺���" HIG " %9d / %-9d" NOR
                                      WHT "�������˺���" HIG " %9d / %d\n" NOR
                                      WHT "�������˺���" HIG " %9s / %-9s" NOR
                                      WHT "��ս��������" HIG " %9d / %d\n" NOR
                                      /*
                                      WHT "�������˺���" HIG " %9d / %-9d" NOR
                                      WHT "�����ӱ�����" HIG " %9d / %d\n" NOR
                                      WHT "�������˺���" HIG " %9d / %-9d" NOR
                                      WHT "�����챣����" HIG " %9d / %d\n" NOR
                                      */
                                      WHT "�������мܡ�" HIY " %9s / %-9s" NOR
                                      WHT "�����Ӷ�����" HIY " %9s / %s\n" NOR
                                      WHT "�������ع���" HIY " %9s / %-9s" NOR
                                      WHT "�������ڷ���" HIY " %9s / %s\n\n" NOR,
                                      ob->query_yuanshen_buff("attack"),9000,
                                      ob->query_yuanshen_buff("defense"),9000,
                                      ob->query_yuanshen_buff("dodge"),9000,
                                      ob->query_yuanshen_buff("parry"),9000,
                                      ob->query_yuanshen_buff("ap_power")+"%","120%",
                                      ob->query_yuanshen_buff("dp_power")+"%","120%",
                                      ob->query_yuanshen_buff("damage"),200000,
                                      ob->query_yuanshen_buff("unarmed_damage"),200000,
                                      ob->query_yuanshen_buff("da_power")+"%","120%",
                                      ob->query_yuanshen_buff("armor"),200000,
                                      //query_temp("apply/damage1", ob),200000,query_temp("apply/armor1", ob),200000,
                                      //query_temp("apply/damage2", ob),200000,query_temp("apply/armor2", ob),200000,
                                      ob->query_yuanshen_buff("avoid_parry")+"%","90%",
                                      ob->query_yuanshen_buff("avoid_dodge")+"%","90%",
                                      ob->query_yuanshen_buff("avoid_attack")+"%","90%",
                                      ob->query_yuanshen_buff("avoid_force")+"%","90%");                      
                        sp += HIC "��" HIY "������������������������������������������������������������������������" HIC "��\n" NOR;
                        sp += HIC "��" HIY "����������������������������--==�߼�����==--����������������������������" HIC "��\n\n" NOR;        
                        sp += sprintf(HIW "������æ�ҡ�" HIM " %9d / %-9d"
                                      HIW "��Ѱ �� �ʡ�" HIM " %9s / %s\n"
                                      HIW "��˫���˺���" CYN " %9s / %-9s"
                                      HIW "����ת������" CYN " %9s / %s\n"  
                                      HIW "����    ä��" CYN " %9s / %-9s"
                                      HIW "��������ä��" CYN " %9s / %s\n"
                                      HIW "����͸�Ƽס�" CYN " %9s / %-9s"
                                      HIW "���ٶ����֡�" CYN " %9s / %s\n"
                                      HIW "��ս���塿" CYN " %9s / %-9s\n\n",
                                      ob->query_yuanshen_buff("reduce_busy"),90,
                                      ob->query_yuanshen_buff("magic_find")+"%","300%",
                                      ob->query_yuanshen_buff("double_damage")+"%","200%",
                                      ob->query_yuanshen_buff("qi_abs_neili")+"%","90%",
                                      ob->query_yuanshen_buff("add_blind")+"%","90%",
                                      ob->query_yuanshen_buff("avoid_blind")+"%","90%",
                                      ob->query_yuanshen_buff("through_armor")+"%","90%",
                                      ob->query_yuanshen_buff("avoid_poison")+"%","100%",
                                      ob->query_yuanshen_buff("full_self")+"%","90%");
                      
                        sp += HIC "��" HIY "������������������������������������������������������������������������" HIC "��\n" NOR;
                        sp += HIC "��" HIY "����������������������������--==�ռ�����==--����������������������������" HIC "��\n\n" NOR;         
                        sp += sprintf(HIY "����    ����" HIM " %9s / %-9s"
                                      HIY "�����ӱ�����" HIM " %9s / %s\n"
                                      /*
                                      HIY "��ѣ    �Ρ�" HIM " %9s / %-9s"
                                      HIY "������ѣ�Ρ�" HIM " %9s / %s\n"
                                      */
                                      HIY "����    ����" HIM " %9s / %-9s"
                                      HIY "������������" HIM " %9s / %s\n"
                                      HIY "��æ    �ҡ�" HIM " %9d / %-9d"
                                      HIY "������æ�ҡ�" HIM " %9s / %s\n"
                                      HIY "����    ����" HIM " %9s / %-9s"
                                      HIY "������������" HIM " %9s / %s\n"
                                      HIY "��׷���˺���" HIM " %9s / %-9s"
                                      HIY "�������˺���" HIM " %9s / %s\n"
                                      HIY "���˺����ɡ�" HIM " %9s / %-9s"
                                      HIY "��ԡѪ������" HIM " %9s / %s\n"                      
                                      HIY "������һ����" HIM " %9s / %-9s"
                                      HIY "���������ܡ�" HIM " %9d / %d\n\n",
                                      ob->query_yuanshen_buff("add_freeze")+"%","90%",ob->query_yuanshen_buff("avoid_freeze")+"%","90%",
                                      /*
                                      ob->query_yuanshen_buff("add_dizziness")+"%","90%",ob->query_yuanshen_buff("avoid_dizziness")+"%","90%",                    ;:207c
                                      */
                                      ob->query_yuanshen_buff("add_forget")+"%","90%",ob->query_yuanshen_buff("avoid_forget")+"%","90%",
                                      ob->query_yuanshen_buff("add_busy"),90,ob->query_yuanshen_buff("avoid_busy")+"%","90%",
                                      ob->query_yuanshen_buff("add_weak")+"%","90%",ob->query_yuanshen_buff("avoid_weak")+"%","90%",
                                      ob->query_yuanshen_buff("add_damage")+"%","200%",
                                      ob->query_yuanshen_buff("reduce_damage")+"%","90%",
                                      ob->query_yuanshen_buff("counter_damage")+"%","90%",ob->query_yuanshen_buff("avoid_die")+"%","90%",
                                      ob->query_yuanshen_buff("fatal_blow")+"%","90%",ob->query_yuanshen_buff("add_skill"),1200);

                        //sp += HIC "��" HIY "������������������������������������������������������������������������" HIC "��\n" NOR;
                        sp += HIC "��" HIY "����������������������������--==���߹���==--����������������������������" HIC "��\n\n" NOR;
                        sp += sprintf(HIG + (ob == me ? "��" : ob->name()) + HIG "��%s���Ѿ������� " NOR + HIC "%s\n" NOR,
                                      LOCAL_MUD_NAME(), time_period(query("online_time", ob)));

                        if( MEMBER_D->is_valid_member(ob) )
                                sp += sprintf(HIG + (ob == me ? "��" : ob->name()) + HIG "��������������ʱ�仹�� " NOR + HIY "������\n" NOR);
                        else
                        {
                                if( query("online_time", ob)/3<query("offline_time", ob) )
                                        set("offline_time",query("online_time",  ob)/3, ob);
                                sp += sprintf(HIG + (ob == me ? "��" : ob->name()) + HIG "��������������ʱ�仹�� " NOR + HIY "%s\n" NOR,
                                              time_period(query("online_time", ob)/3-query("offline_time", ob)));
                        }

                        sp += sprintf(HIG + (ob == me ? "��" : ob->name()) + HIG "�����˫������ʱ�仹�� " NOR + HIW "%s\n" NOR,
                                      time_period(query("time_reward/quest", ob)));
                        sp += sprintf(HIG + (ob == me ? "��" : ob->name()) + HIG "����ĸ�Ч����ʱ�仹�� " NOR + HIM "%s\n" NOR,
                                      time_period(query("time_reward/study", ob)));


                        me->start_more(sp);
                        return 1;
        }

        if( arg && (arg == "-skillmix"
        ||  sscanf(arg, "-skillmix %s", arg)
        ||  sscanf(arg, "%s -skillmix", arg)) )
        {
                if( arg == "-skillmix" )
                        ob = me;
                else
                if( wizardp(me) || query("couple/child_id", me) )
                {
                        ob = present(arg, environment(me));

                        if (! ob || ! ob->is_character())
                                ob = find_player(arg);

                        if (! ob || ! ob->is_character())
                                ob = find_living(arg);

                        if (! ob || ! ob->is_character() || ! me->visible(ob))
                                return notify_fail("��Ҫ�쿴˭��״̬��\n");

                        if( !wizardp(me) && query("couple/child_id", me) != query("id", ob) )
                                return notify_fail("��Ҫ�쿴˭��״̬��\n");

                } else
                        return notify_fail("ֻ����ʦ�ܲ쿴���˵�״̬��\n");
                
                        sp = HIM + (ob == me ? "��" : ob->name(1)) + "Ŀǰ�ļ�����ϸ�������Ч��һ��\n" NOR;
                        //sp += HIC "��" HIY "������������������������������������������������������������������������" HIC "��\n" NOR;
                        sp += HIC "��" HIY "����������������������������--==�츳�ӳ�==--����������������������������" HIC "��\n\n" NOR;

                        sp += sprintf(HIC "���������ӡ�" HIG " %9d / %-9d"
                                      HIC "�����Ը��ӡ�" HIG " %9d / %d\n"
                                      HIC "�����Ǹ��ӡ�" HIG " %9d / %-9d"
                                      HIC "�������ӡ�" HIG " %9d / %d\n\n",
                                      ob->query_skillmix_buff("str"),2000,
                                      ob->query_skillmix_buff("int"),2000,
                                      ob->query_skillmix_buff("con"),2000,
                                      ob->query_skillmix_buff("dex"),2000);
                        sp += HIC "��" HIY "������������������������������������������������������������������������" HIC "��\n" NOR;
                        sp += HIC "��" HIY "����������������������������--==���޼ӳ�==--����������������������������" HIC "��\n\n" NOR;
                        sp += sprintf(HIC "��Ǳ�����ޡ�" HIM " %9d / %-9d"
                                      HIC "��������ޡ�" HIM " %9d / %d\n"
                                      HIC "���������ޡ�" HIM " %9d / %-9d"
                                      HIC "���������ޡ�" HIM " %9d / %d\n"
                                      HIC "����Ѫ���ޡ�" HIM " %9d / %-9d"
                                      HIC "���������ޡ�" HIM " %9d / %d\n\n",
                                      ob->query_skillmix_buff("max_potential"),10000000,
                                      ob->query_skillmix_buff("max_experience"),10000000,
                                      ob->query_skillmix_buff("max_neili"),2000000,
                                      ob->query_skillmix_buff("max_jingli"),1000000,
                                      ob->query_skillmix_buff("max_qi"),2000000,
                                      ob->query_skillmix_buff("max_jing"),1000000);        
                        sp += HIC "��" HIY "������������������������������������������������������������������������" HIC "��\n" NOR;
                        sp += HIC "��" HIY "����������������������������--==�����ӳ�==--����������������������������" HIC "��\n\n" NOR;
                        sp += sprintf(HIC "���о�������" HIY " %9d / %-9d"
                                      HIC "���о�Ч����" HIY " %9s / %s\n"
                                      HIC "����ϰ������" HIY " %9d / %-9d"
                                      HIC "����ϰЧ����" HIY " %9s / %s\n"
                                      HIC "��ѧϰ������" HIY " %9d / %-9d"
                                      HIC "��ѧϰЧ����" HIY " %9s / %s\n"
                                      HIC "����ȡ���ġ�" HIY " %9d / %-9d"
                                      HIC "����ȡЧ����" HIY " %9s / %s\n\n",
                                      ob->query_skillmix_buff("research_times"),2000,
                                      ob->query_skillmix_buff("research_effect")+"%","2000%",
                                      ob->query_skillmix_buff("practice_times"),2000,
                                      ob->query_skillmix_buff("practice_effect")+"%","2000%",
                                      ob->query_skillmix_buff("learn_times"),2000,
                                      ob->query_skillmix_buff("learn_effect")+"%","2000%",
                                      ob->query_skillmix_buff("derive_times"),2000,
                                      ob->query_skillmix_buff("derive_effect")+"%","2000%");
                        sp += HIC "��" HIY "������������������������������������������������������������������������" HIC "��\n" NOR;
                        sp += HIC "��" HIY "����������������������������--==���мӳ�==--����������������������������" HIC "��\n\n" NOR;
                        sp += sprintf(RED "���� �� ����" RED " %9s / %-9s"
                                      RED "����    ����" RED " %9s / %s\n"
                                      RED "��ħ �� ����" RED " %9s / %-9s"
                                      RED "����    ħ��" RED " %9s / %s\n"
                                      RED "���� �� ����" RED " %9s / %-9s"
                                      RED "����    ��" RED " %9s / %s\n"
                                      RED "��ľ �� ����" RED " %9s / %-9s"
                                      RED "����    ľ��" RED " %9s / %s\n"
                                      RED "��ˮ �� ����" RED " %9s / %-9s"
                                      RED "����    ˮ��" RED " %9s / %s\n"
                                      RED "���� �� ����" RED " %9s / %-9s"
                                      RED "����    ��" RED " %9s / %s\n"
                                      RED "���� �� ����" RED " %9s / %-9s"
                                      RED "����    ����" RED " %9s / %s\n\n",
                                      ob->query_skillmix_buff("add_poison")+"%","100%",ob->query_skillmix_buff("reduce_poison")+"%","100%",
                                      ob->query_skillmix_buff("add_magic")+"%","100%",ob->query_skillmix_buff("reduce_magic")+"%","100%",
                                      ob->query_skillmix_buff("add_metal")+"%","100%",ob->query_skillmix_buff("reduce_metal")+"%","100%",
                                      ob->query_skillmix_buff("add_wood")+"%","100%",ob->query_skillmix_buff("reduce_wood")+"%","100%",
                                      ob->query_skillmix_buff("add_water")+"%","100%",ob->query_skillmix_buff("reduce_water")+"%","100%",
                                      ob->query_skillmix_buff("add_fire")+"%","100%",ob->query_skillmix_buff("reduce_fire")+"%","100%",
                                      ob->query_skillmix_buff("add_earth")+"%","100%",ob->query_skillmix_buff("reduce_earth")+"%","100%");
                        sp += HIC "��" HIY "������������������������������������������������������������������������" HIC "��\n" NOR;
                        sp += HIC "��" HIY "����������������������������--==״̬�ָ�==--����������������������������" HIC "��\n\n" NOR;              
                        sp += sprintf(HIB "��͵ȡ������" HIB " %9s / %-9s"
                                      HIB "��͵ȡ������" HIB " %9s / %s\n\n",
                                      ob->query_skillmix_buff("leech_neili")+"%","90%",
                                      ob->query_skillmix_buff("leech_qi")+"%","90%");
                        sp += HIC "��" HIY "������������������������������������������������������������������������" HIC "��\n" NOR;
                        sp += HIC "��" HIY "����������������������������--==ս���ӳ�==--����������������������������" HIC "��\n\n" NOR;
                        sp += sprintf(WHT "�������ȼ���" HIW " %9d / %-9d" NOR
                                      WHT "�������ȼ���" HIW " %9d / %d\n" NOR
                                      WHT "�������ȼ���" HIW " %9d / %-9d" NOR
                                      WHT "���мܵȼ���" HIW " %9d / %d\n" NOR
                                      WHT "���������С�" HIW " %9s / %-9s" NOR
                                      WHT "�����з�����" HIW " %9s / %s\n" NOR
                                      WHT "�������˺���" HIG " %9d / %-9d" NOR
                                      WHT "�������˺���" HIG " %9d / %d\n" NOR
                                      WHT "�������˺���" HIG " %9s / %-9s" NOR
                                      WHT "��ս��������" HIG " %9d / %d\n" NOR
                                      /*
                                      WHT "�������˺���" HIG " %9d / %-9d" NOR
                                      WHT "�����ӱ�����" HIG " %9d / %d\n" NOR
                                      WHT "�������˺���" HIG " %9d / %-9d" NOR
                                      WHT "�����챣����" HIG " %9d / %d\n" NOR
                                      */
                                      WHT "�������мܡ�" HIY " %9s / %-9s" NOR
                                      WHT "�����Ӷ�����" HIY " %9s / %s\n" NOR
                                      WHT "�������ع���" HIY " %9s / %-9s" NOR
                                      WHT "�������ڷ���" HIY " %9s / %s\n\n" NOR,
                                      ob->query_skillmix_buff("attack"),9000,
                                      ob->query_skillmix_buff("defense"),9000,
                                      ob->query_skillmix_buff("dodge"),9000,
                                      ob->query_skillmix_buff("parry"),9000,
                                      ob->query_skillmix_buff("ap_power")+"%","120%",
                                      ob->query_skillmix_buff("dp_power")+"%","120%",
                                      ob->query_skillmix_buff("damage"),200000,
                                      ob->query_skillmix_buff("unarmed_damage"),200000,
                                      ob->query_skillmix_buff("da_power")+"%","120%",
                                      ob->query_skillmix_buff("armor"),200000,
                                      //query_temp("apply/damage1", ob),200000,query_temp("apply/armor1", ob),200000,
                                      //query_temp("apply/damage2", ob),200000,query_temp("apply/armor2", ob),200000,
                                      ob->query_skillmix_buff("avoid_parry")+"%","90%",
                                      ob->query_skillmix_buff("avoid_dodge")+"%","90%",
                                      ob->query_skillmix_buff("avoid_attack")+"%","90%",
                                      ob->query_skillmix_buff("avoid_force")+"%","90%");                      
                        sp += HIC "��" HIY "������������������������������������������������������������������������" HIC "��\n" NOR;
                        sp += HIC "��" HIY "����������������������������--==�߼�����==--����������������������������" HIC "��\n\n" NOR;        
                        sp += sprintf(HIW "������æ�ҡ�" HIM " %9d / %-9d"
                                      HIW "��Ѱ �� �ʡ�" HIM " %9s / %s\n"
                                      HIW "��˫���˺���" CYN " %9s / %-9s"
                                      HIW "����ת������" CYN " %9s / %s\n"  
                                      HIW "����    ä��" CYN " %9s / %-9s"
                                      HIW "��������ä��" CYN " %9s / %s\n"
                                      HIW "����͸�Ƽס�" CYN " %9s / %-9s"
                                      HIW "���ٶ����֡�" CYN " %9s / %s\n"
                                      HIW "��ս���塿" CYN " %9s / %-9s\n\n",
                                      ob->query_skillmix_buff("reduce_busy"),90,
                                      ob->query_skillmix_buff("magic_find")+"%","300%",
                                      ob->query_skillmix_buff("double_damage")+"%","200%",
                                      ob->query_skillmix_buff("qi_abs_neili")+"%","90%",
                                      ob->query_skillmix_buff("add_blind")+"%","90%",
                                      ob->query_skillmix_buff("avoid_blind")+"%","90%",
                                      ob->query_skillmix_buff("through_armor")+"%","90%",
                                      ob->query_skillmix_buff("avoid_poison")+"%","100%",
                                      ob->query_skillmix_buff("full_self")+"%","90%");
                      
                        sp += HIC "��" HIY "������������������������������������������������������������������������" HIC "��\n" NOR;
                        sp += HIC "��" HIY "����������������������������--==�ռ�����==--����������������������������" HIC "��\n\n" NOR;         
                        sp += sprintf(HIY "����    ����" HIM " %9s / %-9s"
                                      HIY "�����ӱ�����" HIM " %9s / %s\n"
                                      /*
                                      HIY "��ѣ    �Ρ�" HIM " %9s / %-9s"
                                      HIY "������ѣ�Ρ�" HIM " %9s / %s\n"
                                      */
                                      HIY "����    ����" HIM " %9s / %-9s"
                                      HIY "������������" HIM " %9s / %s\n"
                                      HIY "��æ    �ҡ�" HIM " %9d / %-9d"
                                      HIY "������æ�ҡ�" HIM " %9s / %s\n"
                                      HIY "����    ����" HIM " %9s / %-9s"
                                      HIY "������������" HIM " %9s / %s\n"
                                      HIY "��׷���˺���" HIM " %9s / %-9s"
                                      HIY "�������˺���" HIM " %9s / %s\n"
                                      HIY "���˺����ɡ�" HIM " %9s / %-9s"
                                      HIY "��ԡѪ������" HIM " %9s / %s\n"                      
                                      HIY "������һ����" HIM " %9s / %-9s"
                                      HIY "���������ܡ�" HIM " %9d / %d\n\n",
                                      ob->query_skillmix_buff("add_freeze")+"%","90%",ob->query_skillmix_buff("avoid_freeze")+"%","90%",
                                      /*
                                      ob->query_skillmix_buff("add_dizziness")+"%","90%",ob->query_skillmix_buff("avoid_dizziness")+"%","90%",                    ;:207c
                                      */
                                      ob->query_skillmix_buff("add_forget")+"%","90%",ob->query_skillmix_buff("avoid_forget")+"%","90%",
                                      ob->query_skillmix_buff("add_busy"),90,ob->query_skillmix_buff("avoid_busy")+"%","90%",
                                      ob->query_skillmix_buff("add_weak")+"%","90%",ob->query_skillmix_buff("avoid_weak")+"%","90%",
                                      ob->query_skillmix_buff("add_damage")+"%","200%",
                                      ob->query_skillmix_buff("reduce_damage")+"%","90%",
                                      ob->query_skillmix_buff("counter_damage")+"%","90%",ob->query_skillmix_buff("avoid_die")+"%","90%",
                                      ob->query_skillmix_buff("fatal_blow")+"%","90%",ob->query_skillmix_buff("add_skill"),1200);

                        //sp += HIC "��" HIY "������������������������������������������������������������������������" HIC "��\n" NOR;
                        sp += HIC "��" HIY "����������������������������--==���߹���==--����������������������������" HIC "��\n\n" NOR;
                        sp += sprintf(HIG + (ob == me ? "��" : ob->name()) + HIG "��%s���Ѿ������� " NOR + HIC "%s\n" NOR,
                                      LOCAL_MUD_NAME(), time_period(query("online_time", ob)));

                        if( MEMBER_D->is_valid_member(ob) )
                                sp += sprintf(HIG + (ob == me ? "��" : ob->name()) + HIG "��������������ʱ�仹�� " NOR + HIY "������\n" NOR);
                        else
                        {
                                if( query("online_time", ob)/3<query("offline_time", ob) )
                                        set("offline_time",query("online_time",  ob)/3, ob);
                                sp += sprintf(HIG + (ob == me ? "��" : ob->name()) + HIG "��������������ʱ�仹�� " NOR + HIY "%s\n" NOR,
                                              time_period(query("online_time", ob)/3-query("offline_time", ob)));
                        }

                        sp += sprintf(HIG + (ob == me ? "��" : ob->name()) + HIG "�����˫������ʱ�仹�� " NOR + HIW "%s\n" NOR,
                                      time_period(query("time_reward/quest", ob)));
                        sp += sprintf(HIG + (ob == me ? "��" : ob->name()) + HIG "����ĸ�Ч����ʱ�仹�� " NOR + HIM "%s\n" NOR,
                                      time_period(query("time_reward/study", ob)));


                        me->start_more(sp);
                        return 1;
        }

        if( arg && (arg == "-ability"
        ||  sscanf(arg, "-ability %s", arg)
        ||  sscanf(arg, "%s -ability", arg)) )
        {
                if( arg == "-ability" )
                        ob = me;
                else
                if( wizardp(me) || query("couple/child_id", me) )
                {
                        ob = present(arg, environment(me));

                        if (! ob || ! ob->is_character())
                                ob = find_player(arg);

                        if (! ob || ! ob->is_character())
                                ob = find_living(arg);

                        if (! ob || ! ob->is_character() || ! me->visible(ob))
                                return notify_fail("��Ҫ�쿴˭��״̬��\n");

                        if( !wizardp(me) && query("couple/child_id", me) != query("id", ob) )
                                return notify_fail("��Ҫ�쿴˭��״̬��\n");

                } else
                        return notify_fail("ֻ����ʦ�ܲ쿴���˵�״̬��\n");
                
                        sp = HIM + (ob == me ? "��" : ob->name(1)) + "Ŀǰ���������׸�������Ч��һ��\n" NOR;
                        //sp += HIC "��" HIY "������������������������������������������������������������������������" HIC "��\n" NOR;
                        sp += HIC "��" HIY "����������������������������--==�츳�ӳ�==--����������������������������" HIC "��\n\n" NOR;

                        sp += sprintf(HIC "���������ӡ�" HIG " %9d / %-9d"
                                      HIC "�����Ը��ӡ�" HIG " %9d / %d\n"
                                      HIC "�����Ǹ��ӡ�" HIG " %9d / %-9d"
                                      HIC "�������ӡ�" HIG " %9d / %d\n\n",
                                      ob->query_ability_buff("str"),2000,
                                      ob->query_ability_buff("int"),2000,
                                      ob->query_ability_buff("con"),2000,
                                      ob->query_ability_buff("dex"),2000);
                        sp += HIC "��" HIY "������������������������������������������������������������������������" HIC "��\n" NOR;
                        sp += HIC "��" HIY "����������������������������--==���޼ӳ�==--����������������������������" HIC "��\n\n" NOR;
                        sp += sprintf(HIC "��Ǳ�����ޡ�" HIM " %9d / %-9d"
                                      HIC "��������ޡ�" HIM " %9d / %d\n"
                                      HIC "���������ޡ�" HIM " %9d / %-9d"
                                      HIC "���������ޡ�" HIM " %9d / %d\n"
                                      HIC "����Ѫ���ޡ�" HIM " %9d / %-9d"
                                      HIC "���������ޡ�" HIM " %9d / %d\n\n",
                                      ob->query_ability_buff("max_potential"),10000000,
                                      ob->query_ability_buff("max_experience"),10000000,
                                      ob->query_ability_buff("max_neili"),2000000,
                                      ob->query_ability_buff("max_jingli"),1000000,
                                      ob->query_ability_buff("max_qi"),2000000,
                                      ob->query_ability_buff("max_jing"),1000000);        
                        sp += HIC "��" HIY "������������������������������������������������������������������������" HIC "��\n" NOR;
                        sp += HIC "��" HIY "����������������������������--==�����ӳ�==--����������������������������" HIC "��\n\n" NOR;
                        sp += sprintf(HIC "���о�������" HIY " %9d / %-9d"
                                      HIC "���о�Ч����" HIY " %9s / %s\n"
                                      HIC "����ϰ������" HIY " %9d / %-9d"
                                      HIC "����ϰЧ����" HIY " %9s / %s\n"
                                      HIC "��ѧϰ������" HIY " %9d / %-9d"
                                      HIC "��ѧϰЧ����" HIY " %9s / %s\n"
                                      HIC "����ȡ���ġ�" HIY " %9d / %-9d"
                                      HIC "����ȡЧ����" HIY " %9s / %s\n\n",
                                      ob->query_ability_buff("research_times"),2000,
                                      ob->query_ability_buff("research_effect")+"%","2000%",
                                      ob->query_ability_buff("practice_times"),2000,
                                      ob->query_ability_buff("practice_effect")+"%","2000%",
                                      ob->query_ability_buff("learn_times"),2000,
                                      ob->query_ability_buff("learn_effect")+"%","2000%",
                                      ob->query_ability_buff("derive_times"),2000,
                                      ob->query_ability_buff("derive_effect")+"%","2000%");
                        sp += HIC "��" HIY "������������������������������������������������������������������������" HIC "��\n" NOR;
                        sp += HIC "��" HIY "����������������������������--==���мӳ�==--����������������������������" HIC "��\n\n" NOR;
                        sp += sprintf(RED "���� �� ����" RED " %9s / %-9s"
                                      RED "����    ����" RED " %9s / %s\n"
                                      RED "��ħ �� ����" RED " %9s / %-9s"
                                      RED "����    ħ��" RED " %9s / %s\n"
                                      RED "���� �� ����" RED " %9s / %-9s"
                                      RED "����    ��" RED " %9s / %s\n"
                                      RED "��ľ �� ����" RED " %9s / %-9s"
                                      RED "����    ľ��" RED " %9s / %s\n"
                                      RED "��ˮ �� ����" RED " %9s / %-9s"
                                      RED "����    ˮ��" RED " %9s / %s\n"
                                      RED "���� �� ����" RED " %9s / %-9s"
                                      RED "����    ��" RED " %9s / %s\n"
                                      RED "���� �� ����" RED " %9s / %-9s"
                                      RED "����    ����" RED " %9s / %s\n\n",
                                      ob->query_ability_buff("add_poison")+"%","100%",ob->query_ability_buff("reduce_poison")+"%","100%",
                                      ob->query_ability_buff("add_magic")+"%","100%",ob->query_ability_buff("reduce_magic")+"%","100%",
                                      ob->query_ability_buff("add_metal")+"%","100%",ob->query_ability_buff("reduce_metal")+"%","100%",
                                      ob->query_ability_buff("add_wood")+"%","100%",ob->query_ability_buff("reduce_wood")+"%","100%",
                                      ob->query_ability_buff("add_water")+"%","100%",ob->query_ability_buff("reduce_water")+"%","100%",
                                      ob->query_ability_buff("add_fire")+"%","100%",ob->query_ability_buff("reduce_fire")+"%","100%",
                                      ob->query_ability_buff("add_earth")+"%","100%",ob->query_ability_buff("reduce_earth")+"%","100%");
                        sp += HIC "��" HIY "������������������������������������������������������������������������" HIC "��\n" NOR;
                        sp += HIC "��" HIY "����������������������������--==״̬�ָ�==--����������������������������" HIC "��\n\n" NOR;              
                        sp += sprintf(HIB "��͵ȡ������" HIB " %9s / %-9s"
                                      HIB "��͵ȡ������" HIB " %9s / %s\n\n",
                                      ob->query_ability_buff("leech_neili")+"%","90%",
                                      ob->query_ability_buff("leech_qi")+"%","90%");
                        sp += HIC "��" HIY "������������������������������������������������������������������������" HIC "��\n" NOR;
                        sp += HIC "��" HIY "����������������������������--==ս���ӳ�==--����������������������������" HIC "��\n\n" NOR;
                        sp += sprintf(WHT "�������ȼ���" HIW " %9d / %-9d" NOR
                                      WHT "�������ȼ���" HIW " %9d / %d\n" NOR
                                      WHT "�������ȼ���" HIW " %9d / %-9d" NOR
                                      WHT "���мܵȼ���" HIW " %9d / %d\n" NOR
                                      WHT "���������С�" HIW " %9s / %-9s" NOR
                                      WHT "�����з�����" HIW " %9s / %s\n" NOR
                                      WHT "�������˺���" HIG " %9d / %-9d" NOR
                                      WHT "�������˺���" HIG " %9d / %d\n" NOR
                                      WHT "�������˺���" HIG " %9s / %-9s" NOR
                                      WHT "��ս��������" HIG " %9d / %d\n" NOR
                                      /*
                                      WHT "�������˺���" HIG " %9d / %-9d" NOR
                                      WHT "�����ӱ�����" HIG " %9d / %d\n" NOR
                                      WHT "�������˺���" HIG " %9d / %-9d" NOR
                                      WHT "�����챣����" HIG " %9d / %d\n" NOR
                                      */
                                      WHT "�������мܡ�" HIY " %9s / %-9s" NOR
                                      WHT "�����Ӷ�����" HIY " %9s / %s\n" NOR
                                      WHT "�������ع���" HIY " %9s / %-9s" NOR
                                      WHT "�������ڷ���" HIY " %9s / %s\n\n" NOR,
                                      ob->query_ability_buff("attack"),9000,
                                      ob->query_ability_buff("defense"),9000,
                                      ob->query_ability_buff("dodge"),9000,
                                      ob->query_ability_buff("parry"),9000,
                                      ob->query_ability_buff("ap_power")+"%","120%",
                                      ob->query_ability_buff("dp_power")+"%","120%",
                                      ob->query_ability_buff("damage"),200000,
                                      ob->query_ability_buff("unarmed_damage"),200000,
                                      ob->query_ability_buff("da_power")+"%","120%",
                                      ob->query_ability_buff("armor"),200000,
                                      //query_temp("apply/damage1", ob),200000,query_temp("apply/armor1", ob),200000,
                                      //query_temp("apply/damage2", ob),200000,query_temp("apply/armor2", ob),200000,
                                      ob->query_ability_buff("avoid_parry")+"%","90%",
                                      ob->query_ability_buff("avoid_dodge")+"%","90%",
                                      ob->query_ability_buff("avoid_attack")+"%","90%",
                                      ob->query_ability_buff("avoid_force")+"%","90%");                      
                        sp += HIC "��" HIY "������������������������������������������������������������������������" HIC "��\n" NOR;
                        sp += HIC "��" HIY "����������������������������--==�߼�����==--����������������������������" HIC "��\n\n" NOR;        
                        sp += sprintf(HIW "������æ�ҡ�" HIM " %9d / %-9d"
                                      HIW "��Ѱ �� �ʡ�" HIM " %9s / %s\n"
                                      HIW "��˫���˺���" CYN " %9s / %-9s"
                                      HIW "����ת������" CYN " %9s / %s\n"  
                                      HIW "����    ä��" CYN " %9s / %-9s"
                                      HIW "��������ä��" CYN " %9s / %s\n"
                                      HIW "����͸�Ƽס�" CYN " %9s / %-9s"
                                      HIW "���ٶ����֡�" CYN " %9s / %s\n"
                                      HIW "��ս���塿" CYN " %9s / %-9s\n\n",
                                      ob->query_ability_buff("reduce_busy"),90,
                                      ob->query_ability_buff("magic_find")+"%","300%",
                                      ob->query_ability_buff("double_damage")+"%","200%",
                                      ob->query_ability_buff("qi_abs_neili")+"%","90%",
                                      ob->query_ability_buff("add_blind")+"%","90%",
                                      ob->query_ability_buff("avoid_blind")+"%","90%",
                                      ob->query_ability_buff("through_armor")+"%","90%",
                                      ob->query_ability_buff("avoid_poison")+"%","100%",
                                      ob->query_ability_buff("full_self")+"%","90%");
                      
                        sp += HIC "��" HIY "������������������������������������������������������������������������" HIC "��\n" NOR;
                        sp += HIC "��" HIY "����������������������������--==�ռ�����==--����������������������������" HIC "��\n\n" NOR;         
                        sp += sprintf(HIY "����    ����" HIM " %9s / %-9s"
                                      HIY "�����ӱ�����" HIM " %9s / %s\n"
                                      /*
                                      HIY "��ѣ    �Ρ�" HIM " %9s / %-9s"
                                      HIY "������ѣ�Ρ�" HIM " %9s / %s\n"
                                      */
                                      HIY "����    ����" HIM " %9s / %-9s"
                                      HIY "������������" HIM " %9s / %s\n"
                                      HIY "��æ    �ҡ�" HIM " %9d / %-9d"
                                      HIY "������æ�ҡ�" HIM " %9s / %s\n"
                                      HIY "����    ����" HIM " %9s / %-9s"
                                      HIY "������������" HIM " %9s / %s\n"
                                      HIY "��׷���˺���" HIM " %9s / %-9s"
                                      HIY "�������˺���" HIM " %9s / %s\n"
                                      HIY "���˺����ɡ�" HIM " %9s / %-9s"
                                      HIY "��ԡѪ������" HIM " %9s / %s\n"                      
                                      HIY "������һ����" HIM " %9s / %-9s"
                                      HIY "���������ܡ�" HIM " %9d / %d\n\n",
                                      ob->query_ability_buff("add_freeze")+"%","90%",ob->query_ability_buff("avoid_freeze")+"%","90%",
                                      /*
                                      ob->query_ability_buff("add_dizziness")+"%","90%",ob->query_ability_buff("avoid_dizziness")+"%","90%",                    ;:207c
                                      */
                                      ob->query_ability_buff("add_forget")+"%","90%",ob->query_ability_buff("avoid_forget")+"%","90%",
                                      ob->query_ability_buff("add_busy"),90,ob->query_ability_buff("avoid_busy")+"%","90%",
                                      ob->query_ability_buff("add_weak")+"%","90%",ob->query_ability_buff("avoid_weak")+"%","90%",
                                      ob->query_ability_buff("add_damage")+"%","200%",
                                      ob->query_ability_buff("reduce_damage")+"%","90%",
                                      ob->query_ability_buff("counter_damage")+"%","90%",ob->query_ability_buff("avoid_die")+"%","90%",
                                      ob->query_ability_buff("fatal_blow")+"%","90%",ob->query_ability_buff("add_skill"),1200);

                        //sp += HIC "��" HIY "������������������������������������������������������������������������" HIC "��\n" NOR;
                        sp += HIC "��" HIY "����������������������������--==���߹���==--����������������������������" HIC "��\n\n" NOR;
                        sp += sprintf(HIG + (ob == me ? "��" : ob->name()) + HIG "��%s���Ѿ������� " NOR + HIC "%s\n" NOR,
                                      LOCAL_MUD_NAME(), time_period(query("online_time", ob)));

                        if( MEMBER_D->is_valid_member(ob) )
                                sp += sprintf(HIG + (ob == me ? "��" : ob->name()) + HIG "��������������ʱ�仹�� " NOR + HIY "������\n" NOR);
                        else
                        {
                                if( query("online_time", ob)/3<query("offline_time", ob) )
                                        set("offline_time",query("online_time",  ob)/3, ob);
                                sp += sprintf(HIG + (ob == me ? "��" : ob->name()) + HIG "��������������ʱ�仹�� " NOR + HIY "%s\n" NOR,
                                              time_period(query("online_time", ob)/3-query("offline_time", ob)));
                        }

                        sp += sprintf(HIG + (ob == me ? "��" : ob->name()) + HIG "�����˫������ʱ�仹�� " NOR + HIW "%s\n" NOR,
                                      time_period(query("time_reward/quest", ob)));
                        sp += sprintf(HIG + (ob == me ? "��" : ob->name()) + HIG "����ĸ�Ч����ʱ�仹�� " NOR + HIM "%s\n" NOR,
                                      time_period(query("time_reward/study", ob)));


                        me->start_more(sp);
                        return 1;
        }

        if( arg && (arg == "-equipment"
        ||  sscanf(arg, "-equipment %s", arg)
        ||  sscanf(arg, "%s -equipment", arg)) )
        {
                if( arg == "-equipment" )
                        ob = me;
                else
                if( wizardp(me) || query("couple/child_id", me) )
                {
                        ob = present(arg, environment(me));

                        if (! ob || ! ob->is_character())
                                ob = find_player(arg);

                        if (! ob || ! ob->is_character())
                                ob = find_living(arg);

                        if (! ob || ! ob->is_character() || ! me->visible(ob))
                                return notify_fail("��Ҫ�쿴˭��״̬��\n");

                        if( !wizardp(me) && query("couple/child_id", me) != query("id", ob) )
                                return notify_fail("��Ҫ�쿴˭��״̬��\n");

                } else
                        return notify_fail("ֻ����ʦ�ܲ쿴���˵�״̬��\n");
                
                        sp = HIM + (ob == me ? "��" : ob->name(1)) + "Ŀǰ���������׸�������Ч��һ��\n" NOR;
                        //sp += HIC "��" HIY "������������������������������������������������������������������������" HIC "��\n" NOR;
                        sp += HIC "��" HIY "����������������������������--==�츳�ӳ�==--����������������������������" HIC "��\n\n" NOR;

                        sp += sprintf(HIC "���������ӡ�" HIG " %9d / %-9d"
                                      HIC "�����Ը��ӡ�" HIG " %9d / %d\n"
                                      HIC "�����Ǹ��ӡ�" HIG " %9d / %-9d"
                                      HIC "�������ӡ�" HIG " %9d / %d\n\n",
                                      ob->query_equipment_buff("str"),2000,
                                      ob->query_equipment_buff("int"),2000,
                                      ob->query_equipment_buff("con"),2000,
                                      ob->query_equipment_buff("dex"),2000);
                        sp += HIC "��" HIY "������������������������������������������������������������������������" HIC "��\n" NOR;
                        sp += HIC "��" HIY "����������������������������--==���޼ӳ�==--����������������������������" HIC "��\n\n" NOR;
                        sp += sprintf(HIC "��Ǳ�����ޡ�" HIM " %9d / %-9d"
                                      HIC "��������ޡ�" HIM " %9d / %d\n"
                                      HIC "���������ޡ�" HIM " %9d / %-9d"
                                      HIC "���������ޡ�" HIM " %9d / %d\n"
                                      HIC "����Ѫ���ޡ�" HIM " %9d / %-9d"
                                      HIC "���������ޡ�" HIM " %9d / %d\n\n",
                                      ob->query_equipment_buff("max_potential"),10000000,
                                      ob->query_equipment_buff("max_experience"),10000000,
                                      ob->query_equipment_buff("max_neili"),2000000,
                                      ob->query_equipment_buff("max_jingli"),1000000,
                                      ob->query_equipment_buff("max_qi"),2000000,
                                      ob->query_equipment_buff("max_jing"),1000000);        
                        sp += HIC "��" HIY "������������������������������������������������������������������������" HIC "��\n" NOR;
                        sp += HIC "��" HIY "����������������������������--==�����ӳ�==--����������������������������" HIC "��\n\n" NOR;
                        sp += sprintf(HIC "���о�������" HIY " %9d / %-9d"
                                      HIC "���о�Ч����" HIY " %9s / %s\n"
                                      HIC "����ϰ������" HIY " %9d / %-9d"
                                      HIC "����ϰЧ����" HIY " %9s / %s\n"
                                      HIC "��ѧϰ������" HIY " %9d / %-9d"
                                      HIC "��ѧϰЧ����" HIY " %9s / %s\n"
                                      HIC "����ȡ���ġ�" HIY " %9d / %-9d"
                                      HIC "����ȡЧ����" HIY " %9s / %s\n\n",
                                      ob->query_equipment_buff("research_times"),2000,
                                      ob->query_equipment_buff("research_effect")+"%","2000%",
                                      ob->query_equipment_buff("practice_times"),2000,
                                      ob->query_equipment_buff("practice_effect")+"%","2000%",
                                      ob->query_equipment_buff("learn_times"),2000,
                                      ob->query_equipment_buff("learn_effect")+"%","2000%",
                                      ob->query_equipment_buff("derive_times"),2000,
                                      ob->query_equipment_buff("derive_effect")+"%","2000%");
                        sp += HIC "��" HIY "������������������������������������������������������������������������" HIC "��\n" NOR;
                        sp += HIC "��" HIY "����������������������������--==���мӳ�==--����������������������������" HIC "��\n\n" NOR;
                        sp += sprintf(RED "���� �� ����" RED " %9s / %-9s"
                                      RED "����    ����" RED " %9s / %s\n"
                                      RED "��ħ �� ����" RED " %9s / %-9s"
                                      RED "����    ħ��" RED " %9s / %s\n"
                                      RED "���� �� ����" RED " %9s / %-9s"
                                      RED "����    ��" RED " %9s / %s\n"
                                      RED "��ľ �� ����" RED " %9s / %-9s"
                                      RED "����    ľ��" RED " %9s / %s\n"
                                      RED "��ˮ �� ����" RED " %9s / %-9s"
                                      RED "����    ˮ��" RED " %9s / %s\n"
                                      RED "���� �� ����" RED " %9s / %-9s"
                                      RED "����    ��" RED " %9s / %s\n"
                                      RED "���� �� ����" RED " %9s / %-9s"
                                      RED "����    ����" RED " %9s / %s\n\n",
                                      ob->query_equipment_buff("add_poison")+"%","100%",ob->query_equipment_buff("reduce_poison")+"%","100%",
                                      ob->query_equipment_buff("add_magic")+"%","100%",ob->query_equipment_buff("reduce_magic")+"%","100%",
                                      ob->query_equipment_buff("add_metal")+"%","100%",ob->query_equipment_buff("reduce_metal")+"%","100%",
                                      ob->query_equipment_buff("add_wood")+"%","100%",ob->query_equipment_buff("reduce_wood")+"%","100%",
                                      ob->query_equipment_buff("add_water")+"%","100%",ob->query_equipment_buff("reduce_water")+"%","100%",
                                      ob->query_equipment_buff("add_fire")+"%","100%",ob->query_equipment_buff("reduce_fire")+"%","100%",
                                      ob->query_equipment_buff("add_earth")+"%","100%",ob->query_equipment_buff("reduce_earth")+"%","100%");
                        sp += HIC "��" HIY "������������������������������������������������������������������������" HIC "��\n" NOR;
                        sp += HIC "��" HIY "����������������������������--==״̬�ָ�==--����������������������������" HIC "��\n\n" NOR;              
                        sp += sprintf(HIB "��͵ȡ������" HIB " %9s / %-9s"
                                      HIB "��͵ȡ������" HIB " %9s / %s\n\n",
                                      ob->query_equipment_buff("leech_neili")+"%","90%",
                                      ob->query_equipment_buff("leech_qi")+"%","90%");
                        sp += HIC "��" HIY "������������������������������������������������������������������������" HIC "��\n" NOR;
                        sp += HIC "��" HIY "����������������������������--==ս���ӳ�==--����������������������������" HIC "��\n\n" NOR;
                        sp += sprintf(WHT "�������ȼ���" HIW " %9d / %-9d" NOR
                                      WHT "�������ȼ���" HIW " %9d / %d\n" NOR
                                      WHT "�������ȼ���" HIW " %9d / %-9d" NOR
                                      WHT "���мܵȼ���" HIW " %9d / %d\n" NOR
                                      WHT "���������С�" HIW " %9s / %-9s" NOR
                                      WHT "�����з�����" HIW " %9s / %s\n" NOR
                                      WHT "�������˺���" HIG " %9d / %-9d" NOR
                                      WHT "�������˺���" HIG " %9d / %d\n" NOR
                                      WHT "�������˺���" HIG " %9s / %-9s" NOR
                                      WHT "��ս��������" HIG " %9d / %d\n" NOR
                                      /*
                                      WHT "�������˺���" HIG " %9d / %-9d" NOR
                                      WHT "�����ӱ�����" HIG " %9d / %d\n" NOR
                                      WHT "�������˺���" HIG " %9d / %-9d" NOR
                                      WHT "�����챣����" HIG " %9d / %d\n" NOR
                                      */
                                      WHT "�������мܡ�" HIY " %9s / %-9s" NOR
                                      WHT "�����Ӷ�����" HIY " %9s / %s\n" NOR
                                      WHT "�������ع���" HIY " %9s / %-9s" NOR
                                      WHT "�������ڷ���" HIY " %9s / %s\n\n" NOR,
                                      ob->query_equipment_buff("attack"),9000,
                                      ob->query_equipment_buff("defense"),9000,
                                      ob->query_equipment_buff("dodge"),9000,
                                      ob->query_equipment_buff("parry"),9000,
                                      ob->query_equipment_buff("ap_power")+"%","120%",
                                      ob->query_equipment_buff("dp_power")+"%","120%",
                                      ob->query_equipment_buff("damage"),200000,
                                      ob->query_equipment_buff("unarmed_damage"),200000,
                                      ob->query_equipment_buff("da_power")+"%","120%",
                                      ob->query_equipment_buff("armor"),200000,
                                      //query_temp("apply/damage1", ob),200000,query_temp("apply/armor1", ob),200000,
                                      //query_temp("apply/damage2", ob),200000,query_temp("apply/armor2", ob),200000,
                                      ob->query_equipment_buff("avoid_parry")+"%","90%",
                                      ob->query_equipment_buff("avoid_dodge")+"%","90%",
                                      ob->query_equipment_buff("avoid_attack")+"%","90%",
                                      ob->query_equipment_buff("avoid_force")+"%","90%");                      
                        sp += HIC "��" HIY "������������������������������������������������������������������������" HIC "��\n" NOR;
                        sp += HIC "��" HIY "����������������������������--==�߼�����==--����������������������������" HIC "��\n\n" NOR;        
                        sp += sprintf(HIW "������æ�ҡ�" HIM " %9d / %-9d"
                                      HIW "��Ѱ �� �ʡ�" HIM " %9s / %s\n"
                                      HIW "��˫���˺���" CYN " %9s / %-9s"
                                      HIW "����ת������" CYN " %9s / %s\n"  
                                      HIW "����    ä��" CYN " %9s / %-9s"
                                      HIW "��������ä��" CYN " %9s / %s\n"
                                      HIW "����͸�Ƽס�" CYN " %9s / %-9s"
                                      HIW "���ٶ����֡�" CYN " %9s / %s\n"
                                      HIW "��ս���塿" CYN " %9s / %-9s\n\n",
                                      ob->query_equipment_buff("reduce_busy"),90,
                                      ob->query_equipment_buff("magic_find")+"%","300%",
                                      ob->query_equipment_buff("double_damage")+"%","200%",
                                      ob->query_equipment_buff("qi_abs_neili")+"%","90%",
                                      ob->query_equipment_buff("add_blind")+"%","90%",
                                      ob->query_equipment_buff("avoid_blind")+"%","90%",
                                      ob->query_equipment_buff("through_armor")+"%","90%",
                                      ob->query_equipment_buff("avoid_poison")+"%","100%",
                                      ob->query_equipment_buff("full_self")+"%","90%");
                      
                        sp += HIC "��" HIY "������������������������������������������������������������������������" HIC "��\n" NOR;
                        sp += HIC "��" HIY "����������������������������--==�ռ�����==--����������������������������" HIC "��\n\n" NOR;         
                        sp += sprintf(HIY "����    ����" HIM " %9s / %-9s"
                                      HIY "�����ӱ�����" HIM " %9s / %s\n"
                                      /*
                                      HIY "��ѣ    �Ρ�" HIM " %9s / %-9s"
                                      HIY "������ѣ�Ρ�" HIM " %9s / %s\n"
                                      */
                                      HIY "����    ����" HIM " %9s / %-9s"
                                      HIY "������������" HIM " %9s / %s\n"
                                      HIY "��æ    �ҡ�" HIM " %9d / %-9d"
                                      HIY "������æ�ҡ�" HIM " %9s / %s\n"
                                      HIY "����    ����" HIM " %9s / %-9s"
                                      HIY "������������" HIM " %9s / %s\n"
                                      HIY "��׷���˺���" HIM " %9s / %-9s"
                                      HIY "�������˺���" HIM " %9s / %s\n"
                                      HIY "���˺����ɡ�" HIM " %9s / %-9s"
                                      HIY "��ԡѪ������" HIM " %9s / %s\n"                      
                                      HIY "������һ����" HIM " %9s / %-9s"
                                      HIY "���������ܡ�" HIM " %9d / %d\n\n",
                                      ob->query_equipment_buff("add_freeze")+"%","90%",ob->query_equipment_buff("avoid_freeze")+"%","90%",
                                      /*
                                      ob->query_equipment_buff("add_dizziness")+"%","90%",ob->query_equipment_buff("avoid_dizziness")+"%","90%",                    ;:207c
                                      */
                                      ob->query_equipment_buff("add_forget")+"%","90%",ob->query_equipment_buff("avoid_forget")+"%","90%",
                                      ob->query_equipment_buff("add_busy"),90,ob->query_equipment_buff("avoid_busy")+"%","90%",
                                      ob->query_equipment_buff("add_weak")+"%","90%",ob->query_equipment_buff("avoid_weak")+"%","90%",
                                      ob->query_equipment_buff("add_damage")+"%","200%",
                                      ob->query_equipment_buff("reduce_damage")+"%","90%",
                                      ob->query_equipment_buff("counter_damage")+"%","90%",ob->query_equipment_buff("avoid_die")+"%","90%",
                                      ob->query_equipment_buff("fatal_blow")+"%","90%",ob->query_equipment_buff("add_skill"),1200);

                        //sp += HIC "��" HIY "������������������������������������������������������������������������" HIC "��\n" NOR;
                        sp += HIC "��" HIY "����������������������������--==���߹���==--����������������������������" HIC "��\n\n" NOR;
                        sp += sprintf(HIG + (ob == me ? "��" : ob->name()) + HIG "��%s���Ѿ������� " NOR + HIC "%s\n" NOR,
                                      LOCAL_MUD_NAME(), time_period(query("online_time", ob)));

                        if( MEMBER_D->is_valid_member(ob) )
                                sp += sprintf(HIG + (ob == me ? "��" : ob->name()) + HIG "��������������ʱ�仹�� " NOR + HIY "������\n" NOR);
                        else
                        {
                                if( query("online_time", ob)/3<query("offline_time", ob) )
                                        set("offline_time",query("online_time",  ob)/3, ob);
                                sp += sprintf(HIG + (ob == me ? "��" : ob->name()) + HIG "��������������ʱ�仹�� " NOR + HIY "%s\n" NOR,
                                              time_period(query("online_time", ob)/3-query("offline_time", ob)));
                        }

                        sp += sprintf(HIG + (ob == me ? "��" : ob->name()) + HIG "�����˫������ʱ�仹�� " NOR + HIW "%s\n" NOR,
                                      time_period(query("time_reward/quest", ob)));
                        sp += sprintf(HIG + (ob == me ? "��" : ob->name()) + HIG "����ĸ�Ч����ʱ�仹�� " NOR + HIM "%s\n" NOR,
                                      time_period(query("time_reward/study", ob)));


                        me->start_more(sp);
                        return 1;
        }

        if( arg && (arg == "-talent"
        ||  sscanf(arg, "-talent %s", arg)
        ||  sscanf(arg, "%s -talent", arg)) )
        {
                if( arg == "-talent" )
                        ob = me;
                else
                if( wizardp(me) || query("couple/child_id", me) )
                {
                        ob = present(arg, environment(me));

                        if (! ob || ! ob->is_character())
                                ob = find_player(arg);

                        if (! ob || ! ob->is_character())
                                ob = find_living(arg);

                        if (! ob || ! ob->is_character() || ! me->visible(ob))
                                return notify_fail("��Ҫ�쿴˭��״̬��\n");

                        if( !wizardp(me) && query("couple/child_id", me) != query("id", ob) )
                                return notify_fail("��Ҫ�쿴˭��״̬��\n");

                } else
                        return notify_fail("ֻ����ʦ�ܲ쿴���˵�״̬��\n");
                
                        sp = HIM + (ob == me ? "��" : ob->name(1)) + "Ŀǰ���������׸�������Ч��һ��\n" NOR;
                        //sp += HIC "��" HIY "������������������������������������������������������������������������" HIC "��\n" NOR;
                        sp += HIC "��" HIY "����������������������������--==�츳�ӳ�==--����������������������������" HIC "��\n\n" NOR;

                        sp += sprintf(HIC "���������ӡ�" HIG " %9d / %-9d"
                                      HIC "�����Ը��ӡ�" HIG " %9d / %d\n"
                                      HIC "�����Ǹ��ӡ�" HIG " %9d / %-9d"
                                      HIC "�������ӡ�" HIG " %9d / %d\n\n",
                                      ob->query_talent_buff("str"),2000,
                                      ob->query_talent_buff("int"),2000,
                                      ob->query_talent_buff("con"),2000,
                                      ob->query_talent_buff("dex"),2000);
                        sp += HIC "��" HIY "������������������������������������������������������������������������" HIC "��\n" NOR;
                        sp += HIC "��" HIY "����������������������������--==���޼ӳ�==--����������������������������" HIC "��\n\n" NOR;
                        sp += sprintf(HIC "��Ǳ�����ޡ�" HIM " %9d / %-9d"
                                      HIC "��������ޡ�" HIM " %9d / %d\n"
                                      HIC "���������ޡ�" HIM " %9d / %-9d"
                                      HIC "���������ޡ�" HIM " %9d / %d\n"
                                      HIC "����Ѫ���ޡ�" HIM " %9d / %-9d"
                                      HIC "���������ޡ�" HIM " %9d / %d\n\n",
                                      ob->query_talent_buff("max_potential"),10000000,
                                      ob->query_talent_buff("max_experience"),10000000,
                                      ob->query_talent_buff("max_neili"),2000000,
                                      ob->query_talent_buff("max_jingli"),1000000,
                                      ob->query_talent_buff("max_qi"),2000000,
                                      ob->query_talent_buff("max_jing"),1000000);        
                        sp += HIC "��" HIY "������������������������������������������������������������������������" HIC "��\n" NOR;
                        sp += HIC "��" HIY "����������������������������--==�����ӳ�==--����������������������������" HIC "��\n\n" NOR;
                        sp += sprintf(HIC "���о�������" HIY " %9d / %-9d"
                                      HIC "���о�Ч����" HIY " %9s / %s\n"
                                      HIC "����ϰ������" HIY " %9d / %-9d"
                                      HIC "����ϰЧ����" HIY " %9s / %s\n"
                                      HIC "��ѧϰ������" HIY " %9d / %-9d"
                                      HIC "��ѧϰЧ����" HIY " %9s / %s\n"
                                      HIC "����ȡ���ġ�" HIY " %9d / %-9d"
                                      HIC "����ȡЧ����" HIY " %9s / %s\n\n",
                                      ob->query_talent_buff("research_times"),2000,
                                      ob->query_talent_buff("research_effect")+"%","2000%",
                                      ob->query_talent_buff("practice_times"),2000,
                                      ob->query_talent_buff("practice_effect")+"%","2000%",
                                      ob->query_talent_buff("learn_times"),2000,
                                      ob->query_talent_buff("learn_effect")+"%","2000%",
                                      ob->query_talent_buff("derive_times"),2000,
                                      ob->query_talent_buff("derive_effect")+"%","2000%");
                        sp += HIC "��" HIY "������������������������������������������������������������������������" HIC "��\n" NOR;
                        sp += HIC "��" HIY "����������������������������--==���мӳ�==--����������������������������" HIC "��\n\n" NOR;
                        sp += sprintf(RED "���� �� ����" RED " %9s / %-9s"
                                      RED "����    ����" RED " %9s / %s\n"
                                      RED "��ħ �� ����" RED " %9s / %-9s"
                                      RED "����    ħ��" RED " %9s / %s\n"
                                      RED "���� �� ����" RED " %9s / %-9s"
                                      RED "����    ��" RED " %9s / %s\n"
                                      RED "��ľ �� ����" RED " %9s / %-9s"
                                      RED "����    ľ��" RED " %9s / %s\n"
                                      RED "��ˮ �� ����" RED " %9s / %-9s"
                                      RED "����    ˮ��" RED " %9s / %s\n"
                                      RED "���� �� ����" RED " %9s / %-9s"
                                      RED "����    ��" RED " %9s / %s\n"
                                      RED "���� �� ����" RED " %9s / %-9s"
                                      RED "����    ����" RED " %9s / %s\n\n",
                                      ob->query_talent_buff("add_poison")+"%","100%",ob->query_talent_buff("reduce_poison")+"%","100%",
                                      ob->query_talent_buff("add_magic")+"%","100%",ob->query_talent_buff("reduce_magic")+"%","100%",
                                      ob->query_talent_buff("add_metal")+"%","100%",ob->query_talent_buff("reduce_metal")+"%","100%",
                                      ob->query_talent_buff("add_wood")+"%","100%",ob->query_talent_buff("reduce_wood")+"%","100%",
                                      ob->query_talent_buff("add_water")+"%","100%",ob->query_talent_buff("reduce_water")+"%","100%",
                                      ob->query_talent_buff("add_fire")+"%","100%",ob->query_talent_buff("reduce_fire")+"%","100%",
                                      ob->query_talent_buff("add_earth")+"%","100%",ob->query_talent_buff("reduce_earth")+"%","100%");
                        sp += HIC "��" HIY "������������������������������������������������������������������������" HIC "��\n" NOR;
                        sp += HIC "��" HIY "����������������������������--==״̬�ָ�==--����������������������������" HIC "��\n\n" NOR;              
                        sp += sprintf(HIB "��͵ȡ������" HIB " %9s / %-9s"
                                      HIB "��͵ȡ������" HIB " %9s / %s\n\n",
                                      ob->query_talent_buff("leech_neili")+"%","90%",
                                      ob->query_talent_buff("leech_qi")+"%","90%");
                        sp += HIC "��" HIY "������������������������������������������������������������������������" HIC "��\n" NOR;
                        sp += HIC "��" HIY "����������������������������--==ս���ӳ�==--����������������������������" HIC "��\n\n" NOR;
                        sp += sprintf(WHT "�������ȼ���" HIW " %9d / %-9d" NOR
                                      WHT "�������ȼ���" HIW " %9d / %d\n" NOR
                                      WHT "�������ȼ���" HIW " %9d / %-9d" NOR
                                      WHT "���мܵȼ���" HIW " %9d / %d\n" NOR
                                      WHT "���������С�" HIW " %9s / %-9s" NOR
                                      WHT "�����з�����" HIW " %9s / %s\n" NOR
                                      WHT "�������˺���" HIG " %9d / %-9d" NOR
                                      WHT "�������˺���" HIG " %9d / %d\n" NOR
                                      WHT "�������˺���" HIG " %9s / %-9s" NOR
                                      WHT "��ս��������" HIG " %9d / %d\n" NOR
                                      /*
                                      WHT "�������˺���" HIG " %9d / %-9d" NOR
                                      WHT "�����ӱ�����" HIG " %9d / %d\n" NOR
                                      WHT "�������˺���" HIG " %9d / %-9d" NOR
                                      WHT "�����챣����" HIG " %9d / %d\n" NOR
                                      */
                                      WHT "�������мܡ�" HIY " %9s / %-9s" NOR
                                      WHT "�����Ӷ�����" HIY " %9s / %s\n" NOR
                                      WHT "�������ع���" HIY " %9s / %-9s" NOR
                                      WHT "�������ڷ���" HIY " %9s / %s\n\n" NOR,
                                      ob->query_talent_buff("attack"),9000,
                                      ob->query_talent_buff("defense"),9000,
                                      ob->query_talent_buff("dodge"),9000,
                                      ob->query_talent_buff("parry"),9000,
                                      ob->query_talent_buff("ap_power")+"%","120%",
                                      ob->query_talent_buff("dp_power")+"%","120%",
                                      ob->query_talent_buff("damage"),200000,
                                      ob->query_talent_buff("unarmed_damage"),200000,
                                      ob->query_talent_buff("da_power")+"%","120%",
                                      ob->query_talent_buff("armor"),200000,
                                      //query_temp("apply/damage1", ob),200000,query_temp("apply/armor1", ob),200000,
                                      //query_temp("apply/damage2", ob),200000,query_temp("apply/armor2", ob),200000,
                                      ob->query_talent_buff("avoid_parry")+"%","90%",
                                      ob->query_talent_buff("avoid_dodge")+"%","90%",
                                      ob->query_talent_buff("avoid_attack")+"%","90%",
                                      ob->query_talent_buff("avoid_force")+"%","90%");                      
                        sp += HIC "��" HIY "������������������������������������������������������������������������" HIC "��\n" NOR;
                        sp += HIC "��" HIY "����������������������������--==�߼�����==--����������������������������" HIC "��\n\n" NOR;        
                        sp += sprintf(HIW "������æ�ҡ�" HIM " %9d / %-9d"
                                      HIW "��Ѱ �� �ʡ�" HIM " %9s / %s\n"
                                      HIW "��˫���˺���" CYN " %9s / %-9s"
                                      HIW "����ת������" CYN " %9s / %s\n"  
                                      HIW "����    ä��" CYN " %9s / %-9s"
                                      HIW "��������ä��" CYN " %9s / %s\n"
                                      HIW "����͸�Ƽס�" CYN " %9s / %-9s"
                                      HIW "���ٶ����֡�" CYN " %9s / %s\n"
                                      HIW "��ս���塿" CYN " %9s / %-9s\n\n",
                                      ob->query_talent_buff("reduce_busy"),90,
                                      ob->query_talent_buff("magic_find")+"%","300%",
                                      ob->query_talent_buff("double_damage")+"%","200%",
                                      ob->query_talent_buff("qi_abs_neili")+"%","90%",
                                      ob->query_talent_buff("add_blind")+"%","90%",
                                      ob->query_talent_buff("avoid_blind")+"%","90%",
                                      ob->query_talent_buff("through_armor")+"%","90%",
                                      ob->query_talent_buff("avoid_poison")+"%","100%",
                                      ob->query_talent_buff("full_self")+"%","90%");
                      
                        sp += HIC "��" HIY "������������������������������������������������������������������������" HIC "��\n" NOR;
                        sp += HIC "��" HIY "����������������������������--==�ռ�����==--����������������������������" HIC "��\n\n" NOR;         
                        sp += sprintf(HIY "����    ����" HIM " %9s / %-9s"
                                      HIY "�����ӱ�����" HIM " %9s / %s\n"
                                      /*
                                      HIY "��ѣ    �Ρ�" HIM " %9s / %-9s"
                                      HIY "������ѣ�Ρ�" HIM " %9s / %s\n"
                                      */
                                      HIY "����    ����" HIM " %9s / %-9s"
                                      HIY "������������" HIM " %9s / %s\n"
                                      HIY "��æ    �ҡ�" HIM " %9d / %-9d"
                                      HIY "������æ�ҡ�" HIM " %9s / %s\n"
                                      HIY "����    ����" HIM " %9s / %-9s"
                                      HIY "������������" HIM " %9s / %s\n"
                                      HIY "��׷���˺���" HIM " %9s / %-9s"
                                      HIY "�������˺���" HIM " %9s / %s\n"
                                      HIY "���˺����ɡ�" HIM " %9s / %-9s"
                                      HIY "��ԡѪ������" HIM " %9s / %s\n"                      
                                      HIY "������һ����" HIM " %9s / %-9s"
                                      HIY "���������ܡ�" HIM " %9d / %d\n\n",
                                      ob->query_talent_buff("add_freeze")+"%","90%",ob->query_talent_buff("avoid_freeze")+"%","90%",
                                      /*
                                      ob->query_talent_buff("add_dizziness")+"%","90%",ob->query_talent_buff("avoid_dizziness")+"%","90%",                    ;:207c
                                      */
                                      ob->query_talent_buff("add_forget")+"%","90%",ob->query_talent_buff("avoid_forget")+"%","90%",
                                      ob->query_talent_buff("add_busy"),90,ob->query_talent_buff("avoid_busy")+"%","90%",
                                      ob->query_talent_buff("add_weak")+"%","90%",ob->query_talent_buff("avoid_weak")+"%","90%",
                                      ob->query_talent_buff("add_damage")+"%","200%",
                                      ob->query_talent_buff("reduce_damage")+"%","90%",
                                      ob->query_talent_buff("counter_damage")+"%","90%",ob->query_talent_buff("avoid_die")+"%","90%",
                                      ob->query_talent_buff("fatal_blow")+"%","90%",ob->query_talent_buff("add_skill"),1200);

                        //sp += HIC "��" HIY "������������������������������������������������������������������������" HIC "��\n" NOR;
                        sp += HIC "��" HIY "����������������������������--==���߹���==--����������������������������" HIC "��\n\n" NOR;
                        sp += sprintf(HIG + (ob == me ? "��" : ob->name()) + HIG "��%s���Ѿ������� " NOR + HIC "%s\n" NOR,
                                      LOCAL_MUD_NAME(), time_period(query("online_time", ob)));

                        if( MEMBER_D->is_valid_member(ob) )
                                sp += sprintf(HIG + (ob == me ? "��" : ob->name()) + HIG "��������������ʱ�仹�� " NOR + HIY "������\n" NOR);
                        else
                        {
                                if( query("online_time", ob)/3<query("offline_time", ob) )
                                        set("offline_time",query("online_time",  ob)/3, ob);
                                sp += sprintf(HIG + (ob == me ? "��" : ob->name()) + HIG "��������������ʱ�仹�� " NOR + HIY "%s\n" NOR,
                                              time_period(query("online_time", ob)/3-query("offline_time", ob)));
                        }

                        sp += sprintf(HIG + (ob == me ? "��" : ob->name()) + HIG "�����˫������ʱ�仹�� " NOR + HIW "%s\n" NOR,
                                      time_period(query("time_reward/quest", ob)));
                        sp += sprintf(HIG + (ob == me ? "��" : ob->name()) + HIG "����ĸ�Ч����ʱ�仹�� " NOR + HIM "%s\n" NOR,
                                      time_period(query("time_reward/study", ob)));


                        me->start_more(sp);
                        return 1;
        }
                                
        if (arg && arg != "")
        {
                if( wizardp(me) || query("couple/child_id", me) )
                {
                        ob = present(arg, environment(me));

                        if (! ob || ! ob->is_character())
                                ob = find_player(arg);

                        if (! ob || ! ob->is_character())
                                ob = find_living(arg);

                        if (! ob || ! ob->is_character() || ! me->visible(ob))
                                return notify_fail("��Ҫ�쿴˭��״̬��\n");

                        if( !wizardp(me) && query("couple/child_id", me) != query("id", ob) )
                                return notify_fail("��Ҫ�쿴˭��״̬��\n");

                } else
                        return notify_fail("ֻ����ʦ�ܲ쿴���˵�״̬��\n");
        } else
                ob = me;

        sp = ZJOBLONG;
        sp += HIM + (ob == me ? "��" : ob->name(1)) + "Ŀǰ�ĸ���������Ч��һ��\n" NOR;
        sp += HIC "��" HIY "������--==�츳�ӳ�==--������" HIC "��\n" NOR;

        sp += sprintf(HIC "���������ӡ�" HIG " %9d / %-9d"
                      HIC "�����Ը��ӡ�" HIG " %9d / %d\n"
                      HIC "�����Ǹ��ӡ�" HIG " %9d / %-9d"
                      HIC "�������ӡ�" HIG " %9d / %d\n\n",
                      ob->query_all_buff("str"),2000,
                      ob->query_all_buff("int"),2000,
                      ob->query_all_buff("con"),2000,
                      ob->query_all_buff("dex"),2000);
        sp += HIC "��" HIY "������--==���޼ӳ�==--������" HIC "��\n" NOR;
        sp += sprintf(HIC "��Ǳ�����ޡ�" HIM " %9d / %-9d"
                      HIC "��������ޡ�" HIM " %9d / %d\n"
                      HIC "���������ޡ�" HIM " %9d / %-9d"
                      HIC "���������ޡ�" HIM " %9d / %d\n"
                      HIC "����Ѫ���ޡ�" HIM " %9d / %-9d"
                      HIC "���������ޡ�" HIM " %9d / %d\n\n",
                      ob->query_all_buff("max_potential"),10000000,
                      ob->query_all_buff("max_experience"),10000000,
                      ob->query_all_buff("max_neili"),2000000,
                      ob->query_all_buff("max_jingli"),1000000,
                      ob->query_all_buff("max_qi"),2000000,
                      ob->query_all_buff("max_jing"),1000000);        
        sp += HIC "��" HIY "������--==�����ӳ�==--������" HIC "��\n" NOR;
        sp += sprintf(HIC "���о�������" HIY " %9d / %-9d"
                      HIC "���о�Ч����" HIY " %9s / %s\n"
                      HIC "����ϰ������" HIY " %9d / %-9d"
                      HIC "����ϰЧ����" HIY " %9s / %s\n"
                      HIC "��ѧϰ������" HIY " %9d / %-9d"
                      HIC "��ѧϰЧ����" HIY " %9s / %s\n"
                      HIC "����ȡ���ġ�" HIY " %9d / %-9d"
                      HIC "����ȡЧ����" HIY " %9s / %s\n\n",
                      ob->query_all_buff("research_times"),2000,
                      ob->query_all_buff("research_effect")+"%","2000%",
                      ob->query_all_buff("practice_times"),2000,
                      ob->query_all_buff("practice_effect")+"%","2000%",
                      ob->query_all_buff("learn_times"),2000,
                      ob->query_all_buff("learn_effect")+"%","2000%",
                      ob->query_all_buff("derive_times"),2000,
                      ob->query_all_buff("derive_effect")+"%","2000%");
        sp += HIC "��" HIY "������--==���мӳ�==--������" HIC "��\n" NOR;
        sp += sprintf(RED "���� �� ����" RED " %9s / %-9s"
                      RED "����    ����" RED " %9s / %s\n"
                      RED "��ħ �� ����" RED " %9s / %-9s"
                      RED "����    ħ��" RED " %9s / %s\n"
                      RED "���� �� ����" RED " %9s / %-9s"
                      RED "����    ��" RED " %9s / %s\n"
                      RED "��ľ �� ����" RED " %9s / %-9s"
                      RED "����    ľ��" RED " %9s / %s\n"
                      RED "��ˮ �� ����" RED " %9s / %-9s"
                      RED "����    ˮ��" RED " %9s / %s\n"
                      RED "���� �� ����" RED " %9s / %-9s"
                      RED "����    ��" RED " %9s / %s\n"
                      RED "���� �� ����" RED " %9s / %-9s"
                      RED "����    ����" RED " %9s / %s\n\n",
                      ob->query_all_buff("add_poison")+"%","100%",ob->query_all_buff("reduce_poison")+"%","100%",
                      ob->query_all_buff("add_magic")+"%","100%",ob->query_all_buff("reduce_magic")+"%","100%",
                      ob->query_all_buff("add_metal")+"%","100%",ob->query_all_buff("reduce_metal")+"%","100%",
                      ob->query_all_buff("add_wood")+"%","100%",ob->query_all_buff("reduce_wood")+"%","100%",
                      ob->query_all_buff("add_water")+"%","100%",ob->query_all_buff("reduce_water")+"%","100%",
                      ob->query_all_buff("add_fire")+"%","100%",ob->query_all_buff("reduce_fire")+"%","100%",
                      ob->query_all_buff("add_earth")+"%","100%",ob->query_all_buff("reduce_earth")+"%","100%");
        sp += HIC "��" HIY "������--==״̬�ָ�==--������" HIC "��\n" NOR;
        sp += sprintf(HIB "��͵ȡ������" HIB " %9s / %-9s"
                      HIB "��͵ȡ������" HIB " %9s / %s\n\n",
                      ob->query_all_buff("leech_neili")+"%","90%",
                      ob->query_all_buff("leech_qi")+"%","90%");
        sp += HIC "��" HIY "������--==ս���ӳ�==--������" HIC "��\n" NOR;
        sp += sprintf(WHT "�������ȼ���" HIW " %9d / %-9d" NOR
                      WHT "�������ȼ���" HIW " %9d / %d\n" NOR
                      WHT "�������ȼ���" HIW " %9d / %-9d" NOR
                      WHT "���мܵȼ���" HIW " %9d / %d\n" NOR
                      WHT "���������С�" HIW " %9s / %-9s" NOR
                      WHT "�����з�����" HIW " %9s / %s\n" NOR
                      WHT "�������˺���" HIG " %9d / %-9d" NOR
                      WHT "�������˺���" HIG " %9d / %d\n" NOR
                      WHT "�������˺���" HIG " %9s / %-9s" NOR
                      WHT "��ս��������" HIG " %9d / %d\n" NOR
                      /*
                      WHT "�������˺���" HIG " %9d / %-9d" NOR
                      WHT "�����ӱ�����" HIG " %9d / %d\n" NOR
                      WHT "�������˺���" HIG " %9d / %-9d" NOR
                      WHT "�����챣����" HIG " %9d / %d\n" NOR
                      */
                      WHT "�������мܡ�" HIY " %9s / %-9s" NOR
                      WHT "�����Ӷ�����" HIY " %9s / %s\n" NOR
                      WHT "�������ع���" HIY " %9s / %-9s" NOR
                      WHT "�������ڷ���" HIY " %9s / %s\n\n" NOR,
                      ob->query_all_buff("attack"),9000,
                      ob->query_all_buff("defense"),9000,
                      ob->query_all_buff("dodge"),9000,
                      ob->query_all_buff("parry"),9000,
                      ob->query_all_buff("ap_power")+"%","120%",
                      ob->query_all_buff("dp_power")+"%","120%",
                      ob->query_all_buff("damage"),200000,
                      ob->query_all_buff("unarmed_damage"),200000,
                      ob->query_all_buff("da_power")+"%","120%",
                      ob->query_all_buff("armor"),200000,
                      //query_temp("apply/damage1", ob),200000,query_temp("apply/armor1", ob),200000,
                      //query_temp("apply/damage2", ob),200000,query_temp("apply/armor2", ob),200000,
                      ob->query_all_buff("avoid_parry")+"%","90%",
                      ob->query_all_buff("avoid_dodge")+"%","90%",
                      ob->query_all_buff("avoid_attack")+"%","90%",
                      ob->query_all_buff("avoid_force")+"%","90%");                      
        sp += HIC "��" HIY "������--==�߼�����==--������" HIC "��\n" NOR;
        sp += sprintf(HIW "������æ�ҡ�" HIM " %9d / %-9d"
                      HIW "��Ѱ �� �ʡ�" HIM " %9s / %s\n"
                      HIW "��˫���˺���" CYN " %9s / %-9s"
                      HIW "����ת������" CYN " %9s / %s\n"  
                      HIW "����    ä��" CYN " %9s / %-9s"
                      HIW "��������ä��" CYN " %9s / %s\n"
                      HIW "����͸�Ƽס�" CYN " %9s / %-9s"
                      HIW "���ٶ����֡�" CYN " %9s / %s\n"
                      HIW "��ս���塿" CYN " %9s / %-9s\n\n",
                      ob->query_all_buff("reduce_busy"),90,
                      ob->query_all_buff("magic_find")+"%","300%",
                      ob->query_all_buff("double_damage")+"%","200%",
                      ob->query_all_buff("qi_abs_neili")+"%","90%",
                      ob->query_all_buff("add_blind")+"%","90%",
                      ob->query_all_buff("avoid_blind")+"%","90%",
                      ob->query_all_buff("through_armor")+"%","90%",
                      ob->query_all_buff("avoid_poison")+"%","100%",
                      ob->query_all_buff("full_self")+"%","90%");
                      
        sp += HIC "��" HIY "������--==�ռ�����==--������" HIC "��\n" NOR;
        sp += sprintf(HIY "����    ����" HIM " %9s / %-9s"
                      HIY "�����ӱ�����" HIM " %9s / %s\n"
                      HIY "����    ����" HIM " %9s / %-9s"
                      HIY "������������" HIM " %9s / %s\n"
                      HIY "��æ    �ҡ�" HIM " %9d / %-9d"
                      HIY "������æ�ҡ�" HIM " %9s / %s\n"
                      HIY "����    ����" HIM " %9s / %-9s"
                      HIY "������������" HIM " %9s / %s\n"
                      HIY "��׷���˺���" HIM " %9s / %-9s"
                      HIY "�������˺���" HIM " %9s / %s\n"
                      HIY "���˺����ɡ�" HIM " %9s / %-9s"
                      HIY "��ԡѪ������" HIM " %9s / %s\n"                      
                      HIY "������һ����" HIM " %9s / %-9s"
                      HIY "���������ܡ�" HIM " %9d / %d\n\n",
                      ob->query_all_buff("add_freeze")+"%","90%",ob->query_all_buff("avoid_freeze")+"%","90%",
                      ob->query_all_buff("add_forget")+"%","90%",ob->query_all_buff("avoid_forget")+"%","90%",
                      ob->query_all_buff("add_busy"),90,ob->query_all_buff("avoid_busy")+"%","90%",
                      ob->query_all_buff("add_weak")+"%","90%",ob->query_all_buff("avoid_weak")+"%","90%",
                      ob->query_all_buff("add_damage")+"%","200%",
                      ob->query_all_buff("reduce_damage")+"%","90%",
                      ob->query_all_buff("counter_damage")+"%","90%",ob->query_all_buff("avoid_die")+"%","90%",
                      ob->query_all_buff("fatal_blow")+"%","90%",ob->query_all_buff("add_skill"),1200);

        sp += HIC "��" HIY "������--==���߹���==--������" HIC "��\n" NOR;
        sp += sprintf(HIG + (ob == me ? "��" : ob->name()) + HIG "��%s���Ѿ������� " NOR + HIC "%s\n" NOR,
                        LOCAL_MUD_NAME(), time_period(query("online_time", ob)));

        if (MEMBER_D->is_valid_member(ob))
                sp += sprintf(HIG + (ob == me ? "��" : ob->name()) + HIG "��������������ʱ�仹�� " NOR + HIY "������\n" NOR);
        else
        {
                if( query("online_time", ob)/3<query("offline_time", ob) )
                        set("offline_time",query("online_time",  ob)/3, ob);
                sp += sprintf(HIG + (ob == me ? "��" : ob->name()) + HIG "��������������ʱ�仹�� " NOR + HIY "%s\n" NOR,
                              time_period(query("online_time", ob)/3-query("offline_time", ob)));
        }

        sp += sprintf(HIG + (ob == me ? "��" : ob->name()) + HIG "���߱�����Ʒʱ�仹ʣ�� " NOR + HIW "%s\n" NOR,
                      (query("srv/quit_save", ob)-time()) > 0 ? time_period(query("srv/quit_save", ob)-time()) : "����");

        sp += sprintf(HIG + (ob == me ? "��" : ob->name()) + HIG "�����˫������ʱ�仹�� " NOR + HIW "%s\n" NOR,
                      time_period(query("time_reward/quest", ob)));
        sp += sprintf(HIG + (ob == me ? "��" : ob->name()) + HIG "����ĸ�Ч����ʱ�仹�� " NOR + HIM "%s\n" NOR,
                      time_period(query("time_reward/study", ob)));

        sp = replace_string(sp,"\n",ZJBR);
	  if(sp[(strlen(sp)-4)..(strlen(sp)-1)]=="$br#")
		sp = sp[0..(strlen(sp)-5)];
	  sp+= "\n";
        message("vision", sp, me);
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ��istat [-jingmai] [-yuanshen] [-ability] [-skillmix] [-equipment] [-talent]
          istat [-jingmai] [-yuanshen] [-ability] [-skillmix] [-equipment] [-talent] <��������>  ����ʦר�ã�

���ָ�������ʾ���ָ������ĸ��ָ���״̬����ֵ��

HELP);
        return 1;
}
