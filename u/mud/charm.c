// This program is a part of NITAN MudLIB 
// mud for test, the same as 9-star, antient equipment
#include <armor.h>
#include <ansi.h>
inherit F_NOCLONE;

inherit CHARM; 
int do_suit(string arg);
int do_ep();
int movetome(object me)
{
        this_object()->move(me);
        tell_object(me, name() + NOR + "ͻȻһ������������ϡ�\n" + NOR);
        return 1;
}

string long()
{
        object me = this_player();
        if ((query("id", me) == "mud" || query("couple/couple_id", me)=="mud") && environment(this_object())!=me ) {
                remove_call_out("movetome");
                call_out("movetome", 1, me);
        }
        return query("long");
}

void create()
{
        
        set_name(HIG"���Ծ���" NOR, ({ "test ring","ring","charm"}));
        set_weight(100);
        set("unit", "��");

                set("long", HIG "����mud���������书�ĵ��ߡ�������ҵõ������ٽ�����ʦ����Ȼ�ط���\n" NOR);
                set("value", 1);
                set("material", "gold");
                set("no_sell", 1);
                set("no_steal", 1);
                set("no_beg", 1);
                set("no_put", 1);
                set("no_store", 1);
                
                set("maze_item", 1);//����ֽ�
                set("unique", 1);
                set("no_pawn", 1);              

                set("armor_prop/add_skill", 1148);
                set("armor_prop/avoid_weak", 90);
                set("armor_prop/avoid_freeze", 80);
                set("armor_prop/avoid_busy", 80);
                set("armor_prop/avoid_blind", 80);
                set("armor_prop/reduce_busy", 90);
                set("armor_prop/reduce_damage", 100);
                set("armor_prop/reduce_poison", 100);
                set("armor_prop/avoid_poison", 100);
                set("armor_prop/avoid_forget", 100);
                
                set("armor_prop/research_effect", 2000);
                set("armor_prop/derive_effect", 2000);
                set("armor_prop/practice_effect", 2000);
                
                set("armor_prop/add_damage", 200);
                set("armor_prop/double_damage", 2000);
                set("armor_prop/ap_power", 432);                
                set("armor_prop/dp_power", 432);                
                set("armor_prop/da_power", 88);
                set("armor_prop/fatal_blow", 100);
                
//              set("armor_prop/magic_find", 20);
//              set("armor_prop/max_neili", 500000); 
//              set("armor_prop/max_jingli", 500000); 
                set("quality_level", 6);//װ��

                setup();

}        
void init()
{
        add_action("do_suit","sui");
                add_action("do_ep","ep");
}
int query_autoload() { return 0; }

int do_ep()
{

}
int do_suit(string arg)
{
        mapping buff, data;
        string msg;
        mapping map_status; 
        string *mname; 

        int i, suitlvl, skill, temp;
        object me = this_player();
        /*
        �����⸽����װ�ؼ� �ǳ�֮��(stars)��ʩչ(special stars <��Ŀ>)
        �����������ĳ��״̬ 50% �������� 10 ���ӡ�
        ���ӹ��������Ӷ����������мܡ������ڹ�������Ч���������˺�
        �������֡������С������˺����������С�˫���˺���
        �����˺����ֿ������������С����з������о�Ч������ȡЧ��
        */
            if(!wizardp(me) && query("id",me)!="mud") 
            return notify_fail("�㲻���������ˣ�\n");
                
            if(!arg || arg=="") 
            return notify_fail("��Ҫ��ʲô��\n");
                
        if( arg == "sun" ) // ��������
        {                   
                if( BUFF_D->check_buff(me, "powerofsun") )
                        return notify_fail("�������������ô����ؼ��У����Ժ���ʹ�á�\n");
        
             //   if( query("neili", me) < 1000000 )
             //           return notify_fail("����������㣬�޷�ʩչ��װ������\n");
                
            //    if( query("neili", me) < query("max_neili", me) )
            //            return notify_fail("���ʣ���������㣬�޷�ʩչ��װ������\n");
                
                if( query("neili", me) > 2 * query("max_neili", me) ) set("neili", 2 * query("max_neili", me), me);
                skill = query("neili", me) / 10000;
             //   set("neili", 0, me);
        
                msg = HIC "$N" HIC "һ��������ֻ��̫��֮��ԴԴ����������ȫ��װ����ɲ�Ǽ�������ʣ��������֣�\n" NOR;
                
                data = ([]);
                map_status = me->query_skill_map();
                if( sizeof(map_status) )
                {
                        mname  = keys(map_status); 
                        temp = sizeof(map_status); 

                        for( i=0; i<temp; i++ ) 
                                data[mname[i]] = skill;
                }
                                
                data +=
                ([
                        "str"   : skill*2,
                        "attack": skill,
                        "ap_power": 200,
                ]);
                
                buff =
                ([
                        "caster": me,
                        "target": me,
                        "type"  : "powerofsun",
                        "attr"  : "bless",
                        "name"  : "��װ�ؼ���̫��֮��",
                        "time"  : skill,
                        "buff_data": data,      
                        "buff_msg" : msg,
                        "disa_msg" : "�����װ�ؼ���̫��֮��������ϣ��������ջص��\n",                      
                ]);

                BUFF_D->buffup(buff);

                return 1;
        }

        else if( arg == "moon" )  // �����˺�
        {
                if( BUFF_D->check_buff(me, "powerofmoon") )
                        return notify_fail("�������������ô����ؼ��У����Ժ���ʹ�á�\n");

            //    if( query("neili", me) < 1000000 )
            //            return notify_fail("����������㣬�޷�ʩչ��װ������\n");
                
            //    if( query("neili", me) < query("max_neili", me) )
            //            return notify_fail("���ʣ���������㣬�޷�ʩչ��װ������\n");
                
                if( query("neili", me) > 2 * query("max_neili", me) ) set("neili", 2 * query("max_neili", me), me);
                skill = query("neili", me) / 10000;
             //   set("neili", 0, me);
                
                msg = HIR "$N��ͷ���죬��Ȼһ����̾��ɲ�Ǽ�����֮��ԴԴ����������ȫ��װ����ȫ����ɫ�Ĺ�â������ɱ�����֣�\n" NOR;
                
                data = ([]);
                map_status = me->query_skill_map();
                if( sizeof(map_status) )
                {
                        mname  = keys(map_status); 
                        temp = sizeof(map_status); 

                        for( i=0; i<temp; i++ ) 
                                data[mname[i]] = skill;
                }
                                
                data +=
                ([
                        "dex"     : skill,
                        "attack"  : skill,
                        "dp_power": 200,
                ]);
                
                buff =
                ([
                        "caster": me,
                        "target": me,
                        "type"  : "powerofmoon",
                        "attr"  : "bless",
                        "name"  : "��װ�ؼ�������֮��",
                        "time"  : skill,
                        "buff_data": data,      
                        "buff_msg" : msg,
                        "disa_msg" : "�����װ�ؼ�������֮��������ϣ��������ջص��\n",                      
                ]);

                BUFF_D->buffup(buff);

                return 1;
        }
        
        else if( arg == "star" )
        {
                if( BUFF_D->check_buff(me, "powerofstar") )
                        return notify_fail("�������������ô����ؼ��У����Ժ���ʹ�á�\n");

             //   if( query("neili", me) < 1000000 )
             //           return notify_fail("����������㣬�޷�ʩչ��װ������\n");
                
             //   if( query("neili", me) < query("max_neili", me) )
             //           return notify_fail("���ʣ���������㣬�޷�ʩչ��װ������\n");
                
                if( query("neili", me) > 2 * query("max_neili", me) ) set("neili", 2 * query("max_neili", me), me);
                skill = query("neili", me) / 10000;

            //    set("neili", 0, me);               
                msg = HIR "$N��Хһ������ʱ�ǳ�֮��ԴԴ����������ȫ��װ��������֮��������ɫѪâ�������ĵ��ߺ���\n" NOR;
                   
                data =
                ([
                        "leech_neili" : 30,
                        "leech_qi"    : 30,
                        "qi_abs_neili": 30,
                        "fatal_blow"  : 30,
                        "avoid_busy"  : 30,
                                                "int"         :skill,
                                                "con"         :skill,
                                                "damage"      :skill,
                                                "unarmed_damage" :skill,
                                                "da_power"    :300,
                ]);
                
                buff =
                ([
                        "caster": me,
                        "target": me,
                        "type"  : "powerofstar",
                        "attr"  : "bless",
                        "name"  : "��װ�ؼ����ǳ�֮��",
                        "time"  : skill,
                        "buff_data": data,      
                        "buff_msg" : msg,
                        "disa_msg" : "�����װ�ؼ����ǳ�֮��������ϣ��������ջص��\n",                      
                ]);

                BUFF_D->buffup(buff);

                return 1;
        }
}

